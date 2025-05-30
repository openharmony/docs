# ArkTS1.2互操作场景

## ArkTS1.2中使用ArkTS1.1或TS

### 文件导入

在ArkTS1.2中使用`import`函数导入ArkTS1.1模块的对象。

```typescript
// file1.ets ArkTS1.1
export function foo() {}
export class A {
  field: number = 0;
  test() {}
}
```

```typescript
// file2.ets ArkTS1.2
import { foo, A } from "./file1";
```

### 类实例化

在ArkTS1.2中使用从ArkTS1.1中导入的类，并用new来创建该类的实例。

```typescript
// file1.ets ArkTS1.1
export class A {
  id: number = 0;
  constructor(arg: number) {
    this.id = arg;
  }
}
export class B extends A {
  name: string = "";
  constructor(arg0: number, arg1: string) {
    super(arg0);
    this.name = arg1;
  }
}
export interface Inface {
  x: number;
  y: number;
  normSquare(): number;
}
export class C implements Inface {
  x: number = 0;
  y: number = 0;
  normSquare(): number {
    return this.x * this.x + this.y * this.y;
  }
}
```

```typescript
// file2.ets ArkTS1.2
import { A, B, C } from "./file1";
let a = new A(123);
let b = new B(456, "Bob");
let c = new C();
```

### 属性读写

在ArkTS1.2中读写ArkTS1.1对象的属性。

```typescript
// file1.ets ArkTS1.1
export class Person {
  public id: number = 0;
  private name_: string = "";
  constructor(name: string) {
    this.name_ = name;
  }
  get name(): string {
    return this.name_;
  }
  set name(name: string) {
    this.name_ = name;
  }
}
```

```typescript
// file2.ets ArkTS1.2
import { Person } from "./file1";
let p = new Person("John");
console.log(p.name); // Output: John
p.name = "Alice";
console.log(p.name); // Output: Alice
p.id = 123456;
console.log(p.id); // Output: 123456
```

### 函数调用

在ArkTS1.2中直接调用从ArkTS1.1导入的函数。

```typescript
// file1.ets ArkTS1.1
export let say = (msg: string) => {
  console.log(msg);
};
export function myAdd(a: number, b: number): number {
  let ret = a + b;
  console.log(ret);
  return ret;
}
```

```typescript
// file2.ets ArkTS1.2
import { say, myAdd } from "file1";
say("Hello"); // Output: Hello
myAdd(3, 4); // Output: 7
```

### 对象方法调用

在ArkTS1.2中直接调用ArkTS1.1导入对象的方法。

```typescript
// file1.ets ArkTS1.1
export class A {
  log() {
    console.log(123)
  }
}
class B {
  foo() : void {}
}
export class C extends B {
  override foo() : void { console.log('D.foo') }
}
interface InterA {
  foo: () => void;
}
export let itA: InterA = {
  foo: () => { console.log('interface log') }
}
export let arr = new Array<number>(1, 2, 3);
```

```typescript
// file2.ets ArkTS.12
import { A, C, itA, arr } from "file1";
let a = new A();
a.log();
let c = new C();
c.foo(); // Output: D.foo
itA.foo();
arr.push(4);
```

### 参数传递

可以将ArkTS1.2的对象直接作为参数传入到`import`来的ArkTS1.1函数。

```typescript
// file1.ets ArkTS1.1
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

### 异常处理

当在ArkTS1.1中定义一个异常的实例时，可以在ArkTS1.2中捕获这个异常。

```typescript
// file1.ets ArkTS1.1
export let err = new Error("123");
export function foo1() {
  throw err;
}

export let ranErr = new RangeError("456");
export function foo2() {
  throw err;
}

export let refErr = new ReferenceError("789");
export function foo3() {
  throw err;
}

export let synErr = new SyntaxError("111");
export function foo4() {
  throw err;
}

export let uriErr = new URIError("222");
export function foo5() {
  throw err;
}

// file2.ets ArkTS1.2
import {
  err,
  ranErr,
  refErr,
  synErr,
  uriErr,
  foo1,
  foo2,
  foo3,
  foo4,
  foo5,
} from "1.1";
err instanceof Error; // true
try {
  foo1();
} catch (e) {
  (e as Error).message; // OK, '123'
}

ranErr instanceof RangeError; // true
try {
  foo2();
} catch (e) {
  (e as RangeError).message; // OK, '456'
}

refErr instanceof ReferenceError; // true
try {
  foo3();
} catch (e) {
  (e as ReferenceError).message; // OK, '789'
}

synErr instanceof SyntaxError; // true
try {
  foo4();
} catch (e) {
  (e as SyntaxError).message; // OK, '111'
}

uriErr instanceof URIError; // true
try {
  foo5();
} catch (e) {
  (e as URIError).message; // OK, '222'
}
```
