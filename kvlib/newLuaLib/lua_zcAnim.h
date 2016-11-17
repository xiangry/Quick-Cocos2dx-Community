#ifndef miniDotaClient_LUA_ZCANIM_H__
#define miniDotaClient_LUA_ZCANIM_H__

extern "C" {
#include "lua.h"
#include "tolua++.h"
#include "tolua_fix.h"
}

TOLUA_API int luaopen_luaZcAnim (lua_State* tolua_S);

#endif//file end