# TypeScript to ArkTS Cookbook

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @husenlin-->
<!--Designer: @qyhuo32-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @zhang_yixin13-->

ArkTS restricts the features of TypeScript (TS) that undermine development correctness or increase runtime overhead. This topic lists the TypeScript features restricted by ArkTS and provides recipes on code refactoring. ArkTS retains most syntax features of TypeScript. TypeScript features that are not mentioned in this topic are fully supported by ArkTS. For example, the custom decorators supported by ArkTS have the same syntax as those supported by TypeScript. After code refactoring based on the recipes in this topic, the code is still valid TypeScript code.

**Example**

Original TypeScript code containing the keyword **var**:

```typescript
function addTen(x: number): number {
  var ten = 10;
  return x + ten;
}
```

Refactored code:

```typescript
function addTen(x: number): number {
  let ten = 10;
  return x + ten;
}
```

**Severity levels**

Each recipe is marked with the severity level. Supported values:

- **Error**: The recipe should be followed, otherwise the program will fail to compile.
- **Warning**: It is highly recommended to follow the recipe. Although violating the recipe does not currently affect the compilation, in future versions, it will cause compilation to fail.

**Unsupported Features**

Currently, unsupported features are mainly either of the following:

- Features relate to dynamic typing that degrades runtime performance
- Features that require extra support in the compiler, thereby degrading project build time

However, the ArkTS team reserves the right to reconsider the list and shrink it in the future releases based on the feedback from developers and real-world data experiments.

## Recipes Summarized

