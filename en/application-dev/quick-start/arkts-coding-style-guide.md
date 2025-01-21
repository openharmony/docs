# ArkTS Coding Style Guide

## Purpose

Based on the language characteristics of ArkTS, as well as industry standards and practices, this guide provides coding guidelines to improve code standardization, security, and performance.

This guide is applicable when you use ArkTS for coding during system or application development.

## Source

ArkTS further enhances static check and analysis while maintaining the basic syntax style of TypeScript. Some rules in this topic are selected from the [TypeScript and JavaScript Coding Style Guide](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/OpenHarmony-Application-Typescript-JavaScript-coding-guide.md), providing standards for ArkTS-specific syntax to improve code readability and execution performance.

## Document Structure

### Coding Style

Style for the naming and format.

### Programming Practices

Practices for declaration, initialization, data types, operations and expressions, and exceptions.

Guidelines in **TypeScript and JavaScript Coding Style Guide** that are involved in the ArkTS language are extracted, and new guidelines are added for ArkTS-specific syntax.

## Terms

|  Term  | Acronym/Abbreviation | Description|
|  ----  | ----  |  ----|
| ArkTS  | N/A| ArkTS programming language|
| TypeScript  | TS | TypeScript programming language|
| JavaScript  | JS | JavaScript programming language|
| ESObject  | N/A| JS/TS object in ArkTS cross-language calls|

## Principle

Guidelines are categorized as follows:

**Rule**: a convention that must be complied with. All contents in this document are for ArkTS.

**Recommendation**: a convention that must be considered.

## Naming

### Properly Name Identifiers to Make Them Easy to Read

**[Description]**

A well-named identifier meets the following basic requirements:
 - Clearly express the intent. Do not use single letters or non-conventional abbreviations.
 - Use correct English words in line with the English grammar. Do not use Pinyin.
 - Clearly express the meaning, and avoid misleading.

### Use UpperCamelCase for Class Names, Enum Names, and Namespace Names

**[Category]** Recommendation

**[Description]**

Classes are named in upper camel case.
Class names are usually nouns or noun phrases, for example, Person, Student, and Worker. Avoid verbs and ambiguous words like Data and Info in class names.

**[Correct Example]**
```
// Class name
class User {
  username: string

  constructor(username: string) {
    this.username = username;
  }

  sayHi() {
    console.log('hi' + this.username);
  }
}

// Enum name
enum UserType {
  TEACHER = 0,
  STUDENT = 1
};

// Namespace name
namespace Base64Utils {
  function encrypt() {
    // todo encrypt
  }

  function decrypt() {
    // todo decrypt
  }
};
```

### Use lowerCamelCase for Variable Names, Method Names, and Parameter Names

**[Category]** Recommendation

**[Description]**

A method is usually named as a verb or verb phrase in lower camel case. Examples are as follows:
1.   load + attributeName()
2.   put + attributeName()
3.   is + BooleanAttributeName()
4.   has + noun/adjective()
5.   verb()
6.   verb + object()
A variable name is usually a noun or noun phrase in lower camel case.

**[Correct Example]**
```
let msg = 'Hello world';

function sendMsg(msg: string) {
  // todo send message
}

let userName = 'Zhangsan';

function findUser(userName: string) {
  // todo find user by user name
}
```

### Use Uppercase Letters for Constant Names and Enum Value Names and Separate Words by Underscores

**[Category]** Recommendation

**[Description]**

A constant name must consist of uppercase letters separated by underscores (_). A constant name should express complete semantics whenever possible.

**[Correct Example]**

```
const MAX_USER_SIZE = 10000;

enum UserType {
  TEACHER = 0,
  STUDENT = 1
};
```

### Do Not Use Negative Boolean Variable Names

**[Category]** Recommendation

**[Description]**

It is recommended that a local variable of the Boolean type be prefixed with a meaningless expression, for example, is, has, can, or should. It is confusing when a logical NOT operator is used in a double negative phrase, for example, !isNotError. Therefore, avoid defining negative Boolean variable names.

**[Incorrect Example]**

```
let isNoError = true;
let isNotFound = false;

function empty() {}
function next() {}
```

**[Correct Example]**

```
let isError = false;
let isFound = true;

function isEmpty() {}
function hasNext() {}
```

## Format

### Use Spaces for Indentation

**[Category]** Recommendation

**[Description]**

Use spaces only to indent.

