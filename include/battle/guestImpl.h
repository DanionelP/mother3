#ifndef BATTLE_GUEST_IMPL_H
#define BATTLE_GUEST_IMPL_H

#include "battle/guestFactory.h"
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
        }
    }
    virtual ~DefaultGuest();
    bool onAction(Action*);

    void _e8();
    void _f0();
    void _f8(u32);
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

    Action* guest_2c0();
    bool onAction(Action*);
    virtual Action* _108();
    virtual Action* _110();
    virtual void _118(bool, bool);

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

#endif  // BATTLE_GUEST_IMPL_H