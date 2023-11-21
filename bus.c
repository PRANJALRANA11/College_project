#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bus route
typedef struct BusRoute {
  char startCity[20];
  char endCity[20];
  char startTime[10];
  char endTime[10];
  int numStops;
  float ticketCost;
  int availableSeats;
} BusRoute;

// Function to print bus route details
void printBusRouteDetails(BusRoute route) {
  printf("Bus Route: %s to %s\n", route.startCity, route.endCity);
  printf("Start Time: %s\n", route.startTime);
  printf("End Time: %s\n", route.endTime);
  printf("Number of Stops: %d\n", route.numStops);
  printf("Ticket Cost: $%.2f\n", route.ticketCost);
  printf("Available Seats: %d\n", route.availableSeats);
}

// Function to book tickets for a specific bus route
void bookTickets(BusRoute *route) {
  int numTickets;
  printf("Enter the number of tickets you want to book: ");
  scanf("%d", &numTickets);

  if (numTickets > route->availableSeats) {
    printf("Insufficient seats available. Please enter a valid number of tickets.\n");
    return;
  }

  route->availableSeats -= numTickets;
  printf("Tickets booked successfully!\n");
  printf("Total cost: $%.2f\n", numTickets * route->ticketCost);
}

int main() {
  // Define bus routes
  BusRoute routes[] = {
    {"City A", "City B", "6:00 AM", "8:30 AM", 3, 20.00, 5},
    {"City B", "City A", "10:00 AM", "12:30 PM", 3, 20.00, 5},
    {"City A", "City C", "8:00 AM", "10:30 AM", 2, 15.00, 5},
    {"City C", "City A", "12:00 PM", "2:30 PM", 2, 15.00, 5},
    {"City B", "City C", "11:00 AM", "1:30 PM", 1, 10.00, 5},
    {"City C", "City B", "3:00 PM", "5:30 PM", 1, 10.00, 5}
  };

  int numRoutes = sizeof(routes) / sizeof(routes[0]);

  while (1) {
    int choice;
    printf("\nWelcome to the bus booking system.\n");
    printf("1. View bus routes\n");
    printf("2. Book tickets\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Display all bus route details
        for (int i = 0; i < numRoutes; i++) {
          printBusRouteDetails(routes[i]);
        }
        break;
      case 2:
        // Book tickets for a specific bus route
        int routeIndex;
        printf("Enter the bus route number: ");
        scanf("%d", &routeIndex);

        if (routeIndex < 1 || routeIndex > numRoutes) {
          printf("Invalid bus route number.\n");
          break;
        }

        bookTickets(&routes[routeIndex - 1]);
        break;
      case 3:
        printf("Thank you for using the bus booking system.\n");
        exit(0);
      default:
        printf("Invalid choice. Please enter a valid option.\n");
    }
  }

  return 0;
}