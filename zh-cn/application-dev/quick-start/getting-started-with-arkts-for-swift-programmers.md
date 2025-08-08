# 从Swift到ArkTS的迁移指导

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @fanglou-->
<!--SE: @qyhuo32-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

对于熟悉Swift的开发者而言，ArkTS作为新的开发语言，带来了全新的开发体验与机遇。ArkTS在语法和编程范式上不仅继承了现代语言的特性，还针对生态进行了深度优化。理解Swift与ArkTS的差异和共性，能够帮助开发者快速上手应用开发，避开常见的编程误区。

本文档基于Swift语言对ArkTS语言进行对比和介绍。如需更详细的了解，可参考[ArkTS语言介绍](./introduction-to-arkts.md)。

## 探索Swift与ArkTS的差异

本文档将帮助Swift开发者梳理在转向ArkTS开发过程中会遇到的误解和陷阱。ArkTS的语法、类型系统以及应用开发模式与Swift存在差异，在学习过程中需特别注意这些关键区别。建议先掌握ArkTS的基础语法和运行时行为，再重点对比其与Swift的不同之处。

## 基础语法

### 变量声明

**ArkTS示例：**

```typescript
// 类型注解（类似Swift）。
let age: number = 20; 
const program: string = 'ArkTS';

// 类型推断（类似Swift的局部变量类型推断）。
let version = 5.0;
```

### 基础数据类型  
| Swift类型       | ArkTS类型            | 示例代码                          | 核心差异说明                  |  
|----------------|----------------------|-----------------------------------|-------------------------------|  
| `Bool`    | `boolean`     | `let isDone: boolean = false;`    | 定义方式相似，均用于逻辑判断。                      |  
| `Int8`    | `number`      | `let count: number = 10;`         | Swift的`Int8`为8位整数。<br>ArkTS统一用`number`表示小整数类型。  |  
| `Int16`   | `number`      | `let count: number = 10;`         | Swift的`Int16`为16位整数。<br>ArkTS统一用`number`表示小整数类型。|  
| `Int32`   | `number`      | `let count: number = 10;`         | Swift的`Int32`为32位整数。<br>ArkTS的`number`是双精度浮点型，可存储整数和浮点数。       |  
| `Int64`        | `number`             | `let largeNum: number = 9007199254740991;` | Swift需处理大整数。<br>ArkTS用同一类型表示。          |  
| `Float`        | `number`             | `let pi: number = 3.14;`          | Swift需显式指定`Float`。<br>ArkTS直接使用`number`。       |  
| `Double`       | `number`             | `let e: number = 2.71828;`        | Swift区分`Float`和`Double`。<br>ArkTS统一用`number`表示所有数值类型。         |  
| `Character`    | `string`             | `let c: string = 'a';`            | ArkTS无`Character`类型，单字符场景使用`string`。   |  
| `String`       | `string`             | `let message: string = 'Hello';`  | 定义方式类似，但ArkTS字符串支持模板字面量和更灵活的操作。  |  

### 复杂数据类型
| Swift类型体系                | ArkTS类型体系            | ArkTS示例代码                                                                 | 核心差异说明                                                                 |  
|-----------------------------|--------------------------|-------------------------------------------------------------------------|-----------------------------------------------------------------------------|  
| **数组**：`var arr: [Int] = [1, 2, 3]` | **Array**：`let arr: Array<number> = [1, 2, 3];` | ```// 动态长度语法糖```<br>```let dynamicArr = [4, 5, 6];```<br> | Swift数组长度可变。<br>ArkTS的`Array`是动态数组，支持`push`/`pop`等操作；可直接用`[]`简化初始化。数组不会越界，当数组下标超过数组长度时会得到undefined。 |  
| **集合 - Set**：`var mySet: Set<String> = ["a", "b"]` | **Set**：`let mySet: Set<string> = new Set(["a", "b"]);` | ```mySet.add('c'); // 向集合内添加元素```<br>```for (const item of mySet) {...); // 迭代访问```<br> | Swift集合通过类型声明。<br>ArkTS中集合的类型较灵活，适合动态场景。 |  
| **字典 - Dictionary**：`var dict: [String: Int] = ["key": 1]` | **Map**：`let map: Map<string, number> = new Map();` | ```map.set('key', 1); // 添加键值对```<br>```let value = map.get('key'); // 获取值```<br>```map.has('key'); // 检查键是否存在```<br> | Swift的`Dictionary`需显式声明类型。<br>ArkTS的`Map`操作更直接，支持链式调用。 |  
| **协议**：`protocol Shape { func area() -> Double }` | **interface**：`interface Shapes { area(): number; }` | ```class Rectangles implements Shapes {```<br>```  public width: number = 0;```<br>```  public height: number = 0;```<br>```  area(): number { return this.width * this.height; }```<br>```}```<br> | 语法结构相似，但ArkTS接口实现无需显式修饰符，且支持可选属性。 |  
| **类**：`class Circle: Shape { /* 类定义 */ }` | **class**：`class Circles implements Shape { /* 类定义 */ }` | ```class Circles {```<br>```  radius: number;```<br>```  constructor(radius: number = 10) { // 支持参数默认值```<br>```    this.radius = radius;```<br>```  }```<br>```}```<br> | ArkTS类支持属性默认值、可选参数，构造函数参数可直接声明为类属性，语法更简洁。 |  
| **枚举**：`enum Color { case red, green, blue }` | **enum**：`enum Colors { Red, Green, Blue }` | ```enum Colors { Red = 1, Green, Blue };```<br>```let color = Colors.Green; // 值为2（自动递增）```<br> | 基本概念一致，但ArkTS枚举不支持Swift中的自定义构造函数和方法，仅支持简单的数值或字符串枚举。 |  

### 函数与闭包

