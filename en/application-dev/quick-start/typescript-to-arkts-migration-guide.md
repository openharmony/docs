# TypeScript to ArkTS Cookbook

Welcome to the "TypeScript to ArkTS cookbook". This document gives you short
recipes to rewrite your standard TypeScript code to ArkTS. Although ArkTS is
designed to be close to TypeScript, some limitations were added for the sake of
performance. As a result, all TypeScript features can be divided into the following
categories:

- **Fully supported features**: The original code requires no modification
   at all. According to our measurements, projects that already follow the
   best TypeScript practices can keep 90% to 97% of their codebase intact.
- **Partially supported features**: Some minor code refactoring is needed.
   Example: The keyword `let` must be used in place of `var` to declare
   variables. Your code will remain a valid TypeScript code
   after rewriting by our recipes.
- **Unsupported features**: A greater code refactoring effort is required.
   Example: The type `any` is unsupported, and you need to introduce explicit
   typing to your code everywhere `any` is used.

The document is built on the feature-by-feature basis, and if you do not
find a specific feature, then you can safely consider it **fully supported**. Otherwise,
a recipe will give you a suggestion on how to rewrite your code and work
around an unsupported case. For example, the custom decorators supported by ArkTS have the same syntax as those supported by TypeScript.

**Recipe Explained**

The original TypeScript code contains the keyword `var`:

```typescript
function addTen(x: number): number {
  var ten = 10
  return x + ten
}
```

The code must be rewritten as follows:

```typescript
// Important! This is still valid TypeScript code.
function addTen(x: number): number {
  let ten = 10
  return x + ten
}
```
**Severity Levels**

Each recipe is marked with the the severity level. Supported values:

- **Severity: error**: The recipe should be followed, otherwise the program
  will fail to compile.
- **Severity: warning**: It is highly recommended to follow the recipe. Although
  violating the recipe does not currently affect the compilation, in future
  versions, it will cause compilation to fail.

**Status of Unsupported Features**

Currently, unsupported features are mainly either of the following:

- Features relate to dynamic typing that degrades runtime performance
- Features that require extra support in the compiler, thereby degrading project build time

However, the ArkTS team reserves the right to reconsider the list and
**shrink** it in the future releases based on the feedback from developers
and real-world data experiments.

## Recipes Summarized