This topic lists the TypeScript features that are not supported or partially supported by ArkTS. For details about the full feature list, detailed code examples, and workaround suggestions, see [Recipes](#recipes). For more cases, see [Adaptation Cases](arkts-more-cases.md).

### Static Typing Is Enforced

One of the most important features of ArkTS is static typing. If a program is statically typed (all types are known at compile time), it is much easier to understand what data structures are used in the code. Since all types are known before the program actually runs, the compiler can verify code correctness, thereby eliminating many runtime type checks and improving performance.

Therefore, the usage of the type **any** in ArkTS is prohibited.

**Example**

```typescript
// Not supported:
let res: any = some_api_function('hello', 'world');
// Supported:
class CallResult {
  public succeeded(): boolean {
    return false;
  }
  public errorMessage(): string {
    return '123';
  }
}
function some_api_function(param1: string, param2: string): CallResult {
  return new CallResult();
}

let res: CallResult = some_api_function('hello', 'world');
if (!res.succeeded()) {
  console.info('Call failed: ' + res.errorMessage());   
}  
```

According to our measurements, **any** is already not welcome in TypeScript. It is used in approximately 1% of TypeScript codebases. Moreover, today's code linters (for example, ESLint) include a set of rules that prohibit the usage of **any**. Prohibiting **any** results in a strong positive impact on performance at the cost of low-effort code refactoring.

### Changing Object Layout in Runtime Is Prohibited

To achieve maximum performance benefits, ArkTS requires the layout of objects to remain unchanged during program execution. In other words, it is prohibited to:

- Add new properties or methods to objects.
- Delete existing properties or methods from objects.
- Assign values of arbitrary types to object properties.

It is noteworthy that many such operations are already prohibited by the TS compiler. However, it can still be "tricked" by, for example, using **as any** to convert the object type, disabling strict type check when compiling TS code, or ignoring type check using **@ts-ignore** in the code.

In ArkTS, strict type check is not configurable. ArkTS enforces strict type check and prohibits the use of **any** and **@ts-ignore** in the code.

**Example**

```typescript
class Point {
  public x: number = 0
  public y: number = 0

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}

// It is impossible to delete a property from the object. It is guaranteed that all Point objects have the property x.
let p1 = new Point(1.0, 1.0);
delete p1.x;           // Compile-time error in TypeScript and ArkTS
delete (p1 as any).x;  // OK in TypeScript; compile-time error in ArkTS

// Class Point does not define any property named `z`, and it is impossible to add it while the program runs.
let p2 = new Point(2.0, 2.0);
p2.z = 'Label';           // Compile-time error in TypeScript and ArkTS
(p2 as any).z = 'Label';   // OK in TypeScript; compile-time error in ArkTS

// It is guaranteed that all Point objects have only properties x and y and other properties cannot be added.
let p3 = new Point(3.0, 3.0);
let prop = Symbol();      // OK in TypeScript; compile-time error in ArkTS
(p3 as any)[prop] = p3.x; // OK in TypeScript; compile-time error in ArkTS
p3[prop] = p3.x;          // Compile-time error in TypeScript and ArkTS

// It is guaranteed that all Point objects have properties x and y of type number, so assigning a value of any other type is impossible:
let p4 = new Point(4.0, 4.0);
p4.x = 'Hello!';          // Compile-time error in TypeScript and ArkTS
(p4 as any).x = 'Hello!'; // OK in TypeScript; compile-time error in ArkTS

// Usage of Point objects which is compliant with the class definition:
function distance(p1: Point, p2: Point): number {
  return Math.sqrt(
    (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y)
  );
}
let p5 = new Point(5.0, 5.0);
let p6 = new Point(6.0, 6.0);
console.info('Distance between p5 and p6: ' + distance(p5, p6));
```

Unpredictable changing of object layout contradicts both good readability and good performance of code. Indeed, having class definition at one place and modifying actual object layout elsewhere is confusing and error-prone from the developer's point of view. It opposes the idea of static typing and requires extra runtime support that causes undesired execution overhead. When an explicit type is used, properties cannot be added or deleted.

Currently, only a few projects allow object layout changes at runtime, and some common code linters have added corresponding constraints. Although a small amount of code refactoring is required, the performance improvement benefits are considerable.

### Semantics of Operators Is Restricted

To achieve better performance and encourage developers to write clearer code, ArkTS restricts the semantics of some operators. An example is given below, and the full list of constraints is outlined in [Recipes](#recipes).

**Example**

```typescript
// Unary `+` is defined only for numbers, but not for strings:
let t = +42;   // OK
let s = +'42'; // Compile-time error
```

Loading language operators with extra semantics complicates the language specification, and forces developers to remember all possible corner cases with appropriate handling rules. Besides, in certain cases it causes some undesired runtime overhead.

According to our observations and experiments, this feature is not popular in TypeScript. It is used in less than 1% of real-world codebases, and such cases are easy to refactor. Restricting the operator semantics results in a clearer and more performant at the cost of low-effort changes in code.

### Structural Typing Is Not Supported

Assume that two unrelated classes **T** and **U** have the same **public** API:

```typescript
class T {
  public name: string = ''

  public greet(): void {
    console.info('Hello, ' + this.name);
  }
}

class U {
  public name: string = ''

  public greet(): void {
    console.info('Greetings, ' + this.name);
  }
}
```

Can we assign a value of **T** to a variable of **U**?

```typescript
let u: U = new T(); // Is this allowed?
```

Can we pass a value of **T** to a function that accepts a parameter of **U**?

```typescript
function greeter(u: U) {
  console.info('To ' + u.name);
  u.greet();
}

let t: T = new T();
greeter(t); // Is this allowed?
```

In other words, which approach will we take:

- **T** and **U** are not related by inheritance or any common interface, but they are "somewhat equivalent" since they have the same **public** API, and so the answer to both questions above is "yes".
- **T** and **U** are not related by inheritance or any common interface, and always must be considered as totally different types, and so the answer to both questions above is "no".

The languages that take the first approach are said to support structural typing, whereas the languages that take the second approach do not support it. Currently, TypeScript supports structural typing, and ArkTS does not.

It is debatable whether structural typing helps to produce code that is clearer and more understandable, and both pro and contra arguments can be found. Why not just support it then?

The answer is that supporting structural typing is a major feature that needs a lot of considerations and careful implementation in language specification, compiler, and runtime. More importantly, in case if ArkTS, which enforces static typing (see above), runtime support for structural typing implies performance overhead.

So since functionally correct and performant implementation requires taking that many aspects into account, the support to this feature is postponed. The ArkTS team is ready to reconsider based on real-world scenarios and feedback. More cases and suggested workarounds can be found in [Recipes](#recipes).

## Recipes

### Objects with Property Names That Are Not Identifiers Are Not Supported

**Rule:** arkts-identifiers-as-prop-names

**Severity: error**

**Error code: 10605001**

ArkTS does not support objects with name properties that are numbers or strings. Exceptions are string type enumeration constants and string literal. Use classes to access data by property names. Use arrays to access data by numeric indices.

**TypeScript**

```typescript
var x = { 'name': 'x', 2: '3' };

console.info(x['name']); // x
console.info(x[2]); // 3
```

**ArkTS**

```typescript
class X {
  public name: string = ''
}
let x: X = { name: 'x' };
console.info(x.name); // x

let y = ['a', 'b', 'c'];
console.info(y[2]); // c

// If you still need a container to store keys of different types, use Map<Object, some_type>.
let z = new Map<Object, string>();
z.set('name', '1');
z.set(2, '2');
console.info(z.get('name'));  // 1
console.info(z.get(2)); // 2

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

### Symbol() Is Not Supported

**Rule:** arkts-no-symbol

**Severity: error**

**Error code: 10605002**

ArkTS does not support the **Symbol()** API because its most popular use cases make no sense in the statically typed environment. In particular, the object layout is defined at compile time and cannot be changed at runtime.

Only **Symbol.iterator** is supported.

### Private # Identifiers Are Not Supported

**Rule:** arkts-no-private-identifiers

**Severity: error**

**Error code: 10605003**

ArkTS does not use private identifiers starting with the symbol **#**. Use the keyword **private** instead.

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

### Use Unique Names for Types and Namespaces

**Rule:** arkts-unique-names

**Severity: error**

**Error code: 10605004**

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

### Use let Instead of var

**Rule:** arkts-no-var

**Severity: error**

**Error code: 10605005**

The **let** keyword can declare variables in block scope, helping programmers avoid errors. Therefore, ArkTS does not support **var**. Use **let** instead.

**TypeScript**

```typescript
function f(shouldInitialize: boolean) {
  if (shouldInitialize) {
     var x = 'b';
  }
  return x;
}

console.info(f(true));  // b
console.info(f(false)); // undefined

let upperLet = 0;
{
  var scopedVar = 0;
  let scopedLet = 0;
  upperLet = 5;
}
scopedVar = 5; // Visible
scopedLet = 5; // Compile-time error
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

console.info(f(true));  // b
console.info(f(false)); // a

let upperLet = 0;
let scopedVar = 0;
{
  let scopedLet = 0;
  upperLet = 5;
}
scopedVar = 5;
scopedLet = 5; // Compile-time error
```

### Use Explicit Types Instead of any or unknown

**Rule:** arkts-no-any-unknown

**Severity: error**

**Error code: 10605008**

ArkTS does not support the types **any** and **unknown**. Specify types explicitly.

**TypeScript**

```typescript
let value1: any
value1 = true;
value1 = 42;

let value2: unknown
value2 = true;
value2 = 42;
```

**ArkTS**

```typescript
let value_b: boolean = true; // OR: let value_b = true
let value_n: number = 42; // OR: let value_n = 42
let value_o1: Object = true;
let value_o2: Object = 42;
```

### Use class Instead of a Type with a Call Signature

**Rule:** arkts-no-call-signatures

**Severity: error**

**Error code: 10605014**

ArkTS does not support call signatures in object types. Use **class** instead.

**TypeScript**

```typescript
type DescribableFunction = {
  description: string
  (someArg: string): string // call signature
}

function doSomething(fn: DescribableFunction): void {
  console.info(fn.description + ' returned ' + fn(''));
}
```

**ArkTS**

```typescript
class DescribableFunction {
  description: string
  public invoke(someArg: string): string {
    return someArg;
  }
  constructor() {
    this.description = 'desc';
  }
}

function doSomething(fn: DescribableFunction): void {
  console.info(fn.description + ' returned ' + fn.invoke(''));
}

doSomething(new DescribableFunction());
```

### Use class Instead of a Type with a Constructor Signature

**Rule:** arkts-no-ctor-signatures-type

**Severity: error**

**Error code: 10605015**

ArkTS does not support constructor signatures in object types. Use **class** instead.

**TypeScript**

```typescript
class SomeObject {}

type SomeConstructor = {
  new (s: string): SomeObject
}

function fn(ctor: SomeConstructor) {
  return new ctor('hello');
}
```

**ArkTS**

```typescript
class SomeObject {
  public f: string
  constructor (s: string) {
    this.f = s;
  }
}

function fn(s: string): SomeObject {
  return new SomeObject(s);
}
```

### Only One Static Block Is Supported

**Rule:** arkts-no-multiple-static-blocks

**Severity: error**

**Error code: 10605016**

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

### Indexed Signatures Are Not Supported

**Rule:** arkts-no-indexed-signatures

**Severity: error**

**Error code: 10605017**

ArkTS does not allow indexed signatures. Use arrays instead.

**TypeScript**

```typescript
// Interface with an indexed signature:
interface StringArray {
  [index: number]: string
}

function getStringArray(): StringArray {
  return ['a', 'b', 'c'];
}

const myArray: StringArray = getStringArray();
const secondItem = myArray[1];
```

**ArkTS**

```typescript
class X {
  public f: string[] = []
}

let myArray: X = new X();
const secondItem = myArray.f[1];
```

### Use Inheritance Instead of Intersection Types

**Rule:** arkts-no-intersection-types

**Severity: error**

**Error code: 10605019**

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

### Type Notation Using this Is Not Supported

**Rule:** arkts-no-typing-with-this

**Severity: error**

**Error code: 10605021**

ArkTS does not support type notation using the **this** keyword. Use the explicit type instead.

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
interface testListItem {
  getHead(): testListItem
}

class C {
  n: number = 0

  m(c: C) {
    // ...
  }
}
```

### Conditional Types Are Not Supported

**Rule:** arkts-no-conditional-types

**Severity: error**

**Error code: 10605022**

ArkTS does not support conditional type aliases. Introduce a new type with constraints explicitly, or rewrite logic using **Object**.
The keyword **infer** is not supported.

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

### Declaring Fields in constructor Is Not Supported

**Rule:** arkts-no-ctor-prop-decls

**Severity: error**

**Error code: 10605025**

ArkTS does not support declaring class fields in **constructor**. Declare class fields inside the **class** declaration instead.

**TypeScript**

```typescript
class Person {
  constructor(
    protected ssn: string,
    private firstName: string,
    private lastName: string
  ) {
    this.ssn = ssn;
    this.firstName = firstName;
    this.lastName = lastName;
  }

  getFullName(): string {
    return this.firstName + ' ' + this.lastName;
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
    this.ssn = ssn;
    this.firstName = firstName;
    this.lastName = lastName;
  }

  getFullName(): string {
    return this.firstName + ' ' + this.lastName;
  }
}
```

### Constructor Signatures Are Not Supported in Interfaces

**Rule:** arkts-no-ctor-signatures-iface

**Severity: error**

**Error code: 10605027**

ArkTS does not allow constructor signatures to be defined in interfaces. Use common functions or methods instead.

**TypeScript**

```typescript
interface I {
  new (s: string): I
}

function fn(i: I) {
  return new i('hello');
}
```

**ArkTS**

```typescript
interface I {
  create(s: string): I
}

function fn(i: I) {
  return i.create('hello');
}
```

### Indexed Access Types Are Not Supported

**Rule:** arkts-no-aliases-by-index

**Severity: error**

**Error code: 10605028**

ArkTS does not support indexed access types. Use the type name instead.

### Indexed Access Is Not Supported for Fields

**Rule:** arkts-no-props-by-index

**Severity: error**

**Error code: 10605029**

ArkTS does not support dynamic field declaration and access. Access only those class fields that are either declared in the class, or accessible via inheritance. Accessing any other fields is prohibited, and causes compile-time errors.
To access a field, use the **obj.field** syntax. Indexed access (**obj['field']**) is not supported.
An exception is all typed arrays from the standard library (for example, **Int32Array**), which support access to their elements through the **container[index]** syntax.

**TypeScript**

```typescript
class Point {
  x: string = ''
  y: string = ''
}
let p: Point = {x: '1', y: '2'};
console.info(p['x']); // 1

class Person {
  name: string = ''
  age: number = 0;
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
let p: Point = {x: '1', y: '2'};
console.info(p.x); // 1

class Person {
  name: string
  age: number
  email: string
  phoneNumber: string

  constructor(name: string, age: number, email: string,
        phoneNumber: string) {
    this.name = name;
    this.age = age;
    this.email = email;
    this.phoneNumber = phoneNumber;
  }
}

let person = new Person('John', 30, '***@example.com', '18*********');
console.info(person['name']);     // Compile-time error
console.info(person.unknownProperty); // Compile-time error

let arr = new Int32Array(1);
arr[0];
```

### Structural Typing Is Not Supported

**Rule:** arkts-no-structural-typing

**Severity: error**

**Error code: 10605030**

Currently, ArkTS does not support structural typing. This means that the compiler cannot compare **public** APIs of two types and decide whether they are identical. Use other mechanisms (inheritance, interfaces, or type aliases) instead.

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

let x = new X();
let y = new Y();

// Assign the X object to the Y object.
y = x;

// Assign the Y object to the X object.
x = y;

function foo(x: X) {
  console.info(x.n + x.s);
}

// X and Y are equivalent because their public API is equivalent.
foo(new X());
foo(new Y());
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

let b = new B();
let d = new D();

console.info('Assign D to B');
b = d; // OK. B is the superclass of D.

// An attempt to assign b to d will result in a compile-time error.
// d = b

interface Z {
   n: number
   s: string
}

// X implements interface Z, which makes relationship between X and Y explicit.
class X implements Z {
  n: number = 0
  s: string = ''
}

// Y implements interface Z, which makes relationship between X and Y explicit.
class Y implements Z {
  n: number = 0
  s: string = ''
}

let x: Z = new X();
let y: Z = new Y();

console.info('Assign X to Y');
y = x // OK, both are of the same type

console.info('Assign Y to X');
x = y // OK, both are of the same type

function foo(c: Z): void {
  console.info(c.n + c.s);
}

// X and Y implement the same interface. Therefore both calls are allowed.
foo(new X());
foo(new Y());
```

### Type Inference in Case of Generic Function Calls Is Limited

**Rule: **arkts-no-inferred-generic-params

**Severity: error**

**Error code: 10605034**

ArkTS allows to omit generic type parameters if it is possible to infer the concrete types from the parameters passed to the function. A compile-time error occurs otherwise. 
In particular, inference of generic type parameters based only on function return types is prohibited.

**TypeScript**

```typescript
function choose<T>(x: T, y: T): T {
  return Math.random() < 0.5 ? x: y;
}

let x = choose(10, 20);   // OK. choose<number>(...) is inferred.
let y = choose('10', 20); // Compile-time error

function greet<T>(): T {
  return 'Hello' as T;
}
let z = greet() // Type of T is inferred as "unknown".
```

**ArkTS**

```typescript
function choose<T>(x: T, y: T): T {
  return Math.random() < 0.5 ? x: y;
}

let x = choose(10, 20);   // OK. choose<number>(...) is inferred.
let y = choose('10', 20); // Compile-time error

function greet<T>(): T {
  return 'Hello' as T;
}
let z = greet<string>();
```

### Object Literal Must Correspond to Some Explicitly Declared Class or Interface

**Rule:** arkts-no-untyped-obj-literals

**Severity: error**

**Error code: 10605038**

ArkTS supports usage of object literals if the compiler can infer to the classes or interfaces that such literals correspond to. Otherwise, a compile-time error occurs. In some scenarios, the compiler can infer the type of the literal based on the context.

Using literals to initialize classes and interfaces is specifically not supported in the following contexts:

* Initialization of anything that has **any**, **Object**, or **object** type
* Initialization of classes or interfaces with methods
* Initialize a class that contains a custom **constructor** with parameters.
* Initialization of classes with **readonly** fields

**Example 1**

**TypeScript**

```typescript
let o1 = {n: 42, s: 'foo'};
let o2: Object = {n: 42, s: 'foo'};
let o3: object = {n: 42, s: 'foo'};

let oo: Object[] = [{n: 1, s: '1'}, {n: 2, s: '2'}];
```

**ArkTS**

```typescript
class C1 {
  n: number = 0
  s: string = ''
}

let o1: C1 = {n: 42, s: 'foo'};
let o2: C1 = {n: 42, s: 'foo'};
let o3: C1 = {n: 42, s: 'foo'};

let oo: C1[] = [{n: 1, s: '1'}, {n: 2, s: '2'}];
```

**Example 2**

**TypeScript**

```typescript
class C2 {
  s: string
  constructor(s: string) {
    this.s = 's =' + s;
  }
}
let o4: C2 = {s: 'foo'};
```

**ArkTS**

```typescript
class C2 {
  s: string
  constructor(s: string) {
    this.s = 's =' + s;
  }
}
let o4 = new C2('foo');
```

**Example 3**

**TypeScript**

```typescript
class C3 {
  readonly n: number = 0
  readonly s: string = ''
}
let o5: C3 = {n: 42, s: 'foo'};
```

**ArkTS**

```typescript
class C3 {
  n: number = 0
  s: string = ''
}
let o5: C3 = {n: 42, s: 'foo'};
```

**Example 4**

**TypeScript**

```typescript
abstract class A {}
let o6: A = {};
```

**ArkTS**

```typescript
abstract class A {}
class C extends A {}
let o6: C = {}; // Or let o6: C = new C()
```

**Example 5**

**TypeScript**

```typescript
class C4 {
  n: number = 0
  s: string = ''
  f() {
    console.info('Hello');
  }
}
let o7: C4 = {n: 42, s: 'foo', f: () => {}};
```

**ArkTS**

```typescript
class C4 {
  n: number = 0
  s: string = ''
  f() {
    console.info('Hello');
  }
}
let o7 = new C4();
o7.n = 42;
o7.s = 'foo';
```

**Example 6**

**TypeScript**

```typescript
class Point {
  x: number = 0
  y: number = 0
}

function getPoint(o: Point): Point {
  return o;
}

// Structural typing is used to deduce that p is Point.
let p = {x: 5, y: 10};
getPoint(p);

// A literal can be contextually (i.e., implicitly) typed as Point.
getPoint({x: 5, y: 10});
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
  return o;
}

// Explicit type is required for literal initialization.
let p: Point = {x: 5, y: 10};
getPoint(p);

// getPoint expects Point explicitly. A new instance of Point is initialized with the literal.
getPoint({x: 5, y: 10});
```

### Object Literals Cannot Be Used as Type Declarations

**Rule:** arkts-no-obj-literals-as-types

**Severity: error**

**Error code: 10605040**

ArkTS does not support the usage of object literals to declare types in place. Use classes or interfaces to declare types instead.

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

let o: O = {x: 2, y: 3};

type S = Set<O>
```

### Array Literals Must Contain Elements of Only Inferrable Types

**Rule:** arkts-no-noninferrable-arr-literals

**Severity: error**

**Error code: 10605043**

Basically, ArkTS infers the type of an array literal as a union type of its contents. However, a compile-time error occurs if there is at least one element with a non-inferrable type (for example, untyped object literal).

**TypeScript**

```typescript
let a = [{n: 1, s: '1'}, {n: 2, s: '2'}];
```

**ArkTS**

```typescript
class C {
  n: number = 0
  s: string = ''
}

let a1 = [{n: 1, s: '1'} as C, {n: 2, s: '2'} as C]; // a1 is of type "C[]"
let a2: C[] = [{n: 1, s: '1'}, {n: 2, s: '2'}];    // a2 is of type "C[]"
```

### Use Arrow Functions Instead of Function Expressions

**Rule:** arkts-no-func-expressions

**Severity: error**

**Error code: 10605046**

ArkTS does not support function expressions. Use arrow functions instead to specify explicitly.

**TypeScript**

```typescript
let f = function (s: string) {
  console.info(s);
}
```

**ArkTS**

```typescript
let f = (s: string) => {
  console.info(s);
}
```

### Class Literals Are Not Supported

**Rule:** arkts-no-class-literals

**Severity: error**

**Error code: 10605050**

ArkTS does not support class literals. Introduce new named class types explicitly.

**TypeScript**

```typescript
const Rectangle = class {
  constructor(height: number, width: number) {
    this.height = height;
    this.width = width;
  }

  height;
  width;
}

const rectangle = new Rectangle(0.0, 0.0);
```

**ArkTS**

```typescript
class testRectangle {
  constructor(testHeight: number, testWidth: number) {
    this.testHeight = testHeight;
    this.testWidth = testWidth;
  }

  testHeight: number;
  testWidth: number;
}

const rectangle = new testRectangle(0.0, 0.0);
```

### Classes Cannot Be Specified in the implements Clause

**Rule:** arkts-implements-only-iface

**Severity: error**

**Error code: 10605051**

ArkTS does not allow to specify a class in the **implements** clause. Only interfaces may be specified.

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

### Reassigning Object Methods Is Not Supported

**Rule:** arkts-no-method-reassignment

**Severity: error**

**Error code: 10605052**

ArkTS does not support reassigning a method for objects. In the statically typed languages, the layout of objects is fixed and all instances of the same object must share the same code of each method.
If you need to add specific behavior for certain objects, you can create separate wrapper functions or use inheritance.

**TypeScript**

```typescript
class C {
  foo() {
    console.info('foo');
  }
}

function bar() {
  console.info('bar');
}

let c1 = new C();
let c2 = new C();
c2.foo = bar;

c1.foo(); // foo
c2.foo(); // bar
```

**ArkTS**

```typescript
class C {
  foo() {
    console.info('foo');
  }
}

class Derived extends C {
  foo() {
    console.info('Extra');
    super.foo();
  }
}

function bar() {
  console.info('bar');
}

let c1 = new C();
let c2 = new C();
c1.foo(); // foo
c2.foo(); // foo

let c3 = new Derived();
c3.foo(); // Extra foo
```

### Only the as T Syntax Is Supported for Type Casting

**Rule:** arkts-as-casts

**Severity: error**

**Error code: 10605053**

ArkTS supports the keyword **as** as the only syntax for type casting. Incorrect casting causes a compile-time error or runtime **ClassCastException**. The **\<type>** syntax for type casting is not supported.

Use the expression **new** instead of **as** if a **primitive** type (such as a **number** or a **boolean**) must be cast to the reference type.

**TypeScript**

```typescript
class testShape {}
class testCircle extends testShape { x: number = 5 }
class testSquare extends testShape { y: string = 'a' }

function createShape(): Shape {
  return new Circle();
}

let c1 = <Circle> createShape();

let c2 = createShape() as Circle;

// No report is provided during compilation or runtime if casting is wrong.
let c3 = createShape() as Square;
console.info(c3.y); // undefined

// Important corner case for casting primitives to the boxed counterparts: The left operand is not properly boxed here in runtime because "as" has no runtime effect in TypeScript.
let e1 = (5.0 as Number) instanceof Number; // false

// A Number object is created and instanceof works as expected.
let e2 = (new Number(5.0)) instanceof Number; // true
```

**ArkTS**

```typescript
class testShape {}
class testCircle extends testShape { x: number = 5 }

function createShape(): testShape {
  return new Circle();
}

let c2 = createShape() as testCircle;

// A Number object is created and instanceof works as expected.
let e2 = (new Number(5.0)) instanceof Number; // true
```

### JSX Expressions Are Not Supported

**Rule:** arkts-no-jsx

**Severity: error**

**Error code: 10605054**

Do not use JSX since no alternative is provided to rewrite it.

### Unary Operators +, -, and ~ Work Only on Numbers

**Rule:** arkts-no-polymorphic-unops

**Severity: error**

**Error code: 10605055**

ArkTS allows unary operators to work on numeric types only. A compile-time error occurs if these operators are applied to a non-numeric type. Unlike in TypeScript, implicit casting of strings in this context is not supported and casting must be done explicitly.

**TypeScript**

```typescript
let a = +5;    // 5 as number
let b = +'5';    // 5 as number
let c = -5;    // -5 as number
let d = -'5';    // -5 as number
let e = ~5;    // -6 as number
let f = ~'5';    // -6 as number
let g = +'string'; // NaN as number

function returnTen(): string {
  return '-10';
}

function returnString(): string {
  return 'string';
}

let x = +returnTen();  // -10 as number
let y = +returnString(); // NaN
```

**ArkTS**

```typescript
let a = +5;    // 5 as number
let b = +'5';    // Compile-time error
let c = -5;    // -5 as number
let d = -'5';    // Compile-time error
let e = ~5;    // -6 as number
let f = ~'5';    // Compile-time error
let g = +'string'; // Compile-time error

function returnTen(): string {
  return '-10';
}

function returnString(): string {
  return 'string';
}

let x = +returnTen();  // Compile-time error
let y = +returnString(); // Compile-time error
```

### delete Operator Is Not Supported

**Rule:** arkts-no-delete

**Severity: error**

**Error code: 10605059**

ArkTS assumes that object layout is known at compile time and cannot be changed at runtime. Therefore, the operation of deleting a property makes no sense.

**TypeScript**

```typescript
class Point {
  x?: number = 0.0
  y?: number = 0.0
}

let p = new Point();
delete p.y;
```

**ArkTS**

```typescript
// To mimic the original semantics, you may declare a nullable type and assign null to mark the value absence.
class Point {
  x: number | null = 0
  y: number | null = 0
}

let p = new Point();
p.y = null;
```

### typeof Operator Is Allowed Only in Expression Contexts

**Rule:** arkts-no-type-query

**Severity: error**

**Error code: 10605060**

ArkTS supports the **typeof** operator only in the expression context. Using **typeof** to specify type notations is not supported.

**TypeScript**

```typescript
let n1 = 42;
let s1 = 'foo';
console.info(typeof n1); // 'number'
console.info(typeof s1); // 'string'
let n2: typeof n1
let s2: typeof s1
```

**ArkTS**

```typescript
let n1 = 42;
let s1 = 'foo';
console.info(typeof n1); // 'number'
console.info(typeof s1); // 'string'
let n2: number
let s2: string
```

### instanceof Operator Is Partially Supported

**Rule:** arkts-instanceof-ref-types

**Severity: error**

**Error code: 10605065**

In TypeScript, the left-hand side of an **instanceof** expression must be of the type **any**, an object type, or a type parameter. Otherwise, the result is **false**. In ArkTS, the left-hand side of an expression may be of any reference type, for example, an object, an array, or a function. Otherwise, a compile-time error occurs. In addition, the left operand in ArkTS cannot be a type. It must be an object instance.

**TypeScript**

```typescript
let num: number = 42;
let result = num instanceof Number;
console.info('result = ', result); // result = false
```

**ArkTS**

```typescript
let num: number = 42;
let result = num instanceof Number; // Compile-time error
```

### in Operator Is Not Supported

**Rule:** arkts-no-in

**Severity: error**

**Error code: 10605066**

ArkTS does not support the operator **in**. This operator makes little sense since the object layout is known at compile time and cannot be changed at runtime. Use **instanceof** as a workaround if you want to check whether certain class members exist.

**TypeScript**

```typescript
class Person {
  name: string = ''
}
let p = new Person();

let b = 'name' in p; // true
```

**ArkTS**

```typescript
class Person {
  name: string = ''
}
let p = new Person();

let b = p instanceof Person; // True. "name" is guaranteed to be present.
```

### Destructuring Assignment Is Not Supported

**Rule:** arkts-no-destruct-assignment

**Severity: error**

**Error code: 10605069**

ArkTS does not support destructuring assignment. Use other idioms (for example, a temporary variable, where applicable) instead.

**TypeScript**

```typescript
let [one, two] = [1, 2]; // Semicolon is required here.
[one, two] = [two, one];

let head, tail
[head, ...tail] = [1, 2, 3, 4];
```

**ArkTS**

```typescript
let arr: number[] = [1, 2];
let one = arr[0];
let two = arr[1];

let tmp = one;
one = two;
two = tmp;

let data: Number[] = [1, 2, 3, 4];
let head = data[0];
let tail: Number[] = [];
for (let i = 1; i < data.length; ++i) {
  tail.push(data[i]);
}
```

### Comma Operator Is Supported Only in for Loops

**Rule:** arkts-no-comma-outside-loops

**Severity: error**

**Error code: 10605071**

ArkTS supports the comma operator (,) only in **for** loops. In other cases, the comma operator is useless as it makes the execution order harder to understand.
>**NOTE**<br>This is different from the comma separator used to declare variables and pass function parameters.

**TypeScript**

```typescript
for (let i = 0, j = 0; i < 10; ++i, j += 2) {
  // ...
}

let x = 0;
x = (++x, x++); // 1
```

**ArkTS**

```typescript
for (let i = 0, j = 0; i < 10; ++i, j += 2) {
  // ...
}

// Use the explicit execution order instead of the comma operator.
let x = 0;
++x;
x = x++;
```

### Destructuring Variable Declarations Are Not Supported

**Rule:** arkts-no-destruct-decls

**Severity: error**

**Error code: 10605074**

ArkTS does not support destructuring variable declarations. This is a dynamic feature relying on structural compatibility. In addition, names in destructuring declarations must be equal to properties within destructed classes.

**TypeScript**

```typescript
class Point {
  x: number = 0.0
  y: number = 0.0
}

function returnZeroPoint(): Point {
  return new Point();
}

let {x, y} = returnZeroPoint();
```

**ArkTS**

```typescript
class Point {
  x: number = 0.0
  y: number = 0.0
}

function returnZeroPoint(): Point {
  return new Point();
}

// Create an intermediate object and work with it field by field without name restrictions.
let zp = returnZeroPoint();
let x = zp.x;
let y = zp.y;
```

### Type Annotation in the Catch Clause Is Not Supported

**Rule:** arkts-no-types-in-catch

**Severity: error**

**Error code: 10605079**

In TypeScript, the catch clause variable type annotation must be **any** or **unknown** if specified. As ArkTS does not support these types, omit type annotations.

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

### for .. in Is Not Supported

**Rule:** arkts-no-for-in

**Severity: error**

**Error code: 10605080**

ArkTS does not support iteration over object contents by the **for .. in** loop. For objects, iteration over properties at runtime is considered redundant because object layout is known at compile time and cannot change at runtime.

**TypeScript**

```typescript
let a: string[] = ['1.0', '2.0', '3.0'];
for (let i in a) {
  console.info(a[i]);
}
```

**ArkTS**

```typescript
let a: string[] = ['1.0', '2.0', '3.0'];
for (let i = 0; i < a.length; ++i) {
  console.info(a[i]);
}
```

### Mapped Type Expression Is Not Supported

**Rule:** arkts-no-mapped-types

**Severity: error**

**Error code: 10605083**

ArkTS does not support mapped types. Use other language idioms and regular classes to achieve the same behavior.

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

### with Statement Is Not Supported

**Rule:** arkts-no-with

**Severity: error**

**Error code: 10605084**

ArkTS does not support the **with** statement. Use other language idioms to achieve the same behavior.

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

### throw Statements Do Not Accept Values of Arbitrary Types

**Rule:** arkts-limited-throw

**Severity: error**

**Error code: 10605087**

ArkTS supports throwing only objects of the class **Error** or any derived class. Throwing an arbitrary type (for example, **number** or **string**) is prohibited.

**TypeScript**

```typescript
throw 4;
throw '';
throw new Error();
```

**ArkTS**

```typescript
throw new Error();
```

### Function Return Type Inference Is Limited

**Rule:** arkts-no-implicit-return-types

**Severity: error**

**Error code: 10605090**

ArkTS supports type inference for function return types, but this functionality is currently restricted. In particular, when the expression in the **return** statement is a call to a function or method whose return value type is omitted, a compile-time error occurs. If this is the case, specify the return type explicitly.

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

// Return type may be omitted.
function doOperation(x: number, y: number) {
  return x + y;
}

f(10);
doOperation(2, 3);
```

### Destructuring Parameter Declarations Are Not Supported

**Rule:** arkts-no-destruct-params

**Severity: error**

**Error code: 10605091**

ArkTS requires that arguments be explicitly passed to function parameters without destructing.

**TypeScript**

```typescript
function drawText({ text = '', location: [x, y] = [0, 0], bold = false }) {
  text;
  x;
  y;
  bold;
}

drawText({ text: 'Hello, world!', location: [100, 50], bold: true });
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

### Nested Functions Are Not Supported

**Rule:** arkts-no-nested-funcs

**Severity: error**

**Error code: 10605092**

ArkTS does not support nested functions. Use lambdas instead.

**TypeScript**

```typescript
function addNum(a: number, b: number): void {

  // Nested function
  function logToConsole(message: string): void {
    console.info(message);
  }

  let result = a + b;

  // Invoke the nested function.
  logToConsole('result is ' + result);
}
```

**ArkTS**

```typescript
function addNum(a: number, b: number): void {
  // Use lambda instead of a nested function.
  let logToConsole: (message: string) => void = (message: string): void => {
    console.info(message);
  }

  let result = a + b;

  logToConsole('result is ' + result);
}
```

### Using this Inside Stand-Alone Functions Is Not Supported

**Rule:** arkts-no-standalone-this

**Severity: error**

**Error code: 10605093**

ArkTS does not support the usage of **this** inside stand-alone functions and inside static methods. **this** can be used in instance methods only.

**TypeScript**

```typescript
function foo(i: string) {
  this.count = i; // Compile-time error only when noImplicitThis is enabled.
}

class A {
  count: string = 'a'
  m = foo
}

let a = new A();
console.info(a.count); // Print "a".
a.m('b');
console.info(a.count); // Print "b".
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
  console.info(a.count);  // Print "a".
  a.m('b');
  console.info(a.count);  // Print "b".
}
```

### Generator Functions Are Not Supported

**Rule:** arkts-no-generators

**Severity: error**

**Error code: 10605094**

Currently, ArkTS does not support generator functions. Use the **async** or **await** mechanism for multitasking.

**TypeScript**

```typescript
function* counter(start: number, end: number) {
  for (let i = start; i <= end; i++) {
    yield i;
  }
}

for (let num of counter(1, 5)) {
  console.info(num.toString());
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

### Type Guarding Is Supported with instanceof and as

**Rule:** arkts-no-is

**Severity: error**

**Error code: 10605096**

ArkTS does not support the **is** operator, which must be replaced by the **instanceof** operator. Note that the fields of an object must be cast to the appropriate type with the **as** operator before **instanceof** is used.

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
  return arg.foo !== undefined;
}

function doStuff(arg: Foo | Bar) {
  if (isFoo(arg)) {
    console.info(arg.foo);  // OK
    console.info(arg.bar);  // Compile-time error
  } else {
    console.info(arg.foo);  // Compile-time error
    console.info(arg.bar);  // OK
  }
}

doStuff({ foo: '123', common: '123' });
doStuff({ bar: '123', common: '123' });
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
  return arg instanceof Foo;
}

function doStuff(arg: Object): void {
  if (isFoo(arg)) {
    let fooArg = arg as Foo;
    console.info(fooArg.foo);   // OK
    console.info(arg.bar);    // Compile-time error
  } else {
    let barArg = arg as Bar;
    console.info(arg.foo);    // Compile-time error
    console.info(barArg.bar);   // OK
  }
}

function main(): void {
  doStuff(new Foo());
  doStuff(new Bar());
}
```

### Spread Operator Is Supported in Partial Scenarios

**Rule:** arkts-no-spread

**Severity: error**

**Error code: 10605099**

The only supported scenario for the spread operator is to spread an array, a child class of an array, or a typed array (for example, **Int32Array**). A spread operator can be used only in the following scenarios:
1. Being passed to the rest parameter;
2. Copying an array to an array literal.

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

### Interface Cannot Extend Interfaces with the Same Method

**Rule:** arkts-no-extend-same-prop

**Severity: error**

**Error code: 106050102**

In TypeScript, an interface that extends two other interfaces with the same method must declare that method with a combined return type. It is not allowed in ArkTS because ArkTS does not allow an interface to contain two methods with signatures that are not distinguishable, for example, two methods that have the same parameter lists but different return types.

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
    return { speed: this.speed, frequency: this.frequency };
  }
}
```

**ArkTS**

```typescript
class MoveStatus {
  public speed: number
  constructor() {
    this.speed = 0;
  }
}
interface Mover {
  getMoveStatus(): MoveStatus
}

