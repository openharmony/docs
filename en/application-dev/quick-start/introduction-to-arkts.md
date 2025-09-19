# Introduction

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @LeechyLiang-->
<!--Designer: @qyhuo32-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @zhang_yixin13-->

Welcome to the tutorial for ArkTS, a TypeScript-based programming language designed specifically to build high-performance mobile applications! ArkTS is optimized to provide better performance and efficiency, while still maintaining the familiar syntax of TypeScript.

Many current programming languages were not designed with mobile devices in mind, resulting in slow and inefficient applications that drain battery life. As mobile devices continue to become more prevalent in our daily lives, there is a growing need for programming languages optimized for the mobile environment. ArkTS has been specifically designed to address such concerns by prioritizing higher execution efficiency.

ArkTS is based on the popular programming language TypeScript that extends JavaScript by adding type definitions. TypeScript is well-loved by many developers as it provides a more structured approach to coding in JavaScript. ArkTS aims to keep the look and feel of TypeScript to enable a seamless transition for the existing TypeScript developers, and to let mobile developers learn ArkTS quickly.

One of the key features of ArkTS is its focus on low runtime overhead. ArkTS imposes stricter limitations on the TypeScript's dynamically typed features, reducing runtime overhead and allowing faster execution. By eliminating the dynamically typed features from the language, ArkTS code can be compiled ahead-of-time more efficiently, resulting in faster application startup and lower power consumption.

Interoperability with TypeScript and JavaScript was a critical consideration in the ArkTS language design. Many mobile application developers already have TypeScript and JavaScript code and libraries they would want to reuse. ArkTS has been designed for seamless JavaScript interoperability, making it easy for the developers to integrate the JavaScript code into their applications and vice versa. This will allow the developers to use their existing codebases and libraries to leverage the power of our new language.

This tutorial will guide you through the core features, syntax, and best practices of ArkTS. After reading this tutorial through the end, you will be able to build performant and efficient mobile applications in ArkTS.

For a more detailed understanding of the ArkTS language, see [Introduction to ArkTS](../arkts-utils/arkts-overview.md)<!--RP1--><!--RP1End-->.

## The Basics

### Declarations

Declarations in ArkTS allow you to introduce variables, constants, types, and functions.

**Variable declaration**

A declaration starting with the keyword **let** introduces a variable which can have different values during program execution.

```typescript
let hi: string = 'hello';
hi = 'hello, world';
```

**Constant declaration**

A declaration starting with the keyword **const** introduces a read-only constant that can be assigned only once.

```typescript
const hello: string = 'hello';
```

A compile-time error occurs if a new value is assigned to a constant.

**Automatic type inference**

You do not need to explicitly specify the type of a declared entity if a variable or a constant declaration contains an initial value, as all cases that allow the type to be inferred automatically are specified in the ArkTS Specification.

Both variable declarations are valid, and both variables are of the string type:

```typescript
let hi1: string = 'hello';
let hi2 = 'hello, world';
```

### Types

**Basic types and reference types**

Basic types include number and string, which can accurately represent simple data types. You can directly store and access these types and compare their values.

Reference types include complex data structures such as objects, arrays, and functions. These types access data by reference. An object and array contain multiple values or KV pairs, and a function encapsulates executable code logic. The reference type accesses data in the memory through pointers. Changing the reference affects the original data.

**Number type**

ArkTS has the number type. Any integer and floating-point values can be assigned to a variable of this type.

Numeric literals include integer literals and floating-point literals with the decimal base.

Integer literals are classified into the following:

* Decimal integers that consist of a sequence of digits. Example: **0**, **117**, **-345**.
* Hexadecimal integers that start with 0x (or 0X), and can contain digits (0-9) and letters a-f or A-F. Example: **0x1123**, **0x00111**, **-0xF1A7**.
* Octal integers that start with 0o (or 0O) and can only contain digits (0-7). Example: **0o777**.
* Binary integers that start with 0b (or 0B), and can only contain the digits 0 and 1. Example: **0b11**, **0b0011**, **-0b11**.

A floating-point literal includes the following:

* Decimal integer, optionally signed (that is, prefixed with "+" or "-")
* Decimal point (".")
* Fractional part (represented by a string of decimal digits)
* Exponent part that starts with "e" or "E", followed by an optionally signed (that is, prefixed with "+" or "-") integer

Example:

```typescript
let n1 = 3.14;
let n2 = 3.141592;
let n3 = .5;
let n4 = 1e2;

function factorial(n: number): number {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

factorial(n1)  //  7.660344000000002 
factorial(n2)  //  7.680640444893748 
factorial(n3)  //  1 
factorial(n4)  //  9.33262154439441e+157 
```

The number type tends to lose precision when it represents very large integers (ranging from -9007199254740991 to 9007199254740991). You can use the bigint type to ensure the precision as required.

```typescript

let bigInt: BigInt = BigInt('999999999999999999999999999999999999999999999999999999999999');
console.info('bigInt:' + bigInt.toString());

```

**Boolean type**

The Boolean type represents logical values that are either **true** or **false**.

Usually variables of this type are used in conditional statements:

```typescript
let isDone: boolean = false;

// ...

if (isDone) {
  console.info('Done!');
}
```

**String type**

A string is a sequence of characters; some characters can be set by using escape sequences.

