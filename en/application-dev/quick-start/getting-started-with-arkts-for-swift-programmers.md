# Migrating from Swift to ArkTS

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @fanglou-->
<!--Designer: @qyhuo32-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @zhang_yixin13-->

ArkTS is a new programming language that brings new development experience and opportunities to developers familiar with Swift. It inherits the features of modern languages in terms of syntax and programming paradigms, and is deeply optimized for the ecosystem. Understanding the differences and commonalities between Swift and ArkTS can help you quickly get started with application development and avoid common programming pitfalls.

This topic compares ArkTS with Swift from the perspective of basic syntax, language structure, and type system. For details, see [Introduction to ArkTS](./introduction-to-arkts.md).

## Exploring the Differences Between Swift and ArkTS

The following will sort out the misunderstandings and pitfalls you may encounter when migrating a Swift project to ArkTS due to differential syntax, type system, and application development mode. You are advised to master the basic syntax and runtime behavior of ArkTS, and then focus on the differences between ArkTS and Swift.

## Basic Syntax

### Variable Declaration

**Sample code in ArkTS**:

```typescript
// Type annotation (similar to Swift).
let age: number = 20; 
const program: string = 'ArkTS';

// Type inference (similar to that of local variable in Swift).
let version = 5.0;
```

### Primitive Types 
| Swift      | ArkTS           | Sample Code                         | Key Difference                 |  
|----------------|----------------------|-----------------------------------|-------------------------------|  
| `Bool`    | `boolean`     | `let isDone: boolean = false;`    | They are defined similarly and used for logical judgments in Swift and ArkTS.                     |  
| `Int8`    | `number`      | `let count: number = 10;`         | Swift: the value of **Int8** type is an 8-bit integer.<br>ArkTS: **number** represents small-range integer type. |  
| `Int16`   | `number`      | `let count: number = 10;`         | Swift: the value of **Int16** type is a 16-bit integer.<br>ArkTS: **number** represents small-range integer type.|  
| `Int32`   | `number`      | `let count: number = 10;`         | Swift: the value of **Int32** type is a 32-bit integer.<br>ArkTS: **number** represents double-precision floating-point type, which can store integers and floating-point numbers.      |  
| `Int64`        | `number`             | `let largeNum: number = 9007199254740991;` | Swift: **Int64** represents large-range integer type.<br>ArkTS: **number** represents all numeric types.         |  
| `Float`        | `number`             | `let pi: number = 3.14;`          | Swift: **Float** needs to be explicitly specified.<br>ArkTS: `number` can be used directly.      |  
| `Double`       | `number`             | `let e: number = 2.71828;`        | Swift: the **Double** type is used.<br>ArkTS: **number** represents all numeric types.        |  
| `Character`    | `string`             | `let c: string = 'a';`            | ArkTS: **string**, instead of **Character**, is used to represent string type.  |  
| `String`       | `string`             | `let message: string = 'Hello';`  | They are defined similarly, but the **string** type of ArkTS supports template literals and more flexible operations. |  

