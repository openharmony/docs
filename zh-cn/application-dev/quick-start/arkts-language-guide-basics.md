# 基础知识
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

ArkTS是基于TypeScript的扩展语言，专为OpenHarmony开发设计。本章介绍ArkTS的基础知识，包括常量与变量、类型系统、注释、分号等核心概念。

## 常量与变量

ArkTS使用`const`声明不可重新赋值的常量、`let`声明可重新赋值的变量。选择准则：默认使用`const`，仅在需要重新赋值时改用`let`，这遵循最小权限原则——不打算修改的数据不应被意外写入。`const`保证变量绑定不变，但对象类型的`const`仅锁定引用，对象内部属性仍可修改（如`const arr = []; arr.push(1)`合法）。ArkTS不使用`var`，因其函数作用域和变量提升特性不符合静态可预测的编码要求。

### 声明

ArkTS使用`let`和`const`声明变量与常量。TypeScript中的`var`具有函数作用域和变量提升特性，不符合ArkTS对静态、可预测作用域的要求，ArkTS代码中不使用`var`。

<!-- @[variable_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let count: number = 10;
let name: string = 'ArkTS';
let isActive: boolean = true;

// 可重新赋值
let message: string = 'Hello';
message = 'Hello, ArkTS';
```

与`let`不同，`const`声明的绑定不可重新赋值，但对于引用类型，对象内部属性仍可修改。

<!-- @[ts_const_reassignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
const MAX_SIZE: number = 100;
const APP_NAME: string = 'MyApp';

// 常量必须初始化
const value: number = 10;  // 正确

// 引用类型：引用不变，内容可修改
const numbers: number[] = [1, 2, 3];
numbers.push(4);           // 合法
numbers = [5, 6];          // 编译错误
```

### 命名

标识符由字母、数字、下划线和$组成，不能以数字开头，不能使用[保留关键字](#保留关键字)。推荐小驼峰命名变量和函数、大驼峰命名类和接口、全大写下划线命名常量。

<!-- @[ts_illegal_naming](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// 合法命名
let validName: number = 1;
let _private: number = 2;
let $special: number = 3;
let camelCase: number = 4;

// 非法命名
let 123start: number = 1;    // 数字开头
let my-var: number = 2;      // 包含连字符
let class: number = 3;       // 保留关键字
```

在合法命名的基础上，遵循统一的命名约定能显著提升代码可读性，以下示例展示各场景下的推荐命名风格。

<!-- @[naming_conventions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let userName: string = 'Alice';
let itemCount: number = 10;

const MAX_RETRY_COUNT: number = 3;
const API_BASE_URL: string = 'EXAMPLE_API_URL';

class UserProfile { }
interface IRepository { }
```

### 保留关键字

以下关键字在ArkTS中具有特殊语义，不能用作标识符名称。

| 类别 | 关键字 |
| --- | --- |
| 控制流 | `break` `case` `catch` `continue` `default` `do` `else` `finally` `for` `if` `return` `switch` `throw` `try` `while` |
| 声明 | `class` `const` `enum` `export` `extends` `function` `import` `interface` `let` `var` |
| 运算符与操作 | `delete` `in` `instanceof` `new` `super` `this` `typeof` `void` |
| 值 | `false` `null` `true` |
| 其他 | `abstract` `as` `async` `await` `debugger` `implements` `package` `readonly` `static` `with` `yield` |

### 打印

console提供多种输出方式：`console.info`输出一般信息，`console.warn`输出警告，`console.error`输出错误。开发调试时可用模板字面量拼接变量值，或用`JSON.stringify`输出对象。

<!-- @[variable_output](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let outputName: string = 'ArkTS';
const version: number = 1.0;

console.info(`${outputName}`);              // ArkTS
console.info(`${version}`);      // 1
console.info(`Name: ${outputName}`);   // Name: ArkTS
console.info(`Version: ${version}, Name: ${outputName}`);  // Version: 1, Name: ArkTS
console.warn(`Version: ${version}, Name: ${outputName}`);  // Version: 1, Name: ArkTS
console.error('Invalid input');        // Invalid input
```

调试时建议根据信息级别选择对应方法，并用模板字符串或`JSON.stringify`格式化复杂对象输出。

## 注释

ArkTS支持单行注释（//）和多行注释（/* */），用于解释代码意图。

### 单行注释

单行注释使用//开始，用于简短说明或临时禁用代码。

<!-- @[single_line_comment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let commentCount: number = 10;  // 单行注释
```

### 多行注释

多行注释使用/* */包裹，用于详细说明或大段代码注释。

<!-- @[multi_line_comment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
/*
 * 多行注释
 * 可以跨越多行
 */
function calculate(): number {
  return 100;
}
```

### 文档注释

文档注释使用/** */包裹，用于生成API文档和类型提示。

<!-- @[documentation_comment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
/**
 * 计算两个数的和
 * @param a 第一个数
 * @param b 第二个数
 * @returns 两数之和
 */
function add(a: number, b: number): number {
  return a + b;
}
```

## 分号

每条语句末尾推荐使用分号结束，提高代码一致性和可读性。多条语句写在同一行时，分号是必须的。

<!-- @[semicolon_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let x: number = 10;
let y: number = 20;

// 同一行多个语句需要分号
let a: number = 1; let b: number = 2;

// 语句块末尾的分号可选
function greet(): void {
  console.info('Hello');
}
```

## 类型声明

类型声明通过类型标注在编译期约束变量、参数和返回值的类型，使编译器能在运行前发现类型不匹配的错误（如将`string`赋给`number`变量），而非等到运行时才暴露。ArkTS中类型声明有三种形式：类型注解（`: type`）、类型别名（`type Name = ...`）和接口声明（`interface`），分别适用于不同场景。

### 基本类型声明

通过[类型标注](#类型标注)（: type）为变量、参数和返回值标注类型。

<!-- @[type_annotation_examples](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// 变量类型
let annotExAge: number = 0;

// 函数参数和返回值类型
function annotExGreet(name: string): string {
  return `Hello, ${name}`;
}

// 类属性类型
class User {
  public id: number = 0;
  public name: string = '';
}
```

### 类型别名

类型别名为已有类型起一个新名字，简化复杂类型的书写。别名与原类型完全等价——使用别名等同于使用原类型，不创建新类型。常用于简化联合类型（如`type ID = number | string`）和复杂泛型（如`type Mapper<T, R> = (input: T) => R`）。

<!-- @[type_alias](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
type ID = number | string;
type Age = number;

let userId: ID = 123;
userId = 'ABC';
```

### 接口声明

interface定义对象的结构契约，描述属性名、类型和可选性。详细内容见[接口](arkts-language-guide-interfaces.md)。

<!-- @[interface_definition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface IfaceDefUser {
  id: number;
  name: string;
  email?: string;
}

let user: IfaceDefUser = { id: 1, name: 'Alice' };
```

## 类型

ArkTS提供number、boolean、string、数组、枚举等类型，约束值的范围和操作。

### number类型

number类型表示IEEE 754双精度浮点数（64位），没有独立的整数类型。支持十进制、十六进制、二进制和八进制字面量。

<!-- @[number_literals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let decimal: number = 42;      // 十进制
let hex: number = 0xFF;        // 十六进制 (255)
let binary: number = 0b1010;   // 二进制 (10)
let octal: number = 0o755;     // 八进制 (493)
```

### boolean类型

boolean类型表示逻辑值true或false，由直接赋值、比较运算（`===`、`!==`、`>`、`<`）和逻辑运算（`&&`、`||`、`!`）产生。布尔类型不可与其他类型隐式转换，避免JavaScript的类型混淆问题。

<!-- @[boolean_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let boolTypeIsActive: boolean = true;
let isComplete: boolean = false;

// 比较产生布尔值
let boolTypeX: number = 10;
let boolTypeY: number = 5;
let greater: boolean = boolTypeX > boolTypeY;  // true
```

注意条件判断时不要将布尔值与其他类型混用，ArkTS会在编译期拒绝隐式转换。

### array类型

array类型表示有序的元素集合，所有元素类型相同，支持通过索引访问。推荐使用`number[]`语法，也可用`Array<number>`泛型语法。详细内容见[集合类型](arkts-language-guide-collection-types.md)。

<!-- @[array_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// 数组声明
let arrTypeNumbers: number[] = [1, 2, 3];
let arrTypeNames: string[] = ['A', 'B', 'C'];

// 数组操作
arrTypeNumbers.push(4);
arrTypeNumbers.pop();
let first: number = arrTypeNumbers[0];
```

两种语法等价，团队内建议统一选用`number[]`以保持风格一致。

### object类型

object类型表示引用类型，包括类实例和接口对象，通过引用访问。

<!-- @[object_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
class Point {
  public x: number = 0;
  public y: number = 0;
}

let point: Point = new Point();
point.x = 10;
point.y = 20;

// 使用接口定义对象结构
interface ObjTypeUser {
  id: number;
  name: string;
}

let objTypeUser: ObjTypeUser = { id: 1, name: 'Alice' };
```
ArkTS要求对象布局在编译期确定，运行时不动态添加或删除属性。详细内容见[集合类型](arkts-language-guide-collection-types.md)。

### enum类型

enum类型为一组命名的常量值定义枚举，便于语义化表达固定状态。详细内容见[枚举](arkts-language-guide-enums.md)。

<!-- @[enum_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
enum Direction {
  Up,
  Down,
  Left,
  Right
}

let dir: Direction = Direction.Up;

// 带值的枚举
enum Status {
  Pending = 'pending',
  Active = 'active',
  Completed = 'completed'
}

let status: Status = Status.Active;
```
枚举值默认从0开始递增，也可显式指定字符串或数值以增强可读性与稳定性。

### union类型

union类型（联合类型）表示一个值可以是多种类型之一，用竖线（`|`）分隔。联合类型适用于：函数参数接受多种类型（如`id: number | string`）、变量在不同分支中持有不同类型的值、表达枚举的扩展集合。使用联合类型的值时，只能访问所有成员共有的属性；若需访问特定类型的属性，须通过`typeof`、`instanceof`或判别字段进行类型收窄。

<!-- @[union_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let unionTypeId: number | string = 123;
unionTypeId = 'ABC-123';

let result: number | null = null;
result = 100;

// 多类型联合
let data: number | string | boolean = 1;
data = 'text';
data = true;
```

### 字面量类型

字面量类型将值本身作为类型，限制变量只能取特定字面量值。

<!-- @[literal_union_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
type TaskState = 'pending' | 'running' | 'done';

let state: TaskState = 'pending';
state = 'running';
```
稳定状态集合优先使用`enum`，避免大量字符串字面量散落业务代码。

### void类型

void类型表示函数无返回值，常用于只执行操作不返回结果的函数；注意void与undefined不同，后者表示未定义值。

<!-- @[void_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function logMessage(message: string): void {
  console.info(`${message}`);
}

function doNothing(): void {
  // 无返回值
}
```

### never类型

never类型表示永不返回的函数——抛出异常或无限循环。

<!-- @[never_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function fail(message: string): never {
  throw new Error(message);
}

function assertNever(value: never): never {
  throw new Error(`Unexpected value: ${value}`);
}
```

never类型常用于两类场景：异常函数总是抛出异常永不返回，以及穷尽性检查——通过让default分支返回never确保switch覆盖所有枚举值。

### any和unknown的限制

ArkTS不支持any和unknown类型，应使用明确类型、联合类型或泛型替代。

**TypeScript对照**

<!-- @[ts_avoid_any_unknown](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// ArkTS中不使用：
let value: any;
let raw: unknown;

type InputValue = string | number | boolean;
let inputValue: InputValue = 'ok';
```
在定义变量类型时，应根据具体场景选择使用明确类型、联合类型、接口或类来实现类型安全。

### 高级类型边界

ArkTS更强调静态可判定的类型关系，以下TypeScript高级类型在ArkTS中均不支持，优先使用`interface extends`、类继承、泛型约束等替代方案：

| TypeScript高级类型 | 语法示例 | ArkTS替代方案 |
| --- | --- | --- |
| 交叉类型 | `A & B` | 使用`interface extends`多继承或类组合 |
| 条件类型 | `T extends U ? X : Y` | 使用显式接口或函数重载 |
| 映射类型 | `{ [K in keyof T]: ... }` | 使用显式接口或类 |
| 索引访问类型 | `T[K]` | 使用显式返回类型和字段访问方法 |

### bigint类型

bigint类型表示任意精度的整数，用n后缀标记字面量，适合超大整数运算。

<!-- @[bigint_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let bigValue: bigint = 999999999999999999999999999999999999n;
console.info(`${bigValue.toString()}`);

let nextValue: bigint = bigValue + 1n;
console.info(`${nextValue.toString()}`);
```

数字字面量后加`n`表示bigint类型，`bigValue`表示超大整数无精度损失，`nextValue`进行加法运算结果精确。bigint不能和`number`直接混合运算，需要显式转换。

<!-- @[bigint_conversion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let bigintCount: number = 10;
let preciseCount: bigint = BigInt(bigintCount);
let total: bigint = preciseCount + 20n;
```

需要注意的是，某些特定的API（如Date相关方法）或注解字段可能不支持`bigint`，使用前应确认对应API文档的类型约束。大整数优先使用bigint避免`number`精度损失，混合运算必须显式转换，bigint只支持整数运算不支持小数，部分旧版本API可能不支持bigint。

### symbol类型

symbol表示全局唯一的原始值，通过`Symbol()`创建，每次调用返回不同的唯一值，适合用作对象属性键以避免命名冲突。**ArkTS不支持`Symbol()` API**。

<!-- @[ts_symbol_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript支持symbol类型，ArkTS不支持Symbol() API
let sym1: symbol = Symbol('name');
let sym2: symbol = Symbol('name');
console.info(`${sym1 === sym2}`); // false，每个symbol唯一

let uniqueKey: symbol = Symbol('id');
let myMap: Map<symbol, string> = new Map();
myMap.set(uniqueKey, '123');
console.info(`${myMap.get(uniqueKey)}`); // 123
```

## 类型标注

类型标注为变量、参数和返回值指定类型，让编译器在编译期检查类型正确性。

<!-- @[type_annotation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// 基本类型标注
let age: number = 25;
let annotName: string = 'Alice';
let isValid: boolean = true;

// 引用类型标注
let annotNumbers: number[] = [1, 2, 3];
let names: string[] = ['A', 'B', 'C'];

// 联合类型
let id: number | string = 123;
id = 'ABC-123';
```

公共API和复杂类型（联合、泛型）应显式标注，简单局部变量可依赖类型推断。

## 类型推断

类型推断是编译器根据上下文自动推导变量或表达式的类型，无需开发者显式标注。ArkTS在大多数场景下支持类型推断，合理使用可减少冗余标注。

### 变量类型推断

变量赋值时，编译器根据右侧值推断左侧类型。

<!-- @[type_inference_variables](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let tiCount = 10;        // 推断为number
let tiMessage = 'hello'; // 推断为string
let tiItems = [1, 2, 3]; // 推断为number[]
```

`const`声明的变量推断为字面量类型，`let`声明的变量推断为宽泛类型。

<!-- @[type_inference_const_let](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
const tiPi = 3.14;   // 推断为3.14（字面量类型）
let tiRatio = 3.14;  // 推断为number（宽泛类型）
```

### 最佳通用类型

当多个候选类型存在时，编译器从中选择最通用的类型。数组包含多种类型元素时，推断为元素类型的联合。

<!-- @[type_inference_best_common](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let tiMixed: (number | null)[] = [0, 1, null]; // 需显式标注为联合类型数组
let tiNames: string[] = ['Alice', 'Bob'];      // 推断为string[]
```

如果无法找到统一的通用类型，则需要开发者显式标注。

### 上下文类型

上下文类型是指编译器根据变量所在的位置（如函数参数、回调）推断其类型。当函数的参数类型已知时，传入的回调函数参数会自动推断。

<!-- @[type_inference_contextual](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let tiCtxNames: string[] = ['Alice', 'Bob', 'Charlie'];
tiCtxNames.forEach((s) => {
  console.info(s.toUpperCase()); // s自动推断为string
});
```

回调函数的参数`s`无需标注类型，编译器根据`forEach`的签名自动推断为`string`。上下文类型与最佳通用类型互补，共同覆盖大多数推断场景。

### 控制流推断

编译器沿`if`/`else`、`switch`、循环等控制流分支追踪类型变化，在不同分支内将变量收窄为更具体的类型，分支合并后取联合类型。

<!-- @[type_inference_control_flow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let tiValue: string | number = 'hello';
if (typeof tiValue === 'string') {
  console.info(tiValue.toUpperCase()); // 此处value收窄为string
} else {
  console.info(`${tiValue}`);          // 此处value收窄为number
}
```

### 字面量推断

对象属性默认推断为宽泛类型而非字面量类型。TypeScript中可用`as const`将对象属性推断为字面量类型，ArkTS中不使用`as const`，需要字面量约束时使用`enum`或显式类型标注。

## 可选/可空类型

可选类型允许null或undefined，表示可能缺失的值。

### null/undefined

null表示有意赋的空值，undefined表示变量未赋值或属性不存在。两者语义不同，ArkTS中需显式区分。

<!-- @[null_undefined_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// null：有意的空值
let empty: null = null;
let nullUndefData: string | null = null;

// undefined：未定义值
let missing: undefined = undefined;
let optional: string | undefined = undefined;

// null与undefined区别
let nickname: string | null = null;     // 明确表示没有昵称
let title: string | undefined;          // 可能未提供
```

### 可选值绑定

可选属性（?）表示该属性可能不存在，访问前需通过显式检查（`if (value !== undefined)`）、类型守卫（`if (value !== null)`）或可选链（`value?.property`）处理。

<!-- @[optional_property](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface OptPropUser {
  id: number;
  name: string;
  email?: string;  // 可选属性
}

let optPropUser: OptPropUser = { id: 1, name: 'Alice' };

// 检查可选值是否存在
if (optPropUser.email !== undefined) {
  console.info(`${optPropUser.email}`);
}
```

访问多层嵌套的可选属性时，可选链能避免逐层判空，使代码更简洁。

### 提供默认值

通过空值合并运算符（??）或函数默认参数，在值为null/undefined时提供兜底值。注意`??`仅对`null`/`undefined`生效，而`||`会对所有假值（`0`、`false`、`''`）生效，需根据场景选择。

<!-- @[null_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// 空值合并运算符
let nullHandleValue: string | null = null;
let display: string = nullHandleValue ?? 'default';

// 函数默认参数
function nullHandleGreet(name: string, title: string = 'User'): string {
  return `Hello, ${title} ${name}`;
}

nullHandleGreet('Alice');           // Hello, User Alice
nullHandleGreet('Alice', 'Dr.');    // Hello, Dr. Alice
```

当默认值需要保留`0`、`false`、`''`等合法值时，必须使用`??`而非`||`。

## 非空断言

非空断言（Non-null Assertion）使用`!`操作符，告诉编译器“此处按非空处理”。非空断言会绕过编译器的空值检查，但不会在运行时生成任何验证代码。应优先使用类型守卫、可选链或空值合并，仅在确信非空时使用非空断言。

<!-- @[non_null_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let nonNullValue: string | null = 'text';

// 非空断言（确认值不为null）
let length: number = nonNullValue!.length;

// 类型守卫检查
if (nonNullValue !== null) {
  let len: number = nonNullValue.length;  // 安全访问
}
```

非空断言是"开发者承诺非空"的捷径，一旦承诺失误，运行时会直接崩溃，因此仅在确信非空且无法用类型守卫表达时使用。

### 隐式解析可空类型

可空类型（`T | null`/`T | undefined`）表示值可能不存在。与可选属性`?`的区别：`?`是属性声明时的修饰符（`name?: string`），而可空类型是显式的联合类型标注（`name: string | null`）。访问可空类型的值前须通过`if`检查、可选链`?.`或空值合并`??`处理可能的空值。

<!-- @[null_safety](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface NullableSub {
  sub?: string;
}

interface NullableObj {
  prop?: NullableSub;
}

let optionalValue: string | null = 'hello';

// 显式处理空值
if (optionalValue !== null) {
  console.info(`${optionalValue.length}`);
}

// 使用可选链
let obj: NullableObj = {};
let sub: string | undefined = obj?.prop?.sub;
```

## 类型安全与不可变性

类型安全在编译期捕获类型错误，不可变性通过const防止值被重新赋值。

### 类型安全

编译器拒绝类型不匹配的赋值，如将string赋给number变量。

<!-- @[ts_type_mismatch](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
let typeCheckAge: number = 25;
typeCheckAge = 'text';  // 编译错误：类型不匹配

function typeCheckAdd(a: number, b: number): number {
  return a + b;
}

typeCheckAdd(1, 2);      // 正确
typeCheckAdd(1, '2');    // 编译错误
```

类型安全能在编译期提前发现错误、避免运行时崩溃，同时提高代码可读性和重构安全性，并支持DevEco Studio的智能提示。

### 不可变性

const声明的变量不可重新赋值，确保值在生命周期内不变。

<!-- @[ts_immutability_violation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// const声明不可变常量
const MAX_VALUE: number = 100;
MAX_VALUE = 200;  // 编译错误

// readonly只读属性
interface Config {
  readonly apiKey: string;
}

let config: Config = { apiKey: 'key' };
config.apiKey = 'new';  // 编译错误

// 只读数组
let readonlyNumbers: ReadonlyArray<number> = [1, 2, 3];
readonlyNumbers[0] = 10;  // 编译错误
```

## 错误处理

通过try-catch捕获运行时异常，防止程序意外终止。

### try-catch异常捕获

try块包裹可能抛出异常的代码，catch块捕获并处理异常，防止程序意外终止。

<!-- @[try_catch_basic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function riskyOperation(): number {
  throw new Error('operation failed');
}

function parseJSON(data: string): Object {
  return JSON.parse(data);
}

let tcData: string = '{"name": "Alice"}';

try {
  let result: number = riskyOperation();
} catch (error) {
  console.info(`Error: ${error}`);
}

// 捕获特定错误
try {
  parseJSON(tcData);
} catch (error) {
  if (error instanceof SyntaxError) {
    console.info(`JSON 解析错误`);
  }
}
```

### throw抛出错误

throw语句抛出Error对象，中断当前函数并向外传播异常。

<!-- @[throwing_exceptions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function validateAge(age: number): void {
  if (age < 0) {
    throw new Error('年龄不能为负数');
  }
  if (age > 150) {
    throw new Error('年龄超出合理范围');
  }
}
```

抛出异常时应始终使用Error对象并附上清晰明确的错误信息，且仅在真正异常的情况下抛出，避免用异常控制正常流程。

### 错误处理约定

通过返回元组`[result, Error | null]`让调用方同时拿到结果和错误信息。

<!-- @[error_tuple_return](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
// 返回错误信息元组
function divide(a: number, b: number): [number, Error | null] {
  if (b === 0) {
    return [0, new Error('除数不能为零')];
  }
  return [a / b, null];
}

let divideResult: [number, Error | null] = divide(10, 0);
let errTupleResult: number = divideResult[0];
let error: Error | null = divideResult[1];

if (error !== null) {
  console.info(`${error.message}`);
}
```

## 断言与先决条件

断言在开发期验证内部假设，先决条件在函数入口校验外部入参。

### 使用断言调试

断言函数在条件为false时抛出错误，用于开发期发现逻辑错误。

<!-- @[assertion_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function assert(condition: boolean, message: string = 'Assertion failed'): void {
  if (!condition) {
    throw new Error(message);
  }
}

function assertEqual<T>(actual: T, expected: T, message?: string): void {
  if (actual !== expected) {
    throw new Error(message ?? `Expected ${expected}, got ${actual}`);
  }
}

// 使用断言
let assertFuncValue: number = 10;
assert(assertFuncValue > 0, '值必须为正数');
assertEqual(assertFuncValue, 10);
```

### 强制执行先决条件

先决条件函数在函数入口校验参数，不满足时立即抛出错误。

<!-- @[precondition_checks](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function precondition(condition: boolean, message: string): void {
  if (!condition) {
    throw new Error(`Precondition failed: ${message}`);
  }
}

function calculateSquareRoot(value: number): number {
  precondition(value >= 0, '参数必须为非负数');
  return Math.sqrt(value);
}

function getElement(arr: number[], index: number): number {
  precondition(index >= 0, '索引不能为负数');
  precondition(index < arr.length, '索引超出数组范围');
  return arr[index];
}
```

## 作用域规则

作用域决定变量的可见性和生命周期。ArkTS支持块级作用域和函数作用域。

### var声明（函数作用域）

`var`声明的变量具有函数作用域，存在变量提升（hoisting），可在声明前访问（值为`undefined`），且允许重复声明。**ArkTS不支持`var`声明**，使用`let`或`const`替代。

<!-- @[ts_var_declaration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript支持var声明，ArkTS不支持
function tsVarScope(): void {
  var x: number = 10;
  if (true) {
    var x: number = 20; // 同一作用域，重复声明
  }
  console.info(`${x}`); // 20
}

tsVarScope();
```

### let/const声明（块级作用域）

`let`和`const`声明的变量具有块级作用域，受暂时性死区（TDZ）保护，声明前不可访问，且不允许在同一作用域内重复声明。

<!-- @[let_const_block_scope](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
function blockScope(): void {
  let bsA: number = 10;
  const bsB: number = 20;
  if (true) {
    let bsA: number = 30; // 内层作用域的独立变量，不影响外层
    console.info(`${bsA}`); // 30
    console.info(`${bsB}`); // 20，可访问外层
  }
  console.info(`${bsA}`); // 10
}
```

### 嵌套作用域

内层作用域可访问外层变量，反之不行。`let`/`const`在嵌套块中可遮蔽外层同名变量，`var`则不行（同一函数作用域）。

<!-- @[nested_scope](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let nsOuter: string = 'outer';

function nestedScope(): void {
  let nsInner: number = 100;
  console.info(`${nsOuter}`); // 可访问外层

  if (true) {
    let nsInner: number = 200; // 遮蔽外层nsInner
    console.info(`${nsInner}`); // 200
  }
  console.info(`${nsInner}`); // 100
}
```

ArkTS推荐使用`let`和`const`，避免使用`var`。`const`用于不可重新赋值的引用，`let`用于需要修改的变量。

## 解构赋值

解构赋值允许从数组或对象中按位置或名称提取值赋给变量。TypeScript支持数组解构和对象解构，ArkTS不支持解构赋值语法。

### 数组解构

TypeScript中可用`let [a, b] = [1, 2]`从数组提取元素。ArkTS不支持解构变量声明（`arkts-no-destruct-decls`），详见[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md#不支持解构变量声明)，使用逐个赋值替代。

**TypeScript对照**

<!-- @[ts_array_destructuring](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript数组解构写法，ArkTS不支持
let pair: number[] = [1, 2];
let [first, second] = pair;
console.info(`${first}, ${second}`); // 1, 2
```

ArkTS替代方式：按索引访问数组元素。

<!-- @[array_access_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
let arrPair: number[] = [1, 2];
let arrFirst: number = arrPair[0];
let arrSecond: number = arrPair[1];
```

### 对象解构

TypeScript中可用`let { name, age } = obj`从对象提取属性。ArkTS不支持解构变量声明（`arkts-no-destruct-decls`），详见[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md#不支持解构变量声明)，使用逐个赋值替代。

**TypeScript对照**

<!-- @[ts_object_destructuring](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript对象解构写法，ArkTS不支持
interface TsUserInfo {
  name: string;
  age: number;
}

let tsUser: TsUserInfo = { name: 'Alice', age: 25 };
let { name: userName, age: userAge } = tsUser;
console.info(`${userName}, ${userAge}`); // Alice, 25
```

ArkTS替代方式：逐个访问属性。

<!-- @[object_access_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface DestrUserInfo {
  name: string;
  age: number;
}

let destrUser: DestrUserInfo = { name: 'Alice', age: 25 };
let destrUserName: string = destrUser.name;
let destrUserAge: number = destrUser.age;
```

### 函数参数解构

TypeScript中函数参数可直接解构对象。ArkTS不支持参数解构（`arkts-no-destruct-params`），详见[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md#不支持参数解构的函数声明)，使用接口类型参数替代。

**TypeScript对照**

<!-- @[ts_param_destructuring](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript写法，ArkTS不支持函数参数解构
interface GreetParam {
  name: string;
  age: number;
}

function greet({ name, age }: GreetParam): void {
  console.info(`Hello, ${name}, age ${age}`);
}

let greetParam: GreetParam = { name: 'Alice', age: 25 };
greet(greetParam);
```

ArkTS替代方式：使用接口类型参数替代。

<!-- @[param_destructuring_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface ParamUserInfo {
  name: string;
  age: number;
}

function greetUser(user: ParamUserInfo): void {
  console.info(`Hello, ${user.name}, age ${user.age}`);
}

greetUser({ name: 'Alice', age: 25 });
```

## 展开语法（spread）

展开语法`...`在ArkTS中仅支持数组和剩余参数，不支持对象展开（`arkts-no-spread`），详见[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md#部分支持展开运算符)。需要复制对象属性时，逐个赋值。

**TypeScript对照**

<!-- @[ts_object_spread](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Basics.ts) -->

``` TypeScript
// TypeScript对象展开写法，ArkTS不支持
interface TsConfig {
  host: string;
  port: number;
}

let original: TsConfig = { host: 'localhost', port: 8080 };
let copy: TsConfig = { ...original, port: 3000 };
console.info(`${copy.host}, ${copy.port}`); // localhost, 3000
```

ArkTS替代方式：逐个赋值对象属性。

<!-- @[spread_syntax_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Basics.ets) -->

``` TypeScript
interface SpreadConfig {
  host: string;
  port: number;
}

// 数组展开，ArkTS支持
let spreadArr1: number[] = [1, 2, 3];
let spreadArr2: number[] = [...spreadArr1, 4, 5];

// 对象属性复制，使用逐个赋值
let spreadOriginal: SpreadConfig = { host: 'localhost', port: 8080 };
let spreadCopy: SpreadConfig = {
  host: spreadOriginal.host,
  port: 3000
};
console.info(`${spreadCopy.host}, ${spreadCopy.port}`); // localhost, 3000
```
