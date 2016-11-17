//
//  skeletal.cpp
//  sanguo
//
//  Created by yock on 14-9-15.
//
//

#include "skeletalNode.h"
#include "util_file.h"
#include "zcAnimNode.h"
#include "util_json.h"

using namespace cocos2d;

skeletalNode::skeletalNode():
m_iSam("")
{
    m_hSkt = NULL;
    m_iItemMap.clear();
    m_nCount = 0;
}
skeletalNode::~skeletalNode()
{
    if(m_hSkt)
        delete m_hSkt;
    m_iItemMap.clear();
}

// create anim with skeleatl file
skeletalNode* skeletalNode::create(const char* fname,int theId , const char* plistName)
{
    const char* skeletalName =  cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(fname).c_str();
    util_file file;
    if(file.Open(skeletalName, util_file::XREAD))
    {
        int len = file.GetLength();
        int *skt = (int*)new char[len];
        int *temp = skt;
        int count = 0;
        while (*temp)
        {
            temp++;
            count++;
        }
        temp++;
        char *sam = (char*)temp;
        
        skeletalNode* node = new skeletalNode();
        if(node->init())
        {
            node->m_hAnim = zcAnimNode::create(sam, theId, plistName);
            if(node->m_hAnim)
            {
                node->m_hAnim->setAnchorPoint(ccp(0,0));
                node->m_hAnim->setPosition(ccp(0,0));
                node->setContentSize(node->m_hAnim->getContentSize());
                node->ignoreAnchorPointForPosition(false);
                node->setAnchorPoint(ccp(0.5,0.5));
                node->m_sAnimName = fname;
                node->m_sPListName = plistName;
                node->addChild(node->m_hAnim);
                node->m_hAnim->m_hObserver = node;
                node->m_hSkt = skt;
                node->m_iSam = sam;
                node->m_nCount = count;
            }
            else
            {
                delete node;
                delete skt;
                return NULL;
            }
            node->autorelease();
            return node;
        }
        else
        {
            delete node;
            delete skt;
            return NULL;
        }
    }
    return NULL;
}


bool skeletalNode::setItemWith(std::string iname , int tid)
{
    std::string animName = iname;
    animName.append(".swf.sam");
    std::string plistName = iname;
    plistName.append(".plist");
    zcAnimNode* node = zcAnimNode::create(animName.c_str(), tid, plistName.c_str());
    if(node == NULL)
        return false;
    addChild(node);
    m_iItemMap[tid] = node;
    return true;
}


void skeletalNode::OnComponent(zcAnimNode *node,
                               int theId,
                               int flag,
                               const cocos2d::CCPoint &pt ,
                               const cocos2dMATRIX& matrix ,
                               float z ,
                               float a)
{
    zcAnimNode *anim = m_iItemMap[flag];
    if(anim)
    {
        anim->setPosition(pt);
        anim->setMatrix(matrix);
        anim->setZOrder(z);
    }
}

void skeletalNode::OnAnchor(zcAnimNode *node,int theId,std::string anchorString)
{
    util_json json;
    if(json.init(anchorString.c_str()))
    {
        util_json *flag = json.getNodeWithKey("flag");
        if(flag)
        {
            std::string value = flag->toStr();
            std::string bind = "bind";
            if(value == bind)
            {
                util_json *param = json.getNodeWithKey("param");
                if(param)
                {
                    util_json *id = param->getNodeWithKey("id");
                    if(id == NULL) return;
                    int iid = id->toInt();
                    util_json *act = param->getNodeWithKey("act");
                    if(act == NULL) return;
                    std::string action = act->toStr();
                    zcAnimNode *anim = m_iItemMap[iid];
                    if(anim)
                    {
                        anim->playSection(action);
                    }
                }
            }
        }
    }
}



