# ArkCompiler子系统变更说明

## cl.arkcompiler.1 Sendable容器TypedArray提供的map方法的回调函数声明变更

**访问级别**

公开接口

**变更原因**

Sendable容器TypedArray提供map方法。该方法对TypedArray中的每个元素进行某种操作或转换（通过callbackFn的返回值），并返回一个新的TypedArray，其中包含经过映射函数处理后的结果。

以Uint8Array为例，变更前，map函数的callbackFn声明无返回值，导致转换后的数据丢失，引起开发者使用上的困惑。
- map方法的回调函数声明为`map(callbackFn: TypedArrayForEachCallback<number, Uint8Array>): Uint8Array;`
- 而TypedArrayForEachCallback 的定义为无返回值的：`type TypedArrayForEachCallback<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => void;`

**变更影响**

此变更为不兼容变更。

**变更前**

- 情况一： map函数中的callbackFn无返回值，能通过编译，但是无法实现map功能
- 情况二： map函数中的callbackFn有返回值，但是返回类型不是number，能通过编译，能实现map功能
- 情况三： map函数中的callbackFn有返回值，且返回类型是number，能通过编译，能实现map功能

```
let arr = [1, 2, 3, 4, 5];

// 创建一个Uint8Array
let uint8: collections.Uint8Array = new collections.Uint8Array(arr);

// 情况一：不能完成map功能：callbackFn无返回值，map函数返回新的collections.Uint8Array
let zeroMappedArray: collections.Uint8Array = uint8.map((value: number) => {}); // 能通过编译
console.info('' + zeroMappedArray); // 输出: collections.Uint8Array [0, 0, 0, 0, 0]

// 情况二：能完成map功能：callbackFn返回map后的元素值，但类型为string，map函数返回新的collections.Uint8Array
let wrongTypeMapped: collections.Uint8Array = uint8.map((value: number) => value + "1"); // 能通过编译
console.info('' + wrongTypeMapped); // 输出: collections.Uint8Array [11, 21, 31, 41, 51]

// 情况三：能完成map功能：callbackFn返回map后的元素值，map函数返回新的collections.Uint8Array
let normalMapped: collections.Uint8Array = uint8.map((value: number) => value * 2); // 能通过编译
console.info('' + normalMapped); // 输出: collections.Uint8Array [2, 4, 6, 8, 10]
```

**变更后**

- 情况一： map函数中的callbackFn无返回值，不能通过编译（不兼容变更）
- 情况二： map函数中的callbackFn有返回值，但是返回类型不是number，不能通过编译（不兼容变更）
- 情况三： map函数中的callbackFn有返回值，且返回类型是number，能通过编译，能实现map功能（兼容）


```
let arr = [1, 2, 3, 4, 5];

// 创建一个Uint8Array
let uint8: collections.Uint8Array = new collections.Uint8Array(arr);

// 情况一：不能完成map功能：callbackFn无返回值，map函数返回新的collections.Uint8Array
let zeroMappedArray: collections.Uint8Array = uint8.map((value: number) => {}); // 不兼容变更：不能通过编译

// 情况二：能完成map功能：callbackFn返回map后的元素值，但类型为string，map函数返回新的collections.Uint8Array
let wrongTypeMapped: collections.Uint8Array = uint8.map((value: number) => value + "1"); // 不兼容变更：不能通过编译

// 情况三：能完成map功能：callbackFn返回map后的元素值，map函数返回新的collections.Uint8Array
let normalMapped: collections.Uint8Array = uint8.map((value: number) => value * 2); // 能通过编译
console.info('' + normalMapped); // 输出: collections.Uint8Array [2, 4, 6, 8, 10]
```

**起始API Level**

API12

**变更发生版本**

从OpenHarmony SDK 5.0.0.31 版本开始。

**变更的接口/组件**

/interface/sdk-js/arkts/@arkts.collections.d.ets中TypedArray（包括Int8Array/Uint8Array/Int16Array/Uint16Array/Int32Array/Uint32Array）的map接口

**适配指导**

- 举例：上述场景二的例子，可以做如下修改：
```
let wrongTypeMapped: collections.Uint8Array = uint8.map((value: number) => parseInt(value + "1")); // 通过parseInt进行字符串到number的转换
```

