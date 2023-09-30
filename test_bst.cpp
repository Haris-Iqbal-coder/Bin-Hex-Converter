//========================================================
// Muhammad Haris Iqbal
// test_bst.cpp
//========================================================
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "bst.h"
using namespace std;

void test_empty() {
    try
    {
        BST<double, string> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert(27.02,"hello world");
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }

    try
    {
        BST<long long, long long> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert(8000888000,1);
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }
}

void test_insert() {
    try {
        BST<string, int> bst;
        bst.insert("one", -1);
        string bst_str = bst.to_string();
        if(bst_str != "-1") {
            cout << "Incorrect result of inserting (\"one\", -1). Expected -1 but got : " << bst_str << endl;
        }
        for(int i = 22; i <= 30; i++) {
            bst.insert("some data", i);
        }
        bst_str = bst.to_string();
        if(bst_str != "-1 22 23 24 25 26 27 28 29 30") {
            cout << "Incorrect result of inserting keys 22-30 in order. Expected -1 22 23 24 25 26 27 28 29 30 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 7 1 3 6 9 4 8 10") {
            cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 5 2 7 1 3 6 9 4 8 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }

    try {
        BST<int, char> bst1;
        bst1.insert(1704, 'h');
        bst1.insert(2810, 'a');
        bst1.insert(303, 'x');
        bst1.insert(3001, 'm');
        bst1.insert(806, 'z');
        string bst1_str = bst1.to_string();
        if(bst1_str != "h a x m z") {
            cout << "Incorrect result of inserting. Expected h a x m z but got : " << bst1_str << endl;
        }
        
        BST<bool, bool> bst2;
        bst2.insert(true,true);
        bst2.insert(false,false);
        bst2.insert(false,true);
        string bst2_str = bst2.to_string();
        if(bst2_str != "1 0 1") {
            cout << "Incorrect result of inserting. Expected h a x m z but got : " << bst2_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}

void test_get() {
    try {
        BST<string, int> bst;
        string val = bst.get(0);
        if(val!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        bst.insert("one",1);
        val = bst.get(1);
        if(val != "one") {
            cout << "Incorrect get result. Expected \"one\" but got : " << val << endl;
        }
    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }

    try {
        BST<string, float> bst;
        string val = bst.get(7749);
        if(val!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        bst.insert("1",1);
        bst.insert("log2",1);
        bst.insert("neg3",-3);
        bst.insert("zero",0);
        bst.insert("pi",3.14);
        bst.insert("e",2.71);
        bst.insert("11^2",121);
        bst.insert("sqrt(2)",1.41);
        bst.insert("Sigma x^n/fac(n)",2.71);
        val = bst.get(1);
        if(val != "1") {
            cout << "Incorrect get result. Expected 1 but got : " << val << endl;
        }
        val = bst.get(2.71);
        if(val != "e") {
            cout << "Incorrect get result. Expected e but got : " << val << endl;
        }
    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }
}

void test_remove() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        balanced_bst.remove(7);
        string bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 8 1 3 6 9 4 10") {
            cout << "Incorrect result of removing 7. Expected 5 2 8 1 3 6 9 4 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }

    try {
        BST<string, float> bst;
        bst.remove(7);
        string bst_str = bst.to_string();
        if(bst_str != "") {
            cout << "Incorrect result of removing from empty BST." << endl;
        }

        bst.insert("1",1);
        bst.insert("log2",1);
        bst.insert("neg3",-3);
        bst.insert("zero",0);
        bst.insert("pi",3.14);
        bst.insert("e",2.71);
        bst.insert("11^2",121);
        bst.insert("sqrt(2)",1.41);
        bst.insert("Sigma x^n/fac(n)",2.71);
        bst_str = bst.to_string();
        if(bst_str != "1 -3 1 0 3.14 2.71 121 1.41 2.71") {
            cout << "Incorrect result of inserting. Got" << bst_str << endl;
        }
        bst.remove(1);
        bst_str = bst.to_string();
        if(bst_str != "1 -3 3.14 0 2.71 121 1.41 2.71") {
            cout << "Incorrect result of removing. Got" << bst_str << endl;
        }
        bst.remove(2.71);
        bst.remove(1.41);
        bst_str = bst.to_string();
        if(bst_str != "1 -3 3.14 0 2.71 121") {
            cout << "Incorrect result of removing." << endl;
        }
    } catch(exception& e) {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }
}

void test_max_data() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string max_str = balanced_bst.max_data();
        if(max_str != "10 data") {
            cout << "Incorrect result of max_data. Expected \"10 data\" but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }

    try {
        BST<string, int> sq_bst;
        for(int i = 0; i <= 10; i++) {
            sq_bst.insert(to_string(i*i)+" data",i);
        }
        string max_sq_str = sq_bst.max_data();
        if(max_sq_str != "100 data") {
            cout << "Incorrect result of max_data. Expected \"100 data\" but got : " << max_sq_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }
}

void test_max_key() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int max_k = balanced_bst.max_key();
        if(max_k != 10) {
            cout << "Incorrect result of max_key. Expected 10 but got : " << max_k << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining key of max node in bst : " << e.what() << endl;
    }
}

void test_min_data() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string min_str = balanced_bst.min_data();
        if(min_str != "1 data") {
            cout << "Incorrect result of min_data. Expected \"1 data\" but got : " << min_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }
}

void test_min_key() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int min_k = balanced_bst.min_key();
        if(min_k != 1) {
            cout << "Incorrect result of min_key. Expected 10 but got : " << min_k << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining key of min node in bst : " << e.what() << endl;
    }
}

void test_successor() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int succ = balanced_bst.successor(4);
        if(succ != 5) {
            cout << "Incorrect result of successor of 4. Expected 5 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(7);
        if(succ != 8) {
            cout << "Incorrect result of successor of 7. Expected 8 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(10);
        if(succ != 0) {
            cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }

    try {
        BST<string, double> bst;
        bst.insert("1",1);
        bst.insert("log2",1);
        bst.insert("neg3",-3);
        bst.insert("zero",0);
        bst.insert("pi",3.14);
        bst.insert("e",2.71);
        bst.insert("11^2",121);
        bst.insert("sqrt(2)",1.41);
        bst.insert("Sigma x^n/fac(n)",2.71);
        string bst_str = bst.to_string();
        bst.remove(1);
        bst.remove(2.71);
        bst.remove(1.41);
        bst_str = bst.to_string();
        if(bst_str != "1 -3 3.14 0 2.71 121") {
            cout << "Incorrect result of removing." << endl;
        }

        double succ = bst.successor(0);
        if(succ != 1) {
            cout << "Incorrect result of successor of 0. Expected 1 but got : " << succ << endl;
        }
        succ = bst.successor(121);
        if(succ != 0) {
            cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ << endl;
        }
        succ = bst.successor(1);
        if(succ != 2.71) {
            cout << "Incorrect result of successor of 1. Expected 2.71 but got : " << succ << endl;
        }

        bst.insert("sqrt(2)",1.41);
        bst.insert("Sigma x^n/fac(n)",2.71);
        succ = bst.successor(2.71);
        if(succ != 2.71) {
            cout << "Incorrect result of successor of 2.71. Expected 2.71 but got : " << succ << endl;
        }
        succ = bst.successor(1);
        if(succ != 1.41) {
            cout << "Incorrect result of successor of 1. Expected 1.41 but got : " << succ << endl;
        }

    } catch(exception& e) {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }
}

void test_in_order() {
    try {
        BST<string, int> bst;
        for(int i = 1; i <= 10; i++) {
            bst.insert("some data", i);
        }
        string bst_str = bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

void test_trim() {
    try {
        BST<string,int> bst;
        int vals[3] = {1, 0, 2};
        for(int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i])+" data", vals[i]);
        }
        bst.trim(1,2);
        string bst_str = bst.to_string();
        if(bst_str != "1 2") {
            cout << "Incorrect tree after trimming 1 0 2 with low=1, high=2. Expected 1 2 but got : " << bst_str << endl;
        }
        BST<string, int> bst2;
        int vals2[5] = {3, 0, 4, 2, 1};
        for(int i = 0; i < 5; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim(1,3);
        bst_str = bst2.to_string();
        if(bst_str != "3 2 1") {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. Expected 3 2 1 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }

    try {
        BST<int,int> bst;
        for(int i = 0; i < 10; i++) {
            bst.insert(i,i);
        }
        bst.trim(1,2);
        string bst_str = bst.to_string();
        if(bst_str != "1 2") {
            cout << "Incorrect tree after trimming with low=1, high=2. Expected 1 2 but got : " << bst_str << endl;
        }

        bst.trim(2,2);
        bst_str = bst.to_string();
        if(bst_str != "2") {
            cout << "Incorrect tree after trimming with low=2, high=2. Expected 2 but got : " << bst_str << endl;
        }
        
        bst.trim(3,4);
        bst_str = bst.to_string();
        if(bst_str != "") {
            cout << "Incorrect tree after trimming with low=3, high=4. Expected empty but got : " << bst_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
}

int main() {
    test_empty();
    test_insert();
    test_get();
    test_remove();
    test_max_data();
    test_max_key();
    test_min_data();
    test_min_key();
    test_successor();
    test_in_order();
    test_trim();
    cout << "Testing completed" << endl;
    return 0;
}
