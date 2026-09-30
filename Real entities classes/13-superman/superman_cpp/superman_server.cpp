//SUPERMAN SERVER
#include <iostream>
#include "superman_interface.hpp"

//default constr
Superman::Superman()
:   sCapeColour("empty"),
    sMainAbility("empty"),
    sSpeed("empty"),
    sPartner("empty"),
    sOriginPlanet("empty"),
    bHasFlight(NO),
    bHasVehicle(YES),
    usAlterEgos(0)      
{

}

void Superman::setCharacteristics
(
    std::string _sCapeColour,
    std::string _sMainAbility,
    std::string _sSpeed,
    std::string _sPartner,
    std::string _sOriginPlanet,
    bool _bHasFlight,
    bool _bHasVehicle,
    unsigned short _usAlterEgos
)
{
    this->sCapeColour = _sCapeColour;
    sMainAbility = _sMainAbility;
    sSpeed = _sSpeed;
    sPartner = _sPartner;
    sOriginPlanet = _sOriginPlanet;
    bHasFlight = _bHasFlight;
    bHasVehicle = _bHasVehicle;
    usAlterEgos = _usAlterEgos;
}

void Superman::showCharacteristics()
{
    std::cout << "Characteristics of Superman" << std::endl;
    std::cout << "Cape Color : " << sCapeColour << std::endl;
    std::cout << "Main Ability : " << sMainAbility << std::endl;
    std::cout << "Speed : " << sSpeed << std::endl;
    std::cout << "Partner : " << sPartner << std::endl;
    std::cout << "Origin Planet : " << sOriginPlanet << std::endl;
    std::cout << std::boolalpha << "Has Flight ? : " << bHasFlight << std::endl;
    std::cout << "Has Vehicle ? : " << bHasVehicle << std::endl;
    std::cout << "Alter Ego Count : " << usAlterEgos << std::endl;

    std::cout << std::endl;
}
