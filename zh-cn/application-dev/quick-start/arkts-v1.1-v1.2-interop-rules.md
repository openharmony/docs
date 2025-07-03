# ArkTS1.2与ArkTS1.1互操作规范

## ArkTS1.1中使用ArkTS1.2

### ArkTS1.2导出ArkTS1.1实体

**规则：** arkts-interop-d2s-export-entity

**级别：** error

ArkTS1.2中使用静态语义，不允许将导入ArkTS1.1模块中的实体重新导出。

确保模块之间的静态与动态边界清晰，防止动态模块中的不确定行为影响静态模块的类型安全和编译优化。

**ArkTS1.1**
```typescript
// file1.ets
export function foo() {}
export class X {}
export interface Y {}

// file2.ets
import { foo } from './file1';
export { foo };

export { X, Y } from './file1';
```

**ArkTS1.2**
```typescript
// file1.ets ArkTS1.1
export function foo() {}
export class X {}
export interface Y {}

// file2.ets ArkTS1.2
'use static'
import { foo } from './file1';
export { foo }; // 编译报错

export { X, Y } from './file2'; // 编译报错
```

### ArkTS1.2判断ArkTS1.1装箱类型

**规则：** arkts-interop-d2s-boxed-type

**级别：** error

在ArkTS1.2中，语言层面不再区分基本类型和装箱类型。因此，当与JS或ArkTS1.1进行互操作时，ArkTS1.2会自动拆箱，转换为对应的基本类型并使用。

避免使用装箱类型或对装箱类型进行typeof操作。

**ArkTS1.1**
```typescript
// file1.ets
export let a = new Number(123);
export let b = new Boolean(true);
export let c = new String('hello');
typeof a; // 'object'
typeof b; // 'object'
typeof c; // 'object'

//file2.ets
import { a, b, c } from './file1';
typeof a; // 'object'
typeof b; // 'object'
typeof c; // 'object'
```

**ArkTS1.2**
```typescript
// file1.ets ArkTS1.2
'use static'
export let a = new Number(123);
export let b = new Boolean(true);
export let c = new String('hello');
typeof a; // 'number'
typeof b; // 'boolean'
typeof c; // 'string'

//file2.ets  ArkTS1.1
import { a, b, c } from './file1';
typeof a; // 'number'
typeof b; // 'boolean'
typeof c; // 'string'
```

### ArkTS1.2使用ArkTS1.1的@Sendable和@Concurrent

**规则：** arkts-interop-d2s-no-concurrent-decorators

**级别：** error

ArkTS1.2的对象天然支持并发共享，不需要加@Sendable和@Concurrent注解。

**ArkTS1.1**
```typescript
// file1.ets
@Sendable
class X {}

@Concurrent
function foo() {}
```

**ArkTS1.2**
```typescript
// file1.ets
'use static'
class X {}

function foo() {}
```

### ArkTS1.1Object内置方法作用在ArkTS1.2对象

**规则：** arkts-interop-d2s-dynamic-object-on-static-instance

**级别：** error

ArkTS1.2对象在动态上下文中不能修改对象布局。

ArkTS1.1Object内置方法作用在ArkTS1.2对象需要重新适配代码。

**ArkTS1.1**
```typescript
// file1.ets
export function foo(prx: Object) {
  Object.getOwnPropertyNames(prx); // ["a"]
  Object.hasOwn(prx, 'a'); // true
  Object.keys(prx); // ["a"]
  Object.values(prx); // [1]
}

// file2.ets
import { foo } from './file1';
class X {
  a = 1;
}
foo(new X());
```

**ArkTS1.2**
```typescript
// Object.keys的解决方案，与Object.values的情况类似
// file0.ets  ArkTS1.2
'use static'
export function getKeys(prx: Object | ESValue): string[] | undefined {
  if (prx instanceof Object) {
    return Object.keys(prx);
  }
  return undefined;
}

// file1.ets ArkTS1.1
import { getKeys } from './file0';
function myGetKeys(prx: Object) {
  let ret = getKeys(prx);
  if (ret == undefined) {
    // prx is dynamic
    return Object.keys(prx);
  }
  return ret;
}
export function foo(prx: Object) {
  Object.getOwnPropertyNames(prx); // []
  Object.hasOwn(prx, 'a'); // false
  Object.keys(prx); // []
  myGetKeys(prx); // ['a']
  Object.values(prx); // []
}

// file2.ets  ArkTS1.2
'use static'
import { foo } from './file1';
class X {
  a = 1;
}
foo(new X());
```

### ArkTS1.1Reflect内置方法作用在ArkTS1.2对象

**规则：** arkts-interop-d2s-dynamic-reflect-on-static-instance

**级别：** error

ArkTS1.2对象在动态上下文中不能修改对象布局。

ArkTS1.1Reflect内置方法作用在ArkTS1.2对象需要重新适配代码。

**ArkTS1.1**
```typescript
// file1.ets
import { foo } from './file1';
export class X {
  a: string = 'hello';
  getName() {
    return this.a;
  }
}

// file2.ets
import { X } from './file1';
function foo(prx: Object) {
  Reflect.ownKeys(prx); // ['a']
  Reflect.set(prx, 'newField', 7); // true
}
foo(new X());
```

**ArkTS1.2**
```typescript
// static ownKeys的解决方案
// file0.ets ArkTS1.2
'use static'
export getOwnKeys(prx: Object | ESValue): string[] | undefined {
    if (prx instanceof Object) { return Reflect.ownKeys(prx) }
    return undefined
}

// file1.ets ArkTS1.1
import { getOwnKeys } from './file0'
export function myOwnKeys(prx: Object) {
    let ret = getOwnKeys(prx)
    if (ret == undefined) {  // prx是动态对象
        return Reflect.ownKeys(prx)
    }
    return ret
}

export function foo(prx: Object) {
    Reflect.ownKeys(prx)  // []
    myOwnKeys(prx)  // ['a']
    Reflect.set(prx, 'newField', 7)  // false
}

// file2.ets  ArkTS1.2
'use static'
import { foo } from './file1'
export class X {
    a: string = 'hello'
    getName() { return this.a }
}
foo(new X())
```

### ArkTS1.2Object内置方法作用在ArkTS1.1对象

**规则：** arkts-interop-d2s-static-object-on-dynamic-instance

**级别：** error

