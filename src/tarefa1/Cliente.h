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
    Cliente(std::string nom, std::string eml, std::string endrc, std::string fone, std::string cf, int idd);
    void setNome(std::string nom);
    void setEmail(std::string eml);
    void setEndereco(std::string endrc);
    void setTelefone(std::string fone);
    void setCpf(std::string cf); 
    void setIdade(int idd);

    std::string getNome();
    std::string getEmail();
    std::string getEndereco();
    std::string getTelefone();
    std::string getCpf();
    int getIdade();
};
#endif