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
  int qtdProduto[11] = {5,5,5,5,5,5,5,5,5,5};

  int opt;
  float dinheiro, troco = 0, faturamentoMaximo = 0, faturamentoTotal = 0;
  int codigoEstoque, opc, qtd;
  
  cout << fixed << setprecision(2);
  while(true){

     for(int i = 0; i < 10; i++)
     {
       cout <<i+1<<" - "<< produtos[i] << " R$" << precosVenda[i] << " | " <<  " Quantidade: " << qtdProduto[i] << endl;
     }

    cout << "Escolha uma opcao ou digite a senha do modo administrador: ";
    cin >> opt;
    cout << endl;

    if(opt == 11)
    {

      for (int i = 0; i < 10; i++){
         faturamentoMaximo += qtdProduto[i] * precosVenda[i]; 
      }
      cout << "1 - Visualizar faturamento, 2 - Repor Estoque" << endl;
      cin >> opc;
      switch (opc)
      {
        case 1:
        
            cout << "=-=- Dados da máquina -=-=" << endl;
            cout << "     Faturamento atual: " << faturamentoTotal << endl;
            cout << "     Ainda pode faturar: " << faturamentoMaximo  << endl;
            cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
            cout << endl;
            break;
        case 2:
            cout << "Insira o código do produto: ";
            cin >> codigoEstoque;
            cout << "Insira a quantidade: ";
            cin >> qtd; 
            qtdProduto[codigoEstoque - 1] = qtdProduto[codigoEstoque - 1] + qtd;
            cout << endl;
            break;
      }
      faturamentoMaximo = 0;
      continue;
    }

    cout << endl; 
    cout << "Valor inserido: R$ ";
    cin >> dinheiro;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << endl; 

  
    if(dinheiro - precosVenda[opt - 1] < 0) //Verifica se o dinheiro inserido pelo usuário é suficiente para a compra.
    {
      cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << "         Valor insuficiente." << endl;
      cout << "         Valor retornado ao usuário: R$ " << dinheiro << endl;
      cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << endl;
      continue;
    }

     else if(qtdProduto[opt - 1] <= 0 && opt != 11)
     {
       cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
       cout << "         Sem unidades disponiveis" << endl;
       cout << "         Valor retornado ao usuário: R$" << dinheiro << endl;
       cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
     }
     else
     {
       cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
       cout << "            Produto retirado: " << produtos[opt - 1] << endl;
       qtdProduto[opt - 1] = qtdProduto[opt - 1] - 1;
       troco = dinheiro - precosVenda[opt - 1];
       faturamentoTotal += precosVenda[opt - 1]; //Lucro líquido da máquina//
       cout << "             Seu troco: " << troco << endl;
       cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
       cout << endl;
     }
 }
  return 0;
}