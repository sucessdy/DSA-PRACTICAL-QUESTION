#include <iostream>
using namespace std;

#define SIZE 10

int table[SIZE];
// Initialize Table
void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = -1;
    }
}
// hash function

int hash1(int key)
{
    return key % SIZE;
}

int hash2(int key)
{
    return 7 - (key % 7);
}

// insert
void insertLinear(int key){ 
    int index= hash1(key) ; 
    while(table[index] != -1 && table[index] != -2){ 
        index = (index + 1) % SIZE; 
    }
    table[index] = key; 
}
// search 

int searchLinear(int key){ 
    int index = hash1(key) ; 
    while(table[index] != -1) { 
        if (table[index] == key) {
            return index ;
        }
        index = (index + 1) % SIZE ; 
    }
    return -1;
     
}

int main()
{

    return 0;
}