#include "busBookingfinal.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int checkPassword(char* a) {
  int num_flag=0,A_flag=0,a_flag=0,spl_flag=0,signal;
  char b[200];
  for(int i=0;a[i]!='\0';i++) {
    b[i]=(int)a[i];
    if(b[i]>=48 && b[i]<=57)
      num_flag=1;
    if(b[i]>=65 && b[i]<=97)
      A_flag=1;
    if(b[i]>=65 && b[i]<=89)
      A_flag=1;
    if(b[i]>=97 && b[i]<=122)
      a_flag=1;
    if(a[i]=='!'||a[i]=='@'||a[i]=='#'||a[i]=='$'||a[i]=='%'||a[i]=='^'||a[i]=='&'||a[i]=='*'||a[i]=='('||a[i]==')'||a[i]=='-'||a[i]=='+')
      spl_flag=1;
  }
  signal=num_flag+A_flag+a_flag+spl_flag;
  if(signal==4)
    printf("Strong Password\n");
  if(signal==3)
    printf("Moderate Password\n");
  if(signal<3)
    printf("Weak password\n");
  return signal;
}

void signIn() {
  char in_pass[100],in_check[30]={"null"},in_fuser[30],in_fpass[30];
  int i=0,flag=0;
  FILE *ptr;
  x:   printf("Enter the username:\n");
        scanf("%s",in_user);
        ptr=fopen("user.dat","a+");

       while(fscanf(ptr,"%s %s\n",in_fuser,in_fpass)!=EOF)
       {
           if(strcmp(in_fuser,in_user)==0)
             {
                y: printf("Enter the password:\n");
                scanf("%s",in_pass);
                 if(strcmp(in_fpass,in_pass)==0)
                 {

                     flag=1;
                     printf("You are Logged in :)\n ..........Welcome to ROUTE MASTER.........\n\n");
                     break;
                 }
                 else
                 {
                     printf("Incorrect Password!(\n");
                     goto y;
                 }

             }

       }fclose(ptr);

       if(flag==0)
       {
           printf("Username does not exists!(\n");
           goto x;
       }

    fclose(ptr);
}

void signUp() {
  char user[100];
  char check[30] = "null";
  char pass[30];
  int rs;
  int flag=0;
  FILE *ptr;
  ptr=fopen("user.dat","a+");
  fscanf(ptr,"%s\n",check);
  if(strcmp(check,"null")!=0) {
      x:
      printf("Enter the username:\n");
      scanf("%s",user);
      do {
          if(strcmp(user,check)==0) {
              printf("Already exists:(\n");
              flag=1;
              goto x;
          }
      } while (fscanf(ptr,"%s\n",check)!=EOF);
      p1:
      printf("Enter the password:\n");
      scanf("%s",pass);
      rs = checkPassword(pass);
      if(rs<3)
          goto p1;
      fprintf(ptr,"\n%s %s",user,pass);
  }
  else {
      printf("Enter the username:\n");
      scanf("%s",user);
      p:
      printf("Enter the password:\n");
      scanf("%s",pass);
      rs = checkPassword(pass);
      if(rs<3)
      goto p;
      fprintf(ptr,"%s %s",user,pass);
  }
  fclose(ptr);
  printf("Account created please Login :) !\n");
  signIn();
}

void login() {
  printf("                  ***Route Master***\n\n\n              Enter a choice\n          1. I don't have an account..Help me to create one.\n          2. I am an Existing user let me sign in.\n");
  int choice;
  scanf("%d",&choice);
  switch (choice) {
    case 1:
      signUp();
      break;
    case 2:
      signIn();
      break;
    default:
      printf("Enter a valid input\n");
      break;
  }
}


void print_ticket(struct Ticket t1) {
  printf("\n");
    printf("E-Ticket : ");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t************************************\n");
    printf("\t\t\t\t\t\t\t\t\t***********Ticket Details***********\n");
    printf("\t\t\t\t\t\t\t\t\t     UserName : %s\n",in_user);
    printf("\t\t\t\t\t\t\t\t\t     From     : %s\n",t1.from);
    printf("\t\t\t\t\t\t\t\t\t     To       : %s\n",t1.to);
    printf("\t\t\t\t\t\t\t\t\t     Price    :RS.%d\n",t1.price);
    printf("\t\t\t\t\t\t\t\t\t***********Ticket Booked***********\n");
    printf("\t\t\t\t\t\t\t\t\t***********************************\n");
}


