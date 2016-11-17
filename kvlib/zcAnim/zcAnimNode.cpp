#include "zcAnimNode.h"
#include "zcAnimSprite.h"
#if(ISLUA==1)
    #include "CCLuaEngine.h"
#endif

#include "zcSuperCatch.h"

#ifdef WIN32

displayList iPlaceList;

displayList* getPlaceList()
{
	return &iPlaceList;
}
#endif//win32

//using namespace cocos2d;


/*  changed by yock in 
//this is a frame cache opertion
class SuperPsz
{
public:
    SuperPsz() : 
    m_rPszName("")
    {
        m_iReference = 1;
    }
    ~SuperPsz()
    {
        m_rPszName.clear();
    }
public:
    static SuperPsz* create(const char *psz);
    bool init(std::string psz);
    void retain();
    void release();
public:
    std::string m_rPszName;
protected:
    int         m_iReference;
};
static std::map<std::string, SuperPsz*> iSuperPszMap;

SuperPsz* SuperPsz::create(const char *psz)
{
    std::map<std::string, SuperPsz*>::iterator it;
    std::string key = psz;
    it = iSuperPszMap.find(key);
    if(it != iSuperPszMap.end())
        return it->second;
    SuperPsz* sp = new SuperPsz();
    if(sp->init(key))
    {
        iSuperPszMap[sp->m_rPszName] = sp;
        return sp;
    }
    delete sp;
    return NULL;
}

bool SuperPsz::init(std::string psz)
{
    if(psz.size()<=0) return false;
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(psz.c_str());
    m_rPszName = psz;
    iSuperPszMap[psz] = this;
    return true;
}
void SuperPsz::retain()
{
    m_iReference++;
}
void SuperPsz::release()
{
    m_iReference--;
    if(m_iReference<=0)
    {
        iSuperPszMap.erase(m_rPszName);
        CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile(m_rPszName.c_str());
        delete this;
    }
}

class SuperAnim
{
public:
    SuperAnim();
    ~SuperAnim();
public:
    static SuperAnim* create(const char* animName);
    bool init(std::string anim);
    void retain();
    void release();
public:
    zcanim_tag *m_pTaglist;
    std::string m_iAnimName;
protected:
    int         m_nReference;
};

std::map<std::string, SuperAnim*> iSuperAnimMap;

SuperAnim::SuperAnim()
: m_iAnimName("")
{
    m_pTaglist = NULL;
    m_nReference = 1;
}
SuperAnim::~SuperAnim()
{
    m_iAnimName.clear();
    while(m_pTaglist)
    {
        zcanim_tag *tag = m_pTaglist;
        m_pTaglist = m_pTaglist->getNext();
        delete tag;
    }
}

SuperAnim* SuperAnim::create(const char* animName)
{
    std::map<std::string, SuperAnim*>::iterator it;
    std::string key = animName;
    it = iSuperAnimMap.find(key);
    if(it != iSuperAnimMap.end())
    {
        return it->second;
    }
    SuperAnim* anim = new SuperAnim();
    if(anim->init(key))
    {
        iSuperAnimMap[anim->m_iAnimName] = anim;
        return anim;
    }
    delete anim;
    return NULL;
}

bool SuperAnim::init(std::string anim)
{
    std::string name = CCFileUtils::sharedFileUtils()->fullPathForFilename(anim.c_str());
    m_pTaglist = zcanim_tag_factory::createTagList(name.c_str());
    if(m_pTaglist == NULL)
        return false;
    else 
    {
        m_iAnimName = anim;
        return true;
    }
}
void SuperAnim::retain()
{
    m_nReference++;
}
void SuperAnim::release()
{
    m_nReference--;
    if(m_nReference<=0)
    {
        iSuperAnimMap.erase(m_iAnimName);
        delete this;
    }
}
*/


#define zc_min(m,n) ((m)<(n) ? (m) : (n))
#define zc_max(m,n) ((m)>(n) ? (m) : (n))
#define fixed8 0x00000100L
#define fixed8Tofloat(x) ((float)(x)/fixed8)


zcAnimNode::zcAnimNode(void):
m_iCurSectionName("")
#ifndef WIN32
,m_iAnimName("")
,m_iFramePoolName("")
#endif//win32
{
//	m_pDisplayList = NULL;
	m_pOpraterList = NULL;		//oprater list
	m_fDuration = 0.0f;		//every frame duration
	m_pResourceDictionary = NULL;
	m_bPause = false;
	m_bPlaying = false;
    m_bEntering = false;
	m_nCurFrameIndex = 0;
	m_fRhythm = 1.0f;			//the phythm for real duration (realDuration = duration*rhythm)
	m_nId = 0;				//the id with this anim
	m_nScriptObserverId = 0;//
    m_nScriptAnchorId = 0;
	m_hObserver = NULL;
	m_bFlipX = false;
	m_bFlipY = false;
    m_tColor = Color3B(0xff, 0xff, 0xff);
    m_nOpacity = 255;
	m_fUpDurt = 0.0;
    
    m_hPszHandle = NULL;
    m_hAnimHandle = NULL;
    
    m_pLastAnimTag = NULL;
    m_nAnimFramesCount = 0;
    
    m_nMaxComponent = 0;
    m_pComponentFlag = NULL;
    m_nScriptComponent = 0;
    
    memset(&m_iMatrix, 0, sizeof(cocos2dMATRIX));
    m_iMatrix.scaleX = 1.0;
    m_iMatrix.scaleY = 1.0;
//    m_iMatrix.scaleX = -0.44807;
//    m_iMatrix.rotateSkew1 = 0.89400;
//    m_iMatrix.rotateSkew0 = -0.89400;
//    m_iMatrix.scaleY = -0.44807;
}


