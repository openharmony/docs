# arkui子系统ChangeLog

## cl.arkui.1 List组件和Gird组件滚动条默认状态变更

List组件和Gird组件滚动条默认状态从BarState.Off变更为BarState.Auto。

**变更影响**

List组件和Gird组件，如果没有设置滚动条状态，变更前不会显示滚动条，变更以后滚动时会显示滚动条，滚动停止两秒后滚动条隐藏。

**关键接口/组件变更**

List组件和Gird组件滚动条API接口文档：
- [List组件属性](../../../application-dev/reference/arkui-ts/ts-container-list.md#属性)
- [Grid组件属性](../../../application-dev/reference/arkui-ts/ts-container-grid.md#属性)

**适配指导**

对于不需要滚动条的场景，需要将List组件或Grid组件的scrollBar属性设置为BarState.Off。

参考代码如下：
```ts
// xxx.ets
@Entry
@Component
struct ListItemExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          }
        }, item => item)
      }
      .width('90%')
      .scrollBar(BarState.Off)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```