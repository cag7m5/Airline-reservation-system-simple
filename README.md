# simple-c
#include <stdio.h>
  3 #include <stdlib.h>
  4 #include <time.h>
  5 #define ROW 6
  6 #define COL 4
  7 #define MAX 25
  8 int costMatrix[ROW][COL]={{500,200,200,500},{500,200,200,500},{500,200,200,500},{500,200,200,500},{500,200,200,500},{500,200,200,500}};
  9 void initialSeats(char[][COL], int);
 10 void displayMenu();
 11 int errorcheck(int);
 12 void printFlightMap(char[][COL]);
 13 int loginMatch(int,int);
 14 int getTotalRevenue(char[][COL], char[][COL], char[][COL]);
 15 void flightMenu();
 16 void seatReservation(char[][COL]);
 17 void printMessage(char[], char[]);
 18 int main(void)
 19 {
 20     int count,result=0, loop=0, option, passcode, adminPasscode=105016;//result is for all errorchecking, loop is for looping the entire system until termination
 21     srand(time(NULL));
 22     char flight1[ROW][COL];
 23     char flight2[ROW][COL];
 24     char flight3[ROW][COL];
 25     char name[MAX];
 26     char num1[8]="MIA1050";
 27     char num2[8]="BNA1050";
 28     char num3[8]="LAS1050";
 29     count=1+rand()%5;//1 through 5
 30     initialSeats(flight1, count);
 31     initialSeats(flight2, count);
 32     initialSeats(flight3, count);
 33     printf("\n********* WELCOME TO JOE'S AIRLINE BOOKING SYSTEM *********");
 34     while (loop==0)
 35     {
