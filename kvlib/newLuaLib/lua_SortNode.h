//
//  lua_SortNode.h
//  miniDotaClient
//
//  Created by yock on 13-3-8.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#ifndef miniDotaClient_lua_SortNode_h
#define miniDotaClient_lua_SortNode_h

extern "C" {
#include "lua.h"
#include "tolua++.h"
#include "tolua_fix.h"
}


TOLUA_API int luaopen_lua_SortNode (lua_State* tolua_S);

#endif
