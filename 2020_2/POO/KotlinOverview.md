# Laços de repetição

## Variáveis
```kotlin
var name = "Gabriel"
name = "Gabriel Sancho"
```
---

## Constantes
```kotlin
val name = "Gabriel Sancho"
```
---

## Tipos básicos
| Type   | Bit width |
| ------ | --------- |
| Double | 64        |
| Float  | 32        |
| Long   | 64        |
| Int    | 32        |
| Short  | 16        |
| Byte   | 8         |
---

## Literais
| Type         | Representation        |
| ------------ | --------------------- |
| Decimais     | `123` ou `123L`       |
| Hexadecimais | `0x0F`                |
| Binários     | `0b00001011`          |
| Doubles      | `123.5` ou `123.5e10` |
| floats       | `123.5f`              |
---

## Arrays
```kotlin
val arr1 = arrayOf(1, 2, 3, 4)
val arr2 = arrayOf(1, 2, 3, "String", false)
val arr3 = arrayOf<Int>(1, 2, 3, "String", false) // Compilation error
val arr4 = intArrayOf(1, 2, 3, "String", false) // Compilation error
```
---

# String templates
```kotlin
val nome = "Gabriel"
var saudacao = "Olá $nome - Tamanho: ${nome.length}"
```

# Intervalos
```kotlin
val aToZ = 'a'..'z'
val isTrue = 'c' in aToZ
```

# Laços de repetição

## While
```kotlin
while(true) {
  println("it has no end...")
}
```

## For
```kotlin
val list = listOf(1, 2, 3, 4, 5)
for (x in list)
  println(x)
```

```kotlin
for (x in 0..10) { println(x) }
```

```kotlin
for (i in 2 until 5)
  println(i)
```
---

# Controles de fluxo
## If
* **If** em Kotilin é uma expressão, ou seja, retorna valor;
* Não exites operador ternário uma vez que **if** faz esse papel;
* **Existe** o operador **elvis** ( `?:` )

```kotlin
var max = a
if (a < b) max = b
```
```kotlin
var max: Int
if (a > b)
  max = a
else
  max = b
```
```kotlin
val max = if (a > b) a else b
```

```kotlin
val b = a?.length ?: -1
```