#ifndef MYDOUBLE_H
#define MYDOUBLE_H

#include <iostream>
#include <list>
class MyDouble
{
    private:
        double value;
    public:
        // default constructor
        MyDouble() {
            value = 0;
        }
        // constructor taking a double as parameter
        MyDouble(double v) {
            value = v;
        }
        // mutator
        void setValue(double d) {
            value=d;
        }

        // operator +
        MyDouble operator+(const MyDouble& obj) {
            MyDouble temp;
            temp.setValue(value + obj.value);
            return temp;
        }

        // operator + a double
        MyDouble operator+(double v) {
            MyDouble temp;
            temp.setValue(value + v);
            return temp;
        }

        // operator += to the object of the same class
        void operator+=(const MyDouble& right) {
            value += right.value;
        }
        // operator += to the primitive type
        void operator+=(double d) {
            value += d;
        }
        // overload operator + applied to a primitive double
        friend MyDouble operator+(double v, MyDouble d) {
            MyDouble temp;
            temp.setValue(v+d.value);
            return temp;
        }

        // overload operator == with right side of the object of the same class
        bool operator==(const MyDouble& d) {
            return value==d.value;
        }
        // overload operator == with right side of a primitive double
        bool operator==(double d) {
            return value==d;
        }
        // overload operator == with left side of a primitive double
        friend bool operator==(double left, const MyDouble& d) {
            return left==d.value;
        }

        // prefix ++, return the value after incremented
        MyDouble operator++() {
            value += 1;
            return *this;
        }

        // prefix ++, return the value before incremented
        MyDouble operator++(int) {
            MyDouble temp(value);
            value += 1;
            return temp;
        }
        friend std::ostream& operator<<(std::ostream& out, MyDouble d) {
            out << d.value;
            return out;
        }
};


class IntList
{
private:
    int numberOfInts;
    int* myList;
public:
    IntList(int numberOfIntegers) {
        numberOfInts = numberOfIntegers;
        myList = new int[numberOfInts];
        for (int i = 0; i < numberOfInts; ++i) {
            myList[i] = 0;
        }
    }
    int size() const {
        return numberOfInts;
    }
    int& operator[](int index) {
        return myList[index];
    }
    // destruxtor
    ~IntList() {
        if (myList) {
            delete[] myList;
        }
    }
    // copy constructor
    IntList(const IntList& l) {
        // memcpy sig:  void* memcpy( void* dest, const void* src, std::size_t count );
        //memcpy(myList, l.myList, numberOfInts * sizeof(*myList)); // careful with memcpy see below
        /* safer way */
        numberOfInts = l.numberOfInts;
        myList = new int[numberOfInts];
        if (myList) {
            for (int i = 0; i < numberOfInts; i++) {
                myList[i] = l.myList[i];
            }
        }
    }
    IntList operator=(const IntList& l) {
        numberOfInts = l.numberOfInts;
        myList = new int[numberOfInts];
        if (myList) {
            for (int i = 0; i < numberOfInts; i++) {
                myList[i] = l.myList[i];
            }
        }
        //memcpy(myList, l.myList, numberOfInts * sizeof(*myList)); // careful with memcpy see below
        return *this;
    }
    // + operator
    IntList operator+(const IntList& l) {
        int* tmp;
        for (int i = 0; i < numberOfInts - 1; i++) {
            tmp[i] = myList[i];
            tmp[i] += l.myList[i];
        }
        if (l.size() > numberOfInts) {
            for (int i = numberOfInts - 1; i < l.size() - numberOfInts; i++) {
                tmp[i] += l.myList[i];
            }
        }
        return *tmp;
    }
    IntList operator+=(int i) {
        numberOfInts++;
        myList[numberOfInts-1] = i;
        return *this;
    }
    // filters myList of i
    IntList operator-=(int i) {
        int* list;
        list = new int[numberOfInts];
        int count = 0;
        for (int k = 0; k < numberOfInts; k++) {
            if (myList[k] != i) {
                list[count] = myList[k];
                count++;
            }
        }
        numberOfInts -= (numberOfInts - count);
        for (int k = 0; k < count; k++) {
            myList[k] = list[k];
        }
        return *this;
    }
    // filters myList of all elements in IntList l
    IntList operator-=(const IntList& l) {
        /* TODO */
        return *this;
    }
    friend IntList operator-(const IntList& l, const IntList& r) {
        if (l.size() >= r.size()) {
            for (int i = 0; i < l.size() - (r.size() - l.size()); i++) {
                l.myList[i] -= r.myList[i];
            }
        }
        else {
            for (int i = 0; i < l.size(); i++) {
                l.myList[i] -= r.myList[i];
            }
        }
        return l;
    }
    //  << operator
    friend std::ostream &operator<<(std::ostream &out, const IntList &l) {
        out << "[";
        for (int i = 0; i < l.size(); i++) {
            out << l.myList[i];
            if (i != l.size() - 1) out << ',';
        }
        out << ']';
        return out;
    }
};
#endif //  MYDOUBLE_H