Object的接口参数类型为静态Object。ArkTS1.1对象在ArkTS1.2中不是静态Object实例，因此参数类型不匹配。

**ArkTS1.1**
```typescript
// file1.ets
export class X {
  a = 1;
}

// file2.ets
import { X } from 'file1';
export function foo(prx: Object) {
  Object.entries(prx); // [a, 1]
  Object.keys(prx); // ["a"]
  Object.values(prx); // [1]
}
foo(new X());
```

**ArkTS1.2**
```typescript
// file1.ets  ArkTS1.1
export class X {
  a = 1;
}

// file2.ets  ArkTS1.2
'use static'
import { X } from 'file1';
export function foo(prx: Object) {
  Object.entries(prx); // [a, 1]
  Object.keys(prx); // ["a"]
  Object.values(prx); // [1]
}
foo(new X()); // 编译报错
```

### ArkTS1.2Reflect内置方法作用在ArkTS1.1对象

**规则：** arkts-interop-d2s-static-reflect-on-dynamic-instance

**级别：** error

Reflect接口参数类型为静态Object。ArkTS1.1对象在ArkTS1.2中不是静态Object实例，因此参数类型不匹配。

**ArkTS1.1**
```typescript
// file1.ets  ArkTS1.1
class X {
  a: string = 'hello';
  getName() {
    return this.a;
  }
}

// file2.ets  ArkTS1.2
'use static'
import { X } from './file1';
export function foo(prx: Object) {
  Reflect.get(prx, 'a'); // 'hello'
  Reflect.set(prx, 'a', 'world'); // true
  Reflect.ownKeys(prx); // ['a']
}
foo(new X());
```

**ArkTS1.2**
```typescript
// file1.ets  ArkTS1.1
class X {
  a: string = 'hello';
  getName() {
    return this.a;
  }
}

// file2.ets  ArkTS1.2
'use static'
import { X } from './file1';
export function foo(prx: Object) {
  Reflect.get(prx, 'a'); // 'hello'
  Reflect.set(prx, 'a', 'world'); // true
  Reflect.ownKeys(prx); // ['a']
}
foo(new X()); // 编译报错
```

### ArkTS1.2动态导入ArkTS1.1

**规则：** arkts-interop-d2s-dynamic-import

**级别：** error

ArkTS1.2使用ESValue接口动态导入ArkTS1.1模块和调用接口。

**ArkTS1.1**
```typescript
// file1.ets
export class A {}

// file2.ets
let mod = await import('./file1');
let A: ESValue = mod.A;
let a = new A() as A;

// 动态导入class、function、enum变量
```

**ArkTS1.2**
```typescript
// file1.ets  ArkTS1.1
export class A {}

// file2.ets   ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let A: ESValue = mod.getProperty('A');
let a = A.instantiate() as A;
```

### ArkTS1.2创建ArkTS1.1的没有无参构造函数的类的对象字面量

**规则：** arkts-interop-d2s-object-literal-no-args-constructor

**级别：** error

由于ArkTS1.2的语法限制，当ArkTS1.2创建ArkTS1.1的没有无参构造函数的类的对象字面量时，需要使用new关键字和构造函数。

**ArkTS1.1**
```typescript
// file1.ets
export class X {
  name: string;
  constructor(arg: string) {
    this.name = arg;
  }
}
// file2.ets
import { X } from './file1';
let x = new X('hello');
```

**ArkTS1.2**
```typescript
// file1.ets  ArkTS1.1
export class X {
  name: string;
  constructor(arg: string) {
    this.name = arg;
  }
}
// file2.ets  ArkTS1.2
'use static'
import { X } from './file1';
let x: X = new X('hello') // 编译报错
```

### ArkTS1.2创建ArkTS1.1具有二义性的对象字面量

**规则：** arkts-interop-d2s-object-literal-no-ambiguity

**级别：** error

当一个对象的类型被声明为联合类型，而右侧实际赋值的是一个类的实例时，会引发类型系统的二义性（对象可以是联合类型的任一类型，但实际运行时明确是一个类的实例，这种差异会导致类型检查或运行时的不确定性）。

**ArkTS1.1**
```typescript
// file1.ets
export class X {
  name: string = '';
}
export interface Y {
  name: string;
  age?: number;
}

// file2.ets
import { X, Y } from './file1';
let x: X | Y = { name: 'hello' };
```

**ArkTS1.2**
```typescript
// file1.ets  ArkTS1.1
export class X {
  name: string = '';
}
export interface Y {
  name: string;
  age?: number;
}

// file2.ets  ArkTS1.2
'use static'
import { X, Y } from './file1';
let x: X | Y = { name: 'hello' }; //编译报错
let x: X | Y = new X('hello'); // OK
```

### ArkTS1.2创建ArkTS1.1的类的对象字面量

**规则：** arkts-interop-d2s-object-literal

**级别：** error

ArkTS1.2创建ArkTS1.1的类的对象字面量时，不要使用instanceof判断字面量类型。

**ArkTS1.1**
```typescript
// file1.ets
export class A {
  name: string = '';
}

// file2.ets
import { A } from './file1';
let a: A = { name: 'hello' }; // a是创建的对象自变量

a instanceof A; // false
```

**ArkTS1.2**
```typescript
// file1.ets ArkTS1.1
export class A {
  name: string = '';
}

// file2.ets ArkTS1.2
'use static'
import { A } from './file1';
let a: A = { name: 'hello' }; // a是创建的对象

a instanceof A; // true
```

## ArkTS1.2中使用ArkTS1.1

### ArkTS1.1判断ArkTS1.2装箱类型

**规则：** arkts-interop-s2d-boxed-type

**级别：** error

在ArkTS1.2中，语言层面不再区分基本类型和装箱类型。因此，当与JS或ArkTS1.1进行互操作时，ArkTS1.2会自动拆箱，转换为对应的基本类型并使用。

避免使用装箱类型或对装箱类型进行typeof操作。

**ArkTS1.1**
```typescript
// file1.ets
export let a = new Number(123);
export let b = new Boolean(true);
export let c = new String('hello');
typeof a; // 'object'
typeof b; // 'object'
typeof c; // 'object'

//file2.ets
import { a, b, c } from './file1';
typeof a; // 'object'
typeof b; // 'object'
typeof c; // 'object'
```

