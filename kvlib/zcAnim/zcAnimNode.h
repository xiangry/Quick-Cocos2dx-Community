#ifndef __ZCANIMNODE_H__
#define __ZCANIMNODE_H__

#if _MSC_VER > 1000
#pragma once
#endif // in

#include "cocos2d.h"

#include "zcAnim.h"
#include "swfType.h"

#define ZCVERSION   20131001
#define ISLUA 1

#ifdef WIN32

displayList* getPlaceList();

typedef swfDictionary resourceDeictionary;
#else//win32

typedef std::map<int, std::string> resourceDeictionary;

#endif//win32

class zcAnimSprite;
class zcAnimNode;
class SuperPsz;
class SuperAnim;


class zcAnimNodeListenter
{
public:
	virtual void OnAnimSectionEnd(zcAnimNode *node,int theId,std::string theLabelName){}
    virtual void OnAnchor(zcAnimNode *node,int theId,std::string anchorString){}
    /*
     * script callback function like this
     * void OnComponent(zcAnimNode this,int theId,int flag,float x,float y , float scaleX , float scaleY , float rotateSkew0 , float rotateSkew1 , float z , float a)
     */
    virtual void OnComponent(zcAnimNode *node,
                             int theId,
                             int flag,
                             const cocos2d::Point &pt ,
                             const cocos2dMATRIX& matrix ,
                             float z ,
                             float a){}
};
#ifdef WIN32
class zcAnimNode : public cocos2d::CCNode
#else//win32
class zcAnimNode : public cocos2d::SpriteBatchNode
#endif//win32
{
public:
	friend class SortNode;
//    friend class skeletalNode;
public:
	zcAnimNode(void);
	~zcAnimNode(void);
public:
	static zcAnimNode* create(const char* fname,int theId , const char* plistName);
	static zcAnimNode* create(const char* fname,int theId , const char* plistName, zcAnimNodeListenter *theListenter);
    static void removeAllUnusing();
#ifdef WIN32
	static zcAnimNode* create(int theId,zcAnimNodeListenter* listenter);
#endif//win32
public:
	bool init(const char* fname,int theId, const char* plistName ,zcAnimNodeListenter *theListenter);
	void updateMovie(float dt);

	bool playSection(std::string theLabelName);
	void pause();
	void resume();
	bool isPause();
	bool isPlaying();
	int getCurFrame();
	std::string getCurSectionName();
	bool hasSection(std::string theLabelName);
	void setRhythm(float rhythm);
	float getRhythm();

	virtual void registerScriptTapHandler(int nHandler);
	virtual void unregisterScriptTapHandler();
    void registerScriptAnchor(int nHandler);
    void unregisterScriptAnchor();
    void registerComponent(int nHandler);
    void unregisterComponent();
	int getId();
    
    void setComponentId(std::string flag);
    void resetComponentId(std::string flag);

	void setFlipX(bool fx);
	void setFlipY(bool fy);
	bool getFlipX();
	bool getFlipY();
    void setColor(const Color3B& color);

	virtual void setPosition(const cocos2d::Point& pt);
    
    void setMatrix(const cocos2dMATRIX& matrix);
    const cocos2dMATRIX* getMatrix();
    void setBlendFunc(const BlendFunc &blendFunc);
    virtual void setOpacity(GLubyte opacity);
	void setMatrixValue(float scaleX,float scaleY,float rotationX,float rotationY);
    void flushMatrix();
    
	int getActionCount();
	std::string getActionName(int index);
    int getActionFramesCount(std::string action);
    
    std::string getAnimName() {return m_iAnimName;}
    std::string getPlistName() {return m_iFramePoolName;}
#ifdef WIN32
	std::map<std::string,zcanim_tag*>* getKeyFrameD();
#endif//win32

    
    //add by ysp
    // for replaceable sprite
    void replaceSprite(const std::string &theOriginSpriteName, const std::string &theNewSpriteName);
    // end
public:
	//scene management

    /** callback that is called every time the CCNode enters the 'stage'.
     If the CCNode enters the 'stage' with a transition, this callback is called when the transition starts.
     During onEnter you can't a "sister/brother" node.
     */
    virtual void onEnter();

    /** callback that is called every time the CCNode leaves the 'stage'.
     If the CCNode leaves the 'stage' with a transition, this callback is called when the transition finishes.
     During onExit you can't access a sibling node.
     */
    virtual void onExit();
protected:
	void changedFrame();
#ifdef WIN32
	zcAnimSprite* createCCSprite(_Bitmap *bitmap);
#else//win32
    zcAnimSprite* createCCSprite(const std::string& bitmap);
#endif//win32
public:
	zcanim_tag*		m_pOpraterList;		//oprater list
	std::map<std::string,zcanim_tag*>	m_iKeyframeDictionary;
	zcanim_tag*		m_pCurTag;			//current tag
	resourceDeictionary*	m_pResourceDictionary;
    std::map<std::string,std::list<int> >   m_iReverseResource;
#ifndef WIN32
    std::string     m_iAnimName;
    std::string     m_iFramePoolName;
#endif//not win32
    
	float			m_fDuration;		//every frame duration
	std::string		m_iCurSectionName;	//current used label name
	bool			m_bPause;
	bool			m_bPlaying;
    bool            m_bEntering;
	int				m_nCurFrameIndex;
	float			m_fRhythm;			//the phythm for real duration (realDuration = duration*rhythm)
	int				m_nId;				//the id with this anim
    
    int				m_nScriptObserverId;//this is a script call back handle,when animation section end,will be call
    int             m_nScriptAnchorId;  //this is a script call back handle,when Anchor tag be see , will be call
    int             m_nScriptComponent; //this is a script call back handle,when component id be set;
    
	zcAnimNodeListenter* m_hObserver;
	bool			m_bFlipX;
	bool			m_bFlipY;
    Color3B       m_tColor;
    unsigned char   m_nOpacity;

	float			m_fUpDurt;
    
    //
    SuperPsz        *m_hPszHandle;
    SuperAnim       *m_hAnimHandle;
    
    //----------------------------------frames count--------------------------
    std::map<std::string,int>           m_iKeyAllFramesCount;       //the frames count with action name
    zcanim_tag*                         m_pLastAnimTag;             //the last animation lable point
    int                                 m_nAnimFramesCount;         //the frames count at one of animation
    
    //----------------------------------with component------------------------
    int             m_nMaxComponent;                                //the max id for component with animation
    int             *m_pComponentFlag;                              //the component flag
    
    //----------------------------------metrix
    cocos2dMATRIX                       m_iMatrix;
};


bool loadZcAnim(const char* fanim,const char* fplist);
void unloadZcAnim(const char* fanim,const char* fplist);

#endif//file end

