//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_OPENGL_DOUBLEBUFFER_H
#define GAMEOFLIFE_OPENGL_DOUBLEBUFFER_H


#include <cstring>

template<typename T>
class DoubleBuffer {
private:
    T *front;
    T *back;
    int size;

public:
    explicit DoubleBuffer(int size);

    ~DoubleBuffer();

    void swap();

    void clear();

    T *get_front() const;

    T *get_back() const;

};

template<typename T>
DoubleBuffer<T>::DoubleBuffer(int size) {
    this->size = size;
    front = new T[size];
    back = new T[size];
    clear();
}

template<typename T>
DoubleBuffer<T>::~DoubleBuffer() {
    delete[] front;
    delete[] back;
}

template<typename T>
void DoubleBuffer<T>::swap() {
    T *tmp = front;
    front = back;
    back = tmp;
}

template<typename T>
T *DoubleBuffer<T>::get_front() const {
    return front;
}

template<typename T>
T *DoubleBuffer<T>::get_back() const {
    return back;
}

template<typename T>
void DoubleBuffer<T>::clear() {
    // Zero arrays
    memset(front, 0, sizeof(T) * size);
    memset(back, 0, sizeof(T) * size);
}

#endif //GAMEOFLIFE_OPENGL_DOUBLEBUFFER_H