zcAnimNode::~zcAnimNode(void)
{
	m_iKeyframeDictionary.clear();
	m_iCurSectionName.clear();
#ifdef WIN32
	cleanWin32tagList();
	cleanDictionary();
	cleanDisplayList();
#else
    m_pOpraterList = NULL;
    if(m_hPszHandle)
        m_hPszHandle->release();
    if(m_hAnimHandle)
        m_hAnimHandle->release();
    if(m_pResourceDictionary)
        delete m_pResourceDictionary;
    unregisterScriptTapHandler();
    unregisterScriptAnchor();
    unregisterComponent();
    m_iKeyAllFramesCount.clear();
//    CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(zcAnimNode::update),this);
    if(m_pComponentFlag != NULL)
        delete m_pComponentFlag;
#endif
}


zcAnimNode* zcAnimNode::create(const char* fname,int theId, const char* plistName)
{
	zcAnimNode *node = new zcAnimNode();
	if(node->init(fname,theId,plistName,NULL))
	{
		node->autorelease();
		return node;
	}
	delete node;
	return NULL;
}
zcAnimNode* zcAnimNode::create(const char* fname,int theId, const char* plistName,zcAnimNodeListenter *theListenter)
{
	zcAnimNode *node = new zcAnimNode();
	if(node->init(fname,theId,plistName,theListenter))
	{
		node->autorelease();
		return node;
	}
	delete node;
	return NULL;
}

void zcAnimNode::removeAllUnusing()
{
    SuperAnim::removeUnusing();
    SuperPsz::removeUnusing();
}

#ifdef WIN32
zcAnimNode* zcAnimNode::create(int theId,zcAnimNodeListenter* listenter)
{
	zcAnimNode *node = new zcAnimNode();
	if(node->init(NULL,theId,listenter))
	{
		node->autorelease();
		node->m_pOpraterList = getWin32tagList();
		node->m_pResourceDictionary = getDictionary();
		zcanim_handle* handle = (zcanim_handle*)(node->m_pOpraterList);
		node->m_fDuration = 1.0/handle->m_fRate;
#ifdef zcDebug
		int frameCount = 0;
		int tagCount = 0;
#endif
		for(zcanim_tag* i = node->m_pOpraterList ; i!=NULL ; i=i->m_pNext)
		{
			if(i->getTag() == EzcLable)
			{
				node->m_iKeyframeDictionary[((zcanim_lable*)i)->m_iName] = i;
#ifdef zcDebug
				CCLOG("frame id = %d ,tag id = %d , name = %s",frameCount,tagCount,((zcanim_lable*)i)->m_iName.c_str());
#endif
			}
#ifdef zcDebug
			if(i->getTag() == EzcShow)
				frameCount++;
			tagCount++;
#endif
		}
		return node;
	}
	delete node;
	return NULL;
}
#endif
void zcAnimNode::setBlendFunc(const BlendFunc &blendFunc)
{
    _blendFunc = blendFunc;
//    CCObject* pObject = NULL;
//    CCARRAY_FOREACH(_children, pObject)
//    {
//        CCNode* pChild = dynamic_cast<CCNode*>(pObject);
//        if (pChild)
//        {
//            pChild->setBlendFunc(blendFunc);
//        }
//    }
}
void zcAnimNode::setOpacity(GLubyte opacity)
{
    m_nOpacity = MAX(0, MIN(255,opacity));
//    CCObject* pObject = NULL;
//    CCARRAY_FOREACH(_children, pObject)
//    {
//        CCNode* pChild = dynamic_cast<CCNode*>(pObject);
//        if (pChild)
//        {
//            pChild->setOpacity(m_nOpacity);
//        }
//    }
    
    Node::setOpacity(m_nOpacity);
    return;
}

