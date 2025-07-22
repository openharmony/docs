# 滚动与滑动

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## List

### onScroll

ArkTS1.1接口声明：[onScroll(event: (scrollOffset: number, scrollState: ScrollState) => void)](../reference/apis-arkui/arkui-ts/ts-container-list.md#onscrolldeprecated)

替代的ArkTS1.2接口声明：[onDidScroll(handler: OnScrollCallback): T](../reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#ondidscroll12)

适配方法如下：

ArkTS1.1
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct ListComponent {
  build() {
    Column() {
      List() {
      }
      .onScroll((scrollOffset: number, scrollState: ScrollState) => {
        // some logic
      })
    }
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct ListComponent {
  build() {
    Column() {
      List() {
      }
      .onDidScroll((scrollOffset: number, scrollState: ScrollState) => {
        // some logic
      })
    }
  }
}
```

### onItemDelete

ArkTS1.1接口声明：[onItemDelete(event: (index: number) => boolean)](../reference/apis-arkui/arkui-ts/ts-container-list.md#onitemdeletedeprecated)

替代的ArkTS1.2接口声明：ArkTS1.2暂无替代接口。

### editMode

ArkTS1.1接口声明：[editMode(value: boolean)](../reference/apis-arkui/arkui-ts/ts-container-list.md#editmodedeprecated)

替代的ArkTS1.2接口声明：ArkTS1.2暂无替代接口。

## ListItem

### ListItem

ArkTS1.1接口声明：[ListItem(value?: string)](../reference/apis-arkui/arkui-ts/ts-container-listitem.md#listitemdeprecated)

替代的ArkTS1.2接口声明：[ListItem(value?: ListItemOptions)](../reference/apis-arkui/arkui-ts/ts-container-listitem.md#listitem10)

适配方法如下：

ArkTS1.1
<!--code_no_check-->
```ts
// xxx.ets
export class ListDataSource implements IDataSource {
  private list: number[] = [];

  constructor(list: number[]) {
    this.list = list;
  }

  totalCount(): number {
    return this.list.length;
  }

  getData(index: number): number {
    return this.list[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
  }
}

@Entry
@Component
struct ListItemExample {
  private arr: ListDataSource = new ListDataSource([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        LazyForEach(this.arr, (item: number) => {
          ListItem("") {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
        }, (item: string) => item)
      }.width('90%')
      .scrollBar(BarState.Off)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
export class ListDataSource implements IDataSource {
  private list: number[] = [];

  constructor(list: number[]) {
    this.list = list;
  }

  totalCount(): number {
    return this.list.length;
  }

  getData(index: number): number {
    return this.list[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
  }
}

@Entry
@Component
struct ListItemExample {
  private arr: ListDataSource = new ListDataSource([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        LazyForEach(this.arr, (item: number) => {
          ListItem({style: ListItemStyle.NONE}) {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
        }, (item: string) => item)
      }.width('90%')
      .scrollBar(BarState.Off)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

### sticky

ArkTS1.1接口声明：[sticky(value: Sticky)](../reference/apis-arkui/arkui-ts/ts-container-listitem.md#stickydeprecated)

替代的ArkTS1.2接口声明：[sticky(value: StickyStyle)](../reference/apis-arkui/arkui-ts/ts-container-list.md#sticky9)

适配方法如下：

ArkTS1.1
<!--code_no_check-->
```ts
// xxx.ets
export class ListDataSource implements IDataSource {
  private list: number[] = [];

  constructor(list: number[]) {
    this.list = list;
  }

  totalCount(): number {
    return this.list.length;
  }

  getData(index: number): number {
    return this.list[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
  }
}

@Entry
@Component
struct ListItemExample {
  private arr: ListDataSource = new ListDataSource([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        LazyForEach(this.arr, (item: number) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
          .sticky(Sticky.None)
        }, (item: string) => item)
      }.width('90%')
      .scrollBar(BarState.Off)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
export class ListDataSource implements IDataSource {
  private list: number[] = [];

  constructor(list: number[]) {
    this.list = list;
  }

  totalCount(): number {
    return this.list.length;
  }

  getData(index: number): number {
    return this.list[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
  }
}

@Entry
@Component
struct ListItemExample {
  private arr: ListDataSource = new ListDataSource([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        LazyForEach(this.arr, (item: number) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
        }, (item: string) => item)
      }.width('90%')
      .sticky(StickyStyle.None)
      .scrollBar(BarState.Off)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

### editable

ArkTS1.1接口声明：[editable(value: boolean | EditMode)](../reference/apis-arkui/arkui-ts/ts-container-listitem.md#editabledeprecated)

替代的ArkTS1.2接口声明：ArkTS1.2暂无替代接口。


### Sticky

ArkTS1.1接口声明：[Sticky](../reference/apis-arkui/arkui-ts/ts-container-listitem.md#stickydeprecated枚举说明)

替代的ArkTS1.2接口声明：[StickyStyle](../reference/apis-arkui/arkui-ts/ts-container-list.md#stickystyle9枚举说明)

适配方法如下：

ArkTS1.1
<!--code_no_check-->
```ts
// xxx.ets
const stickTypeNone : Sticky = Sticky.None;
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
const stickTypeNone : StickyStyle = StickyStyle.None;
```

### EditMode

ArkTS1.1接口声明：[EditMode](../reference/apis-arkui/arkui-ts/ts-container-listitem.md#editmodedeprecated枚举说明)

替代的ArkTS1.2接口声明：ArkTS1.2暂无替代接口。
## Grid

### onScroll

ArkTS1.1接口声明：[onScroll(event: (scrollOffset: number, scrollState: ScrollState) => void)](../reference/apis-arkui/arkui-ts/ts-container-grid.md#onscrolldeprecated)

替代的ArkTS1.2接口声明：[onDidScroll(handler: OnScrollCallback): T](../reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#ondidscroll12)

适配方法如下：

ArkTS1.1
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct GridComponent {
  build() {
    Column() {
      Grid() {
      }
      .onScroll((scrollOffset: number, scrollState: ScrollState) => {
        // some logic
      })
    }
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct GridComponent {
  build() {
    Column() {
      Grid() {
      }
      .onDidScroll((scrollOffset: number, scrollState: ScrollState) => {
        // some logic
      })
    }
  }
}
```

## GridItem

### forceRebuild

ArkTS1.1接口声明：[forceRebuild(value: boolean)](../reference/apis-arkui/arkui-ts/ts-container-griditem.md#forcerebuilddeprecated)

替代的ArkTS1.2接口声明：ArkTS1.2暂无替代接口。

## Scroll

### scrollPage

ArkTS1.1接口声明：[scrollPage(value: { next: boolean, direction?: Axis })](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#scrollpagedeprecated)

替代的ArkTS1.2接口声明：[scrollPage(value: ScrollPageOptions)](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#scrollpage9)

适配方法如下：

ArkTS1.1
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item: number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item: number) => item.toString())
        }.width('100%')
      }
      .scrollable(ScrollDirection.Vertical) // 滚动方向纵向
      .scrollBar(BarState.On) // 滚动条常驻显示
      .scrollBarColor(Color.Gray) // 滚动条颜色
      .scrollBarWidth(10) // 滚动条宽度
      .friction(0.6)
      .edgeEffect(EdgeEffect.None)

      Button('next page')
        .height('5%')
        .onClick(() => { // 点击后滑到下一页
          this.scroller.scrollPage({ next: true ,direction: Axis.Vertical });
        })
        .margin({ top: 210, left: 20 })
    
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item: number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item: number) => item.toString())
        }.width('100%')
      }
      .scrollable(ScrollDirection.Vertical) // 滚动方向纵向
      .scrollBar(BarState.On) // 滚动条常驻显示
      .scrollBarColor(Color.Gray) // 滚动条颜色
      .scrollBarWidth(10) // 滚动条宽度
      .friction(0.6)
      .edgeEffect(EdgeEffect.None)

      Button('next page')
        .height('5%')
        .onClick(() => { // 点击后滑到下一页
          this.scroller.scrollPage({ next: true ,animation: true });
        })
        .margin({ top: 210, left: 20 })
    
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

### ScrollDirection.Free

ArkTS1.1接口声明：[ScrollDirection.Free](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#scrolldirection枚举说明)

替代的ArkTS1.2接口声明：ArkTS1.2暂无替代接口。

### onScrollEnd

ArkTS1.1接口声明：[onScrollEnd(event: () => void)](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#onscrollenddeprecated)

替代的ArkTS1.2接口声明：[onScrollStop(event: VoidCallback)](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#onscrollstop9)

适配方法如下：

ArkTS1.1
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item: number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item: number) => item.toString())
        }.width('100%')
      }
      .scrollable(ScrollDirection.Vertical) // 滚动方向纵向
      .scrollBar(BarState.On) // 滚动条常驻显示
      .scrollBarColor(Color.Gray) // 滚动条颜色
      .scrollBarWidth(10) // 滚动条宽度
      .friction(0.6)
      .edgeEffect(EdgeEffect.None)
      .onScrollEnd(() => {
        console.info('Scroll end');
      })
    
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item: number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item: number) => item.toString())
        }.width('100%')
      }
      .scrollable(ScrollDirection.Vertical) // 滚动方向纵向
      .scrollBar(BarState.On) // 滚动条常驻显示
      .scrollBarColor(Color.Gray) // 滚动条颜色
      .scrollBarWidth(10) // 滚动条宽度
      .friction(0.6)
      .edgeEffect(EdgeEffect.None)
      .onScrollStop(()=>{
        console.info('Scroll stop');
      })
      
    
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

### onScroll

ArkTS1.1接口声明：[onScroll(event: (xOffset: number, yOffset: number) => void)](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#onscrolldeprecated)

替代的ArkTS1.2接口声明：[onWillScroll(handler: ScrollOnWillScrollCallback)](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#onwillscroll12)

适配方法如下：

ArkTS1.1
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item: number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item: number) => item.toString())
        }.width('100%')
      }
      .scrollable(ScrollDirection.Vertical) // 滚动方向纵向
      .scrollBar(BarState.On) // 滚动条常驻显示
      .scrollBarColor(Color.Gray) // 滚动条颜色
      .scrollBarWidth(10) // 滚动条宽度
      .friction(0.6)
      .edgeEffect(EdgeEffect.None)
      .onScroll((xOffset: number, yOffset: number) => {
        console.info('onScroll');
      })
    
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller();
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item: number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item: number) => item.toString())
        }.width('100%')
      }
      .scrollable(ScrollDirection.Vertical) // 滚动方向纵向
      .scrollBar(BarState.On) // 滚动条常驻显示
      .scrollBarColor(Color.Gray) // 滚动条颜色
      .scrollBarWidth(10) // 滚动条宽度
      .friction(0.6)
      .edgeEffect(EdgeEffect.None)
      .onWillScroll((xOffset: number, yOffset: number, scrollState: ScrollState, scrollSource: ScrollSource) => {
        console.info('onWillScroll');
      })
      
    
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

