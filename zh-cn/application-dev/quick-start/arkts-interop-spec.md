# ArkTS1.2互操作特性规范

## ArkTS1.2互操作场景

### ArkTS1.1中使用ArkTS1.2

#### 文件导入

在ArkTS1.2中使用`import`函数导入ArkTS1.1的文件相关的内容，包含函数，类，对象等。

```typescript
// file1.ets ArkTS1.2
export function func(){}
export class A{}
export let a: A = new A();

// file2.ets ArkTS1.1
import { func, A, a} from './file1'
```

#### 类实例化

在ArkTS1.1中可以使用从ArkTS1.2中导入的类，用new来创建该类的实例。

```typescript
// file1.ets ArkTS1.2
export class A {}
export class B extends A {}
interface interA {}
export class C implements interA {}

// file2.ets ArkTS1.1
import { A, B, C } from "file1";
let a = new A();
let b = new B();
let c = new C();
```

#### 属性读写

在ArkTS1.1中可以读写ArkTS1.2中导入的对象的属性。

```typescript
// file1.ets ArkTS1.2
export class Person {
  name: string = "unknown"
}

// file2.ets ArkTS1.1
import { Person } from "file1";
let a = new Person();
let b = a.name; // "unknown"
a.name = "John";
```

#### 函数调用

在ArkTS1.1中可以直接调用ArkTS1.2中导入的函数。

```typescript
// file1.ets ArkTS1.2
export let func = () => {
  console.log(123);
};
export function foo1() {}
export function foo2(a: number, b: number): number {
  return a + b;
}

// file2.ets ArkTS1.1
import { func, foo1, foo2 } from "file1";
func();
foo1();
foo(1.5, 2.5);
```

#### 对象方法调用

在ArkTS1.2中可以直接访问ArkTS1.1导入对象的方法。

```typescript
// file1.ets ArkTS1.2
export class A {
  function log() {
    console.log(123)
  }
}
class B {
  foo() : void {}
}
export class C extends B {
  override foo() : void { console.log('D.foo') }
}
interface interA {
  foo: () => void;
}
export let itA: InterA = {
  foo: () => { console.log('interface log')) }
}
export let arr = new Array<number>(1, 2, 3);

// file2.ets ArkTS1.1
import { A, C, itA, arr } from 'file1'
let a = new A()
a.foo()
let c = new C()
c.foo()  // Output: D.foo
itA.foo()
arr.push(4)
```

#### 参数传递

在ArkTS1.1中可以将ArkTS1.1的参数传至导入的函数，从而回传至ArkTS1.2。

```typescript
// file1.ets ArkTS1.2
export function foo(a: Array<string>) {
  console.log(a[0]);
}
export class C {
  static foo(a: Array<string>) {
    console.log(a[0]);
  }
  bar(a: Array<string>) {
    console.log(a[0]);
  }
}
export interface Iface {
  foo(a: Array<string>): void;
}

// file2.ets ArkTS1.1
import { foo, C, Iface } from "file1";

foo(["Hi", "Bye"]); // Output: Hi
C.foo(["Hi", "Bye"]); // Output: Hi
new C().bar(["Hi", "Bye"]); // Output: Hi

function baz(i: Iface) {
  i.foo(["Hi", "Bye"]); // OK
}
```

#### 异常处理

ArkTS1.1中定义一个异常的实例，可以在ArkTS1.2中捕获这个异常。

```typescript
// file1.ets ArkTS1.2
export function foo() {
  throw new Error("123");
}

// file2.ets ArkTS1.1
import { foo } from "1.1";

try {
  foo();
} catch (e) {
  (e as Error).message; // "123"
}
```

### ArkTS1.2中使用TS

#### 文件导入

在ArkTS1.2中使用`import`函数导入ArkTS1.1的文件相关的内容，包含函数，类，对象等。

```typescript
// file1.ts
export function func(){}
export class A{}
export let a: A = new A();

// file2.ets ArkTS1.2
import { func, A, a} from './file1'
```

#### 类实例化

在ArkTS1.1中可以使用从ArkTS1.2中导入的类，用new来创建该类的实例。可以访问实例的方法和属性。也可以使用ArkTS1.1的类扩展ArkTS1.2的类后创建实例对象。

```typescript
// file1.ts
export class A {}
export class B extends A {}
interface interA {}
export class C implements interA {}

// file2.ets ArkTS1.2
import { A, B, C } from "file1";
let a = new A();
let b = new B();
let c = new C();
```

#### 属性读写

在ArkTS1.2中可以读写从TS中导入对象。

```typescript
// file1.ts
export class Person {
  name: string = "unknown"
}

// file2.ets ArkTS1.2
import { Person } from "file1";
let a = new Person();
let b = a.name; // "unknown"
a.name = "John";
```

#### 函数调用

在ArkTS1.2中可以调用从TS中导入函数。

```typescript
// file1.ts
export let func = () => {
  console.log(123);
};
export function foo1() {}
export function foo2(a: number, b: number): number {
  return a + b;
}

// file2.ets ArkTS1.2
import { func, foo1, foo2 } from "file1";
func();
foo1();
foo(1.5, 2.5);
```

#### 对象方法调用

在ArkTS1.2中可以调用从TS中导入的对象，并调用该对象的方法。

```typescript
// file1.ts
export class A {
  function log() {
    console.log(123)
  }
}
class B {
  foo() : void {}
}
export class C extends B {
  override foo() : void { console.log('D.foo') }
}
interface interA {
  foo: () => void;
}
export let itA: InterA = {
  foo: () => { console.log('interface log')) }
}
export let arr = new Array<number>(1, 2, 3);

// file2.ets ArkTS.12
import { A, C, itA, arr } from 'file1'
let a = new A()
a.foo()
let c = new C()
c.foo()  // Output: D.foo
itA.foo()
arr.push(4)
```

#### 参数传递

在ArkTS1.2中可以调用从TS中导入的函数，并将参数传递至TS。

```typescript
// file1.ts
export function foo(a: Array<string>) {
  console.log(a[0]);
}
export class C {
  static foo(a: Array<string>) {
    console.log(a[0]);
  }
  bar(a: Array<string>) {
    console.log(a[0]);
  }
}
export interface Iface {
  foo(a: Array<string>): void;
}

// file2.ets ArkTS1.2
import { foo, C, Iface } from "file1";

foo(["Hi", "Bye"]); // Output: Hi
C.foo(["Hi", "Bye"]); // Output: Hi
new C().bar(["Hi", "Bye"]); // Output: Hi

function baz(i: Iface) {
  i.foo(["Hi", "Bye"]); // OK
}
```

#### 异常处理

TS中定义一个异常的实例，可以在ArkTS1.2中捕获这个异常。

```typescript
// file1.ts
export function foo() {
  throw new Error("123")
}

// file2.ets ArkTS1.2
import { foo } from "./file1";

try {
  foo();
} catch (e) {
  (e as Error).message; // '123'
}
```

### ArkTS1.2中使用JS

#### 文件导入

```typescript
// file1.js
export function func(){}
export class A{}
export let a: A = new A();

// file2.ets ArkTS1.2
let mod: ESValue = ESValue.load('./file1')
let func: ESValue = mod.getProperty('func')
let A: ESValue = mod.getProperty('A')
let a: ESValue = mod.getProperty('a')
```

#### 类实例化

可以在ArkTS1.2中创建新的JS类，通过ESValue创建JS类的实例。

```typescript
// file1.js
export class A {}

// file2.ets ArkTS1.2
let mod: ESValue = ESValue.load("js");
let A: ESValue = module.getProperty("A");
let a: ESValue = A.instantiate();  // 创建A的实例，这个实例被包装在a中
```

#### 属性读写

在ArkTS1.2中可以访问JS类实例的字段和方法。

```typescript
// file1.js
export class A {
  name = "unknown"
}

// file2.ets ArkTS1.2
let module = ESValue.load('./file1')
let A = module.getProperty('A');
let a = A.instantiate()
b.getProperty('name').toString()  // "unknown"
a.setProperty('name', ESValue.wrap('John'))
b.getProperty('name').toString()  // "John"
```

