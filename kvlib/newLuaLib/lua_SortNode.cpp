/*
** Lua binding: lua_SortNode
** Generated automatically by tolua++-1.0.92 on Tue Jul 30 13:33:37 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"
#include "SortNode.h"
#include "lua_SortNode.h"
#include <string>
using namespace std;
USING_NS_CC;
/* Exported function */
TOLUA_API int  tolua_lua_SortNode_open (lua_State* tolua_S);


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"zcMoveTo");
 tolua_usertype(tolua_S,"CCLayer");
 tolua_usertype(tolua_S,"ccColor3B");
 tolua_usertype(tolua_S,"SortNode");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"CCPoint");
}

/* method: create of class  zcMoveTo */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_zcMoveTo_create00
static int tolua_lua_SortNode_zcMoveTo_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"zcMoveTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  const CCPoint* pt = ((const CCPoint*)  tolua_tousertype(tolua_S,3,0));
  float height = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   zcMoveTo* tolua_ret = (zcMoveTo*)  zcMoveTo::create(duration,*pt,height);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"zcMoveTo");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  zcMoveTo */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_zcMoveTo_create01
static int tolua_lua_SortNode_zcMoveTo_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"zcMoveTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,3,0));
  float height = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   zcMoveTo* tolua_ret = (zcMoveTo*)  zcMoveTo::create(duration,node,height);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"zcMoveTo");
  }
 }
 return 1;
tolua_lerror:
 return tolua_lua_SortNode_zcMoveTo_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerCallBack of class  zcMoveTo */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_zcMoveTo_registerCallBack00
static int tolua_lua_SortNode_zcMoveTo_registerCallBack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcMoveTo",0,&tolua_err) ||
//     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
//     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcMoveTo* self = (zcMoveTo*)  tolua_tousertype(tolua_S,1,0);
//  int handle = ((int)  tolua_tonumber(tolua_S,2,0));
     int handle = 0;//(int)toluafix_ref_function(tolua_S, 2, 0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerCallBack'", NULL);
