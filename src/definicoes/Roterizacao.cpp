#include "../includes/Roterizacao.h"
#include <cmath>

GerenciadorVeiculos * Roterizacao::veiculosDisponiveis = NULL;

Roterizacao::Roterizacao()
{
    this -> pedido = new Pedido;
    this -> pedido = NULL;
    this -> distanciaVeiculoColeta = 0;
    this -> distanciaColetaEntrega = 0;
    this -> distanciaTotal = 0;
    this -> tempoEntrega = 0;
}
Roterizacao::Roterizacao(Pedido *pedido, float distanciaVeiculoColeta, float distanciaColetaEntrega, float distanciaTotal, float tempoEntrega)
{
    this -> pedido = new Pedido;
    this -> pedido = pedido;
    this -> distanciaVeiculoColeta = distanciaVeiculoColeta;
    this -> distanciaColetaEntrega = distanciaColetaEntrega;
    this -> distanciaTotal = distanciaTotal;
    this -> tempoEntrega = tempoEntrega;
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
int Roterizacao::setDistanciaVeiculoColeta(float distanciaVeiculoColeta)
{
    this -> distanciaVeiculoColeta = distanciaVeiculoColeta;
    return 1;
}
int Roterizacao::setDistanciaColetaEntrega(float distanciaColetaEntrega)
{
    this -> distanciaColetaEntrega = distanciaColetaEntrega;
    return 1;
}
int Roterizacao::setDistanciaTotal(float distanciaTotal)
{
    this -> distanciaTotal = distanciaTotal;
    return 1;
}
int Roterizacao::setTempoEntrega(float tempoEntrega)
{
    this -> tempoEntrega = tempoEntrega;
    return 1;
}
int Roterizacao::setVeiculosDisponiveis(GerenciadorVeiculos *veiculosDisponiveis)
{
    Roterizacao::veiculosDisponiveis = veiculosDisponiveis;
    return 1;
}

Pedido *Roterizacao::getPedido()
{
    return this -> pedido;
}
float Roterizacao::getDistanciaVeiculoColeta()
{
    return this -> distanciaVeiculoColeta;
}
float Roterizacao::getDistanciaColetaEntrega()
{
    return this -> distanciaColetaEntrega;
}
float Roterizacao::getDistanciaTotal()
{
    return this -> distanciaTotal;
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
    (this -> pedido -> getVeiculo() -> getLatitude() == 0 && this -> pedido -> getVeiculo() -> getLongitude() == 0) || 
    (this -> pedido -> getLatitudeOrigem() == 0 && this -> pedido -> getLongitudeOrigem() == 0) || 
    (this -> pedido -> getLatitudeDestino() == 0 && this -> pedido -> getLongitudeDestino() == 0))
    {
        perror("Latitude e longitude invalidas");
        return 0;
    }
    double raioTerra = 6371.0;
    double latitude1Rad = rad(this -> pedido -> getVeiculo() -> getLatitude());
    double longitude1Rad = rad(this -> pedido -> getVeiculo() -> getLongitude());
    double latitude2Rad = rad(this -> pedido -> getLatitudeOrigem());
    double longitude2Rad = rad(this -> pedido -> getLongitudeOrigem());
    double latitude3Rad = rad(this -> pedido -> getLatitudeDestino());
    double longitude3Rad = rad(this -> pedido -> getLongitudeDestino());
    double distanciaVeiculoColeta = 2 * raioTerra * asin(sqrt(pow(sin((latitude2Rad - latitude1Rad) / 2), 2) + cos(latitude1Rad) * cos(latitude2Rad) * pow(sin((longitude2Rad - longitude1Rad) / 2), 2)));
    double distanciaColetaEntrega = 2 * raioTerra * asin(sqrt(pow(sin((latitude3Rad - latitude2Rad) / 2), 2) + cos(latitude2Rad) * cos(latitude3Rad) * pow(sin((longitude3Rad - longitude2Rad) / 2), 2)));
    this -> distanciaVeiculoColeta = distanciaVeiculoColeta;
    this -> distanciaColetaEntrega = distanciaColetaEntrega;
    this -> distanciaTotal = distanciaVeiculoColeta + distanciaColetaEntrega;
    return this -> distanciaTotal;
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
    Veiculo* veiculo = this -> veiculosDisponiveis -> buscarProximidade(this -> pedido -> getLatitudeOrigem(), this -> pedido -> getLongitudeOrigem(), this -> pedido -> getVolume_carga());
    if(veiculo)
    {
        this -> pedido -> setVeiculo(veiculo);
        this -> veiculosDisponiveis -> removerVeiculo(veiculo);
        return veiculo;
    }
    perror("Veiculo nao encontrado");
    return NULL;
}

float Roterizacao::calcularTempoEntrega(float kmh)
{
    if(this -> distanciaTotal <= 0)
    {
        perror("Distancia invalida");
        return 0;
    }
    float tempo = this -> distanciaTotal / kmh;
    this -> tempoEntrega = tempo;
    return tempo;
}

int Roterizacao::finalizarEntrega()
{
    if(this -> pedido == NULL || this -> pedido -> getVeiculo() == NULL)
    {
        perror("Pedido invalido");
        return 0;
    }
    this -> pedido -> getVeiculo() -> setLatitude(this -> pedido -> getLatitudeDestino());
    this -> pedido -> getVeiculo() -> setLongitude(this -> pedido -> getLongitudeDestino());
    this -> pedido -> getVeiculo() -> setLocalizacao(this -> pedido -> getLocal_entrega());
    this -> veiculosDisponiveis -> adicionarVeiculo(this -> pedido -> getVeiculo());
    this -> veiculosDisponiveis -> getVeiculosDisponiveis() -> sort();
    this -> pedido -> setVeiculo(nullptr);
    return 1;
}

bool Roterizacao::operator==(const Roterizacao& outro) const
{
    return this -> pedido == outro.pedido;
}
std::ostream& operator<<(std::ostream& os, Roterizacao& roterizacao)
{
    os << "Pedido: " << *roterizacao.getPedido() << "\n"
        << "Local de origem: " << roterizacao.getPedido() -> getLocal_coleta() << "\n"
        << "Local de destino: " << roterizacao.getPedido() -> getLocal_entrega() << "\n"
        << "Local do Veiculo: " << roterizacao.getPedido() -> getVeiculo() -> getLocalizacao() << "\n"
        << "Distancia do veiculo ao local de coleta: " << roterizacao.getDistanciaVeiculoColeta() << " km\n"
        << "Distancia do local de coleta ao local de entrega: " << roterizacao.getDistanciaColetaEntrega() << " km\n"
        << "Distancia total: " << roterizacao.getDistanciaTotal() << " km\n"
        << "Tempo estimado de entrega: " << roterizacao.getTempoEntrega() << " horas de viagem\n";
    return os;
}