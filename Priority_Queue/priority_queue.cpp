#include "priority_queue.h"
#include <utility>

using namespace std;

PriorityQueue::PriorityQueue() : size(0) {}

void PriorityQueue::max_heapify(int i)
{
    int l, r, largest;
    l = i * 2 + 1;
    r = i * 2 + 2;

    if (l < size && queue[l] > queue[i])
        largest = l;
    else
        largest = i;
    if (r < size && queue[r] > queue[largest])
        largest = r;

    if (largest != i)
    {
        swap(queue[i], queue[largest]);
        max_heapify(largest);
    }
}

void PriorityQueue::push(int key)
{
    int parent, pos;
    pos = size;
    size++;
    queue[pos] = key;
    parent = (pos - 1) / 2;
    while (pos >= 0 && queue[pos] > queue[parent])
    {
        swap(queue[pos], queue[parent]);
        pos = parent;
        parent = (pos - 1) / 2;
    }
}

int PriorityQueue::pop()
{
    if (size < 1)
        return -1;
    int max_value = queue[0];

    queue[0] = queue[size - 1];
    size--;
    max_heapify(0);

    return max_value;
}