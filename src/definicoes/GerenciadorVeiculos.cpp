#include "../includes/GerenciadorVeiculos.h"
#include <cmath>

GerenciadorVeiculos::GerenciadorVeiculos()
{
   this -> veiculos = new std::list<Veiculo*>();
}

GerenciadorVeiculos::~GerenciadorVeiculos()
{
    delete(this -> veiculos);
}

void GerenciadorVeiculos::adicionarVeiculo(Veiculo *veiculo)
{
    this -> veiculos -> push_back(veiculo);
}

std::ostream& operator<<(std::ostream& os, GerenciadorVeiculos *gerenciador)
{
    os<< "\nTodos os veiculos gerenciados: \n";
    for (std::list<Veiculo*>::iterator i = gerenciador -> getVeiculosDisponiveis() -> begin(); i != gerenciador -> getVeiculosDisponiveis() -> end(); i++)
    {
        os << **i << "\n";
    }
    return os;
}

void GerenciadorVeiculos::removerVeiculo(Veiculo *veiculo)
{
    this -> veiculos -> remove(veiculo);
}

Veiculo* GerenciadorVeiculos::buscarId(int id)
{
    for(std::list<Veiculo*>::iterator i = this -> veiculos -> begin(); i != this -> veiculos -> end(); i++)
    {
        if((*i) -> getId() == id)
            return (*i);
    }
    return nullptr;
}

Veiculo *GerenciadorVeiculos::buscaPlaca(std::string placa)
{
    for(std::list<Veiculo*>::iterator i = this -> veiculos -> begin(); i != this -> veiculos -> end(); i++)
    {
        if((*i) -> getPlaca() == placa)
        {
            return *i;
        }
    }
    return nullptr;
}

Veiculo *GerenciadorVeiculos::buscarCapacidade(float capacidade)
{
    for(std::list<Veiculo*>::iterator i = this -> veiculos -> begin(); i != this -> veiculos -> end(); i++)
    {
        if((*i) -> getCapacidade_carga() >= capacidade)
        {
            return *i;
        }
    }
    return nullptr;
}
Veiculo *GerenciadorVeiculos::buscarLocalizacao(std::string localizacao)
{
    for(std::list<Veiculo*>::iterator i = this -> veiculos -> begin();i != this -> veiculos -> end(); i++)
    {
        if((*i)-> getLocalizacao() == localizacao)
        {
            return *i;
        }
    }
    return nullptr;
}
//buscar veiculo por distancia mais proxima de um ponto, e que tenha uma certa capacidade de carga
Veiculo *GerenciadorVeiculos::buscarProximidade(float latitude, float longitude, float capacidade)
{
    Veiculo *veiculo = nullptr;
    float distancia = 9999999;
    for(std::list<Veiculo*>::iterator i = this -> veiculos -> begin(); i != this -> veiculos -> end(); i++)
    {
        float distanciaAtual =sqrt(pow(((*i) -> getLatitude() - latitude), 2) + pow(((*i)-> getLongitude() - longitude), 2));
 
        if(distanciaAtual < distancia && (*i) -> getCapacidade_carga() >= capacidade)
        {
            distancia = distanciaAtual;
            veiculo = *i;
        }
    }
    return veiculo;
}
std::list<Veiculo*> *GerenciadorVeiculos::getVeiculosDisponiveis()
{
    return this -> veiculos;
}