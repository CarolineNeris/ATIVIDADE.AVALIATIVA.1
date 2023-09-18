#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Cliente {
    string CPF;
    string Nome;
    string dataNascimento;
    string CNH;
};

struct Veiculo {
    string Renavan;
    string placaVeiculo;
    string dataHoraRetirada;
    string dataHoraEntrega;
    string lojaRetirada;
};

vector<Cliente> clientes;
vector<Veiculo> veiculos;

void incluirCliente() {
    Cliente cliente;
    cout << "Digite o CPF: ";
    cin >> cliente.CPF;
    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, cliente.Nome);
    cout << "Digite a data de nascimento (DD/MM/AAAA): ";
    cin >> cliente.dataNascimento;
    cout << "Digite a CNH: ";
    cin >> cliente.CNH;

    clientes.push_back(cliente);
    cout << "Cliente incluído com sucesso!" << endl;
}

void excluirCliente() {
    string cpf;
    cout << "Digite o CPF do cliente a ser excluído: ";
    cin >> cpf;

    auto it = remove_if(clientes.begin(), clientes.end(), [&cpf](const Cliente& c) { return c.CPF == cpf; });

    if (it != clientes.end()) {
        clientes.erase(it, clientes.end());
        cout << "Cliente excluído com sucesso!" << endl;
    } else {
        cout << "Cliente não encontrado!" << endl;
    }
}

void alterarCliente() {
    string cpf;
    cout << "Digite o CPF do cliente a ser alterado: ";
    cin >> cpf;

    for (auto& cliente : clientes) {
        if (cliente.CPF == cpf) {
            cout << "Cliente encontrado!" << endl;
            cout << "Nome atual: " << cliente.Nome << "\nDeseja alterar? (s/n) ";
            char resposta;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite o novo nome: ";
                cin.ignore();
                getline(cin, cliente.Nome);
            }

            cout << "Data de nascimento atual: " << cliente.dataNascimento << "\nDeseja alterar? (s/n) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova data de nascimento (DD/MM/AAAA): ";
                cin >> cliente.dataNascimento;
            }

            cout << "CNH atual: " << cliente.CNH << "\nDeseja alterar? (s/n) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova CNH: ";
                cin >> cliente.CNH;
            }

            return;
        }
    }
    cout << "Cliente não encontrado!" << endl;
}

void listarClientes() {
    for (const auto& cliente : clientes) {
        cout << "CPF: " << cliente.CPF << "\nNome: " << cliente.Nome << "\nData de Nascimento: " << cliente.dataNascimento << "\nCNH: " << cliente.CNH << "\n\n";
    }
}

void localizarCliente() {
    string cpf;
    cout << "Digite o CPF do cliente a ser localizado: ";
    cin >> cpf;

    for (const auto& cliente : clientes) {
        if (cliente.CPF == cpf) {
            cout << "CPF: " << cliente.CPF << "\nNome: " << cliente.Nome << "\nData de Nascimento: " << cliente.dataNascimento << "\nCNH: " << cliente.CNH << "\n\n";
            return;
        }
    }
    cout << "Cliente não encontrado!" << endl;
}

void menuGestaoClientes() {
    int opcao;

    do {
        cout << "Módulo de Gestão de Clientes" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar" << endl;
        cout << "0. Sair" << endl;
        cout << "Digite uma opção: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            incluirCliente();
            break;
        case 2:
            excluirCliente();
            break;
        case 3:
            alterarCliente();
            break;
        case 4:
            listarClientes();
            break;
        case 5:
            localizarCliente();
            break;
        case 0:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }

    } while (opcao != 0);
}



void incluirVeiculo() {
    Veiculo veiculo;
    cout << "Digite o Renavan: ";
    cin >> veiculo.Renavan;
    cout << "Digite a placa do veículo: ";
    cin.ignore();
    getline(cin, veiculo.placaVeiculo);
    cout << "Digite a data e hora de retirada (DD/MM/AAAA HH:MM): ";
    getline(cin, veiculo.dataHoraRetirada);
    cout << "Digite a data e hora de entrega (DD/MM/AAAA HH:MM): ";
    getline(cin, veiculo.dataHoraEntrega);
    cout << "Digite a loja de retirada: ";
    getline(cin, veiculo.lojaRetirada);

    veiculos.push_back(veiculo);
    cout << "Veículo incluído com sucesso!" << endl;
}

