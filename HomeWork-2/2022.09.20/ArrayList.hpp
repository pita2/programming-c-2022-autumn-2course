#pragma once
#include<ostream>
template <typename T>
class ArrayList
{
private:
    T* data;
    int capacity;
    int count;
    void expand(int count = 1);
    void swap(int posi, int posj);
    int ind(int index);

public:
    ArrayList(int capacity = 10);
    ArrayList(const ArrayList<T>& list);
    ~ArrayList();
    /// <summary>
    /// длина
    /// </summary>
    int size();
    /// <summary>
    /// вставкв элемента element в конец
    /// </summary>
    void pushend(T element);
    /// <summary>
    /// вставкв элемента element в начало
    /// </summary>

    void pushbegin(T element);
    /// <summary>
    /// вставкв элемента element на position
    /// </summary>
    ///
    void insert(T element, int position);
    /// <summary>
    /// удвление первого элемента
    /// </summary>
    ///
    T extractbegin();
    /// <summary>
    /// удвление последнего элемента
    /// </summary>
    ///
    T extractend();
    
    /// <summary>
    /// удаление элемента на position
    /// </summary>
    T extract(int position);
    
    void print();
    
    /// <summary>
    /// QuickSort
    /// </summary>
    
    T& operator[](int pos);
    
    
};
