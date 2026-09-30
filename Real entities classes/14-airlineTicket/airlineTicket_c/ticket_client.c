//AIRLINE TICKET C CLIENT
#include <stdio.h>
#include "ticket_interface.h"

int main(void)
{
    struct AirlineTicket* newTicket = getTicketVariable();

    newTicket = &(struct AirlineTicket){
                                            .pcPaxName = ("empty_name"),
                                            .pcJourney = ("empty_journey"),
                                            .pcFlightNumber = ("empty_flight"),
                                            .pcSeatNumber = ("empty_seat"),
                                            .structDate_dateOfJourney = {0, "empty_month", 0},
                                            .cClassOfService = ('X'),
                                            .bMealAdded = (NO),
                                            .bFrequentFlyer = (NO)
                                       };

    showTicketDetails(newTicket);

    setTicketDetails
    (
        newTicket,
        "Aditya Panchal",
        "BOM-DEL",
        "AI-325",
        "C33",
        (struct Date){17, "Dec", 2023},
        'F',
        YES,
        YES
    );

    showTicketDetails(newTicket);

    return(0);
}