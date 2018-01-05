
/* Ryan Hoover
 * CS 202 - Fant - SPRING 2017
 * Program 1
 * 04/21/17 */

/***********************************************************/

#include "list.h"

node::node()
{   
    players = NULL;
    next = NULL;
}

node::~node()
{
    if (players)
    {
        delete [] players;
        players = NULL;
    }
    if (next)
    {
        delete next;
        next = NULL;
    }
}

node *& node::getNext()
{
    return next;
}

void node::setNext(node * setTo)
{
    next = setTo;
}

player *& node::getPlayer()
{
    return players;
}

void node::setPlayer(player * setTo)
{
    players = setTo;
}

player & node::getPlayerIndex(int i)
{
    return (*(players + i));
}

void node::copyPlayer(player & dest, player & source, int i)
{
    players[i].copyPlayer(dest, source);
}

/***********************************************************/

pList::pList()
{
    topIndex = 0;
    head = NULL;
}


pList::~pList()
{

}

node *& pList::getHead()
{
    return head;
}

void pList::setHead(node * setTo)
{
    head = setTo;
}

int pList::getIndex()
{
    return topIndex;
}

void pList::setIndex(int setTo)
{
    topIndex = setTo;
}

int pList::push(player & toAdd)
{
    int success = 0;
    if (!head)
    {
        head = new node;
        head->setNext(NULL);
        head->setPlayer(new player[INDEX]);
        topIndex = 0;
        //head->setPlayer(player[topIndex]);
        head->copyPlayer(head->getPlayerIndex(topIndex), toAdd, topIndex);
        ++topIndex; ++success;
    }
    else if (head && topIndex &&topIndex < INDEX)
    {
        head->copyPlayer(head->getPlayerIndex(topIndex), toAdd, topIndex);
        ++topIndex;
        ++success;
    }
    else if (head && topIndex && topIndex == INDEX)
    {
        node * temp = new node;
        temp->setPlayer(new player[INDEX]);
        topIndex = 0;
        temp->copyPlayer(temp->getPlayerIndex(topIndex), toAdd, topIndex);
        ++topIndex; ++success;
        temp->setNext(head);
        head = temp;
    }
    return success;
}

int pList::pop()
{
    int success = 0;
    if (!head)
        return success;
    if (topIndex > 1)
    {
        --topIndex;
        ++success;
    }
    else if (topIndex <= 1)
    {
        node * temp = head;
        delete head;
        head = temp;
        if (!head)
            topIndex = 0;
        else
            topIndex = INDEX;
        ++success;
    }
    return success;
}

int pList::peek(player & toPlay)
{
    int success = 0;
    if (!head)
        return success;
    head->copyPlayer(toPlay, head->getPlayerIndex(topIndex), topIndex);
    ++success;
    return success;
}

/***********************************************************/

