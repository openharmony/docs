# 从TypeScript到ArkTS的适配规则

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @husenlin-->
<!--Designer: @qyhuo32-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @zhang_yixin13-->

ArkTS规范约束了TypeScript（简称TS）中影响开发正确性或增加运行时开销的特性。本文罗列了ArkTS中限制的TS特性，并提供重构代码的建议。ArkTS保留了TS大部分语法特性，未在本文中约束的TS特性，ArkTS完全支持。例如，ArkTS支持自定义装饰器，语法与TS一致。按本文约束进行代码重构后，代码仍为合法有效的TS代码。

**示例**

包含关键字`var`的原始TypeScript代码：

```typescript
function addTen(x: number): number {
  var ten = 10;
  return x + ten;
}
```

重构后的代码：

```typescript
function addTen(x: number): number {
  let ten = 10;
  return x + ten;
}
```

**级别**

约束分为两个级别：错误、警告。

- **错误**: 必须要遵从的约束。如果不遵从该约束，将会导致程序编译失败。
- **警告**: 推荐遵从的约束。尽管现在违反该约束不会影响编译流程，但是在将来，违反该约束可能会导致程序编译失败。

**不支持的特性**

目前，不支持的特性主要包括：

- 与降低运行时性能的动态类型相关的特性。
- 需要编译器额外支持从而导致项目构建时间增加的特性。

根据开发者的反馈和实际场景的数据，未来将逐步减少不支持的特性。

## 概述

