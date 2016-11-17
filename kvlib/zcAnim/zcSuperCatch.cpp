//
//  zcSuperCatch.cpp
//  chuangshiji_pp
//
//  Created by yock on 14-6-23.
//
//

#include "zcSuperCatch.h"
#include "cocos2d.h"

#include "zcAnim.h"
#include "swfType.h"

static std::map<std::string, SuperPsz*> iSuperPszMap;

std::string getfirstframename(std::string &psz )
{
    std::string::size_type offset = psz.find(".plist");
    std::string::size_type offset1 = psz.find_last_of("/");
    if(offset == std::string::npos)
        return "";
    if(offset1 == std::string::npos)
        offset1 = 0;
    else
        offset1++;
    std::string iname = psz.substr(offset1,offset-offset1);
    iname.append(".swf1.png");
    return iname;
}

SuperPsz* SuperPsz::create(const char *psz)
{
    std::map<std::string, SuperPsz*>::iterator it;
    std::string key = psz;
    it = iSuperPszMap.find(key);
    if(it != iSuperPszMap.end() && it->second != NULL)
        return it->second;
    SuperPsz* sp = new SuperPsz();
    if(sp->init(key))
    {
//        iSuperPszMap[sp->m_rPszName] = sp;
        return sp;
    }
    delete sp;
    return NULL;
}

void SuperPsz::removeUnusing()
{
    std::map<std::string, SuperPsz*>::iterator it;
    for (it = iSuperPszMap.begin(); it != iSuperPszMap.end(); ++it)
    {
        if(it->second != NULL)
        {
            SuperPsz* sp = it->second;
            if(sp->m_iReference<=1)
            {
                iSuperPszMap[sp->m_rPszName] = NULL;
                
//                std::string::size_type offset = sp->m_rPszName.find(".plist");
//                std::string iname = sp->m_rPszName.substr(0,offset);
//                iname.append(".swf1.png");
                std::string iname = getfirstframename(sp->m_rPszName);
                
//                if (sp->m_rPszName.compare("anirole9001.plist") == 0)
//                {
//                    int a = 0;
//                    a = 1;
//                }
//                else
//                    printf("remove anim plist %s",sp->m_rPszName.c_str());
                
                CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(iname.c_str());
                if(frame)
                    frame->release();
                else
                {
                    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(sp->m_rPszName.c_str());
                    CCDictionary *dict = CCDictionary::createWithContentsOfFileThreadSafe(fullPath.c_str());
                    if(dict != NULL)
                    {
                        CCDictionary *dframe = (CCDictionary*)dict->objectForKey("frames");
                        DictElement* pElement = NULL;
                        CCDICT_FOREACH(dframe, pElement)
                        {
                            std::string spriteFrameName = pElement->getStrKey();
                            CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(spriteFrameName.c_str());
                            if(spriteFrame)
                            {
                                spriteFrame->release();
                                break;
                            }
                        }
                        dict->release();
                    }
                }
                /*
                std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(sp->m_rPszName.c_str());
                CCDictionary *dict = CCDictionary::createWithContentsOfFileThreadSafe(fullPath.c_str());
                if(dict != NULL)
                {
                    CCDictionary *dframe = (CCDictionary*)dict->objectForKey("frames");
                    CCDictElement* pElement = NULL;
                    CCDICT_FOREACH(dframe, pElement)
                    {
                        std::string spriteFrameName = pElement->getStrKey();
                        CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(spriteFrameName.c_str());
                        if(spriteFrame)
                            spriteFrame->release();
                    }
                    dict->release();
                }
                */
                CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile(sp->m_rPszName.c_str());
                delete sp;
            }
        }
    }
}

bool SuperPsz::init(std::string psz)
{
    if(psz.size()<=0) return false;
//    std::string::size_type offset = psz.find(".plist");
//    if(offset == std::string::npos)
//        return false;
//    std::string iname = psz.substr(0,offset);
//    iname.append(".swf1.png");
    
    std::string iname = getfirstframename(psz);
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(psz.c_str());
    
    CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(iname.c_str());
    if(frame)
        frame->retain();
    else
    {
        std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(psz.c_str());
        CCDictionary *dict = CCDictionary::createWithContentsOfFileThreadSafe(fullPath.c_str());
        if(dict == NULL)
            return false;
        CCDictionary *dframe = (CCDictionary*)dict->objectForKey("frames");
        DictElement* pElement = NULL;
        CCDICT_FOREACH(dframe, pElement)
        {
            std::string spriteFrameName = pElement->getStrKey();
            CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(spriteFrameName.c_str());
            if(spriteFrame)
            {
                spriteFrame->retain();
                break;
            }
        }
        dict->release();
    }
    /*
    std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(psz.c_str());
    CCDictionary *dict = CCDictionary::createWithContentsOfFileThreadSafe(fullPath.c_str());
    if(dict == NULL)
        return false;
    CCDictionary *dframe = (CCDictionary*)dict->objectForKey("frames");
    CCDictElement* pElement = NULL;
    CCDICT_FOREACH(dframe, pElement)
    {
        std::string spriteFrameName = pElement->getStrKey();
        CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(spriteFrameName.c_str());
        if(spriteFrame)
            spriteFrame->retain();
    }
    dict->release();
    */
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
        
//        std::string::size_type offset = m_rPszName.find(".plist");
//        std::string iname = m_rPszName.substr(0,offset);
//        iname.append(".swf1.png");
        std::string iname = getfirstframename(m_rPszName);
        
        CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(iname.c_str());
        if(frame)
            frame->release();
        else
        {
            std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(m_rPszName.c_str());
            CCDictionary *dict = CCDictionary::createWithContentsOfFileThreadSafe(fullPath.c_str());
            if(dict != NULL)
            {
                CCDictionary *dframe = (CCDictionary*)dict->objectForKey("frames");
                DictElement* pElement = NULL;
                CCDICT_FOREACH(dframe, pElement)
                {
                    std::string spriteFrameName = pElement->getStrKey();
                    CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(spriteFrameName.c_str());
                    if(spriteFrame)
                    {
                        spriteFrame->release();
                        break;
                    }
                }
                dict->release();
            }
        }
        /*
        std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(m_rPszName.c_str());
        CCDictionary *dict = CCDictionary::createWithContentsOfFileThreadSafe(fullPath.c_str());
        if(dict != NULL)
        {
            CCDictionary *dframe = (CCDictionary*)dict->objectForKey("frames");
            CCDictElement* pElement = NULL;
            CCDICT_FOREACH(dframe, pElement)
            {
                std::string spriteFrameName = pElement->getStrKey();
                CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(spriteFrameName.c_str());
                if(spriteFrame)
                    spriteFrame->release();
            }
            dict->release();
        }
         */
        CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile(m_rPszName.c_str());
        delete this;
    }
}


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
    if(it != iSuperAnimMap.end() && it->second != NULL)
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

void SuperAnim::removeUnusing()
{
    std::map<std::string, SuperAnim*>::iterator it;
    for (it = iSuperAnimMap.begin(); it != iSuperAnimMap.end(); it++)
    {
        if(it->second != NULL)
        {
            SuperAnim* sa = it->second;
            if(sa->m_nReference<=1)
            {
                iSuperAnimMap[sa->m_iAnimName] = NULL;
                delete sa;
            }
        }
    }
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



