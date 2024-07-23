# Custom Component Layout

The custom layout of a custom component is used to lay out its child components through data calculation.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## onPlaceChildren<sup>10+</sup>

onPlaceChildren?(selfLayoutInfo: GeometryInfo, children: Array&lt;Layoutable&gt;, constraint: ConstraintSizeOptions):void

Invoked when the custom component lays out its child components. Through this callback the component receives its child component size constraints from the ArkUI framework. State variables should not be changed in this callback.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name           | Type                                                        | Description              |
|----------------|------------------------------------------------------------|------------------|
| selfLayoutInfo | [GeometryInfo](#geometryinfo10)                            | Layout information of the parent component.        |
| children       | Array&lt;[Layoutable](#layoutable10)&gt;                   | Child component layout information.        |
| constraint     | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | Size constraint of the parent component.|

## onMeasureSize<sup>10+</sup>

onMeasureSize?(selfLayoutInfo: GeometryInfo, children: Array&lt;Measurable&gt;, constraint: ConstraintSizeOptions): SizeResult

Invoked when the custom component needs to determine its size. Through this callback the component receives its child component layout information and size constraint from the ArkUI framework. State variables should not be changed in this callback.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name        | Type                                                      | Description                                                        |
| -------------- | ---------------------------------------------------------- | ------------------------------------------------------------ |
| selfLayoutInfo | [GeometryInfo](#geometryinfo10)                            | Layout information of the parent component.                                            |
| children       | Array&lt;[Measurable](#measurable10)&gt;                   | Child component layout information.<br>**NOTE**<br>When a child component does not have its layout information set, it retains the previous layout settings or, if no previous layout settings are available, stays at the default size of 0.|
| constraint     | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | Size constraint of the parent component.                                      |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| [SizeResult](#sizeresult10) | Component size information.|

## GeometryInfo<sup>10+</sup>

Provides the parent component layout information. Inherits from [SizeResult](#sizeresult10).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name         | Type     | Description                 |
|-------------|-----------|---------------------|
| borderWidth | [EdgeWidth](ts-types.md#edgewidths9) | Border width of the parent component.<br>Unit: vp           |
| margin      | [Margin](ts-types.md#margin)       | Margin of the parent component.<br>Unit: vp      |
| padding     | [Padding](ts-types.md#padding)   | Padding of the parent component.<br>Unit: vp|
| width  | number | Width obtained from the measurement result.<br>Unit: vp<br> **NOTE**<br>If the value is empty, the component width in percentage is returned.|
| height | number | Height obtained from the measurement result.<br>Unit: vp<br> **NOTE**<br>If the value is empty, the component height in percentage is returned.|


## Layoutable<sup>10+</sup>

Provides the child component layout information.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Name

| Name        | Type      | Mandatory     |  Description                                                     |
|--------------|---------------------------------- | -----------------------------------------------|---------------------|
| measureResult| [MeasureResult](#measureresult10)      |   Yes| Measurement result of the child component. Inherits from [SizeResult](#sizeresult10).<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>Unit: vp    |


### layout

layout(position: Position)

Applies the specified position information to the child component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name        | Type                                                   | Mandatory                |Description        |
|-----------------|---------------------------------------------------------|---------------------|-------------|
|   position      | [Position](ts-types.md#position)                        | Yes                 |   Position.  |

### getMargin<sup>12+</sup>

getMargin() : DirectionalEdgesT\<number>

Obtains the margin of the child component.

**Return value**

| Type                         | Description                                       |
|------------------------------------|---------------------------------------------|
| [DirectionalEdgesT&lt;number&gt;](#directionaledgestt12)  |  Margin of the child component.  |

 ### getPadding<sup>12+</sup>

getPadding() : DirectionalEdgesT\<number>

 Obtains the padding of the child component.

 **Return value**

| Type                         | Description                                       |
|------------------------------------|---------------------------------------------|
| [DirectionalEdgesT&lt;number&gt;](#directionaledgestt12)  |  Padding of the child component. |

### getBorderWidth<sup>12+</sup>

getBorderWidth() : DirectionalEdgesT\<number>

Obtains the border width of the child component.

**Return value**

| Type                         | Description                                       |
|------------------------------------|---------------------------------------------|
| [DirectionalEdgesT&lt;number&gt;](#directionaledgestt12)  |  Border width of the child component. |

## Measurable<sup>10+</sup>

Provides the child component position information.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 11.

### measure

 measure(constraint: ConstraintSizeOptions) : MeasureResult

 Applies the size constraint to the child component.

 **System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name        | Type                                                   | Mandatory                |Description        |
|-----------------|---------------------------------------------------------|---------------------|-------------|
|   constraint    | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions)  | Yes           |   Size constraint. |

**Return value**

 | Type                              | Description                    |
 |------------------------------------|-------------------------|
 |[MeasureResult](#measureresult10)   | Provides the measurement result of the component.  |

 ### getMargin<sup>12+</sup>

 getMargin() : DirectionalEdgesT\<number\>

 Obtains the padding of the child component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

 | Type                              | Description                    |
 |------------------------------------|-------------------------|
 |[DirectionalEdgesT&lt;number&gt;](#directionaledgestt12)  | Margin of the child component.  |

### getPadding<sup>12+</sup>

getPadding() : DirectionalEdgesT\<number\>

Obtains the padding of the child component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

 | Type                              | Description                    |
 |------------------------------------|-------------------------|
 |[DirectionalEdgesT&lt;number&gt;](#directionaledgestt12)  | Padding of the child component.  |

 ### getBorderWidth<sup>12+</sup>

getBorderWidth() : DirectionalEdgesT\<number\>

Obtains the border widthof the child component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

 | Type                              | Description                    |
 |------------------------------------|-------------------------|
 |[DirectionalEdgesT&lt;number&gt;](#directionaledgestt12)  | Border width of the child component.|


## MeasureResult<sup>10+</sup>

Provides the measurement result of the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Type  | Description   |
|--------|--------|-------|
| width  | number | Width obtained from the measurement result.<br>Unit: vp|
| height | number | Height obtained from the measurement result.<br>Unit: vp|


## SizeResult<sup>10+</sup>

Provides the component size information.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name    | Type  | Description   |
|--------|--------|-------|
| width  | number | Width obtained from the measurement result.<br>Unit: vp|
| height | number | Height obtained from the measurement result.<br>Unit: vp|

## DirectionalEdgesT\<T><sup>12+</sup>

Defines the directional edges.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

| Name  | Type| Description            |
| ------ | ---- | ---------------- |
| start   | T    | Start edge. It is the left edge if the direction is left-to-right and the right edge if the direction is right-to-left.|
| end    | T    | End edge. It is the right edge if the direction is left-to-right and the left edge if the direction is right-to-left.|
| top  | T    | Top edge.|
| bottom | T    | Top edge.|

> **NOTE**
>
>- The custom layout does not support the LazyForEach syntax.
>- When a custom layout is created in builder mode, only **this.builder()** is allowed in the **build()** method of a custom component, as shown in the recommended usage in the example below.
>- The size parameters of the parent component (custom component), except **aspectRatio**, are at a lower priority than those specified by **onMeasureSize**.
>- The position parameters of the child component, except **offset**, **position**, and **markAnchor**, are at a lower priority than those specified by **onPlaceChildren**, and do not take effect.
>- When using the custom layout method, you must call **onMeasureSize** and **onPlaceChildren** at the same time for the layout to display properly.

**Example 1**
This example demonstrates how to customize a layout.
```
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      CustomLayout({ builder: ColumnChildren })
    }
  }
}

@Builder
function ColumnChildren() {
  ForEach([1, 2, 3], (index: number) => {// LazyForEach is not supported.
    Text('S' + index)
      .fontSize(30)
      .width(100)
      .height(100)
      .borderWidth(2)
      .offset({ x: 10, y: 20 })
  })
}

@Component
struct CustomLayout {
  @Builder
  doNothingBuilder() {
  };

  @BuilderParam builder: () => void = this.doNothingBuilder;
  @State startSize: number = 100;
  result: SizeResult = {
    width: 0,
    height: 0
  };

  onPlaceChildren(selfLayoutInfo: GeometryInfo, children: Array<Layoutable>, constraint: ConstraintSizeOptions) {
    let startPos = 300;
    children.forEach((child) => {
      let pos = startPos - child.measureResult.height;
      child.layout({ x: pos, y: pos })
    })
  }

  onMeasureSize(selfLayoutInfo: GeometryInfo, children: Array<Measurable>, constraint: ConstraintSizeOptions) {
    let size = 100;
    children.forEach((child) => {
      let result: MeasureResult = child.measure({ minHeight: size, minWidth: size, maxWidth: size, maxHeight: size })
      size += result.width / 2
      ;
    })
    this.result.width = 100;
    this.result.height = 400;
    return this.result;
  }

  build() {
    this.builder()
  }
}
```

![custom_layout10.png](figures/custom_layout10.png)

**Example 2**
This example shows how to determine whether a component participates in layout calculation based on its position.
```
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      CustomLayout({ builder: ColumnChildren })
    }
    .justifyContent(FlexAlign.Center)
    .width("100%")
    .height("100%")
  }
}

@Builder
function ColumnChildren() {
  ForEach([1, 2, 3], (item: number, index: number) => { // LazyForEach is not supported.
    Text('S' + item)
      .fontSize(20)
      .width(60 + 10 * index)
      .height(100)
      .borderWidth(2)
      .margin({ left:10 })
      .padding(10)
  })
}

@Component
struct CustomLayout {
  // Lay out only one row, and hide child components that are too large for the available space.
  @Builder
  doNothingBuilder() {
  };

  @BuilderParam builder: () => void = this.doNothingBuilder;
  result: SizeResult = {
    width: 0,
    height: 0
  };
  overFlowIndex: number = -1;

  onPlaceChildren(selfLayoutInfo: GeometryInfo, children: Array<Layoutable>, constraint: ConstraintSizeOptions) {
    let currentX = 0;
    let infinity = 100000;
    if (this.overFlowIndex == -1) {
      this.overFlowIndex = children.length;
    }
    for (let index = 0; index < children.length; ++index) {
      let child = children[index];
      if (index >= this.overFlowIndex) {
        // Hide any child component that extends beyond the area of its parent component by placing it in a distant position.
        child.layout({x: infinity, y: 0});
        continue;
      }
      child.layout({ x: currentX, y: 0 })
      let margin = child.getMargin();
      currentX += child.measureResult.width + margin.start + margin.end;
    }
  }

  onMeasureSize(selfLayoutInfo: GeometryInfo, children: Array<Measurable>, constraint: ConstraintSizeOptions) {
    let width = 0;
    let height = 0;
    this.overFlowIndex = -1;
    // Assume that the component width cannot exceed 200 vp or the maximum constraint.
    let maxWidth = Math.min(200, constraint.maxWidth as number);
    for (let index = 0; index < children.length; ++index) {
      let child = children[index];
      let childResult: MeasureResult = child.measure({
          minHeight: constraint.minHeight,
          minWidth: constraint.minWidth,
          maxWidth: constraint.maxWidth,
          maxHeight: constraint.maxHeight
      })
      let margin = child.getMargin();
      let newWidth = width + childResult.width + margin.start + margin.end;
      if (newWidth > maxWidth) {
        // Record the index of the component that should not be laid out.
        this.overFlowIndex = index;
        break;
      }
      // Accumulate the width and height of the parent component.
      width = newWidth;
      height = Math.max(height, childResult.height + margin.top + margin.bottom);
    }
    this.result.width = width;
    this.result.height = height;
    return this.result;
  }

  build() {
    this.builder()
  }
}
```

![custom_layout_demo2.png](figures/custom_layout_demo2.png)

## onLayout<sup>(deprecated)</sup>

onLayout?(children: Array&lt;LayoutChild&gt;, constraint: ConstraintSizeOptions): void

Invoked when the custom component lays out its child components. Through this callback the component receives its child component layout information and size constraint from the ArkUI framework. State variables should not be changed in this callback.

This API is supported since API version 9 and deprecated since API version 10. You are advised to use [onPlaceChildren](#onplacechildren10) instead.

**Parameters**

| Name       | Type                                                        | Description              |
|------------|------------------------------------------------------------|------------------|
| children   | Array&lt;[LayoutChild](#layoutchilddeprecated)&gt;                  | Child component layout information.        |
| constraint | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | Size constraint of the parent component.|

## onMeasure<sup>(deprecated)</sup>

onMeasure?(children: Array&lt;LayoutChild&gt;, constraint: ConstraintSizeOptions): void

Invoked when the custom component needs to determine its size. Through this callback the component receives its child component layout information and size constraint from the ArkUI framework. State variables should not be changed in this callback.

This API is supported since API version 9 and deprecated since API version 10. You are advised to use [onMeasureSize](#onmeasuresize10) instead.

**Parameters**

| Name       | Type                                                        | Description              |
|------------|------------------------------------------------------------|------------------|
| children   | Array&lt;[LayoutChild](#layoutchilddeprecated)&gt;                  | Child component layout information.        |
| constraint | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | Size constraint of the parent component.|

## LayoutChild<sup>(deprecated)</sup>

Child component layout information.

This API is supported since API version 9 and deprecated since API version 10. It is supported in ArkTS widgets.


| Name      | Type                                                    | Description                                  |
| ---------- | ------------------------------------------------------------ | -------------------------------------- |
| name       | string                                                       | Name of the child component.                          |
| id         | string                                                       | ID of the child component.                            |
| constraint | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions)   | Constraint size of the child component.                      |
| borderInfo | [LayoutBorderInfo](#layoutborderinfodeprecated)              | Provides the border information of the child component.                    |
| position   | [Position](ts-types.md#position)                             | Position coordinates of the child component.                      |
| measure    | (childConstraint: [ConstraintSizeOptions](ts-types.md#constraintsizeoptions))&nbsp;=&gt;&nbsp;void | Method called to apply the size constraint to the child component.|
| layout     | (LayoutInfo: [LayoutInfo](#layoutinfodeprecated))&nbsp;=&gt;&nbsp;void | Method called to apply the specified position information to the child component.|

## LayoutBorderInfo<sup>(deprecated)</sup>

Provides the border information of the child component.

This API is supported since API version 9 and deprecated since API version 10. It is supported in ArkTS widgets.

| Name         | Type                                | Description                     |
|-------------|--------------------------------------|-------------------------|
| borderWidth | [EdgeWidths](ts-types.md#edgewidths9) | Edge widths in different directions of the component.|
| margin      | [Margin](ts-types.md#margin)         | Margins in different directions of the component.  |
| padding     | [Padding](ts-types.md#padding)       | Paddings in different directions of the component.  |

## LayoutInfo<sup>(deprecated)</sup>

Provides the layout information of the child component.

This API is supported since API version 9 and deprecated since API version 10. It is supported in ArkTS widgets.

| Name      | Type                                                  | Description            |
| ---------- | ---------------------------------------------------------- | ---------------- |
| position   | [Position](ts-types.md#position)                           | Position coordinates of the child component.|
| constraint | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | Constraint size of the child component.|

The layout can be modified through **layout**.
```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      CustomLayout() {
        ForEach([1, 2, 3], (index: number) => {
          Text('Sub' + index)
            .fontSize(30)
            .borderWidth(2)
        })
      }
    }
  }
}


@Component
struct CustomLayout {
  @Builder
  doNothingBuilder() {
  };

  @BuilderParam builder: () => void = this.doNothingBuilder;

  onLayout(children: Array<LayoutChild>, constraint: ConstraintSizeOptions) {
    let pos = 0;
    children.forEach((child) => {
      child.layout({ position: { x: pos, y: pos }, constraint: constraint })
      pos += 70;
    })
  }

  onMeasure(children: Array<LayoutChild>, constraint: ConstraintSizeOptions) {
    let size = 100;
    children.forEach((child) => {
      child.measure({ minHeight: size, minWidth: size, maxWidth: size, maxHeight: size })
      size += 50;
    })
  }

  build() {
    this.builder()
  }
}
```

![en-us_image_0000001511900496](figures/en-us_image_0000001511900496.png)
