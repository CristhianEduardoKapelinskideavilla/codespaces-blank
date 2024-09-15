#include "Veiculo.cpp"
#include "Cliente.cpp"
#include "Pedido.cpp"
#include "onibus.cpp"
#include "GerenciadorVeiculos.cpp"
#include "Roterizacao.cpp"
#include <iostream>
#include <list>

int main(void)
{
    Veiculo carro = Veiculo(500, "1991", "123456789", "Fusca", "Хатанга, RU", "4x4", "Carro", "Passeio", "ABC123", 185, 220, 445, 1500, 71.95683503660769, 102.32859790085502);
    // if(carro == carro)
    //     std::cout << carro << std::endl;

    Cliente cliente1 = Cliente("Дми́трий", "dmitri2913219@gmail.com", "Коротчаево, RU", "00 00000000", "123456789", 19);
    // if(cliente1 == cliente1)
    //     std::cout << cliente1 << std::endl;
                
    Pedido pedido1 = Pedido(cliente1, carro, "Carro", "Alegrete, RS", cliente1.getEndereco(), 1000.0, 300.0, -19.84578804521026, -43.9946677273016);
    // if(pedido1 == pedido1)
    //     std::cout << pedido1 << std::endl;
    
    Veiculo motocicleta = Veiculo();
    Pedido pedido2 = Pedido(cliente1, motocicleta, "carro", "Тикси, RU", cliente1.getEndereco(), 300, 100, 71.63916451382197, 128.85308458153048);

    Onibus onibus1 = Onibus(41, 5500, "1991", "123456789", "onibus", "Alegrete, RS", "8x4", "onibus", "trabalho","ABC321", 300, 400, 530, 4000, -29.789200620677825, -55.76846768255048);
    onibus1.setAltura(500);
    // if (onibus1 == onibus1)
    //     std::cout << onibus1 << std::endl;
   
    Onibus onibus2 = Onibus();


    GerenciadorVeiculos *gerenciador = new GerenciadorVeiculos();
    gerenciador -> adicionarVeiculo(carro);
    gerenciador -> adicionarVeiculo(onibus1);
    gerenciador -> adicionarVeiculo(onibus2);
    gerenciador -> adicionarVeiculo(motocicleta);
    gerenciador -> removerVeiculo(onibus2);
    
    Veiculo *search = gerenciador -> buscarId(12);
    // if(search)
    //     std::cout << *search << std::endl;
    // search = gerenciador -> buscaPlaca("ABC321");
    // if(search)
    //     std::cout << *search << std::endl;

    std::list<Veiculo> *veiculos = gerenciador -> getVeiculosDisponiveis();
    //std::cout << gerenciador << std::endl;

    
    Roterizacao *roterizador = new Roterizacao();
    //if(roterizador == roterizador)
    roterizador -> setPedido(&pedido2);
    roterizador -> setVeiculosDisponiveis(gerenciador);
    roterizador -> acharVeiculo();
    roterizador -> calcularDistancia();
    roterizador -> calcularTempoEntrega(80);
    std::cout << *roterizador;
    delete(gerenciador);
    return 0;
}
