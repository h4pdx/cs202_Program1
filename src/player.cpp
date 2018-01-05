
/* Ryan Hoover
 * CS 202 - Fant - SPRING 2017
 * Program 1
 * 04/21/17 */

#include "player.h"

/***********************************************************/

name::name(): aName(0)
{

}

name::name(const name & copyFrom)
{
    if (copyFrom.aName)
    {
        aName = new char[strlen(copyFrom.aName)];
        strcpy(aName, copyFrom.aName);
    }
    else
        aName = NULL;
}

name::name(char * copyFrom)
{
    if (copyFrom)
    {       
        aName = new char[strlen(copyFrom)+1];
        strcpy(aName, copyFrom);
    }
    else
        aName = NULL;
}

name::~name()
{
    if (aName)
    {
        delete [] aName;
        aName = NULL;
    }
}

void name::read()
{
    // take user input for player name
    if (aName)
        delete [] aName;
    char newName[100];
    cout << "\nEnter your name: ";
    cin.get(newName,100,'\n'); cin.ignore(100,'\n');
    aName = new char[strlen(newName)+1];
    strcpy(aName,newName);
}

void name::display()
{
    if (aName)
        cout << "\nPlayer Name: " << aName;
    else
        cout << "\nNo player name recorded! :/\n";
}

/***********************************************************/

player::player()
    :name()
{
    location = stars = 0;
}

player::player(const player & copyFrom)
    :name(copyFrom.aName)
{
    location = copyFrom.location;
    stars = copyFrom.stars;
}


player::player(char * newName, int aLocation, int aStars)
    :name(newName)
{
    location = aLocation;
    stars = aStars;
}

player::player(const name & input)
    :name(input)
{
}

player::~player()
{
}

void player::copyPlayer(player & dest, player & source)
{
    
    //name(source.aName);
    if (source.aName)
    {
        dest.aName = new char[strlen(source.aName)+1];
        strcpy(dest.aName, source.aName);
        dest.location = source.location;
        dest.stars = source.stars;
    }
}

void player::display()
{
    // shows player locarion, name, and points
    name::display();
    cout << "\nCurrent Checkpoint: #" << location;
    cout << "\n*** " << stars << " Stars accumulated *** " << endl << endl;
}

void player::setLoc(int newLoc)
{
    location = newLoc;
}

int player::getLoc()
{
    return location;
}

void player::setStars(int toAdd)
{
    stars += toAdd;
}

int player::getStars()
{
    return stars;
}

/***********************************************************/

