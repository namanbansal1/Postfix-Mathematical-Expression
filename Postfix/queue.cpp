//
// Created by naman on 2017-10-22.


#ifdef _QUEUE_H_


template<typename T>
Queue<T>::Queue() {
    front = 0;
    _size = 0;
    ac = NULL;


}

template<typename T>
Queue<T>::Queue(const Queue<T> &qq) {
    ac =qq.ac;
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &qq) {
    if (this == &qq) {
        return *this;
    } else {
        this->ac=qq.ac;
        return *this;
    }


}

template<typename T>
bool Queue<T>::isEmpty() const {
    return ac.empty();
}

template<typename T>
unsigned int Queue<T>::size() const {
    return  ac.size();
}

template<typename T>
T &Queue<T>::peek() {
    return  ac.front();

}

template<typename T>
void Queue<T>::enqueue(const T item) {
    ac.insert(ac.size(),item);
}

template<typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Out of range!");
    } else {
        T a = ac.at(0);
        ac.erase(0);
        return a;
    }
}

#endif





