#include <iostream>
#include "MaxHeap.h"
#include "PriorityQueue.h"


using namespace std;

int main(int argc, char* argv[]){

    PriorityQueue<int> pqueue;
    pqueue.add(5);
    pqueue.add(3);
    pqueue.add(2);
    pqueue.add(8);
    pqueue.add(1);
    pqueue.add(2);
    pqueue.add(7);
    pqueue.add(11);
    cout << pqueue.peek() << "\n";
    while (pqueue.size()){
        cout << pqueue.poll() << "\n";
    }

    return 0;
}

