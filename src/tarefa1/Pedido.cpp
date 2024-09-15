#include "Pedido.h"
#include <iostream>

Pedido::Pedido()
{
    this -> tipo_transporte = "";
    this -> local_coleta = "";
    this -> local_entrega = "";
    this -> peso_carga = 0.0;
    this -> volume_carga = 0.0;
}

Pedido::Pedido(Cliente clnt, Veiculo vcl, std::string tptrsprt, std::string lclclt, std::string lclentrg, float psocarg, float volcarg)
{
    this -> cliente = clnt;
    this -> veiculo = vcl;
    this -> tipo_transporte = tptrsprt;
    this -> local_coleta = lclclt;
    this -> local_entrega = lclentrg;
    this -> peso_carga = psocarg;
    this -> volume_carga = volcarg;
}

void Pedido::setCliente(Cliente clnt)
{
    this -> cliente = clnt;
}
void Pedido::setVeiculo(Veiculo vcl)
{
    this ->  veiculo = vcl;
}
void Pedido::setTipo_transporte(std::string tptrsprt)
{
    this -> tipo_transporte = tptrsprt;
}
void Pedido::setLocal_coleta(std::string lclclt)
{
    this -> local_coleta = lclclt;
}
void Pedido::setLocal_entrega(std::string lclentrg)
{
    this -> local_entrega = lclentrg;
}
void Pedido::setPeso_carga(float psocarg)
{
    if(psocarg < 0)
    {
        std::cout << "Valor negativo invalido, pesocarga foi setado = a 0" << std::endl;
        psocarg = 0;
    }
    this -> peso_carga = psocarg;
}
void Pedido::setVolume_carga(float volcarg)
{
    if(volcarg < 0)
    {
        std::cout << "Valor negativo invalido, volumecarga foi setado = a 0" << std::endl;
        volcarg = 0;
    }
    this -> volume_carga = volcarg;
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

