
# Jogo da Velha

Jogo da velha para aprendizagem da linguagem C/C++, Orientação Objeto e banco de dados com Sqlite3.



## Requisitos

* Qualquer distribuição linux (Ex: Fedora, Ubuntu) [Não disponível para Windows],
* Biblioteca ncurses,
* Cmake,
* Compilador C++ (Ex.: g++, Clang),

## Instalação ncurses

Arch-based use o camando abaixo:
```bash
$ sudo pacman -S ncurses
```
On Fedora, RHEL, CentOS, AlmaLinux, Rocky Linux:
```bash
$ sudo yum install ncurses-devel
```
Or,
```bash
$ sudo dnf install ncurses-devel
```

On Debian, Ubuntu, Linux Mint, Pop OS:
```bash
$ sudo apt install libncurses5-dev libncursesw5-dev
```

## Instalação dependência Sqlite3

Arch-baseado use o camando abaixo:
```bash
$ sudo pacman -S libsqlite-devel
```

On Fedora, RHEL, CentOS, AlmaLinux, Rocky Linux:
```bash
$ sudo yum install sqlite-devel
```
Or,
```bash
$ sudo dnf install sqlite-devel
```

On Debian, Ubuntu, Linux Mint, Pop OS:
```bash
$ sudo apt install libsqlite3-dev
```


## Instalação Jogo da Velha

Para instalar o jogo.

```bash
$ mkdir build && cd build
```


```bash
$ cmake ../
```

```bash
$ make
```
 
```bash
$ ./Jogo_da_Velha
```