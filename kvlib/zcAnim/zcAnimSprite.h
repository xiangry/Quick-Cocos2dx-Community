#ifndef __ZCANIMSPRITE_H__
#define __ZCANIMSPRITE_H__


#include "cocos2d.h"
#include "swfType.h"

class zcAnimSprite : public cocos2d::Sprite
{
public:
    friend class zcAnimNode;
public:
	zcAnimSprite(void);
	virtual ~zcAnimSprite(void);
public:
	static zcAnimSprite* createWithTexture(const cocos2d::Texture2D* texture,const cocos2d::Rect& rect,const cocos2d::Size parentSz);
    static zcAnimSprite* createWithFrame(const char *frameName , const cocos2d::Size &parentSz);
public:
	void setMatrix(const cocos2dMATRIX& matrix);
	void setColorForm(const cocos2dCOLORFORM& colorform);
    void setFlipX(bool fx);
    void setFlipY(bool fy);
    
    void asSameAs(zcAnimSprite* sprite);
    
    int setCid(int cid);
    int getCid();
    
    
    /** updates the quad according the the rotation, position, scale values. */
    virtual void updateTransform(void);

//	virtual void draw(void);
    virtual void draw(Renderer* renderer, const Mat4 &transform, uint32_t flags);

//	virtual cocos2d::CCAffineTransform nodeToParentTransform(void);
    
    void setColor(const Color3B& color);
    virtual void setOpacity(GLubyte opacity);
protected:
	void updateAnimMatrix();
    void updateAnimColor();
    void updateColor();
protected:
	bool			m_bChangedMatrix;
    bool            m_bChangedColor;
    bool            m_bHadMatrix;
    bool            m_bHadColor;
	cocos2dMATRIX	m_iMatrix;
    cocos2dCOLORFORM    m_iColorTrans;
	V3F_C4B_T2F_Quad m_iQuad;
	cocos2d::Size			m_iParentContentSize;
    bool            m_bAnimFlipX;
    bool            m_bAnimFlipY;
    int             m_nCid;
    
    //add by ysp
    std::string     m_frameName;
    //end
};

#endif//file end
