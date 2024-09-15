#include "Roterizacao.h"
#include <cmath>

Roterizacao::Roterizacao()
{
    this -> pedido = new Pedido;
    this -> pedido = NULL;
    this -> distancia = 0;
    this -> tempoEntrega = 0;
    this -> veiculosDisponiveis = new GerenciadorVeiculos;
    this -> veiculosDisponiveis = NULL;
}
Roterizacao::Roterizacao(Pedido *pedido, double distancia, float tempoEntrega, GerenciadorVeiculos *veiculosDisponiveis)
{
    this -> pedido = new Pedido;
    this -> pedido = pedido;
    this -> distancia = distancia;
    this -> tempoEntrega = tempoEntrega;
    this -> veiculosDisponiveis = new GerenciadorVeiculos;
    this -> veiculosDisponiveis = veiculosDisponiveis;
}
Roterizacao::~Roterizacao()
{
    delete(this -> pedido);
    delete(this -> veiculosDisponiveis);
}
int Roterizacao::setPedido(Pedido *pedido)
{
    this -> pedido = pedido;
    return 1;
}
int Roterizacao::setDistancia(double distancia)
{
    this -> distancia = distancia;
    return 1;
}
int Roterizacao::setTempoEntrega(float tempoEntrega)
{
    this -> tempoEntrega = tempoEntrega;
    return 1;
}
int Roterizacao::setVeiculosDisponiveis(GerenciadorVeiculos *veiculosDisponiveis)
{
    this -> veiculosDisponiveis = veiculosDisponiveis;
    return 1;
}

Pedido *Roterizacao::getPedido()
{
    return this -> pedido;
}
double Roterizacao::getDistancia()
{
    return this -> distancia;
}
float Roterizacao::getTempoEntrega()
{
    return this -> tempoEntrega;
}
GerenciadorVeiculos *Roterizacao::getVeiculosDisponiveis()
{
    return this -> veiculosDisponiveis;
}

double Roterizacao::calcularDistancia()
{
    if(this -> pedido == NULL || 
    (this -> pedido -> getVeiculo().getLatitude() == 0 && this -> pedido -> getVeiculo().getLongitude() == 0) || 
    (this -> pedido -> getLatitude() == 0 && this -> pedido -> getLongitude() == 0))
    {
        perror("Latitude e longitude de veiculo invalida");
        return 0;
    }
    double raioTerra = 6371.0;
    double latitude1Rad = rad(this -> pedido -> getVeiculo().getLatitude());
    double longitude1Rad = rad(this -> pedido -> getVeiculo().getLongitude());
    double latitude2Rad = rad(this -> pedido -> getLatitude());
    double longitude2Rad = rad(this -> pedido -> getLongitude());
    double distancia = 2 * raioTerra * asin(sqrt( pow(sin((latitude2Rad - latitude1Rad)/2),2) + cos(latitude1Rad) * cos(latitude2Rad) * pow(sin((longitude2Rad - longitude1Rad)/2),2)));
    this -> distancia = distancia;
    return distancia;
}

double Roterizacao::rad(double graus)
{
    return graus * (M_PI/180);
}   

Veiculo *Roterizacao::acharVeiculo()
{
    if(this -> veiculosDisponiveis == NULL || this -> pedido == NULL)
    {
        perror("Veiculos disponiveis ou pedido invalido");
        return NULL;
    }
    Veiculo* veiculo = this -> veiculosDisponiveis -> buscarCapacidade(this -> pedido -> getPeso_carga());
    if(veiculo != NULL)
    {
        this -> pedido -> setVeiculo(*veiculo);
        return veiculo;
    }
    return NULL;
}

float Roterizacao::calcularTempoEntrega(float kmh)
{
    if(this -> distancia <= 0)
    {
        perror("Distancia invalida");
        return 0;
    }
    float tempo = this -> distancia / kmh;
    this -> tempoEntrega = tempo;
    return tempo;
}
bool Roterizacao::operator==(const Roterizacao& outro) const
{
    return this -> pedido == outro.pedido;
}
std::ostream& operator<<(std::ostream& os, Roterizacao& roterizacao)
{
    os << "Pedido de: " << roterizacao.getPedido() -> getCliente().getNome() << "\n"
        << "Local de origem: " << roterizacao.getPedido() -> getLocal_coleta() << "\n"
        << "Local de destino: " << roterizacao.getPedido() -> getLocal_entrega() << "\n"
        << "Local do Veiculo: " << roterizacao.getPedido() -> getVeiculo().getLocalizacao() << "\n"
        << "Distancia entre o veiculo e o local de entrega: " << roterizacao.getDistancia() << "km\n"
        << "Tempo estimado de entrega: " << roterizacao.getTempoEntrega() << " horas de viagem\n";
    return os;
}