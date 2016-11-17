#ifndef _SWFTYPE_H_
#define _SWFTYPE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cocos2d.h>

using namespace cocos2d;

#define UI8 unsigned char
#define UI16 unsigned short
#define UI32 unsigned int
#define SI8 char
#define SI16 short
#define SI32 int
#define FIXED	unsigned int
#define FIXED8	unsigned short

#define TRUE    1
#define FALSE   0

#define swfArray	std::list

#define UDATA char*
#define FSTREAM FILE*

static const unsigned char bitflag[] = {0x00,0x80,0xc0,0xe0,0xf0,
0xf8,0xfc,0xfe,0xff};
static const unsigned char nbitflag[] = {0x00,0x01,0x03,0x07,0x0f,
0x1f,0x3f,0x7f,0xff};

static const unsigned char pndflag[] = {0x89,0x50,0x4e,0x47,0x0d,0x0a,0x1a,0x0a};

struct bitStream
{
	bitStream()
	{
		data = NULL;
		cOffset = 0;
		bOffset = 0;
		maxlen = 0;
		bit = 0;
	}
	unsigned char* data;
	int	  cOffset;
	int   bOffset;
	int	  maxlen;
	unsigned int bit;
};



unsigned int breadUBit(bitStream* s,int size);
int breadSBit(bitStream* s,int size);
float breadFBit(bitStream* s,int size);
unsigned char breadByte(bitStream* s);
unsigned short  breadWord(bitStream* s);
unsigned int	breadDWord(bitStream* s);
const char* breadString(bitStream *s);
float breadFloat(bitStream*s);

int byteAligment(bitStream* s);





class _RECT
{
public:
	_RECT(){}
	_RECT(FSTREAM data);
	_RECT(bitStream* s);
	~_RECT(){}
	int m_nXmin;
	int m_nXmax;
	int m_nYmin;
	int m_nYmax;
};



class _FILE
{

	_FILE(){};
public:
	static _FILE* Open(char* fname);
	~_FILE();
	int read(void* data,int size);
	int jumpTo(int offset);
	int getCurrent();
	FILE  *m_hFile; 
};



struct swfHeader{
	UI8	flag[3];
	UI8 version;
	UI32 fileLen;
	_RECT frameSize;
	UI16  frameRate;
	UI16  frameCount;
};

struct swfRGBA
{
	UI8	red;
	UI8	green;
	UI8	blue;
	UI8	alpha;
};
struct swfARGB
{
	UI8	alpha;
	UI8	red;
	UI8	green;
	UI8	blue;
};
struct swfRGB 
{
	UI8	red;
	UI8	green;
	UI8	blue;
};

swfRGBA makeRGBA(bitStream *s);
swfARGB makeARGB(bitStream *s);
swfRGB  makeRGB(bitStream *s);

/*
 * for any point (x,y) has (x1,y1)
 * x1 = x*scaleX + y*rotateSkew1 + translateX
 * y1 = y*scaleY + x*rotateSkew0 + translateY
*/

struct swfMATRIX 
{
	bool	hasScale;				//has scale values if equal to true , UB[1]
	int		nScaleBits;				//Bits in each scale value field , UB[5]
	float	scaleX;					//x scale value
	float	scaleY;					//y scale value
	bool	hasRotate;				//has rotate and skew values if equal to true , UB[1]
	int		nRotateBits;			//bits in each rotate value field , UB[5]
	float	rotateSkew0;			//first rotate and skew value
	float	rotateSkew1;			//second rotate and skew value
	int		nTranslateBits;			//bits in each translate value field , UB[5]
	int		translateX;				//x translate value in twips
	int		translateY;				//y translate value in twips
};
//make a matrix from bits stream
swfMATRIX makeMATRIX(bitStream* s);

/*
 * R' = max(0, min(((R * redMultTerm) /256) + redAddTerm, 255))
 * G' = max(0, min(((G * greenMultTerm) /256) + greenAddTerm, 255))
 * B' = max(0, min(((B * blueMultTerm) /256) + blueAddTerm, 255))
 * A' = max(0, min(((A * alphaMultTerm) /256) + alphaAddTerm, 255))
*/
struct swfCXFORMWITHALPHA 
{
	bool	hasAddTerms;			//has color addition values if equal to true ,  UB[1]
	bool	hasMultTerms;			//has color multiply values if equal to true ,  UB[1]
	UI8		nbits;					//bits in each value field , UB[4]
	SI32	redMultTerm;			//if hasMultTerms = 1 , SB[nbits] , red multiply value
	SI32	greenMultTerm;			//if hasMultTerms = 1 , SB[nbits] , green multiply value
	SI32	blueMultTerm;			//if hasMultTerms = 1 , SB[nbits] , blue multiply value
	SI32	alphaMultTerm;			//if hasMultTerms = 1 , SB[nbits] , alpha multiply value
	SI32	redAddTerm;				//if hasAddTerms = 1 , SB[nbits] , red addition value
	SI32	greenAddTerm;			//if hasAddTerms = 1 , SB[nbits] , green addition value
	SI32	blueAddTerm;			//if hasAddTerms = 1 , SB[nbits] , blue addition value
	SI32	alphaAddTerm;			//if hasAddTerms = 1 , SB[nbits] , alpha addition value
};
// make a color transform with alpha , record is byte aligned.
swfCXFORMWITHALPHA makeCXFORMWITHALPHA(bitStream *s);

