# Tarefa 4

1) Criados `READMEs` para cada semana, e um para todo o projeto que reune os de cada semana em apenas um.
2) Inseridos `comentarios` no código para facilitar o entendimento.
3) Modificada a classe `Pedido`, substituidas as variaveis `latitude` e `longitude` por `latitudeOrigem`, `longitudeOrigem`, `latitudeDestino` e `longitudeDestino`. Além das variaveis cliente e veiculo da classe terem mudado de variaveis estaticas para ponteiros.
4) Modificado o parametro da classe Roterizacao, de `calcular a distancia entre pontos`, agora ela usa as novas variaveis do pedido para calcular a distancia entre o veiculo e o local de coleta, e entre o local de coleta e local de entrega, além da distancia total.
5) Criada um parametro na classe `GerenciadorVeiculos` para buscar os veiculos mais proximos à um certo ponto, e que tenha uma capacidade de carga maior ou igual ao necesario.
6) Modificado o parametro `acharVeiculo` da classe Roterizacao, agora o mesmo acha o veiculo mais proximo a regiao de coleta e com a capacidade de carga necessaria, além de remover o veiculo da lista de veiculos disponiveis.
7) Criado o parametro `finalizarEntrega`, que adiciona o veiculo novamente à lista de veiculos disponiveis e que troca a localizacao do veiculo para a localizacão de entrega.