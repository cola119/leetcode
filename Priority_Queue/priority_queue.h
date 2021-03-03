#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_

class PriorityQueue
{
private:
    int size;
    int queue[2000];
    void max_heapify(int i);

public:
    PriorityQueue();
    void push(int key);
    int pop();
};

#endif