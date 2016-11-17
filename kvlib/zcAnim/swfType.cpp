#include "swfType.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

_Bitmap::_Bitmap()
{
	m_pTexture = NULL;
	m_nBitmapId = 0;
	m_hData = NULL;
	m_nDatalen = 0;
	m_bPng = false;
}

_Bitmap::_Bitmap(_Bitmap &bitmap)
{
	m_pTexture = bitmap.m_pTexture;
	m_iRect = bitmap.m_iRect;
	m_nBitmapId = bitmap.m_nBitmapId;
	m_hData = NULL;
	m_nDatalen = 0;
	m_bPng = false;
	if(m_pTexture)
		m_pTexture->retain();
}

_Bitmap::~_Bitmap()
{
	if(m_pTexture)
		m_pTexture->release();
	delete m_hData;
}

_Bitmap _Bitmap::operator=(const _Bitmap& bitmap)
{
	m_pTexture = bitmap.m_pTexture;
	if(m_pTexture) m_pTexture->retain();
	m_iRect = bitmap.m_iRect;
	m_nBitmapId = bitmap.m_nBitmapId;
	return *this;
}

_Element::_Element()
{
	m_nCid = 0;
	m_nClipDepth = 0;
	m_bHasColorF = FALSE;
	m_bHasMatrix = TRUE;
	memset(&m_iMatrix,0,sizeof(cocos2dMATRIX));
	memset(&m_iColorForm,0,sizeof(cocos2dCOLORFORM));
}
_Element::~_Element()
{

}

unsigned int breadUBit(bitStream* s,int size)
{
	/*
	if(size <= 0) return 0;
	unsigned char* buf = s->data+s->cOffset+(s->bOffset>>3);
	int offset = s->bOffset & 0x7;	//?????
	int charnum = size>>3;			//size?????????
	int	bitnum = size & 0x7;		//size??????
	int value = 0;
	//flash??????,???????????
	int i;
	for(i=0 ; i<charnum ; i++)
	{
		((char*)&value)[i] = (buf[i] & nbitflag[8-offset])<<offset;
		((char*)&value)[i] |= (buf[i+1] & bitflag[offset])>>(8-offset);
	}
	if(bitnum>0)
	{
		int bit1,bit2;
		bit1 = (8-offset)>=bitnum ? bitnum : bitnum-(8-offset);
		bit2 = bitnum-bit1;
		((char*)&value)[i] = (((buf[i]<<offset) & bitflag[bit1])>>(8-bitnum));
		if(bit2>0)
			((char*)&value)[i] |= (buf[i+1] & bitflag[bit2])>>(8-bit2);
	}
	s->bOffset+=size;
	s->cOffset+=s->bOffset>>3;
	s->bOffset = s->bOffset & 0x7;
	return value;
	*/
	UI32 v = 0;
	while(true)
	{
		int n = size-s->bOffset;
		if(n>0)
		{
			//consume the entire buffer
			v |= s->bit<<n;
			size-=s->bOffset;

			//get next buffer
			s->bit = breadByte(s);
			s->bOffset = 8;
		}
		else
		{
			//consume a portion of the buffer
			v |= s->bit>>-n;
			s->bOffset-=size;
			s->bit &= 0xff>>(8-s->bOffset);
			return v;
		}
	}
}

int breadSBit(bitStream* s,int size)
{
	/*
	unsigned int value = breadUBit(s,size);
	unsigned int flag = 0x1<<(size-1);
	if(value & flag)
	{
		value |= (0xffffffff<<size);
		
		//value &= ~flag;
		//value = (~value)+0x1;
		
	}
	return value;
	*/
	SI32 v = breadUBit(s,size);
	if( v & (1L<<(size-1)) )
	{
		v|= -1L << size;
	}
	return v;
}

#define fixed	0x00010000L