bool zcAnimNode::init(const char* fname,int theId, const char* plistName,zcAnimNodeListenter *theListenter)
{
	m_nId = theId;
	m_hObserver = theListenter;
    m_iAnimName = fname;
    m_iFramePoolName = plistName;
    m_hAnimHandle = SuperAnim::create(m_iAnimName.c_str());
    if(m_hAnimHandle)
    {
        m_hAnimHandle->retain();
        m_hPszHandle = SuperPsz::create(m_iFramePoolName.c_str());
        if(m_hPszHandle)
        {
            m_hPszHandle->retain();
            std::string path = cocos2d::FileUtils::getInstance()->fullPathForFilename(plistName);
            const char *pszPath = path.c_str();
            cocos2d::Dictionary *dict = cocos2d::Dictionary::createWithContentsOfFileThreadSafe(pszPath);
            cocos2d::Dictionary* metadataDict = (cocos2d::Dictionary*)dict->objectForKey("metadata");
            std::string texturePath = metadataDict->valueForKey("textureFileName")->getCString();
            initWithFile(texturePath.c_str(), 50);
            
            m_pResourceDictionary = new resourceDeictionary();
            m_pOpraterList = m_hAnimHandle->m_pTaglist;
            for(zcanim_tag *i = m_pOpraterList ; i!=NULL ; i = i->getNext())
            {
                switch (i->getTag())
                {
                    case EzcHandle:
                    {
                        zcanim_handle *handle = (zcanim_handle*)i;
                        m_fDuration = 1.0 / handle->m_fRate;
                        float scale = Director::getInstance()->getContentScaleFactor();
//                        scale = 2;
                        setContentSize(Size(handle->m_nFrameWidth/scale,handle->m_nFrameHeight/scale));
                    }
                        break;
                    case EzcLable:
                    {
                        if(m_pLastAnimTag == NULL)
                        {
                            m_pLastAnimTag = i;
                            m_nAnimFramesCount=0;
                        }
                        else
                        {
                            m_iKeyAllFramesCount[((zcanim_lable*)m_pLastAnimTag)->m_iName] = m_nAnimFramesCount;
                            m_nAnimFramesCount=0;
                            m_pLastAnimTag=i;
                        }
                        m_iKeyframeDictionary[((zcanim_lable*)i)->m_iName] = i;
                    }
                        break;
                    case EzcShow:
                    {
                        m_nAnimFramesCount++;
                    }
                        break;
                        
                    case EzcImage:
                    {
                        (*m_pResourceDictionary)[((zcanim_image*)i)->m_nCid] = ((zcanim_image*)i)->m_iName;
                        m_iReverseResource[((zcanim_image*)i)->m_iName].push_back(((zcanim_image*)i)->m_nCid);
                        if(m_nMaxComponent<((zcanim_image*)i)->m_nCid)
                        {
                            m_nMaxComponent = ((zcanim_image*)i)->m_nCid;
                        }
//                        CCLOG("image name %s",((zcanim_image*)i)->m_iName.c_str());
                    }
                        break;
                }
            }
            if(m_pLastAnimTag != NULL)      //get last animation frames count  , changed by yock in 2013,10,22
            {
                m_iKeyAllFramesCount[((zcanim_lable*)m_pLastAnimTag)->m_iName] = m_nAnimFramesCount;
                m_nAnimFramesCount=0;
                m_pLastAnimTag=NULL;
            }
            m_nMaxComponent+=1;
            if(m_pComponentFlag!=NULL)
                delete m_pComponentFlag;
            m_pComponentFlag = new int[m_nMaxComponent];
            memset(m_pComponentFlag, 0, m_nMaxComponent*sizeof(int));
#ifdef DEBUG
//            printf("----------------------------print----------------------");
//            for (int i=0; i<m_nMaxComponent; i++) {
//                printf("m_pComponentFlag[%d]:%d\n",i,m_pComponentFlag[i]);
//            }
#endif
            ignoreAnchorPointForPosition(false);
            setAnchorPoint(Point(0.5,0.5));
//            cocos2d::CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(zcAnimNode::updateMovie),this,1.0/60,false);
            CC_SAFE_RELEASE(dict);
            return true;
        }
        m_hAnimHandle->release();
    }
	return false;
}
void zcAnimNode::updateMovie(float dt)
{
	if(m_bPause || !m_bPlaying || !m_bEntering) return;
	m_fUpDurt+=dt;
	if(m_fUpDurt>=m_fRhythm*m_fDuration)
	{
		changedFrame();
		m_fUpDurt = 0.0f;
	}
}

bool zcAnimNode::playSection(std::string theLabelName)
{
    if(theLabelName.compare("gongji4_2") == 0)
    {
        int a = 0;
        a = 1;
    }
	std::map<std::string,zcanim_tag*>::iterator it;
//	int size = m_iKeyframeDictionary.size();
	it = m_iKeyframeDictionary.find(theLabelName);
	if(it != m_iKeyframeDictionary.end())
	{
		removeAllChildrenWithCleanup(true);
		m_iCurSectionName = theLabelName;
		m_pCurTag = it->second;
		m_bPlaying = true;
		m_nCurFrameIndex = 0;
		changedFrame();
#ifdef _DEBUG
		m_bPause = false;
#endif
		return true;
	}
    else
    {
        CCLOG("%s not has animation %s",m_iAnimName.c_str(),theLabelName.c_str());
    }
	return false;
}
void zcAnimNode::pause()
{
	m_bPause = true;
}
void zcAnimNode::resume()
{
	m_bPause = false;
}
bool zcAnimNode::isPause()
{
	return m_bPause;
}
bool zcAnimNode::isPlaying()
{
	return m_bPlaying;
}
int zcAnimNode::getCurFrame()
{
	return m_nCurFrameIndex;
}
std::string zcAnimNode::getCurSectionName()
{
	return m_iCurSectionName;
}
bool zcAnimNode::hasSection(std::string theLabelName)
{
	std::map<std::string,zcanim_tag*>::iterator it;
	it = m_iKeyframeDictionary.find(theLabelName);
	return it != m_iKeyframeDictionary.end();
}
void zcAnimNode::setRhythm(float rhythm)
{
	m_fRhythm = rhythm;
}
float zcAnimNode::getRhythm()
{
	return m_fRhythm;
}

