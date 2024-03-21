#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string msg;
    cout << "Digite uma mensagem: ";
    getline(cin, msg);

    msg.erase(remove(msg.begin(), msg.end(), ' '), msg.end());
    string reversed = msg;
    reverse(reversed.begin(), reversed.end());

    if (msg == reversed) {
        cout << "A msg é um palíndromo." << endl;
    } else {
        cout << "A msg não é um palíndromo." << endl;
    }

    return 0;
}