#### 函数调用

在ArkTS1.2中可以通过ESValue来调用JS的函数。

```typescript
// file1.js
export function foo() {
    return 100
}

// file2.ets ArkTS1.2
let foo: ESValue = ESValue.load("./file1").getProperty("foo");
let res: ESValue = foo.invoke();
let resNum: string = res.toNumber();  // 100
```

#### 对象方法调用

在ArkTS1.2中可以通过ESValue来调用JS的对象的方法。

```typescript
//file1.js
export class A {
  sayHi(msg: string) {
    console.log(msg)
    return msg
  }
  static getInstance() {
    return new A()
  }
}

//file2.ets  ArkTS1.2
let A = ESValue.load('./file1').getProperty('A')
let a: ESValue = A.invokeMethod('getInstance')  // 调用静态方法
let msg: ESValue = a.invokeMethod('sayHi', ESValue.wrap('hello'))  // 调用实例方法, 打印hello
msg.toString()  // 'hello'
```

#### 参数传递

在ArkTS1.2中可以通过ESValue来调用JS的函数将参数传递至JS。

```typescript
// file1.js
export function foo(msg, count) {
  for (let i = 0; i < count; ++i) {
    console.log(msg)
  }
}

// file2.ets ArkTS1.2
let foo = ESValue.load("./file1").getProperty("foo");
foo.invoke(ESValue.wrap("hello"), ESValue.wrap(3));  // 打印3次hello
```

#### 异常处理

在JS中定义一个异常的实例，可以在ArkTS1.2中ESValue来获取这个异常。

```typescript
// file1.js
export function foo() {
  throw new Error('123')
}

// file2.ets  ArkTS1.2
let foo = ESValue.load('./file1').getProperty('foo')
try {
  foo.invoke()
} catch(e) {
  (e as Error).message  // '123'
}
```

## 交互限制

### 在ArkTS1.2中使用ArkTS1.1

#### ArkTS1.1给ArkTS1.2传参或赋值给Object类型

- ArkTS1.1语法

```typescript
// fiel1.ets
export function foo(obj: Object) {}
export class A {
  data: Object = 0;
}

// file2.ets
import { foo, A } from "./file1";

class X {}
foo(new X());
interface Y {
  s: string;
}
let y: Y = { s: "Hi" };
let a = new A();
a.data = y;
```

- ArkTS1.2语法

```typescript
// fiel1.ets ArkTS1.2
export function foo(obj: Object) {}
// solution: export function foo(obj: Any) {}
export class A {
  data: Object = 0;
}
// solution: export class A { data: Any = ESValue.wrap(0) }

// file2.ets ArkTS1.1
import { foo, A } from "./file1";

class X {}
foo(new X()); // 运行时报错
interface Y {
  s: string;
}
let y: Y = { s: "Hi" };
let a = new A();
a.data = y; // 运行时报错
```

- 编译报错信息：
  nan
- 运行时报错信息：
  runtime type cast error
- 适配建议：
  nan
- 变更理由：
  nan

---

#### ArkTS1.1的Object内置方法作用在ArkTS1.2对象上

- ArkTS1.1语法

```typescript
// file2.ets
export class X {
  a = 1;
}

// file1.ets
import { X } from "./file2";
function foo(prx: Object) {
  Object.getOwnPropertyDescriptor(prx, "a"); // not undefined
  Object.getOwnPropertyDescriptors(prx); // not {}
  Object.getOwnPropertyNames(prx); // ['a']
  Object.hasOwn(prx, "a"); // true
  Object.isExtensible(prx); // true
  Object.isFrozen(prx); // false
  Object.isSealed(prx); // false
  Object.keys(prx); // ['a']
  Object.setPrototypeOf(prx, {}); // OK
  Object.values(prx); // [1]
  prx.hasOwnProperty("a"); // true
  prx.propertyIsEnumerable("a"); // true
}

foo(new X());
```

- ArkTS1.2语法

```typescript
// file2.ets ArkTS1.2
export class X {
  a = 1;
}
// solution for Object.keys, case for Object.values is similar:
export function getKeys(prx: Object | ESValue): string[] | undefined {
  if (prx instanceof Object) {
    return Object.keys(prx);
  }
  return undefined;
}
// file1.ets ArkTS1.1
import { X, getKeys } from "./file2";
function myGetKeys(prx: Object) {
  let ret = getKeys(prx);
  if (ret == undefined) {
    // prx is dynamic
    return Object.keys(prx);
  }
  return ret;
}
export function foo(prx: Object) {
  Object.getOwnPropertyDescriptor(prx, "a"); // undefined
  Object.getOwnPropertyDescriptors(prx); // {}
  Object.getOwnPropertyNames(prx); // []
  Object.hasOwn(prx, "a"); // false
  Object.isExtensible(prx); // false
  Object.isFrozen(prx); // true
  Object.isSealed(prx); // true
  Object.keys(prx); // []
  myGetKeys(prx); // ['a']
  Object.setPrototypeOf(prx, {}); // 运行时报错
  Object.values(prx); // []
  prx.hasOwnProperty("a"); // false
  prx.propertyIsEnumerable("a"); // false
}

foo(new X());
```

- 编译报错信息：
  nan
- 运行时报错信息：
  object is sealed
- 适配建议：
  nan
- 变更理由：
  nan

---

#### ArkTS1.1的Reflect内置方法作用在ArkTS1.2对象上

- ArkTS1.1语法

```typescript
// file2.ets
export class X {
  a: string = "hello";
  getName() {
    return this.a;
  }
}

// file1.ets
import { X } from "./file2";
function foo(prx: Object) {
  Reflect.apply(prx.getName, { a: 12 }); // 12
  Reflect.defineProperty(prx, "newField", { value: 7 }); // true
  Reflect.deleteProperty(prx, "a"); // true
  Reflect.getOwnPropertyDescriptor(prx, "a"); // not undefined
  Reflect.ownKeys(prx); // ['a']
  Reflect.isExtensible(prx); // true
  Reflect.set(prx, "newField", 7); // true
  Reflect.setPrototypeOf(prx, {}); // true
}

foo(new X());
```

- ArkTS1.2语法

```typescript
// file2.ets  ArkTS1.2
export class X {
  a: string = 'hello'
  getName() { return this.a }
}

// solution for static ownKeys:
export getOwnKeys(prx: Object | ESValue): string[] | undefined {
  if (prx instanceof Object) { return Reflect.ownKeys(prx) }
  return undefined
}

// file1.ets ArkTS1.1
import {X, getOwnKeys} from './file2'
function myOwnKeys(prx: Object) {
  let ret = getOwnKeys(prx)
  if (ret == undefined) {  // prx is dynamic
    return Reflect.ownKeys(prx)
  }
  return ret
}

function foo(prx: Object) {
 Reflect.apply(prx.getName, {a: 12}) // 运行时报错
 Reflect.defineProperty(prx, 'newField', {value: 7})  // false
 Reflect.deleteProperty(prx, 'a')  // false
 Reflect.getOwnPropertyDescriptor(prx, 'a')  // undefined
 Reflect.ownKeys(prx)  // []
 myOwnKeys(prx)  // ['a']
 Reflect.isExtensible(prx) // false
 Reflect.set(prx, 'newField', 7)  // false
 Reflect.setPrototypeOf(prx, {})  // false
}

foo(new X())
```

- 编译报错信息：
  nan
- 运行时报错信息：
  runtime cast error
- 适配建议：
  nan
- 变更理由：
  nan

---

#### ArkTS1.2的Object内置方法作用在ArkTS1.1对象上

- ArkTS1.1语法

```typescript
// file1.ets
export function foo(prx: Object) {
  Object.assign({}, prx); // OK
  Object.entries(prx); // [a, 1]
  Object.keys(prx); // ['a']
  Object.values(prx); // [1]
  prx.hasOwnProperty("a"); // true
}

// file2.ets
import { foo } from "./file1";
class X {
  a = 1;
}
foo(new X());
```

- ArkTS1.2语法

