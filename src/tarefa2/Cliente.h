//Descrever os clientes
#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>

class Cliente
{

private:
    std::string nome;
    std::string email;
    std::string endereco;
    std::string telefone;
    std::string cpf;
    int idade;

public:
    Cliente();
    Cliente(std::string nome, std::string email, std::string endereco, std::string telefone, std::string cpf, int idade);
    void print();
    int setNome(std::string nome);
    int setEmail(std::string email);
    int setEndereco(std::string endereco);
    int setTelefone(std::string telefone);
    int setCpf(std::string cpf); 
    int setIdade(int idade);

    std::string getNome();
    std::string getEmail();
    std::string getEndereco();
    std::string getTelefone();
    std::string getCpf();
    int getIdade();
};
#endif