#ifndef INT_ARRAY_H
#define INT_ARRAY_H

class IntArray{

public:
    explicit IntArray(int sz = DefaultArraySize);
    IntArray(int sz, int *array);
    IntArray(const IntArray &rhs);
    ~IntArray(){
        delete [] ap;
    };

    int& operator[](int index) const;
    IntArray& operator=(const IntArray& rhs);

    int size() const;
    void randomize();
    void swap(int left, int right);
    void print();
    void plot();
    const IntArray part(int left, int right);

private:
    static const int DefaultArraySize = 20;
    void init(int sz, int *array);
    void init(const IntArray &rhs);
    int _size;
    int *ap;
};

inline IntArray::IntArray(int sz){
    init(sz, 0);
}

inline IntArray::IntArray(int sz, int *array){
    init(sz, array);
}

inline IntArray::IntArray(const IntArray &rhs){
    init(rhs);
}

inline int& IntArray::operator[](int index) const{
    return ap[index];
}

inline int IntArray::size() const{
    return _size;
}

#endif /* INT_ARRAY_H */