float breadFBit(bitStream* s,int size)
{
	return (float)breadSBit(s,size) / fixed;
	/*
	int integerBS = (size-16)>0 ? (size-16) : 0;
	int desimalBS = size>16 ? 16 : size;
	double value = 0.0;
	double tempf=0;
	int temp = breadSBit(s,size);
	value = (temp>>16);
	tempf = (temp & 0x0000ffff);
	tempf = tempf/0x10000;
	value = value>0.0 ? value+tempf : value-tempf;
	return value;
	*/
	/*
	if(desimalBS>0)
	{
		value = breadUBit(s,desimalBS);
		while(value>1.0)
			value*=0.1;
	}
	if(integerBS>0)
	{
		int testV = breadSBit(s,integerBS);
		if(testV>0)
			value+=testV;
		else
			value = -value+testV;
	}
	return value;
	*/
	
}

unsigned char breadByte(bitStream* s)
{
	return s->data[s->cOffset++];
}
unsigned short  breadWord(bitStream* s)
{
	UI8 *st = s->data + s->cOffset;
	s->cOffset+=2;
	return (UI16)st[0] | ((UI16)st[1]<<8);
}
unsigned int	breadDWord(bitStream* s)
{
	UI8 *st = s->data + s->cOffset;
	s->cOffset+=4;
	return (UI32)st[0] | ((UI32)st[1]<<8) | ((UI32)st[2]<<16) | ((UI32)st[3]<<24);
}

const char* breadString(bitStream *s)
{
    SI8 *str = (SI8*)(s->data + s->cOffset);
    s->cOffset+=strlen(str)+1;
    return (const char*)str;
}

float breadFloat(bitStream*s)
{
    UI32 f = breadDWord(s);
    return *((float*)&f);
}


int byteAligment(bitStream* s)
{
	/*
	int temp = s->bOffset;
	s->cOffset += ((temp+0x7) & (~0x7))>>3;
	s->bOffset=0;
	return s->cOffset;
	*/
	s->bit = 0;
	s->bOffset = 0;
	return s->cOffset;
}

_RECT::_RECT(FSTREAM data)
{
	char d;
	fread(&d,1,sizeof(char),data);
	int len = (d>>3) & 0x1f;
	int datalen = ((len<<2)+5+0x07)>>3;		//字节对齐，数据字节数
	char dd[17];
	memset(dd,0,17);
	dd[0]=d;
	fread(&dd[1],1,datalen-1,data);
	for(int i=0 ; i<datalen ; i++)
	{
		printf("0x%x,",dd[i]);
	}
	printf("\n");
	bitStream s;
	s.data = (unsigned char*)&dd[0];
	/*
	s.cOffset=0;
	s.bOffset=5;
	m_nXmin = breadSBit(&s,len);
	m_nXmax = breadSBit(&s,len);
	m_nYmin = breadSBit(&s,len);
	m_nYmax = breadSBit(&s,len);
	*/
	s.cOffset = 0;
	s.bOffset = 0;
	int len1 = breadUBit(&s,5);
	m_nXmin = breadSBit(&s,len1);
	m_nXmax = breadSBit(&s,len1);
	m_nYmin = breadSBit(&s,len1);
	m_nYmax = breadSBit(&s,len1);
}
_RECT::_RECT(bitStream* s)
{
	int len = breadUBit(s,5);
	m_nXmin = breadSBit(s,len);
	m_nXmax = breadSBit(s,len);
	m_nYmin = breadSBit(s,len);
	m_nYmax = breadSBit(s,len);
	byteAligment(s);
}


_FILE* _FILE::Open(char* fname)
{
	_FILE* f = new _FILE(); 
	f->m_hFile = fopen(fname,"rb");
	if(f->m_hFile == NULL)
	{
		delete f;
		return NULL;
	}
	return f;
}
_FILE::~_FILE()
{
	fclose(m_hFile);
}
int _FILE::read(void* data,int size)
{
	return ::fread(data,1,size,m_hFile);
}
int _FILE::jumpTo(int offset)
{
	return fseek(m_hFile,offset,SEEK_CUR);
}

int _FILE::getCurrent()
{
	return ftell(m_hFile);
}

swfDictionary  m_swfDictionary;			//the dictionary for swf's resource 

