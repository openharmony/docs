# ArkTS Migration Background

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao; @cy917474985-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=eaf9a3423e56fef11b14600736f6791af6ae7703 translatedAt=2026-08-13T09:02:21.750Z pushedAt=2026-08-13T13:44:10.187Z -->

Building on the basic syntax of TypeScript (TS), ArkTS further strengthens static checks and analysis. This allows for the detection of more errors during development, thereby enhancing program stability and running performance. This topic explains why it makes sense to migrate from the standard TS to ArkTS.

## Program Stability

Dynamically typed languages like JavaScript (JS) can improve development efficiency, but they are prone to unexpected runtime errors. For example, an unchecked **undefined** value may cause program breakdown. If such issues can be detected during development, the program stability can be significantly improved. TS allows to annotate the code with types, which makes errors more detectable for the compiler. However, its non-forcible type system still has limitations. For example, variables without type annotations may hinder complete compilation check. ArkTS overcomes this drawback by forcibly using a static type system and implementing a stricter type check, thereby minimizing runtime errors.

The following case demonstrates how we can improve stability and correctness of our code by enforcing stricter type checking in ArkTS.

**Explicit Initialization of Fields for Better Stability**

ArkTS requires that all fields are explicitly initialized with some values either when the field is declared or in **constructor**. This is similar to **strictPropertyInitialization** mode of the standard TS. Let's look at the following TS code:

```typescript
class Person {
  name: string; // undefined
  
  setName(n: string): void {
    this.name = n;
  }
  
  getName(): string {
  // Developers use "string" as the return type, which hides the fact that name may be "undefined".
  // A better approach is to annotate the return type as "string | undefined" to tell developers all possible return value types of this API.
    return this.name;
  }
}

let buddy = new Person()
// Assume that no value is assigned to name in the code. For example, buddy.setName("John") is not called.
buddy.getName().length; // Runtime exception: name is undefined.
```

ArkTS requires explicit initialization. The code is as follows:

