#include <iostream>
#include <vector>
using namespace std;

struct Cliente{

    string cpf;
    string nome;
    string dtNascimento;
    string cnh;
};

struct Veiculo{
    string renavam;
    string placadoveiculo;
    string data_hora_retirada;
    string data_hora_entrega;
    string loja_retirada;
};

struct Locacao{
    Cliente* cliente;
    Veiculo* veiculo;
    bool realizada;
    string dataHoraRetiradaReal;
    string dataHoraEntregaReal;
};
void preencheVetorCliente(vector<Cliente>& vect){

    vect.push_back(Cliente());
    vect[0].cpf="123.456.789-10";
    vect[0].nome="Adriano";
    vect[0].dtNascimento="12/10/1982";
    vect[0].cnh="11111111";
    
    vect.push_back(Cliente());
    vect[1].cpf="234.567.890-12";
    vect[1].nome="Bruna";
    vect[1].dtNascimento="22/11/1983";
    vect[1].cnh="22222222";

    vect.push_back(Cliente());
    vect[2].cpf="345.678.901-23";
    vect[2].nome="Carla Maria";
    vect[2].dtNascimento="02/02/1972";
    vect[2].cnh="33333333";

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

void preencheVetorLocacao(vector<Locacao>& vect){

    vect.push_back(Locacao());
//    vect[0].cliente->cnh="12";
  //  vect[0].veiculo->renavam="23";
    vect[0].realizada=1;
    //vect[0].dataHoraEntregaReal="AAA1A11";
    vect[0].dataHoraEntregaReal="19/09/2023 12:00";
    vect[0].dataHoraRetiradaReal="21/09/2023 12:01";
    //vect[0].;
}
void Listar(vector<Locacao>& vecloc){
    //for(auto it=veccli.begin();it!=veccli.end(); it++){
                for(auto& it:vecloc){
                    cout<<"Realizada           : "<<it.realizada<<endl;
                    //cout<<"DataHoraRetiradaReal: "<<it.dataHoraEntregaReal<<endl;
                    cout<<"D.H.Retirada Real   : "<<it.dataHoraRetiradaReal<<endl;
                    cout<<"D.H.Entrega Real    : "<<it.dataHoraEntregaReal<<endl;
                    //cout<<"Loja          : "<<it.loja_retirada<<endl<<endl;
                }

}


int main()
{
        	vector<Locacao> locacaos;

	/*for (int x : vect)
		cout << x << " ";
    */
   preencheVetorLocacao(locacaos);
   Listar(locacaos);
	return 0;
}
