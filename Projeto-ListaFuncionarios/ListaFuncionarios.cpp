#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Funcionario {
    string prontuario; // Alterado para string
    string nome;
    double salario;
};

void incluirFuncionario(vector<Funcionario>& funcionarios) {
    Funcionario novoFuncionario;
    cout << "Digite o prontuario do funcionario: ";
    cin >> novoFuncionario.prontuario;

    vector<Funcionario>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == novoFuncionario.prontuario) {
            break;
        }
    }

    if (it != funcionarios.end()) {
        cout << "Ja existe um funcionario com esse prontuario!" << endl;
        return;
    }

    cout << "Digite o nome do funcionario: ";
    cin.ignore();
    getline(cin, novoFuncionario.nome);

    cout << "Digite o salario do funcionario: ";
    cin >> novoFuncionario.salario;

    funcionarios.push_back(novoFuncionario);
    cout << "Funcionario incluido com sucesso!" << endl;
}

void excluirFuncionario(vector<Funcionario>& funcionarios) {
    string prontuario; // Change type to string
    cout << "Digite o prontuario do funcionario a ser excluido: ";
    cin >> prontuario;

    vector<Funcionario>::iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == prontuario) {
            break;
        }
    }

    if (it != funcionarios.end()) {
        funcionarios.erase(it);
        cout << "Funcionario excluido com sucesso!" << endl;
    } else {
        cout << "Funcionario nao encontrado!" << endl;
    }
}

void pesquisarFuncionario(const vector<Funcionario>& funcionarios) {
    string prontuario; // Change type to string
    cout << "Digite o prontuario do funcionario a ser pesquisado: ";
    cin >> prontuario;

    vector<Funcionario>::const_iterator it;
    for (it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == prontuario) {
            break;
        }
    }

    if (it != funcionarios.end()) {
        cout << "Funcionario encontrado:" << endl;
        cout << "Prontuario: " << it->prontuario << endl;
        cout << "Nome: " << it->nome << endl;
        cout << "Salario: " << it->salario << endl;
    } else {
        cout << "Funcionario nao encontrado!" << endl;
    }
}

void listarFuncionarios(const vector<Funcionario>& funcionarios) {
    cout << "Lista de funcionarios:" << endl;
    double totalSalarios = 0.0;

    for (vector<Funcionario>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        cout << "Prontuario: " << it->prontuario << endl;
        cout << "Nome: " << it->nome << endl;
        cout << "Salario: " << it->salario << endl;
        totalSalarios += it->salario;
        cout << endl;
    }

    cout << "Total de salarios: " << totalSalarios << endl;
}

int main() {
    vector<Funcionario> funcionarios;
    int opcao;

    do {
        cout << "Menu:" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Pesquisar" << endl;
        cout << "4. Listar" << endl;
        cout << "Digite a opcao desejada: ";

        
		if (!(cin >> opcao)) {
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    continue;
		}

        switch (opcao) {
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            case 1:
                incluirFuncionario(funcionarios);
                break;
            case 2:
                excluirFuncionario(funcionarios);
                break;
            case 3:
                pesquisarFuncionario(funcionarios);
                break;
            case 4:
                listarFuncionarios(funcionarios);
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }

        cout << endl;
    } while (opcao != 0);

    return 0;
}