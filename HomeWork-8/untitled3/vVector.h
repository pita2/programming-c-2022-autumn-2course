#include <iostream>

template <typename T>
class vVector
{
private:
    int capacity;
    int count;
    T *data;
public:
    vVector()
    {
        this->capacity = 0;
        this->count = 0;
        this->data = nullptr;
    }
    vVector(int n)
    {
        this->capacity = 2 * n;
        this->count = n;
        this->data = new T[n];
    }
    int size()
    {
        return this->count;
    }

    vVector(const vVector& v)
    {
        capacity = v.count * 2;
        this->data = new T[v.count * 2];
        for (int i = 0; i < v.count; ++i)
        {
            data[i] = v[i];
        }
    }

    ~vVector()
    {
        this->count = 0;
        this->capacity = 0;
        delete[] this->data;
    }

    void expand(int n)
    {
        T* newdata = new T[2 * n];
        for (int i = 0; i < this->count; ++i)
        {
            newdata[i] = this->data[i];
        }
        delete[] this->data;
        this->data = newdata;
        this->capacity = 2 * n;
    }

    bool empty()
    {
        return count;
    }

    int MaxSize()
    {
        return this->capacity;
    }

    void clear()
    {
        this->count = 0;
        this->data = nullptr;
    }

    void resize(int sz)
    {
        expand(sz);
    }

    void PushBack(T elem)
    {
        if (this->count == this->capacity)
        {
            expand(this->capacity);
        }
        this->data[this->count] = elem;
        this->count++;
    }

    void PushFront(T elem)
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
        this->data[0] = elem;
    }

    void insert(T elem, int position)
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
        this->data[position] = elem;
    }

    T erase(int position)
    {
        int elem = this->data[position];
        this->count--;
        for (int i = position; i < this->count; ++i)
        {
            this->data[i] = this->data[i + 1];
        }
        return elem;
    }

    T& operator[](int pos)
    {
        return data[pos];
    }

};
