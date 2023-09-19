#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Estrutura de dados para representar um veículo
struct Veiculo {
    string RENAVAN;
    string placa_veiculo;
    string data_hora_retirada;
    string data_hora_prevista;
    string loja_retirada;
};

// Função para incluir um veículo:
void incluirVeiculo(vector<Veiculo>& veiculos) {
    Veiculo novoVeiculo;
    cout << "Informe o RENAVAN do veículo: ";
    cin >> novoVeiculo.RENAVAN;
    cout << "Informe a placa do veículo: ";
    cin >> novoVeiculo.placa_veiculo;
    cout << "Informe a data/hora de retirada do veículo: ";
    cin >> novoVeiculo.data_hora_retirada;
    cout << "Informe a data/hora prevista para o veículo: ";
    cin >> novoVeiculo.data_hora_prevista;
    cout << "Informe a loja de retirada do veículo: ";
    cin.ignore(); // Para evitar problemas com espaços na loja
    getline(cin, novoVeiculo.loja_retirada);

    veiculos.push_back(novoVeiculo);
}

// Função para excluir um veículo por placa:
void excluirVeiculo(vector<Veiculo>& veiculos) {
    string excluiPlaca;
    cout << "Informe a placa do veículo a ser excluído: ";
    cin >> excluiPlaca;
    for (auto it = veiculos.begin(); it != veiculos.end(); ++it) {
        if (it->placa_veiculo == excluiPlaca) {
            it = veiculos.erase(it);
            cout << "Veículo excluído com sucesso!" << endl;
            return;
        }
    }
    cout << "Veículo não encontrado." << endl;
}

// Função para listar veículos:
void listarVeiculos(const vector<Veiculo>& veiculos) {
    cout << left << setw(20) << "RENAVAN" << setw(15) << "Placa do Veículo" << setw(25) << "Data/Hora de Retirada" << setw(25) << "Data/Hora Prevista" << setw(25) << "Loja de Retirada" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (const auto& veiculo : veiculos) {
        cout << left << setw(20) << veiculo.RENAVAN << setw(15) << veiculo.placa_veiculo << setw(25) << veiculo.data_hora_retirada << setw(25) << veiculo.data_hora_prevista << setw(25) << veiculo.loja_retirada << endl;
    }
}
void alterarDadosVeiculo(vector<Veiculo>& veiculos) {
    string placa_veiculo, novaRENAVAN, novaplaca_veiculo, novadata_hora_retirada, novadata_hora_prevista, novaloja_retirada;
    int tipoAlteracao;
    
    cout << "Digite o CPF para encontrar o cliente desejado: ";
    cin >> placa_veiculo;

    for (auto it = veiculos.begin(); it != veiculos.end(); ++it) {
        if (placa_veiculo == it->placa_veiculo) {
            cout << "Veículo localizado!" << endl << endl;
            cout << "RENAVAN: " << it->RENAVAN << endl;
            cout << "Placa do vaículo: " << it->placa_veiculo << endl;
            cout << "Data/Hora Retirada:" << it->data_hora_retirada << endl;
            cout << "Data/Hora Prevista: " << it-> data_hora_prevista << endl; 
            cout << "Loja retirada: " << it-> loja_retirada << endl << endl;

            cout << "Qual dado do veículo você deseja alterar? " << endl;
            cout << "1. Renavan" << endl;
            cout << "2. Placa "<< endl;
            cout << "3. Data/hora retirada" << endl;
            cout << "4. Data/hora prevista" << endl;
            cout << "5. Loja Retirada " << endl;
            cout << "Escolha uma opção: ";
            cin >> tipoAlteracao;
            cin.ignore(); // Limpa o buffer de entrada
            
            switch (tipoAlteracao) {
                case 1:
                    cout << "Digite o novo RENAVAN: ";
                    getline(cin, novaRENAVAN);
                    it->RENAVAN = novaRENAVAN;
                    break;
                case 2:
                    cout << "Digite nova placa: ";
                    cin >> novaplaca_veiculo;
                    it->placa_veiculo = novaplaca_veiculo;
                    break;
                case 3:
                    cout << "Digite a nova data/hora retirada: ";
                    cin >> novadata_hora_retirada;
                    it->data_hora_retirada = novadata_hora_retirada;
                    break;
                case 4:
                    cout << "Digite nova data/hora prevista: ";
                    cin >> novadata_hora_prevista;
                    it->data_hora_prevista= novadata_hora_prevista;
                    break;
                 case 5:
                    cout << "Digite nova loja para retirada: ";
                    cin >> novaloja_retirada;
                    it->loja_retirada = novaloja_retirada;
                    break;    
                default:
                    cout << "Opção inválida." << endl;
                    break;
            }
        }
    }
}
// Função para localizar um veículo por placa:
void localizarVeiculo(const vector<Veiculo>& veiculos) {
    string placaParaLocalizar;
    cout << "Informe a placa do veículo: ";
    cin >> placaParaLocalizar;
    for (const auto& veiculo : veiculos) {
        if (veiculo.placa_veiculo == placaParaLocalizar) {
            cout << "RENAVAN: " << veiculo.RENAVAN << endl;
            cout << "Placa do Veículo: " << veiculo.placa_veiculo << endl;
            cout << "Data/Hora de Retirada: " << veiculo.data_hora_retirada << endl;
            cout << "Data/Hora Prevista: " << veiculo.data_hora_prevista << endl;
            cout << "Loja de Retirada: " << veiculo.loja_retirada << endl;
            return;
        }
    }
    cout << "Este veículo não existe em nosso banco de dados." << endl;
}

int main() {
    vector<Veiculo> veiculos;

    int opcao;
    do {
        cout << "Menu de Opções:" << endl;
        cout << "1. Cadastrar Veículo" << endl;
        cout << "2. Excluir Veículo" << endl;
        cout << "3. Alterar Veículo" << endl;
        cout << "4. Listar Veículos" << endl;
        cout << "5. Localizar Veículo (por Placa)" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                incluirVeiculo(veiculos);
                break;
            case 2:
                excluirVeiculo(veiculos);
                break;
            case 3:
                alterarDadosVeiculo(veiculos);
                break;
            case 4:
                listarVeiculos(veiculos);
                break;
            case 5:
                localizarVeiculo(veiculos);
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