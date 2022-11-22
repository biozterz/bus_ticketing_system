// Login system.
// Interface to select seat.
// Check and Select bus schedule. Including time and destination.
// Select seat class.
// Select, select multiple & modify seat selection. Store selection in a db.
// Cancel seat selection and provide refund.  
// View bus status.

#include<stdio.h>
#include <stdlib.h>
#include<string.h>

struct passengerDetails
{
	int passengerAge;
	char passengerName[15];
} p1;

struct Date 
{
	int year;
	int month;
	int day;
} date;

struct tripDetails
{

	int tripNumber;
	struct Date departureDate;
	char coachClass[15];
	float totalPaymentAmount;
	int seatNumber[30];
} trip;

typedef struct node
{
	int data;
	struct passengerDetails passengerDetails1;
	struct tripDetails tripDetails1;
	struct node *next;
} Node;

Node *start = NULL;
		
// Global variables
int numPassengers;

int seatSelection(){
	printf("Select your seat:\n");
	printf("\t [1][2] [3][4]\n");
	printf("\t [5][6] [7][8]\n");
	printf("\t [9][10] [11][12]\n");
	printf("\t [13][14] [15][16]\n");
	printf("\t [17][18] [19][20]\n");

	for(int i=0; i<numPassengers; i++){
		printf("Enter seat number for passenger %d:\n", i+1);
		scanf("%d", &(trip.seatNumber[i]));
	}
	
	return 0;
}

int bill(){

	Node *ptr = start;
	for(int i=0; i<numPassengers; i++){
		printf("Name: %s\n", ptr -> passengerDetails1.passengerName);
		printf("Age: %d\n", ptr ->passengerDetails1.passengerAge);
		ptr = ptr -> next;
	}

	printf("Seats chosen:\n");
	for(int i=0; i<numPassengers; i++){
		printf("%d\n", trip.seatNumber[i]);
	}
	return 0;
}

int classSelection(int p1, int p2, int p3, int np){
	printf("Select coach class:\n");
	printf("\t 1 First Class (RM40)\n");
	printf("\t 2 Second Class (RM30)\n");
	printf("\t 3 Third Class (RM20)\n");

	int k;
	printf("Enter your coach class number:\n");
	scanf("%d", &k);
	
	switch (k)
	{
	case 1:
		trip.totalPaymentAmount = p1 * np;
		strcpy(trip.coachClass, "First Class");
		break;
	case 2:
		trip.totalPaymentAmount = p2 * np;
		strcpy(trip.coachClass, "Second Class");
		break;
	case 3:
		trip.totalPaymentAmount = p3 * np;
		strcpy(trip.coachClass, "Third Class");
		break;
	default:
		printf("trip amount invalid");
		break;
	} 

	return trip.totalPaymentAmount;
}

int tripSelection(){

	int i, price1, price2, price3, t;

	printf("Select trip:\n");
	printf("\t 1 JB Sentral to Melaka Sentral\n");
	printf("\t 2 JB Sentral to KL Sentral\n");
	printf("\t 3 Melaka Sentral to JB Sentral\n");
	printf("\t 4 Melaka Sentral to KL Sentral\n");
	printf("\t 5 KL Sentral to JB Sentral\n");
	printf("\t 6 KL Sentral to Melaka Sentral\n");

	printf("Enter trip number:");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		trip.tripNumber = 1;
		price1 = 12;
		price2 = 10;
		price3 = 8;
		t = classSelection(price1, price2, price3, numPassengers);
		printf("total price: %d", t);
		break;
	case 2:
		trip.tripNumber = 2;
		price1 = 14;
		price2 = 12;
		price3 = 10;
		t = classSelection(price1, price2, price3, numPassengers);
		printf("total price: %d\n", t);
		break;
	case 3:
		trip.tripNumber = 3;
		price1 = 12;
		price2 = 10;
		price3 = 8;
		t = classSelection(price1, price2, price3, numPassengers);
		printf("total price: %d\n", t);
		break;
	case 4:
		trip.tripNumber = 4;
		price1 = 10;
		price2 = 8;
		price3 = 6;
		t = classSelection(price1, price2, price3, numPassengers);
		printf("total price: %d\n", t);
		break;
	case 5:
		trip.tripNumber = 5;
		price1 = 14;
		price2 = 12;
		price3 = 10;
		t = classSelection(price1, price2, price3, numPassengers);
		printf("total price: %d\n", t);
		break;
	case 6:
		trip.tripNumber = 6;
		price1 = 10;
		price2 = 8;
		price3 = 6;
		t = classSelection(price1, price2, price3, numPassengers);
		printf("total price: %d\n", t);
		break;
	default:
		printf("Please enter valid trip number\n");
		break;
	}

	printf("Enter departure year:\n");
	scanf("%d", &(trip.departureDate.year));

	printf("Enter departure month:\n");
	scanf("%d", &(trip.departureDate.month));

	printf("Enter departure date:\n");
	scanf("%d", &(trip.departureDate.day));

	seatSelection();
	bill();

	return 0;
}

void printList(Node* n){
	while(n!=NULL){
		printf("%d\n", n -> data);
		printf("%d\n", n -> passengerDetails1.passengerAge);
		n = n -> next;
	}
}

void addNode(char na[15], int ag){
	Node *newptr = NULL, *ptr;	// this is the same as int b, c, a=1; Just that both initialisations are of the type Node.

	// Allocate node dynamically.
	// The pointers to the node is called as head.
	newptr = (Node*) malloc(sizeof(Node));

	// Add in the details.
	strcpy(newptr -> passengerDetails1.passengerName, p1.passengerName);
	newptr -> passengerDetails1.passengerAge = p1.passengerAge;
	newptr -> next = NULL;

	if (start == NULL)
	{
		start = newptr;
	} else {
		ptr = start;
		while(ptr -> next != NULL){
			ptr = ptr -> next;
		}
		ptr -> next = newptr;
	}

	printList(start);
}

//Get passenger details.
void passengerDetails(int n){

	for (int i = 0; i < n; i++)
	{
	
	printf("Enter name:");
	scanf("%s", (p1.passengerName)); 
	// array and &array both yield a pointer to the same address, but with different types. The former is equivalent in most situations to &array[0], a char * in your case. 
	// &array, however, is the address of the array itself, which has type char (*)[10] in your example.

	// An array is already a pointer like object, as array can decay to pointers but have different semantics. 
	// Hence, & is not needed since the existing method is already setting p1.passengerName to a pointer to the 64 byte region of memory.

	printf("Enter age:");
	scanf("%d", &(p1.passengerAge));

	addNode(p1.passengerName, p1.passengerAge);
	}
}

int main(){

	printf("Enter number of passengers:");
	scanf("%d", &numPassengers);

	passengerDetails(numPassengers);
	
	tripSelection();
	
}

