# LazyForEach

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

For details about the development, see [LazyForEach: Lazy Data Loading](../../../quick-start/arkts-rendering-control-lazyforeach.md).

## APIs

LazyForEach(dataSource: IDataSource,itemGenerator: (item: any, index: number) => void,keyGenerator?: (item: any, index: number) => string,)

**LazyForEach** iterates over provided data sources and creates corresponding components during each iteration. When **LazyForEach** is used in a scrolling container, the framework creates components as required within the visible area of the scrolling container. When a component is out of the visible area, the framework destroys and reclaims the component to reduce memory usage.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                                                     | Mandatory| Description                                                        |
| ------------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| dataSource    | [IDataSource](#idatasource10)                       | Yes  | **LazyForEach** data source. You need to implement related APIs.                 |
| itemGenerator | (item: Object, index: number) =&gt; void   | Yes  | Child component generation function, which generates a child component for each data item in the array.<br>**NOTE**<br>- **item** indicates the current data item, and **index** indicates the index of the data item.<br>- The function body of **itemGenerator** must be included in braces {...}.<br>- **itemGenerator** can and must generate only one child component for each iteration.<br>- The **if** statement is allowed in **itemGenerator**, but you must ensure that each branch of the **if** statement creates a child component of the same type.<br>- **ForEach** and **LazyForEach** statements are not allowed in **itemGenerator**.|
| keyGenerator  | (item: Object, index: number) =&gt; string | No  | ID generation function, which generates a unique and fixed ID for each data item in the data source. This ID must remain unchanged for the data item even when the item is relocated in the array. When the item is replaced by a new item, the ID of the new item must be different from that of the replaced item. This ID generation function is optional. However, for performance reasons, it is strongly recommended that the ID generation function be provided, so that the framework can better identify array changes. For example, if no ID generation function is provided, a reverse of an array will result in rebuilding of all nodes in **LazyForEach**.<br>**NOTE**<br>- **item** indicates the current data item, and **index** indicates the index of the data item.<br>- The ID generated for each data item in the data source must be unique.|

## Name

Inherited from [DynamicNode](./ts-rendering-control-foreach.md#dynamicnode12).

## IDataSource<sup>10+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### totalCount

totalCount(): number

Obtains the total number of data items.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### getData

getData(index: number): Object

Obtains the data item that matches the specified index.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the data record to obtain.|

### registerDataChangeListener

registerDataChangeListener(listener: DataChangeListener): void

Registers a listener for data changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                       | Mandatory| Description          |
| -------- | ------------------------------------------- | ---- | -------------- |
| listener | [DataChangeListener](#datachangelistener10) | Yes  | Listener for data changes.|

### unregisterDataChangeListener

unregisterDataChangeListener(listener: DataChangeListener): void

Unregisters the listener for data changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                       | Mandatory| Description          |
| -------- | ------------------------------------------- | ---- | -------------- |
| listener | [DataChangeListener](#datachangelistener10) | Yes  | Listener for data changes.|

## DataChangeListener<sup>10+</sup>

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
| index  | number | Yes  | Index of the position where data is added.|

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
| from   | number | Yes  | Original position of data.|
| to     | number | Yes  | Target position of data.|

### onDataDeleted<sup>(deprecated)</sup>

onDataDeleted(index: number): void

Invoked when data is deleted from the position indicated by the specified index. LazyForEach will update the displayed content accordingly.  

> This API is deprecated since API version 8. You are advised to use [onDataDelete](#ondatadelete8) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the position where data is deleted.|

### onDataChanged<sup>(deprecated)</sup>

onDataChanged(index: number): void

Invoked when data in the position indicated by the specified index is changed.  

> This API is deprecated since API version 8. You are advised to use [onDataChange](#ondatachange8) instead.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| index  | number | Yes  | Listener for data changes.|

### onDataAdd<sup>8+</sup>

onDataAdd(index: number): void

Invoked when data is added to the position indicated by the specified index.  

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| index  | number | Yes  | Index of the position where data is added.|

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
| from   | number | Yes  | Original position of data.|
| to     | number | Yes  | Target position of data.|

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
| index  | number | Yes  | Index of the position where data is deleted.|

### onDataChange<sup>8+</sup>

onDataChange(index: number): void

Invoked when data in the position indicated by the specified index is changed.  

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the position where data is changed.|

### onDatasetChange<sup>12+</sup>

onDatasetChange(dataOperations: DataOperation[]): void

Invoked when data is processed in batches to notify the component of refreshing.

> **NOTE**
>
> This API cannot be used together with other data operation APIs of **DataChangeListener**. For example, in the same **LazyForEach**, if you have called **onDataAdd**, do not call **onDatasetChange**; if you have called **onDatasetChange**, do not call **onDataAdd** or other data operation APIs. Different **LazyForEach** instances on the page do not affect each other.

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
| index  | number                    | Yes  | Index at which to insert the data record.      |
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
| index  | number                    | Yes  | Index at which to start deleting data.      |
| count  | number                    | No  | Number of data records to delete.<br>Default value: **1**.   |

### DataChangeOperation

Represents an operation for changing data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                     | Mandatory| Description                |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).CHANGE     | Yes  | Type of data change.        |
| index  | number                    | Yes  | Index of the data to be changed.      |
| key  | string                    | No  | New key to assign to the changed data. The original key is used by default.   |

### DataMoveOperation

Represents an operation for moving data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                     | Mandatory| Description                |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).MOVE     | Yes  | Type of data movement.|
| index  | [MoveIndex](#moveindex)        | Yes  | Positions for the movement.  |
| key | string              | No  | New key to assign to the moved data. The original key is used by default.|

#### MoveIndex

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description           |
| ------ | --------------- | ---- | ------- |
| from   | number | Yes  | Start position for the movement.                |
| to  | number           | Yes  | End position for the movement.          |

### DataExchangeOperation

Represents an operation for exchanging data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description                        |
| ------ | -------------------------- | ---- | ---------------------------- |
| type   | [DataOperationType](#dataoperationtype).EXCHANGE | Yes  | Type of data exchange.                |
| index  | [ExchangeIndex](#exchangeindex)            | Yes  | Positions for the exchange.                    |
| key    | [ExchangeKey](#exchangekey)              | No  | New keys to assign to the exchanged data. The original keys are used by default.|

#### ExchangeIndex

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description           |
| ------ | --------------- | ---- | ------- |
| start   | number | Yes  | First position for the exchange.                |
| end  | number           | Yes  | Second position for the exchange.          |

#### ExchangeKey

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description           |
| ------ | --------------- | ---- | ------- |
| start   | string | Yes  | New key to assign to the first position in the exchange. The original key is used by default.       |
| end  | string   | Yes  | New key to assign to the second position in the exchange. The original key is used by default.          |

### DataReloadOperation

Represents an operation for reloading data. If the **onDatasetChange** event contains a **DataOperationType.RELOAD** operation, all other operations in the event are ineffective. In such cases, the framework will call **keygenerator** to perform a comparison of keys with their corresponding values.

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
