#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Data
{
private:
    int dia;
    int mes;
    int ano;

public:
    Data() {}

    Data(int dia, int mes, int ano)
    {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    int getDia() const
    {
        return dia;
    }

    void setDia(int dia)
    {
        this->dia = dia;
    }

    int getMes() const
    {
        return mes;
    }

    void setMes(int mes)
    {
        this->mes = mes;
    }

    int getAno() const
    {
        return ano;
    }

    void setAno(int ano)
    {
        this->ano = ano;
    }
};

class Contato
{
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato() {}

    Contato(const string &email, const string &nome, const string &telefone, const Data &dtnasc)
    {
        this->email = email;
        this->nome = nome;
        this->telefone = telefone;
        this->dtnasc = dtnasc;
    }

    string getEmail() const
    {
        return email;
    }

    void setEmail(const string &email)
    {
        this->email = email;
    }

    string getNome() const
    {
        return nome;
    }

    void setNome(const string &nome)
    {
        this->nome = nome;
    }

    string getTelefone() const
    {
        return telefone;
    }

    void setTelefone(const string &telefone)
    {
        this->telefone = telefone;
    }

    Data getDtnasc() const
    {
        return dtnasc;
    }

    void setDtnasc(const Data &dtnasc)
    {
        this->dtnasc = dtnasc;
    }

    int idade() const
    {
        int currentYear = 2024;
        return currentYear - dtnasc.getAno();
    }
};

void printData(const Data &data)
{
    cout << "---------------------\n";
    cout << "| Data              |\n";
    cout << "|-------------------|\n";
    cout << "| - dia: " << data.getDia() << " | \n";
    cout << "| - mes: " << data.getMes() << " | \n";
    cout << "| - ano: " << data.getAno() << " | \n";
    cout << "---------------------\n";
}

void printContato(const Contato &contato)
{
    cout << "---------------------------------------\n";
    cout << "| Contato                             |\n";
    cout << "|-------------------------------------|\n";
    cout << "| - email: " << contato.getEmail() << " | \n";
    cout << "| - nome: " << contato.getNome() << " | \n";
    cout << "| - telefone: " << contato.getTelefone() << " | \n";
    cout << "| - dtnasc:" << contato.getDtnasc().getDia() << " | \n";
    cout << "|-------------------------------------|\n";
    cout << "| + idade(): " << contato.idade() << " | \n";
    cout << "---------------------------------------\n";
}

int main()
{
    Contato contatos[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Digite o email do contato " << i + 1 << ": ";
        string email;
        getline(cin, email);

        cout << "Digite o nome do contato " << i + 1 << ": ";
        string nome;
        getline(cin, nome);

        cout << "Digite o telefone do contato " << i + 1 << ": ";
        string telefone;
        getline(cin, telefone);

        cout << "Digite o dia de nascimento do contato " << i + 1 << ": ";
        int dia;
        cin >> dia;

        cout << "Digite o mes de nascimento do contato " << i + 1 << ": ";
        int mes;
        cin >> mes;

        cout << "Digite o ano de nascimento do contato " << i + 1 << ": ";
        int ano;
        cin >> ano;
        cin.ignore();

        contatos[i] = Contato(email, nome, telefone, Data(dia, mes, ano));
    }

    for (int i = 0; i < 5; i++)
    {
        printContato(contatos[i]);
    }

    return 0;
}