void zcAnimNode::registerScriptTapHandler(int nHandler)
{
	unregisterScriptTapHandler();
	m_nScriptObserverId = nHandler;
}
void zcAnimNode::unregisterScriptTapHandler()
{
	if(m_nScriptObserverId)
	{
		ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nScriptObserverId);
		m_nScriptObserverId=0;
	}
}
void zcAnimNode::registerScriptAnchor(int nHandler)
{
    unregisterScriptAnchor();
    m_nScriptAnchorId = nHandler;
}
void zcAnimNode::unregisterScriptAnchor()
{
    if(m_nScriptAnchorId)
    {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nScriptAnchorId);
        m_nScriptAnchorId=0;
    }
}
void zcAnimNode::registerComponent(int nHandler)
{
    unregisterComponent();
    m_nScriptComponent = nHandler;
}

void zcAnimNode::unregisterComponent()
{
    if(m_nScriptComponent)
    {
        ScriptEngineManager::getInstance()->getScriptEngine()->removeScriptHandler(m_nScriptComponent);
        m_nScriptComponent=0;
    }
}

int zcAnimNode::getId()
{
	return m_nId;
}

void zcAnimNode::setComponentId(std::string flag)
{
//    if(flag<0 || flag>=m_nMaxComponent)
//        return;
//    m_pComponentFlag[flag]=1;
    int flagId = 1;
    
    int offsetdon = (int)flag.find_last_of('.');
    int offsetch = (int)flag.find_last_of('f');
    std::string temp = flag.substr(offsetch+1 , offsetdon-offsetch-1);
    flagId = atoi(temp.c_str());
    
    std::map<std::string,std::list<int> >::iterator  listit;
    std::list<int>::iterator it;
    listit = m_iReverseResource.find(flag);
    if(listit == m_iReverseResource.end())
        return;
    for(it = listit->second.begin(); it!=listit->second.end() ; ++it)
    {
        int realflag = *it;
        if(realflag<0 || realflag>=m_nMaxComponent)
            return;
        m_pComponentFlag[realflag]=flagId;
    }
    
}
void zcAnimNode::resetComponentId(std::string flag)
{
//    if(flag<0 || flag>=m_nMaxComponent)
//        return;
//    m_pComponentFlag[flag]=0;
    std::map<std::string,std::list<int> >::iterator  listit;
    std::list<int>::iterator it;
    listit = m_iReverseResource.find(flag);
    if(listit == m_iReverseResource.end())
        return;
    for(it = listit->second.begin(); it!=listit->second.end() ; ++it)
    {
        int realflag = *it;
        if(realflag<0 || realflag>=m_nMaxComponent)
            return;
        m_pComponentFlag[realflag]=0;
    }
}


void zcAnimNode::setFlipX(bool fx)
{
   
	m_bFlipX = fx;
    ssize_t ccount = getChildrenCount();
    if(ccount<=0) return;
    for(int i=0 ; i<ccount ; i++)
    {
        zcAnimSprite *sprite;
        sprite = (zcAnimSprite*)(_children.at(i));
        sprite->setFlipX(m_bFlipX);
    }
}
void zcAnimNode::setFlipY(bool fy)
{
	m_bFlipY = fy;
    ssize_t ccount = getChildrenCount();
    if(ccount<=0) return;
    for(int i=0 ; i<ccount ; i++)
    {
        zcAnimSprite *sprite;
        sprite = (zcAnimSprite*)(_children.at(i));
        sprite->setFlipY(m_bFlipY);
    }
}
bool zcAnimNode::getFlipX()
{
	return m_bFlipX;
}
bool zcAnimNode::getFlipY()
{
	return m_bFlipY;
}

void zcAnimNode::setColor(const Color3B& color)
{
   
    m_tColor = color;
    ssize_t ccount = getChildrenCount();
    if(ccount<=0) return;
    for(int i=0 ; i<ccount ; i++)
    {
        zcAnimSprite *sprite;
        sprite = (zcAnimSprite*)(_children.at(i));
        sprite->setColor(m_tColor);
    }
}

