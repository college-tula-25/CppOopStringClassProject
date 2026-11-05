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
    String s1;
    String s2 = s1;
    //Func(s1);
    String s3 = GetStars(10);
}
