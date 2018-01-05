
/* Ryan Hoover
 * CS 202 - Fant - SPRING 2017
 * Program 1
 * 04/21/17 */

#include "graph.h"

/***********************************************************/

checkpoint::checkpoint():
    head(0), checkpointNumber(0), isEnd(false), reward(0)
{
    //head = NULL;
    //checkpointNumber = 0;

}
checkpoint::~checkpoint()
{    
    delAll();
}

void checkpoint::delAll()
{
    while (delHead());
}

bool checkpoint::delHead()
{
    if (!head)
        return false;
    trail * temp = head->goNext();
    delete head;
    head = NULL;
    head = temp;
    return true;
} 

int checkpoint::displayTrails()
{
    cout << "To Checkpoint #" << checkpointNumber << endl;
    return checkpointNumber;
}

int checkpoint::display()
{
    // basically the map of the maze
    // displays checkpoints and paths from each one
    cout << "\nCheckpoint #: " << checkpointNumber;
    cout << "\nStars: " << reward << endl << endl;
    if (isEnd)
        cout << "Checkpoint " << checkpointNumber << " is the end point." << endl;
    if (head)
    {
        trail * temp = head;
        while (temp)
        {
            temp->display();
            temp = temp->goNext();
        }
    }
    else
        cout << "\nNo paths from here.\n";
    cout << endl;
    return checkpointNumber;
}

void checkpoint::setNum(int setTo)
{
    checkpointNumber = setTo;
}

int checkpoint::getNum()
{
    return checkpointNumber;
}

void checkpoint::setHead(trail * setTo)
{
    head = setTo;
}

trail *& checkpoint::goHead()
{
    return head;
}

void checkpoint::setEnd(bool setTo)
{
    isEnd = setTo;
}

bool checkpoint::endCheck()
{
    return isEnd;
}

void checkpoint::setReward(int setTo)
{
    reward = setTo;
}

int checkpoint::getReward()
{
    return reward;
}

/***********************************************************/

trail::trail():
    adjacent(0), next(0), prev(0) {}

trail::~trail()
{
    if (adjacent)
    {
        delete adjacent;
        adjacent = NULL;
    }
    if (next)
    {
        delete next;
        next = NULL;
    }
    if (prev)
    {
        delete prev;
        prev = NULL;
    }
}

void trail::display()
{
    int currentCheckpt = adjacent->getNum();
    cout << "Path to " << currentCheckpt << ", ";
}

checkpoint *& trail::goAdjacent()
{
    return adjacent;
}

void trail::setAdjacent(checkpoint * toSet)
{
    adjacent = toSet;
}

trail *& trail::goNext()
{
    return next;
}

trail *& trail::goPrev()
{
    return prev;
}

void trail::setNext(trail * setTo)
{
    next = setTo;
}

void trail::setPrev(trail * setTo)
{
    prev = setTo;
}

/***********************************************************/

maze::maze(){
    int num = 0;
    // create adjacency list for graph
    mazeList = new checkpoint[SIZE];
    // set all values
    for (int i = 0; i < SIZE; ++i){
        mazeList[i].setNum(num++);  // assign numbers to checkpoints
        mazeList[i].setReward(rand()%100);  // give checkpoints a random star amount
    }
    mazeList[SIZE-1].setEnd(true);  //final checkpoint is the end
}

int maze::displayCheckpoints(){
    if (!mazeList){
        return 0;
    }
    int success = 0;
    // display all verticies
    for (int i = 0; i < SIZE; ++i){
        if (mazeList[i].display()){
            ++success;
        }
    }
    return success;
}

int maze::displayAdjacent(int toDisplay)
{
    int success = 0;
    if (!mazeList)
        return success;
    // Take int argument and loop thru list
    trail * temp = mazeList[toDisplay].goHead();
    cout << "\nGo down which path?";
    cout << "\nPress the corresponding checkpoint # to move there.\n";
    while (temp)
    {
        if (temp->goAdjacent())
        {
            success = temp->goAdjacent()->displayTrails();
        }
        temp = temp->goNext();
    }
    return success;
}

int maze::insertTrail(int currentCP, int toAttach)
{
    int success = 0;
    if (!mazeList)
        return success;
    if (currentCP != -1 && toAttach != -1)
    {
        // make a new trail object
        trail * temp = new trail;
        // set location ptr to passed-in int (random)
        temp->setAdjacent(&mazeList[toAttach]);
        // first added node's next will be NULL
        temp->setNext(mazeList[currentCP].goHead());
        // the next newest node is always first in the list
        mazeList[currentCP].setHead(temp);
        ++success;
    }
    return success;
}

bool maze::isEnd(int i)
{
    return mazeList[i].endCheck();
}

int maze::awardStars(int i)
{
    return mazeList[i].getReward();
}

int maze::getMazeLoc(int i)
{
    return mazeList[i].getNum();
}

int maze::generate()
{
    if (!mazeList)
        return 0;
    // initialize loop control variables
    int listMax, listSize, randIndex;
    // loop for the adjacency list
    for (int i = 0; i < (SIZE - 1); ++i)
    {
        //determine how many trails from current vertex, 1-3
        do
        {
            listMax = rand() % 3;
        }
        while(listMax == 0);
        // initialize size of current vertex's edge list, currently none
        listSize = 0;
        // will be used as 'switchboard' to prevent duplicate paths being established
        bool selected[SIZE];
        // set all to false to begin
        for (int j = 0; j < SIZE; ++j)
            selected[j] = false;
        // inner loop for building edge list within current vertex
        while (listSize < listMax)
        {
            // come up with a random number that hasn't been picked yet, and is not current vertex
            do
            {
                randIndex = rand() % SIZE;
            }
            while (randIndex == i || selected[randIndex]);
            // make sure to set corresponding bool array index to true, wont be called twice
            insertTrail(i, randIndex);
            insertTrail(randIndex, i);
            // increment listSize to ensure not too many nodes are made
            selected[randIndex] = true;
            selected[i] = true;
            ++listSize;
        }
    }
    return 1;
}

/***********************************************************/