Preferentially use two-space indentation in most scenarios. Use four spaces in line break scenarios.
Do not use the Tab key to indent. Currently, almost all IDEs and code editors support automatic conversion of a Tab input to two spaces. The code editors should be configured to use spaces for indentation.

**[Correct Example]**

```
class DataSource {
  id: number = 0
  title: string = ''
  content: string = ''
}

const dataSource: DataSource[] = [
  {
    id: 1,
    title: 'Title 1',
    content: 'Content 1'
  },
  {
    id: 2,
    title: 'Title 2',
    content: 'Content 2'
  }

];

function test(dataSource: DataSource[]) {
  if (!dataSource.length) {
    return;
  }

  for (let data of dataSource) {
    if (!data || !data.id || !data.title || !data.content) {
      continue;
    }
    // some code
  }

  // some code
}
```

### Use No More Than 120 Characters in Each Line

**[Category]** Recommendation

**[Description]**

The code line width should not be too long. Otherwise, it is difficult to read.

The line width requirement encourages you to shorten method and variable names, reduce nesting, and write concise comments to improve code readability.
It is recommended that each line contain no more than 120 characters unless a longer line can significantly improve the code readability and no information is hidden.
Exception: If a one-line comment contains a command or URL of more than 120 characters, you can keep the line for ease in using copy, paste, and search with the **grep** command. Put the error information of preprocessor directives in one line to facilitate reading and understanding even if the line contains more than 120 characters.

### Use Braces in Conditional Statements and Loop Statements

**[Category]** Recommendation

**[Description]**

It is a best practice to add braces ({}) to the execution body of statements such as **if**, **for**, **do**, and **while**, because omitting the braces can cause errors and reduce code clarity.

**[Incorrect Example]**

```
if (condition)
  console.log('success');

for (let idx = 0; idx < 5; ++idx)
  console.log(idx);
```

**[Correct Example]**

```
if (condition) {
  console.log('success');
}

for (let idx = 0; idx < 5; ++idx) {
  console.log(idx);
}
```

### Indent case and default in the switch Statement Block

**[Category]** Recommendation

**[Description]**

Use two spaces to indent the case or default statement in a switch statement block. Use two spaces to indent the line feed statement after the switch label.

**[Correct Example]**

```
switch (condition) {
  case 0: {
    doSomething();
    break;
  }
  case 1: {
    doOtherthing();
    break;
  }
  default:
    break;
}
```

### Keep a Consistent Line Break Style for Expressions

**[Category]** Recommendation

**[Description]**

When a statement is too long or difficult to read, start a new line at a proper position.
During line breaking, always place operators at the end of lines, indicating that the operations are to be continued. This is also the default configurations of typical formatting tools.

**[Correct Example]**

```
// The if conditional statement exceeds the line width.
if (userCount > MAX_USER_COUNT ||
  userCount < MIN_USER_COUNT) {
  doSomething();
}
```

### Do Not Put Multiple Variable Definitions and Assignment Statements in a Line

**[Category]** Rule

**[Description]**

Each statement should declare only one variable.
In this way, it is easier to add variable declarations and can avoid errors, because you do not need to consider changing a semicolon (;) to a comma (,). It is also easier for the debugger to debug variables one by one, rather than skipping all variables at a time.

**[Incorrect Example]**

```
let maxCount = 10, isCompleted = false;
let pointX, pointY;
pointX = 10; pointY = 0;
```

**[Correct Example]**

```
let maxCount = 10;
let isCompleted = false;
let pointX = 0;
let pointY = 0;
```

### Use Spaces to Highlight Keywords and Important Information

**[Category]** Recommendation

**[Description]**