class ShakeStatus {
  public frequency: number
  constructor() {
    this.frequency = 0;
  }
}
interface Shaker {
  getShakeStatus(): ShakeStatus
}

class MoveAndShakeStatus {
  public speed: number
  public frequency: number
  constructor() {
    this.speed = 0;
    this.frequency = 0;
  }
}

class C implements Mover, Shaker {
  private move_status: MoveStatus
  private shake_status: ShakeStatus

  constructor() {
    this.move_status = new MoveStatus();
    this.shake_status = new ShakeStatus();
  }

  public getMoveStatus(): MoveStatus {
    return this.move_status;
  }

  public getShakeStatus(): ShakeStatus {
    return this.shake_status;
  }

  public getStatus(): MoveAndShakeStatus {
    return {
      speed: this.move_status.speed,
      frequency: this.shake_status.frequency
    };
  }
}
```

### Declaration Merging Is Not Supported

**Rule:** arkts-no-decl-merging

**Severity: error**

**Error code: 10605103**

ArkTS does not support merging declarations. Keep all definitions of classes and interfaces compact in the codebase.

**TypeScript**

```typescript
interface Document {
  createElement(tagName: any): number;
}

interface Document {
  createElement(tagName: string): boolean;
}

interface Document {
  createElement(tagName: number): number;
  createElement(tagName: boolean): boolean;
  createElement(tagName: string, value: number): string;
}
```

**ArkTS**

```typescript
interface Document {
  createElement(tagName: number): number;
  createElement(tagName: boolean): boolean;
  createElement(tagName: string, value: number): number;
  createElement(tagName: string): string;
  createElement(tagName: Object): object;
}
```

### Interfaces Cannot Extend Classes

**Rule:** arkts-extends-only-class

**Severity: error**

**Error code: 10605104**

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

### Constructor Function Type Is Not Supported

**Rule:** arkts-no-ctor-signatures-funcs

**Severity: error**

**Error code: 10605106**

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
  return new Ctor(name, age);
}

const person = createPerson(Person, 'John', 30);
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
  return Ctor(n, a);
}

let Impersonizer: PersonCtor = (n: string, a: number): Person => {
  return new Person(n, a);
}

const person = createPerson(Impersonizer, 'John', 30);
```

