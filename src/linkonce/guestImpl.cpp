#include "global.h"
#include "battle/guestFactory.h"

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
extern "C" ASM_FUNC("asm/non_matching/guestImpl/guest_2c0__5Ionia.inc", void guest_2c0__5Ionia());
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

extern "C" ASM_FUNC("asm/non_matching/guestImpl/_110__6Fassad.inc", void _110__6Fassad());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/_108__6Fassad.inc", void _108__6Fassad());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/guest_2c0__6Fassad.inc", void guest_2c0__6Fassad());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/_e8__6Fassad.inc", void _e8__6Fassad());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__6Fassad.inc", void dt__6Fassad());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/onAction__4WessP6Action.inc", void onAction__4WessP6Action());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/_108__4Wess.inc", void _108__4Wess());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/guest_2c0__4Wess.inc", void guest_2c0__4Wess());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__4Wess.inc", void dt__4Wess());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/sub_080A0758.inc", void sub_080A0758());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/_110__4Alec.inc", void _110__4Alec());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/_108__4Alec.inc", void _108__4Alec());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/guest_2c0__4Alec.inc", void guest_2c0__4Alec());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__4Alec.inc", void dt__4Alec());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/guest_2c0__4Fuel.inc", void guest_2c0__4Fuel());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__4Fuel.inc", void dt__4Fuel());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/guest_2c0__6Thomas.inc", void guest_2c0__6Thomas());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__6Thomas.inc", void dt__6Thomas());

u32 DefaultGuest::_100() { return this->unk_104; }

extern "C" ASM_FUNC("asm/non_matching/guestImpl/_f8__12DefaultGuest.inc", void _f8__12DefaultGuest());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/onAction__12DefaultGuestP6Action.inc", void onAction__12DefaultGuestP6Action());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/_f0__12DefaultGuest.inc", void _f0__12DefaultGuest());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/_e8__12DefaultGuest.inc", void _e8__12DefaultGuest());
extern "C" ASM_FUNC("asm/non_matching/guestImpl/dt__12DefaultGuest.inc", void dt__12DefaultGuest());