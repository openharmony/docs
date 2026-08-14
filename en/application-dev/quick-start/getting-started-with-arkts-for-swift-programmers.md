# Migrating from Swift to ArkTS

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=d6200ee580e2d2b406a92c0e4a15bf6480d0d39a translatedAt=2026-08-13T09:06:51.233Z pushedAt=2026-08-13T13:48:45.755Z -->

ArkTS is a new programming language that brings new development experience and opportunities to developers familiar with Swift. It inherits the features of modern languages in terms of syntax and programming paradigms, and is deeply optimized for the ecosystem. Understanding the differences and commonalities between Swift and ArkTS can help you quickly get started with application development and avoid common programming pitfalls.

This document compares and introduces ArkTS based on the Swift language. For more details, see [ArkTS Syntax](./arkts-language-guide-basics.md).

## Exploring the Differences Between Swift and ArkTS

The following will sort out the misunderstandings and pitfalls you may encounter when migrating a Swift project to ArkTS due to differential syntax, type system, and application development mode. You are advised to master the basic syntax and runtime behavior of ArkTS, and then focus on the differences between ArkTS and Swift.

## Basic Syntax

### Variable Declaration

**Sample code in ArkTS**:

<!-- @[swift_type_annotation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromSwiftToArkTS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Type annotation (similar to Swift)
let age: number = 20;
const program: string = 'ArkTS';

// Type inference (similar to Swift's local variable type inference)
let version = 5.0;
```

### Primitive Types

| Swift      | ArkTS           | Sample Code                         | Key Difference                 |
|----------------|----------------------|-----------------------------------|-------------------------------|
| `Bool`    | `boolean`     | `let isDone: boolean = false;`    | They are defined similarly and used for logical judgments in Swift and ArkTS.                     |
| `Int8`    | `number`      | `let count: number = 10;`         | In Swift, `Int8` is an 8-bit integer.<br>ArkTS uses `number` uniformly, which is a double-precision floating-point type that can store both integers and floating-point numbers.  |
| `Int16`   | `number`      | `let count: number = 10;`         | In Swift, `Int16` is a 16-bit integer.<br>ArkTS uses `number` uniformly, which is a double-precision floating-point type that can store both integers and floating-point numbers.|
| `Int32`   | `number`      | `let count: number = 10;`         | In Swift, `Int32` is a 32-bit integer.<br>ArkTS uses `number` uniformly, which is a double-precision floating-point type that can store both integers and floating-point numbers.       |
| `Int64`        | `number`             | `let largeNum: number = 9007199254740991;` | In Swift, large integers need to be handled.<br>ArkTS uses `number` uniformly, which is a double-precision floating-point type.          |
| `Float`        | `number`             | `let pi: number = 3.14;`          | In Swift, `Float` must be explicitly specified.<br>ArkTS uses `number` uniformly, which is a double-precision floating-point type.       |
| `Double`       | `number`             | `let e: number = 2.71828;`        | Swift distinguishes between `Float` and `Double`.<br>ArkTS uses `number` uniformly, which is a double-precision floating-point type.         |
| `Character`    | `string`             | `let c: string = 'a';`            | ArkTS: **string**, instead of **Character**, is used to represent string type.  |
| `String`       | `string`             | `let message: string = 'Hello';`  | They are defined similarly, but the **string** type of ArkTS supports template literals and more flexible operations. |

### Complication Types

| Swift               | ArkTS           | Sample Code in ArkTS                                                                | Key Difference                                                                |
|-----------------------------|--------------------------|-------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| **Array**: `var arr: [Int] = [1, 2, 3]`| **Array**: `let arr: number[] = [1, 2, 3];`| `// Initialize an array at dynamic length. Syntactic sugar is used.`<br>`let dynamicArr = [4, 5, 6];`<br>| The length of a Swift array can be changed.<br>The length of an ArkTS array is dynamic. Operations such as **push** and **pop** are supported. You can use **[]** to simplify initialization. ArkTS array does not go out of bounds. If the array subscript exceeds the array length, **undefined** is returned.|
| **Collection - Set**: `var mySet: Set<String> = ["a", "b"]` | **Set**: `let mySet: Set<string> = new Set(["a", "b"]);` | ```mySet.add('c'); // Add an element to the set.```<br>```for (const item of mySet) {...} // Iterate over the set.```<br> | Swift collections are declared through types.<br>In ArkTS, collection types are more flexible and suitable for dynamic scenarios. |
| **Dictionary**: var dict: [String: Int] = ["key": 1]| **Map**: `let map: Map<string, number> = new Map();`| `map.set('key', 1); // Add a KV pair.`<br>`let value = map.get('key'); // Obtain the value.`<br>`map.has('key'); // Check whether the key exists.`<br>| Swift **Dictionary** requires explicit declaration of types.<br>ArkTS Map supports chain calls, which is more direct.|
| **Protocol**: `protocol Shape { func area() -> Double }` | **interface**: `interface Shape { area(): number; }` | ```class Rectangle implements Shape {```<br>```  public width: number = 0;```<br>```  public height: number = 0;```<br>```  area(): number { return this.width * this.height; }```<br>```}```<br> | The syntax structures are similar, but ArkTS interface implementation does not require explicit modifiers and supports optional properties. |
| **Class**: `class Circle: Shape { /* class definition */ }` | **class**: `class Circle implements Shape { /* class definition */ }` | ```class Circle {```<br>```  radius: number;```<br>```  constructor(radius: number = 10) { // Support default parameter values.```<br>```    this.radius = radius;```<br>```  }```<br>```}```<br> | ArkTS classes support default property values and optional parameters, with more concise syntax. |
| **Enumeration**: `enum Color { case red, green, blue }`| **enum**: `enum Colors { Red, Green, Blue }`| `enum Colors { Red = 1, Green, Blue };`<br>`let color = Colors.Green; // The value is 2, which is automatically incremented.`<br>| The basic concepts are the same. However, ArkTS enum does not support custom constructors and methods like Swift. Only a simple numeric or string enum is supported.|

### Functions and Closures

The syntax of functions in Swift and ArkTS is similar, but there are subtle differences.

Similarities: regular function definition and arrow function.

**Sample code in ArkTS**: function definition

<!-- @[swift_function_definition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromSwiftToArkTS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Define a regular function, similar to Swift.
function add(x: number, y: number): number {
  return x + y;
}
  // ...
  // Use a concise arrow function, similar to Swift closure syntax.
  const multiply = (a: number, b: number): number => a * b;
```

Differences:

1. ArkTS provides polymorphism at the type declaration level, which is used only for type check and document prompt. There is only one implementation function.

   **Sample code in ArkTS**: ArkTS function overloading

   <!-- @[function_overload_demo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromSwiftToArkTS/entry/src/main/ets/pages/Index.ets) -->    

   ``` TypeScript
   function foo(x: number): void;            /* First function definition. */
   function foo(x: string): void;            /* Second function definition. */
   function foo(x: number | string): void {  /* Function implementation. */
   }
     // ...
     foo(123);     // OK, uses the first definition.
     foo('aa'); // OK, uses the second definition.
   ```

2. ArkTS uses **?** for optional parameters, for example, **function foo(name?: string)**, instead of the default value syntax in Swift.

   <!-- @[optional_parameter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromSwiftToArkTS/entry/src/main/ets/pages/Index.ets) -->    

   ``` TypeScript
   function foo2(name?: string) {}  /* name is an optional parameter. */
     // ...
     foo2('hello');     // OK, pass the name parameter.
     foo2();     // OK, do not pass the name parameter.
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

<!-- @[import_collections](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromSwiftToArkTS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Import the ArkTS container set from the ArkTS standard library.

import { collections } from '@kit.ArkTS';
```

The module system of ArkTS focuses more on modular development and code reuse, so it can conveniently manage dependencies between different functional modules. In this case, the usage is different from that of Swift module management.

### Class and Namespace

The class system of ArkTS is similar to that of Swift in syntax, but it offers more advanced features.

| Feature      |Swift Implementation     | ArkTS Implementation           | Description                         |
|------------|------------|------------------|-------------------------------|
| Namespace organization   | Nested structure/inner class    | **namespace** keyword or module file structure          | Supports the mixed mode of explicit namespace and modular organization.  |
| Inheritance mechanism       | Class-based inheritance mechanism       | Prototype chain-based inheritance mechanism          | Similar syntax with differential underlying mechanism.       |
| Class member visibility | public/private/internal | public/private/protected | Swift uses `internal` to control visibility within a module, while ArkTS uses `protected` to control visibility within a class and its subclasses, and controls the visibility scope through module exports. |

**Namespace management**

ArkTS supports explicit namespaces and modular organization.

**Sample code in ArkTS**:

<!-- @[namespace_demo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromSwiftToArkTS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
namespace Models {
  export class User {
    // Implementation details.
    // ...
  }

  export interface Repository {
    // Interface definition.
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
    print(self) // Always points to the MyClass instance.
  }
}
```

In ArkTS, the instance pointed by **this** is determined by the context when the function is called.

**Sample code in ArkTS**:

<!-- @[this_context](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromSwiftToArkTS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
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
  // ...
  let a: A = new A();
  let b: B = new B();

  // callFunction(a.foo); // The program crashes because the context of `this` has changed.
  // b.callFunction(a.foo); // The program crashes because the context of `this` has changed.
  b.callFunction(a.foo.bind(b)) // Output 'I am B'.
```

## Type System

The type system of ArkTS is different from that of Swift.

### Type Inference and Optional Types

Compared with Swift that requires explicit type declaration and strict null check, the type system of ArkTS provides more flexible expression modes.

ArkTS has powerful type inference capabilities. The compiler can automatically infer the type of a variable based on the context. Therefore, you do not need to explicitly declare the type of a variable in most cases.

**Sample code in ArkTS**:

<!-- @[auto_type_inference](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromSwiftToArkTS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
let num = 10; // The compiler automatically infers num as the number type.
```

<!-- @[optional_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromSwiftToArkTS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
interface Person {
  name: string;
  age?: number;  // age is an optional property.
}

const person: Person = {
  name: 'Alice',
};
```

### Union Type

Union type provides type combination capability for complex scenarios, which is an important innovation of the ArkTS type system.

ArkTS supports union types (separated using **|**). A union type indicates that a value can be one of multiple types.

**Sample code in ArkTS**:

<!-- @[union_type_demo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromSwiftToArkTS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Union type example.

let value: string | number;
value = 'hello';
value = 123;
```