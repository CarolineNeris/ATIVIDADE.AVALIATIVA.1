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
    cout << "Numero de CNH: ";
    cin >> novoCliente.CNH;

    clientes.push_back(novoCliente);
    cout << "Cliente incluido com sucesso!" << endl;
}

// Função para excluir um cliente por CPF
void ExcluirCliente(vector<Cliente>& clientes) {
    string cpfParaExcluir;
    cout << "Digite o CPF do Cliente que deseja excluir: ";
    cin >> cpfParaExcluir;

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->CPF == cpfParaExcluir) {
            clientes.erase(it);
            cout << "Cliente excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "CPF nao encontrado. Nenhum cliente excluido." << endl;
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
            cout << "Numero de CNH: " << cliente.CNH << endl;

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

            cout << "Deseja alterar o numero de CNH do cliente? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe o novo número de CNH: ";
                cin >> cliente.CNH;
            }

            cout << "Cliente alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "CPF nao encontrado." << endl;
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
        cout << "Número de Autorizacao: " << cliente.CNH << endl;
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
            cout << "Numero de Autorizacao: " << cliente.CNH << endl;
            return;
        }
    }

    cout << "CPF nao encontrado." << endl;
}

void IncluirVeiculo(vector<Veiculo>& veiculos) {
    Veiculo novoVeiculo;
    cout << "Renavam: ";
    cin >> novoVeiculo.Renavam;
    cout << "Placa do Veiculo: ";
    cin >> novoVeiculo.PlacaDoVeiculo;
    cout << "Data e Hora de Retirada: ";
    cin >> novoVeiculo.Data_HoraRetirada;
    cout << "Data e Hora de Entrega: ";
    cin >> novoVeiculo.Data_HoraEntrega;
    cout << "Loja de Retirada: ";
    cin >> novoVeiculo.Loja_Retirada;

    veiculos.push_back(novoVeiculo);
    cout << "Veiculo incluido com sucesso!" << endl;
}

void ExcluirVeiculo(vector<Veiculo>& veiculos) {
    string placaParaExcluir;
    cout << "Digite a placa do Veiculo que deseja excluir: ";
    cin >> placaParaExcluir;

    for (auto it = veiculos.begin(); it != veiculos.end(); ++it) {
        if (it->PlacaDoVeiculo == placaParaExcluir) {
            veiculos.erase(it);
            cout << "Veiculo excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "Placa nao encontrada. Nenhum veiculo excluido." << endl;
}

void AlterarVeiculo(vector<Veiculo>& veiculos) {
    string placaParaAlterar;
    cout << "Digite a placa do veiculo que deseja alterar: ";
    cin >> placaParaAlterar;

    for (int i = 0; i < veiculos.size(); ++i) {
        if (veiculos[i].PlacaDoVeiculo == placaParaAlterar) {
            cout << "Dados atuais do veículo:" << endl;
            cout << "Renavam: " << veiculos[i].Renavam << endl;
            cout << "Placa do Veiculo: " << veiculos[i].PlacaDoVeiculo << endl;
            cout << "Data e Hora de Retirada: " << veiculos[i].Data_HoraRetirada << endl;
            cout << "Data e Hora de Entrega: " << veiculos[i].Data_HoraEntrega << endl;
            cout << "Loja de Retirada: " << veiculos[i].Loja_Retirada << endl;

            char opcao;
            cout << "Deseja alterar o Renavam do veiculo? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe o novo Renavam: ";
                cin >> veiculos[i].Renavam;
            }

            cout << "Deseja alterar a Data e Hora de Retirada do veiculo? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe a nova Data e Hora de Retirada: ";
                cin >> veiculos[i].Data_HoraRetirada;
            }

            cout << "Deseja alterar a Data e Hora de Entrega do veiculo? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe a nova Data e Hora de Entrega: ";
                cin >> veiculos[i].Data_HoraEntrega;
            }

            cout << "Deseja alterar a Loja de Retirada do veiculo? (S/N): ";
            cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                cout << "Informe a nova Loja de Retirada: ";
                cin.ignore();
                getline(cin, veiculos[i].Loja_Retirada);
            }

            cout << "Veiculo alterado com sucesso!" << endl;
            return;
        }
    }

    cout << "Placa do veiculo nao encontrada." << endl;
}



