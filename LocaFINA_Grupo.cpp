#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//PRIMEIRA PARTE

using namespace std;

struct Cliente {

    string cpf;
    string nome;
    string dtnascimento;
    string cnh;
};

struct Veiculo{

    string renavam;
    string placadoveiculo;
    string data_hora_retirada;  
    string data_hora_entrega;   
    string loja_retirada;

};

struct Ocorrencia {
    string descricao;
    string dataHora;
    string numeroApolice;
};

struct Locacao {
    Cliente* cliente;
    Veiculo* veiculo;
    string realizada;  // 's' para Sim ou 'n' para não
    string dataHoraRetiradaReal;
    string dataHoraEntregaReal;
    Ocorrencia ocorrencia; 
};

void Incluir(vector<Cliente>& clientes) {
    Cliente cliente;
    cout << "Digite o CPF do cliente: ";
    cin >> cliente.cpf;
    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, cliente.nome);
    cout << "Digite a data de nascimento (DD/MM/AAAA): ";
    cin >> cliente.dtnascimento;
    cout << "Digite a CNH: ";
    cin >> cliente.cnh;
    clientes.push_back(cliente);
    cout << "O cliente foi incluído com sucesso!"<< endl<<endl;
}

void Excluir(vector<Cliente>& clientes) {
    string cpf;
    cout << "Digite o CPF do cliente a ser excluído: "<< endl;
    cin >> cpf;

    auto it = remove_if(clientes.begin(), clientes.end(), [&cpf](const Cliente& c) { return c.cpf == cpf; });

    if (it != clientes.end()) {
        clientes.erase(it, clientes.end());
        cout << "Cliente excluído com sucesso. " << endl;
    } else {
        cout << "Cliente não encontrado. "<< endl;
    }
}

void Alterar(vector<Cliente>& clientes) {
    string cpf;
    cout << "Digite o CPF do cliente que deseja alterar: " << endl;
    cin >> cpf;

    for (auto& cliente : clientes) {
        if (cliente.cpf == cpf) {
            cout << "Cliente encontrado. "<<endl;
            cout << "Nome atual: " << cliente.nome << endl <<"Deseja alterar? ('s'para sim ou 'n' para não) ";
            char resposta;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite o novo nome: ";
                cin.ignore();
                getline(cin, cliente.nome);
            }

            cout << "Data de nascimento atual: " << cliente.dtnascimento <<endl<< "Deseja alterar? ('s'para sim ou 'n' para não) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova data de nascimento (DD/MM/AAAA): ";
                cin >> cliente.dtnascimento;
            }

            cout << "CNH atual: "<< cliente.cnh <<endl<<"Deseja alterar? ('s'para sim ou 'n' para não) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova CNH: ";
                cin >> cliente.cnh;
            }

            return;
        }
    }
    cout << "Cliente não encontrado. "<< endl;
}

void Listar(vector<Cliente>& clientes) {
    for (const auto& cliente : clientes) {
        cout << "CPF: " << cliente.cpf << endl<<"Nome: " << cliente.nome << endl <<"Data de Nascimento: " << cliente.dtnascimento << endl<<"CNH: " << cliente.cnh <<endl<<endl;
    }
}

void Localizar(vector<Cliente>& clientes) {
    string cpf;
    cout << "Digite o CPF do cliente que deseja localizar: "<< endl;
    cin >> cpf;

    for (const auto& cliente : clientes) {
        if (cliente.cpf == cpf) {
            cout << "CPF: " << cliente.cpf << endl<<"Nome: " << cliente.nome << endl<<"Data de Nascimento: " << cliente.dtnascimento << endl<<"CNH: " << cliente.cnh << endl<<endl;
            return;
        }
    }
    cout << "Cliente não encontrado. "<<endl;
}

//BANCO DE DADDOS CLIENTE

