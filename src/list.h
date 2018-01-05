
/* Ryan Hoover
 * CS 202 - Fant - SPRING 2017
 * Program 1
 * 04/21/17 */

/***********************************************************/

#ifndef _LIST_H_
#define _LIST_H_

#include "graph.h"
#include "player.h"

const int INDEX = 5;

class node
{
    public:
        node();
        ~node();
        node *& getNext();
        void setNext(node * setTo);
        player *& getPlayer();
        void setPlayer(player * setTo);
        player & getPlayerIndex(int i);
        void copyPlayer(player & dest, player & source, int i);
    protected:
        player * players;   // array of players in each node
        node * next;
};

/***********************************************************/

class pList
{
    public:
        pList();
        ~pList();
        node *& getHead();
        void setHead(node * setTo);
        int getIndex();
        void setIndex(int setTo);
        int push(player & toAdd);
        int pop();
        int peek(player & toPlay);

    protected:
        int topIndex;
        node * head;
};

#endif // _LIST_H_

/***********************************************************/

