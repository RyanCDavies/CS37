#include <iostream>
#include <string>

using namespace std;

int main(){

    int a;
    int sum = 0;
    int count = 0;

    cout << "Enter numbers that you want to sum up" << endl;
    while (cin >> a){
        sum += a;
        count++;
    }

    cout << "There are " << count << " numbers entered\n";
    cout << "The final result is " << sum << endl;

    return 0;
    }