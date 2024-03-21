#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    string msg;
    cout << "Digite uma mensagem: ";
    getline(cin, msg);

    int terminal_width = 80;
    int padding = (terminal_width - msg.size()) / 2;

    for (int i = 0; i < 4; i++) {
        cout << endl;
    }

    for (int i = 0; i < padding; i++) {
        cout << " ";
    }

    cout << msg << endl;

    for (int i = 5; i < 20; i++) {
        Sleep(1000);
        for (int j = 0; j < padding; j++) {
            cout << " ";
        }
        cout << msg << endl;
    }

    return 0;
}