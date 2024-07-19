#include<iostream>
#include<stdlib.h>

using namespace std;

template<typename T> class Vector
{
private:
    int capacity;
    int size;
    T *element;
public:
    // Function that add element at the end
    T push_back(T);
    // Function that remove the last element
    T pop_back();
    // Funtion that returns size of the sequence
    int size();
    // Funtion that check the sequence is empty or not
    bool emty();
    // Class point each element
    class iterator
    {
    private:
        T *ptr;
    public:
        explicit iterator()
        : ptr(nullptr)
        {
        }
        explicit iterator(T *p)
        {
            : ptr(p)
        }
        ~iterator(){ delete[] ptr;}
        iterator(T *p)
        : ptr(p){
            bool operator==(const iterator &rhs) const
            {
                return !(this == rhs);
            }
            T operator*() const { return *ptr;}
            iterator &operator++(){
                ++ptr;
                return *this;
            }
            iterator operator++(int){
                iterator temp(*this);
                ++*this;
                return temp;
            }
        }
        //Begin iterator
        iterator begin() const;
        iterator end() const;
    };
    // Funtion that add to the specified index 
    T insert(int, T);
};