### Enumeration Members Can Be Initialized Only with Compile Time Expressions of the Same Type

**Rule:** arkts-no-enum-mixed-types

**Severity: error**

**Error code: 10605111**

ArkTS does not support initializing members of enumerations with expressions that are evaluated during program runtime. Besides, all explicitly set initializers must be of the same type.

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

### enum Declaration Merging Is Not Supported

**Rule:** arkts-no-enum-merging

**Severity: error**

**Error code: 10605113**

ArkTS does not support merging declarations for **enum**. Keep the declaration of each **enum** compact in the codebase.

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

### Namespaces Cannot Be Used as Objects

**Rule:** arkts-no-ns-as-obj

**Severity: error**

**Error code: 10605114**

ArkTS does not support the usage of namespaces as objects. Classes or modules can be interpreted as analogs of namespaces.

**TypeScript**

```typescript
namespace MyNamespace {
  export let x: number
}

let m = MyNamespace;
m.x = 2;
```

**ArkTS**

```typescript
namespace MyNamespace {
  export let x: number
}

MyNamespace.x = 2;
```

### Non-declaration Statements in Namespaces Are Not Supported

**Rule:** arkts-no-ns-statements

**Severity: error**

**Error code: 10605116**

In ArkTS, namespaces are used to define the visibility scope of identifiers. Namespaces are valid only during compilation. Therefore, non-declaration statements are not supported in namespaces. Use a function to execute non-declaration statements.

