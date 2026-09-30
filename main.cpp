/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
  #include <iostream>
#include <string>
using namespace std;

int main() {

    // Variáveis da conta
    int numeroConta;
    string nomeCliente;
    string cpf;
    int tipoConta;
    double saldo;
    bool contaAtiva = false;

    int opcao;

    do {
        cout << "\n********************************\n";
        cout << "       BANCO DO CARLOS\n";
        cout << "********************************\n";
        cout << "1 - Cadastrar conta\n";
        cout << "2 - Consultar conta\n";
        cout << "3 - Verificar saldo\n";
        cout << "4 - Alterar tipo da conta\n";
        cout << "5 - Ativar/Desativar conta\n";
        cout << "6 - Sair\n";
        cout << "********************************\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1:
                cout << "\n--- CADASTRO DA CONTA ---\n";

                // Validação do número da conta
                do {
                    cout << "Numero da conta: ";
                    cin >> numeroConta;

                    if (numeroConta <= 0) {
                        cout << "O numero da conta deve ser maior que zero!\n";
                    }

                } while (numeroConta <= 0);

                cin.ignore();

                cout << "Nome do cliente: ";
                getline(cin, nomeCliente);

                cout << "CPF do cliente: ";
                getline(cin, cpf);

                // Validação do tipo da conta
                do {
                    cout << "Tipo da conta:\n";
                    cout << "1 - Corrente\n";
                    cout << "2 - Poupanca\n";
                    cout << "Escolha: ";
                    cin >> tipoConta;

                    if (tipoConta != 1 && tipoConta != 2) {
                        cout << "Tipo de conta invalido!\n";
                    }

                } while (tipoConta != 1 && tipoConta != 2);

                // Validação do saldo
                do {
                    cout << "Saldo inicial: R$ ";
                    cin >> saldo;

                    if (saldo < 0) {
                        cout << "O saldo nao pode ser negativo!\n";
                    }

                } while (saldo < 0);

                // A conta começa ativa
                contaAtiva = true;

                cout << "\nConta cadastrada com sucesso!\n";
                break;

            case 2:
                if (numeroConta > 0) {

                    cout << "\n--- CONSULTA DA CONTA ---\n";
                    cout << "Numero da conta: " << numeroConta << endl;
                    cout << "Nome do cliente: " << nomeCliente << endl;
                    cout << "CPF: " << cpf << endl;

                    if (tipoConta == 1) {
                        cout << "Tipo da conta: Corrente\n";
                    } else {
                        cout << "Tipo da conta: Poupanca\n";
                    }

                    cout << "Saldo: R$ " << saldo << endl;

                    if (contaAtiva) {
                        cout << "Situacao: Ativa\n";
                    } else {
                        cout << "Situacao: Inativa\n";
                    }

                } else {
                    cout << "\nNenhuma conta cadastrada!\n";
                }
                break;

            case 3:
                if (numeroConta > 0) {

                    if (contaAtiva) {
                        cout << "\n--- SALDO ---\n";
                        cout << "Saldo atual: R$ " << saldo << endl;
                    } else {
                        cout << "\nA conta esta desativada!\n";
                    }

                } else {
                    cout << "\nNenhuma conta cadastrada!\n";
                }
                break;

            case 4:
                if (numeroConta > 0) {

                    if (contaAtiva) {

                        cout << "\n--- ALTERAR TIPO DA CONTA ---\n";
                        cout << "1 - Corrente\n";
                        cout << "2 - Poupanca\n";
                        cout << "Novo tipo: ";
                        cin >> tipoConta;

                        while (tipoConta != 1 && tipoConta != 2) {
                            cout << "Tipo invalido! Digite 1 ou 2: ";
                            cin >> tipoConta;
                        }

                        cout << "Tipo da conta alterado com sucesso!\n";

                    } else {
                        cout << "\nA conta esta desativada!\n";
                    }

                } else {
                    cout << "\nNenhuma conta cadastrada!\n";
                }
                break;

            case 5:
                if (numeroConta > 0) {

                    if (contaAtiva) {
                        contaAtiva = false;
                        cout << "\nConta desativada com sucesso!\n";
                    } else {
                        contaAtiva = true;
                        cout << "\nConta ativada com sucesso!\n";
                    }

                } else {
                    cout << "\nNenhuma conta cadastrada!\n";
                }
                break;

            case 6:
                cout << "\nSistema encerrado. Obrigado!\n";
                break;

            default:
                cout << "\nOpcao invalida! Escolha uma opcao de 1 a 6.\n";
        }

    } while (opcao != 6);

    return 0;
}