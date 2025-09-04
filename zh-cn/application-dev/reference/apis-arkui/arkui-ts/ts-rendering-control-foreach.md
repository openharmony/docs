# ForEach
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @maorh-->
<!--Designer: @keerecles-->
<!--Tester: @TerryTsao-->
<!--Adviser: @HelloCrease-->

ForEach接口基于数组类型数据来进行循环渲染。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

开发者指南见：[ForEach开发者指南](../../../ui/state-management/arkts-rendering-control-foreach.md)。

## 接口

ForEach(arr: Array\<any\>, itemGenerator: (item: any, index: number) => void, keyGenerator?: (item: any, index: number) => string)

ForEach接口基于数组类型数据来进行循环渲染，需要与容器组件配合使用，且接口返回的组件应当是允许包含在ForEach父容器组件中的子组件。例如，ListItem组件要求ForEach的父容器组件必须为[List组件](../../../reference/apis-arkui/arkui-ts/ts-container-list.md)。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名        | 类型                                    | 必填 | 说明                                                         |
| ------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| arr           | Array\<any\>                         | 是   | 数据源，为`Array`类型的数组。<br/>**说明：**<br/>- 可以设置为空数组，此时不会创建子组件。<br/>- 可以设置返回值为数组类型的函数，例如`arr.slice(1, 3)`，但设置的函数不应改变包括数组本身在内的任何状态变量，例如不应使用`Array.splice()`,`Array.sort()`或`Array.reverse()`这些会改变原数组的函数。 |
| itemGenerator | (item: any, index: number) => void   | 是   | 组件生成函数。<br/>- 为数组中的每个元素创建对应的组件。<br/>- `item`参数（可选）：`arr`数组中的数据项。<br/>- `index`参数（可选）：`arr`数组中的数据项索引。<br/>**说明：**<br/>- 组件的类型必须是`ForEach`的父容器所允许的。例如，`ListItem`组件要求`ForEach`的父容器组件必须为`List`组件。 |
| keyGenerator  | (item: any, index: number) => string | 否   | 键值生成函数。<br/>- 为数据源`arr`的每个数组项生成唯一且持久的键值。函数返回值为开发者自定义的键值生成规则。<br/>- `item`参数（可选）：`arr`数组中的数据项。<br/>- `index`参数（可选）：`arr`数组中的数据项索引。<br/>**说明：**<br/>- 如果函数缺省，框架默认的键值生成函数为`(item: T, index: number) => { return index + '__' + JSON.stringify(item); }`<br/>- 键值生成函数不应改变任何组件状态。 |

> **说明：**
>
> - `ForEach`的`itemGenerator`函数可以包含`if/else`条件渲染逻辑。另外，也可以在`if/else`条件渲染语句中使用`ForEach`组件。
> - 在初始化渲染时，`ForEach`会加载数据源的所有数据，并为每个数据项创建对应的组件，然后将其挂载到渲染树上。如果数据源非常大或有特定的性能需求，建议使用`LazyForEach`组件。最佳实践请参考[使用懒加载优化性能](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-lazyforeach-optimization)。

由于数据源的数据项类型为`any`，缺少类型一致性校验，建议在使用`ForEach`时保持类型声明一致（详见如下代码片段），不规范写法可能会导致子组件无法正常渲染。

```ts
// 不规范写法
arr: Array<Type1 | Type2> = [];

ForEach(this.arr, (item: Type1) => {...}, (item: Type2) => item.toString()) // item类型和数据项类型不一致

// 正确写法
arr: Array<Type1 | Type2> = [];

ForEach(this.arr, (item: Type1 | Type2) => {...}, (item: Type1 | Type2) => item.toString()) // item类型和数据项类型保持一致
```