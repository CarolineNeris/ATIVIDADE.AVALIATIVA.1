#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
//#include "teste.h"

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
    string data_hora_retirada;  // prevista
    string data_hora_entrega;   // prevista
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
    Ocorrencia ocorrencia; // Atributo do tipo Ocorrencia QUARTA PARTE
};
void preencheVetorCliente(vector<Cliente>& vect){

    vect.push_back(Cliente());
    vect[0].cpf="123.456.789-10";
    vect[0].nome="Adriano";
    vect[0].dtnascimento="12/10/1982";
    vect[0].cnh="11111111";
    
    cout<<"preenche cnh vec: "<<&vect[0]<<endl;
    cout<<"preenche cnh veccnh: "<<&vect[0].cnh<<endl;
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
    return;
}

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

void preencheVetorLocacao(vector<Cliente>& veccli, vector<Veiculo>& vecveic, vector<Locacao>& vecloc){

    Locacao strloc;
    Cliente strcli;
    //Cliente *ptrcli=&strcli;

    vecloc.push_back(strloc);
    vecloc[0].cliente=&veccli[0];
    vecloc[0].veiculo=&vecveic[0];
    vecloc[0].realizada="n"; 
    vecloc[0].dataHoraRetiradaReal="10/10/2023 17:00";
    vecloc[0].dataHoraEntregaReal="11/10/2023 17:01";

    vecloc.push_back(strloc);
    vecloc[1].cliente=&veccli[0];
    vecloc[1].veiculo=&vecveic[0];
    vecloc[1].realizada="n"; 
    vecloc[1].dataHoraRetiradaReal="11/10/2023 16:00";
    vecloc[1].dataHoraEntregaReal="12/10/2023 16:01";
    
    vecloc.push_back(strloc);
    vecloc[2].cliente=&veccli[1];
    vecloc[2].veiculo=&vecveic[1];
    vecloc[2].realizada="s"; 
    vecloc[2].dataHoraRetiradaReal="12/09/2023 14:00";
    vecloc[2].dataHoraEntregaReal="13/10/2023 14:01";
    
    vecloc.push_back(strloc);
    vecloc[3].cliente=&veccli[2];
    vecloc[3].veiculo=&vecveic[2];
    vecloc[3].realizada="n"; 
    vecloc[3].dataHoraRetiradaReal="10/10/2023 12:00";
    vecloc[3].dataHoraEntregaReal="15/10/2023 12:01";
    
    vecloc.push_back(strloc);
    vecloc[4].cliente=&veccli[2];
    vecloc[4].veiculo=&vecveic[2];
    vecloc[4].realizada="n"; 
    vecloc[4].dataHoraRetiradaReal="01/10/2023 13:00";
    vecloc[4].dataHoraEntregaReal="11/10/2023 13:01";
    
    return;
}

void ListarCliente(vector<Cliente>& veccli){
    //for(auto it=veccli.begin();it!=veccli.end(); it++){
        cout<<"Nome\tCPF\tData Nasc.\tCNH"<<endl;
                for(const auto& it:veccli){
                    cout<<it.nome<<"\t";
                    cout<<it.cpf<<"\t";
                    cout<<it.dtnascimento<<"\t";
                    cout<<it.cnh<<endl<<endl;
                }
    return;
}

void ListarVeiculos(vector<Veiculo>& veiculos) {
    cout<<"Renavam\tPlaca\tD.H.Retirada\tD.H.Entrega\tLoja Retirada"<<endl;
    for (const auto& veiculo : veiculos) {
        cout<< veiculo.renavam <<"\t";
        cout<< veiculo.placadoveiculo<<"\t";
        cout<< veiculo.data_hora_retirada<<"\t";
        cout<< veiculo.data_hora_entrega<<"\t";
        cout<< veiculo.loja_retirada<<endl<<endl;
    }
    return;
}
void listarLocacoes(vector<Locacao>& locacoes){//, vector<Veiculo>&veiculos, vector<Cliente>&clientes) {
    for (const auto& loc : locacoes) {
        cout << "CPF               : " << loc.cliente->cpf <<endl;
        cout << "Nome              : " << loc.cliente->nome<<endl;
        cout << "Placa             : " << loc.veiculo->placadoveiculo <<endl;
        cout << "Retirada Realizada: " << loc.realizada <<endl; 
        cout << "Data/Hora Retirada: " << loc.dataHoraRetiradaReal <<endl;
        cout << "Data/Hora Entrega : " << loc.dataHoraEntregaReal << endl<<endl;
    }
}

void listarOcorrenciasPorCliente(vector<Locacao>& locacoes) {
    string cpf;
    cout << "Digite o cpf do cliente: "<<endl;
    cin >> cpf;

    for (const auto& loc : locacoes) {
        if (loc.cliente->cpf == cpf && !loc.ocorrencia.descricao.empty()) {
            cout << "Descrição: " << loc.ocorrencia.descricao << ", Data/Hora: " << loc.ocorrencia.dataHora << ", Apólice: " << loc.ocorrencia.numeroApolice << "\n";
        }
    }
}

void listarOcorrenciasPorVeiculo(vector<Locacao>& locacoes) {
    string placa;
    cout << "Digite a placa do veículo: "<<endl;
    cin >> placa;

    for (const auto& loc : locacoes) {
        if (loc.veiculo->placadoveiculo == placa && !loc.ocorrencia.descricao.empty()) {
            cout << "Descrição: " << loc.ocorrencia.descricao << ", Data/Hora: " << loc.ocorrencia.dataHora << ", Apólice: " << loc.ocorrencia.numeroApolice << "."<<endl;
        }
    }
}




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

int main(){

    vector<Veiculo> vecveic;
    vector<Cliente> veccli;
    vector<Locacao> vecloc;

    preencheVetorCliente(veccli);
    preencheVetorVeiculos(vecveic);
    preencheVetorLocacao(veccli,vecveic,vecloc);

    ListarCliente(veccli);
    ListarVeiculos(vecveic);
    //incluirLocacao(vecloc,veccli,vecveic);
    //ListarCliente(veccli);
    //ListarVeiculos(vecveic);
    listarLocacoes(vecloc);//,vecveic,veccli);


    return 0;
}
