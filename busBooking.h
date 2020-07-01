#ifndef BUS_BOOKING_H
#define BUS_BOOKING_H

char a[20][20]={"B.K.Pudur","V.L.Mills","E.D.Pirivu","Aparna","Kuniyamuthur","Aathupaalam","Ukkadam","Townhall","Railway station","Gandhipuram"};
int from, to, ticket_count=0;
char in_user[100];

struct User {
    char name[100];
    int avbalance;
    char gender[10];
    char username[100];
    char password[100];
};

struct Ticket {
    int flag;
    int price;
    char from[100];
    char to[100];
    int serialno;
};

struct Bus {
    int seatavb;
    int busno;
    int totalseats;
    struct Ticket tickets[60];
    char from[20];
    char to[20];
    float time;
} bus_obj[48];

#endif