```typescript
// file1.ets  ArkTS1.2
export function foo(prx: Object) {
  Object.assign({}, prx); // OK
  Object.entries(prx); // [a, 1]
  Object.keys(prx); // ['a']
  Object.values(prx); // [1]
  prx.hasOwnProperty("a"); // true
}

// file2.ets  ArkTS1.1
import { foo } from "./file1";
class X {
  a = 1;
}
foo(new X()); // 运行时报错
```

- 编译报错信息：
  nan
- 运行时报错信息：
  object is sealed
- 适配建议：
  nan
- 变更理由：
  nan

---

#### ArkTS1.2 Reflect内置方法作用在ArkTS1.1对象

- ArkTS1.1语法

```typescript
// file1.ets
export function foo(prx: Object) {
  Reflect.get(prx, "a"); // 'hello'
  Reflect.set(prx, "a", "world"); // true
  Reflect.ownKeys(prx); // ['a']
}

// file2.ets
import { foo } from "./file1";
class X {
  a: string = "hello";
  getName() {
    return this.a;
  }
}
foo(new X());
```

- ArkTS1.2语法

```typescript
// file1.ets  ArkTS1.2
export function foo(prx: Object) {
  Reflect.get(prx, "a"); // 'hello'
  Reflect.set(prx, "a", "world"); // true
  Reflect.ownKeys(prx); // ['a']
}

// file2.ets  ArkTS1.1
import { foo } from "./file1";
class X {
  a: string = "hello";
  getName() {
    return this.a;
  }
}
foo(new X()); // 运行时报错
```

- 编译报错信息：
  nan
- 运行时报错信息：
  runtime cast error
- 适配建议：
  nan
- 变更理由：
  nan

### ArkTS1.1中使用ArkTS1.2

#### ArkTS1.1 Object内置方法作用在ArkTS1.2对象

- ArkTS1.1语法

```typescript
// file1.ets
export function foo(prx: ESValue) {
  Object.getOwnPropertyDescriptor(prx, "a"); // not undefined
  Object.getOwnPropertyDescriptors(prx); // not {}
  Object.getOwnPropertyNames(prx); // ['a']
  Object.hasOwn(prx, "a"); // true
  Object.isExtensible(prx); // true
  Object.isFrozen(prx); // false
  Object.isSealed(prx); // false
  Object.keys(prx); // ['a']
  Object.setPrototypeOf(prx, {}); // OK
  Object.values(prx); // [1]
  prx.hasOwnProperty("a"); // true
  prx.propertyIsEnumerable("a"); // true
}

// file2.ets
import { foo } from "./file1";
class X {
  a = 1;
}
foo(new X());
```

- ArkTS1.2语法

```typescript
// solution for Object.keys, case for Object.values is similar:
// file0.ets  ArkTS1.2
export function getKeys(prx: Object | ESValue): string[] | undefined {
  if (prx instanceof Object) {
    return Object.keys(prx);
  }
  return undefined;
}

// file1.ets ArkTS1.1
import { getKeys } from "./file0";
function myGetKeys(prx: ESValue) {
  let ret = getKeys(prx);
  if (ret == undefined) {
    // prx is dynamic
    return Object.keys(prx);
  }
  return ret;
}
export function foo(prx: Object) {
  Object.getOwnPropertyDescriptor(prx, "a"); // undefined
  Object.getOwnPropertyDescriptors(prx); // {}
  Object.getOwnPropertyNames(prx); // []
  Object.hasOwn(prx, "a"); // false
  Object.isExtensible(prx); // false
  Object.isFrozen(prx); // true
  Object.isSealed(prx); // true
  Object.keys(prx); // []
  myGetKeys(prx); // ['a']
  Object.setPrototypeOf(prx, {}); // 运行时报错
  Object.values(prx); // []
  prx.hasOwnProperty("a"); // false
  prx.propertyIsEnumerable("a"); // false
}

// file2.ets  ArkTS1.2
import { foo } from "./file1";
class X {
  a = 1;
}
foo(new X());
```

- 编译报错信息：
  nan
- 运行时报错信息：
  object is sealed
- 适配建议：
  根据这些变化重新适配代码，或者避免使用这些内置底层接口。
- 变更理由：
  ArkTS1.2对象在动态上下文中没有own property，表现为sealed，不能修改对象布局。

---

#### ArkTS1.1 Reflect内置方法作用在ArkTS1.2对象

- ArkTS1.1语法

```typescript
// file1.ets
import {foo} from './file1'
export class X {
  a: string = 'hello'
  getName() { return this.a }
}

// file2.ets
improt {X} from './file1'
function foo(prx: ESValue) {
 Reflect.apply(prx.getName, {a: 12}) // 12
 Reflect.defineProperty(prx, 'newField', {value: 7})  // true
 Reflect.deleteProperty(prx, 'a')  // true
 Reflect.getOwnPropertyDescriptor(prx, 'a')  // not undefined
 Reflect.ownKeys(prx)  // ['a']
 Reflect.isExtensible(prx) // true
 Reflect.set(prx, 'newField', 7)  // true
 Reflect.setPrototypeOf(prx, {})  // true
}
foo(new X())
```

- ArkTS1.2语法

```typescript
// solution for static ownKeys:
// file0.ets ArkTS1.2
export getOwnKeys(prx: Object | ESValue): string[] | undefined {
  if (prx instanceof Object) { return Reflect.ownKeys(prx) }
  return undefined
}

// file1.ets ArkTS1.1
import {getOwnKeys} from './file0'
export function myOwnKeys(prx: ESValue) {
  let ret = getOwnKeys(prx)
  if (ret == undefined) {  // prx is dynamic
    return Reflect.ownKeys(prx)
  }
  return ret
}

export function foo(prx: ESValue) {
 Reflect.apply(prx.getName, {a: 12}) // 运行时报错
 Reflect.defineProperty(prx, 'newField', {value: 7})  // false
 Reflect.deleteProperty(prx, 'a')  // false
 Reflect.getOwnPropertyDescriptor(prx, 'a')  // undefined
 Reflect.ownKeys(prx)  // []
 myOwnKeys(prx)  // ['a']
 Reflect.isExtensible(prx) // false
 Reflect.set(prx, 'newField', 7)  // false
 Reflect.setPrototypeOf(prx, {})  // false
}

// file2.ets  ArkTS1.2
improt {foo} from './file1'
export class X {
  a: string = 'hello'
  getName() { return this.a }
}
foo(new X())
```

- 编译报错信息：
  nan
- 运行时报错信息：
  runtime cast error
- 适配建议：
  根据这些变化重新适配代码，或者避免使用这些内置底层接口
- 变更理由：
  ArkTS1.2对象在动态上下文中没有own property，表现为sealed，不能修改对象布局。

---

#### ArkTS1.2动态import ArkTS1.1

- ArkTS1.1语法

```typescript
// file1.ets
export class A {}

// file2.ets
let mod = await import("./file1");
let A: ESObject = mod.A;
let a = new A() as A;

// 动态import class function enum 变量
```

- ArkTS1.2语法

```typescript
// file1.ets  ArkTS1.1
export class A {}

// file2.ets   ArkTS1.2
let mod = ESValue.load("./file1");
let A: ESValue = mod.getProperty("A");
let a = A.instantiate() as A;
```

- 编译报错信息：
  SyntaxError: Unexpected token, expected an identifier.
- 运行时报错信息：
  不涉及
- 适配建议：
  使用ESValue接口动态导入模块和调用接口
- 变更理由：
  ArkTS1.2没有动态import语法，使用ESValue接口动态导入动态模块。

---

#### ArkTS1.2创建ArkTS1.1的没有无参构造函数的类的对象字面量

- ArkTS1.1语法

```typescript
// file1.ets
export class X {
  name: string;
  constructor(arg: string) {
    this.name = arg;
  }
}
// file2.ets
import { X } from "./file1";
let x: X = { name: "hello" };
```

- ArkTS1.2语法

```typescript
// file1.ets  ArkTS1.1
export class X {
  name: string;
  constructor(arg: string) {
    this.name = arg;
  }
}
// file2.ets  ArkTS1.2
import { X } from "./file1";
let x: X = { name: "hello" }; // 编译报错
```