**ArkTS1.2**
```typescript
// file1.ets ArkTS1.2
'use static'
export let a = new Number(123);
export let b = new Boolean(true);
export let c = new String('hello');
typeof a; // 'number'
typeof b; // 'boolean'
typeof c; // 'string'

//file2.ets  ArkTS1.1
import { a, b, c } from './file1';
typeof a; // 'number'
typeof b; // 'boolean'
typeof c; // 'string'
```

### ArkTS1.1创建ArkTS1.2对象字面量

**规则：** arkts-interop-s2d-object-literal

**级别：** error

ArkTS1.1的对象字面量是动态对象，不是真正的标注类型，所以ArkTS1.1中使用构造函数创建ArkTS1.2对象字面量。

**ArkTS1.1**
```typescript
// file1.ets
export class X {
  name: string = '';
  constructor(arg: string) {
    this.name = arg;
  }
}
export interface Y {
  data: number;
}
export type MyRecord = Record<string, number>;
export function foo(arg: X) {}
export function bar(arg: Y) {}

// file2.ets
import { X, Y } from './file1';
let x = { name: 'hello' };
let y: Y = { data: 123 };
foo({ name: 'world' });
bar({ data: 456 });
// 返回值 zoo(): X { return {..}}
// 嵌套场景
interface Z {
  x: X;
}
let z: Z = {x: { name: 'hello' }};
```

**ArkTS1.2**
```typescript
// file1.ets ArkTS1.2
'use static'
export class X { name: string = '' }
export interface Y { data: number }
export function foo(arg: X) { }
export function bar(arg: Y) { }
export function createY(d: number): Y {
  let y: Y = { data: d }
  return y
}

// file2.ets ArkTS1.1
import { X, Y, createY } from "./file1"
let x: X = new X("hello")
let y: Y = createY(123)
foo(new X("world"))
bar(createY(456))
```

### ArkTS1.1传参或赋值给ArkTS1.2

**规则：** arkts-interop-s2d-dynamic-args-to-static

**级别：** error

当从ArkTS1.1传参或赋值给ArkTS1.2时，ArkTS1.2需要将接收的动态对象参数或字段的类型声明为ESObject。

**ArkTS1.1**
```typescript
// file1.ets
export function foo(obj: Object) {}
export class A {
  data: Object = 0;
}

// file2.ets
import { foo, A } from './file1';

class X {}
foo(new X());
interface Y {
  s: string;
}
let y: Y = { s: 'Hi' };
let a = new A();
a.data = y;
// 动态对象的来源：class/interface/对象字面量
```

**ArkTS1.2**
```typescript
// file1.ets ArkTS1.2
'use static'
export function foo(obj: Object) {}
// solution: export function foo(obj: ESValue | Object) {}
export class A {
  data: Object = 0;
}
// solution: export class A { data: ESValue = ESValue.wrap(0) }

// file2.ets ArkTS1.1
import { foo, A } from './file1';

class X {}
foo(new X()); // 运行时报错
interface Y {
  s: string;
}
let y: Y = { s: 'Hi' };
let a = new A();
a.data = y; // 运行时报错
```

### ArkTS1.1Object内置方法作用在ArkTS1.2对象

**规则：** arkts-interop-s2d-dynamic-object-on-static-instance

**级别：** error

ArkTS1.2对象在动态上下文中不能修改对象布局。

ArkTS1.1Object内置方法作用在ArkTS1.2对象需要重新适配代码。

**ArkTS1.1**
```typescript
// file2.ets
export class X {
  a = 1;
}

// file1.ets
import { X } from './file2';
function foo(prx: Object) {
  Object.getOwnPropertyNames(prx); // ["a"]
  Object.hasOwn(prx, 'a'); // true
  Object.keys(prx); // ["a"]
  Object.values(prx); // [1]
}

foo(new X());
```

**ArkTS1.2**
```typescript
// file2.ets ArkTS1.2
'use static'
export class X {
  a = 1;
}
// Object.keys的解决方案，与Object.values的情况类似
export function getKeys(prx: Object | ESValue): string[] | undefined {
  if (prx instanceof Object) {
    return Object.keys(prx);
  }
  return undefined;
}
// file1.ets ArkTS1.1
import { X, getKeys } from './file2';
function myGetKeys(prx: Object) {
  let ret = getKeys(prx);
  if (ret == undefined) {
    // prx is dynamic
    return Object.keys(prx);
  }
  return ret;
}
export function foo(prx: Object) {
  Object.getOwnPropertyNames(prx); // []
  Object.hasOwn(prx, 'a'); // false
  Object.keys(prx); // []
  myGetKeys(prx); // ['a']
  Object.values(prx); // []
}

foo(new X());
```

### ArkTS1.1Reflect内置方法作用在ArkTS1.2对象

**规则：** arkts-interop-s2d-dynamic-reflect-on-static-instance

**级别：** error

ArkTS1.2对象在动态上下文中不能修改对象布局。

ArkTS1.1Reflect内置方法作用在ArkTS1.2对象需要重新适配代码。

**ArkTS1.1**
```typescript
// file2.ets
export class X {
  a: string = 'hello';
  getName() {
    return this.a;
  }
}

// file1.ets
import { X } from './file2';
function foo(prx: Object) {
  Reflect.ownKeys(prx); // ['a']
  Reflect.set(prx, 'newField', 7); // true
}

foo(new X());
```

**ArkTS1.2**
```typescript
// file2.ets  ArkTS1.2
'use static'
export class X {
  a: string = 'hello'
  getName() { return this.a }
}

// static ownKeys的解决方案
export getOwnKeys(prx: Object | ESValue): string[] | undefined {
  if (prx instanceof Object) { return Reflect.ownKeys(prx) }
  return undefined
}

// file1.ets ArkTS1.1
import { X, getOwnKeys } from "./file2"
function myOwnKeys(prx: Object) {
  let ret = getOwnKeys(prx)
  if (ret == undefined) {  // prx is dynamic
      return Reflect.ownKeys(prx)
  }
  return ret
}

function foo(prx: Object) {
  Reflect.ownKeys(prx)  // []
  myOwnKeys(prx)  // ['a']
  Reflect.set(prx, 'newField', 7)  // false
}

foo(new X())
```

### ArkTS1.2Object内置方法作用在ArkTS1.1对象

**规则：** arkts-interop-s2d-static-object-on-dynamic-instance

**级别：** error

ArkTS1.2对象在动态上下文中不能修改对象布局。