Use spaces to highlight keywords and important information. The general recommendations are as follows:
1.   Add a space between keywords such as **if**, **for**, **while**, and **switch** and the open parentheses.
2.   Do not add a space between the method name and the open parentheses of the parameter list when defining or calling the method.
3.   Add a space between the keyword **else** or **catch** and the close brace (}).
4.   Add a space before the open brace ({), except when:
a. The open brace is used as the first parameter of a method or the first element in an array, for example, **foo({ name: 'abc' })**.
b. The open brace is used in a template name, for example, **abc${name}**.
5.   Spaces are added before and after the binary operator (+, -, *, =, <, >, <=, >=, ===, !==, &&, ||). Spaces are added on both sides of the ternary operator (?, :).
6.   Add a space after the comma in array initialization and the comma between multiple parameters in a method.
7.   Do not add a space before a comma (,) or semicolon (;).
8.   Do not add spaces inside the square brackets ([]) of an array.
9.   Do not contain multiple consecutive spaces. It is a bad practice if consecutive spaces in a line are not used for indentation.

**[Incorrect Example]**

```
// There is no space between if and the open parenthesis.
if(isJedi) {
  fight();
}

// There is a space between the method name fight and the open parenthesis.
function fight (): void {
  console.log('Swooosh!');
}
```

**[Correct Example]**

```
// There is a space between if and the open parenthesis.
if (isJedi) {
  fight();
}

// There is no space between the method name fight and the open parenthesis.
function fight(): void {
  console.log('Swooosh!');
}
```

**[Incorrect Example]**

```
if (flag) {
  //...
}else {  // There is no space between the close brace and else.
  //...
}
```

**[Correct Example]**

```
if (flag) {
  //...
} else {  // There is a space between the close brace and else.
  //...
}
```

**[Correct Example]**

```
function foo() {  // There is a space before the open brace in the method declaration.
  //...
}

bar('attr', {  // There is a space before the open brace.
  age: '1 year',
  sbreed: 'Bernese Mountain Dog',
});
```

**[Correct Example]**

```
const arr = [1, 2, 3];  // There is a space after the comma during array initialization. There is no space before the comma.
myFunc(bar, foo, baz);  // There is a space after the comma between multiple parameters of a method. There is no space before the comma.
```

### Use Single Quotation Marks for Strings

**[Category]** Recommendation

**[Description]**

Use single quotation marks for strings.

**[Incorrect Example]**

```
let message = "world";
console.log(message);
```

**[Correct Example]**

```
let message = 'world';
console.log(message);
```

### If an Object Literal Has More Than Four Properties, Place Each of Them at Separate Lines

**[Category]** Recommendation

**[Description]**

The properties of an object literal should be all placed at the same line or each at a separate line. If an object literal has more than four properties, place each of them at separate lines.

**[Incorrect Example]**

```
interface I {
  name: string
  age: number
  value: number
  sum: number
  foo: boolean
  bar: boolean
}

let obj: I = { name: 'tom', age: 16, value: 1, sum: 2, foo: true, bar: false }
```

**[Correct Example]**

```
interface I {
  name: string
  age: number
  value: number
  sum: number
  foo: boolean
  bar: boolean
}

let obj: I = {
  name: 'tom',
  age: 16,
  value: 1,
  sum: 2,
  foo: true,
  bar: false
}
```

### Put else or catch in the Same Line as the Close Parenthesis of the if or try Code Block

**[Category]** Recommendation

**[Description]**

In conditional statements, place **else** in the same line as the close parenthesis of the **if** code block. Similarly, in exception handling statements, place **catch** in the same line as the close parenthesis of the **try** code block.

**[Incorrect Example]**

```
if (isOk) {
  doThing1();
  doThing2();
}
else {
  doThing3();
}
```

**[Correct Example]**

```
if (isOk) {
  doThing1();
  doThing2();
} else {
  doThing3();
}
```

**[Incorrect Example]**

```
try {
  doSomething();
}
catch (err) {
  // Error handling.
}
```

**[Correct Example]**

```
try {
  doSomething();
} catch (err) {
  // Error handling.
}
```

### Put the Open Brace and the Statement in the Same Line

**[Category]** Recommendation

**[Description]**

Follow a consistent style of using braces in the project. You are advised to put the open brace ({) and the control or declaration statement in the same line.

**[Incorrect Example]**

```
function foo()
{
  //...
}
```

**[Correct Example]**

```
function foo() {
  //...
}
```
 
## Programming Practices

### Add Accessible Modifiers for Class Attributes

**[Category]** Recommendation

**[Description]**

In ArkTS, the accessible modifiers **private**, **protected**, and **public** are provided. The default accessible modifier of an attribute is **public**. Selecting appropriate accessible modifiers can improve code security and readability. Note: If a class contains the **private** attribute, the class cannot be initialized through object literals.

**[Incorrect Example]**

```
class C {
  count: number = 0

  getCount(): number {
    return this.count
  }
}
```

**[Correct Example]**

```
class C {
  private count: number = 0

  public getCount(): number {
    return this.count
  }
}
```

### Do Not Omit 0s Before and After the Decimal Point of a Floating-Point Number

**[Category]** Recommendation

**[Description]**

In ArkTS, a floating-point number must contain a decimal point, but no digit is required before or after the decimal point. However, using digits before and after the decimal point can improve code readability.

**[Incorrect Example]**

```
const num = .5;
const num = 2.;
const num = -.7;
```

**[Correct Example]**

```
const num = 0.5;
const num = 2.0;
const num = -0.7;
```

### Use Number.isNaN() to Check Whether a Variable Is Number.NaN

**[Category]** Rule

**[Description]**

In ArkTS, **Number.NaN** is a particular value of a numeric data type. It represents a non-numeric value in the double-precision 64-bit format, as defined in the IEEE floating-point standard.
**Number.NaN** is unique in ArkTS because it is not equal to any value, including itself. Therefore, the result of comparison with **Number.NaN** is confusing, as the values of **Number.NaN !== Number.NaN** and **Number.NaN != Number.NaN** are both **true**.
Therefore, you must use **Number.isNaN()** to check whether a value is **Number.NaN**.

**[Incorrect Example]**

```
if (foo == Number.NaN) {
  // ...
}

if (foo != Number.NaN) {
  // ...
}
```

**[Correct Example]**

```
if (Number.isNaN(foo)) {
  // ...
}

if (!Number.isNaN(foo)) {
  // ...
}
```

### Preferentially Use Array Object Methods for Array Traversal

**[Category]** Rule

**[Description]**

To traverse an array, preferentially use the methods provided by **Array**, such as **forEach()**, **map()**, **every()**, **filter()**, **find()**, **findIndex()**, **reduce()**, and **some()**.

**[Incorrect Example]**

```
const numbers = [1, 2, 3, 4, 5];
// Use for to traverse an existing array to generate a new array.
const increasedByOne: number[] = [];
for (let i = 0; i < numbers.length; i++) {
  increasedByOne.push(numbers[i] + 1);
}
```

**[Correct Example]**

```
const numbers = [1, 2, 3, 4, 5];
// Better: Use the map method.
const increasedByOne: number[] = numbers.map(num => num + 1);
```

### Do Not Assign Values in Control Conditional Expressions

**[Category]** Rule

**[Description]**

Control conditional expressions are usually used in **if**, **while**, **for**, and **?:** statements.
Assigning values in this type of expression often leads to unexpected behavior and poor code readability.

**[Incorrect Example]**

```
// It is difficult to understand the value assignment in the control conditional expression.
if (isFoo = false) {
  ...
}
```

**[Correct Example]**

```
const isFoo = someBoolean; // Assign a value above and directly use it in the if statement.
if (isFoo) {
  ...
}
```

### Do Not Use return, break, continue, or throw in a finally Code Block

**[Category]** Rule

**[Description]**

If the **return**, **break**, **continue**, or **throw** statement is used in a **finally** code block or an exception that arise during method calling are not handled, the **finally** code block cannot properly stop. An abnormally stopped **finally** code block affects the throwing of exceptions in a **try** or **catch** block, and may affect the return value of a method. Therefore, ensure that the **finally** code block can stop properly.

**[Incorrect Example]**

```
function foo() {
  try {
    ...
    return 1;
  } catch (err) {
    ...
    return 2;
  } finally {
    return 3;
 }
}
```

**[Correct Example]**

```
function foo() {
  try {
    ...
    return 1;
  } catch (err) {
    ...
    return 2;
  } finally {
    console.log('XXX!');
  }
}
```

### Do Not Use ESObject

**[Category]** Recommendation

**[Description]**

**ESObject** is mainly used for type annotation in ArkTS and TS/JS cross-language calls. Using it in other scenarios introduces unnecessary cross-language calls and causes extra performance overhead.

**[Incorrect Example]**

```
// lib.ets
export interface I {
  sum: number
}

export function getObject(value: number): I {
  let obj: I = { sum: value };
  return obj
}

// app.ets
import { getObject } from 'lib'
let obj: ESObject = getObject(123);
```

**[Correct Example]**

```
// lib.ets
export interface I {
  sum: number
}

export function getObject(value: number): I {
  let obj: I = { sum: value };
  return obj
}

// app.ets
import { getObject, I } from 'lib'
let obj: I = getObject(123);
```

### Use T[] for the Array Type

**[Category]** Recommendation

**[Description]**

ArkTS provides two array types: **T[]** and **Array\<T>**. To ensure code readability, you are advised to use **T[]** to represent all array types.

**[Incorrect Example]**

```
let x: Array<number> = [1, 2, 3];
let y: Array<string> = ['a', 'b', 'c'];
```

**[Correct Example]**

```
// Use the T[] syntax.
let x: number[] = [1, 2, 3];
let y: string[] = ['a', 'b', 'c'];
```
