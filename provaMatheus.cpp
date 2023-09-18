#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Cliente
{
    string CPF;
    string Nome;
    string DtNascimento;
    string CNH;
};

struct Veiculo
{
    string Renavam;
    string PlacaDoVeiculo;
    string Data_HoraRetirada;
    string Data_HoraEntrega;
    string Loja_Retirada;
};

// Função para incluir um novo cliente 
void IncluirCliente(vector<Cliente>& clientes) {
    Cliente novoCliente;
    cout << "CPF: ";
    cin >> novoCliente.CPF;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, novoCliente.Nome);
    cout << "Data de Nascimento: ";
    cin >> novoCliente.DtNascimento;
    cout << "Número de CNH: ";
    cin >> novoCliente.CNH;

    clientes.push_back(novoCliente);
    cout << "Cliente incluído com sucesso!" << endl;
}

// Função para excluir um cliente por CPF
void ExcluirCliente(vector<Cliente>& clientes) {
    string cpfParaExcluir;
    cout << "Digite o CPF do Cliente que deseja excluir: ";
    cin >> cpfParaExcluir;

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->CPF == cpfParaExcluir) {
            clientes.erase(it);
            cout << "Cliente excluído com sucesso!" << endl;
            return;
        }
    }

    cout << "CPF não encontrado. Nenhum cliente excluído." << endl;
}

void AlterarCliente(vector<Cliente>& clientes) {
    string cpfParaAlterar;
    cout << "Digite o CPF do cliente que deseja alterar: ";
    cin >> cpfParaAlterar;

    for (auto& cliente : clientes) {
        if (cliente.CPF == cpfParaAlterar) {
            cout << "Dados atuais do cliente:" << endl;
            cout << "CPF: " << cliente.CPF << endl;
            cout << "Nome: " << cliente.Nome << endl;
            cout << "Data de Nascimento: " << cliente.DtNascimento << endl;
            cout << "Número de CNH: " << cliente.CNH << endl;

            char opcao;
            cout << "Deseja alterar o nome do cliente? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe o novo nome: ";
                cin.ignore();
                getline(cin, cliente.Nome);
            }

            cout << "Deseja alterar a data de nascimento do cliente? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe a nova data de nascimento: ";
                cin >> cliente.DtNascimento;
            }

            cout << "Deseja alterar o número de CNH do cliente? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe o novo número de CNH: ";
                cin >> cliente.CNH;
            }

            cout << "Cliente alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "CPF não encontrado." << endl;
}

// Função para listar todos os clientes
void ListarCliente(const vector<Cliente>& clientes) {
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado." << endl;
        return;
    }

    cout << "Lista de Clientes:" << endl;
    for (const Cliente& cliente : clientes) {
        cout << "CPF: " << cliente.CPF << endl;
        cout << "Nome: " << cliente.Nome << endl;
        cout << "Data de Nascimento: " << cliente.DtNascimento << endl;
        cout << "Número de Autorização: " << cliente.CNH << endl;
        cout << "---------------------------" << endl;
    }
}


// Função para localizar um cliente por CPF
void LocalizarCliente(const vector<Cliente>& clientes) {
    string cpfParaLocalizar;
    cout << "Digite o CPF do cliente que deseja localizar: ";
    cin >> cpfParaLocalizar;

    for (const Cliente& cliente : clientes) {
        if (cliente.CPF == cpfParaLocalizar) {
            cout << "CPF: " << cliente.CPF << endl;
            cout << "Nome: " << cliente.Nome << endl;
            cout << "Data de Nascimento: " << cliente.DtNascimento << endl;
            cout << "Número de Autorização: " << cliente.CNH << endl;
            return;
        }
    }

    cout << "CPF não encontrado." << endl;
}



int main(){
    vector<Cliente> clientes;

    int escolha;
    do{
        cout << "Menu de Opções:" << endl;
        cout << "1. Incluir Cliente" << endl;
        cout << "2. Excluir Cliente" << endl;
        cout << "3. Alterar Cliente (Apenas por CPF)" << endl;
        cout << "4. Listar Cliente" << endl;
        cout << "5. Localizar (Apenas por CPF)" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                IncluirCliente(clientes);
                break;
            case 2:
                ExcluirCliente(clientes);
                break;
            case 3:
                AlterarCliente(clientes);
                break;
            case 4:
                ListarCliente(clientes);
                break;
              case 5:
                LocalizarCliente(clientes);
                break;   
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
    } while (escolha != 0);
     
    
    return 0;
}