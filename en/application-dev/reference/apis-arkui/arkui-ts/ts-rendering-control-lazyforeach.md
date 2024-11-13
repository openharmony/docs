# LazyForEach

**LazyForEach** iterates over provided data sources and creates corresponding components during each iteration. When **LazyForEach** is used in a scrolling container, the framework creates components as required within the visible area of the scrolling container. When a component is out of the visible area, the framework destroys and reclaims the component to reduce memory usage.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name       | Type                                                     | Mandatory| Description                                                        |
| ------------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| dataSource    | [IDataSource](#idatasource10)                       | Yes  | **LazyForEach** data source. You need to implement related APIs.                 |
| itemGenerator | (item: Object, index: number) =&gt; void   | Yes  | Child component generation function, which generates a child component for each data item in the array.<br>**NOTE**<br>- **item** indicates the current data item, and **index** indicates the index of the data item.<br>- The function body of **itemGenerator** must be included in braces {...}.<br>- **itemGenerator** can and must generate only one child component for each iteration.<br>- The **if** statement is allowed in **itemGenerator**, but you must ensure that each branch of the **if** statement creates a child component of the same type.<br>- **ForEach** and **LazyForEach** statements are not allowed in **itemGenerator**.|
| keyGenerator  | (item: Object, index: number) =&gt; string | No  | ID generation function, which generates a unique and fixed ID for each data item in the data source. This ID must remain unchanged for the data item even when the item is relocated in the array. When the item is replaced by a new item, the ID of the new item must be different from that of the replaced item. This ID generation function is optional. However, for performance reasons, it is strongly recommended that the ID generation function be provided, so that the framework can better identify array changes. For example, if no ID generation function is provided, a reverse of an array will result in rebuilding of all nodes in **LazyForEach**.<br>**NOTE**<br>- **item** indicates the current data item, and **index** indicates the index of the data item.<br>- The ID generated for each data item in the data source must be unique.|

## onMove<sup>12+</sup>

onMove(handler: Optional<(from: index, to: index) => void>): T

Invoked when data is moved after sorting with dragging. This API takes effect only when it is used in a list and a list item is generated in each iteration of **LazyForEach**.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type     | Mandatory| Description      |
| ------ | --------- | ---- | ---------- |
| from  | number | Yes  | Start index of the data before movement.|
| to  | number | Yes  | Target index of the data after movement.|

## IDataSource<sup>10+</sup>

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### totalCount

totalCount(): number

Obtains the total number of data items.

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### getData

getData(index: number): Object

Obtains the data item that matches the specified index.

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the data record to obtain.|

### registerDataChangeListener

registerDataChangeListener(listener: DataChangeListener): void

Registers a listener for data changes.

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                       | Mandatory| Description          |
| -------- | ------------------------------------------- | ---- | -------------- |
| listener | [DataChangeListener](#datachangelistener10) | Yes  | Listener for data changes.|

### unregisterDataChangeListener

unregisterDataChangeListener(listener: DataChangeListener): void

Unregisters the listener for data changes.

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                       | Mandatory| Description          |
| -------- | ------------------------------------------- | ---- | -------------- |
| listener | [DataChangeListener](#datachangelistener10) | Yes  | Listener for data changes.|

## DataChangeListener<sup>10+</sup>

Listener for data changes.

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onDataReloaded

onDataReloaded(): void

Invoked when all data is reloaded. For data items whose key remains unchanged, the original child component is used. For data items whose key changes, a new child component is created.  

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onDataAdded<sup>(deprecated)</sup>

onDataAdded(index: number): void

Invoked when data is added to the position indicated by the specified index.  

> This API is deprecated since API version 8. You are advised to use [onDataAdd](#ondataadd8) instead.

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the position where data is added.|

### onDataMoved<sup>(deprecated)</sup>

onDataMoved(from: number, to: number): void

Invoked when data is moved. Data is swapped between the **from** and **to** positions.

> **NOTE**
>
> This API is deprecated since API version 8. You are advised to use [onDataMove](#ondatamove8) instead.
>
> The ID must remain unchanged before and after data movement. If the ID changes, APIs for deleting and adding data must be called.  

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| from   | number | Yes  | Original position of data.|
| to     | number | Yes  | Target position of data.|

### onDataDeleted<sup>(deprecated)</sup>

onDataDeleted(index: number): void

Invoked when data is deleted from the position indicated by the specified index. LazyForEach will update the displayed content accordingly.  

> This API is deprecated since API version 8. You are advised to use [onDataDelete](#ondatadelete8) instead.

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the position where data is deleted.|

### onDataChanged<sup>(deprecated)</sup>

onDataChanged(index: number): void

Invoked when data in the position indicated by the specified index is changed.  

> This API is deprecated since API version 8. You are advised to use [onDataChange](#ondatachange8) instead.

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| index  | number | Yes  | Listener for data changes.|

### onDataAdd<sup>8+</sup>

onDataAdd(index: number): void

Invoked when data is added to the position indicated by the specified index.  

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| index  | number | Yes  | Index of the position where data is added.|

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

### onDataMove<sup>8+</sup>

onDataMove(from: number, to: number): void

Invoked when data is moved. Data is swapped between the **from** and **to** positions.  

> **NOTE**
>
> The ID must remain unchanged before and after data movement. If the ID changes, APIs for deleting and adding data must be called.

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| from   | number | Yes  | Original position of data.|
| to     | number | Yes  | Target position of data.|

### onDataDelete<sup>8+</sup>

onDataDelete(index: number): void

Invoked when data is deleted from the position indicated by the specified index. LazyForEach will update the displayed content accordingly.  

> **NOTE**<br>Before **onDataDelete** is called, ensure that the corresponding data in **dataSource** has been deleted. Otherwise, undefined behavior will occur during page rendering.

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the position where data is deleted.|

### onDataChange<sup>8+</sup>

onDataChange(index: number): void

Invoked when data in the position indicated by the specified index is changed.  

**Widget capability**: This API can be used in ArkTS widgets since API version 10.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| index  | number | Yes  | Index of the position where data is changed.|

### onDatasetChange<sup>12+</sup>

onDatasetChange(dataOperations: DataOperation[]): void

Invoked when data is changed in batches. It cannot be used together with the aforementioned APIs.  

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name        | Type               | Mandatory| Description              |
| -------------- | ------------------- | ---- | ------------------ |
| dataOperations | [DataOperation](#dataoperation12)[] | Yes  | Data processing operation.|

## DataOperation<sup>12+</sup>

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

### DataAddOperation

Represents an operation for adding data.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                     | Mandatory| Description                |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).ADD     | Yes  | Type of data operation, specifically for adding data records.        |
| index  | number                    | Yes  | Index at which to insert the data record.      |
| count  | number                    | No  | Number of data records to insert.<br>Default value: **1**   |
| key    | string \| Array\<string\> | No  | Keys to assign to the inserted data records.|

### DataDeleteOperation

Represents an operation for deleting data.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                     | Mandatory| Description                |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).DELETE     | Yes  | Type of data operation, specifically for deleting data records.        |
| index  | number                    | Yes  | Index at which to start deleting data records.      |
| count  | number                    | No  | Number of data records to delete.<br>Default value: **1**   |

### DataChangeOperation

Represents an operation for changing data.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                     | Mandatory| Description                |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).CHANGE     | Yes  | Type of data operation, specifically for changing data records.        |
| index  | number                    | Yes  | Index of the data record to change.      |
| key  | string                    | No  | New key to assign to the changed data. The original key is used by default.   |

### DataMoveOperation

Represents an operation for moving data.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                     | Mandatory| Description                |
| ------ | ------------------------- | ---- | -------------------- |
| type   | [DataOperationType](#dataoperationtype).MOVE     | Yes  | Type of data operation, specifically for moving data records.|
| index  | [MoveIndex](#moveindex)        | Yes  | Position to move the data record to or from.  |
| key | string              | No  | New key to assign to the moved data. The original key is used by default.|

#### MoveIndex

| Name| Type                      | Mandatory| Description           |
| ------ | --------------- | ---- | ------- |
| from   | number | Yes  | Starting position for the movement.                |
| to  | number           | Yes  | Destination position for the movement.          |

### DataExchangeOperation

Represents an operation for exchanging data.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description                        |
| ------ | -------------------------- | ---- | ---------------------------- |
| type   | [DataOperationType](#dataoperationtype).EXCHANGE | Yes  | Type of data operation, specifically for exchanging data records.                |
| index  | [ExchangeIndex](#exchangeindex)            | Yes  | Positions to be exchanged.                    |
| key    | [ExchangeKey](#exchangekey)              | No  | New keys to assign to the exchanged positions. The original keys are used by default.|

#### ExchangeIndex

| Name| Type                      | Mandatory| Description           |
| ------ | --------------- | ---- | ------- |
| start   | number | Yes  | First position for the exchange.                |
| end  | number           | Yes  | Second position for the exchange.          |

#### ExchangeKey

| Name| Type                      | Mandatory| Description           |
| ------ | --------------- | ---- | ------- |
| start   | string | Yes  | New key to assign to the first position in the exchange. The original key is used by default.       |
| end  | string   | Yes  | New key to assign to the second position in the exchange. The original key is used by default.          |

### DataReloadOperation

Represents an operation for reloading data. If the **onDatasetChange** event contains a **DataOperationType.RELOAD** operation, all other operations in the event are ineffective. In such cases, the framework will call **keygenerator** to perform a comparison of keys with their corresponding values.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                    | Mandatory| Description            |
| ------ | ------------------------ | ---- | ---------------- |
| type   | [DataOperationType](#dataoperationtype).RELOAD | Yes  | Type of data operation, specifically for reloading all data records.|

### DataOperationType

Enumerates the data operation types.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Enum description**

| Name| Value                   | Description                |
| ------ | ------------------- | -------------------- |
| ADD   |   add       | Data addtion.  |
| DELETE  | delete    | Data deletion.   |
| CHANGE  | change     | Data change.   |
| MOVE | move | Data movement.|
| EXCHANGE | exchange | Data exchange.|
| RELOAD | reload | Data reloading.|
