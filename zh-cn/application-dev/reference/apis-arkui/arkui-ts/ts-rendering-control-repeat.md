# Repeat

>**说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

开发者指南见：[Repeat开发者指南](../../../quick-start/arkts-new-rendering-control-repeat.md)

Repeat组件non-virtualScroll场景（不开启virtualScroll开关）中，Repeat基于数据源进行循环渲染，需要与容器组件配合使用，且接口返回的组件应当是允许包含在Repeat父容器组件中的子组件。Repeat循环渲染和ForEach相比有两个区别，一是优化了部分更新场景下的渲染性能，二是组件生成函数的索引index由框架侧来维护。

Repeat组件virtualScroll场景中，Repeat将从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件，必须与滚动类容器组件配合使用。当在滚动类容器组件中使用了Repeat，框架会根据滚动容器可视区域按需创建组件，当组件滑出可视区域外时，框架会缓存组件，并在下一次迭代中使用。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型       | 必填 | 说明      |
| ------ | ---------- | -------- | -------- |
| arr    | Array\<T\> | 是 | 数据源，为`Array<T>`类型的数组，由开发者决定数据类型。 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
| [RepeatAttribute](#repeatattribute)\<T\> | Repeat组件属性 |

## RepeatAttribute

### each

each(itemGenerator: (repeatItem: RepeatItem\<T\>) => void): RepeatAttribute\<T\>

组件生成函数。template和templateId匹配不上的数据项走默认生成函数each。

**说明：**

- `each`属性必须有，否则运行时会报错。
- `itemGenerator`的参数为`RepeatItem`，该参数将`item`和`index`结合到了一起，请勿将`RepeatItem`参数拆开使用。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明 |
| ------ | ---------- | -------- | -------- |
| repeatItem  | [RepeatItem](#repeatitem)\<T\> | 是 | repeat数据项 |

### key

key(keyGenerator: (item: T, index: number) => string): RepeatAttribute\<T\>

键值生成函数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明  |
| ------ | ---------- | -------- | -------- |
| item  | T | 是 | `arr`数组中的数据项 |
| index  | number | 是 | `arr`数组中的数据项索引 |

### virtualScroll

virtualScroll(virtualScrollOptions?: VirtualScrollOptions): RepeatAttribute\<T\>

`Repeat`开启虚拟滚动。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明  |
| ------ | ---------- | -------- | -------- |
| virtualScrollOptions  | [VirtualScrollOptions](#virtualscrolloptions)  | 否 | 虚拟滚动配置项 |

### template

template(type: string, itemBuilder: RepeatItemBuilder\<T\>, templateOptions?: TemplateOptions): RepeatAttribute\<T\>

复用模板。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明  |
| ------ | ---------- | -------- | -------- |
| type | string | 是 | 当前模板类型 |
| itemBuilder  | [RepeatItemBuilder](#repeatitembuilder)\<T\> | 是 | 组件生成函数 |
| templateOptions | [TemplateOptions](#templateoptions) | 否 | 当前模板配置项 |

### templateId

templateId(typedFunc: TemplateTypedFunc\<T\>): RepeatAttribute\<T\>

为当前数据项分配templateId。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明  |
| ------ | ---------- | -------- | -------- |
| typedFunc | [TemplateTypedFunc](#templatetypedfunc)\<T\> | 是 | 生成当前数据项对应的templateId |

## RepeatItem

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                         |
| ------ | ------ | ---- | -------------------------------------------- |
| item   | T      | 是   | arr中每一个数据项。T为开发者传入的数据类型。 |
| index  | number | 是   | 当前数据项对应的索引。                       |

## VirtualScrollOptions

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型   | 必填 | 说明                                                         |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| totalCount | number | 否   | 数据源的总长度，可以大于已加载数据项的数量 |

## RepeatItemBuilder

type RepeatItemBuilder\<T\> = (repeatItem: RepeatItem\<T\>) => void

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型          | 必填      | 说明                                    |
| ---------- | ------------- | --------------------------------------- | --------------------------------------- |
| repeatItem | [RepeatItem](#repeatitem)\<T\> | 是 | 将item和index结合到一起的一个状态变量。 |

## TemplateOptions

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型   | 必填 | 说明                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| cachedCount | number | 否   | 当前模板在Repeat的缓存池中可缓存子节点的最大数量，仅在开启virtualScroll后生效。 |

## TemplateTypedFunc

type TemplateTypedFunc\<T\> = (item : T, index : number) => string

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                         |
| ------ | ------ | ---- | -------------------------------------------- |
| item   | T      | 是   | arr中每一个数据项。T为开发者传入的数据类型。 |
| index  | number | 是   | 当前数据项对应的索引。                       |