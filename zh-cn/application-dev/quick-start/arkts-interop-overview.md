# ArkTS1.2互操作概述

## 背景

ArkTS1.2在ArkTS1.1版本的基础上增强了类型安全和并发能力，带来了基于静态类型系统的编译器和运行时实现。为了让开发者能够达到更好的并发性能等目的，可选择ArkTS1.2作为开发语言，或将存量应用逐步改造为ArkTS1.2版本。在此场景下，为了让开发者能够复用已有的生态资产，以及让存量应用的开发者可以便捷地逐步迁移到ArkTS1.2，我们需要提供ArkTS1.2和ArkTS1.1以及TS/JS代码的交互能力。

## 可交互方向

- ArkTS1.2可以导入ArkTS1.1, TS, JS。
- ArkTS1.1可以导入ArkTS1.2。
- TS/JS不可以导入ArkTS1.2/ArkTS1.1。

## ArkTS1.2 静态语义原则

- ArkTS1.2的对象的布局不能被修改，动态修改对象布局（包括新增或删除对象属性，以及修改对象属性的类型）将会出现编译时报错或者运行时报错。
- ArkTS1.2的函数参数需要匹配声明的类型，否则会出现编译报错或运行时报错。
- ArkTS1.2代码中的类型转换如果不能在运行时以合理的方式进行，将会出现编译报错或运行时报错。

## ArkTS1.2类型系统

- ArkTS1.2的顶层类型有：`undefined`，`null`和`Any`。
  - `Any`有子类`Object`，`Object`有子类`ESValue`。ArkTS1.2中的自定义类，标准库(`Array/Map/Set`等)等类型都是`Object`的子类型。

### ESValue

- `ESValue`是`Object`的子类。
- `ESValue`可用于封装来自于JS的对象。
- `ESValue`提供了多种方法来对应对象的常见操作。比如：加载 JS 模块、实例化`new obj(x)`、函数调用`obj(x)`、属性访问`obj.prop`、方法调用`obj.foo(x)`、索引访问`obj[idx]`等。
- ArkTS1.2的`ESValue`作为普通的类型，并无额外限制和额外特权。比如：ArkTS1.2中`ESValue`可以用于类型标注和泛型，但针对`ESValue`类型对象的操作也只能通过调用它的方法来进行。

```txt
AnyObject
    |
Object
    |
ESValue  -|- (static) load(path: string): ESValue                            // 模块加载
          |- wrap(arg: Any)                                                  // 将对象包装成ESObject实例
          |- getProperty(key: string | number): ESValue                      // 读属性
          |- setProperty(key: string | number, newVal: ESValue): void        // 写属性
          |- instantiate(...args: ESValue[]): ESValue                        // 实例化
          |- invoke(...args: ESValue[]): ESValue                             // 函数调用
          |- invokeMethod(methodName: string, ...args: ESValue[]): ESValue   // 方法调用
          |- toString(): string                                              // 将包装的对象转换为string
          |- toNumber(): number                                              // 将包装的对象转换为number
          |- ...
```

（TODO：加链接）`ESValue`接口说明文档。

## 交互基本原则

- ArkTS1.2特有的语言特性不能用于和ArkTS1.1交互（比如：重载、注解、final、尾随闭包、function with receiver）。
- ArkTS1.0特有的语言特性不能用于和ArkTS1.2交互（比如：@Sendable/@Concurrenct）。
- TS特有的语言特性不能用于和ArkTS1.2交互（比如：decorator、call-signature）。
- ArkTS1.2的对象属性在动态上下文使用时有如下特点：
  - 没有自身属性（own property）。
  - 对象和对象的属性都是密封的（sealed）。
- ArkTS1.2和JS的交互，需要开发者显式调用API来进行交互。

```javascript
// file1.js
export class A {
  constructor() {
    console.log("new A");
  }
  msg = "hello";
  data = [1, 2, 3];
  say(arg) {
    console.log(this.msg + arg);
  }
}
export function foo(arg) {
  return arg;
}
```

```typescript
// file2.ets ArkTS1.2
// 加载模块
let module: ESValue = ESValue.load('./file1')
let foo ESValue = module.getProperty('foo')
let A: ESValue = module.getProperty('A')
// 实例化
let aa: ESValue = A.instantiate()
// 调用函数
let a: ESValue = foo.invoke(aa)
// 读属性
let msg: ESValue = a.getProperty('msg')
let msgStr: string = msg.toString()  // 'hello'
let data: ESValue = a.getProperty('data')
// 写属性
let newMsgValue: ESValue = ESValue.wrap('world')  // 将对象包装成ESObject实例
a.setProperty('msg', newMsgValue)
// 调用方法
a.invokeMethod('say', ESValue.wrap(' cup'))  // 打印'world cup'
// 读索引元素
let element0 = data.getProperty(0)
element0.toNumber()  // 1
// 写索引元素
data.setProperty(2, ESValue.wrap(4))
```

- ArkTS1.2和ArkTS1.1/TS的交互，不需要开发者显式调用API来进行交互。

```typescript
// file1.ts
export class A {
  constructor() {
    console.log("new A");
  }
  msg: string = "hello";
  data: Array<number> = [1, 2, 3];
  say(arg: string): void {
    console.log(this.msg + arg);
  }
}
export function foo(arg: A): A {
  return arg;
}
```

```typescript
// file2.ets ArkTS1.2
// 加载模块
import { A, foo } from "./file1";
// 实例化
let aa: A = new A();
// 调用函数
let a: A = foo(aa);
// 读属性
let msg: string = a.msg; // 'hello'
let data: Array<number> = a.data;
// 写属性
a.msg = "world";
// 调用方法
a.say(" cup"); // 打印'world cup'
// 读索引元素
let element0 = data[0]; // 1
// 写索引元素
data[2] = 4;
```
