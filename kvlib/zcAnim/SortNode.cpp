//
//  SortNode.cpp
//  miniDotaClient
//
//  Created by yock on 13-3-8.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "SortNode.h"
#include "zcAnimNode.h"
#if(ISLUA==1)
    #include "CCLuaEngine.h"
#endif


zcMoveTo::zcMoveTo()
{
    m_fDuration=0;
    m_hNext=NULL;
    m_fHeight = 0;
    m_hNode = NULL;
    m_nScriptCallBack = 0;
}
zcMoveTo::~zcMoveTo()
{
    unregisterCallBack();
    if(m_hNode)
        m_hNode->release();
    m_hNode = NULL;

}

zcMoveTo* zcMoveTo::create(float duration,const cocos2d::CCPoint& pt , float height)
{
    zcMoveTo* move2 = new zcMoveTo();
    move2->m_fDuration = duration;
    move2->m_iPt = pt;
    move2->m_fHeight = height;
    return move2;
}

zcMoveTo* zcMoveTo::create(float duration,cocos2d::CCNode* node, float height)
{
    zcMoveTo* move2 = new zcMoveTo();
    move2->m_fDuration = duration;
    move2->m_hNode = node;
    move2->m_hNode->retain();
    move2->m_fHeight = height;
    return move2;
}

void zcMoveTo::registerCallBack(int handle)
{
    unregisterCallBack();
    m_nScriptCallBack = handle;
}
void zcMoveTo::unregisterCallBack()
{
    if(m_nScriptCallBack != 0)
    {
        ScriptEngineManager::sharedManager()->getScriptEngine()->removeScriptHandler(m_nScriptCallBack);
		m_nScriptCallBack=0;
    }
}

//----------------------------------------------------------------------------

SortNode::SortNode()
{
    m_hAnim = NULL;
    m_hCurrent = NULL;
    m_hLast = NULL;
    m_fCurrentParten = 0;
    m_fRhythm = 1.0f;
    m_bMoveRun = false;
    m_fHeight = 0;
    m_bIsMoveLineTo = false;
    m_nMoveMode = 0;
    m_fMoveTime = 0;
    m_bRemoveIsStart = false;
    m_iLastPt = ccp(0,0);
    m_posChange = 0;
    m_bOffReorder = false;
    
    m_disableSort = false;  //自动排序的开关
}
SortNode::~SortNode()
{
    stopMove();
}


SortNode* SortNode::create(const char* fname,int theId , const char* plistName)
{
    SortNode* node = new SortNode();
    if(node->init())
    {
        node->m_hAnim = zcAnimNode::create(fname, theId, plistName);
        if(node->m_hAnim)
        {
            node->m_hAnim->setAnchorPoint(ccp(0,0));
            node->m_hAnim->setPosition(ccp(0,0));
            node->setContentSize(node->m_hAnim->getContentSize());
            node->ignoreAnchorPointForPosition(false);
            node->setAnchorPoint(ccp(0.5,0.5));
            node->m_sAnimName = fname;
            node->m_sPListName = plistName;
#ifdef DEBUG
//            CCLayerColor *colorl = CCLayerColor::create(ccc4(0xff, 0xff, 0x00, 0xff),node->getContentSize().width,node->getContentSize().height);
//            colorl->setAnchorPoint(ccp(0,0));
//            colorl->setPosition(ccp(0,0));
//            node->addChild(colorl);
#endif
            node->addChild(node->m_hAnim);
        }
        else 
        {
            delete node;
            return NULL;
        }
        node->autorelease();
        return node;
    }
    delete node;
    return NULL;
}
bool SortNode::playSection(const std::string& theLabelName)
{
    std::map<zcAnimNode*,float>::iterator it;
    for(it = m_rAnimList.begin() ; it != m_rAnimList.end() ; ++it)
    {
        it->first->playSection(theLabelName);
    }
    return m_hAnim->playSection(theLabelName);
}
void SortNode::pause()
{
    m_hAnim->pause();
    if(m_bMoveRun)
        CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(SortNode::update), this);
}
void SortNode::resume()
{
    m_hAnim->resume();
    if(m_bMoveRun)
        CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(SortNode::update), this, 1.0/60, false);
}
bool SortNode::isPause()
{
    return m_hAnim->isPause();
}
bool SortNode::isPlaying()
{
    return m_hAnim->isPlaying();
}
int SortNode::getCurFrame()
{
    return m_hAnim->getCurFrame();
}
std::string SortNode::getCurSectionName()
{
    return m_hAnim->getCurSectionName();
}
bool SortNode::hasSection(const std::string& theLabelName)
{
    return m_hAnim->hasSection(theLabelName);
}
void SortNode::setRhythm(float rhythm)
{
    m_hAnim->setRhythm(rhythm);
    m_fRhythm=MAX(rhythm,0);
}
float SortNode::getRhythm()
{
    return m_hAnim->getRhythm();
}

