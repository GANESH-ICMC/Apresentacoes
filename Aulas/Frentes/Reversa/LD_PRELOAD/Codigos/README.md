# Códigos de Exemplo usando LD\_PRELOAD

## Para compilar os .so:

`gcc urandom.c -o unrandom.so -shared -fPIC`

## Try it out:

`gcc main.c -o random`

Execute e veja 10 números aleatórios

`./random`

Troque por:

`LD_PRELOAD=$PWD/unrandom.so ./random`

## Desativar usleep

Arquivo `hacking_time.c`.

## Obter "função original":

Exemplo no código `func.c`

Compile com:

`gcc func.c -o func.so -shared -fPIC -ldl`

Faça o que quiser com o ponteiro para função retornado
