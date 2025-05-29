# 从Java到ArkTS的迁移指导

对于熟悉Java的开发者而言，ArkTS作为新的开发语言，带来了全新的开发体验与机遇。ArkTS在语法和编程范式上不仅继承了现代语言的特性，还针对生态进行了深度优化。理解Java与ArkTS的差异和共性，能够帮助开发者快速上手应用开发，避开常见的编程误区。

本文档基于Java语言对ArkTS语言进行对比和介绍。如需更详细的了解，可参考[ArkTS语言介绍](./introduction-to-arkts.md)。

## 探索Java与ArkTS的差异

本文档将帮助Java开发者梳理在转向ArkTS开发过程中会遇到的误解和陷阱。ArkTS的语法、类型系统以及应用开发模式与Java存在差异，在学习过程中需特别注意这些关键区别。建议先掌握ArkTS的基础语法和运行时行为，再重点对比其与Java的不同之处。

## 基础语法

### 变量声明

**ArkTS示例：**

```typescript
// 类型注解（类似Java）。
let age: number = 20; 
const program: string = 'ArkTS';

// 类型推断（类似Java的局部变量类型推断）。
let version = 5.0;
```

### 基础数据类型  
| Java类型       | ArkTS类型            | 示例代码                          | 核心差异说明                  |  
|----------------|----------------------|-----------------------------------|-------------------------------|  
| `boolean`      | `boolean`            | `let isDone: boolean = false;`    | 定义方式相似，均用于逻辑判断，无运行时装箱拆箱操作。                      |  
| `byte`         | -                    | -                                 | ArkTS无对应类型，小整数场景统一使用`number`（如`let b: number = 10;`）。 |  
| `short`        | -                    | -                                 | 同上，ArkTS通过`number`覆盖短整数场景，不区分数据宽度。                   |  
| `int`          | `number`             | `let count: number = 10;`         | Java的`int`为32位整数。<br>ArkTS的`number`是双精度浮点型，可存储整数和浮点数。       |  
| `long`         | `number`             | `let largeNum: number = 9007199254740991;` | Java需加`L`后缀（如`9007199254740991L`）。<br>ArkTS用同一类型表示。          |  
| `float`        | `number`             | `let pi: number = 3.14;`          | Java需加`f`后缀（如`3.14f`）。<br>ArkTS直接使用`number`，无需特殊标识。       |  
| `double`       | `number`             | `let e: number = 2.71828;`        | Java区分`float`和`double`。<br>ArkTS统一用`number`表示所有数值类型。         |  
| `char`         | -                    | -                                 | ArkTS无`char`类型，单字符场景使用`string`（如`let c: string = 'a';`）。   |  
| `String`       | `string`             | `let message: string = 'Hello';`  | 定义方式类似，但ArkTS字符串支持模板字面量（如`${name}`）和更灵活的操作。  |  

### 复杂数据类型
| Java类型体系                | ArkTS类型体系            | ArkTS示例代码                                                                 | 核心差异说明                                                                 |  
|-----------------------------|--------------------------|-------------------------------------------------------------------------|-----------------------------------------------------------------------------|  
| **数组**：`int[] arr = new int[5];` | **Array**：`let arr: Array<number> = [1, 2, 3];` | ```// 固定长度初始化（类似Java）```<br>```let fixedArr: number[] = new Array<number>(5);```<br>```// 动态长度语法糖```<br>```let dynamicArr = [4, 5, 6];```<br> | Java数组长度固定。<br>ArkTS的`Array`是动态数组，支持`push`/`pop`等操作；可直接用`[]`简化初始化。数组不会越界，当数组下标超过数组长度时会得到undefined。 |  
| **集合 - List**：`List<String> list = new ArrayList<>();` | **Array**：`let strList: Array<string> = ['a', 'b'];` | ```strList.push('c'); // 向数组末尾添加元素```<br>```let firstItem = strList[0]; // 索引访问```<br> | Java集合通过接口（如`List`）与实现类（如`ArrayList`）分离。<br>ArkTS数组兼具基础类型与集合特性，语法更简洁。 |  
| **集合 - Map**：`Map<String, Integer> map = new HashMap<>();` | **Map**：`let map: Map<string, number> = new Map();` | ```map.set('key', 1); // 添加键值对```<br>```let value = map.get('key'); // 获取值```<br>```map.has('key'); // 检查键是否存在```<br> |Java的`Map`需显式声明泛型类型。<br>ArkTS的`Map`操作更直接，支持链式调用（如`map.set('a', 1).set('b', 2)`）。 |  
| **接口**：`interface Shape { double area(); }` | **interface**：`interface Shapes { area(): number; }` | ```class Rectangles implements Shapes {```<br>```  public width: number = 0;```<br>```  public height: number = 0;```<br>```  area(): number { return this.width * this.height; }```<br>```}```<br> | 语法结构相似，但ArkTS接口实现无需显式修饰符（如Java的`public`），且支持可选属性（如`name?: string`）。 |  
| **类**：`class Circle implements Shape { /* 类定义 */ }` | **class**：`class Circles implements Shape { /* 类定义 */ }` | ```class Circles {```<br>```  radius: number;```<br>```  constructor(radius: number = 10) { // 支持参数默认值```<br>```    this.radius = radius;```<br>```  }```<br>```}```<br> | ArkTS类支持属性默认值、可选参数，构造函数参数可直接声明为类属性（如`constructor(public name: string)`），语法更简洁。 |  
| **枚举**：`enum Color { RED, GREEN, BLUE; }` | **enum**：`enum Colors { Red, Green, Blue }` | ```enum Colors { Red = 1, Green, Blue };```<br>```let color = Colors.Green; // 值为2（自动递增）```<br> | 基本概念一致，但ArkTS枚举不支持Java中的自定义构造函数和方法，仅支持简单的数值或字符串枚举。 |  


