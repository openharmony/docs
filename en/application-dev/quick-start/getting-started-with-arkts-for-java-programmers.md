# Migrating from Java to ArkTS

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=d6200ee580e2d2b406a92c0e4a15bf6480d0d39a translatedAt=2026-08-13T09:05:36.340Z pushedAt=2026-08-13T13:48:08.313Z -->

ArkTS is a new programming language that brings new development experience and opportunities to developers familiar with Java. It inherits the features of modern languages in terms of syntax and programming paradigms, and is deeply optimized for the ecosystem. Understanding the differences and commonalities between Java and ArkTS can help you quickly get started with application development and avoid common programming pitfalls.

This document compares and introduces ArkTS based on the Java language. For more details, see [ArkTS syntax](./arkts-language-guide-basics.md).

## Exploring the Differences Between Java and ArkTS

The following will sort out the misunderstandings and pitfalls you may encounter when migrating a Java project to ArkTS due to differential syntax, type system, and application development mode. You are advised to master the basic syntax and runtime behavior of ArkTS, and then focus on the differences between ArkTS and Java.

## Basic Syntax

### Variable Declaration

**Sample code in ArkTS**:

<!-- @[variable_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromJavaToArkTS/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// Type annotation (similar to Java).
let age: number = 20;
const program: string = 'ArkTS';

// Type inference (similar to that of local variable in Java).
let version = 5.0;
```

### Primitive Types

| Java      | ArkTS           | Sample Code                         | Key Difference                 |
|----------------|----------------------|-----------------------------------|-------------------------------|
| `boolean`      | `boolean`            | `let isDone: boolean = false;`    | They are defined similarly and used for logical judgments in Java and ArkTS, with no runtime boxing or unboxing operations.                     |
| `byte`         | `number`             | `let b: number = 100;`            | In Java, `byte` is an 8-bit integer.<br>ArkTS uses a single `number` type to represent it, and `number` is a double-precision floating-point type that can store both integers and floating-point numbers. |
| `short`        | `number`             | `let s: number = 300;`            | In Java, `short` is a 16-bit integer.<br>ArkTS uses a single `number` type to represent it, and `number` is a double-precision floating-point type that can store both integers and floating-point numbers. |
| `int`          | `number`             | `let count: number = 10;`         | In Java, `int` is a 32-bit integer.<br>ArkTS uses a single `number` type to represent it, and `number` is a double-precision floating-point type that can store both integers and floating-point numbers.       |
| `long`         | `number`             | `let largeNum: number = 9007199254740991;` | In Java, an `L` suffix is required (for example, `9007199254740991L`).<br>ArkTS uses a single `number` type to represent it, and `number` is a double-precision floating-point type.          |
| `float`        | `number`             | `let pi: number = 3.14;`          | In Java, an `f` suffix is required (for example, `3.14f`).<br>ArkTS uses a single `number` type to represent it, and `number` is a double-precision floating-point type.       |
| `double`       | `number`             | `let e: number = 2.71828;`        | Java distinguishes between `float` and `double`.<br>ArkTS uses a single `number` type to represent it, and `number` is a double-precision floating-point type.         |
| `char`         | `string`             | `let c: string = 'a';`            | ArkTS: **string**, instead of **char**, is used to represent string type.  |
| `String`       | `string`             | `let message: string = 'Hello';`  | They are defined similarly, but the **string** type of ArkTS supports template literals (for example, **${name}**) and more flexible operations. |

### Complication Types

| Java               | ArkTS           | Sample Code in ArkTS                                                                | Key Difference                                                                |
|-----------------------------|--------------------------|-------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| **Array**: `int[] arr = new int[5];`| **Array**: `let arr: Array<number> = [1, 2, 3];`| `// Initialize an array at fixed length (similar to Java).`<br>`let fixedArr: number[] = new Array<number>(5);`<br>`// Initialize an array at dynamic length. Syntactic sugar is used.`<br>`let dynamicArr = [4, 5, 6];`<br>| The length of a Java array is fixed.<br>The length of an ArkTS array is dynamic. Operations such as **push** and **pop** are supported. You can use **[]** to simplify initialization. ArkTS array does not go out of bounds. If the array subscript exceeds the array length, **undefined** is returned.|
| **List**: `List<String> list = new ArrayList<>();`| **Array**: `let strList: Array<string> = ['a', 'b'];`| `strList.push('c'); // Push an element to the end of an array.`<br>`let firstItem = strList[0]; // Access by index.`<br>| Java list separates APIs (such as **List**) from implementation classes (such as **ArrayList**).<br>ArkTS array uses basic types and set features, simplifying syntax.|
| **Map**: `Map<String, Integer> map = new HashMap<>();`| **Map**: `let map: Map<string, number> = new Map();`| `map.set('key', 1); // Add a KV pair.`<br>`let value = map.get('key'); // Obtain the value.`<br>`map.has('key'); // Check whether the key exists.`<br>|Java **Map** requires explicit declaration of generic types.<br>ArkTS **Map** supports chain calls (such as **map.set('a', 1).set('b', 2)**), which is more direct.|
| **Interface**: `interface Shape { double area(); }` | **interface**: `interface Shape { area(): number; }` | ```class Rectangle implements Shape {```<br>```  public width: number = 0;```<br>```  public height: number = 0;```<br>```  area(): number { return this.width * this.height; }```<br>```}```<br> | The syntax is similar, but ArkTS interface implementations do not require explicit modifiers (such as Java's `public`), and they support optional properties (such as `name?: string`). |
| **Class**: `class Circle implements Shape { /* Class definition */ }` | **class**: `class Circle implements Shape { /* Class definition */ }` | ```class Circle {```<br>```  radius: number;```<br>```  constructor(radius: number = 10) { // Support default parameter values.```<br>```    this.radius = radius;```<br>```  }```<br>```}```<br> | ArkTS classes support default property values and optional parameters, making the syntax more concise. |
| **Enum**: `enum Color { RED, GREEN, BLUE; }`| **enum**: `enum Colors { Red, Green, Blue }`| `enum Colors { Red = 1, Green, Blue };`<br>`let color = Colors.Green; // The value is 2, which is automatically incremented.`<br>| The basic concepts are the same. However, ArkTS enum does not support custom constructors and methods like Java. Only a simple numeric or string enum is supported.|

### Functions

**Sample code in ArkTS**:

<!-- @[function_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromJavaToArkTS/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// Define a common function.
function add(x: number, y: number): number {
  return x + y;
}
  // ...
  // Define a concise arrow function.
  const multiply = (a: number, b: number): number => a * b;
```

### Function Overloading

Java supports compile-time polymorphism, allowing multiple methods with the same name in the same class. The methods are distinguished by the parameter list in terms of quantity, type, and sequence.

* Overloading is implemented through multiple specific methods, each of which has an independent method body.

* The parameter list (type, quantity, and sequence) must be different, but the return value type can be the same or different.

* A specific method is selected based on the parameter type during compilation.

**Sample code in Java**: Java function overloading

```java
class Example {
    // Method 1: Accepts an int parameter.
    void print(int value) {
        System.out.println("Integer: " + value);
    }

    // Method 2: Accepts a String parameter.
    void print(String value) {
        System.out.println("String: " + value);
    }
}
```

ArkTS provides polymorphism at the type declaration level, which is used only for type check and document prompt. There is only one implementation function.

* Overload signatures via type declarations, but there is only one implementation function.

* The implementation function must be compatible with all overload signatures. Generally, you need to manually determine the parameter type in the function body.

* The type checker matches the declaration based on the called parameters, but only one function is available at runtime.

**Sample code in ArkTS**: ArkTS function overloading

<!-- @[function_overloading](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromJavaToArkTS/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
function foo(x: number): void;            /* First function definition */
function foo(x: string): void;            /* Second function definition */
function foo(x: number | string): void {  /* Function implementation */
}
  // ...
  foo(123);     // OK. Use the first function definition.
  foo('aa'); // OK. Use the second function definition.
```

### Utils

The ArkTS basic class library and container class library enhance the basic features of the programming language, including high-precision floating-point operations, binary buffer, XML generation, parsing, conversion, and multiple container libraries, reducing development workload and improving efficiency. For details, see [Overview of the ArkTS Common Library](../arkts-utils/arkts-utils-overview.md).

## Language Structure

Java is a typical object-oriented programming language, which means that all projects are developed based on classes and objects.

ArkTS adopts a more flexible language structure and integrates multiple paradigms such as object-oriented programming and functional programming.

### Module and Package Management

Java allows you to use packages to organize code and import classes in other packages using the **import** statement. ArkTS also has its own module and package management mechanism, and uses the **import** statement to import functions in other modules.

**Sample code in ArkTS**:

<!-- @[import_package](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromJavaToArkTS/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// Import the ArkTS container set in the ArkTS standard library.

import { collections } from '@kit.ArkTS';
```

The module system of ArkTS focuses more on modular development and code reuse, so it can conveniently manage dependencies between different functional modules. In this case, the usage is different from that of Java package management.

### Class and Namespace

The class system of ArkTS is similar to that of Java in syntax, but it offers more advanced features.

| Feature      |Java Implementation     | ArkTS Implementation           | Description                         |
|------------|------------|------------------|-------------------------------|
| Namespace organization   | Static nested class/inner class    | **namespace** keyword or module file structure          | Supports the mixed mode of explicit namespace and modular organization.  |
| Inheritance mechanism       | Class-based inheritance mechanism       | Prototype chain-based inheritance mechanism          | Similar syntax with differential underlying mechanism.       |
| Class member visibility   | public/private/protected       | Same as Java, but supports [module-level](../arkts-utils/module-principle.md) visibility control.         | Added the dimension for controlling module export.|

**Namespace management**

ArkTS supports explicit namespaces and modular organization.

**Sample code in ArkTS**:

<!-- @[namespace_models](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromJavaToArkTS/entry/src/main/ets/pages/Index.ets) --> 

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

Compared with the combination of package and static class in Java, the namespace in ArkTS can be used to implement a more intuitive code layering.

### Asynchronous Programming Model

**Single-threaded or multi-threaded processing**

Java depends on multi-threading and **Future**/**CompletableFuture** to implement concurrency.

Based on the event loop, ArkTS uses a promise/**async**/**await** to process asynchronous tasks, preventing the main thread from being blocked.

**Error handling**

In Java, use **try/catch** to capture exceptions in synchronous code. For asynchronous code, handle exceptions in a special manner (for example, using **Future.get()**).

Uncaptured promise errors in ArkTS may cause silent failures. You need to explicitly use **try/catch** or **.catch()**.

### Binding of this

In Java, **this** always points to the instance of the current class, which is determined by the code structure during compilation. In a method, **this** points to the object instance that calls the method. The instance pointed by this cannot be changed by calling the method.

**Sample code in Java**:

```java
class MyClass {
  void method() {
    System.out.println(this); // Always points to the MyClass instance.
  }
}
```

In ArkTS, the instance pointed by **this** is determined by the context when the function is called.

**Sample code in ArkTS**:

<!-- @[class_this](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromJavaToArkTS/entry/src/main/ets/pages/Index.ets) --> 

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

  // callFunction(a.foo); // The program crashes because the context of this has changed.
  // b.callFunction(a.foo); // The program crashes because the context of this has changed.
  b.callFunction(a.foo.bind(b)) // Output 'I am B'.
```

## Type System

The type system of ArkTS is different from that of Java.

### Type Inference and Optional Types

Compared with Java that requires explicit type declaration and strict null check, the type system of ArkTS provides more flexible expression modes.

ArkTS has powerful type inference capabilities. The compiler can automatically infer the type of a variable based on the context. Therefore, you do not need to explicitly declare the type of a variable in most cases.

**Sample code in ArkTS**:

<!-- @[type_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromJavaToArkTS/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
let num = 10; // The compiler automatically infers that num is of the number type.
```

In addition, ArkTS supports optional types. You can add a question mark (?) to the end of a type to indicate that the variable can be **null** or **undefined**.

**Sample code in ArkTS**:

<!-- @[optional_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromJavaToArkTS/entry/src/main/ets/pages/Index.ets) --> 

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

<!-- @[unite_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/MigrationFromOtherLanguagesToArkTS/MigratingFromJavaToArkTS/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// Example of a union type.

let value: string | number;
value = 'hello';
value = 123;
```