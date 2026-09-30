//C Struct for Superman Interface
#ifndef _SUPERMAN_INTERFACE_H
#define _SUPERMAN_INTERFACE_H

#define YES     1
#define NO      0

struct Superman
{
    char* pcCapeColour;
    char* pcMainAbility;
    char* pcSpeed;
    char* pcPartner;
    char* pcOriginPlanet;
    _Bool bHasFlight;
    _Bool bHasVehicle;
    unsigned short usAlterEgos;
};

void showCharacteristics(const struct Superman* variable);

void setCharacteristics
(
    struct Superman* variableToSetValues,
    char* _pcCapeColour,
    char* _pcMainAbility,
    char* _pcSpeed,
    char* _pcPartner,
    char* _pcOriginPlanet,
    _Bool _bHasFlight,
    _Bool _bHasVehicle,
    unsigned short _usAlterEgos
);

struct Superman* getSupermanVariable();

#endif /*_SUPERMAN_INTERFACE_H*/