void SortNode::registerScriptTapHandler(int nHandler)
{
    m_hAnim->registerScriptTapHandler(nHandler);
}
void SortNode::unregisterScriptTapHandler()
{
    m_hAnim->unregisterScriptTapHandler();
}

void SortNode::registerScriptAnchor(int nHandler)
{
    m_hAnim->registerScriptAnchor(nHandler);
}
void SortNode::unregisterScriptAnchor()
{
    m_hAnim->unregisterScriptAnchor();
}

void SortNode::registerComponent(int nHandler)
{
    m_hAnim->registerComponent(nHandler);
}
void SortNode::unregisterComponent()
{
    m_hAnim->unregisterComponent();
}

int SortNode::getId()
{
    return m_hAnim->getId();
}

void SortNode::setComponentId(const std::string& flag)
{
    m_hAnim->setComponentId(flag);
}
void SortNode::resetComponentId(const std::string& flag)
{
    m_hAnim->resetComponentId(flag);
}

void SortNode::setMatrixValue(float scaleX,float scaleY,float rotationX,float rotationY)
{
    m_hAnim->setMatrixValue(scaleX, scaleY, rotationX, rotationY);
}

void SortNode::flushMatrix()
{
    m_hAnim->flushMatrix();
}

void SortNode::setOffReorder(bool click)
{
    m_bOffReorder = click;
    if (m_disableSort) return;
    
    if(!m_bOffReorder)
    {
        CCPoint pt = getPosition();
        int z = pt.y;
        reorderChild(this, -z);
    }
}

void SortNode::setFlipX(bool fx)
{
    m_hAnim->setFlipX(fx);
}
void SortNode::setFlipY(bool fy)
{
    m_hAnim->setFlipY(fy);
}
bool SortNode::getFlipX()
{
    return m_hAnim->getFlipX();
}
bool SortNode::getFlipY()
{
    return m_hAnim->getFlipY();
}
void SortNode::setColor(const cocos2d::ccColor3B& color)
{
    m_hAnim->setColor(color);
}
void SortNode::setOpacity(GLubyte opacity)
{
    m_hAnim->setOpacity(opacity);
}
void SortNode::setRotation(float rotation)
{
    if(m_hAnim)
        m_hAnim->setRotation(rotation);
    std::map<zcAnimNode*, float>::iterator it;
    for(it=m_rAnimList.begin() ; it!=m_rAnimList.end() ; ++it)
    {
        it->first->setRotation(rotation);
    }
}

int SortNode::getActionCount()
{
    return m_hAnim->getActionCount();
}
std::string SortNode::getActionName(int index)
{
    return m_hAnim->getActionName(index);
}

void SortNode::setPosition(const cocos2d::CCPoint& pt)
{
    CCNode::setPosition(pt);
    
    if ( m_disableSort ) // 屏蔽掉自动排序
    {
        return;
    }
    
    if(!m_bOffReorder)
    {
        int z = pt.y;
        setZOrder(-z);
        if(_parent)
            _parent->reorderChild(this,-z);
    }
    if(m_posChange != 0){
       LuaEngine *m_engine = (LuaEngine*)ScriptEngineManager::sharedManager()->getScriptEngine();
       LuaStack* luaStack = m_engine->getLuaStack();
       luaStack->pushFloat(pt.x);
       luaStack->pushFloat(pt.y);
       luaStack->executeFunctionByHandler(m_posChange, 2);
       luaStack->clean();
    }
}

float SortNode::getAnimPercent()
{
    if(m_hAnim == NULL) return 0;
    float framecount = m_hAnim->m_iKeyAllFramesCount.find(m_hAnim->getCurSectionName())->second;
    return m_hAnim->getCurFrame()/framecount;
}

std::string SortNode::getAnimName()
{
    return m_hAnim->getAnimName();
}
std::string SortNode::getPlistName()
{
    return m_hAnim->getPlistName();
}

void SortNode::registerPosChange(int handle)
{
    m_posChange = handle;
}
void SortNode::unregisterPosChange()
{
    if(m_posChange)
    {
        ScriptEngineManager::sharedManager()->getScriptEngine()->removeScriptHandler(m_posChange);
        m_posChange = 0;
    }
}
void SortNode::moveTo(zcMoveTo* move)
{
    if(m_hCurrent == NULL)
    {
        m_hCurrent = move;
        m_hLast = move;
        m_iStartPosition = getPosition();
        initMoveTo();
    }
    else
    {
        m_hLast->m_hNext = move;
        m_hLast = move;
    }
    if(!m_bMoveRun)
    {
        if(!isPause())
            CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(SortNode::update), this, 1.0/60, false);
        m_bMoveRun = true;
    }
}

void SortNode::moveLineTo(zcMoveTo* move,int movemode,float movetime)
{
    moveTo(move);
    m_bIsMoveLineTo = true;
    m_nMoveMode = movemode;
    m_fMoveTime = movetime;
}

