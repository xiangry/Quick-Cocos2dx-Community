#include "zcAnim.h"
#include <stdio.h>
#ifdef WIN32
#include "swfTag.h"
#endif//win32

int myfileWrite(FILE *fl,void* buf,int size)
{
	return fwrite(buf,1,size,fl);
}

zcanim_tag::zcanim_tag()
{
	m_nTag = 0;
	m_nLen = 0;
	m_pNext = NULL;
}
zcanim_tag::~zcanim_tag()
{
	/*
	//most stack count mast be lass then 5000
	if(m_pNext)
		delete m_pNext;
	m_pNext=NULL;
	*/
}

bool zcanim_tag::create(bitStream *s)
{
	if(s->cOffset>=s->maxlen)
		return false;
	m_nTag = breadDWord(s);
	m_nLen = breadDWord(s);
	if(m_nTag == EzcEnd || m_nTag>=EzcError)
		return false;
    return true;
}

zcanim_tag* zcanim_tag::getNext()
{
	return m_pNext;
}

zcanim_end::zcanim_end()
{
}
zcanim_end::~zcanim_end()
{

}
bool zcanim_end::create(bitStream *s)
{
	return zcanim_tag::create(s);
}
void zcanim_end::writeData(FILE *fl)
{
	m_nLen = 0;
	myfileWrite(fl,&m_nTag,sizeof(UI32));
	myfileWrite(fl,&m_nLen,sizeof(UI32));
}

zcanim_image::zcanim_image():
m_iName("")
{
	m_nCid = 0;
}
zcanim_image::~zcanim_image()
{
	m_iName.clear();	
}
bool zcanim_image::create(bitStream *s)
{
	if(zcanim_tag::create(s))
	{
		m_nCid = breadDWord(s);
//		m_iName = (char*)(s->data+s->cOffset);
        m_iName = breadString(s);
		return true;
	}
	return false;
}
void zcanim_image::writeData(FILE *fl)
{
	m_nLen = sizeof(m_nCid) + m_iName.size()+1;
	myfileWrite(fl,&m_nTag,sizeof(UI32));
	myfileWrite(fl,&m_nLen,sizeof(UI32));
	myfileWrite(fl,&m_nCid,sizeof(UI32));
	myfileWrite(fl,(void*)(m_iName.c_str()),m_iName.size()+1);
}

zcanim_lable::zcanim_lable():
m_iName("")
{

}
zcanim_lable::~zcanim_lable()
{
	m_iName.clear();
}
bool zcanim_lable::create(bitStream *s)
{
	if(zcanim_tag::create(s))
	{
//		m_iName = (char*)(s->data+s->cOffset);
//        CCLOG("%s",m_iName.c_str());
//        s->cOffset+=m_nLen;
        m_iName = breadString(s);
		return true;
	}
	return false;
}
void zcanim_lable::writeData(FILE *fl)
{
	m_nLen = m_iName.size()+1;
	myfileWrite(fl,&m_nTag,sizeof(UI32));
	myfileWrite(fl,&m_nLen,sizeof(UI32));
	myfileWrite(fl,(void*)(m_iName.c_str()),m_iName.size()+1);
}