- 详细说明参见：接口使用的示例代码:
[ArkTS容器集 - TypedArray](../../../application-dev/reference/apis-arkts/js-apis-arkts-collections.md#collectionstypedarray)

## cl.arkcompiler.2 ArkTS Sendable语法规则编译检查完善

**访问级别**

其他

**变更原因**

Sendable对象需要遵循一定[使用规则](../../..//application-dev/arkts-utils/arkts-sendable.md#sendable使用规则)，在Sendable泛型类的部分语法中，编译器没有对应的检查，导致这些语法下的Sendable对象用在并发场景中运行异常但是没有无编译时错误。在本次版本更新中，我们修复了这些场景下Sendable约束的编译时检查，将运行时异常提前到编译时。旨在通过编译时错误，帮助开发者更早发现Sendable使用约束，减少运行时定位成本。

**变更影响**

此变更为不兼容变更。


变更前：当Sendable泛型类用作类型标注时，类型形参可以使用Non-sendable类型，DevEco编辑界面没有错误提示，编译没有报错。

变更后：当Sendable泛型类用作类型标注时，类型形参不可以使用Non-sendable类型，DevEco编辑界面有错误提示，编译有报错。

对于使用Sendable泛型类进行声明，但是被赋值为Non-sendable对象的变量/参数/返回值，如果它们被用在并发实例共享的场景中，变更前会有运行时异常，变更后错误提前至编译期。如果它们被当作普通对象使用时，变更前运行时不报错，变更后编译器新增报错。


具体场景示例：

Sendable泛型类约束

场景一：当Sendable对象被用在多线程共享时，影响：运行时异常提前到编译时

变更前

```ts
// declaration.ets
export class NonSendableClass {};

// main.ets
import { NonSendableClass } from './declaration';
import collections from '@arkts.collections';

@Sendable
class SendableClass {
    private arr: collections.Array<NonSendableClass> = new collections.Array();
    constructor() {
        this.arr.push(new NonSendableClass()); // Runtime ERROR
    }
}
let sendableclassObject: SendableClass = new SendableClass();
```

变更后

```ts
// declaration.ets
export class NonSendableClass {};

// main.ets
import { NonSendableClass } from './declaration';
import collections from '@arkts.collections';

@Sendable
class SendableClass {
    private arr: collections.Array<NonSendableClass> = new collections.Array(); // ArkTS compile-time error
    constructor() {
        this.arr.push(new NonSendableClass());
    }
}
let sendableclassObject: SendableClass = new SendableClass();
```

场景二：Sendable对象被当作普通对象使用时，影响：产生不兼容变更新增编译报错

变更前

```ts
@Sendable
class SendableClassA<T> {
    one: string = '1';
}
class NoneSendableClassA<T> {
    one: string = '1';
}
let sendableObjectA: SendableClassA<NoneSendableClassA<number>> = new SendableClassA();
```

变更后

```ts
@Sendable
class SendableClassA<T> {
    one: string = '1';
}
class NoneSendableClassA<T> {
    one: string = '1';
}
let sendableObjectA: SendableClassA<NoneSendableClassA<number>> = new SendableClassA(); // ArkTS compile-time error
```

**起始 API Level**

ArkTS Sendable语法检查从API 12起启用。

**变更发生版本**

从OpenHarmony SDK 5.0.0.31 开始。

**变更的接口/组件**

不涉及。

**适配指导**

Sendable泛型类的类型必须使用Sendable类型。

## cl.arkcompiler.3 ArkTS Sendable赋值语法规则编译检查完善

**访问级别**

其他

**变更原因**

Sendable赋值时需要遵循一定[使用规则](../../..//application-dev/arkts-utils/arkts-sendable.md#sendable使用规则)，但是在Non-sendable对象赋值给Sendable类型的部分场景中，编译没有对应的检查，导致这些场景下的Non-sendable对象被当成Sendable对象使用，运行异常但是没有编译时报错。在本次版本更新中，我们修复了这些场景下Sendable赋值约束的编译时检查，将运行时异常提前到编译时。旨在通过编译时错误，帮助开发者更早发现Sendable使用约束，减少运行时定位成本。

错误对象：使用Sendable类型/接口进行声明，但是被赋值为Non-sendable对象的变量/参数/返回值。

**变更影响**

此变更为不兼容变更。

变更前：Non-sendable对象赋值给Sendable类型的部分场景中，DevEco编辑界面没有错误提示，编译没有报错。

变更后：Non-sendable对象赋值给Sendable类型的部分场景中，DevEco编辑界面有错误提示，编译有报错。

当错误对象被当成Sendable对象使用时，将运行时报错提前到编译期。当错误对象被当做普通对象使用时，运行时不报错但编译期新增报错。变更前，在一些场景下Non-sendable对象可以被赋值给Sendable类型。变更后，Non-sendable对象不可以赋值给Sendable类型。
 
下面的场景将会报错：

Sendable赋值约束

场景一：当错误对象被当成Sendable对象使用时

变更前

```ts
// declaration.ets
export class NonSendableClass {};
@Sendable
export class SendableClass {};

export class NonSendableClassT<T> {};
@Sendable
export class SendableClassT<T> {};

// main.ets
import { NonSendableClass, SendableClass, NonSendableClassT, SendableClassT } from './declaration';
import collections from '@arkts.collections';

@Sendable
class SendableData {
    propA: SendableClass = new NonSendableClass(); // Runtime ERROR
    propB: SendableClassT<number>;
    propC: SendableClass;
    propD: SendableClass;
    propE: SendableClass;

    constructor(sendableT: SendableClassT<number>) {
      const sendableList: SendableClass[] = [new NonSendableClass()];
      this.propB = new NonSendableClassT<number>(); // Runtime ERROR
      this.propC = this.getSendable(); // Runtime ERROR
      this.propD = sendableList[0]; // Runtime ERROR
      this.propE = sendableT; // Runtime ERROR
    }

    getSendable(): SendableClass {
        return new NonSendableClass();
    }
}

new SendableData(new NonSendableClassT<number>());

const sendable: SendableClassT<number> = new NonSendableClassT<number>();
const sendableArray: collections.Array<SendableClass> = new collections.Array<SendableClass>();
sendableArray.push(sendable); // Runtime ERROR

```

变更后

```ts
// declaration.ets
export class NonSendableClass {};
@Sendable
export class SendableClass {};

export class NonSendableClassT<T> {};
@Sendable
export class SendableClassT<T> {};

// main.ets
import { NonSendableClass, SendableClass, NonSendableClassT, SendableClassT } from './declaration';
import collections from '@arkts.collections';

@Sendable
class SendableData {
    propA: SendableClass = new NonSendableClass(); // ArkTS compile-time error
    propB: SendableClassT<number>;
    propC: SendableClass;
    propD: SendableClass;
    propE: SendableClass;
    
    constructor(sendableT: SendableClassT<number>) {
      const sendableList: SendableClass[] = [new NonSendableClass()]; // ArkTS compile-time error
      this.propB = new NonSendableClassT<number>(); // ArkTS compile-time error
      this.propC = this.getSendable(); 
      this.propD = sendableList[0]; 
      this.propE = sendableT;
    }

    getSendable(): SendableClass {
        return new NonSendableClass(); // ArkTS compile-time error
    }
}

new SendableData(new NonSendableClassT<number>()); // ArkTS compile-time error

const sendable: SendableClassT<number> = new NonSendableClassT<number>(); // ArkTS compile-time error
const sendableArray: collections.Array<SendableClass> = new collections.Array<SendableClass>();
sendableArray.push(sendable);

```

场景二：错误对象被当作普通对象使用时，影响：产生不兼容变更新增报错

变更前

```ts
class NonSendableClass {};
@Sendable
class SendableClass {};

class NonSendableClassT<T> {};
@Sendable
class SendableClassT<T> {};

function getSendable(): SendableClass {
    return new NonSendableClass();
}

const objectA: SendableClass = getSendable();
const objectB: SendableClassT<number> = new NonSendableClassT<number>();

```

变更后

```ts
class NonSendableClass {};
@Sendable
class SendableClass {};

class NonSendableClassT<T> {};
@Sendable
class SendableClassT<T> {};

function getSendable(): SendableClass {
    return new NonSendableClass(); // ArkTS compile-time error
}

const objectA: SendableClass = getSendable();
const objectB: SendableClassT<number> = new NonSendableClassT<number>(); // ArkTS compile-time error

```

**起始 API Level**

ArkTS Sendable语法检查从API 12起启用。

**变更发生版本**

从OpenHarmony SDK 5.0.0.31 开始。

**变更的接口/组件**

不涉及。

**适配指导**

避免把Non-sendable对象赋值给Sendable变量/参数/返回值。