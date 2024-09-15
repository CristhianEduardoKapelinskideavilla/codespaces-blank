#ifndef ROTERIZACAO_H
#define ROTERIZACAO_H 
#include "Pedido.h"
#include "GerenciadorVeiculos.h"
#include "Veiculo.h"
#include "GerenciadorVeiculos.h"
#include <iostream>

class Roterizacao{
private:
    Pedido *pedido;
    double distancia;
    float tempoEntrega;
    GerenciadorVeiculos *veiculosDisponiveis;

public:
    Roterizacao();
    Roterizacao(Pedido *pedido, double distancia, float tempoEntrega, GerenciadorVeiculos *veiculosDisponiveis);
    ~Roterizacao();
    int setPedido(Pedido *pedido);
    int setDistancia(double distancia);
    int setTempoEntrega(float tempoEntrega);
    int setVeiculosDisponiveis(GerenciadorVeiculos *veiculosDisponiveis);
    
    Pedido *getPedido();
    double getDistancia();
    float getTempoEntrega();
    GerenciadorVeiculos *getVeiculosDisponiveis();

    double rad(double graus);
    double calcularDistancia();
    Veiculo *acharVeiculo();
    float calcularTempoEntrega(float kmh);
    bool operator==(const Roterizacao& outro) const; 
    friend std::ostream& operator<<(std::ostream& os, const Roterizacao& roterizacao);
};
#endif