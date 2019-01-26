


#ifdef _ARRAYCLASS_H_
using namespace std;

// default constructor
// Creates an empty ArrayClass with DEFAULTCAPACITY

template<typename T>
ArrayClass<T>::ArrayClass() {
    arr = new T[DEFAULTCAPACITY];
    _size = 0;
    _capacity = DEFAULTCAPACITY;


}

// parameterized constructor
// Creates an empty ArrayClass with capacity of n
template<typename T>
ArrayClass<T>::ArrayClass(unsigned int n) {
    arr = new T[n];
    _size = 0;
    _capacity = n;
}

// copy constructor
// Creates an ArrayClass as a deep copy of the parameter
template<typename T>
ArrayClass<T>::ArrayClass(const ArrayClass &ac) {
    arr = new T[ac.capacity()];
    _capacity = ac.capacity();
    _size = ac.size();
    for (int i = 0; i < ac.size(); i++) {
        arr[i] = ac.arr[i];
    }
}

// destructor
template<typename T>
ArrayClass<T>::~ArrayClass() {
       delete[] arr;
    arr=NULL;
}

// overloaded assignment operator
template<typename T>
ArrayClass<T> &ArrayClass<T>::operator=(const ArrayClass &ac) {
    if (this == &ac) {
        return *this;
    } else {

        this->arr = new T[ac.capacity()];
        this->_capacity = ac.capacity();
        this->_size = ac.size();

        for (int i = 0; i < ac.size(); i++) {
            this->arr[i] = ac.arr[i];
        }

        return *this;
    }
}

////////////////////////
// capacity functions //
////////////////////////

// Returns the number of elements stored in the array
template<typename T>
unsigned int ArrayClass<T>::size() const {
    return _size;
}

// Returns the maximum capacity of the array
template<typename T>
unsigned int ArrayClass<T>::capacity() const {
    return _capacity;
}

// Resizes the array
// If n is smaller than the size, then only the
//   first n elements are copied to the new array
template<typename T>
void ArrayClass<T>::resize(unsigned int n) {
    if (n < _size && n != 0) {
        T *arrcopy = arr;
        arr = new T[n];
        _capacity = n;
        _size = n;
        for (int i = 0; i < n; i++) {
            arr[i] = arrcopy[i];
        }
        delete[] arrcopy;

    }
    if (n >= size() && n != 0) {
        T *arrcopy = arr;
        arr = new T[n];
        _capacity = n;
        _size = size();
        for (int i = 0; i < size(); i++) {
            arr[i] = arrcopy[i];
        }
        delete[] arrcopy;
    }


}

// Check if array is empty
// return true if array is empty
template<typename T>
bool ArrayClass<T>::empty() const {

    if (_size == 0) {
        return true;
    }
    return false;
}

// Resizes the array to fit exactly as many items
//   as are stored in the array
template<typename T>
void ArrayClass<T>::shrinkToFit() {

    if (_size < capacity() && (!empty())) {
        T *arrcopy = arr;
        arr = new T[size()];
        _size = size();
        _capacity = _size;
        for (int i = 0; i < size(); i++) {
            arr[i] = arrcopy[i];
        }
        delete[] arrcopy;
    }
    if (empty()) {
        _capacity = 1;
    }

}

//////////////////////////////
// element access functions //
//////////////////////////////

// Returns a reference to the element at position i
//   in the array.
// Throws an out_of_range exception if i is outside
//   the bounds of valid elements
template<typename T>
T &ArrayClass<T>::operator[](unsigned int i) {

    if (0 <= i && i < size()) {
        T *arrcopy = arr;
        if (i == 0) {
            return *arrcopy;
        }

        for (int a = 0; a < i; a++) {

            arrcopy = arrcopy + 1;
        }
        return *arrcopy;
    } else
        throw std::out_of_range("Out of range!");

}


// Returns a reference to the element at position i
//   in the array.
// Throws an out_of_range exception if i is outside
//   the bounds of valid elements
template<typename T>
T &ArrayClass<T>::at(unsigned int i) {
    if (0 <= i && i < size()) {
        if (i == 0) {
            return *arr;
        }
        T *arrcopy = arr;
        for (int a = 0; a < i; a++) {

            arrcopy = arrcopy + 1;
        }
        return *arrcopy;
    } else
        throw std::out_of_range("Out of range!");
}

// Returns a reference to the first element in the array
// Calling this on an empty array throws out_of_range exception
template<typename T>
T &ArrayClass<T>::front() {
    if (!empty()) {
        return *arr;
    } else
        throw std::out_of_range("Out of range!");

}

// Returns a reference to the last element in the array
// Calling this on an empty array throws out_of_range exception
template<typename T>
T &ArrayClass<T>::back() {
    if (!empty()) {
        return operator[](size() - 1);
    } else
        throw std::out_of_range("Out of range!");

}

