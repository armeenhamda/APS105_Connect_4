#include <stdio.h>

    //Code written by: Hamda Armeen
    //Description of program: Implement a simplified version of Connect Four using C programming

#define ROWS 6
#define COLS 6
#define EMPTY '-'
#define RED 'R'
#define YELLOW 'Y'

//Prints the empty board, this function is used whenever there is a need to print the board every time after a new coin is dropped
void PrintBoard(char Board[][COLS]){
    for (int row = ROWS - 1; row >= 0; row--){
        for (int col = 0; col < COLS; col++){
            printf("%c", Board[row][col]);
        }
        printf("\n");
    }
}

//This function alternates between Red and Yellow depending on who's turn it is
//It uses a pointer to do so so that the actual value in the main function changes every time the value is changed in this function
void SwitchTurn(char* Turn){
    if (*Turn == RED){
        *Turn = YELLOW;
    }
    else if (*Turn == YELLOW){
        *Turn = RED;
    }
}

//This function takes the input from the player
int Input(char Turn, int Coin, char Board[][COLS]){
    if (Turn == YELLOW){
        printf("Yellow, please enter a valid column number (0-5): ");
    } else {
        printf("Red, please enter a valid column number (0-5): ");
    }

    scanf("%d", &Coin);

    //This while loops contiuously asks the player for input until they don't enter a reasonable column number
    while (Coin < 0 || Coin > 5 || Board[ROWS - 1][Coin] != EMPTY){ //The last condition is to ensure that the player doesn't choose a full column
        if (Turn == YELLOW) {
            printf("Yellow, please enter a valid column number (0-5): ");
        }
        else {
            printf("Red, please enter a valid column number (0-5): ");
        }
        
        scanf("%d", &Coin);
    }
    return Coin;
}

//This fucntion is for determining the winner by checking for a four-in-a-row
int Winner(char Board[][COLS]){
    int RedCounter = 0;
    int YellowCounter = 0;

    //Check horizontally
    for (int i = 0; i < ROWS; i++){
        RedCounter = 0;
        YellowCounter = 0;

        for (int j = 0; j < COLS; j++){
            //Red
            if (Board[i][j] == RED){
                RedCounter++;
                if (RedCounter == 4){
                    return RED;
                }
            } else {
                RedCounter = 0;
            }

            //Yellow
            if (Board[i][j] == YELLOW){
                YellowCounter++;
                if (YellowCounter == 4){
                    return YELLOW;
                }
            } else {
                YellowCounter = 0;
            }
        }
    }

    //Check vertically
    for (int i = 0; i < COLS; i++){
        RedCounter = 0;
        YellowCounter = 0;

        for (int j = 0; j < ROWS; j++){
            //Red
            if (Board[j][i] == RED){
                RedCounter++;
                if (RedCounter == 4){
                    return RED;
                }
            } else {
                RedCounter = 0;
            }

            //Yellow
            if (Board[j][i] == YELLOW){
                YellowCounter++;
                if (YellowCounter == 4){
                    return YELLOW;
                }
            } else {
                YellowCounter = 0;
            }
        }
    }

    //Check diagonally (left to right)
    //The reason why you have the condition of ROWS - 3 (6 - 3) is to ensure you dont try
    //finding diagonals from values of i greater than 3 since if you get 4, for example, to make a diagonal you would go a column forward
    //and you need 3 extra columns to the right to make it a four-in-a-row which won't be possible since 4 + 3 = 7, which is out of bound
    //for a 6x6 board
    for (int i = 0; i < ROWS - 3; i++){
        for (int j = 0; j < COLS - 3; j++){
            RedCounter = 0;
            YellowCounter = 0;

            //Red
            //The reason why I wrote 4 here instead of ROWS - 3 or COLS - 3 is because previously I had to make sure that i didn't go out
            //of bounds since it was being used as the starting position to check the diagornal, however, here I just want to increment
            //4 times because this is four-in-a-row so I need to check if they match 4 times
            for (int Shift = 0; Shift < 4; Shift++){
                if (Board[i + Shift][j + Shift] == RED){
                    RedCounter++;
                    if (RedCounter == 4){
                        return RED;
                    }
                } else {
                    RedCounter = 0;
                }

            //Yellow
            if (Board[i + Shift][j + Shift] == YELLOW){
                YellowCounter++;
                if (YellowCounter == 4){
                    return YELLOW;
                }
            } else {
                YellowCounter = 0;
            }
            }
        }
    }

    //Check diagonally (right to left)
    for (int i = 0; i < ROWS - 3; i++){
        for (int j = COLS - 1; j >= 3; j--){
            RedCounter = 0;
            YellowCounter = 0;

            //Red
            for (int Shift = 0; Shift < 4; Shift++){
                if (Board[i + Shift][j - Shift] == RED){
                    RedCounter++;
                    if (RedCounter == 4){
                        return RED;
                    }
                } else {
                    RedCounter = 0;
                }

                //Yellow
                if (Board[i + Shift][j - Shift] == YELLOW){
                    YellowCounter++;
                    if (YellowCounter == 4){
                        return YELLOW;
                    }
                } else {
                    YellowCounter = 0;
                }
            }
        }
    }

    return 0;
}

//This function is for dropping in the coin depending on who's turn it is
void InsertedCoin(char Board[][COLS], int Coin, char Turn){
    if (Turn == RED){
        for (int i = 0; i < ROWS; i++){
            if (Board[i][Coin] == EMPTY){
                Board[i][Coin] = RED;
                break;
            }
        }
    }
    else if (Turn == YELLOW){
        for (int i = 0; i < ROWS; i++){
            if (Board[i][Coin] == EMPTY){
                Board[i][Coin] = YELLOW;
                break;
            }
        }
    }
  
}

//This function is used for determining ties when the entire board is full yet there isn't a winner
//It checks this by iterating through every row and colum combinaion to check if the entire board doesn't have a '-' character
int FullBoard(char Board[][COLS]){
    for (int i = 0; i < COLS; i++){
        if (Board[ROWS - 1][i] == EMPTY){
            return 0; //Return zero means that the function wouldn't be used since there is still space left on the board (false)
        }
    }
    return 1; //Return one means that the function would be used to termnate the game since no more options are available on the baord (true)
}

int main(void){
    int Coin = 0;
    char Turn = RED;
    char Board[ROWS][COLS];

    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            Board[i][j] = EMPTY;
        }
    }

    while (1){
        PrintBoard(Board);  // Print the board after each move

        Coin = Input(Turn, Coin, Board);  //Get column input from player
        InsertedCoin(Board, Coin, Turn);  //Drop in the coin in the board

        //Check for winner and prints the results
        int result = Winner(Board);
        if (result == RED) {
            printf("Red wins!\n");
            printf("Final board: \n");
            PrintBoard(Board);
            break;
        } else if (result == YELLOW) {
            printf("Yellow wins!\n");
            printf("Final board: \n");
            PrintBoard(Board);
            break;
        }

        //If no one won and it was a draw, it prints the final draw board and that it was a tie
        if (FullBoard(Board)){
            printf("It's a tie\n");
            printf("Final board: \n");
            PrintBoard(Board);
            break;
        }

        //After everything is accounted for, the turns are swapped
        SwitchTurn(&Turn);
    }

    return 0;
}
