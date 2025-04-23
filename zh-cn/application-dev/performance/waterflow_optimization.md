# WaterFlow高性能开发指导

## 背景

瀑布流常用于展示图片信息，如多用于购物、资讯类应用。下面通过对[WaterFlow](../reference/apis-arkui/arkui-ts/ts-container-waterflow.md)组件示例代码的逐步改造，介绍优化WaterFlow性能的方法。

## 使用懒加载

先看一下组件示例代码中瀑布流的基本用法：

```ts
  build() {
    Column({ space: 2 }) {
      WaterFlow() {
        LazyForEach(this.dataSource, (item: number) => {
          FlowItem() {
            Column() {
              Text("N" + item).fontSize(12).height('16')
              Image('res/waterFlowTest (' + item % 5 + ').jpg')
                .objectFit(ImageFit.Fill)
                .width('100%')
                .layoutWeight(1)
            }
          }
          .width('100%')
          // 提前设定FlowItem高度，避免自适应图片高度  
          .height(this.itemHeightArray[item])
          .backgroundColor(this.colors[item % 5])
        }, (item: string) => item)
      }
      .columnsTemplate("1fr 1fr")
      .columnsGap(10)
      .rowsGap(5)
      .backgroundColor(0xFAEEE0)
      .width('100%')
      .height('80%')
    }
  }
```

示例代码已经使用了[LazyForEach](../ui/state-management/arkts-rendering-control-lazyforeach.md)进行数据懒加载，WaterFlow布局时会根据可视区域按需创建FlowItem组件，并在FlowItem滑出可视区域外时销毁以降低内存占用。

另外，由于Image组件默认异步加载，建议提前根据图片大小设定FlowItem的高度，避免图片加载成功后高度变化触发瀑布流刷新布局。

## 无限滚动

示例代码中FlowItem数量是固定的，不能满足无限滚动的场景。

基于WaterFlow本身提供的能力，可以在onReachEnd时给LazyForEach数据源增加新数据，并将footer做成正在加载新数据的样式（使用[LoadingProgress](../reference/apis-arkui/arkui-ts/ts-basic-components-loadingprogress.md)组件）。

```ts
  build() {
    Column({ space: 2 }) {
      WaterFlow({ footer: this.itemFoot.bind(this) }) {
        LazyForEach(this.dataSource, (item: number) => {
          FlowItem() {
            Column() {
              Text("N" + item).fontSize(12).height('16')
              Image('res/waterFlowTest (' + item % 5 + ').jpg')
                .objectFit(ImageFit.Fill)
                .width('100%')
                .layoutWeight(1)
            }
          }
          .width('100%')
          .height(this.itemHeightArray[item % 100])
          .backgroundColor(this.colors[item % 5])
        }, (item: string) => item)
      }
      // 触底加载数据  
      .onReachEnd(() => {
        console.info("onReachEnd")
        setTimeout(() => {
          this.dataSource.addNewItems(100)
        }, 1000)
      })
      .columnsTemplate("1fr 1fr")
      .columnsGap(10)
      .rowsGap(5)
      .backgroundColor(0xFAEEE0)
      .width('100%')
      .height('80%')
    }
  }

  // 在数据尾部增加count个元素
  public addNewItems(count: number): void {
    let len = this.dataArray.length
    for (let i = 0; i < count; i++) {
      this.dataArray.push(this.dataArray.length)
    }
    this.notifyDatasetChange([{ type: DataOperationType.ADD, index: len, count: count }]);
  }
```

此处需要通过在尾部增加元素的方式新增数据，不能使用直接修改dataArray后通过LazyForEach的onDataReloaded()通知瀑布流重新加载数据。

由于瀑布流布局子组件高度不相等的特点，下面节点的位置依赖上面的节点，重新加载所有数据会触发整个瀑布流重新计算布局导致卡顿。而在数据末尾增加数据后使用notifyDatasetChange([{ type: DataOperationType.ADD, index: len, count: count }])通知，瀑布流就知道有新增数据可以继续加载，同时又不会重复处理已有数据。

![](figures/waterflow-perf-demo1.gif)

## 提前新增数据

虽然在onReachEnd()触发时新增数据可以实现无限加载，但在滑动到底部时，会有明显的停顿加载新数据的过程。

想要流畅的进行无限滑动，还需要调整下增加新数据的时机。比如可以在LazyForEach还剩若干个数据就迭代到结束的情况下提前增加一些新数据。

```ts
  build() {
    Column({ space: 2 }) {
      WaterFlow() {
        LazyForEach(this.dataSource, (item: number) => {
          FlowItem() {
            Column() {
              Text("N" + item).fontSize(12).height('16')
              Image('res/waterFlowTest (' + item % 5 + ').jpg')
                .objectFit(ImageFit.Fill)
                .width('100%')
                .layoutWeight(1)
            }
          }
          .onAppear(() => {
            // 即将触底时提前增加数据  
            if (item + 20 == this.dataSource.totalCount()) {
              this.dataSource.addNewItems(100)
            }
          })
          .width('100%')
          .height(this.itemHeightArray[item % 100])
          .backgroundColor(this.colors[item % 5])
        }, (item: string) => item)
      }
      .columnsTemplate("1fr 1fr")
      .columnsGap(10)
      .rowsGap(5)
      .backgroundColor(0xFAEEE0)
      .width('100%')
      .height('80%')
    }
  }
```

此处通过在FlowItem的onAppear中判断距离数据终点的数量，提前增加数据的方式实现了无停顿的无限滚动。

![](figures/waterflow-perf-demo2.gif)

## 组件复用

现在，得到了一个无限滚动且没有显式等待加载的瀑布流，还能不能进一步优化性能呢？

考虑到滑动场景存在FlowItem及其子组件的频繁创建和销毁，可以将FlowItem中的组件封装成自定义组件，并使用@Reusable装饰器修饰，使其具备组件复用能力，减少ArkUI框架内部反复创建销毁节点的开销。组件复用的详细介绍可以参考[组件复用最佳实践](component-recycle.md)。

```ts
  build() {
    Column({ space: 2 }) {
      WaterFlow() {
        LazyForEach(this.dataSource, (item: number) => {
          FlowItem() {
            // 使用可复用自定义组件  
            ResuableFlowItem({ item: item })
          }
          .onAppear(() => {
            // 即将触底时提前增加数据  
            if (item + 20 == this.dataSource.totalCount()) {
              this.dataSource.addNewItems(100)
            }
          })
          .width('100%')
          .height(this.itemHeightArray[item % 100])
          .backgroundColor(this.colors[item % 5])
        }, (item: string) => item)
      }
      .columnsTemplate("1fr 1fr")
      .columnsGap(10)
      .rowsGap(5)
      .backgroundColor(0xFAEEE0)
      .width('100%')
      .height('80%')
    }
  }
@Reusable
@Component
struct ResuableFlowItem {
  @State item: number = 0

  // 从复用缓存中加入到组件树之前调用，可在此处更新组件的状态变量以展示正确的内容
  aboutToReuse(params) {
    this.item = params.item;
  }

  build() {
    Column() {
      Text("N" + this.item).fontSize(12).height('16')
      Image('res/waterFlowTest (' + this.item % 5 + ').jpg')
        .objectFit(ImageFit.Fill)
        .width('100%')
        .layoutWeight(1)
    }
  }
}

```

## 总结

WaterFlow配合LazyForEach渲染控制语法、提前加载数据和组件复用可以达到无限滚动场景性能最优效果。
