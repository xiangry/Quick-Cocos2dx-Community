/*
** Lua binding: luaZcAnim
** Generated automatically by tolua++-1.0.92 on Tue Jul 30 10:42:05 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "lua_zcAnim.h"
#include "zcAnimNode.h"

#include "LuaBasicConversions.h"

/* Exported function */
TOLUA_API int  tolua_luaZcAnim_open (lua_State* tolua_S);


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"zcAnimNode");
 tolua_usertype(tolua_S,"CCPoint");
 tolua_usertype(tolua_S,"CCSpriteBatchNode");
 tolua_usertype(tolua_S,"ccColor3B");
}

/* method: create of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_create00
static int tolua_luaZcAnim_zcAnimNode_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
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
   zcAnimNode* tolua_ret = (zcAnimNode*)  zcAnimNode::create(fname,theId,plistName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"zcAnimNode");
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

/* method: removeAllUnusing of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_create00
static int tolua_luaZcAnim_zcAnimNode_removeAllUnusing00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertable(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        zcAnimNode::removeAllUnusing();
    }
    return 1;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'removeAllUnusing'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playSection of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_playSection00
static int tolua_luaZcAnim_zcAnimNode_playSection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
  std::string theLabelName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playSection'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->playSection(theLabelName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playSection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_pause00
static int tolua_luaZcAnim_zcAnimNode_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: resume of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_resume00
static int tolua_luaZcAnim_zcAnimNode_resume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isPause of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_isPause00
static int tolua_luaZcAnim_zcAnimNode_isPause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: isPlaying of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_isPlaying00
static int tolua_luaZcAnim_zcAnimNode_isPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getCurFrame of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_getCurFrame00
static int tolua_luaZcAnim_zcAnimNode_getCurFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getCurSectionName of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_getCurSectionName00
static int tolua_luaZcAnim_zcAnimNode_getCurSectionName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: hasSection of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_hasSection00
static int tolua_luaZcAnim_zcAnimNode_hasSection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
  std::string theLabelName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hasSection'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->hasSection(theLabelName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hasSection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRhythm of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_setRhythm00
static int tolua_luaZcAnim_zcAnimNode_setRhythm00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getRhythm of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_getRhythm00
static int tolua_luaZcAnim_zcAnimNode_getRhythm00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: registerScriptTapHandler of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_registerScriptTapHandler00
static int tolua_luaZcAnim_zcAnimNode_registerScriptTapHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
//     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
//     (tolua_isvaluenil(tolua_S, 2, &tolua_err) || !toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, &tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
     int nHandler = ((int)  tolua_tonumber(tolua_S,2,0));
//     int nHandler = (int)toluafix_ref_function(tolua_S, 2, 0);
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

/* method: unregisterScriptTapHandler of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_unregisterScriptTapHandler00
static int tolua_luaZcAnim_zcAnimNode_unregisterScriptTapHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: registerScriptAnchor of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_registerScriptAnchor00
static int tolua_luaZcAnim_zcAnimNode_registerScriptAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
//     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
//     (tolua_isvaluenil(tolua_S, 2, &tolua_err) || !toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, &tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: unregisterScriptAnchor of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_unregisterScriptAnchor00
static int tolua_luaZcAnim_zcAnimNode_unregisterScriptAnchor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: registerComponent of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_registerComponent00
static int tolua_luaZcAnim_zcAnimNode_registerComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
        //     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
//        (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_unregisterComponent00
static int tolua_luaZcAnim_zcAnimNode_unregisterComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

//---------------------------------------add setComponen function for lua
/* method: setComponentId of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_setComponentId00
static int tolua_luaZcAnim_zcAnimNode_setComponentId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
        !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
        const std::string flag = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setComponentId'", NULL);
#endif
        {
            self->setComponentId(flag);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'setComponentId'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetComponentId of class  SortNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_resetComponentId00
static int tolua_luaZcAnim_zcAnimNode_resetComponentId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
        !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,3,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
        const std::string flag = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
        if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetComponentId'", NULL);
#endif
        {
            self->resetComponentId(flag);
        }
    }
    return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'resetComponentId'.",&tolua_err);
    return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE


/* method: getId of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_getId00
static int tolua_luaZcAnim_zcAnimNode_getId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setFlipX of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_setFlipX00
static int tolua_luaZcAnim_zcAnimNode_setFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setFlipY of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_setFlipY00
static int tolua_luaZcAnim_zcAnimNode_setFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getFlipX of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_getFlipX00
static int tolua_luaZcAnim_zcAnimNode_getFlipX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getFlipY of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_getFlipY00
static int tolua_luaZcAnim_zcAnimNode_getFlipY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setColor of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_setColor00
static int tolua_luaZcAnim_zcAnimNode_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setPosition of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_setPosition00
static int tolua_luaZcAnim_zcAnimNode_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_istable(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
//  const CCPoint* pt = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
     // convert lua value to desired arguments
     cocos2d::CCPoint arg0;
     
     // convert lua value to desired arguments
     luaval_to_point(tolua_S, 2, &arg0, "CCNode:setPositionByAnchor");
     
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition( arg0 );
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

/* method: getActionCount of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_getActionCount00
static int tolua_luaZcAnim_zcAnimNode_getActionCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getActionName of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_getActionName00
static int tolua_luaZcAnim_zcAnimNode_getActionName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getActionName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getActionName(index);
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

/* function: loadZcAnim */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_loadZcAnim00
static int tolua_luaZcAnim_loadZcAnim00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fanim = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* fplist = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  loadZcAnim(fanim,fplist);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadZcAnim'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: unloadZcAnim */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_unloadZcAnim00
static int tolua_luaZcAnim_unloadZcAnim00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fanim = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* fplist = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   unloadZcAnim(fanim,fplist);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unloadZcAnim'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMatrixValue of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_setMatrixValue00
static int tolua_luaZcAnim_zcAnimNode_setMatrixValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
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
        zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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


