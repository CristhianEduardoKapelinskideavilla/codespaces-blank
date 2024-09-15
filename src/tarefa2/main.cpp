#include "Veiculo.cpp"
#include "Cliente.cpp"
#include "Pedido.cpp"
#include "onibus.cpp"
#include "GerenciadorVeiculos.cpp"
#include <iostream>
#include <list>

int main(void)
{
    Veiculo carro = Veiculo("500kg", "1991", "123456789", "Fusca", "Alegrete, RS", "4x4", "Carro", "Passeio", "ABC123", 185, 220, 445, 1500);
    //carro.print();

    Cliente cliente1 = Cliente("João", "joao2913219@gmail.com", "Belo Horizonte, MG", "00 00000000", "123456789", 19);
    //cliente1.print();
                
    Pedido pedido1 = Pedido(cliente1, carro, "Carro", carro.getLocalizacao(), cliente1.getEndereco(), 1000.0, 300.0);
    //pedido1.print();

    //printf("\n");
    Onibus onibus1 = Onibus(41, "5500kg", "1991", "123456789", "onibus", "Alegrete, RS", "8x4", "onibus", "trabalho","ABC321", 300, 400, 530, 4000);
    //onibus1.setAltura(500);
    //onibus1.print();
    
   //printf("\n"); 
   
    Onibus onibus2 = Onibus();
    //onibus2.print();

    Veiculo motocicleta = Veiculo();

    GerenciadorVeiculos *gerenciador = new GerenciadorVeiculos();
    gerenciador -> adicionarVeiculo(carro);
    gerenciador -> adicionarVeiculo(onibus1);
    gerenciador -> adicionarVeiculo(onibus2);
    gerenciador -> adicionarVeiculo(motocicleta);

    gerenciador -> removerVeiculo(onibus2);

    Veiculo *search = gerenciador -> buscarId(12);
    if(search)
        search -> print();

    search = gerenciador -> buscaPlaca("ABC123");
    if(search)
        search -> print();

    std::list<Veiculo> *veiculos = gerenciador -> getVeiculosDisponiveis();

    std::cout << "\n\n\nTodos os veiculos gerenciados: \n" << std::endl;
    gerenciador -> print();

    delete(gerenciador);

    return 0;
}