void SortNode::stopMove()
{
    if(m_bMoveRun)
    {
        CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(SortNode::update), this);
        m_bMoveRun = false;
        while(m_hCurrent)
        {
            zcMoveTo *temp = m_hCurrent;
            m_hCurrent=m_hCurrent->m_hNext;
            delete temp;
        }
        m_hLast = NULL;
    }
    if(m_rAnimList.size()>0)
        m_rAnimList.clear();
}

void SortNode::initMoveTo()
{
    m_iStartPosition = getPosition();
    if(m_hCurrent->m_hNode)
        m_iSubPt = ccpSub(m_hCurrent->m_hNode->getPosition(), m_iStartPosition);
    else
        m_iSubPt = ccpSub(m_hCurrent->m_iPt,m_iStartPosition);
    m_fHeight = m_hCurrent->m_fHeight;
    m_fCurrentParten = 0;
}
void SortNode::update(float dt)
{
    m_fCurrentParten+=dt;
    if(m_bIsMoveLineTo)
    {
        std::map<zcAnimNode*, float>::iterator it;
        for(it = m_rAnimList.begin() ; it!=m_rAnimList.end() ; ++it)
        {
            it->second-=dt;
            if(it->second<=0)
            {
                it->first->removeFromParentAndCleanup(true);
                m_rAnimList.erase(it);
            }
        }
        if(m_hCurrent == NULL && m_rAnimList.size()<=0)
        {
            CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(SortNode::update), this);
            m_bMoveRun = false;
            m_bIsMoveLineTo = false;
            return;
        }
    }
    if(m_hCurrent == NULL) return;
    float parten = MAX (0,                                  // needed for rewind. elapsed could be negative
                        MIN(1, m_fCurrentParten /
                            MAX(m_hCurrent->m_fDuration*m_fRhythm, FLT_EPSILON)   // division by 0
                            )
                        );
    if(m_hCurrent->m_hNode)
    {
        m_iSubPt = ccpSub( m_hCurrent->m_hNode->getPosition(),m_iStartPosition);
    }
    float y = m_fHeight * 4 * parten * (1 - parten);
    y += m_iSubPt.y*parten;
    float x = m_iSubPt.x*parten;
    if(m_bIsMoveLineTo)
    {
        if(ccpLength(ccpSub(ccp(x,y), m_iLastPt))>10)
        {
            m_iLastPt.x = x;
            m_iLastPt.y = y;
            zcAnimNode *node = zcAnimNode::create(m_sAnimName.c_str(), 0, m_sPListName.c_str());
            node->playSection(m_hAnim->getCurSectionName());
            node->setRhythm(m_hAnim->getRhythm());
            node->setRotation(m_hAnim->getRotation());
            node->registerScriptTapHandler(m_hAnim->m_nScriptObserverId);
            node->m_hObserver = m_hAnim->m_hObserver;
            node->setAnchorPoint(ccp(0.5,0.5));
            node->setPosition(ccp(x,y));
            addChild(node);
            float time;
            switch (m_nMoveMode) {
                case 0:
                default:
                    time = (m_hCurrent->m_fDuration*(1-parten)+m_fMoveTime)*m_fRhythm;
                    break;
                case 1:
                    time = (m_hCurrent->m_fDuration*(1-parten)+m_fMoveTime*(1-parten))*m_fRhythm;
                    break;
                case 2:
                    time = (m_hCurrent->m_fDuration*(1-parten)+m_fMoveTime*parten)*m_fRhythm;
                    break;
            }
            m_rAnimList[node] = time;
        }
    }
    else
    {
        setPosition(ccp(m_iStartPosition.x+x,m_iStartPosition.y+y));
    }
    
    if(parten>=1)
    {
        //执行结束回调
#if (ISLUA==1)
        if(m_hCurrent->m_nScriptCallBack!=0)
        {
//            CCLuaEngine *m_engine = (CCLuaEngine*)CCScriptEngineManager::sharedManager()->getScriptEngine();
//            CCLuaStack* luaStack = m_engine->getLuaStack();
//            luaStack->pushCCObject(this, "SortNode");
//            if(m_hCurrent->m_hNode)
//            {
//                luaStack->pushCCObject(this, "CCNode");
//            }
//            else
//            {
////                luaStack->pushCCObject(&(m_hCurrent->m_iPt), "CCPoint");
//            }
//            luaStack->executeFunctionByHandler(m_hCurrent->m_nScriptCallBack, 2);
//            luaStack->clean();
        }
#endif
        //切换连续移动点
        zcMoveTo *temp = m_hCurrent;
        m_hCurrent=m_hCurrent->m_hNext;
        delete temp;
        if(m_hCurrent == NULL)
        {
            if(!m_bIsMoveLineTo)
            {
                CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(SortNode::update), this);
                m_bMoveRun = false;
            }
            m_hLast = NULL;
            return;
        }
        initMoveTo();
    }
    

}



