# 分布式迁移标识
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->

组件的分布式迁移标识，用于在分布式迁移场景下标识组件，将组件的特定状态恢复到对端设备，帮助用户在设备切换后保持原有的组件位置或滚动状态，提升跨设备使用的连续性。

>  **说明：**
>
>  从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## restoreId

restoreId(value: number): T

标记支持分布式迁移的组件Id，系统通过该Id匹配两端设备上的对应组件，并据此恢复组件的特定状态。不同组件的迁移效果和限制有所不同：Grid的ScrollBar位置无法迁移；Scroll在两端设备显示规格不同或布局参数差异导致布局不一致时会影响迁移效果；WaterFlow还会迁移顶部FlowItem相对WaterFlow的主轴偏移值（单位为vp）。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | 是   | 标记支持分布式迁移的组件Id，用于两端设备组件的配对。取值为整数，具体范围以接口实现约束为准。同一个应用中各个支持分布式迁移组件的Id必须不同；否则可能导致两端设备组件无法正确配对，影响分布式迁移时的状态恢复。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## 支持的组件

| 组件名称      | 起始版本 | 迁移状态                                     |
| --------- | ---- | ---------------------------------------- |
| [List](./ts-container-list.md)      | 8    | 迁移当前设备顶部显示的ListItem索引值，迁移后在对端设备上，将该索引值对应的ListItem在List中置顶显示。 |
| [Grid](./ts-container-grid.md)      | 9    | 迁移当前设备顶部显示的GridItem索引值，迁移后在对端设备上，将该索引值对应的GridItem在Grid中置顶显示。ScrollBar位置无法迁移。 |
| [Scroll](./ts-container-scroll.md)    | 9    | 迁移滚动位置距顶部的绝对距离（vp单位）。两端设备显示规格不同等原因导致布局不一致，会影响迁移效果。 |
| [WaterFlow](./ts-container-waterflow.md) | 11   | 迁移当前设备顶部显示的FlowItem索引值，迁移后在对端设备上，将该索引值对应的FlowItem在WaterFlow顶部显示。同时迁移顶部FlowItem相对WaterFlow的主轴偏移值（vp单位）。 |

## 示例

该示例通过restoreId设置了List组件的分布式迁移标识。

```ts
// xxx.ets
@Entry
@Component
struct RestoreIdExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
  build() {
    Column() {
      List({ space: 20 }) {
        ForEach(this.arr, (item:number) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(Color.Pink)
          }
        }, (item:number) => (item.toString()))
      }
      .restoreId(1);
    }
  }
}
```