ArkTS1.2Object内置方法作用在ArkTS1.1对象需要重新适配代码。

**ArkTS1.1**
```typescript
// file1.ets
export function foo(prx: Object) {
  Object.entries(prx); // [a, 1]
  Object.keys(prx); // ["a"]
  Object.values(prx); // [1]
}

// file2.ets
import { foo } from './file1';
class X {
  a = 1;
}
foo(new X());
```

**ArkTS1.2**
```typescript
// file1.ets  ArkTS1.2
'use static'
export function foo(prx: Object) {
  Object.entries(prx); // [a, 1]
  Object.keys(prx); // ["a"]
  Object.values(prx); // [1]
}

// file2.ets  ArkTS1.1
import { foo } from './file1';
class X {
  a = 1;
}
foo(new X()); // 运行时报错
```

### ArkTS1.2Reflect内置方法作用在ArkTS1.1对象

**规则：** arkts-interop-s2d-static-reflect-on-dynamic-instance

**级别：** error

ArkTS1.1对象在ArkTS1.2中表现为ESObject实例，不是Object实例，因此参数类型不匹配。

ArkTS1.2Reflect内置方法作用在ArkTS1.1对象需要重新适配代码。

**ArkTS1.1**
```typescript
// file1.ets
export function foo(prx: Object) {
  Reflect.get(prx, 'a'); // 'hello'
  Reflect.set(prx, 'a', 'world'); // true
  Reflect.ownKeys(prx); // ['a']
}

// file2.ets
import { foo } from './file1';
class X {
  a: string = 'hello';
  getName() {
    return this.a;
  }
}
foo(new X());
```

**ArkTS1.2**
```typescript
// file1.ets  ArkTS1.2
'use static'
export function foo(prx: Object) {
  Reflect.get(prx, 'a'); // 'hello'
  Reflect.set(prx, 'a', 'world'); // true
  Reflect.ownKeys(prx); // ['a']
}

// file2.ets  ArkTS1.1
import { foo } from './file1';
class X {
  a: string = 'hello';
  getName() {
    return this.a;
  }
}
foo(new X()); // 运行时报错
```

### ArkTS1.1代码调用ArkTS1.2中废弃的方法

**规则：** arkts-interop-s2d-dynamic-call-builtin-api-not-in-static

**级别：** error

在ArkTS1.1代码中导入ArkTS1.2的Builtin类型对象，并调用一个在ArkTS1.2版本中已被移除（但在1.1中仍存在）的方法，导致潜在的兼容性问题出现。

**ArkTS1.1**
```typescript
// file1.ets
export let arr: Array<number> = new Array<number>(1, 2, 3);

// file2.ets
import {arr} from "./file1"

class C {
  base: number;
  constructor(base:number) {
  this.base = base;
}
compare(value: number, index: number, arr: Array<number>) {
  return value >= this.base
}
}
let a = new C(2);
let b = new C(3);
arr.find(a.compare, a) // Result: 2
arr.find(a.compare, b) // Result: 3
```

**ArkTS1.2**
```typescript
// file1.ets ArkTS1.2
'use static'
export let arr: Array<number> = new Array<number>(1, 2, 3);

// file2.ets ArkTS1.1
import {arr} from "./file1"

class C {
  base: number;
  constructor(base:number) {
  this.base = base;
}
compare(value: number, index: number, arr: Array<number>) {
  return value >= this.base
}
}
let a = new C(2);
let b = new C(3);
arr.find(a.compare, a) // 运行时报错
arr.find(a.compare, b) // 运行时报错
```

## ArkTS1.2中使用TS

### ArkTS1.2使用TS装饰器

**规则：** arkts-interop-ts2s-no-ts-decorator

**级别：** error

装饰器会动态修改类或对象的布局，ArkTS1.2不支持装饰器特性。

**ArkTS1.1**
```typescript
// file1.ts
export function MyClassDecorator(klass: Object) {}

// file2.ets
import { MyClassDecorator } from './file1';
@MyClassDecorator
class K {}
```

**ArkTS1.2**
```typescript
NA;
```

### ArkTS1.2访问TS独有类型的实体

**规则：** arkts-interop-ts2s-static-access-ts-type

**级别：** error

TS独有类型包括如下类型：
- any
- unknown
- symbol
- Function
- object literal （例如 {x: number, y: string}）
- mixing enum （例如 enum X {a = 0, b = '1'}）
- call signature （例如 {(arg: number): string}）
- constructor signature （例如 {new(): Object}）
- index signature （例如 {[index: number]: string}）
- intersection （例如 TypeA & TypeB）
- keyof （例如 interface X<T> { props: keyof T}）
- typeof（例如 let p = {x: 1, y: ''}, let q: typeof p）
- indexed access type（例如 MyArray = [{ name: "Alice", age: 15 }] type Person = typeof MyArray[number]）
- conditional types （例如 type Swap<T extends A | B> = T extends A ? B : A）
- mapped types （例如 type A<T> = {[K in keyof T]: T[K]}）
- template literal types （例如 type AB = "A" | "B", type AllLocaleIDs = `${AB}_id`）
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

ArkTS1.2使用ESValue接口进行交互，不支持以上类型。

**ArkTS1.1**
```typescript
// file1.ts
export let obj: Symbol;

// file2.ets
import { obj } from './file1';
let val = obj.prop;
obj.prop = 1;
obj.foo();
let item = obj[0];
```

**ArkTS1.2**
```typescript
// file1.ts
export let obj: Symbol;
// 从ArkTS1.2看来，这个声明为
// export let obj: ESValue

// file2.ets ArkTS1.2
'use static'
import { obj } from './file1';
obj.setProperty('prop', ESValue.wrap(1));
```

### ArkTS1.1Object内置方法作用在ArkTS1.2对象

**规则：** arkts-interop-ts2s-ts-object-on-static-instance

**级别：** error

ArkTS1.2对象在动态上下文中不能修改对象布局。

ArkTS1.1Object内置方法作用在ArkTS1.2对象需要重新适配代码。

**ArkTS1.1**
```typescript
// file1.ts
export function foo(prx: any) {
  Object.getOwnPropertyNames(prx); // ["a"]
  Object.hasOwn(prx, 'a'); // true
  Object.keys(prx); // ["a"]
  Object.values(prx); // [1]
}

// file2.ets
import { foo } from './file1';
class X {
  a = 1;
}
foo(new X());
```