void zcAnimNode::setPosition(const cocos2d::Point& pt)
{
    
	Node::setPosition(pt);

    /*
>>>>>>> .r480
	int z = pt.y;
	_setZOrder(-z);
	if(m_pParent)
		m_pParent->reorderChild(this,-z);
<<<<<<< .mine
     */
     

}

void zcAnimNode::setMatrix(const cocos2dMATRIX& matrix)
{
    m_iMatrix = matrix;
    
    if(m_bFlipX)
    {
        m_iMatrix.scaleX = -m_iMatrix.scaleX;
        m_iMatrix.rotateSkew1 = -m_iMatrix.rotateSkew1;
    }
    if(m_bFlipY)
    {
        m_iMatrix.scaleY = -m_iMatrix.scaleY;
        m_iMatrix.rotateSkew0 = -m_iMatrix.rotateSkew0;
    }
}

const cocos2dMATRIX* zcAnimNode::getMatrix()
{
    return &m_iMatrix;
}

    /** callback that is called every time the CCNode enters the 'stage'.
     If the CCNode enters the 'stage' with a transition, this callback is called when the transition starts.
     During onEnter you can't a "sister/brother" node.
     */

void zcAnimNode::onEnter()
{
    Node::onEnter();
        Director::getInstance()->getScheduler()->scheduleSelector(schedule_selector(zcAnimNode::updateMovie),this,1/60.0f,false);
//    this->schedule(schedule_selector(zcAnimNode::updateMovie), 1/60.0f);
    m_bEntering = true;
}


    /** callback that is called every time the CCNode leaves the 'stage'.
     If the CCNode leaves the 'stage' with a transition, this callback is called when the transition finishes.
     During onExit you can't access a sibling node.
     */

void zcAnimNode::onExit()
{
    Node::onExit();
    m_bEntering = false;
    Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
//    this->unschedule(schedule_selector(zcAnimNode::updateMovie));
    
}