**TypeScript**

```typescript
namespace A {
  export let x: number
  x = 1;
}
```

**ArkTS**

```typescript
namespace A {
  export let x: number

  export function init() {
    x = 1;
  }
}

// Initialization function should be called to execute statements.
A.init();
```

### require and import Assignment Are Not Supported

**Rule:** arkts-no-require

**Severity: error**

**Error code: 10605121**

ArkTS does not support importing via **require**. It does not support **import** assignments either. Use the regular **import** syntax instead.

**TypeScript**

```typescript
import m = require('mod')
```

**ArkTS**

```typescript
import * as m from 'mod'
```

### export = ... Is Not Supported

**Rule:** arkts-no-export-assignment

**Severity: error**

**Error code: 10605126**

ArkTS does not support the **export = ...** syntax. Use the ordinary **export** and **import** syntaxes instead.

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

let p = Pt.Point.origin;
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

### Ambient Module Declaration Is Not Supported

**Rule:** arkts-no-ambient-decls

**Severity: error**

**Error code: 10605128**

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
import { normalize } from 'someModule'
```

### Wildcards in Module Names Are Not Supported

**Rule:** arkts-no-module-wildcards

**Severity: error**

**Error code: 10605129**

ArkTS does not support wildcards in module names, because import is a compile-time feature in ArkTS, not a runtime feature.

**TypeScript**

```typescript
// Declaration
declare module '*!text' {
  const content: string
  export default content
}

