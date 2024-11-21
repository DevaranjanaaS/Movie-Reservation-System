#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

int rateChange(int);
void booking(int *,int,int );
int option(void);
void cancelBooking(int *);
void book_1(int choice,char name[10],int id2,int price, int screen);
void book_2(int choice,char name[10],int id2,int price, int screen);
void book_3(int choice,char name[10],int id2,int price, int screen);
int cancelmovie(void);
int movie(void);
void info(void);

struct customer
{
	char name[50];
	int phone[10],seat,id;
}cust[300];

int count=0;
int id2=786703;

int main()
{
	int **seat;
	int choice;
	int price=300;
	int i,a;
	int selection,m,n;

    seat=(int **)calloc(101,sizeof(int *));

	for (i=0;i<3;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int ));

	while(a != 5)
	{
		choice=option();
		switch(choice)
		{
			case 1:
				selection=movie();
				booking(seat[selection-1],price,selection);
				count++;
				break;

			case 2:
			    selection=cancelmovie();
				cancelBooking(seat[selection-1]);
				break;

			case 3:
				price=rateChange(price);
				break;

			case 4:
			    info();
				break;

			case 5:
				a=5;

				break;

			default:
				printf("Invalid choice\n");
				break;
		}
	}
}
int rateChange(int prize)
{
	char pass[10],pak[10]="password";
	printf("Enter the password to change price of ticket: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		printf("Please enter new price: ");
		scanf("%d",&prize);
		system("PAUSE");
		system("CLS");
	}
	else
		printf("The entered password is wrong! ");
	return prize;
}
void booking(int *array,int price,int selection)
{
		int i,arrray[100],j, m;
		printf("\n press 1 for SCREEN 1\n\n\n");
		printf("\n press 2 for SCREEN 2\n\n\n");
		scanf("%d", &m);
		system("cls");
        printf("Booking for screen %d\n", m);
        for (i=1;i<=100;i++)
		{
			if (array[i]==0)
				printf("%d\t",i);
			else
				printf("\t",i);
			if(i%10==0)
				printf("\n\n");
		}
		printf("Please enter your name: ");
		scanf(" %19[^\n]%*[^\n]",&cust[count].name);
		printf("Please enter your phone number: ");
		scanf("%u",&cust[count].phone);
		printf("Which seat number you want? ");
		scanf("%d",&j);
		if (j>100||j<1)
			{
				printf("Seat number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;
		cust[count].seat=j;
		if (selection==1)
			book_1(j,cust[count].name,id2,price,m);
		else if (selection==2)
			book_2(j,cust[count].name,id2,price,m);
		else
			book_3(j,cust[count].name,id2,price,m);
		id2++;
}
int option(void)
{
	int choice;
	printf("                 Simple Movie Ticket Booking System\n");
	printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("**         *   1- To book tickets:                       *         **\n");
	printf("||         *   2-  To cancel the booking:                *         ||\n");
	printf("**         *   3- To change price of ticket (only admin):*         **\n");
	printf("||         *   4- To view booked tickets (only admin):   *         ||\n");
	printf("**         *   5- Exit:                                  *         **\n");
	printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}
void cancelBooking(int *array)
{
      int Cseat,i,stop;
	  printf("Please enter ID number of ticket: ");
	  scanf("%d",&Cseat);
	  for (i=0;i<300;i++)
	  {
	  		if(Cseat==cust[i].id)
	  		{
					 stop=5;
					 system("cls");
					 printf("%s your seat is %d cancelled",cust[i].name,cust[i].seat);
					 array[cust[i].seat]=0;
					 i=300;
	  		}
	  }
	  if (stop!=5)
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
}
void  book_1(int choice,char name[10],int id2,int price, int screen)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name :varisu\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 14-12-2022\n");
        printf("\t                                              Time      : 08:00pm\n");
        printf("\t                                              Screen      : %d\n", screen);
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		cust[count].id=id2;
        printf("\t============================================================\n");
        return;
}
void info(void)
{
	int i;
	char pass[10],pak[10]="password";
	printf("Enter the password to see details: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		for (i=0;i<count;i++)
		{
			printf("seat no: %d is booked by %s booking id is %d\n",cust[i].seat,cust[i].name,cust[i].id);
		}
	}
	else
		printf("Entered password is wrong \n");
		system("PAUSE");
		system("CLS");

}
int movie(void)
{
	int i;
	system("cls");
	printf("\t\t\twhich movie you want to see?\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tpress 1 for varisu\n\n");
	printf("\t\t\tpress 2 for thunivu\n\n");
	printf("\t\t\tpress 3 for jailer\n");
	scanf("%d",&i);
	system("cls");
	return i;
}
void  book_2(int choice,char name[10],int id2,int price, int screen)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name :thunivu\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 14-12-2022");
        printf("\t                                              Time      : 09:00pm\n");
        printf("\t                                              Screen      : %d\n", screen);
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        cust[count].id=id2;
        printf("\t============================================================\n");

}
int cancelmovie(void)
{
	int i;
	printf("\t\t\twhich movie ticket you want to cancel\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tpress 1 for varisu\n\n");
	printf("\t\t\tpress 2 for thunivu\n\n");
	printf("\t\t\tpress 3 for jailer\n");
	scanf("%d",&i);
	return i;
}
void  book_3(int choice,char name[10],int id2,int price, int screen)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : jailer\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 14-12-2022\n");
        printf("\t                                              Time      : 10:00pm\n");
        printf("\t                                              Screen      : %d\n", screen);
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        cust[count].id=id2;
        printf("\t============================================================\n");

}