Swift和ArkTS在函数方面语法趋同，细节上有差别。

相似点：常规函数定义和箭头函数。

**ArkTS示例：** 函数定义

```typescript
// 常规函数定义，与Swift类似。
function add(x: number, y: number): number {
    return x + y;
}

// 简洁的箭头函数形式，类似Swift的闭包语法。
const multiply = (a: number, b: number): number => a * b;
```

差异点：

1. ArkTS提供类型声明层面的多态，仅用于类型检查和文档提示，实际只有一个实现函数。

**ArkTS示例：** ArkTS函数重载

```typescript
function foo(x: number): void;            /*  第一个函数定义。  */
function foo(x: string): void;            /*  第二个函数定义。  */
function foo(x: number | string): void {  /*  函数实现。       */
}

foo(123);     //  OK，使用第一个定义。
foo('aa'); // OK，使用第二个定义。
```

2. ArkTS可选参数使用`?`，如`function foo(name?: string)`，而非Swift的默认值语法。
```typescript
function foo(name?: string){}  /*  name为可选参数。  */

foo('hello');     //  OK，传入name参数。
foo();     //  OK，不传name参数。
```

### 基础类库

ArkTS基础类库和容器类库增强了语言的基础功能，包括高精度浮点运算、二进制Buffer、XML生成解析转换和多种容器库等能力，协助开发者简化开发工作，提升开发效率。

## 语言结构

Swift是一种融合面向对象、函数式和协议导向范式的现代语言，强调安全性、性能与简洁性，适用于跨平台开发。

ArkTS融合声明式UI、函数式和面向对象范式，通过响应式系统和跨设备适配能力，高效构建多端一致的高性能应用。

### 模块与包管理

在Swift中，开发者使用模块（module）来组织代码，通过import语句引入其他模块中的类。

ArkTS也有自己的模块和包管理机制，同样通过import语句引入其他模块中的功能。

**ArkTS示例：**

```
// 引入ArkTS标准库中的ArkTS容器集。

import { collections } from '@kit.ArkTS';
```

由于ArkTS的模块系统更注重模块化开发和代码复用，能够更便捷地管理不同功能模块之间的依赖关系，所以在使用方式上，与Swift的模块管理会有所区别。

### 类与命名空间特性

ArkTS的类系统在语法层面与Swift相似，但在高阶特性上展现出更现代的设计理念。

| 特性       |Swift实现方式      | ArkTS实现方式            | 说明                          |
|------------|------------|------------------|-------------------------------|
| 命名空间组织    | 嵌套结构/内部类     | `namespace`关键字或模块文件结构。           | 支持显式命名空间与模块化组织的混合模式。   |
| 类继承机制        | 基于类的继承体系        | 基于原型链的继承机制。           | 语法相似但底层机制不同。        |
| 类成员可见性    | public/private/internal       | 同Swift，但支持模块级可见性控制。          | 增加了模块导出控制的维度。|

**命名空间管理** 

ArkTS支持显式命名空间（namespace）和模块化组织。

**ArkTS示例：**

```typescript
namespace Models {
    export class User {
        // 实现细节。
    }
    
    export interface Repository {
        // 接口定义。
    }
}
```

相比Swift的模块+内部类组合，ArkTS的命名空间能更直观地实现代码分层。

**类成员初始化**

ArkTS支持在类体内直接初始化属性。

**ArkTS示例：**

```typescript
class User {
    private name: string = 'Default'
}
```

Swift通常在构造函数中初始化属性。

### 异步编程模型

**单线程vs多线程**

Swift使用`async`/`await` + `Task`实现异步编程，使用多线程和`DispatchQueue`实现并发。

ArkTS基于事件循环，使用`Promise`/`async`/`await`处理异步，避免阻塞主线程。

**错误处理**

Swift的同步代码通过`try/catch`捕获异常，异步异常需特殊处理。

ArkTS中未捕获的`Promise`错误可能导致静默失败，需显式使用`try/catch`或`.catch`。

### this的绑定

Swift的方法中，`self`始终指向类的实例对象，由代码结构在编译时确定。在方法中，`self`指向调用该方法的对象实例，无法通过调用方式改变`self`的指向。

**Swift示例：**

```swift
class MyClass {
  func method() {
    print(self) // 始终指向MyClass的实例。
  }
}
```

ArkTS的`this`指向取决于函数调用时的上下文。

**ArkTS示例：**

```typescript
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

let a: A = new A();
let b: B = new B();

callFunction(a.foo); // 程序crash。this的上下文发生了变化。
b.callFunction(a.foo); // 程序crash。this的上下文发生了变化。
b.callFunction(a.foo.bind(b)) // 输出'I'm B'。
```

## 类型系统

ArkTS与Swift的类型系统也存在差异。

### 类型推断与可选类型

相较于Swift需要显式类型声明和严格的nil检查，ArkTS的类型系统提供了更灵活的表达方式。

ArkTS具有强大的类型推断能力，编译器能够根据上下文自动推断出变量的类型，所以很多时候不需要显式声明变量的类型。

**ArkTS示例：**

```typescript
let num = 10; // 编译器自动推断num为number类型。
```

同时，ArkTS支持可选类型，通过在类型后面添加问号（`?`）来表示该变量可以为`null`或`undefined`。

**ArkTS示例：**

```typescript
interface Person {
  name: string;
  age?: number;  // age是可选属性。
}

const person: Person = {
  name: "Alice",
};
```

### 联合类型

联合类型这种类型组合能力为复杂场景提供了更强的表达力，是ArkTS类型系统的重要创新点。

ArkTS支持联合类型（`|`）。联合类型表示一个值可以是多种类型中的一种。

**ArkTS示例：**

```typescript
// 联合类型示例。

let value: string | number;
value = 'hello';
value = 123;

```