void cleanDictionary()
{
	if(m_swfDictionary.size()<=0) return;
	swfDictionary::iterator it;
	for(it=m_swfDictionary.begin() ; it != m_swfDictionary.end() ; ++it)
	{
		delete it->second;
	}
	m_swfDictionary.clear();
}
_Bitmap* getBitmapFromDictionary(int id)
{
	swfDictionary::iterator it;
	it = m_swfDictionary.find(id);
	if(it != m_swfDictionary.end())
	{
		return (it->second);
	}
	return NULL;
}

bool setBitmapToDictionary(int id,_Bitmap *bitmap)
{
	swfDictionary::iterator it;
	it = m_swfDictionary.find(id);
	if(it != m_swfDictionary.end())
		return false;
	m_swfDictionary[id] = bitmap;
	return true;
}

swfDictionary* getDictionary()
{
	return &m_swfDictionary;
}

displayList m_desplayList;

void cleanDisplayList()
{
	displayList::iterator it;
	for(it = m_desplayList.begin() ; it != m_desplayList.end() ; ++it)
	{
		delete it->second;
	}
	m_desplayList.clear();
}

displayList* getDisplayList()
{
	return &m_desplayList;
}

void removeElement(int depth)
{
	displayList::iterator it;
	it = m_desplayList.find(depth);

	if(it == m_desplayList.end())
		return;
	delete it->second;
	m_desplayList.erase(it); 
}
void addElement(int depth,_Element* element)
{
	displayList::iterator it;
	it = m_desplayList.find(depth);
	if(it != m_desplayList.end())
	{
		it->second->m_iMatrix = element->m_iMatrix;
	}
	else
	{
			m_desplayList[depth] = element;
	}
}

swfRGBA makeRGBA(bitStream *s)
{
	swfRGBA color;
	color.red = breadByte(s);
	color.green = breadByte(s);
	color.blue = breadByte(s);
	color.alpha = breadByte(s);
	return color;
}
swfARGB makeARGB(bitStream *s)
{
	swfARGB color;
	color.alpha = breadByte(s);
	color.red = breadByte(s);
	color.green = breadByte(s);
	color.blue = breadByte(s);
	return color;
}
swfRGB  makeRGB(bitStream *s)
{
	swfRGB color;
	color.red = breadByte(s);
	color.green = breadByte(s);
	color.blue = breadByte(s);
	return color;
}

//make a matrix from bits stream
swfMATRIX makeMATRIX(bitStream* s)
{
	swfMATRIX matrix;
	memset(&matrix,0,sizeof(swfMATRIX));
	matrix.hasScale = breadUBit(s,1);
	if(matrix.hasScale)
	{
		matrix.nScaleBits = breadUBit(s,5);
//		matrix.scaleX = breadUBit(s,matrix.nScaleBits);
//		matrix.scaleY = breadUBit(s,matrix.nScaleBits);
		matrix.scaleX = breadFBit(s,matrix.nScaleBits);
		matrix.scaleY = breadFBit(s,matrix.nScaleBits);
	}
	else
	{
		matrix.scaleX = 1.0;
		matrix.scaleY = 1.0;
	}
	matrix.hasRotate = breadUBit(s,1);
	if(matrix.hasRotate)
	{
		matrix.nRotateBits = breadUBit(s,5);
//		matrix.rotateSkew0 = breadSBit(s,matrix.nRotateBits);
//		matrix.rotateSkew1 = breadSBit(s,matrix.nRotateBits);
		matrix.rotateSkew0 = breadFBit(s,matrix.nRotateBits);
		matrix.rotateSkew1 = breadFBit(s,matrix.nRotateBits);
	}
	matrix.nTranslateBits = breadUBit(s,5);
	matrix.translateX = breadSBit(s,matrix.nTranslateBits);
	matrix.translateY = breadSBit(s,matrix.nTranslateBits);
	byteAligment(s);
	return matrix;
}

