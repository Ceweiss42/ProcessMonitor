#include <iostream>

using namespace std;

class Thread
{
    private:
        int ram;
        int cpu;
        string name;

    public:
        int testing;
        string getName();
        int getCPU();
        int getRAM();
        string toString();
        Thread(string n, int r, int c)
        {
            this->name = n;
            this->ram = r;
            this->cpu = c;
            testing  = 12;
        }

};