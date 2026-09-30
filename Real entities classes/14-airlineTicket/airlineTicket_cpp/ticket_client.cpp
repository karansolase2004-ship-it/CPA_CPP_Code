//AIRLINE TICKET CLIENT
#include <iostream>
#include "ticket_interface.hpp"

int main(void){
    AirlineTicket* newTicket = new AirlineTicket;

    newTicket->setTicketDetails
    (
        "Aditya Panchal",
        "BOM-DEL",
        "AI-325",
        "C33",
        {17, "Dec", 2023},
        'F',
        YES,
        YES
    );

    newTicket->showTicketDetails();

    return 0;
}