本节罗列了ArkTS不支持或部分支持的TypeScript特性。完整的列表以及详细的代码示例和重构建议，请参考[约束说明](#约束说明)。更多案例请参考[适配指导案例](arkts-more-cases.md)。

### 强制使用静态类型

静态类型是ArkTS的重要特性之一。当程序使用静态类型时，所有类型在编译时已知，这有助于开发者理解代码中的数据结构。编译器可以提前验证代码的正确性，减少运行时的类型检查，从而提升性能。

基于上述考虑，ArkTS中禁止使用`any`类型。

**示例**

```typescript
// 不支持：
let res: any = some_api_function('hello', 'world');
// 支持：
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

`any`类型在TypeScript中并不常见，仅约1%的TypeScript代码库使用。代码检查工具（例如ESLint）也制定了一系列规则来禁止使用`any`。因此，虽然禁止`any`将导致代码重构，但重构量很小，有助于整体性能提升。

### 禁止在运行时变更对象布局

为实现最佳性能，ArkTS要求在程序执行期间不能更改对象的布局。换句话说，ArkTS禁止以下行为：

- 向对象中添加新的属性或方法。
- 从对象中删除已有的属性或方法。
- 将任意类型的值赋值给对象属性。

TypeScript编译器已经禁止了许多此类操作。然而，有些操作还是有可能绕过编译器的，例如，使用`as any`转换对象的类型，或者在编译TS代码时关闭严格类型检查的配置，或者在代码中通过`@ts-ignore`忽略类型检查。

在ArkTS中，严格类型检查不是可配置项。ArkTS强制进行部分严格类型检查，并通过规范禁止使用`any`类型，禁止在代码中使用`@ts-ignore`。

**示例**

```typescript
class Point {
  public x: number = 0
  public y: number = 0

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}

// 无法从对象中删除某个属性，从而确保所有Point对象都具有属性x
let p1 = new Point(1.0, 1.0);
delete p1.x;           // 在TypeScript和ArkTS中，都会产生编译时错误
delete (p1 as any).x;  // 在TypeScript中不会报错；在ArkTS中会产生编译时错误

// Point类没有定义命名为z的属性，在程序运行时也无法添加该属性
let p2 = new Point(2.0, 2.0);
p2.z = 'Label';           // 在TypeScript和ArkTS中，都会产生编译时错误
(p2 as any).z = 'Label';   // 在TypeScript中不会报错；在ArkTS中会产生编译时错误

// 类的定义确保了所有Point对象只有属性x和y，并且无法被添加其他属性
let p3 = new Point(3.0, 3.0);
let prop = Symbol();      // 在TypeScript中不会报错；在ArkTS中会产生编译时错误
(p3 as any)[prop] = p3.x; // 在TypeScript中不会报错；在ArkTS中会产生编译时错误
p3[prop] = p3.x;          // 在TypeScript和ArkTS中，都会产生编译时错误

// 类的定义确保了所有Point对象的属性x和y都具有number类型，因此，无法将其他类型的值赋值给它们
let p4 = new Point(4.0, 4.0);
p4.x = 'Hello!';          // 在TypeScript和ArkTS中，都会产生编译时错误
(p4 as any).x = 'Hello!'; // 在TypeScript中不会报错；在ArkTS中会产生编译时错误

// 使用符合类定义的Point对象：
function distance(p1: Point, p2: Point): number {
  return Math.sqrt(
    (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y)
  );
}
let p5 = new Point(5.0, 5.0);
let p6 = new Point(6.0, 6.0);
console.info('Distance between p5 and p6: ' + distance(p5, p6));
```

修改对象布局会影响代码可读性和运行时性能。定义类后，在其他地方修改对象布局，容易引起困惑乃至引入错误。此外，还需要额外的运行时支持，增加执行开销。这与静态类型约束冲突：使用显式类型时，不应添加或删除属性。

当前，只有少数项目允许在运行时变更对象布局，一些常用的代码检查工具也增加了相应的限制规则。虽然需要少量代码重构，但由此带来的性能提升收益十分可观。

### 限制运算符的语义

为获得更好的性能并鼓励开发者编写更清晰的代码，ArkTS限制了一些运算符的语义。详细的语义限制，请参考[约束说明](#约束说明)。

**示例**

```typescript
// 一元运算符`+`只能作用于数值类型：
let t = +42;   // 合法运算
let s = +'42'; // 编译时错误
```

使用额外的语义重载语言运算符会增加语言规范的复杂度，而且，开发者还被迫牢记所有可能的例外情况及对应的处理规则。在特定情况下，这会导致不必要的运行时开销。

当前只有不到1%的代码库使用该特性。因此，尽管限制运算符的语义需要重构代码，但重构量很小且非常容易操作，并且，通过重构能使代码更清晰、具备更高性能。

### 不支持 structural typing

假设两个不相关的类`T`和`U`都拥有相同的`public`API：

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

类型为`T`的值是否能赋给类型为`U`的变量。

```typescript
let u: U = new T(); // 是否允许？
```

类型为`T`的值是否能传递给接受类型为`U`的参数的函数。

```typescript
function greeter(u: U) {
  console.info('To ' + u.name);
  u.greet();
}

let t: T = new T();
greeter(t); // 是否允许？
```

具体采用哪种方法，情况如下：

- `T`和`U`没有继承关系或没有`implements`相同的接口，但由于它们具有相同的`public`API，它们“在某种程度上是相等的”，因此上述两个问题的答案都是“是”。
- `T`和`U`没有继承关系或没有`implements`相同的接口，应当始终被视为完全不同的类型，因此上述两个问题的答案都是“否”。

采用第一种方法的语言支持structural typing，而采用第二种方法的语言则不支持structural typing。目前TypeScript支持structural typing，而ArkTS不支持。

关于structural typing是否有助于生成清晰、易理解的代码，目前尚无定论。ArkTS不支持structural typing的原因如下：

因为对structural typing的支持是一个重大的特性，需要在语言规范、编译器和运行时进行大量的考虑和仔细的实现。另外，由于ArkTS使用静态类型，运行时为了支持这个特性需要额外的性能开销。

鉴于此，当前我们还不支持该特性。根据实际场景的需求和反馈，我们后续会重新加以考虑。更多案例和建议请参考[约束说明](#约束说明)。

## 约束说明

### 对象的属性名必须是合法的标识符

**规则：**`arkts-identifiers-as-prop-names`

**级别：错误**

**错误码：10605001**

在ArkTS中，对象的属性名不能为数字或字符串。例外：ArkTS支持属性名为字符串字面量和枚举中的字符串值。通过属性名访问类的属性，通过数值索引访问数组元素。

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

// 在需要通过非标识符（即不同类型的key）获取数据的场景中，使用Map<Object, some_type>。
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
  [Test.A]: 1,   // 枚举中的字符串值
  [Test.B]: 2,   // 枚举中的字符串值
  ['value']: 3   // 字符串字面量
}
```

### 不支持`Symbol()`API

**规则：**`arkts-no-symbol`

**级别：错误**

**错误码：10605002**

在ArkTS中，对象布局在编译时确定，不可在运行时更改，因此不支持`Symbol()` API。该API在静态类型语言中通常没有实际意义。

ArkTS只支持`Symbol.iterator`。

### 不支持以`#`开头的私有字段

**规则：**`arkts-no-private-identifiers`

**级别：错误**

**错误码：10605003**

ArkTS不支持使用`#`符号开头声明的私有字段。改用`private`关键字。

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

### 类型、命名空间的命名必须唯一

**规则：**`arkts-unique-names`

**级别：错误**

**错误码：10605004**

类型（类、接口、枚举）和命名空间的名称必须唯一，并且不能与其他名称（如变量名、函数名）重复。

**TypeScript**

```typescript
let X: string
type X = number[] // 类型的别名与变量同名
```

**ArkTS**

```typescript
let X: string
type T = number[] // 为避免名称冲突，此处不允许使用X
```

### 使用`let`而非`var`

**规则：**`arkts-no-var`

**级别：错误**

**错误码：10605005**

`let`关键字可以在块级作用域中声明变量，帮助程序员避免错误。因此，ArkTS不支持`var`，请使用`let`声明变量。

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
scopedVar = 5; // 可见
scopedLet = 5; // 编译时错误
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
scopedLet = 5; //编译时错误
```

### 使用具体的类型而非`any`或`unknown`

**规则：**`arkts-no-any-unknown`

**级别：错误**

**错误码：10605008**

ArkTS不支持`any`和`unknown`类型。显式指定具体类型。

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
let value_b: boolean = true; // 或者 let value_b = true
let value_n: number = 42; // 或者 let value_n = 42
let value_o1: Object = true;
let value_o2: Object = 42;
```

### 使用`class`而非具有call signature的类型

**规则：**`arkts-no-call-signatures`

**级别：错误**

**错误码：10605014**

ArkTS不支持对象类型中包含call signature。

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

### 使用`class`而非具有构造签名的类型

**规则：**`arkts-no-ctor-signatures-type`

**级别：错误**

**错误码：10605015**

ArkTS不支持对象类型中的构造签名。改用类。

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

### 仅支持一个静态块

**规则：**`arkts-no-multiple-static-blocks`

**级别：错误**

**错误码：10605016**

ArkTS不允许类中存在多个静态块。如果存在多个静态块语句，请将其合并到一个静态块中。

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

### 不支持index signature

**规则：**`arkts-no-indexed-signatures`

**级别：错误**

**错误码：10605017**

ArkTS不允许index signature，改用数组。

**TypeScript**

```typescript
// 带index signature的接口：
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

### 使用继承而非intersection type

**规则：**`arkts-no-intersection-types`

**级别：错误**

**错误码：10605019**

目前ArkTS不支持intersection type，可以使用继承作为替代方案。

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

### 不支持`this`类型

**规则：**`arkts-no-typing-with-this`

**级别：错误**

**错误码：10605021**

ArkTS不支持`this`类型，改用显式具体类型。

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

### 不支持条件类型

**规则：**`arkts-no-conditional-types`

**级别：错误**

**错误码：10605022**

ArkTS不支持条件类型别名，建议引入带显式约束的新类型，或使用`Object`进行逻辑重构。
不支持`infer`关键字。

**TypeScript**

```typescript
type X<T> = T extends number ? T: never
type Y<T> = T extends Array<infer Item> ? Item: never
```

**ArkTS**

```typescript
// 在类型别名中提供显式约束
type X1<T extends number> = T

// 用Object重写，类型控制较少，需要更多的类型检查以确保安全
type X2<T> = Object

// Item必须作为泛型参数使用，并能正确实例化
type YI<Item, T extends Array<Item>> = Item
```

### 不支持在`constructor`中声明字段

**规则：**`arkts-no-ctor-prop-decls`

**级别：错误**

**错误码：10605025**

ArkTS禁止在构造函数中声明类字段，所有字段都必须在`class`作用域内显示声明。

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

### 接口中不支持构造签名

**规则：**`arkts-no-ctor-signatures-iface`

**级别：错误**

**错误码：10605027**

ArkTS语法禁止在接口（interface）中定义构造签名。作为替代方案，建议使用普通函数或方法来实现相同功能。

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

### 不支持索引访问类型

**规则：**`arkts-no-aliases-by-index`

**级别：错误**

**错误码：10605028**

ArkTS不支持索引访问类型。

### 不支持通过索引访问字段

**规则：**`arkts-no-props-by-index`

**级别：错误**

**错误码：10605029**

ArkTS不支持动态声明字段，不支持动态访问字段。只能访问已在类中声明或者继承可见的字段，访问其他字段将会造成编译时错误。
使用点操作符访问字段，例如（`obj.field`），不支持索引访问（`obj['field']`）。
ArkTS支持通过索引访问`TypedArray`（例如`Int32Array`）中的元素。

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
console.info(person['name']);     // 编译时错误
console.info(person.unknownProperty); // 编译时错误

let arr = new Int32Array(1);
arr[0];
```

### 不支持structural typing

**规则：**`arkts-no-structural-typing`

**级别：错误**

**错误码：10605030**

ArkTS不支持structural typing，编译器无法比较两种类型的`public`API并决定它们是否相同。使用其他机制，例如继承、接口或类型别名。

**TypeScript**

```typescript
interface I1 {
  f(): string
}

interface I2 { // I2等价于I1
  f(): string
}

class X {
  n: number = 0
  s: string = ''
}

class Y { // Y等价于X
  n: number = 0
  s: string = ''
}

let x = new X();
let y = new Y();

// 将X对象赋值给Y对象
y = x;

// 将Y对象赋值给X对象
x = y;

function foo(x: X) {
  console.info(x.n + x.s);
}

// 由于X和Y的API是等价的，所以X和Y是等价的
foo(new X());
foo(new Y());
```

**ArkTS**

```typescript
interface I1 {
  f(): string
}

type I2 = I1 // I2是I1的别名

class B {
  n: number = 0
  s: string = ''
}

// D是B的继承类，构建了子类型和父类型的关系
class D extends B {
  constructor() {
    super()
  }
}

let b = new B();
let d = new D();

console.info('Assign D to B');
b = d; // 合法赋值，因为B是D的父类

// 将b赋值给d将会引起编译时错误
// d = b

interface Z {
   n: number
   s: string
}

// 类X implements 接口Z，构建了X和Y的关系
class X implements Z {
  n: number = 0
  s: string = ''
}

// 类Y implements 接口Z，构建了X和Y的关系
class Y implements Z {
  n: number = 0
  s: string = ''
}

let x: Z = new X();
let y: Z = new Y();

console.info('Assign X to Y');
y = x // 合法赋值，它们是相同的类型

console.info('Assign Y to X');
x = y // 合法赋值，它们是相同的类型

function foo(c: Z): void {
  console.info(c.n + c.s);
}

// 类X和类Y implement 相同的接口，因此下面的两个函数调用都是合法的
foo(new X());
foo(new Y());
```

### 需要显式标注泛型函数类型实参

**规则：**`arkts-no-inferred-generic-params`

**级别：错误**

**错误码：10605034**

如果可以从传递给泛型函数的参数中推断出具体类型，ArkTS允许省略泛型类型实参。否则，省略泛型类型实参会发生编译时错误。
禁止仅基于泛型函数返回类型推断泛型类型参数。

**TypeScript**

```typescript
function choose<T>(x: T, y: T): T {
  return Math.random() < 0.5 ? x: y;
}

let x = choose(10, 20);   // 推断choose<number>(...)
let y = choose('10', 20); // 编译时错误

function greet<T>(): T {
  return 'Hello' as T;
}
let z = greet() // T的类型被推断为“unknown”
```

**ArkTS**

```typescript
function choose<T>(x: T, y: T): T {
  return Math.random() < 0.5 ? x: y;
}

let x = choose(10, 20);   // 推断choose<number>(...)
let y = choose('10', 20); // 编译时错误

function greet<T>(): T {
  return 'Hello' as T;
}
let z = greet<string>();
```

### 需要显式标注对象字面量的类型

**规则：**`arkts-no-untyped-obj-literals`

**级别：错误**

**错误码：10605038**

在 ArkTS 中，需要显式标注对象字面量的类型，否则将导致编译时错误。在某些场景下，编译器可以根据上下文推断出字面量的类型。

在以下上下文中不支持使用字面量初始化类和接口：

* 初始化具有`any`、`Object`或`object`类型的任何对象
* 初始化带有方法的类或接口
* 初始化包含自定义含参数的构造函数的类
* 初始化带`readonly`字段的类

**例子1**

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

**例子2**

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

**例子3**

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

**例子4**

**TypeScript**

```typescript
abstract class A {}
let o6: A = {};
```

**ArkTS**

```typescript
abstract class A {}
class C extends A {}
let o6: C = {}; // 或 let o6: C = new C()
```

**例子5**

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

**例子6**

**TypeScript**

```typescript
class Point {
  x: number = 0
  y: number = 0
}

function getPoint(o: Point): Point {
  return o;
}

// TS支持structural typing，可以推断p的类型为Point
let p = {x: 5, y: 10};
getPoint(p);

// 可通过上下文推断出对象字面量的类型为Point
getPoint({x: 5, y: 10});
```

**ArkTS**

```typescript
class Point {
  x: number = 0
  y: number = 0

  // 在字面量初始化之前，使用constructor()创建一个有效对象。
  // 由于没有为Point定义构造函数，编译器将自动添加一个默认构造函数。
}

function getPoint(o: Point): Point {
  return o;
}

// 字面量初始化需要显式定义类型
let p: Point = {x: 5, y: 10};
getPoint(p);

// getPoint接受Point类型，字面量初始化生成一个Point的新实例
getPoint({x: 5, y: 10});
```

### 对象字面量不能用于类型声明

**规则：**`arkts-no-obj-literals-as-types`

**级别：错误**

**错误码：10605040**

ArkTS不支持使用对象字面量声明类型，建议使用类或接口声明类型。

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

### 数组字面量必须仅包含可推断类型的元素

**规则：**`arkts-no-noninferrable-arr-literals`

**级别：错误**

**错误码：10605043**

ArkTS将数组字面量的类型推断为所有元素的联合类型。如果其中任何一个元素的类型无法推导，则在编译时会发生错误。

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

let a1 = [{n: 1, s: '1'} as C, {n: 2, s: '2'} as C]; // a1的类型为“C[]”
let a2: C[] = [{n: 1, s: '1'}, {n: 2, s: '2'}];    // a2的类型为“C[]”
```

### 使用箭头函数而非函数表达式

**规则：**`arkts-no-func-expressions`

**级别：错误**

**错误码：10605046**

ArkTS不支持函数表达式，使用箭头函数（=>）。

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

### 不支持使用类表达式

**规则：**`arkts-no-class-literals`

**级别：错误**

**错误码：10605050**

ArkTS不支持类表达式，必须显式声明一个类。

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

### 类不允许`implements`

**规则：**`arkts-implements-only-iface`

**级别：错误**

**错误码：10605051**

ArkTS中只有接口可以被`implements`，类不允许被`implements`。

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

### 不支持修改对象的方法

**规则：**`arkts-no-method-reassignment`

**级别：错误**

**错误码：10605052**

ArkTS不支持修改对象的方法。在静态语言中，对象布局固定，类的所有实例共享同一个方法。
若需为特定对象添加方法，可封装函数或采用继承机制。

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

### 类型转换仅支持`as T`语法

**规则：**`arkts-as-casts`

**级别：错误**

**错误码：10605053**

在ArkTS中，`as`关键字是类型转换的唯一语法，错误的类型转换会导致编译时错误或者运行时抛出`ClassCastException`异常。ArkTS不支持使用`<type>`语法进行类型转换。

需要将`primitive`类型（如`number`或`boolean`）转换为引用类型时，请使用`new`表达式。

**TypeScript**

```typescript
class Shape {}
class Circle extends Shape { x: number = 5 }
class Square extends Shape { y: string = 'a' }

function createShape(): Shape {
  return new Circle();
}

let c1 = <Circle> createShape();

let c2 = createShape() as Circle;

// 如果转换错误，不会产生编译时或运行时报错
let c3 = createShape() as Square;
console.info(c3.y); // undefined

// 在TS中，由于`as`关键字不会在运行时生效，所以`instanceof`的左操作数不会在运行时被装箱成引用类型
let e1 = (5.0 as Number) instanceof Number; // false

// 创建Number对象，获得预期结果：
let e2 = (new Number(5.0)) instanceof Number; // true
```

**ArkTS**

```typescript
class Shape {}
class Circle extends Shape { x: number = 5 }
class Square extends Shape { y: string = 'a' }

function createShape(): Shape {
  return new Circle();
}

let c2 = createShape() as Circle;

// 创建Number对象，获得预期结果：
let e2 = (new Number(5.0)) instanceof Number; // true
```

### 不支持JSX表达式

**规则：**`arkts-no-jsx`

**级别：错误**

**错误码：10605054**

不支持使用JSX。

### 一元运算符`+`、`-`和`~`仅适用于数值类型

**规则：**`arkts-no-polymorphic-unops`

**级别：错误**

**错误码：10605055**

ArkTS对一元运算符实施严格的类型检查，仅允许操作数值类型。与TypeScript不同，ArkTS禁止隐式的字符串转换到数值，开发者必须使用显示类型的转换方法。

**TypeScript**

```typescript
let a = +5;    // 5（number类型）
let b = +'5';    // 5（number类型）
let c = -5;    // -5（number类型）
let d = -'5';    // -5（number类型）
let e = ~5;    // -6（number类型）
let f = ~'5';    // -6（number类型）
let g = +'string'; // NaN（number类型）

function returnTen(): string {
  return '-10';
}

function returnString(): string {
  return 'string';
}

let x = +returnTen();  // -10（number类型）
let y = +returnString(); // NaN
```

**ArkTS**

```typescript
let a = +5;    // 5（number类型）
let b = +'5';    // 编译时错误
let c = -5;    // -5（number类型）
let d = -'5';    // 编译时错误
let e = ~5;    // -6（number类型）
let f = ~'5';    // 编译时错误
let g = +'string'; // 编译时错误

function returnTen(): string {
  return '-10';
}

function returnString(): string {
  return 'string';
}

let x = +returnTen();  // 编译时错误
let y = +returnString(); // 编译时错误
```

### 不支持`delete`运算符

**规则：**`arkts-no-delete`

**级别：错误**

**错误码：10605059**

在ArkTS中，对象布局于编译时确定，运行时不可更改，因此删除属性的操作无意义。

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
// 可以声明一个可空类型并使用null作为缺省值
class Point {
  x: number | null = 0
  y: number | null = 0
}

let p = new Point();
p.y = null;
```

### 仅允许在表达式中使用`typeof`运算符

**规则：**`arkts-no-type-query`

**级别：错误**

**错误码：10605060**

ArkTS仅支持在表达式中使用`typeof`运算符，不允许使用`typeof`作为类型。

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

### 部分支持`instanceof`运算符

**规则：**`arkts-instanceof-ref-types`

**级别：错误**

**错误码：10605065**

TypeScript中，`instanceof`运算符的左操作数类型必须为`any`类型、对象类型或类型参数，否则结果为`false`。ArkTS中，`instanceof`运算符的左操作数类型必须为引用类型（如对象、数组或函数），否则会发生编译时错误。此外，左操作数必须是对象实例。

**TypeScript**

```typescript
let num: number = 42;
let result = num instanceof Number;
console.info('result = ', result); // result = false
```

**ArkTS**

```typescript
let num: number = 42;
let result = num instanceof Number; // 编译报错
```

### 不支持`in`运算符

**规则：**`arkts-no-in`

**级别：错误**

**错误码：10605066**

在ArkTS中，对象布局在编译时已知且运行时无法修改，因此不支持`in`运算符。需要检查类成员是否存在时，使用`instanceof`代替。

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

let b = p instanceof Person; // true，且属性name一定存在
```

### 不支持解构赋值

**规则：**`arkts-no-destruct-assignment`

**级别：错误**

**错误码：10605069**

ArkTS不支持解构赋值。可使用其他替代方法，例如，使用临时变量。

**TypeScript**

```typescript
let [one, two] = [1, 2]; // 此处需要分号
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

### 逗号运算符`,`仅用在`for`循环语句中

**规则：**`arkts-no-comma-outside-loops`

**级别：错误**

**错误码：10605071**

在ArkTS中，逗号运算符仅适用于`for`循环语句，用于明确执行顺序。
>**注意：** 这与声明变量和函数参数传递时使用的逗号分隔符不同。

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

// 通过语句表示执行顺序，而非逗号运算符
let x = 0;
++x;
x = x++;
```

### 不支持解构变量声明

**规则：**`arkts-no-destruct-decls`

**级别：错误**

**错误码：10605074**

ArkTS不支持解构变量声明。解构变量声明是一个依赖于结构兼容性的动态特性，且解构声明中的名称必须与被解构对象中的属性名称一致。

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

// 创建一个局部变量来处理每个字段
let zp = returnZeroPoint();
let x = zp.x;
let y = zp.y;
```

### 不支持在catch语句标注类型

**规则：**`arkts-no-types-in-catch`

**级别：错误**

**错误码：10605079**

TypeScript的catch语句中，只能标注`any`或`unknown`类型。ArkTS不支持这些类型，应省略类型标注。

**TypeScript**

```typescript
try {
  // ...
} catch (a: unknown) {
  // 处理异常
}
```

**ArkTS**

```typescript
try {
  // ...
} catch (a) {
  // 处理异常
}
```

### 不支持`for .. in`

**规则：**`arkts-no-for-in`

**级别：错误**

**错误码：10605080**

在ArkTS中，对象布局在编译时确定且运行时不可修改，因此不支持使用`for .. in`迭代对象属性。

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

### 不支持映射类型

**规则：**`arkts-no-mapped-types`

**级别：错误**

**错误码：10605083**

ArkTS不支持映射类型，使用其他语法表示相同语义。

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

### 不支持`with`语句

**规则：**`arkts-no-with`

**级别：错误**

**错误码：10605084**

ArkTS不支持`with`语句，使用其他语法来表示相同的语义。

**TypeScript**

```typescript
with (Math) { // 编译时错误, 但是仍能生成JavaScript代码
  let r: number = 42;
  let area: number = PI * r * r;
}
```

**ArkTS**

```typescript
let r: number = 42;
let area: number = Math.PI * r * r;
```

### 限制`throw`语句中表达式的类型

**规则：**`arkts-limited-throw`

**级别：错误**

**错误码：10605087**

ArkTS只支持抛出`Error`类或其派生类的实例。禁止抛出其他类型的数据，例如`number`或`string`。

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

### 限制省略函数返回类型标注

**规则：**`arkts-no-implicit-return-types`

**级别：错误**

**错误码：10605090**

ArkTS在部分场景中支持对函数返回类型进行推断。当`return`语句中的表达式是对某个函数或方法进行调用，且该函数或方法的返回类型没有被显著标注时，会出现编译时错误。在这种情况下，请标注函数返回类型。

**TypeScript**

```typescript
// 只有在开启noImplicitAny选项时会产生编译时错误
function f(x: number) {
  if (x <= 0) {
    return x;
  }
  return g(x);
}

// 只有在开启noImplicitAny选项时会产生编译时错误
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
// 需标注返回类型：
function f(x: number): number {
  if (x <= 0) {
    return x;
  }
  return g(x);
}

// 可以省略返回类型，返回类型可以从f的类型标注推导得到
function g(x: number): number {
  return f(x - 1);
}

// 可以省略返回类型
function doOperation(x: number, y: number) {
  return x + y;
}

f(10);
doOperation(2, 3);
```

### 不支持参数解构的函数声明

**规则：**`arkts-no-destruct-params`

**级别：错误**

**错误码：10605091**

ArkTS要求实参必须直接传递给函数，且必须指定到形参。

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

### 不支持在函数内声明函数

**规则：**`arkts-no-nested-funcs`

**级别：错误**

**错误码：10605092**

ArkTS不支持在函数内声明函数，改用lambda函数。

**TypeScript**

```typescript
function addNum(a: number, b: number): void {

  // 函数内声明函数
  function logToConsole(message: string): void {
    console.info(message);
  }

  let result = a + b;

  // 调用函数
  logToConsole('result is ' + result);
}
```

**ArkTS**

```typescript
function addNum(a: number, b: number): void {
  // 使用lambda函数代替声明函数
  let logToConsole: (message: string) => void = (message: string): void => {
    console.info(message);
  }

  let result = a + b;

  logToConsole('result is ' + result);
}
```

### 不支持在函数和类的静态方法中使用`this`

**规则：**`arkts-no-standalone-this`

**级别：错误**

**错误码：10605093**

ArkTS中`this`只能在类的实例方法中使用，不支持在函数和类的静态方法中使用。

**TypeScript**

```typescript
function foo(i: string) {
  this.count = i; // 只有在开启noImplicitThis选项时会产生编译时错误
}

class A {
  count: string = 'a'
  m = foo
}

let a = new A();
console.info(a.count); // 打印a
a.m('b');
console.info(a.count); // 打印b
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
  console.info(a.count);  // 打印a
  a.m('b');
  console.info(a.count);  // 打印b
}
```

### 不支持生成器函数

**规则：**`arkts-no-generators`

**级别：错误**

**错误码：10605094**

目前ArkTS不支持生成器函数，可使用`async`或`await`机制处理并行任务。

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

### 使用`instanceof`和`as`进行类型保护

**规则：**`arkts-no-is`

**级别：错误**

**错误码：10605096**

在ArkTS中，不支持`is`运算符，必须使用`instanceof`运算符来替代。在使用`instanceof`之前，必须先使用`as`运算符将对象转换为所需类型。

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
    console.info(arg.bar);  // 编译时错误
  } else {
    console.info(arg.foo);  // 编译时错误
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
    console.info(arg.bar);    // 编译时错误
  } else {
    let barArg = arg as Bar;
    console.info(arg.foo);    // 编译时错误
    console.info(barArg.bar);   // OK
  }
}

