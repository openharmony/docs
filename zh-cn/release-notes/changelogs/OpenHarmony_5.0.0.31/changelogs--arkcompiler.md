# ArkCompiler子系统变更说明

## cl.arkcompiler.1 ArkTS Sendable语法规则编译检查完善

**访问级别**

其他

**变更原因**

Sendable对象需要遵循一些的约束，但是在Sendable泛型类和Non-sendable对象赋值给Sendable类型变量的部分语法中，编译器没有对应的检查，导致这些语法下的Sendable对象用在并发场景中运行异常但是没有无编译时错误。在本次版本更新中，我们修复了这些场景下Sendable约束的编译时检查，将运行时异常提前到编译时。旨在通过编译时错误，帮助开发者更早发现Sendable使用约束，减少运行时定位成本。

**变更影响**

当Sendable对象被用在多线程共享时，将运行时报错提前到编译期。当Sendable对象被当作普通对象使用时，运行时不报错但编译期新增的报错。变更前，Sendable对象的泛型内可以填写非Sendable对象。变更后，Sendable对象的泛型内不可以填写非Sendable对象。

下面的场景将会报错：

Sendable泛型类约束

场景一：当Sendable对象被用在多线程共享时，影响：运行时异常提前到编译时

变更前

```ts
import collections from '@arkts.collections';
class NoneSendableClass {
    one: string = '1';
}

@Sendable
class SendableClass {
    private arr: collections.Array<NoneSendableClass> = new collections.Array();
    constructor() {
        this.arr.push(new NoneSendableClass()); // Runtime ERROR
    }
}
let sendableclassObject: SendableClass = new SendableClass();
```

变更后

```ts
import collections from '@arkts.collections';
class NoneSendableClass {
    one: string = '1';
}

@Sendable
class SendableClass {
    private arr: collections.Array<NoneSendableClass> = new collections.Array(); // ArkTS compile-time error
    constructor() {
        this.arr.push(new NoneSendableClass()); 
    }
}
let sendableclassObject: SendableClass = new SendableClass();
```

场景二：Sendable对象被当作普通对象使用时，影响：产生不兼容变更新增报错

变更前

```ts
@Sendable
class SendableClassA<T> {
    one: string = '1';
}
class NoneSendableClassA<T> {
    one: string = '1';
}
let sendableObjectA: SendableClassA<NoneSendableClassA<number>> = new SAendableClassA();
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
let sendableObjectA: SendableClassA<NoneSendableClassA<number>> = new SAendableClassA(); // ArkTS compile-time error
```

**起始 API Level**

ArkTS Sendable语法检查语法检查从API 12起启用。

**变更发生版本**

从OpenHarmony SDK 5.0.0.31 开始。

**变更的接口/组件**

不涉及。

**适配指导**

建议声明阶段在Sendable对象的泛型内填写Sendable对象，以及避免把非Sendable对象赋值给Sendable对象。