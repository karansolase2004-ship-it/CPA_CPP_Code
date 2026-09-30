//SUPERMAN INTERFACE
#ifndef _SUPERMAN_HPP
#define _SUPERMAN_HPP

const bool YES  = true;
const bool NO   = false;

class Superman{
    private:
    //charactertistics
    std::string sCapeColour;
    std::string sMainAbility;
    std::string sSpeed;
    std::string sPartner;
    std::string sOriginPlanet;
    bool bHasFlight;
    bool bHasVehicle;
    unsigned short usAlterEgos;

    public:
    Superman();
    
    void showCharacteristics();

    void setCharacteristics
    (
        std::string _sCapeColour,
        std::string _sMainAbility,
        std::string _sSpeed,
        std::string _sPartner,
        std::string _sOriginPlanet,
        bool _bHasFlight,
        bool _bHasVehicle,
        unsigned short _usAlterEgos
    );
};

#endif /*_SUPERMAN_HPP*/