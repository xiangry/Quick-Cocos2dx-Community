//
//  skeletal.h
//  sanguo
//
//  Created by yock on 14-9-15.
//
//

#ifndef __sanguo__skeletal__
#define __sanguo__skeletal__

#include <iostream>
#include "SortNode.h"
#include "zcAnimNode.h"


class skeletalNode : public SortNode , public zcAnimNodeListenter
{
public:
    skeletalNode();
    virtual ~skeletalNode();
public:
    // create anim with skeleatl file 
    static skeletalNode* create(const char* fname,int theId , const char* plistName);
    
    bool setItemWith(std::string iname , int tid);
    
public:
    void OnComponent(zcAnimNode *node,int theId,int flag,const cocos2d::CCPoint &pt , const cocos2dMATRIX& matrix , float z , float a);
    void OnAnchor(zcAnimNode *node,int theId,std::string anchorString);
protected:
    std::map<int , zcAnimNode*>     m_iItemMap;     //
    int             *m_hSkt;                        //绑点标记数组
    std::string      m_iSam;                        //动画名字
    int              m_nCount;                      //标记个数
};

#endif /* defined(__sanguo__skeletal__) */