// make a color transform with alpha , record is byte aligned.
swfCXFORMWITHALPHA makeCXFORMWITHALPHA(bitStream *s)
{
	swfCXFORMWITHALPHA ctrans;
	memset(&ctrans,0,sizeof(swfCXFORMWITHALPHA));
	ctrans.hasAddTerms = breadUBit(s,1);
	ctrans.hasMultTerms = breadUBit(s,1);
	ctrans.nbits = breadUBit(s,4);
	if(ctrans.hasMultTerms)
	{
		ctrans.redMultTerm = breadUBit(s,ctrans.nbits);
		ctrans.greenMultTerm = breadUBit(s,ctrans.nbits);
		ctrans.blueMultTerm = breadUBit(s,ctrans.nbits);
		ctrans.alphaMultTerm = breadUBit(s,ctrans.nbits);
	}
	if(ctrans.hasAddTerms)
	{
		ctrans.redAddTerm = breadUBit(s,ctrans.nbits);
		ctrans.greenAddTerm = breadUBit(s,ctrans.nbits);
		ctrans.blueAddTerm = breadUBit(s,ctrans.nbits);
		ctrans.alphaAddTerm = breadUBit(s,ctrans.nbits);
	}
	byteAligment(s);
	return ctrans;
}

cocos2dCOLORFORM makeCocos2dCOLORFORM(const swfCXFORMWITHALPHA& color)
{
	cocos2dCOLORFORM ccolor;
	ccolor.hasAddTerms = color.hasAddTerms;
	ccolor.hasMultTerms = color.hasMultTerms;
	ccolor.redMultTerm = color.redMultTerm;
	ccolor.greenMultTerm = color.greenMultTerm;
	ccolor.blueMultTerm = color.blueMultTerm;
	ccolor.alphaMultTerm = color.alphaMultTerm;
	ccolor.redAddTerm = color.redAddTerm;
	ccolor.greenAddTerm = color.greenAddTerm;
	ccolor.blueAddTerm = color.blueAddTerm;
	ccolor.alphaAddTerm = color.alphaAddTerm;
	return ccolor;
}
cocos2dCOLORFORM makeCocos2dCOLORFORMWithStream(bitStream *s)
{
	cocos2dCOLORFORM color;
	color.hasAddTerms = breadDWord(s);
	color.hasMultTerms = breadDWord(s);
	if(color.hasMultTerms)
	{
		color.redMultTerm = breadDWord(s);
		color.greenMultTerm = breadDWord(s);
		color.blueMultTerm = breadDWord(s);
		color.alphaMultTerm = breadDWord(s);
	}
	if(color.hasAddTerms)
	{
		color.redAddTerm = breadDWord(s);
		color.greenAddTerm = breadDWord(s);
		color.blueAddTerm = breadDWord(s);
		color.alphaAddTerm = breadDWord(s);
	}
	return color;
}

