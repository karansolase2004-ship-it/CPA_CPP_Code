//AIRLINE TICKET C INTERFACE / HEADER
#ifndef _TICKET_H
#define _TICKET_H

#include <stdio.h>

#define YES     1
#define NO      0

struct Date
{
    unsigned short usDay;
    char* pcMonth;
    unsigned short usYear;
};

struct AirlineTicket
{
    char* pcPaxName;
    char* pcJourney;
    char* pcFlightNumber;
    char* pcSeatNumber;
    struct Date structDate_dateOfJourney;
    char cClassOfService;
    _Bool bMealAdded;
    _Bool bFrequentFlyer;
};

void setTicketDetails
(
    struct AirlineTicket* structVariableToSetValues,
    char* _pcPaxName,
    char* _pcJourney,
    char* _pcFlightNumber,
    char* _pcSeatNumber,
    struct Date _structDate_dateOfJourney,
    char _cClassOfService,
    _Bool _bMealAdded,
    _Bool _bFrequentFlyer
);

void showTicketDetails(const struct AirlineTicket* ticketVariable);

struct AirlineTicket* getTicketVariable();

static void* ampMalloc(size_t sizeOfStruct);

#endif /*_TICKET_H*/
