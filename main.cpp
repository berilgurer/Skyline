#include <iostream>
#include <sstream>
#include <fstream>
#include "priorityQueue.h"

using namespace std;

int main()
{
    int size,buildingH, startX, endX;
    int count = 0;

    ifstream input;
    string s;
    input.open("input.txt");

    if (input.is_open())
    {
        getline(input, s);
        istringstream ss1(s);
        ss1 >> size;
        priorityQueue myHeap(size);
        
        while(getline(input, s))
        {
            istringstream ss2(s);
            ss2 >> endX >> buildingH >> startX;
            myHeap.x_insert(endX, buildingH, count*2 + 1, "start");
            myHeap.x_insert(startX, buildingH, count*2 + 2, "end");
            count++;
        }
        myHeap.printBuidings();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    
    
    return 0;
}
