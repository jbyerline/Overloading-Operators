//
//  intArray.h
//  Overload Operator Lab
//  CS320
//  cssc0457 Red ID: 821301215
//
//  Created by Jacob Byerline on 11/13/19.
//  Copyright © 2019 Jacob Byerline. All rights reserved.
//

#ifndef _INTARRAY_H
#define _INTARRAY_H
#include <iostream>
#include <iomanip>
#include <string>         // warnings issued whether this or <string>
#include <fstream>          // necessary for external file ptr
#include <stdlib.h>

using std::ostream;

class IntArray {
    private:
        const char* name;       // array's name
        int* pA;                // dynamic array
        int size;               // size of array
        int hi;                 // largest index
        int lo;                 // smallest index
    public:
    // Overloaded constructors
    // IntArray z
    IntArray(){
        pA = (int *)calloc(10, sizeof(int));
        lo = 0;
        hi = 9;
        size = 10;
    }
    // IntArray y(size)
    IntArray(int arrSize){
        pA = (int *)calloc(arrSize, sizeof(int));
        lo = 0;
        hi = arrSize - 1;
        size = arrSize;
    }
    // IntArray x(lowerIndex,upperIndex)
    IntArray(int lowerIndex, int upperIndex){
        if(lowerIndex > upperIndex){
            std::cout << "Invalid index imput" << std::endl;
        }
        else if(upperIndex >= lowerIndex){
            pA = (int *)calloc((upperIndex - lowerIndex + 1), sizeof(int));
            lo = lowerIndex;
            hi = upperIndex;
            size = (upperIndex - lowerIndex + 1);
        }
    }
    // IntArray w(anotherIntArray)
    IntArray(const IntArray& clone){
        pA = (int *)calloc(clone.size, sizeof(int));
        lo = clone.lo;
        hi = clone.hi;
        size = clone.size;
        // Assign all values from clone to self
        for(int i = 0; i < size; i++) {
            pA[i] = clone.pA[i];
        }
    }
    // Destructor
    ~IntArray(){
    
    }
        // Overloaded operators
        int operator==(const IntArray&);
        int operator!=(const IntArray&);
        int& operator[] (int);                                      
        IntArray& operator=(IntArray&);                       
        IntArray operator+(const IntArray&);
        IntArray& operator+=(const IntArray&);
        friend ostream& operator<<(ostream& phrase, IntArray& inputArr) {
            IntArray a = inputArr;
            for (int i = a.lo; i <= a.hi; i++) {
                phrase << inputArr.getName() << "[" << i << "] = " << inputArr[i] << std::endl;
            }
            return phrase;
        }

        // Helper functions
        void setName(char const *_name);
        std::string getName();
        int  high();
        int  low();
};
#endif
