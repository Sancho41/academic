fun bubblesort(arr: MutableList<Int>) {
  for (pass in 0 until (arr.size - 1))
    for (j in 0 until (arr.size - 1 - pass))
      if (arr[j] > arr[j + 1]) {
        arr[j] = arr[j + 1] + arr[j]
        arr[j + 1] = arr[j] - arr[j + 1]
        arr[j] = arr[j] - arr[j + 1]
      }
}

fun main() {
  val numbers: MutableList<Int> = ArrayList()

  for (i in 1 until 10) numbers.add((1..100).random())

  numbers.forEach { print("$it ") }
  println()

  bubblesort(numbers)

  numbers.forEach { print("$it ") }
  println()
}
