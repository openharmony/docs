# ArkTS1.2互操作类型映射规则

## 编译类型检查原则

- 可以使用ArkTS1.1和TS中的类型在ArkTS1.2的源码中用作类型标注，也可以使用ArkTS1.2中的类型在ArkTS1.1的源码中用作类型标注。
- 编译类型检查将会根据源码文件的种类来进行：
  - ArkTS1.2的文件按照ArkTS1.2的类型检查规则
  - ArkTS1.1的文件按照ArkTS1.1的类型检查规则
  - 针对源码中的交互部分，编译器会使用特定的类型映射规则将交互部分的类型映射到所在文件的类型后，再进行编译检查。

## 类型映射基本原则

- 基本类型映射为基本类型（比如`number <-> number`）。
- 标准库类型映射为标准库类型（比如`Array <-> Array`）。
- 组合类型映射为组合类型（比如`class <-> class`）。
- 无法直接映射到ArkTS1.2的ArkTS1.1或TS类型，会被映射为`Any`（比如 TS `symbol -> 1.2 Any`）。
- 无法直接映射到ArkTS1.1的ArkTS1.2类型，会被映射为空，即交互场景不可用（比如ArkTS1.2的`final class`）。

## 类型映射详细规则

ArkTS1.2采用递归的方式定义类型映射，例如以下的类型映射。

| **T**           | **f(T)**              |
| --------------- | --------------------- |
| `number/Number` | `number`              |
| `(arg: A) => R` | `(arg: f(A)) => f(R)` |

这表示：

1. 第一行表示`Number`和`number`都被映射到`number`。
2. 第二行 lambda 类型`(arg: A) => R`被映射为参数类型为`f(A)`且返回值类型为`f(R)`的 lambda 类型，即`(arg: f(A)) => f(R)`；比如`(arg: number) => Number`被映射到`(arg: f(number)) => f(Number)`，即`(arg: number) => number`。

### ArkTS1.2类型映射到ArkTS1.1类型

#### 基本类型

| **1.2 type (T)**      | **1.1 type (f(T))**   |
| --------------------- | --------------------- |
| `number/Number`       | `number`              |
| `double/Double`       | `number`              |
| `float/Float`         | `number`              |
| `long/Long`           | `number`              |
| `int/Int`             | `number`              |
| `short/Short`         | `number`              |
| `byte/Byte`           | `number`              |
| `char/Char`           | `string`              |
| `string/String`       | `string`              |
| `literal type string` | `literal type string` |
| `boolean/Boolean`     | `boolean`             |
| `bigint/BigInt`       | `bigint`              |
| `null`                | `null`                |
| `undefined`           | `undefined`           |
| `void`                | `void`                |
| `never`               | `never`               |

注：`literal type string`指字符串字面量类型，比如`type Alice = 'Alice'`。

#### 标准库

| **1.2 type (T)**    | **1.1 type (f(T))** |
| ------------------- | ------------------- |
| `Array`             | `Array`             |
| `Map`               | `Map`               |
| `Set`               | `Set`               |
| `Promise`           | `Promise`           |
| `RegExp`            | `RegExp`            |
| `WeakMap`           | `WeakMap`           |
| `WeakSet`           | `WeakSet`           |
| `Object`            | `Object`            |
| `ArrayBuffer`       | `ArrayBuffer`       |
| `DataView`          | `DataView`          |
| `Date`              | `Date`              |
| `Error`             | `Error`             |
| `RangeError`        | `RangeError`        |
| `ReferenceError`    | `ReferenceError`    |
| `SyntaxError`       | `SyntaxError`       |
| `URIError`          | `URIError`          |
| `Float32Array`      | `Float32Array`      |
| `Float64Array`      | `Float64Array`      |
| `Int8Array`         | `Int8Array`         |
| `Int16Array`        | `Int16Array`        |
| `Int32Array`        | `Int32Array`        |
| `Uint8Array`        | `Uint8Array`        |
| `Uint16Array`       | `Uint16Array`       |
| `Uint32Array`       | `Uint32Array`       |
| `BigInt64Array`     | `BigInt64Array`     |
| `BigUint64Array`    | `BigUint64Array`    |
| `Uint8ClampedArray` | `Uint8ClampedArray` |

#### 工具类型

| **1.2 type (T)** | **1.1 type (f(T))** |
| ---------------- | ------------------- |
| `Readonly`       | `Readonly`          |
| `Record`         | `Record`            |
| `Required`       | `Required`          |
| `Partial`        | `Partial`           |

