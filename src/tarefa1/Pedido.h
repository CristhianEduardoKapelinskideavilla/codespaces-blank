//Descrever os pedidos de transportes (e.g., cliente que solicita, tipo de transporte, local de coleta, local de entrega, peso da carga, volume da carga).
#ifndef PEDIDO_H
 #define PEDIDO_H
#include "Cliente.h"
#include "Veiculo.h"
#include <iostream>


class Pedido
{

private:
    Cliente cliente;
    Veiculo veiculo;
    std::string tipo_transporte;
    std::string local_coleta;
    std::string local_entrega;
    float peso_carga;
    float volume_carga;

public:
    Pedido();
    Pedido(Cliente clnt, Veiculo vcl, std::string tptrsprt, std::string lclclt, std::string lclentrg, float psocarg, float volcarg);
    void setCliente(Cliente clnt);
    void setVeiculo(Veiculo vcl);
    void setTipo_transporte(std::string tptrsprt);
    void setLocal_coleta(std::string lclclt);
    void setLocal_entrega(std::string lclentrg);
    void setPeso_carga(float psocarg);
    void setVolume_carga(float volcarg);

    Cliente getCliente();
    Veiculo getVeiculo();
    std::string getTipo_transporte();
    std::string getLocal_coleta();
    std::string getLocal_entrega();
    float getPeso_carga();
    float getVolume_carga();
};
#endif