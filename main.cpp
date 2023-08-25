#include <iostream>
#include <vector>
#include "Thread.h"


using namespace std;


void populateProcesses(vector<Thread>* processes)
{

    Thread a("A", 1, 2);
    Thread b("B", 2, 3);
    Thread c("C", 3, 4);

    processes->push_back(a);
    processes->push_back(b);
    processes->push_back(c);

}

void showProcesses(vector<Thread>* processes)
{
    vector<Thread>::iterator i = processes->begin();

  cout << "Vector: ";
 
  // run for loop from 0 to vecSize
  for(i; i < processes->end(); i++)
  {
    // access value in the memory to which the pointer
    // is referencing
    cout << i->toString();
  }

  cout << endl;
}

int main()
{
    cout << "This is a test of the Thread Process Application..." << endl;
    cout << "Creating Threads..." << endl;

    vector<Thread> processes;

    populateProcesses(&processes);

    showProcesses(&processes);
    
    string s;
    cin >> s;


    return 0;

}