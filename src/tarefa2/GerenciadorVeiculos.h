#ifndef GERENCIADOR_VEICULOS_H
#define GERENCIADOR_VEICULOS_H
#include "Veiculo.h"
#include <list>
#include <iostream>

class GerenciadorVeiculos
{
    private:
        std::list<Veiculo> *veiculos;

    public:
        GerenciadorVeiculos();
        ~GerenciadorVeiculos();
        void print();
        void adicionarVeiculo(Veiculo veiculo);
        void removerVeiculo(Veiculo veiculo);
        Veiculo *buscarId(int id);
        Veiculo *buscaPlaca(std::string placa);
        Veiculo *buscarLocalizacao(std::string localizacao);
        std::list<Veiculo> *getVeiculosDisponiveis();
};
#endif