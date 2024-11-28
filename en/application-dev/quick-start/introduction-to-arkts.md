# Introduction

Welcome to the tutorial for ArkTS, a TypeScript-based programming language designed specifically to build high-performance mobile applications!

ArkTS is optimized to provide better performance and efficiency, while still maintaining the familiar syntax of TypeScript.

As mobile devices continue to become more prevalent in our daily lives, there is a growing need for programming languages optimized for the mobile environment. Many current programming languages were not designed with mobile devices in mind, resulting in slow and inefficient applications that drain battery life. ArkTS has been specifically designed to address such concerns by prioritizing higher execution efficiency.

ArkTS is based on the popular programming language TypeScript that extends JavaScript by adding type definitions. TypeScript is well-loved by many developers as it provides a more structured approach to coding in JavaScript. ArkTS aims to keep the look and feel of TypeScript to enable a seamless transition for the existing TypeScript developers, and to let mobile developers learn ArkTS quickly.

One of the key features of ArkTS is its focus on low runtime overhead.
ArkTS imposes stricter limitations on the TypeScript's dynamically typed features, reducing runtime overhead and allowing faster execution. By eliminating the dynamically typed features from the language, ArkTS code can be compiled ahead-of-time more efficiently, resulting in faster application startup and lower power consumption.

Interoperability with JavaScript was a critical consideration in the ArkTS language design. Many mobile app developers already have TypeScript and JavaScript code and libraries they would want to reuse. ArkTS has been designed for seamless JavaScript interoperability, making it easy for the developers to integrate the JavaScript code into their applications and vice versa. This will allow the developers to use their existing codebases and libraries to leverage the power of our new language.

To ensure best experience for UI app development for OpenHarmony ecosystem, ArkTS provides support for ArkUI, including its declarative syntax and other features. Since this feature is outside the scope of the "stock" TypeScript, a verbose ArkUI example is provided in a separate chapter.

This tutorial will guide you through the core features, syntax, and best practices of ArkTS. After reading this tutorial through the end, you will be able to build performant and efficient mobile applications in ArkTS. For details about programming specifications, see [ArkTS Coding Style Guide](../../contribute/OpenHarmony-ArkTS-coding-style-guide.md).<!--RP1--><!--RP1End-->

