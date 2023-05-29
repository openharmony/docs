# ArkUI Subsystem Changelog

## cl.arkui.1 Change in the Default Scrollbar State of \<List> and \<Gird> Components

Changed the default state of the scrollbar in the **\<List>** and **\<Gird>** components from **BarState.Off** to **BarState.Auto**.

**Change Impact**

In the scenario where the scrollbar status is not set in the **\<List>** and **\<Gird>** components:

- Before change:

  The scrollbar is not displayed.

- After change:

  The scrollbar is displayed during scrolling and is hidden 2 seconds after the scrolling stops.

**Key API/Component Changes**

**scrollBar** attribute of the **\<List>** and **\<Gird>** components:
- [List](../../../application-dev/reference/arkui-ts/ts-container-list.md#attributes)
- [Grid](../../../application-dev/reference/arkui-ts/ts-container-grid.md#attributes)

**Adaptation Guide**

In scenarios where the scrollbar is not required, set the **scrollBar** attribute of the **\<List>** and **\<Gird>** components to **BarState.Off**.

The code snippet is as follows:
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
