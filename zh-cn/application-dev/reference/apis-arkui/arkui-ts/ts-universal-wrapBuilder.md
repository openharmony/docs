# wrapBuilder
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

`wrapBuilder`用于封装全局[@Builder](./ts-universal-builder-dynamic.md#builder)，可以将全局`@Builder`函数作为参数传递，实现按引用传递和动态调用，提升代码复用性。

开发指南见：[wrapBuilder：封装全局@Builder](../../../ui/state-management/arkts-wrapBuilder.md)。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 后续版本的新增接口，采用上角标单独标记接口的起始版本。

## wrapBuilder

wrapBuilder\<Args extends Object[]>(builder: (...args: Args) => void): WrappedBuilder\<Args>

`wrapBuilder`是一个模板函数，返回一个`WrappedBuilder`对象。模板参数`Args extends Object[]`是需要封装的`@Builder`函数的参数列表。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名         | 类型                                   | 必填 | 说明                                                         |
| -------------- | -------------------------------------- | ---- | ---- |
| builder        | (...args: Args) => void                | 是   | `@Builder`装饰的全局函数，传入后将被封装为`WrappedBuilder`对象。函数参数args为该`@Builder`函数所需的参数列表。 |

**返回值：**

| 类型                  | 说明                       |
| --------------------- | -------------------------- |
| [WrappedBuilder\<Args>](#wrappedbuilder) | `@Builder`函数的包装类对象，用于将全局`@Builder`函数及其参数封装为可按引用传递、支持动态调用的对象。 |

**示例：**

```ts
@Builder
function myBuilder(value: string, size: number) {
  Text(value)
    .fontSize(size)
}

// 使用wrapBuilder封装myBuilder
let builderVar: WrappedBuilder<[string, number]> = wrapBuilder(myBuilder);
```

## WrappedBuilder

`WrappedBuilder`是`@Builder`函数的包装类，用于封装全局`@Builder`函数及其参数，实现按引用传递和动态调用。模板参数`Args extends Object[]`应传入`@Builder`函数的参数类型列表。

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 类型                    | 只读 | 可选 | 说明      |
| ------- | ---------------------- | ---- | ---  | -------- |
| builder | (...args: Args) => void | 否  | 否   | `@Builder`装饰的全局函数。 |

### constructor

constructor(builder: (...args: Args) => void)

`WrappedBuilder`的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名    | 类型                                    | 必填 | 说明                                                              |
| --------- | --------------------------------------- | ---- | ----------------------------------------------------------------- |
| builder   | (...args: Args) => void               | 是 | `@Builder`装饰的全局函数，作为构造参数用于初始化`WrappedBuilder`实例。函数参数args为该`@Builder`函数所需的参数列表。 |

**示例：**

```ts
@Builder
function myBuilder(value: string, size: number) {
  Text(value)
    .fontSize(size)
}

// 使用WrappedBuilder封装myBuilder
let builderVar: WrappedBuilder<[string, number]> = new WrappedBuilder<[string, number]>(myBuilder);
```
