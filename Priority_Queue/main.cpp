#include <iostream>
#include "priority_queue.h"
using namespace std;

int main()
{
    PriorityQueue q;

    q.push(3);
    q.push(11);
    q.push(5);

    cout << q.pop() << endl; // 11

    q.push(6);

    cout << q.pop() << endl; // 6
    cout << q.pop() << endl; // 5
    cout << q.pop() << endl; // 3

    return 0;
}