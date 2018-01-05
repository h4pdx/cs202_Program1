
/* Ryan Hoover
 * CS 202 - Fant - SPRING 2017
 * Program 1
 * 04/21/17 */

#include "graph.h"
/***********************************************************/

int mainMenu(void) {
    int menu = 0;
    cout << "\n\n+ + Main Menu + + + +\n"
         << "\nPress > 1 < to add players."
         << "\nPress > 2 < to display the Maze Map."
         << "\nPress > 3 < to plauy the game."
         << "\nPress > 4 < to quit.";
    do {
        cout << "\n >> Make a selection: ";
        cin >> menu; cin.ignore(SIZE,'\n');
        if (cin.fail())
            cout << "\nError - Enter a valid number: ";
        while (cin.fail()) {
            cin.clear(); cin.ignore();
            cin >> menu; cin.ignore(SIZE,'\n');
        }
    } while (menu < 1 || menu > 4);
    return menu;
}

/***********************************************************/

bool again(void) {
    char response = 'n';
    bool again = false;
    do {
        cout << "\n >> Again? (y,n): ";
        cin >> response; cin.ignore(SIZE,'\n');
        if (response == 'Y' || response == 'y')
            again = true;
    } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
    return again;
}

/***********************************************************/

bool backToMenu(void) {
    char response = 'n';
    bool back = false;
    do {
        cout << " >> Back to menu? (y,n): ";
        cin >> response; cin.ignore(SIZE,'\n');
        if (response == 'Y' || response == 'y')
            back = true;
    } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
    return back;
}

/***********************************************************/

bool confirm(void) {
    char response = 'n';
    bool confirm = false;
    do {
        cout << " >> Confirm? (y,n): ";
        cin >> response; cin.ignore(SIZE,'\n');
        if (response == 'Y' || response == 'y')
            confirm = true;
    } while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
    return confirm;
}

/***********************************************************/

// Paves the word as all lower case, then goes through again and capitalizes accordingly
int formatTitle(char * aTitle)
{
    if (!aTitle) return 0;
    int t = strlen(aTitle);
    aTitle[0] = toupper(aTitle[0]);
    for (int i=1; i < t; ++i)
    {
        aTitle[i] = tolower(aTitle[i]);
    }
    for (int i=1; i < t; ++i)
    {
        if (aTitle[i] == ' ')
        {
            aTitle[i+1] = toupper(aTitle[i+1]);
        }
    }
    return 1;
}

/***********************************************************/

// Paves the word as all lower case, then goes through again and capitalizes accordingly
int formatDef(char * aDef)
{
    if (!aDef) return 0;
    int d = strlen(aDef);
    aDef[0] = toupper(aDef[0]);
    for (int i=1; i < d; ++i)
    {
        aDef[i] = tolower(aDef[i]);
    }
    for (int i=1; i < d; ++i)
    {
        if (aDef[i] == '.' || aDef[i] == '!' || aDef[i] == '?')
        {
            if (aDef[i+1] == ' ')
            {
                aDef[i+2] = toupper(aDef[i+2]);
            }
            else
            {
                aDef[i+1] = toupper(aDef[i+1]);
            }
        }
    }
    return 1;
}

/***********************************************************/

