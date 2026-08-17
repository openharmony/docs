# DynamicLayout
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zju_ljz-->
<!--Designer: @lanshouren-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

Defines the dynamic layout container component, which supports dynamically switching between different layout algorithms at runtime without changing the status of child components.

> **NOTE**
>
> This component is supported since API version 24. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Child components are supported.

## APIs

DynamicLayout(algorithm: LayoutAlgorithm)  

Defines the dynamic layout container.

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 24.

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| algorithm | [LayoutAlgorithm](../js-apis-arkui-layoutAlgorithm.md#layoutalgorithm-1) | Yes| Layout algorithm of the dynamic layout component. If an invalid value is used, the child components are stacked and arranged according to [StackLayoutAlgorithm](../js-apis-arkui-layoutAlgorithm.md#stacklayoutalgorithm).|

## Attributes

The [universal attributes](ts-component-general-attributes.md) are supported.

> **NOTE**
>
> - When the layout algorithm is [RowLayoutAlgorithm](../js-apis-arkui-layoutAlgorithm.md#rowlayoutalgorithm) or [ColumnLayoutAlgorithm](../js-apis-arkui-layoutAlgorithm.md#columnlayoutalgorithm), the [Flex layout](ts-universal-attributes-flex-layout.md) attributes set for child components take effect.
>
> - When the layout algorithm is [StackLayoutAlgorithm](../js-apis-arkui-layoutAlgorithm.md#stacklayoutalgorithm), the [layoutGravity](ts-universal-attributes-location.md#layoutgravity20) attribute set for child components takes effect.
>
> - When the layout algorithm is [CustomLayoutAlgorithm](../js-apis-arkui-layoutAlgorithm.md#customlayoutalgorithm), the [setMeasuredSize](../js-apis-arkui-frameNode.md#setmeasuredsize12) method of the [FrameNode](../js-apis-arkui-frameNode.md#framenode-1) component of **DynamicLayout** has a higher priority than the [sizing](ts-universal-attributes-size.md) and [border styling](ts-universal-attributes-border.md) attributes. The [measure](../js-apis-arkui-frameNode.md#measure12) and [layout](../js-apis-arkui-frameNode.md#layout12) methods of the child component [FrameNode](../js-apis-arkui-frameNode.md#framenode-1) have a higher priority than the [ignoreLayoutSafeArea](ts-universal-attributes-expand-safe-area.md#ignorelayoutsafearea20) attribute.

## Events

The [universal events](ts-component-general-events.md) are supported.

## Examples

### Example 1: Implementing Waterfall Layout Using a Custom Layout Algorithm

This example shows how to override the [onMeasure](../js-apis-arkui-layoutAlgorithm.md#onmeasure) and [onLayout](../js-apis-arkui-layoutAlgorithm.md#onlayout) functions to display the product list in waterfall layout.

Since API version 24, **onMeasure** and **onLayout** are added.

```typescript
import { DynamicLayout, DynamicLayoutAttribute, CustomLayoutAlgorithm, LayoutAlgorithm, FrameNode, LayoutConstraint, Position } from '@kit.ArkUI';

// Waterfall layout algorithm
class WaterfallLayout extends CustomLayoutAlgorithm {
  private columnCount: number = 2;
  private columnGap: number = 10;
  private rowGap: number = 10;

  onMeasure(self: FrameNode, constraint: LayoutConstraint): void {
    const childCount = self.getChildrenCount();
    const columnWidth = (constraint.maxSize.width - (this.columnCount - 1) * this.columnGap) / this.columnCount;

    // Record the current height of each column.
    const columnHeights: number[] = new Array(this.columnCount).fill(0);

    for (let i = 0; i < childCount; i++) {
      const child = self.getChild(i);
      if (child) {
        // Set minSize and maxSize to the same value to restrict the width of child components.
        const childConstraint: LayoutConstraint = {
          maxSize: {
            width: columnWidth,
            height: constraint.maxSize.height
          },
          minSize: {
            width: columnWidth,
            height: 0
          },
          percentReference: constraint.percentReference
        };

        child.measure(childConstraint);

        // Find the column with the minimum height.
        const minColumn = columnHeights.indexOf(Math.min(...columnHeights));
        columnHeights[minColumn] += child.getMeasuredSize().height + this.rowGap;
      }
    }

    const maxHeight = Math.max(...columnHeights);
    self.setMeasuredSize({
      width: constraint.maxSize.width,
      height: maxHeight
    });
  }

  onLayout(self: FrameNode, position: Position): void {
    const childCount = self.getChildrenCount();
    const measuredSize = self.getMeasuredSize();
    const columnWidth = (measuredSize.width - (this.columnCount - 1) * this.columnGap) / this.columnCount;

    // Record the current Y coordinate of each column.
    const columnYs: number[] = new Array(this.columnCount).fill(0);

    for (let i = 0; i < childCount; i++) {
      const child = self.getChild(i);
      if (child) {
        const childSize = child.getMeasuredSize();

        // Find the column with the minimum Y coordinate.
        const minColumn = columnYs.indexOf(Math.min(...columnYs));
        const x = minColumn * (columnWidth + this.columnGap);
        const y = columnYs[minColumn];

        child.layout({ x, y });

        columnYs[minColumn] += childSize.height + this.rowGap;
      }
    }

    self.setLayoutPosition(position);
  }
}

@Entry
@ComponentV2
struct WaterfallLayoutExample {
  @Local algorithm: LayoutAlgorithm = new WaterfallLayout();

  // Product data
  private products: Product[] = [
    { id: '1', name: 'Fashion sneakers', price: '¥399', height: 180, image: 'Product image' },
    { id: '2', name: 'Casual backpack', price: '¥259', height: 220, image: 'Product image' },
    { id: '3', name: 'Wireless Bluetooth earbuds', price: '¥599', height: 150, image: 'Product image' },
    { id: '4', name: 'Smart watch', price: '¥1299', height: 200, image: 'Product image' },
    { id: '5', name: 'Sunglasses', price: '¥199', height: 130, image: 'Product image' },
    { id: '6', name: 'Portable power bank', price: '¥129', height: 170, image: 'Product image' },
    { id: '7', name: 'Mechanical keyboard', price: '¥459', height: 160, image: 'Product image' },
    { id: '8', name: 'Gaming mouse', price: '¥189', height: 140, image: 'Product image' },
    { id: '9', name: 'HD display', price: '¥1599', height: 210, image: 'Product image' },
    { id: '10', name: 'Smart speaker', price: '¥299', height: 190, image: 'Product image' }
  ];

  // Product card component
  @Builder ProductCard(product: Product) {
    Column() {
      Text(product.image)
        .fontSize(18)
        .margin({ bottom: 8 })
      Text(product.name)
        .fontSize(14)
        .fontWeight(FontWeight.Medium)
        .fontColor(0x333333)
        .margin({ bottom: 4 })
        .maxLines(1)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
      Text(product.price)
        .fontSize(16)
        .fontColor(0xFF6B35)
        .fontWeight(FontWeight.Bold)
    }
    .width('100%')
    .padding(12)
    .backgroundColor(0xFAFAFA)
    .borderRadius(8)
    .border({ width: 1, color: 0xE0E0E0 })
    .height(product.height)
    .justifyContent(FlexAlign.Center)
  }

  build() {
    Column() {
      Text('Product list - waterfall layout')
        .fontSize(18)
        .fontWeight(FontWeight.Bold)
        .margin({ bottom: 20 })

      Scroll() {
        DynamicLayout(this.algorithm) {
          ForEach(this.products, (product: Product) => {
            this.ProductCard(product)
          })
        }
        .width('100%')
        .backgroundColor(0xEFEFEF)
        .borderRadius(12)
        .padding(10)
      }
      .scrollable(ScrollDirection.Vertical)
      .scrollBar(BarState.Auto)
      .edgeEffect(EdgeEffect.Spring)
      .width('100%')
      .layoutWeight(1)

      Text('The product card is automatically allocated to the column with the smallest height.')
        .fontSize(14)
        .fontColor(Color.Gray)
        .margin({ top: 12 })
    }
    .padding(20)
    .width('100%')
    .height('100%')
  }
}

// Product data model
interface Product {
  id: string;
  name: string;
  price: string;
  height: number;
  image: string;
}
```

### Example 2: Switching the Layout Algorithm

This example demonstrates how to dynamically switch the layout algorithm of the **DynamicLayout** component by changing the **LayoutAlgorithm** variable decorated by [\@Local](../../../ ui/state-management/arkts-new-local.md). Specifically, it shows how to switch between [RowLayoutAlgorithm](../js-apis-arkui-layoutAlgorithm.md#rowlayoutalgorithm), [ColumnLayoutAlgorithm](../js-apis-arkui-layoutAlgorithm.md#columnlayoutalgorithm), [StackLayoutAlgorithm](../js-apis-arkui-layoutAlgorithm.md#stacklayoutalgorithm) and [GridLayoutAlgorithm](../js-apis-arkui-layoutAlgorithm.md#gridlayoutalgorithm).

Since API version 24, **RowLayoutAlgorithm**, **ColumnLayoutAlgorithm**, **StackLayoutAlgorithm**, and **GridLayoutAlgorithm** have been added.

```typescript
import { DynamicLayout, DynamicLayoutAttribute, RowLayoutAlgorithm, ColumnLayoutAlgorithm, StackLayoutAlgorithm, GridLayoutAlgorithm, LayoutAlgorithm, LengthMetrics } from '@kit.ArkUI';

@Entry
@ComponentV2
struct LayoutSwitchExample {
  @Local algorithm: LayoutAlgorithm = new RowLayoutAlgorithm({
    space: LengthMetrics.vp(10),
    alignItems: VerticalAlign.Center
  });
  @Local childWidth: string = '20%'
  @Local childHeight: string = '20%'

  build() {
    Column() {
      // Use the status variable to control the layout algorithm.
      DynamicLayout(this.algorithm) {
        Text('Item 1')
          .width(this.childWidth)
          .height(this.childHeight)
          .fontSize(14)
          .textAlign(TextAlign.Center)
          .backgroundColor(0xF5DEB3)
          .borderRadius(8)
          .layoutGravity(LocalizedAlignment.TOP_START)
        Text('Item 2')
          .width(this.childWidth)
          .height(this.childHeight)
          .fontSize(14)
          .textAlign(TextAlign.Center)
          .backgroundColor(0xF5DEB3)
          .borderRadius(8)
          .layoutGravity(LocalizedAlignment.TOP_END)
        Text('Item 3')
          .width(this.childWidth)
          .height(this.childHeight)
          .fontSize(14)
          .textAlign(TextAlign.Center)
          .backgroundColor(0xF5DEB3)
          .borderRadius(8)
          .layoutGravity(LocalizedAlignment.BOTTOM_START)
        Text('Item 4')
          .width(this.childWidth)
          .height(this.childHeight)
          .fontSize(14)
          .textAlign(TextAlign.Center)
          .backgroundColor(0xF5DEB3)
          .borderRadius(8)
          .layoutGravity(LocalizedAlignment.BOTTOM_END)
      }
      .width(300)
      .height(280)
      .backgroundColor(0xEFEFEF)
      .borderRadius(12)
      .padding(10)

      Column({ space: 10 }) {
        Row({ space: 10 }) {
          Button('Row layout')
            .fontSize(14)
            .onClick(() => {
              this.algorithm = new RowLayoutAlgorithm({
                space: LengthMetrics.vp(10),
                alignItems: VerticalAlign.Center
              });
              this.childWidth = '20%'
              this.childHeight = '20%'
            })
          Button('Column layout')
            .fontSize(14)
            .onClick(() => {
              this.algorithm = new ColumnLayoutAlgorithm({
                space: LengthMetrics.vp(10),
                alignItems: HorizontalAlign.Center
              });
              this.childWidth = '20%'
              this.childHeight = '20%'
            })
        }
        Row({ space: 10 }) {
          Button('Stack layout')
            .fontSize(14)
            .onClick(() => {
              this.algorithm = new StackLayoutAlgorithm({
                alignContent: LocalizedAlignment.CENTER
              });
              this.childWidth = '20%'
              this.childHeight = '20%'
            })
          Button('Grid layout')
            .fontSize(14)
            .onClick(() => {
              this.algorithm = new GridLayoutAlgorithm({
                columnsTemplate: '1fr 1fr',
                rowsGap: LengthMetrics.vp(5),
                columnsGap: LengthMetrics.vp(5)
              });
              this.childWidth = '100%'
              this.childHeight = '50%'
            })
        }
      }
      .margin({ top: 20 })
    }
    .padding(20)
  }
}
```

### Example 3: Modifying the Layout Algorithm Attributes

This example shows how to modify the **space** and **justifyContent** attributes of [RowLayoutAlgorithm](../js-apis-arkui-layoutAlgorithm.md#rowlayoutalgorithm) to update the layout effect of the **DynamicLayout** component.

Since API version 24, the **space** and **justifyContent** attributes are added.

```typescript
import { DynamicLayout, DynamicLayoutAttribute, RowLayoutAlgorithm, LengthMetrics } from '@kit.ArkUI';

@Entry
@ComponentV2
struct PropertyChangeExample {
  algorithm: RowLayoutAlgorithm = new RowLayoutAlgorithm({
    space: LengthMetrics.vp(10),
    justifyContent: FlexAlign.Start
  });

  build() {
    Column() {
      DynamicLayout(this.algorithm) {
        Text('Item 1')
          .width(60)
          .height(40)
          .fontSize(14)
          .backgroundColor(0xF5DEB3)
        Text('Item 2')
          .width(60)
          .height(40)
          .fontSize(14)
          .backgroundColor(0xD2B48C)
        Text('Item 3')
          .width(60)
          .height(40)
          .fontSize(14)
          .backgroundColor(0xF5DEB3)
      }
      .width('100%')
      .height(80)
      .backgroundColor(0xEFEFEF)

      Row({ space: 10 }) {
        Button('Increase spacing')
          .fontSize(14)
          .onClick(() => {
            // Modify the space attribute to trigger re-layout.
            const currentSpace = this.algorithm.space?.value;
            this.algorithm.space = LengthMetrics.vp(currentSpace as number + 5);
          })
        Button('Center align')
          .fontSize(14)
          .onClick(() => {
            // Modify the justifyContent attribute to trigger re-layout.
            this.algorithm.justifyContent = FlexAlign.Center;
          })
        Button('Space between')
          .fontSize(14)
          .onClick(() => {
            this.algorithm.justifyContent = FlexAlign.SpaceBetween;
          })
      }
      .margin({ top: 20 })
    }
    .padding(20)
  }
}
```