//////////////////////
// modify functions //
//////////////////////

// Add an element at the end
// If array is at capacity before adding, then
//   expand the array to double its capacity and
//   then add.
template<typename T>
void ArrayClass<T>::pushBack(const T &item) {

    if (size() == capacity()) {
        T *arrcopy = arr;

        arr = new T[capacity() * EXPANSIONFACTOR];
        for (int i = 0; i < size(); i++) {
            arr[i] = arrcopy[i];
        }
        delete[] arrcopy;
        arr[size()] = item;
        _size = _size + 1;
        _capacity = EXPANSIONFACTOR * _capacity;
    } else {

        arr[size()] = item;
        _size = _size + 1;
    }
}

// Removes the last stored element in the array,
//   reducing container size by 1.
// No effect if called on an empty container
template<typename T>
void ArrayClass<T>::popBack() {
    if (!empty()) {
        T *arrcopy = arr;
        arr = new T[capacity() - 1];
        for (int i = 0; i < size() - 1; i++) {
            arr[i] = arrcopy[i];
        }
        delete[] arrcopy;
        _size--;
        _capacity--;
    }

}

// Inserts an element before the element at specified position
// Expands the array if necessary
// Elements to the right of position (inclusive) must be shifted
// Throws out_of_range if position is > _size
// POST: item is at position, all elements formerly at position and beyond are shifted
template<typename T>
void ArrayClass<T>::insert(unsigned int position, const T &item) {

    if (size() == capacity()) {
        T *arrcopy = arr;
        arr = new T[capacity() +1];
        for (int i = 0; i < size(); i++) {
            arr[i] = arrcopy[i];
        }
        delete[] arrcopy;
        arr[size()] = item;
        _capacity = 1+  _capacity;
    }

    if (0 < position && position < size()) {
        T *arrcopy = arr;
        arr = new T[capacity()];
        _size++;
        for (int i = 0; i < position ; i++) {
            arr[i] = arrcopy[i];
        }
        arr[position ] = item;

        for (int i = position+1; i < size(); i++) {
            arr[i] = arrcopy[i - 1];

        }
        delete[] arrcopy;
    }else if (position == 0) {
            T *arrcopy = arr;

            arr = new T[capacity()];

            arr[0] = item;
            _size++;
            for (int i = 1; i < size(); i++) {

                arr[i] = arrcopy[i-1];

            }
            delete[] arrcopy;

        }else if (position == size()) {
            T *arrcopy = arr;
            arr = new T[capacity()];

            arr[size()]=item;
            for (int i = 0; i < size(); i++) {

                arr[i] = arrcopy[i];

            }
            _size++;
            delete[] arrcopy;


        } else
        throw std::out_of_range("Out of range!");


}

// Removes an element from the array at specified position.
// Elements to the right of position will be shifted over to fill the gap
// Throws out_of_range if position is >= _size
template<typename T>
void ArrayClass<T>::erase(unsigned int position) {

    if (position < size()) {

        T *arrcopy = arr;

        arr= new T[capacity()];

        if(position!=0) {
            for (int i = 0; i < position ; i++) {
                arr[i] = arrcopy[i];
            }
        }
        _size--;
        for(int i =position; i<size();i++){
            arr[i]=arrcopy[i+1];
        }
        delete[] arrcopy;

    } else
        throw std::out_of_range("Out of range!");


}

// Reallocates stored items into a new array of the same size,
//   starting from specified position
// No effect if position is 0 or >= _size
// e.g. startFrom(3) on {1, 2, 3, 4, 5, 6, 7}
//   produces {4, 5, 6, 7, 1, 2, 3}
template<typename T>
void ArrayClass<T>::startFrom(unsigned int position) {

    if(position!=0 && position<size()) {
        T *arrcopy = arr;
        arr= new T[capacity()];

        for (int i = position; i < size(); i++) {

            arr[i-position] = arrcopy[i];

        }
        int y=0;
        for (int i = size()-position; i < size(); i++) {

            arr[i] = arrcopy[y];
            y++;
        }

        delete[] arrcopy;
    }
}

//////////////////////
// helper functions //
//////////////////////

// helper method for deep copy
template<typename T>
void ArrayClass<T>::copyArray(const ArrayClass &ac) {
    arr = new T[ac.capacity()];
    _capacity = ac.capacity();
    _size = ac.size();
    for (int i = 0; i < ac.size(); i++) {
        arr[i] = ac.arr[i];
    }
}

// helper method for expanding array
template<typename T>
void ArrayClass<T>::expandArray() {
    if (size() == capacity()) {
        T *arrcopy = arr;

        arr = new T[capacity() * EXPANSIONFACTOR];
        for (int i = 0; i < size(); i++) {
            arr[i] = arrcopy[i];
        }
        _capacity = EXPANSIONFACTOR * _capacity;
            delete[] arrcopy;
    }
}

#endif