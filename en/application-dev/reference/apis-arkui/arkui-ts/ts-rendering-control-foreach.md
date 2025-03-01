# ForEach

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

For details about the development, see [ForEach: Rendering Repeated Content](../../../quick-start/arkts-rendering-control-foreach.md).

**ForEach** enables rendering of repeated content based on array type data. It must be used in a container component, and the component it returns must be one allowed inside the container component. For example, for rendering of list items, **ForEach** must be used in the [List](../../../reference/apis-arkui/arkui-ts/ts-container-list.md) component.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name       | Type                                   | Mandatory| Description                                                        |
| ------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| arr           | Array\<Object\>                         | Yes  | Data source, which is an array.<br>**NOTE**<br>- You can set this parameter to an empty array. In this case, no child component is created.<br>- You can also set this parameter to a function whose return value is an array, for example, **arr.slice (1, 3)**. However, the set function cannot change any state variables including the array itself. For example, **Array.splice**, **Array.sort**, and **Array.reverse** functions are not allowed, as they may change the array.|
| itemGenerator | (item: Object, index: number) => void   | Yes  | Component generator.<br>- It generates a component for each data item in an array. <br>- **item**: data item in the **arr** array.<br>- (Optional) **index**: index of the data item in the **arr** array.<br>**NOTE**<br>- The type of the created component must be the one allowed inside the parent container component of **ForEach**. For example, a **ListItem** component is allowed only when the parent container component of **ForEach** is **List**.|
| keyGenerator  | (item: Object, index: number) => string | No  | Key generator.<br>- It generates a unique and persistent key for each array item of the data source **arr**. The return value is the key generation rule you customize.<br>- **item**: data item in the **arr** array.<br>- (Optional) **index**: index of the data item in the **arr** array.<br>**NOTE**<br>- If this function is not specified, the default key generator of the framework is used: **(item: T, index: number) => { return index + '__' + JSON.stringify(item); }**.<br>- The key generator should not change any component state.|

> **NOTE**
>
> - The **itemGenerator** function can contain an **if/else** statement, and an **if/else** statement can contain **ForEach**.
> - On initial rendering, **ForEach** loads all data of the data source, creates a component for each data item, and mounts the created components to the render tree. If the data source contains a large number of items or performance is a critical concern, you are advised to use **LazyForEach**.

**Example**
```ts
// arr is an array of strings.
// The first parameter is a component creation function.
// The second parameter is a key generation function.
ForEach(this.arr, (item: string, index: number) => {Text(item)}, (item: string, index: number) => item + index)
```

## onMove<sup>12+</sup>

onMove(handler: Optional<(from: index, to: index) => void>): T

Invoked when data is moved after sorting with dragging. This API takes effect only when it is used in a list and a list item is generated in each iteration of **ForEach**.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type     | Mandatory| Description      |
| ------ | --------- | ---- | ---------- |
| from  | number | Yes  | Start index of the data before movement.|
| to  | number | Yes  | Target index of the data after movement.|
