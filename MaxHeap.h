
#ifndef MY_MAXHEAP_H
#define MY_MAXHEAP_H


#include <vector>
template <class Type>
class MaxHeap {
    private:
        std::vector<Type> list;
        void heapify_down(int index);//bubble down
    public:
        MaxHeap() = default;
        int size();
        void add(const Type &value);
        void removeTop();

        //Returns the top element
        Type& peek();

        //Removes and returns the top element
        Type poll();
};

template<class Type>
void MaxHeap<Type>::add(const Type &value) {
    int index = list.size();
    list.push_back(value);

    int parentIndex = (index - 1)/2;
    while (index > 0 && list[parentIndex] < list[index] ){
        int temp = list[index];
        list[index] = list[parentIndex];
        list[parentIndex] = temp;

        index = parentIndex;
        parentIndex = (index - 1)/2;
    }
}

template<class Type>
Type &MaxHeap<Type>::peek() {
    return list[0];
}

template<class Type>
Type MaxHeap<Type>::poll() {
    Type result = list[0];
    removeTop();
    return result;
}

template<class Type>
void MaxHeap<Type>::removeTop() {
    int last_index = list.size() - 1;
    list[0] = list[last_index];
    list.pop_back();
    heapify_down(0);
}

template<class Type>
void MaxHeap<Type>::heapify_down(int index) {
    int leftChild;
    int rightChild;
    int largestChild;

    while(true){
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largestChild = index;

        if (leftChild < list.size() && list[leftChild] > list[largestChild])
            largestChild = leftChild;

        if (rightChild < list.size() && list[rightChild] > list[largestChild])
            largestChild = rightChild;

        if (largestChild == index)
            break;

        int temp = list[index];
        list[index] = list[largestChild];
        list[largestChild] = temp;
        index = largestChild;
    }
}

template<class Type>
int MaxHeap<Type>::size() {
    return list.size();
}
#endif //MY_MAXHEAP_H