A string literal consists of zero or more characters enclosed in single (') or double quotes ("). The special form of a string literal is the template literal enclosed in backticks (\`).

```typescript
let s1 = 'Hello, world!\n';
let s2 = "this is a string";
let a = 'Success';
let s3 = `The result is ${a}`;
```

**Void type**

The void type is used to specify that a function does not return a value.
This type has the only one value which is also void. As void is a reference type, it can be used as type argument for generic types.

```typescript
class Class<T> {
  //...
}
let instance: Class <void>
```

**Object type**

An Object type is a base type for all reference types. Any value, including values of primitive types (they will be automatically boxed), can be directly assigned to variables of the type Object. The Object type is used to represent types other than the primitive types.
```typescript
let o1: Object = 'Alice';
let o2: Object = ['a','b'];
let o3: Object = 1;
```

**Array type**

An array is an object comprised of elements of data types assignable to the element type specified in the array declaration.
A value of an array is set by using array composite literal, which is a list of zero or more expressions enclosed in square brackets ([]). Each expression represents an element of the array. The length of the array is set by the number of expressions. Index of the first array element is 0.

The following example creates the array with three elements:

```typescript
let names: string[] = ['Alice', 'Bob', 'Carol'];
```

**Enum type**

An enum type is a value type with a defined set of named values called enum constants.
In order to be used, an enum constant must be prefixed with an enum type name.

```typescript
enum ColorSet { Red, Green, Blue }
let c: ColorSet = ColorSet.Red;
```

A constant expression can be used to explicitly set the value of an enum constant.

```typescript
enum ColorSet { White = 0xFF, Grey = 0x7F, Black = 0x00 }
let c: ColorSet = ColorSet.Black;
```

**Union type**

A Union type is a reference type which is created as a combination of multiple types. Values of union types can be valid values of all types a union was created from.

```typescript
class Cat {
  name: string = 'cat';
  // ...
}
class Dog {
  name: string = 'dog';
  // ...
}
class Frog {
  name: string = 'frog';
  // ...
}
type Animal = Cat | Dog | Frog | number | string | null | undefined;
// Cat, Dog, and Frog are some types (classes or interfaces).

let animal: Animal = new Cat();
animal = new Frog();
animal = 42;
animal = 'dog';
animal = undefined;
// One may assign the variable of the union type with any valid value.
```

There are different mechanisms to get a value of a particular type from a union.

Example:

```typescript
class Cat { sleep () {}; meow () {} }
class Dog { sleep () {}; bark () {} }
class Frog { sleep () {}; leap () {} }

type Animal = Cat | Dog | Frog;

function foo(animal: Animal) {
  if (animal instanceof Frog) {
    animal.leap(); // animal is of type Frog here.
  }
  animal.sleep(); // Any animal can sleep.
}
```

**Aliases type**

Type Aliases provides names for anonymous types (such as array, function, object literal or union type) or alternative names for existing types.

```typescript
type Matrix = number[][];
type Handler = (s: string, no: number) => string;
type Predicate <T> = (x: T) => boolean;
type NullableObject = Object | null;
```

### Operators

Assignment operators

Simple assignment operator **=** is used as in **x = y**.

Compound assignment operators combine an assignment with an operator. For example, **a += b** equals **a = a + b**,

where **+=** is a compound assignment operator.

Compound assignment operators are as follows: **+=**, **-=**, ***=**, **/=**, **%=**, **<<=**, **>>=**, **>>>=**, **&=**, **|=**, and **^=**.

**Comparison operators**

| Operator| Description                                                |
| -------- | ------------------------------------------------------------ |
| `===`    | Returns **true** if both operands are strict equal. (Operands of different types are considered unequal.)|
| `!==`    | Returns **true** if both operands are not strict equal. (Operands of different types are considered unequal.)|
| `==`     | Returns **true** if both operands are equal.|
| `!=`     | Returns **true** if both operands are not equal.   |
| `>`      | Returns **true** if the left operand is greater than the right.|
| `>=`     | Returns **true** if the left operand is greater than or equal to the right.|
| `<`      | Returns **true** if the left operand is less than the right.   |
| `<=`     | Returns **true** if the left operand is less than or equal to the right.|

The differences between **===** and **==** are as follows:
```typescript
// == compares only the values.
console.info(String(null == undefined)); // true
// === compares the values and types.
console.info(String(null === undefined)); // false
```


**Arithmetic operators**

Unary operators are as follows: **-**, **+**, **--**, and **++**.

Binary operators are as follows:

| Operator| Description            |
| -------- | ------------------------ |
| `+`      | Addition               |
| `-`      | Subtraction            |
| `*`      | Multiplication         |
| `/`      | Division               |
| `%`      | Remainder after division|

**Bitwise operators**

| Operator| Description                                                |
| --------- | ------------------------------------------------------------ |
| `a & b`   | Bitwise AND: sets each bit to 1 if the corresponding bits of both operands are 1, otherwise to 0.|
| `a | b`  | Bitwise OR: sets each bit to 1 if at least one of the corresponding bits of both operands is 1, otherwise to 0.|
| `a ^ b`   | Bitwise XOR: sets each bit to 1 if the corresponding bits of both operands are different, otherwise to 0.|
| `~ a`     | Bitwise NOT: inverts the bits of the operand.              |
| `a << b`  | Shift left: shifts the binary representation of *a* to the left by *b* bits.|
| `a >> b`  | Arithmetic right shift: shifts the binary representation of *a* to the right by *b* bits with sign-extension.|
| `a >>> b` | Logical right shift: shifts the binary representation of *a* to the right by *b* bits with zero-extension.|

**Logical operators**

| Operator | Description|
| ---------- | ----------- |
| `a && b`   | Logical AND|
| `a || b` | Logical OR|
| `! a`      | Logical NOT|

### Statements

**If statement**

An **if** statement is used to execute a sequence of statements when a logical condition is true, or another set of statements (if provided) otherwise.
The **else** part can also contain more **if** statements.

An **if** statement is as follows:

```typescript
if (condition1) {
  // Statement 1
} else if (condition2) {
  // Statement 2
} else {
  // The else statement
}
```

All conditional expressions must be of any type. For types other than Boolean, implicit conversion rules are applied:

```typescript
let s1 = 'Hello';
if (s1) {
  console.info(s1); // Print "Hello"
}

let s2 = 'World';
if (s2.length != 0) {
  console.info(s2); // Print "World"
}
```

**Switch statement**

A **switch** statement is used to execute a sequence of statements that match the value of a **switch** expression.

The **switch** statement is as follows:

```typescript
switch (expression) {
  case label1: // Execute if label1 is matched.
    // ...
    // Statement 1
    // ...
    break; // Can be omitted.
  case label2:
  case label3: // Execute if label2 or label3 is matched.
    // ...
    // Statement 23
    // ...
    break; // Can be omitted.
  default:
    // Default statement
}
```

If the value of a **switch** expression equals the value of a certain label, then the corresponding statements are executed.

If there is no match, and the **switch** has the **default** clause, then the **default** statements are executed.

An optional **break** statement allows you to break out of the **switch** and continue executing the statement that follows the **switch**.

If there is no **break**, then the next statements in the **switch** are executed.

**Conditional expressions**

A conditional expression returns the result of one of the other two expressions based on the Boolean value of the first expression.

A conditional expression looks as follows:

```typescript
condition ? expression1 : expression2
```

If the value of **condition** is truthy (a value that is considered **true**), the **expression1** is used as the result of the expression; otherwise, the **expression2** is used.

Example:

```typescript
let message = Math.random() > 0.5 ? 'Valid' : 'Failed';
```

If the value of **condition** is not a Boolean value, implicit conversion is performed.

Example:

```typescript
    console.info('a' ? 'true' : 'false'); // true
    console.info('' ? 'true' : 'false'); // false
    console.info(1 ? 'true' : 'false'); // true
    console.info(0 ? 'true' : 'false'); // false
    console.info(null ? 'true' : 'false'); // false
    console.info(undefined ? 'true' : 'false'); // false
```

**For statement**

The **for** statement is executed repeatedly until the specified loop exit condition result is **false**.

The **for** statement is as follows:

```typescript
for ([init]; [condition]; [update]) {
  statements
}
```

When a **for** statement is executed, the following process takes place:

1. An **init** expression is executed, if any. This expression usually initializes one or more loop counters. 
2. The **condition** is evaluated. If the value of **condition** is truthy (a value that is considered **true**), or if the conditional expression is omitted, the statements in the **for** body are to be executed. If the value of **condition** is falsy (a value that is considered **false**), the **for** loop terminates. 
3. The statements of the **for** body are executed.
4. If there is an **update** expression, then the **update** expression is executed. 
5. Go back to step 2.

Example:

```typescript
let sum = 0;
for (let i = 0; i < 10; i += 2) {
  sum += i;
}
```

**For-of statement**

You can use the **for-of** statement to iterate over iterable types such as array, Set, Map, and string. A **for-of** statement looks as follows:

```typescript
for (forVar of IterableExpression) {
  // process forVar
}
```

Example:

```typescript
for (let ch of 'a string object') {
  console.info(ch);
}
```

**While statement**

The **while** statement executes **statements** as long as the value of **condition** is **true**. A **while** statement looks as follows:

```typescript
while (condition) {
  statements
}
```

Example:

```typescript
let n = 0;
let x = 0;
while (n < 3) {
  n++;
  x += n;
}
```

**Do-while statement**

If the value of **condition** is truthy (a value that is considered **true**), the **statements** is executed repeatedly. A **do-while** statement looks as follows:

```typescript
do {
  statements
} while (condition)
```

Example:

```typescript
let i = 0;
do {
  i += 1;
} while (i < 10)
```

**Break statement**

A **break** statement is used to terminate any loop statement or the **switch** statement.

A **break** statement looks as follows:

```typescript
let x = 0;
while (true) {
  x++;
  if (x > 5) {
    break;
  }
}
```

A **break** statement with a label identifier transfers control out of the enclosing statement to the one which has the same label identifier.

Example:

```typescript
let x = 1;
label: while (true) {
  switch (x) {
    case 1:
      // statements
      break label; // Break the while statement.
  }
}
```

**Continue statement**

A **continue** statement stops the execution of the current loop iteration and passes control to the next iteration.

A **continue** statement looks as follows:

```typescript
let sum = 0;
for (let x = 0; x < 100; x++) {
  if (x % 2 == 0) {
    continue;
  }
  sum += x;
}
```

**Throw and Try statements**

A **throw** statement is used to throw an exception or an error:

```typescript
throw new Error('this error')
```

A **try** statement is used to catch and handle an exception or an error:

```typescript
try {
  // Statement block where an exception may occur
} catch (e) {
  // Handle the exception.
}
```

The example below shows the **throw** and **try** statements used to handle the zero division case:

```typescript
class ZeroDivisor extends Error {}

function divide (a: number, b: number): number{
  if (b == 0) throw new ZeroDivisor();
  return a / b;
}

function process (a: number, b: number) {
  try {
    let res = divide(a, b);
    console.info('result: ' + res);
  } catch (x) {
    console.error('some error');
  }
}
```

**finally** clause is also supported:

```typescript
function processData(s: string) {
  let error: Error | null = null;

  try {
    console.info('Data processed: ' + s);
    // ...
    // Statement where an exception may occur
    // ...
  } catch (e) {
    error = e as Error;
    // ...
    // Handle the exception.
    // ...
  } finally {
    // Code that is executed regardless of whether an exception occurs
    if (error != null) {
      console.error(`Error caught: input='${s}', message='${error.message}'`);
    }
  }
}
```

## Function

### Function Declaration

A function declaration introduces a named function, specifying its name, parameters, return type and body.

Below is a simple function with two string parameters and string return type:

1. Parameter type annotation: **x: string, y: string** explicitly specifies the parameter type as string.

2. Return value type: **: string** specifies the return value type of the function as string.

```typescript
function add(x: string, y: string): string {
  let z: string = `${x} ${y}`;
  return z;
}
```

For every parameter, its type annotation must be specified. An optional parameter allows you to omit this parameter when calling a function. The last parameter of a function can be a rest parameter.

### Optional Parameter

The format of the optional parameter can be **name?: Type**.

```typescript
function hello(name?: string) {
  if (name == undefined) {
    console.info('Hello!');
  } else {
    console.info(`Hello, ${name}!`);
  }
}
```

Another form contains an expression that specifies a default value. If the optional parameter is omitted in a function call, the default value of the parameter is used as the argument.

```typescript
function multiply(n: number, coeff: number = 2): number {
  return n * coeff;
}
multiply(2);  // Return 2*2.
multiply(2, 3); // Return 2*3.
```

### Rest Parameter

The last parameter of a function can be a rest parameter in the format of **...restArgs**. It allows functions to take unlimited number of arguments of any specified type.

```typescript
function sum(...numbers: number[]): number {
  let res = 0;
  for (let n of numbers)
    res += n;
  return res;
}

sum(); // Return 0.
sum(1, 2, 3); // Return 6.
```

### Return Type

If function return type can be inferred from its body content, then it can be omitted from the function declaration.

```typescript
// Explicit return type
function foo(): string { return 'foo'; }

// Implicit return type inferred as string
function goo() { return 'goo'; }
```

The return type of a function that does not need to return a value can be explicitly specified as **void** or omitted altogether. No return statement is needed for such functions.

Both notations below are valid:

```typescript
function hi1() { console.info('hi'); }
function hi2(): void { console.info('hi'); }
```

### Function Scope

Variables and other entities defined in a function are local to the function and cannot be accessed from the outside.

If the name of a variable defined in the function is equal to the name of an entity in the outer scope, then the local definition shadows the outer entity.

```typescript
let outerVar = 'I am outer ';

function func() {
    let outerVar = 'I am inside';
    console.info(outerVar); // Output: I am inside
}

func();
```

### Function Call

Calling a function actually leads to the execution of its body, while the arguments of the call are assigned to the function parameters.

If the function is defined as follows:

```typescript
function join(x: string, y: string): string {
  let z: string = `${x} ${y}`;
  return z;
}
```

Then this function is called with two parameters of the type **string**:

```typescript
let x = join('hello', 'world');
console.info(x); // Output: hello world
```

### Function Type

A Function type is commonly used as follows to define a callback:

```typescript
type trigFunc = (x: number) => number // This is a function type.

function do_action(f: trigFunc) {
  f(3.141592653589); // Call the function.
}

do_action(Math.sin); // Pass in the function as a parameter.
```

### Arrow Function (Lambda Function)

A function can be defined as an arrow function. Example:

```typescript
let sum = (x: number, y: number): number => {
  return x + y;
}
```

An arrow function return type can be omitted; in such case, it is inferred from the function body.

An expression can be specified as an arrow function to make the notation shorter, that is, the following two notations are equivalent:

```typescript
let sum1 = (x: number, y: number) => { return x + y; }
let sum2 = (x: number, y: number) => x + y
```

### Closure

A closure is the combination of a function and the lexical environment within which that function was declared. This environment consists of any local variables that were in-scope at the time the closure was created.

In the following example, the **f** function returns a closure that captures the **count** variable. Each time **z** is called, the value of **count** is retained and incremented.

```typescript
function f(): () => number {
  let count = 0;
  let g = (): number => { count++; return count; };
  return g;
}

let z = f();
z(); // Return 1.
z(); // Return 2.
```

### Function Overload Signature

A function can be specified to be called in different ways by writing overload signatures. To do so, several functions' headers that have the same name but different signatures are written to the same function and immediately followed by the single implementation function.

```typescript
function foo(x: number): void;            /* First function definition */
function foo(x: string): void;            /* Second function definition */
function foo(x: number | string): void {  /* Implementation signature */
}

foo(123);     // Use the first function definition.
foo('aa'); // Use the second function definition.
```

An error occurs if two overload signatures have identical names and parameter lists.

## Class

A class declaration introduces a new type and defines its fields, methods and constructors.

In the following example, class **Person** is defined, which has fields **name** and **surname**, constructor, and the **fullName** method:

```typescript
class Person {
  name: string = '';
  surname: string = '';
  constructor (n: string, sn: string) {
    this.name = n;
    this.surname = sn;
  }
  fullName(): string {
    return this.name + ' ' + this.surname;
  }
}
```

After the class is defined, its instances can be created by using the keyword **new**:

```typescript
let p = new Person('John', 'Smith');
console.info(p.fullName());
```

Alternatively, an instance can be created by using object literals:

```typescript
class Point {
  x: number = 0;
  y: number = 0;
}
let p: Point = {x: 42, y: 42};
```

### Field

A field is a variable of some type that is declared directly in a class.

Classes may have instance fields or static fields.

**Instance fields**

Instance fields exist on every instance of a class. Each instance has its own set of instance fields.

An instance of the class is used to access an instance field.

```typescript
class Person {
  name: string = '';
  age: number = 0;
  constructor(n: string, a: number) {
    this.name = n;
    this.age = a;
  }

  getName(): string {
    return this.name;
  }
}

let p1 = new Person('Alice', 25);
p1.name; // Alice
let p2 = new Person('Bob', 28);
p2.getName(); // Bob
```

**Static fields**

The keyword **static** is used to declare a field as static. Static fields belong to the class itself, and all instances of the class share one static field.

The class name is used to access a static field:

```typescript
class Person {
  static numberOfPersons = 0;
  constructor() {
     // ...
     Person.numberOfPersons++;
     // ...
  }
}

Person.numberOfPersons;
```

**Field initializers**

ArkTS requires that all fields are explicitly initialized with some values either when the field is declared or in the **constructor**.
This is similar to **strictPropertyInitialization** mode of the standard TypeScript. Such behavior is enforced to minimize the number of unexpected runtime errors and achieve better performance.

The following code (invalid in ArkTS) is error-prone:

```typescript
class Person {
  name: string; // undefined
  
  setName(n:string): void {
    this.name = n;
  }
  
  getName(): string {
    // Return type "string" hides the fact that name can be undefined.
    // The most correct action would be to write the return type as "string | undefined". By doing so, we could tell the users of our API about all possible return values.
    return this.name;
  }
}

let jack = new Person();
// Assume that name is not assigned with a value, that is, jack.setName('Jack') is not called.
jack.getName().length; // Runtime exception: name is undefined.
```

In ArkTS, you should write code as follows:

```typescript
class Person {
  name: string = '';
  
  setName(n:string): void {
    this.name = n;
  }
  
  // The type is string in all cases, null and undefined are impossible.
  getName(): string {
    return this.name;
  }
}
  

let jack = new Person();
// Assume that name is not assigned with a value, that is, jack.setName('Jack') is not called.
jack.getName().length; // 0, no runtime error.
```

The following shows how our code behaves if the field **name** can be **undefined**:

```typescript
class Person {
  name?: string; // The field may be undefined.

  setName(n:string): void {
    this.name = n;
  }

  // Compilation error: name can be undefined. Therefore, the return value type of the API cannot be defined as string only.
  getNameWrong(): string {
    return this.name;
  }

  getName(): string | undefined { // Return type matches the type of name.
    return this.name;
  }
}

let jack = new Person();
// Assume that name is not assigned with a value, that is, jack.setName('Jack') is not called.

// Compile-time error: Compiler suspects that the next line of code possibly accesses something undefined.
jack.getName().length;  // Compilation failed.

jack.getName()?.length; // Successful compilation and no runtime error.
```

**getter and setter**

**setter** and **getter** can be used to provide controlled access to object properties.

In the following example, a **setter** is used to forbid setting invalid values of the **_age** property:

```typescript
class Person {
  name: string = '';
  private _age: number = 0;
  get age(): number { return this._age; }
  set age(x: number) {
    if (x < 0) {
      throw Error('Invalid age argument');
    }
    this._age = x;
  }
}

let p = new Person();
p.age; // Output 0.
p.age = -42; // Error will be thrown as an attempt to set incorrect age.
```

A class can define a **getter** or a **setter**.

### Method

A method is a function that belongs to a class. A class can define instance methods, static methods or both. A static method belongs to the class itself, and can have access to static fields only. A **while** instance method has access to both static (class) fields and instance fields including private ones of its class.

**Instance method**

The example below illustrates how instance methods work.

The **calculateArea** method calculates the area of a rectangle by multiplying the height by the width:

```typescript
class RectangleSize {
  private height: number = 0;
  private width: number = 0;
  constructor(height: number, width: number) {
    this.height = height;
    this.width = width;
  }
  calculateArea(): number {
    return this.height * this.width;
  }
}
```

To use an instance method, it must be called on an instance of the class:

```typescript
let square = new RectangleSize(10, 10);
square.calculateArea(); // Output: 100
```

**Static method**

The keyword **static** is used to declare a method as static. A static method belongs to the class itself and have access to static fields only.

A static method defines a common behavior of the class as a whole.

The class name is used to call a static method.

```typescript
class Cl {
  static staticMethod(): string {
    return 'this is a static method.';
  }
}
console.info(Cl.staticMethod());
```

**Inheritance**

A class can extend another class (called base class) and implement multiple APIs using the following syntax:

```typescript
class [extends BaseClassName] [implements listOfInterfaces] {
  // ...
}
```

An inheritance class extends the fields and methods of the base class, but does not extend the constructor. An inheritance class allows you to define new fields and methods or override the methods defined by the base class.

The class that is being extended by another class is called 'base class', 'parent class', or 'superclass'. The class that extends another class is called 'extended class', 'derived class', or 'child class'.

Example:

```typescript
class Person {
  name: string = '';
  private _age = 0;
  get age(): number {
    return this._age;
  }
}
class Employee extends Person {
  salary: number = 0;
  calculateTaxes(): number {
    return this.salary * 0.42;
  }
}
```

A class containing the **implements** clause must implement all methods defined in all listed APIs, except the methods defined with default implementation.

```typescript
interface DateInterface {
  now(): string;
}
class MyDate implements DateInterface {
  now(): string {
    // Here is the implementation.
    return 'now';
  }
}
```

**Access to super**

The keyword **super** can be used to access instance fields, instance methods and constructors from the super class. It is often used to extend basic functionality of child class with the required behavior taken from the super class:

```typescript
class RectangleSize {
  protected height: number = 0;
  protected width: number = 0;

  constructor (h: number, w: number) {
    this.height = h;
    this.width = w;
  }

  draw() {
    /* Draw bounds. */
  }
}
class FilledRectangle extends RectangleSize {
  color = ''
  constructor (h: number, w: number, c: string) {
    super(h, w); // Call of the super constructor.
    this.color = c;
  }

  draw() {
    super.draw(); // Call of the super method.
    // super.height can be used here.
    /* Fill the rectangle. */
  }
}
```

**Method overriding**

A child class can override implementation of a method defined in its superclass. An overridden method must have the same types of parameters, and same or derived return type as the original method.

```typescript
class RectangleSize {
  // ...
  area(): number {
    // Implementation
    return 0;
  }
}
class Square extends RectangleSize {
  private side: number = 0;
  area(): number {
    return this.side * this.side;
  }
}
```

**Method overload signature**

A method can be specified to be called in different ways by writing overload signatures. To do so, several methods' headers that have the same name but different signatures are written to the same method and immediately followed by the single implementation method.

```typescript
class C {
  foo(x: number): void;            /* First signature */
  foo(x: string): void;            /* Second signature */
  foo(x: number | string): void {  /* Implementation signature */
  }
}
let c = new C();
c.foo(123);     // Use the first signature.
c.foo('aa'); // Use the second signature.
```

An error occurs if two overload signatures have identical names and parameter lists.

### Constructor

A class declaration may contain a constructor that is used to initialize object state.

A constructor is defined as follows:

```typescript
constructor ([parameters]) {
  // ...
}
```

If no constructor is defined, then a default constructor with an empty parameter list is created automatically. Example:

```typescript
class Point {
  x: number = 0;
  y: number = 0;
}
let p = new Point();
```

In this case, the default constructor fills the instance fields with default values for the field types.

**Constructor in a derived class**

The first statement of a constructor body can use the keyword **super** to explicitly call a constructor of the direct superclass.

```typescript
class RectangleSize {
  constructor(width: number, height: number) {
    // ...
  }
}
class Square extends RectangleSize {
  constructor(side: number) {
    super(side, side);
  }
}
```

**Constructor overload signature**

A constructor can be specified to be called in different ways by writing overload signatures. To do so, several constructors' headers that have the same name but different signatures are written to the same constructor and immediately followed by the single implementation constructor.

```typescript
class C {
  constructor(x: number)             /* First signature */
  constructor(x: string)             /* Second signature */
  constructor(x: number | string) {  /* Implementation signature */
  }
}
let c1 = new C(123);      // Use the first signature.
let c2 = new C('abc');    // Use the second signature.
```

An error occurs if two overload signatures have identical names and parameter lists.

### Visibility Modifiers

Both methods and properties of a class can have visibility modifiers.

Visibility modifiers include **private**, **protected**, and **public**. The default visibility is **public**.

**Public**

The **public** members (fields, methods, constructors) of a class are visible in any part of the program, where their class is visible.

**Private**

A **private** member cannot be accessed outside the class where it is declared in. Example:

```typescript
class C {
  public x: string = '';
  private y: string = '';
  set_y (new_y: string) {
    this.y = new_y; // OK, as y is accessible within the class itself.
  }
}
let c = new C();
c.x = 'a'; // OK, as the field is public.
c.y = 'b'; // Compile-time error: 'y' is not visible.
```

**Protected**

The modifier **protected** acts much like the modifier **private**, but the **protected** members are also accessible in derived classes. Example:

```typescript
class Base {
  protected x: string = '';
  private y: string = '';
}
class Derived extends Base {
  foo() {
    this.x = 'a'; // Access the protected member.
    this.y = 'b'; // Compile-time error: 'y' is not visible, because it is private.
  }
}
```

### Object Literal

An object literal is an expression that can be used to create a class instance and provide some initial values. It can be used instead of the expression **new** as it is more convenient in some cases.

An object literal is a list of ***property name*: *value*** enclosed in a pair of curly brackets ({}).

```typescript
class C {
  n: number = 0;
  s: string = '';
}

let c: C = {n: 42, s: 'foo'};
```

ArkTS is a statically typed language. As shown in the preceding example, object literals can be used only in contexts where the literal type can be inferred. Other valid cases are illustrated below:

```typescript
class C {
  n: number = 0;
  s: string = '';
}

function foo(c: C) {}

let c: C

c = {n: 42, s: 'foo'};  // Use the variable type.
foo({n: 42, s: 'foo'}); // Use the parameter type.

function bar(): C {
  return {n: 42, s: 'foo'}; // Use the return type.
}
```

You can also use the object literals in array element types or class field types.

```typescript
class C {
  n: number = 0;
  s: string = '';
}
let cc: C[] = [{n: 1, s: 'a'}, {n: 2, s: 'b'}];
```

**Object literal of Record type**

The generic **Record<K, V>** type is used to map the properties of a type (Key type) to another type (Value type). A special form of object literal is used to initialize the value of such type:

```typescript
let map: Record<string, number> = {
  'John': 25,
  'Mary': 21,
}

map['John']; // 25
```

The **K** type can be either string or number (excluding bigint), while **V** can be any type.

```typescript
interface PersonInfo {
  age: number;
  salary: number;
}
let map: Record<string, PersonInfo> = {
  'John': { age: 25, salary: 10},
  'Mary': { age: 21, salary: 20}
}
```

### Abstract Class

A class with the modifier **abstract** is known as abstract class. Abstract classes can be used to represent notions that are common to some set of more concrete notions.

A compile-time error occurs if an attempt is made to create an instance of an abstract class:

```typescript
abstract class X {
  field: number;
  constructor(p: number) {
    this.field = p; 
  }
}

let x = new X(666)  // Compile-time error: Cannot create an instance of an abstract class.
```

Child classes of an abstract class can be non-abstract or in turn abstract. A non-abstract child class of an abstract parent class can be instantiated. As a result, a constructor for the abstract class, and field initializers for non-static fields of that class are executed:

```typescript
abstract class Base {
  field: number;
  constructor(p: number) { 
    this.field = p; 
  }
}

class Derived extends Base {
  constructor(p: number) {
    super(p); 
  }
}

let x = new Derived(666);
```

**Abstract method**

A method with the modifier **abstract** is considered an abstract method. Abstract methods do not have bodies, that is, they can be declared but not implemented.

Only abstract classes can have abstract methods. A compile-time error occurs if a non-abstract class has an abstract method:

```typescript
class Y {
  abstract method(p: string) // Compile-time error: Abstract methods can only appear within an abstract class.
}
```

## Interface

An interface declaration introduces a new type. Interfaces are a common way of defining contracts between various part of codes.

Interfaces are used to write polymorphic code, which can be applied to any class instances that implement a particular interface.

An interface usually contains properties and method declarations.

Example:

```typescript
interface Style {
  color: string; // Property
}
interface AreaSize {
  calculateAreaSize(): number; // Method declaration
  someMethod(): void;     // Method declaration
}
```

Example of a class implementing an interface:

```typescript
// Interface:
interface AreaSize {
  calculateAreaSize(): number; // Method declaration
  someMethod(): void;     // Method declaration
}

// Implementation
class RectangleSize implements AreaSize {
  private width: number = 0;
  private height: number = 0;
  someMethod(): void {
    console.info('someMethod called');
  }
  calculateAreaSize(): number {
    this.someMethod(); // Call another method and return the result.
    return this.width * this.height;
  }
}
```

### Interface Property

An interface property can be in a form of field, **getter**, **setter**, or both **getter** and **setter**.

A property field is just a shortcut notation of a **getter** or **setter** pair, and the following notations are equal:

```typescript
interface Style {
  color: string;
}
```

```typescript
interface Style {
  get color(): string;
  set color(x: string);
}
```

A class that implements an interface may also use a short or a long notation:

```typescript
interface Style {
  color: string;
}

class StyledRectangle implements Style {
  color: string = '';
}
```

```typescript
interface Style {
  color: string;
}

class StyledRectangle implements Style {
  private _color: string = '';
  get color(): string { return this._color; }
  set color(x: string) { this._color = x; }
}
```

### Interface Inheritance

An interface may extend other interfaces, as shown in the example below:

```typescript
interface Style {
  color: string;
}

interface ExtendedStyle extends Style {
  width: number;
}
```

An extended interface contains all properties and methods of the interface it extends, and can also add its own properties and methods.


### Abstract Class and Interface

Abstract classes and interfaces cannot be instantiated. Abstract classes are abstractions of classes, used to capture the general characteristics of child classes, and interfaces are abstractions of behavior. The differences between abstract classes and interfaces in ArkTS are as follows:

* A class can extend only one abstract class, but can implement one or more interfaces.
```typescript
// The Bird class extends the abstract class Animal and implements multiple interfaces CanFly and CanSwim.
class Bird extends Animal implements CanFly, CanSwim {
  // ...  
}
```
* An abstract class, instead of an interface, can contain static code blocks or static methods.
```typescript
interface MyInterface {
    // Error: The interface cannot contain static members.
    static staticMethod(): void; 

    // Error: The interface cannot contain static code blocks.
    static { console.info("static") }; 
} 

abstract class MyAbstractClass {
    // Correct: An abstract class can contain static methods.
    static staticMethod(): void { console.info("static");}

    // Correct: An abstract class can contain static code blocks.
    static { console.info("static initialization block");}
}
```
* In abstract classes, there can be implementations of methods, but interfaces are completely abstract and there is no implementation of methods.
```typescript
abstract class MyAbstractClass {
   // Correct: An abstract class can contain implementation of methods.
   func(): void { console.info("func");}
}
interface MyInterface {
   // Error: Interfaces are completely abstract and there is no implementation of methods.
   func(): void { console.info("func");}
}
```
* Abstract classes can have constructors, while interfaces cannot.
```typescript
abstract class MyAbstractClass {
  constructor(){}  // Correct: Abstract classes can have constructors.
}
interface MyInterface {
  constructor(); // Error: Interfaces cannot contain constructors.
}
```

## Generic Type and Function

Generic type and function enable code to operate on multiple data types in a type-safe way without writing repetitive logic for each type.

### Generic Class and Interface

A class and an interface can be defined as generics. Add parameters to the type definition, such as the type parameter **Element** in the following example:

```typescript
class CustomStack<Element> {
  public push(e: Element):void {
    // ...
  }
}
```

To use type **CustomStack**, the type argument must be specified for each type parameter:

```typescript
let s = new CustomStack<string>();
s.push('hello');
```

Compiler ensures type safety while working with generic types and functions. Refer to the example below:

```typescript
let s = new CustomStack<string>();
s.push(55); // A compile-time error is thrown.
```

### Generic Constraints

Type parameters of generic types can be bounded. For example, the **Key** type parameter in the **MyHashMap<Key, Value>** class must have the **hash** method.

```typescript
interface Hashable {
  hash(): number;
}
class MyHashMap<Key extends Hashable, Value> {
  public set(k: Key, v: Value) {
    let h = k.hash();
    // Other code is omitted here.
  }
}
```

In the above example, the **Key** type extends **Hashable**, and all methods of **Hashable** interface can be called for keys.

### Generic Function

Use a generic function to create a more universal code. Consider a function that returns the last element of the array:

```typescript
function last(x: number[]): number {
  return x[x.length - 1];
}
last([1, 2, 3]); // 3
```

If the same function needs to be defined for any array, then define it as a generic with a type parameter:

```typescript
function last<T>(x: T[]): T {
  return x[x.length - 1];
}
```

Now, the function can be used with any array.

In a function call, type argument can be set explicitly or implicitly:

```typescript
// Explicit type argument
let res: string = last<string>(['aa', 'bb']);
let res: number = last<number>([1, 2, 3]);

// Implicit type argument
// Compiler determines the type argument based on the type of the call arguments.
let res: number = last([1, 2, 3]);
```

### Generic Default

Type parameters of generic types can have defaults. It allows using just the generic type name instead of specifying the actual type arguments. The example below illustrates this feature of both class and function.

```typescript
class SomeType {}
interface Interface <T1 = SomeType> { }
class Base <T2 = SomeType> { }
class Derived1 extends Base implements Interface { }
// Derived1 is semantically equivalent to Derived2.
class Derived2 extends Base<SomeType> implements Interface<SomeType> { }

function foo<T = number>(): void {
  // ...
}
foo();
// Such function is semantically equivalent to the call below:
foo<number>();
```

## Null Safety

All types in ArkTS by default are non-nullable, so the value of a type cannot be null. It is similar to TypeScript behavior in strict null checking mode (**strictNullChecks**), but the rules in ArkTS are stricter.

In the following example, all lines lead to a compile-time error:

```typescript
let x: number = null;    // Compile-time error
let y: string = null;    // Compile-time error
let z: number[] = null;  // Compile-time error
```

A variable that can have a null value is defined with a union type **T | null**.

```typescript
let x: number | null = null;
x = 1;    // ok
x = null; // ok
if (x != null) { /* do something */ }
```

### Non-Null Assertion Operator

A postfix operator **!** can be used to assert that its operand is non-null.

When applied to a value of a nullable type, the type becomes non-nullable at compile time. For example, the type of the value is changed from **T | null** to **T**:

```typescript
class A {
  value: number = 0;
}

function foo(a: A | null) {
  a.value;   // Compile-time error: cannot access to a nullable value.
  a!.value;  // If the value of a is not null at runtime, the fields of a can be accessed; if the value of a is null at runtime, a runtime exception occurs.
}
```

### Null-Coalescing Operator

The null-coalescing binary operator **??** checks whether the evaluation of the left-hand-side expression is equal to **null** or **undefined**. If it is, the result of the expression is the right-hand-side expression; otherwise, it is the left-hand-side expression.

In other words, **a ?? b** equals the ternary operator **(a != null && a != undefined) ? a : b**.

In the following example, the **getNick** method returns a nickname if it is set; otherwise, an empty string is returned:

```typescript
class Person {
  // ...
  nick: string | null = null;
  getNick(): string {
    return this.nick ?? '';
  }
}
```

### Optional Chaining

If the object property is **undefined** or **null** when it is being accessed, the optional chaining operator returns **undefined**.

```typescript
class Person {
  nick: string | null = null;
  spouse?: Person

  setSpouse(spouse: Person): void {
    this.spouse = spouse;
  }

  getSpouseNick(): string | null | undefined {
    return this.spouse?.nick;
  }

  constructor(nick: string) {
    this.nick = nick;
    this.spouse = undefined;
  }
}
```

Note: The return type of **getSpouseNick** must be **string | null | undefined**, as the method can return **null** or **undefined**.

The optional chaining can be of any length and can contain any number of **?.** operators.

In the following example, if the **spouse** property of the **Person** instance and the **nick** property of **spouse** both are not null, the **spouse.nick** is output. Otherwise, **undefined** is output.

```typescript
class Person {
  nick: string | null = null;
  spouse?: Person;

  constructor(nick: string) {
    this.nick = nick;
    this.spouse = undefined;
  }
}

let p: Person = new Person('Alice');
p.spouse?.nick; // undefined
```

## Module

Programs are organized as sets of compilation units or modules.

Each module creates its own scope, that is, any declarations (variables, functions, classes, etc.) declared in the module are not visible outside that module unless they are explicitly exported.

Conversely, a variable, function, class, or interface exported from another module must first be imported to a module.

### Export

A top-level declaration can be exported by using the keyword **export**.

A declared name that is not exported is considered private and can be used only in the module where it is declared.

```typescript
export class Point {
  x: number = 0;
  y: number = 0;
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}
export let Origin = new Point(0, 0);
export function Distance(p1: Point, p2: Point): number {
  return Math.sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}
```
**Exporting default objects**
```typescript
class Demo{
  constructor(){
  }
}
export default new Demo();

```

### Import

**Static import**

Import declarations are used to import entities exported from other modules and provide their bindings in the current module. An import declaration consists of two parts:

* Import path that determines the module to import from.
* Import bindings that define the set of usable entities in the imported module, and the form of use (qualified or unqualified).

Import bindings may have several forms.

Let's assume a module has the path **./utils** and export entities **X** and **Y**.

An import binding of the form *** as A** binds the name **A**, and all entities exported from the module defined by the import path can be accessed by using the qualified name **A.name**:

```typescript
import * as Utils from './utils';
Utils.X // Denote X from Utils.
Utils.Y // Denote Y from Utils.
```

An import binding of the form **{ ident1, ..., identN }** binds an exported entity with a specified name, which can be used as a simple name:

```typescript
import { X, Y } from './utils';
X // Denote X from utils.
Y // Denote Y from utils.
```

If a list of identifiers contains an alias in the form **ident as alias**, the entity **ident** is bound under the name **alias**:

```typescript
import { X as Z, Y } from './utils';
Z // Denote X from Utils.
Y // Denote Y from Utils.
X // Compile-time error: 'X' is not visible.
```

**Dynamic import**
Unlike static import, dynamic import allows you to load a module conditionally or on demand.
The **import()** syntax, commonly called dynamic import, is a function-like expression that allows for dynamic loading of a module. A promise is returned when this method is invoked.
In the following example, **import(modulePath)** loads a module and returns a promise that resolves into a module object that contains all its exports. This expression can be called from any place in the code.

```typescript
// Calc.ts
export function add(a:number, b:number):number {
  let c = a + b;
  console.info('Dynamic import, %d + %d = %d', a, b, c);
  return c;
}

// Index.ts
import("./Calc").then((obj: ESObject) => {
  console.info(obj.add(3, 5));  
}).catch((err: Error) => {
  console.error("Module dynamic import error: ", err);
});
```

You can also use **let module = await import(modulePath)** inside an async function.

```typescript
// say.ts
export function hi() {
  console.info('Hello');
}
export function bye() {
  console.info('Bye');
}
```

Then dynamic import can be like this:

```typescript
async function test() {
  let ns = await import('./say');
  let hi = ns.hi;
  let bye = ns.bye;
  hi();
  bye();
}
```

For more details about dynamic import, see [Dynamic Import](../arkts-utils/arkts-dynamic-import.md).

<!--RP2--><!--RP2End-->

### Top-Level Statement

Top-level statements are those written at the outermost layer of a module, not wrapped by any function, class, or block scope. These statements include variable declarations, function declarations, and expressions.

## Keyword

### this

The keyword **this** can only be used in instance methods of a class.

**Example**

```typescript
class A {
  count: string = 'a';
  m(i: string): void {
    this.count = i;
  }
}
```

Constraints:

* Type notation using **this** is not supported.
* **this** is not allowed in functions and static methods of classes.

**Example**

```typescript
class A {
  n: number = 0;
  f1(arg1: this) {} // Compile-time error: Type notation using `this` is not supported.
  static f2(arg1: number) {
    this.n = arg1;  // Compile-time error: `this` is not allowed in the static methods of classes.
  }
}

function foo(arg1: number) {
  this.n = i;       // Compile-time error: `this` is not allowed in functions.
}
```

The keyword **this** used as a primary expression denotes a value that is a reference to the following:

* Object for which the instance method
* Object being constructed

## Annotation

Annotation is a language feature that changes the semantics of application declarations by adding metadata.
The declaration and usage of annotations are as follows:

**Example**

```typescript
// Declaration of an annotation:
@interface ClassAuthor {
  authorName: string
}

// Usage of an annotation:
@ClassAuthor({authorName: "Bob"})
class MyClass {
  // ...
}
```

- Use @interface to declare an annotation.
- The **ClassAuthor** annotation should add metadata to the class declaration.
- The annotation must be placed before the declaration.
- The annotation can contain the parameters shown in the preceding example.

The name of the annotation to be used must be prefixed with the **@** symbol (for example, **@MyAnno**). No space or line separator is allowed between the **@** symbol and the name.
```typescript
ClassAuthor({authorName: "Bob"}) // Compile-time error: The annotation must be prefixed with '@'.
@ ClassAuthor({authorName: "Bob"}) // Compile-time error: No space or line separator is allowed between the @ symbol and the name.
```
If the annotation name cannot be accessed, a compile-time error occurs.
Annotation declarations can be exported and used in other files.

Multiple annotations can be applied to the same declaration (the sequence of annotations does not affect the usage).
```typescript
@MyAnno()
@ClassAuthor({authorName: "John Smith"})
class MyClass {
  // ...
}
```
Annotations are not features in TypeScript and can be used only in .ets and .d.ets files.

> **Notice**
> 
> When you [build a source code HAR in release mode](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-har#section19788284410) and [enable obfuscation](../../application-dev/arkts-utils/source-obfuscation.md), the build products, which are JS files, will be removed during build due to the lack of an annotation implementation mechanism in JS. As a result, AOP code instrumentation cannot be implemented through the annotation.
>
> To avoid function exceptions caused by this issue, do not use annotations in JS HAR (which exists in the build products).
>
> If you need to build a HAR that contains annotations in release mode with obfuscation enabled, build a [bytecode HAR](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-build-har#section16598338112415).

### Custom Annotation

Custom annotations are supported since API version 20.

**Declaration of custom annotation**
The definition of custom annotation is similar to that of **interface**. The **interface** keyword is prefixed with the **@** symbol.<br>
The following types can be used for annotation fields:
* Number
* Boolean
* String
* Enum
* Array of the preceding types
>**NOTE**
>
> - If other types are used for annotation fields, a compile-time error occurs.
> - The bigint type is not supported for annotation field.

The default value of an annotation field must be specified using a constant expression.<br>The following types of constant expressions are used:
* Numeric literal
* Boolean literal
* String literal
* Enum (values must be determined during compilation)
* Array of the preceding constants
>**NOTE**
>
> If the enums cannot be determined during compilation, a compile-time error is reported.
```typescript
// a.ts
export enum X {
  x = foo(); // x is not a constant that can be determined during compilation.
}

// b.ets
import {X} from './a';

@interface Position {
  data: number = X.x; // Compile-time error: The default value of the annotation field must be a constant expression.
}
```
Annotations must be defined in the top-level scope. Otherwise, a compile-time error is reported.<br>
The name of an annotation cannot be the same as that of another entity visible in the scope where the annotation is defined. Otherwise, a compile-time error is reported.<br>
Annotations do not support the merging feature in TypeScript. Otherwise, a compile-time error is reported.
```typescript
namespace ns {
  @interface MataInfo { // Compile-time error: Annotations must be defined in the top-level scope.
    // ...
  }
}

@interface Position {
  // ...
}

class Position { // Compile-time error: The name of an annotation cannot be the same as that of another entity visible in the scope where the annotation is defined.
  // ...
}

@interface ClassAuthor {
  name: string;
}

@interface ClassAuthor { // Compile-time error: The name of an annotation cannot be the same as that of another entity visible in the scope where the annotation is defined.
  data: sting;
}
```
Annotations are not types. If annotations are used as types, a compile-time error is reported. For example, type aliases are used for annotations.
```typescript
@interface Position {}
type Pos = Position; // Compile-time error: Annotations are not types.
```
Annotations cannot be added to the **getter** and **setter** methods of a class. Otherwise, a compile-time error is reported.
```typescript
@interface ClassAuthor {
  authorName: string;
}

@ClassAuthor({authorName: "John Smith"})
class MyClass {
  private _name: string = "Bob";

  @ClassAuthor({authorName: "John Smith"}) // Compile-time error: Annotations cannot be added to the getter and setter methods of a class.
  get name() {
    return this._name;
  }

  @ClassAuthor({authorName: "John Smith"}) // Compile-time error: Annotations cannot be added to the getter and setter methods of a class.
  set name(authorName: string) {
    this._name = authorName;
  }
}
```

**Usage of custom annotation**
The following is an example of annotation declaration:
```typescript
@interface ClassPreamble {
  authorName: string;
  revision: number = 1;
}
@interface MyAnno {}
```
Currently, annotations can be used only for class declarations and method declarations. The same annotation can be used for classes and methods.<br>The following is an example of annotation usage:
```typescript
@ClassPreamble({authorName: "John", revision: 2})
class C1 {
  // ...
}

@ClassPreamble({authorName: "Bob"}) // The default value of revision is 1.
class C2 {
  // ...
}

@MyAnno() // The same annotation can be used for classes and methods.
class C3 {
  @MyAnno()
  foo() {}
  @MyAnno()
  static bar() {}
}
```
The field sequence in an annotation does not affect the usage.
```typescript
@ClassPreamble({authorName: "John", revision: 2})
// the same as:
@ClassPreamble({revision: 2, authorName: "John"})
```
When using an annotation, you must assign values to the fields that do not have default values. Otherwise, a compile-time error occurs.
>**NOTE**
>
> The value to assign must be of the same type as the annotation declaration and only constant expressions can be used.
```typescript
@ClassPreamble() // Compile-time error: The authorName field is not defined.
class C1 {
  // ...
}
```
If a field of the array type is defined in an annotation, use an array literal to set the value of the field.
```typescript
@interface ClassPreamble {
  authorName: string;
  revision: number = 1;
  reviewers: string[];
}

@ClassPreamble(
  {
    authorName: "Alice",
    reviewers: ["Bob", "Clara"]
  }
)
class C3 {
  // ...
}
```
If it is not necessary to define an annotation field, you can omit the parentheses following the annotation name.
```typescript
@MyAnno
class C4 {
  // ...
}
```

**Importing and exporting annotations**
Annotations can also be imported and exported. Currently, only the annotations in the **export @interface** form can be exported.<br>
**Example**
```typescript
export @interface MyAnno {}
```
Currently, only the annotations in the **import {}** and **import * as** forms can be imported.<br>
**Example**
```typescript
// a.ets
export @interface MyAnno {}
export @interface ClassAuthor {}

// b.ets
import { MyAnno } from './a';
import * as ns from './a';

@MyAnno
@ns.ClassAuthor
class C {
  // ...
}
```
- Annotation renaming is not allowed in **import**.
```typescript
import { MyAnno as Anno } from './a'; // Compile-time error: Annotation renaming is not allowed in import.
```
Any other forms of **import** or **export** are not allowed for annotations. Otherwise, a compile-time error is reported.
- As annotations are not types, the **type** symbol is not allowed for import and export.
```typescript
import type { MyAnno } from './a'; // Compile-time error: The type symbol is not allowed for annotation import and export.
```

- If an annotation is imported only from a module, the module side effects will not be triggered.
```typescript
// a.ets
export @interface Anno {}

export @interface ClassAuthor {}

console.info("hello");

// b.ets
import { Anno } from './a';
import * as ns from './a';

@MyAnno
@ns.ClassAuthor // Only the annotation of ns is referenced, which does not execute console.info of a.ets.
class X {
  // ...
}
```

**Annotations in .d.ets files**
Annotations can be used in .d.ets files.
You can declare annotations using ambient declarations in .d.ets files.
```typescript
ambientAnnotationDeclaration:
  'declare' userDefinedAnnotationDeclaration
  ;
```

**Example**
```typescript
// a.d.ets
export declare @interface ClassAuthor {}
```
In the preceding declaration:
- No new annotation definition is introduced, but the annotation type information is provided.
- Annotations must be defined in other source code files.
- The ambient declaration and implementation of an annotation must be the same, including the field type and default value.
```typescript
// a.d.ets
export declare @interface NameAnno{name: string = ""}

// a.ets
export @interface NameAnno{name: string = ""} // ok
```
The ambient declaration of an annotation is similar to that of a class and can also be imported.
```typescript
// a.d.ets
export declare @interface MyAnno {}

// b.ets
import { MyAnno } from './a';

@MyAnno
class C {
  // ...
}
```

**.d.ets files automatically generated by a compiler**<br>
When a compiler automatically generates .d.ets files based on ETS code, the following situations may occur:
1. When the annotation definition is exported, the annotation definition in the source code is retained in the .d.ets file.
```typescript
// a.ets
export @interface ClassAuthor {}

@interface MethodAnno { // Not exported
  data: number;
}

// Declaration file generated by the a.d.ets compiler
export declare @interface ClassAuthor {}
```
2. If all the following conditions are met, the annotation instance of the entity in the source code is retained in the .d.ets file.<br>
    2.1 The annotation definition (including imported annotation) is exported.<br>
    2.2 If the entity is a class, the class is exported.<br>
    2.3 If the entity is a method, the class is exported, and the method is not private.
```typescript
// a.ets
import { ClassAuthor } from './author';

export @interface MethodAnno {
  data: number = 0;
}

@ClassAuthor
class MyClass {
  @MethodAnno({data: 123})
  foo() {}

  @MethodAnno({data: 456})
  private bar() {}
}

// Declaration file generated by the a.d.ets compiler
import {ClassAuthor} from "./author";

export declare @interface MethodAnno {
  data: number = 0;
}

@ClassAuthor
export declare class MyClass {
  @MethodAnno({data: 123})
  foo(): void;

  bar; // Annotations are not retained for private methods.
}
```

**.d.ets file generated by the developer**<br>
The annotation information in the .d.ets file generated by you is not automatically applied to the implemented source code.<br>
**Example**
```typescript
// Declaration file generated by you in b.d.ets
@interface ClassAuthor {}

@ClassAuthor // The declaration file contains annotations.
class C {
  // ...
}

// Source code of the declaration file implemented by you in b.ets
@interface ClassAuthor {}

// The implementation file does not contain annotations.
class C {
  // ...
}
```
In the final build product, **class C** does not have annotations.

**Duplicate annotations and inheritance**
The same annotation cannot be used repeatedly for the same entity. Otherwise, a compile-time error occurs.
```typescript
@MyAnno({name: "123", value: 456})
@MyAnno({name: "321", value: 654}) // Compile-time error: Duplicate annotations are not allowed.
class C {
  // ...
}
```
A child class does not extend the annotations of the base class or that of the methods of the base class.

**Annotations, abstract classes, and abstract methods**
Annotations cannot be used for abstract classes or abstract methods. Otherwise, a compile-time error occurs.
```typescript
@MyAnno // Compile-time error: Annotations cannot be used for abstract classes and abstract methods.
abstract class C {
  @MyAnno
  abstract foo(): void; // Compile-time error: Annotations cannot be used for abstract classes and abstract methods.
}
```

## ArkUI Supports

This section demonstrates the mechanism provided by ArkTS for creating GUIs. ArkUI provides a series of extended capabilities based on TypeScript to declaratively describe the GUIs of an application and the interaction between GUI components.


### ArkUI Example

[MVVM code example](../ui/state-management/arkts-mvvm.md#example) provides a complete ArkUI-based application to demonstrate its GUI programming features.

For more details about ArkUI features, see [Basic Syntax Overview](../ui/state-management/arkts-basic-syntax-overview.md).