- 编译报错信息
  type X has no parameterless constructor
- 运行时报错信息
  不涉及
- 适配建议
  使用new:
  let x: X = new X('hello')
- 变更理由
  ArkTS1.2的语法限制

---

#### ArkTS1.2创建ArkTS1.1具有二义性的对象字面量

- ArkTS1.1语法

```typescript
// file1.ets
export class X {
  name: string = "";
}
export interface Y {
  name: string;
  age?: number;
}

// file2.ets
import { X, Y } from "./file1";
let x: X | Y = { name: "hello" };
```

- ArkTS1.2语法

```typescript
// file1.ets  ArkTS1.1
export class X {
  name: string = "";
}
export interface Y {
  name: string;
  age?: number;
}

// file2.ets  ArkTS1.2
import { X, Y } from "./file1";
let x: X | Y = { name: "hello" }; // 编译报错
```

- 编译报错信息
  object literal is ambiguous for the type X | Y
- 运行时报错信息
  不涉及
- 适配建议
  使用 as确定类型
  let x: X | Y = {name: 'hello'} as X
- 变更理由
  ArkTS1.2的语法限制

---

#### ArkTS1.2创建ArkTS1.1的类的对象字面量

- ArkTS1.1语法

```typescript
// file1.ets
export class A {
  name: string = "";
}

// file2.ets
import { A } from "./file1";
let a: A = { name: "hello" }; // let a = {}， a.name = 'hello'

a instanceof A; // false
```

- ArkTS1.2语法

```typescript
// file1.ets ArkTS1.1
export class A {
  name: string = "";
}

// file2.ets ArkTS1.2
import { A } from "./file1";
let a: A = { name: "hello" }; // let a = new A(), a.name = 'hello'

a instanceof A; // true
```

- 编译报错信息
  不涉及
- 运行时报错信息
  不涉及
- 适配建议
  不要使用instanceof 判断字面量类型
- 变更理由
  ArkTS1.2的语义变更

### ArkTS1.2中使用TS

#### ArkTS1.2访问TS独有类型的实体

实体类型如下所示:

- any
- unknown
- symbol
- Function
- object literal (比如{x: number, y: string})
- mixing enum (比如enum X {a = 0, b = '1'})
- call signature (比如{(arg: number): string})
- constructor signature (比如{new(): Object}
- index signature (比如{[index: number]: string})
- intersection (比如TypeA & TypeB)
- keyof (比如interface X<T> { props: keyof T})
- typeof(比如let p = {x: 1, y: ''}, let q: typeof p)
- indexed access type( 比如 MyArray = [{ name: 'Alice', age: 15 }] type Person = typeof MyArray[number])
- conditional types （比如 type Swap<T extends A | B> = T extends A ? B : A)
- mapped types (比如 type A<T> = {[K in keyof T]: T[K]})
- template literal types (比如type AB = 'A' | 'B', type AllLocaleIDs = `${AB}_id`)
- 工具类型如下所示：
  - Pick<Type, Keys>
  - Omit<Type, Keys>
  - Exclude<UnionType, ExcludedMembers>
  - Extract<Type, Union>
  - NonNullable<Type>
  - Parameters<Type>
  - ConstructorParameters<Type>
  - ReturnType<Type>
  - InstanceType<Type>
  - NoInfer<Type>
  - ThisParameterType<Type>
  - OmitThisParameter<Type>
  - ThisType<Type>
  - Uppercase<StringType>
  - Lowercase<StringType>
  - Capitalize<StringType>
  - Uncapitalize<StringType>
- TS语法

```typescript
// file1.ts
export let obj: SomeType; // SomeType是某个TS独有类型

// file2.ets
import { obj } from "./file1";
let val = obj.prop;
obj.prop = 1;
obj.foo();
obj();
let item = obj[0];
```

- ArkTS1.2语法

```typescript
// file1.ts
export let obj: SomeType;
// 从ArkTS1.2看来，这个声明为
// export let obj: ESValue

// file2.ets ArkTS1.2
import { obj } from "./file1";
obj.setProperty("prop", ESValue.wrap(1));
```

- 编译报错信息：
  - obj does not have property prop
  - obj does not have property prop
  - obj does not have method foo
  - obj is not callable
  - obj is not indexable
- 运行时报错信息：
  不涉及。
- 适配建议：
  使用ESValue接口进行交互。
- 变更理由：
  ArkTS1.2中不支持这些类型。

---

#### ArkTS1.2 for-of遍历自定义TS可迭代对象

- TS语法

```typescript
// file1.ts
export class MyIter<T> {
  [Symbol.iterator](): IterableIterator<T> {...}
}

// file2.ets
import {MyIter} from './file1'
let m = new MyIter<number>()
for (let a of m) { doSomething(a as number) }
```

- ArkTS1.2语法

```typescript
// file1.ts
export class MyIter<T> {
  [Symbol.iterator](): IterableIterator<T> {...}
}

// file2.ets  ArkTS1.2
import {MyIter} from './file1'
let m = new MyIter<number>();
let eo = ESValue.wrap(m)
for (let a of eo) {
  doSomething(a.toNumber())
}
```

- 编译报错信息：
  m is not iterable
- 运行时报错信息：
  nan
- 适配建议：
  转换为ESValue再进行用for-of遍历
- 变更理由：
  ArkTS1.2和TS的可迭代的定义不同。ArkTS1.2中没有Symbol.iterator方法，无法识别自定义的ts可迭代对象

---

#### Object内置方法作用在ArkTS1.2对象

- TS语法

```typescript
// file1.ts
export function foo(prx: any) {
  Object.getOwnPropertyDescriptor(prx, "a"); // not undefined
  Object.getOwnPropertyDescriptors(prx); // not {}
  Object.getOwnPropertyNames(prx); // ['a']
  Object.hasOwn(prx, "a"); // true
  Object.isExtensible(prx); // true
  Object.isFrozen(prx); // false
  Object.isSealed(prx); // false
  Object.keys(prx); // ['a']
  Object.setPrototypeOf(prx, {}); // OK
  Object.values(prx); // [1]
  prx.hasOwnProperty("a"); // true
  prx.propertyIsEnumerable("a"); // true
}

// file2.ets
import { foo } from "./file1";
class X {
  a = 1;
}
foo(new X());
```

- ArkTS1.2语法

```typescript
// file1.ts
export function foo(prx: any) {
 Object.getOwnPropertyDescriptor(prx, 'a') // undefined
 Object.getOwnPropertyDescriptors(prx) // {}
 Object.getOwnPropertyNames(prx) // []
 Object.getOwnPropertySymbols(prx)) // []
 Object.hasOwn(prx, 'a')  // false
 Object.isExtensible(prx)  // false
 Object.isFrozen(prx)  // true
 Object.isSealed(prx)  // true
 Object.keys(prx)  // []
 Object.setPrototypeOf(prx, {})  // 运行时报错
 Object.values(prx)  // []
 prx.hasOwnProperty('a')  // false
 prx.propertyIsEnumerable('a')  // false
}

// file2.ets
import {foo} from './file1'
class X { a = 1 }
foo(ESValue.wrap(new X()))
```

- 编译报错信息：
  parameter type does not match
- 运行时报错信息：
  object is sealed
- 适配建议：
  根据这些变化重新适配代码，或者避免使用这些内置底层接口
- 变更理由：
  ArkTS1.2对象在动态上下文中没有own property，表现为sealed，不能修改对象布局。

---

#### Reflect内置方法作用在ArkTS1.2对象

- TS语法

```typescript
// file1.ts
export function foo(prx: any) {
  Reflect.apply(prx.getName, { a: 12 }); // 12
  Reflect.defineProperty(prx, "newField", { value: 7 }); // true
  Reflect.deleteProperty(prx, "a"); // true
  Reflect.getOwnPropertyDescriptor(prx, "a"); // not undefined
  Reflect.ownKeys(prx); // ['a']
  Reflect.isExtensible(prx); // true
  Reflect.set(prx, "newField", 7); // true
  Reflect.setPrototypeOf(prx, {}); // true
}

// file2.ets
import { foo } from "./file1";
class X {
  a: string = "hello";
  getName() {
    return this.a;
  }
}
foo(new X());
```

