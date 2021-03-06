/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef AURAMETHODS_H
#define AURAMETHODS_H

namespace LuaAura
{
    int GetCaster(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetCaster());
        return 1;
    }

    int GetCasterGUID(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetCasterGUID());
        return 1;
    }

    int GetCasterLevel(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetCaster()->getLevel());
        return 1;
    }

    int GetDuration(lua_State* L, Aura* aura)
    {
#ifdef MANGOS
        sEluna->Push(L, aura->GetAuraDuration());
#else
        sEluna->Push(L, aura->GetDuration());
#endif
        return 1;
    }

    int GetCharges(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetStackAmount());
        return 1;
    }

    int GetAuraId(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetId());
        return 1;
    }

    int GetMaxDuration(lua_State* L, Aura* aura)
    {
#ifdef MANGOS
        sEluna->Push(L, aura->GetAuraMaxDuration());
#else
        sEluna->Push(L, aura->GetMaxDuration());
#endif
        return 1;
    }

    int GetStackAmount(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetStackAmount());
        return 1;
    }

    int SetDuration(lua_State* L, Aura* aura)
    {
        int duration = sEluna->CHECKVAL<int>(L, 2);

        aura->SetAuraDuration(duration);
        return 0;
    }

    int SetMaxDuration(lua_State* L, Aura* aura)
    {
        int duration = sEluna->CHECKVAL<int>(L, 2);

        aura->SetAuraMaxDuration(duration);
        return 0;
    }

    int SetStackAmount(lua_State* L, Aura* aura)
    {
        int amount = sEluna->CHECKVAL<int>(L, 2);
        int duration = sEluna->CHECKVAL<int>(L, 2);

        aura->SetStackAmount(amount);
        return 0;
    }

    int Remove(lua_State* L, Aura* aura)
    {
        int duration = sEluna->CHECKVAL<int>(L, 2);

        aura->_RemoveAura();
        return 0;
    }

    int GetOwner(lua_State* L, Aura* aura)
    {
        sEluna->Push(L, aura->GetTarget());
        return 1;
    }
};
#endif
