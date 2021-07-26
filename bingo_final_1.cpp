#include "baseclass.h"
#include <iostream>

#include <stdlib.h>

#include <time.h>
#include <string> 
#include <random>


using namespace std;

string words[50] = {
     "teeth",
     "provide",
     "doubtful",
     "bone",
     "warlike",
     "blue-eyed",
     "cycle",
     "dream",
     "relax",
     "far",
     "cobweb",
     "daily",
     "painstaking",
     "agonizing",
     "comparison",
     "ghost",
     "soft",
     "telling",
     "abhorrent",
     "shame",
     "sign",
     "chickens",
     "acoustics",
     "smiling",
     "ignore",
     "tight",
     "pail",
     "wine",
     "crayon",
     "puzzling",
     "juice",
     "horse",
     "destroy",
     "defiant",
     "rest",
     "verse",
     "available",
     "empty",
     "spiffy",
     "neat",
     "many",
     "wonderful",
     "blood",
     "undesirable",
     "young",
     "blind",
     "ashamed",
     "hill",
     "salt",
     "agree",
};

//Implementation of main function


// The bots get a random chance to win, but they take a long time to get the win (by a stroke of luck)
// The algorithm is tested and it works well now 

int main() {

    srand(time(NULL));

    //Declaration of words[output,result,i,j,k ,figure as integer type and
   
    //assign flog with 0
    int output[5][5], i, j, k, figure = 0;
    string result[5];
    float score = 1000, scoreBot1 = 1000, scoreBot2 = 1000;
    bool play = 1;
    float betAmount = 0;
    bool betChoice = true;
    int choice = 0;
    float MAXBET = 500;
    float MINBET = 2;


    // Before the check here we will set up 5 inputs for the 2 bots
    int bot1[5], bot2[5];
    bot1[0] = rand() % 10 + 1;
    bot1[1] = rand() % 10 + 11;
    bot1[2] = rand() % 10 + 21;
    bot1[3] = rand() % 10 + 31;
    bot1[4] = rand() % 10 + 41;

    bot2[0] = rand() % 10 + 1;
    bot2[1] = rand() % 10 + 11;
    bot2[2] = rand() % 10 + 21;
    bot2[3] = rand() % 10 + 31;
    bot2[4] = rand() % 10 + 41;

    
    while (play) {
        cout << "\nCURRENT PLAYER BALANCE: $" << score << "\nCURRENT BOT 1 BALANCE: $" << scoreBot1 << "\nCURRENT BOT 2 BALANCE: $" << scoreBot2;
        cout << "\n\n\t\t--------";
        cout << "\nWelcome to BINGO! The goal of this game is to guess a 5 words on a randomized BINGO board(Can be including a freespace) and see if those 5 words you chose made a bingo on the random board. " << endl;
        cout << "\nif you win you can get payouts of 20 TIMES YOUR BET AMOUNT!" << endl;
        //cin >> choice;

        while (true)
        {
            cout << "\n\t\t| MENU:|\n\t\t-------- \n\t\t 1: PLAY \n\t\t 2: WORD LIST \n\t\t 3: Exit \n\t Your choice:  ";
            if (std::cin >> choice)
                break;
            cout << "\n\n!! Input is not in the range. Try again !!\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: {
            // STARTS THE GAME
            // FIRST YOU ENTER THE WORDS
            // AND THEN THE BINGO CARD GETS GENERATED AND SHOWN 
            // AFTER THE CARD IS SHOWN THE SCANNING STARTS
            // AND THEN IT DISPLAYS IF THERE IS A WINNER 
            // BY COMPARING WORDS IN THE HORIZONTAL OR VERTICAL LINE


            while (betChoice == true) {
                cout << "\n Enter a bet amount, numbers only (Min bet $2, Max bet $500): $";
                cin >> betAmount;
                if (betAmount <= 500 && MAXBET >= MINBET) {
                    score = score - betAmount;
                    betChoice = false;
                }
                else {
                    cout << "\nPlease enter a valid bet" << endl;
                }
            }

           
            cout << "\nTest by entering 5 unique words from the list (use 0 for FS) : ";

            cin >> result[0] >> result[1] >> result[2] >> result[3] >> result[4];

            //Iterate loop
            cout << "\n";


            for (i = 0; i < 5; i++)

            {

                //Iterate loop

                for (j = 0; j < 5; j++)

                {

                    output[j][i] = (rand() % 10) + ((10 * i) + 1);
                    //decrement k by j - 1

                    k = j - 1;

                    //iterate loop

                    while (k >= 0)

                    {

                        if (output[k][i] == output[j][i])

                        {

                            output[j][i] = (rand() % 10) + ((10 * i) + 1);

                            //decrement k by j - 1

                            k = j - 1;

                        }

                        //otherwise

                        else

                        {

                            //decrement k by 1

                            k = k - 1;

                        }

                    }

                }

            }

            //Initialize output[2][2] with 0

            output[2][2] = 0;

            //Display statement

            cout << "\n\t\t\t\t\t\tBINGO CARD: \n\n";
            cout << "\n\t\t--------------------------------------------------------------------------------------\n";

            //assign 0 to i

            i = 0;

            //Iterate loop

            while (i < 5)

            {

                //Display statement

                cout << "\t\t|";

                //iterate loop

                for (j = 0; j < 5; j++)

                {

                    if (i == 2 && j == 2)

                    {

                        //Display statement

                        cout << " \tFS |";

                    }

                    //otherwise

                    else if (output[i][j] < 10)

                    {

                        //Display statement

                        cout << " \t" << words[output[i][j]] << " |";

                    }

                    //otherwise

                    else

                    {

                        //Display statement
                        cout << " \t" << words[output[i][j]] << " |";



                    }

                }

                //Display statement

                cout << "\n\t\t--------------------------------------------------------------------------------------\n";

                //increment i by 1

                i = i + 1;

            }





            //assign 0 to i

            i = 0;




            // Iterate loop and check if the 5 words are on the card
            // If it is, add the score and display that there is a winner
            // CHECK THE PLAYER


            // HORIZONTAL CHECK

            k = 0;
            for (i = 0; i < 5; i++) {
                figure = 0;
                for (j = 0; j < 5; j++) {
                    for (k = 0; k < 5; k++) {

                        if (result[k] == words[output[i][j]]) {
                            figure++;
                        }

                        else if (to_string(output[i][j]) == result[k]) {
                            figure++;

                        }
                        if (figure == 5) {
                            cout << "\n\nWINNER!!!\n\n" << endl;
                            score = score + (betAmount * 20);
                            goto checkBots;
                        }

                    }

                }

            }

            // VERTICAL CHECK
            for (i = 0; i < 5; i++) {
                figure = 0;
                for (j = 0; j < 5; j++) {
                    for (k = 0; k < 5; k++) {
                        if (result[k] == words[output[j][i]]) {
                            figure++;
                        }

                        else if (to_string(output[i][j]) == result[k]) {
                            figure++;

                        }
                    }
                }
                if (figure == 5) {
                    cout << "\n\nWINNER!!!\n\n" << endl;
                    score = score + (betAmount * 20);
                    break;
                }

            }
            figure = 0;

            for (i = 0; i < 5; i++) {
                if (words[output[0][0]] == result[i] || words[output[1][1]] == result[i] || result[i] == to_string(output[2][2]) || words[output[3][3]] == result[i] || words[output[4][4]] == result[i]) figure++;
            }
            if (figure < 5) {
                figure = 0;
                for (i = 0; i < 5; i++) {
                    if (words[output[4][0]] == result[i] || words[output[3][1]] == result[i] || result[i] == to_string(output[2][2]) || words[output[1][3]] == result[i] || words[output[0][4]] == result[i]) figure++;
                }
            }
            if (figure == 5) {
                cout << "\n\nWINNER!!!\n\n" << endl;
                score = score + (betAmount * 20);
                figure = 0;
            }

        checkBots:
            // BOT 1 

            k = 0;
            figure = 0;
            for (i = 0; i < 5; i++) {
                for (j = 0; j < 5; j++) {
                    for (k = 0; k < 5; k++) {
                        if (words[bot1[k]] == words[output[i][j]]) {
                            figure++;
                        }

                        else if (to_string(output[i][j]) == words[bot1[k]]) {
                            figure++;

                        }
                    }

                    if (figure == 5) {
                        cout << "\n\nBOT1 IS THE WINNER!!!\n\n" << endl;
                        scoreBot1 = scoreBot1 * 4;
                        break;
                    }

                }

            }

            for (i = 0; i < 5; i++) {
                figure = 0;
                for (j = 0; j < 5; j++) {
                    for (k = 0; k < 5; k++) {
                        if (words[bot1[k]] == words[output[j][i]]) {
                            figure++;
                        }
                        else if (to_string(output[i][j]) == words[bot1[k]]) {
                            figure++;

                        }
                    }
                }
                if (figure == 5) {
                    cout << "\n\nBOT1 IS THEWINNER!!!\n\n" << endl;
                    scoreBot1 = scoreBot1 * 4;
                    break;
                }

            }
            figure = 0;

            for (i = 0; i < 5; i++) {
                if (words[output[0][0]] == words[bot1[i]] || words[output[1][1]] == words[bot1[i]] || words[bot1[i]] == to_string(output[2][2]) || words[output[3][3]] == words[bot1[i]] || words[output[4][4]] == words[bot1[i]]) figure++;
            }
            if (figure < 5) {
                figure = 0;
                for (i = 0; i < 5; i++) {
                    if (words[output[4][0]] == words[bot1[i]] || words[output[3][1]] == words[bot1[i]] || words[bot1[i]] == to_string(output[2][2]) || words[output[1][3]] == words[bot1[i]] || words[output[0][4]] == words[bot1[i]]) figure++;
                }
            }
            if (figure == 5) {
                cout << "\n\nBOT1 IS THE WINNER!!!\n\n" << endl;
                scoreBot1 = scoreBot1 * 4;
                figure = 0;
            }


            // BOT 2

            k = 0;
            figure = 0;
            for (i = 0; i < 5; i++) {
                for (j = 0; j < 5; j++) {
                    for (k = 0; k < 5; k++) {
                        if (words[bot2[k]] == words[output[i][j]]) {
                            figure++;
                        }
                        else if (to_string(output[i][j]) == words[bot2[k]]) {
                            figure++;

                        }
                    }

                    if (figure == 5) {
                        cout << "\n\nBOT2 IS THEWINNER!!!\n\n" << endl;
                        scoreBot2 = scoreBot2 * 4;
                        break;
                    }

                }

            }

            for (i = 0; i < 5; i++) {
                figure = 0;
                for (j = 0; j < 5; j++) {
                    for (k = 0; k < 5; k++) {
                        if (words[bot2[k]] == words[output[j][i]]) {
                            figure++;
                        }

                        else if (to_string(output[i][j]) == words[bot2[k]]) {
                            figure++;

                        }
                    }
                }
                if (figure == 5) {
                    cout << "\n\nBOT2 IS THE WINNER!!!\n\n" << endl;
                    scoreBot2 = scoreBot2 * 4;
                    break;
                }

            }
            figure = 0;

            for (i = 0; i < 5; i++) {
                if (words[output[0][0]] == words[bot2[i]] || words[output[1][1]] == words[bot2[i]] || words[bot2[i]] == to_string(output[2][2]) || words[output[3][3]] == words[bot2[i]] || words[output[4][4]] == words[bot2[i]]) figure++;
            }
            if (figure < 5) {
                figure = 0;
                for (i = 0; i < 5; i++) {
                    if (words[output[4][0]] == words[bot2[i]] || words[output[3][1]] == words[bot2[i]] || words[bot2[i]] == to_string(output[2][2]) || words[output[1][3]] == words[bot2[i]] || words[output[0][4]] == words[bot2[i]]) figure++;
                }
            }
            if (figure == 5) {
                cout << "\n\nBOT2 IS THE WINNER!!!\n\n" << endl;
                scoreBot2 = scoreBot2 * 4;
                figure = 0;
            }
            betChoice = true;
            break;
        }

        case 2: {
            for (i = 0; i < 50; i++) {
                cout << i + 1 << "." << words[i] << endl;

            }

            break;
        }
        case 3: {
            cout << "Thank you for playing! :)" << endl << "Your balance is now: $" << score;

            return 1;
        }
        default: {
            cout << "You enter a value that does not exist. Try again!";
        }
        }
    }


}

