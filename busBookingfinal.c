#include "service.h"
#include "busBookingfinal.h"
#include <stdio.h>
#include <string.h>

int abs(int x) {
	if(x<0)
		return -x;
	else
		return x;
}

int main() {
  struct User u1,u2,u3,u4;
  struct Ticket t1,t2,t3,t4;
  float tk = 0.0;
  int bus_id;
  int aks;
  for(int i=0;i<48;i++) {
    bus_obj[i].busno=i+1;
    bus_obj[i].totalseats=bus_obj[i].seatavb=60;
  	bus_obj[i].time=tk;
  	tk=tk+1.0;
  	if(i<=24) {
      for(int j=0;j<strlen(a[0]);j++)
        bus_obj[i].from[j]=a[0][j];
      for(int j=0;j<strlen(a[9]);j++)
        bus_obj[i].to[j]=a[9][j];
    }
  	else {
      for(int j=0;j<strlen(a[9]);j++)
        bus_obj[i].from[j]=a[9][j];
      for(int j=0;j<strlen(a[0]);j++)
        bus_obj[i].to[j]=a[0][j];
  	}
  	if(tk==24.00)
  	   tk=0.0;
  }
  login();
  do {
    void_fromto();
    float t;
    printf("Enter the time you want to board\n");
    scanf("%f",&t);
    Buses_in_From_To_Destination(a[from-1],a[to-1],t);
    printf("Book Tickets(Enter the bus ID)\n");
    scanf("%d",&bus_id);
    book_ticket(bus_id-1);
    printf("Book Tickets Again(1.yes 2.no)\n");
    scanf("%d",&aks);
    if(aks==2)
      break;
  } while(1);
}
