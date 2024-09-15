#include <iostream>
#include "./includes/Pedido.h"
#include "./includes/Cliente.h"
#include "./includes/Veiculo.h"
#include "./includes/GerenciadorVeiculos.h"
#include "./includes/Roterizacao.h"
#include "./includes/Arquivo.h"

int main()
{
    Arquivo *arquivo = new Arquivo();
    vector<Pedido*> *pedidos = new vector<Pedido*>();
    vector<map<string, string>*> *dados_csv = new vector<map<string, string>*>();
    dados_csv = arquivo->read_csv("dados_entregas", ','); // TODO: certas strings tem virgula na parte de dentro, ou seja o split vai quebar no meio a string e vai dar ruim
    for(map<string, string> *dado: * dados_csv) {
        // Veiculos da empresa
        Veiculo *veiculo1 = new Veiculo(1000, "2021", "123456789", "Carro", "Rio de Janeiro, Brasil", "4x4", "Trabalho", 
         "Trabalho", "ABC-1234", 450, 350, 2000, 10000, -22.9068467, -43.1728965);

        Cliente *cliente = new Cliente();
        cliente->setNome(dado->at("Nome"));
        cliente->setCpf(dado->at("CPF"));
        cliente->setEndereco(dado->at("Endereço"));
        cliente->setTelefone(dado->at("Telefone"));
        cliente->setEmail(dado->at("Email"));
        
        Pedido *pedido = new Pedido();
        pedido->setLocal_coleta(dado->at("Endereço coleta"));
        pedido->setLocal_entrega(dado->at("Endereço entrega"));
        pedido->setCliente(cliente);
        pedido->setVeiculo(veiculo1);

        pedidos->push_back(pedido);
    }

    return 0;
}