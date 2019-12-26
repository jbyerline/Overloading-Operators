//
//  intArray.cpp
//  Overload Operator Lab
//  CS320
//  cssc0457 Red ID: 821301215
//
//  Created by Jacob Byerline on 11/13/19.
//  Copyright © 2019 Jacob Byerline. All rights reserved.
//

#include <iostream>
#include "intArray.h"

using namespace std;

// Overloaded operators
int IntArray::operator==(const IntArray& compArr){
    IntArray temp = compArr;
    if(size != temp.size){
        return 0;
    }
    for(int i = 0; i < size; i++){
        if(pA[lo + i] != temp[temp.lo + i]){
            return 0;
        }
    }
    return 1;
}
int& IntArray::operator[] (int index){
    int doesntMatter;
    if (index >= lo && index <= hi){
        return pA[index - lo];
    }
    else {
        cout << "ERROR: Invalid index\n";
    }
    return doesntMatter;
}
int IntArray::operator!=(const IntArray& compArr){
    IntArray temp = compArr;
    if(size != temp.size){
        return 1;
    }
    for(int i = 0; i < size; i++){
        if(pA[lo + i] != temp[temp.lo + i]){
            return 1;
        }
    }
    return 0;
}
IntArray& IntArray::operator=(IntArray& compArr){
    // Makes copy of origional array to return if sizes dont match
    IntArray * updated = new IntArray;
    updated->lo = lo;
    updated->hi = hi;
    updated->size = size;
    for(int i = 0; i < size; i++){
        updated->pA[updated->lo + i] = pA[lo+i];
    }
    if (compArr.size != size) {
        cout << "Error: Array Sizes do not Match" << endl;
        return *updated;
    }
    // Copy values to self
    lo = compArr.lo;
    hi = compArr.hi;
    for(int i = 0; i < size; i++){
        pA[i] = compArr.pA[i];
    }
    return compArr;
}
IntArray IntArray::operator+(const IntArray& inputArr){
    // Make a copy of inputArr
    IntArray copy = inputArr;
    // Define sum array and define it largest size, hi and lo index
    IntArray sumArray;
    if(size >= copy.size){
        sumArray.size = size;
        sumArray.hi = hi;
        sumArray.lo = lo;
    }
    else{
        sumArray.size = copy.size;
        sumArray.hi = copy.hi;
        sumArray.lo = copy.lo;
    }
    // Check for non existant index, then add arrays together
    for(int i = 0; i < sumArray.size; i++){
        if(i > size - 1){
            sumArray.pA[i] = copy.pA[i];
        }
        else if(i > copy.size - 1){
            sumArray.pA[i] = pA[i];
        }
        else{
            sumArray.pA[i] = copy.pA[i] + pA[i];
        }
    }
    return sumArray;
}

IntArray& IntArray::operator+=(const IntArray& inputArr){
    
    // Make a copy of inputArr
    IntArray copy = inputArr;
    // Define sum array and define it largest size, hi and lo index
    IntArray * sumArray = new IntArray;
    
    if(size >= copy.size) {
        for (int i = 0; i < copy.size; i++) {
            pA[i] = pA[i] + copy.pA[i];
        }
    }
    else {
        int * placeHolder = (int*)realloc(pA, sizeof(int) * copy.size);
        delete pA;
        pA = (int*)realloc(placeHolder, sizeof(int) * copy.size);
        for (int i = 0; i < copy.size; i++) {
            if (i < size)
                pA[i] = pA[i] + copy.pA[i];
            else
                pA[i] = copy.pA[i];
        }
        size = copy.size;
        lo = copy.lo;
        hi = copy.hi;
    }
    return *sumArray;
    
}
// Helper functions
void IntArray::setName(char const *_name){
    name = _name;
}
string IntArray::getName(){
    return name;
}
int  IntArray::high(){
    return hi;
}
int  IntArray::low(){
    return lo;
}