## Refresh

### RefreshOptions-offset

ArkTS1.1接口声明：[RefreshOptions-offset](../reference/apis-arkui/arkui-ts/ts-container-refresh.md#refreshoptions对象说明)

替代的ArkTS1.2接口声明：ArkTS1.2暂无替代接口。

### RefreshOptions-friction

ArkTS1.1接口声明：[RefreshOptions-friction](../reference/apis-arkui/arkui-ts/ts-container-refresh.md#refreshoptions对象说明)

替代的ArkTS1.2接口声明：[pullDownRatio(ratio: Optional<number>)](../reference/apis-arkui/arkui-ts/ts-container-refresh.md#pulldownratio12)

适配方法如下：

ArkTS1.1
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct RefreshComponent {
  build() {
    Column() {
      Refresh({ refreshing: true ,friction: 62 }) {
      }
    }
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct RefreshComponent {
  build() {
    Column() {
      Refresh({ refreshing: true }) {
      }
      .pullDownRatio(62)
    }
  }
}
```

## 滚动组件通用接口

### onScroll

ArkTS1.1接口声明：[onScroll(event: (scrollOffset: number, scrollState: ScrollState) => void): T](../reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#onscrolldeprecated)

替代的ArkTS1.2接口声明：

Scroll组件的onScroll事件在布局之前触发，建议使用[onWillScroll](../reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#onwillscroll12)。

List、Grid和WaterFlow组件的onScroll事件在布局之后触发，建议使用[onDidScroll](../reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md#ondidscroll12)。

适配方法如下：

ArkTS1.1
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct ScrollComponent {
  build() {
    Column() {
      Scroll() {
      }
      .onScroll((scrollOffset: number, scrollState: ScrollState) => {
        // some logic
      })
    }
  }
}

@Component
struct ListComponent {
  build() {
    Column() {
      List() {
      }
      .onScroll((scrollOffset: number, scrollState: ScrollState) => {
        // some logic
      })
    }
  }
}

@Component
struct GridComponent {
  build() {
    Column() {
      Grid() {
      }
      .onScroll((scrollOffset: number, scrollState: ScrollState) => {
        // some logic
      })
    }
  }
}

@Component
struct WaterFlowComponent {
  build() {
    Column() {
      WaterFlow() {
      }
      .onScroll((scrollOffset: number, scrollState: ScrollState) => {
        // some logic
      })
    }
  }
}

```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct ScrollComponent {
  build() {
    Column() {
      Scroll() {
      }
      .onWillScroll((scrollOffset: number, scrollState: ScrollState, scrollSource: ScrollSource) => {
        // some logic
      })
    }
  }
}

@Component
struct ListComponent {
  build() {
    Column() {
      List() {
      }
      .onDidScroll((scrollOffset: number, scrollState: ScrollState) => {
        // some logic
      })
    }
  }
}

@Component
struct GridComponent {
  build() {
    Column() {
      Grid() {
      }
      .onDidScroll((scrollOffset: number, scrollState: ScrollState) => {
        // some logic
      })
    }
  }
}

@Component
struct WaterFlowComponent {
  build() {
    Column() {
      WaterFlow() {
      }
      .onDidScroll((scrollOffset: number, scrollState: ScrollState) => {
        // some logic
      })
    }
  }
}
```

## 枚举说明

### Edge.Center

ArkTS1.1接口声明：[Edge.Center](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#edge)

替代的ArkTS1.2接口声明：ArkTS1.2暂无替代接口。

### Edge.Middle

ArkTS1.1接口声明：[Edge.Middle](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#edge)

替代的ArkTS1.2接口声明：ArkTS1.2暂无替代接口。

### Edge.Baseline

ArkTS1.1接口声明：[Edge.Baseline](../reference/apis-arkui/arkui-ts/ts-appendix-enums.md#edge)

替代的ArkTS1.2接口声明：ArkTS1.2暂无替代接口。