void zcAnimNode::changedFrame()
{
	if(m_pCurTag == NULL)
	{
		m_bPlaying = false;
		if(m_hObserver)
			m_hObserver->OnAnimSectionEnd(this,m_nId,m_iCurSectionName);
#if (ISLUA==1)
        if(m_nScriptObserverId>0)
        {
            LuaEngine *m_engine = (LuaEngine*)ScriptEngineManager::getInstance()->getScriptEngine();
            LuaStack* luaStack = m_engine->getLuaStack();
            luaStack->pushObject(this, "zcAnimNode");
            luaStack->pushInt(m_nId);
            luaStack->pushString(m_iCurSectionName.c_str());
            luaStack->executeFunctionByHandler(m_nScriptObserverId, 3);
            luaStack->clean();
        }
#endif
		return;
	}
	while(m_pCurTag)
	{
		int tagid = m_pCurTag->getTag();
		switch (tagid)
		{
		case EzcPlace:
			{
				zcanim_place *tag = (zcanim_place *)m_pCurTag;
				cocos2dMATRIX matrix = tag->getMatrix();
				int cid = tag->getCid();
				if(cid>0)
				{
					resourceDeictionary::iterator it;
					it = m_pResourceDictionary->find(cid);
					if(it == m_pResourceDictionary->end())
                    {
#ifndef DEBUG
                        m_pCurTag = m_pCurTag->getNext();
#else
                        CCLOG("cid = %d not fond",cid);
                        m_pCurTag = m_pCurTag->getNext();
#endif
                        return;
                    }
					/*
					CCSprite *sprite = createCCSprite(it->second);
					sprite->setPosition(ccp(matrix.positionX,matrix.positionY));
					sprite->setScaleX(matrix.scaleX);
					sprite->setScaleY(matrix.scaleY);
					sprite->setSkewX(matrix.rotateSkewX);
					sprite->setSkewY(matrix.rotateSkewY);
					*/
					zcAnimSprite *sprite = createCCSprite(it->second);
					if(sprite)
					{
						
						zcAnimSprite *old = (zcAnimSprite *)getChildByTag(tag->getDepth());
						if(old)
						{
                            sprite->asSameAs(old);
							old->removeFromParentAndCleanup(true);
						}
                        if(tag->m_bHasMatrix)
							sprite->setMatrix(matrix);
						if(tag->m_bHasColorF)
							sprite->setColorForm(tag->m_iColorForm);
                        if(m_hObserver)
                        {
                            if(m_pComponentFlag[cid])
                            {
                                Point pt = sprite->getPosition();
                                cocos2dMATRIX matrix = sprite->m_iMatrix;
                                matrix.positionX=0;
                                matrix.positionY=0;
                                if(sprite->m_bAnimFlipX)
                                {
                                    matrix.scaleX = -matrix.scaleX;
                                    matrix.rotateSkew0 = -matrix.rotateSkew0;
                                }
                                if(sprite->m_bAnimFlipY)
                                {
                                    matrix.scaleY = -matrix.scaleY;
                                    matrix.rotateSkew1 = -matrix.rotateSkew1;
                                }
                                float z = this->getLocalZOrder();
                                cocos2dCOLORFORM mtrx = sprite->m_iColorTrans;
                                float a = 0;
                                if(mtrx.hasMultTerms)
                                {
                                    a = (a * fixed8Tofloat(mtrx.alphaMultTerm));
                                }
                                if(mtrx.hasAddTerms)
                                {
                                    a = zc_max(0, zc_min(a + mtrx.alphaAddTerm, 255));
                                }
                                m_hObserver->OnComponent(this , m_nId , m_pComponentFlag[cid] , pt , matrix , z , a);
                            }
                        }
#if (ISLUA==1)
                        if(m_nScriptComponent)
                        {
                            if(m_pComponentFlag[cid])
                            {
//                                CCLOG("%d,cid:%d,maxid:%d",m_pComponentFlag[cid],cid,m_nMaxComponent);
                                Point pt = sprite->getPosition();
                                cocos2dMATRIX matrix = sprite->m_iMatrix;
                                matrix.positionX=0;
                                matrix.positionY=0;
                                LuaEngine *m_engine = (LuaEngine*)ScriptEngineManager::getInstance()->getScriptEngine();
                                LuaStack* luaStack = m_engine->getLuaStack();
                                if(sprite->m_bAnimFlipX)
                                {
                                    matrix.scaleX = -matrix.scaleX;
                                    matrix.rotateSkew0 = -matrix.rotateSkew0;
                                }
                                if(sprite->m_bAnimFlipY)
                                {
                                    matrix.scaleY = -matrix.scaleY;
                                    matrix.rotateSkew1 = -matrix.rotateSkew1;
                                }
                                
                                float z = this->getLocalZOrder();
                                cocos2dCOLORFORM mtrx = sprite->m_iColorTrans;
                                float a = 0;
                                if(mtrx.hasMultTerms)
                                {
                                    a = (a * fixed8Tofloat(mtrx.alphaMultTerm));
                                }
                                if(mtrx.hasAddTerms)
                                {
                                    a = zc_max(0, zc_min(a + mtrx.alphaAddTerm, 255));
                                }
                                
                                luaStack->pushObject(this, "zcAnimNode");
                                luaStack->pushInt(m_nId);
                                luaStack->pushInt(m_pComponentFlag[cid]);
                                luaStack->pushFloat(pt.x);
                                luaStack->pushFloat(pt.y);
                                luaStack->pushFloat(matrix.scaleX);
                                luaStack->pushFloat(matrix.scaleY);
                                luaStack->pushFloat(matrix.rotateSkew0);
                                luaStack->pushFloat(matrix.rotateSkew1);
                                luaStack->pushFloat(z);
                                luaStack->pushFloat(a);
                                luaStack->executeFunctionByHandler(m_nScriptComponent, 11);
                                luaStack->clean();
                            }
                        }
#endif
                        sprite->setCid(cid);
						this->addChild(sprite,tag->getRealDepth(),tag->getDepth());
					}
					else
					{
//						CCLOG("resource is not bitmap cid = %d",tag->getCid());
					}
				}
				else
				{
					/*
					CCSprite *sprite = (CCSprite*)getChildByTag(tag->getDepth());
					sprite->setPosition(ccp(matrix.positionX,matrix.positionY));
					sprite->setScaleX(matrix.scaleX);
					sprite->setScaleY(matrix.scaleY);
					sprite->setSkewX(matrix.rotateSkewX);
					sprite->setSkewY(matrix.rotateSkewY);
					*/
					zcAnimSprite *sprite = (zcAnimSprite*)getChildByTag(tag->getDepth());
					if(sprite)
					{
						if(tag->m_bHasMatrix)
							sprite->setMatrix(matrix);
						if(tag->m_bHasColorF)
							sprite->setColorForm(tag->m_iColorForm);
                        
                        if(m_hObserver)
                        {
                            int tempCid = sprite->getCid();
                            if(m_pComponentFlag[tempCid])
                            {
                                Point pt = sprite->getPosition();
                                cocos2dMATRIX matrix = sprite->m_iMatrix;
                                matrix.positionX=0;
                                matrix.positionY=0;
                                if(sprite->m_bAnimFlipX)
                                {
                                    matrix.scaleX = -matrix.scaleX;
                                    matrix.rotateSkew0 = -matrix.rotateSkew0;
                                }
                                if(sprite->m_bAnimFlipY)
                                {
                                    matrix.scaleY = -matrix.scaleY;
                                    matrix.rotateSkew1 = -matrix.rotateSkew1;
                                }
                                float z = sprite->getLocalZOrder();
                                cocos2dCOLORFORM mtrx = sprite->m_iColorTrans;
                                float a = 0;
                                if(mtrx.hasMultTerms)
                                {
                                    a = (a * fixed8Tofloat(mtrx.alphaMultTerm));
                                }
                                if(mtrx.hasAddTerms)
                                {
                                    a = zc_max(0, zc_min(a + mtrx.alphaAddTerm, 255));
                                }
                                m_hObserver->OnComponent(this,m_nId,m_pComponentFlag[tempCid], pt, matrix , z , a);
                            }
                        }
#if (ISLUA==1)
                        if(m_nScriptComponent)
                        {
                            int tempCid = sprite->getCid();
                            if(m_pComponentFlag[tempCid])
                            {
                                Point pt = sprite->getPosition();
                                cocos2dMATRIX matrix = sprite->m_iMatrix;
                                matrix.positionX=0;
                                matrix.positionY=0;
                                LuaEngine *m_engine = (LuaEngine*)ScriptEngineManager::getInstance()->getScriptEngine();
                                LuaStack* luaStack = m_engine->getLuaStack();
                                luaStack->pushObject(this, "zcAnimNode");
                                if(sprite->m_bAnimFlipX)
                                {
                                    matrix.scaleX = -matrix.scaleX;
                                    matrix.rotateSkew0 = -matrix.rotateSkew0;
                                }
                                if(sprite->m_bAnimFlipY)
                                {
                                    matrix.scaleY = -matrix.scaleY;
                                    matrix.rotateSkew1 = -matrix.rotateSkew1;
                                }
                                
                                float z = this->getZOrder();
                                cocos2dCOLORFORM mtrx = sprite->m_iColorTrans;
                                float a = 0;
                                if(mtrx.hasMultTerms)
                                {
                                    a = (a * fixed8Tofloat(mtrx.alphaMultTerm));
                                }
                                if(mtrx.hasAddTerms)
                                {
                                    a = zc_max(0, zc_min(a + mtrx.alphaAddTerm, 255));
                                }
                                
                                luaStack->pushInt(m_nId);
                                luaStack->pushInt(m_pComponentFlag[tempCid]);
                                luaStack->pushFloat(pt.x);
                                luaStack->pushFloat(pt.y);
                                luaStack->pushFloat(matrix.scaleX);
                                luaStack->pushFloat(matrix.scaleY);
                                luaStack->pushFloat(matrix.rotateSkew0);
                                luaStack->pushFloat(matrix.rotateSkew1);
                                luaStack->pushFloat(z);
                                luaStack->pushFloat(a);
                                luaStack->executeFunctionByHandler(m_nScriptComponent, 11);
                                luaStack->clean();
                            }
                        }
#endif
					}
				}
				m_pCurTag = m_pCurTag->getNext();

			}
			break;
		case EzcRemove:
			{
				zcanim_remove *tag = (zcanim_remove*)m_pCurTag;
				this->removeChildByTag(tag->getDepth(),true);
				m_pCurTag = m_pCurTag->getNext();
			}
			break;
		case EzcShow:
			{
				m_pCurTag = m_pCurTag->getNext();
				m_nCurFrameIndex++;
#ifdef _DEBUG
				/*
				if(m_nCurFrameIndex>=0)
				{
					m_bPause = true;
				}
				*/
#endif
				return;
			}
			break;
		case EzcLable:
			{
				if(((zcanim_lable*)m_pCurTag)->m_iName.compare(m_iCurSectionName) == 0)
				{
					m_pCurTag = m_pCurTag->getNext();
					break;
				}
				m_bPlaying = false;
				m_fUpDurt = 0.0f;
				m_pCurTag = NULL;
				if(m_hObserver)
					m_hObserver->OnAnimSectionEnd(this,m_nId,m_iCurSectionName);
#if (ISLUA==1)
                if(m_nScriptObserverId>0)
                {
                    LuaEngine *m_engine = (LuaEngine*)ScriptEngineManager::getInstance()->getScriptEngine();
                    LuaStack* luaStack = m_engine->getLuaStack();
                    luaStack->pushObject(this, "zcAnimNode");
                    luaStack->pushInt(m_nId);
                    luaStack->pushString(m_iCurSectionName.c_str());
                    luaStack->executeFunctionByHandler(m_nScriptObserverId, 3);
                    luaStack->clean();
                }
#endif
				return;
			}
			break;
        case EzcAnchor:
            {
                zcanim_anchor *tag = (zcanim_anchor*)m_pCurTag;
                if(m_hObserver)
                    m_hObserver->OnAnchor(this, m_nId, tag->getStr());
#if (ISLUA==1)
                if(m_nScriptAnchorId>0)
                {
                    LuaEngine *m_engine = (LuaEngine*)ScriptEngineManager::getInstance()->getScriptEngine();
                    LuaStack* luaStack = m_engine->getLuaStack();
                    luaStack->pushObject(this, "zcAnimNode");
                    luaStack->pushInt(m_nId);
                    luaStack->pushString(tag->getStr().c_str());
                    luaStack->executeFunctionByHandler(m_nScriptAnchorId, 3);
                    luaStack->clean();
                }
#endif
                m_pCurTag = m_pCurTag->getNext();
            }
            break;
		default:
			{
//				CCLOG("changed frame default tag id = %d",m_pCurTag->getTag());
				m_pCurTag = m_pCurTag->getNext();
			}
			break;
		}
	}
}
void zcAnimNode::setMatrixValue(float scaleX,float scaleY,float rotationX,float rotationY)
{
    m_iMatrix.positionX = 0;
    m_iMatrix.positionY = 0;
    m_iMatrix.scaleX = scaleX;
    m_iMatrix.scaleY = scaleY;
    m_iMatrix.rotateSkew0 = rotationX;
    m_iMatrix.rotateSkew1 = rotationY;
    
//    if(m_bFlipX)
//    {
//        m_iMatrix.scaleX = -m_iMatrix.scaleX;
//        m_iMatrix.rotateSkew1 = -m_iMatrix.rotateSkew1;
//    }
//    if(m_bFlipY)
//    {
//        m_iMatrix.scaleY = -m_iMatrix.scaleY;
//        m_iMatrix.rotateSkew0 = -m_iMatrix.rotateSkew0;
//    }
}

