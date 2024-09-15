#ifndef GERENCIADOR_VEICULOS_H
#define GERENCIADOR_VEICULOS_H
#include "Veiculo.h"
#include <list>
#include <iostream>

//Classe que gerencia os veiculos, contém apenas uma lista de veiculos e métodos para adicionar, remover e buscar veiculos.
class GerenciadorVeiculos
{
    private:
        std::list<Veiculo*> *veiculos;

    public:
        GerenciadorVeiculos();
        ~GerenciadorVeiculos();
        void adicionarVeiculo(Veiculo *veiculo);
        void removerVeiculo(Veiculo *veiculo);
        Veiculo *buscarId(int id);
        Veiculo *buscaPlaca(std::string placa);
        Veiculo *buscarLocalizacao(std::string localizacao);
        Veiculo *buscarCapacidade(float capacidade);
        Veiculo *buscarProximidade(float latitude, float longitude, float capacidade);
        std::list<Veiculo*> *getVeiculosDisponiveis();
        friend std::ostream& operator<<(std::ostream& os, GerenciadorVeiculos gerenciador);
};
#endif