- ArkTS1.2语法

```typescript
// file1.ts
export function foo(prx: any) {
  Reflect.apply(prx.getName, { a: 12 }); // 运行时报错
  Reflect.defineProperty(prx, "newField", { value: 7 }); // false
  Reflect.deleteProperty(prx, "a"); // false
  Reflect.getOwnPropertyDescriptor(prx, "a"); // undefined
  Reflect.ownKeys(prx); // []
  Reflect.isExtensible(prx); // false
  Reflect.set(prx, "newField", 7); // false
  Reflect.setPrototypeOf(prx, {}); // false
}

// file2.ets
import { foo } from "./file1";
class X {
  a: string = "hello";
  getName() {
    return this.a;
  }
}
foo(ESValue.wrap(new X()));
```

- 编译报错信息：
  parameter type does not match
- 运行时报错信息：
  runtime cast error
- 适配建议：
  根据这些变化重新适配代码，或者避免使用这些内置底层接口
- 变更理由：
  ArkTS1.2对象在动态上下文中没有own property，表现为sealed，不能修改对象布局。

---

#### ArkTS1.2处理ts非常规异常

- TS语法

```typescript
// file1.ts
export function foo() {
  throw 123;
}

// file2.ets
import { foo } from "./file1";

try {
  foo();
} catch (e) {
  console.log(e as number); // 123
}
```

- ArkTS1.2语法

```typescript
// file1.ts
export function foo() {
  throw 123;
}

// file2.ets  // ArkTS1.2
import { foo } from "./file1";

try {
  foo();
} catch (e) {
  let err: ESValue = (e as ESError).getValue();
  err.toNumber(); // 123
}
```

- 编译报错信息：
  ArkTS1.2 only catch a Error instance
- 运行时报错信息：
  不涉及
- 适配建议：
  ArkTS1.2只能catch Error实例，针对非常规的ts异常对象，交互是会被包装到ESError中，通过getValue()方法可以获取包装了原始异常对象的ESValue实例
- 变更理由：
  ArkTS1.2中throw和catch的对象只能是Error的实例

---

#### ArkTS1.2判断TS boxed type类型

- TS语法

```typescript
// file1.ts
export let a = new Number(123);
export let b = new Boolean(true);
export let c = new String("hello");
typeof a; // 'object'
typeof b; // 'object'
typeof c; // 'object'

//file2.ets
import { a, b, c, d, e } from "./fiel1";
typeof a; // 'object'
typeof b; // 'object'
typeof c; // 'object'
```

- ArkTS1.2语法

```typescript
// file1.ts
export let a = new Number(123);
export let b = new Boolean(true);
export let c = new String("hello");
typeof a; // 'object'
typeof b; // 'object'
typeof c; // 'object'

//file2.ets  ArkTS1.2
import { a, b, c, d, e } from "./fiel1";
typeof a; // 'number'
typeof b; // 'boolean'
typeof c; // 'string'
```

- 编译报错信息：
  不涉及
- 运行时报错信息：
  不涉及
- 适配建议：
  避免使用boxed类型，或者避免对boxed类型进行typeof
- 变更理由：
  ArkTS1.2不区分基本类型和boxed类型，因此js的boxed对象在interop时会被unboxed成基本类型的值

---

#### ArkTS1.2动态import TS

- TS语法

```typescript
// file1.ts
export class A {}

// file2.ets
let mod = await import("./file1");
let A: ESObject = mod.A;
let a = new A() as A;
```

- ArkTS1.2语法

```typescript
// file1.ets ts
export class A {}

// file2.ets   ArkTS1.2
let mod = ESValue.load("./file1");
let A: ESValue = mod.getProperty("A");
let a = A.instantiate() as A;
```

- 编译报错信息：
  SyntaxError: Unexpected token, expected an identifier.
- 运行时报错信息：
  不涉及
- 适配建议：
  使用ESValue接口动态导入模块和调用接口
- 变更理由：
  ArkTS1.2没有动态import语法，使用ESValue接口动态导入动态模块。

---

#### ArkTS1.2创建TS的类的对象字面量

- TS语法

```typescript
// file1.ts
export class A {
  name: string = "";
}

// file2.ets
import { A } from "./file1";
let a: A = { name: "hello" };

a instanceof A; // false
```

- ArkTS1.2语法

```typescript
// file1.ts
export class A {
  name: string = "";
}

// file2.ets ArkTS1.2
import { A } from "./file1";
let a: A = { name: "hello" };

a instanceof A; // true
```

- 编译报错信息：
  不涉及
- 运行时报错信息：
  不涉及
- 适配建议：
  不要使用instanceof 判断字面量类型
- 变更理由：
  ArkTS1.2的语义变更

### ArkTS1.2中使用JS

#### ArkTS1.2导出js实体

- JS语法

```typescript
// file1.js
export function foo() {}
export class A {}

// file2.ets
import { foo } from "./file1";
export { foo };

export { A } from "./file1";
```

- ArkTS1.2语法

```typescript
// file1.js
export function foo() {}
export class A {}

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
let A = mod.getProperty("A");

export { foo, A };
```

- 编译报错信息：
  ArkTS1.2 cannot export entities from js
- 运行时报错信息：
  不涉及
- 适配建议：
  直接从js文件导入使用
- 变更理由：
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2调用js函数和传参

- JS语法

```typescript
// file1.js
export function foo() {}
export function bar(a) {}

// file2.ets
import { foo, bar } from "./file1";
foo();
bar(123);
```

- ArkTS1.2语法

```typescript
// file1.js
export function foo() {}
export function bar(a) {}

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
let bar = mod.getProperty("bar");
foo.invoke();
bar.invoke(ESValue.wrap(123));
```

- 编译报错信息：
  - ArkTS1.2 cannot import js files directly
  - foo is not callable
- 运行时报错信息：
  不涉及
- 适配建议：
  调用ESValue的接口，接口接收参数为ESValue类型，传参时需要用wrap接口构造ESValue实例再传参。
- 变更理由：
  - ArkTS1.2中只能和有类型声明的文件进行交互。
  - ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景。

---

#### ArkTS1.2实例化js对象

- JS语法

```typescript
// file1.js
class foo {
  constructor(a) {}
}
// file2.ets
import { foo } from "./file1";
new foo(123);
```

- ArkTS1.2语法

```typescript
// file1.js
class foo {
  constructor(a) {}
}

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
foo.instantiate(ESValue.wrap(123));
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo is not constructor
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口实例化，接口接收参数为ESValue类型，传参时需要用wrap接口构造ESValue实例再传参
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2访问js属性

- JS语法

```typescript
// file1.js
export let foo = { name: "123" };
// file2.ets
import { foo } from "./file1";
foo.name;
foo.name = "456";
```

- ArkTS1.2语法

```typescript
// file1.js
export let foo = {name: '123'}

