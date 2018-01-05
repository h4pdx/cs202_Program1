
/* Ryan Hoover
 * CS 202 - Fant - SPRING 2017
 * Program 1
 * 04/21/17 */

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "graph.h"


// derive player & reward from name
class name
{
    public:
        name();
        name(const name & copyFrom);
        name(char * copyFrom);
        ~name();
        void read();
        void display();


    protected:
        char * aName;
};

class player: public name
{
    public:
        player();
        player(const name & input);
        player(char * newName, int aLocation, int aStars); // one of the name funcs might be unecessary (see labs)
        player(const player & copyFrom);
        ~player();
        //void setLoc(checkpoint * newLoc);
        //checkpoint *& getLoc();
        //void read();
        void setLoc(int newLoc);
        int getLoc();
        bool endCheck();
        void display();
        void setStars(int toAdd);
        int getStars();
        void copyPlayer(player & dest, player & source);

    protected:
        //checkpoint * location;
        int location;
        //char * teamName; /* Just an Idea... if I HAVE to do teams */
        /* Implement ASAP! */
        int stars;
};


/* Going easy on it and just making rewards an int */
/*
class reward: public name
{

    public:
        reward();
        reward(const reward & copyFrom);
        reward(char * aName); // one of these name funcs might me unnecessary (see labs) 
        reward(name & aName);
        ~reward();
        void setPoints(int points); // assign pts to input value (+= used with call?)
        int getPoints(); // return protected points



    protected:
        // used in conjunction with char * name,
        // eg: Points! (or Stars), (int) = 100
        int points;
};
*/
#endif //_PLAYER_H_


