# Corewar 2019 Epitech

> Epitech project - based around the creation of a virtual machine as well as an assembler for the game Corewar

***MARK : 100%***


## Table of Contents

- [Overview](#overview)
- [Installation](#installation)
- [Team](#team)


## Overview
Corewar is a game.  Where two or more battle programs (called "champions") compete for control of a [virtual computer](https://en.wikipedia.org/wiki/Virtual_machine "Virtual machine"). These battle programs are written in an abstract [assembly language](https://en.wikipedia.org/wiki/Assembly_language "Assembly language") called _Redcode_.

 # **This project was divided in three main parts :**

 **Virtual machine** :
  <dd>It is the fighting grounds of these so called champions.
 - It does two main things which is execute the champions instructions and keep track of the champions that are still alive

**Assembler** :
 <dd>This program understands the assembly language *Redcode* and generates a binary file that the virtual machine can use

**Champions** :
<dd>These are the warriors that will battle in the virtual machine; they are written in the assembly code and must be able to survive in the harsh environment that is the Corewar


## Installation

### Clone

- Clone this repo to your local machine using `https://github.com/Memoniak/corewar_2020.git`

### Setup

```shell
$ make
```
You just need one simple command to make the entire project.

### Usage

In order to compile a champion all you need to do is enter
```shell
$ ./asm/asm *name-of-file*.s
```
this will generate a .cor file with the same *name-of-file*

To use these champions on the virtual arena you just need to input
> ./corewar/corewar *champion1* *champion2* ...<br>

You can also input the number of champions that you want to have and their position in the memory
Just use ``` ./corewar/corewar -h ``` for more information


## Team


| <a href="http://fvcproductions.com" target="_blank">**Simon**</a> | <a href="http://fvcproductions.com" target="_blank">**Ewen**</a> | <a href="http://fvcproductions.com" target="_blank">**Evan**</a> |
| :---: |:---:| :---: |
| <a href="https://github.com/sim56300" target="_blank">`github.com/sim56300`</a> | <a href="https://github.com/Ewen2910" target="_blank">`github.com/Ewen2910`</a> | <a href="http://github.com/fvcproductions" target="_blank">`github.com/Evan`</a> |
