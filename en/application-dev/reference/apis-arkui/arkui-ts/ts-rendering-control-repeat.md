# Repeat

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**Repeat** is used to perform repeated rendering based on array data. Generally, it is used together with container components.
This document provides API parameter descriptions. For details about the development, see [Repeat: Reusing Child Components](../../../quick-start/arkts-new-rendering-control-repeat.md).

## Properties

Inherited from [DynamicNode](./ts-rendering-control-foreach.md#dynamicnode12).

## APIs

### Repeat: \<T\>(arr: Array\<T\>)

When **virtualScroll** is not enabled: renders repeated components based on the data source. This API must be used in conjunction with a container component. In addition, the component returned by the API must be a child component that can be contained in the **Repeat** parent container component. Compared to **ForEach**, **Repeat** optimizes the rendering performance for partial updates. The index for the component generator function is maintained by the framework.

When virtualScroll is enabled: Iterates data from the provided data source as required and creates the corresponding component during each iteration. In this scenario, the API must be used together with a scrollable container component. When **Repeat** is used in a scrollable container component, the framework creates components as required based on the visible area of the container. When a component scrolls out of the visible area, the framework caches it and reuses it in the next iteration.

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

## Events

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### each

each(itemGenerator: (repeatItem: RepeatItem\<T\>) => void): RepeatAttribute\<T\>

Generates components. This function is used as the default generator when data items do not match any specified template or template ID.

> **NOTE**
>
> The **each** attribute is mandatory. Otherwise, a runtime error occurs.
> The **itemGenerator** parameter is of the **RepeatItem** type, which combines **item** and **index**. Do not split **RepeatItem**.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description|
| ------ | ---------- | -------- | -------- |
| repeatItem  | [RepeatItem](#repeatitemt)\<T\> | Yes| Data item for the repeat.|

**Example**
```ts
// Create a Text component for each item in the arr array of the Array<string> type.
Repeat<string>(this.arr)
  .each((obj: RepeatItem<string>) => { Text(obj.item) })
```

### key

key(keyGenerator: (item: T, index: number) => string): RepeatAttribute\<T\>

Generates a unique key for each item in the data source.

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
// Use the string value as the key value.
Repeat<string>(this.arr)
  .each((obj: RepeatItem<string>) => { Text(obj.item) })
  .key((obj: string) => obj)
```

### virtualScroll

virtualScroll(virtualScrollOptions?: VirtualScrollOptions): RepeatAttribute\<T\>

Enables virtual scrolling for the **Repeat** component.

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

template(type: string, itemBuilder: RepeatItemBuilder\<T\>, templateOptions?: TemplateOptions): RepeatAttribute\<T\>

Defines a reusable template for component generation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ---------- | -------- | -------- |
| type | string | Yes| Type of the template.|
| itemBuilder  | [RepeatItemBuilder](#repeatitembuildert)\<T\> | Yes| Component generator.|
| templateOptions | [TemplateOptions](#templateoptions) | No| Configuration of the template.|

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

templateId(typedFunc: TemplateTypedFunc\<T\>): RepeatAttribute\<T\>

Assigns a template ID to each data item.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ---------- | -------- | -------- |
| typedFunc | [TemplateTypedFunc](#templatetypedfunct)\<T\> | Yes| Function that generates a template ID for each data item.|

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

## Properties

Inherited from [DynamicNode](./ts-rendering-control-foreach.md#dynamicnode12) since API version 18.

## RepeatArray\<T\><sup>18+</sup>

type RepeatArray\<T\> = Array\<T\> | ReadonlyArray\<T\> | Readonly\<Array\<T\>\>

Defines a union type for the **Repeat** data source parameter.

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
| totalCount | number | No  | Total number of data items to load, which may not equal the data source length.|
| reusable<sup>18+</sup> | boolean | No  | Whether to enable component reuse. The value **true** means to enable component reuse, and **false** means the opposite.<br>Default value: **false**|
| onLazyLoading<sup>18+</sup> | (index: number) => void | No  | Function to load data on demand for a given index.|
| onTotalCount<sup>18+</sup> | () => number | No  | Function to dynamically obtain the total number of items, which may not equal the data source length. Prioritize this function over **totalCount**. If both **totalCount** and **onTotalCount** are set, **totalCount** is ignored.|

**Example**
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
    .virtualScroll( { 
      onTotalCount: () => { return 100; },
      onLazyLoading: (index: number) => { this.arr[index] = `No.${index}`; }
      } )
}
```

## RepeatItemBuilder\<T\>

type RepeatItemBuilder\<T\> = (repeatItem: RepeatItem\<T\>) => void

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type         | Mandatory     | Description                                   |
| ---------- | ------------- | --------------------------------------- | --------------------------------------- |
| repeatItem | [RepeatItem](#repeatitemt)\<T\> | Yes| A state variable that combines **item** and **index**.|

## TemplateOptions

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| cachedCount | number | No  | Maximum number of child nodes that can be cached for the current template in the **Repeat** cache pool. This parameter takes effect only when **virtualScroll** is enabled.|

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

type TemplateTypedFunc\<T\> = (item : T, index : number) => string

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                        |
| ------ | ------ | ---- | -------------------------------------------- |
| item   | T      | Yes  | Each data item in the **arr** array. **T** indicates the data type passed in.|
| index  | number | Yes  | Index corresponding to the current data item.                      |
