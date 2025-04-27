# ArkTS语法适配背景

ArkTS在保留TypeScript（简称TS）基本语法风格的基础上，进一步通过规范强化了静态检查和分析，使得在程序开发阶段能够检测出更多错误，提升程序的稳定性和运行性能。本文将详细解释为什么建议将TS代码适配为ArkTS代码。

## 程序稳定性

动态类型语言如JavaScript（简称JS）虽能提升开发效率，但也容易在运行时引发非预期错误。例如未检查的`undefined`值可能导致程序崩溃，这类问题若能在开发阶段发现将显著提升稳定性。TypeScript（TS）通过类型标注机制，使编译器能在编译时检测出多数类型错误，但其非强制类型系统仍存在局限。例如未标注类型的变量会阻碍完整编译检查。ArkTS通过强制静态类型系统克服这一缺陷，实施更严格的类型验证机制，从而最大限度减少运行时错误的发生。

下面这个例子展示了ArkTS通过强制严格的类型检查来提高代码稳定性和正确性。


**显式初始化类的属性**

ArkTS要求类的所有属性在声明时或者在构造函数中显式地初始化，这和TS中的`strictPropertyInitialization`检查一致。以下的代码片段是非严格模式下的TS代码。

```typescript
class Person {
  name: string // undefined
  
  setName(n: string): void {
    this.name = n
  }
  
  getName(): string {
  // 开发者使用"string"作为返回类型，这隐藏了name可能为"undefined"的事实。
  // 更合适的做法是将返回类型标注为"string | undefined"，以告诉开发者这个API所有可能的返回值的类型。
    return this.name
  }
}

let buddy = new Person()
// 假设代码中没有对name的赋值，例如没有调用"buddy.setName('John')"
buddy.getName().length; // 运行时异常：name is undefined
```

ArkTS要求属性显式初始化，代码应如下所示：

```typescript
class Person {
  name: string = ''
  
  setName(n: string): void {
    this.name = n
  }
  
  // 类型为"string"，不可能为"null"或者"undefined"
  getName(): string {
    return this.name
  }
}

let buddy = new Person()
// 假设代码中没有对name的赋值，例如没有调用"buddy.setName('John')"
buddy.getName().length; // 0, 没有运行时异常
```

如果`name`可以是`undefined`，其类型应在代码中精确标注。

```typescript
class Person {
    name?: string // 可能为undefined

    setName(n: string): void {
        this.name = n
    }

    // 编译时错误：name可能为"undefined"，所以不能将这个API的返回类型标注为"string"
    getNameWrong(): string {
        return this.name
    }

    getName(): string | undefined { // 返回类型匹配name的类型
        return this.name
    }
}

let buddy = new Person()
// 假设代码中没有对name的赋值，例如没有调用"buddy.setName('John')"

// 编译时错误：编译器认为下一行代码有可能访问"undefined"的属性，报错
buddy.getName().length;  // 编译失败

buddy.getName()?.length; // 编译成功，没有运行时错误
```

## 程序性能

为了确保程序的正确性，动态类型语言需要在运行时检查对象的类型。例如JavaScript不允许访问`undefined`的属性。检查一个值是否为`undefined`的唯一方法是在运行时进行类型检查。所有JavaScript引擎都会执行以下操作：如果一个值不是`undefined`，则可以访问其属性；否则，抛出异常。虽然现代JavaScript引擎可以优化这类操作，但仍然存在一些无法消除的运行时检查，这会导致程序变慢。由于TypeScript代码总是先被编译成JavaScript代码，因此在TypeScript中也会遇到相同的问题。ArkTS解决了这个问题。通过启用静态类型检查，ArkTS代码将被编译成方舟字节码文件，而不是JavaScript代码。因此，ArkTS运行速度更快，更容易被进一步优化。


**Null Safety**

```typescript
function notify(who: string, what: string) {
  console.log(`Dear ${who}, a message for you: ${what}`)
}

notify('Jack', 'You look great today')
```

