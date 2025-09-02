# LazyForEach

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

For details about the development, see [LazyForEach: Lazy Data Loading](../../../ui/state-management/arkts-rendering-control-lazyforeach.md).
In scenarios involving a large number of child components, LazyForEach, when combined with techniques such as cached list items, dynamic preloading, and component reuse, can significantly improve scrolling frame rates while reducing memory usage. For best practices, see [Optimizing Frame Loss for Long List Loading](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-best-practices-long-list).

## APIs

LazyForEach(dataSource: IDataSource, itemGenerator: (item: any, index: number) => void, keyGenerator?: (item: any, index: number) => string)

**LazyForEach** iterates over provided data sources and creates corresponding components during each iteration. When **LazyForEach** is used in a scrolling container, the framework creates components as required within the visible area of the scrolling container. When a component is out of the visible area, the framework destroys and reclaims the component to reduce memory usage.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                                                     | Mandatory| Description                                                        |
| ------------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| dataSource    | [IDataSource](#idatasource)                       | Yes  | **LazyForEach** data source. You need to implement related APIs.                 |
| itemGenerator | (item: any, index: number) =&gt; void   | Yes  | Child component generation function, which generates a child component for each data item in the array.<br>**NOTE**<br>- (Optional) **item**: data item.<br>(Optional) **index**: index of the data item.<br>- The function body of **itemGenerator** must be included in braces {...}.<br>- **itemGenerator** can and must generate only one child component for each iteration.<br>- The **if** statement is allowed in **itemGenerator**, but you must ensure that each branch of the **if** statement creates a child component of the same type.|
| keyGenerator  | (item: any, index: number) =&gt; string | No  | ID generation function, which generates a unique and fixed ID for each data item in the data source. Components are updated only when their generated key changes. The **keyGenerator** parameter is optional, but you are advised to provide it so that the development framework can better identify array changes and update components correctly.<br>**NOTE**<br>- (Optional) **item**: data item.<br>(Optional) **index**: index of the data item.<br>- The ID generated for each data item in the data source must be unique.<br>- If **keyGenerator** is not provided, the framework uses the default key generation function, that is, **(item: Object, index: number) => { return viewId + '-' + index.toString(); }**, where the generated key value is only affected by the index.|

> **NOTE**
>
> To ensure smooth scrolling and prevent frame drops, avoid time-consuming operations in **keyGenerator** and **itemGenerator** functions. For best practices, see [Optimizing Time-Consuming Operations in the Main Thread: Repeated Rendering](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-time-optimization-of-the-main-thread#section4551193714439). The **JSON.stringify()** method is particularly discouraged for key generation in complex business scenarios. When processing item objects, this serialization method consumes significant computational resources and execution time, which can substantially degrade page rendering performance. For best practices, see [Optimizing Performance Using LazyForEach: Rules for Generating Key Values and Creating Components](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-lazyforeach-optimization#section68711519072).

## IDataSource

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### totalCount

totalCount(): number

Obtains the total number of data items.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type               | Description       |
| ------------------- | --------- |
| number | Total number of data items, which is subject to the data source.|

### getData

getData(index: number): any

Obtains the data item that matches the specified index.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the data record to obtain. The value range is [0, data source length - 1].|

**Return value**

| Type               | Description       |
| ------------------- | --------- |
| any | Data item that matches the specified index. The actual type is determined by the data source implementation.|

> **NOTE**
>
> To ensure smooth scrolling and prevent frame drops, avoid time-consuming operations in the **getData** function. For best practices, see [Optimizing Time-Consuming Operations in the Main Thread: Repeated Rendering](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-time-optimization-of-the-main-thread#section4551193714439).

### registerDataChangeListener

registerDataChangeListener(listener: DataChangeListener): void

Registers a listener for data changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                       | Mandatory| Description          |
| -------- | ------------------------------------------- | ---- | -------------- |
| listener | [DataChangeListener](#datachangelistener7) | Yes  | Listener for data changes.|

### unregisterDataChangeListener

unregisterDataChangeListener(listener: DataChangeListener): void

Unregisters the listener for data changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                       | Mandatory| Description          |
| -------- | ------------------------------------------- | ---- | -------------- |
| listener | [DataChangeListener](#datachangelistener7) | Yes  | Listener for data changes.|

## DataChangeListener<sup>7+</sup>

Listener for data changes.

> **NOTE**
>
> In APIs of **DataChangeListener** other than **onDatasetChange**, if the value of **index** is negative, the value is treated as **0** by default. In **onDatasetChange**, if the specified index in a **DataOperation** is outside the data source index range, the corresponding **DataOperation** does not take effect. (In **DataAddOperation**, the value of **index** can equal the data source length.)

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onDataReloaded

onDataReloaded(): void

Invoked when all data is reloaded. For data items whose key remains unchanged, the original child component is used. For data items whose key changes, a new child component is created.  

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onDataAdded<sup>(deprecated)</sup>

onDataAdded(index: number): void

Invoked when data is added to the position indicated by the specified index.  

> This API is deprecated since API version 8. You are advised to use [onDataAdd](#ondataadd8) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the position where data is added. The value range is [0, data source length - 1].|

### onDataMoved<sup>(deprecated)</sup>

onDataMoved(from: number, to: number): void

Invoked when data is moved, that is, when data is swapped between the **from** and **to** positions.

> This API is deprecated since API version 8. You are advised to use [onDataMove](#ondatamove8) instead.

> **NOTE**
>
> The ID must remain unchanged before and after data movement. If the ID changes, APIs for deleting and adding data must be called.  

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| from   | number | Yes  | Original position of data. The value range is [0, data source length - 1].|
| to     | number | Yes  | Target position of data. The value range is [0, data source length - 1].|

### onDataDeleted<sup>(deprecated)</sup>

onDataDeleted(index: number): void

Invoked when data is deleted from the position indicated by the specified index. LazyForEach will update the displayed content accordingly.  

> This API is deprecated since API version 8. You are advised to use [onDataDelete](#ondatadelete8) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the position where data is deleted. The value range is [0, data source length - 1].|

### onDataChanged<sup>(deprecated)</sup>

onDataChanged(index: number): void

Invoked when data in the position indicated by the specified index is changed.  

> This API is deprecated since API version 8. You are advised to use [onDataChange](#ondatachange8) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| index  | number | Yes  | Listener for data changes. The value range is [0, data source length - 1].|

### onDataAdd<sup>8+</sup>

onDataAdd(index: number): void

Invoked when data is added to the position indicated by the specified index.  

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| index  | number | Yes  | Index of the position where data is added. The value range is [0, data source length - 1].|

### onDataMove<sup>8+</sup>

onDataMove(from: number, to: number): void

Invoked when data is moved, that is, when data is swapped between the **from** and **to** positions.  

> **NOTE**
>
> The ID must remain unchanged before and after data movement. If the ID changes, APIs for deleting and adding data must be called.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| from   | number | Yes  | Original position of data. The value range is [0, data source length - 1].|
| to     | number | Yes  | Target position of data. The value range is [0, data source length - 1].|

### onDataDelete<sup>8+</sup>

onDataDelete(index: number): void

Invoked when data is deleted from the position indicated by the specified index. LazyForEach will update the displayed content accordingly.  

> **NOTE**
>
> Before **onDataDelete** is called, ensure that the corresponding data in **dataSource** has been deleted. Otherwise, undefined behavior will occur during page rendering.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the position where data is deleted. The value range is [0, data source length - 1].|

### onDataChange<sup>8+</sup>

onDataChange(index: number): void

Invoked when data in the position indicated by the specified index is changed.  

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the position where data is changed. The value range is [0, data source length - 1].|

### onDatasetChange<sup>12+</sup>

onDatasetChange(dataOperations: DataOperation[]): void

Invoked when data is processed in batches to notify the component of refreshing.

> **NOTE**
>
> This API cannot be used together with other data operation APIs of **DataChangeListener**. For example, in the same **LazyForEach**, if you have called **onDataAdd**, do not call **onDatasetChange**; if you have called **onDatasetChange**, do not call **onDataAdd** or other data operation APIs. Different **LazyForEach** instances on the page do not affect each other. When data is processed in batches within the same **onDatasetChange** callback, if multiple **DataOperation** instances target the same index, only the first **DataOperation** will take effect.
**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name        | Type               | Mandatory| Description              |
| -------------- | ------------------- | ---- | ------------------ |
| dataOperations | [DataOperation](#dataoperation12)[] | Yes  | Array of data operations performed.|

## DataOperation<sup>12+</sup>

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### DataAddOperation

Represents an operation for adding data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                     | Mandatory| Description                |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).ADD     | Yes  | Type of data addition.        |
| index  | number                    | Yes  | Index at which to insert the data record. The value range is [0, data source length - 1].|
| count  | number                    | No  | Number of data records to insert.<br>Default value: **1**.  |
| key    | string \| Array\<string\> | No  | Keys to assign to the inserted data records.|

### DataDeleteOperation

Represents an operation for deleting data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                     | Mandatory| Description                |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).DELETE     | Yes  | Type of data deletion.        |
| index  | number                    | Yes  | Index at which to start deleting data. The value range is [0, data source length - 1].|
| count  | number                    | No  | Number of data records to delete.<br>Default value: **1**.   |

### DataChangeOperation

Represents an operation for changing data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                     | Mandatory| Description                |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).CHANGE     | Yes  | Type of data change.        |
| index  | number                    | Yes  | Index of the data to be changed. The value range is [0, data source length - 1].|
| key  | string                    | No  | New key to assign to the changed data. The original key is used by default.   |

### DataMoveOperation

Represents an operation for moving data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                     | Mandatory| Description                |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).MOVE     | Yes  | Type of data movement.|
| index  | [MoveIndex](#moveindex)        | Yes  | Positions for the movement. The value range is [0, data source length - 1].|
| key | string              | No  | New key to assign to the moved data. The original key is used by default.|

#### MoveIndex

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description           |
| ------ | --------------- | ---- | ------- |
| from   | number | Yes  | Start position for the movement. The value range is [0, data source length - 1].|
| to  | number           | Yes  | End position for the movement. The value range is [0, data source length - 1].|

### DataExchangeOperation

Represents an operation for exchanging data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description                        |
| ------ | -------------------------- | ---- | ---------------------------- |
| type   | [DataOperationType](#dataoperationtype).EXCHANGE | Yes  | Type of data exchange.                |
| index  | [ExchangeIndex](#exchangeindex)            | Yes  | Positions for the exchange. The value range is [0, data source length - 1].|
| key    | [ExchangeKey](#exchangekey)              | No  | New keys to assign to the exchanged data. The original keys are used by default.|

#### ExchangeIndex

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description           |
| ------ | --------------- | ---- | ------- |
| start   | number | Yes  | First position for the exchange. The value range is [0, data source length - 1].|
| end  | number           | Yes  | Second position for the exchange. The value range is [0, data source length - 1].|

#### ExchangeKey

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description           |
| ------ | --------------- | ---- | ------- |
| start   | string | Yes  | New key to assign to the first position in the exchange. The original key is used by default.       |
| end  | string   | Yes  | New key to assign to the second position in the exchange. The original key is used by default.          |

### DataReloadOperation

Represents an operation for reloading data. If the **onDatasetChange** event contains a **DataOperationType.RELOAD** operation, all other operations in the event are ineffective. In such cases, the framework will call **keyGenerator** to perform a comparison of keys with their corresponding values.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                    | Mandatory| Description            |
| ------ | ------------------------ | ---- | ---------------- |
| type   | [DataOperationType](#dataoperationtype).RELOAD | Yes  | Type of data reloading.|

### DataOperationType

Enumerates the data operation types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value                   | Description                |
| ------ | ------------------- | -------------------- |
| ADD   |   add       | Data addition.  |
| DELETE  | delete    | Data deletion.   |
| CHANGE  | change     | Data change.   |
| MOVE | move | Data movement.|
| EXCHANGE | exchange | Data exchange.|
| RELOAD | reload | Data reloading.|
