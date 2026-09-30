#include "global.h"
#include "battle/guestFactory.h"
#include "battle/monster.h"
#include "battle/player.h"

extern "C" Action* getGuestSkill(u16, Unit*);
extern "C" Player* sub_08072AC4(u16);
extern "C" bool sub_08074160(Action*, u32);
extern "C" Monster* GetMonster(s32);

extern "C" ASM_FUNC("asm/non_matching/guestImpl/init__9GuestRTTI.inc", void init__9GuestRTTI());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/getName__9GuestRTTI.inc", void getName__9GuestRTTI());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/create__12IoniaFactoryUs.inc", void create__12IoniaFactoryUs());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/create__13FassadFactoryUs.inc", void create__13FassadFactoryUs());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/create__11WessFactoryUs.inc", void create__11WessFactoryUs());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/create__11AlecFactoryUs.inc", void create__11AlecFactoryUs());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/create__11FuelFactoryUs.inc", void create__11FuelFactoryUs());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/create__13ThomasFactoryUs.inc", void create__13ThomasFactoryUs());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/sub_0809FCE8.inc", void sub_0809FCE8());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/sub_0809FD08.inc", void sub_0809FD08());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/create__19DefaultGuestFactoryUs.inc", void create__19DefaultGuestFactoryUs());

Ionia::Ionia(u16 arg) : DefaultGuest(arg) {}

Fassad::Fassad(u16 arg) : DefaultGuest(arg) {
    this->unk_10C = randS32(2, 3);
    this->unk_108 = 0;
}

Wess::Wess(u16 arg) : DefaultGuest(arg) {
    this->unk_108 = 0;
}

Alec::Alec(u16 arg) : DefaultGuest(arg) {
    this->unk_108 = 0;
    this->unk_10C = 0;
}

Fuel::Fuel(u16 arg) : DefaultGuest(arg) {}

Thomas::Thomas(u16 arg) : DefaultGuest(arg) {}

extern "C" ASM_FUNC("asm/non_matching/guestImpl/__12DefaultGuestUs.inc", void __12DefaultGuestUs());

Action* Ionia::guest_2c0() {
    u16 prob1 = 33;
    u16 prob2 = 66;
    u16 val;
    s32 rng = randS32_(0, 99);

    val = 26;

    if (rng >= prob1) {
        val = 28;
        if (rng < prob2) {
            val = 27;
        }
    }

    return getGuestSkill(val, this);
}

extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__5Ionia.inc", void dt__5Ionia());

bool Fassad::_118(u32 arg1, bool arg2) {
    if (this->unk_108 != arg1 || arg2 == true) {
        this->unk_108 = arg1;
        this->_2f8(0);
        this->unk_10C = randS32(2, 3);
        return true;
    }
    
    return false;
}

Action* Fassad::_110() {
    u16 prob1 = 30;
    u16 prob2 = 55;
    u16 val;
    s32 rand = randS32_(0, 99);
    
    val = 34;
    
    if (rand >= prob1) {
        val = 36;
        if (rand < prob2) {
            val = 35;
        }
    }
    
    return getGuestSkill(val, this);
}

Action* Fassad::_108() {
    u16 prob1 = 60;
    u16 prob2 = 97;
    u16 val;
    s32 rand = randS32_(0, 99);
    
    val = 29;

    if (rand >= prob1) {
        val = 31;
        if (rand < prob2) {
            val = 30;
        }
    }

    return getGuestSkill(val, this);
}

Action* Fassad::guest_2c0() {
    Player* target = sub_08072AC4(Player::Salsa);

    if (target != NULL) {
        if (randS32(0, 99) <= 69) {
            if (target->hasStatus(Status::Sleep) == true || target->hasStatus(Status::Strange) == true) {
                return getGuestSkill(33, this);
            }
        }
    }

    switch (this->unk_108) {
    case false:
        return this->_308();
    case true:
        return this->_310();
    default:
        return Guest::guest_2c0();
    }
}

void Fassad::_e8(Fassad* arg) {
    if (arg != this) return;

    switch (arg->unk_108) {
        case false:
            if (arg->_300() >= arg->unk_10C) {
                arg->_318(true, false);
            }
            break;
        case true:
            arg->_318(false, false);
            break;
    }
}

extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__6Fassad.inc", void dt__6Fassad());

NONMATCH("asm/non_matching/guestImpl/onAction__4WessP6Action.inc", bool Wess::onAction(Action* action)) {
    bool res;
    if (Unit::onAction(action) == true) {
        this->unk_104++;
        res = true;
    }

    if (res == false) {
        return false;
    }

    if (sub_08074160(action, 0x15) == true) {
        this->unk_108++;
    }

    return true;
}
END_NONMATCH


Action* Wess::_108() {
    Vector<u16> skills;

    skills.append(0x16);

    if (sub_08072AC4(Player::Duster) != false) { skills.append(0x17); }
    if (sub_08072AC4(Player::Kumatora) != false) { skills.append(0x18); }

    u16 selected_skill = skills[randS32(0, skills.size() - 1)];

    return getGuestSkill(selected_skill, this);
}

Action* Wess::guest_2c0() {
    if (IsBossBattle() == true && GetMonster(0)->hpReal() <= 149) {
        return this->_308();
    }

    if (this->unk_108 <= 0) {
        s32 rand = randS32(0, 99);
        if (rand <= 49) {
            return getGuestSkill(20, this);
        } else if (rand <= 66) {
             return getGuestSkill(21, this);
        } else if (rand <= 69) {
             return getGuestSkill(25, this);
        } else {
            return this->_308();
        }
    } else {
        s32 rand = randS32(0, 99);
        if (rand <= 49) {
             return getGuestSkill(20, this);
        } else if (rand <= 69) {
             return getGuestSkill(25, this);
        } else {
            return this->_308();
        }
    }
}

extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__4Wess.inc", void dt__4Wess());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/sub_080A0758.inc", void sub_080A0758());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/_110__4Alec.inc", void _110__4Alec());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/_108__4Alec.inc", void _108__4Alec());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/guest_2c0__4Alec.inc", void guest_2c0__4Alec());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__4Alec.inc", void dt__4Alec());

Action* Fuel::guest_2c0() {
    u16 prob1 = 33;
    u16 prob2 = 66;
    u16 val;
    s32 rng = randS32_(0, 99);

    val = 7;

    if (rng >= prob1) {
        val = 9;
        if (rng < prob2) {
            val = 8;
        }
    }

    return getGuestSkill(val, this);
}

extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__4Fuel.inc", void dt__4Fuel());

Action* Thomas::guest_2c0() {
    u16 prob1 = 25;
    u16 prob2 = 50;
    u16 prob3 = 75;
    u16 val;
    s32 rng = randS32_(0, 99);
    
    val = 1;

    if (rng >= prob1) {
        val = 2;
        if (rng >= prob2) {
            val = 4;
            if (rng < prob3) {
                val = 3;
            }
        }
    }

    return getGuestSkill(val, this);
}

extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__6Thomas.inc", void dt__6Thomas());

u32 DefaultGuest::_100() { return this->unk_104; }

extern "C" ASM_FUNC("asm/non_matching/guestImpl/_f8__12DefaultGuest.inc", void _f8__12DefaultGuest());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/onAction__12DefaultGuestP6Action.inc", void onAction__12DefaultGuestP6Action());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/_f0__12DefaultGuest.inc", void _f0__12DefaultGuest());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/_e8__12DefaultGuest.inc", void _e8__12DefaultGuest());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__12DefaultGuest.inc", void dt__12DefaultGuest());