void preencheVetorCliente(vector<Cliente>& vect){

    vect.push_back(Cliente());
    vect[0].cpf="123.456.789-10";
    vect[0].nome="Adriano";
    vect[0].dtnascimento="12/10/1982";
    vect[0].cnh="11111111";
    
    vect.push_back(Cliente());
    vect[1].cpf="234.567.890-12";
    vect[1].nome="Bruna";
    vect[1].dtnascimento="22/11/1983";
    vect[1].cnh="22222222";

    vect.push_back(Cliente());
    vect[2].cpf="345.678.901-23";
    vect[2].nome="Carla Maria";
    vect[2].dtnascimento="02/02/1972";
    vect[2].cnh="33333333";

}

void menuCliente (vector<Cliente>& clientes) {
int menu;

do {
cout << "1.Incluir"<<endl<<"2.Excluir"<<endl<<"3.Alterar"<<endl<<"4.Listar"<<endl<<"5.Localizar"<<endl<<"0.Sair"<< endl<< endl;
cout << "Digite a opção desejada: " << endl;
cin >> menu;

switch(menu) {
  case 1:        // Incluir
    preencheVetorCliente(clientes);
    Incluir(clientes);
    break;
  case 2:         // Excluir
    Excluir(clientes);
    break;
  case 3:        // Alterar (Apenas por CPF)
    Alterar (clientes);
    break;
  case 4:         // Listar
    Listar (clientes);
    break;
  case 5:        // Localizar (por CPF)
    Localizar (clientes);
    break;
  case 0:        // Sair)
    cout << "Você saiu."<<endl;
    break;
  default:
    cout << "Opção inválida." << endl<<endl;
}
}while (menu != 0);
}

//SEGUNDA PARTE

void IncluirVeiculo(vector<Veiculo>& veiculos) {
    Veiculo veiculo;
    cout << "Digite o Renavam: "<<endl;
    cin >> veiculo.renavam;
    cout << "Digite a placa do veículo: "<<endl;
    cin.ignore();
    getline(cin, veiculo.placadoveiculo);
    cout << "Digite a data e hora de retirada (DD/MM/AAAA HH:MM): "<<endl;
    getline(cin, veiculo.data_hora_retirada);
    cout << "Digite a data e hora de entrega (DD/MM/AAAA HH:MM): "<<endl;
    getline(cin, veiculo.data_hora_entrega);
    cout << "Digite a loja de retirada: "<<endl;
    getline(cin, veiculo.loja_retirada);

    veiculos.push_back(veiculo);
    cout << "Veículo incluído com sucesso. " << endl;
}

void ExcluirVeiculo(vector<Veiculo>& veiculos) {
     string placa;
    int cont=0;
    bool flag=false;

    cout << "Digite a placa do veículo que deseja excluir: "<<endl;
    cin >> placa;

    for(auto& veic: veiculos){
        if(placa == veic.placadoveiculo){
           flag=true;
           break;
        }
        cont++;
    }
    
    if(flag){
        veiculos.erase(veiculos.begin()+ cont); 
        cout<<"Veículo excluido!"<<endl<<endl;
    } else {
        cout << "Veículo não encontrado. " << endl;
    }

}

void AlterarVeiculo(vector<Veiculo>& veiculos) {
    string placa;
    cout << "Digite a placa do veículo que deseja alterar: "<<endl;
    cin >> placa;

    for (auto& veiculo : veiculos) {
        if (veiculo.placadoveiculo == placa) {
            cout << "Veículo encontrado." << endl;
            cout << "Renavam atual: " << veiculo.renavam << endl<<"Deseja alterar? ('s'para sim ou 'n' para não) "<<endl;
            char resposta;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite o novo Renavam: "<<endl;
                cin >> veiculo.renavam;
            }

            cout << "Placa atual: " << veiculo.placadoveiculo <<endl<< "Deseja alterar? ('s'para sim ou 'n' para não) "<<endl;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova placa: "<<endl;
                cin.ignore();
                getline(cin, veiculo.placadoveiculo);
            }

            cout << "Data e hora de retirada atual: " << veiculo.data_hora_retirada << endl<< "Deseja alterar? ('s'para sim ou 'n' para não) "<< endl;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova data e hora de retirada (DD/MM/AAAA HH:MM): "<<endl;
                cin.ignore();
                getline(cin, veiculo.data_hora_retirada);
            }

            cout << "Data e hora de entrega atual: " << veiculo.data_hora_entrega << endl<<"Deseja alterar? ('s'para sim ou 'n' para não) "<<endl;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova data e hora de entrega (DD/MM/AAAA HH:MM): "<<endl;
                cin.ignore();
                getline(cin, veiculo.data_hora_entrega);
            }

            cout << "Loja de retirada atual: " << veiculo.loja_retirada <<endl<< "Deseja alterar? ('s'para sim ou 'n' para não) "<<endl;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova loja de retirada: "<<endl;
                cin.ignore();
                getline(cin, veiculo.loja_retirada);
            }

            return;
        }
    }
    cout << "Veículo não encontrado!" << endl;
}

