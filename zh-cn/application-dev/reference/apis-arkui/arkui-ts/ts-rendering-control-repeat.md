# Repeat

> **说明：**
> 
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

本文档仅为API参数说明。开发者指南见：[Repeat开发者指南](../../../quick-start/arkts-new-rendering-control-repeat.md)。

## 接口

### Repeat: \<T\>(arr: Array\<T\>)

Repeat组件non-virtualScroll场景（不开启virtualScroll开关）中，Repeat基于数据源进行循环渲染，需要与容器组件配合使用，且接口返回的组件应当是允许包含在Repeat父容器组件中的子组件。Repeat循环渲染和ForEach相比有两个区别，一是优化了部分更新场景下的渲染性能，二是组件生成函数的索引index由框架侧来维护。

Repeat组件virtualScroll场景中，Repeat将从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件，必须与滚动类容器组件配合使用。当在滚动类容器组件中使用了Repeat，框架会根据滚动容器可视区域按需创建组件，当组件滑出可视区域外时，框架会缓存组件，并在下一次迭代中使用。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型       | 必填 | 说明      |
| ------ | ---------- | -------- | -------- |
| arr    | Array\<T\> | 是 | 数据源，为`Array<T>`类型的数组，由开发者决定数据类型。 |

**示例：**
```ts
// arr是Array<string>类型的数组，以arr为数据源创建Repeat组件
Repeat<string>(this.arr)
```

### Repeat: \<T\>(arr: RepeatArray\<T\>)<sup>18+</sup>

