
#ifndef Queue_hpp
#define Queue_hpp

#include "LinkedList.hpp"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Queue {
public:
    //constructor
    Queue() {
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
    }
    
    //copy constructor
    
    Queue(const Queue& other) {
        this->front = copy_list(other.front);
        this->rear = LastNode(this->front);
        this->size = other.size;
    }
    
    //destructor
    
    ~Queue() {
        // Delete the list, set front and rear to null
        clear_list(front);
        front = nullptr;
        rear = nullptr;
    }
    
    //assignment operator
    
    Queue<T>& operator=(const Queue<T>& rhs) {
        //self-check
        //Commented out for the calculator
//        if (*this == rhs) {
//            return *this;
//        }
        //clean up
        clear_list(front);
        rear = front;
        
        //re-instantiate lhs attributes
        this->front = copy_list(rhs.front);
        this->rear = LastNode(this->front);
        //Commented out for the calculator
//        this.size = rhs.size;
        
        //copy junk over
        
        
        return *this;
    }
    
    // pushes item to the rear
    
    void push(const T& item) {
        
        // declare a walker to traverse down the queue
        node<T>* walker = front;
        
        // if the queue is empty, create a new node of capacity 1
        if (walker == rear) {
            insert_head(front, item);
            rear = LastNode(front);
            //qqq LastNode takes way too long to run
            //            walker->_next = rear;
        }// Does this work?
        else {
            // a more efficient algorith is rear = insert_after
            // and get rid of the walker and wile loop and LastNode
            while (walker->_next != rear) {
                walker = walker->_next;
            }
            insert_after(front, walker, item);
            //resetting rear
            rear = LastNode(front);
        }
        
        //queue size enlarges by 1
        this->size++;
    }
    
    //pop items from the front
    
    T pop() {
        
        if (top() == nullptr) {
            throw top();
            exit(-1);
        }
        
        // cannot pop an empty queue
        assert(!empty());
        //decrement the queue size
        size--;
        // hold the item front of the queue and delete front
        T hold;
        try {
            hold = delete_head(front);
        } catch (node<T>*) {
            cerr << "Error: popping an empty queue";
            exit(-1);
        }
                // reset rear to the last element
        rear = LastNode(front);
        
        if (empty()) {
            rear = front;
        }
        return hold;
    }
    
    T top() {
        // cannot check top of an empty queue
        assert(!empty());
        
        return front->_item;
    }
    
    bool empty() {
        return this->size == 0;
    }
    
    template <class U>
    friend ostream& operator<<(ostream& outs, const Queue<U>& q) {
        node<U>* walker = q.front;
        while (walker != q.rear) {
            //if (walker->_next != q.rear) {
            outs << " [" << walker->_item << "]";
            //}
            walker = walker->_next;
        }
        return outs;
    }
    
private:
    node<T>* front;
    node<T>* rear;
    int size;
};

#endif /* Queue_hpp */