void ListarVeiculos(vector<Veiculo>& veiculos) {
    for (const auto& veiculo : veiculos) {
        cout << "Renavam: " << veiculo.renavam << endl<<"Placa: " << veiculo.placadoveiculo <<endl<< "Data e hora de retirada: " << veiculo.data_hora_retirada <<endl<< "Data e hora de entrega: " << veiculo.data_hora_entrega << endl<<"Loja de retirada: " << veiculo.loja_retirada << "."<<endl<<endl;
    }
}

void LocalizarVeiculo(vector<Veiculo>& veiculos) {
    string placa;
    cout << "Digite a placa do veículo que deseja localizar: "<<endl;
    cin >> placa;

    for (const auto& veiculo : veiculos) {
        if (veiculo.placadoveiculo == placa) {
            cout << "Renavam: " << veiculo.renavam << endl<<"Placa: " << veiculo.placadoveiculo << endl<<"Data e hora de retirada: " << veiculo.data_hora_retirada << endl<<"Data e hora de entrega: " << veiculo.data_hora_entrega <<endl<< "Loja de retirada: " << veiculo.loja_retirada << "."<<endl<<endl;
            return;
        }
    }
    cout << "Veículo não encontrado!" << endl;
}

//BANCO DE DADOS VEICULOS 

void preencheVetorVeiculos(vector<Veiculo>& vect){

    vect.push_back(Veiculo());
    vect[0].renavam="12121212";
    vect[0].placadoveiculo="AAA1A11";
    vect[0].data_hora_retirada="19/09/2023 12:00";
    vect[0].data_hora_entrega="21/09/2023 12:01";
    vect[0].loja_retirada="aeroporto";
    
    vect.push_back(Veiculo());
    vect[1].renavam="23232323";
    vect[1].placadoveiculo="BBB2B22";
    vect[1].data_hora_retirada="22/10/2023 13:00";
    vect[1].data_hora_entrega="25/10/2023 15:01";
    vect[1].loja_retirada="centro";
    
    vect.push_back(Veiculo());
    vect[2].renavam="34343434";
    vect[2].placadoveiculo="CCC3C33";
    vect[2].data_hora_retirada="23/10/2023 15:00";
    vect[2].data_hora_entrega="24/10/2023 11:01";
    vect[2].loja_retirada="sapetinga";

    vect.push_back(Veiculo());
    vect[3].renavam="45454545";
    vect[3].placadoveiculo="DDD4D44";
    vect[3].data_hora_retirada="23/09/2023 16:00";
    vect[3].data_hora_entrega="22/10/2023 17:01";
    vect[3].loja_retirada="sapetinga";

    
}

void menuVeiculos(vector<Veiculo>& veiculos) {
    int opcao;

    do {
        cout << "Menu de Veículos" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar" << endl;
        cout << "0. Sair" << endl;
        cout << "Digite uma opção: "<<endl;
        cin >> opcao;

        switch (opcao) {
        case 1:
            preencheVetorVeiculos(veiculos);
            IncluirVeiculo(veiculos);
            break;
        case 2:
            ExcluirVeiculo(veiculos);
            break;
        case 3:
            AlterarVeiculo(veiculos);
            break;
        case 4:
            ListarVeiculos(veiculos);
            break;
        case 5:
            LocalizarVeiculo(veiculos);
            break;
        case 0:
            cout << "Encerrando..." << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
            break;
        }

    } while (opcao != 0);
}