### 函数

**ArkTS示例：**

```typescript
// 常规函数定义。
function add(x: number, y: number): number {
    return x + y;
}

// 简洁的箭头函数形式。
const multiply = (a: number, b: number): number => a * b;
```

### 函数重载

Java在编译时多态，允许同一类中存在多个同名方法，通过参数列表（数量、类型、顺序）来进行区分。

* 通过多个具体方法实现重载，每个重载方法有独立的方法体。

* 参数列表（类型、数量、顺序）必须不同，返回值类型可以相同或不同。

* 编译时根据参数类型选择具体方法。

**Java示例：** Java函数重载

```java
class Example {
    // 方法1：接受int参数。
    void print(int value) {
        System.out.println("Integer: " + value);
    }

    // 方法2：接受String参数。
    void print(String value) {
        System.out.println("String: " + value);
    }
}
```

ArkTS提供类型声明层面的多态，仅用于类型检查和文档提示，实际只有一个实现函数。

* 通过类型声明重载签名，但仅有一个实现函数。

* 实现函数需兼容所有重载签名，通常需要在函数体内手动判断参数类型。

* 类型检查器根据调用时的参数匹配声明，但运行时只有单一函数。

**ArkTS示例：** ArkTS函数重载

```typescript
function foo(x: number): void;            /* 第一个函数定义 */
function foo(x: string): void;            /* 第二个函数定义 */
function foo(x: number | string): void {  /* 函数实现 */
}

foo(123);     //  OK，使用第一个定义。
foo('aa'); // OK，使用第二个定义。
```

### 基础类库

ArkTS基础类库和容器类库增强了语言的基础功能，包括高精度浮点运算、二进制Buffer、XML生成解析转换和多种容器库等能力，协助开发者简化开发工作，提升开发效率。详细介绍可见[ArkTS基础类库概述](../arkts-utils/arkts-utils-overview.md)。

## 语言结构

Java是一种典型的面向对象的编程语言，即一切围绕类和对象展开。

ArkTS采用更为灵活的语言结构，融合了面向对象编程和函数式编程等多种范式。

### 模块与包管理

在Java中，开发者使用包（package）来组织代码，通过import语句引入其他包中的类。ArkTS也有自己的模块和包管理机制，同样通过import语句引入其他模块中的功能。

**ArkTS示例：**

```typescript
// 引入ArkTS标准库中的ArkTS容器集。

import { collections } from '@kit.ArkTS';
```

由于ArkTS的模块系统更注重模块化开发和代码复用，能够更便捷地管理不同功能模块之间的依赖关系，所以在使用方式上，与Java的包管理会有所区别。

### 类与命名空间特性

ArkTS的类系统在语法层面与Java相似，但在高阶特性上展现出更现代的设计理念。

| 特性       |Java实现方式      | ArkTS实现方式            | 说明                          |
|------------|------------|------------------|-------------------------------|
| 命名空间组织    | 静态嵌套类/内部类     | `namespace`关键字或模块文件结构。           | 支持显式命名空间与模块化组织的混合模式。   |
| 类继承机制        | 基于类的继承体系        | 基于原型链的继承机制。           | 语法相似但底层机制不同。        |
| 类成员可见性    | public/private/protected       | 同Java，但支持模块级可见性控制。          | 增加了模块导出控制的维度。|

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

相比Java的package+static class组合，ArkTS的命名空间能更直观地实现代码分层。

**类成员初始化**

ArkTS支持在类体内直接初始化属性。

**ArkTS示例：**

```typescript
class User {
    private name: string = 'Default'
}
```

Java需要显式构造函数或初始化块。

### 异步编程模型

**单线程vs多线程**

Java依赖多线程和`Future`/`CompletableFuture`实现并发。

ArkTS基于事件循环，使用`Promise`/`async`/`await`处理异步，避免阻塞主线程。

**错误处理**

Java的同步代码通过`try/catch`捕获异常，异步异常需特殊处理（如`Future.get()`）。

ArkTS中未捕获的`Promise`错误可能导致静默失败，需显式使用`try/catch`或`.catch`。

### this的绑定

Java的this始终指向当前类的实例对象，由代码结构在编译时确定。在方法中，this指向调用该方法的对象实例，无法通过调用方式改变this的指向。

**Java示例：**

```java
class MyClass {
  void method() {
    System.out.println(this); // 始终指向MyClass的实例。
  }
}
```

ArkTS的this指向取决于函数调用时的上下文。

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

ArkTS与Java的类型系统也存在差异。

### 类型推断与可选类型


相较于Java需要显式类型声明和严格的null检查，ArkTS的类型系统提供了更灵活的表达方式。

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
  age?: number;  // age 是可选属性。
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