struct cocos2dCOLORFORM
{
	SI32	hasAddTerms;
	SI32	hasMultTerms;
	SI32	redMultTerm;
	SI32	greenMultTerm;
	SI32	blueMultTerm;
	SI32	alphaMultTerm;
	SI32	redAddTerm;
	SI32	greenAddTerm;
	SI32	blueAddTerm;
	SI32	alphaAddTerm;
};
cocos2dCOLORFORM makeCocos2dCOLORFORM(const swfCXFORMWITHALPHA& color);
cocos2dCOLORFORM makeCocos2dCOLORFORMWithStream(bitStream *s);

struct cocos2dMATRIX
{
	float	scaleX;
	float	scaleY;
	float	rotateSkew0;
	float	rotateSkew1;
	float	positionX;
	float	positionY;
};
//make a cocos2d matrix for sprite
cocos2dMATRIX makeCocos2dMATRIX(const swfMATRIX& matrix);
cocos2dMATRIX makeCocos2dMATRIXWithStream(bitStream *s);

struct swfGRADRECORD 
{
	UI8		ratio;			//ratio value
	union{
		swfRGB	color;		//shape1 or shape2
		swfRGBA	color1;		//shape3
	};
};
//make a grad record from bits stream, shape1 = 1 ,shape2 = 2 and shape3 = 3
swfGRADRECORD makeGRADRECORD(bitStream* s,int shapeType);

struct swfGRADIENT 
{
	int		spreadMode;		//UB[2] , 0 = pad mode
							//		  1 = reflect mode
							//		  2 = repeat mode
							//		  3 = reserved
	int		interpolationMode;		//UB[2] , 0 = normal RGB mode interpolation
									//		  1 = linear RGB mode interpolation
									//		  2 and 3 = reserved
	int		numGradients;	//UB[4] , 1 to 15
	swfArray<swfGRADRECORD>	gradientRecords;		//numGradients GRADRECORD
};
//make a gradient from bits stream,
swfGRADIENT	makeGRADIENT(bitStream* s);

struct swfFOCALGRADIENT
{
	int spreadMode;			//UB[2] , 0 = pad mode
							//		  1 = reflect mode
							//		  2 = repeat mode
							//		  3 = reserved
	int interpolationMode;	//UB[2] , 0 = normal RGB mode interpolation
							//		  1 = linear RGB mode interpolation
							//		  2 and 3 = reserved
	int numGradients;		//UB[4] , 1 to 15
	swfArray<swfGRADRECORD>	gradientRecords;		//numGradients GRADRECORD
	FIXED8	focalPoint;		//focal point location
};
swfFOCALGRADIENT makeFOCALGRADIENT(bitStream *s);


class _Bitmap
{
public:
	_Bitmap();
	_Bitmap(_Bitmap &bitmap);
	virtual ~_Bitmap();

	_Bitmap operator=(const _Bitmap& bitmap);

	CCTexture2D	*m_pTexture;
	CCRect		 m_iRect;
	int			 m_nBitmapId;
	UI8			*m_hData;
	UI32		 m_nDatalen;
	bool		 m_bPng;
};

class _Element
{
public:
	_Element();
	~_Element();
public:
	UI32				m_nCid;
	UI32				m_nClipDepth;
	UI32				m_bHasMatrix;
	cocos2dMATRIX		m_iMatrix;
	UI32				m_bHasColorF;
	cocos2dCOLORFORM	m_iColorForm;
};

//resource dictionary
typedef	std::map<int,_Bitmap*> swfDictionary;
//display list
typedef std::map<int,_Element*> displayList;

void cleanDictionary();
_Bitmap* getBitmapFromDictionary(int id);
bool setBitmapToDictionary(int id,_Bitmap *bitmap);
swfDictionary* getDictionary();

void cleanDisplayList();
displayList* getDisplayList();
void removeElement(int depth);
void addElement(int depth,_Element* element);

#ifdef _DEBUG
#define swfCleanLog() {FILE *fl = fopen("log.txt","w"); \
						if(fl != NULL) \
						{	fprintf(fl,"");\
							fclose(fl);	\
						}\
					}
#define swfLog(msgformat,x1,x2) {FILE *fl = fopen("log.txt","a"); \
							if(fl != NULL) \
							{	fprintf(fl,msgformat,x1,x2);\
								fclose(fl);	\
							}\
						}
#define swfByteLog(bytebuf,len) {FILE *fl = fopen("log.txt","a"); \
									if(fl != NULL) \
									{	fwrite(bytebuf,1,len,fl);\
										fclose(fl);	\
									}\
								}
#else
#define swfCleanLog()
#define swfLog(msgformat,x1,x2) 
#define swfByteLog(bytebuf,len)
#endif

#endif