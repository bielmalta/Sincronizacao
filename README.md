# Sincronização do Metrô

Implementação em C utilizando Pthreads, mutex e variáveis de condição para sincronizar o embarque de passageiros em vagões de metrô.

## Arquivos

- `sync_car.c`: implementação das funções de sincronização.
- `sync_car.h`: definição da estrutura station e declaração das funções.
- `sync_car-runner.c`: arquivo de testes fornecido pelo professor.
- `makefile`: compilação e limpeza dos arquivos gerados.

## Sistema operacional

Desenvolvido e testado no Ubuntu 24.04 (WSL2).

## Compilação

```bash
make
```

## Execução e testes

```bash
./sync_car
```

## Limpeza

```bash
make clean
```