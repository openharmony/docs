# Repeat

When **virtualScroll** is disabled, the **Repeat** component, which is used together with the container component, performs loop rendering based on array data. In addition, the component returned by the API should be a child component that can be contained in the **Repeat** parent container. Compared with ForEach, **Repeat** optimizes the rendering performance in some update scenarios and generates function with the index maintained by the framework.

When **virtualScroll** is enabled, **Repeat** iterates data from the provided data source as required and creates the corresponding component during each iteration. When **Repeat** is used in the scrolling container, the framework creates components as required based on the visible area of the scrolling container. When a component slides out of the visible area, the framework caches the component and uses it in the next iteration.

>**NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> State management V2 is still under development, and some features may be incomplete or not always work as expected.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type      | Mandatory| Description     |
| ------ | ---------- | -------- | -------- |
| arr    | Array\<T\> | Yes| Data source, which is an array of the **Array\<T>** type. You can determine the data types.|

**Return value**

| Type| Description|
| --- | --- |
| [RepeatAttribute](#repeatattribute)\<T\> | Repeat attributes.|

## RepeatAttribute

### each

each(itemGenerator: (repeatItem: RepeatItem\<T\>) => void): RepeatAttribute\<T\>

Component generator. Data items that do not match **template** and **templateId** are generated using the **each** function by default.

**NOTE**

- The **each** attribute is mandatory. Otherwise, an error occurs during running.
- The parameter of **itemGenerator** is **RepeatItem**, which combines **item** and **index**. Do not split the **RepeatItem** and use it separately.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description|
| ------ | ---------- | -------- | -------- |
| repeatItem  | [RepeatItem](#repeatitem)\<T\> | Yes| Repeat items.|

### key

key(keyGenerator: (item: T, index: number) => string): RepeatAttribute\<T\>

Key generator.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ---------- | -------- | -------- |
| item  | T | Yes| Data item in the **arr** array.|
| index  | number | Yes| Index of a data item in the **arr** array.|

### virtualScroll

virtualScroll(virtualScrollOptions?: VirtualScrollOptions): RepeatAttribute\<T\>

Enables virtual scrolling for the **Repeat** component.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ---------- | -------- | -------- |
| virtualScrollOptions  | [VirtualScrollOptions](#virtualscrolloptions)  | No| Virtual scrolling configuration.|

### template

template(type: string, itemBuilder: RepeatItemBuilder\<T\>, templateOptions?: TemplateOptions): RepeatAttribute\<T\>

Defines a template for reusing.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ---------- | -------- | -------- |
| type | string | Yes| Template type.|
| itemBuilder  | [RepeatItemBuilder](#repeatitembuilder)\<T\> | Yes| Component generator.|
| templateOptions | [TemplateOptions](#templateoptions) | No| Template configuration.|

### templateId

templateId(typedFunc: TemplateTypedFunc\<T\>): RepeatAttribute\<T\>

Assigns a template ID to this data item.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ---------- | -------- | -------- |
| typedFunc | [TemplateTypedFunc](#templatetypedfunc)\<T\> | Yes| Template ID to assign.|

## RepeatItem

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                        |
| ------ | ------ | ---- | -------------------------------------------- |
| item   | T      | Yes  | Each data item in **arr**. **T** indicates the data type passed in.|
| index  | number | Yes  | Index corresponding to the current data item.                      |

## VirtualScrollOptions

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type  | Mandatory| Description                                                        |
| ---------- | ------ | ---- | ------------------------------------------------------------ |
| totalCount | number | No  | Total length of the data source, which can be greater than the number of loaded data items.<br>With **arr.length** representing the length of the data source, the following are the rules for determining **totalCount**:<br>1. If **totalCount** is not set \|\| **totalCount** is not an integer \|\| totalCount <= 0 \|\| totalCount == arr.length, then **totalCount** is the length of the data source, and the list scrolls properly.<br>2. If 0 < **totalCount** < arr.length, only the **totalCount**-specified number of data items are rendered in the UI.<br>3. If **totalCount** > **arr.Length**, the scrollbar displays normally, but the areas without data items show up as empty spaces. When the scrolling animation finishes, the scrollbar rests at the position of the last data item. In this way, you can use the correct scrollbar style without requesting all the data at the same time.|

> **NOTE**<br>When **totalCount** < **arr.length**, you are advised to set **totalCount** to a value that can fill the parent component to prevent any empty spaces within the parent component, which could lead to a suboptimal user experience.

## RepeatItemBuilder

type RepeatItemBuilder\<T\> = (repeatItem: RepeatItem\<T\>) => void

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type         | Mandatory     | Description                                   |
| ---------- | ------------- | --------------------------------------- | --------------------------------------- |
| repeatItem | [RepeatItem](#repeatitem)\<T\> | Yes| A state variable that combines **item** and **index**.|

## TemplateOptions

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| cachedCount | number | No  | Maximum number of child nodes of the current template that can be cached in the **Repeat** cache pool. This parameter takes effect only when **virtualScroll** is enabled.<br>When **cachedCount** is set to the maximum number of nodes of the current template that may appear on the screen, **Repeat** can be reused as much as possible. However, when there is no node of the current template on the screen, the cache pool is not released and the application memory increases. You need to set the configuration based on the actual situation.<br>If you do not specify **cachedCount**, the framework calculates **cachedCount** for different templates based on the number of visible and pre-rendered nodes on the screen. When the number of visible and pre-rendered nodes on the screen increases, **cachedCount** will also increase accordingly. It should be noted that the value of **cachedCount** will not decrease.<br> To explicitly specify **cachedCount**, you are advised to set it to the same as the number of nodes on the screen. Yet, setting **cachedCount** to less than 2 is not advised. Doing so may lead to the creation of new nodes during rapid scrolling, which could result in performance degradation.|

## TemplateTypedFunc

type TemplateTypedFunc\<T\> = (item : T, index : number) => string

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                        |
| ------ | ------ | ---- | -------------------------------------------- |
| item   | T      | Yes  | Each data item in **arr**. **T** indicates the data type passed in.|
| index  | number | Yes  | Index corresponding to the current data item.                      |
