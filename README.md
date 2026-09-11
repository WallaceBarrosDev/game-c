# Jogo em C — Texto no Terminal

Projeto casual pra passar o tempo. Sem pressão, sem prazo.

## Como compilar e rodar

```bash
make run
```

Ou manualmente:

```bash
gcc -Wall -Wextra -std=c99 -g -o jogo src/main.c
./jogo
```

## Limpar arquivos compilados

```bash
make clean
```

## Ideias pra começar

- Aventura de texto (escolhas com consequências)
- RPG com combate por turnos
- Gerador de história procedural
- Caça-palavras / jogo da memória
- Quiz / adivinhação
- Dungeon crawler em grade ASCII

## Estrutura

```
jogo-terminal-c/
├── Makefile       # compilação
├── README.md      # este arquivo
├── .gitignore     # ignora o binário
└── src/
    └── main.c     # lógica principal
```

## Regras do projeto

1. Não gaste dinheiro.
2. Não coloque prazo.
3. Se enjoar, deixa e volta quando quiser.