void excluirVeiculo() {
    string placa;
    cout << "Digite a placa do veículo a ser excluído: ";
    cin >> placa;

    auto it = remove_if(veiculos.begin(), veiculos.end(), [&placa](const Veiculo& v) { return v.placaVeiculo == placa; });

    if (it != veiculos.end()) {
        veiculos.erase(it, veiculos.end());
        cout << "Veículo excluído com sucesso!" << endl;
    } else {
        cout << "Veículo não encontrado!" << endl;
    }
}

void alterarVeiculo() {
    string placa;
    cout << "Digite a placa do veículo a ser alterado: ";
    cin >> placa;

    for (auto& veiculo : veiculos) {
        if (veiculo.placaVeiculo == placa) {
            cout << "Veículo encontrado!" << endl;
            cout << "Renavan atual: " << veiculo.Renavan << "\nDeseja alterar? (s/n) ";
            char resposta;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite o novo Renavan: ";
                cin >> veiculo.Renavan;
            }

            cout << "Placa atual: " << veiculo.placaVeiculo << "\nDeseja alterar? (s/n) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova placa: ";
                cin.ignore();
                getline(cin, veiculo.placaVeiculo);
            }

            cout << "Data e hora de retirada atual: " << veiculo.dataHoraRetirada << "\nDeseja alterar? (s/n) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova data e hora de retirada (DD/MM/AAAA HH:MM): ";
                cin.ignore();
                getline(cin, veiculo.dataHoraRetirada);
            }

            cout << "Data e hora de entrega atual: " << veiculo.dataHoraEntrega << "\nDeseja alterar? (s/n) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova data e hora de entrega (DD/MM/AAAA HH:MM): ";
                cin.ignore();
                getline(cin, veiculo.dataHoraEntrega);
            }

            cout << "Loja de retirada atual: " << veiculo.lojaRetirada << "\nDeseja alterar? (s/n) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova loja de retirada: ";
                cin.ignore();
                getline(cin, veiculo.lojaRetirada);
            }

            return;
        }
    }
    cout << "Veículo não encontrado!" << endl;
}

void listarVeiculos() {
    for (const auto& veiculo : veiculos) {
        cout << "Renavan: " << veiculo.Renavan << "\nPlaca: " << veiculo.placaVeiculo << "\nData e hora de retirada: " << veiculo.dataHoraRetirada << "\nData e hora de entrega: " << veiculo.dataHoraEntrega << "\nLoja de retirada: " << veiculo.lojaRetirada << "\n\n";
    }
}

void localizarVeiculo() {
    string placa;
    cout << "Digite a placa do veículo a ser localizado: ";
    cin >> placa;

    for (const auto& veiculo : veiculos) {
        if (veiculo.placaVeiculo == placa) {
            cout << "Renavan: " << veiculo.Renavan << "\nPlaca: " << veiculo.placaVeiculo << "\nData e hora de retirada: " << veiculo.dataHoraRetirada << "\nData e hora de entrega: " << veiculo.dataHoraEntrega << "\nLoja de retirada: " << veiculo.lojaRetirada << "\n\n";
            return;
        }
    }
    cout << "Veículo não encontrado!" << endl;
}

void menuGestaoVeiculos() {
    int opcao;

    do {
        cout << "Módulo de Gestão de Veículos" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar" << endl;
        cout << "0. Sair" << endl;
        cout << "Digite uma opção: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            incluirVeiculo();
            break;
        case 2:
            excluirVeiculo();
            break;
        case 3:
            alterarVeiculo();
            break;
        case 4:
            listarVeiculos();
            break;
        case 5:
            localizarVeiculo();
            break;
        case 0:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }

    } while (opcao != 0);
}

int main() {
    int choice;
    do {
        system("clear");
        cout << "Bem Vindo a  LocaFINA S/A" << endl << "Escolha uma das opções a seguir:" << endl;
        cout << "1. Gestão de Clientes" << endl;
        cout << "2. Gestão de Veículos" << endl;
        cout << "0. sair" << endl;
        cout << "Digite uma opção: ";
        cin >> choice;

        switch (choice) {
        case 1:
            menuGestaoClientes();
            break;
        case 2:
            menuGestaoVeiculos();
            break;
        case 0:
            cout << "Encerrando o programa..." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
            
            break;
        }

    } while (choice != 0);

    return 0;
}
