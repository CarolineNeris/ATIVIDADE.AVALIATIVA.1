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

// Função para alterar cliente
void alterarDadosCliente(vector<Cliente>& clientes) {
    string CPF_cliente, novoCPF, novoNome, novaDataNascimento, novaCNH;
    int tipoAlteracao;
    
    cout << "Digite o CPF para encontrar o cliente desejado: ";
    cin >> CPF_cliente;

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (CPF_cliente == it->CPF_cliente) {
            cout << "Cliente localizado!" << endl << endl;
            cout << "Nome do cliente: " << it->nome_cliente << endl;
            cout << "CPF: " << it->CPF_cliente << endl;
            cout << "CNH: " << it->num_CNH << endl;
            cout << "Data de nascimento: " << it->data_Nascimento << endl << endl;

            cout << "Qual dado do cliente você deseja alterar? " << endl;
            cout << "1. Nome do cliente" << endl;
            cout << "2. CPF" << endl;
            cout << "3. CNH" << endl;
            cout << "4. Data de nascimento" << endl;
            cout << "Escolha uma opção: ";
            cin >> tipoAlteracao;
            cin.ignore(); // Limpa o buffer de entrada
            
            switch (tipoAlteracao) {
                case 1:
                    cout << "Digite o novo nome: ";
                    getline(cin, novoNome);
                    it->nome_cliente = novoNome;
                    break;
                case 2:
                    cout << "Digite o novo CPF: ";
                    cin >> novoCPF;
                    it->CPF_cliente = novoCPF;
                    break;
                case 3:
                    cout << "Digite a nova CNH: ";
                    cin >> novaCNH;
                    it->num_CNH = novaCNH;
                    break;
                case 4:
                    cout << "Digite nova data de nascimento: ";
                    cin >> novaDataNascimento;
                    it->data_Nascimento = novaDataNascimento;
                    break;
                default:
                    cout << "Opção inválida." << endl;
                    break;
            }
        }
    }
}

// Função para listar clientes
void listarClientes(const vector<Cliente>& clientes) {
    cout << left << setw(15) << "CPF" << setw(30) << "Nome do cliente" << setw(20) << "Data de nascimento" << setw(15) << "Numero CNH" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    for (const auto& cliente : clientes) {
        cout << left << setw(15) << cliente.CPF_cliente << setw(30) << cliente.nome_cliente << setw(20) << cliente.data_Nascimento << setw(15) << cliente.num_CNH << endl;
    }
}

// Função para localizar cliente
void localizarCliente(const vector<Cliente>& clientes) {
    string cpfParaLocalizar;
    cout << "Informe o CPF do cliente a ser localizado: ";
    cin >> cpfParaLocalizar;
    for (const auto& cliente : clientes) {
        if (cliente.CPF_cliente == cpfParaLocalizar) {
            cout << "CPF: " << cliente.CPF_cliente << endl;
            cout << "Nome do Cliente: " << cliente.nome_cliente << endl;
            cout << "Data de Nascimento: " << cliente.data_Nascimento << endl;
            cout << "Número CNH: " << cliente.num_CNH << endl;
            return;
        }
    }
    cout << "Cliente não encontrado." << endl;
}

int main() {
    vector<Cliente> clientes;

    int opcao;
    do {
        cout << "\nMenu de Opções:" << endl;
        cout << "1. Cadastrar Cliente" << endl;
        cout << "2. Excluir Cliente" << endl;
        cout << "3. Alterar Cliente" << endl; // Corrigido aqui
        cout << "4. Listar Clientes" << endl;
        cout << "5. Localizar Cliente (por CPF)" << endl;
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
                alterarDadosCliente(clientes);
                break;
            case 4:
                listarClientes(clientes);
                break;
            case 5:
                localizarCliente(clientes);
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