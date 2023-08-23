#include "Thread.h"


int Thread::getRAM()
{
    return this->ram;
}

int Thread::getCPU()
{
    return this->cpu;
}

string Thread::getName()
{
    return this->name;
}

string Thread::toString()
{
    string out;
    out = "Thread:  " + getName() + "  | " + to_string(getRAM()) + " | " + to_string(getCPU());

    return out;
}