function main(): void {
  doStuff(new Foo());
  doStuff(new Bar());
}
```

### 部分支持展开运算符

**规则：**`arkts-no-spread`

**级别：错误**

**错误码：10605099**

ArkTS仅支持使用展开运算符展开数组、`Array`的子类和`TypedArray`（例如`Int32Array`）。仅支持使用在以下场景中：
1. 传递给剩余参数时；
2. 复制一个数组到数组字面量。

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

### 接口不能继承具有相同方法的两个接口

**规则：**`arkts-no-extend-same-prop`

**级别：错误**

**错误码：106050102**

在TypeScript中，如果一个接口继承了两个具有相同方法的接口，则必须使用联合类型声明该方法的返回值类型。在ArkTS中，由于接口不能包含两个无法区分的方法（如参数列表相同但返回类型不同），因此不能继承具有相同方法的两个接口。

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

### 不支持声明合并

**规则：**`arkts-no-decl-merging`

**级别：错误**

**错误码：10605103**

ArkTS不支持类和接口的声明合并。

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

### 接口不能继承类

**规则：**`arkts-extends-only-class`

**级别：错误**

**错误码：10605104**

在ArkTS中，接口不能继承类，只能继承其他接口。

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

### 不支持构造函数类型

**规则：**`arkts-no-ctor-signatures-funcs`

**级别：错误**

**错误码：10605106**

ArkTS不支持构造函数类型，改用lambda函数。

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

### 只能使用类型相同的编译时表达式初始化枚举成员

**规则：**`arkts-no-enum-mixed-types`

**级别：错误**

**错误码：10605111**

ArkTS不支持使用运行期间计算的表达式初始化枚举成员。枚举中所有显式初始化的成员必须具有相同类型。

**TypeScript**

```typescript
enum E1 {
  A = 0xa,
  B = 0xb,
  C = Math.random(),
  D = 0xd,
  E // 推断出0xe
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
  E // 推断出0xe
}

