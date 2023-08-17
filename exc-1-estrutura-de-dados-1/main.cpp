#include <iostream>
//implementado utilizando posição lógica7

const int TAMANHO_MAXIMO = 100;

using namespace std;

struct ListaEstatica {
    int elementos[TAMANHO_MAXIMO], tamanho;

    ListaEstatica() : tamanho(0) {
        // Inicializo a lista "vazia"
    }

    bool inserir(int valor, int posicao) {
        if (tamanho < TAMANHO_MAXIMO && posicao >= 0 && posicao <= tamanho) {
            for (int i = tamanho; i > posicao; --i) {
                elementos[i] = elementos[i - 1];
            }
            elementos[posicao] = valor;
            tamanho++;
            return true;
        }
        return false; // Não é possível inserir, a lista está cheia ou a posição é inválida
    }
/*
*/
    bool remover(int valor) {
        for (int i = 0; i < tamanho; ++i) {
            if (elementos[i] == valor) {
                for (int j = i; j < tamanho - 1; ++j) {
                    elementos[j] = elementos[j + 1];
                }
                tamanho--;
                return true;
            }
        }
        return false; // Elemento não encontrado na lista
    }

    bool contem(int valor) {
        for (int i = 0; i < tamanho; ++i) {
            if (elementos[i] == valor) {
                return true;
            }
        }
        return false;
    }

    int obterNumeroDeElementos() {
        return tamanho;
    }

    int obterPosicaoDoElemento(int valor) {
        for (int i = 0; i < tamanho; ++i) {
            if (elementos[i] == valor) {
                return i;
            }
        }
        return -1; // Elemento não encontrado na lista
    }

    int obterElementoNaPosicao(int posicao) {
        if (posicao >= 0 && posicao < tamanho) {
            return elementos[posicao];
        }
        return -1; // Posição inválida
    }

    void mostrar() {
        cout << "Elementos da lista:";
        for (int i = 0; i < tamanho; ++i) {
            cout << " " << elementos[i];
        }
        cout << endl;
    }
};

int main() {
    ListaEstatica lista;

    int escolha;
    int valor, posicao, pos;

    while (true) {
        cout << "(Programa implementado utilizando posição física do C++)";
        cout << "\nMenu:\n\n";
        cout << "1. Inserir elemento\n\n";
        cout << "2. Remover elemento\n\n";
        cout << "3. Exibir elementos\n\n";
        cout << "4. Obter número de elementos\n\n";
        cout << "5. Verificar se um elemento está na lista\n\n";
        cout << "6. Obter posição de um elemento\n\n";
        cout << "7. Recuperar elemento da posição\n\n";
        cout << "8. Sair\n\n";
        cout << "Digite sua escolha: ";
        cin >> escolha;
        cout << endl;

        switch (escolha) {
            case 1:
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                cout << "Digite a posição onde deseja inserir: ";
                cin >> posicao;
                if (lista.inserir(valor, posicao)) {
                    cout << "\nElemento inserido com sucesso.\n";
                } else {
                    cout << "\nFalha ao inserir elemento. A lista está cheia ou a posição é inválida/fora de alcance.\n";
                }
                break;

            case 2:
                cout << "Digite o valor a ser removido: ";
                cin >> valor;
                if (lista.remover(valor)) {
                    cout << "\nElemento removido com sucesso.\n";
                } else {
                    cout << "\nElemento não encontrado na lista.\n";
                }
                break;

            case 3:
                lista.mostrar();
                break;

            case 4:
                cout << "\nNúmero de elementos na lista: " << lista.obterNumeroDeElementos() << endl;
                break;

            case 5:
                cout << "Digite o valor a ser verificado: ";
                cin >> valor;
                if (lista.contem(valor)) {
                    cout << "\nO elemento está na lista.\n";
                } else {
                    cout << "\nO elemento não está na lista.\n";
                }
                break;

            case 6:
                cout << "Digite o valor do elemento para obter a posição: ";
                cin >> valor;
                pos = lista.obterPosicaoDoElemento(valor);
                if (pos != -1) {
                    cout << "\nO elemento está na posição " << pos << ".\n";
                } else {
                    cout << "\nElemento não encontrado na lista.\n";
                }
                break;

            case 7:
                cout << "Digite a posição do elemento para recuperar: ";
                cin >> posicao;
                valor = lista.obterElementoNaPosicao(posicao);
                if (valor != -1) {
                    cout << "\nO elemento na posição " << posicao << " é: " << valor << ".\n";
                } else {
                    cout << "\nPosição inválida.\n";
                }
                break;

            case 8:
                cout << "\nSaindo...\n";
                return 0;

            default:
                cout << "\nEscolha inválida. Por favor, digite uma opção válida.\n";
        }
    }

    return 0;
}
