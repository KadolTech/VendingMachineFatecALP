//Jean Luca Dos Santos Silva RA: 
//Breno Costa Zukowski Marques RA: 

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
  float dinheiro, troco = 0, faturamentoMaximo = 0, faturamentoTotal = 0,precoProduto;
  int codigoEstoque, opc, qtd;
  int senha = 11;
  int pos;
  string nomeProduto;
  
  cout << fixed << setprecision(2);
  while(true){

     for(int i = 0; i < 10; i++)
     {
       cout <<i+1<<" - "<< produtos[i] << " R$" << precosVenda[i] << " | " <<  " Quantidade: " << qtdProduto[i] << endl;
     }

    cout << "Escolha uma opcao ou digite a senha do modo administrador: ";
    cin >> opt;
    cout << endl;

    if(opt == senha)
    {

      for (int i = 0; i < 10; i++){
         faturamentoMaximo += qtdProduto[i] * precosVenda[i]; 
      }
      cout << "1 - Visualizar faturamento, 2 - Repor Estoque, 3 - Trocar senha, 4 - adicionar novo produto" << endl;
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
            while((qtd + qtdProduto[codigoEstoque - 1]) > 10)
            {
              cout << "Nao eh possivel adiconar mais de 10 produtos na maquina" << endl;
              cout << "Insira uma nova quantidade: ";
              cin >> qtd;
            }
            qtdProduto[codigoEstoque -1] += qtd;
            cout << endl;
            break;
        case 3:
          cout << "Insira a nova senha: ";
          cin >> senha;
          cout << "Senha alterada com sucesso!" << endl;
          cout << endl;
        case 4:
          cout << "Insira a posicao na maquina para adicionar o novo produto: ";
          cin >> pos; //posicao do produto
          while(pos > 10)
          {
            cout << "Nao eh possivel cadastrar mais que 10 produtos!";
            cout << "Insira uma nova posicao: ";
            cin >> pos;
          }
          cout << "Insira o nome do novo produto: ";
          cin >> nomeProduto;
          cout << "Informe o preco do novo produto: R$";
          cin >> precoProduto;
          cout << "Insira a quantidade: ";
          cin >> qtd;
          while(qtd > 10)
          {
            cout << "Nao eh possivel adicionar mais de 10 unidades" << endl;
            cout << "Insira uma nova quantidade: ";
            cin >> qtd;
          }
          produtos[pos-1] = nomeProduto;
          qtdProduto[pos-1] = qtd;
          precosVenda[pos-1] = precoProduto;
          cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
          cout << "Novo produto cadastrado com sucesso!" << endl;
          cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
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
