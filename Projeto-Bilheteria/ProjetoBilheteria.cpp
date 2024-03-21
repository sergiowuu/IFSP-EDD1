#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_FILEIRAS = 15;
const int POLTRONAS_POR_FILEIRA = 40;

struct Poltrona {
    bool ocupada;
    float preco;
};

float calcularPreco(int fileira) {
    if (fileira >= 1 && fileira <= 5) {
        return 50.00;
    } else if (fileira >= 6 && fileira <= 10) {
        return 30.00;
    } else if (fileira >= 11 && fileira <= 15) {
        return 15.00;
    } else {
        return 0.00;
    }
}

void exibirMapa(Poltrona teatro[NUM_FILEIRAS][POLTRONAS_POR_FILEIRA]) {
    cout << "\nMapa de Ocupação do Teatro:\n\n";

    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            if (teatro[i][j].ocupada) {
                cout << " #";
            } else {
                cout << " .";
            }
        }
        cout << endl;
    }

    cout << "\nLegenda:\n";
    cout << "'.': Lugar vago\n";
    cout << "'#': Lugar ocupado\n";
}

void reservarPoltrona(Poltrona teatro[NUM_FILEIRAS][POLTRONAS_POR_FILEIRA]) {
    int fileira, poltrona;

    cout << "Informe a fileira (1 a " << NUM_FILEIRAS << "): ";
    cin >> fileira;

    cout << "Informe a poltrona (1 a " << POLTRONAS_POR_FILEIRA << "): ";
    cin >> poltrona;

    if (fileira >= 1 && fileira <= NUM_FILEIRAS && poltrona >= 1 && poltrona <= POLTRONAS_POR_FILEIRA) {
        if (!teatro[fileira - 1][poltrona - 1].ocupada) {
            teatro[fileira - 1][poltrona - 1].ocupada = true;
            teatro[fileira - 1][poltrona - 1].preco = calcularPreco(fileira);
            cout << "Poltrona reservada com sucesso!\n";
        } else {
            cout << "Poltrona já ocupada. Escolha outra.\n";
        }
    } else {
        cout << "Dados inválidos. Tente novamente.\n";
    }
}

void calcularFaturamento(Poltrona teatro[NUM_FILEIRAS][POLTRONAS_POR_FILEIRA]) {
    int lugaresOcupados = 0;
    float valorBilheteria = 0.0;

    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            if (teatro[i][j].ocupada) {
                lugaresOcupados++;
                valorBilheteria += teatro[i][j].preco;
            }
        }
    }

    cout << "\nQuantidade de lugares ocupados: " << lugaresOcupados << endl;
    cout << "Valor da bilheteria: R$ " << fixed << setprecision(2) << valorBilheteria << endl;
}

int main() {
    setlocale (LC_ALL,"");
    Poltrona teatro[NUM_FILEIRAS][POLTRONAS_POR_FILEIRA] = {};

    int opcao;

    do {
        cout << "\nSeletor:\n";
        cout << "0. Finalizar\n";
        cout << "1. Reservar poltrona\n";
        cout << "2. Mapa de ocupação\n";
        cout << "3. Faturamento\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Programa finalizado.\n";
                break;
            case 1:
                reservarPoltrona(teatro);
                break;
            case 2:
                exibirMapa(teatro);
                break;
            case 3:
                calcularFaturamento(teatro);
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0;
}