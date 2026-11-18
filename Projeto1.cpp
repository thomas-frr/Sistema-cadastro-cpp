#include <iostream>
#include <string>

#define MAX 20

using namespace std;

// Struct do usuario
struct Usuario {
    int matricula;
    string nome;
    string tipo;
};

// Struct do livro
struct Livro {
    int codigo;
    int idMatricula;
    string titulo;
    string autor;
    string edicao;
};

// Procedimento do menu
void mostrarMenu() {
    cout << "\n############################ MENU ############################\n";
    cout << "1 - Para cadastrar um usuario.\n";
    cout << "2 - Para cadastrar um livro.\n";
    cout << "3 - Para listar usuarios.\n";
    cout << "4 - Para listar livros.\n";
    cout << "5 - Para buscar livros por usuario.\n";
    cout << "6 - Exibir o relatorio geral.\n";
    cout << "0 - Para encerrar.\n";
    cout << "##############################################################\n\n";
    cout << "Digite sua opcao: ";
}

// Procedimento para cadastrar usuário
void cadastrarUsuario(Usuario vet[], int &n) {
    if (n >= MAX) {
        cout << "Limite de usuarios atingido.\n";
        return;
    }

    int mat;
    cout << "Digite a matricula: ";
    cin >> mat;

    // Verificar se a matrícula já existe
    for (int i = 0; i < n; i++) {
        if (vet[i].matricula == mat) {
            cout << "Erro: Ja existe um usuario cadastrado com esta matricula!\n";
            return;
        }
    }

    vet[n].matricula = mat;
    cin.ignore();
    cout << "Digite o nome: ";
    getline(cin, vet[n].nome);
    cout << "Digite o Tipo (Aluno ou Professor): ";
    cin >> vet[n].tipo;

    n++;
    cout << "Usuario cadastrado com sucesso!\n";
}

// Listar Usuarios
void mostrarUsuarios(Usuario vet[], int n) {
    cout << "\n=== Usuarios Cadastrados ===\n";
    if (n == 0) {
        cout << "Nenhum usuario cadastrado.\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << "---------------------------------\n";
            cout << "Matricula: " << vet[i].matricula << endl;
            cout << "Nome: " << vet[i].nome << endl;
            cout << "Tipo: " << vet[i].tipo << endl;
        }
    }
    cout << "---------------------------------\n\n";
}

// Função para verificar se usuário existe
bool usuarioExiste(Usuario vet[], int n, int matricula) {
    if (matricula == 0) return true; // 0 = livro não emprestado
    for (int i = 0; i < n; i++) {
        if (vet[i].matricula == matricula) {
            return true;
        }
    }
    return false;
}

