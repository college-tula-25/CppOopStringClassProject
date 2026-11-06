#include <iostream>
#include "String.h"

void Func(String s)
{

}

String GetStars(int count)
{
    String s('*', count);
    return s;
}

int main()
{
    String s1("Hello world");
    String s2 = "Good by";

    s2 = 'a';
    std::cout << s2;

    //std::cout << s1[4] << "\n";
    //s1[4] = '$';
    //std::cout << s1 << "\n";
}