void zcAnimNode::flushMatrix()
{
    memset(&m_iMatrix, 0, sizeof(cocos2dMATRIX));
    m_iMatrix.scaleX = 1.0;
    m_iMatrix.scaleY = 1.0;
}



#ifdef WIN32
zcAnimSprite* zcAnimNode::createCCSprite(_Bitmap *bitmap)
{
	if(bitmap->m_pTexture)
	{
		zcAnimSprite *sprite = zcAnimSprite::createWithTexture(bitmap->m_pTexture,bitmap->m_iRect,getContentSize());
		return sprite;
	}
	else
	{
		resourceDeictionary::iterator it;
		it = m_pResourceDictionary->find(bitmap->m_nBitmapId);
		if(it==m_pResourceDictionary->end())
			return NULL;
		bitmap = it->second;
		zcAnimSprite *sprite = zcAnimSprite::createWithTexture(bitmap->m_pTexture,bitmap->m_iRect,getContentSize());
		return sprite;
	}
}
#else
zcAnimSprite* zcAnimNode::createCCSprite(const std::string& bitmap)
{
//    CCLOG("create sprite with frame %s",bitmap.c_str());
//    CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(bitmap.c_str());
    zcAnimSprite* sprite = zcAnimSprite::createWithFrame(bitmap.c_str(),getContentSize());
    if(sprite)
    {
        sprite->setFlipX(m_bFlipX);
        sprite->setFlipY(m_bFlipY);
        sprite->setColor(m_tColor);
        sprite->setOpacity(m_nOpacity);
    }
//    else 
//        CCLOG("Error sprite is NULL");
    return sprite;
}
#endif