#### 函数

| **类别**               | **1.2 type (T)**                               | **1.1 type (f(T))**                                            |
| ---------------------- | ---------------------------------------------- | -------------------------------------------------------------- |
| 普通函数               | `function foo(arg1: K1, arg2: K2): R`          | `function foo(arg1: f(K1), arg2: f(K2)): f(R)`                 |
| 可选参数               | `function foo(arg1: K1, arg2​?​: K2): R`       | `function foo(arg1: f(K1), arg2​?​: f(K2)): f(R)`              |
| 只读参数               | `function foo(arg1: K1, readonly arg2: K2): R` | `function foo(arg1: f(K1), readonly arg2: f(K2)): f(R)`        |
| 剩余参数               | `function foo(arg1: K1, ...​arg2: K2): R`      | `function foo(arg1: f(K1), ...​arg2: f1.2 type (T)(K2)): f(R)` |
| 普通lambda             | `(arg1: K1, arg2: K2) => R`                    | `(arg1: f(K1), arg2: f(K2)) => f(R)`                           |
| function with receiver | `function foo(​this​: K1, arg2: K): R`         | `function foo(this: f(K1), arg2: f(K2)): f(R)`                 |
| lambda with receiver   | `(​this​: K1, arg2: K2) => R`                  | `(this: f(K1), arg2: f(K2)) => f(R)`                           |
| getter with receiver   | `get fullName(​this​: K1, arg2: K): R`         | map to nothing                                                 |
| setter with receiver   | `set fullName(​this: K1, arg2: K): R`          | map to nothing                                                 |

#### 类

TODO: 美化表格

