//AIRLINE TICKET C SERVER
#include <stdio.h>
#include <stdlib.h>
#include "ticket_interface.h"

struct AirlineTicket* getTicketVariable()
{
    struct AirlineTicket* newTicket = NULL;

    newTicket = (struct AirlineTicket*)ampMalloc(sizeof(struct AirlineTicket));

    return newTicket;
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
)
{
    structVariableToSetValues->pcPaxName = _pcPaxName;
    structVariableToSetValues->pcJourney = _pcJourney;
    structVariableToSetValues->pcFlightNumber = _pcFlightNumber;
    structVariableToSetValues->pcSeatNumber = _pcSeatNumber;
    structVariableToSetValues->structDate_dateOfJourney = _structDate_dateOfJourney;
    structVariableToSetValues->cClassOfService = _cClassOfService;
    structVariableToSetValues->bMealAdded = _bMealAdded;
    structVariableToSetValues->bFrequentFlyer = _bFrequentFlyer;
};

void showTicketDetails(const struct AirlineTicket* ticketVariable)
{
    puts("Airline Ticket Details are\n");

    printf("%s\n", ticketVariable->pcPaxName);
    printf("%s\n", ticketVariable->pcJourney);
    printf("%s\n", ticketVariable->pcFlightNumber);
    printf("%s\n", ticketVariable->pcSeatNumber);
    printf("%hu-%s-%hu\n", ticketVariable->structDate_dateOfJourney.usDay, ticketVariable->structDate_dateOfJourney.pcMonth, ticketVariable->structDate_dateOfJourney.usYear);
    printf("%c\n", ticketVariable->cClassOfService);
    printf("%d\n", ticketVariable->bMealAdded);
    printf("%d\n\n", ticketVariable->bFrequentFlyer);
};

static void* ampMalloc(size_t sizeOfStruct)
{
    void* p = NULL;

    p = malloc(sizeOfStruct);
    if(p == NULL)
    {
        puts("Memory Allocation failed in ampMalloc()");
        exit(EXIT_FAILURE);
    }
    return(p);
};
