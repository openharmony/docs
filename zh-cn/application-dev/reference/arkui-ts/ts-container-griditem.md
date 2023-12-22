# GridItem

网格容器中单项内容容器。

>  **说明：**
>
>  * 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>  * 仅支持作为[Grid](ts-container-grid.md)组件的子组件使用。


## 子组件

可以包含单个子组件。

## 接口

### GridItem<sup>11+</sup>

GridItem(value?: GridItemOptions)

**参数：**

| 参数名 | 参数类型                                      | 必填 | 参数描述                                                     |
| ------ | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [GridItemOptions](#griditemoptions11对象说明) | 否   | 为GridItem提供可选参数, 该对象内含有GridItemStyle枚举类型的style参数。 |

### GridItem<sup>(deprecated)</sup>

GridItem()

从API version 11开始, 该接口不再维护，推荐使用GridItem<sup>11+</sup>。


## 属性

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| rowStart | number | 指定当前元素起始行号。 |
| rowEnd | number | 指定当前元素终点行号。 |
| columnStart | number | 指定当前元素起始列号。 |
| columnEnd | number | 指定当前元素终点列号。 |
| forceRebuild<sup>(deprecated)</sup> | boolean | 设置在触发组件build时是否重新创建此节点。<br/>从API version9开始废弃。GridItem会根据自身属性和子组件变化自行决定是否需要重新创建，无需设置。<br/>默认值：false |
| selectable<sup>8+</sup> | boolean | 当前GridItem元素是否可以被鼠标框选。<br/>>&nbsp;&nbsp;**说明：**<br/>>&nbsp;外层Grid容器的鼠标框选开启时，GridItem的框选才生效。<br/>默认值：true |
| selected<sup>10+</sup> | boolean | 设置当前GridItem选中状态。该属性支持[$$](../../quick-start/arkts-two-way-sync.md)双向绑定变量。<br/>**说明：**<br/>该属性需要在设置[选中态样式](./ts-universal-attributes-polymorphic-style.md#statestyles)前使用才能生效选中态样式。<br/>默认值：false|

>  **说明：**
>
>  起始行号、终点行号、起始列号、终点列号生效规则如下：
>
>  rowStart/rowEnd合理取值范围为0\~总行数-1，columnStart/columnEnd合理取值范围为0\~总列数-1。
>
>  如果设置了rowStart/rowEnd/columnStart/columnEnd，GridItem会占据指定的行数(rowEnd-rowStart+1)或列数(columnEnd-columnStart+1)。
>
>  只有在设置columnTemplate和rowTemplate的Grid中，设置合理的rowStart/rowEnd/columnStart/columnEnd四个属性的GridItem才能按照指定的行列号布局。
>
>  在设置columnTemplate和rowTemplate的Grid中，单独设置行号rowStart/rowEnd或列号columnStart/columnEnd的GridItem会按照一行一列进行布局。
>
>  在只设置columnTemplate的Grid中设置列号columnStart/columnEnd的GridItem按照列数布局。在该区域位置存在GridItem布局，则直接换行进行放置。
>
>  在只设置rowTemplate的Grid中设置行号rowStart/rowEnd的GridItem按照行数布局。在该区域位置存在GridItem布局，则直接换列进行放置。
>
>  在只设置columnTemplate的Grid中，在GridItem上设置了不合理的值，GridItem按照一行一列进行布局。
>
>  columnTemplate和rowTemplate都不设置的Grid中GridItem的行列号属性无效。

## GridItemOptions<sup>11+</sup>对象说明

| 名称  | 参数类型                                  | 必填 | 描述                                                         |
| ----- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| style | [GridItemStyle](#griditemstyle11枚举说明) | 否   | 设置GridItem样式。<br/>默认值: GridItemStyle.NONE<br/>设置为GridItemStyle.NONE时无样式。<br/>设置为GridItemStyle.PLAIN时，显示Hover、Press态样式。 |

## GridItemStyle<sup>11+</sup>枚举说明

| 名称  | 描述                     |
| ----- | ------------------------ |
| NONE  | 无样式。                 |
| PLAIN | 显示Hover、Press态样式。 |

> **说明：**
>
> GridItem焦点态样式设置：Grid组件需要设置4vp规格以上的内边距，用于显示GridItem的焦点框。


## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onSelect(event:&nbsp;(isSelected:&nbsp;boolean)&nbsp;=&gt;&nbsp;void)<sup>8+</sup> | GridItem元素被鼠标框选的状态改变时触发回调。<br/>isSelected：进入鼠标框选范围即被选中返回true，&nbsp;移出鼠标框选范围即未被选中返回false。 |

## 示例

### 示例1

```ts
// xxx.ets
@Entry
@Component
struct GridItemExample {
  @State numbers: string[] = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"]

  build() {
    Column() {
      Grid() {
        GridItem() {
          Text('4')
            .fontSize(16)
            .backgroundColor(0xFAEEE0)
            .width('100%')
            .height('100%')
            .textAlign(TextAlign.Center)
        }.rowStart(1).rowEnd(2).columnStart(1).columnEnd(2) // 同时设置合理的行列号

        ForEach(this.numbers, (item: string) => {
          GridItem() {
            Text(item)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height('100%')
              .textAlign(TextAlign.Center)
          }
        }, (item: string) => item)

        GridItem() {
          Text('5')
            .fontSize(16)
            .backgroundColor(0xDBD0C0)
            .width('100%')
            .height('100%')
            .textAlign(TextAlign.Center)
        }.columnStart(1).columnEnd(4) // 只设置列号，不会从第1列开始布局
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .width('90%').height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001174582870](figures/zh-cn_image_0000001174582870.gif)

### 示例2

使用GridItemOptions

```ts
// xxx.ets
@Entry
@Component
struct GridItemExample {
  @State Number: String[] = ['0', '1', '2']

  build() {
    Column({ space: 5 }) {
      Grid() {
        ForEach(this.Number, (day: string) => {
          ForEach(this.Number, (day: string) => {
            GridItem({style:GridItemStyle.NONE}) {
              Text(day)
                .fontSize(16)
                .width('100%')
                .height('100%')
                .textAlign(TextAlign.Center)
                .focusable(true)
            }
            .backgroundColor(0xF9CF93)
          }, (day: string) => day)
        }, (day: string) => day)
      }
      .columnsTemplate('1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr')
      .columnsGap(4)
      .rowsGap(4)
      .width('60%')
      .backgroundColor(0xFAEEE0)
      .height(150)
      .padding('4vp')

      Grid() {
        ForEach(this.Number, (day: string) => {
          ForEach(this.Number, (day: string) => {
            GridItem({style:GridItemStyle.PLAIN}) {
              Text(day)
                .fontSize(16)
                .width('100%')
                .height('100%')
                .textAlign(TextAlign.Center)
                .focusable(true)
            }
            .backgroundColor(0xF9CF93)
          }, (day: string) => day)
        }, (day: string) => day)
      }
      .columnsTemplate('1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr')
      .columnsGap(4)
      .rowsGap(4)
      .width('60%')
      .backgroundColor(0xFAEEE0)
      .height(150)
      .padding('4vp')
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-ch_image_griditem_griditemoptions](figures/zh-ch_image_griditem_griditemoptions.png)