在大多数情况下，函数`notify`会接受两个`string`类型的变量作为输入，产生一个新的字符串。但是，如果将一些特殊值作为输入，例如`notify(null, undefined)`，情况会怎么样呢？
程序仍会正常运行，输出预期值：`Dear null, a message for you: undefined`。一切看起来正常，但是请注意，为了保证该场景下程序的正确性，引擎总是在运行时进行类型检查，执行类似以下的伪代码。

```typescript
function __internal_tostring(s: any): string {
  if (typeof s === 'string')
    return s
  if (s === undefined)
    return 'undefined'
  if (s === null)
    return 'null'
  // ...
}
```

现在想象一下，如果函数`notify`是某些复杂的负载场景中的一部分，而不仅仅是打印日志，那么在运行时执行像`__internal_tostring`的类型检查将会是一个性能问题。

如果可以保证在运行时，只有`string`类型的值（不会是其他值，例如`null`或者`undefined`）可以被传入函数`notify`呢？在这种情况下，因为可以确保没有其他边界情况，像`__internal_tostring`的检查就是多余的了。对于这个场景，这样的机制叫做“null-safety”，也就是说，保证`null`不是一个合法的`string`类型变量的值。如果ArkTS有了这个特性，类型不符合的代码将无法编译。

```typescript
function notify(who: string, what: string) {
  console.log(`Dear ${who}, a message for you: ${what}`)
}

notify('Jack', 'You look great today')
notify(null, undefined) // 编译时错误
```

TS通过启用编译选项`strictNullChecks`实现此特性。虽然TS被编译成JS，但因为JS没有这个特性，所以严格`null`检查仅在编译时起效。从程序稳定性和性能的角度考虑，ArkTS将“null-safety”视为一个重要的特性。因此，ArkTS强制进行严格`null`检查，在ArkTS中上述代码将始终编译失败。作为交换，此类代码为ArkTS引擎提供了更多信息和关于值的类型保证，有助于优化性能。


## .ets代码兼容性

在API version 10之前，ArkTS（.ets文件）完全采用了标准TS的语法。从API version 10 Release起，明确定义ArkTS的语法规则，同时，SDK增加了在编译流程中对.ets文件的ArkTS语法检查，通过编译告警或编译失败提示开发者适配新的ArkTS语法。

根据工程的compatibleSdkVersion，具体策略如下：

  - compatibleSdkVersion >= 10 为标准模式。在该模式下，对.ets文件，违反ArkTS语法规则的代码会导致工程编译失败，需要完全适配ArkTS语法后方可编译成功。
  - compatibleSdkVersion < 10 为兼容模式。在该模式下，对.ets文件以warning形式提示违反ArkTS语法规则的所有代码。尽管违反ArkTS语法规则的工程在兼容模式下仍可编译成功，但需完全适配ArkTS语法后方可在标准模式下编译成功。

## 支持与TS/JS的交互

ArkTS支持与TS/JS的高效互操作。在当前版本中，ArkTS运行时兼容动态类型对象语义。在与TS/JS交互时，将TS/JS的数据和对象作为ArkTS的数据和对象使用，可能会绕过ArkTS的静态编译检查，导致非预期的行为或增加额外的开销。

```typescript
// lib.ts
export class C {
  v: string
}

export let c = new C()

// app.ets
import { C, c } from './lib'

function foo(c: C) {
  c.v.length
}

foo(c)  //  运行时异常：v is undefined
```

## 方舟运行时兼容TS/JS

在API version 11上，OpenHarmony SDK中的TypeScript版本为4.9.5，target字段为es2017。应用中支持使用ECMA2017及更高版本的语法进行TS/JS开发。

**应用环境限制**

1. 强制使用严格模式（use strict）
2. 禁止使用`eval()`
3. 禁止使用`with() {}`
4. 禁止以字符串为代码创建函数
5. 禁止循环依赖

    循环依赖示例:
    ```typescript
    // bar.ets
    import {v} from './foo' // bar.ets依赖foo.ets
    export let u = 0;

    // foo.ets
    import {u} from './bar' // foo.ets同时又依赖bar.ets
    export let v = 0;

    ```

**与标准TS/JS的差异**

在标准的TS/JS中，JSON的数字格式要求小数点后必须跟随数字，例如 `2.e3` 这类科学计数法不被允许，会导致`SyntaxError`。而在方舟运行时中，支持这类科学计数法