#define PI 3.1415926
#define PID 0.0174533
//make a cocos2d matrix for sprite
cocos2dMATRIX makeCocos2dMATRIX(const swfMATRIX& matrix)
{
	cocos2dMATRIX cmatrix;
	/*
	memset(&cmatrix,0,sizeof(cocos2dMATRIX));
	cmatrix.positionX = matrix.translateX/20.0;
	cmatrix.positionY = matrix.translateY/20.0;
	cmatrix.scaleX = matrix.scaleX;
	cmatrix.scaleY = matrix.scaleY;
	cmatrix.rotateSkewX = matrix.rotateSkew0*60.0;
	cmatrix.rotateSkewY = matrix.rotateSkew1*60.0;
	*/
	/*
	memset(&cmatrix,0,sizeof(cocos2dMATRIX));
	cmatrix.positionX = matrix.translateX/20.0;
	cmatrix.positionY = matrix.translateY/20.0;
	cmatrix.rotateSkewX = -asin(matrix.rotateSkew1)/PID;
	cmatrix.rotateSkewY = asin(matrix.rotateSkew0)/PID;
#ifdef _DEBUG
	float alphx,alphy;
	alphx = ::acosf(matrix.scaleX)/PID;
	alphy = ::acosf(matrix.scaleY)/PID;
//	cmatrix.rotateSkewX = (cmatrix.rotateSkewX>0.0) ? alphx : -alphx;
//	cmatrix.rotateSkewY = (cmatrix.rotateSkewY>0.0) ? alphy : -alphy;
#endif
	cmatrix.scaleX = matrix.scaleX;
	cmatrix.scaleY = matrix.scaleY;
	cmatrix.rotateSkewY = -cmatrix.rotateSkewY;
	*/
	memset(&cmatrix,0,sizeof(cocos2dMATRIX));
	cmatrix.positionX = matrix.translateX/20.0;
	cmatrix.positionY = matrix.translateY/20.0;
	cmatrix.scaleX = matrix.scaleX;
	cmatrix.scaleY = matrix.scaleY;
	cmatrix.rotateSkew0 = -matrix.rotateSkew0;
	cmatrix.rotateSkew1 = -matrix.rotateSkew1;
#if ZC_DEBUG==1
	
	CCLOG("this is matrix translate=====================================start");
	CCLOG("%s","matrix");
	CCLOG("position(%2f,%2f)",matrix.translateX/20.0,matrix.translateY/20.0);
	CCLOG("scale(%2f,%2f)",matrix.scaleX,matrix.scaleY);
	CCLOG("skew(%2f,%2f)",matrix.rotateSkew0,matrix.rotateSkew1);
	CCLOG("%s","cmatrix");
	CCLOG("position(%2f,%2f)",cmatrix.positionX,cmatrix.positionY);
	CCLOG("scale(%2f,%2f)",cmatrix.scaleX,cmatrix.scaleY);
	CCLOG("skew(%2f,%2f)",cmatrix.rotateSkew0,cmatrix.rotateSkew1);
	CCLOG("this is matrix translate=====================================end");
	
#endif//ZC_DEBUG==1
	return cmatrix;
}
cocos2dMATRIX makeCocos2dMATRIXWithStream(bitStream *s)
{
	cocos2dMATRIX cmatrix;
	memset(&cmatrix,0,sizeof(cocos2dMATRIX));
	cmatrix.scaleX = breadFloat(s);
	cmatrix.scaleY = breadFloat(s);
	cmatrix.rotateSkew0 = breadFloat(s);
	cmatrix.rotateSkew1 = breadFloat(s);
    cmatrix.positionX = breadFloat(s);
	cmatrix.positionY = breadFloat(s);
	return cmatrix;
}

//make a grad record from bits stream, shape1 = 1 ,shape2 = 2 and shape3 = 3
swfGRADRECORD makeGRADRECORD(bitStream* s,int shapeType)
{
	swfGRADRECORD gradRecord;
	gradRecord.ratio = breadByte(s);
	switch (shapeType)
	{
	case 1:
	case 2:
		gradRecord.color = makeRGB(s);
		break;
	case 3:
		gradRecord.color1 = makeRGBA(s);
		break;
	}
	return gradRecord;
}

//make a gradient from bits stream,
swfGRADIENT	makeGRADIENT(bitStream* s)
{
	swfGRADIENT gradient;
	gradient.spreadMode = breadUBit(s,2);
	gradient.interpolationMode = breadUBit(s,2);
	gradient.numGradients = breadUBit(s,4);
	for(int i=0 ; i<gradient.numGradients ; i++)
	{
		gradient.gradientRecords.assign(1,makeGRADRECORD(s,1));
	}
	return gradient;
}

swfFOCALGRADIENT makeFOCALGRADIENT(bitStream *s)
{
	swfFOCALGRADIENT focalGradient;
	focalGradient.spreadMode = breadUBit(s,2);
	focalGradient.interpolationMode = breadUBit(s,2);
	focalGradient.numGradients = breadUBit(s,4);
	for(int i=0 ; i<focalGradient.numGradients ; i++)
	{
		focalGradient.gradientRecords.assign(1,makeGRADRECORD(s,1));
	}
	focalGradient.focalPoint = breadWord(s);
	return focalGradient;
}