zcanim_place::zcanim_place()
{
	m_nCid = 0;
	m_nDepth = 0;
	m_nRealDepth = 0;
	m_bHasColorF = FALSE;
	m_bHasMatrix = FALSE;
	memset(&m_iMatrix,0,sizeof(cocos2dMATRIX));
	memset(&m_iColorForm,0,sizeof(cocos2dCOLORFORM));
}
zcanim_place::~zcanim_place()
{
	
}
bool zcanim_place::create(bitStream *s)
{
	if(zcanim_tag::create(s))
	{
		m_nCid = breadDWord(s);
		m_nDepth = breadDWord(s);
		m_nRealDepth = breadDWord(s);
		m_bHasColorF = breadDWord(s);
		m_bHasMatrix = breadDWord(s);
		if(m_bHasMatrix)
			m_iMatrix = makeCocos2dMATRIXWithStream(s);
		if(m_bHasColorF)
			m_iColorForm = makeCocos2dCOLORFORMWithStream(s);
		return true;
	}
	return false;
}
void zcanim_place::writeData(FILE *fl)
{
	m_nLen = sizeof(m_nCid)
		+sizeof(m_nDepth)
		+sizeof(m_nRealDepth)
		+sizeof(m_bHasMatrix)
		+sizeof(m_bHasColorF);
	if(m_bHasMatrix)
		m_nLen+=sizeof(cocos2dMATRIX);
	if(m_bHasColorF)
		m_nLen+=sizeof(cocos2dCOLORFORM);
	myfileWrite(fl,&m_nTag,sizeof(UI32));
	myfileWrite(fl,&m_nLen,sizeof(UI32));
	myfileWrite(fl,&m_nCid,sizeof(UI32));
	myfileWrite(fl,&m_nDepth,sizeof(UI32));
	myfileWrite(fl,&m_nRealDepth,sizeof(UI32));
	myfileWrite(fl,&m_bHasColorF,sizeof(UI32));
	myfileWrite(fl,&m_bHasMatrix,sizeof(UI32));
	if(m_bHasMatrix)
		myfileWrite(fl,&m_iMatrix,sizeof(cocos2dMATRIX));
	if(m_bHasColorF)
	{
		myfileWrite(fl,&(m_iColorForm.hasAddTerms),sizeof(UI32));
		myfileWrite(fl,&(m_iColorForm.hasMultTerms),sizeof(UI32));
		if(m_iColorForm.hasMultTerms)
		{
			myfileWrite(fl,&(m_iColorForm.redMultTerm),sizeof(UI32));
			myfileWrite(fl,&(m_iColorForm.greenMultTerm),sizeof(UI32));
			myfileWrite(fl,&(m_iColorForm.blueMultTerm),sizeof(UI32));
			myfileWrite(fl,&(m_iColorForm.alphaMultTerm),sizeof(UI32));
		}
		if(m_iColorForm.hasAddTerms)
		{
			myfileWrite(fl,&(m_iColorForm.redAddTerm),sizeof(UI32));
			myfileWrite(fl,&(m_iColorForm.greenAddTerm),sizeof(UI32));
			myfileWrite(fl,&(m_iColorForm.blueAddTerm),sizeof(UI32));
			myfileWrite(fl,&(m_iColorForm.alphaAddTerm),sizeof(UI32));
		}
//		myfileWrite(fl,&m_iColorForm,sizeof(cocos2dCOLORFORM));
	}
}

zcanim_remove::zcanim_remove()
{
	m_nDepth = 0;
}
zcanim_remove::~zcanim_remove()
{

}
bool zcanim_remove::create(bitStream *s)
{
	if(zcanim_tag::create(s))
	{
		m_nDepth = breadDWord(s);
		return true;
	}
	return false;
}
void zcanim_remove::writeData(FILE *fl)
{
	m_nLen = sizeof(m_nDepth);
	myfileWrite(fl,&m_nTag,sizeof(UI32));
	myfileWrite(fl,&m_nLen,sizeof(UI32));
	myfileWrite(fl,&m_nDepth,sizeof(UI32));
}

zcanim_show::zcanim_show()
{

}
zcanim_show::~zcanim_show()
{

}
bool zcanim_show::create(bitStream *s)
{
	return zcanim_tag::create(s);
}

void zcanim_show::writeData(FILE *fl)
{
	m_nLen = 0;
	myfileWrite(fl,&m_nTag,sizeof(UI32));
	myfileWrite(fl,&m_nLen,sizeof(UI32));
}

zcanim_handle::zcanim_handle()
{
	m_nFrameWidth = 0;
	m_nFrameHeight = 0;
	m_fRate = 0.0;
	m_nAllFrameCount = 0;
}
zcanim_handle::~zcanim_handle()
{

}
bool zcanim_handle::create(bitStream *s)
{
	if(zcanim_tag::create(s))
	{
		m_nFrameWidth = breadDWord(s);
		m_nFrameHeight = breadDWord(s);
		*((UI32*)&m_fRate) = breadDWord(s);
		m_nAllFrameCount = breadDWord(s);
		return true;
	}
	return false;
}

void zcanim_handle::writeData(FILE *fl)
{
	m_nLen = sizeof(m_nFrameWidth)
		+sizeof(m_nFrameHeight)
		+sizeof(m_fRate)
		+sizeof(m_nAllFrameCount);
	myfileWrite(fl,&m_nTag,sizeof(UI32));
	myfileWrite(fl,&m_nLen,sizeof(UI32));
	myfileWrite(fl,&m_nFrameWidth,sizeof(m_nFrameWidth));
	myfileWrite(fl,&m_nFrameHeight,sizeof(m_nFrameHeight));
	myfileWrite(fl,&m_fRate,sizeof(m_fRate));
	myfileWrite(fl,&m_nAllFrameCount,sizeof(m_nAllFrameCount));
}

