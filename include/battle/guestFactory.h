#ifndef BATTLE_GUEST_FACTORY_H
#define BATTLE_GUEST_FACTORY_H

#include "factory.h"
#include "guest.h"
#include "battle.h"

extern ClockData gUnknown_080F741C;
extern ClockData gUnknown_080F7424;

class DefaultGuest : public Guest {
public:
    DefaultGuest(u16 arg) : Guest(arg) {
    this->unk_104 = 0; 
    
    {
        Battle* battleMgr = BattleManager::get();
        UnitTurnBegin turnBeginEvent;
        this->listen(battleMgr, turnBeginEvent, gUnknown_080F741C);
    }
    
    {
        Battle* battleMgr = BattleManager::get();
        UnitTurnEnd turnEndEvent;
        this->listen(battleMgr, turnEndEvent, gUnknown_080F7424);
    };
}
    virtual ~DefaultGuest();
    u32 _100();
    virtual void _2e8();
    virtual void _2f0();
    virtual void _2f8(u32);
    virtual s32 _300();
    virtual Action* _308();
    virtual Action* _310();
    virtual void _318(bool, bool);

};

class Wess : public DefaultGuest {
public:
    Wess(u16 id);
    virtual ~Wess();

    bool onAction(Action*);
    Action* _108();
    Action* _110();
    Action* guest_2c0();
    s32 unk_108;
    s32 unk_10C;
};
class Thomas : public DefaultGuest {
public:
    Thomas(u16 id);
    virtual ~Thomas();

    Action* guest_2c0();
};
class Ionia : public DefaultGuest {
public:
    Ionia(u16 id);
    virtual ~Ionia();

    Action* guest_2c0();
};
class Fuel : public DefaultGuest {
public:
    Fuel(u16 id);
    virtual ~Fuel();

    Action* guest_2c0();
};
class Alec : public DefaultGuest {
public:
    Alec(u16 id);
    virtual ~Alec();

    s32 unk_108;
    s32 unk_10C;
};
class Fassad : public DefaultGuest {
public:
    Fassad(u16 id);
    virtual ~Fassad();


    Action* guest_2c0();
    void _e8(Fassad*);
    Action* _108();
    Action* _110();
    bool _118(u32, bool);
    s32 unk_108;
    s32 unk_10C;
};

class GuestFactory {
public:
    static void init();
    static void put(u16 id, void* (*spawn)(u16 id));
    static void* create(u16 id);
};

FACTORY(DefaultGuest, u16);
FACTORY(Wess, u16);
FACTORY(Thomas, u16);
FACTORY(Ionia, u16);
FACTORY(Fuel, u16);
FACTORY(Alec, u16);
FACTORY(Fassad, u16);

#endif  // BATTLE_GUEST_FACTORY_H
