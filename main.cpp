#include "Thread.h"
#include <iostream>


using namespace std;


int main()
{
    cout << "This is a test of the Thread Process Application..." << endl;
    cout << "Creating Threads..." << endl;

    Thread t("Test Process", 12, 20);

    cout << t.toString() <<endl;
    
    string s;
    cin >> s;


    return 0;

}