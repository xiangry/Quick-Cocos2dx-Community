//
//  SortNode.h
//  miniDotaClient
//
//  Created by yock on 13-3-8.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#ifndef miniDotaClient_SortNode_h
#define miniDotaClient_SortNode_h

#include "cocos2d.h"

class zcAnimNode;

class zcMoveTo
{
public:
    friend class SortNode;
public:
    zcMoveTo();
    ~zcMoveTo();
public:
    static zcMoveTo* create(float duration,const cocos2d::CCPoint& pt , float height=0);
    static zcMoveTo* create(float duration,cocos2d::CCNode* node, float height);
public:
    /*
     * function callback( selfobj , otherobj )
     * selfobj : this node
     * otherobj: des node
     */
    void registerCallBack(int handle);
    void unregisterCallBack();
protected:
    cocos2d::CCNode  *m_hNode;
    cocos2d::CCPoint  m_iPt;
    float             m_fDuration;
    float             m_fHeight;     //it is jump to
    zcMoveTo         *m_hNext;
    int               m_nScriptCallBack;
};

class SortNode : public cocos2d::CCLayer
{
public:
    SortNode();
    ~SortNode();
public:
    
    static SortNode* create(const char* fname,int theId , const char* plistName);
public:
    
	bool playSection(const std::string& theLabelName);
	void pause();
	void resume();
	bool isPause();
	bool isPlaying();
	int getCurFrame();
	std::string getCurSectionName();
	bool hasSection(const std::string& theLabelName);
	void setRhythm(float rhythm);
	float getRhythm();
    
	virtual void registerScriptTapHandler(int nHandler);
	virtual void unregisterScriptTapHandler();
    void registerScriptAnchor(int nHandler);
    void unregisterScriptAnchor();
    void registerComponent(int nHandler);
    void unregisterComponent();
	int getId();
    
    void setComponentId(const std::string& flag);
    void resetComponentId(const std::string& flag);
    
    void setMatrixValue(float scaleX,float scaleY,float rotationX,float rotationY);
    void flushMatrix();
    //close reorder
    void setOffReorder(bool click);
    
	void setFlipX(bool fx);
	void setFlipY(bool fy);
	bool getFlipX();
	bool getFlipY();
    void setColor(const cocos2d::ccColor3B& color);
    void setOpacity(GLubyte opacity);
    void setRotation(float rotation);
    
	int getActionCount();
	std::string getActionName(int index);
    
    virtual void setPosition(const cocos2d::CCPoint& pt);
    
    float getAnimPercent();
    std::string getAnimName();
    std::string getPlistName();
    
    void disableSort(bool disable)
    {
        m_disableSort = disable;
    }
    
public:
    void moveTo(zcMoveTo* move);
    /*
     move is move to position
     movemode is remove animitions mode
        0 when time out remove all
        1 the last anim is first remove when time out all node be removed
        2 the first anim is first remove when time out all node be removed
     */
    void moveLineTo(zcMoveTo* move,int movemode,float movetime);
    void stopMove();
protected:
    void initMoveTo();
public:
    void update(float dt);
    void registerPosChange(int handle);
    void unregisterPosChange();
protected:
    zcAnimNode  *m_hAnim;
    zcMoveTo    *m_hCurrent;
    zcMoveTo    *m_hLast;
    cocos2d::CCPoint    m_iStartPosition;
    cocos2d::CCPoint    m_iSubPt;
    float               m_fHeight;
    float        m_fCurrentParten;
    bool         m_bMoveRun;
    float        m_fRhythm;
    int m_posChange;//位置变化回调
    
    std::string  m_sAnimName;           //animation file name
    std::string  m_sPListName;          //
    std::map<zcAnimNode*, float>  m_rAnimList;
    bool         m_bRemoveIsStart;      //the remove opption is start
    cocos2d::CCPoint    m_iLastPt;
    
    bool         m_bIsMoveLineTo;       //move line flag
    int          m_nMoveMode;           //remove mode
    float        m_fMoveTime;           //remove time
    
    bool         m_bOffReorder;         //reorder click
    
    bool         m_disableSort;        //自动排序的开关
};

#endif
