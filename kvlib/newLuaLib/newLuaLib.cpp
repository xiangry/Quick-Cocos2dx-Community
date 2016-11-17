//
//  newLuaLib.cpp
//  miniDotaClient
//
//  Created by yock on 13-1-24.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "newLuaLib.h"
#include "lua_zcAnim.h"
#include "lua_SortNode.h"


TOLUA_API int luaopen_newLuaLib (lua_State* tolua_S)
{
    luaopen_lua_SortNode(tolua_S);
    luaopen_luaZcAnim(tolua_S);
    
    return 1;
}
