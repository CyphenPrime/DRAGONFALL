#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int a = 3;
int b = 50;

int main()
{
    srand(time(0));
   while(b>0)
    {
    int c = (rand() % 10 +1);
    if(c>=8)
    {
        b-(a*2);
        cout<<"Crit"<<endl;
        cout<<a<<endl;
        cout<<b<<endl<<endl;
    }
    else if(c<=2)
    {
        cout<<"attack miss"<<endl<<endl;
    }
    else
    {
        b = b - a;
        cout<<"Normal attack"<<endl;
        cout<<a<<endl;
        cout<<b<<endl<<endl;
    }





    }
}