For a more detailed understanding of the ArkTS language, please refer to the [ArkTS Specific Guide](https://gitee.com/openharmony/docs/blob/master/en/application-dev/arkts-utils/arkts-overview.md).

## The Basics

### Declarations

Declarations in ArkTS introduce:

- Variables
- Constants
- Functions
- Types

#### Variable Declaration

A declaration starting with the keyword `let` introduces a variable which can have different values during program execution.

```typescript
let hi: string = 'hello';
hi = 'hello, world';
```

#### Constant Declaration

A declaration starting with the keyword `const` introduces a read-only constant that can be assigned only once.

```typescript
const hello: string = 'hello';
```

A compile-time error occurs if a new value is assigned to a constant.

#### Automatic Type Inference

As ArkTS is a statically typed language, the types of all entities, like variables and constants, have to be known at compile time.

However, developers do not need to explicitly specify the type of a declared entity if a variable or a constant declaration contains an initial value.

All cases that allow the type to be inferred automatically are specified in the ArkTS Specification.

Both variable declarations are valid, and both variables are of the `string` type:

```typescript
let hi1: string = 'hello';
let hi2 = 'hello, world';
```

### Types

#### Numeric Types

ArkTS has `number` and `Number` numeric types. Any integer and floating-point values can be assigned to a variable of these types.

Numeric literals include integer literals and floating-point literals
with the decimal base.

Integer literals include the following:

* Decimal integers that consist of a sequence of digits. For example: `0`, `117`, `-345`.
* Hexadecimal integers that start with 0x (or 0X), and can contain digits (0-9) and letters a-f or A-F. For example: `0x1123`, `0x00111`, `-0xF1A7`.
* Octal integers that start with 0o (or 0O) and can only contain digits (0-7). For example: `0o777`.
* Binary integers that start with 0b (or 0B), and can only contain the digits 0 and 1. For example: `0b11`, `0b0011`, `-0b11`.

A floating-point literal includes the following:

* Decimal integer, optionally signed (i.e., prefixed with "+" or "-");
* Decimal point (".").
* Fractional part (represented by a string of decimal digits).
* Exponent part that starts with "e" or "E", followed by an optionally signed (i.e., prefixed with "+" or "-") integer.

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

#### `Boolean`

The `boolean` type represents logical values that are either `true` or `false`.

Usually variables of this type are used in conditional statements:

```typescript
let isDone: boolean = false;

// ...

if (isDone) {
  console.log ('Done!');
}
```

#### `String`

A `string` is a sequence of characters; some characters can be set by using escape sequences.

A `string` literal consists of zero or more characters enclosed in single (') or double quotes ("). The special form of string literals are template literals enclosed in backtick quotes (\`).

```typescript
let s1 = 'Hello, world!\n';
let s2 = 'this is a string';
let a = 'Success';
let s3 = `The result is ${a}`;
```

#### `Void` Type

The `void` type is used to specify that a function does not return a value.
This type has the only one value which is also `void`. As `void` is
a reference type, it can be used as type argument for generic types.

```typescript
class Class<T> {
  //...
}
let instance: Class <void>
```

#### `Object` Type

An `Object` class type is a base type for all reference types. Any value, including values of primitive types (they will be automatically boxed), can be directly assigned to variables of the type `Object`.`The 'object' type is used to represent types other than the primitive types.

#### `Array` Type

An `array` is an object comprised of elements of data types assignable to the element type specified in the array declaration.
A value of an `array` is set by using *array composite literal*, that is a list of zero or more expressions enclosed in square brackets ([]). Each expression represents an element of the `array`. The length of the `array` is set by the number of expressions. Index of the first array element is 0.

The following example creates the `array` with three elements:

```typescript
let names: string[] = ['Alice', 'Bob', 'Carol'];
```

#### `Enum` Type

An `enum` type is a value type with a defined set of named values called enum constants.
In order to be used, an `enum` constant must be prefixed with an enum `type` name.

```typescript
enum ColorSet { Red, Green, Blue }
let c: ColorSet = ColorSet.Red;
```

A constant expression can be used to explicitly set the value of an `enum` constant.

```typescript
enum ColorSet { White = 0xFF, Grey = 0x7F, Black = 0x00 }
let c: ColorSet = ColorSet.Black
```

#### `Union` Type

A `union` type is a reference type which is created as a combination of other types. Values of union types can be valid values of all types a union was created from.

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
type Animal = Cat | Dog | Frog | number
// Cat, Dog, and Frog are some types (class or interface ones)

let animal: Animal = new Cat();
animal = new Frog();
animal = 42;
// One may assign the variable of the union type with any valid value
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
    animal.leap();  // animal is of type Frog here
  }
  animal.sleep(); // Any animal can sleep
}
```

#### Type `Aliases`

Type `aliases` provides names for anonymous types (array, function, object literal or union types) or alternative names for existing types.

```typescript
type Matrix = number[][];
type Handler = (s: string, no: number) => string;
type Predicate <T> = (x: T) => boolean;
type NullableObject = Object | null;
```

### Operators

#### Assignment Operators

Simple assignment operator '=' is used as in "x = y".

Compound assignment operators combine an assignment with an operator, where `x op = y` equals `x = x op y`.

Compound assignment operators are as follows: `+=`, `-=`, `*=`, `/=`, `%=`, `<<=`, `>>=`, `>>>=`, `&=`, `|=`, `^=`.

#### Comparison Operators

| Operator | Description                                                  |
| -------- | ------------------------------------------------------------ |
| `===`    | Returns true if both operands are strict equal.              |
| `!==`    | Returns true if both operands are nots trict equal.          |
| `==`     | Returns true if both operands are equal.                     |
| `!=`     | Returns true if both operands are not equal.                 |
| `>`      | Returns true if the left operand is greater than the right.  |
| `>=`     | Returns true if the left operand is greater than or equal to the right. |
| `<`      | Returns true if the left operand is less than the right.     |
| `<=`     | Returns true if the left operand is less than or equal to the right. |
#### Arithmetic Operators

Unary operators are `-`, `+`, `--` and `++`.

Binary operators are as follows:

| Operator   | Description              |
|------------|--------------------------|
| `+`        | addition                 |
| `-`        | subtraction              |
| `*`        | multiplication           |
| `/`        | division                 |
| `%`        | remainder after division |
#### Bitwise Operators

| Operator   | Description                                                                                                     |
|------------|-----------------------------------------------------------------------------------------------------------------|
| `a & b`    | Bitwise AND: sets each bit to 1 if the corresponding bits of both operands are 1, otherwise to 0.               |
| `a \| b`    | Bitwise OR: sets each bit to 1 if at least one of the corresponding bits of both operands is 1, otherwise to 0. |
| `a ^ b`    | Bitwise XOR: sets each bit to 1 if the corresponding bits of both operands are different, otherwise to 0.       |
| `~ a`      | Bitwise NOT: inverts the bits of the operand.                                                                   |
| `a << b`   | Shift left: shifts the binary representation of *a* to the left by *b* bits.                                    |
| `a >> b`   | Arithmetic right shift: shifts the binary representation of *a* to the right by *b* bits with sign-extension.   |
| `a >>> b`  | Logical right shift: shifts the binary representation of *a* to the right by *b* bits with zero-extension.      |
#### Logical Operators

| Operator   | Description   |
|------------|---------------|
| `a && b`   | Logical AND  |
| `a \|\| b`   | Logical OR   |
| `! a`      | Logical NOT  |
### Statements

#### `If` Statements

An `if` statement is used to execute a sequence of statements when a logical condition is `true`, or another set of statements (if provided) otherwise.

The `else` part can also contain more `if` statements.

An `if` statement looks as follows:

```typescript
if (condition1) {
  // statements1
} else if (condition2) {
  // statements2
} else {
  // else_statements
}
```

All conditional expressions must be of the type `boolean` or other types (`string`, `number`, etc.). For types other than `boolean`, implicit conversion rules apply:

```typescript
let s1 = 'Hello';
if (s1) {
  console.log(s1); // prints 'Hello'
}

let s2 = 'World';
if (s2.length != 0) {
  console.log(s2); // prints 'World'
}
```

#### `Switch` Statements

A `switch` statement is used to execute a sequence of statements that match the value of a switch expression.

A `switch` statement looks as follows:

```typescript
switch (expression) {
  case label1: // will be executed if label1 is matched
    // ...
    // statements1
    // ...
    break; // Can be omitted
  case label2:
  case label3: // will be executed if label2 or label3 is matched
    // ...
    // statements23
    // ...
    break; // Can be omitted
  default:
    // default_statements
}
```

If the value of a `switch` expression equals the value of some label, then the corresponding statements are executed.

If there is no match, and the `switch` has the default clause, then the default statements are executed.

An optional `break` statement allows you to break out of the `switch` and continue executing the statement that follows the `switch`.

If there is no `break`, then the next statements in the `switch` are executed.

#### Conditional Expressions

The conditional expression `? :` uses the `boolean` value of the first expression to decide which of two other expressions to evaluate.

A conditional expression looks as follows:

```typescript
condition ? expression1 : expression2
```

If that logical expression is truthy(a value that is considered `true`), then the first expression is used as the result of the ternary expression; otherwise, the second expression is used.

Example:

```typescript
let isValid = Math.random() > 0.5 ? true : false;
let message = isValid ? 'Valid' : 'Failed';
```

#### `For` Statements

A `for` statement is executed repeatedly until the specified loop exit condition is `false`.

A `for` statement looks as follows:

```typescript
for ([init]; [condition]; [update]) {
  statements
}
```

When a `for` statement is executed, the following process takes place:

1. An `init` expression is executed, if any. This expression usually initializes one or more loop counters.
2. The condition is evaluated. If the value of condition is truthy(a value that is considered `true`), or if the conditional expression is omitted, then the statements in the `for` body are to be executed. If the value of condition is falsy(a value that is considered `false`), then the `for` loop terminates.
3. The statements of the `for` body are executed.
4. If there is an `update` expression, then the `update` expression is executed.
5. Go back to step 2.

Example:

```typescript
let sum = 0;
for (let i = 0; i < 10; i += 2) {
  sum += i;
}
```

#### `For-of` Statements

`for-of` statements are used to iterate over an array or string.

A `for-of` statement looks as follows:

```typescript
for (forVar of expression) {
  statements
}
```

Example:

```typescript
for (let ch of 'a string object') {
  /* process ch */
}
```

#### `While` Statements

A `while` statement has its body statements executed as long as the specified condition evaluates to `true`.

A `while` statement looks as follows:

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

#### `Do-while` Statements

`do-while` statements are executed repetitively until a specified condition evaluates to `false`.

A `do-while` statement looks as follows:

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

#### `Break` Statements

A `break` statement is used to terminate any `loop` statement or `switch`.

Example:

```typescript
let x = 0;
while (true) {
  x++;
  if (x > 5) {
    break;
  }
}
```

A `break` statement with a label identifier transfers control out of the enclosing statement to the one which has the same label identifier.

Example:

```typescript
let x = 1;
label: while (true) {
  switch (x) {
    case 1:
      // statements
      break label; // breaks the while
  }
}
```

#### `Continue` Statements

A `continue` statement stops the execution of the current loop iteration and passes control to the next iteration.

Example:

```typescript
let sum = 0;
for (let x = 0; x < 100; x++) {
  if (x % 2 == 0) {
    continue;
  }
  sum += x;
}
```

#### `Throw` and `Try` Statements

A `throw` statement is used to throw an exception or an error:

```typescript
throw new Error('this error')
```

A `try` statement is used to catch and handle an exception or an error:

```typescript
try {
  // try block
} catch (e) {
  // handle the situation
}
```

The example below shows the `throw` and `try` statements  used to handle the zero division case:

```typescript
class ZeroDivisor extends Error {}

function divide (a: number, b: number): number{
  if (b == 0) throw new ZeroDivisor();
  return a / b;
}

function process (a: number, b: number) {
  try {
    let res = divide(a, b);
    console.log('result: ' + res);
  } catch (x) {
    console.log('some error');
  }
}
```

`finally` clause is also supported:

```typescript
function processData(s: string) {
  let error: Error | null = null;

  try {
    console.log('Data processed: ' + s);
    // ...
    // Throwing operations
    // ...
  } catch (e) {
    error = e as Error;
    // ...
    // More error handling
    // ...
  } finally {
    if (error != null) {
      console.log(`Error caught: input='${s}', message='${error.message}'`);
    }
  }
}
```

## Functions

### Function Declarations

A function declaration introduces a named function, specifying its name, parameters, return type and body.

Below is a simple function with two string parameters and string return type:

```typescript
function add(x: string, y: string): string {
  let z: string = `${x} ${y}`;
  return z;
}
```

For every parameter its type annotation must be specified.
An optional parameter allows you to omit the corresponding argument when calling a function. The last parameter of a function can be a rest parameter.

### Optional Parameters

An optional parameter has the form `name?: Type`.

```typescript
function hello(name?: string) {
  if (name == undefined) {
    console.log('Hello!');
  } else {
    console.log(`Hello, ${name}!`);
  }
}
```

Another form contains an expression that specifies a default value.
If the corresponding argument to such parameter is omitted in a function call, then this parameter's value is default.

```typescript
function multiply(n: number, coeff: number = 2): number {
  return n * coeff;
}
multiply(2);  // returns 2*2
multiply(2, 3); // returns 2*3
```

### The Rest Parameter

The last parameter of a function can be a rest parameter. It allows functions or methods to take unlimited number of arguments.

```typescript
function sum(...numbers: number[]): number {
  let res = 0;
  for (let n of numbers)
    res += n;
  return res;
}

sum(); // returns 0
sum(1, 2, 3); // returns 6
```

### Return Types

If function return type can be inferred from its body content, then it can be omitted from the function declaration.

```typescript
// Explicit return type
function foo(): string { return 'foo'; }

// Implicit return type inferred as string
function goo() { return 'goo'; }
```

The return type of a function that does not need to return a value can be explicitly specified as `void` or omitted altogether. No return statement is needed for such functions.

Both notations below are valid:

```typescript
function hi1() { console.log('hi'); }
function hi2(): void { console.log('hi'); }
```

### Function Scope

Variables and other entities defined in a function are local to the function and cannot be accessed from the outside.

If the name of a variable defined in the function is equal to the name of an entity in the outer scope, then the local definition shadows the outer entity.

### Function Calls

Calling a function actually leads to the execution of its body, while the arguments of the call are assigned to the function parameters.

If the function is defined as follows:

```typescript
function join(x: string, y: string): string {
  let z: string = `${x} ${y}`;
  return z;
}
```

then it is called with two arguments of the type `string`:

```typescript
let x = join('hello', 'world');
console.log(x);
```

## Function Types

Function types are commonly used as follows to define callbacks:

```typescript
type trigFunc = (x: number) => number // this is a function type

function do_action(f: trigFunc) {
   f(3.141592653589); // call the function
}

do_action(Math.sin); // pass the function as the parameter
```

### Arrow Functions (Lambdas Functions)

A function can be defined as an arrow function, for example:

```typescript
let sum = (x: number, y: number): number => {
  return x + y;
}
```

An arrow function return type can be omitted; in such case, it is inferred from the function body.

An expression can be specified as an arrow function to make the notation shorter, i.e., the following two notations are equivalent:

```typescript
let sum1 = (x: number, y: number) => { return x + y; }
let sum2 = (x: number, y: number) => x + y
```

### Closure

A closure is the combination of a function and the lexical environment within which that function was declared. This environment consists of any local variables that were in-scope at the time the closure was created.

In the following example, **z** is a reference to the instance of the function **g** that is created when **f** is executed. The instance of **g** maintains a reference to its lexical environment, within which the variable **count** exists. For this reason, when **z** is invoked, the variable **count** remains available for use.

```typescript
function f(): () => number {
  let count = 0;
  let g = (): number => { count++; return count; };
  return g;
}

let z = f();
z(); // output: 1
z(); // output: 2
```

### Function Overload Signatures

A function can be specified to be called in different ways by writing overload signatures. To do so, several functions' headers that have the same name but different signatures are written and immediately followed by the single implementation function.

```typescript
function foo(x: number): void;            /* 1st signature */
function foo(x: string): void;            /* 2nd signature */
function foo(x: number | string): void {  /* Implementation signature */
}

foo(123);   // ok, 1st signature is used
foo('aa');  // ok, 2nd signature is used
```

An error occurs if two overload signatures have identical parameter lists.

## Classes

A class declaration introduces a new type and defines its fields, methods and constructors.

In the following example, class `Person` is defined, which has fields **name** and **surname**, constructor, and a method `fullName`:

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

After the class is defined, its instances can be created by using the keyword `new`:

```typescript
let p = new Person('John', 'Smith');
console.log(p.fullName());
```

or an instance can be created by using object literals:

```typescript
class Point {
  x: number = 0;
  y: number = 0;
}
let p: Point = {x: 42, y: 42};
```

### Fields

A field is a variable of some type that is declared directly in a class.

Classes may have instance fields, static fields or both.

#### Instance Fields

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
p1.name;
let p2 = new Person('Bob', 28);
p2.getName();
```

#### Static Fields

The keyword `static` is used to declare a field as static. Static fields belong to the class itself, and all instances of the class share one static field.

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

#### Field Initializers

ArkTS requires that all fields are explicitly initialized with some values either when the field is declared or in the `constructor`. This is similar to `strictPropertyInitialization` mode of the standard TypeScript. Such behavior is enforced to minimize the number of unexpected runtime errors and achieve better performance.

The following code (invalid in ArkTS) is error-prone:

```typescript
class Person {
  name: string; // undefined
  
  setName(n:string): void {
    this.name = n;
  }
  
  getName(): string {
    // Return type "string" hides from the developers the fact
    // that name can be undefined. The most correct would be
    // to write the return type as "string | undefined". By doing so
    // we tell the users of our API about all possible return values.
    return this.name;
  }
}

let jack = new Person();
// Let's assume that the developer forgets to call setName:
// jack.setName('Jack')
jack.getName().length; // runtime exception: name is undefined
```

Here is how it should look in ArkTS:

```typescript
class Person {
  name: string = '';
  
  setName(n:string): void {
    this.name = n;
  }

  // The type is always string, no other "hidden options".
  getName(): string {
    return this.name;
  }
}
  

let jack = new Person();
// Let's assume that the developer forgets to call setName:
// jack.setName('Jack')
jack.getName().length; // 0, no runtime error
```

And here how our code behaves if the field `name` can be `undefined`

```typescript
class Person {
  name?: string; // The field may be undefined

  setName(n:string): void {
    this.name = n;
  }

  // Compile-time error:
  // name can be "undefined", so we cannot say to those who use this API
  // that it returns only strings:
  getNameWrong(): string {
    return this.name;
  }

  getName(): string | undefined { // Return type matches the type of name
    return this.name;
  }
}

let jack = new Person()
// Let's assume that the developer forgets to call setName:
// jack.setName('Jack')

// Compile-time(!) error: Compiler suspects that we
// may possibly access something undefined and won't build the code:
jack.getName().length; // The code won't build and run

jack.getName()?.length; // Builds ok, no runtime error
```

#### Getters and Setters

Setters and getters can be used to provide controlled access to object properties.

In the following example, a setter is used to forbid setting invalid values of the '_age' property:

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
p.age; // 0
p.age = -42; // Error will be thrown as an attempt to set incorrect age
```

A class can define a getter, a setter or both.

### Methods

A method is a function that belongs to a class.
A class can define instance methods, static methods or both.
A static method belongs to the class itself, and can have access to static fields only.
A `while` instance method has access to both static (class) fields and instance fields including private ones of its class.

### Instance Methods

The example below illustrates how instanced methods work.
The `calculateArea` method calculates the area of a rectangle by multiplying the height by the width:

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
square.calculateArea(); // output: 100
```

#### Static Methods

The keyword `static` is used to declare a method as static. Static methods belong to the class itself and have access to static fields only.
A static method defines a common behavior of the class as a whole.

The class name is used to call a static method:

```typescript
class Cl {
  static staticMethod(): string {
    return 'this is a static method.';
  }
}
console.log(Cl.staticMethod());
```

#### Inheritance

A class can extend another class.
The class that is being extended by another class is called ‘*base class*’, ‘parent class’, or ‘superclass’.
The class that extends another class is called ‘*extended class*’, ‘derived class’, or ‘subclass’.

An extended class can implement several interfaces by using the following syntax:

```typescript
class [extends BaseClassName] [implements listOfInterfaces] {
  // ...
}
```

An extended class inherits fields and methods, but not constructors from the base class, and can add its own fields and methods, as well as override methods defined by the base class.

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

A class containing the `implements` clause must implement all methods defined in all listed interfaces, except the methods defined with default implementation.

```typescript
interface DateInterface {
  now(): string;
}
class MyDate implements DateInterface {
  now(): string {
    // implementation is here
    return 'now';
  }
}
```

#### Access to Super

The keyword `super` can be used to access instance fields, instance methods and constructors from the super class.

It is often used to extend basic functionality of subclass with the required behavior taken from the super class:

```typescript
class RectangleSize {
  protected height: number = 0;
  protected width: number = 0;

  constructor (h: number, w: number) {
    this.height = h;
    this.width = w;
  }

  draw() {
    /* draw bounds */
  }
}
class FilledRectangle extends RectangleSize {
  color = ''
  constructor (h: number, w: number, c: string) {
    super(h, w); // call of super constructor
    this.color = c;
  }

  draw() {
    super.draw(); // call of super methods
    // super.height - can be used here
    /* fill rectangle */
  }
}
```

#### Override Methods

A subclass can override implementation of a method defined in its superclass.
An overridden method must have the same types of parameters, and same or derived return type as the original method.

```typescript
class RectangleSize {
  // ...
  area(): number {
    // implementation
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

#### Method Overload Signatures

A method can be specified to be called in different ways by writing overload signatures. To do so, several method headers that have the same name but different signatures are written and immediately followed by the single implementation method.

```typescript
class C {
  foo(x: number): void;            /* 1st signature */
  foo(x: string): void;            /* 2nd signature */
  foo(x: number | string): void {  /* implementation signature */
  }
}
let c = new C();
c.foo(123);   // ok, 1st signature is used
c.foo('aa');  // ok, 2nd signature is used
```

An error occurs if two overload signatures have the same name and identical parameter lists.

### Constructors

A class declaration may contain a constructor that is used to initialize object state.

A constructor is defined as follows:

```typescript
constructor ([parameters]) {
  // ...
}
```

If no constructor is defined, then a default constructor with an empty parameter list is created automatically, for example:

```typescript
class Point {
  x: number = 0;
  y: number = 0;
}
let p = new Point();
```

In this case the default constructor fills the instance fields with default values for the field types.

#### Constructors in Derived Class

The first statement of a constructor body can use the keyword `super` to explicitly call a constructor of the direct superclass.

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

#### Constructor Overload Signatures

A constructor can be specified to be called in different ways by writing overload signatures. To do so, several constructor headers that have the same name but different signatures are written and immediately followed by the single implementation constructor.

```typescript
class C {
  constructor(x: number)             /* 1st signature */
  constructor(x: string)             /* 2nd signature */
  constructor(x: number | string) {  /* Implementation signature */
  }
}
let c1 = new C(123);    // ok, 1st signature is used
let c2 = new C('abc');  // ok, 2nd signature is used
```

An error occurs if two overload signatures have the same name and identical parameter lists.

### Visibility Modifiers

Both methods and properties of a class can have visibility modifiers.

There are several visibility modifiers:

- `private`
- `protected`
- `public`

The default visibility is `public`.

#### Public Visibility

The `public` members (fields, methods, constructors) of a class are visible in any part of the program, where their class is visible.

### Private Visibility

A `private` member cannot be accessed outside the class it is declared in.
Example:

```typescript
class C {
  public x: string = '';
  private y: string = '';
  set_y (new_y: string) {
    this.y = new_y // ok, as y is accessible within the class itself
  }
}
let c = new C();
c.x = 'a'; // ok, the field is public
c.y = 'b'; // compile-time error: 'y' is not visible
```

#### Protected Visibility

The modifier `protected` acts much like the modifier `private`, but the `protected` members are also accessible in derived classes.
Example:

```typescript
class Base {
  protected x: string = '';
  private y: string = '';
}
class Derived extends Base {
  foo() {
    this.x = 'a'; // ok, access to protected member
    this.y = 'b'; // compile-time error, 'y' is not visible, as it is private
  }
}
```

### Object Literals

An object literal is an expression that can be used to create a class instance and provide some initial values. It can be used instead of the expression `new` as it is more convenient in some cases.

A class composite is written as a comma-separated list of name-value pairs enclosed in '{' and '}'.

```typescript
class C {
  n: number = 0;
  s: string = '';
}

let c: C = {n: 42, s: 'foo'};
```

Due to the static typing of the ArkTS, object literals can be used in a context where the class or interface type of the object literal can be inferred as in the example above. Other valid cases are illustrated below:

```typescript
class C {
  n: number = 0;
  s: string = '';
}

function foo(c: C) {}

let c: C;

c = {n: 42, s: 'foo'};  // type of the variable is used
foo({n: 42, s: 'foo'}); // type of the parameter is used

function bar(): C {
  return {n: 42, s: 'foo'}; // return type is used
}
```

The type of an array element or of a class field can also be used:

```typescript
class C {
  n: number = 0;
  s: string = '';
}
let cc: C[] = [{n: 1, s: 'a'}, {n: 2, s: 'b'}];
```

#### Object Literals of Record Type

The generic Record<K, V> type is used to map the properties of a type (Key type) to another type (Value type).

A special form of object literal is used to initialize the value of such type:

```typescript
let map: Record<string, number> = {
  'John': 25,
  'Mary': 21,
}

map['John']; // 25
```

The K type can be either string or number, while V can be any type.

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

### Abstract Classes 

A class with the modifier abstract is known as abstract class. Abstract classes can be used to represent notions that are common to some set of more concrete notions.

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

Subclasses of an abstract class can be non-abstract or in turn abstract. A non-abstract subclass of an abstract superclass can be instantiated. As a result, a constructor for the abstract class, and field initializers for non-static fields of that class are executed：

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
```

#### Abstract Methods 

A method with the modifier abstract is considered an abstract method. Abstract methods do not have bodies, i.e., they can be declared but not implemented.

Only abstract classes can have abstract methods. A compile-time error occurs if a non-abstract class has an abstract method:

```typescript
class Y {
  abstract method(p: string)  //Compile-time error: Abstract methods can only appear within an abstract class.
}
```

## Interfaces

An interface declaration introduces a new type. Interfaces are a common way of defining contracts between various part of codes.

Interfaces are used to write polymorphic code, which can be applied to any class instances that implement a particular interface.

An interface usually contains properties and method headers.

Examples:

```typescript
interface Style {
  color: string; // property
}
interface AreaSize {
  calculateAreaSize(): number; // method header
  someMethod(): void;    // method header
}
```

Examples of a class implementing an interface:

```typescript
// Interface:
interface AreaSize {
  calculateAreaSize(): number; // method header
  someMethod(): void;    // method header
}

// Implementation:
class RectangleSize implements AreaSize {
  private width: number = 0;
  private height: number = 0;
  someMethod(): void {
    console.log('someMethod called');
  }
  calculateAreaSize(): number {
    this.someMethod(); // calls another method and returns result
    return this.width * this.height;
  }
}
```

### Interface Properties

An interface property can be in a form of field, getter, setter, or both getter and setter.

A property field is just a shortcut notation of a getter/setter pair, and the following notations are equal:

```typescript
interface Style {
  color: string;
}
```

```typescript
interface Style {
  get color(): string
  set color(x: string)
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

An interface may extend other interfaces like in the example below:

```typescript
interface Style {
  color: string;
}

interface ExtendedStyle extends Style {
  width: number;
}
```

An extended interface contains all properties and methods of the interface it extends, and can also add its own properties and methods.

## Generic Types and Functions

Generic types and functions allow creating the code capable to work over a variety of types rather than a single type.

### Generic Classes and Interfaces

A class and an interface can be defined as generics, adding parameters to the type definition, like the type parameter `Element` in the following example:

```typescript
class CustomStack<Element> {
  public push(e: Element):void {
    // ...
  }
}
```

To use type CustomStack, the type argument must be specified for each type parameter:

```typescript
let s = new CustomStack<string>();
s.push('hello');
```

Compiler ensures type safety while working with generic types and functions.
See below:

```typescript
let s = new CustomStack<string>();
s.push(55); // That will be a compile-time error as 55 is not compatible with type string.
```

### Generic Constraints

Type parameters of generic types can be bounded. For example, the `Key` type parameter in the `MyHashMap<Key, Value>` container must have the `hash` method.

```typescript
interface Hashable {
  hash(): number;
}
class MyHashMap<Key extends Hashable, Value> {
  public set(k: Key, v: Value) {
    let h = k.hash();
    // ... other code ...
  }
}
```

In the above example, the `Key` type extends `Hashable`, and all methods of `Hashable` interface can be called for keys.

### Generic Functions

Use a generic function to create a more universal code. Consider a function that returns the last element of the array:

```typescript
function last(x: number[]): number {
  return x[x.length - 1];
}
last([1, 2, 3]); // output: 3
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
last<string>(['aa', 'bb']);
last<number>([1, 2, 3]);

// Implicit type argument:
// Compiler understands the type argument based on the type of the call arguments
last([1, 2, 3]);
```

### Generic Defaults

Type parameters of generic types can have defaults. It allows using just the generic type name instead of specifying the actual type arguments.
The example below illustrates this for both classes and functions.

```typescript
class SomeType {}
interface Interface <T1 = SomeType> { }
class Base <T2 = SomeType> { }
class Derived1 extends Base implements Interface { }
// Derived1 is semantically equivalent to Derived2
class Derived2 extends Base<SomeType> implements Interface<SomeType> { }

function foo<T = number>(): T {
  // ...
}
foo();
// such function is semantically equivalent to the call below
foo<number>();
```

## Null Safety

All types in ArkTS by default are non-nullable, so the value of a type cannot be null.
It is similar to TypeScript behavior in strict null checking mode (`strictNullChecks`), but the rules are stricter.

In the example below, all lines cause a compile-time error:

```typescript
let x: number = null;    // Compile-time error
let y: string = null;    // Compile-time error
let z: number[] = null;  // Compile-time error
```

A variable that can have a null value is defined with a union type `T | null`.

```typescript
let x: number | null = null;
x = 1;    // ok
x = null; // ok
if (x != null) { /* do something */ }
```

### Non-Null Assertion Operator

A postfix operator `!` can be used to assert that its operand is non-null.

If applied to a null value, the operator throws an error. Otherwise, the type of the value is changed from `T | null` to `T`:

```typescript
class A {
  value: number = 0;
}

function foo(a: A | null) {
  a.value;   // compile time error: cannot access to a nullable value

  // ok, if the value of a is not null at runtime, the fields of a can be accessed;
  // If the value of runtime a is empty, a runtime exception occurs.
  a!.value;  
}
```

### Null-Coalescing Operator

The null-coalescing binary operator `??` checks whether the evaluation of the left-hand-side expression is equal to `null` or `undefined`.
If it is, then the result of the expression is the right-hand-side expression; otherwise, it is the left-hand-side expression.

In other words, `a ?? b` equals the ternary operator `(a != null && a != undefined) ? a : b`.

In the following example, the method `getNick` returns a nickname if it is set; otherwise, an empty string is returned:

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

Optional chaining operator `?.` allows writing code where the evaluation stops at an expression that is partially evaluated to `null` or `undefined`.

```typescript
class Person {
  nick: string | null = null;
  spouse?: Person;

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

**Note**: The return type of `getSpouseNick` must be `string | null | undefined`, as the method can return `null` or `undefined`.

An optional chain can be of any length and contain any number of `?.` operators.

In the following sample, the output is a person's spouse nickname if that person has a spouse, and the spouse has a nickname.

Otherwise, the output is `undefined`:

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

## Modules

Programs are organized as sets of compilation units or modules.

Each module creates its own scope, i.e., any declarations (variables, functions, classes, etc.) declared in the module are not visible outside that module unless they are explicitly exported.

Conversely, a variable, function, class, interface, etc. exported from another module must first be imported to a module.

### Export

A top-level declaration can be exported by using the keyword `export`.

A declared name that is not exported is considered private and can be used only in the module where it is declared.

**NOTE**: Use braces ({}) when importing a declaration that was exported using the keyword `export`.

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

### Import

#### Static Import

Import declarations are used to import entities exported from other modules and provide their bindings in the current module.
An import declaration consists of two parts:

* Import path that determines the module to import from.
* Import bindings that define the set of usable entities in the imported module, and the form of use (i.e., qualified or unqualified use).

Import bindings may have several forms.

Let's assume a module has the path './utils' and export entities 'X' and 'Y'.

An import binding of the form `* as A` binds the name 'A', and all entities exported from the module defined by the import path can be accessed by using the qualified name `A.name`:

```typescript
import * as Utils from './utils'
Utils.X // denotes X from Utils
Utils.Y // denotes Y from Utils
```

An import binding of the form `{ ident1, ..., identN }` binds an exported entity with a specified name, which can be used as a simple name:

```typescript
import { X, Y } from './utils'
X // denotes X from Utils
Y // denotes Y from Utils
```

If a list of identifiers contains aliasing of the form `ident as alias`, then entity `ident` is bound under the name `alias`:

```typescript
import { X as Z, Y } from './utils'
Z // denotes X from Utils
Y // denotes Y from Utils
X // Compile-time error: 'X' is not visible
```
#### Dynamic Import
Unlike static import, static import allows you to load a module conditionally or on demand.
The **import() **syntax, commonly called dynamic import, is a function-like expression that allows for dynamic loading of a module. It returns a promise.
In the following example, **import(modulePath)** loads the module and returns a promise that resolves into a module object that contains all its exports. This expression can be called from any place in the code.

```typescript
let modulePath = prompt("Which module to load?");
import(modulePath)
.then(obj => <module object>)
.catch(err => <loading error, e.g. if no such module>)
```

You can also use **let module = await import(modulePath)** inside an async function.

```typescript
// say.ts
export function hi() {
  console.log('Hello');
}
export function bye() {
  console.log('Bye');
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

For more details about dynamic import, see [Dynamic Import](arkts-dynamic-import.md).

<!--RP2--><!--RP2End-->

### Top-Level Statements

A module can contain any statements at the module level, except `return` ones.

## Keywords

### this

The keyword `this` can only be used in instance methods of a class.

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

* Type notation using `this` is not supported.
* Using `this` inside standalone functions is not supported.

**Example**

```typescript
class A {
  n: number = 0;
  f1(arg1: this) {} // Compile-time error. Type notation using this is not supported.
  static f2(arg1: number) {
    this.n = arg1;  // Compile-time error. Using this inside standalone functions is not supported.
  }
}

function foo(arg1: number) {
  this.n = i;       // Compile-time error. Using this inside standalone functions is not supported.
}
```

The keyword `this` used as a primary expression denotes a value that is a reference to the following:

* Object for which the instance method is called; or
* Object being constructed.

The value denoted by `this` in a lambda body and in the surrounding context is the same.

## Support for ArkUI

This section demonstrates mechanisms that ArkTS provides for creating graphical user interface (GUI) programs. The section is based on the ArkUI declarative framework. ArkUI provides a set of extensions of the standard TypeScript to declaratively describe the GUI of the applications and the interaction between the GUI components.

### ArkUI Example

The [Example](arkts-mvvm.md#example) provides a complete ArkUI-based application as an illustration of GUI programming capabilities.

For more details of the ArkUI features, refer to the ArkUI [Basic Syntax](arkts-basic-syntax-overview.md).

<!--no_check-->