// Consuming code
import fileContent from 'some.txt!text'
```

**ArkTS**

```typescript
// Declaration
declare namespace N {
  function foo(x: number): number
}

// Consuming code
import * as m from 'module'
console.info('N.foo called: ' + N.foo(42));
```

### UMD Is Not Supported

**Rule:** arkts-no-umd

**Severity: error**

**Error code: 10605130**

ArkTS does not support universal module definitions (UMD), because it does not have the concept of "script" (as opposed to "module"). In addition, import is a compile-time feature in ArkTS, not a runtime feature. Use the ordinary **export** and **import** syntaxes instead.

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
import { mathLib } from 'math-lib'
mathLib.isPrime(2)
```

### new.target Is Not Supported

**Rule:** arkts-no-new-target

**Severity: error**

**Error code: 10605132**

ArkTS does not support **new.target**, because there is no concept of runtime prototype inheritance in the language. This feature is considered not applicable to static typing.

### Definite Assignment Assertions Are Not Supported

**Rule:** arkts-no-definite-assignment

**Severity: warning**

**Error code: 10605134**

ArkTS does not support definite assignment assertions **let v!: T** because they are considered an excessive compiler hint. Use declarations with initialization instead.

**TypeScript**

```typescript
let x!: number // Hint: x will be initialized before usage.

initialize();

function initialize() {
  x = 10;
}

console.info('x = ' + x);
```

