//C Struct for Superman Client
#include <stdio.h>
#include "superman_interface.h"

int main(void)
{
    struct Superman* newSuperman = getSupermanVariable();

    newSuperman = &(struct Superman){
                                        .pcCapeColour = ("empty"),
                                        .pcMainAbility = ("empty"),
                                        .pcSpeed = ("empty"),
                                        .pcPartner = ("empty"),
                                        .pcOriginPlanet = ("empty"),
                                        .bHasFlight = (NO),
                                        .bHasVehicle = (YES),
                                        .usAlterEgos = (999)
                                    };

    showCharacteristics(newSuperman);

    setCharacteristics
    (
        newSuperman,
        "Red",
        "Super Strength",
        "Fast",
        "Wonder Women",
        "Krypton",
        YES,
        NO,
        2
    );

    showCharacteristics(newSuperman);

    return(0);
}