This document provides an informal summary of TypeScript features that ArkTS either
can support with limitations, or cannot support. See [Recipes](#recipes) for the
full list with more detailed code examples and workaround suggestions.

### Static Typing Is Enforced

ArkTS was designed with the following goals in mind:

- ArkTS programs must be easy for developers to read and understand because
  the code is read more often than written.
- ArkTS must execute fast and consume as little power as possible because
  it is particularly critical on mobile devices that ArkTS targets.

One of the most important features of ArkTS that helps achieving both goals
is static typing. If a program is statically typed (all types
are known at compile time), it is much easier to understand what data
structures are used in the code. Since all types are known before the program
actually runs, the compiler can verify code correctness, thereby
eliminating many runtime type checks and improving performance.

Therefore, the usage of the type `any` in ArkTS is prohibited.

**Example**

```typescript
// Not supported:
let res: any = some_api_function('hello', 'world')
// What is `res`? A numeric error code, a string, or an object?
// How should we work with it?
// Supported:
class CallResult {
  public succeeded(): boolean { ... }
  public errorMessage(): string { ... }
}

let res: CallResult = some_api_function('hello', 'world')
if (!res.succeeded()) {
  console.log('Call failed: ' + res.errorMessage())
}
```

According to our measurements, `any` is already not welcome in TypeScript. It is used in approximately 1% of
TypeScript codebases. Moreover, today's code linters (for example, ESLint) include a set
of rules that prohibit the usage of `any`. Prohibiting `any` results in a strong positive impact on performance at the cost of low-effort code refactoring.

### Changing Object Layout in Runtime Is Prohibited

To achieve maximum performance benefits, ArkTS requires the layout of objects
to remain unchanged during program execution. In other words, it is prohibited to:

- Add new properties or methods to objects.
- Delete existing properties or methods from objects.
- Assign values of arbitrary types to object properties.

It is noteworthy that many such operations are already prohibited by the TypeScript
compiler. However, it can still be "tricked", for example, by `as any` casting that
ArkTS does not support (see the detailed example below).

**Example**

```typescript
class Point {
  public x: number = 0
  public y: number = 0

  constructor(x: number, y: number) {
    this.x = x
    this.y = y
  }
}

// It is impossible to delete a property from the object. It is guaranteed that all Point objects have the property x.
let p1 = new Point(1.0, 1.0)
delete p1.x           // Compile-time error in TypeScript and ArkTS
delete (p1 as any).x  // OK in TypeScript; compile-time error in ArkTS

// Class Point does not define any property named `z`, and it is impossible to add it while the program runs.
let p2 = new Point(2.0, 2.0)
p2.z = 'Label';           // Compile-time error in TypeScript and ArkTS
(p2 as any).z = 'Label'   // OK in TypeScript; compile-time error in ArkTS

// It is guaranteed that all Point objects have only properties x and y, it is impossible to generate some arbitrary identifier and use it as a new property:
let p3 = new Point(3.0, 3.0)
let prop = Symbol();     // OK in TypeScript; compile-time error in ArkTS
(p3 as any)[prop] = p3.x // OK in TypeScript; compile-time error in ArkTS
p3[prop] = p3.x          // Compile-time error in TypeScript and ArkTS

// It is guaranteed that all Point objects have properties x and y of type number, so assigning a value of any other type is impossible:
let p4 = new Point(4.0, 4.0)
p4.x = 'Hello!';         // Compile-time error in TypeScript and ArkTS
(p4 as any).x = 'Hello!' // OK in TypeScript; compile-time error in ArkTS

// Usage of Point objects which is compliant with the class definition:
function distance(p1: Point, p2: Point): number {
  return Math.sqrt(
    (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y)
  )
}
let p5 = new Point(5.0, 5.0)
let p6 = new Point(6.0, 6.0)
console.log('Distance between p5 and p6: ' + distance(p5, p6))
```

Unpredictable changing of object layout contradicts both good readability and
good performance of code. Indeed, having class definition at one place and
modifying actual object layout elsewhere is confusing and error-prone from the
developer's point of view. It opposes the idea of static typing
and requires extra runtime support that causes undesired execution overhead.

According to our observations and experiments, this feature is already not
welcome in TypeScript. It is used in a marginal number of real-world projects,
and state-of-the-art linters have rules to prohibit its usage.

Prohibiting runtime changes to object layouts results in a
strong positive impact on performance at the cost of low-effort refactoring.

### Semantics of Operators Is Restricted

To achieve better performance and encourage developers to write clearer code,
ArkTS restricts the semantics of some operators. An example is
given below, and the full list of restrictions is outlined in [Recipes](#recipes).

**Example**

```typescript
// Unary `+` is defined only for numbers, but not for strings:
let t = +42; // OK
let s = +'42'; // Compile-time error
```

Loading language operators with extra semantics complicates the language
specification, and forces developers to remember all possible corner cases with
appropriate handling rules. Besides, in certain cases it causes some undesired
runtime overhead.

According to our observations and experiments, this feature is not popular in TypeScript. It is used in less than 1% of real-world codebases, and such cases are easy to refactor. Restricting the operator semantics results in a clearer and more performant at the cost of low-effort changes in code.

### Structural Typing Is Not Supported (Yet)

Assuming that two unrelated classes `T` and `U` have the same public API:

```typescript
class T {
  public name: string = ''

  public greet(): void {
    console.log('Hello, ' + this.name)
  }
}

class U {
  public name: string = ''

  public greet(): void {
    console.log('Greetings, ' + this.name)
  }
}
```

Can we assign a value of `T` to a variable of `U`?

```typescript
let u: U = new T() // Is this allowed?
```

Can we pass a value of `T` to a function that accepts a parameter of `U`?

```typescript
function greeter(u: U) {
  console.log('To ' + u.name)
  u.greet()
}

let t: T = new T()
greeter(t) // Is this allowed?
```

In other words, which approach will we take:

- `T` and `U` are not related by inheritance or any common interface, but
  they are "somewhat equivalent" since they have the same public API, and so
  the answer to both questions above is "yes".
- `T` and `U` are not related by inheritance or any common interface, and
  always must be considered as totally different types, and so the answer to
  both questions above is "no".

The languages that take the first approach are said to support structural
typing, whereas the languages that take the second approach do not support it.
Currently, TypeScript supports structural typing, and ArkTS does not.

It is debatable whether structural typing helps to produce code that
is clearer and more understandable, and both *pro* and *contra* arguments can
be found. Why not just support it then?

The answer is that supporting structural typing is a major feature that needs
a lot of considerations and careful implementation in language specification,
compiler, and runtime. More importantly, in case if ArkTS, which enforces static
typing (see above), runtime support for structural typing implies performance
overhead. So since functionally correct and performant implementation requires
taking that many aspects into account, the support to this feature is postponed.

The ArkTS team is ready to reconsider based on real-world scenarios and feedback.
More cases and suggested workarounds can be found in [Recipes](#recipes).

## Recipes

### Recipe: Objects with Property Names That Are Not Identifiers Are Not Supported

**Rule:** `arkts-identifiers-as-prop-names`

**Severity: error**

ArkTS does not support objects with name properties that are numbers or
strings. Exceptions are string type enumeration constants and string literal. Use classes to access data by property names. Use arrays to access
data by numeric indices.

**TypeScript**

```typescript
var x = { 'name': 'x', 2: '3' }

console.log(x['name'])
console.log(x[2])
```

**ArkTS**

```typescript
class X {
  public name: string = ''
}
let x: X = { name: 'x' }
console.log(x.name)

let y = ['a', 'b', 'c']
console.log(y[2])

// If you still need a container to store keys of different types, use Map<Object, some_type>.
let z = new Map<Object, string>()
z.set('name', '1')
z.set(2, '2')
console.log(z.get('name'))
console.log(z.get(2))

enum Test {
  A = 'aaa',
  B = 'bbb'
}

let obj: Record<string, number> = {
  [Test.A]: 1,   // string type enumeration constants
  [Test.B]: 2,   // string type enumeration constants
  ['value']: 3   // string literal
}
```

### Recipe: `Symbol()` Is Not Supported

**Rule:** `arkts-no-symbol`

**Severity: error**

TypeScript uses the `Symbol()` API among other things to generate
unique property names at runtime. ArkTS does not support the `Symbol()` API
because its most popular use cases make no sense in the statically typed
environment. In particular, the object layout is defined at compile time
and cannot be changed at runtime.

Only `Symbol.iterator` is supported.

### Recipe: Private `#` Identifiers Are Not Supported

**Rule:** `arkts-no-private-identifiers`

**Severity: error**

ArkTS does not use private identifiers starting with the symbol `#`. Use the keyword  `private` instead.

**TypeScript**

```typescript
class C {
  #foo: number = 42
}
```

**ArkTS**

```typescript
class C {
  private foo: number = 42
}
```

### Recipe: Use Unique Names for Types and Namespaces

**Rule:** `arkts-unique-names`

**Severity: error**

Names for all types (classes, interfaces, and enums) and namespaces must be unique and distinct from other names such as, variable names, and function names.

**TypeScript**

```typescript
let X: string
type X = number[] // Type alias with the same name as the variable
```

**ArkTS**

```typescript
let X: string
type T = number[] // X is not allowed here to avoid name collisions.
```

### Recipe: Use `let` Instead of `var`

**Rule:** `arkts-no-var`

**Severity: error**

ArkTS does not support `var`. Use `let` instead.

**TypeScript**

```typescript
function f(shouldInitialize: boolean) {
  if (shouldInitialize) {
     var x = 'b'
  }
  return x
}

console.log(f(true))  // b
console.log(f(false)) // undefined

let upperLet = 0
{
  var scopedVar = 0
  let scopedLet = 0
  upperLet = 5
}
scopedVar = 5 // Visible
scopedLet = 5 // Compile-time error
```

**ArkTS**

```typescript
function f(shouldInitialize: boolean): string {
  let x: string = 'a';
  if (shouldInitialize) {
    x = 'b';
  }
  return x;
}

console.log(f(true));  // b
console.log(f(false)); // a

let upperLet = 0
let scopedVar = 0
{
  let scopedLet = 0
  upperLet = 5
}
scopedVar = 5
scopedLet = 5 // Compile-time error
```

### Recipe: Use Explicit Types Instead of `any` or `unknown`

**Rule:** `arkts-no-any-unknown`

**Severity: error**

ArkTS does not support the types `any` and `unknown`. Specify types explicitly.

**TypeScript**

```typescript
let value1: any
value1 = true
value1 = 42

let value2: unknown
value2 = true
value2 = 42
```

**ArkTS**

```typescript
let value_b: boolean = true // OR: let value_b = true
let value_n: number = 42 // OR: let value_n = 42
let value_o1: Object = true
let value_o2: Object = 42
```

### Recipe: Use `class` Instead of a Type with a Call Signature

**Rule:** `arkts-no-call-signatures`

**Severity: error**

ArkTS does not support call signatures in object types. Use `class` instead.

**TypeScript**

```typescript
type DescribableFunction = {
  description: string
  (someArg: string): string // call signature
}

function doSomething(fn: DescribableFunction): void {
  console.log(fn.description + ' returned ' + fn(''))
}
```

**ArkTS**

```typescript
class DescribableFunction {
  description: string
  public invoke(someArg: string): string {
    return someArg
  }
  constructor() {
    this.description = 'desc'
  }
}

function doSomething(fn: DescribableFunction): void {
  console.log(fn.description + ' returned ' + fn.invoke(''))
}

doSomething(new DescribableFunction())
```

### Recipe: Use `class` Instead of a Type with a Constructor Signature

**Rule:** `arkts-no-ctor-signatures-type`

**Severity: error**

ArkTS does not support constructor signatures in object types. Use `class` instead.

**TypeScript**

```typescript
class SomeObject {}

type SomeConstructor = {
  new (s: string): SomeObject
}

function fn(ctor: SomeConstructor) {
  return new ctor('hello')
}
```

**ArkTS**

```typescript
class SomeObject {
  public f: string
  constructor (s: string) {
    this.f = s
  }
}

function fn(s: string): SomeObject {
  return new SomeObject(s)
}
```

### Recipe: Only One Static Block Is Supported

**Rule:** `arkts-no-multiple-static-blocks`

**Severity: error**

ArkTS does not allow several static blocks for class initialization. Combine static block statements into one static block.

**TypeScript**

```typescript
class C {
  static s: string

  static {
    C.s = 'aa'
  }
  static {
    C.s = C.s + 'bb'
  }
}
```

**ArkTS**

```typescript
class C {
  static s: string

  static {
    C.s = 'aa'
    C.s = C.s + 'bb'
  }
}
```

**NOTE**

Currently, the static block syntax is not supported. This rule must be followed in .ets files when the syntax is supported.

### Recipe: Indexed Signatures Are Not Supported

**Rule:** `arkts-no-indexed-signatures`

**Severity: error**

ArkTS does not allow indexed signatures. Use arrays instead.

**TypeScript**

```typescript
// Interface with an indexed signature:
interface StringArray {
  [index: number]: string
}

function getStringArray(): StringArray {
  return ['a', 'b', 'c']
}

const myArray: StringArray = getStringArray()
const secondItem = myArray[1]
```

**ArkTS**

```typescript
class X {
  public f: string[] = []
}

let myArray: X = new X()
const secondItem = myArray.f[1]
```

### Recipe: Use Inheritance Instead of Intersection Types

**Rule:** `arkts-no-intersection-types`

**Severity: error**

Currently, ArkTS does not support intersection types. Use inheritance as a workaround.

**TypeScript**

```typescript
interface Identity {
  id: number
  name: string
}

interface Contact {
  email: string
  phoneNumber: string
}

type Employee = Identity & Contact
```

**ArkTS**

```typescript
interface Identity {
  id: number
  name: string
}

interface Contact {
  email: string
  phoneNumber: string
}

interface Employee extends Identity,  Contact {}
```

### Recipe: Type Notation Using `this` Is Not Supported

**Rule:** `arkts-no-typing-with-this`

**Severity: error**

ArkTS does not support type notation using the `this` keyword. Use the explicit type instead.

**TypeScript**

```typescript
interface ListItem {
  getHead(): this
}

class C {
  n: number = 0

  m(c: this) {
    // ...
  }
}
```

**ArkTS**

```typescript
interface ListItem {
  getHead(): ListItem
}

class C {
  n: number = 0

  m(c: C) {
    // ...
  }
}
```

### Recipe: Conditional Types Are Not Supported

**Rule:** `arkts-no-conditional-types`

**Severity: error**

ArkTS does not support conditional type aliases. Introduce a new type with constraints explicitly, or rewrite logic using `Object`.
The keyword `infer` is not supported.

**TypeScript**

```typescript
type X<T> = T extends number ? T: never
type Y<T> = T extends Array<infer Item> ? Item: never
```

**ArkTS**

```typescript
// Provide explicit constraints within type alias.
type X1<T extends number> = T

// Rewrite with Object. Less type control requires more type checking for safety.
type X2<T> = Object

// Item has to be used as a generic parameter and needs to be properly instantiated.
type YI<Item, T extends Array<Item>> = Item
```

### Recipe: Declaring Fields in `constructor` Is Not Supported

**Rule:** `arkts-no-ctor-prop-decls`

**Severity: error**

ArkTS does not support declaring class fields in `constructor`. Declare class fields inside the `class` declaration instead.

**TypeScript**

```typescript
class Person {
  constructor(
    protected ssn: string,
    private firstName: string,
    private lastName: string
  ) {
    this.ssn = ssn
    this.firstName = firstName
    this.lastName = lastName
  }

  getFullName(): string {
    return this.firstName + ' ' + this.lastName
  }
}
```

**ArkTS**

```typescript
class Person {
  protected ssn: string
  private firstName: string
  private lastName: string

  constructor(ssn: string, firstName: string, lastName: string) {
    this.ssn = ssn
    this.firstName = firstName
    this.lastName = lastName
  }

  getFullName(): string {
    return this.firstName + ' ' + this.lastName
  }
}
```

### Recipe: Constructor Signatures Are Not Supported in Interfaces

**Rule:** `arkts-no-ctor-signatures-iface`

**Severity: error**

ArkTS does not support constructor signatures. Use methods instead.

**TypeScript**

```typescript
interface I {
  new (s: string): I
}

function fn(i: I) {
  return new i('hello')
}
```

**ArkTS**

```typescript
interface I {
  create(s: string): I
}

function fn(i: I) {
  return i.create('hello')
}
```

### Recipe: Indexed Access Types Are Not Supported

**Rule:** `arkts-no-aliases-by-index`

**Severity: error**

ArkTS does not support indexed access types. Use the type name instead.

### Recipe: Indexed Access Is Not Supported for Fields

**Rule:** `arkts-no-props-by-index`

**Severity: error**

ArkTS does not support dynamic field declaration and access. Declare all
object fields immediately in the class. Access only those class fields
that are either declared in the class, or accessible via inheritance. Accessing
any other fields is prohibited, and causes compile-time errors.

To access a field, use the `obj.field` syntax. Indexed access (`obj["field"]`)
is not supported. An exception is all typed arrays from the standard library
(for example, `Int32Array`), which support access to their elements through the
`container[index]` syntax.
**TypeScript**

```typescript
class Point {
  x: string = ''
  y: string = ''
}
let p: Point = {x: '1', y: '2'}
console.log(p['x'])

class Person {
  name: string = ''
  age: number = 0; // A semicolon is required here.
  [key: string]: string | number
}

let person: Person = {
  name: 'John',
  age: 30,
  email: '***@example.com',
  phoneNumber: '18*********',
}
```

**ArkTS**

```typescript
class Point {
  x: string = ''
  y: string = ''
}
let p: Point = {x: '1', y: '2'}
console.log(p.x)

class Person {
  name: string
  age: number
  email: string
  phoneNumber: string

  constructor(name: string, age: number, email: string,
        phoneNumber: string) {
    this.name = name
    this.age = age
    this.email = email
    this.phoneNumber = phoneNumber
  }
}

let person = new Person('John', 30, '***@example.com', '18*********');
console.log(person['name']);     // Compile-time error
console.log(person.unknownProperty); // Compile-time error

let arr = new Int32Array(1);
arr[0];
```

### Recipe: Structural Typing Is Not Supported

**Rule:** `arkts-no-structural-typing`

**Severity: error**

Currently, ArkTS does not support structural typing. This means that  the compiler
cannot compare public APIs of two types and decide whether they are
identical. Use other mechanisms (inheritance, interfaces, or type aliases)
instead.

**TypeScript**

```typescript
interface I1 {
  f(): string
}

interface I2 { // I2 is structurally equivalent to I1.
  f(): string
}

class X {
  n: number = 0
  s: string = ''
}

class Y { // Y is structurally equivalent to X.
  n: number = 0
  s: string = ''
}

let x = new X()
let y = new Y()

console.log('Assign X to Y')
y = x

console.log('Assign Y to X')
x = y

function foo(x: X) {
  console.log(x.n + x.s)
}

// X and Y are equivalent because their public API is equivalent. Therefore, the second call is allowed.
foo(new X())
foo(new Y())
```

**ArkTS**

```typescript
interface I1 {
  f(): string
}

type I2 = I1 // I2 is an alias for I1.

class B {
  n: number = 0
  s: string = ''
}

// D is derived from B, which explicitly set subtype/supertype relations.
class D extends B {
  constructor() {
    super()
  }
}

let b = new B()
let d = new D()

console.log('Assign D to B')
b = d // OK. B is the superclass of D.

// An attempt to assign b to d will result in a compile-time error.
// d = b

interface Z {
   n: number
   s: string
}

// X implements interface Z, which makes relation between X and Y explicit.
class X implements Z {
  n: number = 0
  s: string = ''
}

// Y implements interface Z, which makes relation between X and Y explicit.
class Y implements Z {
  n: number = 0
  s: string = ''
}

let x: Z = new X()
let y: Z = new Y()

console.log('Assign X to Y')
y = x // ok, both are of the same type

console.log('Assign Y to X')
x = y // ok, both are of the same type

function foo(c: Z): void {
  console.log(c.n + c.s)
}

// X and Y implement the same interface. Therefore both calls are allowed.
foo(new X())
foo(new Y())
```

### Recipe: Type Inference in Case of Generic Function Calls Is Limited

**Rule:** `arkts-no-inferred-generic-params`

**Severity: error**

ArkTS allows to omit generic type parameters if it is possible to infer
the concrete types from the parameters passed to the function. A compile-time
error occurs otherwise. In particular, inference of generic type parameters
based only on function return types is prohibited.

**TypeScript**

```typescript
function choose<T>(x: T, y: T): T {
  return Math.random() < 0.5 ? x: y
}

let x = choose(10, 20)   // OK. choose<number>(...) is inferred.
let y = choose('10', 20) // Compile-time error

function greet<T>(): T {
  return 'Hello' as T
}
let z = greet() // Type of T is inferred as "unknown".
```

**ArkTS**

```typescript
function choose<T>(x: T, y: T): T {
  return Math.random() < 0.5 ? x: y
}

let x = choose(10, 20)   // OK. choose<number>(...) is inferred.
let y = choose('10', 20) // Compile-time error

function greet<T>(): T {
  return 'Hello' as T
}
let z = greet<string>()
```

### Recipe: Object Literal Must Correspond to Some Explicitly Declared Class or Interface

**Rule:** `arkts-no-untyped-obj-literals`

**Severity: error**

ArkTS supports usage of object literals if the compiler can infer to the classes or interfaces that such literals correspond to. Otherwise, a compile-time error occurs.

Using literals to initialize classes and interfaces is specifically not supported in the following contexts:

* Initialization of anything that has `any`, `Object`, or `object` type
* Initialization of classes or interfaces with methods
* Initialization of classes which declare a `constructor` with parameters
* Initialization of classes with `readonly` fields

**Example 1**

**TypeScript**

```typescript
let o1 = {n: 42, s: 'foo'}
let o2: Object = {n: 42, s: 'foo'}
let o3: object = {n: 42, s: 'foo'}

let oo: Object[] = [{n: 1, s: '1'}, {n: 2, s: '2'}]
```

**ArkTS**

```typescript
class C1 {
  n: number = 0
  s: string = ''
}

let o1: C1 = {n: 42, s: 'foo'}
let o2: C1 = {n: 42, s: 'foo'}
let o3: C1 = {n: 42, s: 'foo'}

let oo: C1[] = [{n: 1, s: '1'}, {n: 2, s: '2'}]
```

**Example 2**

**TypeScript**

```typescript
class C2 {
  s: string
  constructor(s: string) {
    this.s = 's =' + s
  }
}
let o4: C2 = {s: 'foo'}
```

**ArkTS**

```typescript
class C2 {
  s: string
  constructor(s: string) {
    this.s = 's =' + s
  }
}
let o4 = new C2('foo')
```

**Example 3**

**TypeScript**

```typescript
class C3 {
  readonly n: number = 0
  readonly s: string = ''
}
let o5: C3 = {n: 42, s: 'foo'}
```

**ArkTS**

```typescript
class C3 {
  n: number = 0
  s: string = ''
}
let o5: C3 = {n: 42, s: 'foo'}
```

**Example 4**

**TypeScript**

```typescript
abstract class A {}
let o6: A = {}
```

**ArkTS**

```typescript
abstract class A {}
class C extends A {}
let o6: C = {} // Or let o6: C = new C()
```

**Example 5**

**TypeScript**

```typescript
class C4 {
  n: number = 0
  s: string = ''
  f() {
    console.log('Hello')
  }
}
let o7: C4 = {n: 42, s: 'foo', f: () => {}}
```

**ArkTS**

```typescript
class C4 {
  n: number = 0
  s: string = ''
  f() {
    console.log('Hello')
  }
}
let o7 = new C4()
o7.n = 42
o7.s = 'foo'
```

**Example 6**

**TypeScript**

```typescript
class Point {
  x: number = 0
  y: number = 0
}

function getPoint(o: Point): Point {
  return o
}

// Structural typing is used to deduce that p is Point.
let p = {x: 5, y: 10}
getPoint(p)

// A literal can be contextually (i.e., implicitly) typed as Point.
getPoint({x: 5, y: 10})
```

**ArkTS**

```typescript
class Point {
  x: number = 0
  y: number = 0

    // constructor() is used before literal initialization to create a valid object.
    // Since there is no other Point constructors, constructor() is automatically added by compiler.
}

function getPoint(o: Point): Point {
  return o
}

// Explicit type is required for literal initialization.
let p: Point = {x: 5, y: 10}
getPoint(p)

// getPoint expects Point explicitly. A new instance of Point is initialized with the literal.
getPoint({x: 5, y: 10})
```

### Recipe: Object Literals Cannot Be Used as Type Declarations

**Rule:** `arkts-no-obj-literals-as-types`

**Severity: error**

ArkTS does not support the usage of object literals to declare types in place. Declare classes and interfaces explicitly instead.

**TypeScript**

```typescript
let o: {x: number, y: number} = {
  x: 2,
  y: 3
}

type S = Set<{x: number, y: number}>
```

**ArkTS**

```typescript
class O {
  x: number = 0
  y: number = 0
}

let o: O = {x: 2, y: 3}

type S = Set<O>
```

### Recipe: Array Literals Must Contain Elements of Only Inferrable Types

**Rule:** `arkts-no-noninferrable-arr-literals`

**Severity: error**

Basically, ArkTS infers the type of an array literal as a union type of its
contents. However, a compile-time error occurs if there is at least one
element with a non-inferrable type (for example, untyped object literal).

**TypeScript**

```typescript
let a = [{n: 1, s: '1'}, {n: 2, s: '2'}]
```

**ArkTS**

```typescript
class C {
  n: number = 0
  s: string = ''
}

let a1 = [{n: 1, s: '1'} as C, {n: 2, s: '2'} as C] // a1 is of type "C[]"
let a2: C[] = [{n: 1, s: '1'}, {n: 2, s: '2'}]    // a2 is of type "C[]"
```

### Recipe: Use Arrow Functions Instead of Function Expressions

**Rule:** `arkts-no-func-expressions`

**Severity: error**

ArkTS does not support function expressions. Use arrow functions instead to specify explicitly.

**TypeScript**

```typescript
let f = function (s: string) {
  console.log(s)
}
```

**ArkTS**

```typescript
let f = (s: string) => {
  console.log(s)
}
```

### Recipe: Class Literals Are Not Supported

**Rule:** `arkts-no-class-literals`

**Severity: error**

ArkTS does not support class literals. Introduce new named class types explicitly.

**TypeScript**

```typescript
const Rectangle = class {
  constructor(height: number, width: number) {
    this.height = height
    this.width = width
  }

  height
  width
}

const rectangle = new Rectangle(0.0, 0.0)
```

**ArkTS**

```typescript
class Rectangle {
  constructor(height: number, width: number) {
    this.height = height
    this.width = width
  }

  height: number
  width: number
}

const rectangle = new Rectangle(0.0, 0.0)
```

### Recipe: Classes Cannot Be Specified in the `implements` Clause

**Rule:** `arkts-implements-only-iface`

**Severity: error**

ArkTS does not allow to specify a class in the `implements` clause. Only interfaces may be specified.

**TypeScript**

```typescript
class C {
  foo() {}
}

class C1 implements C {
  foo() {}
}
```

**ArkTS**

```typescript
interface C {
  foo(): void
}

class C1 implements C {
  foo() {}
}
```

### Recipe: Reassigning Object Methods Is Not Supported

**Rule:** `arkts-no-method-reassignment`

**Severity: error**

ArkTS does not support reassigning a method for objects. In the statically
typed languages, the layout of objects is fixed and all instances of the same
object must share the same code of each method.

If you need to add specific behavior for certain objects, you can create
separate wrapper functions or use inheritance.

**TypeScript**

```typescript
class C {
  foo() {
    console.log('foo')
  }
}

function bar() {
  console.log('bar')
}

let c1 = new C()
let c2 = new C()
c2.foo = bar

c1.foo() // foo
c2.foo() // bar
```

**ArkTS**

```typescript
class C {
  foo() {
    console.log('foo')
  }
}

class Derived extends C {
  foo() {
    console.log('Extra')
    super.foo()
  }
}

function bar() {
  console.log('bar')
}

let c1 = new C()
let c2 = new C()
c1.foo() // foo
c2.foo() // foo

let c3 = new Derived()
c3.foo() // Extra foo
```
### Recipe: Only the `as T` Syntax Is Supported for Type Casting

**Rule:** `arkts-as-casts`

**Severity: error**

ArkTS supports the keyword `as` as the only syntax for type casting.
Incorrect casting causes a compile-time error or runtime `ClassCastException`.
The `<type>` syntax for type casting is not supported.

Use the expression `new ...` instead of `as` if a **primitive** type
(such as a `number` or a `boolean`) must be cast to the reference type.

**TypeScript**

```typescript
class Shape {}
class Circle extends Shape {x: number = 5}
class Square extends Shape {y: string = 'a'}

function createShape(): Shape {
  return new Circle()
}

let c1 = <Circle> createShape()

let c2 = createShape() as Circle

// No report is provided during compilation or runtime if casting is wrong.
let c3 = createShape() as Square
console.log(c3.y) // undefined

// Important corner case for casting primitives to the boxed counterparts:
// The left operand is not properly boxed here in runtime
// because "as" has no runtime effect in TypeScript.
let e1 = (5.0 as Number) instanceof Number // false

// A Number object is created and instanceof works as expected.
let e2 = (new Number(5.0)) instanceof Number // True
```

**ArkTS**

```typescript
class Shape {}
class Circle extends Shape {x: number = 5}
class Square extends Shape {y: string = 'a'}

function createShape(): Shape {
  return new Circle()
}

let c2 = createShape() as Circle

// ClassCastException is thrown during runtime.
let c3 = createShape() as Square

// A Number object is created and instanceof works as expected.
let e2 = (new Number(5.0)) instanceof Number // True
```

### Recipe: JSX Expressions Are Not Supported

**Rule:** `arkts-no-jsx`

**Severity: error**

Do not use JSX since no alternative is provided to rewrite it.

### Recipe: Unary Operators `+`, `-`, and `~` Work Only on Numbers

**Rule:** `arkts-no-polymorphic-unops`

**Severity: error**

ArkTS allows unary operators to work on numeric types only. A compile-time
error occurs if these operators are applied to a non-numeric type. Unlike in
TypeScript, implicit casting of strings in this context is not supported and casting must
be done explicitly.

**TypeScript**

```typescript
let a = +5        // 5 as number
let b = +'5'      // 5 as number
let c = -5        // -5 as number
let d = -'5'      // -5 as number
let e = ~5        // -6 as number
let f = ~'5'      // -6 as number
let g = +'string' // NaN as number

function returnTen(): string {
  return '-10'
}

function returnString(): string {
  return 'string'
}

let x = +returnTen()    // -10 as number
let y = +returnString() // NaN
```

**ArkTS**

```typescript
let a = +5        // 5 as number
let b = +'5'      // Compile-time error
let c = -5        // -5 as number
let d = -'5'      // Compile-time error
let e = ~5        // -6 as number
let f = ~'5'      // Compile-time error
let g = +'string' // Compile-time error

function returnTen(): string {
  return '-10'
}

function returnString(): string {
  return 'string'
}

let x = +returnTen()    // Compile-time error
let y = +returnString() // Compile-time error
```

### Recipe: `delete` Operator Is Not Supported

**Rule:** `arkts-no-delete`

**Severity: error**

ArkTS assumes that object layout is known at compile time and cannot be
changed at runtime. Therefore, the operation of deleting a property makes no sense.

**TypeScript**

```typescript
class Point {
  x?: number = 0.0
  y?: number = 0.0
}

let p = new Point()
delete p.y
```

**ArkTS**

```typescript
// To mimic the original semantics, you may declare a nullable type and assign null to mark the value absence.

class Point {
  x: number | null = 0
  y: number | null = 0
}

let p = new Point()
p.y = null
```

### Recipe: `typeof` Operator Is Allowed Only in Expression Contexts

**Rule:** `arkts-no-type-query`

**Severity: error**

ArkTS supports the `typeof` operator only in the expression context. Using `typeof` to specify type notations is not supported.

**TypeScript**

```typescript
let n1 = 42
let s1 = 'foo'
console.log(typeof n1) // 'number'
console.log(typeof s1) // 'string'
let n2: typeof n1
let s2: typeof s1
```

**ArkTS**

```typescript
let n1 = 42
let s1 = 'foo'
console.log(typeof n1) // 'number'
console.log(typeof s1) // 'string'
let n2: number
let s2: string
```

### Recipe: `instanceof` Operator Is Partially Supported

**Rule:** `arkts-instanceof-ref-types`

**Severity: error**

In TypeScript, the left-hand side of an `instanceof` expression must be of the type
`any`, an object type, or a type parameter. Otherwise, the result is `false`. 
In ArkTS, the left-hand side of an expression may be of any reference type, for example, an object, an array, or a function. Otherwise, a compile-time error occurs. In addition, the left operand in ArkTS
cannot be a type. It must be an object instance.

### Recipe: `in` Operator Is Not Supported

**Rule:** `arkts-no-in`

**Severity: error**

ArkTS does not support the operator `in`. This operator makes
little sense since the object layout is known at compile time and cannot
be changed at runtime. Use `instanceof` as a workaround if you want
to check whether certain class members exist.

**TypeScript**

```typescript
class Person {
  name: string = ''
}
let p = new Person()

let b = 'name' in p // true
```

**ArkTS**

```typescript
class Person {
  name: string = ''
}
let p = new Person()

let b = p instanceof Person // True. "name" is guaranteed to be present.
```

### Recipe: Destructuring Assignment Is Not Supported

**Rule:** `arkts-no-destruct-assignment`

**Severity: error**

ArkTS does not support destructuring assignment. Use other idioms (for example, a temporary variable, where applicable) instead.

**TypeScript**

```typescript
let [one, two] = [1, 2]; // Semicolon is required here
[one, two] = [two, one]

let head, tail
[head, ...tail] = [1, 2, 3, 4]
```

**ArkTS**

```typescript
let arr: number[] = [1, 2]
let one = arr[0]
let two = arr[1]

let tmp = one
one = two
two = tmp

let data: Number[] = [1, 2, 3, 4]
let head = data[0]
let tail: Number[] = []
for (let i = 1; i < data.length; ++i) {
  tail.push(data[i])
}
```

### Recipe: Comma Operator `,` Is Supported Only in `for` Loops

**Rule:** `arkts-no-comma-outside-loops`

**Severity: error**

ArkTS supports the comma operator `,` only in `for` loops. In other cases,
the comma operator is useless as it makes the execution order harder to understand.

Please note that this rule is applied only to the "comma operator". Other cases, when
comma is used to delimit variable declarations or parameters of a function call, are
of course allowed.

**TypeScript**

```typescript
for (let i = 0, j = 0; i < 10; ++i, j += 2) {
  // ...
}

let x = 0
x = (++x, x++) // 1
```

**ArkTS**

```typescript
for (let i = 0, j = 0; i < 10; ++i, j += 2) {
  // ...
}

// Use the explicit execution order instead of the comma operator.
let x = 0
++x
x = x++
```

### Recipe: Destructuring Variable Declarations Are Not Supported

**Rule:** `arkts-no-destruct-decls`

**Severity: error**

ArkTS does not support destructuring variable declarations. This is a dynamic
feature relying on structural compatibility. In addition, names in destructuring
declarations must be equal to properties within destructed classes.

**TypeScript**

```typescript
class Point {
  x: number = 0.0
  y: number = 0.0
}

function returnZeroPoint(): Point {
  return new Point()
}

let {x, y} = returnZeroPoint()
```

**ArkTS**

```typescript
class Point {
  x: number = 0.0
  y: number = 0.0
}

function returnZeroPoint(): Point {
  return new Point()
}

// Create an intermediate object and work with it field by field without name restrictions.
let zp = returnZeroPoint()
let x = zp.x
let y = zp.y
```

### Recipe: Type Annotation in the Catch Clause Is Not Supported

**Rule:** `arkts-no-types-in-catch`

**Severity: error**

In TypeScript, the catch clause variable type annotation must be `any` or `unknown`
if specified. As ArkTS does not support these types, omit type annotations.

**TypeScript**

```typescript
try {
  // ...
} catch (a: unknown) {
  // Handle errors.
}
```

**ArkTS**

```typescript
try {
  // ...
} catch (a) {
  // Handle errors.
}
```

### Recipe: `for .. in` Is Not Supported

**Rule:** `arkts-no-for-in`

**Severity: error**

ArkTS does not support iteration over object contents by the
`for .. in` loop. For objects, iteration over properties at runtime is
considered redundant because object layout is known at compile time and
cannot change at runtime. For arrays, use the regular `for` loop for iteration.

**TypeScript**

```typescript
let a: string[] = ['1.0', '2.0', '3.0']
for (let i in a) {
  console.log(a[i])
}
```

**ArkTS**

```typescript
let a: string[] = ['1.0', '2.0', '3.0']
for (let i = 0; i < a.length; ++i) {
  console.log(a[i])
}
```

### Recipe: Mapped Type Expression Is Not Supported

**Rule:** `arkts-no-mapped-types`

**Severity: error**

ArkTS does not support mapped types. Use other language idioms and regular classes to achieve the same behaviour.

**TypeScript**

```typescript
type OptionsFlags<Type> = {
  [Property in keyof Type]: boolean
}
```

**ArkTS**

```typescript
class C {
  n: number = 0
  s: string = ''
}

class CFlags {
  n: boolean = false
  s: boolean = false
}
```

### Recipe: `with` Statement Is Not Supported

**Rule:** `arkts-no-with`

**Severity: error**

ArkTS does not support the `with` statement. Use other language idioms to achieve the same behaviour.

**TypeScript**

```typescript
with (Math) { // Compile-time error, but JavaScript code can still be emitted.
  let r: number = 42;
  let area: number = PI * r * r;
}
```

**ArkTS**

```typescript
let r: number = 42;
let area: number = Math.PI * r * r;
```

### Recipe: `throw` Statements Do Not Accept Values of Arbitrary Types

**Rule:** `arkts-limited-throw`

**Severity: error**

ArkTS supports throwing only objects of the class `Error` or any
derived class. Throwing an arbitrary type (for example, a `number` or `string`)
is prohibited.

**TypeScript**

```typescript
throw 4
throw ''
throw new Error()
```

**ArkTS**

```typescript
throw new Error()
```

### Recipe: Function Return Type Inference Is Limited

**Rule:** `arkts-no-implicit-return-types`

**Severity: error**

ArkTS supports type inference for function return types, but this functionality
is currently restricted. In particular, when the expression in the `return`
statement is a call to a function or method whose return value type is omitted,
a compile-time error occurs. If this is the case, specify the return type explicitly.

**TypeScript**

```typescript
// Compile-time error when noImplicitAny is enabled.
function f(x: number) {
  if (x <= 0) {
    return x;
  }
  return g(x);
}

// Compile-time error when noImplicitAny is enabled.
function g(x: number) {
  return f(x - 1);
}

function doOperation(x: number, y: number) {
  return x + y;
}

f(10);
doOperation(2, 3);
```

**ArkTS**

```typescript
// An explicit return type is required.
function f(x: number): number {
  if (x <= 0) {
    return x;
  }
  return g(x);
}

// Return type may be omitted. It is inferred from f's explicit type.
function g(x: number): number {
  return f(x - 1);
}

// In this case, the return type will be inferred.
function doOperation(x: number, y: number) {
  return x + y;
}

f(10);
doOperation(2, 3);
```

### Recipe: Destructuring Parameter Declarations Are Not Supported

**Rule:** `arkts-no-destruct-params`

**Severity: error**

ArkTS requires parameters to be passed directly to the function, and local names to be assigned manually.

**TypeScript**

```typescript
function drawText({ text = '', location: [x, y] = [0, 0], bold = false }) {
  text;
  x;
  y;
  bold;
}

drawText({ text: 'Hello, world!', location: [100, 50], bold: true })
```

**ArkTS**

```typescript
function drawText(text: String, location: number[], bold: boolean) {
  let x = location[0];
  let y = location[1];
  text;
  x;
  y;
  bold;
}

function main() {
  drawText('Hello, world!', [100, 50], true);
}
```

### Recipe: Nested Functions Are Not Supported

**Rule:** `arkts-no-nested-funcs`

**Severity: error**

ArkTS does not support nested functions. Use lambdas instead.

**TypeScript**

```typescript
function addNum(a: number, b: number): void {

    // Nested function
  function logToConsole(message: string): void {
    console.log(message)
  }

  let result = a + b

    // Invoke the nested function.
  logToConsole('result is ' + result)
}
```

**ArkTS**

```typescript
function addNum(a: number, b: number): void {
    // Use lambda instead of a nested function.
  let logToConsole: (message: string) => void = (message: string): void => {
    console.log(message)
  }

  let result = a + b

  logToConsole('result is ' + result)
}
```

### Recipe: Using `this` Inside Stand-Alone Functions Is Not Supported

**Rule:** `arkts-no-standalone-this`

**Severity: error**

ArkTS does not support the usage of `this` inside stand-alone functions and inside static methods. `this` can be used in instance methods only.

**TypeScript**

```typescript
function foo(i: string) {
    this.count = i // Compile-time error only when noImplicitThis is enabled.
}

class A {
  count: string = 'a'
  m = foo
}

let a = new A();
console.log(a.count); // Prints "a".
a.m(b);
console.log(a.count); // Prints "b".
```

**ArkTS**

```typescript
class A {
  count: string = 'a'
  m(i: string): void {
    this.count = i;
  }
}

function main(): void {
  let a = new A();
  console.log(a.count);  // Prints "a".
  a.m('b');
  console.log(a.count);  // Prints "b".
}
```

### Recipe: Generator Functions Are Not Supported

**Rule:** `arkts-no-generators`

**Severity: error**

Currently, ArkTS does not support generator functions. Use the `async`/`await` mechanism for multitasking.

**TypeScript**

```typescript
function* counter(start: number, end: number) {
  for (let i = start; i <= end; i++) {
    yield i
  }
}

for (let num of counter(1, 5)) {
  console.log(num)
}
```

**ArkTS**

```typescript
async function complexNumberProcessing(num: number): Promise<number> {
  // ...
  return num;
}

async function foo() {
  for (let i = 1; i <= 5; i++) {
    await complexNumberProcessing(i);
  }
}

foo()
```

### Recipe: Type Guarding Is Supported with `instanceof` and `as`

**Rule:** `arkts-no-is`

**Severity: error**

ArkTS does not support the `is` operator, which must be replaced by the
`instanceof` operator. Note that the fields of an object must be cast to the
appropriate type with the `as` operator before being used.

**TypeScript**

```typescript
class Foo {
  foo: string = ''
  common: string = ''
}

class Bar {
  bar: string = ''
  common: string = ''
}

function isFoo(arg: any): arg is Foo {
  return arg.foo !== undefined
}

function doStuff(arg: Foo | Bar) {
  if (isFoo(arg)) {
    console.log(arg.foo)  // OK
    console.log(arg.bar)  // Compile-time error
  } else {
    console.log(arg.foo)  // Compile-time error
    console.log(arg.bar)  // OK
  }
}

doStuff({ foo: 123, common: '123' })
doStuff({ bar: 123, common: '123' })
```

**ArkTS**

```typescript
class Foo {
  foo: string = ''
  common: string = ''
}

class Bar {
  bar: string = ''
  common: string = ''
}

function isFoo(arg: Object): boolean {
  return arg instanceof Foo
}

function doStuff(arg: Object): void {
  if (isFoo(arg)) {
    let fooArg = arg as Foo
    console.log(fooArg.foo)   // OK
    console.log(arg.bar)    // Compile-time error
  } else {
    let barArg = arg as Bar
    console.log(arg.foo)    // Compile-time error
    console.log(barArg.bar)   // OK
  }
}

function main(): void {
  doStuff(new Foo())
  doStuff(new Bar())
}
```

### Recipe: It is possible to spread only arrays or classes derived from arrays into the rest parameter or array literals

**Rule:** `arkts-no-spread`

**Severity: error**

The only supported scenario for the spread operator is to spread an array or
class derived from array into the rest parameter or array literal.
Otherwise, manually "unpack" data from arrays and objects, where necessary.
All typed arrays from the standard library (for example, ``Int32Array``)
are also supported.

**TypeScript**

```typescript
function foo(x: number, y: number, z: number) {
  // ...
}

let args: [number, number, number] = [0, 1, 2];
foo(...args);
```

**ArkTS**

```typescript
function log_numbers(x: number, y: number, z: number) {
  // ...
}

let numbers: number[] = [1, 2, 3];
log_numbers(numbers[0], numbers[1], numbers[2]);
```

**TypeScript**

```typescript
let point2d = { x: 1, y: 2 };
let point3d = { ...point2d, z: 3 };
```

**ArkTS**

```typescript
class Point2D {
  x: number = 0; y: number = 0
}

class Point3D {
  x: number = 0; y: number = 0; z: number = 0
  constructor(p2d: Point2D, z: number) {
    this.x = p2d.x;
    this.y = p2d.y;
    this.z = z;
  }
}

let p3d = new Point3D({ x: 1, y: 2 } as Point2D, 3);

class DerivedFromArray extends Uint16Array {};

let arr1 = [1, 2, 3];
let arr2 = new Uint16Array([4, 5, 6]);
let arr3 = new DerivedFromArray([7, 8, 9]);
let arr4 = [...arr1, 10, ...arr2, 11, ...arr3];
```

### Recipe: Interface Cannot Extend Interfaces with the Same Method

**Rule:** `arkts-no-extend-same-prop`

**Severity: error**

In TypeScript, an interface that extends two other interfaces with the same method
must declare that method with a combined return type. It is not allowed in
ArkTS because ArkTS does not allow an interface to contain two methods with
signatures that are not distinguishable, for example, two methods that have the same
parameter lists but different return types.

**TypeScript**

```typescript
interface Mover {
  getStatus(): { speed: number }
}
interface Shaker {
  getStatus(): { frequency: number }
}

interface MoverShaker extends Mover, Shaker {
  getStatus(): {
    speed: number
    frequency: number
  }
}

class C implements MoverShaker {
  private speed: number = 0
  private frequency: number = 0

  getStatus() {
    return { speed: this.speed, frequency: this.frequency }
  }
}
```

**ArkTS**

```typescript
class MoveStatus {
  public speed: number
  constructor() {
    this.speed = 0
  }
}
interface Mover {
  getMoveStatus(): MoveStatus
}

class ShakeStatus {
  public frequency: number
  constructor() {
    this.frequency = 0
  }
}
interface Shaker {
  getShakeStatus(): ShakeStatus
}

class MoveAndShakeStatus {
  public speed: number
  public frequency: number
  constructor() {
    this.speed = 0
    this.frequency = 0
  }
}

class C implements Mover, Shaker {
  private move_status: MoveStatus
  private shake_status: ShakeStatus

  constructor() {
    this.move_status = new MoveStatus()
    this.shake_status = new ShakeStatus()
  }

  public getMoveStatus(): MoveStatus {
    return this.move_status
  }

  public getShakeStatus(): ShakeStatus {
    return this.shake_status
  }

  public getStatus(): MoveAndShakeStatus {
    return {
      speed: this.move_status.speed,
      frequency: this.shake_status.frequency
    }
  }
}
```

### Recipe: Declaration Merging Is Not Supported

**Rule:** `arkts-no-decl-merging`

**Severity: error**

ArkTS does not support merging declarations. Keep all definitions of classes and interfaces compact in the codebase.

**TypeScript**

```typescript
interface Document {
  createElement(tagName: any): Element
}

interface Document {
  createElement(tagName: string): HTMLElement
}

interface Document {
  createElement(tagName: number): HTMLDivElement
  createElement(tagName: boolean): HTMLSpanElement
  createElement(tagName: string, value: number): HTMLCanvasElement
}
```

**ArkTS**

```typescript
interface Document {
  createElement(tagName: number): HTMLDivElement
  createElement(tagName: boolean): HTMLSpanElement
  createElement(tagName: string, value: number): HTMLCanvasElement
  createElement(tagName: string): HTMLElement
  createElement(tagName: Object): Element
}
```

### Recipe: Interfaces Cannot Extend Classes

**Rule:** `arkts-extends-only-class`

**Severity: error**

ArkTS does not support interfaces that extend classes. Interfaces can extend only interfaces.

**TypeScript**

```typescript
class Control {
  state: number = 0
}

interface SelectableControl extends Control {
  select(): void
}
```

**ArkTS**

```typescript
interface Control {
  state: number
}

interface SelectableControl extends Control {
  select(): void
}
```

### Recipe: Constructor Function Type Is Not Supported

**Rule:** `arkts-no-ctor-signatures-funcs`

**Severity: error**

ArkTS does not support the usage of the constructor function type. Use lambdas instead.

**TypeScript**

```typescript
class Person {
  constructor(
    name: string,
    age: number
  ) {}
}
type PersonCtor = new (name: string, age: number) => Person

function createPerson(Ctor: PersonCtor, name: string, age: number): Person
{
  return new Ctor(name, age)
}

const person = createPerson(Person, 'John', 30)
```

**ArkTS**

```typescript
class Person {
  constructor(
    name: string,
    age: number
  ) {}
}
type PersonCtor = (n: string, a: number) => Person

function createPerson(Ctor: PersonCtor, n: string, a: number): Person {
  return Ctor(n, a)
}

let Impersonizer: PersonCtor = (n: string, a: number): Person => {
  return new Person(n, a)
}

const person = createPerson(Impersonizer, 'John', 30)
```

### Recipe: Enumeration Members Can Be Initialized Only with Compile Time Expressions of the Same Type

**Rule:** `arkts-no-enum-mixed-types`

**Severity: error**

ArkTS does not support initializing members of enumerations with expressions
that are evaluated during program runtime. Besides, all explicitly set
initializers must be of the same type.

**TypeScript**

```typescript
enum E1 {
  A = 0xa,
  B = 0xb,
  C = Math.random(),
  D = 0xd,
  E // 0xe inferred
}

enum E2 {
  A = 0xa,
  B = '0xb',
  C = 0xc,
  D = '0xd'
}
```

**ArkTS**

```typescript
enum E1 {
  A = 0xa,
  B = 0xb,
  C = 0xc,
  D = 0xd,
  E // 0xe inferred
}

enum E2 {
  A = '0xa',
  B = '0xb',
  C = '0xc',
  D = '0xd'
}
```

### Recipe: `enum` Declaration Merging Is Not Supported

**Rule:** `arkts-no-enum-merging`

**Severity: error**

ArkTS does not support merging declarations for `enum`. Keep the declaration of each `enum` compact in the codebase.

**TypeScript**

```typescript
enum ColorSet {
  RED,
  GREEN
}
enum ColorSet {
  YELLOW = 2
}
enum ColorSet {
  BLACK = 3,
  BLUE
}
```

**ArkTS**

```typescript
enum ColorSet {
  RED,
  GREEN,
  YELLOW,
  BLACK,
  BLUE
}
```

### Recipe: Namespaces Cannot Be Used as Objects

**Rule:** `arkts-no-ns-as-obj`

**Severity: error**

ArkTS does not support the usage of namespaces as objects. Classes or modules can be interpreted as analogs of namespaces.

**TypeScript**

```typescript
namespace MyNamespace {
  export let x: number
}

let m = MyNamespace
m.x = 2
```

**ArkTS**

```typescript
namespace MyNamespace {
  export let x: number
}

MyNamespace.x = 2
```

### Recipe: Non-declaration Statements in Namespaces Are Not Supported

**Rule:** `arkts-no-ns-statements`

**Severity: error**

ArkTS does not support statements in namespaces. Use a function to execute statements.

**TypeScript**

```typescript
namespace A {
  export let x: number
  x = 1
}
```

**ArkTS**

```typescript
namespace A {
  export let x: number

  export function init() {
    x = 1
  }
}

// Initialization function should be called to execute statements.
A.init()
```

### Recipe: `require` and `import` Assignment Are Not Supported

**Rule:** `arkts-no-require`

**Severity: error**

ArkTS does not support importing via `require`.
It does not support `import` assignments either.
Use the regular `import` syntax  instead.

**TypeScript**

```typescript
import m = require('mod')
```

**ArkTS**

```typescript
import * as m from 'mod'
```

### Recipe: `export = ...` Is Not Supported

**Rule:** `arkts-no-export-assignment`

**Severity: error**

ArkTS does not support the `export = ...` syntax.
Use the ordinary `export` and `import` syntaxes instead.

**TypeScript**

```typescript
// module1
export = Point

class Point {
  constructor(x: number, y: number) {}
  static origin = new Point(0, 0)
}

// module2
import Pt = require('module1')

let p = Pt.Point.origin
```

**ArkTS**

```typescript
// module1
export class Point {
  constructor(x: number, y: number) {}
  static origin = new Point(0, 0)
}

// module2
import * as Pt from 'module1'

let p = Pt.Point.origin
```

### Recipe: Ambient Module Declaration Is Not Supported

**Rule:** `arkts-no-ambient-decls`

**Severity: error**

ArkTS does not support ambient module declaration because it has its own mechanisms for interoperating with JavaScript.

**TypeScript**

```typescript
declare module 'someModule' {
  export function normalize(s: string): string;
}
```

**ArkTS**

```typescript
// Import what you need from the original module.
import { normalize } from "someModule"
```

### Recipe: Wildcards in Module Names Are Not Supported

**Rule:** `arkts-no-module-wildcards`

**Severity: error**

ArkTS does not support wildcards in module names, because import is a compile-time feature in ArkTS, not a runtime feature.
Use the ordinary `export` syntax instead.

**TypeScript**

```typescript
// Declaration:
declare module '*!text' {
  const content: string
  export default content
}

// Consuming code:
import fileContent from 'some.txt!text'
```

**ArkTS**

```typescript
// Declaration:
declare namespace N {
  function foo(x: number): number
}

// Consuming code:
import * as m from 'module'
console.log('N.foo called: ' + N.foo(42))
```

### Recipe: UMD Is Not Supported

**Rule:** `arkts-no-umd`

**Severity: error**

ArkTS does not support universal module definitions (UMD), because it does not have the concept of "script" (as opposed to "module").
In addition, import is a compile-time feature in ArkTS, not a runtime feature.
Use the ordinary `export` and `import` syntaxes instead.

**TypeScript**

```typescript
// math-lib.d.ts
export const isPrime(x: number): boolean
export as namespace mathLib

// In script
mathLib.isPrime(2)
```

**ArkTS**

```typescript
// math-lib.d.ts
namespace mathLib {
  export isPrime(x: number): boolean
}

// In program
import { mathLib } from "math-lib"
mathLib.isPrime(2)
```

### Recipe: `new.target` Is Not Supported

**Rule:** `arkts-no-new-target`

**Severity: error**

ArkTS does not support `new.target`, because there is no concept of runtime
prototype inheritance in the language. This feature is considered not applicable
to static typing.

### Recipe: Definite Assignment Assertions Are Not Supported

**Rule:** `arkts-no-definite-assignment`

**Severity: warning**

ArkTS does not support definite assignment assertions `let v!: T` because
they are considered an excessive compiler hint.
Use declarations with initialization instead.

**TypeScript**

```typescript
let x!: number // Hint: x will be initialized before usage.

initialize()

function initialize() {
  x = 10
}

console.log('x = ' + x)
```

**ArkTS**

```typescript
function initialize(): number {
  return 10
}

let x: number = initialize()

console.log('x = ' + x)
```

### Recipe: Prototype Assignment Is Not Supported

**Rule:** `arkts-no-prototype-assignment`

**Severity: error**

ArkTS does not support prototype assignment because there is no concept of
runtime prototype inheritance in the language. This feature is considered not
applicable to static typing. Mechanism of classes and/or interfaces must
be used instead to statically "combine" methods to data together.

**TypeScript**

```typescript
let C = function(p) {
  this.p = p // Compile-time error only when noImplicitThis is enabled
}

C.prototype = {
  m() {
    console.log(this.p)
  }
}

C.prototype.q = function(r: string) {
  return this.p == r
}
```

**ArkTS**

```typescript
class C {
  p: string = ''
  m() {
    console.log(this.p)
  }
  q(r: string) {
    return this.p == r
  }
}
```

### Recipe: `globalThis` Is Not Supported

**Rule:** `arkts-no-globalthis`

**Severity: warning**

ArkTS does not support both global scope and `globalThis` because untyped
objects with dynamically changed layout are not supported.

**TypeScript**

```typescript
// In a global file:
var abc = 100

// Refers to 'abc' from above.
let x = globalThis.abc
```

**ArkTS**

```typescript
// File 1
export let abc: number = 100

// File 2
import * as M from 'file1'

let x = M.abc
```

### Recipe: Some Utility Types Are Not Supported

**Rule:** `arkts-no-utility-types`

**Severity: error**

Currently ArkTS does not support utility types from TypeScript extensions to the
standard library. Exceptions are `Partial`, `Required`, `Readonly` and `Record`.

For the type *Record<K, V>*, the type of an indexing expression *rec[index]* is of the type *V | undefined*.

### Recipe: Declaring Properties on Functions Is Not Supported

**Rule:** `arkts-no-func-props`

**Severity: error**

ArkTS does not support declaring properties on functions because there is no
support for objects with dynamically changing layout. Function objects follow
this rule and their layout cannot be changed at runtime.

### Recipe: `Function.apply` and `Function.call` Are Not Supported

**Rule:** `arkts-no-func-apply-call`

**Severity: error**

ArkTS does not support `Function.apply` or `Function.call`. These APIs are needed in the standard
library to explicitly set the parameter `this` for the called function.
In ArkTS, the semantics of `this` is restricted to the conventional OOP
style, and the usage of `this` in stand-alone functions is prohibited.

### Recipe:`Function.bind` Is Not Supported

**Rule:** `arkts-no-func-bind`

**Severity: warning**

ArkTS does not support `Function.bind`. These APIs are needed in the standard
library to explicitly set the parameter `this` for the called function.
In ArkTS, the semantics of `this` is restricted to the conventional OOP
style, and the usage of `this` in stand-alone functions is prohibited.

### Recipe: `as const` Assertions Are Not Supported

**Rule:** `arkts-no-as-const`

**Severity: error**

ArkTS does not support `as const` assertions, because in standard TypeScript
`as const` is used to annotate literals with corresponding literal types, and ArkTS
does not support literal types.

**TypeScript**

```typescript
// Type 'hello':
let x = 'hello' as const

// Type 'readonly [10, 20]':
let y = [10, 20] as const

// Type '{ readonly text: "hello" }':
let z = { text: 'hello' } as const
```

**ArkTS**

```typescript
// Type 'string':
let x: string = 'hello'

// Type 'number[]':
let y: number[] = [10, 20]

class Label {
  text: string = ''
}

// Type 'Label':
let z: Label = {
  text: 'hello'
}
```

### Recipe: Import Assertions Are Not Supported

**Rule:** `arkts-no-import-assertions`

**Severity: error**

ArkTS does not support import assertions, because import is a
compile-time feature in ArkTS, not a runtime feature. So asserting the correctness of imported APIs
in runtime does not make sense for the statically typed language. Use the ordinary
`import` syntax instead.

**TypeScript**

```typescript
import { obj } from 'something.json' assert { type: 'json' }
```

**ArkTS**

```typescript
// The correctness of importing T will be checked at compile time.
import { something } from 'module'
```

### Recipe: Usage of Standard Libraries Is Restricted

**Rule:** `arkts-limited-stdlib`

**Severity: error**

ArkTS does not support certain APIs in the TypeScript and JavaScript standard libraries.
Most of these restricted APIs are used to manipulate objects in a
dynamic manner, which is not compatible with static typing. The usage of
the following APIs is prohibited:

Properties and functions of the global object: `eval`

`Object`: `__proto__`, `__defineGetter__`, `__defineSetter__`,
`__lookupGetter__`, `__lookupSetter__`, `assign`, `create`,
`defineProperties`, `defineProperty`, `freeze`,
`fromEntries`, `getOwnPropertyDescriptor`, `getOwnPropertyDescriptors`,
`getOwnPropertySymbols`, `getPrototypeOf`,
`hasOwnProperty`, `is`, `isExtensible`, `isFrozen`,
`isPrototypeOf`, `isSealed`, `preventExtensions`,
`propertyIsEnumerable`, `seal`, `setPrototypeOf`

`Reflect`: `apply`, `construct`, `defineProperty`, `deleteProperty`,
`getOwnPropertyDescriptor`, `getPrototypeOf`,
`isExtensible`, `preventExtensions`,
`setPrototypeOf`

`Proxy`: `handler.apply()`, `handler.construct()`,
`handler.defineProperty()`, `handler.deleteProperty()`, `handler.get()`,
`handler.getOwnPropertyDescriptor()`, `handler.getPrototypeOf()`,
`handler.has()`, `handler.isExtensible()`, `handler.ownKeys()`,
`handler.preventExtensions()`, `handler.set()`, `handler.setPrototypeOf()`

### Recipe: Strict Type Checking Is Enforced

**Rule:** `arkts-strict-typing`

**Severity: error**

Type checking in ArkTS is not optional. Any code must be explicitly and
correctly typed to be compiled and run. When porting code from standard TypeScript,
enable the following flags: `noImplicitReturns`, `strictFunctionTypes`,
`strictNullChecks`, and `strictPropertyInitialization`.

**TypeScript**

```typescript
// Compile-time error only when noImplicitReturns is enabled.
function foo(s: string): string {
  if (s != '') {
    console.log(s)
    return s
  } else {
    console.log(s)
  }
}

let n: number = null // Compile-time error only when strictNullChecks is enabled.
```

**ArkTS**

```typescript
function foo(s: string): string {
  console.log(s)
  return s
}

let n1: number | null = null
let n2: number = 0
```

If you cannot initialize an instance property by declaration or in a constructor when defining a class, you can use the definite assignment assertion operator (!) to clear the `strictPropertyInitialization` error.

However, the use of the definite assignment assertion operator (!) increases the risk of code errors. Therefore, you must ensure that the instance property has been assigned a value before being used. Otherwise, the runtime exceptions may occur.

In addition, the use of the definite assignment assertion operator (!) requires a runtime type check, resulting in additional runtime overhead. It also generates the error `warning: arkts-no-definite-assignment` at the compile time. Therefore, use it only when quite necessary.

**TypeScript**

```typescript
class C {
  name: string  // ֻCompile-time error only when strictPropertyInitialization is enabled.
  age: number   // ֻCompile-time error only when strictPropertyInitialization is enabled.
}

let c = new C()
```

**ArkTS**

```typescript
class C {
  name: string = ''
  age!: number      // warning: arkts-no-definite-assignment

  initAge(age: number) {
    this.age = age
  }
}

let c = new C()
c.initAge(10)
```

### Recipe: Disabling Type Checking with In-Place Comments Is Not Allowed

**Rule:** `arkts-strict-typing-required`

**Severity: error**

Type checking in ArkTS is not optional. Any code must be explicitly and
correctly typed to be compiled and run. Disabling type checking in-place
with special comments is not allowed. In particular, `@ts-ignore` and
`@ts-nocheck` annotations are not supported.

**TypeScript**

```typescript
// @ts-nocheck
// ...
// Some code with type checking disabled.
// ...

let s1: string = null // No error, since type checking is disabled.

// @ts-ignore
let s2: string = null // No error, since type checking is disabled.
```

**ArkTS**

```typescript
let s1: string | null = null // No error. The types are proper.
let s2: string = null // Compile-time error.
```

### Recipe: No Dependencies on TypeScript Code Are Allowed

**Rule:** `arkts-no-ts-deps`

**Severity: error**

Currently, the codebase implemented in the standard TypeScript language must not
depend on ArkTS by importing an ArkTS codebase. Imports in the reverse
direction are supported.

**TypeScript**

```typescript
// app.ets
export class C {
  // ...
}

// lib.ts
import { C } from 'app'
```

**ArkTS**

```typescript
// lib1.ets
export class C {
  // ...
}

// lib2.ets
import { C } from 'lib1'
```

### Recipe: Classes Cannot Be Used as Objects

**Rule:** `arkts-no-classes-as-obj`

**Severity: warning**

ArkTS does not support using classes as objects (assigning them to variables,
etc.). This is because in ArkTS, a `class` declaration introduces a new type,
not a value.

### Recipe: `import` Statements After Other Statements Are Not Allowed

**Rule:** `arkts-no-misplaced-imports`

**Severity: error**

In ArkTS, all `import` statements should go before all other statements in the program.

**TypeScript**

```typescript
class C {
  s: string = ''
  n: number = 0
}

import foo from 'module1'
```

**ArkTS**

```typescript
import foo from 'module1'

class C {
  s: string = ''
  n: number = 0
}
```

### Recipe: Usage of `ESObject` Type Is Restricted

**Rule:** `arkts-limited-esobj`

**Severity: warning**

**Error codes: 10605151**

ArkTS does not allow using `ESObject` type in some cases. The most part of
limitations are put in place in order to prevent spread of dynamic objects in
the static codebase. 
For API version 15 or eariler, the only scenario where it is permited to use `ESObject` as type specifier is in local variable declaration. Initialization of variables
with `ESObject` type is also limited. Such variables can only be initialized
with values that originate from interop: other `ESObject` typed variables,
any, unknown, variables with anonymous type, etc. It is prohibited to
initialize `ESObject` typed variable with statically typed value. Varaible
of type `ESObject` can only be passed to interop calls and assigned to other
variables of type `ESObject`.
Since API version 16, the `ESObject` type prohibits object literal assignment while supporting: type annotations in dynamic imports, property access (using both **.** and **[]** operators), **call** expressions, and **new** expressions.

**ArkTS**

```typescript
// lib.d.ts
declare function foo(): any;
declare function bar(a: any): number;

// main.ets
let e0: ESObject = foo(); // For API version 15 or eariler, compile-time error: 'ESObject' typed variable can only be local; since API version 16, the ESObject type supports explicit type annotation.

function f() {
  let e1 = foo();        // Compile-time error: type of e1 is 'any';
  let e2: ESObject = 1;  // For API version 15 or eariler, compile-time error: Cannot initialize an ESObject with non-dynamic values; since API version 16, the number type is supported.
  let e3: ESObject = {}; // For API version 15 or eariler, compile-time error: Cannot initialize an ESObject with non-dynamic values; since API version 16, compile-time error: object literal type is not supported.
  let e4: ESObject = []; // For API version 15 or eariler, compile-time error: Cannot initialize an ESObject with non-dynamic values; since API version 16, the array type is supported.
  let e5: ESObject = ""; // For API version 15 or eariler, compile-time error: Cannot initialize an ESObject with non-dynamic values; since API version 16, the string type is supported.
  e5['prop']             // For API version 15 or eariler, compile-time error: Cannot access dynamic properties of 'ESObject'; since API version 16, property access using square brackets is supported.
  e5[1]                  // For API version 15 or eariler, compile-time error: Cannot access dynamic properties of 'ESObject'; since API version 16, property access using square brackets is supported.
  e5.prop                // For API version 15 or eariler, compile-time error: Cannot access dynamic properties of 'ESObject'; since API version 16, property access using a dot (.) is supported.

  let e6: ESObject = foo(); // OK - Explicitly annotated as 'ESObject'
  let e7 = e6;              // OK - Initialize 'ESObject' with 'ESObject'
  bar(e7)                   // OK - 'ESObject' is passed to interop call
}
```
