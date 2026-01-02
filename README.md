# Integração Numérica em C

O código presente neste repositório implementa, em linguagem C, métodos de **integração numérica** aplicados ao cálculo de:

- integrais definidas
- comprimento de curvas
- volume de sólidos de revolução

O foco do projeto é a **clareza matemática**, a **robustez numérica** e a **organização do código**, de modo que ele possa ser usado tanto para estudo quanto como base para extensões futuras.

---

## Estrutura do projeto

```
integracao-numerica-c/
├── src/
│   ├── main.c
│   ├── curva.c
│   ├── intervalo.c
│   └── ponto.c
├── include/
│   ├── curva.h
│   ├── intervalo.h
│   ├── ponto.h
│   └── constantes.h
├── build.sh
├── README.md
└── .gitignore
```

- `src/` contém as implementações das funções numéricas.
- `include/` contém os arquivos de cabeçalho que definem a API pública.
- `build.sh` compila o projeto.
- `README.md` documenta o uso e as decisões conceituais.

---

## Conceitos matemáticos adotados

### Integrais definidas
As funções de integração numérica aproximam a **integral definida** $\int_a^b f(x)\, dx $.

Portanto:
- o resultado pode ser negativo
- a orientação do intervalo é respeitada (`b < a` inverte o sinal)
- quando `f(x) ≥ 0` e `a < b`, o valor coincide com a área sob a curva

### Comprimento de curva
O comprimento da curva y = f(x) no intervalo [a,b] é aproximado por uma **poligonal**, somando as distâncias entre pontos consecutivos da curva.

O resultado é sempre não negativo.

### Volume de sólidos de revolução
O volume é calculado pelo **método dos troncos de cone**, considerando a rotação da curva em torno do eixo x.

- o volume é sempre não negativo
- o sinal do passo é tratado internamente

---

## Funções disponíveis

### Comprimento de curva
```c
double comprimento_curva(Curva C, int n);
```
Aproxima o comprimento da curva y = f(x) no intervalo [a,b] usando uma aproximação poligonal com `n` subintervalos.

---

### Integrais definidas

#### Retângulos à esquerda
```c
double integral_definida_por_retangulos_esquerda(Curva C, int n);
```
Aproxima a integral definida pelo método dos retângulos à esquerda.

#### Trapézios
```c
double integral_definida_por_trapezios(Curva C, int n);
```
Aproxima a integral definida pelo método dos trapézios.

---

### Volume de sólido de revolução
```c
double volume_solido_revolucao(Curva C, int n);
```
Aproxima o volume do sólido gerado pela rotação da curva em torno do eixo x, usando troncos de cone.

---

## Pré-condições e tratamento de erros

Todas as funções assumem:
- `n > 0`
- `C.funcao != NULL`

Se alguma dessas pré-condições não for satisfeita, a função retorna:

```c
NAN
```

O usuário pode verificar o erro com `isnan(resultado)`.

---

## Compilação

Dê permissão de execução ao script (uma única vez):

```bash
chmod +x build.sh
```

Depois, compile com:

```bash
./build.sh
```
