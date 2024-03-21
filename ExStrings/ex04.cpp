#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream file("C:/Users/User/Desktop/EDD1/ExStrings/names.txt");
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string nome, sobrenome;
        while (iss >> nome) {
            sobrenome = nome;
        }
        string iniciais;
        istringstream iss2(line.substr(0, line.rfind(sobrenome)));
        while (iss2 >> nome) {
            iniciais += nome[0];
            iniciais += ". ";
        }
        cout << sobrenome << ", " << iniciais << endl;
    }
    return 0;
}
