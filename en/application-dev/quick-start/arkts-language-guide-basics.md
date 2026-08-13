# Basics

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T08:54:47.433Z pushedAt=2026-08-13T12:21:20.421Z -->

ArkTS is an extension language based on TypeScript, designed specifically for OpenHarmony development. This chapter introduces the basics of ArkTS, including core concepts such as constants and variables, the type system, comments, and semicolons.

## Constants and Variables

ArkTS uses `const` to declare constants that cannot be reassigned and `let` to declare variables that can be reassigned. Selection guideline: use `const` by default and switch to `let` only when reassignment is required. This follows the principle of least privilege: data that is not intended to be modified should not be accidentally written to. `const` guarantees that the variable binding remains unchanged, but for object types, `const` only locks the reference; the internal properties of the object can still be modified (for example, `const arr = []; arr.push(1)` is valid). ArkTS does not use `var`, because its function scope and variable hoisting do not meet the requirements of statically predictable coding.

### Declaration

ArkTS uses `let` and `const` to declare variables and constants. In TypeScript, `var` has function scope and variable hoisting, which do not meet ArkTS's requirements for static and predictable scopes. Therefore, `var` is not used in ArkTS code.

<!-- @[variable_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let count: number = 10;
let name: string = 'ArkTS';
let isActive: boolean = true;

// Reassignable
let message: string = 'Hello';
message = 'Hello, ArkTS';
```

Unlike `let`, a binding declared with `const` cannot be reassigned. However, for reference types, the internal properties of the object can still be modified.

<!-- @[ts_const_reassignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
const MAX_SIZE: number = 100;
const APP_NAME: string = 'MyApp';

// Constants must be initialized.
const value: number = 10;  // Correct.

// Reference type: the reference remains unchanged, but the content can be modified.
const numbers: number[] = [1, 2, 3];
numbers.push(4);           // Valid.
numbers = [5, 6];          // Compilation error.
```

### Naming

An identifier consists of letters, digits, underscores, and `$`. It cannot start with a digit and cannot use [reserved keywords](#reserved-keywords). It is recommended to use lowerCamelCase for variables and functions, UpperCamelCase for classes and interfaces, and UPPER_SNAKE_CASE for constants.

<!-- @[ts_illegal_naming](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// Valid naming
let validName: number = 1;
let _private: number = 2;
let $special: number = 3;
let camelCase: number = 4;

// Invalid naming
let 123start: number = 1;    // Starts with a digit
let my-var: number = 2;      // Contains a hyphen
let class: number = 3;       // reserved keyword
```

Building on valid naming, following consistent naming conventions can significantly improve code readability. The following examples show the recommended naming styles for various scenarios.

<!-- @[naming_conventions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let userName: string = 'Alice';
let itemCount: number = 10;

const MAX_RETRY_COUNT: number = 3;
const API_BASE_URL: string = 'EXAMPLE_API_URL';

class UserProfile { }
interface IRepository { }
```

### Reserved Keywords

The following keywords have special semantics in ArkTS and cannot be used as identifier names.

| Category | Keywords |
| --- | --- |
| Control flow | `break` `case` `catch` `continue` `default` `do` `else` `finally` `for` `if` `return` `switch` `throw` `try` `while` |
| Declarations | `class` `const` `enum` `export` `extends` `function` `import` `interface` `let` `var` |
| Operators and operations | `delete` `in` `instanceof` `new` `super` `this` `typeof` `void` |
| Values | `false` `null` `true` |
| Others | `abstract` `as` `async` `await` `debugger` `implements` `package` `readonly` `static` `with` `yield` |

### Printing

`console` provides multiple output methods: `console.info` outputs general information, `console.warn` outputs warnings, and `console.error` outputs errors. During development and debugging, you can use template literals to concatenate variable values, or use `JSON.stringify` to output objects.

<!-- @[variable_output](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let outputName: string = 'ArkTS';
const version: number = 1.0;

console.info(`${outputName}`);              // ArkTS
console.info(`${version}`);      // 1
console.info(`Name: ${outputName}`);   // Name: ArkTS
console.info(`Version: ${version}, Name: ${outputName}`);  // Version: 1, Name: ArkTS
console.warn(`Version: ${version}, Name: ${outputName}`);  // Version: 1, Name: ArkTS
console.error('Invalid input');        // Invalid input
```

During debugging, select the corresponding method based on the information level, and use template strings or `JSON.stringify` to format complex object output.

## Comments

ArkTS supports single-line comments (//) and multi-line comments (/* */) to explain the intent of the code.

### Single-Line Comments

A single-line comment starts with `//` and is used for brief explanations or temporarily disabling code.

<!-- @[single_line_comment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let commentCount: number = 10;  // Single-line comment
```

### Multi-line Comments

Multi-line comments are enclosed in `/* */` and are used for detailed explanations or commenting out large blocks of code.

<!-- @[multi_line_comment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
/*
 * Multi-line comment
 * Can span multiple lines*/
function calculate(): number {
  return 100;
}
```

### Documentation Comments

Documentation comments are enclosed in `/** */` and are used to generate API documentation and type hints.

<!-- @[documentation_comment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
/**
 * Calculate the sum of two numbers.
 * @param a The first number.
 * @param b The second number.
 * @returns The sum of the two numbers.
 */
function add(a: number, b: number): number {
  return a + b;
}
```

## Semicolons

It is recommended to end each statement with a semicolon to improve code consistency and readability. When multiple statements are written on the same line, semicolons are required.

<!-- @[semicolon_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let x: number = 10;
let y: number = 20;

// Semicolons are required for multiple statements on the same line.
let a: number = 1; let b: number = 2;

// The semicolon at the end of a statement block is optional.
function greet(): void {
  console.info('Hello');
}
```

## Type Declaration

Type declarations use type annotations to constrain the types of variables, parameters, and return values at compile time, enabling the compiler to detect type mismatch errors (such as assigning a `string` to a `number` variable) before runtime rather than exposing them only when the program runs. In ArkTS, there are three forms of type declaration: type annotation (`: type`), type alias (`type Name = ...`), and interface declaration (`interface`), each suited to different scenarios.

### Basic Type Declaration

Annotate the types of variables, parameters, and return values through [type annotation](#type-annotation) (: type).

<!-- @[type_annotation_examples](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// Variable type
let annotExAge: number = 0;

// Function parameter and return value types
function annotExGreet(name: string): string {
  return `Hello, ${name}`;
}

// Class property type
class User {
  public id: number = 0;
  public name: string = '';
}
```

### Type Alias

A type alias gives a new name to an existing type, simplifying the writing of complex types. An alias is fully equivalent to the original type — using the alias is the same as using the original type, and no new type is created. It is commonly used to simplify union types (for example, `type ID = number | string`) and complex generics (for example, `type Mapper<T, R> = (input: T) => R`).

<!-- @[type_alias](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
type ID = number | string;
type Age = number;

let userId: ID = 123;
userId = 'ABC';
```

### API Declaration

An interface defines the structural contract of an object, describing property names, types, and optionality. For details, see [Interfaces](arkts-language-guide-interfaces.md).

<!-- @[interface_definition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface IfaceDefUser {
  id: number;
  name: string;
  email?: string;
}

let user: IfaceDefUser = { id: 1, name: 'Alice' };
```

## Type

ArkTS provides types such as `number`, `boolean`, `string`, `array`, and `enum` to constrain the range of values and operations.

### number Type

The `number` type represents IEEE 754 double-precision floating-point numbers (64-bit) and has no separate integer type. Decimal, hexadecimal, binary, and octal literals are supported.

<!-- @[number_literals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let decimal: number = 42;      // Decimal
let hex: number = 0xFF;        // Hexadecimal (255)
let binary: number = 0b1010;   // Binary (10)
let octal: number = 0o755;     // octal (493)
```

### boolean Type

The boolean type represents the logical values true or false, which are produced by direct assignment, comparison operations (`===`, `!==`, `>`, `<`), and logical operations (`&&`, `||`, `!`). The boolean type cannot be implicitly converted to or from other types, which avoids the type confusion issues found in JavaScript.

<!-- @[boolean_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let boolTypeIsActive: boolean = true;
let isComplete: boolean = false;

// Comparison produces a boolean value.
let boolTypeX: number = 10;
let boolTypeY: number = 5;
let greater: boolean = boolTypeX > boolTypeY;  // true
```

Note that when performing conditional checks, do not mix boolean values with other types. ArkTS rejects implicit conversions at compile time.

### array Type

The `array` type represents an ordered collection of elements, where all elements are of the same type and can be accessed by index. The `number[]` syntax is recommended, but the `Array<number>` generic syntax can also be used. For details, see [Collection Types](arkts-language-guide-collection-types.md).

<!-- @[array_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// Declare an array.
let arrTypeNumbers: number[] = [1, 2, 3];
let arrTypeNames: string[] = ['A', 'B', 'C'];

// Operate on the array.
arrTypeNumbers.push(4);
arrTypeNumbers.pop();
let first: number = arrTypeNumbers[0];
```

The two syntaxes are equivalent. It is recommended that a team consistently use `number[]` to keep the style uniform.

### object Type

The object type represents a reference type, including class instances and interface objects, accessed by reference.

<!-- @[object_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
class Point {
  public x: number = 0;
  public y: number = 0;
}

let point: Point = new Point();
point.x = 10;
point.y = 20;

// Use an interface to define the object structure.
interface ObjTypeUser {
  id: number;
  name: string;
}

let objTypeUser: ObjTypeUser = { id: 1, name: 'Alice' };
```

ArkTS requires the object layout to be determined at compile time, and does not dynamically add or remove properties at runtime. For details, see [Collection Types](arkts-language-guide-collection-types.md).

### enum Type

The enum type defines an enumeration of named constant values, making it easier to express fixed states semantically. For details, see [Enums](arkts-language-guide-enums.md).

<!-- @[enum_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
enum Direction {
  Up,
  Down,
  Left,
  Right
}

let dir: Direction = Direction.Up;

// Enum with values
enum Status {
  Pending = 'pending',
  Active = 'active',
  Completed = 'completed'
}

let status: Status = Status.Active;
```

Enum values increment from 0 by default. You can also explicitly specify string or numeric values to improve readability and stability.

### union Type

A union type represents a value that can be one of several types, separated by a vertical bar (`|`). Union types are suitable for: function parameters that accept multiple types (for example, `id: number | string`), variables that hold values of different types in different branches, and extended sets of enum values. When using a value of a union type, you can only access properties common to all members; to access properties of a specific type, you must narrow the type using `typeof`, `instanceof`, or a discriminant field.

<!-- @[union_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let unionTypeId: number | string = 123;
unionTypeId = 'ABC-123';

let result: number | null = null;
result = 100;

// Union of multiple types
let data: number | string | boolean = 1;
data = 'text';
data = true;
```

### Literal Type

A literal type uses a value itself as the type, restricting a variable to only specific literal values.

<!-- @[literal_union_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
type TaskState = 'pending' | 'running' | 'done';

let state: TaskState = 'pending';
state = 'running';
```

For a stable set of states, prefer `enum` to avoid scattering a large number of string literals throughout business code.

### void Type

The `void` type indicates that a function returns no value. It is commonly used for functions that only perform operations without returning a result. Note that `void` differs from `undefined`, which represents an undefined value.

<!-- @[void_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function logMessage(message: string): void {
  console.info(`${message}`);
}

function doNothing(): void {
  // No return value.
}
```

### never Type

The `never` type represents functions that never return—those that throw an exception or run an infinite loop.

<!-- @[never_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function fail(message: string): never {
  throw new Error(message);
}

function assertNever(value: never): never {
  throw new Error(`Unexpected value: ${value}`);
}
```

The `never` type is commonly used in two scenarios: exception functions that always throw an exception and never return, and exhaustiveness checking—returning `never` from the `default` branch to ensure that a `switch` covers all enum values.

### Restrictions on any and unknown

ArkTS does not support the `any` and `unknown` types. Use an explicit type, a union type, or a generic instead.

**TypeScript Comparison**

<!-- @[ts_avoid_any_unknown](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// Not used in ArkTS:
let value: any;
let raw: unknown;

type InputValue = string | number | boolean;
let inputValue: InputValue = 'ok';
```

When defining a variable type, choose an explicit type, a union type, an interface, or a class based on the specific scenario to achieve type safety.

### Advanced Type Boundaries

ArkTS places greater emphasis on statically decidable type relationships. The following TypeScript advanced types are not supported in ArkTS. Prefer alternatives such as `interface extends`, class inheritance, and generic constraints:

| TypeScript Advanced Type | Syntax Example | ArkTS Alternative |
| --- | --- | --- |
| Intersection type | `A & B` | Use `interface extends` multiple inheritance or class composition |
| Conditional type | `T extends U ? X : Y` | Use an explicit interface or function overloading |
| Mapped type | `{ [K in keyof T]: ... }` | Use an explicit interface or class |
| Indexed access type | `T[K]` | Use an explicit return type and field access methods |

### bigint Type

The bigint type represents integers of arbitrary precision. Its literals are marked with the `n` suffix, making it suitable for operations on very large integers.

<!-- @[bigint_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let bigValue: bigint = 999999999999999999999999999999999999n;
console.info(`${bigValue.toString()}`);

let nextValue: bigint = bigValue + 1n;
console.info(`${nextValue.toString()}`);
```

Appending `n` to a numeric literal indicates the bigint type. `bigValue` represents a very large integer without precision loss, and `nextValue` performs addition with an exact result. bigint cannot be directly mixed with `number` in operations; explicit conversion is required.

<!-- @[bigint_conversion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let bigintCount: number = 10;
let preciseCount: bigint = BigInt(bigintCount);
let total: bigint = preciseCount + 20n;
```

Note that certain APIs (such as Date-related methods) or annotation fields may not support `bigint`. Before using it, check the type constraints in the corresponding API documentation. For large integers, prefer bigint to avoid the precision loss of `number`. Mixed operations require explicit conversion. bigint supports only integer operations, not decimals. Some APIs in older versions may not support bigint.

### symbol Type

symbol represents a globally unique primitive value. It is created through `Symbol()`, and each call returns a different unique value. It is suitable for use as an object property key to avoid naming conflicts. **ArkTS does not support the `Symbol()` API**.

<!-- @[ts_symbol_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript supports the symbol type, while ArkTS does not support the Symbol() API
let sym1: symbol = Symbol('name');
let sym2: symbol = Symbol('name');
console.info(`${sym1 === sym2}`); // false, each symbol is unique

let uniqueKey: symbol = Symbol('id');
let myMap: Map<symbol, string> = new Map();
myMap.set(uniqueKey, '123');
console.info(`${myMap.get(uniqueKey)}`); // 123
```

## Type Annotation

Type annotation specifies types for variables, parameters, and return values, allowing the compiler to check type correctness at compile time.

<!-- @[type_annotation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// Basic type annotation
let age: number = 25;
let annotName: string = 'Alice';
let isValid: boolean = true;

// Reference type annotation
let annotNumbers: number[] = [1, 2, 3];
let names: string[] = ['A', 'B', 'C'];

// Union type
let id: number | string = 123;
id = 'ABC-123';
```

Public APIs and complex types (unions, generics) should be explicitly annotated, while simple local variables can rely on type inference.

## Type Inference

Type inference is the process by which the compiler automatically derives the type of a variable or expression from the context, without requiring you to explicitly annotate it. ArkTS supports type inference in most scenarios, and using it appropriately can reduce redundant annotations.

### Variable Type Inference

When a variable is assigned a value, the compiler infers the type of the variable from the value on the right side.

<!-- @[type_inference_variables](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let tiCount = 10;        // Inferred as number
let tiMessage = 'hello'; // Inferred as string
let tiItems = [1, 2, 3]; // Inferred as number[]
```

Variables declared with `const` are inferred as literal types, while variables declared with `let` are inferred as widened types.

<!-- @[type_inference_const_let](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
const tiPi = 3.14;   // Inferred as 3.14 (literal type).
let tiRatio = 3.14;  // Inferred as number (widened type).
```

### Best Common Type

When multiple candidate types exist, the compiler selects the most general type among them. When an array contains elements of multiple types, the type is inferred as a union of the element types.

<!-- @[type_inference_best_common](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let tiMixed: (number | null)[] = [0, 1, null]; // Must be explicitly annotated as a union type array.
let tiNames: string[] = ['Alice', 'Bob'];      // Inferred as string[].
```

If no unified common type can be found, you must annotate the type explicitly.

### Contextual Type

A contextual type refers to the type that the compiler infers based on the position of a variable (such as a function parameter or a callback). When the parameter type of a function is known, the parameters of the callback function passed in are inferred automatically.

<!-- @[type_inference_contextual](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let tiCtxNames: string[] = ['Alice', 'Bob', 'Charlie'];
tiCtxNames.forEach((s) => {
  console.info(s.toUpperCase()); // s is automatically inferred as string.
});
```

The parameter `s` of the callback function does not need a type annotation; the compiler infers it as `string` based on the signature of `forEach`. Contextual types and best common types complement each other and together cover most inference scenarios.

### Control Flow Inference

The compiler tracks type changes along control flow branches such as `if`/`else`, `switch`, and loops, narrowing a variable to a more specific type within different branches and taking the union type after the branches merge.

<!-- @[type_inference_control_flow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let tiValue: string | number = 'hello';
if (typeof tiValue === 'string') {
  console.info(tiValue.toUpperCase()); // Here value is narrowed to string
} else {
  console.info(`${tiValue}`);          // Here value is narrowed to number
}
```

### Literal Type Inference

Object properties are inferred as broad types rather than literal types by default. In TypeScript, you can use `as const` to infer object properties as literal types. ArkTS does not use `as const`; when literal type constraints are required, use `enum` or explicit type annotations.

## Optional/Nullable Types

An optional type allows null or undefined, indicating a value that may be missing.

### null/undefined

`null` represents an intentionally assigned empty value, while `undefined` indicates that a variable has not been assigned or a property does not exist. The two have different semantics and must be explicitly distinguished in ArkTS.

<!-- @[null_undefined_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// null: an intentional empty value
let empty: null = null;
let nullUndefData: string | null = null;

// undefined: an undefined value
let missing: undefined = undefined;
let optional: string | undefined = undefined;

// Difference between null and undefined
let nickname: string | null = null;     // Explicitly indicates that there is no nickname.
let title: string | undefined;          // May not be provided.
```

### Optional Value Binding

An optional property (?) indicates that the property may not exist. Before accessing it, handle it through an explicit check (`if (value !== undefined)`), a type guard (`if (value !== null)`), or optional chaining (`value?.property`).

<!-- @[optional_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface OptPropUser {
  id: number;
  name: string;
  email?: string;  // Optional property
}

let optPropUser: OptPropUser = { id: 1, name: 'Alice' };

// Check whether the optional value exists
if (optPropUser.email !== undefined) {
  console.info(`${optPropUser.email}`);
}
```

When accessing optional properties nested at multiple levels, optional chaining avoids null checks at each level, making the code more concise.

### Providing Default Values

Use the nullish coalescing operator (`??`) or function default parameters to provide fallback values when a value is `null`/`undefined`. Note that `??` applies only to `null`/`undefined`, while `||` applies to all falsy values (`0`, `false`, `''`). Choose the appropriate one based on the scenario.

<!-- @[null_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// Nullish coalescing operator
let nullHandleValue: string | null = null;
let display: string = nullHandleValue ?? 'default';

// Function default parameters
function nullHandleGreet(name: string, title: string = 'User'): string {
  return `Hello, ${title} ${name}`;
}

nullHandleGreet('Alice');           // Hello, User Alice
nullHandleGreet('Alice', 'Dr.');    // Hello, Dr. Alice
```

When the default value needs to preserve legitimate values such as `0`, `false`, and `''`, you must use `??` instead of `||`.

## Non-null Assertion

The non-null assertion uses the `!` operator to tell the compiler "treat this as non-null here." The non-null assertion bypasses the compiler's null check but does not generate any verification code at runtime. Prefer type guards, optional chaining, or nullish coalescing, and use the non-null assertion only when you are certain that the value is non-null.

<!-- @[non_null_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let nonNullValue: string | null = 'text';

// Non-null assertion (confirm the value is not null).
let length: number = nonNullValue!.length;

// Type guard check.
if (nonNullValue !== null) {
  let len: number = nonNullValue.length;  // Safe access.
}
```

The non-null assertion is a shortcut for "the developer's promise that the value is non-null". If the promise fails, the program crashes directly at runtime. Therefore, use it only when you are certain that the value is non-null and the condition cannot be expressed with a type guard.

### Implicit Resolution of Nullable Types

A nullable type (`T | null`/`T | undefined`) indicates that a value may not exist. The difference from an optional property `?` is that `?` is a modifier used at property declaration (`name?: string`), whereas a nullable type is an explicit union type annotation (`name: string | null`). Before accessing a value of a nullable type, you must handle the possible null value through an `if` check, optional chaining `?.`, or nullish coalescing `??`.

<!-- @[null_safety](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface NullableSub {
  sub?: string;
}

interface NullableObj {
  prop?: NullableSub;
}

let optionalValue: string | null = 'hello';

// Explicitly handle null values.
if (optionalValue !== null) {
  console.info(`${optionalValue.length}`);
}

// Use optional chaining.
let obj: NullableObj = {};
let sub: string | undefined = obj?.prop?.sub;
```

## Type Safety and Immutability

Type safety catches type errors at compile time, and immutability prevents values from being reassigned through `const`.

### Type Safety

The compiler rejects assignments with mismatched types, such as assigning a string to a number variable.

<!-- @[ts_type_mismatch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
let typeCheckAge: number = 25;
typeCheckAge = 'text';  // Compilation error: type mismatch

function typeCheckAdd(a: number, b: number): number {
  return a + b;
}

typeCheckAdd(1, 2);      // Correct
typeCheckAdd(1, '2');    // Compilation error
```

Type safety detects errors at compile time to avoid runtime crashes, improves code readability and refactoring safety, and supports intelligent hints in DevEco Studio.

### Immutability

Variables declared with `const` cannot be reassigned, ensuring that their values remain unchanged throughout their lifetime.

<!-- @[ts_immutability_violation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// Declare an immutable constant with const.
const MAX_VALUE: number = 100;
MAX_VALUE = 200;  // Compilation error.

// readonly read-only property.
interface Config {
  readonly apiKey: string;
}

let config: Config = { apiKey: 'key' };
config.apiKey = 'new';  // Compilation error

// Read-only array
let readonlyNumbers: ReadonlyArray<number> = [1, 2, 3];
readonlyNumbers[0] = 10;  // Compilation error
```

## Error Handling

Use `try-catch` to catch runtime exceptions and prevent the program from terminating unexpectedly.

### try-catch Exception Handling

The try block wraps code that may throw exceptions, and the catch block catches and handles the exceptions to prevent the program from terminating unexpectedly.

<!-- @[try_catch_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function riskyOperation(): number {
  throw new Error('operation failed');
}

function parseJSON(data: string): Object {
  return JSON.parse(data);
}

let tcData: string = '{"name": "Alice"}';

try {
  let result: number = riskyOperation();
} catch (error) {
  console.info(`Error: ${error}`);
}

// Catch a specific error.
try {
  parseJSON(tcData);
} catch (error) {
  if (error instanceof SyntaxError) {
    console.info(`JSON parsing error`);
  }
}
```

### Throwing Errors with throw

The `throw` statement throws an `Error` object, interrupts the current function, and propagates the exception outward.

<!-- @[throwing_exceptions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function validateAge(age: number): void {
  if (age < 0) {
    throw new Error('Age cannot be negative');
  }
  if (age > 150) {
    throw new Error('Age is out of a reasonable range');
  }
}
```

When throwing an exception, always use an `Error` object with a clear and specific error message. Throw exceptions only in genuinely exceptional situations, and avoid using exceptions to control normal flow.

### Error Handling Conventions

Return a tuple `[result, Error | null]` so that the caller obtains both the result and the error information.

<!-- @[error_tuple_return](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// Return the error information tuple.
function divide(a: number, b: number): [number, Error | null] {
  if (b === 0) {
    return [0, new Error('The divisor cannot be zero.')];
  }
  return [a / b, null];
}

let divideResult: [number, Error | null] = divide(10, 0);
let errTupleResult: number = divideResult[0];
let error: Error | null = divideResult[1];

if (error !== null) {
  console.info(`${error.message}`);
}
```

## Assertions and Preconditions

Assertions verify internal assumptions during development, while preconditions validate external input parameters at function entry.

### Debugging with Assertions

An assertion function throws an error when a condition is false, and is used to detect logic errors during development.

<!-- @[assertion_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function assert(condition: boolean, message: string = 'Assertion failed'): void {
  if (!condition) {
    throw new Error(message);
  }
}

function assertEqual<T>(actual: T, expected: T, message?: string): void {
  if (actual !== expected) {
    throw new Error(message ?? `Expected ${expected}, got ${actual}`);
  }
}

// Use assertions.
let assertFuncValue: number = 10;
assert(assertFuncValue > 0, 'Value must be positive');
assertEqual(assertFuncValue, 10);
```

### Enforcing Preconditions

A precondition function validates parameters at the function entry and throws an error immediately when the condition is not met.

<!-- @[precondition_checks](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function precondition(condition: boolean, message: string): void {
  if (!condition) {
    throw new Error(`Precondition failed: ${message}`);
  }
}

function calculateSquareRoot(value: number): number {
  precondition(value >= 0, 'The parameter must be non-negative.');
  return Math.sqrt(value);
}

function getElement(arr: number[], index: number): number {
  precondition(index >= 0, 'The index must not be negative.');
  precondition(index < arr.length, 'The index is out of range.');
  return arr[index];
}
```

## Scope Rules

Scope determines the visibility and lifecycle of variables. ArkTS supports block scope and function scope.

### var Declaration (Function Scope)

Variables declared with `var` have function scope and are subject to hoisting, which means they can be accessed before declaration (with the value `undefined`) and can be declared repeatedly. **ArkTS does not support `var` declarations**; use `let` or `const` instead.

<!-- @[ts_var_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript supports var declarations, but ArkTS does not.
function tsVarScope(): void {
  var x: number = 10;
  if (true) {
    var x: number = 20; // Repeated declaration in the same scope.
  }
  console.info(`${x}`); // 20
}

tsVarScope();
```

### let/const Declarations (Block Scope)

Variables declared with `let` and `const` have block scope and are protected by the temporal dead zone (TDZ). They cannot be accessed before declaration, and redeclaration within the same scope is not allowed.

<!-- @[let_const_block_scope](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function blockScope(): void {
  let bsA: number = 10;
  const bsB: number = 20;
  if (true) {
    let bsA: number = 30; // An independent variable in the inner scope that does not affect the outer scope.
    console.info(`${bsA}`); // 30
    console.info(`${bsB}`); // 20, accessible from the outer scope.
  }
  console.info(`${bsA}`); // 10
}
```

### Nested Scope

An inner scope can access variables in an outer scope, but not vice versa. `let`/`const` can shadow a variable of the same name in an outer scope within a nested block, whereas `var` cannot (it shares the same function scope).

<!-- @[nested_scope](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let nsOuter: string = 'outer';

function nestedScope(): void {
  let nsInner: number = 100;
  console.info(`${nsOuter}`); // Accessible from the outer scope

  if (true) {
    let nsInner: number = 200; // Shadows the outer nsInner
    console.info(`${nsInner}`); // 200
  }
  console.info(`${nsInner}`); // 100
}
```

ArkTS recommends using `let` and `const` and avoiding `var`. Use `const` for references that are not reassigned, and `let` for variables that need to be modified.

## Destructuring Assignment

Destructuring assignment allows you to extract values from an array or an object by position or name and assign them to variables. TypeScript supports array destructuring and object destructuring, but ArkTS does not support the destructuring assignment syntax.

### Array Destructuring

In TypeScript, you can use `let [a, b] = [1, 2]` to extract elements from an array. ArkTS does not support destructuring variable declarations (`arkts-no-destruct-decls`). For details, see [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md#destructuring-assignment-is-not-supported). Use element-by-element assignment instead.

**TypeScript Comparison**

<!-- @[ts_array_destructuring](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript array destructuring, which ArkTS does not support
let pair: number[] = [1, 2];
let [first, second] = pair;
console.info(`${first}, ${second}`); // 1, 2
```

ArkTS alternative approach: access array elements by index.

<!-- @[array_access_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let arrPair: number[] = [1, 2];
let arrFirst: number = arrPair[0];
let arrSecond: number = arrPair[1];
```

### Object Destructuring

In TypeScript, you can use `let { name, age } = obj` to extract properties from an object. ArkTS does not support destructuring variable declarations (`arkts-no-destruct-decls`). For details, see [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md#destructuring-assignment-is-not-supported). Use individual assignments instead.

**TypeScript Comparison**

<!-- @[ts_object_destructuring](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript object destructuring syntax, which ArkTS does not support
interface TsUserInfo {
  name: string;
  age: number;
}

let tsUser: TsUserInfo = { name: 'Alice', age: 25 };
let { name: userName, age: userAge } = tsUser;
console.info(`${userName}, ${userAge}`); // Alice, 25
```

ArkTS alternative approach: access properties one by one.

<!-- @[object_access_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface DestrUserInfo {
  name: string;
  age: number;
}

let destrUser: DestrUserInfo = { name: 'Alice', age: 25 };
let destrUserName: string = destrUser.name;
let destrUserAge: number = destrUser.age;
```

### Function Parameter Destructuring

In TypeScript, function parameters can directly destructure objects. ArkTS does not support parameter destructuring (`arkts-no-destruct-params`). For details, see [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md#destructuring-assignment-is-not-supported). Use an interface type parameter instead.

**TypeScript Comparison**

<!-- @[ts_param_destructuring](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript syntax; ArkTS does not support function parameter destructuring
interface GreetParam {
  name: string;
  age: number;
}

function greet({ name, age }: GreetParam): void {
  console.info(`Hello, ${name}, age ${age}`);
}

let greetParam: GreetParam = { name: 'Alice', age: 25 };
greet(greetParam);
```

ArkTS alternative approach: use an interface type parameter instead.

<!-- @[param_destructuring_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface ParamUserInfo {
  name: string;
  age: number;
}

function greetUser(user: ParamUserInfo): void {
  console.info(`Hello, ${user.name}, age ${user.age}`);
}

greetUser({ name: 'Alice', age: 25 });
```

## Spread Syntax (spread)

In ArkTS, the spread syntax `...` supports only arrays and rest parameters, and does not support object spread (`arkts-no-spread`). For details, see [TypeScript to ArkTS Cookbook](typescript-to-arkts-migration-guide.md#spread-operator-is-supported-in-partial-scenarios). To copy object properties, assign them one by one.

**TypeScript Comparison**

<!-- @[ts_object_spread](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript object spread syntax, which ArkTS does not support
interface TsConfig {
  host: string;
  port: number;
}

let original: TsConfig = { host: 'localhost', port: 8080 };
let copy: TsConfig = { ...original, port: 3000 };
console.info(`${copy.host}, ${copy.port}`); // localhost, 3000
```

ArkTS alternative approach: assign object properties one by one.

<!-- @[spread_syntax_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface SpreadConfig {
  host: string;
  port: number;
}

// Array spread, supported by ArkTS
let spreadArr1: number[] = [1, 2, 3];
let spreadArr2: number[] = [...spreadArr1, 4, 5];

// Copy object properties by assigning them one by one
let spreadOriginal: SpreadConfig = { host: 'localhost', port: 8080 };
let spreadCopy: SpreadConfig = {
  host: spreadOriginal.host,
  port: 3000
};
console.info(`${spreadCopy.host}, ${spreadCopy.port}`); // localhost, 3000
```