#include "../includes/Pedido.h"
#include "../includes/Cliente.h"
#include "../includes/Veiculo.h"
#include <iostream>

Pedido::Pedido()
{
    this -> cliente = new Cliente();
    this -> veiculo = new Veiculo();
    this -> tipo_transporte = "";
    this -> local_coleta = "";
    this -> local_entrega = "";
    this -> peso_carga = 0.0;
    this -> volume_carga = 0.0;
    this -> longitudeOrigem = 0;
    this -> latitudeOrigem = 0;
    this -> longitudeDestino = 0;
    this -> latitudeDestino = 0;
}

Pedido::Pedido(Cliente *cliente, Veiculo *veiculo, std::string tipo_transporte, std::string local_coleta, std::string local_entrega, float peso_carga, float volume_carga, double latitudeOrigem, double longitudeOrigem, double latitudeDestino, double longitudeDestino)
{
    this -> cliente = cliente;
    this -> veiculo = veiculo;
    this -> tipo_transporte = tipo_transporte;
    this -> local_coleta = local_coleta;
    this -> local_entrega = local_entrega;
    this -> peso_carga = peso_carga;
    this -> volume_carga = volume_carga;
    this -> longitudeOrigem = longitudeOrigem;
    this -> latitudeOrigem = latitudeOrigem;
    this -> longitudeDestino = longitudeDestino;
    this -> latitudeDestino = latitudeDestino;
}

Pedido::~Pedido()
{
    delete this -> cliente;
    delete this -> veiculo;
}
int Pedido::setCliente(Cliente *cliente)
{
    this -> cliente = cliente;
    return 1;
}
int Pedido::setVeiculo(Veiculo *veiculo)
{
    this ->  veiculo = veiculo;
    return 1;
}
int Pedido::setTipo_transporte(std::string tipo_transporte)
{
    this -> tipo_transporte = tipo_transporte;
    return 1;
}
int Pedido::setLocal_coleta(std::string local_coleta)
{
    this -> local_coleta = local_coleta;
    return 1;
}
int Pedido::setLocal_entrega(std::string local_entrega)
{
    this -> local_entrega = local_entrega;
    return 1;
}
int Pedido::setPeso_carga(float peso_carga)
{
    if(peso_carga < 0)
    {
        std::cout << "Valor negativo invalido, pesocarga foi setado = a 0" << std::endl;
        peso_carga = 0;
        return 0;
    }
    this -> peso_carga = peso_carga;
    return 1;
}
int Pedido::setVolume_carga(float volume_carga)
{
    if(volume_carga < 0)
    {
        std::cout << "Valor negativo invalido, volumecarga foi setado = a 0" << std::endl;
        volume_carga = 0;
        return 0;
    }
    this -> volume_carga = volume_carga;
    return 1;
}
int Pedido::setLatitudeOrigem(double latitudeOrigem)
{
    this -> latitudeOrigem = latitudeOrigem;
    return 1;
}
int Pedido::setLongitudeOrigem(double longitudeOrigem)
{
    this -> longitudeOrigem = longitudeOrigem;
    return 1;
}
int Pedido::setLatitudeDestino(double latitudeDestino)
{
    this -> latitudeDestino = latitudeDestino;
    return 1;
}
int Pedido::setLongitudeDestino(double longitudeDestino)
{
    this -> longitudeDestino = longitudeDestino;
    return 1;
}


Cliente *Pedido::getCliente()
{
    return this -> cliente;
}
Veiculo *Pedido::getVeiculo()
{
    return this -> veiculo;
}
std::string Pedido::getTipo_transporte()
{
    return this -> tipo_transporte;
}
std::string Pedido::getLocal_coleta()
{
    return this -> local_coleta;
}
std::string Pedido::getLocal_entrega()
{
    return this -> local_entrega;
}
float Pedido::getPeso_carga()
{
    return this -> peso_carga;
}
float Pedido::getVolume_carga()
{
    return this -> volume_carga;
}
double Pedido::getLatitudeOrigem()
{
    return this -> latitudeOrigem;
}
double Pedido::getLongitudeOrigem()
{
    return this -> longitudeOrigem;
}
double Pedido::getLatitudeDestino()
{
    return this -> latitudeDestino;
}
double Pedido::getLongitudeDestino()
{
    return this -> longitudeDestino;
}

std::ostream& operator<<(std::ostream& os, Pedido& pedido)
{
    os << "\nCliente: " << (pedido.getCliente() != nullptr ? pedido.getCliente() -> getNome() : "N/A") << "\n"
        << "Veiculo: " << (pedido.getVeiculo() != nullptr ? std::to_string(pedido.getVeiculo()->getId()) : "N/A") << "\n"
                << "Tipo de Transporte: " << pedido.getTipo_transporte() << "\n"
                << "Local de Coleta: " << pedido.getLocal_coleta() << "\n"
                << "Local de Entrega: " << pedido.getLocal_entrega() << "\n"
                << "Peso da Carga: " << pedido.getPeso_carga() << "kg\n"
                << "Volume da Carga: " << pedido.getVolume_carga() << "cm³\n"
                << "Latitude de Origem: " << pedido.getLatitudeOrigem() << "\n"
                << "Longitude de Origem: " << pedido.getLongitudeOrigem() << "\n"
                << "Latitude de Destino: " << pedido.getLatitudeDestino() << "\n"
                << "Longitude de Destino: " << pedido.getLongitudeDestino() << "\n";
    return os;
}

bool Pedido::operator==(Pedido& other) const
{
    return this -> cliente == other.getCliente() && this -> veiculo == other.getVeiculo();
}