int zcAnimNode::getActionCount()
{
	return m_iKeyframeDictionary.size();
}
std::string zcAnimNode::getActionName(int index)
{
	int count = getActionCount();
	if(index<0 || index>=count) return std::string("");
	std::map<std::string,zcanim_tag*>::iterator it;
	it = m_iKeyframeDictionary.begin();
	for(int i=0 ; i!=index ; i++)
		it++;
	return it->first;
}

int zcAnimNode::getActionFramesCount(std::string action)
{
    std::map<std::string,int>::iterator it;
    it = m_iKeyAllFramesCount.find(action);
    if(it == m_iKeyAllFramesCount.end())
        return -1;
    return it->second;
}

#ifdef WIN32
std::map<std::string,zcanim_tag*>* zcAnimNode::getKeyFrameD()
{
	return &m_iKeyframeDictionary;
}
#endif

// for replaceable sprite
void zcAnimNode::replaceSprite(const std::string &theOriginSpriteName, const std::string &theNewSpriteName)
{
    // 1, replace exist sprite
    CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    for (auto& obj : _children)
    {
        zcAnimSprite *sp = dynamic_cast<zcAnimSprite *>(obj);
        if (sp != NULL)
        {
            if (theOriginSpriteName == sp->m_frameName)
            {
                CCSpriteFrame *temp = cache->spriteFrameByName(theNewSpriteName.c_str());
                if (temp != NULL)
                {
                    sp->setDisplayFrame(temp);
                    sp->m_frameName = theNewSpriteName;
                }
            }
        }
    }
    
    // 2. 遍历resourceDeictionary, 替换
    resourceDeictionary::iterator it;
    for(it = m_pResourceDictionary->begin();it != m_pResourceDictionary->end();++it)
    {
        if (it->second == theOriginSpriteName)
        {
//            CCLOG("key tag = %d, key value = %s", it->first, ((std::string)(it->second)).c_str());
            it->second = theNewSpriteName;
        }
    }
}
// end

bool loadZcAnim(const char* fanim,const char* fplist)
{
    SuperPsz *psz = SuperPsz::create(fplist);
    if(psz)
    {
        SuperAnim *anim = SuperAnim::create(fanim);
        if(anim)
        {
            return true;
        }
        psz->release();
    }
    return false;
}

void unloadZcAnim(const char* fanim,const char* fplist)
{
    SuperAnim *anim = SuperAnim::create(fanim);
    if(anim)
        anim->release();
    SuperPsz *psz = SuperPsz::create(fplist);
    if(psz)
        psz->release();
}

// end of file
