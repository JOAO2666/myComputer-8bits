================================================================================
myComputer-8bits - Computador Digital de 8 bits em VHDL
================================================================================

DESCRIÇÃO DO PROJETO:
Este projeto implementa um computador digital de 8 bits baseado no modelo Von 
Neumann, utilizando linguagem VHDL para descrição de hardware.

COMPONENTES:
============

1. myComputer_types.pkg
   - Define tipos customizados (byte_t, reg_addr_t)
   - Facilita padronização e legibilidade do código

2. ULA.vhd
   - Unidade Lógica e Aritmética
   - Operações: ADD, AND, SUB, OR, MUL, XOR
   - Entrada: 2 operandos de 8 bits + código de operação (3 bits)
   - Saída: Resultado de 8 bits

3. RegisterBank.vhd
   - Banco com 4 registradores de 8 bits
   - Registradores: R0, R1, LR (Link Register), SR (Status Register)
   - Leitura assíncrona, escrita síncrona

4. Memory.vhd
   - Memória com 256 endereços de 8 bits
   - Capacidade total: 256 bytes
   - Inclui programa de exemplo pré-carregado
   - Leitura assíncrona, escrita síncrona

5. ControlUnit.vhd
   - Unidade de Controle (Decodificador de Instruções)
   - Gera sinais de controle baseado no opcode
   - Suporte a 8 tipos de instruções

6. Mux2to1.vhd
   - Multiplexador 2:1 para seleção de operandos da ULA
   - Seleciona entre segundo operando ou imediato

7. Mux2to1_PC.vhd
   - Multiplexador 2:1 para seleção do próximo PC
   - Seleciona entre PC+1 ou endereço de salto

8. CPU.vhd
   - CPU Principal - integra todos os componentes
   - Executa ciclos de busca-decodificação-execução

9. Testbench.vhd
   - Ambiente de teste
   - Simula clock, reset e monitora saídas

INSTRUÇÕES SUPORTADAS:
======================
- Tipo R (Registrador): ADD, AND, SUB, OR, MUL, XOR
- Tipo I (Imediato): ADDI (Add Immediate)
- Tipo J (Jump): J (Salto incondicional)

FORMATO DE INSTRUÇÃO (8 bits):
=============================
[7:5] - Opcode (3 bits)
[4:2] - Função/Registrador (3 bits)
[1:0] - Registrador/Endereço (2 bits)

COMO USAR NO EDA PLAYGROUND:
============================
1. Acesse: https://edaplayground.com/
2. Selecione Language: VHDL
3. Selecione Simulator: Vivado, VCS ou ModelSim
4. Cole os arquivos nesta ordem:
   - Tipos (myComputer_types)
   - Componentes (ULA, RegisterBank, Memory, ControlUnit, Mux2to1, Mux2to1_PC)
   - CPU
   - Testbench
5. Clique em "Run"

PROGRAMA DE EXEMPLO (em memória):
=================================
00: ADD R0, R1    - Add R1 para R0
01: ADDI R1, 5    - Add 5 (imediato) para R1
02: OR R0, R1     - OR entre R0 e R1
03: J 0           - Salto para endereço 0 (loop)

ARQUITETURA:
============
     ┌────────────────────────────────────────┐
     │          Programa em Memória            │
     └────────────────┬─────────────────────────┘
                      │
                      ├─ Instrução (fetch)
                      │
     ┌────────────────▼─────────────────────────┐
     │       Unidade de Controle               │
     │  (Decodifica instrução, gera sinais)    │
     └────────────────┬─────────────────────────┘
                      │
        ┌─────────────┼─────────────┐
        │             │             │
        ▼             ▼             ▼
    ┌────────┐  ┌──────────┐  ┌────────┐
    │  ULA   │  │ Registr. │  │ Mux    │
    └────────┘  └──────────┘  └────────┘
        │             │             │
        └─────────────┼─────────────┘
                      │
                    Resultado

CARACTERÍSTICAS:
================
✓ Pipeline fetch-decode-execute
✓ 4 registradores de propósito geral
✓ 256 bytes de memória
✓ 6 operações aritméticas/lógicas
✓ Suporte a saltos condicionais
✓ Clock sincronizado

SINAIS PRINCIPAIS:
==================
clk      - Clock do sistema
rst      - Reset assincronizado (ativo em nível alto)
output_data - Saída de dados (resultado da ULA)
output_reg  - Saída do registrador B

MELHORIAS FUTURAS:
==================
- Implementar mais operações (DIV, MOD, etc)
- Adicionar flag register (Zero, Carry, etc)
- Implementar saltos condicionais
- Expandir memória
- Adicionar instruções de load/store
- Pipeline avançado

REFERÊNCIAS:
============
Baseado no modelo Von Neumann de arquitetura de computadores
Segue o padrão IEEE 1076 para VHDL

================================================================================
