#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream file("C:/Users/User/Desktop/EDD1/ExStrings/names.txt");
    if (!file) {
        cerr << "Erro ao abrir o arquivo nomes.txt\n";
        return 1;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string nome, sobrenome;
        while (iss >> nome) {
            sobrenome = nome;
        }
        cout << sobrenome << ", " << line.substr(0, line.rfind(sobrenome)) << endl;
    }
    return 0;
}