enum E2 {
  A = '0xa',
  B = '0xb',
  C = '0xc',
  D = '0xd'
}
```

### 不支持`enum`声明合并

**规则：**`arkts-no-enum-merging`

**级别：错误**

**错误码：10605113**

ArkTS不支持`enum`声明合并。

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

### 命名空间不能被用作对象

**规则：**`arkts-no-ns-as-obj`

**级别：错误**

**错误码：10605114**

ArkTS不支持将命名空间用作对象，可以使用类或模块。

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

### 不支持命名空间中的非声明语句

**规则：**`arkts-no-ns-statements`

**级别：错误**

**错误码：10605116**

在ArkTS中，命名空间用于定义标识符的可见范围，仅在编译时有效。因此，命名空间中不支持非声明语句。可以将非声明语句写在函数中。

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

// 调用初始化函数来执行
A.init();
```

### 不支持`require`和`import`赋值表达式

**规则：**`arkts-no-require`

**级别：错误**

**错误码：10605121**

ArkTS不支持通过`require`导入和`import`赋值表达式，改用`import`。

**TypeScript**

```typescript
import m = require('mod')
```

**ArkTS**

```typescript
import * as m from 'mod'
```

### 不支持`export = ...`语法

**规则：**`arkts-no-export-assignment`

**级别：错误**

