//airline reservation system
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ROW 6
#define COL 4
#define MAX 25
int costMatrix[ROW][COL] = { {500,200,200,500},{500,200,200,500},{500,200,200,500},{500,200,200,500},{500,200,200,500},{500,200,200,500} };
void initialSeats(char[][COL], int);
void displayMenu();
int errorcheck(int);
void printFlightMap(char[][COL]);
int getTotalRevenue(char[][COL], char[][COL], char[][COL]);
void flightMenu();
void seatReservation(char[][COL]);
void printMessage(char[], char[]);
int main(void)
{
	int count, result = 0, loop = 0, option;//result is for all errorchecking, loop is for looping the entire system until termination
	char adminPasscode[] = "105016";
	char passcode[50];
	srand(time(NULL));
	char flight1[ROW][COL];
	char flight2[ROW][COL];
	char flight3[ROW][COL];
	char name[MAX];
	char num1[8] = "MIA1050";
	char num2[8] = "BNA1050";
	char num3[8] = "LAS1050";
	count = 1 + rand() % 5;//1 through 5
	initialSeats(flight1, count);
	initialSeats(flight2, count);
	initialSeats(flight3, count);
	printf("\nWELCOME TO JOE'S AIRLINE BOOKING SYSTEM");
	while (loop == 0)
	{
		while (result == 0)
		{
			displayMenu();
			scanf_s("%d", &option);
			result = errorcheck(option);
			if (result == 0)
			{
				printf("Wrong option! Choose a right option again");
			}
		}
		result = 0;
		if (option == 1)//admin mode
		{
			printf("\n\nEnter the login passcode to log in as admin:");
			scanf_s("%s", passcode, sizeof(passcode));
			result = strcmp(passcode, adminPasscode);
			if (!result) {
				printf("\n\nPrinting the Flight Map of flight Columbia to Miami....\n\n");
				printFlightMap(flight1);
				printf("\n\nPrinting the Flight Map of flight Columbia to Nashville....\n\n");
				printFlightMap(flight2);
				printf("\n\nPrinting the Flight Map of flight Columbia to Las Vegas\n\n");
				printFlightMap(flight3);
				printf("\n\nThe total earning from all the flights: $%d", getTotalRevenue(flight1, flight2, flight3));
				printf("\n\nYou are logged out now!");
			}
			else printf("\nincorrect password");
		}
		if (option == 2)//seat reservation mode
		{
			while (result == 0)
			{
				flightMenu();
				scanf_s("%d", &option);
				result = errorcheck(option);
			}
			result = 0;
			printf("\n\nEnter your first name:");
			scanf_s("%24s", name);
			if (option == 1)
			{
				seatReservation(flight1);
				printMessage(name, num1);
			}
			if (option == 2)
			{
				seatReservation(flight2);
				printMessage(name, num2);
			}
			if (option == 3)
			{
				seatReservation(flight3);
				printMessage(name, num3);
			}
		}
		if (option == 3)//termination mode
		{
			printf("\n\nTerminating the Program\n\nThank you for using Joe's Airline Booking System.\n\n");
			loop = 1;
		}
	}
	return 0;
}
void initialSeats(char flight[][COL], int count)
{
	int i = 0, j = 0, row, col;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			flight[i][j] = 'O';//sets all seats to open
		}
	}
	for (i = 0;i < count;i++)
	{
		row = rand() % ROW;
		col = rand() % COL;
		if (flight[row][col] == 'X')//sets a number of seats equal to count to X
		{
			count++;//do nothing if the seat is already X, and add one to count so it is done an extra time
		}
		else
		{
			flight[row][col] = 'X';
		}
	}
}
void displayMenu()
{
	printf("\n\n1.) Admin Log-in\n\n2.) Reserve a seat\n\n3.) Exit\n\nChoose an option:");
}
int errorcheck(int option)
{
	if (option < 1 || option > 3)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void printFlightMap(char flight[][COL])
{
	int i = 0, j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			printf("%2c", flight[i][j]);
		}
		printf("\n\n");
	}
}

int getTotalRevenue(char flight1[][COL], char flight2[][COL], char flight3[][COL])
{
	int i = 0, j = 0, total = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			if (flight1[i][j] == 'X')
			{
				total += costMatrix[i][j];
			}
			if (flight2[i][j] == 'X')
			{
				total += costMatrix[i][j];
			}
			if (flight3[i][j] == 'X')
			{
				total += costMatrix[i][j];
			}
		}
	}
	return total;

}
void flightMenu()
{
	printf("\n\n1.)COU---->MIA\n\n2.)COU---->BNA\n\n3.)COU---->LAS\n\nChoose a flight:");
}
void seatReservation(char flight[][COL])
{
	int row, col, loop1 = 0, loop2 = 0;//loop1 is for restarting if the seat has been taken, loop2 is for errorchecking values of row/column
	printFlightMap(flight);
	printf("\n\n");
	while (loop1 == 0)
	{
		while (loop2 == 0)
		{
			printf("\n\nWhich Seat row do you want? :");
			scanf_s("%d", &row);
			if (row < 0 || row > 5)
			{
				printf("\n\nSeat rows are between 0 and 5.\n\nTry Again.");
			}
			else
			{
				loop2 = 1;
			}
		}
		loop2 = 0;
		while (loop2 == 0)
		{
			printf("\n\nWhich seat column do you want? :");
			scanf_s("%d", &col);
			if (col < 0 || col > 3)
			{
				printf("\n\nSeat columns are between 0 and 3.\n\nTry Again.");
			}
			else
			{
				loop2 = 1;
			}
		}
		loop2 = 0;
		if (flight[row][col] == 'X')
		{
			printf("\n\nSorry!! someone has reserved that seat. Please Try Again.");
		}
		else if (flight[row][col] == 'O')
		{
			loop1 = 1;
		}
	}
	flight[row][col] = 'X';
	printf("\n\nYour requested seat has been reserved\n");
	printFlightMap(flight);
}
void printMessage(char name[], char num[])
{
	int i = 0, loop = 0, loop2 = 0;
	printf("\n\nCongrats %s, your flight %s is booked, enjoy your trip.", name, num);
	printf("\n\nYour e-ticket number is:");
	//The following is simply a bonus that mixes the persons name and their number together to form the ticket number
	while (loop == 0)
	{
		if (name[i] != '\0' && num[i] != '\0')//prints a character from both arrays when neither has reached a null terminator
		{
			printf("%c%c", name[i], num[i]);
			i += 1;
		}
		if (name[i] != '\0' && num[i] == '\0')//prints the rest of the name once the number reaches the null terminator
		{
			printf("%c", name[i]);
			i += 1;
			while (loop2 == 0)
			{
				if (name[i] != '\0')
				{
					printf("%c", name[i]);
					i += 1;
				}
				else
				{
					loop2 = 1;
					loop = 1;
				}
			}
		}
		if (name[i] == '\0' && num[i] != '\0')//prints the rest of the number when the name reaches  the null terminator
		{
			printf("%c", num[i]);
			i += 1;
			while (loop2 == 0)
			{
				if (num[i] != '\0')
				{
					printf("%c", num[i]);
					i += 1;
				}
				else
				{
					loop2 = 1;
					loop = 1;
				}
			}
		}
		if (name[i] == '\0' && num[i] == '\0')
		{
			loop = 1;
		}
	}
	printf("\n\nThank You :)");
}
