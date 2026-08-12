# @arkts.lang (ArkTS语言基础能力)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @huanghello-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

本模块提供ArkTS语言的基础类型定义，支持跨线程传递数据结构、注解保留策略控制等功能。当前提供ISendable类型、RetentionPolicy枚举类型和Retention注解。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块仅支持在ArkTS文件（文件后缀为.ets）中导入使用。

## 导入模块

```ts
import { lang, Retention, RetentionPolicy } from '@kit.ArkTS';
```

## lang.ISendable
是所有[Sendable](../../arkts-utils/arkts-sendable.md#基础概念)对象类型（除`null`和`undefined`）的父类型。实现该接口后，自定义类的实例将支持跨线程传递。自身不定义任何方法和属性。

ArkTS中，ISendable类型的对象是Object类型的实例，遵循Object类型的基本特征，同时支持跨线程传递。

ISendable主要用在开发者自定义Sendable数据结构的场景中。ArkTS语言标准库中的Sendable容器类型（如[Array](arkts-apis-arkts-collections-Array.md)、[Map](arkts-apis-arkts-collections-Map.md)、[Set](arkts-apis-arkts-collections-Set.md)等）隐式地继承并实现了ISendable。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Utils.Lang

**示例：**

```ts
// 使用@Sendable装饰器声明可跨线程传递的类
@Sendable
// 实现lang.ISendable接口，定义自定义Sendable数据结构
class CustomData implements lang.ISendable {
    id: number;
    name: string;
    constructor(id: number, name: string) {
        this.id = id;
        this.name = name;
    }
}
```

## RetentionPolicy<sup>24+</sup>
描述[注解](../../quick-start/arkts-language-guide-annotations.md#注解的基础概念)类型保留策略的枚举类型。其枚举值和[Retention](#retention24)结合使用，以指定注解的生命周期。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Utils.Lang

| 名称      | 值        | 说明          |
| --------- | --------- | ------------- |
| SOURCE    | "source"   | 注解将在编译期被移除。 |
| BYTECODE  | "bytecode" | 注解将保留到编译产物中。 |

## Retention<sup>24+</sup>
系统提供的API注解能力，可用于指定自定义注解的生命周期。此注解只能标注在其他注解声明上。在自定义注解上标注Retention注解后，根据policy的不同取值，编译器会对自定义注解执行不同的保留策略。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明       |
| ---- | ------ | ---- | ---- | ---------- |
| policy | [RetentionPolicy](#retentionpolicy24) | 否 | 否 | 注解的保留策略。 |

**示例：**

```ts
import { Retention, RetentionPolicy } from '@kit.ArkTS';

// 构造一个用户自定义的源码态注解
@Retention({policy: RetentionPolicy.SOURCE})
@interface sourceAnnotation {
    prop1: number
    prop2: number
}

// 构造一个用户自定义的字节码态注解
@Retention({policy: RetentionPolicy.BYTECODE})
@interface bytecodeAnnotation {
    prop1: number
    prop2: number
}
```