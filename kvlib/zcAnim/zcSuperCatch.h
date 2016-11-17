//
//  zcSuperCatch.h
//  chuangshiji_pp
//
//  Created by yock on 14-6-23.
//
//

#ifndef __chuangshiji_pp__zcSuperCatch__
#define __chuangshiji_pp__zcSuperCatch__

#include <iostream>

class zcanim_tag;

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
    static void removeUnusing();
    bool init(std::string psz);
    void retain();
    void release();
public:
    std::string m_rPszName;
protected:
    int         m_iReference;
};


class SuperAnim
{
public:
    SuperAnim();
    ~SuperAnim();
public:
    static SuperAnim* create(const char* animName);
    static void removeUnusing();
    bool init(std::string anim);
    void retain();
    void release();
public:
    zcanim_tag *m_pTaglist;
    std::string m_iAnimName;
protected:
    int         m_nReference;
};


#endif /* defined(__chuangshiji_pp__zcSuperCatch__) */
