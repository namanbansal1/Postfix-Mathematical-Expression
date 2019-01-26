//
// Created by naman on 2017-10-22.
//


#ifdef _STACK_H_
template<typename T>
Stack<T>::Stack() {
    ac=NULL;
}

template<typename T>
Stack<T>::Stack(const Stack &st) {
    ac= st.ac;
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &st) {
    if (this == &st) {
        return *this;
    } else {
        this->ac=st.ac;
        return *this;
    }
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return ac.empty();
}

template<typename T>
unsigned int Stack<T>::size() const {
    return ac.size();
}

template<typename T>
T &Stack<T>::peek() {
    return ac.front();
}

template<typename T>
void Stack<T>::push(const T item) {

    ac.insert(0, item);
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Out of range!");
    } else {
        T a = ac.at(0);
        ac.erase(0);
        return a;
    }
}
#endif