| **类别**                                 | **1.2 type (T)**                                                                                          | **1.1 type (f(T))**                                                                                                                                       |
| ---------------------------------------- | --------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 普通类                                   | class A { field: F1m(arg: U1): M1static sf: F2static sm(arg: U2): M2get a(): Vset a(v: V): void}          | class A { get field(): f(F1)set field(arg: f(F1)): voidm(arg: f(U1)): f(M1)static sf: f(F2)static sm(arg: f(U2)): f(M2)get a(): f(V)set a(v: f(V)): void} |
| public/private/protected/native/readonly | class A {public field: F1readonly r: F2private m(arg: U1): M1protect p(arg: U2): M2native n(arg: U3): M3} | class A {public field: f(F1)get r(): f(F2)private m(arg: f(U1)): f(M1)protect p(arg: f(U2)): f(M2)n(arg: U3): M3 // native will be ignored}               |
| 抽象类                                   | abstract class A { ... }                                                                                  | abstract class A { ... } // 保留 abstract关键字，内部遵循相同的规则                                                                                       |
| 继承类和override                         | class C extends A {override foo(arg: U1): M1}                                                             | class C extends A {override foo(arg: f(U1)): f(M1)}                                                                                                       |
| 实现类                                   | class A implements Inface { ... }                                                                         | class A implements Inface { ... }                                                                                                                         |
| final类                                  | final class A { ... }                                                                                     | map to**nothing ​**as it cannot be used in interop                                                                                                        |

#### 接口

TODO: 美化表格

| **类别** | **1.2 type (T)**                                                | **1.1 type (f(T))**                                                         |
| -------- | --------------------------------------------------------------- | --------------------------------------------------------------------------- |
| 普通接口 | inteface A {field: F1m(arg: U1): M1get a(): Vset a(v: V): void} | class A {field: f(F1)m(arg: f(U1)): f(M1)get a(): f(V)set a(v: f(V)): void} |
| 继承接口 | interface A extends B { ... }                                   | interface A extends B { ... }                                               |

#### 枚举

| **类别**         | **1.2 type (T)**                     | **1.1 type (f(T))**                  |
| ---------------- | ------------------------------------ | ------------------------------------ |
| 枚举值都为整数   | `enum Color {Blue = 0, Red = 1}`     | `enum Color {Blue = 0, Red = 1}`     |
| 枚举值都为字符串 | `enum Some {A = 'Alice', B = 'Bob'}` | `enum Some {A = 'Alice', B = 'Bob'}` |

#### 注解

注解不能用于交互，映射为空。

#### 命名空间

| **1.2 type (T)**     | **1.1 type (f(T))**  |
| -------------------- | -------------------- |
| `namespace NS {...}` | `namespace NS {...}` |

#### 联合类型

| **1.2 type (T)** | **1.1 type (f(T))**       |
| ---------------- | ------------------------- |
| `T1 \| T2 \| T3` | `f(T1) \| f(T2) \| f(T3)` |

#### 元组类型

| **1.2 type (T)** | **1.1 type (f(T))**     |
| ---------------- | ----------------------- |
| `[T1, T2, T3]`   | `[f(T1), f(T2), f(T3)]` |

#### 类型别名

| **1.2 type (T)** | **1.1 type (f(T))** |
| ---------------- | ------------------- |
| `type alias = K` | `type alias = f(K)` |

### 1.1类型映射到1.2类型

#### 基本类型

| **1.1 type (T)**      | **1.2 type (f(T))**   |
| --------------------- | --------------------- |
| `number/Number`       | `number`              |
| `string/String`       | `string`              |
| `literal type string` | `literal type string` |
| `boolean/Boolean`     | `boolean`             |
| `bigint/BigInt`       | `bigint`              |
| `null`                | `null`                |
| `undefined`           | `undefined`           |
| `void`                | `void`                |
| `never`               | `never`               |
| `literal type number` | `number`              |
| `literal type bigint` | `bigint`              |

> **注意：** `literal type number`和`literal type bigint`分别表示数字字面量和bigint字面量的类型，比如`type PI = 3.14, type LightYear= 9460730472580800n`。

#### 标准库

| **1.1 type (T)**    | **1.2 type (f(T))** |
| ------------------- | ------------------- |
| `Arrays`            | `Arrays`            |
| `Map`               | `Map`               |
| `Set`               | `Set`               |
| `Promise`           | `Promise`           |
| `RegExp`            | `RegExp`            |
| `WeakMap`           | `WeakMap`           |
| `WeakSet`           | `WeakSet`           |
| `Object`            | `Object`            |
| `ArrayBuffer`       | `ArrayBuffer`       |
| `DataView`          | `DataView`          |
| `Date`              | `Date`              |
| `Error`             | `Error`             |
| `RangeError`        | `RangeError`        |
| `ReferenceError`    | `ReferenceError`    |
| `SyntaxError`       | `SyntaxError`       |
| `URIError`          | `URIError`          |
| `Float32Array`      | `Float32Array`      |
| `Float64Array`      | `Float64Array`      |
| `Int8Array`         | `Int8Array`         |
| `Int16Array`        | `Int16Array`        |
| `Int32Array`        | `Int32Array`        |
| `Uint8Array`        | `Uint8Array`        |
| `Uint16Array`       | `Uint16Array`       |
| `Uint32Array`       | `Uint32Array`       |
| `BigInt64Array`     | `BigInt64Array`     |
| `BigUint64Array`    | `BigUint64Array`    |
| `Uint8ClampedArray` | `Uint8ClampedArray` |

#### 工具类型

| **1.1 type (T)** | **1.2 type (f(T))** |
| ---------------- | ------------------- |
| `Readonly`       | `Readonly`          |
| `Record`         | `Record`            |
| `Required`       | `Required`          |
| `Partial`        | `Partial`           |

#### 函数

| **类别**   | **1.1 type (T)**                               | **1.2 type (f(T))**                                     |
| ---------- | ---------------------------------------------- | ------------------------------------------------------- |
| 普通函数   | `function foo(arg1: K1, arg2: K2): R`          | `function foo(arg1: f(K1), arg2: f(K2)): f(R)`          |
| 可选参数   | `function foo(arg1: K1, arg2?​: K2): R`        | `function foo(arg1: f(K1), arg2​​: f(K2)): f(R)`        |
| 只读参数   | `function foo(arg1: K1, readonly arg2: K2): R` | `function foo(arg1: f(K1), readonly arg2: f(K2)): f(R)` |
| 剩余参数   | `function foo(arg1: K1, ...arg2: K2): R`       | `function foo(arg1: f(K1), ...​arg2: f(K2)): f(R)`      |
| 普通lambda | `(arg1: K1, arg2: K2) => R`                    | `(arg1: f(K1), arg2: f(K2)) => f(R)`                    |

#### 类

TODO: 美化表格

| **类别**                          | **1.1 type (T)**                                                                                | **1.2 type (f(T))**                                                                                                     |
| --------------------------------- | ----------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| 普通类                            | class A {field: F1m(arg: U1): M1static sf: F2static sm(arg: U2): M2get a(): Vset a(v: V): void} | class A {field: f(F1)m(arg: f(U1)): f(M1)static sf: f(F2)static sm(arg: f(U2)): f(M2)get a(): f(V)set a(v: f(V)): void} |
| public/private/protected/readonly | class A {public field: F1readonly r: F2private m(arg: U1): M1protect p(arg: U2): M2}            | class A {public field: f(F1)get r(): f(F2)private m(arg: f(U1)): f(M1)protect p(arg: f(U2)): f(M2)}                     |
| 抽象类                            | abstract class A { ... }                                                                        | abstract class A { ... } // 保留 abstract关键字，内部遵循相同的规则。                                                   |
| 继承类和override                  | class C extends A {override foo(arg: U1): M1}                                                   | class C extends A {override foo(arg: f(U1)): f(M1)}                                                                     |
| 实现类                            | class A implements Inface { ... }                                                               | class A implements Inface { ... }                                                                                       |

#### 接口

TODO: 美化表格

| **类别** | **1.1 type (T)**                                                 | **1.2 type (f(T))**                                                             |
| -------- | ---------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| 普通接口 | interface A {field: F1m(arg: U1): M1get a(): Vset a(v: V): void} | interface A {field: f(F1)m(arg: f(U1)): f(M1)get a(): f(V)set a(v: f(V)): void} |
| 继承接口 | interface A extends B { ... }                                    | interface A extends B { ... }                                                   |

#### 枚举

| **类别**         | **1.1 type (T)**                                  | **1.2 type (f(T))**                  |
| ---------------- | ------------------------------------------------- | ------------------------------------ |
| 枚举值都为整数   | `enum Color {Blue = 0,- Red = 1}`                 | `enum Color {Blue = 0, Red = 1}`     |
| 枚举值都为字符串 | `enum Some {A = 'Alice', B = 'Bob'}`              | `enum Some {A = 'Alice', B = 'Bob'}` |
| 其它枚举         | `enum Mix {One = 1, Msg = 'hello', Double = 1.2}` | `Any`                           |

#### 注解

注解不能用于交互，映射为空。

#### 装饰器

装饰器不能用于交互，映射为空。（ArkUI定义的装饰器会被特殊处理，映射为ArkTS1.2的注解）

#### 命名空间

| **1.2 type (T)**     | **1.1 type (f(T))**  |
| -------------------- | -------------------- |
| `namespace NS {...}` | `namespace NS {...}` |

#### 联合类型

| **1.2 type (T)** | **1.1 type (f(T))**       |
| ---------------- | ------------------------- |
| `T1 \| T2 \| T3` | `f(T1) \| f(T2) \| f(T3)` |

#### 元组类型

| **1.2 type (T)** | **1.1 type (f(T))**     |
| ---------------- | ----------------------- |
| `[T1, T2, T3]`   | `[f(T1), f(T2), f(T3)]` |

#### 类型别名

| **1.2 type (T)** | **1.1 type (f(T))** |
| ---------------- | ------------------- |
| `type alias = K` | `type alias = f(K)` |

### TS类型映射到ArkTS1.2类型

#### 基本类型

| **TS type (T)**       | **1.2 type (f(T))**   |
| --------------------- | --------------------- |
| `number/Number`       | `number`              |
| `string/String`       | `string`              |
| `literal type string` | `literal type string` |
| `boolean/Boolean`     | `boolean`             |
| `bigint/BigInt`       | `bigint`              |
| `null`                | `null`                |
| `undefined`           | `undefined`           |
| `void`                | `void`                |
| `never`               | `never`               |
| `literal type number` | `number`              |
| `literal type bigint` | `bigint`              |
| `any`                 | `Any`            |
| `symbol/Symbol`       | `Any`            |
| `unknown`             | `Any`            |

#### 标准库

| **TS type (T)**     | **1.2 type (f(T))** |
| ------------------- | ------------------- |
| `Arrays`            | `Arrays`            |
| `Map`               | `Map`               |
| `Set`               | `Set`               |
| `Promise`           | `Promise`           |
| `RegExp`            | `RegExp`            |
| `WeakMap`           | `WeakMap`           |
| `WeakSet`           | `WeakSet`           |
| `Object`            | `Object`            |
| `ArrayBuffer`       | `ArrayBuffer`       |
| `DataView`          | `DataView`          |
| `Date`              | `Date`              |
| `Error`             | `Error`             |
| `RangeError`        | `RangeError`        |
| `ReferenceError`    | `ReferenceError`    |
| `SyntaxError`       | `SyntaxError`       |
| `URIError`          | `URIError`          |
| `Float32Array`      | `Float32Array`      |
| `Float64Array`      | `Float64Array`      |
| `Int8Array`         | `Int8Array`         |
| `Int16Array`        | `Int16Array`        |
| `Int32Array`        | `Int32Array`        |
| `Uint8Array`        | `Uint8Array`        |
| `Uint16Array`       | `Uint16Array`       |
| `Uint32Array`       | `Uint32Array`       |
| `BigInt64Array`     | `BigInt64Array`     |
| `BigUint64Array`    | `BigUint64Array`    |
| `Uint8ClampedArray` | `Uint8ClampedArray` |

#### 工具类型

| **TS type (T)**          | **1.2 type (f(T))** |
| ------------------------ | ------------------- |
| `Readonly`               | `Readonly`          |
| `Record`                 | `Record`            |
| `Required`               | `Required`          |
| `Partial`                | `Partial`           |
| `Pick`                   | `Any`          |
| `Omit`                   | `Any`          |
| `Exclude`                | `Any`          |
| `Extract`                | `Any`          |
| `NonNullable`            | `Any`          |
| `Parameters`             | `Any`          |
| `Constructor`            | `Any`          |
| `Parameters`             | `Any`          |
| `ReturnType`             | `Any`          |
| `InstanceType`           | `Any`          |
| `NoInfer`                | `Any`          |
| `This`                   | `Any`          |
| `ParameterType`          | `Any`          |
| `OmitThisParameter`      | `Any`          |
| `ThisType`               | `Any`          |
| `Uppercase`              | `Any`          |
| `Lowercase`              | `Any`          |
| `CapitalizeUncapitalize` | `Any`          |

#### 函数

| **类别**   | **TS type (T)**                                | **1.2 type (f(T))**                                     |
| ---------- | ---------------------------------------------- | ------------------------------------------------------- |
| 普通函数   | `function foo(arg1: K1, arg2: K2): R`          | `function foo(arg1: f(K1), arg2: f(K2)): f(R)`          |
| 可选参数   | `function foo(arg1: K1, arg2​?​: K2): R`       | `function foo(arg1: f(K1), arg2​?​: f(K2)): f(R)`       |
| 只读参数   | `function foo(arg1: K1, readonly arg2: K2): R` | `function foo(arg1: f(K1), readonly arg2: f(K2)): f(R)` |
| 剩余参数   | `function foo(arg1: K1, ​...​arg2: K2): R`     | `function foo(arg1: f(K1), ...​arg2: f(K2)): f(R)`      |
| 普通lambda | `(arg1: K1, arg2: K2) => R`                    | `(arg1: f(K1), arg2: f(K2)) => f(R)`                    |

#### 类

TODO: 美化表格

| **类别**                          | **TS type (T)**                                                                                 | **1.2 type (f(T))**                                                                                                     |
| --------------------------------- | ----------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| 普通类                            | class A {field: F1m(arg: U1): M1static sf: F2static sm(arg: U2): M2get a(): Vset a(v: V): void} | class A {field: f(F1)m(arg: f(U1)): f(M1)static sf: f(F2)static sm(arg: f(U2)): f(M2)get a(): f(V)set a(v: f(V)): void} |
| public/private/protected/readonly | class A {public field: F1readonly r: F2private m(arg: U1): M1protect p(arg: U2): M2}            | class A {public field: f(F1)get r(): f(F2)private m(arg: f(U1)): f(M1)protect p(arg: f(U2)): f(M2)}                     |
| 抽象类                            | abstract class A { ... }                                                                        | abstract class A { ... } // 保留 abstract关键字，内部遵循相同的规则                                                     |
| 继承类和override                  | class C extends A {override foo(arg: U1): M1}                                                   | class C extends A {override foo(arg: f(U1)): f(M1)}                                                                     |
| 实现类                            | class A implements Inface { ... }                                                               | class A implements Inface { ... }                                                                                       |

#### 接口

TODO: 美化表格

| **类别** | **TS type (T)**                                                  | **1.2 type (f(T))**                                                             |
| -------- | ---------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| 普通接口 | interface A {field: F1m(arg: U1): M1get a(): Vset a(v: V): void} | interface A {field: f(F1)m(arg: f(U1)): f(M1)get a(): f(V)set a(v: f(V)): void} |
| 继承接口 | interface A extends B { ... }                                    | interface A extends B { ... }                                                   |

#### 枚举

| **类别**         | **TS type (T)**                                   | **1.2 type (f(T))**                  |
| ---------------- | ------------------------------------------------- | ------------------------------------ |
| 枚举值都为整数   | `enum Color {Blue = 0, Red = 1}`                  | `enum Color {Blue = 0, Red = 1}`     |
| 枚举值都为字符串 | `enum Some {A = 'Alice', B = 'Bob'}`              | `enum Some {A = 'Alice', B = 'Bob'}` |
| 其它枚举         | `enum Mix {One = 1, Msg = 'hello', Double = 1.2}` | `Any`                           |

#### 装饰器

装饰器不能用于交互，映射为空（ArkUI定义的装饰器会被特殊处理，映射为ArkTS1.2的注解）。

#### 命名空间

| **1.2 type (T)**     | **1.1 type (f(T))**  |
| -------------------- | -------------------- |
| `namespace NS {...}` | `namespace NS {...}` |

#### 联合类型

| **1.2 type (T)** | **1.1 type (f(T))**       |
| ---------------- | ------------------------- |
| `T1 \| T2 \| T3` | `f(T1) \| f(T2) \| f(T3)` |

#### 元组类型

| **1.2 type (T)** | **1.1 type (f(T))**     |
| ---------------- | ----------------------- |
| `[T1, T2, T3]`   | `[f(T1), f(T2), f(T3)]` |

#### 类型别名

| **1.2 type (T)** | **1.1 type (f(T))** |
| ---------------- | ------------------- |
| `type alias = K` | `type alias = f(K)` |

#### 其它类型

##### 字面量类型

| **TS type (T)**               | **1.2 type (f(T))** |
| ----------------------------- | ------------------- |
| `{name: string, age: number}` | `Any`          |

##### 调用签名

| **TS type (T)**              | **1.2 type (f(T))** |
| ---------------------------- | ------------------- |
| `{ (arg: T1): R }`           | `Any`          |
| `interface X {(arg): T1: R}` | `Any`          |

##### 构造签名

| **TS type (T)**                  | **1.2 type (f(T))** |
| -------------------------------- | ------------------- |
| `{ new (arg: T1): R }`           | `Any`          |
| `interface X {new (arg): T1: R}` | `Any`          |

##### 索引签名

| **TS type (T)**               | **1.2 type (f(T))** |
| ----------------------------- | ------------------- |
| `{ [index: T]: R }`           | `Any`          |
| `interface X {[index: T]: R}` | `Any`          |

##### 相交类型

| **TS type (T)** | **1.2 type (f(T))** |
| --------------- | ------------------- |
| `T1 & T2`       | `Any`          |

##### keyof

| **TS type (T)**                 | **1.2 type (f(T))**  |
| ------------------------------- | -------------------- |
| `type My = keyof T`             | `type My = Any` |
| `interface X { props: keyof T}` | `Any`           |

##### typeof

| **TS type (T)**  | **1.2 type (f(T))** |
| ---------------- | ------------------- |
| `typeof someVar` | `Any`          |

##### 索引访问类型

| **TS type (T)**     | **1.2 type (f(T))** |
| ------------------- | ------------------- |
| `someArray[number]` | `Any`          |

例子：

```typescript
// ts
MyArray = [{ name: "Alice", age: 15 }];
export type Person = (typeof MyArray)[number];

// declaration in ArkTS 1.2 is
export type Person = Any;
```

##### 条件类型

| **TS type (T)**     | **1.2 type (f(T))** |
| ------------------- | ------------------- |
| `condition ? A : B` | `Any`          |

##### 映射类型

| **TS type (T)** | **1.2 type (f(T))** |
| --------------- | ------------------- |
| `SomeType[Key]` | `Any`          |

示例如下：

```typescript
// ts
export type A<T> = { [K in keyof T]: T[K] };

// declaration in 1.2 is
export type A<T> = Any;
```

##### 模板字面量类型

| **TS type (T)**            | **1.2 type (f(T))** |
| -------------------------- | ------------------- |
| `...${SomeLiteralType}...` | `Any`          |

示例如下：

```typescript
// ts
export type AB = "A" | "B";
export type AllLocaleIDs = `${AB}_id`;

// declaration in 1.2 is
export type AB = "A" | "B";
export type AllLocaleIDs = Any;
```
