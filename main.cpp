//==========================================================
// Unit 2: Group 4
// Linh Nguyen & Muhammad Haris Iqbal
// main.cpp
//==========================================================
#include <string>
#include "usecase.cpp"
using namespace std;

void test_binhex() {
    try {
        BST<string,string>* bst1 = create_bst<string,string>("binhex.txt");
        string bin1 = "1111010100101";
        string expected_hex1 = "1EA5";

        string hex1 = convert<string,string>(bst1, bin1);
        delete bst1;

        if(hex1 != expected_hex1) {
            cout << "Incorrect result converting " << bin1 << " to hex. Expected : " << expected_hex1 << ", but got : " << hex1 << endl;
        }
    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }

    try {
        BST<string,string>* bst2 = create_bst<string,string>("binhex.txt");
        string bin2 = "0";
        string expected_hex2 = "0";

        string hex2 = convert<string,string>(bst2, bin2);
        delete bst2;

        if(hex2 != expected_hex2) {
            cout << "Incorrect result converting " << bin2 << " to hex. Expected : " << expected_hex2 << ", but got : " << hex2 << endl;
        }
    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }

    try {
        BST<string,string>* bst3 = create_bst<string,string>("binhex.txt");
        string bin3 = "01011111";
        string expected_hex3 = "5F";

        string hex3 = convert<string,string>(bst3, bin3);
        delete bst3;

        if(hex3 != expected_hex3) {
            cout << "Incorrect result converting " << bin3 << " to hex. Expected : " << expected_hex3 << ", but got : " << hex3 << endl;
        }
    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }
}

int main (void)
{
    test_binhex();
    cout << "Testing completed" << endl;
    return 0;
}