/* method: flushMatrix of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_flushMatrix00
static int tolua_luaZcAnim_zcAnimNode_flushMatrix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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

// --------------------------------------- with new blend anim ---------------------------------------
/* method: getAnimName of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_getAnimName00
static int tolua_luaZcAnim_zcAnimNode_getAnimName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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


/* method: getPlistName of class  zcAnimNode */
#ifndef TOLUA_DISABLE_tolua_luaZcAnim_zcAnimNode_getPlistName00
static int tolua_luaZcAnim_zcAnimNode_getPlistName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
    tolua_Error tolua_err;
    if (
        !tolua_isusertype(tolua_S,1,"zcAnimNode",0,&tolua_err) ||
        !tolua_isnoobj(tolua_S,2,&tolua_err)
        )
        goto tolua_lerror;
    else
#endif
    {
        zcAnimNode* self = (zcAnimNode*)  tolua_tousertype(tolua_S,1,0);
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
TOLUA_API int tolua_luaZcAnim_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"zcAnimNode","zcAnimNode","CCSpriteBatchNode",NULL);
  tolua_beginmodule(tolua_S,"zcAnimNode");
   tolua_function(tolua_S,"create",tolua_luaZcAnim_zcAnimNode_create00);
   tolua_function(tolua_S, "removeAllUnusing", tolua_luaZcAnim_zcAnimNode_removeAllUnusing00);
   tolua_function(tolua_S,"playSection",tolua_luaZcAnim_zcAnimNode_playSection00);
   tolua_function(tolua_S,"pause",tolua_luaZcAnim_zcAnimNode_pause00);
   tolua_function(tolua_S,"resume",tolua_luaZcAnim_zcAnimNode_resume00);
   tolua_function(tolua_S,"isPause",tolua_luaZcAnim_zcAnimNode_isPause00);
   tolua_function(tolua_S,"isPlaying",tolua_luaZcAnim_zcAnimNode_isPlaying00);
   tolua_function(tolua_S,"getCurFrame",tolua_luaZcAnim_zcAnimNode_getCurFrame00);
   tolua_function(tolua_S,"getCurSectionName",tolua_luaZcAnim_zcAnimNode_getCurSectionName00);
   tolua_function(tolua_S,"hasSection",tolua_luaZcAnim_zcAnimNode_hasSection00);
   tolua_function(tolua_S,"setRhythm",tolua_luaZcAnim_zcAnimNode_setRhythm00);
   tolua_function(tolua_S,"getRhythm",tolua_luaZcAnim_zcAnimNode_getRhythm00);
   tolua_function(tolua_S,"setMatrixValue",tolua_luaZcAnim_zcAnimNode_setMatrixValue00);
    tolua_function(tolua_S, "flushMatrix", tolua_luaZcAnim_zcAnimNode_flushMatrix00);
    
   tolua_function(tolua_S,"registerScriptTapHandler",tolua_luaZcAnim_zcAnimNode_registerScriptTapHandler00);
   tolua_function(tolua_S,"unregisterScriptTapHandler",tolua_luaZcAnim_zcAnimNode_unregisterScriptTapHandler00);
   tolua_function(tolua_S,"registerScriptAnchor",tolua_luaZcAnim_zcAnimNode_registerScriptAnchor00);
   tolua_function(tolua_S,"unregisterScriptAnchor",tolua_luaZcAnim_zcAnimNode_unregisterScriptAnchor00);
    
    
    tolua_function(tolua_S,"registerComponent",tolua_luaZcAnim_zcAnimNode_registerComponent00);
    tolua_function(tolua_S,"unrighsterComponent",tolua_luaZcAnim_zcAnimNode_unregisterComponent00);
    tolua_function(tolua_S,"setComponentId",tolua_luaZcAnim_zcAnimNode_setComponentId00);
    tolua_function(tolua_S,"resetComponentId",tolua_luaZcAnim_zcAnimNode_resetComponentId00);
    
    
   tolua_function(tolua_S,"getId",tolua_luaZcAnim_zcAnimNode_getId00);
   tolua_function(tolua_S,"setFlipX",tolua_luaZcAnim_zcAnimNode_setFlipX00);
   tolua_function(tolua_S,"setFlipY",tolua_luaZcAnim_zcAnimNode_setFlipY00);
   tolua_function(tolua_S,"getFlipX",tolua_luaZcAnim_zcAnimNode_getFlipX00);
   tolua_function(tolua_S,"getFlipY",tolua_luaZcAnim_zcAnimNode_getFlipY00);
   tolua_function(tolua_S,"setColor",tolua_luaZcAnim_zcAnimNode_setColor00);
   tolua_function(tolua_S,"setPosition",tolua_luaZcAnim_zcAnimNode_setPosition00);
   tolua_function(tolua_S,"getActionCount",tolua_luaZcAnim_zcAnimNode_getActionCount00);
   tolua_function(tolua_S,"getActionName",tolua_luaZcAnim_zcAnimNode_getActionName00);
   tolua_function(tolua_S, "getAnimName", tolua_luaZcAnim_zcAnimNode_getAnimName00);
   tolua_function(tolua_S, "getPlistName", tolua_luaZcAnim_zcAnimNode_getPlistName00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"loadZcAnim",tolua_luaZcAnim_loadZcAnim00);
  tolua_function(tolua_S,"unloadZcAnim",tolua_luaZcAnim_unloadZcAnim00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_luaZcAnim (lua_State* tolua_S) {
 return tolua_luaZcAnim_open(tolua_S);
};
#endif

