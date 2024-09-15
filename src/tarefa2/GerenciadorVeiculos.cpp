#include "GerenciadorVeiculos.h"

GerenciadorVeiculos::GerenciadorVeiculos()
{
    veiculos = new std::list<Veiculo>();
}

GerenciadorVeiculos::~GerenciadorVeiculos()
{
    delete(veiculos);
}

void GerenciadorVeiculos::adicionarVeiculo(Veiculo veiculo)
{
    veiculos -> push_back(veiculo);
}

void GerenciadorVeiculos::print()
{
    for (std::list<Veiculo>::iterator i = veiculos -> begin(); i != veiculos -> end(); i++)
    {
        i -> print();
    }
}

void GerenciadorVeiculos::removerVeiculo(Veiculo veiculo)
{
    veiculos -> remove(veiculo);
}

Veiculo *GerenciadorVeiculos::buscarId(int id)
{
    for(std::list<Veiculo>::iterator i = veiculos -> begin(); i != veiculos -> end(); i++)
    {
        if(i -> getId() == id)
            return &(*i);
    }
    return NULL;
}

Veiculo *GerenciadorVeiculos::buscaPlaca(std::string placa)
{
    for(std::list<Veiculo>::iterator i = veiculos -> begin(); i != veiculos -> end(); i++)
    {
        if(i -> getPlaca() == placa)
        {
            return &(*i);
        }
    }
    return NULL;
}

Veiculo *GerenciadorVeiculos::buscarLocalizacao(std::string localizacao)
{
    for(std::list<Veiculo>::iterator i = veiculos -> begin();i != veiculos -> end(); i++)
    {
        if(i -> getLocalizacao() == localizacao)
        {
            return &(*i);
        }
    }
    return NULL;
}

std::list<Veiculo> *GerenciadorVeiculos::getVeiculosDisponiveis()
{
    return veiculos;
}

bool operator==(Veiculo veiculo1, Veiculo veiculo2)
{
    return veiculo1.getId() == veiculo2.getId();
}