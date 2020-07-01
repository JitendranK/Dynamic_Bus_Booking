#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

int checkPassword(char* a);
void signIn();
void signUp();
void login();
void print_ticket(struct Ticket);
int ticket_price(int from,int to);
void void_fromto();
int find(int n,char from_input[],int ia);
void Buses_in_From_To_Destination(char from_input[],char dest_input[],float time1);
int no_of_seats(int index, int flag);
void book_ticket(int index);

#endif
