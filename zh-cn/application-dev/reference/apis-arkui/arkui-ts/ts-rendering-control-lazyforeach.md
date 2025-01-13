# LazyForEach

> **说明**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

开发者指南见：[LazyForEach开发者指南](../../../quick-start/arkts-rendering-control-lazyforeach.md)

LazyForEach从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。当在滚动容器中使用了LazyForEach，框架会根据滚动容器可视区域按需创建组件，当组件滑出可视区域外时，框架会进行组件销毁回收以降低内存占用。

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名        | 类型                                                      | 必填 | 说明                                                         |
| ------------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| dataSource    | [IDataSource](#idatasource10)                       | 是   | LazyForEach数据源，需要开发者实现相关接口。                  |
| itemGenerator | (item:&nbsp;Object, index: number)&nbsp;=&gt;&nbsp;void   | 是   | 子组件生成函数，为数组中的每一个数据项创建一个子组件。<br/>**说明：**<br/>- item是当前数据项，index是数据项索引值。<br/>- itemGenerator的函数体必须使用大括号{...}。<br />- itemGenerator每次迭代只能并且必须生成一个子组件。<br />- itemGenerator中可以使用if语句，但是必须保证if语句每个分支都会创建一个相同类型的子组件。<br />- itemGenerator中不允许使用ForEach和LazyForEach语句。 |
| keyGenerator  | (item:&nbsp;Object, index: number)&nbsp;=&gt;&nbsp;string | 否   | 键值生成函数，用于给数据源中的每一个数据项生成唯一且固定的键值。当数据项在数组中的位置更改时，其键值不得更改，当数组中的数据项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的，但是，为了使开发框架能够更好地识别数组更改，提高性能，建议提供。如将数组反向时，如果没有提供键值生成器，则LazyForEach中的所有节点都将重建。<br/>**说明：**<br/>- item是当前数据项，index是数据项索引值。<br/>- 数据源中的每一个数据项生成的键值不能重复。 |

## onMove<sup>12+</sup>

onMove(handler: Optional<(from: index, to: index) => void>): T

拖拽排序数据移动回调。只有在List组件中使用，并且LazyForEach每次迭代都生成一个ListItem组件时才生效拖拽排序。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型      | 必填 | 说明       |
| ------ | --------- | ---- | ---------- |
| from  | number | 是   | 数据源移动起始索引号。 |
| to  | number | 是   | 数据源移动目标索引号。 |

## IDataSource<sup>10+</sup>

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### totalCount

totalCount(): number

获得数据总数。

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### getData

getData(index:&nbsp;number): Object

获取索引值index对应的数据。

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 获取数据对应的索引值 |

### registerDataChangeListener

registerDataChangeListener(listener: DataChangeListener): void

注册数据改变的监听器。

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                        | 必填 | 说明           |
| -------- | ------------------------------------------- | ---- | -------------- |
| listener | [DataChangeListener](#datachangelistener10) | 是   | 数据变化监听器 |

### unregisterDataChangeListener

unregisterDataChangeListener(listener: DataChangeListener): void

注销数据改变的监听器。

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                        | 必填 | 说明           |
| -------- | ------------------------------------------- | ---- | -------------- |
| listener | [DataChangeListener](#datachangelistener10) | 是   | 数据变化监听器 |

## DataChangeListener<sup>10+</sup>

数据变化监听器。

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onDataReloaded

onDataReloaded(): void

通知组件重新加载所有数据。键值没有变化的数据项会使用原先的子组件，键值发生变化的会重建子组件。重新加载数据完成后调用。

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onDataAdded<sup>(deprecated)</sup>

onDataAdded(index: number): void

通知组件index的位置有数据添加。添加数据完成后调用。

> 从API 8开始，建议使用[onDataAdd](#ondataadd8)。

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 数据添加位置的索引值 |

### onDataMoved<sup>(deprecated)</sup>

onDataMoved(from: number, to: number): void

通知组件数据有移动。将from和to位置的数据进行交换。

> 从API 8开始，建议使用[onDataMove](#ondatamove8)。
>
> **说明：** 数据移动前后键值要保持不变，如果键值有变化，应使用删除数据和新增数据接口。数据移动起始位置与数据移动目标位置交换完成后调用。

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| from   | number | 是   | 数据移动起始位置 |
| to     | number | 是   | 数据移动目标位置 |

### onDataDeleted<sup>(deprecated)</sup>

onDataDeleted(index: number): void

通知组件删除index位置的数据并刷新LazyForEach的展示内容。删除数据完成后调用。

> 从API 8开始，建议使用[onDataDelete](#ondatadelete8)。

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 数据删除位置的索引值 |

### onDataChanged<sup>(deprecated)</sup>

onDataChanged(index: number): void

通知组件index的位置有数据有变化。改变数据完成后调用。

> 从API 8开始，建议使用[onDataChange](#ondatachange8)。

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| index  | number | 是   | 数据变化监听器 |

### onDataAdd<sup>8+</sup>

onDataAdd(index: number): void

通知组件index的位置有数据添加。添加数据完成后调用

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| index  | number | 是   | 数据添加位置的索引值 |

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

### onDataMove<sup>8+</sup>

onDataMove(from: number, to: number): void

通知组件数据有移动。将from和to位置的数据进行交换。数据移动起始位置与数据移动目标位置交换完成后调用。

> **说明：** 数据移动前后键值要保持不变，如果键值有变化，应使用删除数据和新增数据接口。

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| from   | number | 是   | 数据移动起始位置 |
| to     | number | 是   | 数据移动目标位置 |

### onDataDelete<sup>8+</sup>

onDataDelete(index: number): void

通知组件删除index位置的数据并刷新LazyForEach的展示内容。删除数据完成后调用。

> **说明：** 需要保证dataSource中的对应数据已经在调用onDataDelete前删除，否则页面渲染将出现未定义的行为。

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 数据删除位置的索引值 |

### onDataChange<sup>8+</sup>

onDataChange(index: number): void

通知组件index的位置有数据有变化。改变数据完成后调用。

**卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 数据变化位置的索引值 |

### onDatasetChange<sup>12+</sup>

onDatasetChange(dataOperations: DataOperation[]): void

进行批量的数据处理后，调用onDatasetChange接口通知组件按照dataOperations刷新组件。

> **说明：** onDatasetChange接口不能与其他DataChangeListener的更新接口混用。如在同一个LazyForEach中，调用过onDataAdd接口后，不能再调用onDatasetChange接口；反之，调用过onDatasetChange接口后，也不能调用onDataAdd等其他更新接口。页面中不同LazyForEach之间互不影响。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名         | 类型                | 必填 | 说明               |
| -------------- | ------------------- | ---- | ------------------ |
| dataOperations | [DataOperation](#dataoperation12)[] | 是   | 一次处理数据的操作 |

## DataOperation<sup>12+</sup>

> **说明**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

### DataAddOperation

添加数据操作。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                      | 必填 | 说明                 |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).ADD     | 是   | 数据添加类型         |
| index  | number                    | 是   | 插入数据索引值       |
| count  | number                    | 否   | 插入数量，默认为1    |
| key    | string \| Array\<string\> | 否   | 为插入的数据分配键值 |

### DataDeleteOperation

删除数据操作。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                      | 必填 | 说明                 |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).DELETE     | 是   | 数据删除类型         |
| index  | number                    | 是   | 起始删除位置索引值       |
| count  | number                    | 否   | 删除数据数量，默认为1    |

### DataChangeOperation

改变数据操作。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                      | 必填 | 说明                 |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).CHANGE     | 是   | 数据改变类型         |
| index  | number                    | 是   | 改变的数据的索引值       |
| key  | string                    | 否   | 为改变的数据分配新的键值，默认使用原键值    |

### DataMoveOperation

移动数据操作。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                      | 必填 | 说明                 |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).MOVE     | 是   | 数据移动类型 |
| index  | [MoveIndex](#moveindex)        | 是   | 移动位置   |
| key | string              | 否   | 为被移动的数据分配新的键值，默认使用原键值 |

#### MoveIndex

| 参数名 | 类型                       | 必填 | 说明            |
| ------ | --------------- | ---- | ------- |
| from   | number | 是   | 起始移动位置                 |
| to  | number           | 是   | 目的移动位置           |

### DataExchangeOperation

交换数据操作。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                       | 必填 | 说明                         |
| ------ | -------------------------- | ---- | ---------------------------- |
| type   | [DataOperationType](#dataoperationtype).EXCHANGE | 是   | 数据交换类型                 |
| index  | [ExchangeIndex](#exchangeindex)            | 是   | 交换位置                     |
| key    | [ExchangeKey](#exchangekey)              | 否   | 分配新的键值，默认使用原键值 |

#### ExchangeIndex

| 参数名 | 类型                       | 必填 | 说明            |
| ------ | --------------- | ---- | ------- |
| start   | number | 是   | 第一个交换位置                 |
| end  | number           | 是   | 第二个交换位置           |

#### ExchangeKey

| 参数名 | 类型                       | 必填 | 说明            |
| ------ | --------------- | ---- | ------- |
| start   | string | 是   | 为第一个交换的位置分配新的键值，默认使用原键值        |
| end  | string   | 是   | 为第二个交换的位置分配新的键值，默认使用原键值           |

### DataReloadOperation

重载所有数据操作。当onDatasetChange含有DataOperationType.RELOAD操作时，其余操作全部失效，框架会自己调用keygenerator进行键值比对。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                     | 必填 | 说明             |
| ------ | ------------------------ | ---- | ---------------- |
| type   | [DataOperationType](#dataoperationtype).RELOAD | 是   | 数据全部重载类型 |

### DataOperationType

枚举类型，数据操作说明。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**枚举类型说明：**

| 属性 | 值                    | 说明                 |
| ------ | ------------------- | -------------------- |
| ADD   |   add       | 数据添加   |
| DELETE  | delete    | 数据删除    |
| CHANGE  | change     | 数据改变    |
| MOVE | move | 数据移动 |
| EXCHANGE | exchange | 数据交换 |
| RELOAD | reload | 全部数据重载 |