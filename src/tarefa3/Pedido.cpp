#include "Pedido.h"
#include "Cliente.h"
#include "Veiculo.h"
#include <iostream>

Pedido::Pedido()
{
    this -> cliente = Cliente();
    this -> veiculo = Veiculo();
    this -> tipo_transporte = "";
    this -> local_coleta = "";
    this -> local_entrega = "";
    this -> peso_carga = 0.0;
    this -> volume_carga = 0.0;
    this -> longitude = 0;
    this -> latitude = 0;
}

Pedido::Pedido(Cliente cliente, Veiculo veiculo, std::string tipo_transporte, std::string local_coleta, std::string local_entrega, float peso_carga, float volume_carga, double latitude, double longitude)
{
    this -> cliente = cliente;
    this -> veiculo = veiculo;
    this -> tipo_transporte = tipo_transporte;
    this -> local_coleta = local_coleta;
    this -> local_entrega = local_entrega;
    this -> peso_carga = peso_carga;
    this -> volume_carga = volume_carga;
    this -> longitude = longitude;
    this -> latitude = latitude;
}

int Pedido::setCliente(Cliente cliente)
{
    this -> cliente = cliente;
    return 1;
}
int Pedido::setVeiculo(Veiculo veiculo)
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
int Pedido::setLatitude(double latitude)
{
    this -> latitude = latitude;
    return 1;
}
int Pedido::setLongitude(double longitude)
{
    this -> longitude = longitude;
    return 1;
}

Cliente Pedido::getCliente()
{
    return this -> cliente;
}
Veiculo Pedido::getVeiculo()
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
double Pedido::getLatitude()
{
    return this -> latitude;
}
double Pedido::getLongitude()
{
    return this -> longitude;
}

std::ostream& operator<<(std::ostream& os, Pedido& pedido)
{
    os << "\nCliente: " << pedido.getCliente().getNome() << "\n"
                << "Veiculo: " << pedido.getVeiculo().getId() << "\n"
                << "Tipo de Transporte: " << pedido.getTipo_transporte() << "\n"
                << "Local de Coleta: " << pedido.getLocal_coleta() << "\n"
                << "Local de Entrega: " << pedido.getLocal_entrega() << "\n"
                << "Peso da Carga: " << pedido.getPeso_carga() << "kg\n"
                << "Volume da Carga: " << pedido.getVolume_carga() << "cm³\n"
                << "Latitude: " << pedido.getLatitude() <<"\n"
                << "Longitude: " << pedido.getLongitude() << "\n";
    return os;
}

bool Pedido::operator==(Pedido& other) const
{
    return this -> cliente == other.getCliente() && this -> veiculo == other.getVeiculo();
}