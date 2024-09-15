#ifndef ROTERIZACAO_H
#define ROTERIZACAO_H 
#include "Pedido.h"
#include "GerenciadorVeiculos.h"
#include "Veiculo.h"
#include "GerenciadorVeiculos.h"
#include <iostream>


class Roterizacao
{
private:
    Pedido *pedido;
    float distanciaVeiculoColeta;
    float distanciaColetaEntrega;
    float distanciaTotal;
    float tempoEntrega;
    static GerenciadorVeiculos *veiculosDisponiveis;

public:
    Roterizacao();
    Roterizacao(Pedido *pedido, float distanciaVeiculoColeta, float distanciaColetaEntrega, float distanciaTotal, float tempoEntrega);
    ~Roterizacao();
    int setPedido(Pedido *pedido);
    int setDistanciaVeiculoColeta(float distanciaVeiculoColeta);
    int setDistanciaColetaEntrega(float distanciaColetaEntrega);
    int setDistanciaTotal(float distanciaTotal);
    int setTempoEntrega(float tempoEntrega);
    int setVeiculosDisponiveis(GerenciadorVeiculos *veiculosDisponiveis);
    
    Pedido *getPedido();
    float getDistanciaVeiculoColeta();
    float getDistanciaColetaEntrega();
    float getDistanciaTotal();
    float getTempoEntrega();
    GerenciadorVeiculos *getVeiculosDisponiveis();

    double rad(double graus);
    /*
        Função calcularDistancia(): Calcula a distancia entre dois pontos na superficie da terra, 
    utilizando a formula de haversine, que é uma formula que calcula a distancia 
    entre dois pontos na superficie de uma esfera, como a terra, utilizando a latitude
    e longitude dos pontos, a funcao calcula a distancia entre o veiculo e o local
    de coleta, o local de coleta e o local de entrega, e a distancia total e seta
    os valores nos atributos da classe.
    */
    double calcularDistancia();
    Veiculo *acharVeiculo();
    float calcularTempoEntrega(float kmh);
    /* 
        funcão finalizarEntrega(): Acha o Veiculo mais proximo do ponto de coleta do pedido e que tenha a 
    capacidade de carga maior ou igual a necessaria. Então seta o veiculo no 
    pedido e remove o veiculo da lista de veiculos disponiveis.
    */
    int finalizarEntrega();
    bool operator==(const Roterizacao& outro) const; 
    friend std::ostream& operator<<(std::ostream& os, Roterizacao& roterizacao);
};
#endif