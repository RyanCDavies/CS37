#include <iostream>
#include <string>
using namespace std;

char get_index(string s, int i){
    char letter = s[i];
    return letter;
}

int main(){
    string text = "This is a linesss";
    string output = "";
    int text_size = text.size(); //get length of string
    for (int i = 0; i < text_size; i++){
        char t = get_index(text, i);
        if (t != 's'){
            output += t;
        }
    }
    cout << output << endl;
    return 0;
}