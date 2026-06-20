#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    srand(time(0));
    for(int i = 0;i<2;i++)
    {
        n= (rand() % 2) + 1;
        cout<<n<<endl<<endl;
        n= (rand() % 10) + 1;
        cout<<n<<endl<<endl;
    }

}