**ArkTS**

```typescript
function initialize(): number {
  return 10;
}

let x: number = initialize();

console.info('x = ' + x);
```

### Prototype Assignment Is Not Supported

**Rule:** arkts-no-prototype-assignment

**Severity: error**

**Error code: 10605136**

ArkTS does not support prototype assignment because there is no concept of runtime prototype inheritance in the language. This feature is considered not applicable to static typing.

**TypeScript**

```typescript
let C = function(p) {
  this.p = p; // Compile-time error only when noImplicitThis is enabled
}

C.prototype = {
  m() {
    console.info(this.p);
  }
}

C.prototype.q = function(r: string) {
  return this.p == r;
}
```

**ArkTS**

```typescript
class C {
  p: string = ''
  m() {
    console.info(this.p);
  }
  q(r: string) {
    return this.p === r;
  }
}
```

### globalThis Is Not Supported

**Rule:** arkts-no-globalthis

**Severity: warning**

**Error code: 10605137**

ArkTS does not support dynamic changes to the layout of objects. Therefore, **global scope** and **globalThis** are not supported.

**TypeScript**

```typescript
// In a global file:
var abc = 100;

// Reference 'abc' from the code above.
let x = globalThis.abc;
```

**ArkTS**

```typescript
// file1
export let abc: number = 100;

// file2
import * as M from 'file1'

let x = M.abc;
```

### Some Utility Types Are Not Supported

**Rule:** arkts-no-utility-types

**Severity: error**

**Error code: 10605138**

ArkTS supports only **Partial**, **Required**, **Readonly**, and **Record**, and does not support other utility types in TypeScript.

For the **Partial\<T>** type, the generic parameter **T** must be a class or interface type.

For objects of the **Record** type, the type of the value accessed using an index is a union type that contains **undefined**.

### Declaring Properties on Functions Is Not Supported

**Rule:** arkts-no-func-props

**Severity: error**

**Error code: 10605139**

ArkTS does not support dynamic change of function object layout. Therefore, declaring properties on functions is not supported.

### Function.apply and Function.call Are Not Supported

**Rule:** arkts-no-func-apply-call

**Severity: error**

**Error code: 10605152**

ArkTS does not support **Function.apply** or **Function.call** because these APIs are needed in the standard library to explicitly set the parameter **this** for the called function. In ArkTS, the semantics of **this** is restricted to the conventional OOP style, and the usage of **this** in function body is prohibited.

### Function.bind Is Not Supported

**Rule:** arkts-no-func-bind

**Severity: warning**

**Error code: 10605140**

ArkTS does not support **Function.bind**. These APIs are needed in the standard library to explicitly set the parameter **this** for the called function. In ArkTS, the semantics of **this** is restricted to the conventional OOP style, and the usage of **this** in function body is prohibited.


### as const Assertions Are Not Supported

**Rule:** arkts-no-as-const

**Severity: error**

**Error code: 10605142**

ArkTS does not support **as const** assertions and literal types. In standard TypeScript, **as const** is used to mark literal types.

**TypeScript**

```typescript
// Type 'hello'
let x = 'hello' as const;

// Type 'readonly [10, 20]'
let y = [10, 20] as const;

// Type '{ readonly text: 'hello' }'
let z = { text: 'hello' } as const;
```

**ArkTS**

```typescript
// Type 'string'
let x: string = 'hello';

// Type 'number[]'
let y: number[] = [10, 20];

class Label {
  text: string = ''
}

// Type 'Label'
let z: Label = {
  text: 'hello'
}
```

### Import Assertions Are Not Supported

**Rule:** arkts-no-import-assertions

**Severity: error**

**Error code: 10605143**

ArkTS does not support import assertions because import is a compile-time feature in ArkTS, not a runtime feature. So asserting the correctness of imported APIs in runtime does not make sense for the statically typed language. Use the ordinary **import** syntax instead.

**TypeScript**

```typescript
import { obj } from 'something.json' assert { type: 'json' }
```

**ArkTS**

```typescript
// The correctness of importing T will be checked at compile time.
import { something } from 'module'
```

### Usage of Standard Libraries Is Restricted

**Rule:** arkts-limited-stdlib

**Severity: error**

**Error code: 10605144**

