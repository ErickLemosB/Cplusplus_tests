#include <iostream>
#include <cstdlib>
#include <ctime>
#define tmax 30
using namespace std;
//funcao para definir n
int n_ordem(int n) {
    do {
        cout << "Informe qual a ordem n da matriz: ";
        cin >> n;
    } while (isdigit(n)==false&&(n<5 or n>tmax));
    return n;
}
// Essa funcao eh pra preencher a matriz geracao anterior
// lembrando que eh mundo plano
void Matriz_em_branco(int n, char Matriz_x[][tmax]) {
    srand(time(NULL));
    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x = rand() % 10;
            if (x >= 0 and x <= 2)
                Matriz_x[i][j] = '*';
            else
                Matriz_x[i][j] = ' ';
        }
    }
}
// funcao para mostrar a matriz anterior
void Mostrar_matriz(int n, char Matriz_x[][tmax]) {
    cout << "Geracao anterior:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "[" << Matriz_x[i][j] << "]";
        }
        cout << endl;
    }
}
// funcao para checar quantos vizinhos tem ao redor do elemento[i][j] .
// lin >= 0 && lin < tmax && col >= 0         limita ao que esta dentro da matriz, ou seja nao inclui o que eh fora da matriz.
//col < tmax                                  limita ao que esta dentro da matriz.
//(lin != i || col != j)                      limita aos numeros ao redor, ou seja, faz com que nao cheque ele mesmo.
int Checagem_vizinhos(int n, int i, int j, char Matriz_x[][tmax]) {
    int lin, col, cont_vizinho = 0;
    for (lin = i - 1; lin <= i + 1; lin++) {
        for (col = j - 1; col <= j + 1; col++) {
            if (lin >= 0 && lin < tmax && col >= 0 && col < n && (lin != i or col != j)) {
                if (Matriz_x[lin][col] == '*') {
                    cont_vizinho++;
                }
            }
        }
    }
    return cont_vizinho;
}
// funcao para regra 1
bool reproducao(int cont_vizinho, int i, int j, char matriz_x[][tmax]) {
    if (cont_vizinho == 3 && matriz_x[i][j] == ' ') {
        return true;
    }
    return false;
}
// funcao para regra 2
bool sobrevivencia(int cont_vizinho, int i, int j, char matriz_x[][tmax]) {
    if ((cont_vizinho >= 2 && cont_vizinho <= 3) && matriz_x[i][j] == '*') {
        return true;
    }
    return false;
}
// nao eh necessario incluir regra 3 e 4 pois as limitacoes da regra 1 e 2 ja excluem a regra 3 e 4, ou seja,
// se nao regra for 1 ou 2, eh uma situacao da regra 3 ou 4 , ou uma situacao nao incluida, por exemplo, uma celula vazia com vizinho!= 3,
//  e resulta em um espaco em branco ' '

//funcao para criacao da matriz nova geracao
void matriz_nova(int n, char matriz_x[][tmax], char Matriz_nova_geracao[][tmax]) {
    int cont_vizinho;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cont_vizinho = Checagem_vizinhos(n, i, j, matriz_x);
            if (reproducao(cont_vizinho, i, j, matriz_x)) {
                Matriz_nova_geracao[i][j] = '*';
            }
            else if (sobrevivencia(cont_vizinho, i, j, matriz_x)) {
                Matriz_nova_geracao[i][j] = '*';
            }
            else
                Matriz_nova_geracao[i][j] = ' ';
        }
    }
}
//funcao para mostrar a matriz nova geracao
void Mostrar_matriz_nova(int n, char Matriz_nova_geracao[][tmax]) {
    cout << "Nova geracao:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "[" << Matriz_nova_geracao[i][j] << "]";
        }
        cout << endl;
    }
}
char S_OU_N(char s_ou_n) {
    do {
        cout << "Mais uma geracao? S/N " << endl;
        cin.ignore();
        cin.get(s_ou_n);
        s_ou_n=toupper(s_ou_n);
    } while (s_ou_n != 'N' and s_ou_n != 'S');
    return s_ou_n;
}
void mais_uma_geracao(int n,char Matriz_nova_geracao[][tmax], char escolha) {
    if (escolha == 'S') {
        matriz_nova(n, Matriz_nova_geracao, Matriz_nova_geracao);
        Mostrar_matriz_nova(n, Matriz_nova_geracao);
    }
}

int main() {
    int n = n_ordem(tmax);
    char Matriz_original[tmax][tmax];
    Matriz_em_branco(n, Matriz_original);
    Mostrar_matriz(n, Matriz_original);
    char Matriz_nova_geracao[tmax][tmax];
    matriz_nova(n, Matriz_original, Matriz_nova_geracao);
    Mostrar_matriz_nova(n, Matriz_nova_geracao);
    char escolha = ' ';
    do {
        escolha = S_OU_N(escolha);
        mais_uma_geracao(n, Matriz_nova_geracao, escolha);
    } while (escolha != 'N');

    return 0;
}
