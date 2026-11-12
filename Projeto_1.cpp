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
void cadastrarUsuario(Usuario vet[], int &n){
    if(n >= MAX){
        cout << "limite de usuarios atingido.\n";
        return;
    }

    int mat;
    cout << "Digite a matricula: ";
    cin >> mat;

    //verifica matricula
    for (int i = 0; i < n; i++){
        if(vet[i].matricula == mat){
            cout << "Erro: Ja existe um usuario cadasatrado com essa matricula.\n";
            return;
        }
    }

    vet[n].matricula = mat;
    cin.ignore();
    cout << "Digite o nome: ";
    getline(cin, vet[n].nome);
    cout << "Digite o tipo: ";
    getline(cin, vet[n].tipo);

    n++;
    cout << "Usuario cadastrado com sucesso.";
}

//Listar Usuarios
void mostrarUsuarios(Usuario vet[], int n) {
    cout << "\n=== Usuarios Cadastrados ===\n";

    if (n == 0){
        cout << "Nenhum usuario cadastrado.\n";
    }
    else{
    for (int i = 0; i < n; i++) {
        cout << "---------------------------------\n";
        cout << "Matricula: " << vet[i].matricula << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Tipo: " << vet[i].tipo << endl;
        }
    }
    cout << "---------------------------------\n\n\n";
}

//Procedimento pra ver se usuario existe
bool usuarioExiste(Usuario vet[], int n, int matricula){
    if(matricula == 0){
        return true;
    }
    for(int i = 0; i > n; i++){
        if(vet[i].matricula == matricula){
            return true;
        }
    }
    return false;
}

//Procedimento do livro
void cadastrarLivro(Livro vetLivros[], int &nLivros,Usuario vetUsuarios[], int nUsuarios){
    if(nLivros >= MAX){
        cout << "Limite de livros atingido.\n";
        return;
    }

    cout << "Digite o codigo: ";
    cin >> vetLivros[nLivros].codigo;
    cin.ignore();
    cout << "Digite o titulo: ";
    getline(cin, vetLivros[nLivros].titulo);
    cout << "Digite o autor: ";
    getline(cin, vetLivros[nLivros].autor);
    cout << "Digite a edicao: ";
    getline(cin, vetLivros[nLivros].edicao);


    while (true){
        int mat;
        cout << "Digite a matricula do usuario que esta pegando emprestado: \n";
        cin >> mat;
        if(usuarioExiste(vetUsuarios, nUsuarios, mat)){
            vetLivros[nLivros].idMatricula = mat;
            break;
        }
        else{
            cout << "Erro. Usuario com matricula: " << mat << " nao encontrado.\n";
        }
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
            cadastrarUsuario(listaUsuarios, contUsuarios);
            break;
        case 2:
            cadastrarLivro(listaLivros, contLivros, listaUsuarios, contUsuarios);
            break;

        case 3:
            mostrarUsuarios(listaUsuarios, contUsuarios);
            break;

        case 4:
            mostrarLivros(listaLivros, contLivros);
            break;


        }
    }

    return 0;
}
