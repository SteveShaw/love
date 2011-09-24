/**
* Copyright (c) 2006-2011 LOVE Development Team
* 
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
**/

#include "wrap_World.h"

namespace love
{
namespace physics
{
namespace box2d
{

	World * luax_checkworld(lua_State * L, int idx)
	{
		return luax_checktype<World>(L, idx, "World", PHYSICS_WORLD_T);
	}

	int w_World_update(lua_State * L)
	{
		World * t = luax_checkworld(L, 1);
		float dt = (float)luaL_checknumber(L, 2);
		t->update(dt);
		return 0;
	}

	int w_World_setCallbacks(lua_State * L)
	{
		World * t = luax_checkworld(L, 1);
		lua_remove(L, 1);
		return t->setCallbacks(L);
	}

	int w_World_getCallbacks(lua_State * L)
	{
		World * t = luax_checkworld(L, 1);
		lua_remove(L, 1);
		return t->getCallbacks(L);
	}
	
	int w_World_setContactFilter(lua_State * L)
	{
		World * t = luax_checkworld(L, 1);
		lua_remove(L, 1);
		return t->setContactFilter(L);
	}
	
	int w_World_getContactFilter(lua_State * L)
	{
		World * t = luax_checkworld(L, 1);
		lua_remove(L, 1);
		return t->getContactFilter(L);
	}

	int w_World_setGravity(lua_State * L)
	{
		World * t = luax_checkworld(L, 1);
		float arg1 = (float)luaL_checknumber(L, 2);
		float arg2 = (float)luaL_checknumber(L, 3);
		t->setGravity(arg1, arg2);
		return 0;
	}

	int w_World_getGravity(lua_State * L)
	{
		World * t = luax_checkworld(L, 1);
		lua_remove(L, 1);
		return t->getGravity(L);
	}

	int w_World_setAllowSleeping(lua_State * L)
	{
		World * t = luax_checkworld(L, 1);
		bool b = luax_toboolean(L, 2);
		t->setAllowSleeping(b);
		return 0;
	}

	int w_World_getAllowSleeping(lua_State * L)
	{
		World * t = luax_checkworld(L, 1);
		luax_pushboolean(L, t->getAllowSleeping());
		return 1;
	}

	int w_World_getBodyCount(lua_State * L)
	{
		World * t = luax_checkworld(L, 1);
		lua_pushinteger(L, t->getBodyCount());
		return 1;
	}

	int w_World_getJointCount(lua_State * L)
	{
		World * t = luax_checkworld(L, 1);
		lua_pushinteger(L, t->getJointCount());
		return 1;
	}

	static const luaL_Reg functions[] = {
		{ "update", w_World_update },
		{ "setCallbacks", w_World_setCallbacks },
		{ "getCallbacks", w_World_getCallbacks },
		{ "setContactFilter", w_World_setContactFilter },
		{ "getContactFilter", w_World_getContactFilter },
		{ "setGravity", w_World_setGravity },
		{ "getGravity", w_World_getGravity },
		{ "setAllowSleeping", w_World_setAllowSleeping },
		{ "getAllowSleeping", w_World_getAllowSleeping },
		{ "getBodyCount", w_World_getBodyCount },
		{ "getJointCount", w_World_getJointCount },
		{ 0, 0 }
	};

	int luaopen_world(lua_State * L)
	{
		return luax_register_type(L, "World", functions);
	}

} // box2d
} // physics
} // love