> **说明：**
>
> 从API version 18开始，Repeat数据源参数支持RepeatArray类型。

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型       | 必填 | 说明      |
| ------ | ---------- | -------- | -------- |
| arr    | [RepeatArray\<T\>](#repeatarrayt18) | 是 | 数据源，为`RepeatArray<T>`类型的数组，由开发者决定数据类型。 |

## 事件

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### each

each(itemGenerator: (repeatItem: RepeatItem\<T\>) => void): RepeatAttribute\<T\>

组件生成函数。template和templateId匹配不上的数据项走默认生成函数each。

> **说明**
>
> `each`属性必须有，否则运行时会报错。
> `itemGenerator`的参数为`RepeatItem`，该参数将`item`和`index`结合到了一起，请勿将`RepeatItem`参数拆开使用。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明 |
| ------ | ---------- | -------- | -------- |
| repeatItem  | [RepeatItem](#repeatitemt)\<T\> | 是 | repeat数据项。 |

**示例：**
```ts
// arr是Array<string>类型的数组，为每个数据创建一个Text组件
Repeat<string>(this.arr)
  .each((obj: RepeatItem<string>) => { Text(obj.item) })
```

### key

key(keyGenerator: (item: T, index: number) => string): RepeatAttribute\<T\>

键值生成函数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明  |
| ------ | ---------- | -------- | -------- |
| item  | T | 是 | `arr`数组中的数据项。 |
| index  | number | 是 | `arr`数组中的数据项索引。 |

**示例：**
```ts
// arr是Array<string>类型的数组，为每个数据创建一个Text组件
// 并将字符串的值作为其键值
Repeat<string>(this.arr)
  .each((obj: RepeatItem<string>) => { Text(obj.item) })
  .key((obj: string) => obj)
```

### virtualScroll

virtualScroll(virtualScrollOptions?: VirtualScrollOptions): RepeatAttribute\<T\>

`Repeat`开启虚拟滚动。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明  |
| ------ | ---------- | -------- | -------- |
| virtualScrollOptions  | [VirtualScrollOptions](#virtualscrolloptions对象说明)  | 否 | 虚拟滚动配置项。 |

**示例：**
```ts
// arr是Array<string>类型的数组，为每个数据创建一个Text组件
// 在List容器组件中使用Repeat，并打开virtualScroll
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }})
    .virtualScroll()
}
```

### template

template(type: string, itemBuilder: RepeatItemBuilder\<T\>, templateOptions?: TemplateOptions): RepeatAttribute\<T\>

复用模板。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明  |
| ------ | ---------- | -------- | -------- |
| type | string | 是 | 当前模板类型。 |
| itemBuilder  | [RepeatItemBuilder](#repeatitembuildert)\<T\> | 是 | 组件生成函数。 |
| templateOptions | [TemplateOptions](#templateoptions对象说明) | 否 | 当前模板配置项。 |

**示例：**
```ts
// arr是Array<string>类型的数组
// 在List容器组件中使用Repeat，并打开virtualScroll
// 创建模板temp，该模板为数据创建Text组件
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => {})
    .virtualScroll()
    .template('temp', (obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }})
}
```

### templateId

templateId(typedFunc: TemplateTypedFunc\<T\>): RepeatAttribute\<T\>

为当前数据项分配templateId。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明  |
| ------ | ---------- | -------- | -------- |
| typedFunc | [TemplateTypedFunc](#templatetypedfunct)\<T\> | 是 | 生成当前数据项对应的templateId。 |

**示例：**
```ts
// arr是Array<string>类型的数组
// 在List容器组件中使用Repeat，并打开virtualScroll
// 创建模板temp，该模板为数据创建Text组件
// 所有数据项都使用temp模板
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => {})
    .virtualScroll()
    .template('temp', (obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }})
    .templateId((item: string, index: number) => { return 'temp' })
}
```

## 属性

从API version 18开始，继承自[DynamicNode](./ts-rendering-control-foreach.md#dynamicnode12)。

## RepeatArray\<T\><sup>18+</sup>

type RepeatArray\<T\> = Array\<T\> | ReadonlyArray\<T\> | Readonly\<Array\<T\>\>

Repeat数据源参数联合类型。

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

|  类型       | 说明      |
| -------- | -------- |
| Array\<T\> | 常规数组类型。 |
| ReadonlyArray\<T\> | 只读数组类型，不允许数组对象变更。 |
| Readonly\<Array\<T\>> | 只读数组类型，不允许数组对象变更。 |

## RepeatItem\<T\>

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型   | 必填 | 说明                                         |
| ------ | ------ | ---- | -------------------------------------------- |
| item   | T      | 是   | arr中每一个数据项。T为开发者传入的数据类型。 |
| index  | number | 是   | 当前数据项对应的索引。                       |

## VirtualScrollOptions对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型   | 必填 | 说明                                                         |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| totalCount | number | 否   | 加载的数据项总数，可以不等于数据源长度。 |
| reusable<sup>18+</sup> | boolean | 否   | 是否开启复用功能，true表示开启，false表示不开启，默认开启。 |
| onLazyLoading<sup>18+</sup> | (index: number) => void | 否   | 数据懒加载函数，向指定的数据源index中写入数据。 |
| onTotalCount<sup>18+</sup> | () => number | 否   | 数据项总数计算函数，返回值可以不等于数据源长度。推荐使用onTotalCount代替totalCount。同时设置totalCount与onTotalCount时，忽略totalCount。 |

**示例：**
```ts
// arr是Array<string>类型的数组，在List容器组件中使用Repeat，并打开virtualScroll
// 将加载的数据项总数设为数据源的长度，并开启复用功能
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }})
    .virtualScroll( { totalCount: this.arr.length, reusable: true } )
}

// 假设数据项总数为100，首屏渲染需3项数据
// 初始数组提供前3项数据（arr = ['No.0', 'No.1', 'No.2']），并开启数据懒加载功能
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }})
    .virtualScroll( { 
      onTotalCount: () => { return 100; },
      onLazyLoading: (index: number) => { this.arr[index] = `No.${index}`; }
      } )
}
```

## RepeatItemBuilder\<T\>

type RepeatItemBuilder\<T\> = (repeatItem: RepeatItem\<T\>) => void

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型          | 必填      | 说明                                    |
| ---------- | ------------- | --------------------------------------- | --------------------------------------- |
| repeatItem | [RepeatItem](#repeatitemt)\<T\> | 是 | 将item和index结合到一起的一个状态变量。 |

## TemplateOptions对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型   | 必填 | 说明                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| cachedCount | number | 否   | 当前模板在Repeat的缓存池中可缓存子节点的最大数量，仅在开启virtualScroll后生效。 |

**示例：**
```ts
// arr是Array<string>类型的数组，在List容器组件中使用Repeat，并打开virtualScroll
// 创建模板temp，该模板为数据创建Text组件，所有数据项都使用temp模板
// 将temp模板的最大缓存节点数量设为2
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => {})
    .virtualScroll()
    .template('temp', (obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }}, { cachedCount: 2 })
    .templateId((item: string, index: number) => { return 'temp' })
}
```

## TemplateTypedFunc\<T\>

type TemplateTypedFunc\<T\> = (item : T, index : number) => string

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                         |
| ------ | ------ | ---- | -------------------------------------------- |
| item   | T      | 是   | arr中每一个数据项。T为开发者传入的数据类型。 |
| index  | number | 是   | 当前数据项对应的索引。                       |