**错误码：10605126**

ArkTS不支持`export = ...`语法，改用常规的`export`或`import`。

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

### 不支持ambient module声明

**规则：**`arkts-no-ambient-decls`

**级别：错误**

**错误码：10605128**

由于ArkTS本身有与JavaScript交互的机制，ArkTS不支持ambient module声明。

**TypeScript**

```typescript
declare module 'someModule' {
  export function normalize(s: string): string;
}
```

**ArkTS**

```typescript
// 从原始模块中导入需要的内容
import { normalize } from 'someModule'
```

### 不支持在模块名中使用通配符

**规则：**`arkts-no-module-wildcards`

**级别：错误**

**错误码：10605129**

在ArkTS中，导入是编译时而非运行时行为，不支持在模块名中使用通配符。

**TypeScript**

```typescript
// 声明
declare module '*!text' {
  const content: string
  export default content
}

// 使用代码
import fileContent from 'some.txt!text'
```

**ArkTS**

```typescript
// 声明
declare namespace N {
  function foo(x: number): number
}

// 使用代码
import * as m from 'module'
console.info('N.foo called: ' + N.foo(42));
```

### 不支持通用模块定义(UMD)

**规则：**`arkts-no-umd`

**级别：错误**

**错误码：10605130**

ArkTS不支持通用模块定义（UMD）。因为在ArkTS中没有“脚本”的概念（相对于“模块”）。此外，在ArkTS中，导入是编译时而非运行时特性。改用`export`和`import`语法。

