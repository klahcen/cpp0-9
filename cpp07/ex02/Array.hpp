#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
    private:
        T *array;
        size_t n;
    public:
        Array(){
            *array = NULL;
        }
        Array(unsigned int n): n(n){
            array = new T[n];
        }
        Array(const Array& other) : n(other.n) {
            array = new T[n];
            for (size_t i = 0; i < n; ++i) {
                array[i] = other.array[i];
            }
        }
        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] array;
                n = other.n;
                array = new T[n];
                for (size_t i = 0; i < n; ++i) {
                    array[i] = other.array[i];
                }
            }
            return *this;
        }
        T& operator[](size_t index) {
            if (index >= n) {
                throw std::out_of_range("Index out of bounds");
            }
            return array[index];
        }
        ~Array(){
            delete[] array;
        }
};

#endif