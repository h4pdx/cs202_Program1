
/* Ryan Hoover
 * CS 202 - Fant - SPRING 2017
 * Program 1
 * 04/21/17 */

/* This file contains the objects needed to build the maze
 * checkpoint, trail, and maze are the components.
 * maze creates an adjacecnyList of checkpoints,
 * which create lists of trails to other checkpoints
 * maze::generate() is responsible for randomly crating a new maze each new game. */

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

const int SIZE = 20;
/***********************************************************/
// manages edge list
class checkpoint //vertex
{
    public:
        checkpoint();
        checkpoint(const checkpoint & copyFrom);
        ~checkpoint();
        void delAll();
        bool delHead();
        int display();
        int getNum();
        void setNum(int setTo);
        void setHead(class trail * setTo);
        class trail *& goHead();
        void setEnd(bool setTo);
        bool endCheck();
        int generateTrails();
        int displayTrails();
        void setReward(int setTo);
        int getReward();
    protected:
        class trail * head; // head of adjacency list
        int checkpointNumber; // data the checkpoint contains, 1-20, player has a (checkpoint *)
        bool isEnd; // only ONE checkpoint will be true
        int reward;
};

/***********************************************************/

class trail // DLL node for edge list
{
    public:
        trail();
        //trail(const trail & copyFrom);
        ~trail();
        checkpoint *& goAdjacent();
        void setAdjacent(checkpoint * toSet);
        trail *& goNext();
        trail *& goPrev();
        void setNext(trail * setTo);
        void setPrev(trail * setTo);
        void display();
    protected:
        checkpoint * adjacent;
        trail * next; // doubly linked list
        trail * prev;
};

/***********************************************************/
// manages the verticies(checkpoints), which manage the edge list
class maze // graph
{
    public:
        maze();
        int findLocation();
        int displayCheckpoints();
        int insertTrail(int currentCP, int toAttach);
        int generate();
        int displayAdjacent(int toDisplay);
        int deleteDuplicates(trail *& head);
        int getMazeLoc(int i);
        bool isEnd(int i);
        int awardStars(int i);
    protected:
        checkpoint * mazeList; // adjacency list
        int maze_size;
};

/***********************************************************/
int mainMenu(void);
bool again(void);
bool backToMenu(void);
bool confirm(void);
int formatTitle(char * aTitle);
int formatDef(char * aDef);
#endif //_GRAPH_H_
