# Repeat

Repeat组件不开启virtualScroll开关时，Repeat基于数组类型数据来进行循环渲染，需要与容器组件配合使用，且接口返回的组件应当是允许包含在Repeat父容器组件中的子组件。Repeat循环渲染和ForEach相比有两个区别，一是优化了部分更新场景下的渲染性能，二是组件生成函数的索引index由框架侧来维护。

Repeat组件开启virtualScroll开关时，Repeat将从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。当在滚动容器中使用了Repeat，框架会根据滚动容器可视区域按需创建组件，当组件滑出可视区域外时，框架会缓存组件，并在下一次迭代中使用。

>**说明：**
>
>Repeat从API version 12开始支持。
>
>当前状态管理（V2试用版）仍在逐步开发中，相关功能尚未成熟，建议开发者尝鲜试用。
>
>**注意：**
>
>Repeat组件不完全兼容V1装饰器，使用V1装饰器存在渲染异常，不建议开发者使用。

## 接口描述

### Repeat组件构造

```ts
declare const Repeat: <T>(arr: Array<T>) => RepeatAttribute<T>
```

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 参数类型   | 是否必填 | 参数描述                                               |
| ------ | ---------- | -------- | ------------------------------------------------------ |
| arr    | Array\<T\> | 是       | 数据源，为`Array<T>`类型的数组，由开发者决定数据类型。 |

### Repeat组件属性

```ts
declare class RepeatAttribute<T> {
  each(itemGenerator: (repeatItem: RepeatItem<T>) => void): RepeatAttribute<T>;
  key(keyGenerator: (item: T, index: number) => string): RepeatAttribute<T>;
  virtualScroll(virtualScrollOptions?: VirtualScrollOptions): RepeatAttribute<T>;
  template(type: string, itemBuilder: RepeatItemBuilder<T>, templateOptions?: TemplateOptions): RepeatAttribute<T>;
  templateId(typedFunc: TemplateTypedFunc<T>): RepeatAttribute<T>;
}
```

参数说明：

| 属性名        | 参数类型                                                     | 参数描述                                                     |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| each          | itemGenerator: (repeatItem: RepeatItem\<T\>) => void         | 组件生成函数。<br/>**说明：**<br/>- `each`属性必须有，否则运行时会报错。<br/>- `itemGenerator`的参数为`RepeatItem`，该参数将`item`和`index`结合到了一起，请勿将`RepeatItem`参数拆开使用。 |
| key           | keyGenerator: (item: T, index: number) => string             | 键值生成函数。<br/>- 为数组中的每个元素创建对应的键值。<br/>- `item`：`arr`数组中的数据项。<br/>- `index`：`arr`数组中的数据项索引。 |
| virtualScroll | virtualScrollOptions?: VirtualScrollOptions                  | `Repeat`开启虚拟滚动。<br/>-`virtualScrollOptions`：虚拟滚动配置项。 |
| template      | type: string, itemBuilder: RepeatItemBuilder\<T\>, templateOptions?: TemplateOptions | 复用模板。<br/>未开启virtualScroll时暂不支持，复用有问题。<br/>-`type`：当前模板类型。<br/>-`itemBuilder`：组件生成函数。<br/>-`templateOptions`：当前模板配置项。 |
| templateId    | typedFunc: TemplateTypedFunc\<T\>                              | 为当前数据项分配模板类型。<br/>-`typedFunc`：生成当前数据项对应的模板类型。<br/>template和templateId匹配不上的数据项走默认生成函数each。 |

### RepeatItem类型

```ts
interface RepeatItem<T> {
  item: T,
  index: number
}
```

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

属性说明：

| 属性名 | 类型   | 是否必填 | 描述                                         |
| ------ | ------ | -------- | -------------------------------------------- |
| item   | T      | 是       | arr中每一个数据项。T为开发者传入的数据类型。 |
| index  | number | 是       | 当前数据项对应的索引。                       |

### VirtualScrollOptions类型

```
interface VirtualScrollOptions {
  totalCount?: number;
}
```

属性说明：

| 属性名     | 类型   | 是否必填 | 描述                                                         |
| ---------- | ------ | -------- | ------------------------------------------------------------ |
| totalCount | number | 否       | 定义数据源长度为arrLength，以下为totalCount的判断规则：<br/>1) totalCount不设置 \|\| totalCount不是整数 \|\| totalCount <= 0 \|\| totalCount == arrLength时，totalCount为数据源长度，列表正常滚动<br/>2) 0 < totalCount < arrLength时，界面中数据源被截断，只渲染“totalCount”个数据<br/>3) totalCount > arrLength时，滚动条样式正常，无数据项的位置显示空白，当滚动动画停止时，滚动条停留在最后一个数据项的位置。这样用户可以不同步请求所有数据，也能实现正确的滚动条样式。 |

### RepeatItemBuilder类型

```
declare type RepeatItemBuilder<T> = (repeatItem: RepeatItem<T>) => void;
```

参数说明：

| 参数名     | 类型          | 是否必填      | 描述                                    |
| ---------- | ------------- | --------------------------------------- | --------------------------------------- |
| repeatItem | RepeatItem\<T\> | 是 | 将item和index结合到一起的一个状态变量。 |

### TemplateOptions类型

```
interface TemplateOptions {
  cachedCount?: number
}
```

属性说明：

| 属性名      | 类型   | 是否必填 | 描述                                                         |
| ----------- | ------ | -------- | ------------------------------------------------------------ |
| cachedCount | number | 否       | 当前模板在Repeat的缓存池中可缓存子节点的最大数量，默认值为1，仅在开启virtualScroll后生效。<br/>将cachedCount设置为当前模板的节点在屏上可能出现的最大数量时，Repeat可以做到尽可能多的复用。但后果是当屏上没有当前模板的节点时，缓存池也不会释放，应用内存会增大。需要开发者依据具体情况自行把控。<br/>each方法的cachedCount默认为1，目前不能修改。 |

### TemplateTypedFunc类型

```
declare type TemplateTypedFunc<T> = (item : T, index : number) => string;
```

参数说明：

| 参数名 | 类型   | 是否必填 | 描述                                         |
| ------ | ------ | -------- | -------------------------------------------- |
| item   | T      | 是       | arr中每一个数据项。T为开发者传入的数据类型。 |
| index  | number | 是       | 当前数据项对应的索引。                       |