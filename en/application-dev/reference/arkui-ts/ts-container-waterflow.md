# WaterFlow


The **\<WaterFlow>** component is a container that consists of cells formed by rows and columns and arranges items of different sizes from top to bottom according to the preset rules.


> **NOTE**
>
> This component is supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components


The [\<FlowItem>](ts-container-flowitem.md) child component is supported.

>  **NOTE**
>
>  When the **visibility** attribute of a child component in **\<WaterFlow >** is set to **None**, the child component is not displayed, but still takes up cells.

## APIs


WaterFlow(options?: {footer?: CustomBuilder, scroller?: Scroller})

**Parameters**

| Name    | Type                                       | Mandatory| Description                                    |
| ---------- | ----------------------------------------------- | ------ | -------------------------------------------- |
| footer |  [CustomBuilder](ts-types.md#custombuilder8) | No  | Footer of the **\<WaterFlow>** component. |
| scroller | [Scroller](ts-container-scroll.md#scroller) | No  | Controller, which can be bound to scrollable components.<br>The **\<WaterFlow>** component supports only the **scrollToIndex** API of the **\<Scroller>** component.|


## Attributes


In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name| Type| Description|
| -------- | -------- | -------- |
| columnsTemplate | string | Number of columns in the layout. If this attribute is not set, one column is used by default.<br>For example, **'1fr 1fr 2fr'** indicates three columns, with the first column taking up 1/4 of the parent component's full width, the second column 1/4, and the third column 2/4. This attribute supports [auto-fill](#auto-fill).<br>Default value: **'1fr'**|
| rowsTemplate | string | Number of rows in the layout. If this attribute is not set, one row is used by default.<br>For example, **'1fr 1fr 2fr'** indicates three rows, with the first row taking up 1/4 of the parent component's full height, the second row 1/4, and the third row 2/4. This attribute supports [auto-fill](#auto-fill).<br>Default value: **'1fr'**|
| itemConstraintSize | [ConstraintSizeOptions](ts-types.md#constraintsizeoptions) | Size constraints of the child components during layout.              |
| columnsGap | Length |Gap between columns.<br>Default value: **0**|
| rowsGap | Length |Gap between rows.<br> Default value: **0**|
| layoutDirection | [FlexDirection](ts-appendix-enums.md#flexdirection) |Main axis direction of the layout.<br>Default value: **FlexDirection.Column**|

The priority of **layoutDirection** is higher than that of **rowsTemplate** and **columnsTemplate**. Depending on the **layoutDirection** settings, there are three layout modes:

- **layoutDirection** is set to **FlexDirection.Column** or **FlexDirection.ColumnReverse**

	In this case, **columnsTemplate** is valid. If it is not set, the default value is used. For example, if **columnsTemplate** is set to **"1fr 1fr"** and **rowsTemplate** **"1fr 1fr 1fr"**, child components are arranged in vertical layout, with the cross axis equally divided into two columns.

- **layoutDirection** set to **FlexDirection.Row** or **FlexDirection.RowReverse**

	In this case, **rowsTemplate** is valid. If it is not set, the default value is used. For example, if **columnsTemplate** is set to **"1fr 1fr"** and **rowsTemplate** **"1fr 1fr 1fr"**, child components are arranged in horizontal layout, with the cross axis equally divided into three columns.

- **layoutDirection** is not set

	In this case, the default value of **layoutDirection** is used, which is **FlexDirection.Column**, and **columnsTemplate** is valid. For example, if **columnsTemplate** is set to **"1fr 1fr"** and **rowsTemplate** **"1fr 1fr 1fr"**, child components are arranged in vertical layout, with the cross axis equally divided into two columns.

## Events


In addition to the [universal events](ts-universal-events-click.md), the following events are supported.


| Name| Description|
| -------- | -------- |
| onReachStart(event: () => void) | Triggered when the component reaches the start.|
| onReachEnd(event: () => void)   | Triggered when the component reaches the end.|


## auto-fill

The **columnsTemplate** and **rowsTemplate** attributes supports **auto-fill** in the following format:

```css
repeat(auto-fill, track-size)
```

Where, **repeat** and **auto-fill** are keywords, and **track-size** indicates the row height or column width. The supported units include px, vp, %, and digits. The value of **track-size** must contain at least one valid row height or column width.


## Example


```ts
// WaterFlowDataSource.ets

// Object that implements the IDataSource API, which is used by the <WaterFlow> component to load data.
export class WaterFlowDataSource implements IDataSource {

  private dataArray: number[] = []
  private listeners: DataChangeListener[] = []

  constructor() {
      for (let i = 0; i < 100; i++) {
          this.dataArray.push(i)
      }
  }

  // Obtain the data corresponding to the specified index.
  public getData(index: number): any {
      return this.dataArray[index]
  }

  // Notify the controller of data reloading.
  notifyDataReload(): void {
      this.listeners.forEach(listener => {
          listener.onDataReloaded()
      })
  }

  // Notify the controller of data addition.
  notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
          listener.onDataAdded(index)
      })
  }

  // Notify the controller of data changes.
  notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
          listener.onDataChanged(index)
      })
  }

  // Notify the controller of data deletion.
  notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
          listener.onDataDeleted(index)
      })
  }

  // Notify the controller of the data location change.
  notifyDataMove(from: number, to: number): void {
      this.listeners.forEach(listener => {
          listener.onDataMoved(from, to)
      })
  }

  // Obtain the total number of data records.
  public totalCount(): number {
      return this.dataArray.length
  }

  // Register the data change listener.
  registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
          this.listeners.push(listener)
      }
  }

  // Unregister the data change listener.
  unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener)
      if (pos >= 0) {
          this.listeners.splice(pos, 1)
      }
  }

  // Add data.
  public Add1stItem(): void {
      this.dataArray.splice(0, 0, this.dataArray.length)
      this.notifyDataAdd(0)
  }

  // Add an item to the end of the data.
  public AddLastItem(): void {
      this.dataArray.splice(this.dataArray.length, 0, this.dataArray.length)
      this.notifyDataAdd(this.dataArray.length-1)
  }

  // Add an item to the position corresponding to the specified index.
  public AddItem(index: number): void {
      this.dataArray.splice(index, 0, this.dataArray.length)
      this.notifyDataAdd(index)
  }

  // Delete the first item.
  public Delete1stItem(): void {
      this.dataArray.splice(0, 1)
      this.notifyDataDelete(0)
  }

  // Delete the second item.
  public Delete2ndItem(): void {
      this.dataArray.splice(1, 1)
      this.notifyDataDelete(1)
  }

  // Delete the last item.
  public DeleteLastItem(): void {
      this.dataArray.splice(-1, 1)
      this.notifyDataDelete(this.dataArray.length)
  }

  // Reload data.
  public Reload(): void {
      this.dataArray.splice(1, 1)
      this.dataArray.splice(3, 2)
      this.notifyDataReload()
  }
}
```

```ts
// WaterflowDemo.ets
import { WaterFlowDataSource } from './WaterFlowDataSource'

@Entry
@Component
struct WaterflowDemo {
  @State minSize: number = 50
  @State maxSize: number = 100
  @State fontSize: number = 24
  @State colors: number[] = [0xFFC0CB, 0xDA70D6, 0x6B8E23, 0x6A5ACD, 0x00FFFF, 0x00FF7F]
  scroller: Scroller = new Scroller()
  datasource: WaterFlowDataSource = new WaterFlowDataSource()
  private itemWidthArray: number[] = []
  private itemHeightArray: number[] = []

  // Calculate the width and height of a flow item. 
  getSize() {
    let ret = Math.floor(Math.random() * this.maxSize)
    return (ret > this.minSize ? ret : this.minSize)
  }

  // Save the width and height of the flow item.  
  getItemSizeArray() {
    for (let i = 0; i < 100; i++) {
      this.itemWidthArray.push(this.getSize())
      this.itemHeightArray.push(this.getSize())
    }
  }
    
  aboutToAppear() {
    this.getItemSizeArray()
  }
    
  @Builder itemFoot() {
    Column() {
      Text(`Footer`)
        .fontSize(10)
        .backgroundColor(Color.Red)
        .width(50)
        .height(50)
        .align(Alignment.Center)
        .margin({ top: 2 })
    }
  }

  build() {
    Column({ space: 2 }) {
      WaterFlow({ footer: this.itemFoot.bind(this), scroller: this.scroller }) {
        LazyForEach(this.datasource, (item: number) => {
          FlowItem() {
            Column() {
              Text("N" + item).fontSize(12).height('16')
              Image('res/waterFlowTest(' + item % 5 + ').jpg')
                .objectFit(ImageFit.Fill)
                .width('100%')
                .layoutWeight(1)
            }
          }
          .width('100%')
          .height(this.itemHeightArray[item])
          .backgroundColor(this.colors[item % 5])
        }, item => item)
      }
      .columnsTemplate("1fr 1fr 1fr 1fr")
      .itemConstraintSize({
        minWidth: 0,
        maxWidth: '100%',
        minHeight: 0,
        maxHeight: '100%'
      })
      .columnsGap(10)
      .rowsGap(5)
      .onReachStart(() => {
        console.info("onReachStart")
      })
      .onReachEnd(() => {
        console.info("onReachEnd")
      })
      .backgroundColor(0xFAEEE0)
      .width('100%')
      .height('80%')
      .layoutDirection(FlexDirection.Column)
    }
  }
}
```

![en-us_image_WaterFlow.gif](figures/waterflow.gif)