zcanim_anchor::zcanim_anchor():
m_iStr("")
{
    
}
zcanim_anchor::~zcanim_anchor()
{
    
}
bool zcanim_anchor::create(bitStream *s)
{
    if(zcanim_tag::create(s))
    {
        m_iStr = breadString(s);
        return true;
    }
    return false;
}
void zcanim_anchor::writeData(FILE *fl)
{
    m_nLen = m_iStr.size()+1;
    myfileWrite(fl, &m_nTag, sizeof(UI32));
    myfileWrite(fl, &m_nLen, sizeof(UI32));
    myfileWrite(fl, (void*)(m_iStr.c_str()), m_iStr.size()+1);
}

//create one tag with stream
zcanim_tag* zcanim_tag_factory::createTag(bitStream* s)
{
	UI32 tag = breadDWord(s);
	s->cOffset-=4;
	switch(tag)
	{
	case EzcEnd:
		return NULL;
	case EzcImage:
		{
			zcanim_image *tag = new zcanim_image();
			if(tag->create(s))
				return tag;
			return NULL;
		}
		break;
	case EzcLable:
		{
			zcanim_lable *tag = new zcanim_lable();
			if(tag->create(s))
				return tag;
			return NULL;
		}
		break;
	case EzcPlace:
		{
			zcanim_place *tag = new zcanim_place();
			if(tag->create(s))
				return tag;
			return NULL;
		}
		break;
	case EzcRemove:
		{
			zcanim_remove *tag = new zcanim_remove();
			if(tag->create(s))
				return tag;
			return NULL;
		}
		break;
	case EzcShow:
		{
			zcanim_show *tag = new zcanim_show();
			if(tag->create(s))
				return tag;
			return NULL;
		}
		break;
	case EzcHandle:
		{
			zcanim_handle *tag = new zcanim_handle();
			if(tag->create(s))
				return tag;
			return NULL;
		}
		break;
    case EzcAnchor:
        {
            zcanim_anchor *tag = new zcanim_anchor();
            if(tag->create(s))
                return tag;
            return NULL;
        }
        break;
	default:
		return NULL;
	}
}

#ifdef WIN32
zcanim_tag* win32tagfirst = NULL;
zcanim_tag* win32taglast = NULL;

void cleanWin32tagList()
{
	zcanim_tag *temp = win32tagfirst;
	while(temp)
	{
		win32tagfirst=win32tagfirst->getNext();
		delete temp;
		temp = win32tagfirst;
	}
	win32tagfirst = NULL;
	win32taglast = NULL;
}
zcanim_tag* getWin32tagList()
{
	return win32tagfirst;
}

void addtag(zcanim_tag *tag)
{
	if(win32taglast==NULL && win32tagfirst==NULL)
	{
		win32tagfirst = tag;
		win32taglast = tag;
	}
	else
	{
		win32taglast->m_pNext = tag;
		win32taglast = tag;
	}
}
#endif//win32

//create tag list with file
zcanim_tag* zcanim_tag_factory::createTagList(const char* fname)
{

    /*
	FILE *fl = fopen(fname,"rb");
    if(fl==NULL) return NULL;
	int flen = 0;
	fseek(fl,0,SEEK_END);
	flen = ftell(fl);
	fseek(fl,0,SEEK_SET);
	UI8* data = new UI8[flen];
	fread(data,1,flen,fl);
	fclose(fl);
     */
    ssize_t flen;
    UI8* data = CCFileUtils::sharedFileUtils()->getFileData(fname, "rb", &flen);
    if(data == NULL)
        return NULL;
	bitStream s;
	s.data = data;
	s.bOffset = 0;
	s.cOffset = 0;
	s.maxlen = flen;
	
	zcanim_tag *first=createTag(&s);
	if(first==NULL)
		return NULL;
	zcanim_tag *last = first;
#ifdef DEBUG
    static int ac(0);
#endif
	while(true)
	{
		zcanim_tag* temp = createTag(&s);
		if(temp == NULL)
			break;
		last->m_pNext = temp;
		last = temp;
#ifdef DEBUG
        ac++;
#endif
	}
    delete data;
#ifdef DEBUG
//    CCLOG("tag count is %d",ac);
#endif
	return first;

}