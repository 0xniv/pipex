[![eng](../../../stuff/blob/main/USA-icon.png)](README.md) ![pt-BR](../../../stuff/blob/main/Brazil-icon.png)



# `pipex`

O propósito desse projeto é descobrir em detalhe o mecanismo dos sistemas baseados em UNIX - `pipe`.

### Primeira parte (Mandatório)
O programa `pipex` deve repetir o comportamento do comando de shell (Terminal) a seguir
```bash
$> < arquivo1(Makefile) comando1(cat) | comando2(sort) > arquivo2
```
execução no seu programa:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```
Todos os erros como: comandos invalidos, permissão de arquivos e etc, devem ser tratados ~~por você~~.
### Segunda parte (Bonus)
Seu progama deve manipular multiplos pipes:
```bash
$> < arquivo1(Makefile) cmd1(cat) | cmd2(grep CC) | cmd3(tr C B) > arquivo2

$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Manipular `<<` and `>>`, quando em vez de `arquivo1` for `here_doc`.
```bash
$> cmd1 << LIMITADOR | cmd2 >> arquivo2

$> ./pipex here_doc LIMITER cmd1 cmd2 file2
```

## Download
```ssh
git@github.com:vinicius-f-pereira/pipex.git
```
Use o comando `make` ou `make bonus` e para usar siga as instruções da [Primeira Parte](#pipex)