**ArkTS1.2**
```typescript
// file1.ts
export function foo(prx: any) {
  Object.getOwnPropertyNames(prx) // []
  Object.hasOwn(prx, "a")  // false
  Object.keys(prx)  // []
  Object.values(prx)  // []
}

// file2.ets
'use static'
import {foo} from "./file1"
class X { a = 1 }
foo(ESValue.wrap(new X()))
```

### ArkTS1.1Reflect内置方法作用在ArkTS1.2对象

**规则：** arkts-interop-ts2s-ts-reflect-on-static-instance

**级别：** error

ArkTS1.2对象在动态上下文中不能修改对象布局。

ArkTS1.1Reflect内置方法作用在ArkTS1.2对象需要重新适配代码。

**ArkTS1.1**
```typescript
// file1.ts
export function foo(prx: any) {
  Reflect.ownKeys(prx); // ['a']
  Reflect.set(prx, 'newField', 7); // true
}

// file2.ets
import { foo } from './file1';
class X {
  a: string = 'hello';
  getName() {
    return this.a;
  }
}
foo(new X());
```

**ArkTS1.2**
```typescript
// file1.ts
export function foo(prx: any) {
  Reflect.ownKeys(prx); // []
  Reflect.set(prx, 'newField', 7); // false
}

// file2.ets
'use static'
import { foo } from './file1';
class X {
  a: string = 'hello';
  getName() {
    return this.a;
  }
}
foo(ESValue.wrap(new X()));
```

### ArkTS1.2处理TS非常规异常

**规则：** arkts-interop-ts2s-ts-exception

**级别：** error

ArkTS1.2中throw和catch的对象只能是Error的实例。

**ArkTS1.1**
```typescript
// file1.ts
export function foo() {
  throw 123;
}

// file2.ets
import { foo } from './file1';

try {
  foo();
} catch (e) {
  console.log("result is " + (e as number)); // 123
}
```

**ArkTS1.2**
```typescript
// file1.ts
export function foo() {
  throw 123;
}

// file2.ets  // ArkTS1.2
'use static'
import { foo } from './file1';

try {
  foo();
} catch (e) {
  let err: ESValue = (e as ESError).getValue();
  err.toNumber(); // 123
}
```

### ArkTS1.2判断ArkTS1.1装箱类型

**规则：** arkts-interop-ts2s-boxed-type

**级别：** error

在ArkTS1.2中，语言层面不再区分基本类型和装箱类型。因此，当与JS或ArkTS1.1进行互操作时，ArkTS1.2会自动拆箱，转换为对应的基本类型并使用。

避免使用装箱类型或对装箱类型进行typeof操作。

**ArkTS1.1**
```typescript
// file1.ts
export let a = new Number(123);
export let b = new Boolean(true);
export let c = new String('hello');
typeof a; // 'object'
typeof b; // 'object'
typeof c; // 'object'

//file2.ets
import { a, b, c } from './file1';
typeof a; // 'object'
typeof b; // 'object'
typeof c; // 'object'
```

**ArkTS1.2**
```typescript
// file1.ts
export let a = new Number(123);
export let b = new Boolean(true);
export let c = new String('hello');
typeof a; // 'object'
typeof b; // 'object'
typeof c; // 'object'

//file2.ets  ArkTS1.2
'use static'
import { a, b, c } from './file1';
typeof a; // 'number'
typeof b; // 'boolean'
typeof c; // 'string'
```
### ArkTS1.2动态导入TS

**规则：** arkts-interop-ts2s-dynamic-import-ts

**级别：** error

ArkTS1.2使用ESValue接口动态导入TS模块和调用接口。

**ArkTS1.1**
```typescript
// file1.ts
export class A {}

// file2.ets
let mod = await import('./file1');
let A: ESValue = mod.A;
let a = new A() as A;
```

**ArkTS1.2**
```typescript
// file1.ets ts
export class A {}

// file2.ets   ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let A: ESValue = mod.getProperty('A');
let a = A.instantiate() as A;
```

### ArkTS1.2创建TS的类的对象字面量

**规则：** arkts-interop-ts2s-object-literal

**级别：** error

不要使用instanceof判断字面量类型。

**ArkTS1.1**
```typescript
// file1.ts
export class A {
  name: string = '';
}

// file2.ets
import { A } from './file1';
let a: A = { name: 'hello' };

a instanceof A; // false
```

**ArkTS1.2**
```typescript
// file1.ts
export class A {
  name: string = '';
}

// file2.ets ArkTS1.2
'use static'
import { A } from './file1';
let a: A = { name: 'hello' };

a instanceof A; // true
```

## ArkTS1.2中使用JS

### ArkTS1.2导入js文件

**规则：** arkts-interop-js2s-import-js

**级别：** error

ArkTS1.2使用ESValue接口动态导入js模块和调用接口。

**ArkTS1.1**
```typescript
// file1.js
export function foo() {}

// file2.ets
import { foo } from './file1';
```

**ArkTS1.2**
```typescript
// file1.js
export function foo() {}

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
```

### ArkTS1.2导出js实体

**规则：** arkts-interop-js2s-export-js

**级别：** error

ArkTS1.2不能以`export {A} from "./file1"`的形式直接在ets文件中导出js对象。

**ArkTS1.1**
```typescript
// file1.js
export function foo() {}
export class A {}

// file2.ets
import { foo } from './file1';
export { foo };

export { A } from './file1';

// 函数、类、变量、枚举
```

**ArkTS1.2**
```typescript
// file1.js
export function foo() {}
export class A {}

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
let A = mod.getProperty('A');

export { foo, A };
```

### ArkTS1.2调用js函数和传参

**规则：** arkts-interop-js2s-call-js-func

**级别：** error

ArkTS1.2中使用ESValue接口调用js函数和传参。

**ArkTS1.1**
```typescript
// file1.js
export function foo() {}
export function bar(a) {}

// file2.ets
import { foo, bar } from './file1';
foo();
bar(123);
```

**ArkTS1.2**
```typescript
// file1.js
export function foo() {}
export function bar(a) {}

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
let bar = mod.getProperty('bar');
foo.invoke();
bar.invoke(ESValue.wrap(123));
```

### ArkTS1.2实例化js对象

**规则：** arkts-interop-js2s-create-js-instance

**级别：** error

ArkTS1.2使用ESValue接口实例化js对象。

