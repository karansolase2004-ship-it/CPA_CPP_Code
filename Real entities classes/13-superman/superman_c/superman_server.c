//C Struct for Superman Server
#include <stdio.h>
#include <stdlib.h>
#include "superman_interface.h"

struct Superman* getSupermanVariable()
{
    struct Superman* newSuperman = (struct Superman*)malloc(sizeof(struct Superman));
    if(newSuperman == NULL)
    {
        puts("Memory Allocation failed in getSupermanVariable()\n");
        exit(EXIT_FAILURE);
    };

    return(newSuperman);
}

void showCharacteristics(const struct Superman* variable)
{
    puts("Superman Characteristics are\n");

    printf("%s\n", variable->pcCapeColour);
    printf("%s\n", variable->pcMainAbility);
    printf("%s\n", variable->pcSpeed);
    printf("%s\n", variable->pcPartner);
    printf("%s\n", variable->pcOriginPlanet);
    printf("%d\n", variable->bHasFlight);
    printf("%d\n", variable->bHasVehicle);
    printf("%hu\n\n", variable->usAlterEgos);
}

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
)
{
    variableToSetValues->pcCapeColour = _pcCapeColour;
    variableToSetValues->pcMainAbility = _pcMainAbility;
    variableToSetValues->pcSpeed = _pcSpeed;
    variableToSetValues->pcPartner = _pcPartner;
    variableToSetValues->pcOriginPlanet = _pcOriginPlanet;
    variableToSetValues->bHasFlight = _bHasFlight;
    variableToSetValues->bHasVehicle = _bHasVehicle;
    variableToSetValues->usAlterEgos = _usAlterEgos;
}