ArkTS does not support certain APIs in the TypeScript and JavaScript standard libraries. Most of these restricted APIs are used to manipulate objects in a dynamic manner, which is not compatible with static typing. The usage of the following APIs is prohibited:

Properties and functions of the global object: **eval**

**Object**: **__proto__**, **__defineGetter__**, **__defineSetter__**,
**__lookupGetter__**, **__lookupSetter__**, **assign**, **create**,
**defineProperties**, **defineProperty**, **freeze**,
**fromEntries**, **getOwnPropertyDescriptor**, **getOwnPropertyDescriptors**,
**getOwnPropertySymbols**, **getPrototypeOf**,
**hasOwnProperty**, **is**, **isExtensible**, **isFrozen**,
**isPrototypeOf**, **isSealed**, **preventExtensions**,
**propertyIsEnumerable**, **seal**, **setPrototypeOf**

**Reflect**: **apply**, **construct**, **defineProperty**, **deleteProperty**,
**getOwnPropertyDescriptor**, **getPrototypeOf**,
**isExtensible**, **preventExtensions**,
**setPrototypeOf**

**Proxy**: **handler.apply()**, **handler.construct()**,
**handler.defineProperty()**, **handler.deleteProperty()**, **handler.get()**,
**handler.getOwnPropertyDescriptor()**, **handler.getPrototypeOf()**,
**handler.has()**, **handler.isExtensible()**, **handler.ownKeys()**,
**handler.preventExtensions()**, **handler.set()**, **handler.setPrototypeOf()**

### Strict Type Checking Is Enforced

**Rule:** arkts-strict-typing

**Severity: error**

**Error code: 10605145**

During compilation, the TypeScript strict mode is used to check the following types:
**noImplicitReturns**,
**strictFunctionTypes**,
**strictNullChecks**,
**strictPropertyInitialization**.

**TypeScript**

```typescript
// Compile-time error only when noImplicitReturns is enabled.
function foo(s: string): string {
  if (s != '') {
    console.info(s);
    return s;
  } else {
    console.info(s);
  }
}

let n: number = null; // Compile-time error only when strictNullChecks is enabled.
```

**ArkTS**

```typescript
function foo(s: string): string {
  console.info(s);
  return s;
}

let n1: number | null = null;
let n2: number = 0;
```

If you cannot initialize an instance property by declaration or in a constructor when defining a class, you can use the definite assignment assertion operator (!) to clear the **strictPropertyInitialization** error.

However, the use of the definite assignment assertion operator (!) increases the risk of code errors. Therefore, you must ensure that the instance property has been assigned a value before being used. Otherwise, the runtime exceptions may occur.

In addition, the use of the definite assignment assertion operator (!) requires a runtime type check, resulting in additional runtime overhead. Therefore, use it only when necessary.

It also generates the error **warning: arkts-no-definite-assignment** at the compile time.

**TypeScript**

```typescript
class C {
  name: string  // Compile-time error only when strictPropertyInitialization is enabled.
  age: number   // Compile-time error only when strictPropertyInitialization is enabled.
}

let c = new C();
```

**ArkTS**

```typescript
class C {
  name: string = ''
  age!: number      // warning: arkts-no-definite-assignment

  initAge(age: number) {
    this.age = age;
  }
}

let c = new C();
c.initAge(10);
```

### Disabling Type Checking with In-Place Comments Is Not Allowed

**Rule:** arkts-strict-typing-required

**Severity: error**

**Error code: 10605146**

Type checking in ArkTS is not optional. Disabling type checking in-place with special comments is not allowed. In particular, **@ts-ignore** and **@ts-nocheck** annotations are not supported.

**TypeScript**

```typescript
// @ts-nocheck
// ...
// Some code with type checking disabled.
// ...

let s1: string = null; // No error is reported.

// @ts-ignore
let s2: string = null; // No error is reported.
```

**ArkTS**

```typescript
let s1: string | null = null; // No error is reported. The types are proper.
let s2: string = null; // Compile-time error
```

### TS/JS File Cannot Import Source Code of ETS File

**Rule:** arkts-no-ts-deps

**Severity: error**

**Error code: 10605147**

An .ets file can import source code of an .ets/.ts/.js file, but a .ts/.js file cannot import source code of an .ets file.

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

### Classes Cannot Be Used as Objects

**Rule:** arkts-no-classes-as-obj

**Severity: warning**

**Error Code: 10605149**

ArkTS does not support using classes as objects (assigning them to variables, etc.). This is because in ArkTS, a **class** declaration introduces a new type, not a value.

### import Statements After Other Statements Are Not Allowed

**Rule:** arkts-no-misplaced-imports

**Severity: error**

**Error Code: 10605150**

In ArkTS, all **import** statements except dynamic **import** statements should go before all other statements in the program.

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

import('module2').then(() => {}).catch(() => {})  // Dynamic import
```

### Usage of ESObject Type Is Restricted

**Rule:** arkts-limited-esobj

**Severity: warning**

**Error Code: 10605151**

ArkTS does not allow using ESObject type in some cases. The most part of limitations are put in place in order to prevent spread of dynamic objects (from an .ts/.js file) in the static codebase (from an .ets file).
Before API version 18, the only scenario where it is allowed to use ESObject as type specifier is in local variable declaration. ESObject type variables can only be assigned by objects that can be called across languages, for example, ESObject, **any**, **unknown**, and anonymous types. It is prohibited to initialize ESObject typed variable with statically typed value defined in the .ets file. ESObject typed variables can only be used for functions that can be called across languages or assigned to another ESObject typed variable.
Since API version 18, the ESObject type prohibits object literal assignment while supporting: type annotations in dynamic imports, property access (using both **.** and **[]** operators), call expressions, and **new** expressions.

**ArkTS**

```typescript
// lib.d.ts
declare function foo(): any;
declare function bar(a: any): number;

// main.ets
let e0: ESObject = foo(); // Before API version 18, compile-time error: 'ESObject' typed variable can only be local; since API version 18, the ESObject type supports explicit type annotation.

function f() {
  let e1 = foo();        // Compile-time error: type of e1 is 'any';
  let e2: ESObject = 1;  // Before API version 18, compile-time error: Cannot initialize an ESObject with non-dynamic values; since API version 18, the number type is supported.
  let e3: ESObject = {}; // Before API version 18, compile-time error: Cannot initialize an ESObject with non-dynamic values; since API version 18, compile-time error: object literal type is not supported.
  let e4: ESObject = []; // Before API version 18, compile-time error: Cannot initialize an ESObject with non-dynamic values; since API version 18, the array type is supported.
  let e5: ESObject = ''; // Before API version 18, compile-time error: Cannot initialize an ESObject with non-dynamic values; since API version 18, the string type is supported.
  e5['prop'];            // Before API version 18, compile-time error: Cannot access dynamic properties of 'ESObject'; since API version 18, property access using square brackets is supported.
  e5[1];                 // Before API version 18, compile-time error: Cannot access dynamic properties of 'ESObject'; since API version 18, property access using square brackets is supported.
  e5.prop;               // Before API version 18, compile-time error: Cannot access dynamic properties of 'ESObject'; since API version 18, property access using a dot (.) is supported.

  let e6: ESObject = foo(); // OK - Explicitly annotated as 'ESObject'.
  let e7: ESObject = e6;    // OK - Initialize 'ESObject' with 'ESObject'.
  bar(e7);                  // OK - 'ESObject' is passed to a cross-language function.
}
```
