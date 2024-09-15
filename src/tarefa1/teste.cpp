#include "Veiculo.cpp"
#include "Cliente.cpp"
#include "Pedido.cpp"
#include <iostream>

int main(void)
{
    Veiculo carro = Veiculo("500kg", "1991", "123456789", "Fusca", "Alegrete, RS", "4x4", "Carro", "Passeio", 185, 220, 445, 1500);
    std::cout << "Modelo: "<< carro.getModelo() << "\n"
                << "Ano de Fabricação: " << carro.getAno_fabricacao() << "\n"
                << "Chassi: " << carro.getChassi() << "\n"
                << "Localização: " << carro.getLocalizacao() << "\n"
                << "Tracao: " << carro.getTracao() << "\n"
                << "Especie: " << carro.getEspecie() << "\n"
                << "Categoria: " << carro.getCategoria() << "\n"
                << "Largura: " << carro.getLargura() << "cm\n"
                << "Altura: " << carro.getAltura() << "cm\n"
                << "Comprimento: " << carro.getComprimento() << "cm\n"
                << "Peso: " << carro.getPeso() << "kg\n";

    Cliente cliente1 = Cliente("João", "joao2913219@gmail.com", "Belo Horizonte, MG", "00 00000000", "123456789", 19);
    std::cout << "\nNome: " << cliente1.getNome() << "\n"
                << "CPF: " << cliente1.getCpf() << "\n"
                << "Endereço: " << cliente1.getEndereco() << "\n"
                << "Telefone: " << cliente1.getTelefone() << "\n"
                << "Email: " << cliente1.getEmail() << "\n"
                << "Idade: " << cliente1.getIdade() << " anos\n";

    Pedido pedido1 = Pedido(cliente1, carro, "Carro", carro.getLocalizacao(), cliente1.getEndereco(), 1000, 300);
    std::cout << "\nCliente: " << pedido1.getCliente().getNome() << "\n"
                << "Veiculo: " << pedido1.getVeiculo().getModelo() << "\n"
                << "Tipo de Transporte: " << pedido1.getTipo_transporte() << "\n"
                << "Local de Coleta: " << pedido1.getLocal_coleta() << "\n"
                << "Local de Entrega: " << pedido1.getLocal_entrega() << "\n"
                << "Peso da Carga: " << pedido1.getPeso_carga() << "kg\n"
                << "Volume da Carga: " << pedido1.getVolume_carga() << "cm³\n";
    
    return 0;
}
