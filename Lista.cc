#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstring>
using namespace std;

struct Node;

typedef struct Node
{
    int pos;
    char inf[50];
    Node *pProx;
    Node *pAnt;
} Node;

typedef struct ListaEncadeada
{
    int node;
    Node *pPrim;
    Node *pAtual;
    Node *pUltm;
} ListaEncadeada;

typedef struct
{
    int pos;
    char inf[50];
} LInformacoes;

typedef struct
{
    int node;
    LInformacoes *informacoes;

} ListaSequencial;

void imprimeLSequencial(ListaSequencial *p);
void imprimeLEncadeada(ListaEncadeada *p);

void leArquivoLS(ListaSequencial *p, char arquivo[50]);
void leArquivoLE(ListaEncadeada *p, char arquivo[50]);

void inserirIni(ListaSequencial *p, ListaEncadeada *t);
void inserirN(ListaSequencial *p, ListaEncadeada *t, int n);
void inserirFim(ListaSequencial *p, ListaEncadeada *t);

void removeInic(ListaSequencial *p, ListaEncadeada *t);
void removeN(ListaSequencial *p, ListaEncadeada *t, int n);
void removeFim(ListaSequencial *p, ListaEncadeada *t);

void buscaRG(ListaSequencial *p, ListaEncadeada *t, char RG[50]);
void buscaBinariaSequencial(ListaSequencial *p, char RG[50], int inicio, int fim, int CS, int Ms);
void buscaBinariaEncadeada(ListaEncadeada *t, char RG[50], int inicio, int fim, int CS, int Ms);

void selectionSort(ListaSequencial *p, ListaEncadeada *t);
void insertionSort(ListaSequencial *p, ListaEncadeada *t);
void bubbleSort(ListaSequencial *p, ListaEncadeada *t);

void quickSortSequencial(ListaSequencial *p, int inicio, int fim);
int particaoSequencial(ListaSequencial *p, int inicio, int fim);

void quickSortEncadeada(ListaEncadeada *t, int inicio, int fim);
int particaoEncadeada(ListaEncadeada *t, int inicio, int fim);