**TypeScript**

```typescript
// math-lib.d.ts
export const isPrime(x: number): boolean
export as namespace mathLib

// 脚本中
mathLib.isPrime(2)
```

**ArkTS**

```typescript
// math-lib.d.ts
namespace mathLib {
  export isPrime(x: number): boolean
}

// 程序中
import { mathLib } from 'math-lib'
mathLib.isPrime(2)
```

### 不支持`new.target`

**规则：**`arkts-no-new-target`

**级别：错误**

**错误码：10605132**

ArkTS没有原型的概念，因此不支持`new.target`。此特性不符合静态类型的原则。

### 不支持确定赋值断言

**规则：**`arkts-no-definite-assignment`

**级别：警告**

**错误码：10605134**

ArkTS不支持确定赋值断言，例如：`let v!: T`。改为在声明变量的同时为变量赋值。

**TypeScript**

```typescript
let x!: number // 提示：在使用前将x初始化

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

### 不支持在原型上赋值

**规则：**`arkts-no-prototype-assignment`

**级别：错误**

**错误码：10605136**

ArkTS没有原型的概念，因此不支持在原型上赋值。此特性不符合静态类型的原则。

**TypeScript**

```typescript
let C = function(p) {
  this.p = p; // 只有在开启noImplicitThis选项时会产生编译时错误
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
    return this.p == r;
  }
}
```

### 不支持`globalThis`

**规则：**`arkts-no-globalthis`

**级别：警告**

**错误码：10605137**

由于ArkTS不支持动态更改对象的布局，因此不支持全局作用域和`globalThis`。

**TypeScript**

```typescript
// 全局文件中
var abc = 100;

