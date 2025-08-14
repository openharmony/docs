# Repeat

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**Repeat** is used to perform repeated rendering based on array data. Generally, it is used together with container components.

This document provides API parameter descriptions. For details about the component descriptions and usage guidelines, see [Repeat: Reusable Repeated Rendering](../../../ui/state-management/arkts-new-rendering-control-repeat.md).

## APIs

### Repeat: \<T\>(arr: Array\<T\>)

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type      | Mandatory| Description     |
| ------ | ---------- | -------- | -------- |
| arr    | Array\<T\> | Yes| Data source, which is an array of the **Array\<T>** type. You can determine the data types.|

**Example**
```ts
// arr is an array of the Array<string> type, which is used as the data source for Repeat.
Repeat<string>(this.arr)
```

### Repeat: \<T\>(arr: RepeatArray\<T\>)<sup>18+</sup>

> **NOTE**
>
> Data sources of the RepeatArray type are supported since API version 18.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type      | Mandatory| Description     |
| ------ | ---------- | -------- | -------- |
| arr    | [RepeatArray\<T\>](#repeatarrayt18) | Yes| Data source, which is an array of the **RepeatArray\<T>** type. You can determine the data types.|

## Properties

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### each

each(itemGenerator: (repeatItem: RepeatItem\<T\>) => void)

Component generator. When none of the **.template()** types match the return value of **.templateId()**, **.each()** will be used to process data items.

> **NOTE**
>
> The **each** property is mandatory. If it is omitted, runtime errors will occur.
> The **itemGenerator** parameter is of the **RepeatItem** type, which combines **item** and **index**. Do not destructure **RepeatItem**.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description|
| ------ | ---------- | -------- | -------- |
| repeatItem  | [RepeatItem](#repeatitemt)\<T\> | Yes| Repeat data item.|

**Example**
```ts
// Create a Text component for each item in the arr array of the Array<string> type.
Repeat<string>(this.arr)
  .each((obj: RepeatItem<string>) => { Text(obj.item) })
```

### key

key(keyGenerator: (item: T, index: number) => string)

Key generator.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ---------- | -------- | -------- |
| item  | T | Yes| Data item in the **arr** array.|
| index  | number | Yes| Index of the data item in the **arr** array.|

**Example**
```ts
// Create a Text component for each item in the arr array of the Array<string> type.
// Use the string value as its key.
Repeat<string>(this.arr)
  .each((obj: RepeatItem<string>) => { Text(obj.item) })
  .key((obj: string) => obj)
```

### virtualScroll

virtualScroll(virtualScrollOptions?: VirtualScrollOptions)

Enables virtual scrolling for **Repeat**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ---------- | -------- | -------- |
| virtualScrollOptions  | [VirtualScrollOptions](#virtualscrolloptions)  | No| Virtual scrolling configuration.|

**Example**
```ts
// Create a Text component for each item in the arr array of the Array<string> type.
// Use Repeat in a List container component with virtual scrolling enabled.
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }})
    .virtualScroll()
}
```

### template

template(type: string, itemBuilder: RepeatItemBuilder\<T\>, templateOptions?: TemplateOptions)

Renders the corresponding template child component based on the template type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ---------- | -------- | -------- |
| type | string | Yes| Current template type.|
| itemBuilder  | [RepeatItemBuilder](#repeatitembuildert)\<T\> | Yes| Component generator.|
| templateOptions | [TemplateOptions](#templateoptions) | No| Current template configuration.|

**Example**
```ts
// arr is an array of the Array<string> type.
// Use Repeat in a List container component with virtual scrolling enabled.
// Define a reusable template temp for generating Text components.
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => {})
    .virtualScroll()
    .template('temp', (obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }})
}
```

### templateId

templateId(typedFunc: TemplateTypedFunc\<T\>)

Assigns a template type for this data item.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ---------- | -------- | -------- |
| typedFunc | [TemplateTypedFunc](#templatetypedfunct)\<T\> | Yes| Function that generates a template type for each data item.|

**Example**
```ts
// arr is an array of the Array<string> type.
// Use Repeat in a List container component with virtual scrolling enabled.
// Define a reusable template temp for generating Text components.
// Use the temp template for all data items.
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => {})
    .virtualScroll()
    .template('temp', (obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }})
    .templateId((item: string, index: number) => { return 'temp' })
}
```

## RepeatArray\<T\><sup>18+</sup>

type RepeatArray\<T\> = Array\<T\> | ReadonlyArray\<T\> | Readonly\<Array\<T\>\>

Defines a union type for **Repeat** data source parameters.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

|  Type      | Description     |
| -------- | -------- |
| Array\<T\> | Regular array type.|
| ReadonlyArray\<T\> | Read-only array type, where the array object cannot be modified.|
| Readonly\<Array\<T\>> | Read-only array type, where the array object cannot be modified.|

## RepeatItem\<T\>

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type  | Mandatory| Description                                        |
| ------ | ------ | ---- | -------------------------------------------- |
| item   | T      | Yes  | Each data item in the **arr** array. **T** indicates the data type passed in.|
| index  | number | Yes  | Index corresponding to the current data item.                      |

## VirtualScrollOptions

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type  | Mandatory| Description                                                        |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| totalCount | number | No  | Total number of data items to load, which may not equal the data source length.<br>Value range: [0, +¡Þ).<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| reusable<sup>18+</sup> | boolean | No  | Whether to enable the reuse feature. The value **true** means to enable the reuse feature, and **false** means the opposite.<br>Default value: **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| onLazyLoading<sup>19+</sup> | (index: number) => void | No  | Function to load data on demand for a given index.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|
| onTotalCount<sup>19+</sup> | () => number | No  | Function to dynamically obtain the total number of items, which may not equal the data source length. Prioritize this function over **totalCount**. If both **totalCount** and **onTotalCount** are set, **totalCount** is ignored.<br>Value range: [0, +¡Þ).<br>**Atomic service API**: This API can be used in atomic services since API version 19.|

### totalCount: Length of the Data to Be Loaded

**totalCount** indicates the length of the data to be loaded, which is the length of the original array by default and can be greater than the number of loaded data items. **arr.length** represents the length of the data source. The processing rules for **totalCount** are as follows:

- When **totalCount** is omitted or set to a non-natural number, the value of **totalCount** is **arr.length**, and the list scrolls normally.
- When the value of **totalCount** is greater that or equal to **0** and smaller than the value of **arr.length**, only data within the range of [0, *totalCount* - 1] is rendered.
- When the value of **totalCount** is greater than the value of **arr.length**, data in the range of [0, *totalCount* - 1] will be rendered. The scrollbar style changes based on the value of **totalCount**.

> **NOTE**
>
> When the value of **totalCount** is greater than the value of **arr.length**, during the scrolling of the parent component container, the application needs to ensure that subsequent data is requested when the list is about to scroll to the end of the data source. You need to handle error scenarios (such as network delays) for data requests until all data sources are loaded; otherwise, scrolling exceptions may occur during list scrolling. For solutions, see [The totalCount Value Is Greater Than the Length of Data Source](../../../ui/state-management/arkts-new-rendering-control-repeat.md#the-totalcount-value-is-greater-than-the-length-of-data-source).

### onLazyLoading<sup>19+</sup>: Precise Lazy Loading

**onLazyLoading** is supported since API version 19 and is intended for use in lazy loading scenarios. You can implement a custom method to write data to a specified index in the data source. The processing rules for **onLazyLoading** are as follows:

- Before reading the data corresponding to an index in the data source, **Repeat** checks whether data exists at that index.
- If no data exists but the **onLazyLoading** method is implemented, **Repeat** calls this method.
- In the **onLazyLoading** method, data should be written to the index specified by **Repeat** in the format of **arr[index] = ...**. In addition, array operations except **[]** are not allowed, and elements except the specified index cannot be written. Otherwise, the system throws an exception.
- After the **onLazyLoading** method is executed, if no data exists in the specified index, rendering exceptions will occur.

> **NOTE**
>
> - Whenever possible, use **onLazyLoading** together with **onTotalCount** instead of **totalCount**.
> - **onLazyLoading** is recommended in scenarios where the expected data length is greater than the actual source length.
> - Avoid using the **onLazyLoading** method to execute time-consuming operations. If data loading takes a long time, you are advised to create a placeholder for the data in the **onLazyLoading** method and then create an asynchronous task to load the data.
> - When **onLazyLoading** is used and **onTotalCount** is set to **arr.length + 1**, data can be loaded infinitely. In this scenario, you need to provide the initial data required for the first screen display and set **cachedCount** to a value greater than 0 for the parent container component. Otherwise, rendering exceptions will occur. Avoid using the **onLazyLoading** method together with the loop mode of **Swipe**. Otherwise, staying at **index = 0** will trigger continuous **onLazyLoading** calls. In addition, you need to pay attention to the memory usage to avoid excessive memory consumption caused by continuous data loading.

### onTotalCount<sup>19+</sup>: Calculating the Expected Data Length

**onTotalCount** is supported since API version 19 and is intended for use in lazy loading scenarios. You can implement a custom method that returns the expected array length. The return value must be a natural number and may not be equal to the actual data source length **arr.length**. The processing rules for **onTotalCount** are as follows:

- When the return value is a non-natural number, **arr.length** is used as the return value and the list scrolls normally.
- When the return value is greater that or equal to **0** and smaller than the value of **arr.length**, only data within the range of [0, *return value* - 1] is rendered.
- When the return value is greater than **arr.length**, the data within the range of [0, *return value* - 1] is rendered. The scrollbar style changes based on the return value.

> **NOTE**
>
> - Unlike **totalCount**, **onTotalCount** can be proactively called by **Repeat** to update the expected data length when necessary.
> - Use either **totalCount** or **onTotalCount**, not both. If neither is set, the default value of **arr.length** is used. If both are set, **totalCount** is ignored.
> - When the return value of **onTotalCount** is greater than the value of **arr.length**, you are advised to use **onLazyLoading** to implement lazy loading.

### Example

```ts
// Create a Text component for each item in the arr array. Use Repeat in a List container component with virtual scrolling enabled.
// Set the total number of data items to the length of the data source and enable component reuse.
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }})
    .virtualScroll( { totalCount: this.arr.length, reusable: true } )
}

// Assume that the total number of items is 100, and 3 items are needed for the initial screen rendering.
// The initial array provides the first 3 items (arr = ['No.0', 'No.1', 'No.2']), and lazy loading is enabled.
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }})
    .virtualScroll({ 
      onTotalCount: () => { return 100; },
      onLazyLoading: (index: number) => { this.arr[index] = `No.${index}`; }
    })
}
```

## RepeatItemBuilder\<T\>

type RepeatItemBuilder\<T\> = (repeatItem: RepeatItem\<T\>) => void

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type         | Mandatory     | Description                                   |
| ---------- | ------------- | --------------------------------------- | --------------------------------------- |
| repeatItem | [RepeatItem](#repeatitemt)\<T\> | Yes| State variable that combines **item** and **index**.|

## TemplateOptions

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| cachedCount | number | No  | Maximum number of child component nodes that can be cached in the cache pool of the current template. <br>Value range: [0, +¡Þ). <br>Default value: sum of the number of onscreen and preloaded nodes. <br>When the number of onscreen and preloaded nodes increases, the value of **cachedCount** will increase accordingly. Note that the value of **cachedCount** does not decrease.|

When **cachedCount** is set to the maximum number of nodes displayed on the screen for the current template, **Repeat** achieves maximum reuse efficiency. However, when no nodes of the current template are on the screen, the cache pool will not be released, and application memory usage will increase. You need to manage this based on specific scenarios.

- If **cachedCount** is not specified, the framework calculates the value of **cachedCount** for each template based on the sum of the number of onscreen and preloaded nodes. When the number of onscreen and preloaded nodes increases, the value of **cachedCount** will increase accordingly. Note that the value of **cachedCount** does not decrease.
- When explicitly specifying **cachedCount**, you are advised to set it equal to the number of onscreen nodes. Yet, setting **cachedCount** to less than 2 is not advised. Doing so may lead to the creation of new nodes during rapid scrolling, which could result in performance degradation.

> **NOTE**
> 
> The **.cachedCount()** attribute of the scrolling container component and the **cachedCount** parameter of the **.template()** method of **Repeat** are used to balance performance and memory, but their meanings are different.
> - **.cachedCount()** in scrollable container components (for example, **List** and **Grid**): indicates the preloaded nodes outside the visible range. These nodes exist in the component tree but are not visible. The container components render these off-screen nodes for performance benefits. However, **Repeat** treats these nodes as visible.
> - **.cachedCount()** in **.template()**: indicates nodes that are treated as invisible by **Repeat**. These nodes are idle and are temporarily stored in the framework. You can update these nodes as required to implement reuse.

**Example**
```ts
// Create a Text component for each item in the arr array. Use Repeat in a List container component with virtual scrolling enabled.
// Define a reusable template temp for generating Text components. Use the temp template for all data items.
// Set the maximum cache count for the temp template to 2.
List() {
  Repeat<string>(this.arr)
    .each((obj: RepeatItem<string>) => {})
    .virtualScroll()
    .template('temp', (obj: RepeatItem<string>) => { ListItem() { Text(obj.item) }}, { cachedCount: 2 })
    .templateId((item: string, index: number) => { return 'temp' })
}
```

## TemplateTypedFunc\<T\>

type TemplateTypedFunc\<T\> = (item: T, index: number) => string

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                        |
| ------ | ------ | ---- | -------------------------------------------- |
| item   | T      | Yes  | Each data item in the **arr** array. **T** indicates the data type passed in.|
| index  | number | Yes  | Index corresponding to the current data item.                      |
