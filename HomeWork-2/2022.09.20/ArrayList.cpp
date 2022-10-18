#include <iostream>
#include "ArrayList.hpp"
template<typename T>
void ArrayList<T>::expand(int count)
{
    T* newdata = new T[count + this->capacity];
    for (int i = 0; i < this->capacity; ++i)
    {
        newdata[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newdata;
    this->capacity += count;
}
template<typename T>
int ArrayList<T>::ind(int index)
{
    if (index < 0)
    {
        pushbegin(0);
        return 0;
    }
    if (index >= this->count)
    {
        pushend(0);
        return this->count - 1;
    }
    return index;
}

template<typename T>
void ArrayList<T>::swap(int posi, int posj)
{
    int t = this->data[posi];
    this->data[posi] = this->data[posj];
    this->data[posj] = t;
}

template<typename T>
int ArrayList<T>::size()
{
    return this->count;
}

template<typename T>
ArrayList<T>::ArrayList(int capacity)
{
    this->capacity = capacity;
    this->count = 0;
    this->data = new T[capacity];
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList& list)
{
    this->capacity = list.count;
    this->count = list.count;
    this->data = new T[list.count];
    for (int i = 0; i < list.count; ++i)
    {
        this->data[i] = list.data[i];
    }
}

template<typename T>
ArrayList<T>::~ArrayList()
{
    this->count = 0;
    this->capacity = 0;
    delete[] this->data;
}

template<typename T>
void ArrayList<T>::pushend(T element)
{
    if (this->count == this->capacity)
    {
        expand(this->capacity);
    }
    this->data[this->count] = element;
    this->count++;
}

template<typename T>
void ArrayList<T>::pushbegin(T element)
{
    if (this->count == this->capacity)
    {
        expand(this->capacity);
    }
    this->count++;
    for (int i = this->count; i > 0; --i)
    {
        this->data[i] = this->data[i - 1];
    }
    this->data[0] = element;
}

template<typename T>
void ArrayList<T>::insert(T element, int position)
{
    if (this->count == this->capacity)
    {
        expand(this->capacity);
    }
    this->count++;
    
    for (int i = this->count; i > position; --i)
    {
        this->data[i] = this->data[i - 1];
    }
    this->data[position] = element;
}

template<typename T>
T ArrayList<T>::extract(int position)
{
    int elem = this->data[position];
    this->count--;
    for (int i = position; i < this->count; ++i)
    {
        this->data[i] = this->data[i + 1];
    }
    return elem;
}

template<typename T>
T ArrayList<T>::extractbegin()
{
    int elem = this->data[0];
    this->count--;
    for (int i = 0; i < this->count; ++i)
    {
        this->data[i] = this->data[i + 1];
    }
    return elem;
}
template<typename T>
T ArrayList<T>::extractend()
{
    this->count--;
    return this->data[this->count];
}

template<typename T>
T& ArrayList<T>::operator[](int pos)
{
    return data[ind(pos)];
}


template <typename T>
void ArrayList<T>::print()
{
    for (int i = 0; i < this->count; ++i)
    {
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}
