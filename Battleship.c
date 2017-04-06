/*
 Program Name: Battleship.c
 Programmer: Donovan Colton

 Date: 10/27/16
 */

/*
* Program implements game of BATTLESHIP
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int userBoard[SIZE];
int cpuBoard[SIZE];
//print playing boards
void printBoard(int *ptr){
    printf("\t0 1 2 3 4 5 6 7 8 9\n\t");
    int i = 0;
    while (i < SIZE){
        printf("%c ",*(ptr + i));
        i++;
    }
    printf("\n\n");
}
//Random num generator
int nextRand(int range){
    int r = rand();
    return r % range;
}

void setBoard(int *ptr){
    int point1;
    int point2;
    printf("Set your ship:\n");
    //loop until two consectutive points are entered
    while (1){
        printf("\tCoordinate 1: ");
        scanf("%d",&point1);

        printf("\tCoordinate 2: ");
        scanf("%d",&point2);
        printf("\n");

        //exit loop
        if ( abs(point1 - point2) == 1 )
            break;
        else
            printf("\t Invalid location\n");
    }
    *(ptr + point1) = 'S';
    *(ptr + point2) = 'S';
}

void setCpuBoard(int *ptr){
    int point1;
    int point2;

    //select first point
    point1 = nextRand(10);
    *(ptr + point1) = 'S';
    //
    point2 = nextRand(2);

    if(*(ptr+0) == 'S'){
      *(ptr + 1) = 'S';
      return;
    }
    if(*(ptr+9) == 'S'){
      *(ptr + 8) = 'S';
      return;
    }
    //randomly select ship placement
    if (point2 == 1){
       *(ptr + point1 + 1) = 'S';
    } else{
        *(ptr + point1 - 1) = 'S';
    }
}

void showInstructions(){
    printf("**************************************\n");
    printf("            BATTLESHIP                \n");
    printf("   1. Choose your ship location.      \n");
    printf("      ex. (2, 3) (1,0) (8,9) (0,9)    \n");
    printf("   2. Choose one spot to fire         \n");
    printf("      at the CPU ship.                \n");
    printf("      playing field: 0 - 9            \n");
    printf("      ex. (2) (0) (9) (5)             \n");
    printf("   3. Make 2 hits on your opponents   \n");
    printf("      ship to win                     \n");
    printf("                                      \n");
    printf("   -Enter 999 to show instructions    \n");
    printf("**************************************\n");
}

int playGame(int *ptr1, int *ptr2){
    int userMove;
    int cpuMove;
    int uhits = 0;
    int cpuhits = 0;

    while(1){
        //*********cpu move**********
        printf("CPU making move:\n");
        //select new cpu move until unchosen spot is selected
        do{
            cpuMove = nextRand(10);
        }while(*(ptr1+cpuMove) == 'H' || *(ptr1+cpuMove) == 'M');
        //cpu hit

        if (*(ptr1 + cpuMove) == 'S'){
            *(ptr1 + cpuMove) = 'H';
            printf("\tCPU guesses: %d\n", cpuMove);
            printf("\tHIT!\n\tUser Board:\n");
            printBoard(userBoard);
            printf("\tCPU Board:\n");
            printBoard(cpuBoard);
            cpuhits++;
            //exit
            if (cpuhits == 2){
                return 0;
            }
        }//cpu miss
        else{
            *(ptr1 + cpuMove) = 'M';
            printf("\tCPU guesses: %d\n", cpuMove);
            printf("\tMISS!\n\tUser Board:\n");
            printBoard(userBoard);
            printf("\tCPU Board:\n");
            printBoard(cpuBoard);
        }
        //*********user move**********************
        printf("User turn: \n");
        do{
            printf("\tEnter your move (0-9): ");
            scanf("%d",&userMove);
            if (userMove == 999){
                showInstructions();
            }
        }while(*(ptr2+userMove) == 'H' || *(ptr2+userMove) == 'M' || (userMove > 9));
        //user hit
        if (*(ptr2+userMove) == 'S'){
            *(ptr2+userMove) = 'H';
            printf("\tUser guesses: %d\n", userMove);
            printf("\tHIT!\n\tUser Board:\n");
            printBoard(userBoard);
            printf("\tCPU Board:\n");
            printBoard(cpuBoard);
            uhits++;
            //exit
            if (uhits == 2){
                return 1;
            }
        }
        //user miss
        else{
            *(ptr2+userMove) = 'M';
            printf("\tUser guesses: %d\n", userMove);
            printf("\tMISS!\n\tUser Board:\n");
            printBoard(userBoard);
            printf("\tCPU Board:\n");
            printBoard(cpuBoard);
        }
    }//end while
}

int main(){
    //seeds rand() func
    srand( time(NULL) );
    char selection;
    int move;
    int i = 0;

    //init playing boards indexes with *
    while (i < SIZE){
        userBoard[i] = '*';
        cpuBoard[i++] = '*';
    }


    showInstructions();
    //references to the playing boards
    int *p1 = &userBoard;
    int *p2 = &cpuBoard;

    //set ship locations
    setBoard(p1);
    setCpuBoard(p2);

    //show orig playing boards
    printf("\tUser Board:\n");
    printBoard(userBoard);
    printf("\tCPU Board:\n");
    printBoard(cpuBoard);

    //start game
    if (playGame(p1,p2) == 0)
        printf("\tCPU wins!!");
    else
        printf("\tUser wins!!");

    return 0;
}
