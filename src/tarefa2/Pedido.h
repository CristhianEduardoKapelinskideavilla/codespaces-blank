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
    Pedido(Cliente cliente, Veiculo veiculo, std::string tipo_transporte, std::string local_coleta, std::string local_entrega, float peso_carga, float volume_carga);
    void print();
    int setCliente(Cliente cliente);
    int setVeiculo(Veiculo veiculo);
    int setTipo_transporte(std::string tipo_transporte);
    int setLocal_coleta(std::string local_coleta);
    int setLocal_entrega(std::string local_entrega);
    int setPeso_carga(float peso_carga);
    int setVolume_carga(float volume_carga);

    Cliente getCliente();
    Veiculo getVeiculo();
    std::string getTipo_transporte();
    std::string getLocal_coleta();
    std::string getLocal_entrega();
    float getPeso_carga();
    float getVolume_carga();
};
#endif