**ArkTS1.1**
```typescript
// file1.js
class foo {
  constructor(a) {}
}
// file2.ets
import { foo } from './file1';
new foo(123);
```

**ArkTS1.2**
```typescript
// file1.js
class foo {
  constructor(a) {}
}

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
foo.instantiate(ESValue.wrap(123));
```

### ArkTS1.2访问js属性

**规则：** arkts-interop-js2s-access-js-prop

**级别：** error

ArkTS1.2使用ESValue接口访问js属性。

**ArkTS1.1**
```typescript
// file1.js
export let foo = { name: '123' };
// file2.ets
import { foo } from './file1';
foo.name;
foo.name = '456';
```

**ArkTS1.2**
```typescript
// file1.js
export let foo = {name: "123"}

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1')
let foo = mod.getProperty('foo')
foo.getProperty('name')
foo.setProperty('name', ESValue.wrap("456")）
```

### ArkTS1.2调用js方法和传参

**规则：** arkts-interop-js2s-call-js-method

**级别：** error

ArkTS1.2使用ESValue接口调用js方法和传参。

**ArkTS1.1**
```typescript
// file1.js
class Foo {
  bar(a) {}
}
export let foo = new Foo();
// file2.ets
import { foo } from './file1';
foo.bar(123);
```

**ArkTS1.2**
```typescript
// file1.js
class Foo {
  bar(a) {}
}

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
foo.invokeMethod('bar', ESValue.wrap(123));
```

### ArkTS1.2访问js索引

**规则：** arkts-interop-js2s-access-js-index

**级别：** error

ArkTS1.2使用ESValue接口访问索引，接口接收参数为ESValue类型，传参时需要用wrap接口构造ESValue实例再传参。

**ArkTS1.1**
```typescript
// file1.js
export let foo = { arr: [1, 2, 3] };
// file2.ets
import { foo } from './file1';
let arr = foo.arr;
arr[1];
arr[3] = 4;
```

**ArkTS1.2**
```typescript
// file1.js
export let foo = [1, 2, 3];

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
let arr = foo.getProperty('arr');
arr.getProperty(1);
arr.setProperty(3, ESValue.wrap(4));
```

### ArkTS1.2转换js对象类型

**规则：** arkts-interop-js2s-convert-js-type

**级别：** error

ArkTS1.2使用ESValue接口转换js对象类型。

**ArkTS1.1**
```typescript
// file1.js
export let foo1 = { num: 123 };
export let foo2 = { bool: true };
export let foo3 = { str: '123' };
export let foo4 = { big: 123n };

// file2.ets
import { foo } from './file1';
let a: number = foo1.num as number;
let b: boolean = foo2.bool as boolean;
let c: string = foo3.str as string;
let d: bigint = foo4.big as bigint;
```

**ArkTS1.2**
```typescript
// file1.js
export let foo1 = { num: 123 };
export let foo2 = { bool: true };
export let foo3 = { str: '123' };
export let foo4 = { big: 123n };

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo1 = mod.getProperty('foo1');
let num = foo1.getProperty('num');
let a1: number = num.toNumber();

let foo2 = mod.getProperty('foo2');
let bool = foo2.getProperty('bool');
let a2: boolean = bool.toBoolean();

let foo3 = mod.getProperty('foo3');
let str = foo3.getProperty('str');
let a3: string = str.toString();

let foo4 = mod.getProperty('foo4');
let big = foo4.getProperty('big');
let a4: bigint = big.toBigInt();
```

### ArkTS1.2获取js对象类型

**规则：** arkts-interop-js2s-typeof-js-type

**级别：** error

ArkTS1.2使用ESValue接口获取js对象类型。

**ArkTS1.1**
```typescript
// file1.js
export let foo = { num: 123 };

// file2.ets
import { foo } from './file1';
typeof foo.num; // 'number'
```

**ArkTS1.2**
```typescript
// file1.js
export let foo = 123;

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
let num = foo.getProperty('num');

num.typeOf(); // 'number'
```

### ArkTS1.2判断js对象类型

**规则：** arkts-interop-js2s-instanceof-js-type

**级别：** error

ArkTS1.2使用ESValue接口判断js对象类型。

**ArkTS1.1**
```typescript
// file1.js
export class Foo {}
export let foo = new Foo();

// file2.ets
import { Foo, foo } from './file1';
foo instanceof Foo;
```

**ArkTS1.2**
```typescript
// file1.js
export class Foo {}
export let foo = new Foo();

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let Foo = mod.getProperty('Foo');
let foo = mod.getProperty('foo');

foo.isInstanceOf(Foo);
```

### ArkTS1.2对js对象自增自减

**规则：** arkts-interop-js2s-self-addtion-reduction

**级别：** error

ArkTS1.2对js对象自增自减时，使用ESValue接口转换为数字后再操作。

**ArkTS1.1**
```typescript
// file1.js
export let foo = { num: 0 };

// file2.ets
import { foo } from './file1';
let a: number = 0;
a = foo.num++;
a = ++foo.num;
a = foo.num--;
a = --foo.num;
```

**ArkTS1.2**
```typescript
// file1.js
export let foo = { num: 0 };

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
let a: number = 0;

// a = foo.num++
let num = foo.getProperty('num');
let tmp: number = num.toNumber();
a = tmp;
foo.setProperty('num', ESValue(tmp + 1));

// a = ++foo.num

num = foo.getProperty('num');
tmp = num.toNumber() + 1;
foo.setProperty('num', ESValue(tmp));
a = tmp;

// the cases "foo.num--" and "--foo.num" are similar
```

### ArkTS1.2对js对象进行一元运算

**规则：** arkts-interop-js2s-unary-op

**级别：** error

ArkTS1.2对js对象进行一元运算时，使用ESValue接口转换为数字后再操作。

**ArkTS1.1**
```typescript
// file1.js
export let foo = { num: 0 };
// file2.ets
import { foo } from './file1';
+foo.num;
-foo.num;
!foo.num;
~foo.num;
```

**ArkTS1.2**
```typescript
// file1.js
export let foo = { num: 0 };

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
let num = foo.getProperty('num');
// +foo.num
+num.toNumber();
// -foo.num
-num.toNumber();
// !foo.num
!num.toNumber();
// ~foo.num
~num.toNumber();
```

### ArkTS1.2对js对象进行二元运算

**规则：** arkts-interop-js2s-binary-op

**级别：** error

