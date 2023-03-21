# Exercicio Escolar 2

## Este sistema deve ser capaz de:

1. Realizar a carga dos arquivos CSV com novos casos e consolidar os dados de todas as
cargas em um outro arquivo CSV. Os arquivos de carga contém um número indeterminado de
linhas, pois em alguns casos as secretarias atrasam o envio diário e acabam enviando dados de
vários dias no mesmo CSV. O arquivo com os dados consolidados nacionais (de todos os
estados/cidades), deve seguir o formato abaixo:

    `CodCidade;CodEstado;TotalCasos;UltimaAtualizacao`

- Onde TotalCasos é a soma de todos os casos registrados por todas as cargas para aquela cidade e
UltimaAtualizacao é a data da última atualização de dados recebida para aquela cidade (obs: não
é a data da carga, mas a data informada no campo DataRegistro). Lembre-se que, no arquivo de
carga, as linhas não estarão necessariamente ordenadas por data.

2. Manter um arquivo CSV com o histórico de todas as cargas realizadas. Este arquivo
deve seguir o mesmo formato do arquivo de cargas, porém contendo um campo adicional chamado
DataCarga que representa a data do sistema no momento em que a carga foi realizada.

3. Gerar relatório de casos por ESTADO. O(A) usuário(a) irá informar o código de um
estado da federação e, caso existam dados para este estado, o sistema irá gerar um relatório.