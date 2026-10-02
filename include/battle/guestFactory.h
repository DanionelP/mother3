#ifndef BATTLE_GUEST_FACTORY_H
#define BATTLE_GUEST_FACTORY_H

#include "factory.h"
#include "guest.h"

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
