//
//  newLuaLib.h
//  miniDotaClient
//
//  Created by yock on 13-1-23.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#ifndef miniDotaClient_newLuaLib_h
#define miniDotaClient_newLuaLib_h

extern "C" {
#include "lua.h"
#include "tolua++.h"
#include "tolua_fix.h"
}

TOLUA_API int luaopen_newLuaLib (lua_State* tolua_S);

#endif
