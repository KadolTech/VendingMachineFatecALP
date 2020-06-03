//Jean Luca Dos Santos Silva RA: 2840482011044
//Breno Costa Zukowski Marques RA: 2840482011010

#include<iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  string produtos[10] = {"Fandangos", "M&M", "Pepsi", "Coca-Cola", "Sprite", "Twix", "Skittle", "Kinder Chocolate", "Cheetos", "Doritos"};

  float precosVenda[10] = {5.0, 1.50, 3.50, 3.50, 3.0, 2.0, 2.0, 1.0, 4.5, 6.0};

  int qtdProduto[10] = {5,5,5,5,5,5,5,5,5,5};

  double lucro = 0;
  int opt = 0;
  float dinheiro;
  
  cout << fixed << setprecision(2);
 while(true){
    cout << endl;      
    cout << "Insira o dinheiro: R$ ";
    cin >> dinheiro;
    cout << endl;

     cout << fixed << setprecision(2);
     for(int i = 0; i < 10; i++)
     {
       cout <<i+1<<" - "<< produtos[i] << " R$" << precosVenda[i] << " | " <<  " Quantidade: " << qtdProduto[i] << endl;
     }

   
     cout << "Escolha uma opcao: ";
     cin >> opt;
     cout << endl;  
      
     if(qtdProduto[opt - 1] <= 0)
     {
       cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
       cout << "         Sem unidades disponiveis" << endl;
       cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
     }
     else
     {
       cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
       cout << "            Produto retirado: " << produtos[opt - 1] << endl;
       cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
       qtdProduto[opt - 1] = qtdProduto[opt - 1] - 1;

     }
 }
  return 0;
}