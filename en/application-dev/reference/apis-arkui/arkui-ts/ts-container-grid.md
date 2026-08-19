# Grid

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @guozejun-->
<!--Designer: @guozejun-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=6bb7734c15263a20cd1bc3773b5ca773f0c94f6a translatedAt=2026-08-18T03:10:11.763Z pushedAt=2026-08-18T06:56:13.651Z -->

The **Grid** component consists of cells formed by rows and columns. You can specify the cells where items are located to form various layouts.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The component has been bound with gestures to implement functions such as follow-up scrolling. If you need to add custom gestures, refer to [Gesture Blocking Enhancement](ts-gesture-blocking-enhancement.md).

## Child Components

Child components are limited to [GridItem](ts-container-griditem.md) and custom components. When using custom components inside **Grid**, it is recommended to wrap the custom component with a **GridItem** as the top-level container. Setting attributes or event methods directly on custom components is not recommended.

Child components can be dynamically generated using rendering control types [if/else](../../../ui/rendering-control/arkts-rendering-control-ifelse.md), [ForEach](../../../ui/rendering-control/arkts-rendering-control-foreach.md), [LazyForEach](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md), and [Repeat](../../../ui/rendering-control/arkts-new-rendering-control-repeat.md). **LazyForEach** or **Repeat** is recommended to optimize performance.

>  **NOTE**
>
>  Below are the rules for calculating the indexes of the child components of **Grid**:
>
>  The index increases in ascending order of child components.
>
>  In the **if/else** statement, only the child components in the branch where the condition is met participate in the index calculation.
>
>  In the ForEach/LazyForEach and Repeat statements, index values are calculated for all expanded child components.
>
>  After changes occur in [if/else](../../../ui/rendering-control/arkts-rendering-control-ifelse.md), [ForEach](../../../ui/rendering-control/arkts-rendering-control-foreach.md), [LazyForEach](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md), and [Repeat](../../../ui/rendering-control/arkts-new-rendering-control-repeat.md), index values are updated accordingly for child components.
>
>  The child component that has the **visibility** attribute set to **Hidden** or **None** is included in the index calculation.
>
>  The child component that has the **visibility** attribute set to **None** is not displayed, but still takes up the corresponding cell.
>
>  The child component that has the **position** attribute set is displayed in the corresponding cell, offset by the distance specified by **position** relative to the upper left corner of the grid. This child component does not scroll with the corresponding cell and is not displayed after the corresponding cell extends beyond the display range of the grid.
>
>  When there is a gap between child components, it is filled as much as possible based on the current display area. Therefore, the relative position of grid items may change as the grid scrolls.
>
>  Since API version 21, the maximum width and height of a single **Grid** child component are 16777216 px. In API version 20 and earlier versions, the maximum width and height of a single **Grid** child component are 1000000 px. Exceeding these limits may result in scrolling or display abnormalities.

## APIs

Grid(scroller?: Scroller, layoutOptions?: GridLayoutOptions)

