#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>

using namespace std;

struct Xcoordinate
{
    int x;
    int y;
    int label;
    string location;
    Xcoordinate():x(-1), y(0), label(0), location(""){}
};

struct Ycoordinate
{
    int y;
    int label;
    Ycoordinate():y(0), label(0){}
};

class priorityQueue
{
    public:
        priorityQueue(int size)
            : xList(1 + size*2), yList(1 + size), locations(1 + size){}
        ~priorityQueue(){}
        void getSorted();
        void x_insert(int x, int y, int label, string location);
        void printBuidings();
        
    private:
        void insert(int value, int label);
        void Remove(int label);
        int GetMax();
        bool IsEmpty();
        void newFunc(int &i);
        void sortSkyline(vector<Xcoordinate> &x);
        void percolateDown(vector<Xcoordinate>& x, int i, int n);

        vector<Xcoordinate>  xList;
        vector<Ycoordinate>  yList;
        vector<int> locations;
        int maxHeight = 0;
        int currSize = 0;
};

#endif //PRIORITYQUEUE_H