ArkTS1.2对js对象进行二元运算时，使用ESValue接口转换为数字后再操作。

**ArkTS1.1**
```typescript
// file1.js
export let foo = { a: 1, b: 2 };

// file2.ets
import { foo } from './file1';
let a = foo.a;
let b = foo.b;
a + b;
a - b;
a * b;
a / b;
a % b;
a ** b;
```

**ArkTS1.2**
```typescript
// file1.js
export let foo = { a: 1, b: 2 };

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
let a = foo.getProperty('a').toNumber();
let b = foo.getProperty('b').toNumber();
a + b;
a - b;
a * b;
a / b;
a % b;
a ** b;
```

### ArkTS1.2 await js Promise对象

**规则：** arkts-interop-js2s-await-js-promise

**级别：** error

ArkTS1.2在await js中的Promise对象时，先使用ESValue接口转换为Promise对象后再await。

**ArkTS1.1**
```typescript
// file1.js
async function foo(){}
export let p = foo()

// file2.ets
import {p} from "./file1"
async function bar() {
  await p.toPromise();
}
```

**ArkTS1.2**
```typescript
// file1.js
async function foo(){}
export let p = foo()

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1')
let p = mod.getProperty('p')

async function bar() {
  await p.toPromise();
}
```

### ArkTS1.2对js数据进行比较

**规则：** arkts-interop-js2s-compare-js-data

**级别：** error

ArkTS1.2对js数据进行比较时，使用ESValue接口转换为数字后再操作。

**ArkTS1.1**
```typescript
// file1.js
export let foo = { a: 1, b: 2 };

// file2.ets
import { foo } from './file1';
let a = foo.a;
let b = foo.b;
a > b;
a < b;
a >= b;
a <= b;
```

**ArkTS1.2**
```typescript
// file1.js
export let a = 1;
export let b = 2;

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
let a = foo.getProperty('a').toNumber();
let b = foo.getProperty('b').toNumber();

a > b;
a < b;
a >= b;
a <= b;
```

### ArkTS1.2对js数据进行相等判断

**规则：** arkts-interop-js2s-equality-judgment

**级别：** error

ArkTS1.2对js数据进行相等判断时，使用ESValue接口判断。

**ArkTS1.1**
```typescript
// file1.js
class A {}
export let a = new A();
export let b = new A();

// file2.ets
import { a, b } from './file1';
a == b;
a != b;
a === b;
a !== b;
```

**ArkTS1.2**
```typescript
// file1.js
class A {}
export let a = new A();
export let b = new A();

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let a = mod.getProperty('a');
let b = mod.getProperty('b');

a.isEqualTo(b);
!a.isEqualTo(b);
a.isStrictlyEqualTo(b);
!a.isStrictlyEqualTo(b);
```

### ArkTS1.2对js对象进行条件判断

**规则：** arkts-interop-js2s-condition-judgment

**级别：** error

ArkTS1.2对js对象进行条件判断时，使用ESValue接口转换为boolean后再判断。

**ArkTS1.1**
```typescript
// file1.js
export let foo = { isGood: true };

// file2.ets
import { foo } from './file1';

if (foo.isGood) {}
```

**ArkTS1.2**
```typescript
// file1.js
export let foo = { isGood: true };

// file2.ets
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');

let isGood = foo.getProperty('isGood').toBoolean();
if (isGood) {}
```

### ArkTS1.2继承js的类

**规则：** arkts-interop-js2s-inherit-js-class

**级别：** error

ArkTS1.2继承js的类时，使用ESValue接口构造JS类并传递js父类。

**ArkTS1.1**
```typescript
// file1.js
export class A {}

// file2.ets
import { A } from './file1';
class B extends A {}
let b = new B();
```

**ArkTS1.2**
```typescript
// file1.js
export class A {}

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let A = mod.getProperty('A');
let fixArr: FixedArray<ESValue> = [];
let esvalueCB = (argThis: ESValue, argNewTgt: ESValue, args: FixedArray<ESValue>, data?: ESValueCallbackData) => {
  return ESValue.Undefined;
};
let B: ESValue = ESValue.defineClass('B', esvalueCB, undefined, undefined, A);
let b = B.instantiate();
```

### ArkTS1.2处理js非常规异常

**规则：** arkts-interop-js2s-js-exception

**级别：** error

ArkTS1.2只能catch Error实例，针对非常规的js异常对象，交互时会被包装到ESError中，通过getValue()方法可以获取包装了原始异常对象的ESValue实例。

**ArkTS1.1**
```typescript
// file1.js
export function foo() {
  throw 123;
}

// file2.ets
import { foo } from './file1';

try {
  foo();
} catch (e) {
  console.log("result is " + (e as number)); //123
}
```

**ArkTS1.2**
```typescript
// file1.js
export function foo() {
  throw 123;
}

// file2.ets
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');

try {
  foo.invoke();
} catch (e) {
  let err: ESValue = (e as ESError).getValue();
  err.toNumber(); // 123
}
```

### ArkTS1.2访问js的装箱类型

**规则：** arkts-interop-js2s-boxed-type

**级别：** error

在ArkTS1.2中，语言层面不再区分基本类型和装箱类型。因此，当与JS或ArkTS1.1进行互操作时，ArkTS1.2会自动拆箱，转换为对应的基本类型并使用。

避免使用装箱类型或对装箱类型进行typeof操作。

**ArkTS1.1**
```typescript
// file1.js
export let foo = {
  num: new Number(123),
  bool: new Boolean(true),
  str: new String('hello'),
};

// file2.ets
import { foo } from './file1';
typeof foo.num; // 'object'
typeof foo.bool; // 'object'
typeof foo.str; // 'object'
```

**ArkTS1.2**
```typescript
// file1.js
export let foo = {
  num: new Number(123),
  bool: new Boolean(true),
  str: new String('hello'),
};

// file2.ets
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');

foo.getProperty('num').typeOf(); // 'number'
foo.getProperty('bool').typeOf(); // 'boolean'
foo.getProperty('str').typeOf(); // 'string'
```

### ArkTS1.2遍历js对象

**规则：** arkts-interop-js2s-traverse-js-instance

**级别：** error

ArkTS1.2遍历js对象时，使用ESValue接口访问索引和属性。

