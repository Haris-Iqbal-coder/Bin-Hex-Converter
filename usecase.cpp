//==========================================================
// Unit 2: Group 4
// Linh Nguyen & Muhammad Haris Iqbal
// usecase.cpp
//==========================================================
#include <string>
#include <fstream>
#include "bst.h"
using namespace std;

//========================================================
// create_bst
// Creates a BST to store data and key from input file.
// Precondition: fname is the file name.
// Postcondition: A BST is created and return the pointer to the root.
//========================================================
template <class T, class U>
BST<T,U>* create_bst(string fname)
{
    ifstream inData;
    inData.open(fname);

    BST<T,U>* bst = new BST<T,U>;
    string line;

    while(getline(inData,line))
    {
        string sub = ""; 
        string data, key;
        for (int i=0; i<line.length(); i++)
        {
            if (line[i] != ',')
                sub += line[i];
            else
            {
                data = sub;
                sub.clear();
            }
        }
        key = sub;
        bst->insert(data, key);
    }
    inData.close();
    return bst;
}

//========================================================
// convert
// Converts binary to hexidecimal
// Precondition: bst is the pointer to the BST, bin is binary string
// Postcondition: returns the corresponding hexidecimal conversion.
//========================================================
template <class T, class U>
string  convert(BST<T,U>* bst, string bin)
{
    int len = bin.length();
    while (len%4 != 0)
    {
        bin = "0"+bin;
        len = bin.length();
    }
    
    string hex;
    for (int i=0; i<len; i+=4)
    {
        string bits = bin.substr(i,4);
        hex += bst->get(bits);
    }
    return hex;
}