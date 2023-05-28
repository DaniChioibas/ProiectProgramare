#include <iostream>
#include <string>
#include "../Shared/Data/data.h"
#include "../Shared/Data/ora.h"
using namespace std;

int main()
{
    Data Q(10, 12, 2023, "Luni");
    Ora q(22, 59);
    cout << q;
    cout << endl;
    cout << Q;
}