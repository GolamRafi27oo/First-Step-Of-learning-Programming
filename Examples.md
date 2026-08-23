# C and JavaScript Examples

Every runnable example in this companion guide is shown in both C and JavaScript. Compile C examples with a C11-compatible compiler such as `cc -std=c11 file.c`, and run JavaScript examples with Node.js or a browser console.

## Number-system conversion

### C

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *binary = "101";
    const char *octal = "100";
    unsigned decimal = 75;

    printf("binary %s = decimal %ld\n", binary, strtol(binary, NULL, 2));
    printf("decimal %u = binary ", decimal);
    for (int bit = 31; bit > 0 && !(decimal & (1u << bit)); --bit) {}
    unsigned mask = 1u;
    while (mask <= decimal / 2) mask <<= 1;
    for (; mask; mask >>= 1) putchar(decimal & mask ? '1' : '0');
    printf("\ndecimal %u = octal %o\n", decimal, decimal);
    printf("octal %s = decimal %ld\n", octal, strtol(octal, NULL, 8));
    return 0;
}
```

### JavaScript

```javascript
const binary = "101";
const octal = "100";
const decimal = 75;

console.log(`binary ${binary} = decimal ${Number.parseInt(binary, 2)}`);
console.log(`decimal ${decimal} = binary ${decimal.toString(2)}`);
console.log(`decimal ${decimal} = octal ${decimal.toString(8)}`);
console.log(`octal ${octal} = decimal ${Number.parseInt(octal, 8)}`);
```

## Bit operations

### C

```c
#include <stdio.h>

int main(void) {
    unsigned value = 10; /* 1010 */
    unsigned bit = 1;
    printf("AND: %u\n", value & 6u);
    printf("OR: %u\n", value | 6u);
    printf("XOR: %u\n", value ^ 6u);
    printf("bit %u is %s\n", bit, value & (1u << bit) ? "ON" : "OFF");
    return 0;
}
```

### JavaScript

```javascript
const value = 10; // 1010
const bit = 1;
console.log("AND:", value & 6);
console.log("OR:", value | 6);
console.log("XOR:", value ^ 6);
console.log(`bit ${bit} is ${(value & (1 << bit)) !== 0 ? "ON" : "OFF"}`);
```

## Conditions, loops, and switch

### C

```c
#include <stdio.h>

int main(void) {
    int choice = 2;
    if (choice > 0) printf("positive\n");
    for (int i = 0; i < 3; ++i) printf("%d ", i);
    putchar('\n');
    switch (choice) {
        case 1: puts("login"); break;
        case 2: puts("user list"); break;
        case 3: puts("sign up"); break;
        default: puts("invalid choice");
    }
    return 0;
}
```

### JavaScript

```javascript
const choice = 2;
if (choice > 0) console.log("positive");
for (let i = 0; i < 3; i += 1) console.log(i);
switch (choice) {
  case 1: console.log("login"); break;
  case 2: console.log("user list"); break;
  case 3: console.log("sign up"); break;
  default: console.log("invalid choice");
}
```

## Triangle patterns

### C

```c
#include <stdio.h>

int main(void) {
    int rows = 3;
    for (int row = 1; row <= rows; ++row) {
        for (int star = 0; star < row; ++star) printf("* ");
        putchar('\n');
    }
    return 0;
}
```

### JavaScript

```javascript
const rows = 3;
for (let row = 1; row <= rows; row += 1) {
  console.log("* ".repeat(row).trimEnd());
}
```

Reverse the outer loop or add leading spaces to produce the reverse and right-aligned variants.

## Arrays: map, search, insert, and remove

### C

```c
#include <stdio.h>

int main(void) {
    int values[10] = {1, 2, 3, 4, 5};
    size_t length = 5;

    for (size_t i = 0; i < length; ++i) values[i] *= values[i];

    int target = 9;
    int found = -1;
    for (size_t i = 0; i < length; ++i)
        if (values[i] == target) { found = (int)i; break; }

    size_t position = 2;
    for (size_t i = length; i > position; --i) values[i] = values[i - 1];
    values[position] = 25;
    ++length;

    for (size_t i = position; i + 1 < length; ++i) values[i] = values[i + 1];
    --length;

    printf("target index: %d\n", found);
    for (size_t i = 0; i < length; ++i) printf("%d%c", values[i], i + 1 == length ? '\n' : ' ');
    return 0;
}
```

### JavaScript

```javascript
const values = [1, 2, 3, 4, 5].map(value => value * value);
const target = 9;
const found = values.indexOf(target);
values.splice(2, 0, 25); // insert
values.splice(2, 1);     // remove
console.log("target index:", found);
console.log(values);
```

## Run-length encoding

### C

```c
#include <stdio.h>

