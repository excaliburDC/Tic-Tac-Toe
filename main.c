#include <stdio.h>

char grid[9]={'1','2','3','4','5','6','7','8','9'};

//prints the menu screen
void menu()
{
    char choice;

    printf("\n\n\t\t\t\t\tWelcome to the game of\n");
    printf("\t\t\t\t     - - - - - - - - - - - - - - ");
    printf("\n\t\t\t\t\t     TIC TAC TOE\n");
    printf("\t\t\t\t\t   - - - - - - - - \n\n");
    printf("\t\t\t\tPress 's' or 'S' to start the game...  ");
    scanf("\n%c",&choice);
    if(choice == 's' || choice == 'S')
    {
        printf("\n\n\t\t Starting Game...\n\n");
        printf("\t\t Initializing game board....\n\n");
        gameBoard(grid);

    }


}

//function to put the mark i,e., X or O in the grids
void putMark(int *player,int no,char mark)
{
    /*if grid is empty it will fill the respective grid with a mark
    otherwise it will again ask the player to enter an empty grid if the it is
    already filled */
    switch(no)
    {
        case 1:
            if(grid[0]=='1')
                grid[0]=mark;
            else if(grid[0]=='X' || grid[0]=='O')
            {
                --*player;
                printf("\n\n Invalid move...This slot is already occupied\n");

            }
            break;

        case 2:
            if(grid[1]=='2')
                grid[1]=mark;

            else if(grid[0]=='X' || grid[0]=='O')
            {
                --*player;
                printf("\n\n Invalid move...This slot is already occupied\n");
            }
            break;

        case 3:
            if(grid[2]=='3')
                grid[2]=mark;

            else if(grid[0]=='X' || grid[0]=='O')
            {
                --*player;
                printf("\n\n Invalid move...This slot is already occupied\n");
            }
            break;

        case 4:
            if(grid[3]=='4')
                grid[3]=mark;

            else if(grid[0]=='X' || grid[0]=='O')
            {
                --*player;
                printf("\n\n Invalid move...This slot is already occupied\n");
            }
            break;

        case 5:
            if(grid[4]=='5')
                grid[4]=mark;

            else if(grid[0]=='X' || grid[0]=='O')
            {
                --*player;
                printf("\n\n Invalid move...This slot is already occupied\n");
            }
            break;

        case 6:
            if(grid[5]=='6')
                grid[5]=mark;

            else if(grid[0]=='X' || grid[0]=='O')
            {
                --*player;
                printf("\n\n Invalid move...This slot is already occupied\n");
            }
            break;

        case 7:
            if(grid[6]=='7')
                grid[6]=mark;

            else if(grid[0]=='X' || grid[0]=='O')
            {
                --*player;
                printf("\n\n Invalid move...This slot is already occupied\n");
            }
            break;

        case 8:
            if(grid[7]=='8')
                grid[7]=mark;

            else if(grid[0]=='X' || grid[0]=='O')
            {
                --*player;
                printf("\n\n Invalid move...This slot is already occupied\n");
            }
            break;

        case 9:

            if(grid[8]=='9')
                grid[8]=mark;

            else if(grid[0]=='X' || grid[0]=='O')
            {
                --*player;
                printf("\n\n Invalid move...This slot is already occupied\n");
            }
            break;

        default:
            printf("\n\t\tInvalid move...\n\n");
            player--;
            break;


    }
}


//function to check the winner of the game
int checkWinner()
{
    //checks if all the grids in row 1 are equal
    if(grid[0]==grid[1]&&grid[1]==grid[2])
        return 1;

     //checks if all the grids in row 2 are equal
    else if(grid[3]==grid[4]&&grid[4]==grid[5])
        return 1;

     //checks if all the grids in row 3 are equal
    else if(grid[6]==grid[7]&&grid[7]==grid[8])
        return 1;

    //checks if all the grid for diagonal 1 are equal
    else if(grid[0]==grid[4]&&grid[4]==grid[8])
        return 1;

    //checks if all the grids for diagonal 2 are equal
    else if(grid[2]==grid[4]&&grid[4]==grid[6])
        return 1;

    //checks if all the grids in column 1 are equal
    else if(grid[0]==grid[3]&&grid[3]==grid[6])
        return 1;

    //checks if all the grids in column 2 are equal
    else if(grid[1]==grid[4]&&grid[4]==grid[7])
        return 1;

    //checks if all the grids in column 3 are equal
    else if(grid[2]==grid[5]&&grid[5]==grid[8])
        return 1;

    else if(grid[0]!= '1' && grid[1]!= '2' && grid[2]!= '3' && grid[3]!= '4' && grid[4]!= '5' && grid[5]!= '6'
            && grid[6]!= '7' && grid[7]!= '8' && grid[8]!= '9')
    {
        return 0;
    }

    //else return -1 to end the do while loop and determine the winner
    else
        return -1;

}


//prints the game board
void gameBoard(char grid[])
{
    printf("\t\t _________________ \n ");
    printf("\t\t|  %c  |  %c  |  %c  |\n",grid[0],grid[1],grid[2]);
    printf("\t\t|_____|_____|_____|\n");
    printf("\t\t|  %c  |  %c  |  %c  |\n",grid[3],grid[4],grid[5]);
    printf("\t\t|_____|_____|_____|\n");
    printf("\t\t|  %c  |  %c  |  %c  |\n",grid[6],grid[7],grid[8]);
    printf("\t\t|_____|_____|_____|\n");

}

int main()
{
    int player=1,grid_no,counter;
    char symbol;

    menu();
    do
    {
        //determines player turns
        player = (player % 2)? 1:2;
        printf("\nPlayer %d 's turn: ",player);
        printf("\nEnter the grid no. to put your mark : ");
        scanf("%d",&grid_no);
        //decides the symbol for player 1 & 2
        symbol = (player==1)? 'X':'O';


        putMark(&player,grid_no,symbol);
        gameBoard(grid);

        //checks for the winner by calling checkWinner() function
        counter = checkWinner();
        //increments the player turn
        player++;

    }
    while(counter == -1);

    if(counter==1)
        printf("\n\n\t\tGame Over...\n\t\tPlayer %d won",--player);

    else if(counter==0)
        printf("\n\n\t\tGame Over...\n\t\tMatch Drawn\n\n");


    return 0;
}
