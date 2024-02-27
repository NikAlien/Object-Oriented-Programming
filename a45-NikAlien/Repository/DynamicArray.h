#pragma once

template <typename T>
class DynamicArray{
private:
    T* elems;
    int length;
    int capacity;

    void resize();
public:
    // default constructor
    DynamicArray(int capacity);

    // copy constructor or a dynamic array
    DynamicArray(const DynamicArray& v);

    // destructor
    ~DynamicArray();

    /* gets the element from position pos from the array and returns it
     * Input: pos - position of the element
     * Output: the TElem element from that position
     * */
    T& operator[](int pos);

    /* adds an element to the array
     * Input: element of type TElem
     * */
    void add(T e);

    /* removes an element from the array
     * Input: index - integer that signifies the position of the element that's to be deleted
     * */
    void remove(int index);

    /* updates an element with new information
     * Input: e - TElem element with the new information
     *        index - position of element to be updated
     * */
    void update(const T& e, int index);

    // gets the array's length
    int getLength() const;
};


template <typename T>
DynamicArray<T>::DynamicArray(int capacity) {
    this->length = 0;
    this->capacity = capacity;
    this->elems = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& v) {
    this->length = v.length;
    this->capacity = v.capacity;
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->length; i++)
        this->elems[i] = v.elems[i];
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] this->elems;
}

template <typename T>
void DynamicArray<T>::add(T e)
{
    if(this->length == this->capacity)
        this->resize();
    this->elems[this->length] = e;
    this->length++;
}

template <typename T>
int DynamicArray<T>::getLength() const {
    return this->length;
}

template <typename T>
void DynamicArray<T>::resize() {
    T* e = new T [this->capacity * 2];

    for(int i = 0; i < this->length; i++)
        e[i] = this->elems[i];

    delete[] this->elems;
    this->elems = e;
    this->capacity *= 2;
}

template <typename T>
T& DynamicArray<T>::operator[](int pos) {
    return this->elems[pos];
}

template <typename T>
void DynamicArray<T>::remove(int index) {
    this->length--;
    for(int j = index; j < this->length; j++)
        this->elems[j] = this->elems[j + 1];
}

template <typename T>
void DynamicArray<T>::update(const T &e, int index) {
    this->elems[index] = e;
}