<!-- @[def_person](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/ArkTSMigration/MigrationBackground/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
class Person {
  name: string = ''; // undefined

  setName(n: string): void {
    this.name = n;
  }

  // The type is "string", and it cannot be "null" or "undefined".
  getName(): string {
    return this.name;
  }
}
// ...
  let buddy = new Person()
  // Assume that name is not assigned in the code, for example, "buddy.setName('John')" is not called.
  let len = buddy.getName().length; // 0, no runtime exception.
```

If **name** can be **undefined**, its type must be accurately annotated in the code.

<!-- @[def_personFix](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/ArkTSMigration/MigrationBackground/entry/src/main/ets/pages/Index.ets) -->  

``` TypeScript
class Person1 {
  name?: string; // May be undefined.

  setName(n: string): void {
    this.name = n;
  }

  getName(): string | undefined { // The return type matches the type of name.
    return this.name;
  }
}
// ...
  let buddy = new Person1()
  // Assume that name is not assigned in the code, for example, "buddy.setName('John')" is not called.

  let len = buddy.getName()?.length; // Compilation succeeds without runtime errors.
```

## Program Performance

To ensure program correctness, dynamically typed languages have to check object types at runtime. In the context of our example, the **undefined** property cannot be read in JS. The only way to check if a value is **undefined** is to perform a runtime check, and all JS engines will perform as follows: If the value is not **undefined**, the property is read, otherwise an exception is thrown. Modern engines can optimize such checks greatly, but these checks cannot be eliminated completely, which slows down the program. Since the standard TS compiles to JS, the code written in TS has the same issues as described above. ArkTS addresses this problem. It enforces a static type check and compiles the program to Ark bytecode instead of JS, thus speeding up the execution and making it easier to optimize the code even further.

**Null Safety**

<!-- @[def_func](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/ArkTSMigration/MigrationBackground/entry/src/main/ets/pages/Index.ets) -->  

``` TypeScript
function notify(who: string, what: string) {
  console.info(`Dear ${who}, a message for you: ${what}`);
}

// ...
  notify('Jack', 'You look great today');
```

In most cases, the **notify** function will take two **string** variables as an input and produces a new string. However, what if we pass some "special" values to the function, for example **notify(null, undefined)**?

The program runs to completion and produces the expected output (**Dear null, a message for you: undefined**), so its behavior may appear correct at first glance. However, the engine that runs the code still checks for such special cases to ensure correct behavior. In pseudocode, something like this happens:

```typescript
function __internal_tostring(s: any): string {
  if (typeof s === 'string')
    return s;
  if (s === undefined)
    return 'undefined';
  if (s === null)
    return 'null';
  // ...
}
```

Now imagine that the **notify** function is a part of some complex heavy-loaded system which sends real notifications instead of just writing to the log. In this scenario, executing all these checks from the **__internal_tostring** function may turn into a performance problem.

But what if we could somehow guarantee to our execution engine that the only values that are passed to the **notify** function are "real" strings, but not some "special" values like **null** or **undefined**? In this case, checks like **__internal_tostring** become redundant because when we execute the program we can ensure that there will be no corner cases. For this particular case, this mechanism would be called "null-safety", which guarantees that **null** is not a valid value of the string type. If ArkTS has such feature, any code that does not match the type will be intercepted at the compilation stage and cannot be compiled.

```typescript
function notify(who: string, what: string) {
  console.info(`Dear ${who}, a message for you: ${what}`);
}

notify('Jack', 'You look great today');
notify(null, undefined); // Compile-time error
```

In TS such behavior can be turned on by a special compiler flag called **strictNullChecks**. But since the standard TS is compiled to JS, which does not have such feature, strict null checks work only in compile-time, for better type checking. However, ArkTS considers null-safety a very important feature from both stability and performance points of view. That is why it enforces strict null check and the example above always produces compile-time errors. In exchange, such code provides ArkTS engine with more information and guarantees about possible types, optimizing performance.

## .ets Code Compatibility

Prior to API version 10, ArkTS (.ets file) completely adopted the syntax of standard TS. Since API version 10, the ArkTS syntax rules are clearly defined. In addition, the SDK adds the ArkTS syntax validation for .ets files to the compilation process, and prompts you to adapt to the new ArkTS syntax through warnings or errors.

Syntax issues are classified as warning or error, depending on the **compatibleSdkVersion** of the project:

  - In standard mode, where the value of **compatibleSdkVersion** is greater than or equal to 10, syntax issues are reported as errors and will block the compilation process. The compilation can be successful only after the ArkTS syntax is fully adapted.

  - In compatible mode, where the value of **compatibleSdkVersion** is smaller than 10, syntax issues are reported as warnings and will not block the compilation process.

## Interaction with TS/JS

ArkTS supports efficient interoperability with TS/JS. In the current version, ArkTS is compatible with dynamic object semantics. In the scenario of interaction with TS/JS, when data and objects of TS/JS are used as those of ArkTS, the static type check of ArkTS may be bypassed, causing unexpected behavior or extra overhead.

```typescript
// lib.ts
export class C {
  v: string; // Compile-time error in TS strict mode: Property 'v' has no initializer
}

export let c = new C()

// app.ets
import { C, c } from './lib';

function foo(c: C) {
  c.v.length;
}

foo(c);
```

## ArkCompiler Runtime Compatibility with TS/JS

The OpenHarmony SDK of API version 11 uses TypeScript 4.9.5, with the **target** field of **es2017**. In the application, you can use the syntax of ECMA2017+ for TS/JS development.

**Application Environment Restrictions**

1. Force the use of strict mode (use strict).

2. Prohibit the use of **eval()**.

3. Prohibit the use of **with() {}**.

4. Prohibit creating functions with strings as code.

5. Prohibit circular dependency.

    Example of circular dependency:

    <!-- @[import_v](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/ArkTSMigration/MigrationBackground/entry/src/main/ets/pages/bar.ets) -->  

    ``` TypeScript
    // bar.ets
    import {v} from './foo'; // bar.ets depends on foo.ets.
    export let u = 0;
    console.info(`v: ${v}`);
    ```

    <!-- @[import_u](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTS/ArkTSMigration/MigrationBackground/entry/src/main/ets/pages/foo.ets) -->  

    ``` TypeScript
    // foo.ets
    import {u} from './bar'; // foo.ets depends on bar.ets reversely.
    export let v = 0;
    console.info(`u: ${u}`);
    
    // Application loading fails.
    ```

**Differences from Standard TS/JS**

In standard TS/JS, the number format of JSON requires that the decimal point must be followed by a number. For example, scientific notation such as **2.e3** is not allowed and will throw **SyntaxError**. In the ArkCompiler Runtime, this type of scientific notation is allowed.