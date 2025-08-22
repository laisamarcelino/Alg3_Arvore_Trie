# 📖 Projeto - Busca de Palavras com Trie e Teclado Numérico

Este projeto implementa uma estrutura de **Trie** em C para realizar buscas de palavras a partir de entradas numéricas, simulando o funcionamento de um teclado T9 (usado em celulares antigos).  
O programa carrega um dicionário de palavras, processa consultas fornecidas pela entrada padrão e retorna as palavras correspondentes.

## 🚀 Funcionalidades
- Carregar um dicionário de palavras a partir de um arquivo `.txt`.
- Mapear palavras para sequências numéricas no estilo T9.
- Permitir consultas interativas via entrada padrão.
- Navegar entre palavras candidatas usando `#`.
- Detectar e reportar entradas inválidas.
- Indicar quando nenhuma palavra correspondente é encontrada.

## ⚙️ Compilação e Execução

### 1. Compilar
```bash
make
./t9 miniDicionario.txt < consulta.txt > saida.txt
```