# TypeScript and JavaScript Coding Style Guide

# Overview

## Purpose

This guide is applicable to the scenario where TypeScript and JavaScript are used during OpenHarmony application development.

Based on the technical features of language engines and OpenHarmony, as well as industry standards and practices, this guide provides coding guide for improving code standardization, security, and performance.

## Source

This guide is developed based on the *JavaScript Coding Style Guide* [1]. It integrates the technical features of OpenHarmony without violating industry rules, including ESLint and TSC configuration.

The correct and incorrect examples, marked with **@typescript-eslint**, in ESLint rules come from ESLint Rules [2].

## Document Structure

- [OpenHarmony Application Environment Restrictions](#openharmony-application-environment-restrictions)

  All the restrictions provided in this section are raised for security purposes and therefore are mandatory.

- Programming language features: [Declaration and Initialization](#declaration-and-initialization), [Data Types](#data-types), [Operation and Expressions](#operation-and-expressions), [Functions](#functions), [Classes and Objects](#classes-and-objects), and [Exceptions](#exceptions), [Async Functions](#async-functions), and [Types](#types).

## Conventions

**Rule**: a convention that must be complied with

**Recommendation**: a convention that must be taken into consideration

It is necessary to understand the reason for each rule or recommendation and try to comply with them.

# OpenHarmony Application Environment Restrictions

## Use Strict Mode

**[Category] Rule**

**[Description]**

Strict mode is a way to opt in to a restricted variant of JavaScript, thereby implicitly opting out of sloppy mode. Strict mode is introduced in ECMAScript 5 and enabled by using the **use strict** syntax.)

1. Strict mode eliminates some JavaScript silent errors by throwing errors.
1. Strict mode fixes defects that make it difficult for JavaScript engines to perform optimizations. Sometimes, the same code can run faster in strict mode than in non-strict mode.
1. Strict mode prohibits some syntax that may be defined in future versions of ECMAScript.

**Note: Currently, only TypeScript or JavaScript code in strict mode is supported on OpenHarmony ArkCompiler.**

## Do Not Use eval()

**[Category] Rule**

**[Description]**

Using **eval()** causes code disorder and poor readability.

**[Incorrect Example]**

```javascript
console.log (eval ({ a:2 })); // Output [object Object].
console.log(eval('"a" + 2')); // Output 'a2'.
console.log(eval('{a: 2}')); // Output 2.
console.log(eval('let value = 1 + 1;'); // Output undefined.
```

## Do Not Use with() {}

**[Category] Rule**

**[Description]**

Using **with()** makes the code semantically unclear because the object of **with()** may conflict with local variables, changing the original semantics.

**[Incorrect Example]**

```javascript
const foo = { x: 5 };
with (foo) {
  let x = 3;
  console.log(x);  // x = 3
}
console.log(foo.x);  // x = 3
```

## Do Not Dynamically Create Functions

**[Category] Rule**

**[Description]**

A function can be defined in three ways: declaration, constructor, and expression. No matter which means is used, the function created is an instance of the **Function** object and inherits all default or custom methods and attributes of the **Function** object. Defining a function by using a constructor is similar to the using of **eval()**. The constructor accepts any string as the function body, causing security vulnerabilities.

**[Incorrect Example]**

```javascript
let add = new Function('a','b','return a + b');
// The function constructor can have only one parameter, which can be any string.
let dd = new Function('alert("hello")');
```

**[Correct Example]**

```javascript
// Function declaration.
function add(a,b){
  return a+b;
}
// Function expression.
let add = function(a,b){
  return a+b;
}
```

# Declaration and Initialization

## Use const or let Instead of var to Declare Variables

**[Category] Rule**

**[Description]**

ECMAScript 6 allows the use of the **let** and **const** keywords to declare variables in the block scope instead of the function scope. The block scope is commonly used in many programming languages. It is helpful in preventing errors. Use **const** to define read-only variables, and use **let** to define other variables.

**[Incorrect Example]**

```javascript
var number = 1;
var count = 1;
if (isOK) {
  count += 1;
}
```

**[Correct Example]**

```javascript
const number = 1;
let count = 1;
if (isOK) {
  count += 1;
}
```

# Data Types

## Do Not Omit 0s Before and After the Decimal Point of a Floating-Point Number

**[Category] Rule**

**[Description]**

In JavaScript, a floating-point number must contain a decimal point, but no digit is required before or after the decimal point. This makes it difficult to distinguish between the decimal point and the dot operator. For this reason, you must use a digit before and after the decimal point for a floating-point number in OpenHarmony code.

**[Incorrect Example]**

```javascript
const num = .5;
const num = 2.;
const num = -.7;
```

**[Correct Example]**

```javascript
const num = 0.5;
const num = 2.0;
const num = -0.7;
```

## Use isNaN() to Check Whether a Variable Is NaN

**[Category] Rule**

**[Description]**

In JavaScript, NaN is a particular value of a numeric data type. It represents a non-numeric value in the double-precision 64-bit format, as defined in the IEEE floating-point standard.
NaN is unique in JavaScript because it is not equal to any value, including itself. Therefore, the result of comparison with NaN is confusing, as the values of **NaN !== NaN** and **NaN != NaN** are both **true**.
Therefore, you must use **Number.isNaN()** or the global **isNaN()** function to check whether a variable is NaN.

**[Incorrect Example]**

```javascript
if (foo == NaN) {
  // ...
}
if (foo != NaN) {
  // ...
}
```

**[Correct Example]**

```javascript
if (isNaN(foo)) {
  // ...
}
if (!isNaN(foo)) {
  // ...
}
```

## Do Not Use == or === to Check Whether Floating-Point Numbers Are Equal

**[Category] Rule**

**[Description]**

Due to the precision problem, mathematically equal numbers may not be equal in floating-point arithmetic. Therefore, the equality operators **==** and **===** cannot be used to check whether floating-point numbers are equal.

**[Incorrect Example]**

```javascript
0.1 + 0.2 == 0.3; // false
0.1 + 0.2 === 0.3; // false
```

**[Correct Example]**

```javascript
const EPSILON = 1e-6;
const num1 = 0.1;
const num2 = 0.2;
const sum = 0.3;
if(Math.abs(num1 + num2 - sum) < EPSILON) {
  ...
}
```

## Do Not Define or Use Non-numeric Attributes (Except Length) for Arrays

**[Category] Rule**

**[Description]**

In JavaScript, an array is an object, which can be added with attributes. To facilitate processing and avoid errors, use an array to store only a group of ordered data, that is, data with continuous indexes. If attributes must be added, use **Map** or **Object** instead.

**[Incorrect Example]**

```javascript
const myHash = [];
myHash['key1'] = 'val1';
myHash['key2'] = 'val2';
myHash[0] = '222';
for (const key in myHash) {
  // The value of key is 0, key1, and key2.
  console.log(key);
}
console.log(myHash.length); // The array length is 1.
```

**[Correct Example]**

Use Map and Object for non-numeric attributes.

```javascript
const map = new Map();
map.set('key1', 'val1');
map.set('key2', 'val2');
for(const [key, value] of map) {
  console.log('Attribute:' + key +', value: '+ value);
}
```

## Preferentially Use Array Object Methods for Array Traversal

**[Category] Rule**

**[Description]**

To traverse an array, preferentially use the methods provided by **Array**, such as **forEach()**, **map()**, **every()**, **filter()**, **find()**, **findIndex()**, **reduce()**, and **some()**.
Do not use **for in** to traverse an array.

**[Incorrect Example]**

```javascript
const numbers = [1, 2, 3, 4, 5];
let sum = 0;
// Use for in to traverse the array.
for (const num in numbers) {
  console.log(num);
  sum += num;
}
// Use for to traverse an existing array to generate a new array.
const increasedByOne = [];
for (let i = 0; i < numbers.length; i++) {
  increasedByOne.push(numbers[i] + 1);
}
```

**[Correct Example]**

```javascript
const numbers = [1, 2, 3, 4, 5];
// Use for of to traverse the array and obtain the sum.
let sum = 0;
for (const num of numbers) {
  sum += num;
}
// Use forEach to traverse the array and obtain the sum.
let sum = 0;
numbers.forEach(num => sum += num);
// Better: Use the reduce method to obtain the sum.
const sum = numbers.reduce((total, num) => total + num, 0);
// Use forEach to traverse an existing array to generate a new array.
const increasedByOne = [];
numbers.forEach(num => increasedByOne.push(num + 1));
// Better: Use the map method.
const increasedByOne = numbers.map(num => num + 1);
```

# Operation and Expressions

## Use === and !==, Instead of == or !=, to Check Whether the Operands Are Equal

**[Category] Rule**

**[Description]**

In JavaScript, type conversion is automatically performed when the **==** operator is used for equality judgment. For example, the values of **[] == false**, **[] == ![]**, and **3 == '03'** are **true**. For higher efficiency, use **===** in comparison when the type is determined.

**[Incorrect Example]**

```javascript
age == bee
foo == true
bananas != 1
value == undefined
typeof foo == 'undefined'
'hello' != 'world'
0 == 0
true == true
```

**[Correct Example]**

```javascript
age === bee
foo === true
bananas !== 1
value === undefined
typeof foo === 'undefined'
'hello' !== 'world'
0 === 0
true === true
```

**[Exceptions]**

```javascript
// Use the following to determine whether an object is null:
obj == null
obj != null
```

## Do Not Assign Values in Control Conditional Expressions

**[Category] Rule**

**[Description]**

Control conditional expressions are usually used in conditional statements such as **if**, **while**, **for**, and **?:**.
Assigning values in this type of expression often leads to unexpected behavior and poor code readability.

**[Incorrect Example]**

```javascript
// It is difficult to understand the value assignment in the control conditional expression. 
if (isFoo = false) {
  ...
}
```

**[Correct Example]**

```javascript
const isFoo = someBoolean; // Assign a value above and directly use it in the if statement.
if (isFoo) {
  ...
}
```

# Functions

## Use the Same Return Statement

**[Category] Rule**

**[Description]**

Unlike statically typed languages that force a function to return a value of a specified type, JavaScript allows different code paths in a function to return different types of values.

JavaScript returns **undefined** in the following cases:

1. The **return** statement is not executed before the exit.
1. The **return** statement is executed, but no value is explicitly assigned.
1. The **return undefined** statement is executed.
1. The **return void** statement is executed, followed by an expression (for example, a function call).
1. The **return** statement is executed, followed by another expression equivalent to **undefined**.

In a function (especially in a larger function), if any code path explicitly returns a value but the other code paths do not explicitly return a value, this may be a coding error. Therefore, use the same **return** statement in a function.

**[Incorrect Example]**

```javascript
function doSomething(condition) {
  if (condition) {
    ...
    return true;
  } else {
    ...
    return;
  }
}
function doSomething(condition) {
  if (condition) {
    ...
    return true;
  }
}
```

**[Correct Example]**

```javascript
// Ensure that all paths return values in the same way.
function doSomething(condition) {
  if (condition) {
    ...
    return true;
  } else {
    ...
    return false;
  }
}

function doSomething(condition) {
  if (condition) {
    ...
    return true;
  }
  ...
  return false;
}
```

## Use rest Instead of arguments

**[Category] Rule**

**[Description]**

The **rest** parameter is an array, and all array methods, such as **sort**, **map**, **forEach**, and **pop**, can be directly used on it. **arguments** is a class array. Therefore, use the **rest** syntax instead of **arguments**. In addition, place the **rest** parameter as the last parameter in the list.

**[Incorrect Example]**

```javascript
function concatenateAll() {
  // arguments is a class array, and the join method can be used only after arguments is converted to a real array.
  const args = Array.prototype.slice.call(arguments);   
  return args.join('');
}
```

**[Correct Example]**

```javascript
function concatenateAll(...args) {
  return args.join('');
}
```

## Do Not Assign this to a Variable; Use this in a Scope

**[Category] Rule**

**[Description]**

Arrow functions provide a simpler syntax. **this** in an arrow function points to the object when it is defined. Assigning **this** to a variable is confusing.

**[Incorrect Example]**

```javascript
function foo() {
  const self = this;
  return function() {
    console.log(self);
  };
}
```

**[Correct Example]**

```javascript
function foo() {
  return () => {
    console.log(this);
  };
}
```

For details, see [@typescript-eslint/no-this-alias](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-this-alias.md).

The description of ESLint is stricter. Therefore, do not assign **this** to a variable in any case.

# Classes and Objects

## Use Dots to Access Object Attributes and [] to Access Computed Attributes

**[Category] Rule**

**[Description]**

In JavaScript, you can use dots (**foo.bar**) or square brackets (**foo['bar']**) to access attributes. The use of dots is preferred because it is more readable, concise, and more suitable for JavaScript compression.

**[Correct Example]**

```javascript
const name = obj.name;
const key = getKeyFromDB();
const prop = obj[key]; // Use [] only when the attribute name is a variable.
```

## Do Not Modify the Prototype of a Built-in Object or Add Methods to the Prototype

**[Category] Rule**

**[Description]**

As a set of public interfaces, built-in objects have conventional behavior modes. Any modification to the prototype of a built-in object may damage the semantics. Therefore, never modify the prototype of a built-in object, or add methods to the prototype.

**[Incorrect Example]**

```javascript
Array.prototype.indexOf = function () {
  return -1;
}
// Used in other places.
const arr = [1, 1, 1, 1, 1, 2, 1, 1, 1];
console.log (arr.indexOf(2)); // Output -1.
```

## Do Not Delete the Computed Attributes of an Object

**[Category] Rule**

**[Description]**

The delete operation changes the layout of an object. Deleting the computed attributes of an object is a dangerous behavior. It greatly restricts the runtime optimization and affects the execution performance.

You are advised not to delete any attribute of an object. If necessary, use **map** and **set**.

**[Incorrect Example]**

```javascript
// Can be replaced with the constant equivalents, such as container.aaa
delete container['aaa'];

// Dynamic, difficult-to-reason-about lookups
const name = 'name';
delete container[name];
delete container[name.toUpperCase()];
```

**[Correct Example]**

```javascript
// The code affects the optimization performance to some extent, but it is better than deleting the computed attributes.
delete container.aaa;

delete container[7];
```

For details, see [@typescript-eslint/no-dynamic-delete](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-dynamic-delete.md).

# Exceptions

## Do Not Use return, break, continue, or throw to End the Finally Block Abnormally

**[Category] Rule**

**[Description]**

In the finally block, if the **return**, **break**, **continue**, or **throw** statement is directly used or the exception that occurs during the method calling is not handled, the finally block ends abnormally. Such a block affects the throwing of exceptions in the **try** or **catch** block, or even the return value of the method. Therefore, you must ensure that the finally block ends normally.

**[Incorrect Example]**

```javascript
function foo() {
  try {
    ...
    return 1;
  } catch(err) {
    ...
    return 2;
  } finally {
    return 3;
 }
}
```

**[Correct Example]**

```javascript
function foo() {
  try {
    ...
    return 1;
  } catch(err) {
    ...
    return 2;
  } finally {
    console.log('XXX!');
  }
}
```

# Async Functions

## Use return await Only When Necessary

**[Category] Rule**

**[Description]**

The return value of an async function is always encapsulated in **Promise.resolve**. The **return await** statement does not actually do anything, but adds time before **Promise.resolve** or **reject**. Therefore, use **return await** only in the **try** or **catch** statement to capture errors of another promise-based function.

**[Incorrect Example]**

```javascript
async function foo() {
  return await bar();
}
```

**[Correct Example]**

```javascript
async function foo() {
  return bar();
}
async function foo() {
  await bar();
  return;
}
async function foo() {
  const baz = await bar();
  return baz;
}
async function foo() {
  try {
    return await bar();
  } catch (error) {
    // here can be executed, go on
  }
}
```

## Do Not Wait for a Non-thenable Value

**[Category] Rule**

**[Description]**

**await** converts a non-thenable value to a promise that has been processed normally and waits for the processing result. In this case, the use of **await** affects the code performance.

**[Incorrect Example]**

```javascript
async function f3() {
  const y = await 20;
  console.log(y); // 20
}

f3();
console.log(30);

// output
// 30
// 20
```

**[Correct Example]**

```javascript
async function f3() {
  const y = 20;
  console.log(y); // 20
}

f3();
console.log(30);

// output
// 20
// 30
```

For details, see [@typescript-eslint/await-thenable](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/await-thenable.md).

# Types

## Forcibly Mark null and undefined as Independent Types

**[Category] Rule**

**[Description]**

Marking **null** and **undefined** as independent types improves code security and avoids null pointer exceptions.

**[Incorrect Example]**

```javascript
let userName: string;
userName = 'hello';
userName = undefined;
```

**[Correct Example]**

```javascript
let userName: string | undefined;
userName = 'hello';
userName = undefined;
```

## Explicitly Declare the Return Value Types of Functions and Class Methods

**[Category] Rule**

**[Description]**

Explicitly declare the return value type to ensure that the return value is assigned to the variable of the correct type. In addition, the explicit declaration ensures that **undefined** is not assigned to a variable when there is no return value.

**[Incorrect Example]**

```javascript
// When there is no return value, the return value type is not declared as void.
function test() {
  return;
}
// The return value type is not declared as number.
function fn() {
  return 1;
};
// The return value type is not declared as string.
let arrowFn = () => 'test';
class Test {
  // When there is no return value, the return value type is not declared as void.
  method() {
    return;
  }
}
```

**[Correct Example]**

```javascript
// When there is no return value, explicitly declare the return value type as void.
function test(): void {
  return;
}
// Explicitly declare the return value type as number.
function fn(): number {
  return 1;
};
// Explicitly declare the return value type as string.
let arrowFn = (): string => 'test';
class Test {
  // When there is no return value, explicitly declare the return value type as void.
  method(): void {
    return;
  }
}
```

For details, see [@typescript-eslint/explicit-function-return-type](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/explicit-function-return-type.md).

## Use Consistent Export Types

**[Category] Rule**

**[Description]**

To export a type, write the type to export and the objects to export separately.

**[Incorrect Example]**

```javascript
interface ButtonProps {
  onClick: () => void;
}
class Button implements ButtonProps {
  onClick() {
    console.log('button!');
  }
}
export { Button, ButtonProps };
```

**[Correct Example]**

```javascript
interface ButtonProps {
  onClick: () => void;
}
class Button implements ButtonProps {
  onClick() {
    console.log('button!');
  }
}
export { Button };
export type { ButtonProps };
```

For details, see [@typescript-eslint/consistent-type-exports](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/consistent-type-exports.md).

## Use Consistent Import Types

**[Category] Rule**

**[Description]**

To import a type, write the type to import and the objects to import separately.

**[Incorrect Example]**

```javascript
import { Foo } from 'Foo';
import Bar from 'Bar';
type T = Foo;
const x: Bar = 1;
```

**[Correct Example]**

```javascript
import type { Foo } from 'Foo';
import type Bar from 'Bar';
type T = Foo;
const x: Bar = 1;
```

For details, see [@typescript-eslint/consistent-type-imports](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/consistent-type-imports.md).

## Do Not Use any

**[Category] Rule**

**[Description]**

If the **any** type is used, all type checks during compilation are ignored. This behavior is not necessary and does not meet expectations. If the type is unknown, use **unknown**.
If the introduced third-party component does not use TypeScript or does not provide the TypeScript type declaration, you can use **any** to declare the related third-party component objects.

## Do Not Define the any Type

**[Category] Rule**

**[Description]**

Do not define the **any** type. This restriction makes types as clear as possible in TypeScript and helps the runtime optimization.

**[Incorrect Example]**

```javascript
const age: any = 'seventeen';
function greet(): any {}
function greet(param: Array<any>): string {}
```

**[Correct Example]**

```javascript
const age: number = 17;
function greet(): string {}
function greet(param: Array<string>): string {}
```

For details, see [@typescript-eslint/no-explicit-any](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-explicit-any.md).

## Do Not Pass In any as a Parameter

**[Category] Rule**

**[Incorrect Example]**

```javascript
declare function foo(arg1: string, arg2: number, arg3: string): void;

const anyTyped = 1 as any;

foo(...anyTyped);
foo(anyTyped, 1, 'a');

const tuple1 = ['a', anyTyped, 'b'] as const;
foo(...tuple1);
```

**[Correct Example]**

```javascript
declare function foo(arg1: string, arg2: number, arg3: string): void;

foo('a', 1, 'b');

const tuple1 = ['a', 1, 'b'] as const;
foo(...tuple1);
```

For details, see [@typescript-eslint/no-unsafe-argument](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-unsafe-argument.md).

## Do Not Use any in Value Assignment

**[Category] Rule**

**[Incorrect Example]**

```javascript
const x = 1 as any,

const x: Set<string> = new Set<any>();
```

**[Correct Example]**

```javascript
const x = 1;

const x: Set<string> = new Set<string>();
```

For details, see [@typescript-eslint/no-unsafe-assignment](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-unsafe-assignment.md).

## Do Not Call a Variable with the any Type

**[Category] Rule**

**[Incorrect Example]**

```javascript
declare const anyVar: any;
declare const nestedAny: { prop: any };

anyVar();
anyVar.a.b();

nestedAny.prop();
nestedAny.prop['a']();
```

**[Correct Example]**

```javascript
declare const typedVar: () => void;
declare const typedNested: { prop: { a: () => void } };

typedVar();
typedNested.prop.a();
```

For details, see [@typescript-eslint/no-unsafe-call](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-unsafe-call.md).

## Do Not Access Members of an Object with the any Type

**[Category] Rule**

**[Incorrect Example]**

```markup
declare const anyVar: any;
declare const nestedAny: { prop: any };

anyVar.a;
anyVar.a.b;

nestedAny.prop.a;
nestedAny.prop['a'];
```

**[Correct Example]**

```javascript
declare const properlyTyped: { prop: { a: string } };

properlyTyped.prop.a;
properlyTyped.prop['a'];
```

For details, see [@typescript-eslint/no-unsafe-member-access](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-unsafe-member-access.md).

## Do Not Declare the Return Value Type of a Function as any or any[]

**[Category] Rule**

**[Incorrect Example]**

```javascript
function foo1() {
  return 1 as any;
}
```

**[Correct Example]**

```javascript
function foo1() : number {
  return 1;
}
```

For details, see [@typescript-eslint/no-unsafe-return](https://github.com/typescript-eslint/typescript-eslint/blob/main/packages/eslint-plugin/docs/rules/no-unsafe-return.md).

# References

1. [JavaScript Coding Style Guide](OpenHarmony-JavaScript-coding-style-guide.md)
1. [ESLint Rules](https://github.com/typescript-eslint/typescript-eslint/tree/main/packages/eslint-plugin/docs/rules)
1. High Performance JavaScript