**ArkTS1.1**
```typescript
// file1.js
export let foo = { arr: [1, 2, 3] };
// file2.ets
import { foo } from './file1';
let arr = foo.arr;
let len = arr.length as number;
for (let i = 0; i < len; ++i) {
  arr[i] as number;
  arr[i] = 0;
}
```

**ArkTS1.2**
```typescript
// file1.js
export let foo = { arr: [1, 2, 3] };

// file2.ets  ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
let arr = foo.getProerpty('arr');
let len = arr.getProerpty('length').toNumber();
for (let i = 0; i < len; ++i) {
  arr.getProperty(i).toNumber();
  arr.setProperty(i, ESValue.wrap(0));
}
```

### js调用ArkTS1.2函数和传参

**规则：** arkts-interop-js2s-js-call-static-func

**级别：** error

js调用ArkTS1.2函数和传参时，确保传参匹配声明的类型。

**ArkTS1.1**
```typescript
// file1.js
export function handle(cb) {
  let p = { name: 'hello' };
  cb(p);
}

// file2.ets
import { handle } from './file1';
interface Person {
  name: string;
}

function foo(p: Person) {}
let lambda = (p: Person) => {};

handle(foo);
handle(lambda);
```

**ArkTS1.2**
```typescript
// file1.js
export function handle(cb) {
  let p = { name: 'hello' };
  cb(p);
}

// file2.ets
'use static'
let mod = ESValue.load('./file1');
let handle = mod.getProperty('handle');
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

### js增删改ArkTS1.2对象属性

**规则：** arkts-interop-js2s-js-add-delete-static-prop

**级别：** error

js增删改ArkTS1.2对象属性时，避免动态修改对象布局，需要新增的属性提前在类型中声明，需要删除的属性使用undefined置空。

**ArkTS1.1**
```typescript
// file1.js
export function foo(obj) {
  obj.newField = 1; // 增加属性
  delete obj.data; // 删除属性
  obj.name = '123'; // 修改属性值（同类型）
  obj.name = { firstName: '456' }; // 修改属性值（不同类型）
}

// file2.ets
import { foo } from './file1';
class X {
  name: string = '';
  data: number = 0;
}
foo(new X());
```

**ArkTS1.2**
```typescript
// file1.js
export function foo(obj) {
  obj.newField = 1; // 增加属性   运行时报错
  delete obj.data; // 删除属性   运行时报错
  obj.name = '123'; // 修改属性值（同类型）OK
  obj.name = { firstName: '456' }; // 修改属性值（不同类型）运行时报错
}

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
class X {
  name: string = '';
  data: number = 0;
}
foo.invoke(ESValue.wrap(new X()));
```

### js Object内置方法作用在ArkTS1.2对象

**规则：** arkts-interop-js2s-js-object-on-static-instance

**级别：** error

js Object内置方法作用在ArkTS1.2对象时，需重新适配代码。

**ArkTS1.1**
```typescript
// file1.js
export function foo(prx) {
  Object.getOwnPropertyNames(prx); // ["a"]
  Object.hasOwn(prx, 'a'); // true
  Object.keys(prx); // ["a"]
  Object.values(prx); // [1]
}

// file2.ets
import { foo } from './file1';
class X {
  a = 1;
}
foo(new X());
```

**ArkTS1.2**
```typescript
// file1.js
export function foo(prx) {
  Object.getOwnPropertyNames(prx) // []
  Object.hasOwn(prx, "a")  // false
  Object.keys(prx)  // []
  Object.values(prx)  // []
}

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1')
let foo = mod.getProperty('foo')
class X { a = 1 }
foo.invoke(ESValue.wrap(new X()))
```

### js Reflect内置方法作用在ArkTS1.2对象

**规则：** arkts-interop-js2s-js-reflect-on-static-instance

**级别：** error

js Reflect内置方法作用在ArkTS1.2对象时，需重新适配代码。

**ArkTS1.1**
```typescript
// file1.js
export function foo(prx) {
  Reflect.ownKeys(prx); // ['a']
  Reflect.set(prx, 'newField', 7); // true
}

// file2.ets
import { foo } from './file1';
class X {
  a: string = 'hello';
  getName() {
    return this.a;
  }
}
foo(new X());
```

**ArkTS1.2**
```typescript
// file1.js
export function foo(prx) {
  Reflect.ownKeys(prx); // []
  Reflect.set(prx, 'newField', 7); // false
}

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1');
let foo = mod.getProperty('foo');
class X {
  a: string = 'hello';
  getName() {
    return this.a;
  }
}
foo.invoke(ESValue.wrap(new X()));
```

### js对ArkTS1.2对象进行展开语法

**规则：** arkts-interop-js2s-js-expand-static-instance

**级别：** error

js对ArkTS1.2对象进行展开语法时，需重新适配代码。

**ArkTS1.1**
```typescript
// file1.js
export function foo(obj) {
let x = {...obj} // x会是{ a = 1; b = 2; c = 3 }
let {a, b, ...rest} = obj  // a会是1, b会是2, rest会是{c: 3}

// file2.ets
import {foo} from "./file1"
class X { a = 1; b = 2; c = 3 }
foo(new X())

// class interface Record
```

**ArkTS1.2**
```typescript
// file1.js
export function foo(obj) {
let x = {...obj} // x会是空对象{}，因为静态对象没有自有属性
// 解决方案：let x = {a: obj.a, b: obj.b, c: obj.c}
// 或者使用keys + Reflect.get
let {a, b, ...rest} = obj  // a会是1，b会是2，rest会是空对象{}，因为静态对象没有自有属性
// 解决方案: let rest = {c: obj.c}

// file2.ets  // ArkTS1.2
'use static'
let mod = ESValue.load('./file1')
let foo = mod.getProperty('foo')
class X { a = 1; b = 2; c = 3 }
foo.invoke(ESValue.wrap(new X()))
```

### ArkTS1.2动态导入JS

**规则：** arkts-interop-js2s-dynamic-import-js

**级别：** error

ArkTS1.2使用ESValue接口动态导入js模块和调用接口。

**ArkTS1.1**
```typescript
// file1.js
export class A {}

// file2.ets ArkTS1.1
let mod: ESObject = await import('./file1')
let A: ESObject = mod.A
new A()
```

**ArkTS1.2**
```typescript
// file1.js
export class A {}

// file2.ets ArkTS1.2
'use static'
let mod: ESValue = ESValue.load('./file1')
let A: ESValue = mod.getProperty('A')
A.instantiate()
```