// Procedimento para cadastrar livro
void cadastrarLivro(Livro vetLivros[], int &nLivros, Usuario vetUsuarios[], int nUsuarios) {
    if (nLivros >= MAX) {
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

    // Associação com o usuário
    while (true) {
        cout << "Digite a matricula do usuario que esta pegando emprestado (ou 0 se nenhum): ";
        int mat;
        cin >> mat;

        if (usuarioExiste(vetUsuarios, nUsuarios, mat)) {
            vetLivros[nLivros].idMatricula = mat;
            break;
        } else {
            cout << "Erro: Usuario com matricula " << mat << " nao encontrado! Cadastre o usuario primeiro.\n";
        }
    }

    nLivros++;
    cout << "Livro cadastrado com sucesso!\n";
}

// Listar Livros (mostrando o nome do usuário responsável)
void mostrarLivros(Livro vetLivros[], int nLivros, Usuario vetUsuarios[], int nUsuarios) {
    cout << "\n=== Livros Cadastrados ===\n";
    if (nLivros == 0) {
        cout << "Nenhum livro cadastrado.\n";
    } else {
        for (int i = 0; i < nLivros; i++) {
            cout << "---------------------------------\n";
            cout << "Codigo: " << vetLivros[i].codigo << endl;
            cout << "Titulo: " << vetLivros[i].titulo << endl;
            cout << "Autor: " << vetLivros[i].autor << endl;
            cout << "Edicao: " << vetLivros[i].edicao << endl;

            // Buscar o nome do usuário pelo idMatricula
            string nomeUsuario = "Disponivel (Nao emprestado)";
            if (vetLivros[i].idMatricula != 0) {
                for (int j = 0; j < nUsuarios; j++) {
                    if (vetUsuarios[j].matricula == vetLivros[i].idMatricula) {
                        nomeUsuario = vetUsuarios[j].nome;
                        break;
                    }
                }
            }
            cout << "Emprestado para: " << nomeUsuario << endl;
        }
    }
    cout << "---------------------------------\n\n";
}

// Buscar livros por usuário específico (Opção 5)
void mostrarLivrosPorUsuario(Livro vetLivros[], int nLivros, Usuario vetUsuarios[], int nUsuarios) {
    int matBusca;
    cout << "Digite a matricula do usuario para buscar os livros: ";
    cin >> matBusca;

    // Verificar se o usuário existe
    if (!usuarioExiste(vetUsuarios, nUsuarios, matBusca) || matBusca == 0) {
        cout << "Usuario nao encontrado ou matricula invalida.\n";
        return;
    }

    // Encontrar o nome do usuário
    string nomeUsuario = "";
    for (int i = 0; i < nUsuarios; i++) {
        if (vetUsuarios[i].matricula == matBusca) {
            nomeUsuario = vetUsuarios[i].nome;
            break;
        }
    }

    cout << "\n=== Livros emprestados para: " << nomeUsuario << " ===\n";
    int contador = 0;
    for (int i = 0; i < nLivros; i++) {
        if (vetLivros[i].idMatricula == matBusca) {
            cout << "---------------------------------\n";
            cout << "Codigo: " << vetLivros[i].codigo << endl;
            cout << "Titulo: " << vetLivros[i].titulo << endl;
            cout << "Autor: " << vetLivros[i].autor << endl;
            cout << "Edicao: " << vetLivros[i].edicao << endl;
            contador++;
        }
    }

    if (contador == 0) {
        cout << "Nenhum livro emprestado para este usuario no momento.\n";
    }
    cout << "---------------------------------\n\n";
}

// Relatório geral: quantidade de livros emprestados por usuário (Opção 6)
void relatorioGeral(Usuario vetUsuarios[], int nUsuarios, Livro vetLivros[], int nLivros) {
    cout << "\n=== Relatorio Geral: Livros por Usuario ===\n";
    if (nUsuarios == 0) {
        cout << "Nenhum usuario cadastrado.\n";
        cout << "---------------------------------\n\n";
        return;
    }

    for (int i = 0; i < nUsuarios; i++) {
        int qtdLivros = 0;
        for (int j = 0; j < nLivros; j++) {
            if (vetLivros[j].idMatricula == vetUsuarios[i].matricula) {
                qtdLivros++;
            }
        }
        cout << "---------------------------------\n";
        cout << "Matricula: " << vetUsuarios[i].matricula << endl;
        cout << "Nome: " << vetUsuarios[i].nome << endl;
        cout << "Tipo: " << vetUsuarios[i].tipo << endl;
        cout << "Total de livros emprestados: " << qtdLivros << endl;
    }
    cout << "---------------------------------\n\n";
}

int main() {
    Usuario listaUsuarios[MAX];
    Livro listaLivros[MAX];

    int opcao;
    int contUsuarios = 0;
    int contLivros = 0;

    while (true) {
        mostrarMenu();
        cin >> opcao;

        if (opcao == 0) {
            cout << "Encerrando o programa...\n";
            break;
        }

        switch (opcao) {
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
                mostrarLivros(listaLivros, contLivros, listaUsuarios, contUsuarios);
                break;
            case 5:
                mostrarLivrosPorUsuario(listaLivros, contLivros, listaUsuarios, contUsuarios);
                break;
            case 6:
                relatorioGeral(listaUsuarios, contUsuarios, listaLivros, contLivros);
                break;
            default:
                cout << "Opcao invalida! Tente novamente.\n";
        }
    }

    return 0;
}