int main(void) {
    int input[] = {1, 1, 1, 2, 2, 3};
    size_t n = sizeof input / sizeof input[0];
    for (size_t i = 0; i < n;) {
        size_t next = i + 1;
        while (next < n && input[next] == input[i]) ++next;
        printf("(%d, %zu) ", input[i], next - i);
        i = next;
    }
    putchar('\n');
    return 0;
}
```

### JavaScript

```javascript
const input = [1, 1, 1, 2, 2, 3];
const encoded = [];
for (const value of input) {
  const last = encoded.at(-1);
  if (last?.[0] === value) last[1] += 1;
  else encoded.push([value, 1]);
}
console.log(encoded);
```

## Multidimensional arrays

### C

```c
#include <stdio.h>

int main(void) {
    int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };
    for (size_t row = 0; row < 2; ++row) {
        for (size_t column = 0; column < 3; ++column)
            printf("%d%c", matrix[row][column], column == 2 ? '\n' : ' ');
    }
    return 0;
}
```

### JavaScript

```javascript
const matrix = [[1, 2, 3], [4, 5, 6]];
for (const row of matrix) console.log(row.join(" "));
```

## Strings: comparison, palindrome, and concatenation

### C

```c
#include <stdio.h>
#include <string.h>

int is_palindrome(const char *text) {
    size_t left = 0, right = strlen(text);
    while (left < right)
        if (text[left++] != text[--right]) return 0;
    return 1;
}

int main(void) {
    char message[32] = "Hello, ";
    strncat(message, "world!", sizeof message - strlen(message) - 1);
    printf("%s\n", strcmp("apple", "banana") < 0 ? "apple comes first" : "banana comes first");
    printf("level is %sa palindrome\n", is_palindrome("level") ? "" : "not ");
    puts(message);
    return 0;
}
```

### JavaScript

```javascript
const isPalindrome = text => text === [...text].reverse().join("");
console.log("apple".localeCompare("banana") < 0 ? "apple comes first" : "banana comes first");
console.log(`level is ${isPalindrome("level") ? "" : "not "}a palindrome`);
console.log("Hello, " + "world!");
```

## Functions, object mutation, and recursion

C always passes arguments by value. Passing a pointer allows a function to modify the pointed-to object. JavaScript also passes arguments by value; an object value is a reference, so its properties can be mutated.

### C

```c
#include <stdio.h>

void set_value(int *value) { *value = 10; }
unsigned factorial(unsigned n) { return n < 2 ? 1 : n * factorial(n - 1); }

int main(void) {
    int value = 5;
    set_value(&value);
    printf("value=%d factorial=%u\n", value, factorial(5));
    return 0;
}
```

### JavaScript

```javascript
function setValue(box) { box.value = 10; }
function factorial(n) { return n < 2 ? 1 : n * factorial(n - 1); }

const box = { value: 5 };
setValue(box);
console.log(`value=${box.value} factorial=${factorial(5)}`);
```

## Structures and classes

C structs contain data but do not have methods or access modifiers. JavaScript classes combine data and methods; private fields use `#`.

### C

```c
#include <stdio.h>

typedef struct { int width, height; } Rectangle;
int area(Rectangle rectangle) { return rectangle.width * rectangle.height; }

int main(void) {
    Rectangle rectangle = {5, 3};
    printf("area=%d\n", area(rectangle));
    return 0;
}
```

### JavaScript

```javascript
class Rectangle {
  #width;
  #height;
  constructor(width, height) { this.#width = width; this.#height = height; }
  area() { return this.#width * this.#height; }
}
console.log(`area=${new Rectangle(5, 3).area()}`);
```

## Sorting algorithms

### C

```c
#include <stdio.h>

void insertion_sort(int values[], size_t n) {
    for (size_t i = 1; i < n; ++i) {
        int key = values[i];
        size_t j = i;
        while (j > 0 && values[j - 1] > key) {
            values[j] = values[j - 1];
            --j;
        }
        values[j] = key;
    }
}

int main(void) {
    int values[] = {8, 3, 11, 2, 1};
    size_t n = sizeof values / sizeof values[0];
    insertion_sort(values, n);
    for (size_t i = 0; i < n; ++i) printf("%d%c", values[i], i + 1 == n ? '\n' : ' ');
    return 0;
}
```

### JavaScript

```javascript
function insertionSort(values) {
  for (let i = 1; i < values.length; i += 1) {
    const key = values[i];
    let j = i;
    while (j > 0 && values[j - 1] > key) {
      values[j] = values[j - 1];
      j -= 1;
    }
    values[j] = key;
  }
  return values;
}
console.log(insertionSort([8, 3, 11, 2, 1]));
```

The same pairing principle applies to bubble, selection, and merge sort: only the language syntax and storage details change; the algorithms do not.

## Binary search and bounds

### C

```c
#include <stdio.h>

int lower_bound(const int values[], int n, int target) {
    int low = 0, high = n;
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (values[middle] < target) low = middle + 1;
        else high = middle;
    }
    return low;
}

int main(void) {
    int values[] = {2, 4, 4, 8, 10};
    printf("first position not below 4: %d\n", lower_bound(values, 5, 4));
    return 0;
}
```

