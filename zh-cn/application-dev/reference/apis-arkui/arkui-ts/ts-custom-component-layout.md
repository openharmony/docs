# 自定义组件的自定义布局

自定义组件的自定义布局用于通过数据计算的方式布局自定义组件内的子组件。

>**说明：**
>
>- 本模块首批接口从API version 9开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## onPlaceChildren<sup>10+</sup>

onPlaceChildren?(selfLayoutInfo: GeometryInfo, children: Array&lt;Layoutable&gt;, constraint: ConstraintSizeOptions):void

ArkUI框架会在自定义组件布局时，将该自定义组件的子节点自身的尺寸范围通过onPlaceChildren传递给该自定义组件。不允许在onPlaceChildren函数中改变状态变量。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**参数：**

| 参数名            | 类型                                                         | 说明               |
|----------------|------------------------------------------------------------|------------------|
| selfLayoutInfo | [GeometryInfo](#geometryinfo10)                            | 父组件布局信息。         |
| children       | Array&lt;[Layoutable](#layoutable10)&gt;                   | 子组件布局信息。         |
| constraint     | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | 父组件constraint信息。 |

## onMeasureSize<sup>10+</sup>

onMeasureSize?(selfLayoutInfo: GeometryInfo, children: Array&lt;Measurable&gt;, constraint: ConstraintSizeOptions): SizeResult

ArkUI框架会在自定义组件确定尺寸时，将该自定义组件的节点信息和尺寸范围通过onMeasureSize传递给该开发者。不允许在onMeasureSize函数中改变状态变量。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**参数：**

| 参数名         | 类型                                                       | 说明                                                         |
| -------------- | ---------------------------------------------------------- | ------------------------------------------------------------ |
| selfLayoutInfo | [GeometryInfo](#geometryinfo10)                            | 父组件布局信息。                                             |
| children       | Array&lt;[Measurable](#measurable10)&gt;                   | 子组件布局信息。<br/>**说明：** <br/>如果没有设置子组件的布局信息，子组件会维持上一次的布局信息，当子组件从来没有设置过尺寸时，尺寸默认为0。 |
| constraint     | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | 父组件constraint信息。                                       |

**返回值：** 

| 类型                        | 描述           |
| --------------------------- | -------------- |
| [SizeResult](#sizeresult10) | 组件尺寸信息。 |

## GeometryInfo<sup>10+</sup>

父组件布局信息。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 属性          | 属性类型      | 描述                  |
|-------------|-----------|---------------------|
| borderWidth | [EdgeWidth](ts-types.md#edgewidths9) | 父组件边框宽度。<br>单位：vp            |
| margin      | [Margin](ts-types.md#margin)       | 父组件margin信息。 <br>单位：vp       |
| padding     | [Padding](ts-types.md#padding)   | 父组件padding信息。<br>单位：vp |
| width  | number | 测量后的宽。<br>单位：vp<br> **说明：** <br>若值为空时，则返回组件的百分比宽。 |
| height | number | 测量后的高。<br>单位：vp<br> **说明：** <br>若值为空时，则返回组件的百分比高。 |


## Layoutable<sup>10+</sup>

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

子组件布局信息。

| 属性         | 属性类型                                                    | 描述                  |
|------------|---------------------------------------------------------|---------------------|
| measureResult| [MeasureResult](#measureresult10)      | 子组件测量后的尺寸信息。   <br>单位：vp     |
| layout     | (position: [Position](ts-types.md#position))&nbsp;=&gt;&nbsp;void | 调用此方法对子组件的位置信息进行限制。 |

## Measurable<sup>10+</sup>

子组件位置信息。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 属性         | 属性类型                                                                             | 描述                                    |
|------------|----------------------------------------------------------------------------------|---------------------------------------|
| measure    | (childConstraint: [ConstraintSizeOptions](ts-types.md#constraintsizeoptions))&nbsp;=&gt;&nbsp;[MeasureResult](#measureresult10) | 调用此方法对子组件的尺寸范围进行限制。<br/>返回值：子组件测量后的尺寸。 |

## MeasureResult<sup>10+</sup>

测量后的组件布局信息。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 属性     | 属性类型   | 描述    |
|--------|--------|-------|
| width  | number | 测量后的宽。<br>单位：vp |
| height | number | 测量后的高。<br>单位：vp |


## SizeResult<sup>10+</sup>

组件尺寸信息。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 属性     | 属性类型   | 描述    |
|--------|--------|-------|
| width  | number | 测量后的宽。<br>单位：vp |
| height | number | 测量后的高。<br>单位：vp |

> **说明：**
>
>- 自定义布局暂不支持LazyForEach写法。
>- 使用builder形式的自定义布局创建，自定义组件的build()方法内只允许存在this.builder()，即示例的推荐用法。
>- 父容器（自定义组件）上设置的尺寸信息，除aspectRatio之外，优先级小于onMeasureSize设置的尺寸信息。
>- 子组件设置的位置信息，offset、position、markAnchor优先级大于onPlaceChildren设置的位置信息，其他位置设置属性不生效。
>- 使用自定义布局方法时，需要同时调用onMeasureSize和onPlaceChildren方法，否则可能出现布局异常。

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
  ForEach([1, 2, 3], (index: number) => { //暂不支持lazyForEach的写法
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

## onLayout<sup>(deprecated)</sup>

onLayout?(children: Array&lt;LayoutChild&gt;, constraint: ConstraintSizeOptions): void

ArkUI框架会在自定义组件布局时，将该自定义组件的子节点信息和自身的尺寸范围通过onLayout传递给该自定义组件。不允许在onLayout函数中改变状态变量。

该接口从API version 9开始支持，从API version 10开始废弃，推荐使用[onPlaceChildren](#onplacechildren10)替代。

**参数：**

| 参数名        | 类型                                                         | 说明               |
|------------|------------------------------------------------------------|------------------|
| children   | Array&lt;[LayoutChild](#layoutchilddeprecated)&gt;                  | 子组件布局信息。         |
| constraint | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | 父组件constraint信息。 |

## onMeasure<sup>(deprecated)</sup>

onMeasure?(children: Array&lt;LayoutChild&gt;, constraint: ConstraintSizeOptions): void

ArkUI框架会在自定义组件确定尺寸时，将该自定义组件的子节点信息和自身的尺寸范围通过onMeasure传递给该自定义组件。不允许在onMeasure函数中改变状态变量。

该接口从API version 9开始支持，从API version 10开始废弃，推荐使用[onMeasureSize](#onmeasuresize10)替代。

**参数：**

| 参数名        | 类型                                                         | 说明               |
|------------|------------------------------------------------------------|------------------|
| children   | Array&lt;[LayoutChild](#layoutchilddeprecated)&gt;                  | 子组件布局信息。         |
| constraint | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | 父组件constraint信息。 |

## LayoutChild<sup>(deprecated)</sup>

子组件布局信息。

从API version 9开始，从API version 10开始废弃，该接口支持在ArkTS卡片中使用。


| 属性       | 属性类型                                                     | 描述                                   |
| ---------- | ------------------------------------------------------------ | -------------------------------------- |
| name       | string                                                       | 子组件名称。                           |
| id         | string                                                       | 子组件id。                             |
| constraint | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions)   | 子组件约束尺寸。                       |
| borderInfo | [LayoutBorderInfo](#layoutborderinfodeprecated)              | 子组件border信息。                     |
| position   | [Position](ts-types.md#position)                             | 子组件位置坐标。                       |
| measure    | (childConstraint: [ConstraintSizeOptions](ts-types.md#constraintsizeoptions))&nbsp;=&gt;&nbsp;void | 调用此方法对子组件的尺寸范围进行限制。 |
| layout     | (LayoutInfo: [LayoutInfo](#layoutinfodeprecated))&nbsp;=&gt;&nbsp;void | 调用此方法对子组件的位置信息进行限制。 |

## LayoutBorderInfo<sup>(deprecated)</sup>

子组件border信息。

从API version 9开始，从API version 10开始废弃，该接口支持在ArkTS卡片中使用。

| 属性          | 属性类型                                 | 描述                      |
|-------------|--------------------------------------|-------------------------|
| borderWidth | [EdgeWidths](ts-types.md#edgewidths9) | 边框宽度类型，用于描述组件边框不同方向的宽度。 |
| margin      | [Margin](ts-types.md#margin)         | 外边距类型，用于描述组件不同方向的外边距。   |
| padding     | [Padding](ts-types.md#padding)       | 内边距类型，用于描述组件不同方向的内边距。   |

## LayoutInfo<sup>(deprecated)</sup>

子组件layout信息。

从API version 9开始，从API version 10开始废弃，该接口支持在ArkTS卡片中使用。

| 属性       | 属性类型                                                   | 描述             |
| ---------- | ---------------------------------------------------------- | ---------------- |
| position   | [Position](ts-types.md#position)                           | 子组件位置坐标。 |
| constraint | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | 子组件约束尺寸。 |

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

![zh-cn_image_0000001511900496](figures/zh-cn_image_0000001511900496.png)