//
// Created by twome on 06/05/2020.
//

#ifndef GAMEOFLIFE_3D_DOUBLEBUFFER_H
#define GAMEOFLIFE_3D_DOUBLEBUFFER_H


#include <cstring>

template <typename T>
class DoubleBuffer {
private:
    T* front;
    T* back;

public:
    explicit DoubleBuffer(int size);
    ~DoubleBuffer();

    void swap();

    T* get_front();

    T* get_back();

};

template<typename T>
DoubleBuffer<T>::DoubleBuffer(int size) {
    front = new T[size];
    back = new T[size];

    // Zero arrays
    memset(front, 0, sizeof(T) * size);
    memset(back, 0, sizeof(T) * size);
}

template<typename T>
DoubleBuffer<T>::~DoubleBuffer() {
    delete[] front;
    delete[] back;
}

template<typename T>
void DoubleBuffer<T>::swap() {
    T* tmp = front;
    front = back;
    back = tmp;
}

template<typename T>
T *DoubleBuffer<T>::get_front() {
    return front;
}

template<typename T>
T *DoubleBuffer<T>::get_back() {
    return back;
}

#endif //GAMEOFLIFE_3D_DOUBLEBUFFER_H
