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
## cl.arkui.2 组件同时设置Margin和Position属性效果变更

组件同时设置margin和position属性由只有position生效变更为margin和position同时生效。

**变更影响**

组件同时设置margin和position属性的时候，位置会多产生一段margin的位移。

**关键接口/组件变更**

margin和position属性API接口文档：
- [margin属性](../../../application-dev/reference/arkui-ts/ts-universal-attributes-size.md#属性)
- [position属性](../../../application-dev/reference/arkui-ts/ts-universal-attributes-location.md#属性)

**适配指导**

当组件同时设置margin和position，或者部分（例如checkbox等）带有默认margin的组件设置了position时，建议调整margin大小使位置结果正常。