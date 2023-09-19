// C++ program to initialize
// a vector like an array.
#include <iostream>
#include <vector>
using namespace std;

struct Cliente{

    string cpf;
    string nome;
    string dtNascimento;
    string cnh;
};
void Listar(vector<Cliente>& veccli){
    //for(auto it=veccli.begin();it!=veccli.end(); it++){
                for(auto& it:veccli){
                    cout<<"Nome       : "<<it.nome<<endl;
                    cout<<"CPF        : "<<it.cpf<<endl;
                    cout<<"Data Nasc. : "<<it.dtNascimento<<endl;
                    cout<<"CNH        : "<<it.cnh<<endl<<endl;
                }

}
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
int main()
{
        	vector<Cliente> vect;

	/*for (int x : vect)
		cout << x << " ";
    */
   preencheVetorCliente(vect);
   Listar(vect);
	return 0;
}
