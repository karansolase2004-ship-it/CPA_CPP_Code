//AIRLINE TICKET INTERFACE
#include <iostream>
#include "ticket_interface.hpp"

Date::Date(unsigned int _d, std::string _s, unsigned int _y)
:   usDay(_d), sMonth(_s), usYear(_y)
{
    
}

AirlineTicket::AirlineTicket()
:   sPaxName{"empty_name"},
    sJourney{"empty_journey"},
    sFlightNumber{"empty_flight"},
    sSeatNumber{"empty_seat"},
    dateOfJourney{0, "empty_month", 0},
    cClassOfService{'X'},
    bMealAdded{NO},
    bFrequentFlyer{NO}
{

}

void AirlineTicket::setTicketDetails
(
    std::string _sPaxName,
    std::string _sJourney,
    std::string _sFlightNumber,
    std::string _sSeatNumber,
    Date _dateOfJourney,
    char _cClassOfService,
    bool _bMealAdded,
    bool _bFrequentFlyer
)
{
    this->sPaxName = _sPaxName;
    sJourney = _sJourney;
    sFlightNumber = _sFlightNumber;
    sSeatNumber = _sSeatNumber;
    dateOfJourney = _dateOfJourney;
    cClassOfService = _cClassOfService;
    bMealAdded = _bMealAdded;
    bFrequentFlyer = _bFrequentFlyer;
}

void AirlineTicket::showTicketDetails()
{
    std::cout << "Airline Ticket Details are" << std::endl;

    std::cout << this->sPaxName << std::endl;
    std::cout << sJourney << std::endl;
    std::cout << sFlightNumber << std::endl;
    std::cout << sSeatNumber << std::endl;
    std::cout << dateOfJourney << std::endl;
    std::cout << cClassOfService << std::endl;
    std::cout << std::boolalpha << bMealAdded << std::endl;
    std::cout << bFrequentFlyer << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Date& resource)
{
    std::cout << resource.usDay << "-" << resource.sMonth << "-" << resource.usYear;
}