# ForEach

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

开发者指南见：[ForEach开发者指南](../../../quick-start/arkts-rendering-control-foreach.md)

ForEach接口基于数组类型数据来进行循环渲染，需要与容器组件配合使用，且接口返回的组件应当是允许包含在ForEach父容器组件中的子组件。例如，ListItem组件要求ForEach的父容器组件必须为[List组件](../../../reference/apis-arkui/arkui-ts/ts-container-list.md)。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名        | 类型                                    | 必填 | 说明                                                         |
| ------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| arr           | Array\<Object\>                         | 是   | 数据源，为`Array`类型的数组。<br/>**说明：**<br/>- 可以设置为空数组，此时不会创建子组件。<br/>- 可以设置返回值为数组类型的函数，例如`arr.slice(1, 3)`，但设置的函数不应改变包括数组本身在内的任何状态变量，例如不应使用`Array.splice()`,`Array.sort()`或`Array.reverse()`这些会改变原数组的函数。 |
| itemGenerator | (item: Object, index: number) => void   | 是   | 组件生成函数。<br/>- 为数组中的每个元素创建对应的组件。<br/>- `item`参数：`arr`数组中的数据项。<br/>- `index`参数（可选）：`arr`数组中的数据项索引。<br/>**说明：**<br/>- 组件的类型必须是`ForEach`的父容器所允许的。例如，`ListItem`组件要求`ForEach`的父容器组件必须为`List`组件。 |
| keyGenerator  | (item: Object, index: number) => string | 否   | 键值生成函数。<br/>- 为数据源`arr`的每个数组项生成唯一且持久的键值。函数返回值为开发者自定义的键值生成规则。<br/>- `item`参数：`arr`数组中的数据项。<br/>- `index`参数（可选）：`arr`数组中的数据项索引。<br/>**说明：**<br/>- 如果函数缺省，框架默认的键值生成函数为`(item: T, index: number) => { return index + '__' + JSON.stringify(item); }`<br/>- 键值生成函数不应改变任何组件状态。 |

> **说明：**
>
> - `ForEach`的`itemGenerator`函数可以包含`if/else`条件渲染逻辑。另外，也可以在`if/else`条件渲染语句中使用`ForEach`组件。
> - 在初始化渲染时，`ForEach`会加载数据源的所有数据，并为每个数据项创建对应的组件，然后将其挂载到渲染树上。如果数据源非常大或有特定的性能需求，建议使用`LazyForEach`组件。

**示例：**
```ts
// arr是string类型的数组
// 第一个参数是组件创建函数
// 第二个参数是键值生成函数
ForEach(this.arr, (item: string, index: number) => {Text(item)}, (item: string, index: number) => item + index)
```

## onMove<sup>12+</sup>

onMove(handler: Optional<(from: index, to: index) => void>): T

拖拽排序数据移动回调。只有在List组件中使用，并且ForEach每次迭代都生成一个ListItem组件时才生效拖拽排序。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型      | 必填 | 说明       |
| ------ | --------- | ---- | ---------- |
| from  | number | 是   | 数据源移动起始索引号。 |
| to  | number | 是   | 数据源移动目标索引号。 |
