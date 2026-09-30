//AIRLINE TICKET INTERFACE
#ifndef _TICKET_HPP
#define _TICKET_HPP

const bool YES = true;
const bool NO = false;

class Date{
    friend class AirlineTicket;

    private:
    unsigned int usDay;
    std::string sMonth;
    unsigned int usYear;

    public:
    Date(unsigned int, std::string, unsigned int);

    friend std::ostream& operator<<(std::ostream& os, const Date& resource);
};

class AirlineTicket{
    private:
    std::string sPaxName;
    std::string sJourney;
    std::string sFlightNumber;
    std::string sSeatNumber;
    Date dateOfJourney;
    char cClassOfService;
    bool bMealAdded;
    bool bFrequentFlyer;

    public:
    AirlineTicket();
    void setTicketDetails
    (
        std::string _sPaxName,
        std::string _sJourney,
        std::string _sFlightNumber,
        std::string _sSeatNumber,
        Date _dateOfJourney,
        char _cClassOfService,
        bool _bMealAdded,
        bool _bFrequentFlyer
    );

    void showTicketDetails();
};

#endif /*_TICKET_HPP*/
