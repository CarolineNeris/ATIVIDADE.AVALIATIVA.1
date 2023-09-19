// C++ program to initialize
// a vector like an array.
#include <iostream>
#include <vector>
using namespace std;

struct Veiculo{
    string renavam;
    string placadoveiculo;
    string data_hora_retirada;
    string data_hora_entrega;
    string loja_retirada;
};
void Listar(vector<Veiculo>& vecveic){
    //for(auto it=veccli.begin();it!=veccli.end(); it++){
                for(auto& it:vecveic){
                    cout<<"Renavam       : "<<it.renavam<<endl;
                    cout<<"Placa         : "<<it.placadoveiculo<<endl;
                    cout<<"D.H.Retirada  : "<<it.data_hora_retirada<<endl;
                    cout<<"D.H.Entrega   : "<<it.data_hora_entrega<<endl;
                    cout<<"Loja          : "<<it.loja_retirada<<endl<<endl;
                }

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
int main()
{
        	vector<Veiculo> veiculos;

	/*for (int x : vect)
		cout << x << " ";
    */
   preencheVetorVeiculos(veiculos);
   Listar(veiculos);
	return 0;
}