### JavaScript

```javascript
function lowerBound(values, target) {
  let low = 0;
  let high = values.length;
  while (low < high) {
    const middle = low + Math.floor((high - low) / 2);
    if (values[middle] < target) low = middle + 1;
    else high = middle;
  }
  return low;
}
console.log("first position not below 4:", lowerBound([2, 4, 4, 8, 10], 4));
```

For an upper bound, change the comparison to `values[middle] <= target`.

## Fibonacci and divisor functions

### C

```c
#include <stdio.h>

unsigned fibonacci(unsigned n) {
    if (n < 2) return n;
    unsigned previous = 0, current = 1;
    for (unsigned i = 2; i <= n; ++i) {
        unsigned next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

unsigned gcd(unsigned a, unsigned b) {
    while (b) { unsigned remainder = a % b; a = b; b = remainder; }
    return a;
}

int main(void) {
    printf("fib(7)=%u gcd(24,18)=%u\n", fibonacci(7), gcd(24, 18));
    return 0;
}
```

### JavaScript

```javascript
function fibonacci(n) {
  let previous = 0;
  let current = 1;
  for (let i = 2; i <= n; i += 1) [previous, current] = [current, previous + current];
  return n === 0 ? 0 : current;
}

function gcd(a, b) {
  while (b !== 0) [a, b] = [b, a % b];
  return Math.abs(a);
}
console.log(`fib(7)=${fibonacci(7)} gcd(24,18)=${gcd(24, 18)}`);
```

## Modular exponentiation

### C

```c
#include <stdio.h>
#include <stdint.h>

uint64_t mod_power(uint64_t base, uint64_t exponent, uint64_t modulus) {
    uint64_t result = 1 % modulus;
    base %= modulus;
    while (exponent) {
        if (exponent & 1u) result = result * base % modulus;
        base = base * base % modulus;
        exponent >>= 1;
    }
    return result;
}

int main(void) {
    printf("%llu\n", (unsigned long long)mod_power(2, 10, 1000));
    return 0;
}
```

### JavaScript

```javascript
function modPower(base, exponent, modulus) {
  let result = 1n % modulus;
  base %= modulus;
  while (exponent > 0n) {
    if (exponent & 1n) result = result * base % modulus;
    base = base * base % modulus;
    exponent >>= 1n;
  }
  return result;
}
console.log(modPower(2n, 10n, 1000n).toString());
```

## Stack and queue

### C

```c
#include <stdio.h>

#define CAPACITY 8
typedef struct { int data[CAPACITY]; int size; } Stack;
typedef struct { int data[CAPACITY]; int front, size; } Queue;

void stack_push(Stack *stack, int value) { if (stack->size < CAPACITY) stack->data[stack->size++] = value; }
int stack_pop(Stack *stack) { return stack->data[--stack->size]; }
void enqueue(Queue *queue, int value) {
    if (queue->size < CAPACITY) queue->data[(queue->front + queue->size++) % CAPACITY] = value;
}
int dequeue(Queue *queue) {
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % CAPACITY;
    --queue->size;
    return value;
}

int main(void) {
    Stack stack = {0};
    Queue queue = {0};
    stack_push(&stack, 10); stack_push(&stack, 20);
    enqueue(&queue, 10); enqueue(&queue, 20);
    printf("stack=%d queue=%d\n", stack_pop(&stack), dequeue(&queue));
    return 0;
}
```

### JavaScript

```javascript
const stack = [];
stack.push(10, 20);

const queue = [];
queue.push(10, 20);

console.log(`stack=${stack.pop()} queue=${queue.shift()}`);
```

JavaScript's `shift()` is O(n) for ordinary arrays. For a high-volume queue, store a separate front index or use a deque implementation.

## Set and pair-like values

### C

C has no standard set or pair container, so a small array and struct can represent them for simple cases.

```c
#include <stdio.h>

typedef struct { const char *name; int age; } Student;

int main(void) {
    int set[8], size = 0;
    int input[] = {5, 2, 8, 2};
    for (int i = 0; i < 4; ++i) {
        int exists = 0;
        for (int j = 0; j < size; ++j) if (set[j] == input[i]) exists = 1;
        if (!exists) set[size++] = input[i];
    }
    Student student = {"Alice", 25};
    printf("unique=%d student=%s/%d\n", size, student.name, student.age);
    return 0;
}
```

### JavaScript

```javascript
const set = new Set([5, 2, 8, 2]);
const student = ["Alice", 25];
console.log(`unique=${set.size} student=${student[0]}/${student[1]}`);
```

## C++-specific examples

The original guide also demonstrates `std::vector`, `std::stack`, `std::queue`, `std::priority_queue`, iterators, `std::set`, and `std::pair`. These are C++ Standard Library types, so they do not have direct C equivalents. The paired sections above show comparable C data structures and JavaScript built-ins without pretending that their APIs are identical.
