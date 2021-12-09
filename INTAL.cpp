// header file for Biginteger
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class bigint
{
public:
        string value;
        bigint(){
                value = "";
        }
        void operator=(string k)
        {
                this->value = k;
        }
        void set(){
                cin>>value;
        }
        ~bigint(){
        }
};
int main()
{
        bigint a;
        a.set();
        cout<<a.value;
}