### Complication Types
| Swift               | ArkTS           | Sample Code in ArkTS                                                                | Key Difference                                                                |  
|-----------------------------|--------------------------|-------------------------------------------------------------------------|-----------------------------------------------------------------------------|  
| **Array**: `var arr: [Int] = [1, 2, 3]`| **Array**: `let arr: Array<number> = [1, 2, 3];`| `// Initialize an array at dynamic length. Syntactic sugar is used.`<br>`let dynamicArr = [4, 5, 6];`<br>| The length of a Swift array can be changed.<br>The length of an ArkTS array is dynamic. Operations such as **push** and **pop** are supported. You can use **[]** to simplify initialization. ArkTS array does not go out of bounds. If the array subscript exceeds the array length, **undefined** is returned.|  
| **Set**: `var mySet: Set<String> = ["a", "b"]`| **Set**: `let mySet: Set<string> = new Set(["a", "b"]);`| `mySet.add('c'); // Add an element to the set.`<br>`for (const item of mySet) {...); // Iterate through the set.`<br>| Swift sets are declared by specifying types.<br>ArkTS sets are flexible and suitable for dynamic scenarios.|  
| **Dictionary**: `var dict: [String: Int] = ["key": 1]`| **Map**: `let map: Map<string, number> = new Map();`| `map.set('key', 1); // Add a KV pair.`<br>`let value = map.get('key'); // Obtain the value.`<br>`map.has('key'); // Check whether the key exists.`<br>| Swift **Dictionary** requires explicit declaration of types.<br>ArkTS Map supports chain calls, which is more direct.|  
| **Protocol**: `protocol Shape { func area() -> Double }`| **interface**: `interface Shapes { area(): number; }`| `class Rectangles implements Shapes {`<br>`  public width: number = 0;`<br>`  public height: number = 0;`<br>`  area(): number { return this.width * this.height; }`<br>`}`<br>| The syntax structures of Swift and ArkTS are similar, but ArkTS APIs do not require explicit modifiers and support optional properties.|  
| **Class**: `class Circle: Shape { /* Class definition */ }`| **class**: `class Circles implements Shape { /* Class definition */ }`| `class Circles {`<br>`  radius: number;`<br>`  constructor(radius: number = 10) { // Support default parameter values.`<br>`    this.radius = radius;`<br>`  }`<br>`}`<br>| ArkTS classes support default property values and optional parameters. Constructor parameters can be directly declared as class properties, which is more concise.|  
| **Enumeration**: `enum Color { case red, green, blue }`| **enum**: `enum Colors { Red, Green, Blue }`| `enum Colors { Red = 1, Green, Blue };`<br>`let color = Colors.Green; // The value is 2, which is automatically incremented.`<br>| The basic concepts are the same. However, ArkTS enum does not support custom constructors and methods like Swift. Only a simple numeric or string enum is supported.|  

### Functions and Closures

The syntax of functions in Swift and ArkTS is similar, but there are subtle differences.

Similarities: regular function definition and arrow function.

**Sample code in ArkTS**: function definition

```typescript
// Regular function definition, similar to that in Swift.
function add(x: number, y: number): number {
    return x + y;
}

// Concise arrow function definition, similar to the closure syntax in Swift.
const multiply = (a: number, b: number): number => a * b;
```

Differences:

1. ArkTS provides polymorphism at the type declaration level, which is used only for type check and document prompt. There is only one implementation function.

**Sample code in ArkTS**: ArkTS function overloading

```typescript
function foo(x: number): void;            /*  First function definition  */
function foo(x: string): void;            /*  Second function definition  */
function foo(x: number | string): void {  /*  Function implementation       */
}

foo(123);     // Use the first function definition.
foo('aa'); // Use the second function definition.
```

2. ArkTS uses **?** for optional parameters, for example, **function foo(name?: string)**, instead of the default value syntax in Swift.
```typescript
function foo(name?: string){}  /*  name is an optional parameter.  */

foo('hello');     //  Pass in the name parameter.
foo();     //  Do not pass in the name parameter.
```

### Utils

The ArkTS basic class library and container class library enhance the basic features of the programming language, including high-precision floating-point operations, binary buffer, XML generation, parsing, conversion, and multiple container libraries, reducing development workload and improving efficiency.

## Language Structure

Swift is a modern language that integrates object-oriented, functional, and protocol-oriented paradigms. It emphasizes security, performance, and simplicity, and is suitable for cross-platform development.

ArkTS integrates declarative UI, functional, and object-oriented paradigms. Leveraging its reactive system and cross-device adaptation capabilities, ArkTS efficiently builds high-performance applications with consistent experiences across multiple devices.

### Module and Package Management

Swift allows you to use modules to organize code and import classes in other modules using the **import** statement.

ArkTS also has its own module and package management mechanism, and uses the **import** statement to import functions in other modules.

**Sample code in ArkTS**:

```
// Import the ArkTS container set in the ArkTS standard library.

import { collections } from '@kit.ArkTS';
```

The module system of ArkTS focuses more on modular development and code reuse, so it can conveniently manage dependencies between different functional modules. In this case, the usage is different from that of Swift module management.

### Class and Namespace

The class system of ArkTS is similar to that of Swift in syntax, but it offers more advanced features.

| Feature      |Swift Implementation     | ArkTS Implementation           | Description                         |
|------------|------------|------------------|-------------------------------|
| Namespace organization   | Nested structure/inner class    | **namespace** keyword or module file structure          | Supports the mixed mode of explicit namespace and modular organization.  |
| Inheritance mechanism       | Class-based inheritance mechanism       | Prototype chain-based inheritance mechanism          | Similar syntax with differential underlying mechanism.       |
| Class member visibility   | public/private/internal       | Same as Java, but supports module-level visibility control.         | Added the dimension for controlling module export.|

**Namespace management**

ArkTS supports explicit namespaces and modular organization.

**Sample code in ArkTS**:

```typescript
namespace Models {
    export class User {
        // Implementation details.
    }
    
    export interface Repository {
        // API definition.
    }
}
```

Compared with the combination of module and inner class in Swift, the namespace in ArkTS can be used to implement a more intuitive code layering.

### Asynchronous Programming Model

**Single-threaded or multi-threaded processing**

Swift uses **async** or **await** and task to implement asynchronous programming and uses multi-threading and **DispatchQueue** to implement concurrency.

Based on the event loop, ArkTS uses a promise, **async**, or **await** to process asynchronous tasks, preventing the main thread from being blocked.

**Error handling**

In Swift, use **try/catch** to capture exceptions in synchronous code. For asynchronous code, handle exceptions in a special manner.

Uncaptured promise errors in ArkTS may cause silent failures. You need to explicitly use **try/catch** or **.catch**.

### Binding of self

In Swift, **self** always points to the instance of the current class, which is determined by the code structure during compilation. In a method, **self** points to the object instance that calls the method. The instance pointed by **self** cannot be changed by calling the method.

**Sample code in Swift**:

```swift
class MyClass {
  func method() {
    print(self) // Always points to the instance of MyClass.
  }
}
```

In ArkTS, the instance pointed by **this** is determined by the context when the function is called.

**Sample code in ArkTS**:

```typescript
class A {
  bar: string = 'I am A';

  foo() {
    console.info(this.bar);
  }
}

class B {
  bar: string = 'I am B';

  callFunction(fn: () => void) {
    fn();
  }
}

function callFunction(fn: () => void) {
  fn();
}

let a: A = new A();
let b: B = new B();

callFunction(a.foo); // Program crashes. The context of this changes.
b.callFunction(a.foo); // Program crashes. The context of this changes.
b.callFunction(a.foo.bind(b)) // Output 'I am B'.
```

## Type System

The type system of ArkTS is different from that of Swift.

### Type Inference and Optional Types

Compared with Swift that requires explicit type declaration and strict null check, the type system of ArkTS provides more flexible expression modes.

ArkTS has powerful type inference capabilities. The compiler can automatically infer the type of a variable based on the context. Therefore, you do not need to explicitly declare the type of a variable in most cases.

**Sample code in ArkTS**:

```typescript
let num = 10; // The compiler automatically infers that num is of the number type.
```

In addition, ArkTS supports optional types. You can add a question mark (?) to the end of a type to indicate that the variable can be **null** or **undefined**.

**Sample code in ArkTS**:

```typescript
interface Person {
  name: string;
  age?: number;  // age is an optional property.
}

const person: Person = {
  name: "Alice",
};
```

### Union Type

Union type provides type combination capability for complex scenarios, which is an important innovation of the ArkTS type system.

ArkTS supports union types (separated using **|**). A union type indicates that a value can be one of multiple types.

**Sample code in ArkTS**:

```typescript
// Example of a union type.

let value: string | number;
value = 'hello';
value = 123;

```