int main()
{
    ListaSequencial *lSequencial;
    ListaEncadeada *lEncadeada;
    lEncadeada = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
    if (lEncadeada == NULL)
    {
        printf("Erro alocacao do vetor1");
        exit(1);
    }
    lEncadeada->pUltm = NULL;
    lSequencial = (ListaSequencial *)malloc(sizeof(ListaSequencial));
    lSequencial->informacoes = new LInformacoes[1000];
    if (lSequencial == NULL)
    {
        printf("Erro alocacao do vetor1");
        exit(1);
    }
    if (lSequencial->informacoes == NULL)
    {
        printf("Erro alocacao do vetor2");
    }
    int opcao;
    int n;
    do
    {
        cout << "Digite 0 para imprimir a lista" << endl;
        cout << "Digite 1 para Insercao de um no no inicio da lista" << endl;
        cout << "Digite 2 para Insercao de um no no fim da lista" << endl;
        cout << "Digite 3 para Insercao de um no no na posicao N" << endl;
        cout << "Digite 4 para Retirar um no do inicio da lista" << endl;
        cout << "Digite 5 para Retirar um no no fim da lista" << endl;
        cout << "Digite 6 para Retirar um no na posicao N" << endl;
        cout << "Digite 7 para escolher um metodo de busca" << endl;
        cout << "Digite 8 para digitar o nome do arquivo a ser lido, Nome.txt" << endl;
        cout << "Digite 9 para escolher um metodo de orednacao" << endl;
        cout << "Digite -1 para sair" << endl;
        cin >> opcao;
        cout << endl;
        switch (opcao)
        {
        case 0:
            imprimeLSequencial(lSequencial);
            imprimeLEncadeada(lEncadeada);
            break;

        case 1:
            inserirIni(lSequencial, lEncadeada);
            break;

        case 2:
            inserirFim(lSequencial, lEncadeada);
            break;

        case 3:
            cout << "Digite a posicao que deseja inserir um no" << endl;
            cin >> n;
            inserirN(lSequencial, lEncadeada, n);
            break;

        case 4:
            removeInic(lSequencial, lEncadeada);
            break;

        case 5:
            removeFim(lSequencial, lEncadeada);
            break;

        case 6:
            cout << "Digite a posicao que deseja remover um no" << endl;
            cin >> n;
            removeN(lSequencial, lEncadeada, n);
            break;

        case 7:
            int escolha2;
            cout << "Digite 1 para uma busca sequencial. Digitar somente o RG" << endl;
            cout << "Digite 2 para uma busca binaria. Digitar somente o RG" << endl;
            cin >> escolha2;
            if (escolha2 == 1)
            {
                char RG[50];
                cout << "Digite o RG que deseja buscar: " << endl;
                fflush(stdin);
                cin >> RG;
                buscaRG(lSequencial, lEncadeada, RG);
            }
            else if (escolha2 == 2)
            {
                char RG[50];
                cout << "Digite o RG que deseja buscar:" << endl;
                cin >> RG;
                buscaBinariaSequencial(lSequencial, RG, 0, lSequencial->node, 0, 0);
                buscaBinariaEncadeada(lEncadeada, RG, 0, lEncadeada->node, 0, 0);
            }
            else
                cout << "opcao invalida" << endl;
            break;

        case 8:
            char arquivo[50];
            cout << "Digite o nome do arquivo (Nome.txt): " << endl;
            fflush(stdin);
            cin >> arquivo;
            leArquivoLS(lSequencial, arquivo);
            leArquivoLE(lEncadeada, arquivo);
            break;

        case 9:
            int escolha3;
            cout << "Digite 1 para selectionSort" << endl;
            cout << "Digite 2 para insertionSort" << endl;
            cout << "Digite 3 para bubbleSort" << endl;
            cout << "Digite 4 para quickSort" << endl;
            cin >> escolha3;
            if (escolha3 == 1)
            {
                selectionSort(lSequencial, lEncadeada);
            }
            else if (escolha3 == 2)
            {
                insertionSort(lSequencial, lEncadeada);
            }
            else if (escolha3 == 3)
            {
                bubbleSort(lSequencial, lEncadeada);
            }
            else if (escolha3 == 4)
            {
                quickSortSequencial(lSequencial, 0, lSequencial->node);
                quickSortEncadeada(lEncadeada, 0, lEncadeada->node);
            }
            else
                cout << "opcao invalida" << endl;
            break;

        case -1:
            exit(1);
            break;
        default:
            cout << "opcao invalida" << endl;
        }
        cout << endl;
    } while (opcao != -1);

    free(lSequencial);
    free(lEncadeada);
    delete (lSequencial->informacoes);
    return 0;
}
void leArquivoLS(ListaSequencial *p, char arquivo[50])
{
    time_t tempo_inicial, tempo_final;

    delete (p->informacoes);
    p->informacoes = new LInformacoes[1000];

    float tempo;
    int i = 0;
    tempo_inicial = clock();
    cout << "Abrindo arquivo: " << arquivo << endl;
    ifstream Arquivo(arquivo, ios::in);
    if (!Arquivo)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
    }
    while (!Arquivo.eof())
    {

        Arquivo >> p->informacoes[i].inf;
        for (int k = 0; k < 50; k++)
        {
            if (p->informacoes[i].inf[k] == ',')
            {
                p->informacoes[i].pos = i;
                i++;
            }
        }
    }
    Arquivo.close();
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);
    cout << "Lista Sequencial -> Lida com sucesso, tempo: " << tempo << " para ler o arquivo." << endl;
    p->node = i - 1;
}
void leArquivoLE(ListaEncadeada *p, char arquivo[50])
{
    int flag = 0;
    int flag2 = 0;
    int pos = 0;
    time_t tempo_inicial, tempo_final;
    float tempo;

    tempo_inicial = clock();
    ifstream Arquivo(arquivo, std::ios::in);
    if (!Arquivo)
    {
        cerr << "Arquivo dasdas pode ser aberto" << endl;
    }
    while (!Arquivo.eof())
    {
        if (flag == 0)
        {
            Node *pAux1 = new Node();
            Arquivo >> pAux1->inf;
            pAux1->pos = pos;
            p->pPrim = pAux1;
            p->pPrim->pProx = new Node();
            p->pAtual = p->pPrim;
            p->pPrim->pAnt = NULL;
            flag = 1;
        }
        else
        {
            pos++;
            Node *pAux2 = new Node();
            Arquivo >> pAux2->inf;
            pAux2->pos = pos;
            if (flag2 == 0)
            {
                p->pAtual = pAux2;
                p->pPrim->pProx = p->pAtual;
                p->pAtual->pAnt = p->pPrim;
                flag2 = 1;
            }
            else
            {
                p->pAtual->pProx = pAux2;
                pAux2->pAnt = p->pAtual;
                p->pAtual = p->pAtual->pProx;
                // p->pAtual->pAnt = p->pAtual;
                for (int k = 0; k < 50; k++)
                {
                    if (p->pAtual->inf[k] == ',')
                    {
                        p->pUltm = p->pAtual;
                        p->node = pos;
                    }
                }
            }
            pAux2 = NULL;
        }
    }
    Arquivo.close();
    p->pUltm->pProx = NULL;
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);
    cout << "Lista Encadeada -> Lida com sucesso, tempo: " << tempo << " para ler o arquivo." << endl;
}
void imprimeLSequencial(ListaSequencial *p)
{
    cout << endl;
    cout << "Lista Sequencial" << endl;
    for (int i = 0; i <= p->node; i++)
        cout << p->informacoes[i].inf << " " << p->informacoes[i].pos << endl;
}
void imprimeLEncadeada(ListaEncadeada *p)
{
    cout << endl;
    cout << "Lista Encadeada" << endl;
    p->pAtual = p->pPrim;
    for (int i = 0; i <= p->node; i++)
    {
        cout << p->pAtual->inf << " " << p->pAtual->pos << endl;
        p->pAtual = p->pAtual->pProx;
    }
}
void inserirIni(ListaSequencial *p, ListaEncadeada *t)
{
    time_t tempo_inicial, tempo_final;
    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    float tempo;
    char aux1[50];
    char aux2[50];
    char inf[50];
    cout << "Digite uma nova informacao neste modelo nome,rg " << endl;
    cin >> inf;
    size_t destination_size = sizeof(aux2);

    // Lista Sequencial
    snprintf(aux2, destination_size, "%s", p->informacoes[0].inf);
    snprintf(aux1, destination_size, "%s", p->informacoes[0].inf);
    snprintf(p->informacoes[0].inf, destination_size, "%s", inf);

    tempo_inicial = clock();
    p->node = p->node + 1;
    p->informacoes[p->node].pos = p->node;
    Ms = Ms + 2;
    for (int i = 1; i <= p->node; i++)
    {
        snprintf(aux2, destination_size, "%s", p->informacoes[i].inf);
        snprintf(p->informacoes[i].inf, destination_size, "%s", aux1);
        snprintf(aux1, destination_size, "%s", aux2);
        Ms = Ms + 3;
        CS = CS + 1;
    }
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);

    cout << "Lista Sequencial -> Foi adicionado com sucesso: " << p->informacoes[0].inf << ", C = " << CS << ", M = " << Ms
         << " Tempo de execucao : " << tempo << " Posicao: " << p->informacoes[0].pos << endl;

    // Lista Encadeada
    Node *aux = new Node();
    strcpy(aux->inf, inf);
    aux->pProx = t->pPrim;
    t->pPrim = aux;
    t->pPrim->pos = 0;
    t->node = t->node + 1;
    t->pAtual = t->pPrim;
    Me = 6;
    for (int pos = 0; pos <= t->node; pos++)
    {
        t->pAtual->pos = pos;
        t->pAtual = t->pAtual->pProx;
        Me = Me + 2;
        CE = CE + 1;
    }

    cout << "Lista Encadeada -> Foi adicionado com sucesso: " << t->pPrim->inf << ", C = " << CE << ", M = " << Me
         << " Tempo de execucao : " << tempo << " Posicao: " << t->pPrim->pos << endl;
}
void inserirN(ListaSequencial *p, ListaEncadeada *t, int n)
{
    time_t tempo_inicial, tempo_final;
    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    float tempo;
    char aux1[50];
    char aux2[50];
    char inf[50];

    size_t destination_size = sizeof(aux1);
    snprintf(aux1, destination_size, "%s", p->informacoes[n].inf);
    cout << "Digite uma nova informacao neste modelo nome,rg " << endl;
    cin >> inf;

    // Lista Sequencial

    tempo_inicial = clock();
    snprintf(p->informacoes[n].inf, destination_size, "%s", inf);
    p->node = p->node + 1;
    p->informacoes[p->node].pos = p->node;
    Ms = 3;
    for (int i = n + 1; i <= p->node; i++)
    {
        snprintf(aux2, destination_size, "%s", p->informacoes[i].inf);
        snprintf(p->informacoes[i].inf, destination_size, "%s", aux1);
        snprintf(aux1, destination_size, "%s", aux2);
        Ms = Ms + 3;
        CS = CS + 1;
    }
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);

    cout << "Lista Sequencial -> Foi adicionado com sucesso: " << p->informacoes[n].inf << ", C = " << CS << ", M = " << Ms
         << " Tempo de execucao : " << tempo << " Posicao: " << p->informacoes[n].pos << endl;

    // Lista Encadeada

    tempo = 0;
    tempo_inicial = clock();
    Node *aux = new Node();
    int flag = 0;
    snprintf(aux->inf, destination_size, "%s", inf);
    aux->pos = n;
    t->node = t->node + 1;
    t->pAtual = t->pPrim;
    Me = 4;
    while (flag != 1)
    {
        t->pAtual = t->pAtual->pProx;
        Me = Me + 1;
        if (n - 1 == t->pAtual->pos)
        {
            aux->pProx = t->pAtual->pProx;
            t->pAtual->pProx = aux;
            flag = 1;
            Me = Me + 3;
            CE = CE + 1;
        }
        CE = CE + 1;
    }
    t->pAtual = t->pPrim;
    Me = Me + 1;
    for (int pos = 0; pos <= t->node; pos++)
    {
        t->pAtual->pos = pos;
        t->pAtual = t->pAtual->pProx;
        Me = Me + 2;
        CE = CE + 1;
    }
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);

    cout << "Lista Encadeada -> Foi adicionado com sucesso: " << aux->inf << ", C = " << CE << ", M = " << Me
         << " Tempo de execucao : " << tempo << " Posicao: " << aux->pos << endl;
}
void inserirFim(ListaSequencial *p, ListaEncadeada *t)
{
    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    time_t tempo_inicial, tempo_final;

    float tempo;
    char aux1[50];
    char inf[50];
    p->node = p->node + 1;
    size_t destination_size = sizeof(aux1);

    cout << "Digite uma nova informacao neste modelo nome,rg " << endl;
    cin >> inf;

    // Lista Sequencial

    tempo_inicial = clock();
    snprintf(aux1, destination_size, "%s", p->informacoes[p->node].inf);
    snprintf(p->informacoes[p->node].inf, destination_size, "%s", inf);
    p->informacoes[p->node].pos = p->node;
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);
    CS = 0;
    Ms = 3;
    cout << "Lista Sequencial -> Foi adicionado com sucesso: " << p->informacoes[p->node].inf << ", C = " << CS << ", M = " << Ms
         << " Tempo de execucao : " << tempo << " Posicao: " << p->informacoes[p->node].pos << endl;

    // Lista Encadeada

    tempo_inicial = clock();

    Node *aux = new Node();
    snprintf(aux->inf, destination_size, "%s", inf);
    aux->pProx = NULL;
    t->pUltm->pProx = aux;
    aux->pAnt = t->pUltm;
    t->pUltm = aux;
    t->node = t->node + 1;
    t->pUltm->pos = t->node;
    Me = 7;
    /*->pAtual = t->pPrim;
    Me = 3;
    for (int k = 1; k <= t->node; k++) {
        t->pAtual = t->pAtual->pProx;
        Me = Me + 1;
        CE = CE + 1;
    }
    t->pAtual->pProx = aux;
    t->pUltm = t->pAtual->pProx;
    t->node = t->node + 1;
    t->pAtual = t->pPrim;
    Me = Me + 4;
    for (int pos = 0; pos <= t->node; pos++)
    {
        t->pAtual->pos = pos;
        t->pAtual = t->pAtual->pProx;
        Me = Me + 2;
        CE = CE + 1;
    }*/
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);

    cout << "Lista Encadeada -> Foi adicionado com sucesso: " << t->pUltm->inf << ", C = " << CE << ", M = " << Me
         << " Tempo de execucao : " << tempo << " Posicao: " << t->pUltm->pos << endl;
}
void removeInic(ListaSequencial *p, ListaEncadeada *t)
{
    time_t tempo_inicial, tempo_final;

    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    float tempo;
    char aux1[50];
    char aux2[50];
    char removido[50];
    size_t destination_size = sizeof(aux1);
    // Lista Sequencial
    tempo_inicial = clock();
    snprintf(removido, destination_size, "%s", p->informacoes[0].inf);
    snprintf(aux1, destination_size, "%s", p->informacoes[p->node].inf);
    Ms = 2;
    for (int i = p->node; i >= 0; i--)
    {
        snprintf(aux2, destination_size, "%s", p->informacoes[i - 1].inf);
        snprintf(p->informacoes[i - 1].inf, destination_size, "%s", aux1);
        snprintf(aux1, destination_size, "%s", aux2);

        Ms = Ms + 3;
        CS = CS + 1;
    }
    snprintf(p->informacoes[p->node].inf, destination_size, "%s", "");

    p->node = p->node - 1;
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);

    Ms = Ms + 2;
    cout << "Lista Sequencial -> Foi removido com sucesso: " << removido << ", C = " << CS << ", M = " << Ms
         << " Tempo de execucao : " << tempo << " Posicao: " << p->informacoes[0].pos << endl;

    // Lista Encadeada

    tempo_inicial = clock();

    Node *aux = new Node();
    aux = t->pPrim;
    t->pPrim = t->pPrim->pProx;
    t->node = t->node - 1;
    t->pUltm->pos = t->node;
    t->pAtual = t->pPrim;
    Me = 5;
    for (int pos = 0; pos <= t->node; pos++)
    {
        t->pAtual->pos = pos;
        t->pAtual = t->pAtual->pProx;
        Me = Me + 2;
        CE = CE + 1;
    }

    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);
    cout << "Lista Encadeada -> Foi removido com sucesso: " << aux->inf << ", C = " << CE << ", M = " << Me
         << " Tempo de execucao : " << tempo << " Posicao: " << aux->pos << endl;
}
void removeN(ListaSequencial *p, ListaEncadeada *t, int n)
{
    time_t tempo_inicial, tempo_final;
    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    float tempo;
    char aux1[50];
    char aux2[50];
    char removido[50];
    size_t destination_size = sizeof(aux1);
    // Lista Sequencial

    tempo_inicial = clock();
    snprintf(removido, destination_size, "%s", p->informacoes[n].inf);
    snprintf(aux1, destination_size, "%s", p->informacoes[p->node].inf);
    Ms = 2;
    for (int i = p->node; i >= n + 1; i--)
    {
        snprintf(aux2, destination_size, "%s", p->informacoes[i - 1].inf);
        snprintf(p->informacoes[i - 1].inf, destination_size, "%s", aux1);
        snprintf(aux1, destination_size, "%s", aux2);

        Ms = Ms + 3;
        CS = CS + 1;
    }
    snprintf(p->informacoes[p->node].inf, destination_size, "%s", "");

    p->node = p->node - 1;
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);

    Ms = Ms + 2;
    cout << "Lista Sequencial -> Foi removido com sucesso: " << removido << ", C = " << CS << ", M = " << Ms
         << " Tempo de execucao : " << tempo << " Posicao: " << p->informacoes[n].pos << endl;

    // Lista Encadeada

    tempo_inicial = clock();
    Node *auxI = new Node();
    Node *auxII = new Node();
    int flag = 0;
    t->node = t->node - 1;
    t->pAtual = t->pPrim;
    Me = 3;
    while (flag != 1)
    {
        t->pAtual = t->pAtual->pProx;
        Me = Me + 1;
        if (n - 1 == t->pAtual->pos)
        {
            auxI = t->pAtual;
            flag = 1;
            Me = Me + 2;
            CE = CE + 1;
        }
        CE = CE + 1;
    }
    t->pAtual = t->pAtual->pProx;
    auxII = t->pAtual;
    auxI->pProx = t->pAtual->pProx;
    t->pAtual = t->pPrim;
    Me = Me + 4;
    for (int pos = 0; pos <= t->node; pos++)
    {
        t->pAtual->pos = pos;
        t->pAtual = t->pAtual->pProx;
        Me = Me + 2;
        CE = CE + 1;
    }
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);

    cout << "Lista Encadeada -> Foi removido com sucesso: " << auxII->inf << ", C = " << CE << ", M = " << Me
         << " Tempo de execucao : " << tempo << " Posicao: " << auxII->pos << endl;
}
void removeFim(ListaSequencial *p, ListaEncadeada *t)
{
    time_t tempo_inicial, tempo_final;
    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    float tempo;
    char removido[50];
    int pos;
    size_t destination_size = sizeof(removido);
    // Lista Sequencial

    pos = p->informacoes[p->node].pos;
    tempo_inicial = clock();
    snprintf(removido, destination_size, "%s", p->informacoes[p->node].inf);
    snprintf(p->informacoes[p->node].inf, destination_size, "%s", "");

    p->node = p->node - 1;

    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);
    CS = 0;
    Ms = 5;
    cout << "Lista Sequencial -> Foi removido com sucesso: " << removido << ", C = " << CS << ", M = " << Ms
         << " Tempo de execucao : " << tempo << " Posicao: " << pos << endl;

    // Lista Encadeada

    tempo_inicial = clock();

    Node *aux = new Node();
    t->node = t->node - 1;
    t->pAtual = t->pPrim;
    Me = 2;
    for (int k = 1; k <= t->node; k++)
    {
        t->pAtual = t->pAtual->pProx;
        Me = Me + 1;
        CE = CE + 1;
    }
    t->pUltm = t->pAtual;
    t->pUltm->pos = t->node;

    t->pAtual = t->pAtual->pProx;
    aux = t->pAtual;
    snprintf(removido, destination_size, "%s", t->pAtual->inf);

    pos = t->pAtual->pos;
    aux->pProx = NULL;
    t->pAtual = t->pPrim;
    Me = Me + 8;
    for (int pos2 = 0; pos2 <= t->node; pos2++)
    {
        t->pAtual->pos = pos2;
        t->pAtual = t->pAtual->pProx;
        Me = Me + 2;
        CE = CE + 1;
    }
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);

    cout << "Lista Encadeada -> Foi removido com sucesso: " << removido << ", C = " << CE << ", M = " << Me
         << " Tempo de execucao : " << tempo << " Posicao: " << pos << endl;
}
void buscaRG(ListaSequencial *p, ListaEncadeada *t, char RG[50])
{
    time_t tempo_inicial, tempo_final;
    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    float tempo;
    // Lista Sequencial

    tempo_inicial = clock();
    bool achou = false;
    int pos = 0;
    Ms = 2;
    for (int i = 0; i <= p->node; i++)
    {
        CS = CS + 1;
        if (achou == true)
        {
            CS = CS + 1;
            break;
        }
        for (int k = 0; k < 50; k++)
        {
            CS = CS + 1;
            if (p->informacoes[i].inf[k] == ',')
            {
                CS = CS + 1;
                int j = 0;
                int t = k + 1;
                Ms = Ms + 2;
                while (RG[j] != '\0')
                {
                    CS = CS + 1;
                    if (p->informacoes[i].inf[t] != RG[j])
                    {
                        CS = CS + 1;
                        achou = false;
                        Ms = Ms + 1;
                        break;
                    }
                    achou = true;
                    pos = i;
                    t++;
                    j++;
                    Ms = Ms + 4;
                }
            }
        }
    }
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);
    if (achou == true)
    {
        cout << "Lista Sequencial -> " << p->informacoes[pos].inf << " , C = " << CS << " , M = " << Ms
             << " Tempo: " << tempo << " Pos:" << p->informacoes[pos].pos << endl;
    }
    else
        cout << "Lista Sequencial -> RG nao encontrado" << endl;

    // Lista Encadeada

    tempo_inicial = clock();
    bool achou2 = false;
    int pos2 = 0;
    t->pAtual = t->pPrim;
    Me = 3;
    for (int i = 0; i <= t->node; i++)
    {
        CE = CE + 1;
        for (int k = 0; k < 50; k++)
        {
            CE = CE + 1;
            if (t->pAtual->inf[k] == ',')
            {
                CE = CE + 1;
                int j = 0;
                int y = k + 1;
                Me = Me + 2;
                while (RG[j] != '\0')
                {
                    CE = CE + 1;
                    if (t->pAtual->inf[y] != RG[j])
                    {
                        CE = CE + 1;
                        achou2 = false;
                        Me = Me + 1;
                        break;
                    }
                    achou2 = true;
                    pos2 = i;
                    y++;
                    j++;
                    Me = Me + 4;
                }
            }
        }
        if (achou2 == true)
        {
            CE = CE + 1;
            break;
        }
        t->pAtual = t->pAtual->pProx;
        Me = Me + 1;
    }
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);

    if (achou2 == true)
    {
        cout << "Lista Encadeada -> " << t->pAtual->inf << " , " << CE << " , " << Me
             << " Tempo: " << tempo << " Pos:" << t->pAtual->pos << endl;
    }
    else
    {
        cout << "Lista Encadeada -> RG nao encontrado" << endl;
    }
}
void buscaBinariaSequencial(ListaSequencial *p, char RG[50], int inicio, int fim, int CS, int Ms)
{
    int m;
    bool mesmoRG = false;

    if (inicio <= fim)
    {
        m = (inicio + fim) / 2;
        int k, h;
        int x, y;
        int aux1, aux2;
        for (k = 0; p->informacoes[m].inf[k] != ','; k++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        for (x = 0; p->informacoes[m].inf[x + k + 1] != '\0'; x++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        for (y = 0; RG[y] != '\0'; y++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        if (x > y)
        {
            Ms = Ms + 1;
            CS = CS + 1;
            buscaBinariaSequencial(p, RG, inicio, m - 1, CS, Ms);
        }
        else if (x < y)
        {
            Ms = Ms + 1;
            CS = CS + 1;
            buscaBinariaSequencial(p, RG, m + 1, fim, CS, Ms);
        }
        else if (x == y)
        {
            CS = CS + 1;
            int aux1 = k + 1, aux2 = 0;
            Ms = Ms + 2;
            while (p->informacoes[m].inf[aux1] != '\0')
            {
                mesmoRG = false;
                CS = CS + 1;
                if (p->informacoes[m].inf[aux1] > RG[aux2])
                {
                    CS = CS + 1;
                    Ms = Ms + 1;
                    mesmoRG = false;
                    buscaBinariaSequencial(p, RG, inicio, m - 1, CS, Ms);
                    break;
                }
                else if (p->informacoes[m].inf[aux1] < RG[aux2])
                {
                    CS = CS + 1;
                    mesmoRG = false;
                    buscaBinariaSequencial(p, RG, m + 1, fim, CS, Ms);
                    break;
                }
                else if (p->informacoes[m].inf[aux1] == RG[aux2])
                {
                    CS = CS + 1;
                    mesmoRG = true;
                }
                aux1++;
                aux2++;
                Ms = Ms + 2;
            }
        }
    }
    if (mesmoRG == true)
    {
        cout << "Lista Sequencial -> " << p->informacoes[m].inf << " C = " << CS << " M = " << Ms << "Posicao = " << p->informacoes[m].pos << endl;
    }
}
void buscaBinariaEncadeada(ListaEncadeada *t, char RG[50], int inicio, int fim, int CS, int Ms)
{
    int m, flag = 0;
    bool mesmoRG = false;
    if (inicio <= fim)
    {
        m = (inicio + fim) / 2;
        t->pAtual = t->pPrim;
        while (t->pAtual->pos != m)
        {
            Ms = Ms + 1;
            CS = CS + 1;
            t->pAtual = t->pAtual->pProx;
        }
        int k, h;
        int x, y;
        int aux1, aux2;
        for (k = 0; t->pAtual->inf[k] != ','; k++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        for (x = 0; t->pAtual->inf[x + k + 1] != '\0'; x++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        for (y = 0; RG[y] != '\0'; y++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        if (x > y)
        {
            Ms = Ms + 1;
            CS = CS + 1;
            buscaBinariaEncadeada(t, RG, inicio, m - 1, CS, Ms);
        }
        else if (x < y)
        {
            Ms = Ms + 1;
            CS = CS + 1;
            buscaBinariaEncadeada(t, RG, m + 1, fim, CS, Ms);
        }
        else if (x == y)
        {
            CS = CS + 1;
            int aux1 = k + 1, aux2 = 0;
            Ms = Ms + 2;
            while (t->pAtual->inf[aux1] != '\0')
            {
                mesmoRG = false;
                CS = CS + 1;
                if (t->pAtual->inf[aux1] > RG[aux2])
                {
                    CS = CS + 1;
                    Ms = Ms + 1;

                    buscaBinariaEncadeada(t, RG, inicio, m - 1, CS, Ms);
                    break;
                }
                else if (t->pAtual->inf[aux1] < RG[aux2])
                {
                    CS = CS + 1;
                    buscaBinariaEncadeada(t, RG, m + 1, fim, CS, Ms);
                    break;
                }
                else if (t->pAtual->inf[aux1] == RG[aux2])
                {
                    CS = CS + 1;
                    mesmoRG = true;
                }
                aux1++;
                aux2++;
                Ms = Ms + 2;
            }
        }
    }
    if (mesmoRG == true)
    {
        cout << "Lista Encadeada -> " << t->pAtual->inf << " C = " << CS << " M = " << Ms << "Posicao = " << t->pAtual->pos << endl;
    }
}
void selectionSort(ListaSequencial *p, ListaEncadeada *t)
{
    int menor, i, j, k;
    time_t tempo_inicial, tempo_final;
    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    float tempo;
    bool sair1 = false;
    bool sair2 = false;
    bool tamanhoDiferente = false;
    char aux[50];
    size_t destination_size = sizeof(aux);
    // Lista Sequencial
    tempo_inicial = clock();
    for (i = 0; i <= p->node - 1; i++)
    {
        CS = CS + 1;
        menor = i;
        Ms = Ms + 2;
        for (j = i + 1; j <= p->node; j++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
            int k, h;
            int x, y;
            int aux1, aux2;
            for (k = 0; p->informacoes[menor].inf[k] != ','; k++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            for (h = 0; p->informacoes[j].inf[h] != ','; h++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            for (x = 0; p->informacoes[menor].inf[x + k + 1] != '\0'; x++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            for (y = 0; p->informacoes[j].inf[y + h + 1] != '\0'; y++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            if (x > y)
            {
                Ms = Ms + 1;
                CS = CS + 1;
                menor = j;
            }
            if (x == y)
            {
                CS = CS + 1;
                int aux1 = k + 1, aux2 = h + 1;
                Ms = Ms + 2;
                while (p->informacoes[menor].inf[aux1] != '\0')
                {
                    CS = CS + 1;
                    if (p->informacoes[menor].inf[aux1] > p->informacoes[j].inf[aux2])
                    {
                        CS = CS + 1;
                        Ms = Ms + 1;
                        menor = j;
                        break;
                    }
                    if (p->informacoes[menor].inf[aux1] < p->informacoes[j].inf[aux2])
                    {
                        CS = CS + 1;
                        break;
                    }
                    aux1++;
                    aux2++;
                    Ms = Ms + 2;
                }
            }
        }
        if (menor != i)
        {
            CS = CS + 1;
            snprintf(aux, destination_size, "%s", p->informacoes[i].inf);
            snprintf(p->informacoes[i].inf, destination_size, "%s", p->informacoes[menor].inf);
            snprintf(p->informacoes[menor].inf, destination_size, "%s", aux);
            Ms = Ms + 3;
        }
    }
    tempo_final = clock();
    tempo = difftime(tempo_final, tempo_inicial);
    cout << "Lista Sequencial -> "
         << " C = " << CS << " , M = " << Ms
         << " Tempo: " << tempo << endl;

    // Lista encadeada
    tempo_inicial = clock();
    Node *pMenor = new Node();
    Node *pAux = new Node();
    t->pAtual = t->pPrim;
    Me = Me + 1;
    for (int i = 0; i <= t->node; i++)
    {
        CE = CE + 1;
        pMenor = t->pAtual;
        pAux = t->pAtual->pProx;
        Me = Me + 3;
        for (j = i + 1; j <= t->node; j++)
        {
            Me = Me + 1;
            CE = CE + 1;
            int k, h;
            int x, y;
            int aux1, aux2;
            for (k = 0; pMenor->inf[k] != ','; k++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            for (h = 0; pAux->inf[h] != ','; h++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            for (x = 0; pMenor->inf[x + k + 1] != '\0'; x++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            for (y = 0; pAux->inf[y + h + 1] != '\0'; y++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            if (x > y)
            {
                Me = Me + 1;
                CE = CE + 1;
                pMenor = pAux;
            }
            if (x == y)
            {
                CE = CE + 1;
                int aux1 = k + 1, aux2 = h + 1;
                Me = Me + 2;
                while (pMenor->inf[aux1] != '\0')
                {
                    CE = CE + 1;
                    if (pMenor->inf[aux1] > pAux->inf[aux2])
                    {
                        CE = CE + 1;
                        Me = Me + 1;
                        pMenor = pAux;
                        break;
                    }
                    if (pMenor->inf[aux1] < pAux->inf[aux2])
                    {
                        CE = CE + 1;
                        break;
                    }
                    aux1++;
                    aux2++;
                    Me = Me + 2;
                }
            }
            pAux = pAux->pProx;
            Me = Me + 1;
        }
        if (menor != i)
        {
            CE = CE + 1;
            char aux2[50];
            snprintf(aux2, destination_size, "%s", t->pAtual->inf);
            snprintf(t->pAtual->inf, destination_size, "%s", pMenor->inf);
            snprintf(pMenor->inf, destination_size, "%s", aux2);
            Me = Me + 3;
        }
        t->pAtual = t->pAtual->pProx;
        Me = Me + 1;
    }
    tempo_final = clock();
    cout << "Lista Encadeada -> "
         << " C = " << CE << " , M = " << Me
         << " Tempo: " << tempo << endl;
}
void insertionSort(ListaSequencial *p, ListaEncadeada *t)
{
    time_t tempo_inicial, tempo_final;
    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    float tempo;
    int j, k;
    char aux[50];
    size_t destination_size = sizeof(aux);

    // Lista Sequencial
    tempo_inicial = clock();
    for (int i = 0; i <= p->node; i++)
    {
        CS = CS + 1;
        j = i;
        Ms = Ms + 1;
        while (j > 0)
        {
            Ms = Ms + 1;
            CS = CS + 1;
            int k, h;
            int x, y;
            int aux1, aux2;
            for (k = 0; p->informacoes[j - 1].inf[k] != ','; k++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            for (h = 0; p->informacoes[j].inf[h] != ','; h++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            for (x = 0; p->informacoes[j - 1].inf[x + k + 1] != '\0'; x++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            for (y = 0; p->informacoes[j].inf[y + h + 1] != '\0'; y++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            if (x > y)
            {
                Ms = Ms + 1;
                CS = CS + 1;
                snprintf(aux, destination_size, "%s", p->informacoes[j].inf);
                snprintf(p->informacoes[j].inf, destination_size, "%s", p->informacoes[j - 1].inf);
                snprintf(p->informacoes[j - 1].inf, destination_size, "%s", aux);
            }
            if (x == y)
            {
                CS = CS + 1;
                int aux1 = k + 1, aux2 = h + 1;
                Ms = Ms + 2;
                while (p->informacoes[j - 1].inf[aux1] != '\0')
                {
                    CS = CS + 1;
                    if (p->informacoes[j - 1].inf[aux1] > p->informacoes[j].inf[aux2])
                    {
                        CS = CS + 1;
                        Ms = Ms + 1;
                        snprintf(aux, destination_size, "%s", p->informacoes[j].inf);
                        snprintf(p->informacoes[j].inf, destination_size, "%s", p->informacoes[j - 1].inf);
                        snprintf(p->informacoes[j - 1].inf, destination_size, "%s", aux);
                        break;
                    }
                    if (p->informacoes[j - 1].inf[aux1] < p->informacoes[j].inf[aux2])
                    {
                        CS = CS + 1;
                        break;
                    }
                    aux1++;
                    aux2++;
                    Ms = Ms + 2;
                }
            }
            j--;
            Ms = Ms + 1;
        }
    }
    tempo_final = clock();
    cout << "Lista Sequencial -> "
         << " C = " << CS << " , M = " << Ms
         << " Tempo: " << tempo << endl;

    // Lista Encadeada
    tempo_inicial = clock();
    Node *pAuxAnt = new Node();
    Node *pAux = new Node();
    t->pAtual = t->pPrim;
    Me = Me + 1;
    for (int i = 0; i <= t->node; i++)
    {
        CE = CE + 1;
        j = i;
        pAux = t->pAtual;
        Me = Me + 2;
        while (j > 0)
        {
            CE = CE + 1;
            pAuxAnt = pAux->pAnt;
            Me = Me + 1;
            int k, h;
            int x, y;
            int aux1, aux2;
            for (k = 0; pAuxAnt->inf[k] != ','; k++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            for (h = 0; pAux->inf[h] != ','; h++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            for (x = 0; pAuxAnt->inf[x + k + 1] != '\0'; x++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            for (y = 0; pAux->inf[y + h + 1] != '\0'; y++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            if (x > y)
            {
                Me = Me + 1;
                CE = CE + 1;
                snprintf(aux, destination_size, "%s", pAuxAnt->inf);
                snprintf(pAuxAnt->inf, destination_size, "%s", pAux->inf);
                snprintf(pAux->inf, destination_size, "%s", aux);
            }
            if (x == y)
            {
                CE = CE + 1;
                int aux1 = k + 1, aux2 = h + 1;
                Me = Me + 2;
                while (pAuxAnt->inf[aux1] != '\0')
                {
                    CE = CE + 1;
                    if (pAuxAnt->inf[aux1] > pAux->inf[aux2])
                    {
                        CE = CE + 1;
                        Me = Me + 1;
                        snprintf(aux, destination_size, "%s", pAuxAnt->inf);
                        snprintf(pAuxAnt->inf, destination_size, "%s", pAux->inf);
                        snprintf(pAux->inf, destination_size, "%s", aux);
                        break;
                    }
                    if (pAuxAnt->inf[aux1] < pAux->inf[aux2])
                    {
                        CE = CE + 1;
                        break;
                    }
                    aux1++;
                    aux2++;
                    Me = Me + 2;
                }
            }
            pAux = pAux->pAnt;
            j--;
            Me = Me + 2;
        }
        t->pAtual = t->pAtual->pProx;
        Me = Me + 1;
    }
    tempo_final = clock();
    cout << "Lista Encadeada -> "
         << " C = " << CE << " , M = " << Me
         << " Tempo: " << tempo << endl;
}
void bubbleSort(ListaSequencial *p, ListaEncadeada *t)
{
    time_t tempo_inicial, tempo_final;
    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    float tempo;
    char aux[50];
    bool mesmoNome;
    int k = 0;
    size_t destination_size = sizeof(aux);

    // Lista sequencial
    tempo_inicial = clock();
    for (int i = 1; i <= p->node; i++)
    {
        CS = CS + 1;
        for (int j = 0; j < p->node; j++)
        {
            CS = CS + 1;
            mesmoNome = false;
            Ms = Ms + 1;
            int k, h;
            int x, y;
            int aux1, aux2;
            for (k = 0; p->informacoes[j].inf[k] != ','; k++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            for (h = 0; p->informacoes[j + 1].inf[h] != ','; h++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            for (x = 0; p->informacoes[j].inf[x + k + 1] != '\0'; x++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            for (y = 0; p->informacoes[j + 1].inf[y + h + 1] != '\0'; y++)
            {
                Ms = Ms + 1;
                CS = CS + 1;
            }
            if (x > y)
            {
                Ms = Ms + 1;
                CS = CS + 1;
                snprintf(aux, destination_size, "%s", p->informacoes[j].inf);
                snprintf(p->informacoes[j].inf, destination_size, "%s", p->informacoes[j + 1].inf);
                snprintf(p->informacoes[j + 1].inf, destination_size, "%s", aux);
            }
            if (x == y)
            {
                CS = CS + 1;
                int aux1 = k + 1, aux2 = h + 1;
                Ms = Ms + 2;
                while (p->informacoes[j].inf[aux1] != '\0')
                {
                    CS = CS + 1;
                    if (p->informacoes[j].inf[aux1] > p->informacoes[j + 1].inf[aux2])
                    {
                        CS = CS + 1;
                        Ms = Ms + 1;
                        snprintf(aux, destination_size, "%s", p->informacoes[j].inf);
                        snprintf(p->informacoes[j].inf, destination_size, "%s", p->informacoes[j + 1].inf);
                        snprintf(p->informacoes[j + 1].inf, destination_size, "%s", aux);
                        break;
                    }
                    if (p->informacoes[j].inf[aux1] < p->informacoes[j + 1].inf[aux2])
                    {
                        CS = CS + 1;
                        break;
                    }
                    aux1++;
                    aux2++;
                    Ms = Ms + 2;
                }
            }
        }
    }
    tempo_final = clock();
    cout << "Lista Sequencial -> "
         << " C = " << CS << " , M = " << Ms
         << " Tempo: " << tempo << endl;
    // Lista Encadeada
    tempo_inicial = clock();
    Node *pAux = new Node();
    for (int i = 1; i <= t->node; i++)
    {
        CE = CE + 1;
        t->pAtual = t->pPrim;
        pAux = t->pAtual->pProx;
        Me = Me + 2;
        for (int j = 0; j < t->node; j++)
        {
            CE = CE + 1;
            mesmoNome = false;
            Me = Me + 1;
            int k, h;
            int x, y;
            int aux1, aux2;
            for (k = 0; t->pAtual->inf[k] != ','; k++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            for (h = 0; pAux->inf[h] != ','; h++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            for (x = 0; t->pAtual->inf[x + k + 1] != '\0'; x++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            for (y = 0; pAux->inf[y + h + 1] != '\0'; y++)
            {
                Me = Me + 1;
                CE = CE + 1;
            }
            if (x > y)
            {
                Me = Me + 1;
                CE = CE + 1;
                snprintf(aux, destination_size, "%s", t->pAtual->inf);
                snprintf(t->pAtual->inf, destination_size, "%s", pAux->inf);
                snprintf(pAux->inf, destination_size, "%s", aux);
            }
            if (x == y)
            {
                CE = CE + 1;
                int aux1 = k + 1, aux2 = h + 1;
                Me = Me + 2;
                while (t->pAtual->inf[aux1] != '\0')
                {
                    CE = CE + 1;
                    if (t->pAtual->inf[aux1] > pAux->inf[aux2])
                    {
                        CE = CE + 1;
                        Me = Me + 1;
                        snprintf(aux, destination_size, "%s", t->pAtual->inf);
                        snprintf(t->pAtual->inf, destination_size, "%s", pAux->inf);
                        snprintf(pAux->inf, destination_size, "%s", aux);
                        break;
                    }
                    if (t->pAtual->inf[aux1] < pAux->inf[aux2])
                    {
                        CE = CE + 1;
                        break;
                    }
                    aux1++;
                    aux2++;
                    Me = Me + 2;
                }
            }
            if (j == 0)
            {
                CE = CE + 1;
                t->pPrim = t->pAtual;
                Me = Me + 1;
            }
            t->pAtual = t->pAtual->pProx;
            pAux = t->pAtual->pProx;
            Me = Me + 2;
        }
    }
    tempo_final = clock();
    cout << "Lista Encadeada -> "
         << " C = " << CE << " , M = " << Me
         << " Tempo: " << tempo << endl;
}
void quickSortSequencial(ListaSequencial *p, int inicio, int fim)
{
    int pivo;
    if (inicio < fim)
    {
        pivo = particaoSequencial(p, inicio, fim);
        quickSortSequencial(p, inicio, pivo - 1);
        quickSortSequencial(p, pivo + 1, fim);
    }
}
int particaoSequencial(ListaSequencial *p, int inicio, int fim)
{
    char aux[50];
    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    size_t destination_size = sizeof(aux);
    int ladoEsq, k;
    char pivo[50];
    snprintf(pivo, destination_size, "%s", p->informacoes[fim].inf);
    ladoEsq = inicio;
    for (int j = inicio; j < fim; j++)
    {

        int k, h;
        int x, y;
        int aux1, aux2;
        for (k = 0; pivo[k] != ','; k++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        for (h = 0; p->informacoes[j].inf[h] != ','; h++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        for (x = 0; pivo[x + k + 1] != '\0'; x++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        for (y = 0; p->informacoes[j].inf[y + h + 1] != '\0'; y++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        if (x > y)
        {
            Ms = Ms + 1;
            CS = CS + 1;
            snprintf(aux, destination_size, "%s", p->informacoes[j].inf);
            snprintf(p->informacoes[j].inf, destination_size, "%s", p->informacoes[ladoEsq].inf);
            snprintf(p->informacoes[ladoEsq].inf, destination_size, "%s", aux);
            ladoEsq = ladoEsq + 1;
        }
        if (x == y)
        {
            CS = CS + 1;
            int aux1 = k + 1, aux2 = h + 1;
            Ms = Ms + 2;
            while (p->informacoes[j].inf[aux1] != '\0')
            {
                CS = CS + 1;
                if (pivo[aux1] > p->informacoes[j].inf[aux2])
                {
                    CS = CS + 1;
                    Ms = Ms + 1;
                    snprintf(aux, destination_size, "%s", p->informacoes[j].inf);
                    snprintf(p->informacoes[j].inf, destination_size, "%s", p->informacoes[ladoEsq].inf);
                    snprintf(p->informacoes[ladoEsq].inf, destination_size, "%s", aux);
                    ladoEsq = ladoEsq + 1;
                    break;
                }
                if (pivo[aux1] < p->informacoes[j].inf[aux2])
                {
                    CS = CS + 1;
                    break;
                }
                aux1++;
                aux2++;
                Ms = Ms + 2;
            }
        }
    }
    snprintf(aux, destination_size, "%s", p->informacoes[ladoEsq].inf);
    snprintf(p->informacoes[ladoEsq].inf, destination_size, "%s", p->informacoes[fim].inf);
    snprintf(p->informacoes[fim].inf, destination_size, "%s", aux);

    return ladoEsq;
}
void quickSortEncadeada(ListaEncadeada *t, int inicio, int fim)
{
    int posPivo;
    if (inicio < fim)
    {
        posPivo = particaoEncadeada(t, inicio, fim);
        quickSortEncadeada(t, inicio, posPivo - 1);
        quickSortEncadeada(t, posPivo + 1, fim);
    }
}
int particaoEncadeada(ListaEncadeada *t, int inicio, int fim)
{
    char aux[50];
    int CE = 0;
    int CS = 0;
    int Me = 0;
    int Ms = 0;
    size_t destination_size = sizeof(aux);
    int ladoEsq;
    ladoEsq = inicio;
    char pivo[50];
    Node *pFim = new Node();
    Node *pLadoEsq = new Node();
    pFim = t->pPrim;
    while (pFim->pos != fim)
    {
        if (pFim->pos == ladoEsq)
        {
            pLadoEsq = pFim;
        }
        if (pFim->pos == inicio)
        {
            t->pAtual = pFim;
        }
        pFim = pFim->pProx;
    }
    snprintf(pivo, destination_size, "%s", pFim->inf);
    for (int j = inicio; j < fim; j++)
    {
        int k, h;
        int x, y;
        int aux1, aux2;
        for (k = 0; pivo[k] != ','; k++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        for (h = 0; t->pAtual->inf[h] != ','; h++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        for (x = 0; pivo[x + k + 1] != '\0'; x++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        for (y = 0; t->pAtual->inf[y + h + 1] != '\0'; y++)
        {
            Ms = Ms + 1;
            CS = CS + 1;
        }
        if (x > y)
        {
            Ms = Ms + 5;
            CS = CS + 1;
            snprintf(aux, destination_size, "%s", t->pAtual->inf);
            snprintf(t->pAtual->inf, destination_size, "%s", pLadoEsq->inf);
            snprintf(pLadoEsq->inf, destination_size, "%s", aux);
            ladoEsq = ladoEsq + 1;
            pLadoEsq = pLadoEsq->pProx;
        }
        if (x == y)
        {
            CS = CS + 1;
            int aux1 = k + 1, aux2 = h + 1;
            Ms = Ms + 2;
            while (t->pAtual->inf[aux1] != '\0')
            {
                CS = CS + 1;
                if (pivo[aux1] > t->pAtual->inf[aux2])
                {
                    CS = CS + 1;
                    Ms = Ms + 5;
                    snprintf(aux, destination_size, "%s", t->pAtual->inf);
                    snprintf(t->pAtual->inf, destination_size, "%s", pLadoEsq->inf);
                    snprintf(pLadoEsq->inf, destination_size, "%s", aux);
                    ladoEsq = ladoEsq + 1;
                    pLadoEsq = pLadoEsq->pProx;
                    break;
                }
                if (pivo[aux1] < t->pAtual->inf[aux2])
                {
                    CS = CS + 1;
                    break;
                }
                aux1++;
                aux2++;
                Ms = Ms + 2;
            }
        }
        t->pAtual = t->pAtual->pProx;
    }
    snprintf(aux, destination_size, "%s", pLadoEsq->inf);
    snprintf(pLadoEsq->inf, destination_size, "%s", pFim->inf);
    snprintf(pFim->inf, destination_size, "%s", aux);
    Ms = Ms + 3;
    return ladoEsq;
}
