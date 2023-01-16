#include <string>
#include "priorityQueue.h"

using namespace std;

int leftChild(int i){
    return ((2*i)+1);
}

void priorityQueue::getSorted()
{
    sortSkyline(xList);
}

void priorityQueue::x_insert(int x, int y, int label, string location)
{
    xList[label].x = x;
    xList[label].y = y;
    if (location == "start"){xList[label].label = (label + 1) / 2;}
    else if (location == "end"){xList[label].label = label / 2;}
    xList[label].location = location;

}
void priorityQueue::insert(int value, int label)
{
    int hole = ++currSize;
    for (; hole>1 && value > yList[hole/2].y; hole/=2)
    {
        yList[hole] = yList[hole/2];
        locations[yList[hole].label] = hole;
    }
    yList[hole].y = value;
    yList[hole].label = label;
}

int priorityQueue::GetMax()
{
    return yList[1].y;
}

void priorityQueue::percolateDown(vector<Xcoordinate> &a, int i, int n)
{
    Xcoordinate tmp = a[i];
    int child;
    while (leftChild(i) < n)
    {
        child = leftChild(i);
        if (child != n - 1 && a[child].x < a[child + 1].x)
            child++;
        if (a[child].x > tmp.x)
            a[i] = a[child];
        else
            break;
        i = child;
    }
    a[i] = tmp;
}

void priorityQueue::newFunc(int &i){
    while (i < xList.size() - 1 && xList[i].x == xList[i + 1].x)
    {
        if (xList[i + 1].location == "end")
        {
            Remove(xList[i + 1].label);
        }
        else if (xList[i + 1].location == "start")
        {
            insert(xList[i + 1].y, xList[i + 1].label);
        }
        i++;
    }
    if(maxHeight != GetMax()){
        maxHeight = GetMax();
        cout << xList[i].x << " " << maxHeight << endl;
    }
}

void priorityQueue::printBuidings()
{
    getSorted();
    
    if (xList[1].x != 0)
    {
        cout << "0" << " " << maxHeight;
        cout << endl;
    }

    for (int i = 1; i < xList.size(); i++)
    {
        if (xList[i].location == "start")
        {
            insert(xList[i].y, xList[i].label);
            newFunc(i);
        }
        else if (xList[i].location == "end")
        {
            Remove(xList[i].label);
            newFunc(i);
        }
    }
}

void priorityQueue::sortSkyline(vector<Xcoordinate> &a)
{
    for (int i = a.size()/2; i >= 0; i--)
        percolateDown(a, i, a.size());
    
    for (int i = a.size()-1; i > 0; i--)
    {
        swap(a[0], a[i]);
        percolateDown(a, 0, i);
    }
}

bool priorityQueue::IsEmpty()
{
    if (yList[1].label == 0){
        return true;
    }else{
        return false;
    }; 
}

void priorityQueue::Remove(int buildingL)
{
    if (IsEmpty() == false)
    {
        int c;
        int index = locations[buildingL];
        yList[index] = yList[currSize];
        
        yList[currSize].y = 0;
        yList[currSize].label = 0;
    
        currSize = currSize - 1;
        
        Ycoordinate tmp = yList[index];
        while (leftChild(index)-1 <= currSize)
        {
            c = leftChild(index)-1;
            if (c != currSize && yList[c].y < yList[c + 1].y)
                c++;
            if (tmp.y < yList[c].y)
                yList[index] = yList[c];
            else
                break;
            index = c;
        }
        yList[index] = tmp;
    }
}



