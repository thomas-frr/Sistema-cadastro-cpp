#include <iostream>
#include <string>
#include <cstdlib>

#define MAX 20

using namespace std;

//Struct do usuario
struct Usuario {
    int matricula;
    string nome;
    string tipo;
};

//Struct do livro
struct Livro {
    int codigo;
    int idMatricula;
    string titulo;
    string autor;
    string edicao;
};

//Procedimento do menu
void mostrarMenu() {
    cout << "############################ MENU ############################\n";
    cout << "1 - para cadastrar um usuario.\n";
    cout << "2 - para cadastrar um livro.\n";
    cout << "3 - para listar usuarios.\n";
    cout << "4 - para listar livros.\n";
    cout << "5 - para buscar livros por usuario.\n";
    cout << "6 - exibir o relatorio geral.\n";
    cout << "0 - para encerrar.\n";
    cout << "##############################################################\n\n";
    cout << "Digite sua opcao: ";
}

//Procedimento do usuario
void cadastrarUsuario(Usuario vet[], int i){
    cout << "Digite a matricula: ";
    cin >> vet[i].matricula;
    cin.ignore();
    cout << "Digite o nome: ";
    getline(cin, vet[i].nome);
    cout << "Digite o Tipo (Aluno ou Professor): ";
    cin >> vet[i].tipo;
}

//Listar Usuarios
void mostrarUsuarios(Usuario vet[], int n) {
    cout << "\n=== Usuarios Cadastrados ===\n";
    for (int i = 0; i < n; i++) {
        cout << "---------------------------------\n";
        cout << "Matricula: " << vet[i].matricula << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Tipo: " << vet[i].tipo << endl;
    }
    if (n == 0) cout << "Nenhum usuario cadastrado.\n";
    cout << "---------------------------------\n\n\n";
}

//Procedimento do livro
void cadastrarLivro(Livro vet[], int i){
    cout << "Digite o codigo: ";
    cin >> vet[i].codigo;
    cin.ignore();
    cout << "Digite o titulo: ";
    getline(cin, vet[i].titulo);
    cout << "Digite o autor: ";
    getline(cin, vet[i].autor);
    cout << "Digite a edicao: ";
    getline(cin, vet[i].edicao);
}

//Listar Livros
void mostrarLivros(Livro vet[], int n) {
    cout << "\n=== Livros Cadastrados ===\n";
    for (int i = 0; i < n; i++) {
        cout << "---------------------------------\n";
        cout << "Codigo: " << vet[i].codigo << endl;
        cout << "Titulo: " << vet[i].titulo << endl;
        cout << "Autor: " << vet[i].autor << endl;
        cout << "Edicao: " << vet[i].edicao << endl;
    }
    if (n == 0) cout << "Nenhum usuario cadastrado.\n";
    cout << "---------------------------------\n\n\n";
}

//Mostrar livros por usuario
void mostrarLivrosPorUsuario()

int main(){

    Usuario listaUsuarios[MAX];
    Livro listaLivros[MAX];

    int opcao;
    int contUsuarios = 0;
    int contLivros = 0;

     while(true){
        mostrarMenu();
        cin >> opcao;

        if(opcao == 0)
            break;

        switch(opcao){
        case 1:
            if (contUsuarios < MAX) {
                cadastrarUsuario(listaUsuarios, contUsuarios++);
            } else {
                cout << "Limite de funcionarios atingido.\n";
            }
            break;
        case 2:
            if (contLivros < MAX) {
                cadastrarLivro(listaLivros, contLivros++);
            } else {
                cout << "Limite de livros atingido.\n";
            }
            break;

        case 3:
            mostrarUsuarios(listaUsuarios, contUsuarios);
            break;

        case 4:
            mostrarLivros(listaLivros, contLivros);
            break;
        case 5:

        }
    }

    return 0;
}