// file2.ets  // ArkTS1.2
let mod = ESValue.load('./file1')
let foo = mod.getProperty('foo')
foo.getProperty('name')
foo.setProperty('name', ESValue.wrap('456')）
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo does not have property 'name'
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口访问属性，接口接收参数为ESValue类型，传参时需要用wrap接口构造ESValue实例再传参
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2调用js方法和传参

- JS语法

```typescript
// file1.js
class Foo {
  bar(a) {}
}
export let foo = new Foo();
// file2.ets
import { foo } from "./file1";
foo.bar(123);
```

- ArkTS1.2语法

```typescript
// file1.js
class Foo {
  bar(a) {}
}

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
foo.invokeMethod("bar", ESValue.wrap(123));
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo does not have method 'bar'
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口调用方法，接口接收参数为ESValue类型，传参时需要用wrap接口构造ESValue实例再传参
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2访问js索引

- JS语法

```typescript
// file1.js
export let foo = { arr: [1, 2, 3] };
// file2.ets
import { foo } from "./file1";
let arr = foo.arr;
arr[1];
arr[3] = 4;
```

- ArkTS1.2语法

```typescript
// file1.js
export let foo = [1, 2, 3];

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
let arr = foo.getProperty("arr");
arr.getProperty(1);
arr.setProperty(3, ESValue.wrap(4));
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo is not indexable
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口访问索引，接口接收参数为ESValue类型，传参时需要用wrap接口构造ESValue实例再传参
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2转换js对象类型

- JS语法

```typescript
// file1.js
export let foo1 = { num: 123 };
export let foo2 = { bool: true };
export let foo3 = { str: "123" };
export let foo4 = { big: 123n };

// file2.ets
import { foo } from "./file1";
let a: number = foo1.num as number;
let a: boolean = foo2.bool as boolean;
let a: string = foo3.str as string;
let a: bigint = foo4.big as bigint;
```

- ArkTS1.2语法

```typescript
// file1.js
export let foo1 = { num: 123 };
export let foo2 = { bool: true };
export let foo3 = { str: "123" };
export let foo4 = { big: 123n };

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo1 = mod.getProperty("foo1");
let num = foo.getProperty("num");
let a1: number = num.toNumber();

let foo2 = mod.getProperty("foo2");
let bool = foo.getProperty("bool");
let a2: boolean = bool.toBoolean();

let foo3 = mod.getProperty("foo3");
let str = foo3.getProperty("str");
let a3: string = str.toString();

let foo4 = mod.getProperty("foo4");
let big = foo.getProperty("big");
let a4: bigint = big.toBigInt();
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  cannot cast ESValue to number
  cannot cast ESValue to boolean
  cannot cast ESValue to string
  cannot cast ESValue to bigint
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口转换类型
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2获取js对象类型

- JS语法

```typescript
// file1.js
export let foo = { num: 123 };

// file2.ets
import { foo } from "./file1";
typeof foo.num; // 'number'
```

- ArkTS1.2语法

```typescript
// file1.js
export let foo = 123;

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
let num = foo.getProperty("num");

num.typeOf(); // 'number'
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口获取类型
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2判断js对象类型

- JS语法

```typescript
// file1.js
export class Foo {}
export let foo = new Foo();

// file2.ets
import { Foo, foo } from "./file1";
foo instanceof Foo;
```

- ArkTS1.2语法

```typescript
// file1.js
export class Foo {}
export let foo = new Foo();

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let Foo = mod.getProperty("Foo");
let foo = mod.getProperty("foo");

foo.isInstanceOf(Foo);
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  Foo is not a type
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口判断类型
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2对js对象自增自减

- JS语法

```typescript
// file1.js
export let foo = { num: 0 };

// file2.ets
import { foo } from "./file1";
let a: number = 0;
a = foo.num++;
a = ++foo.num;
a = foo.num--;
a = --foo.num;
```

- ArkTS1.2语法

```typescript
// file1.js
export let foo = { num: 0 };

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
let a: number = 0;

// a = foo.num++
let num = foo.getProperty("num");
let tmp: number = num.toNumber();
a = tmp;
foo.setProperty("num", ESValue(tmp + 1));

// a = ++foo.num
num = foo.getProperty("num");
tmp = num.toNumber() + 1;
foo.setProperty("num", ESValue(tmp));
a = tmp;
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo does not have property 'num'
  foo.num is not number
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口转换为数字后再操作
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2对js对象进行一元运算

- JS语法

```typescript
// file1.js
export let foo = { num: 0 };
// file2.ets
import { foo } from "./file1";
+foo.num - foo.num;
!foo.num;
~foo.num;
```

- ArkTS1.2语法

```typescript
// file1.js
export let foo = { num: 0 };

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
let num =
  foo.getProperty("num") +
  // +foo.num
  num.toNumber() -
  // -foo.num
  num.toNumber();
// !foo.num
!num.toNumber();
// ~foo.num
~num.toNumber();
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo does not have property 'num'
  foo.num is not number
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口转换为数字后再操作
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2对js对象进行二元运算

- JS语法

```typescript
// file1.js
export let foo = { a: 1, b: 2 };

// file2.ets
import { foo } from "./file1";
let a = foo.a;
let b = foo.b;
a + b;
a - b;
a * b;
a / b;
a % b;
a ** b;
```

- ArkTS1.2语法

```typescript
// file1.js
export let foo = { a: 1, b: 2 };

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
let a = foo.getProperty("a").toNumber();
let b = foo.getProperty("b").toNumber();
a + b;
a - b;
a * b;
a / b;
a % b;
a ** b;
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo does not have property 'a'
  foo does not have property 'b'
  a is not number
  b is not number
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口转换为数字后再操作
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2 await js Promise对象

- JS语法

```typescript
// file1.js
async function foo(){}
export p = foo()

// file2.ets
import {p} from './file1'
async function bar() {
  await p
}
```

- ArkTS1.2语法

```typescript
// file1.js
async function foo(){}
export p = foo()

// file2.ets  // ArkTS1.2
let mod = ESValue.load('./file1')
let p = mod.getProperty('p')

async function bar() {
  await p.toPromise()
}
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  p is not Promise
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口转换为Promise对象后再await
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2对js数据进行比较

- JS语法

```typescript
// file1.js
export let foo = { a: 1, b: 2 };

// file2.ets
import { foo } from "./file1";
let a = foo.a;
let b = foo.b;
a > b;
a < b;
a >= b;
a <= b;
```

- ArkTS1.2语法

```typescript
// file1.js
export let a = 1;
export let b = 2;

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
let a = foo.getProperty("a").toNumber();
let b = foo.getProperty("b").toNumber();

a > b;
a < b;
a >= b;
a <= b;
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  a is not number
  b is not number
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口转换为数字后再操作
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2对js数据进行相等判断

- JS语法

```typescript
// file1.js
class A {}
export let a = new A();
export let b = new A();

// file2.ets
import { a, b } from "./file1";
a == b;
a != b;
a === b;
a !== b;
```

- ArkTS1.2语法

```typescript
// file1.js
class A {}
export let a = new A();
export let b = new A();

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let a = mod.getProperty("a");
let b = mod.getProperty("b");

a.areEqual(b);
!a.areEqual(b);
a.areStrictlyEqual(b);
!a.areStrictlyEqual(b);
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  a is not number
  b is not number
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue的接口判断
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2对js对象进行条件判断

- JS语法

```typescript
// file1.js
export let foo = { isGood: true };

// file2.ets
import { foo } from "./file1";

if (foo.isGood) {
}
```

- ArkTS1.2语法

```typescript
// file1.js
export let foo = { isGood: true };

// file2.ets
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");

let isGood = foo.getProperty("isGood").toBoolean();
if (isGood) {
}
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo does not have property 'isGood'
- 运行时报错信息
  nan
- 适配建议
  使用ESValue的接口转换为boolean
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2继承js的类

- JS语法

```typescript
// file1.js
export class A {}

// file2.ets
import { A } from "./file1";
class B extends A {}
let b = new B();
```

- ArkTS1.2语法

```typescript
// file1.js
export class A {}

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let A = mod.getProperty("A");

let B: ESValue = ESValue.defineClass("B", () => {}, undefined, undefined, A);
let b = B.instantiate();
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  A is not a class
- 运行时报错信息
  nan
- 适配建议
  使用ESValue的接口构造JS类并传递js父类
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### ArkTS1.2处理js非常规异常

- JS语法

```typescript
// file1.js
export function foo() {
  throw 123;
}

// file2.ets
import { foo } from "./file1";

try {
  foo();
} catch (e) {
  console.log(e as number); //123
}
```

- ArkTS1.2语法

```typescript
// file1.js
export function foo() {
  throw 123;
}

// file2.ets
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");

try {
  foo.invoke();
} catch (e) {
  let err: ESValue = (e as ESError).getValue();
  err.toNumber(); // 123
}
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  ArkTS1.2 only catch a Error instance
- 运行时报错信息
  不涉及
- 适配建议
  ArkTS1.2只能catch Error实例，针对非常规的js异常对象，交互是会被包装到ESError中，通过getValue()方法可以获取包装了原始异常对象的ESValue实例
- 变更理由
  ArkTS1.2中throw和catch的对象只能是Error的实例

---

#### ArkTS1.2访问js的boxed对象

- JS语法

```typescript
// file1.js
export let foo = {
  num: new Number(123),
  bool: new Boolean(true),
  str: new String("hello"),
};

// file2.ets
import { foo } from "./file1";
typeof foo.num; // 'object'
typeof foo.bool; // 'object'
typeof foo.str; // 'object'
```

- ArkTS1.2语法

```typescript
// file1.js
export let foo = {
  num: new Number(123),
  bool: new Boolean(true),
  str: new String("hello"),
};

// file2.ets
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");

foo.getProperty("num").typeOf(); // 'number'
foo.getProperty("bool").typeOf(); // 'boolean'
foo.getProperty("str").typeOf(); // 'string'
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo does not have properties 'num', 'bool', 'str'
- 运行时报错信息
  不涉及
- 适配建议
  避免使用boxed类型，或者避免对boxed类型进行typeof
- 变更理由
  ArkTS1.2不区分基本类型和boxed类型，因此js的boxed对象在interop时会被unboxed成基本类型的值

---

#### ArkTS1.2遍历js对象

- JS语法

```typescript
// file1.js
export let foo = { arr: [1, 2, 3] };
// file2.ets
import { foo } from "./file1";
let arr = foo.arr;
let len = arr.length as number;
for (let i = 0; i < len; ++i) {
  arr[i] as number;
  arr[i] = 0;
}
```

- ArkTS1.2语法

```typescript
// file1.js
export let foo = { arr: [1, 2, 3] };

// file2.ets  ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
let arr = foo.getProerptyByName("arr");
let len = arr.getProerptyByName("length").toNumber();
for (let i = 0; i < len; ++i) {
  arr.getPropertyByIndex(i).toNumber();
  arr.setPropertyByIndex(i, ESValue.wrap(0));
}
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo does not have property 'arr'
  arr does not have property 'length'
  arr is not indexable
- 运行时报错信息
  不涉及
- 适配建议
  使用ESValue接口访问索引和属性
- 变更理由
  ArkTS1.2中只能和有类型声明的文件进行交互。
  ArkTS1.2中限制ESValue的动态行为，形成动静态更清晰的界限，减少开发者滥用ESValue导致性能劣化的场景

---

#### js调用ArkTS1.2函数和传参

- JS语法

```typescript
// file1.js
export function handle(cb) {
  let p = { name: "hello" };
  cb(p);
}

// file2.ets
import { handle } from "./file1";
interface Person {
  name: string;
}

function foo(p: Person) {}
let lambda = (p: Person) => {};

handle(foo);
handle(lambda);
```

- ArkTS1.2语法

```typescript
// file1.js
export function handle(cb) {
  let p = { name: "hello" };
  cb(p);
}

// file2.ets
let mod = ESValue.load("./file1");
let handle = mod.getProperty("handle");
interface Person {
  name: string;
}
function foo(p: Person) {}
// solution: function foo(p: ESValue) {}
let lambda = (p: Person) => {};
// solution: let lambda = (p: ESValue) => {}

handle.invoke(ESValue.wrap(foo));
handle.invoke(ESValue.wrap(lambda));
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo is not callable
- 运行时报错信息
  runtime cast error
- 适配建议
  确保传参匹配参数声明的类型
- 变更理由
  ArkTS1.2的函数运行时会检查参数类型，需要确保参数类型匹配

---

#### js增删改ArkTS1.2对象属性

- JS语法

```typescript
// file1.js
export function foo(obj) {
  obj.newField = 1; // 增加属性
  delete obj.data; // 删除属性
  obj.name = "123"; // 修改属性值（同类型）
  obj.name = { firstName: "456" }; // 修改属性值（不同类型）
}

// file2.ets
import { foo } from "./file1";
class X {
  name: string = "";
  data: number = 0;
}
foo(new X());
```

- ArkTS1.2语法

```typescript
// file1.js
export function foo(obj) {
  obj.newField = 1; // 增加属性   运行时报错
  delete obj.data; // 删除属性   运行时报错
  obj.name = "123"; // 修改属性值（同类型）OK
  obj.name = { firstName: "456" }; // 修改属性值（不同类型）运行时报错
}

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
class X {
  name: string = "";
  data: number = 0;
}
foo.invoke(ESValue.wrap(new X()));
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo is not callable
- 运行时报错信息
  object is sealed
- 适配建议
  避免动态修改对象布局。需要新增的属性提前在类型中声明，需要删除的属性使用undefined置空。
- 变更理由
  ArkTS1.2的对象布局在编译时就确定了，不能动态修改

---

#### js Object内置方法作用在ArkTS1.2对象

- JS语法

```typescript
// file1.js
export function foo(prx) {
  Object.getOwnPropertyDescriptor(prx, "a"); // not undefined
  Object.getOwnPropertyDescriptors(prx); // not {}
  Object.getOwnPropertyNames(prx); // ['a']
  Object.hasOwn(prx, "a"); // true
  Object.isExtensible(prx); // true
  Object.isFrozen(prx); // false
  Object.isSealed(prx); // false
  Object.keys(prx); // ['a']
  Object.setPrototypeOf(prx, {}); // OK
  Object.values(prx); // [1]
  prx.hasOwnProperty("a"); // true
  prx.propertyIsEnumerable("a"); // true
}

// file2.ets
import { foo } from "./file1";
class X {
  a = 1;
}
foo(new X());
```

- ArkTS1.2语法

```typescript
// file1.js
export function foo(prx) {
 Object.getOwnPropertyDescriptor(prx, 'a') // undefined
 Object.getOwnPropertyDescriptors(prx) // {}
 Object.getOwnPropertyNames(prx) // []
 Object.getOwnPropertySymbols(prx)) // []
 Object.hasOwn(prx, 'a')  // false
 Object.isExtensible(prx)  // false
 Object.isFrozen(prx)  // true
 Object.isSealed(prx)  // true
 Object.keys(prx)  // []
 Object.setPrototypeOf(prx, {})  // 运行时报错
 Object.values(prx)  // []
 prx.hasOwnProperty('a')  // false
 prx.propertyIsEnumerable('a')  // false
}

// file2.ets  // ArkTS1.2
let mod = ESValue.load('./file1')
let foo = mod.getProperty('foo')
class X { a = 1 }
foo.invoke(ESValue.wrap(new X()))
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo is not callable
- 运行时报错信息
  object is sealed
- 适配建议
  根据这些变化重新适配代码，或者避免使用这些内置底层接口
- 变更理由
  ArkTS1.2对象在动态上下文中没有own property，表现为sealed，不能修改对象布局。

---

#### jsReflect内置方法作用在ArkTS1.2对象

- JS语法

```typescript
// file1.js
export function foo(prx) {
  Reflect.apply(prx.getName, { a: 12 }); // 12
  Reflect.defineProperty(prx, "newField", { value: 7 }); // true
  Reflect.deleteProperty(prx, "a"); // true
  Reflect.getOwnPropertyDescriptor(prx, "a"); // not undefined
  Reflect.ownKeys(prx); // ['a']
  Reflect.isExtensible(prx); // true
  Reflect.set(prx, "newField", 7); // true
  Reflect.setPrototypeOf(prx, {}); // true
}

// file2.ets
import { foo } from "./file1";
class X {
  a: string = "hello";
  getName() {
    return this.a;
  }
}
foo(new X());
```

- ArkTS1.2语法

```typescript
// file1.js
export function foo(prx) {
  Reflect.apply(prx.getName, { a: 12 }); // 运行时报错
  Reflect.defineProperty(prx, "newField", { value: 7 }); // false
  Reflect.deleteProperty(prx, "a"); // false
  Reflect.getOwnPropertyDescriptor(prx, "a"); // undefined
  Reflect.ownKeys(prx); // []
  Reflect.isExtensible(prx); // false
  Reflect.set(prx, "newField", 7); // false
  Reflect.setPrototypeOf(prx, {}); // false
}

// file2.ets  // ArkTS1.2
let mod = ESValue.load("./file1");
let foo = mod.getProperty("foo");
class X {
  a: string = "hello";
  getName() {
    return this.a;
  }
}
foo.invoke(ESValue.wrap(new X()));
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo is not callable
- 运行时报错信息
  runtime cast error
- 适配建议
  根据这些变化重新适配代码，或者避免使用这些内置底层接口
- 变更理由
  ArkTS1.2对象在动态上下文中没有own property，表现为sealed，不能修改对象布局。

---

#### js对ArkTS1.2对象进行展开语法

- JS语法

```typescript
// file1.js
export function foo(obj) {
  let x = {...obj} // x will be { a = 1; b = 2; c = 3 }
  let {a, b, ...rest} = obj  // a will be 1, b will be 2, rest will be {c: 3}

// file2.ets
import {foo} from './file1'
class X { a = 1; b = 2; c = 3 }
foo(new X())

// class interface Record
```

- ArkTS1.2语法

```typescript
// file1.js
export function foo(obj) {
  let x = {...obj} // x will be empty object {}. because there is no own properties for static object
  // solution: let x = {a: obj.a, b: obj.b, c: obj.c}
  // keys + Reflect.get
  let {a, b, ...rest} = obj
  // a will be 1, b will be 2, rest will be empty object {}, because there is no own properties for static object
  // solution: let rest = {c: obj.c}

// file2.ets  // ArkTS1.2
let mod = ESValue.load('./file1')
let foo = mod.getProperty('foo')
class X { a = 1; b = 2; c = 3 }
foo.invoke(ESValue.wrap(new X()))
```

- 编译报错信息
  ArkTS1.2 cannot import js files directly
  foo is not callable
- 运行时报错信息
  不涉及
- 适配建议
  根据这些变化重新适配代码，或者避免使用解构语法。
- 变更理由
  ArkTS1.2对象在动态上下文中没有own property，相关解构操作会失效。

---

#### ArkTS1.2动态import JS

- JS语法

```typescript
ArkTS1.2动态导入JS
```

- ArkTS1.2语法

```typescript
不涉及;
```

- 编译报错信息
  SyntaxError: Unexpected token, expected an identifier.
- 运行时报错信息
  SyntaxError: Unexpected token, expected an identifier.
- 适配建议

```typescript
// file1.js
export class A {}

// file2.ets   ArkTS1.2
let mod = ESValue.load("./file1");
let A: ESValue = mod.getProperty("A");
let a = A.instantiate();
```

- 变更理由
  使用ESValue接口动态导入模块和调用接口

## ArkTS1.2并发场景下的交互

并发执行ArkTS1.1&ArkTS1.2混合代码的主要方式通过ArkTS1.2的上下文；ArkTS1.1中需要执行ArkTS1.1&ArkTS1.2混合代码的场景需要迁移到ArkTS1.2来保证易用性和性能。

### ArkTS1.2使用ArkTS1.1的场景

#### ArkTS1.2与ArkTS1.1的Promise互操作

```typescript
// file1.ets ArkTS1.1
export let p = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("foo");
  }, 300);
});
// file2.ets ArkTS1.2
import { p } from "file1";
// OK
p.then((s: String) => {
  console.log(s);
});
// OK
p.catch((e: Object) => {
  console.error(e);
});
// OK
p.finally(() => {
  console.log("Completed");
});
// OK
async function foo() {
  const result = await p;
}
```

#### ArkTS1.2与ArkTS1.1的async function互操作

```typescript
// file1.ets ArkTS1.1
export async function foo() {}
// file2.ets ArkTS1.2
import { foo } from "file1";
// OK, call foo
function baz() {
  foo();
}
// OK, await foo
await foo();
async function bar() {
  await foo();
}
// OK, use the return value as a 1.2 Promise
const p = foo();
```

#### ArkTS1.2单线程异步上下文与ArkTS1.1对象互操作

- 使用当前线程的动态上下文，规格同主线程规格

```typescript
// file1.ets ArkTS1.1
export let s = new String("123");
export function foo(arg: Object) {
  console.log(typeof arg);
  return 42;
}
// file2.ets ArkTS1.2
import { s, foo } from "file1";
function bar() {
  let p = new Promise<number>(
    (resolve: (v: number) => void, _: (error: Object) => void) => {
      // OK
      foo.invoke(s);
      resolve(42);
    }
  );
}
async function baz() {
  // OK
  foo.invoke(s);
}
```

#### ArkTS1.2多线程异步上下文与ArkTS1.1对象互操作

- 跨线程通信时，适用1.1线程间通信的规格，但sendData / onReceiveData不再支持，用1.2线程间通信代替
- 使用当前线程的动态上下文，规格同主线程规格

```typescript
// file1.ets ArkTS1.1
export let s = new String('123')
@concurrent
export function foo(arg: Object){
   console.log(typeof arg)
   return 42;
}
export function bar() {
  return foo(42); // 违反闭包原则，报错
}
// file2.ets ArkTS1.2
import { s, foo, bar } from 'file1'
// 1.2 Taskpool
function baz() {
  // OK. print 'object'
  taskpool.execute(foo, s);
  // NO. not allowed to call 1.1 non-concurrenct function
  taskpool.execute(bar);
}
// 1.2 EAWorker
let eaw : EAWorker = new EAWorker();
// OK. print 'object'
let p = eaw.run(foo, s);
// NO. not allowed to call 1.1 non-concurrenct function
let q = eaw.run(bar)
cont result = p.Await();
eaw.stop();
```

#### 协程不支持互操作

```typescript
// file1.ets ArkTS1.1
export let function foo() {}
export async function bar() {}
export let p = new Promise<number>(...)
// file2.ets ArkTS1.2
import {foo, bar, A, p} from 'file1'
async function baz() {
  foo(); // NO
  await bar(); // NO
  await p; // NO
}
launch(baz)  // NO
```

### ArkTS1.1使用ArkTS1.2的场景

#### ArkTS1.1与ArkTS1.2的Promise互操作

```typescript
// file1.ets ArkTS1.2
export let p = new Promise<String>(
  (resolve: (v: number) => void, _: (error: Object) => void) => {
    setTimeout(() => {
      resolve("foo");
    }, 300);
  }
);
// file2.ets ArkTS1.1
import { p } from "file1";
// OK
p.then((value) => {
  console.log(value);
});
// OK
p.catch((error) => {
  console.error(error);
});
// OK
p.finally(() => {
  console.log("Completed");
});
// OK
await p;
```

#### ArkTS1.1与ArkTS1.2的async function互操作

```typescript
// file1.ets ArkTS1.2
export async function foo() {}
// file2.ets ArkTS1.1
import { foo } from "file1";
// OK, call foo
function baz() {
  foo();
}
// OK, await foo
await foo();
async function bar() {
  await foo();
}
// OK, use the return value as a 1.1 Promise
const p = foo();
```

#### ArkTS1.1单线程异步上下文与ArkTS1.2对象互操作

- 主线程使用主线程规格，非主线程（Taskpool和Worker）不支持互操作

```typescript
// file1.ets ArkTS1.2
export class A {}
export function foo(arg: Object) {
  arg as A;
}
// file2.ets ArkTS1.1
import { foo, A } from "file1";
const p = new Promise((resolve, reject) => {
  foo(123); // RTE
  foo(new A()); // OK
  resolve("foo");
});
async function bar() {
  foo(123); // RTE
  foo(new A()); // OK
}
```

#### ArkTS1.1多线程异步上下文不支持互操作

- Taskpool和Worker上下文不支持互操作

```typescript
// file1.ets ArkTS1.2
export class A {}
export function foo(arg: Object) {
  arg as A;
}
// file2.ets ArkTS1.1
import { foo, A } from "file1";
foo(new A()); // OK
// file3.ets ArkTS1.1
import { foo, A } from "file1";
function bar() {
  // NO
  taskpool.execute(foo, new A());
}
// NO
let workerInstance = new worker.ThreadWorker("file2.ets");
```
