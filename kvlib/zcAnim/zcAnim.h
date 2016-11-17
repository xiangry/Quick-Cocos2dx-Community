#ifndef __ZCANIM_H__
#define __ZCANIM_H__

#include "swfType.h"

enum
{
	EzcEnd = 0,
	EzcImage,
	EzcLable,
	EzcPlace,
	EzcRemove,
	EzcShow,
	EzcHandle,
    EzcAnchor,
	EzcError
};

class zcanim_tag
{
public:
	friend class zcanim_tag_factory;
public:
	zcanim_tag();
	virtual ~zcanim_tag();
public:
	bool create(bitStream *s);	//if false is endTag or errorTag
	virtual void writeData(FILE *fl){};
	zcanim_tag* getNext();
	UI32 getTag(){return m_nTag;}
public:
	UI32 m_nTag;		//tag flag
	UI32 m_nLen;		//data length
	zcanim_tag	*m_pNext;		//next tag
};

class zcanim_end : public zcanim_tag
{
public:
	zcanim_end();
	~zcanim_end();
public:
	bool create(bitStream *s);
	void writeData(FILE *fl);
};

class zcanim_image : public zcanim_tag
{
public:
	zcanim_image();
	~zcanim_image();
public:
	bool create(bitStream *s);
	void writeData(FILE *fl);
public:
	UI32		 		 m_nCid;		//resource id
	std::string			 m_iName;		//image file name
};

class zcanim_lable : public zcanim_tag
{
public:
	zcanim_lable();
	~zcanim_lable();
public:
	bool create(bitStream *s);
	std::string getName(){return m_iName;}
	void writeData(FILE *fl);
public:
	std::string		m_iName;				//frame name , the frame is keyframe
};

class zcanim_place : public zcanim_tag
{
public:
	zcanim_place();
	~zcanim_place();
public:
	bool create(bitStream *s);
	void writeData(FILE *fl);
	UI32 getCid(){return m_nCid;}
	UI32 getDepth(){return m_nDepth;}
	UI32 getRealDepth(){return m_nRealDepth;}
	cocos2dMATRIX getMatrix(){return m_iMatrix;}
public:
	UI32			m_nCid;				//image id , if cid = 0 , the tag is changed matrix for old sprite
	UI32			m_nDepth;			//cocos2d tag
	UI32			m_nRealDepth;		//cocos2d z
	UI32			m_bHasColorF;		//with or without color transform 
	UI32			m_bHasMatrix;		//with or without transform matrix
	cocos2dMATRIX	m_iMatrix;
	cocos2dCOLORFORM	m_iColorForm;	//cocos2d sprite color transform
};

class zcanim_remove : public zcanim_tag
{
public:
	zcanim_remove();
	~zcanim_remove();
public:
	bool create(bitStream *s);
	UI32 getDepth(){return m_nDepth;}
	void writeData(FILE *fl);
public:
	UI32 		m_nDepth;				//cocos2d tag
};

class zcanim_show : public zcanim_tag
{
public:
	zcanim_show();
	~zcanim_show();
public:
	bool create(bitStream *s);
	void writeData(FILE *fl);
};

class zcanim_handle : public zcanim_tag
{
public:
	zcanim_handle();
	~zcanim_handle();
public:
	bool create(bitStream *s);
	void writeData(FILE *fl);
public:
	UI32		m_nFrameWidth;
	UI32		m_nFrameHeight;
	float		m_fRate;
	UI32		m_nAllFrameCount;
};

class zcanim_anchor : public zcanim_tag
{
public:
    zcanim_anchor();
    ~zcanim_anchor();
public:
    bool create(bitStream *s);
    std::string getStr(){return m_iStr;}
    void writeData(FILE *fl);
public:
    std::string     m_iStr;
};

class zcanim_tag_factory
{
public:
	//create one tag with stream
	static zcanim_tag* createTag(bitStream* s);
	//create tag list with file
	static zcanim_tag* createTagList(const char* fname);	
};


#ifdef WIN32
void cleanWin32tagList();
zcanim_tag* getWin32tagList();
void addtag(zcanim_tag *tag);
#endif//win32






#endif//file end