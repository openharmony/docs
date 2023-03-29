# 分布式迁移标识

组件的分布式迁移标识，指明了该组件在分布式迁移场景下可以将特定状态恢复到对端设备。

>  **说明：**
>
> 从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 属性

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| restoreId | number | 标记支持分布式迁移的组件Id，用于两端设备组件的配对。同一个应用中各个支持分布式迁移组件的Id必须不同。 |

## 支持的组件

| 组件名称 | 起始API版本 | 迁移状态 |
| -------- | -------- | -------- |
| List | 8 | 迁移当前设备显示在顶部ListItem的索引值，迁移后在对端设备上，将迁移索引值对应的ListItem在List中完整地置顶显示。 |
| Grid | 9 | 迁移当前设备显示在顶部GridItem的索引值，迁移后在对端设备上，将迁移索引值对应的GridItem在Grid中完整地置顶显示。ScrollBar位置无法迁移。 |
| Scroll | 9 | 迁移距顶部滚动的绝对距离。两端设备显示规格不同等原因导致布局不一致，会影响迁移效果。 |
| TextArea | 9 | 迁移输入的文本内容和光标位置。 |
| TextInput | 9 | 迁移输入的文本内容和光标位置。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct RestoreIdExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  build() {
    Column() {
      List({ space: 20 }) {
        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(Color.Pink)
          }
        }, item => item)
      }
      .restoreId(1)
    }
  }
}
```
