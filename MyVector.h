#pragma once

template<class T>
class My_vector {
    T* vec{};
    int _size{};
    int _capacity{2};
public:
    My_vector() {
        vec = new T[_capacity] {0};
    }

    ~My_vector() {
        delete[] vec;
    }

    int size() {
       return _size;
    }

    int capacity() {
      return _capacity;
    }
    
     void push_back(T value) {
        if (_size == _capacity) {
            _capacity = static_cast<int>(_capacity * 1.5);
            T* new_vec = new T[_capacity];
            for(int i{}; i < _size; ++i) {
                new_vec[i] = vec[i];
            }
            delete[] vec;
            vec = new_vec;
        }
        _size++;
        vec[_size - 1] = value;
    }

     auto pop_back() {
        if (_size == 0) {
            throw std::range_error("Vector is empty");
        }
        T temp{vec[_size - 1]};
        _size--;
        if (_size < static_cast<int>(_capacity / 1.5)) {
            _capacity = static_cast<int>(_capacity/ 1.5);
            T* new_vec = new T[_capacity];
            for (int i{}; i < _size; ++i) {
                new_vec[i] = vec[i];
            }
            delete[] vec;
            vec = new_vec;
        }
        return temp;
    }

    void print_vec() {
        for (int i{}; i < _size; ++i) {
            std::cout << vec[i] << " ";
        }
    }

    T at(int index) {
        if (index < 0 || index > _size - 1) {
            throw std::range_error("Out of range");
        }
        return vec[index];
    }

    T& operator[](int i) {
        return vec[i];
    }
};