//TERCEIRA PARTE (EM GRUPO)

//Função para inlcuir Locação


void incluirLocacao(vector<Locacao>& locacoes, vector<Cliente>& clientes, vector<Veiculo>& veiculos) {
    string cnh, placa;

    cout << "Digite o CNH do cliente: "<<endl;
    cin >> cnh;

    // Verificar se o cliente existe:
    Cliente* clientePtr = nullptr;
    for (auto& c : clientes) {
        if (c.cnh == cnh) {
            clientePtr = &c;
            break;
        }
    }

    if (!clientePtr) {
        cout << "Cliente não encontrado." <<endl;
        return;
    }

    cout << "Digite a placa do veículo: ";
    cin >> placa;

    // Verificar se o veículo existe:
    Veiculo* veiculoPtr = nullptr;
    for (auto& v : veiculos) {
        if (v.placadoveiculo == placa) {
            veiculoPtr = &v;
            break;
        }
    }

    if (!veiculoPtr) {
        cout << "Veículo não encontrado!"<<endl;
        return;
    }

    Locacao novaLocacao;
    novaLocacao.cliente = clientePtr;
    novaLocacao.veiculo = veiculoPtr;

    cout << "Digite a data e hora real de retirada (DD/MM/AAAA HH:MM): ";
    cin.ignore();
    getline(cin, novaLocacao.dataHoraRetiradaReal);
    cout << "Retirada já realizada? ('s' para Sim ou 'n' para Não): ";
    cin >> novaLocacao.realizada;

    locacoes.push_back(novaLocacao);
    cout << "Locação registrada com sucesso!"<<endl;
}


//Função para excluir Locação

    string placa, cpf;

    cout << "Digite a placa do veículo: ";
    cin >> placa;

    cout << "Locações associadas a este veículo: "<<endl;
    for (const auto& loc : locacoes) {
        if (loc.veiculo->placadoveiculo == placa) {
            cout << "CPF: " << loc.cliente->cpf << ", Nome: " << loc.cliente->nome <<endl;
        }
    }

    cout << "Digite o CPF do cliente que deseja excluir a locação: ";
    cin >> cpf;

    auto it = remove_if(locacoes.begin(), locacoes.end(), [&placa, &cpf](const Locacao& loc) {
        return loc.veiculo->placadoveiculo == placa && loc.cliente->cpf == cpf;
    });

    if (it != locacoes.end()) {
        locacoes.erase(it, locacoes.end());
        cout << "Locação excluída com sucesso!"<<endl;
    } else {
        cout << "Locação não encontrada!"<<endl;
    }
}

//Função para alterar Locação

void alterarLocacao(vector<Locacao>& locacoes, vector<Veiculo>&veiculos, vector<Cliente>&clientes) {
    string placa, cpf;

    cout << "Digite a placa do veículo: ";
    cin >> placa;

    cout << "Locações associadas a este veículo: "<<endl;
    for (const auto& loc : locacoes) {
        if (loc.veiculo->placadoveiculo == placa) {
            cout << "CPF: " << loc.cliente->cpf << ", Nome: " << loc.cliente->nome << endl;
        }
    }

    cout << "Digite o CPF do cliente que deseja alterar a locação: ";
    cin >> cpf;

    for (auto& loc : locacoes) {
        if (loc.veiculo->placadoveiculo == placa && loc.cliente->cpf == cpf) {
            cout << "Digite a data e hora real de entrega (DD/MM/AAAA HH:MM): ";
            cin.ignore();
            getline(cin, loc.dataHoraEntregaReal);
            cout << "Locação alterada com sucesso!"<<endl;
            return;
        }
    }
    cout << "Locação não encontrada!"<<endl;
}


//Função para listar Locação

//Função Menu Locação


//QUARTA E QUINTA PARTE


//Função incluir ocorrência

