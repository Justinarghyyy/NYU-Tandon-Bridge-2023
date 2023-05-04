#include <iostream>
#include <vector>

template <class T>
class Queue{
public:
    Queue() : start(0), end(0), size(0) {}
    void enqueue ( T newItem ) { 
        data.push_back( newItem ); 
        end ++ ;
        size ++ ; 
    }
    T dequeue() { 
        if ( size == 0 ) {
            cout << "Queue is empty" << endl ;
        }
        T value ;
        value = data[start] ; 
        start ++ ;
        size -- ;
        if ( size == 0 ){
            start = 0 ;
            end = 0 ;
            data.clear() ;
        }
        return value ;
    }
    T top() const { return *data(start); }
    bool isEmpty() const { return size == 0; }
    int size() const { return size ; }
    void clear() { data.clear(); }
} ;