int ticket_price(int from,int to) {
  int i,temp=0,p=5;
  temp=abs(from-to);
  if(temp==1)
   return p;
  if(temp>1) {
    for(i=0;i<temp-1;i++) {
      p=p+2;
    }
    return p;
  }
  return 0;
}


void void_fromto() {
  int loc_count=0;
  printf("Enter your current location: \n");
  for(int i=0;i<a[i][0]!='\0';i++) {
    printf("%d.%s\n",i+1,a[i]);
    loc_count=loc_count+1;
  }
  do {
    scanf("%d",&from);
    if(from>loc_count || from<1) {
     printf("Invalid Location\n");
     printf("Enter your current location: \n");
    }
  } while(from>loc_count || from<1);

  printf("Choose the destination: \n");
  for(int i=0,k=1   ;i<a[i][0]!='\0';i++) {
    if(i!=from-1) {
      printf("%d.%s\n",i+1,a[i]);
    }
  }
  do {
    scanf("%d",&to);
    if(to>loc_count || to<1 || to==from) {
      printf("Invalid Location\n");
      printf("Enter your Destination: \n");
    }
  } while(to>loc_count || to<1 || to==from);
}


int find(int n,char from_input[],int ia) {
    int flag=0;
    for(int i=0;i<n;i++) {
        if(strcmp(a[i],from_input)==0) {
        flag=1;
        break;
        }
    }
    if(flag==1)
     return 1;
    else
     return 0;
}


void Buses_in_From_To_Destination(char from_input[],char dest_input[],float time1) {
  printf("The Available Buses Are:\n");
    for(int i=0;i<48;i++) {
        if(from<to) {
        if((find(48,from_input,i)&&find(48,dest_input,i))&&bus_obj[i].time>=time1&&bus_obj[i].busno<=24) {
        printf("Bus ID:%d \tStart_Location:%s \tDestionation_location:%s \tArraival_Time:%.2f\n",bus_obj[i].busno,bus_obj[i].from,bus_obj[i].to,bus_obj[i].time);
        }
        }
        else {
      if((find(48,from_input,i)&&find(48,dest_input,i))&&bus_obj[i].time>=time1&&bus_obj[i].busno>=25) {
        printf("Bus ID:%d \tStart_Location:%s \tDestionation_location:%s \tArraival_Time:%.2f\n",bus_obj[i].busno,bus_obj[i].from,bus_obj[i].to,bus_obj[i].time);
      }
        }
    }
}


int no_of_seats(int index, int flag) {
    struct Bus b1=bus_obj[index];
    if(flag==1) {
    for(int i=0;i<ticket_count;i++) {
        if(from<to) {
            for(int j=1;j<from;j++){
                if(strcmp(bus_obj[index].tickets[i].to,a[j])==0){
                    if(bus_obj[index].seatavb<60) {
                        bus_obj[index].seatavb++;
                  }
            }
        }
      }
        else {
            for(int j=to; j>from; j--) {
                if(strcmp(bus_obj[index].tickets[i].to,a[j])==0) {
                    if(bus_obj[index].seatavb<60) {
                        bus_obj[index].seatavb++;
                    }
            }
        }
      }
    }
  }
    else {
    for(int i=0; i<ticket_count; i++) {
        if(strcmp(b1.tickets[i].to,a[from-1])==0) {
            if(b1.seatavb<60) {
                b1.seatavb++;
            }
            else
                return b1.totalseats;
        }
    }
    return b1.seatavb;
  }
    return bus_obj[index].seatavb;
}


void book_ticket(int index) {
  int flag;
    bus_obj[index].seatavb=no_of_seats(index,1);
    printf("\nThese are the number of seats Available %d\n",bus_obj[index].seatavb);
    printf("Do you wanna book(1/0)?\n");
    scanf("%d",&flag);
    if(flag==1) {
        if(bus_obj[index].seatavb>0) {
            bus_obj[index].seatavb--;
            strcpy(bus_obj[index].tickets[ticket_count].from,a[from-1]);
            printf("KP:%s",bus_obj[index].tickets[ticket_count].from);
            strcpy(bus_obj[index].tickets[ticket_count].to,a[to-1]);
            bus_obj[index].tickets[ticket_count].price=ticket_price(from,to);
            print_ticket(bus_obj[index].tickets[ticket_count]);
            ticket_count++;
        }
    }
    else {
        printf("Unfortunately,The seats are full\n");
        return;
    }
}