// 从上面引用'abc'
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

### 不支持一些utility类型

**规则：**`arkts-no-utility-types`

**级别：错误**

**错误码：10605138**

ArkTS仅支持`Partial`、`Required`、`Readonly`和`Record`，不支持TypeScript中其他的`Utility Types`。

对于`Partial<T>`类型，泛型参数T必须为类或者接口类型。

对于`Record`类型的对象，通过索引访问到的值的类型是包含`undefined`的联合类型。

### 不支持对函数声明属性

**规则：**`arkts-no-func-props`

**级别：错误**

**错误码：10605139**

由于ArkTS不支持动态改变函数对象布局，因此，不支持对函数声明属性。

### 不支持`Function.apply`和`Function.call`

**规则：**`arkts-no-func-apply-call`

**级别：错误**

**错误码：10605152**

ArkTS不允许使用标准库函数`Function.apply`和`Function.call`，因为这些函数用于显式设置被调用函数的`this`参数。在ArkTS中，`this`的语义仅限于传统的OOP风格，函数体中禁止使用`this`。

### 不支持`Function.bind`

**规则：**`arkts-no-func-bind`

**级别：警告**

**错误码：10605140**

ArkTS禁用标准库函数`Function.bind`。标准库使用这些函数显式设置被调用函数的`this`参数。在ArkTS中，`this`仅限于传统OOP风格，函数体中禁用使用`this`。


### 不支持`as const`断言

**规则：**`arkts-no-as-const`

**级别：错误**

**错误码：10605142**

ArkTS不支持`as const`断言和字面量类型。在标准TypeScript中，`as const`用于标注字面量类型。

**TypeScript**

```typescript
// 'hello'类型
let x = 'hello' as const;

// 'readonly [10, 20]'类型
let y = [10, 20] as const;

// '{ readonly text: 'hello' }'类型
let z = { text: 'hello' } as const;
```

**ArkTS**

```typescript
// 'string'类型
let x: string = 'hello';

// 'number[]'类型
let y: number[] = [10, 20];

class Label {
  text: string = ''
}

// 'Label'类型
let z: Label = {
  text: 'hello'
}
```

### 不支持导入断言

**规则：**`arkts-no-import-assertions`

**级别：错误**

**错误码：10605143**

ArkTS不支持导入断言。因为导入是编译时特性，运行时检查导入API是否正确没有意义。改用常规的`import`语法。

**TypeScript**

```typescript
import { obj } from 'something.json' assert { type: 'json' }
```

**ArkTS**

```typescript
// 编译时将检查导入T的正确性
import { something } from 'module'
```

### 限制使用标准库

**规则：**`arkts-limited-stdlib`

**级别：错误**

**错误码：10605144**

ArkTS不允许使用TypeScript或JavaScript标准库中的某些接口。大部分接口与动态特性有关。ArkTS中禁止使用以下接口：

全局对象的属性和方法：`eval`

`Object`：`__proto__`、`__defineGetter__`、`__defineSetter__`、
`__lookupGetter__`、`__lookupSetter__`、`assign`、`create`、
`defineProperties`、`defineProperty`、`freeze`、
`fromEntries`、`getOwnPropertyDescriptor`、`getOwnPropertyDescriptors`、
`getOwnPropertySymbols`、`getPrototypeOf`、
`hasOwnProperty`、`is`、`isExtensible`、`isFrozen`、
`isPrototypeOf`、`isSealed`、`preventExtensions`、
`propertyIsEnumerable`、`seal`、`setPrototypeOf`

`Reflect`：`apply`、`construct`、`defineProperty`、`deleteProperty`、
`getOwnPropertyDescriptor`、`getPrototypeOf`、
`isExtensible`、`preventExtensions`、
`setPrototypeOf`

