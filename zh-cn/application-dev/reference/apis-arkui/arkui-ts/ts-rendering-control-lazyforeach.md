# LazyForEach

LazyForEach从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。当在滚动容器中使用了LazyForEach，框架会根据滚动容器可视区域按需创建组件，当组件滑出可视区域外时，框架会进行组件销毁回收以降低内存占用。

> **说明**
>
> LazyForEach必须在容器组件内使用，仅有List、Grid、Swiper以及WaterFlow组件支持数据懒加载（可配置cachedCount属性，即只加载可视部分以及其前后少量数据用于缓冲），其他组件仍然是一次性加载所有的数据。

## 接口描述


```ts
LazyForEach(
    dataSource: IDataSource,             // 需要进行数据迭代的数据源
    itemGenerator: (item: Object, index: number) => void,  // 子组件生成函数
    keyGenerator?: (item: Object, index: number) => string // 键值生成函数
): void
```

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名        | 参数类型                                               | 必填 | 参数描述                                                     |
| ------------- | ------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataSource    | [IDataSource](#idatasource类型说明)                    | 是   | LazyForEach数据源，需要开发者实现相关接口。                  |
| itemGenerator | (item:&nbsp;Object， index:number)&nbsp;=&gt;&nbsp;void  | 是   | 子组件生成函数，为数组中的每一个数据项创建一个子组件。<br/>**说明：**<br/>item是当前数据项，index是数据项索引值。<br/>itemGenerator的函数体必须使用大括号{...}。itemGenerator每次迭代只能并且必须生成一个子组件。itemGenerator中可以使用if语句，但是必须保证if语句每个分支都会创建一个相同类型的子组件。itemGenerator中不允许使用ForEach和LazyForEach语句。 |
| keyGenerator  | (item:&nbsp;Object, index:number)&nbsp;=&gt;&nbsp;string | 否   | 键值生成函数，用于给数据源中的每一个数据项生成唯一且固定的键值。当数据项在数组中的位置更改时，其键值不得更改，当数组中的数据项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的，但是，为了使开发框架能够更好地识别数组更改，提高性能，建议提供。如将数组反向时，如果没有提供键值生成器，则LazyForEach中的所有节点都将重建。<br/>**说明：**<br/>item是当前数据项，index是数据项索引值。<br/>数据源中的每一个数据项生成的键值不能重复。 |

## 事件

### onMove

onMove(handler: Optional<(from: index, to: index) => void>)

拖拽排序数据移动回调。只有在List组件中使用，并且LazyForEach每次迭代都生成一个ListItem组件时才生效拖拽排序。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型      | 必填 | 说明       |
| ------ | --------- | ---- | ---------- |
| from  | number | 是   | 数据源移动起始索引号。 |
| to  | number | 是   | 数据源移动目标索引号。 |

## IDataSource类型说明

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

```ts
interface IDataSource {
    totalCount(): number; // 获得数据总数
    getData(index: number): Object; // 获取索引值对应的数据
    registerDataChangeListener(listener: DataChangeListener): void; // 注册数据改变的监听器
    unregisterDataChangeListener(listener: DataChangeListener): void; // 注销数据改变的监听器
}
```

| 接口声明                                                     | 参数类型                                          | 说明                                                        |
| ------------------------------------------------------------ | ------------------------------------------------- | ----------------------------------------------------------- |
| totalCount():&nbsp;number                                    | -                                                 | 获得数据总数。                                              |
| getData(index:&nbsp;number):&nbsp;Object                        | number                                            | 获取索引值index对应的数据。<br/>index：获取数据对应的索引值。 |
| registerDataChangeListener(listener:[DataChangeListener](#datachangelistener类型说明)):&nbsp;void | [DataChangeListener](#datachangelistener类型说明) | 注册数据改变的监听器。<br/>listener：数据变化监听器         |
| unregisterDataChangeListener(listener:[DataChangeListener](#datachangelistener类型说明)):&nbsp;void | [DataChangeListener](#datachangelistener类型说明) | 注销数据改变的监听器。<br/>listener：数据变化监听器         |

## DataChangeListener类型说明

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

```ts
interface DataChangeListener {
    onDataReloaded(): void; // 重新加载数据完成后调用
    onDataAdded(index: number): void; // 添加数据完成后调用
    onDataMoved(from: number, to: number): void; // 数据移动起始位置与数据移动目标位置交换完成后调用
    onDataDeleted(index: number): void; // 删除数据完成后调用
    onDataChanged(index: number): void; // 改变数据完成后调用
    onDataAdd(index: number): void; // 添加数据完成后调用
    onDataMove(from: number, to: number): void; // 数据移动起始位置与数据移动目标位置交换完成后调用
    onDataDelete(index: number): void; // 删除数据完成后调用
    onDataChange(index: number): void; // 改变数据完成后调用
    onDatasetChange(dataOperations: DataOperation[]): void; // 批量数据处理后调用
}
```

| 接口声明                                                     | 参数类型                               | 说明                                                         |
| ------------------------------------------------------------ | -------------------------------------- | ------------------------------------------------------------ |
| onDataReloaded():&nbsp;void                                  | -                                      | 通知组件重新加载所有数据。<br/>键值没有变化的数据项会使用原先的子组件，键值发生变化的会重建子组件。 |
| onDataAdd(index:&nbsp;number):&nbsp;void<sup>8+</sup>        | number                                 | 通知组件index的位置有数据添加。<br/>index：数据添加位置的索引值。 |
| onDataMove(from:&nbsp;number,&nbsp;to:&nbsp;number):&nbsp;void<sup>8+</sup> | from:&nbsp;number,<br/>to:&nbsp;number | 通知组件数据有移动。<br/>from:&nbsp;数据移动起始位置，to:&nbsp;数据移动目标位置。<br/>将from和to位置的数据进行交换。<br/>**说明：**<br/>数据移动前后键值要保持不变，如果键值有变化，应使用删除数据和新增数据接口。 |
| onDataDelete(index: number):void<sup>8+</sup>                | number                                 | 通知组件删除index位置的数据并刷新LazyForEach的展示内容。<br/>index：数据删除位置的索引值。<br/>**说明：** <br/>需要保证dataSource中的对应数据已经在调用onDataDelete前删除，否则页面渲染将出现未定义的行为。 |
| onDataChange(index:&nbsp;number):&nbsp;void<sup>8+</sup>     | number                                 | 通知组件index的位置有数据有变化。<br/>index：数据变化位置的索引值。 |
| onDataAdded(index:&nbsp;number):void<sup>(deprecated)</sup>  | number                                 | 通知组件index的位置有数据添加。<br/>从API 8开始，建议使用onDataAdd。<br/>index：数据添加位置的索引值。 |
| onDataMoved(from:&nbsp;number,&nbsp;to:&nbsp;number):&nbsp;void<sup>(deprecated)</sup> | from:&nbsp;number,<br/>to:&nbsp;number | 通知组件数据有移动。<br/>从API 8开始，建议使用onDataMove。<br/>from:&nbsp;数据移动起始位置，to:&nbsp;数据移动目标位置。<br/>将from和to位置的数据进行交换。<br/>**说明：**<br/>数据移动前后键值要保持不变，如果键值有变化，应使用删除数据和新增数据接口。 |
| onDataDeleted(index: number):void<sup>(deprecated)</sup>     | number                                 | 通知组件删除index位置的数据并刷新LazyForEach的展示内容。<br/>从API 8开始，建议使用onDataDelete。<br/>index：数据删除位置的索引值。 |
| onDataChanged(index:&nbsp;number):&nbsp;void<sup>(deprecated)</sup> | number                                 | 通知组件index的位置有数据有变化。<br/>从API 8开始，建议使用onDataChange。<br/>index：数据变化监听器。 |
| onDatasetChange(dataOperations: DataOperation[]): void<sup>12+</sup> | DataOperation[]                        | 进行批量的数据处理。<br/>该接口不可与上述接口混用。<br/>DataOperation：一次处理数据的操作。 |

## DataOperation类型说明

```ts
type DataOperation =
  	DataAddOperation |          // 添加数据操作
	DataDeleteOperation |       // 删除数据操作
	DataChangeOperation |       // 改变数据操作
	DataMoveOperation |         // 移动数据操作
	DataExchangeOperation |     // 交换数据操作
	DataReloadOperation         // 重载所有数据操作
```

### DataAddOperation

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

```ts
interface DataAddOperation {
  type: DataOperationType.ADD,     // 数据添加类型
  index: number,                   // 插入数据索引值
  count?: number,                  // 插入数量，默认值为1
  key?: string | Array<string>     // 为插入的数据分配键值
}
```

### DataDeleteOperation

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

```ts
interface DataDeleteOperation {
  type: DataOperationType.DELETE,  // 数据删除类型
  index: number,                   // 起始删除位置索引值
  count?: number                   // 删除数据数量，默认值为1
}
```

### DataChangeOperation

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

```ts
interface DataChangeOperation {
  type: DataOperationType.CHANGE,  // 数据改变类型
  index: number,                   // 改变的数据的索引值
  key?: string                     // 为改变的数据分配新的键值，默认使用原键值
}
```

### DataMoveOperation

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

```ts
interface MoveIndex {
  from: number;                    // 起始移动位置
  to: number;                      // 目的移动位置
}

interface DataMoveOperation {
  type: DataOperationType.MOVE,    // 数据移动类型
  index: MoveIndex,
  key?: string                     // 为被移动的数据分配新的键值，默认使用原键值
}
```

### DataExchangeOperation

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

```ts
interface ExchangeIndex {
  start: number;                   // 第一个交换位置
  end: number;                     // 第二个交换位置
}
interface ExchangeKey {
  start: string;                   // 为第一个交换的位置分配新的键值，默认使用原键值
  end: string;                     // 为第二个交换的位置分配新的键值，默认使用原键值
}

interface DataExchangeOperation {
  type: DataOperationType.EXCHANGE,  // 数据交换类型
  index: ExchangeIndex,
  key?: ExchangeKey
}
```

### DataReloadOperation

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

```ts
interface DataReloadOperation {     // 当onDatasetChange含有DataOperationType.RELOAD操作时，其余操作全部失效，框架会自己调用keygenerator进行键值比对
  type: DataOperationType.RELOAD    // 数据全部重载类型
}
```

### DataOperationType

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

```ts
declare enum DataOperationType {
  ADD = 'add',                      // 数据添加
  DELETE = 'delete',                // 数据删除
  CHANGE = 'change',                // 数据改变
  MOVE = 'move',                    // 数据移动
  EXCHANGE = 'exchange',            // 数据交换
  RELOAD = 'reload'                 // 全部数据重载
}
```