void incluirOcorrencia(vector<Locacao>& locacoes, vector<Cliente>& clientes, vector<Veiculo>&veiculos) {
    string cpf, placa;
    cout << "Digite o cpf do cliente: "<<endl;
    cin >> cpf;
    cout << "Digite a placa do veículo: "<<endl;
    cin >> placa;

    for (auto& loc : locacoes) {
        if (loc.cliente->cpf == cpf && loc.veiculo->placadoveiculo == placa) {
            cout << "Digite a descrição da ocorrência: "<<endl;
            cin.ignore();
            getline(cin, loc.ocorrencia.descricao);
            cout << "Digite a data e hora da ocorrência (DD/MM/AAAA HH:MM): "<<endl;
            getline(cin, loc.ocorrencia.dataHora);
            cout << "Digite o número da apólice: "<<endl;
            cin >> loc.ocorrencia.numeroApolice;
            cout << "Ocorrência registrada com sucesso!"<<endl;
            return;
        }
    }
    cout << "Locação não encontrada!"<<endl;
}


//Função para excluir ocorrência

void excluirOcorrencia(vector<Locacao>& locacoes) {
    string cpf, placa;
    cout << "Digite o cpf do cliente: "<<endl;
    cin >> cpf;
    cout << "Digite a placa do veículo: "<<endl;
    cin >> placa;

    for (auto& loc : locacoes) {
        if (loc.cliente->cpf == cpf && loc.veiculo->placadoveiculo == placa) {
            loc.ocorrencia = Ocorrencia();  // Resetar a ocorrência para um estado vazio
            cout << "Ocorrência excluída com sucesso!"<<endl;
            return;
        }
    }
    cout << "Ocorrência ou locação não encontrada!"<< endl;
}

//Função para alterar ocorrência

void alterarOcorrencia(vector<Locacao>& locacoes) {
    string cpf, placa;
    cout << "Digite o cpf do cliente: "<<endl;
    cin >> cpf;
    cout << "Digite a placa do veículo: "<<endl;
    cin >> placa;

    for (auto& loc : locacoes) {
        if (loc.cliente->cpf == cpf && loc.veiculo->placadoveiculo == placa) {
            cout << "Descrição atual da ocorrência: " << loc.ocorrencia.descricao <<endl<< "Deseja alterar? ('s' para Sim ou 'n' para Não) "<< endl;
            char resposta;
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova descrição da ocorrência: ";
                cin.ignore();
                getline(cin, loc.ocorrencia.descricao);
            }

            cout << "Data e hora atual da ocorrência: " << loc.ocorrencia.dataHora <<endl<< "Deseja alterar? ('s' para Sim ou 'n' para Não) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite a nova data e hora da ocorrência (DD/MM/AAAA HH:MM): ";
                cin.ignore();
                getline(cin, loc.ocorrencia.dataHora);
            }

            cout << "Número da apólice atual: " << loc.ocorrencia.numeroApolice <<endl<< "Deseja alterar? ('s' para Sim ou 'n' para Não) ";
            cin >> resposta;
            if (resposta == 's') {
                cout << "Digite o novo número da apólice: ";
                cin >> loc.ocorrencia.numeroApolice;
            }

            cout << "Ocorrência alterada com sucesso!"<<endl;
            return;
        }
    }
    cout << "Ocorrência ou locação não encontrada!"<<endl;
}

//Função para listar ocorrência

//Função Menu ocorrência

int main() {
    int opcao;

    vector<Cliente> clientes;
    vector<Veiculo> veiculos;
    do {
        system("clear");
        cout << "LocaFINA S/A" << endl;
        cout << "1. Gestão de Clientes." << endl;
        cout << "2. Gestão de Veículos." << endl;
        cout << "0. Sair." << endl;
        cout << "Escolha uma das opções :" << endl;;
        cin >> opcao;

        switch (opcao) {
        case 1:
            menuCliente(clientes);
            break;
        case 2:
            menuVeiculos(veiculos);
            break;
        case 0:
            cout << "Encerrando o programa..." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }

    } while (opcao != 0); 

    return 0;
}