void ListarVeiculo(const vector<Veiculo>& veiculos) {
    if (veiculos.empty()) {
        cout << "Nenhum veiculo cadastrado." << endl;
        return;
    }

    cout << "Lista de Veiculos:" << endl;
    for (const Veiculo& veiculo : veiculos) {
        cout << "Renavam: " << veiculo.Renavam << endl;
        cout << "Placa do Veiculo: " << veiculo.PlacaDoVeiculo << endl;
        cout << "Data e Hora de Retirada: " << veiculo.Data_HoraRetirada << endl;
        cout << "Data e Hora de Entrega: " << veiculo.Data_HoraEntrega << endl;
        cout << "Loja de Retirada: " << veiculo.Loja_Retirada << endl;
        cout << "---------------------------" << endl;
    }
}

void LocalizarVeiculoPorPlaca(const vector<Veiculo>& veiculos) {
    string placaParaLocalizar;
    cout << "Digite a placa do veículo que deseja localizar: ";
    cin >> placaParaLocalizar;

    for (const Veiculo& veiculo : veiculos) {
        if (veiculo.PlacaDoVeiculo == placaParaLocalizar) {
            cout << "Renavam: " << veiculo.Renavam << endl;
            cout << "Placa do Veículo: " << veiculo.PlacaDoVeiculo << endl;
            cout << "Data e Hora de Retirada: " << veiculo.Data_HoraRetirada << endl;
            cout << "Data e Hora de Entrega: " << veiculo.Data_HoraEntrega << endl;
            cout << "Loja de Retirada: " << veiculo.Loja_Retirada << endl;
            return;
        }
    }

    cout << "Placa do veículo não encontrada." << endl;
}


int main() {
    vector<Cliente> clientes;
    vector<Veiculo> veiculos;

    int escolha;
    do {
        cout << "Menu Principal:" << endl;
        cout << "1. Menu de Clientes" << endl;
        cout << "2. Menu de Veículos" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                int escolhaCliente;
                do {
                    cout << "\nMenu de Clientes:" << endl;
                    cout << "1. Incluir Cliente" << endl;
                    cout << "2. Excluir Cliente" << endl;
                    cout << "3. Alterar Cliente (Apenas por CPF)" << endl;
                    cout << "4. Listar Clientes" << endl;
                    cout << "5. Localizar Cliente (Por CPF)" << endl;
                    cout << "0. Voltar ao Menu Principal" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> escolhaCliente;

                    switch (escolhaCliente) {
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
                            break;
                        default:
                            cout << "Opção inválida." << endl;
                    }
                } while (escolhaCliente != 0);
                break;

            case 2:
                int escolhaVeiculo;
                do {
                    cout << "\nMenu de Veículos:" << endl;
                    cout << "1. Incluir Veículo" << endl;
                    cout << "2. Excluir Veículo" << endl;
                    cout << "3. Alterar Veículo (Por Placa)" << endl;
                    cout << "4. Listar Veículos" << endl;
                    cout << "5. Localizar Veículo (Por Placa)" << endl;
                    cout << "0. Voltar ao Menu Principal" << endl;
                    cout << "Escolha uma opção: ";
                    cin >> escolhaVeiculo;

                    switch (escolhaVeiculo) {
                        case 1:
                            IncluirVeiculo(veiculos);
                            break;
                        case 2:
                            ExcluirVeiculo(veiculos);
                            break;
                        case 3:
                            AlterarVeiculo(veiculos);
                            break;
                        case 4:
                            ListarVeiculo(veiculos);
                            break;
                        case 5:
                            LocalizarVeiculoPorPlaca(veiculos);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opção inválida." << endl;
                    }
                } while (escolhaVeiculo != 0);
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