`Proxy`：`handler.apply()`、`handler.construct()`、
`handler.defineProperty()`、`handler.deleteProperty()`、`handler.get()`、
`handler.getOwnPropertyDescriptor()`、`handler.getPrototypeOf()`、
`handler.has()`、`handler.isExtensible()`、`handler.ownKeys()`、
`handler.preventExtensions()`、`handler.set()`、`handler.setPrototypeOf()`

### 强制进行严格类型检查

**规则：**`arkts-strict-typing`

**级别：错误**

**错误码：10605145**

在编译阶段，会进行TypeScript严格模式的类型检查，包括：
`noImplicitReturns`, 
`strictFunctionTypes`, 
`strictNullChecks`, 
`strictPropertyInitialization`。

**TypeScript**

```typescript
// 只有在开启noImplicitReturns选项时会产生编译时错误
function foo(s: string): string {
  if (s != '') {
    console.info(s);
    return s;
  } else {
    console.info(s);
  }
}

let n: number = null; // 只有在开启strictNullChecks选项时会产生编译时错误
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

在定义类时，如果无法在声明时或者构造函数中初始化某实例属性，那么可以使用确定赋值断言符`!`来消除`strictPropertyInitialization`的报错。

使用确定赋值断言符会增加代码错误的风险。开发者必须确保实例属性在使用前已赋值，以避免运行时异常。

使用确定赋值断言符会增加运行时开销，应尽量避免使用。

使用确定赋值断言符将产生`warning: arkts-no-definite-assignment`。

**TypeScript**

```typescript
class C {
  name: string  // 只有在开启strictPropertyInitialization选项时会产生编译时错误
  age: number   // 只有在开启strictPropertyInitialization选项时会产生编译时错误
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

### 不允许通过注释关闭类型检查

**规则：**`arkts-strict-typing-required`

**级别：错误**

**错误码：10605146**

在ArkTS中，类型检查不是可选项。不允许通过注释关闭类型检查，不支持使用`@ts-ignore`和`@ts-nocheck`。

**TypeScript**

```typescript
// @ts-nocheck
// ...
// 关闭了类型检查后的代码
// ...

let s1: string = null; // 没有报错

// @ts-ignore
let s2: string = null; // 没有报错
```

**ArkTS**

```typescript
let s1: string | null = null; // 没有报错，合适的类型
let s2: string = null; // 编译时报错
```

### 允许.ets文件`import`.ets/.ts/.js文件源码, 不允许.ts/.js文件`import`.ets文件源码

**规则：**`arkts-no-ts-deps`

**级别：错误**

**错误码：10605147**

.ets文件可以`import`.ets/.ts/.js文件源码，但是.ts/.js文件不允许`import`.ets文件源码。

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

### `class`不能被用作对象

**规则：**`arkts-no-classes-as-obj`

**级别：警告**

**错误码：10605149**

在ArkTS中，`class`声明的是一个新类型，不是值。因此，不支持将`class`用作对象，例如将其赋值给一个对象。

### 不支持在`import`语句前使用其他语句

**规则：**`arkts-no-misplaced-imports`

**级别：错误**

**错误码：10605150**

在ArkTS中，除动态 `import` 语句外，所有 `import` 语句都应置于其他语句之前。

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

import('module2').then(() => {}).catch(() => {})  // 动态import
```

### 限制使用`ESObject`类型

**规则：**`arkts-limited-esobj`

**级别：警告**

**错误码：10605151**

为了防止动态对象（来自.ts/.js文件）在静态代码（.ets文件）中的滥用，`ESObject`类型在ArkTS中的使用是受限的。
在API版本18以前，唯一允许使用`ESObject`类型的场景是局部变量的声明。`ESObject`类型变量只能被跨语言调用的对象赋值，例如：`ESObject`、`any`、`unknown`、匿名类型等。禁止使用在.ets文件中定义的静态类型值初始化`ESObject`类型变量。`ESObject`类型变量只能用于跨语言调用的函数或赋值给另一个`ESObject`类型变量。
从API版本18开始，`ESObject`类型不再支持赋值对象字面量类型。`ESObject`类型支持在动态导入场景中作为类型标注，以及用于属性访问（点操作符和[]访问）、调用表达式和new表达式。

**ArkTS**

```typescript
// lib.d.ts
declare function foo(): any;
declare function bar(a: any): number;

// main.ets
let e0: ESObject = foo(); // API18以前，编译时错误：ESObject类型只能用于局部变量；API18以后，OK，显式标注ESObject类型

function f() {
  let e1 = foo();        // 编译时错误：e1的类型是any
  let e2: ESObject = 1;  // API18以前，编译时错误：不能用非动态值初始化ESObject类型变量；API18以后，OK，支持赋值数字类型
  let e3: ESObject = {}; // API18以前，编译时错误：不能用非动态值初始化ESObject类型变量；API18以后，编译时错误：ESObject不支持赋值对象字面量类型
  let e4: ESObject = []; // API18以前，编译时错误：不能用非动态值初始化ESObject类型变量；API18以后，OK，支持赋值数组类型
  let e5: ESObject = ''; // API18以前，编译时错误：不能用非动态值初始化ESObject类型变量；API18以后，OK，支持赋值字符串类型
  e5['prop'];            // API18以前，编译时错误：不能访问ESObject类型变量的属性；API18以后，OK，支持[]访问
  e5[1];                 // API18以前，编译时错误：不能访问ESObject类型变量的属性；API18以后，OK，支持[]访问
  e5.prop;               // API18以前，编译时错误：不能访问ESObject类型变量的属性；API18以后，OK，支持点操作符访问

  let e6: ESObject = foo(); // OK，显式标注ESObject类型
  let e7: ESObject = e6;    // OK，使用ESObject类型赋值
  bar(e7);                  // OK，ESObject类型变量传给跨语言调用的函数
}
```
