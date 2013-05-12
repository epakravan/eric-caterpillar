#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>
#include <QGraphicsScene>

const int DEFAULT_LIST_SIZE = 100;

template <typename T>
class Data {
private:
    int size_;
    int capacity_;
    T* data_;
public:
    Data();
    Data(int capacity);
    ~Data();
    void push_back(T val);
    T at(int loc) const;
    int size() const;
    T* data();
    bool remove(T val);
    T pop(int loc);
    T& operator[](int loc);
    void clear();
    void clear(QGraphicsScene* scene);
};

template <typename T>
T& Data<T>::operator[](int loc) {
if (loc>=size_)
	throw std::invalid_argument("location not within range");
return data_[loc];
}

template <typename T>
Data<T>::Data() {
    capacity_=DEFAULT_LIST_SIZE;
    size_=0;
    data_ = new T[capacity_];
}

template <typename T>
Data<T>::Data(int capacity) {
    capacity_=capacity;
    size_=0;
    data_ = new T[capacity_];
}

template <typename T>
Data<T>::~Data() {
    clear();
    delete[] data_;
}

template <typename T>
int Data<T>::size() const{
    return size_;
}

template <typename T>
T* Data<T>::data() {
    return data_;
}

template <typename T>
void Data<T>::push_back(T val)
{
    if (size_>=capacity_){
        capacity_*=2;
        T* tempList=new T[capacity_];
        for (int i=0;i<size_;i++){
            tempList[i]=data_[i];
        }
        delete[] data_;
        data_=tempList;
    }
    T newval = val;
    data_[size_++] = newval;
}

template <typename T>
T Data<T>::at(int loc) const{
    if (loc>=size_) {
        throw std::invalid_argument("location not within range");
    }
    return data_[loc];
}

template <typename T>
T Data<T>::pop(int loc) {
    if (loc>=size_)
        throw std::invalid_argument("location not within range");
    else {
        T temp=data_[loc];
        for (int i=loc; i<size_; i++){
            data_[i]=data_[i+1];
        }
        size_--;
        return temp;
    }
}

template <typename T>
void Data<T>::clear(QGraphicsScene* scene) {
    for (int i=size_-1;i>=0;i--){
    	scene->removeItem(data_[i]);
        delete data_[i];
        size_--;
    }
}

template <typename T>
void Data<T>::clear() {
    for (int i=size_-1;i>=0;i--){
        delete data_[i];
        size_--;
    }
}

#endif // DATA_H
