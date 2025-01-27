#include <iostream>
#include <cassert>
#include <stdexcept> 
using namespace std;

template<typename T>
class Array
{
private:
    T* arr;
    int capacity;
    int size;

    void Resize(size_t new_capacity)
    {
        T* ptr = new T[new_capacity];
        for(size_t i = 0; i < size; i++)
        {
            ptr[i] = arr[i];
        }
        delete[] arr;
        arr = ptr;
        capacity = new_capacity;
    }

public:
    Array()
    {
        capacity = 2;
        size = 0;
        arr = new T[capacity];
    }

    Array(const Array& other)
    {
        capacity = other.capacity;
        size = other.size;
        arr = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    Array& operator=(const Array& other)
    {
        if (this == &other)  
            return *this;

        delete[] arr;  

        capacity = other.capacity;
        size = other.size;
        arr = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }

        return *this;
    }

    void append(const T& value)
    {
        if(size >= capacity)
        {
            Resize(capacity * 2);
        }
        arr[size++] = value;
    }

    void Insert(const T& element, size_t index)
    {
        if(index > size) 
            throw out_of_range("Index out of range");
            
        if(size >= capacity)
        {
            Resize(capacity * 2);
        }
        for(size_t i = size; i > index; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[index] = element;
        size++;
    }

    T& operator[] (int index)
    {
        if (index >= size)
            throw out_of_range("Index out of range");
        return arr[index];
    }

    T get(size_t index) const
    {
        if (index >= size)
            throw out_of_range("Index out of range");
        return arr[index];
    }

    size_t getSize() const
    {
        return size;
    }

    void Clear()
    {
        size = 0;
        Resize(2);
    }

    bool is_sorted() const
    {
        for(size_t i = 1; i < size; i++)
        {
            if(arr[i] < arr[i-1]) return false;
        }
        return true;
    }

    size_t LinearSearch(const T& element) const
    {
        for(size_t i = 0; i < size; i++)
        {
            if(arr[i] == element) return i;
        }
        return -1;
    }

    size_t BinarySearch(const T& element) const
    {
        if(!is_sorted())
        {
            cout << "The array is not sorted, so binary search will not work." << endl;
            return -1;
        }
        size_t low = 0, high = size - 1;
        while(low <= high)
        {
            size_t mid = low + (high - low) / 2;
            if(arr[mid] == element) return mid;
            else if(arr[mid] < element)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }

    T Remove()
    {
        if (size == 0)
            throw underflow_error("Array is empty");
        return arr[--size];
    }

    T Delete(const size_t index)
    {
        if (size == 0)
            throw underflow_error("Array is empty");
        if (index >= size)
            throw out_of_range("Index out of range");
        
        T deletedElement = arr[index];
        for(size_t i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return deletedElement;
    }

    void Reverse()
    {
        size_t start = 0, end = size - 1;
        while(start < end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    ~Array() 
    {
        delete[] arr;
    }
};