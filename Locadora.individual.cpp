#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Estrutura de dados para representar um cliente
struct Cliente {
    string CPF_cliente;
    string nome_cliente;
    string data_Nascimento;
    string num_CNH;
};

// Função incluir cliente:
void incluirCliente(vector<Cliente>& clientes) {
    Cliente novoCliente;
    cout << "Informe o CPF do cliente: ";
    cin >> novoCliente.CPF_cliente;
    cout << "Informe o nome do cliente: ";
    cin.ignore(); // Para evitar problemas com espaços no nome
    getline(cin, novoCliente.nome_cliente);
    cout << "Informe a data de nascimento do cliente (formato dd/mm/yyyy): ";
    cin >> novoCliente.data_Nascimento;
    cout << "Informe o número da CNH do cliente: ";
    cin >> novoCliente.num_CNH;

    clientes.push_back(novoCliente); 
}

// Função excluir cliente:
void excluirCliente(vector<Cliente>& clientes) {
    string excluiCPF;
    cout << "Informe o CPF do cliente a ser excluído: ";
    cin >> excluiCPF;
    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->CPF_cliente == excluiCPF) {
            it = clientes.erase(it);
            cout << "Cliente excluído com sucesso!" << endl;
            return;
        }
    }
    cout << "Cliente não encontrado." << endl;
}

// Função para listar clientes
void listarClientes(const vector<Cliente>& clientes) {
    cout << left << setw(15) << "CPF" << setw(30) << "Nome do cliente" << setw(20) << "Data de nascimento" << setw(15) << "Numero CNH" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (const auto& cliente : clientes) {
        cout << left << setw(15) << cliente.CPF_cliente << setw(30) << cliente.nome_cliente << setw(20) << cliente.data_Nascimento << setw(15) << cliente.num_CNH << endl;
    }
}

int main() {
    vector<Cliente> clientes;

    int opcao;
    do {
        cout << "\nMenu de Opções:" << endl;
        cout << "1. Cadastrar Cliente" << endl;
        cout << "2. Excluir Cliente" << endl;
        cout << "3. Listar Clientes" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                incluirCliente(clientes);
                break;
            case 2:
                excluirCliente(clientes);
                break;
            case 3:
                listarClientes(clientes);
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}
