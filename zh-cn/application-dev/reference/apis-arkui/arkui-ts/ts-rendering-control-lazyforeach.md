# LazyForEach
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @maorh-->
<!--Designer: @keerecles-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

> **说明**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

开发者指南见：[LazyForEach开发者指南](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md)。

LazyForEach是一种懒加载渲染控制组件，从提供的数据源中按需迭代数据并创建相应组件。在大量子组件的场景下，LazyForEach与缓存列表项、动态预加载、组件复用等方法配合使用，可以进一步提升滑动帧率并降低应用内存占用。最佳实践请参考[优化长列表加载慢丢帧问题](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-best-practices-long-list)。

## 接口

### LazyForEach

LazyForEach(dataSource: IDataSource, itemGenerator: (item: any, index: number) => void, keyGenerator?: (item: any, index: number) => string)

LazyForEach从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。当在滚动容器中使用了LazyForEach，框架会根据滚动容器可视区域按需创建组件，当组件滑出可视区域外时，框架会进行组件销毁回收以降低内存占用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名        | 类型                                                      | 必填 | 说明                                                         |
| ------------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| dataSource    | [IDataSource](#idatasource)                       | 是   | LazyForEach数据源，需要开发者实现相关接口。  |
| itemGenerator | (item:&nbsp;any, index: number)&nbsp;=&gt;&nbsp;void   | 是   | 子组件生成函数，为数组中的每一个数据项创建一个子组件。<br>**说明：**<br>- item是当前数据项（可选），index是数据项索引值（可选）。<br>- 建议item的数据类型与数据源的数据类型保持一致，否则，当itemGenerator中存在与数据类型强相关的操作时，会导致子组件无法正常渲染，甚至运行时崩溃。<br>- itemGenerator的函数体必须使用大括号{...}。<br>- itemGenerator每次迭代只能并且必须生成一个子组件。<br>- itemGenerator中可以使用if语句，但是必须保证if语句每个分支都会创建一个相同类型的子组件。 |
| keyGenerator  | (item:&nbsp;any, index: number)&nbsp;=&gt;&nbsp;string | 否   | 键值生成函数，用于给数据源中的每一个数据项生成唯一且固定的键值。修改数据源中的一个数据项若不影响其生成的键值，则对应组件不会被更新，否则对应组件就会被重建更新。`keyGenerator`参数是可选的，但是，为了使开发框架能够更好地识别数组更改并正确更新组件，建议提供。<br>默认使用框架内置的键值生成函数（详见下方说明）。<br>**说明：**<br>- item是当前数据项（可选），index是数据项索引值（可选）。<br>- 建议item的数据类型与数据源的数据类型保持一致，否则，当keyGenerator中存在与数据类型强相关的操作时，会导致子组件无法正常渲染，甚至运行时崩溃。<br>- `keyGenerator`缺省时，使用默认的键值生成函数，即`(item: Object, index: number) => { return viewId + '-' + index.toString(); }`，生成键值仅受索引值index影响（viewId在编译器转换过程中生成，同一个LazyForEach组件内的viewId一致）。<br>- 为保证`LazyForEach`正确、高效地更新子组件，避免渲染结果异常、渲染效率降低等问题，键值应满足以下条件。<br>1. 键值具有唯一性，每个数据项对应的键值互不相同。<br>2. 键值具有一致性，数据项不变时对应的键值也不变。 |

<!--RP1--><!--RP1End-->

### LazyForEach

LazyForEach(dataSource: IDataSource, itemGenerator: (item: any, index: number) => void, keyGenerator?: (item: any, index: number) => string, options?: LazyForEachOptions)

LazyForEach从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。当在滚动容器中使用了LazyForEach，框架会根据滚动容器可视区域按需创建组件，当组件滑出可视区域外时，框架会进行组件销毁回收以降低内存占用。

> **说明**
>
> 从API版本26.0.0开始，LazyForEach支持传入[LazyForEachOptions](#lazyforeachoptions)，用于使能自定义组件冻结和配置内存优化策略、资源释放策略。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名        | 类型                                                      | 必填 | 说明                                                         |
| ------------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| dataSource    | [IDataSource](#idatasource)                       | 是   | LazyForEach数据源，需要开发者实现相关接口。  |
| itemGenerator | (item:&nbsp;any, index: number)&nbsp;=&gt;&nbsp;void   | 是   | 子组件生成函数，为数组中的每一个数据项创建一个子组件。<br>**说明：**<br>- item是当前数据项（可选），index是数据项索引值（可选）。<br>- 建议item的数据类型与数据源的数据类型保持一致，否则，当itemGenerator中存在与数据类型强相关的操作时，会导致子组件无法正常渲染，甚至运行时崩溃。<br>- itemGenerator的函数体必须使用大括号{...}。<br>- itemGenerator每次迭代只能并且必须生成一个子组件。<br>- itemGenerator中可以使用if语句，但是必须保证if语句每个分支都会创建一个相同类型的子组件。 |
| keyGenerator  | (item:&nbsp;any, index: number)&nbsp;=&gt;&nbsp;string | 否   | 键值生成函数，用于给数据源中的每一个数据项生成唯一且固定的键值。修改数据源中的一个数据项若不影响其生成的键值，则对应组件不会被更新，否则对应组件就会被重建更新。`keyGenerator`参数是可选的，但是，为了使开发框架能够更好地识别数组更改并正确更新组件，建议提供。<br>默认使用框架内置的键值生成函数（详见下方说明）。<br>**说明：**<br>- item是当前数据项（可选），index是数据项索引值（可选）。<br>- 建议item的数据类型与数据源的数据类型保持一致，否则，当keyGenerator中存在与数据类型强相关的操作时，会导致子组件无法正常渲染，甚至运行时崩溃。<br>- `keyGenerator`缺省时，使用默认的键值生成函数，即`(item: Object, index: number) => { return viewId + '-' + index.toString(); }`，生成键值仅受索引值index影响（viewId在编译器转换过程中生成，同一个LazyForEach组件内的viewId一致）。<br>- 为保证`LazyForEach`正确、高效地更新子组件，避免渲染结果异常、渲染效率降低等问题，键值应满足以下条件。<br>1. 键值具有唯一性，每个数据项对应的键值互不相同。<br>2. 键值具有一致性，数据项不变时对应的键值也不变。 |
| options   | [LazyForEachOptions](#lazyforeachoptions)   | 否   | 开发者配置项，用于使能自定义组件冻结和配置内存优化策略、资源释放策略。使用此配置项时，必须设置键值生成函数，否则将编译失败。不传入时使用默认配置（自定义组件冻结模式默认为AUTO，资源释放策略默认为BATCH，内存优化策略默认为DEFAULT）。   |

## 属性

支持[拖拽排序](./ts-universal-attributes-drag-sorting.md)属性。

## IDataSource

LazyForEach的数据源，开发者需要实现该接口以提供数据访问和数据变化通知能力，包括获取数据总数、按索引获取数据、注册和注销数据变化监听器等。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### totalCount

totalCount(): number

获得数据总数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| number | 获得数据总数，由数据源决定实际大小。 |

### getData

getData(index:&nbsp;number): any

获取索引值index对应的数据。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 获取数据对应的索引值。取值范围是[0, 数据源长度-1]。超出取值范围时行为由数据源实现决定，建议开发者做边界检查。 |

**返回值：**

| 类型                | 说明        |
| ------------------- | --------- |
| any | 获取索引值index对应的数据，由数据源决定具体类型。 |

> **说明：** 
>
> 应避免在`getData`函数中执行耗时操作，以减少应用滑动时的卡顿丢帧，最佳实践请参考[主线程耗时操作优化-循环渲染](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-time-optimization-of-the-main-thread#section4551193714439)。

### registerDataChangeListener

registerDataChangeListener(listener: DataChangeListener): void

注册数据改变的监听器。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                        | 必填 | 说明           |
| -------- | ------------------------------------------- | ---- | -------------- |
| listener | [DataChangeListener](#datachangelistener) | 是   | 数据变化监听器，用于在数据源发生变化时通知组件刷新。 |

### unregisterDataChangeListener

unregisterDataChangeListener(listener: DataChangeListener): void

注销数据改变的监听器。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                        | 必填 | 说明           |
| -------- | ------------------------------------------- | ---- | -------------- |
| listener | [DataChangeListener](#datachangelistener) | 是   | 数据变化监听器，用于在数据源发生变化时通知组件刷新。 |

## DataChangeListener

数据变化监听器，用于在数据源发生变化时通知LazyForEach组件进行相应的渲染更新，支持数据添加、删除、改变、移动、交换、重载等多种数据变化类型的监听。

> **说明：** 
>
> DataChangeListener除onDatasetChange以外的方法中，当参数包含index且值为负数时，会默认用0来替换。onDatasetChange中，当单个DataOperation参数包含index且值在数据源索引范围之外（DataAddOperation中index可以等于数据源长度），则可能导致渲染异常。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onDataReloaded

onDataReloaded(): void

通知组件重新加载所有数据。键值没有变化的数据项会使用原先的子组件，键值发生变化的会重建子组件。重新加载数据完成后调用。

> **说明：**
>
> 该接口不能与onDatasetChange接口混用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onDataAdded<sup>(deprecated)</sup>

onDataAdded(index: number): void

通知组件index的位置有数据添加。添加数据完成后调用。

> **说明：**
>
> 从API version 7开始支持，从API version 8开始废弃。建议使用[onDataAdd](#ondataadd8)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 数据添加位置的索引值。取值范围是[0, 数据源长度-1]。<br>小于0时取值为0，大于数据源长度-1时取值为数据源长度-1。 |

### onDataMoved<sup>(deprecated)</sup>

onDataMoved(from: number, to: number): void

通知组件数据有移动。将from和to位置的数据进行交换。

> **说明：** 
>
> - 从API version 7开始支持，从API version 8开始废弃。建议使用[onDataMove](#ondatamove8)替代。
>
> - 数据移动前后键值要保持不变，如果键值有变化，应使用删除数据和新增数据接口。数据移动起始位置与数据移动目标位置交换完成后调用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| from   | number | 是   | 数据移动起始位置。取值范围是[0, 数据源长度-1]。<br>小于0时取值为0，大于数据源长度-1时取值为数据源长度-1。 |
| to     | number | 是   | 数据移动目标位置。取值范围是[0, 数据源长度-1]。<br>小于0时取值为0，大于数据源长度-1时取值为数据源长度-1。 |

### onDataDeleted<sup>(deprecated)</sup>

onDataDeleted(index: number): void

通知组件删除index位置的数据并刷新LazyForEach的展示内容。删除数据完成后调用。

> **说明：**
>
> - 从API version 7开始支持，从API version 8开始废弃。建议使用[onDataDelete](#ondatadelete8)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 数据删除位置的索引值。取值范围是[0, 数据源长度-1]。<br>小于0时取值为0，大于数据源长度-1时取值为数据源长度-1。 |

### onDataChanged<sup>(deprecated)</sup>

onDataChanged(index: number): void

通知组件index的位置有数据变化。改变数据完成后调用。

> **说明：**
>
> 从API version 7开始支持，从API version 8开始废弃。建议使用[onDataChange](#ondatachange8)替代。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| index  | number | 是   | 数据变化位置的索引值。取值范围是[0, 数据源长度-1]。<br>小于0时取值为0，大于数据源长度-1时取值为数据源长度-1。 |

### onDataAdd<sup>8+</sup>

onDataAdd(index: number): void

通知组件index的位置有数据添加。添加数据完成后调用。

> **说明：** 
>
> 该接口不能与onDatasetChange接口混用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| index  | number | 是   | 数据添加位置的索引值。取值范围是[0, 数据源长度-1]。<br>小于0时取值为0，大于数据源长度-1时取值为数据源长度-1。 |

### onDataMove<sup>8+</sup>

onDataMove(from: number, to: number): void

通知组件数据有移动。将from和to位置的数据进行交换。数据移动起始位置与数据移动目标位置交换完成后调用。

> **说明：** 
>
> - 数据移动前后键值要保持不变，如果键值有变化，应使用删除数据和新增数据接口。
> - 该接口不能与onDatasetChange接口混用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| from   | number | 是   | 数据移动起始位置。取值范围是[0, 数据源长度-1]。<br>小于0时取值为0，大于数据源长度-1时取值为数据源长度-1。 |
| to     | number | 是   | 数据移动目标位置。取值范围是[0, 数据源长度-1]。<br>小于0时取值为0，大于数据源长度-1时取值为数据源长度-1。 |

### onDataDelete<sup>8+</sup>

onDataDelete(index: number): void

通知组件删除index位置的数据并刷新LazyForEach的展示内容。删除数据完成后调用。

> **说明：** 
>
> - 需要保证dataSource中的对应数据已经在调用onDataDelete前删除，否则页面渲染将出现未定义的行为。
> - 该接口不能与onDatasetChange接口混用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 数据删除位置的索引值。取值范围是[0, 数据源长度-1]。<br>小于0时取值为0，大于数据源长度-1时取值为数据源长度-1。 |

### onDataChange<sup>8+</sup>

onDataChange(index: number): void

通知组件index的位置有数据变化。改变数据完成后调用。

> **说明：**
>
> 该接口不能与onDatasetChange接口混用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| index  | number | 是   | 数据变化位置的索引值。取值范围是[0, 数据源长度-1]。<br>小于0时取值为0，大于数据源长度-1时取值为数据源长度-1。 |

### onDatasetChange<sup>12+</sup>

onDatasetChange(dataOperations: DataOperation[]): void

进行批量的数据处理后，调用onDatasetChange接口通知组件按照dataOperations刷新组件。

> **说明：** 
>
> onDatasetChange接口不能与其他DataChangeListener的更新接口混用。例如，在同一个LazyForEach中，调用过onDataAdd接口后，不能再调用onDatasetChange接口；反之，调用过onDatasetChange接口后，也不能调用onDataAdd等其他更新接口。页面中不同LazyForEach之间互不影响。在同一个onDatasetChange批量处理数据时，如果多个DataOperation操作同一个index，只有第一个DataOperation生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名         | 类型                | 必填 | 说明               |
| -------------- | ------------------- | ---- | ------------------ |
| dataOperations | [DataOperation](#dataoperation12)[] | 是   | 一次批量处理数据的操作集合，开发者将需要处理的数据操作（添加、删除、改变、移动、交换、重载等）放入该数组，组件按照数组中的操作顺序刷新展示内容。 |

## DataOperation<sup>12+</sup>

type DataOperation = DataAddOperation | DataDeleteOperation | DataChangeOperation | DataMoveOperation | DataExchangeOperation | DataReloadOperation

> **说明**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### DataAddOperation<sup>12+</sup>

添加数据操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                      | 只读 | 可选 | 说明                 |
| ------ | ------------------------- | ---- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype12).ADD     | 否 | 否   | 数据添加类型。         |
| index  | number                    | 否 | 否   | 添加数据索引值。取值范围是[0, 数据源长度]。超出取值范围时渲染异常。 |
| count  | number                    | 否 | 是   | 添加数量，必须是正整数（大于0），默认为1。传入0或负数时可能导致渲染效果异常。   |
| key    | string \| Array\<string\> | 否 | 是   | 为添加的数据分配键值，默认使用原键值。键值支持string或Array\<string\>类型；当键值为数组且长度大于count时报参数无效错误。 |

### DataDeleteOperation<sup>12+</sup>

删除数据操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                      | 只读 | 可选 | 说明                 |
| ------ | ------------------------- | ---- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype12).DELETE     | 否 | 否   | 数据删除类型。         |
| index  | number                    | 否 | 否   | 起始删除位置索引值。取值范围是[0, 数据源长度-1]。超出取值范围时渲染异常。|
| count  | number                    | 否 | 是   | 删除数据数量，必须是正整数（大于0），且index与count之和不超过数据源长度，默认为1。传入负数时该操作会被忽略；传入0时会异常地将index处的数据项标记删除。index与count之和超过数据源长度时可能导致渲染异常。    |

### DataChangeOperation<sup>12+</sup>

改变数据操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                      | 只读 | 可选 | 说明                 |
| ------ | ------------------------- | ---- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype12).CHANGE     | 否 | 否   | 数据改变类型。         |
| index  | number                    | 否 | 否   | 改变的数据的索引值。取值范围是[0, 数据源长度-1]。超出取值范围时渲染异常。|
| key  | string                    | 否 | 是   | 为改变的数据分配新的键值，默认使用原键值。    |

### DataMoveOperation<sup>12+</sup>

移动数据操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                      | 只读 | 可选 | 说明                 |
| ------ | ------------------------- | ---- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype12).MOVE     | 否 | 否   | 数据移动类型。 |
| index  | [MoveIndex](#moveindex12)        | 否 | 否   | 移动位置。取值范围是[0, 数据源长度-1]。超出取值范围时渲染异常。|
| key | string              | 否 | 是   | 为被移动的数据分配新的键值，默认使用原键值。 |

### DataExchangeOperation<sup>12+</sup>

交换数据操作。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                       | 只读 | 可选 | 说明                         |
| ------ | -------------------------- | ---- | ---- | ---------------------------- |
| type   | [DataOperationType](#dataoperationtype12).EXCHANGE | 否 | 否   | 数据交换类型。                 |
| index  | [ExchangeIndex](#exchangeindex12)            | 否 | 否   | 交换位置。取值范围是[0, 数据源长度-1]。超出取值范围时渲染异常。|
| key    | [ExchangeKey](#exchangekey12)              | 否 | 是   | 分配新的键值，默认使用原键值。 |

### DataReloadOperation<sup>12+</sup>

重载所有数据操作。当onDatasetChange含有DataOperationType.RELOAD操作时，其余操作全部失效，框架会自己调用keyGenerator进行键值比对。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                     | 只读 | 可选 | 说明             |
| ------ | ------------------------ | ---- | ---- | ---------------- |
| type   | [DataOperationType](#dataoperationtype12).RELOAD | 否 | 否   | 数据全部重载类型。 |

### DataOperationType<sup>12+</sup>

枚举类型，数据操作说明。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值                    | 说明                 |
| ------ | ------------------- | -------------------- |
| ADD   |   add       | 数据添加。   |
| DELETE  | delete    | 数据删除。    |
| CHANGE  | change     | 数据改变。    |
| MOVE | move | 数据移动。 |
| EXCHANGE | exchange | 数据交换。 |
| RELOAD | reload | 全部数据重载。 |

## MoveIndex<sup>12+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                       | 只读 | 可选 | 说明            |
| ------ | --------------- | ---- | ---- | ------- |
| from   | number | 否 | 否   | 起始移动位置。取值范围是[0, 数据源长度-1]。超出取值范围时渲染异常。|
| to  | number           | 否 | 否   | 目标移动位置。取值范围是[0, 数据源长度-1]。超出取值范围时渲染异常。|

## ExchangeIndex<sup>12+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                       | 只读 | 可选 | 说明            |
| ------ | --------------- | ---- | ---- | ------- |
| start   | number | 否 | 否   | 第一个交换位置。取值范围是[0, 数据源长度-1]。超出取值范围时渲染异常。|
| end  | number           | 否 | 否   | 第二个交换位置。取值范围是[0, 数据源长度-1]。超出取值范围时渲染异常。|

## ExchangeKey<sup>12+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                       | 只读 | 可选 | 说明            |
| ------ | --------------- | ---- | ---- | ------- |
| start   | string | 否 | 否   | 为第一个交换的位置分配新的键值，默认使用原键值。        |
| end  | string   | 否 | 否   | 为第二个交换的位置分配新的键值，默认使用原键值。           |

## LazyForEachOptions

用于配置LazyForEach的资源释放策略、内存优化策略，以及是否使能自定义组件冻结。

> **说明：** 
>
> 1. 注意：在使用LazyForEachOptions时，必须保证键值生成函数已经定义，否则将编译失败。
>
> 2. 自定义组件冻结：在LazyForEach下，直接使用自定义组件时，使用该配置选择是否使能自定义组件的冻结功能。使能后，当自定义组件不在可视区域时，框架会暂停该组件的状态变量更新等处理逻辑，以降低资源消耗；组件重新进入可视区域时恢复正常处理。
>
> 3. 资源释放策略：LazyForEach会管理屏上区域节点和预加载区域节点，当节点滑动出预加载区域离开LazyForEach的管理范围时，LazyForEach不再管理该节点，该节点资源被释放。默认使用BATCH模式，LazyForEach会在当前帧释放所有待释放的节点；PROGRESSIVE模式会逐个释放资源，在释放每个节点资源时判断当前帧的时间是否足够，如果不够就会放到后续帧释放。在此策略下，LazyForEach可能会持有节点资源，缓存池中的节点来不及扩充，在快速获取节点的场景下会导致复用率下降。开发者应根据应用情况选择合适的资源释放策略。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型                       | 只读 | 可选 | 说明            |
| ------ | --------------- | ---- | ---- | ------- |
| customComponentFreezeMode   | [LazyForEachCustomComponentFreezeMode](#lazyforeachcustomcomponentfreezemode) | 否 | 是   | 选择是否使能自定义组件冻结。仅在LazyForEach下直接使用自定义组件时生效，其他情况不适用。<br>默认为[AUTO](#lazyforeachcustomcomponentfreezemode)。        |
| releaseStrategy  | [LazyForEachReleaseStrategy](#lazyforeachreleasestrategy)   | 否 | 是   | 为LazyForEach配置资源释放策略。<br>默认使用[BATCH](#lazyforeachreleasestrategy)，批量释放节点。           |
| memoryOptimizationStrategy   | [LazyForEachMemOptStrategy](#lazyforeachmemoptstrategy) | 否 | 是   | LazyForEach的内存优化策略。该参数在创建LazyForEach时设定，不支持动态修改。<br>默认值：[DEFAULT](#lazyforeachmemoptstrategy) |

## LazyForEachCustomComponentFreezeMode

选择是否使能自定义组件冻结。

> **说明：** 
>
> 该配置仅在LazyForEach下直接使用自定义组件时添加，其他情况不适用。


**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值                    | 说明                 |
| ------ | ------------------- | -------------------- |
| AUTO   |   0       | 跟随module.json5配置文件中metadata的设置。   |
| DISABLED  | 1    | 不使能自定义组件冻结。    |
| ENABLED  | 2     | 使能自定义组件冻结。    |

## LazyForEachReleaseStrategy

选择LazyForEach的资源释放策略。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值                    | 说明                 |
| ------ | ------------------- | -------------------- |
| BATCH   |   0       | BATCH为默认使用的资源释放策略，该策略在当前帧释放掉所有废弃节点资源。如果存在节点复用，此时能够最大化节点复用率，但如果存在组件层级较深、子组件数量较多的节点，单节点资源释放耗时较长。大量节点在当前帧释放可能会导致超大帧，影响性能。   |
| PROGRESSIVE  | 1    | PROGRESSIVE为根据节点释放时间和当前帧剩余时间自动调整节点释放的策略，如果当前帧时间不足以释放剩余节点，会放到后续帧继续释放，避免超大帧的出现，优化性能。此时，LazyForEach会继续持有节点，可能导致复用率下降，在节点大量产生来不及释放的情况下，内存会相应地升高。开发者需关注性能和内存的影响，合理选择资源释放策略。    |

## LazyForEachMemOptStrategy

LazyForEach内存优化策略枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 值 | 说明 |
| --- | --- | --- |
| DEFAULT | 0 | 无内存优化策略。 |
| ENABLE_AUTO_CACHE_OPTIMIZATION | 1 << 0 | 自动内存优化策略，当LazyForEach承载的列表项数量较多（例如达到数百项以上）或单项子组件结构复杂（例如包含多层嵌套或数十个子节点），导致内存占用偏高（可通过性能分析工具检测内存占用情况）时，建议使用此策略以降低内存使用量。<br>当应用退后台时、LazyForEach所在组件不可见时（[visibility](./ts-universal-attributes-visibility.md#visibility)属性设置为[Visible](./ts-appendix-enums.md#visibility)以外的值，或组件面积为0，不考虑遮挡）、整机低内存时（[MemoryLevel](../../apis-ability-kit/js-apis-app-ability-abilityConstant.md#memorylevel)达到MEMORY_LEVEL_LOW或MEMORY_LEVEL_CRITICAL），对于内存大于6G的设备，释放[预加载区域](../../../ui/rendering-control/arkts-rendering-control-overview.md#基本概念)内的部分节点，直至上下预加载区域内的节点数量均不超过2；对于内存小于等于6G的设备，释放预加载区域内的全部节点。<br>当应用恢复前台时、LazyForEach所在组件恢复显示时，LazyForEach发生滑动时，恢复预加载区域内的节点。<br>在释放和恢复节点时，会触发[自定义组件生命周期](../../../ui/state-management/arkts-page-custom-components-lifecycle.md)。 |

## 示例

### 示例1（使用自动内存优化策略）

以下示例中，通过[LazyForEachOptions](#lazyforeachoptions)的memoryOptimizationStrategy属性使用了自动内存优化策略。应用退后台时，清理缓存。应用恢复前台时，恢复缓存。

从API版本26.0.0开始，新增LazyForEachOptions接口。

BasicDataSource代码见LazyForEach开发者指南末尾BasicDataSource示例代码：[string类型数组的BasicDataSource代码](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md#string类型数组的basicdatasource代码)。

<!--code_no_check-->
```ts
import { BasicDataSource } from './BasicDataSource';

class DataSource extends BasicDataSource {
  public dataArray: string[] = [];
  public totalCount(): number {
    return this.dataArray.length;
  }
  public getData(index: number): string {
    return this.dataArray[index];
  }
  public pushData(data: string): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@Component
struct ChildComponent {
  aboutToAppear() {
    console.info('ChildComponent aboutToAppear');
  }
  aboutToDisappear() {
    console.info('ChildComponent aboutToDisappear');
  }
  build() {
    Text('ChildComponent')
  }
}

@Entry
@Component
struct MemoryOptimizeDemo {
  private data: DataSource = new DataSource();
  aboutToAppear() {
    for (let i = 0; i < 100; i++) {
      this.data.pushData(`item ${i}`);
    }
  }
  build() {
    Column() {
      List() {
        LazyForEach(this.data,
          (item: string, index: number) => {
            ListItem() {
              ChildComponent()
            }
          },
          (item: string, index: number) => item,
          { memoryOptimizationStrategy: LazyForEachMemOptStrategy.ENABLE_AUTO_CACHE_OPTIMIZATION } // 使用自动内存优化策略
        )
      }
      .cachedCount(5)
    }
  }
}
```

