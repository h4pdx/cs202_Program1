
/* Ryan Hoover
 * CS 202 - Fant - SPRING 2017
 * Program 1
 * 04/21/17 */

#include "list.h"

/***********************************************/ 

int main()
{
    struct timeval start_time;
    gettimeofday(&start_time, NULL);
    srand(start_time.tv_usec);

    maze myMaze;
    player player1;
    pList playerList;
    // create the maze on running the program
    if (myMaze.generate())
        cout << "\nMaze generated.\n";
    else cout << "\nMaze NOT generated.\n";
    int playerCount = 0;
    int menu = 0;
    do
    {
        menu = mainMenu();
        switch (menu)
        {
            case 1: // OPTION 1 - ADD PLAYERS
                do // while (again())
                {
                    cout << "\nAdd a player!!\n";
                    do // while (!confirm())
                    {
                        player1.read();
                        player1.display();
                    } while (!confirm());
                    if (playerList.push(player1))
                    {
                        ++playerCount;
                        cout << "\nPlayer addd to the lsit!\n";
                    }
                    else cout << "\nPlayer not added.\n";
                } while (again());
                // display players in the game
                break;
            case 2: // OPTION 2 - DISPLAY MAP
                cout << "\nView the maze map. (Checkpoints and their paths)\n";
                // displays all the checkpoints, the points they contain, and all possible paths
                if (myMaze.displayCheckpoints())
                    cout << "\nHere's the map, now go out and win!\n";
                else cout << "\nNothing to display.\n";
                break;
            case 3: // OPTION 3 - PLAY THE GAME
                cout << "\nTime to play!\n";
                player readyPlayers[playerCount];
                for (int i = 0; i < playerCount; ++i)
                {
                    if (playerList.peek(readyPlayers[i]))
                    {
                        readyPlayers[i].display();
                        cout << "\nPlayer" << i << " ready to play\n";
                        if (!playerList.pop())
                            cout << "\nNot popped.\n";
                    }
                    else cout << "\nPlayer"<< i <<" not ready.\n";
                }
                // loop to control game flow
                int i, goHere;
                i = goHere = 0;
                do{
                    // display player loaction and adjacent paths
                    cout << "\n_-_-_- Player " << i+1 << " _-_-_- ";
                    cout << "\n>> Make a move >>\n";
                    readyPlayers[i].display();
                    myMaze.displayAdjacent(readyPlayers[i].getLoc());
                    // player specifies where they want to go
                    cout << "\nWhere would you like to go? \n";
                    cin >> goHere; cin.ignore(SIZE, '\n');
                    if (cin.fail())
                        cout << "\nEnter a valid number.\n";
                    while (cin.fail())
                    {
                        cin.clear(); cin.ignore();
                        cin >> goHere; cin.ignore(SIZE,'\n');
                    }
                    // player location is set to the value of the input
                    readyPlayers[i].setLoc(goHere);
                    // current checkpoint rewrds are given to player
                    readyPlayers[i].setStars(myMaze.awardStars(goHere));
                    // check to see if current location is the end
                    if (myMaze.isEnd(goHere))
                        cout << "\n*** YOU WIN ***\n";
                    // continue loop thru array or start back at player 1
                    if (i < playerCount-1)
                        ++i;
                    else i = 0;
                } while (!myMaze.isEnd(goHere));
                cout << "\n*** GAME RESULTS ***\n";
                for (int j = 0; j < playerCount; ++j)
                    readyPlayers[j].display();
                cout << "\nThanks for playing!\n";
                break;
        }
    }
    while (menu != 4 && backToMenu());
    return 0;
}

/***********************************************/ 

