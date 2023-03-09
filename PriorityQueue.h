
#ifndef MY_PRIORITYQUEUE_H
#define MY_PRIORITYQUEUE_H

#include <vector>
#include "MaxHeap.h"

template <class Type>
class PriorityQueue{
    private:
        std::vector<Type> buffer;
        MaxHeap<Type> heap;
        Type max;
    public:
        PriorityQueue() = default;
        int size();
        void add(const Type &value);
        void removeTop();

        //Returns the top element
        Type& peek();

        //Removes and returns the top element
        Type poll();
};

template<class Type>
void PriorityQueue<Type>::add(const Type &value) {
    if ( size()==0 || value > max ) max = value;
    buffer.push_back(value);
}

template<class Type>
Type &PriorityQueue<Type>::peek() {
    return max;
}

template<class Type>
Type PriorityQueue<Type>::poll() {
    Type result = max;
    removeTop();
    return result;
}

template<class Type>
void PriorityQueue<Type>::removeTop() {
    if (buffer.size()) {
        for (auto x: buffer) {
            heap.add(x);
        }
        buffer.clear();
    }
    heap.removeTop();
    max = heap.peek();
}

template<class Type>
int PriorityQueue<Type>::size() {
    return buffer.size()+heap.size();
}


#endif //MY_PRIORITYQUEUE_H