Creates a **Grid** component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                    |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| scroller | [Scroller](ts-container-scroll.md#scroller) | No | Controller of the scrollable component. It is used to bind to the scrollable component. If it is not set, no external controller is bound, and the component manages the scrolling behavior by itself.<br/>**NOTE**<br/>It is not allowed to bind the same scroll control object to other scrollable components, such as [ArcList](ts-container-arclist.md), [List](ts-container-list.md), [Grid](ts-container-grid.md), [Scroll](ts-container-scroll.md), and [WaterFlow](ts-container-waterflow.md). |
| layoutOptions<sup>10+</sup> | [GridLayoutOptions](#gridlayoutoptions10) | No | Grid layout options, used to configure layout information such as **GridItem** spanning rows and columns. If it is not passed in, the **Grid** performs layout based on regular attributes such as **rowsTemplate** and **columnsTemplate** and the attributes of **GridItem** itself, without enabling the layout options provided by **GridLayoutOptions**.<br/>**Model restriction:** This API can be used only in the stage model. |

## GridLayoutOptions<sup>10+</sup>

Defines the grid layout options. In this API, **irregularIndexes** and **onGetIrregularSizeByIndex** can be used for grids where either **rowsTemplate** or **columnsTemplate** is set. These properties allow you to specify an index array and set the number of rows and columns to be occupied by a grid item at the specified index. For details about the usage, see [Example 3](#example-3-implementing-a-scrollable-grid-with-grid-items-spanning-rows-and-columns). On the other hand, **onGetRectByIndex** can be used for grids where both **rowsTemplate** and **columnsTemplate** are set. It allows you to specify the position and size for the grid item at the specified index. For details about the usage, see [Example 1](#example-1-creating-a-fixed-row-and-column-grid-layout).

To improve the performance of **Grid** in scenarios such as jumps and column quantity changes, you are advised to use **GridLayoutOptions** whenever possible. Even if there are no special cross-row or cross-column nodes in **Grid**, performance during jumps can still be enhanced by using 'Grid(this.scroller, {regularSize: [1, 1]})'.  

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

<!--Table: 20%; 20%; 8%; 8%; 44%-->

| Name   | Type     | Read Only  | Optional| Description                   |
| ----- | ------- | ---- | --  | --------------------- |
| regularSize  | [number, number]  | No   | No| Number of rows and columns occupied by a grid item with regular size. The only supported value is **[1, 1]**, meaning that the grid item occupies one row and one column.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| irregularIndexes | number[] | No   | Yes| Size of **GridItem** at the specified index in **Grid**. The size is irregular. When **onGetIrregularSizeByIndex** is not set, the grid item specified in this parameter occupies an entire row of the grid that scrolls vertically or an entire column of the grid that scrolls horizontally.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onGetIrregularSizeByIndex | (index: number) => [number, number] | No   | Yes| Number of rows and columns occupied by the grid item with an irregular size. This parameter is used together with **irregularIndexes**. You can set the number of rows and columns occupied by the **GridItem** corresponding to the index specified in **irregularIndexes**. In versions earlier than API version 12, the vertical scrolling grid does not support grid items spanning multiple rows, and the horizontal scrolling grid does not support grid items spanning multiple columns.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| onGetRectByIndex<sup>11+</sup> | (index: number) => [number, number,number,number] | No | Yes| Position and size of the grid item with the specified index, in the format of [rowStart,columnStart,rowSpan,columnSpan],<br>where **rowStart** indicates the row start position, **columnStart** indicates the column start position,<br>**rowSpan** indicates the number of rows occupied by the grid item, and **columnSpan** indicates the number of columns occupied by the grid item. Their values are unitless.<br>The values of **rowStart** and **columnStart** are natural numbers greater than or equal to 0. If a negative value is set, the default value **0** is used.<br>The values of **rowSpan** and **columnSpan** are natural numbers greater than or equal to 1. If a decimal is set, it is rounded down. If the decimal set is less than 1, the value **1** is used.<br>**NOTE**<br>Case 1: If a grid item finds that the start position specified for it is already occupied, it searches for an available start position from left to right and from top to bottom, starting from position [0,0].<br>Case 2: If any space other than the start position specified for a grid item is occupied, the grid item is displayed within the available space left.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## Attributes

In addition to [universal attributes](ts-component-general-attributes.md) and [scrollable component common attributes](ts-container-scrollable-common.md#attributes), the following attributes are also supported.
> **NOTE**
>
> When the universal attributes [clip<sup>12+</sup>](ts-universal-attributes-sharp-clipping.md#clip12) and [clip<sup>18+</sup>](ts-universal-attributes-sharp-clipping.md#clip18) are used, the default values are **true**.
>
> After **padding** of **Grid** is set, if a child component is partially located in **Grid**'s content area and partially located in the padding area, it will be displayed. If the child component is entirely within the padding area, it will not be displayed. As shown in the following figure, **GridItem1** is displayed, but **GridItem2** is not displayed.
>
> ![GridPadding](figures/gridPadding.png)

### columnsTemplate

columnsTemplate(value: string)

Sets the number of columns, fixed column width, or minimum column width of the grid. If this attribute is not set, one column will be used.

For example, **&nbsp;'1fr&nbsp;1fr&nbsp;2fr'&nbsp;** indicates three columns, with the first column taking up 1/4 of the parent component's full width, the second column 1/4, and the third column 2/4.

**columnsTemplate('repeat(auto-fit, track-size)')**: The layout automatically calculates the number of columns and the actual column width, while adhering to the minimum column width specified with **track-size**.

**columnsTemplate('repeat(auto-fill, track-size)')**: The layout automatically calculates the number of columns based on the fixed column width specified with **track-size**.

**columnsTemplate('repeat(auto-stretch, track-size)')**: The layout uses **columnsGap** to define the minimum gap between columns and automatically calculates the number of columns and the actual gap size based on the fixed column width specified by **track-size**.

**repeat**, **auto-fit**, **auto-fill**, and **auto-stretch** are keywords. **track-size** indicates the column width, in the unit of px, vp (default), %, or any valid digit. The value must be greater than or equal to one valid column width.<br>
In auto-fit and auto-stretch modes, only a valid column width value is supported for **track-size**. Additionally, in auto-stretch mode, **track-size** only supports units such as px, vp, and valid numbers, but does not support percentage (%). The auto-fill mode supports one or more valid column widths, for example, columnsTemplate('repeat(auto-fill, 20)') or columnsTemplate('repeat(auto-fill, 20 80px)').

For details about the effect, see [Example 8](#example-8-using-adaptive-column-count-settings).

If this attribute is set to **'0fr'**, the column width is 0, and grid item in the column is not displayed. If this attribute is set to any other invalid value, the grid item is displayed as one column.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                              |
| ------ | ------ | ---- | ---------------------------------- |
| value  | string | Yes  | Number of columns or minimum column width of the grid.|

### columnsTemplate<sup>22+</sup>

columnsTemplate(value: string | ItemFillPolicy)

Number of columns in the current grid layout. If this attribute is not set, one column will be used.

When the value is of the string type, refer to [columnsTemplate(value: string)](#columnstemplate) for the usage.

When the value is of the **ItemFillPolicy** type, the number of columns is determined based on the [breakpoint type](../../../ui/arkts-layout-development-grid-layout.md#breakpoints) corresponding to the width of the **Grid** component.

For example, the **ItemFillPolicy.BREAKPOINT_DEFAULT** component displays two columns when the component width falls within the sm or smaller breakpoint range, three columns for the md breakpoint range, and five columns for the lg or larger breakpoint range, with each column being 1 fr.

**Atomic service API**: This API can be used in atomic services since API version 22.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                     |
| ------ | ---------------------------------------------------- | ---- | --------------------------------------------------------- |
| value  | string&nbsp;\|&nbsp;[ItemFillPolicy](./ts-types.md#itemfillpolicy22) | Yes   | Number of columns in the current grid layout. When **value** is of the string type, it indicates a fixed number of columns or the repeat function form; when **value** is of the ItemFillPolicy type, the number of columns is automatically determined based on the breakpoint. |

### rowsTemplate

rowsTemplate(value: string)

Sets the number of rows, fixed row height, or minimum row height of the grid. If this attribute is not set, one row will be used.

For example, **'1fr 1fr 2fr'** indicates three rows, with the first row taking up 1/4 of the parent component's full height, the second row 1/4, and the third row 2/4.

**rowsTemplate('repeat(auto-fit, track-size)')**: The layout automatically calculates the number of rows and the actual row height, while adhering to the minimum row height specified with **track-size**.

**rowsTemplate('repeat(auto-fill, track-size)')**: The layout automatically calculates the number of rows based on the fixed row height specified with **track-size**.

**rowsTemplate('repeat(auto-stretch, track-size)')**: The layout uses **rowsGap** to define the minimum gap between rows and automatically calculates the number of rows and the actual gap size based on the fixed row height specified with **track-size**.

**repeat**, **auto-fit**, **auto-fill**, and **auto-stretch** are keywords. **track-size** indicates the row height, in the unit of px, vp (default), %, or any valid digit. The value must be greater than or equal to one valid row height.<br>
In auto-fit and auto-stretch modes, only a valid row height value is supported for **track-size**. Additionally, in auto-stretch mode, **track-size** only supports units such as px, vp, and valid numbers, but does not support percentage (%). The auto-fill mode supports one or more valid row heights, for example, rowsTemplate('repeat(auto-fill, 20)') or rowsTemplate('repeat(auto-fill, 20 80px)').

If this attribute is set to **'0fr'**, the row height is 0, and grid item in the row is not displayed. If this attribute is set to any other invalid value, the grid item is displayed as one row.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                              |
| ------ | ------ | ---- | ---------------------------------- |
| value  | string | Yes  | Number of rows or minimum row height of the grid.|

>  **NOTE**
>
>  Depending on the settings of the **rowsTemplate** and **columnsTemplate** attributes, the **Grid** component supports the following layout modes:
>
>  1. **rowsTemplate** and **columnsTemplate** are both set
>
>  - The **Grid** component displays only elements in a fixed number of rows and columns and cannot be scrolled.
>  - In this mode, the following attributes do not take effect: **layoutDirection**, **maxCount**, **minCount**, and **cellLength**.
>  - If the width and height of a grid are not set, the grid adapts to the size of its parent component by default.
>  - The size of the grid rows and columns is the size of the grid content area minus the gap between rows and columns. It is allocated based on the proportion of each row and column.
>  - By default, the grid items fill the entire grid.
>
>  2. Either **rowsTemplate** or **columnsTemplate** is set
>
>  - The **Grid** component arranges elements in the specified direction and allows for scrolling to display excess elements.
>  - If **columnsTemplate** is set, the component scrolls vertically, the main axis runs vertically, and the cross axis runs horizontally.
>  - If **rowsTemplate** is set, the component scrolls horizontally, the main axis runs horizontally, and the cross axis runs vertically.
>  - In this mode, the following attributes do not take effect: **layoutDirection**, **maxCount**, **minCount**, and **cellLength**.
>  - The cross axis size of the grid is the cross axis size of the grid content area minus the gaps along the cross axis. It is allocated based on the proportion of each row and column.
>  - The main axis size of the grid is the maximum value of the main axis sizes of all grid items in the cross axis direction of the grid.
>  - In this mode, the size of **GridItem** in the cross-axis is the same as that of the grid. You can set **maxWidth** or **maxHeight** in [constraintSize](./ts-universal-attributes-size.md#constraintsize) to limit the size of **GridItem** in the cross axis to be less than that of the grid.
>
>  3. Neither **rowsTemplate** nor **columnsTemplate** is set
>
>  - The **Grid** component arranges elements in the direction specified by **layoutDirection**. The number of columns is jointly determined by the grid width, width of the first element, **minCount**, **maxCount**, and **columnsGap**.
>  - The number of rows is jointly determined by the grid height, height of the first element, **cellLength**, and **rowsGap**. Elements outside the determined range of rows and columns are not displayed and cannot be viewed through scrolling.
>  - In this mode, only the following attributes take effect: **layoutDirection**, **maxCount**, **minCount**, **cellLength**, **editMode**, **columnsGap**, and **rowsGap**.
>  - When **layoutDirection** is set to **Row**, child components are arranged from left to right. When a row is full, a new row will be added. If the remaining height is insufficient, no more elements will be laid out, and the whole content is centered at the top.
>  - When **layoutDirection** is set to **Column**, elements are arranged column by column from top to bottom. If the remaining height is insufficient, no more elements will be laid out, and the whole content is centered at the top.
>  - If there are no grid items in the grid, the width and height of the grid are set to 0.
>

### columnsGap

columnsGap(value: Length)

Sets the gap between columns. A value less than 0 evaluates to the default value.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                        | Mandatory| Description                        |
| ------ | ---------------------------- | ---- | ---------------------------- |
| value  | [Length](ts-types.md#length) | Yes   | Spacing between columns.<br/>Default value: 0<br/>Value range: [0, +∞). If a value less than 0 is set, the default value 0 is used. |

### rowsGap

rowsGap(value: Length)

Sets the gap between rows. A value less than 0 evaluates to the default value.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                        | Mandatory| Description                        |
| ------ | ---------------------------- | ---- | ---------------------------- |
| value  | [Length](ts-types.md#length) | Yes   | Spacing between rows.<br/>Default value: 0<br/>Value range: [0, +∞). If a value less than 0 is set, the default value 0 is used. |

### scrollBar

scrollBar(value: BarState)

Sets the scrollbar state.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                     | Mandatory| Description                                                        |
| ------ | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [BarState](ts-appendix-enums.md#barstate) | Yes  | Scrollbar state.<br>Default value: **BarState.Auto**<br>**NOTE**<br>In API version 9 and earlier versions, the default value is **BarState.Off**. Since API version 10, the default value is **BarState.Auto**.|

### scrollBarColor

scrollBarColor(value: Color | number | string)

Sets the scrollbar color.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description          |
| ------ | ------------------------------------------------------------ | ---- | -------------- |
| value  | [Color](ts-appendix-enums.md#color)&nbsp;\|&nbsp;number&nbsp;\|&nbsp;string | Yes  | Scrollbar color.<br>Default value: **'\#182431'** (40% opacity)<br>A number value indicates a HEX color in RGB or ARGB format, for example, **0xffffff**.<br>A string value indicates a color in RGB or ARGB format, for example, **'#ffffff'**.|

### scrollBarColor<sup>22+</sup>

scrollBarColor(color: Color | number | string | Resource)

Sets the scrollbar color. Compared with [scrollBarColor](#scrollbarcolor), the parameter name is changed to **color** and the Resource type is supported.

**Atomic service API**: This API can be used in atomic services since API version 22.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description          |
| ------ | ------------------------------------------------------------ | ---- | -------------- |
| color  | [Color](ts-appendix-enums.md#color)&nbsp;\|&nbsp;number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | Yes  | Scrollbar color.<br>Default value: **'\#182431'** (40% opacity)<br>A number value indicates a HEX color in RGB or ARGB format, for example, **0xffffff**. A string value indicates a color in RGB or ARGB format, for example, **'#ffffff'**.|

### scrollBarWidth

scrollBarWidth(value: number | string)

Sets the width of the scrollbar. Percentage values are not supported. After the width is set, the scrollbar width in both the normal state and the pressed state is the set value. If the scrollbar width exceeds the visible size of the **Grid** component along the main axis, the scrollbar width changes to the default value of 4 vp.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description                                     |
| ------ | -------------------------- | ---- | ----------------------------------------- |
| value  | number&nbsp;\|&nbsp;string | Yes   | Width of the scrollbar.<br/>Default value: **4**<br/>Unit: vp<br/>Value range: [0, +∞). If the value is less than 0, the default value is used. If the value is 0, the scrollbar is not displayed. |

### scrollBarWidth

scrollBarWidth(value: number | string | Resource)

Sets the width of the scrollbar. Percentage values are not supported. After the width is set, the scrollbar width in both the normal state and the pressed state is the set value. If the scrollbar width exceeds the visible size of the **Grid** component along the main axis, the scrollbar width changes to the default value of 4 vp. Resource type is supported.

If this attribute is not set, the scrollbar width is 4 vp.

**Since:** 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                      | Mandatory| Description                                     |
| ------ | -------------------------- | ---- | ----------------------------------------- |
| value  | number&nbsp;\|&nbsp;string \| [Resource](ts-types.md#resource) | Yes  | Scrollbar width.<br>Unit: vp<br>The value range is [0, +∞). If this parameter is set to a value less than 0, **4vp** is used. The value **0** means not to show the scrollbar.|

### cachedCount

cachedCount(value: number)

Sets the number of grid rows/columns to be preloaded on both sides along the main axis. This attribute takes effect only in [LazyForEach](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md) and [Repeat](../../../ui/rendering-control/arkts-new-rendering-control-repeat.md) with [virtualScroll](ts-rendering-control-repeat.md#virtualscroll) enabled.<!--Del-->For details, see [Minimizing White Blocks During Swiping](../../../performance/arkts-performance-improvement-recommendation.md#minimizing-white-blocks-during-swiping).<!--DelEnd-->

After caching is set, **cachedCount** grid rows/columns are preloaded on both sides of the display area of the **Grid** component along the main axis. During vertical scrolling, **cachedCount** rows are preloaded on the top and bottom sides respectively. During horizontal scrolling, **cachedCount** columns are preloaded on the left and right sides respectively.

[LazyForEach](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md) and [Repeat](../../../ui/rendering-control/arkts-new-rendering-control-repeat.md) with [virtualScroll](ts-rendering-control-repeat.md#virtualscroll) enabled will release **GridItem** components that are outside the display and cache range.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | Yes  | Number of grid items to be cached (preloaded).<br>Default value: the number of rows visible on the screen for vertical scrolling, or the number of columns visible on the screen for horizontal scrolling. The maximum value is 16.<br>Value range: [0, +∞).<br>Values less than 0 are treated as **1**.<br>When **value** is updated using a state variable, the **Grid** component does not trigger a layout update. The number of cached nodes is updated only during the next layout.|

### cachedCount<sup>14+</sup>

cachedCount(count: number, show: boolean)

Sets the number of grid rows/columns to be preloaded on both sides along the main axis, and configures whether to display the preloaded nodes. This attribute takes effect only in [LazyForEach](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md) and [Repeat](../../../ui/rendering-control/arkts-new-rendering-control-repeat.md) with [virtualScroll](ts-rendering-control-repeat.md#virtualscroll) enabled.

After caching is set, **cachedCount** grid rows/columns are preloaded on both sides of the display area of the **Grid** component along the main axis. During vertical scrolling, **cachedCount** rows are preloaded on the top and bottom sides respectively. During horizontal scrolling, **cachedCount** columns are preloaded on the left and right sides respectively. The preloaded nodes can be displayed together with the [clip](ts-universal-attributes-sharp-clipping.md#clip12) or [clipContent](ts-container-scrollable-common.md#clipcontent14) attribute.

**Atomic service API**: This API can be used in atomic services since API version 14.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| count  | number | Yes  | Number of grid items to be cached (preloaded).<br>Default value: the number of rows visible on the screen for vertical scrolling, or the number of columns visible on the screen for horizontal scrolling. The maximum value is 16.<br>Value range: [0, +∞).<br>Values less than 0 are treated as **1**.<br>When the count value is updated using the state variable, the **Grid** component does not trigger a layout update. The number of cached nodes is updated only during the next layout.|
| show  | boolean | Yes  | Whether to display the preloaded nodes. If this parameter is set to **true**, the preloaded **GridItem** is displayed. If this parameter is set to **false**, the preloaded **GridItem** is not displayed.<br> Default value: **false**|

### editMode<sup>8+</sup>

editMode(value: boolean)

Sets whether to enable edit mode. In edit mode, the user can drag the [grid items](ts-container-griditem.md) in the **Grid** component.

> **NOTE**
>
> This attribute takes effect only when neither **rowsTemplate** nor **columnsTemplate** is set.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| value  | boolean | Yes  | Whether to enable edit mode. If this parameter is set to **true**, the **Grid** component is in edit mode. If this parameter is set to **false**, the **Grid** component is not in edit mode.<br>Default value: **false**|

### layoutDirection<sup>8+</sup>

layoutDirection(value: GridDirection)

Sets the main axis layout direction of the grid.

> **NOTE**
>
> This attribute takes effect only when neither **rowsTemplate** nor **columnsTemplate** is set.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                    | Mandatory| Description                                          |
| ------ | ---------------------------------------- | ---- | ---------------------------------------------- |
| value  | [GridDirection](#griddirection8) | Yes  | Main axis layout direction of the grid.<br>Default value: **GridDirection.Row**|

### maxCount<sup>8+</sup>

maxCount(value: number)

Sets the maximum number of rows or columns that can be displayed. A value less than 1 evaluates to the default value.

> **NOTE**
>
> This attribute takes effect only when neither **rowsTemplate** nor **columnsTemplate** is set.

When **layoutDirection** is **Row** or **RowReverse**, the value indicates the maximum number of columns that can be displayed.

When **layoutDirection** is **Column** or **ColumnReverse**, the value indicates the maximum number of rows that can be displayed.

If the value of **maxCount** is smaller than that of **minCount**, the default values of **maxCount** and **minCount** are used.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                         |
| ------ | ------ | ---- | --------------------------------------------- |
| value  | number | Yes   | Maximum number of rows or columns that can be displayed.<br/>Default value: **Infinity**<br/>Value range: [1, +∞). If the value is set to less than 1, the default value **Infinity** is used. |

### minCount<sup>8+</sup>

minCount(value: number)

Sets the minimum number of rows or columns that can be displayed. A value less than 1 evaluates to the default value.

> **NOTE**
>
> This attribute takes effect only when neither **rowsTemplate** nor **columnsTemplate** is set.

When **layoutDirection** is **Row** or **RowReverse**, the value indicates the minimum number of columns that can be displayed.

When **layoutDirection** is **Column** or **ColumnReverse**, the value indicates the minimum number of rows that can be displayed.

If the value of **minCount** is greater than that of **maxCount**, both **minCount** and **maxCount** are treated as using their default values.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| value  | number | Mandatory   | Minimum number of rows or columns that can be displayed.<br/>Default value: **1**<br/>Value range: [1, +∞). If a value less than 1 is set, the default value **1** is used. |

### cellLength<sup>8+</sup>

cellLength(value: number)

Sets the height per row or width per column.

> **NOTE**
>
> This attribute takes effect only when neither **rowsTemplate** nor **columnsTemplate** is set.

When **layoutDirection** is **Row** or **RowReverse**, the value indicates the height per row.

When **layoutDirection** is **Column** or **ColumnReverse**, the value indicates the width per column.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                   |
| ------ | ------ | ---- | ------------------------------------------------------- |
| value  | number | Yes  | Height of a row or width of a column.<br/>Default value: when **layoutDirection** is **Row**/**RowReverse**, the height of the first **GridItem**; when **layoutDirection** is **Column**/**ColumnReverse**, the width of the first **GridItem**.<br/>Unit: vp <br/>Value range: (0, +∞). If the value is set to a value less than or equal to 0, the default value is used. |

### multiSelectable<sup>8+</sup>

multiSelectable(value: boolean)

Sets whether to enable multiselect. After multiselect is enabled, you can use **GridItem**'s **selected** attribute and **onSelect** event to obtain the selection state of **GridItem**. Additionally, you can set the selected state style of **GridItem** using [Polymorphic Style](./ts-universal-attributes-polymorphic-style.md) (by default, **GridItem** has no selected state style).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether to enable multiselect.<br>Default value: **false**<br>**false**: Multiselect is disabled. **true**: Multiselect is disabled.|

### supportAnimation<sup>8+</sup>

supportAnimation(value: boolean)

Sets whether to enable animation. Currently, the grid item drag animation is supported. Animation is supported only in scrolling mode (only **rowsTemplate** or **columnsTemplate** is set).<br>Drag animations are only supported in grids with fixed size rules; scenarios involving spanning across rows or columns are not supported.

For details about the **supportAnimation** animation effect, see [Example 5: Implementing Dragging in a Grid](#example-5-implementing-dragging-in-a-grid). For other animation effects, customize the drag effect.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                            |
| ------ | ------- | ---- | -------------------------------- |
| value  | boolean | Yes  | Whether to enable animation. If this parameter is set to **true**, the drag animation of **GridItem** is supported. If this parameter is set to **false**, the drag animation of **GridItem** is not supported.<br>Default value: **false**|

### edgeEffect<sup>10+</sup>

edgeEffect(value: EdgeEffect, options?: EdgeEffectOptions)

Sets the effect used when the scroll boundary is reached.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name               | Type                                                        | Mandatory| Description                                                        |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value                 | [EdgeEffect](ts-appendix-enums.md#edgeeffect)                | Yes  | Effect used when the scroll boundary is reached. The spring and shadow effects are supported.<br>Default value: **EdgeEffect.None**|
| options<sup>11+</sup> | [EdgeEffectOptions](ts-container-scrollable-common.md#edgeeffectoptions11) | No  | Whether to enable the scroll effect when the component content is smaller than the component itself. The value **{ alwaysEnabled: true }** means to enable the scroll effect, and **{ alwaysEnabled: false }** means the opposite.<br>Default value: **{ alwaysEnabled: false }**|

### enableScrollInteraction<sup>10+</sup>

enableScrollInteraction(value: boolean)

Sets whether to support the scrolling gesture.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                               |
| ------ | ------- | ---- | ----------------------------------- |
| value  | boolean | Yes  | Whether to support scroll gestures. With the value **true**, scrolling via finger or mouse is enabled. With the value **false**, scrolling via finger or mouse is disabled, but this does not affect the scrolling APIs of the [Scroller](ts-container-scroll.md#scroller).<br>Default value: **true**|

> **NOTE**
>
> The component cannot be scrolled through mouse press-and-drag operations.

### nestedScroll<sup>10+</sup>

nestedScroll(value: NestedScrollOptions)

Sets the nested scrolling options. Sets the nested scrolling modes for both forward and backward directions to achieve scrolling linkage with the parent component. When the component content is smaller than the component itself and **options** of [edgeEffect](#edgeeffect10) is set to **{ alwaysEnabled: false }**, the component's own swipe gesture will not be triggered, and the nested scroll property will not take effect. If its parent scrollable component has a swipe gesture, this swipe gesture will be triggered instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description          |
| ------ | ------------------------------------------------------------ | ---- | -------------- |
| value  | [NestedScrollOptions](ts-container-scrollable-common.md#nestedscrolloptions10) | Yes   | Nested scroll options, used to set the nested scrolling linkage behavior between the **Grid** component and its parent component. |

### friction<sup>10+</sup>

friction(value: number | Resource)

Sets the friction coefficient. It takes effect when the scroll area is swiped, and affects only the inertial scrolling process. It has an indirect impact on the chained effect during inertial scrolling.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                       |
| ------ | ---------------------------------------------------- | ---- | ----------------------------------------------------------- |
| value  | number&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | Yes  | Friction coefficient.<br>Default value: **0.9** for wearable devices and **0.6** for non-wearable devices<br>Since API version 11, the default value for non-wearable devices is **0.7**.<br>Since API version 12, the default value for non-wearable devices is **0.75**.<br>Value range: (0, +∞). If this parameter is set to a value less than or equal to 0, the default value is used.|

### alignItems<sup>12+</sup>

alignItems(alignment: Optional\<GridItemAlignment\>)

Sets the alignment mode of grid items in the grid. For details about the usage, see [Example 9](#example-9-setting-grid-item-heights-based-on-the-tallest-item-in-the-current-row).

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type  | Mandatory| Description                           |
| ---------- | ------ | ---- | ------------------------------- |
| alignment | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[GridItemAlignment](#griditemalignment12)\> | Yes  | Alignment mode of grid items in the grid.<br>Default value: **GridItemAlignment.DEFAULT**|

### focusWrapMode<sup>20+</sup>

focusWrapMode(mode: Optional\<FocusWrapMode\>)

Sets the focus wrap mode for cross-axis arrow keys.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| mode   | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[FocusWrapMode](ts-appendix-enums.md#focuswrapmode20)\> | Yes  | Focus wrap mode for cross-axis arrow keys.<br>Default value: **FocusWrapMode.DEFAULT**<br>**NOTE**<br>Abnormal values are treated as the default value, meaning that cross-axis arrow keys cannot wrap.|

### syncLoad<sup>20+</sup>

syncLoad(enable: boolean)

Sets whether to synchronously load all child components in the grid.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| enable   | boolean | Yes  | Whether to synchronously load all child components in the grid.<br> **true**: yes; **false**: no Default value: **true**<br> **NOTE**<br>When this parameter is set to **false**, in the first display or **scrollToIndex** jumps without animation, if the time consumed by the frame layout exceeds 50 ms, the child components that have not been laid out in the grid are delayed to the next frame for layout.|

### supportEmptyBranchInLazyLoading<sup>23+</sup>

supportEmptyBranchInLazyLoading(supported: boolean | undefined)

Sets whether the current **Grid** component supports the use of the if/else rendering syntax in **LazyForEach** or **Repeat** to generate an empty branch node that contains no child component. If this attribute is not set, empty branch nodes are not supported. This attribute cannot be updated after being set. Therefore, you cannot switch between the behavior of supporting empty branches and the behavior of not supporting empty branches after setting this attribute.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 23.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                              |
| ------ | ------ | ---- | -------------------------------------------------- |
| supported  | boolean \| undefined | Yes   | Whether the current **Grid** component supports using the [if/else](../../../ui/rendering-control/arkts-rendering-control-ifelse.md) rendering control syntax in [LazyForEach](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md) or [Repeat](../../../ui/rendering-control/arkts-new-rendering-control-repeat.md) to generate an empty branch node that contains no child nodes.<br/>The value **true** indicates that empty branch nodes are supported, and **false** indicates that empty branch nodes are not supported.<br/>If the value is **undefined**, it is processed as **false**. |

### editModeOptions<sup>23+</sup>

editModeOptions(options?: EditModeOptions)

Sets the options of the edit mode.

**Atomic service API**: This API can be used in atomic services since API version 23.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| options   | [EditModeOptions](ts-container-scrollable-common.md#editmodeoptions23) | No   | Edit mode options, used to configure behaviors such as the multi-select gathering animation, preview badge, multi-select style, and two-finger swipe multi-select in Grid edit mode. Pass this parameter when the preceding behaviors need to be adjusted; if it is not passed, each option uses the default value in the EditModeOptions object description. |

### enableEditMode

enableEditMode(enabled: boolean | undefined)

Sets whether to enable the edit mode for the **Grid** component. After the edit mode is enabled, you can swipe to select multiple [GridItem](ts-container-griditem.md) components in the **Grid** component. If this API is not called, the edit mode is not enabled.

**Since:** 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| enabled  | boolean \| undefined | Yes   | Whether to enable the editing mode. This parameter supports two-way binding with a variable through [!!](../../../ui/state-management/arkts-new-binding.md). When set to **true**, the editing mode is enabled and multiple items can be selected by swiping. When set to **false** or **undefined**, the editing mode is disabled and multiple items cannot be selected by swiping. |

## GridItemAlignment<sup>12+</sup>

Enumerates the alignment modes of grid items.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Value| Description                                |
| ------ |------| -------------------------------------- |
| DEFAULT  |  0  | Use the default alignment mode of the grid.|
| STRETCH |  1  | Use the height of the tallest grid item in a row as the height for all other grid items in that row.|

> **NOTE**
>
> 1. The **STRETCH** option only takes effect in scrollable grids.<br>
> 2. The **STRETCH** option takes effect only if each grid item in a row is of a regular size (occupying only one row and one column). It is not effective in scenarios where there are grid items spanning across rows or columns.<br>
> 3. When **STRETCH** is used, only grid items without a set height will adopt the height of the tallest grid item in the current row; the height of grid items with a set height will remain unchanged.<br>
> 4. When **STRETCH** is used, the grid undergoes an additional layout process, which may incur additional performance overhead.

## GridDirection<sup>8+</sup>

Enumerates the main axis layout directions.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  |Value| Description                                |
| ------ |------| -------------------------------------- |
| Row  |  0  | Horizontal layout, where the child components are arranged from left to right as the main axis runs along the rows.|
| Column |  1  | Vertical layout, where the child components are arranged from top to bottom as the main axis runs down the columns.|
| RowReverse    |  2  | Reverse horizontal layout, where the child components are arranged from right to left as the main axis runs along the rows.|
| ColumnReverse   |  3  | Reverse vertical layout, where the child components are arranged from bottom up as the main axis runs down the columns.|

## Events

In addition to [universal events](ts-component-general-events.md) and [scrollable component common events](ts-container-scrollable-common.md#events), the following events are also supported.

### onScrollIndex

onScrollIndex(event: (first: number, last: number) => void)

Triggered when the first or last item displayed in the grid changes, that is, when the index of either the first or last item changes. It is triggered once when the grid is initialized.  

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name            | Type  | Mandatory| Description                            |
| ------------------ | ------ | ---- | -------------------------------- |
| first              | number | Yes  | Index of the first item of the grid.|
| last<sup>10+</sup> | number | Yes | Index of the end position of the currently displayed grid.<br/>**Model restriction:** This API can be used only in the stage model. |

### onItemDragStart<sup>8+</sup>

onItemDragStart(event: OnItemDragStartCallback)

Triggered when dragging of a **GridItem** starts.

This event is triggered when the user long presses a grid item.

Drag gesture recognition is also initiated by a long press, and the event processing mechanism prioritizes child component events. Therefore, when the grid item is bound to the [LongPressGesture](ts-basic-gestures-longpressgesture.md#longpressgesture-1), it cannot be dragged. In light of this, if both long press and drag operations are required on the grid item, you can use the universal drag event.

The dragged and lifted **GridItem** can move within the app window. To restrict the movement range, you can implement it through a custom gesture. For details, see [Example 16: Customizing the Drag Effect for GridItem](#example-16-customizing-the-drag-effect-for-griditem).

Automatic scrolling when dragging to the edge of the **Grid** is not supported. You can use the universal drag to implement it. For details, see [Example 17: Dragging Grid Items with Drag Events](#example-17-dragging-grid-items-with-drag-events). Since API version 26.0.0, you can use the [onMove](./ts-universal-attributes-drag-sorting.md#onmove) API of [ForEach](../../../ui/rendering-control/arkts-rendering-control-foreach.md), [LazyForEach](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md), and [Repeat](../../../ui/rendering-control/arkts-new-rendering-control-repeat.md) to implement this effect. For details, see [Example 22 (Dragging with OnMove)](#example-22-dragging-with-onmove). It also supports dragging of **GridItem** that spans rows and columns, but note that the **Grid** must be scrollable.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                 | Mandatory| Description                  |
| --------- | ------------------------------------- | ---- | ---------------------- |
| event     | [OnItemDragStartCallback](ts-container-scrollable-common.md#onitemdragstartcallback23) | Yes   | Callback triggered when the drag of a **GridItem** starts.<br>In API version 22 and earlier versions, the type of this parameter is **(event: ItemDragInfo, itemIndex: number) => (() => any) \| void**. For the meanings of the **event** and **itemIndex** parameters, see [OnItemDragStartCallback](ts-container-scrollable-common.md#onitemdragstartcallback23). |

### onItemDragEnter<sup>8+</sup>

onItemDragEnter(event: (event: ItemDragInfo) => void)

Triggered when a dragged item enters the range of a **GridItem**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                 | Mandatory| Description          |
| ------ | ------------------------------------- | ---- | -------------- |
| event  | [ItemDragInfo](ts-container-scrollable-common.md#itemdraginfo) | Yes  | Information about the drag point.|

### onItemDragMove<sup>8+</sup>

onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void)

Triggered when a dragged item moves within the range of a **GridItem**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                 | Mandatory| Description          |
| ----------- | ------------------------------------- | ---- | -------------- |
| event       | [ItemDragInfo](ts-container-scrollable-common.md#itemdraginfo) | Yes  | Information about the drag point.|
| itemIndex   | number                                | Yes   | Drag start position, which is the index of the dragged **GridItem** in the **Grid**. |
| insertIndex | number                                | Yes   | Current drag insertion position, which is the target insertion index of the **GridItem** during dragging. |

### onItemDragLeave<sup>8+</sup>

onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void)

Triggered when a dragged item leaves a **GridItem**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                                 | Mandatory| Description                      |
| --------- | ------------------------------------- | ---- | -------------------------- |
| event     | [ItemDragInfo](ts-container-scrollable-common.md#itemdraginfo) | Yes  | Information about the drag point.            |
| itemIndex | number                                | Yes   | Index of the **GridItem** from which the drag exits. |

### onItemDrop<sup>8+</sup>

onItemDrop(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void)

The **GridItem** bound with this event can serve as a drop target. This event is triggered when the **GridItem** stops being dragged.

When the drop position is within the **GridItem**, **isSuccess** returns **true**; when it is outside the **GridItem**, **isSuccess** returns **false**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                 | Mandatory| Description          |
| ----------- | ------------------------------------- | ---- | -------------- |
| event       | [ItemDragInfo](ts-container-scrollable-common.md#itemdraginfo) | Yes  | Information about the drag point.|
| itemIndex   | number                                | Yes  | Initial position of the dragged item.|
| insertIndex | number                                | Yes  | Position to which the dragged item is dropped.|
| isSuccess   | boolean                               | Yes   | Whether the drop position is within the **GridItem** for which **onItemDrop** is set.<br/>The value **true** indicates that the drop position is within the **GridItem** for which **onItemDrop** is set; the value **false** indicates that the drop position is outside the **GridItem** for which **onItemDrop** is set.  |

### onScrollBarUpdate<sup>10+</sup>

onScrollBarUpdate(event: (index: number, offset: number) => ComputedBarAttribute)

Triggered at the end of each frame layout in the grid. You can use the callback to set the position and length of the scrollbar.

This API is intended solely for setting the scroll position of the grid. Avoid implementing service logic within this API.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| index  | number | Yes  | Index of the first item of the grid.                            |
| offset | number | Yes  | Offset of the displayed first item relative to the start position of the grid, in vp.|

**Return value**

| Type                                                 | Description                |
| ----------------------------------------------------- | -------------------- |
| [ComputedBarAttribute](#computedbarattribute10) | Position and length of the scrollbar.|

### onReachStart<sup>10+</sup>

onReachStart(event: () => void)

Triggered when the grid reaches the start position.

This event is triggered once when the **Grid** is initialized and once when the **Grid** scrolls to the start position. When the edge effect of the **Grid** is a spring effect, this event is triggered once when the swipe passes the start position and once again when the rebound returns to the start position.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------|
| event | () => void | Yes| Callback triggered when the grid reaches the start position.|

### onReachEnd<sup>10+</sup>

onReachEnd(event: () => void)

Triggered when the grid reaches the end position. It is triggered when the grid content does not fill one screen and the end of the last child component is within the **Grid**.

When the edge effect of the **Grid** is a spring effect, this event is triggered once when the swipe passes the end position and once again when the rebound returns to the end position.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------|
| event | () => void | Yes| Callback triggered when the grid reaches the end position.|

### onScrollFrameBegin<sup>10+</sup>

onScrollFrameBegin(event: OnScrollFrameBeginCallback)

When this API is called back, the event parameter passes the scroll offset that is about to occur. The event processing function can calculate the actually required scroll offset based on the application scenario and return it as the return value. The grid will then scroll according to this returned actual scroll offset.

This event is triggered when either of the following conditions is met:

1. Scrolling is initiated by user interaction (for example, finger swipe, keyboard, or mouse operation).

2. The **Grid** component scrolls by inertia.

3. Call the [fling](ts-container-scroll.md#fling12) API to trigger scrolling.

This event is not triggered in the following scenarios:

1. A scroll control API other than [fling](ts-container-scroll.md#fling12) is called.

2. The out-of-bounds bounce effect is active.

3. The scrollbar is dragged.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                   | Mandatory| Description                      |
| ------ | ------------------------------------------------------- | ---- | -------------------------- |
| event | [OnScrollFrameBeginCallback](ts-container-scroll.md#onscrollframebegincallback18)   | Yes  | Callback triggered when each frame scrolling starts.|

### onScrollStart<sup>10+</sup>

onScrollStart(event: () => void)

Triggered when the grid starts scrolling initiated by the user's finger dragging the grid or its scrollbar. This event is also triggered when the animation contained in the scrolling triggered by [Scroller](ts-container-scroll.md#scroller) starts.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------|
| event | () => void | Yes| Callback invoked when the grid starts scrolling.|

### onScrollStop<sup>10+</sup>

onScrollStop(event: () => void)

Triggered when the grid stops scrolling after the user's finger leaves the screen. This event is also triggered when the animation contained in the scrolling triggered by [Scroller](ts-container-scroll.md#scroller) stops.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------|
| event | () => void | Yes| Callback when the grid stops scrolling.|

### onScroll<sup>(deprecated)</sup>

onScroll(event: (scrollOffset: number, scrollState: [ScrollState](ts-container-list.md#scrollstate)) => void) 

Triggered when the grid scrolls.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 12. You are advised to use [onDidScroll](ts-container-scrollable-common.md#ondidscroll12) instead.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------|
| scrollOffset | number | Yes| Offset relative to the previous frame. The offset is positive when the **Grid** component is scrolled up and negative when it is scrolled down.<br>Unit: vp|
| scrollState | [ScrollState](ts-container-list.md#scrollstate) | Yes| Current scroll state.|

### onEditModeChange

onEditModeChange(callback: Callback\<boolean\> | undefined)

Triggered when the edit mode state of [enableEditMode](#enableeditmode) changes. This API uses an asynchronous callback to return the result.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type   | Mandatory | Description                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| callback  | [Callback](ts-types.md#callback12)\<boolean\> \| undefined | Yes   | Callback invoked when the edit mode state changes. The callback parameter is of the boolean type. The value **true** indicates entering the edit mode, and **false** indicates exiting the edit mode.<br>When **undefined** is passed in, the callback is canceled. |

## ComputedBarAttribute<sup>10+</sup>

Provides information about the position and length of the scrollbar.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type        | Read Only| Optional|   Description        |
| ----------- | ------------ | ---- | ---- | ---------- |
| totalOffset | number | No| No|  Total offset of the grid content relative to the display area, in px.   |
| totalLength   | number | No| No|  Total length of the grid content, in px.   |

## UIGridEvent<sup>19+</sup>

Represents the return value of the [getEvent('Grid')](../js-apis-arkui-frameNode.md#geteventgrid19) method in **frameNode**, which can be used to set scroll events for a **Grid** node.

**UIGridEvent** inherits from [UIScrollableCommonEvent](./ts-container-scrollable-common.md#uiscrollablecommonevent19).

### setOnWillScroll<sup>19+</sup>

setOnWillScroll(callback:  OnWillScrollCallback | undefined): void

Sets the callback for the [onWillScroll](./ts-container-scrollable-common.md#onwillscroll12) event.

If the input parameter is **undefined**, the event callback is reset.

**Atomic service API**: This API can be used in atomic services since API version 19.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [OnWillScrollCallback](./ts-container-scrollable-common.md#onwillscrollcallback12)&nbsp;\|&nbsp;undefined | Yes   | Callback for the onWillScroll event. When undefined is passed in, the event callback is reset. |

### setOnDidScroll<sup>19+</sup>

setOnDidScroll(callback: OnScrollCallback | undefined): void

Sets the callback for the [onDidScroll](./ts-container-scrollable-common.md#ondidscroll12) event.

If the input parameter is **undefined**, the event callback is reset.

**Atomic service API**: This API can be used in atomic services since API version 19.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [OnScrollCallback](./ts-container-scrollable-common.md#onscrollcallback12)&nbsp;\|&nbsp;undefined | Yes   | Callback for the onDidScroll event. When undefined is passed in, the event callback is reset. |

### setOnScrollIndex<sup>19+</sup>

setOnScrollIndex(callback: OnGridScrollIndexCallback | undefined): void

Sets the callback of the [onScrollIndex](#onscrollindex) event.

If the input parameter is **undefined**, the event callback is reset.

**Atomic service API**: This API can be used in atomic services since API version 19.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| callback  | [OnGridScrollIndexCallback](#ongridscrollindexcallback19)&nbsp;\|&nbsp;undefined | Yes   | Callback for the onScrollIndex event. When undefined is passed in, the event callback is reset. |

## OnGridScrollIndexCallback<sup>19+</sup>

type OnGridScrollIndexCallback = (first: number, last: number) => void

Represents a callback for item changes in the visible area of the **Grid** component.

**Atomic service API**: This API can be used in atomic services since API version 19.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------|
| first | number | Yes| Index of the first item of the **Grid** component.|
| last | number | Yes| Index of the last item of the **Grid** component.|

## Example

### Example 1: Creating a Fixed Row and Column Grid Layout

You can use the **onGetRectByIndex** function in the [GridLayoutOptions](#gridlayoutoptions10) to specify the position and size of a grid item.

```ts
// xxx.ets
@Entry
@Component
struct GridExample {
  @State numbers1: string[] = ['0', '1', '2', '3', '4'];
  @State numbers2: string[] = ['0', '1', '2', '3', '4', '5'];
  layoutOptions3: GridLayoutOptions = {
    regularSize: [1, 1],
    onGetRectByIndex: (index: number) => {
      if (index == 0) {
        return [0, 0, 1, 1];
      } else if (index == 1) {
        return [0, 1, 2, 2];
      } else if (index == 2) {
        return [0, 3, 3, 3];
      } else if (index == 3) {
        return [3, 0, 3, 3];
      } else if (index == 4) {
        return [4, 3, 2, 2];
      } else {
        return [5, 5, 1, 1];
      }
    }
  };

  build() {
    Column({ space: 5 }) {
      Grid() {
        ForEach(this.numbers1, (day: string) => {
          ForEach(this.numbers1, (day: string) => {
            GridItem() {
              Text(day)
                .fontSize(16)
                .backgroundColor(0xF9CF93)
                .width('100%')
                .height('100%')
                .textAlign(TextAlign.Center)
            }
          }, (day: string) => day)
        }, (day: string) => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)

      Text('Usage of GridLayoutOptions: onGetRectByIndex.').fontColor(0x000000).fontSize(14).width('90%')

      Grid(undefined, this.layoutOptions3) {
        ForEach(this.numbers2, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height('100%')
              .textAlign(TextAlign.Center)
          }
          .height('100%')
          .width('100%')
        }, (day: string) => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

<!--Del--> <!--DelEnd-->

### Example 2: Implementing a Scrollable Grid with Scroll Events

This example shows a scrollable grid with all its scrolling attributes and events specified.

**GridDataSource** implements the **LazyForEach** data source API [IDataSource](ts-rendering-control-lazyforeach.md#idatasource), which is used to provide child components for **Grid** through **LazyForEach**.

<!--code_no_check-->

```ts
// GridDataSource.ets
export class GridDataSource implements IDataSource {
  private list: string[] = [];
  private listeners: DataChangeListener[] = [];

  constructor(list: string[]) {
    this.list = list;
  }

  totalCount(): number {
    return this.list.length;
  }

  getData(index: number): string {
    return this.list[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  // Notify the controller that the data position has changed.
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    })
  }
  
  // Reload all data.
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  // Exchange element positions.
  public swapItem(from: number, to: number): void {
    let temp: string = this.list[from];
    this.list[from] = this.list[to];
    this.list[to] = temp;
    this.notifyDataReload()
  }
}
```

<!--code_no_check-->

```ts
// xxx.ets
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource([]);
  scroller: Scroller = new Scroller();
  @State gridPosition: number = 0; // 0 indicates scrolling to the top of the grid, 1 indicates scrolling to the center, and 2 indicates scrolling to the bottom.

  aboutToAppear() {
    let list: string[] = [];
    for (let i = 0; i < 5; i++) {
      for (let j = 0; j < 5; j++) {
        list.push(j.toString());
      }
    }
    this.numbers = new GridDataSource(list);
  }

  build() {
    Column({ space: 5 }) {
      Text('Grid').fontColor(0x000000).fontSize(16).width('90%')
      Grid(this.scroller) {
        LazyForEach(this.numbers, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height(80)
              .textAlign(TextAlign.Center)
          }
        }, (index: number) => index.toString())
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .friction(0.6)
      .enableScrollInteraction(true)
      .supportAnimation(false)
      .multiSelectable(false)
      .edgeEffect(EdgeEffect.Spring)
      .scrollBar(BarState.On)
      .scrollBarColor(Color.Grey)
      .scrollBarWidth(4)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
      .onScrollIndex((first: number, last: number) => {
        console.info(first.toString());
        console.info(last.toString());
      })
      .onScrollBarUpdate((index: number, offset: number) => {
        console.info('XXX' + 'Grid onScrollBarUpdate,index : ' + index.toString() + ',offset' + offset.toString());
        return { totalOffset: (index / 5) * (80 + 10) - offset, totalLength: 80 * 5 + 10 * 4 };
      })  // The sample code applies only to the current data source. If the data source changes, modify the code or delete this attribute.
      .onDidScroll((scrollOffset: number, scrollState: ScrollState) => {
        console.info(scrollOffset.toString());
        console.info(scrollState.toString());
      })
      .onScrollStart(() => {
        console.info('XXX' + 'Grid onScrollStart');
      })
      .onScrollStop(() => {
        console.info('XXX' + 'Grid onScrollStop');
      })
      .onReachStart(() => {
        this.gridPosition = 0;
        console.info('XXX' + 'Grid onReachStart');
      })
      .onReachEnd(() => {
        this.gridPosition = 2;
        console.info('XXX' + 'Grid onReachEnd');
      })

      Button('next page')
        .onClick(() => {// Click to go to the next page.
          this.scroller.scrollPage({ next: true });
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

![scrollerExample2](figures/scrollerExample2.gif)

### Example 3: Implementing a Scrollable Grid with Grid Items Spanning Rows and Columns

[GridLayoutOptions](#gridlayoutoptions10): irregularIndexes and onGetIrregularSizeByIndex.

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
// xxx.ets
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource([]);
  scroller: Scroller = new Scroller();
  layoutOptions1: GridLayoutOptions = {
    regularSize: [1, 1],        // Only [1, 1] is supported.
    irregularIndexes: [0, 6],   // The grid item whose indexes are 0 and 6 occupies one row.
  };

  layoutOptions2: GridLayoutOptions = {
    regularSize: [1, 1],
    irregularIndexes: [0, 7],   // The number of columns occupied by the grid item whose indexes are 0 and 7 is specified by onGetIrregularSizeByIndex.
    onGetIrregularSizeByIndex: (index: number) => {
      if (index === 0) {
        return [1, 5];
      }
      return [1, index % 6 + 1];
    }
  };

  aboutToAppear() {
    let list: string[] = [];
    for (let i = 0; i < 5; i++) {
      for (let j = 0; j < 5; j++) {
        list.push(j.toString());
      }
    }
    this.numbers = new GridDataSource(list);
  }

  build() {
    Column({ space: 5 }) {
      Text('Grid1').fontColor(0x000000).fontSize(16).width('90%')
      Grid(this.scroller, this.layoutOptions1) {
        LazyForEach(this.numbers, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height(80)
              .textAlign(TextAlign.Center)
          }.selectable(false)
        }, (index: number) => index.toString())
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .multiSelectable(true)
      .scrollBar(BarState.Off)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)

      Text('Grid2').fontColor(0x000000).fontSize(16).width('90%')
      // The grid does not scroll, and undefined is used to reserve space.
      Grid(undefined, this.layoutOptions2) {
        LazyForEach(this.numbers, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height(80)
              .textAlign(TextAlign.Center)
          }
        }, (index: number) => index.toString())
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .scrollBar(BarState.Off)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![gridLayoutOptions](figures/gridLayoutOptions.gif)

### Example 4: Implementing Nested Scrolling in a Grid

This example demonstrates how to use [nestedScroll](#nestedscroll10) and [onScrollFrameBegin](#onscrollframebegin10).

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct GridExample {
  @State colors: number[] = [0xFFC0CB, 0xDA70D6, 0x6B8E23, 0x6A5ACD, 0x00FFFF, 0x00FF7F];
  numbers: GridDataSource = new GridDataSource([]);
  @State translateY: number = 0;
  private scroller: Scroller = new Scroller();
  private gridScroller: Scroller = new Scroller();
  private touchDown: boolean = false;
  private listTouchDown: boolean = false;
  private scrolling: boolean = false;

  aboutToAppear() {
    let list: string[] = [];
    for (let i = 0; i < 100; i++) {
      list.push(i.toString());
    }
    this.numbers = new GridDataSource(list);
  }

  build() {
    Stack() {
      Column() {
        Row() {
          Text('Head')
        }

        Column() {
          List({ scroller: this.scroller }) {
            ListItem() {
              Grid() {
                GridItem() {
                  Text('GoodsTypeList1')
                }
                .backgroundColor(this.colors[0])
                .columnStart(0)
                .columnEnd(1)

                GridItem() {
                  Text('GoodsTypeList2')
                }
                .backgroundColor(this.colors[1])
                .columnStart(0)
                .columnEnd(1)

                GridItem() {
                  Text('GoodsTypeList3')
                }
                .backgroundColor(this.colors[2])
                .columnStart(0)
                .columnEnd(1)

                GridItem() {
                  Text('GoodsTypeList4')
                }
                .backgroundColor(this.colors[3])
                .columnStart(0)
                .columnEnd(1)

                GridItem() {
                  Text('GoodsTypeList5')
                }
                .backgroundColor(this.colors[4])
                .columnStart(0)
                .columnEnd(1)
              }
              .scrollBar(BarState.Off)
              .columnsGap(15)
              .rowsGap(10)
              .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
              .columnsTemplate('1fr')
              .width('100%')
              .height(200)
            }

            ListItem() {
              Grid(this.gridScroller) {
                LazyForEach(this.numbers, (item: string) => {
                  GridItem() {
                    Text(item)
                      .fontSize(16)
                      .backgroundColor(0xF9CF93)
                      .width('100%')
                      .height('100%')
                      .textAlign(TextAlign.Center)
                  }
                  .width('100%')
                  .height(40)
                  .shadow({ radius: 10, color: '#909399', offsetX: 1, offsetY: 1 })
                  .borderRadius(10)
                  .translate({ x: 0, y: this.translateY })
                }, (item: string) => item)
              }
              .columnsTemplate('1fr 1fr')
              .friction(0.3)
              .columnsGap(15)
              .rowsGap(10)
              .scrollBar(BarState.Off)
              .width('100%')
              .height('100%')
              .layoutDirection(GridDirection.Column)
              .nestedScroll({
                scrollForward: NestedScrollMode.PARENT_FIRST,
                scrollBackward: NestedScrollMode.SELF_FIRST
              })
              .onTouch((event: TouchEvent) => {
                if (event.type == TouchType.Down) {
                  this.listTouchDown = true;
                } else if (event.type == TouchType.Up) {
                  this.listTouchDown = false;
                }
              })
            }
          }
          .scrollBar(BarState.Off)
          .edgeEffect(EdgeEffect.None)
          .onTouch((event: TouchEvent) => {
            if (event.type == TouchType.Down) {
              this.touchDown = true;
            } else if (event.type == TouchType.Up) {
              this.touchDown = false;
            }
          })
          .onScrollFrameBegin((offset: number, state: ScrollState) => {
            if (this.scrolling && offset > 0) {
              let newOffset = this.scroller.currentOffset().yOffset;
              if (newOffset >= 590) {
                this.gridScroller.scrollBy(0, offset);
                return { offsetRemain: 0 };
              } else if (newOffset + offset > 590) {
                this.gridScroller.scrollBy(0, newOffset + offset - 590);
                return { offsetRemain: 590 - newOffset };
              }
            }
            return { offsetRemain: offset };
          })
          .onScrollStart(() => {
            if (this.touchDown && !this.listTouchDown) {
              this.scrolling = true;
            }
          })
          .onScrollStop(() => {
            this.scrolling = false;
          })
        }
        .width('100%')
        .height('100%')
        .padding({ left: 10, right: 10 })
      }

      Row() {
        Text('Top')
          .width(30)
          .height(30)
          .borderRadius(50)
      }
      .padding(5)
      .borderRadius(50)
      .backgroundColor('#ffffff')
      .shadow({ radius: 10, color: '#909399', offsetX: 1, offsetY: 1 })
      .margin({ right: 22, bottom: 15 })
      .onClick(() => {
        this.scroller.scrollTo({ xOffset: 0, yOffset: 0 });
        this.gridScroller.scrollTo({ xOffset: 0, yOffset: 0 });
      })
    }
    .align(Alignment.BottomEnd)
  }
}
```

![nestedScrollExample4](figures/nestedScrollExample4.gif)

### Example 5: Implementing Dragging in a Grid

1.  Set [editMode](#editmode8) to enable edit mode for a grid, where the user can drag grid items.

2.  In the [onItemDragStart](#onitemdragstart8) callback, set the image to be displayed during dragging.

3.  Through [onItemDrop](#onitemdrop8), obtain the initial position of the dragged item and the position to which the dragged item will be dropped. Through [onItemDrop](#onitemdrop8), complete the array position exchange logic.

4.  Set the **supportAnimation(true)** attribute to support animations.

> **NOTE**
>
> The drag and drop action is not displayed in the preview.

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource([]);
  scroller: Scroller = new Scroller();
  @State text: string = 'drag';

  @Builder pixelMapBuilder() { // Style for the drag event.
    Column() {
      Text(this.text)
        .fontSize(16)
        .backgroundColor(0xF9CF93)
        .width(80)
        .height(80)
        .textAlign(TextAlign.Center)
    }
  }

  aboutToAppear() {
    let list: string[] = [];
    for (let i = 1; i <= 15; i++) {
      list.push(i + '');
    }
    this.numbers = new GridDataSource(list);
  }

  changeIndex(index1: number, index2: number) { // Exchange the array positions.
    this.numbers.swapItem(index1, index2);
  }

  build() {
    Column({ space: 5 }) {
      Grid(this.scroller) {
        LazyForEach(this.numbers, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width(80)
              .height(80)
              .textAlign(TextAlign.Center)
          }
        }, (day: string) => day)
      }
      .columnsTemplate('1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
      .editMode(true) // Enable edit mode, where the user can drag the grid items.
      .supportAnimation(true) // Support animations.
      .onItemDragStart((event: ItemDragInfo, itemIndex: number) => { // Triggered when a grid item starts to be dragged.
        this.text = this.numbers.getData(itemIndex);
        return this.pixelMapBuilder(); // Set the image displayed during the dragging.
      })
      .onItemDrop((event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => { // Triggered when the dragged item is dropped on the drop target of the grid.
        // If isSuccess is set to false, the item is dropped outside of the grid. If the value of insertIndex is greater than that of length, an item adding event occurs.
        if (!isSuccess || insertIndex >= this.numbers.totalCount()) {
          return;
        }
        console.info('itemIndex:' + itemIndex + ', insertIndex:' + insertIndex); // itemIndex indicates the start position of the drag, and insertIndex indicates the insertion position of the drag.
        this.changeIndex(itemIndex, insertIndex);
      })
    }.width('100%').margin({ top: 5 })
  }
}
```

Below are some examples.

Below shows how the grid looks when dragging of grid items starts.

![gridDrag](figures/gridDrag.png)

Below shows how the grid looks when dragging of grid items is in progress.

![gridDrag](figures/gridDrag1.png)

Below shows how the grid looks after grid item 1 and grid item 6 swap their positions.

![gridDrag](figures/gridDrag2.png)

Below shows the drag animation.

![gridDragAnimation](figures/gridDragAnimation.gif)

### Example 6: Implementing Adaptive Grid Layout

This example demonstrates how to use [layoutDirection](#layoutdirection8), [maxCount](#maxcount8), [minCount](#mincount8), and [cellLength](#celllength8).

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource([]);

  aboutToAppear() {
    let list: string[] = [];
    for (let i = 1; i <= 30; i++) {
      list.push(i + '');
    }
    this.numbers = new GridDataSource(list);
  }

  build() {
    Scroll() {
      Column({ space: 5 }) {
        Blank()
        Text('The layoutDirection, maxCount, minCount, and cellLength parameters take effect only when neither rowsTemplate nor columnsTemplate is set.')
          .fontSize(16).fontColor(0x000000).width('90%')
        Grid() {
          LazyForEach(this.numbers, (day: string) => {
            GridItem() {
              Text(day).fontSize(16).backgroundColor(0xF9CF93)
            }.width(40).height(80).borderWidth(2).borderColor(Color.Red)
          }, (day: string) => day)
        }
        .height(300)
        .columnsGap(10)
        .rowsGap(10)
        .backgroundColor(0xFAEEE0)
        .maxCount(6)
        .minCount(2)
        .cellLength(0)
        .layoutDirection(GridDirection.Row)
      }
      .width('90%').margin({ top: 5, left: 5, right: 5 })
      .align(Alignment.Center)
    }
  }
}
```

![cellLength](figures/cellLength.gif)

### Example 7: Dynamically Adjusting the Number of Grid Columns with a Pinch Gesture

This example demonstrates how to adjust the number of columns in the grid with a pinch gesture using two fingers.

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
// xxx.ets
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource([]);
  @State columns: number = 2;

  aboutToAppear() {
    let lastCount = AppStorage.get<number>('columnsCount');
    if (typeof lastCount != 'undefined') {
      this.columns = lastCount;
    }

    let list: string[] = [];
    for (let i = 0; i < 20; i++) {
      for (let j = 0; j < 20; j++) {
        list.push(j.toString());
      }
    }
    this.numbers = new GridDataSource(list);
  }

  build() {
    Column({ space: 5 }) {
      Row() {
        Text('Pinch to change the number of columns')
          .height('5%')
          .margin({ top: 10, left: 20 })
      }

      Grid() {
        LazyForEach(this.numbers, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height(80)
              .textAlign(TextAlign.Center)
          }
        }, (index: number) => index.toString())
      }
      .columnsTemplate('1fr '.repeat(this.columns))
      .columnsGap(10)
      .rowsGap(10)
      .width('90%')
      .scrollBar(BarState.Off)
      .backgroundColor(0xFAEEE0)
      .height('100%')
      .cachedCount(3)
      // Switching the number of columns triggers a reordering animation for the item positions.
      .animation({
        duration: 300,
        curve: Curve.Smooth
      })
      .priorityGesture(
        PinchGesture()
          .onActionEnd((event: GestureEvent) => {
            console.info('end scale:' + event.scale);
            // When a user performs a pinch-to-zoom gesture by moving their fingers apart, and the number of columns decreases to a certain threshold (in this case, 2), it will cause the items to enlarge.
            if (event.scale > 2) {
              this.columns--;
            } else if (event.scale < 0.6) {
              this.columns++;
            }
            // You can set the maximum and minimum number of columns based on the device screen width. Here, the minimum number of columns is 1, and the maximum number of columns is 4.
            this.columns = Math.min(4, Math.max(1, this.columns));
            AppStorage.setOrCreate<number>('columnsCount', this.columns);
          })
      )
    }.width('100%').margin({ top: 5 })
  }
}
```

![pinch](figures/grid-pinch.gif)

### Example 8: Using Adaptive Column Count Settings

This example shows the usage of **auto-fill**, **auto-fit**, and **auto-stretch** in [columnsTemplate](#columnstemplate).

```ts
@Entry
@Component
struct GridColumnsTemplate {
  data: number[] = [0, 1, 2, 3, 4, 5];
  data1: number[] = [0, 1, 2, 3, 4, 5];
  data2: number[] = [0, 1, 2, 3, 4, 5];

  build() {
    Column({ space: 10 }) {
      Text('auto-fill auto-calculates the number of columns based on the set column width').width('90%')
      Grid() {
        ForEach(this.data, (item: number) => {
          GridItem() {
            Text('N' + item).height(80)
          }
          .backgroundColor(Color.Orange)
        })
      }
      .width('90%')
      .border({ width: 1, color: Color.Black })
      .columnsTemplate('repeat(auto-fill, 70)')
      .columnsGap(10)
      .rowsGap(10)
      .height(150)

      Text('auto-fit calculates the number of columns based on the specified column width, and then any remaining space is evenly distributed across all columns').width('90%')
      Grid() {
        ForEach(this.data1, (item: number) => {
          GridItem() {
            Text('N' + item).height(80)
          }
          .backgroundColor(Color.Orange)
        })
      }
      .width('90%')
      .border({ width: 1, color: Color.Black })
      .columnsTemplate('repeat(auto-fit, 70)')
      .columnsGap(10)
      .rowsGap(10)
      .height(150)

      Text('auto-stretch calculates the number of columns based on the specified column width, and then any remaining space is evenly distributed into the gaps between columns').width('90%')
      Grid() {
        ForEach(this.data2, (item: number) => {
          GridItem() {
            Text('N' + item).height(80)
          }
          .backgroundColor(Color.Orange)
        })
      }
      .width('90%')
      .border({ width: 1, color: Color.Black })
      .columnsTemplate('repeat(auto-stretch, 70)')
      .columnsGap(10)
      .rowsGap(10)
      .height(150)
    }
    .width('100%')
    .height('100%')
  }
}
```

![gridColumnsTemplate](figures/gridColumnsTemplate.png)

### Example 9: Setting Grid Item Heights Based on the Tallest Item in the Current Row

This example implements a grid that contains two columns. The grid item in each column consists of two **Column** components with determined heights and one **Text** component with an undetermined height.

By default, the heights of the left and right grid items may differ; however, after the grid's [alignItems](#alignitems12) attribute is set to **GridItemAlignment.STRETCH**, the grid item with a shorter height in a row will adopt the height of the taller grid item, aligning their heights within the same row.

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct Index {
  data: GridDataSource = new GridDataSource([]);
  @State items: number[] = [];

  aboutToAppear(): void {
    let list: string[] = [];
    for (let i = 0; i < 100; i++) {
      list.push(i.toString());
      this.items.push(this.getSize());
    }
    this.data= new GridDataSource(list);
  }

  getSize() {
    let ret = Math.floor(Math.random() * 5);
    return Math.max(1, ret);
  }

  build() {
    Column({ space: 10 }) {
      Text('Grid alignItems sample code')

      Grid() {
        LazyForEach(this.data, (item: string) => {
          // GridItem and Column components, when left without explicitly set heights, will by default adapt to the size of their child components. With alignItems set to STRETCH, they will instead take on the height of the tallest component in the current row.
          // If the height is explicitly set, the component maintains the defined height and will not follow the height of the tallest component in the current row.
          GridItem() {
            Column() {
              Column().height(100).backgroundColor('#D5D5D5').width('100%')
              // The Text component in the center is set with flexGrow(1) to automatically fill the available space within the parent component.
              Text('This is a piece of text.'.repeat(this.items[item]))
                .flexGrow(1).width('100%').align(Alignment.TopStart)
                .backgroundColor('#F7F7F7')
              Column().height(50).backgroundColor('#707070').width('100%')
            }
          }
          .border({ color: Color.Black, width: 1 })
        })
      }
      .columnsGap(10)
      .rowsGap(5)
      .columnsTemplate('1fr 1fr')
      .width('80%')
      .height('100%')
      // When the grid has its alignItems attribute set to STRETCH, it adjusts the height of all grid items in a row to match the height of the tallest grid item in that row.
      .alignItems(GridItemAlignment.STRETCH)
      .scrollBar(BarState.Off)
    }
    .height('100%')
    .width('100%')
  }
}

```

![gridAlignItems](figures/gridAlignItems.png)

### Example 10: Setting Edge Fading

This example demonstrates how to enable the edge fading effect using [fadingEdge](ts-container-scrollable-common.md#fadingedge14).

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
// xxx.ets
// This example demonstrates how to implement a Grid component with an edge fading effect and set the length of the fading edge.
import { LengthMetrics } from '@kit.ArkUI';
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource([]);
  scroller: Scroller = new Scroller();

  aboutToAppear() {
    let list: string[] = [];
    for (let i = 0; i <= 10; i++) {
      for (let j = 0; j < 5; j++) {
        list.push(j.toString());
      }
    }
    this.numbers = new GridDataSource(list);
  }

  build() {
    Column({ space: 5 }) {
      Text('Grid').fontColor(0x000000).fontSize(16).width('90%')
      Grid(this.scroller) {
        LazyForEach(this.numbers, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height(80)
              .textAlign(TextAlign.Center)
          }
        }, (index: number) => index.toString())
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(20)
      .height('90%')
      .fadingEdge(true, { fadingEdgeLength: LengthMetrics.vp(80) })

    }.width('100%').margin({ top: 5 })
  }
}
```

![fadingEdge_grid](figures/fadingEdge_grid.gif)

### Example 11: Setting the Single-Side Edge Effect

This example uses the [edgeEffect](#edgeeffect10) API to set the single-edge effect for the **Grid** component.

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
// xxx.ets
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource([]);
  scroller: Scroller = new Scroller();

  aboutToAppear() {
    let list: string[] = [];
    for (let i = 0; i <= 10; i++) {
      for (let j = 0; j < 5; j++) {
        list.push(j.toString());
      }
    }
    this.numbers = new GridDataSource(list);
  }

  build() {
    Column({ space: 5 }) {
      Grid(this.scroller) {
        LazyForEach(this.numbers, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height(80)
              .textAlign(TextAlign.Center)
          }
        }, (index: number) => index.toString())
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(20)
      .edgeEffect(EdgeEffect.Spring, { alwaysEnabled: true, effectEdge: EffectEdge.START })
      .width('90%')
      .backgroundColor(0xDCDCDC)
      .height('80%')

    }.width('100%').margin({ top: 5 })
  }
}
```

![edgeEffect_grid](figures/edgeEffect_grid.gif)

### Example 12: Moving Focus with Wrap by Arrow Keys

In API version 20 and later versions, this example uses the [focusWrapMode](#focuswrapmode20) API to implement the effect of line-wrapping focus navigation with arrow keys in the **Grid** component.

```ts
// xxx.ets
@Entry
@Component
struct GridExample {
  scroller: Scroller = new Scroller();
  build() {
    Column() {
      Grid(this.scroller) {
        GridItem() {
          Text('A')
            .focusable(true)
            .fontSize(18)
            .fontWeight(5)
            .backgroundColor(0xF9CF93)
            .width('100%')
            .height(80)
            .textAlign(TextAlign.Center)
        }
        GridItem() {
          Text('B')
            .focusable(true)
            .fontSize(18)
            .fontWeight(5)
            .backgroundColor(0xF9CF93)
            .width('100%')
            .height(80)
            .textAlign(TextAlign.Center)
        }
        GridItem() {
          Text('C')
            .focusable(true)
            .fontSize(18)
            .fontWeight(5)
            .backgroundColor(0xF9CF93)
            .width('100%')
            .height(80)
            .textAlign(TextAlign.Center)
        }
        GridItem() {
          Text('D')
            .focusable(true)
            .fontSize(18)
            .fontWeight(5)
            .backgroundColor(0xF9CF93)
            .width('100%')
            .height(80)
            .textAlign(TextAlign.Center)
        }
        GridItem() {
          Text('E')
            .focusable(true)
            .fontSize(18)
            .fontWeight(5)
            .backgroundColor(0xF9CF93)
            .width('100%')
            .height(80)
            .textAlign(TextAlign.Center)
        }
        GridItem() {
          Text('F')
            .focusable(true)
            .fontSize(18)
            .fontWeight(5)
            .backgroundColor(0xF9CF93)
            .width('100%')
            .height(80)
            .textAlign(TextAlign.Center)
        }
      }
      .focusWrapMode(FocusWrapMode.WRAP_WITH_ARROW)
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(20)
      .backgroundColor(0xDCDCDC)
    }.width('100%').margin({ top: 5 })
  }
}
```

![edgeEffect_grid](figures/gridFocus.gif)

### Example 13: Setting Scrolling Events

This example obtains a [UIGridEvent](#uigridevent19) instance via [getEvent('Grid')](../js-apis-arkui-frameNode.md#geteventgrid19) on a FrameNode and sets scroll event callbacks for a **Grid** component. This approach is intended for scenarios where the page code cannot be directly modified to use declarative callbacks.

The **UIGridEvent** API is added since API version 19.

```ts
import { NodeController, FrameNode, typeNode } from '@kit.ArkUI';

class MyNodeController extends NodeController {
  public rootNode: FrameNode | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.rootNode.commonAttribute.width(100);
    return this.rootNode;
  }

  addCommonEvent(frameNode: FrameNode) {
    let gridEvent: UIGridEvent | undefined = typeNode.getEvent(frameNode, 'Grid');
    gridEvent?.setOnWillScroll((scrollOffset: number, scrollState: ScrollState, scrollSource: ScrollSource) => {
      console.info(`onWillScroll scrollOffset = ${scrollOffset}, scrollState = ${scrollState}, scrollSource = ${scrollSource}`);
    });
    gridEvent?.setOnDidScroll((scrollOffset: number, scrollState: ScrollState) => {
      console.info(`onDidScroll scrollOffset = ${scrollOffset}, scrollState = ${scrollState}`);
    });
    gridEvent?.setOnReachStart(() => {
      console.info(`onReachStart`);
    });
    gridEvent?.setOnReachEnd(() => {
      console.info(`onReachEnd`);
    });
    gridEvent?.setOnScrollStart(() => {
      console.info(`onScrollStart`);
    });
    gridEvent?.setOnScrollStop(() => {
      console.info(`onScrollStop`);
    });
    gridEvent?.setOnScrollFrameBegin((offset: number, state: ScrollState) => {
      console.info(`onScrollFrameBegin offset = ${offset}, state = ${state}`);
      return undefined;
    });
    gridEvent?.setOnScrollIndex((first: number, last: number) => {
      console.info(`onScrollIndex start = ${first}, end = ${last}`);
    });
  }
}

@Entry
@Component
struct Index {
  @State index: number = 0;
  private myNodeController: MyNodeController = new MyNodeController();
  @State numbers: string[] = [];

  aboutToAppear() {
    for (let i = 0; i < 5; i++) {
      for (let j = 0; j < 5; j++) {
        this.numbers.push(j.toString());
      }
    }
  }

  build() {
    Column() {
      Button('add CommonEvent to Grid')
        .onClick(() => {
          this.myNodeController!.addCommonEvent(this.myNodeController!.rootNode!.getParent()!.getPreviousSibling()!);
        })
      Grid() {
        ForEach(this.numbers, (day: string, index: number) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height(80)
              .textAlign(TextAlign.Center)
          }
        }, (day: string, index: number) => index.toString() + day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .enableScrollInteraction(true)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
      NodeContainer(this.myNodeController)
    }.width('100%')
  }
}
```

### Example 14: Scrolling to a Specified Position

This example uses the [scrollToIndex](ts-container-scroll.md#scrolltoindex) API to scroll the **Grid** component to a specified position.

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
import { GridDataSource } from './GridDataSource';
@Entry
@Component
struct GridScrollToIndexSample {
  numbers: GridDataSource = new GridDataSource([]);
  scroller: Scroller = new Scroller();
  aboutToAppear(): void {
    let list: string[] = [];
    for (let i = 0; i < 10; i++) {
      for (let j = 0; j < 10; j++) {
        list.push((i * 5 + j + 1).toString());
      }
    }
    this.numbers =  new GridDataSource(list);
  }

  build() {
    Column({ space: 5 }) {
      Button('scrollToIndex')
        .onClick (() => { // Scroll to the corresponding position.
          this.scroller.scrollToIndex(25, true, ScrollAlign.START);
        })
      Grid(this.scroller) {
        LazyForEach(this.numbers, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height(80)
              .textAlign(TextAlign.Center)
          }
        }, (index: number) => index.toString())
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .friction(0.6)
      .enableScrollInteraction(true)
      .supportAnimation(false)
      .multiSelectable(false)
      .edgeEffect(EdgeEffect.Spring)
      .scrollBar(BarState.On)
      .scrollBarColor(Color.Grey)
      .scrollBarWidth(4)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![grid_scrollToIndex](figures/gridScrollToIndex.gif)

### Example 15: Implementing Panning Selection in Grid

This example uses the [PanGesture](./ts-basic-gestures-pangesture.md#pangesture-1) API to implement the effect of panning while selecting items in a **Grid** component.

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
// xxx.ets
import { GridDataSource } from './GridDataSource';
import { display, curves } from '@kit.ArkUI';

enum SlideActionType {
  START,
  UPDATE,
  END
}
// Hot zone
let HOT_AREA_LENGTH: number = 0;
try {
  HOT_AREA_LENGTH =
    Math.round(display.getDefaultDisplaySync().densityDPI * 10 / 25.4 / display.getDefaultDisplaySync().densityPixels);
} catch (error) {
  console.info('Failed to get default display for HOT_AREA_LENGTH:', error);
}
// Scroll curve: Bezier curve
const SLIDE_SELECT_SPEED_CURVE = curves.cubicBezierCurve(0.33, 0, 0.67, 1);
// Scroll speed: maximum speed
let AUTO_SPEED_MAX: number = 0;
try {
  AUTO_SPEED_MAX = Math.round(2400 / display.getDefaultDisplaySync().densityPixels);
} catch (error) {
  console.info('Failed to get default display for AUTO_SPEED_MAX:', error);
}
@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource([]);
  scroller: Scroller = new Scroller();
  @State selectedIndexes: string[] = [];
  // Items selected during panning
  @State updateIndex: number = -1;
  @State lastUpdateIndex: number = -1;
  @State updateTimer: number = new Date().valueOf();
  // Whether items can be selected during panning
  @State canSlideSelect: boolean = false;
  @State isAutoScroll: boolean = false;
  // Stop gesture
  @State stopGesture: boolean = false;
  private scrollStartIndex: number = 0;
  private scrollEndIndex: number = 0;
  // Initial position of panning
  @State startIndex: number = -1;
  @State endIndex: number = -1;
  //Height of the scrolling area
  @State contentHeight: number = 0;
  @State areaY: number = 0;
  // List width
  @State listWidth: number = 0;
  @State oldCheckList: boolean[] = [];
  // Whether to set passed points as selected during panning
  @State setChecked: boolean = false;
  aboutToAppear() {
    let list: string[] = [];
    for (let i = 0; i < 20; i++) {
      for (let j = 0; j < 20; j++) {
        list.push((20 * i + j + 1).toString());
      }
    }
    this.numbers = new GridDataSource(list);
  }
  /**
   * Obtain the current point.
   * @param finger
   * @returns
   */
  getIndex(finger: FingerInfo): number {
    // Initialize data.
    let index = -1;
    try {
      index = this.scroller.getItemIndex(finger.localX, finger.localY);
      if (index === -1) {
        for (let i = this.scrollStartIndex; i <= this.scrollEndIndex; i++) {
          const item = this.scroller.getItemRect(i);
          if (finger.localY < item.y ||
            finger.localY >= item.y && finger.localY <= item.y + item.height && finger.localX < item.x) {
            break;
          }
          index = i;
        }
      }
    } catch {
      this.stopGesture = true;
      return index;
    }
    return index;
  }
  slideActionStart(index: number): void {
    if (index < 0) {
      return;
    }
    console.debug('start index: ' + index.toString());
    const targetIndex = index + 1;
    this.setChecked = !this.selectedIndexes.includes(targetIndex.toString());
    this.startIndex = index;
    this.selectedIndexes.push(targetIndex.toString());
    this.updateIndex = index;

  }
  slideActionUpdate(index: number): void {
    if (!this.canSlideSelect) {
      return;
    }
    if (this.startIndex === -1) {
      // Reconfigure the initial data of panning when the initial contact point is in the gap.
      this.slideActionStart(index);
      return;
    }
    if (index === -1) {
      return;
    }

    this.lastUpdateIndex = this.updateIndex;
    this.setItemChecked(index);
    this.updateIndex = index;
  }
  setItemChecked(index: number):void {
    const start = Math.min(this.startIndex, index);
    const end = Math.max(this.startIndex, index);
    for (let i = start; i < end+1;i++) {
      const item = (i+1).toString();
      if (this.setChecked) {
        this.selectedIndexes.push(item);
      } else {
        if (this.selectedIndexes.includes(item)) {
          this.selectedIndexes = this.selectedIndexes.filter(selectIndex => selectIndex != item);
        }
      }

    }
  }
  /**
   * Panning ends.
   */
  slideActionEnd(): void {
    this.startIndex = -1;
    this.updateIndex = -1;
    this.scroller.scrollBy(0, 0);
    this.isAutoScroll = false;
  }
  /**
   * Automatic scrolling--
   * @param finger
   */
  autoScroll(finger: FingerInfo): void {
    // Multiple selections are not allowed.
    if (!this.canSlideSelect) {
      return;
    }
    let pointY = finger.globalY - this.areaY;
    if (pointY <= HOT_AREA_LENGTH) {
      if (this.isAutoScroll && pointY <= 0) {
        return;
      }
      const speedFlag = pointY > 0 ? SLIDE_SELECT_SPEED_CURVE
        .interpolate(1 - pointY / HOT_AREA_LENGTH) : 1;
      this.scroller.scrollEdge(Edge.Top, {
        velocity: speedFlag * AUTO_SPEED_MAX
      });
      this.isAutoScroll = true;
    } else if (pointY > this.contentHeight - HOT_AREA_LENGTH) {
      if (this.isAutoScroll && pointY >= this.contentHeight) {
        return;
      }
      const speedFlag = pointY < this.contentHeight ? SLIDE_SELECT_SPEED_CURVE
        .interpolate(1 - (this.contentHeight - pointY) / HOT_AREA_LENGTH) : 1;
      this.scroller.scrollEdge(Edge.Bottom, {
        velocity: speedFlag * AUTO_SPEED_MAX
      });
      this.isAutoScroll = true;
    } else {
      if (this.isAutoScroll) {
        this.scroller.scrollBy(0, 0);
        this.isAutoScroll = false;
      }
    }
  }

  panGestureAction(type: SlideActionType, event: GestureEvent | undefined): void {
    if (this.stopGesture || !event) {
      return;
    }
    const finger = event!.fingerList[0];
    const index = this.getIndex(finger);
    switch (type) {
      case SlideActionType.START: {
        this.slideActionStart(index);
        break;
      }
      case SlideActionType.UPDATE: {
        this.slideActionUpdate(index);
        this.autoScroll(finger);
        break;
      }
      case SlideActionType.END: {
        this.slideActionEnd();
        break;
      }
      default: {
      }
    }
  }
  build() {
    Column({ space: 5 }) {
      Grid(this.scroller) {
        LazyForEach(this.numbers, (day: string) => {
          GridItem() {
            Stack() {
              Text(day)
                .fontSize(16)
                .backgroundColor(0xF9CF93)
                .width('100%')
                .height(80)
                .textAlign(TextAlign.Center)
              if (this.canSlideSelect) {
                // Replace $r('app.media.gouxuan') and $r('app.media.weigouxuan') with the image resource files you use.
                Image(this.selectedIndexes.includes(day) ? $r('app.media.gouxuan') :$r('app.media.weigouxuan'))
                  .width(30)
                  .height(30)
                  .position({right:5,top:5})
                  .draggable(false)
              }

            }
          }
        }, (index: number) => index.toString())
      }
      .columnsTemplate('1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .friction(0.6)
      .enableScrollInteraction(true)
      .supportAnimation(false)
      .multiSelectable(false)
      .edgeEffect(EdgeEffect.Spring)
      .scrollBar(BarState.On)
      .scrollBarColor(Color.Grey)
      .scrollBarWidth(4)
      .width('90%')
      .height('85%')
      .draggable(!this.canSlideSelect)
      .backgroundColor(0xFAEEE0)
      .onAreaChange((oldVal, newVal) => {
        this.listWidth = newVal.width as number;
        this.areaY = newVal.globalPosition.y as number;
        this.contentHeight = newVal.height as number;
      })
      .onScrollIndex((start, end) => {
        this.scrollStartIndex = start;
        this.scrollEndIndex = end;
      })
      .gesture(
        // Pan gesture
        PanGesture({ direction: PanDirection.Vertical })
          .onActionStart((event: GestureEvent | undefined) => {
            this.panGestureAction(SlideActionType.START, event);
          })
          .onActionUpdate((event: GestureEvent | undefined) => {
            this.panGestureAction(SlideActionType.UPDATE, event);
          })
          .onActionEnd((event?: GestureEvent) => {
            this.panGestureAction(SlideActionType.END, event);
          }),
        GestureMask.Normal
      )
      .onGestureRecognizerJudgeBegin((event: BaseGestureEvent, current: GestureRecognizer,
        recognizers: Array<GestureRecognizer>) => {
        if (this.canSlideSelect && current.isBuiltIn() &&
          current.getType() == GestureControl.GestureType.PAN_GESTURE) {
          return GestureJudgeResult.REJECT;
        }
        return GestureJudgeResult.CONTINUE;
      })
      Row() {
        Button('Start Editing').onClick(()=>{
          this.selectedIndexes = [];
          this.canSlideSelect = true;
        })
        Button('End Editing').onClick(()=>{
          this.canSlideSelect = false;
          this.selectedIndexes = [];
        })
      }
      .margin({
        bottom: 30
      })
      Text(`${this.selectedIndexes.join(',')}`)
    }.width('100%').margin({ top: 5 })
  }
}
```

![gridScrollWithPanGesture](figures/gridScrollWithPanGesture.gif)

### Example 16: Customizing the Drag Effect for GridItem

This example uses the [gesture](./ts-gesture-settings.md#gesture) API to customize the drag effect for the **GridItem** component.

```ts
import { curves } from '@kit.ArkUI';

@Entry
@Component
struct GridItemExample {
  @State numbers: number[] = [];
  @State dragItem: number = -1;
  @State scaleItem: number = -1;
  private dragRefOffsetX: number = 0;
  private dragRefOffsetY: number = 0;
  @State offsetX: number = 0;
  @State offsetY: number = 0;
  private FIX_VP_X: number = 108;
  private FIX_VP_Y: number = 120;

  aboutToAppear() {
    for (let i = 1; i <= 11; i++) {
      this.numbers.push(i);
    }
  }

  itemMove(index: number, newIndex: number): void {
    console.info('index:' + index + ' newIndex:' + newIndex);
    if (!this.isDraggable(newIndex)) {
      return;
    }
    let tmp = this.numbers.splice(index, 1);
    this.numbers.splice(newIndex, 0, tmp[0]);
  }

  // Swipe down.
  down(index: number): void {
    // Specify that the fixed GridItem does not respond to events.
    if (!this.isDraggable(index + 3)) {
      return;
    }
    this.offsetY -= this.FIX_VP_Y;
    this.dragRefOffsetY += this.FIX_VP_Y;
    this.itemMove(index, index + 3);
  }

  // Swipe down (in a grid where the lower right corner is empty).
  down2(index: number): void {
    if (!this.isDraggable(index + 3)) {
      return;
    }
    this.offsetY -= this.FIX_VP_Y;
    this.dragRefOffsetY += this.FIX_VP_Y;
    this.itemMove(index, index + 3);
  }

  // Swipe up.
  up(index: number): void {
    if (!this.isDraggable(index - 3)) {
      return;
    }
    this.offsetY += this.FIX_VP_Y;
    this.dragRefOffsetY -= this.FIX_VP_Y;
    this.itemMove(index, index - 3);
  }

  // Swipe left.
  left(index: number): void {
    if (!this.isDraggable(index - 1)) {
      return;
    }
    this.offsetX += this.FIX_VP_X;
    this.dragRefOffsetX -= this.FIX_VP_X;
    this.itemMove(index, index - 1);
  }

  // Swipe right.
  right(index: number): void {
    if (!this.isDraggable(index + 1)) {
      return;
    }
    this.offsetX -= this.FIX_VP_X;
    this.dragRefOffsetX += this.FIX_VP_X;
    this.itemMove(index, index + 1);
  }

  // Swipe to the lower right.
  lowerRight(index: number): void {
    if (!this.isDraggable(index + 4)) {
      return;
    }
    this.offsetX -= this.FIX_VP_X;
    this.dragRefOffsetX += this.FIX_VP_X;
    this.offsetY -= this.FIX_VP_Y;
    this.dragRefOffsetY += this.FIX_VP_Y;
    this.itemMove(index, index + 4);
  }

  // Swipe to the upper right.
  upperRight(index: number): void {
    if (!this.isDraggable(index - 2)) {
      return;
    }
    this.offsetX -= this.FIX_VP_X;
    this.dragRefOffsetX += this.FIX_VP_X;
    this.offsetY += this.FIX_VP_Y;
    this.dragRefOffsetY -= this.FIX_VP_Y;
    this.itemMove(index, index - 2);
  }

  // Swipe to the lower left.
  lowerLeft(index: number): void {
    if (!this.isDraggable(index + 2)) {
      return;
    }
    this.offsetX += this.FIX_VP_X;
    this.dragRefOffsetX -= this.FIX_VP_X;
    this.offsetY -= this.FIX_VP_Y;
    this.dragRefOffsetY += this.FIX_VP_Y;
    this.itemMove(index, index + 2);
  }

  // Swipe to the upper left.
  upperLeft(index: number): void {
    if (!this.isDraggable(index - 4)) {
      return;
    }
    this.offsetX += this.FIX_VP_X;
    this.dragRefOffsetX -= this.FIX_VP_X;
    this.offsetY += this.FIX_VP_Y;
    this.dragRefOffsetY -= this.FIX_VP_Y;
    this.itemMove(index, index - 4);
  }

  isDraggable(index: number): boolean {
    console.info('index:' + index)
    return index > 1;
  }

  build() {
    Column() {
      Grid() {
        ForEach(this.numbers, (item: number) => {
          GridItem() {
            Text(item + '')
              .fontSize(16)
              .width('100%')
              .textAlign(TextAlign.Center)
              .height(100)
              .borderRadius(10)
              .backgroundColor(0xF9CF93)
              .shadow(this.scaleItem == item ? {
                radius: 70,
                color: '#15000000',
                offsetX: 0,
                offsetY: 0
              } :
                {
                  radius: 0,
                  color: '#15000000',
                  offsetX: 0,
                  offsetY: 0
                })
              .animation({ curve: Curve.Sharp, duration: 300 })
          }
          // Specify that the fixed GridItem does not respond to events.
          .hitTestBehavior(this.isDraggable(this.numbers.indexOf(item)) ? HitTestMode.Default : HitTestMode.None)
          .scale({ x: this.scaleItem == item ? 1.05 : 1, y: this.scaleItem == item ? 1.05 : 1 })
          .zIndex(this.dragItem == item ? 1 : 0)
          .translate(this.dragItem == item ? { x: this.offsetX, y: this.offsetY } : { x: 0, y: 0 })
          .padding(10)
          .gesture(
            // The following combined gestures are recognized in sequential recognition mode. If the long press gesture event is not triggered correctly, the drag gesture event will not be triggered.
            GestureGroup(GestureMode.Sequence,
              LongPressGesture({ repeat: true })
                .onAction((event?: GestureEvent) => {
                  this.getUIContext()?.animateTo({ curve: Curve.Friction, duration: 300 }, () => {
                    this.scaleItem = item;
                  })
                })
                .onActionEnd(() => {
                  this.getUIContext()?.animateTo({ curve: Curve.Friction, duration: 300 }, () => {
                    this.scaleItem = -1;
                  })
                }),
              PanGesture({ fingers: 1, direction: null, distance: 0 })
                .onActionStart(() => {
                  this.dragItem = item;
                  this.dragRefOffsetX = 0;
                  this.dragRefOffsetY = 0;
                })
                .onActionUpdate((event: GestureEvent) => {
                  this.offsetY = event.offsetY - this.dragRefOffsetY;
                  this.offsetX = event.offsetX - this.dragRefOffsetX;
                  this.getUIContext()?.animateTo({ curve: curves.interpolatingSpring(0, 1, 400, 38) }, () => {
                    let index = this.numbers.indexOf(this.dragItem);
                    if (this.offsetY >= this.FIX_VP_Y / 2 && (this.offsetX <= 44 && this.offsetX >= -44) &&
                      ![8, 9, 10].includes(index)) {
                      // Swipe down.
                      this.down(index);
                    } else if (this.offsetY <= -this.FIX_VP_Y / 2 && (this.offsetX <= 44 && this.offsetX >= -44) &&
                      ![0, 1, 2].includes(index)) {
                      // Swipe up.
                      this.up(index);
                    } else if (this.offsetX >= this.FIX_VP_X / 2 && (this.offsetY <= 50 && this.offsetY >= -50) &&
                      ![2, 5, 8, 10].includes(index)) {
                      // Swipe right.
                      this.right(index);
                    } else if (this.offsetX <= -this.FIX_VP_X / 2 && (this.offsetY <= 50 && this.offsetY >= -50) &&
                      ![0, 3, 6, 9].includes(index)) {
                      // Swipe left.
                      this.left(index);
                    } else if (this.offsetX >= this.FIX_VP_X / 2 && this.offsetY >= this.FIX_VP_Y / 2 &&
                      ![2, 5, 7, 8, 9, 10].includes(index)) {
                      // Swipe to the lower right.
                      this.lowerRight(index);
                    } else if (this.offsetX >= this.FIX_VP_X / 2 && this.offsetY <= -this.FIX_VP_Y / 2 &&
                      ![0, 1, 2, 5, 8].includes(index)) {
                      // Swipe to the upper right.
                      this.upperRight(index);
                    } else if (this.offsetX <= -this.FIX_VP_X / 2 && this.offsetY >= this.FIX_VP_Y / 2 &&
                      ![0, 3, 6, 9, 10].includes(index)) {
                      // Swipe to the lower left.
                      this.lowerLeft(index);
                    } else if (this.offsetX <= -this.FIX_VP_X / 2 && this.offsetY <= -this.FIX_VP_Y / 2 &&
                      ![0, 1, 2, 3, 6, 9].includes(index)) {
                      // Swipe to the upper left.
                      this.upperLeft(index);
                    } else if (this.offsetX >= this.FIX_VP_X / 2 && this.offsetY >= this.FIX_VP_Y / 2 &&
                    [7].includes(index)) {
                      // Swipe to the lower right (in a grid where the lower right corner is empty).
                      this.down2(index);
                    }
                  })
                })
                .onActionEnd(() => {
                  this.getUIContext()?.animateTo({ curve: curves.interpolatingSpring(0, 1, 400, 38) }, () => {
                    this.dragItem = -1;
                  })
                  this.getUIContext()?.animateTo({
                    curve: curves.interpolatingSpring(14, 1, 170, 17), delay: 150
                  }, () => {
                    this.scaleItem = -1;
                  })
                })
            )
              .onCancel(() => {
                this.getUIContext()?.animateTo({ curve: curves.interpolatingSpring(0, 1, 400, 38) }, () => {
                  this.dragItem = -1;
                })
                this.getUIContext()?.animateTo({
                  curve: curves.interpolatingSpring(14, 1, 170, 17)
                }, () => {
                  this.scaleItem = -1;
                })
              })
          )
        }, (item: number) => item.toString())
      }
      .width('90%')
      .editMode(true)
      .scrollBar(BarState.Off)
      .columnsTemplate('1fr 1fr 1fr')
    }.width('100%').height('100%').backgroundColor('#0D182431').padding({ top: 5 })
  }
}
```

![gridCustomDrag](figures/gridCustomDrag.gif)

### Example 17: Dragging Grid Items with Drag Events

This example demonstrates dragging **GridItem** components to the **Grid** component's edges to trigger automatic scrolling, implemented through [drag events](./ts-universal-events-drag-drop.md).

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
// xxx.ets
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct Example {
  numbers: GridDataSource = new GridDataSource([]);

  aboutToAppear(): void {
    let list: string[] = [];
    for (let index = 0; index < 100; index++) {
      list.push(index.toString());
    }
    this.numbers = new GridDataSource(list);
  }

  changeIndex(index1: number, index2: number) { // Exchange the array positions.
    console.info(index1 + 'index2:' + index2);
    this.numbers.swapItem(index1, index2);
  }

  build() {
    Column({ space: 5 }) {
      Grid() {
        LazyForEach(this.numbers, (item: string, index: number) => {
          GridItem() {
            Text(item + '')
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width(80)
              .height(80)
              .textAlign(TextAlign.Center)
          }
          .width(90)
          .height(90)
          .selectable(true)
          .selected(true)
          .allowDrop([])
          .onDragStart((event: DragEvent) => {
            return { extraInfo: index + '' };
          })
          .onDragEnter((event: DragEvent, extraParams?: string) => {
            console.info(index + '' + extraParams);
          })
          .onDragEnd((event: DragEvent, extraParams?: string) => {
            console.info('onDragEnd' + index + '' + extraParams);
          })
          .onDrop((event?: DragEvent, extraParams?: string) => {
            console.info('drop:' + item + '' + extraParams + JSON.stringify(event!));
            this.changeIndex(parseInt(JSON.parse(extraParams!).extraInfo), index);
          })
        }, (item: string, index: number) => item + '+' + index)
      }
      .columnsGap(5)
      .rowsGap(5)
      .columnsTemplate('1fr 1fr 1fr')
      .height(300)
    }
    .width('100%')
  }
}
```

![universal-drag-drop-GridItem](figures/universal-drag-drop-GridItem.gif)

### Example 18: Configuring the Number of Columns in the Grid Component Based on Breakpoints

In API version 22 and later versions, this example shows how to configure the number of columns in the **Grid** component based on breakpoints.

<!--code_no_check-->

```ts
// Index.ets
// xxx.ets
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource([]);

  aboutToAppear() {
    let list: string[] = [];
    for (let i = 0; i < 5; i++) {
      for (let j = 0; j < 5; j++) {
        list.push(j.toString());
      }
    }
    this.numbers = new GridDataSource(list);
  }

  build() {
    Column({ space: 5 }) {
      Grid(undefined) {
        LazyForEach(this.numbers, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height(80)
              .textAlign(TextAlign.Center)
          }
        }, (index: number) => index.toString())
      }
      .columnsTemplate({fillType:PresetFillType.BREAKPOINT_SM2MD3LG5})
      .columnsGap(10)
      .rowsGap(10)
      .scrollBar(BarState.Off)
      .width('100%')
      .backgroundColor(0xFAEEE0)
      .height(300)
    }.width('100%').height('10%').justifyContent(FlexAlign.SpaceBetween)
  }
}
```

When the grid width is within the breakpoint range of sm or smaller, two columns are displayed.

![sm_grid](figures/grid_itemFillPolicy_SM.png)

When the grid width is within the breakpoint range of md, three columns are displayed.

![md_grid](figures/grid_itemFillPolicy_MD.png)

When the grid width is within the breakpoint range of lg or larger, five columns are displayed.

![lg_grid](figures/grid_itemFillPolicy_LG.png)

### Example 19: Obtaining the Total Content Size

This example demonstrates how to obtain the total content size. This functionality is supported since API version 22.

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
import { GridDataSource } from './GridDataSource';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource([]);
  scroller: Scroller = new Scroller();
  @State contentWidth: number = -1;
  @State contentHeight: number = -1;

  aboutToAppear() {
    let list: string[] = [];
    for (let i = 0; i < 10; i++) {
      for (let j = 0; j < 5; j++) {
        list.push(j.toString());
      }
    }
    this.numbers = new GridDataSource(list);
  }

  build() {
    Column({ space: 5 }) {
      Text('Scrollable Grid and LazyForEach')
      Row() {
        // Button to obtain the content size.
        Button('GetContentSize')
          .onClick(() => {
            // Scroller throws an exception when not bound to a component; wrap with try-catch for safety.
            try {
              // Obtain the content width using contentSize.
              this.contentWidth = this.scroller.contentSize().width;
              // Obtain the content height using contentSize.
              this.contentHeight = this.scroller.contentSize().height;
            } catch (error) {
              let err: BusinessError = error as BusinessError;
              console.error(`Failed to get contentSize of the grid, code=${err.code}, message=${err.message}`);
            }
          })
        // Display the obtained content size.
        Text('Width: ' + this.contentWidth + ', Height: ' + this.contentHeight)
          .fontColor(Color.Red)
          .height(50)
      }

      Grid(this.scroller) {
        LazyForEach(this.numbers, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height(80)
              .textAlign(TextAlign.Center)
          }
          .margin(20)
        }, (index: number) => index.toString())
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .friction(0.6)
      .enableScrollInteraction(true)
      .supportAnimation(false)
      .multiSelectable(false)
      .edgeEffect(EdgeEffect.Spring)
      .scrollBar(BarState.On)
      .scrollBarColor(Color.Grey)
      .scrollBarWidth(4)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![gridContentSize](figures/gridContentSize.gif)

### Example 20: Setting the Multi-selection Gather Animation

This example enables the multi-select gather animation switch of the **Grid** to implement the effect of gathering the selected **GridItem** items within the display range through [bindContextMenu](ts-universal-attributes-menu.md#bindcontextmenu8) when a context menu is popped up by long pressing a **GridItem**.

Since API version 23, the [editModeOptions](#editmodeoptions23) API is added to the **Grid** component to set the multi-selection gather animation switch.

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
// xxx.ets
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource(['1', '2', '3', '4', '5', '6', '7', '8', '9']);
  @State isSelected: boolean[] = [];
  selectedCount: number = 0;

  @Styles
  normalStyles(): void {
    .opacity(1.0)
  }

  @Styles
  selectStyles(): void {
    .opacity(0.4)
  }

  onPageShow(): void {
    let i: number = 0;
    for (i = 0; i < 9; i++) {
      this.isSelected.push(false);
    }
  }

  @Builder
  MenuBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('menu item 1')
        .fontSize(18)
        .width(120)
        .height(50)
        .textAlign(TextAlign.Center)
      Divider().height(10)
      Text('menu item 2')
        .fontSize(18)
        .width(120)
        .height(50)
        .textAlign(TextAlign.Center)
    }.width(100)
  }

  build() {
    Column({ space: 5 }) {
      Text('Grid')
      Grid() {
        LazyForEach(this.numbers, (day: string, index: number) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height('100%')
              .textAlign(TextAlign.Center)
          }
          .selected(this.isSelected[index])
          // Set the multi-selection display effects.
          .stateStyles({
            normal: this.normalStyles,
            selected: this.selectStyles
          })
          .bindContextMenu(this.MenuBuilder, ResponseType.LongPress,
            { preview: MenuPreviewMode.IMAGE, hapticFeedbackMode: HapticFeedbackMode.ENABLED })
          .onClick(() => {
            this.isSelected[index] = !this.isSelected[index];
            console.info(`item:${index}, this.isSelected[item]:${this.isSelected[index]}`)
            if (this.isSelected[index]) {
              ++this.selectedCount;
            } else {
              --this.selectedCount;
            }
          })
        }, (day: string) => day)
      }
      .editModeOptions({
        enableGatherSelectedItemsAnimation: true, onGetPreviewBadge: () => {
          return this.selectedCount;
        }
      })
      .columnsTemplate('1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![gridMultiselectAnimation](figures/gridMultiselectAnimation.gif)

### Example 21: Implementing Swipe-based Multi-Selection

This example uses the two-way binding of `enableEditMode` and the `onEditModeChange` event to listen for the notification of entering the multi-select mode by swiping with two fingers on the **Grid**, implementing the effect of selecting while swiping on the **Grid**.

Since API version 26.0.0, the **Grid** component adds the [enableEditMode](#enableeditmode) API and the [onEditModeChange](#oneditmodechange) event.

For details about **GridDataSource** and the complete code, see [Example 2: Implementing a Scrollable Grid with Scroll Events](#example-2-implementing-a-scrollable-grid-with-scroll-events).

<!--code_no_check-->

```ts
// xxx.ets
import { GridDataSource } from './GridDataSource';

@Entry
@Component
struct GridExample {
  numbers: GridDataSource = new GridDataSource([]);
  @State @Watch('onEditModeChanged') enableEditMode: boolean = false;
  @State enableTwoFingerSelect: boolean = false;
  @State selectedIndexes: number[] = [];

  onEditModeChanged() {
    console.info(`enableEditMode changed to: ${this.enableEditMode}`);
    if (!this.enableEditMode) {
      console.info('enableEditMode changed to false, clearing selectedIndexes');
      this.selectedIndexes = [];
    }
  }

  aboutToAppear() {
    let list: string[] = [];
    for (let i = 0; i < 20; i++) {
      for (let j = 0; j < 20; j++) {
        list.push((20 * i + j + 1).toString());
      }
    }
    this.numbers = new GridDataSource(list);
  }

  build() {
    Column({ space: 5 }) {
      Grid() {
        LazyForEach(this.numbers, (day: string, index: number) => {
          GridItem() {
            Stack() {
              Text(day)
                .fontSize(16)
                .backgroundColor(0xF9CF93)
                .width('100%')
                .height(80)
                .textAlign(TextAlign.Center)
            }
          }
          .selected(this.selectedIndexes.includes(index))
          .onSelect((isSelected: boolean) => {
            console.info('item ' + index.toString() + ' is ' + (isSelected ? 'selected' : 'unselected'));
            if (isSelected) {
              this.selectedIndexes.push(index);
            } else {
              let deleted = this.selectedIndexes.findIndex((value) => value === index);
              if (deleted !== -1) {
                this.selectedIndexes.splice(deleted, 1);
              }
            }
          })
        }, (index: number) => index.toString())
      }
      .columnsTemplate('1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .width('90%')
      .height('50%')
      .backgroundColor(0xFAEEE0)
      .enableEditMode(this.enableEditMode!!)
      .onEditModeChange((data: boolean) => {
        // You can also implement the business logic in onEditModeChanged here instead of using the enableEditMode two-way binding.
        console.info(`onEditModeChange:${data}`)
      })
      .editModeOptions({ useDefaultMultiSelectStyle: true, enableTwoFingerMultiSelect: this.enableTwoFingerSelect })

      Row() {
        Button('EditMode: ' + this.enableEditMode).onClick(() => {
          this.enableEditMode = !this.enableEditMode;
        })
        Button('TwoFinger: ' + this.enableTwoFingerSelect).onClick(() => {
          this.enableTwoFingerSelect = !this.enableTwoFingerSelect;
        })
      }
      .margin({
        bottom: 30
      })
    }.width('100%').margin({ top: 5 })
  }
}
```

![grid_two_finger_select](figures/grid_two_finger_select.gif)

### Example 22: Dragging with OnMove

Since API version 26.0.0, this example demonstrates the effect of drag sorting using the [onMove](./ts-universal-attributes-drag-sorting.md#onmove) API of **LazyForEach** in the **Grid**. It supports triggering automatic scrolling of the **Grid** when dragging to the edge, and the **Grid** contains nodes that span rows and columns.

```ts
// RectGridDataSource.ets
export class Rects {
  id: number = 0
  // rectSize indicates the number of [rows, columns] occupied by the GridItem. The default value [1, 1] indicates a regular node.
  rectSize: [number, number] = [1, 1]
  constructor(id_: number) {
    this.id = id_
  }
}

// Data source of LazyForEach, which implements the IDataSource interface and manages data and notifies the UI to refresh.
export class RectGridDataSource implements IDataSource {
  private list: Array<Rects> = [];
  private listeners: DataChangeListener[] = [];

  constructor(list: Rects[]) {
    this.list = list;
  }

  // Return the total number of data items.
  totalCount(): number {
    return this.list.length;
  }

  // Obtain the corresponding data item by index.
  getData(index: number): Rects {
    return this.list[index];
  }

  // Register a data change listener.
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  // Unregister the data change listener.
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  // Notify the controller of the data position change.
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    })
  }

  // Reload all data.
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  // Move the element at the from position to the to position, and notify the UI to reload and refresh all data.
  public moveItem(from: number, to: number): void {
    let tmp = this.list.splice(from, 1);  // Remove the dragged item first.
    this.list.splice(to, 0, tmp[0]);      // Insert the dragged item into the target position.
    this.notifyDataReload()
  }
}
```

```ts
// xxx.ets
import { RectGridDataSource, Rects } from './RectGridDataSource';

@Entry
@Component
struct GridOnMoveExample {
  numbers: RectGridDataSource = new RectGridDataSource([]);

  // Grid layout options (actually effective), which declare the indexes of irregular nodes and the number of rows and columns occupied by each.
  @State layoutOptions: GridLayoutOptions = {
    regularSize: [1, 1],
    irregularIndexes: [4, 5, 6, 7, 8, 13],   // Set which indexes correspond to irregular GridItem nodes.
    onGetIrregularSizeByIndex: (index: number) => {
      return this.numbers.getData(index).rectSize
    }
  };

  // Layout options (backup), used to trigger the refresh of layoutOptions through overall assignment during dragging.
  layoutOptions_back: GridLayoutOptions = {
    regularSize: [1, 1],
    irregularIndexes: [4, 5, 6, 7, 8, 13],
    onGetIrregularSizeByIndex: (index: number) => {
      return this.numbers.getData(index).rectSize
    }
  };

  build() {
    Row() {
      Grid(undefined, this.layoutOptions) {
        LazyForEach(this.numbers, (item: Rects) => {
          GridItem() {
            Text(item.id.toString())
              .fontSize(16)
              .textAlign(TextAlign.Center)
              // Set the height. A GridItem spanning rows needs extra margins (the spacing of a regular GridItem is 2*10) for UI alignment.
              .size({ height: 100 * item.rectSize[0] + (item.rectSize[0] - 1) * 20, width: '100%'})
          }.margin(10)
          .borderRadius(10)
          .backgroundColor(0xF9CF93)
        }, (index: Rects) => index.id.toString())
          // Triggered when the dragged item is released and its landing position differs from that before dragging. from is the start index, and to is the target index.
          .onMove((from:number, to:number) => {
            console.info("Grid onMove from " + from + " to " + to)
            // Update the data source.
            this.numbers.moveItem(from, to)
            if (from < to) {  // The index of the dragged item is smaller than the target position index.
              // Save the position of the dragged item in the irregularIndexes array first to avoid indexOf locating errors caused by duplicate values generated in subsequent loop updates.
              let from_idx = -1
              if (this.layoutOptions.irregularIndexes?.includes(from)) {
                from_idx = this.layoutOptions.irregularIndexes.indexOf(from)
              }

              // Move the elements between the dragged item and the target position forward by one position (index -1).
              if (this.layoutOptions.irregularIndexes != undefined) {
                let len = this.layoutOptions.irregularIndexes.length
                for (let i = len - 1; i >= 0; i --) {
                  let irregularIndex = this.layoutOptions.irregularIndexes[i]
                  if (irregularIndex > from && irregularIndex <= to) {
                    this.layoutOptions.irregularIndexes[i] --
                  }
                }
              }

              // If the dragged item itself is an irregular node, update its index to the target position.
              if (from_idx != -1 && this.layoutOptions.irregularIndexes != undefined) {
                this.layoutOptions.irregularIndexes[from_idx] = to
              }
            } else {  // The index of the dragged item is greater than or equal to the target position index.
              // Save the position of the dragged item in the irregularIndexes array first to avoid indexOf locating errors caused by duplicate values generated in subsequent loop updates.
              let from_idx = -1
              if (this.layoutOptions.irregularIndexes?.includes(from)) {
                from_idx = this.layoutOptions.irregularIndexes.indexOf(from)
              }

              // Move the elements between the target position and the dragged item backward by one position (index +1).
              if (this.layoutOptions.irregularIndexes != undefined) {
                let len = this.layoutOptions.irregularIndexes.length
                for (let i = 0; i < len; i ++) {
                  let irregularIndex = this.layoutOptions.irregularIndexes[i]
                  if (irregularIndex >= to && irregularIndex < from) {
                    this.layoutOptions.irregularIndexes[i] ++
                  }
                }
              }

              // If the dragged item itself is an irregular node, update its index to the target position.
              if (from_idx != -1 && this.layoutOptions.irregularIndexes != undefined) {
                this.layoutOptions.irregularIndexes[from_idx] = to
              }
            }
            // Force layoutOptions to refresh and take effect through overall assignment of the backup object.
            this.layoutOptions_back.irregularIndexes = this.layoutOptions.irregularIndexes
            this.layoutOptions = this.layoutOptions_back
            console.info("Grid this.layoutOptions.irregularIndexes " + this.layoutOptions.irregularIndexes)
          },
            {
              onLongPress: (index: number) => {
                // Triggered when the GridItem is lifted after a long press.
                console.info('Grid onLongPress: ' + index);
              },
              onDrop: (index: number) => {
                // Triggered when the dragged GridItem is released.
                console.info('Grid onDrop: ' + index);
              },
              onDragStart: (index: number) => {
                // Triggered when the GridItem is lifted after a long press and dragging starts.
                console.info('Grid onDragStart: ' + index);
              },
              onMoveThrough: (from: number, to: number) => {
                // Triggered continuously during GridItem dragging.
                console.info('Grid onMoveThrough From: ' + from + ' to: ' + to);
              }
            })
      }
      .columnsTemplate('1fr 1fr 1fr 1fr')   // Four-column equal-width layout.
      .width('100%')
      .height('100%')
      .backgroundColor(0xFAEEE0)
    }
  }

  aboutToAppear(): void {
    // Initialize 100 rectangle data items and set the spanning size of each irregular node.
    let list: Rects[] = [];
    for (let i = 0; i < 100; i++) {
      list.push(new Rects(i));
    }
    list[4].rectSize = [2, 2] // 2 rows and 2 columns.
    list[5].rectSize = [1, 2] // 1 row and 2 columns.
    list[6].rectSize = [1, 2] // 1 row and 2 columns.
    list[7].rectSize = [2, 1] // 2 rows and 1 column.
    list[8].rectSize = [2, 1] // 2 rows and 1 column.
    list[13].rectSize = [1, 4]  // 1 row and 4 columns.
    this.numbers = new RectGridDataSource(list);
  }
}
```

![grid-onmove-drag](figures/grid-onmove-drag.gif)