#endif
  {
   self->registerCallBack(handle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerCallBack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterCallBack of class  zcMoveTo */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_zcMoveTo_unregisterCallBack00
static int tolua_lua_SortNode_zcMoveTo_unregisterCallBack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcMoveTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcMoveTo* self = (zcMoveTo*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterCallBack'", NULL);
#endif
  {
   self->unregisterCallBack();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterCallBack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_create00
static int tolua_lua_SortNode_SortNode_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fname = ((const char*)  tolua_tostring(tolua_S,2,0));
  int theId = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* plistName = ((const char*)  tolua_tostring(tolua_S,4,0));
  {
   SortNode* tolua_ret = (SortNode*)  SortNode::create(fname,theId,plistName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SortNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playSection of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_playSection00
static int tolua_lua_SortNode_SortNode_playSection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
  const std::string theLabelName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playSection'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->playSection(theLabelName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)theLabelName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playSection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_pause00
static int tolua_lua_SortNode_SortNode_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'", NULL);
#endif
  {
   self->pause();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resume of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_resume00
static int tolua_lua_SortNode_SortNode_resume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resume'", NULL);
#endif
  {
   self->resume();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPause of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_isPause00
static int tolua_lua_SortNode_SortNode_isPause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPause'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isPause();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPlaying of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_isPlaying00
static int tolua_lua_SortNode_SortNode_isPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPlaying'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isPlaying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPlaying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurFrame of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_getCurFrame00
static int tolua_lua_SortNode_SortNode_getCurFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurFrame'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCurFrame();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurSectionName of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_getCurSectionName00
static int tolua_lua_SortNode_SortNode_getCurSectionName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurSectionName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getCurSectionName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurSectionName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hasSection of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_hasSection00
static int tolua_lua_SortNode_SortNode_hasSection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
  const std::string theLabelName = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasSection'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasSection(theLabelName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)theLabelName);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasSection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRhythm of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_setRhythm00
static int tolua_lua_SortNode_SortNode_setRhythm00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
  float rhythm = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRhythm'", NULL);
#endif
  {
   self->setRhythm(rhythm);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRhythm'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRhythm of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_getRhythm00
static int tolua_lua_SortNode_SortNode_getRhythm00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRhythm'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getRhythm();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRhythm'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerScriptTapHandler of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_registerScriptTapHandler00
static int tolua_lua_SortNode_SortNode_registerScriptTapHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        //     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
//        (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
        //  int nHandler = ((int)  tolua_tonumber(tolua_S,2,0));
        int nHandler = 0;//(int)toluafix_ref_function(tolua_S, 2, 0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerScriptTapHandler'", NULL);
#endif
        {
            self->registerScriptTapHandler(nHandler);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'registerScriptTapHandler'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerPosChange of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_registerPosChange00
static int tolua_lua_SortNode_SortNode_registerPosChange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
//     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
//     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
//  int nHandler = ((int)  tolua_tonumber(tolua_S,2,0));
     int nHandler = 0;//(int)toluafix_ref_function(tolua_S, 2, 0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerPosChange'", NULL);
#endif
  {
   self->registerPosChange(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerPosChange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterScriptTapHandler of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_unregisterScriptTapHandler00
static int tolua_lua_SortNode_SortNode_unregisterScriptTapHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterScriptTapHandler'", NULL);
#endif
        {
            self->unregisterScriptTapHandler();
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'unregisterScriptTapHandler'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterScriptTapHandler of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_unregisterPosChange00
static int tolua_lua_SortNode_SortNode_unregisterPosChange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterPosChange'", NULL);
#endif
  {
   self->unregisterPosChange();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterPosChange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerScriptAnchor of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_registerScriptAnchor00
static int tolua_lua_SortNode_SortNode_registerScriptAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
//     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
//     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
//  int nHandler = ((int)  tolua_tonumber(tolua_S,2,0));
     int nHandler = 0;//(int)toluafix_ref_function(tolua_S, 2, 0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerScriptAnchor'", NULL);
#endif
  {
   self->registerScriptAnchor(nHandler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerScriptAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterScriptAnchor of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_unregisterScriptAnchor00
static int tolua_lua_SortNode_SortNode_unregisterScriptAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterScriptAnchor'", NULL);
#endif
  {
   self->unregisterScriptAnchor();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterScriptAnchor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

//-----------------------------------------add registerComponent

/* method: registerComponent of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_registerComponent00
static int tolua_lua_SortNode_SortNode_registerComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        //     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
//        (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
        //  int nHandler = ((int)  tolua_tonumber(tolua_S,2,0));
        int nHandler = 0;//(int)toluafix_ref_function(tolua_S, 2, 0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerComponent'", NULL);
#endif
        {
            self->registerComponent(nHandler);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'registerComponent'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterComponent of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_unregisterComponent00
static int tolua_lua_SortNode_SortNode_unregisterComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterComponent'", NULL);
#endif
        {
            self->unregisterComponent();
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'unregisterComponent'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

//-----------------------------------------------------------

/* method: getId of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_getId00
static int tolua_lua_SortNode_SortNode_getId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getId'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getId();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

//---------------------------------------add setComponen function for lua
/* method: setComponentId of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_setComponentId00
static int tolua_lua_SortNode_SortNode_setComponentId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
        const std::string flag = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setComponentId'", NULL);
#endif
        {
            self->setComponentId(flag);
        }
    }
    return 2;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setComponentId'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetComponentId of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_resetComponentId00
static int tolua_lua_SortNode_SortNode_resetComponentId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
        const std::string flag = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetComponentId'", NULL);
#endif
        {
            self->resetComponentId(flag);
        }
    }
    return 2;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'resetComponentId'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
//-----------------------------------------------------------------------

/* method: setFlipX of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_setFlipX00
static int tolua_lua_SortNode_SortNode_setFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
  bool fx = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlipX'", NULL);
#endif
  {
   self->setFlipX(fx);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFlipY of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_setFlipY00
static int tolua_lua_SortNode_SortNode_setFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
  bool fy = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFlipY'", NULL);
#endif
  {
   self->setFlipY(fy);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFlipX of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_getFlipX00
static int tolua_lua_SortNode_SortNode_getFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFlipX'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getFlipX();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFlipX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFlipY of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_getFlipY00
static int tolua_lua_SortNode_SortNode_getFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFlipY'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getFlipY();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFlipY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_setColor00
static int tolua_lua_SortNode_SortNode_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
  const ccColor3B* color = ((const ccColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActionCount of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_getActionCount00
static int tolua_lua_SortNode_SortNode_getActionCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActionCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getActionCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActionCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getActionName of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_getActionName00
static int tolua_lua_SortNode_SortNode_getActionName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActionName'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getActionName(index);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getActionName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_setPosition00
static int tolua_lua_SortNode_SortNode_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* pt = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(*pt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveTo of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_moveTo00
static int tolua_lua_SortNode_SortNode_moveTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"zcMoveTo",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
  zcMoveTo* move = ((zcMoveTo*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveTo'", NULL);
#endif
  {
   self->moveTo(move);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: moveLineTo of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_moveLineTo00
static int tolua_lua_SortNode_SortNode_moveLineTo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"zcMoveTo",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
  zcMoveTo* move = ((zcMoveTo*)  tolua_tousertype(tolua_S,2,0));
  int movemode = ((int)  tolua_tonumber(tolua_S,3,0));
  float movetime = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'moveLineTo'", NULL);
#endif
  {
   self->moveLineTo(move,movemode,movetime);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'moveLineTo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stopMove of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_stopMove00
static int tolua_lua_SortNode_SortNode_stopMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stopMove'", NULL);
#endif
  {
   self->stopMove();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stopMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMatrixValue of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_SortNode_setMatrixValue00
static int tolua_luaZcAnim_SortNode_setMatrixValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
        !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
        !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
        !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,6,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
        float scaleX = ((float)  tolua_tonumber(tolua_S,2,0));
        float scaleY = ((float)  tolua_tonumber(tolua_S,3,0));
        float rotationX = ((float)  tolua_tonumber(tolua_S,4,0));
        float rotationY = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMatrixValue'", NULL);
#endif
        {
            self->setMatrixValue(scaleX,scaleY,rotationX,rotationY);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setMatrixValue'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE


/* method: flushMatrix of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_SortNode_flushMatrix00
static int tolua_luaZcAnim_SortNode_flushMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'flushMatrix'", NULL);
#endif
        {
            self->flushMatrix();
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'flushMatrix'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOffReorder of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_setOffReorder00
static int tolua_lua_SortNode_SortNode_setOffReorder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
        bool click = (bool)tolua_toboolean(tolua_S, 2, 0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOffReorder'", NULL);
#endif
        {
            self->setOffReorder(click);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setOffReorder'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOffReorder of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_disableSort00
static int tolua_lua_SortNode_SortNode_disableSort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
        bool disable = (bool)tolua_toboolean(tolua_S, 2, 0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOffReorder'", NULL);
#endif
        {
            self->disableSort(disable);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setOffReorder'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

// --------------------------------------- with new blend anim ---------------------------------------
/* method: getAnimName of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_getAnimName00
static int tolua_lua_SortNode_SortNode_getAnimName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimName'", NULL);
#endif
        {
            std::string tolua_ret = (std::string)  self->getAnimName();
            tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'getAnimName'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE


/* method: getPlistName of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_lua_SortNode_SortNode_stopMove00
static int tolua_lua_SortNode_SortNode_getPlistName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"SortNode",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        SortNode* self = (SortNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPlistName'", NULL);
#endif
        {
            std::string tolua_ret = (std::string)  self->getPlistName();
            tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
        }
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'getPlistName'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

//-------------------------------------------------------------------------------------------------

/* Open function */
TOLUA_API int tolua_lua_SortNode_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"zcMoveTo","zcMoveTo","",NULL);
  tolua_beginmodule(tolua_S,"zcMoveTo");
   tolua_function(tolua_S,"create",tolua_lua_SortNode_zcMoveTo_create00);
   tolua_function(tolua_S,"create",tolua_lua_SortNode_zcMoveTo_create01);
   tolua_function(tolua_S,"registerCallBack",tolua_lua_SortNode_zcMoveTo_registerCallBack00);
   tolua_function(tolua_S,"unregisterCallBack",tolua_lua_SortNode_zcMoveTo_unregisterCallBack00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SortNode","SortNode","CCLayer",NULL);
  tolua_beginmodule(tolua_S,"SortNode");
   tolua_function(tolua_S,"create",tolua_lua_SortNode_SortNode_create00);
   tolua_function(tolua_S,"playSection",tolua_lua_SortNode_SortNode_playSection00);
   tolua_function(tolua_S,"pause",tolua_lua_SortNode_SortNode_pause00);
   tolua_function(tolua_S,"resume",tolua_lua_SortNode_SortNode_resume00);
   tolua_function(tolua_S,"isPause",tolua_lua_SortNode_SortNode_isPause00);
   tolua_function(tolua_S,"isPlaying",tolua_lua_SortNode_SortNode_isPlaying00);
   tolua_function(tolua_S,"getCurFrame",tolua_lua_SortNode_SortNode_getCurFrame00);
   tolua_function(tolua_S,"getCurSectionName",tolua_lua_SortNode_SortNode_getCurSectionName00);
   tolua_function(tolua_S,"hasSection",tolua_lua_SortNode_SortNode_hasSection00);
   tolua_function(tolua_S,"setRhythm",tolua_lua_SortNode_SortNode_setRhythm00);
   tolua_function(tolua_S,"getRhythm",tolua_lua_SortNode_SortNode_getRhythm00);
   tolua_function(tolua_S,"registerScriptTapHandler",tolua_lua_SortNode_SortNode_registerScriptTapHandler00);
   tolua_function(tolua_S,"unregisterScriptTapHandler",tolua_lua_SortNode_SortNode_unregisterScriptTapHandler00);
   tolua_function(tolua_S,"registerPosChange",tolua_lua_SortNode_SortNode_registerPosChange00);
   tolua_function(tolua_S,"unregisterPosChange",tolua_lua_SortNode_SortNode_unregisterPosChange00);
   tolua_function(tolua_S,"registerScriptAnchor",tolua_lua_SortNode_SortNode_registerScriptAnchor00);
   tolua_function(tolua_S,"unregisterScriptAnchor",tolua_lua_SortNode_SortNode_unregisterScriptAnchor00);
    
    tolua_function(tolua_S,"registerComponent",tolua_lua_SortNode_SortNode_registerComponent00);
    tolua_function(tolua_S,"unrighsterComponent",tolua_lua_SortNode_SortNode_unregisterComponent00);
    tolua_function(tolua_S,"setComponentId",tolua_lua_SortNode_SortNode_setComponentId00);
    tolua_function(tolua_S,"resetComponentId",tolua_lua_SortNode_SortNode_resetComponentId00);
    
    tolua_function(tolua_S, "setMatrixValue", tolua_luaZcAnim_SortNode_setMatrixValue00);
    tolua_function(tolua_S, "flushMatrix", tolua_luaZcAnim_SortNode_flushMatrix00);
    tolua_function(tolua_S, "setOffReorder", tolua_lua_SortNode_SortNode_setOffReorder00);
    
   tolua_function(tolua_S,"getId",tolua_lua_SortNode_SortNode_getId00);
   tolua_function(tolua_S,"setFlipX",tolua_lua_SortNode_SortNode_setFlipX00);
   tolua_function(tolua_S,"setFlipY",tolua_lua_SortNode_SortNode_setFlipY00);
   tolua_function(tolua_S,"getFlipX",tolua_lua_SortNode_SortNode_getFlipX00);
   tolua_function(tolua_S,"getFlipY",tolua_lua_SortNode_SortNode_getFlipY00);
   tolua_function(tolua_S,"setColor",tolua_lua_SortNode_SortNode_setColor00);
   tolua_function(tolua_S,"getActionCount",tolua_lua_SortNode_SortNode_getActionCount00);
   tolua_function(tolua_S,"getActionName",tolua_lua_SortNode_SortNode_getActionName00);
   tolua_function(tolua_S,"setPosition",tolua_lua_SortNode_SortNode_setPosition00);
   tolua_function(tolua_S,"moveTo",tolua_lua_SortNode_SortNode_moveTo00);
   tolua_function(tolua_S,"moveLineTo",tolua_lua_SortNode_SortNode_moveLineTo00);
   tolua_function(tolua_S,"stopMove",tolua_lua_SortNode_SortNode_stopMove00);
    
   tolua_function(tolua_S,"disableSort",tolua_lua_SortNode_SortNode_disableSort00);
   tolua_function(tolua_S, "getAnimName", tolua_lua_SortNode_SortNode_getAnimName00);
   tolua_function(tolua_S, "getPlistName", tolua_lua_SortNode_SortNode_getPlistName00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_lua_SortNode (lua_State* tolua_S) {
 return tolua_lua_SortNode_open(tolua_S);
};
#endif

