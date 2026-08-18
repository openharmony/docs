# GridItem

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @rongShao-Z; @guozejun-->
<!--Designer: @guozejun-->
<!--Tester: @leiyuqian-->
<!--Adviser: @Brilliantry_Rui-->

网格容器中单项内容容器。

>  **说明：**
>
>  * 该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>  * 仅支持作为[Grid](ts-container-grid.md)组件的子组件使用。
>  * 当GridItem配合[LazyForEach](../../../ui/rendering-control/arkts-rendering-control-lazyforeach.md)使用时，GridItem子组件在GridItem创建时创建。配合[if/else](../../../ui/rendering-control/arkts-rendering-control-ifelse.md)、[ForEach](../../../ui/rendering-control/arkts-rendering-control-foreach.md)使用时，或父组件为Grid时，GridItem子组件在GridItem布局时创建。
>  * 当Grid中存在大量GridItem时，使用[columnStart](#columnstart)/[columnEnd](#columnend)、[rowStart](#rowstart)/[rowEnd](#rowend)设置GridItem大小会导致在使用scrollToIndex滑动到指定Index时，依次遍历GridItem节点，耗时较长。建议使用[GridLayoutOptions](ts-container-grid.md#gridlayoutoptions10对象说明)布局，以提高查找GridItem位置的效率。最佳实践请参考[优化Grid组件加载慢丢帧问题](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-improve_grid_performance)。

## 子组件

可以包含单个子组件。

## 接口

GridItem(value?: GridItemOptions)

创建网格容器中单项内容容器。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                      | 必填 | 说明                                                     |
| ------ | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| value<sup>11+</sup>  | [GridItemOptions](#griditemoptions11对象说明) | 否   | 为GridItem提供可选参数，该对象内包含[GridItemStyle](#griditemstyle11枚举说明)枚举类型的style参数。不传入时使用默认样式，即GridItemStyle.NONE。<br/>**模型约束：** 此接口仅可在Stage模型下使用。 |

## 属性

### rowStart

rowStart(value: number)

设置当前元素起始行号。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| value  | number | 是   | 当前元素起始行号。<br/>需要指定GridItem起始行列号和所占行列数的场景推荐使用Grid的[GridLayoutOptions](ts-container-grid.md#gridlayoutoptions10对象说明)参数，详细可参考Grid的[示例1（固定行列Grid）](ts-container-grid.md#示例1固定行列grid)和[示例3（可滚动Grid设置跨行跨列节点）](ts-container-grid.md#示例3可滚动grid设置跨行跨列节点)。<br/>取值范围：[0, 总行数-1] |

### rowEnd

rowEnd(value: number)

设置当前元素终点行号。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| value  | number | 是   | 当前元素终点行号。<br/>需要指定GridItem起始行列号和所占行列数的场景推荐使用Grid的[GridLayoutOptions](ts-container-grid.md#gridlayoutoptions10对象说明)参数，详细可参考Grid的[示例1（固定行列Grid）](ts-container-grid.md#示例1固定行列grid)和[示例3（可滚动Grid设置跨行跨列节点）](ts-container-grid.md#示例3可滚动grid设置跨行跨列节点)。<br/>取值范围：[0, 总行数-1] |

### columnStart

columnStart(value: number)

设置当前元素起始列号。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| value  | number | 是   | 当前元素起始列号。<br/>需要指定GridItem起始行列号和所占行列数的场景推荐使用Grid的[GridLayoutOptions](ts-container-grid.md#gridlayoutoptions10对象说明)参数，详细可参考Grid的[示例1（固定行列Grid）](ts-container-grid.md#示例1固定行列grid)和[示例3（可滚动Grid设置跨行跨列节点）](ts-container-grid.md#示例3可滚动grid设置跨行跨列节点)。<br/>取值范围：[0, 总列数-1] |

### columnEnd

columnEnd(value: number)

设置当前元素终点列号。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| value  | number | 是   | 当前元素终点列号。<br/>需要指定GridItem起始行列号和所占行列数的场景推荐使用Grid的[GridLayoutOptions](ts-container-grid.md#gridlayoutoptions10对象说明)参数，详细可参考Grid的[示例1（固定行列Grid）](ts-container-grid.md#示例1固定行列grid)和[示例3（可滚动Grid设置跨行跨列节点）](ts-container-grid.md#示例3可滚动grid设置跨行跨列节点)。<br/>取值范围：[0, 总列数-1] |

需要指定GridItem起始行列号和所占行列数的场景推荐使用Grid的[GridLayoutOptions](ts-container-grid.md#gridlayoutoptions10对象说明)参数，详细可参考Grid的[示例1（固定行列Grid）](ts-container-grid.md#示例1固定行列grid)和[示例3（可滚动Grid设置跨行跨列节点）](ts-container-grid.md#示例3可滚动grid设置跨行跨列节点)。

起始行号、终点行号、起始列号、终点列号生效规则如下：

* rowStart/rowEnd合理取值范围为0\~总行数-1，columnStart/columnEnd合理取值范围为0\~总列数-1。

* 如果设置了rowStart/rowEnd/columnStart/columnEnd，GridItem会占据指定的行数(rowEnd-rowStart+1)或列数(columnEnd-columnStart+1)。

* 只有在设置columnsTemplate和rowsTemplate的Grid中，设置合理的rowStart/rowEnd/columnStart/columnEnd四个属性的GridItem才能按照指定的行列号布局。

* 在设置columnsTemplate和rowsTemplate的Grid中，单独设置行号rowStart/rowEnd或列号columnStart/columnEnd的GridItem会按照一行一列进行布局。

* 在只设置columnsTemplate的Grid中设置列号columnStart/columnEnd的GridItem按照列数布局。在该区域位置存在GridItem布局，则直接换行进行放置。

* 在只设置rowsTemplate的Grid中设置行号rowStart/rowEnd的GridItem按照行数布局。在该区域位置存在GridItem布局，则直接换列进行放置。

* columnsTemplate和rowsTemplate都不设置的Grid中GridItem的行列号属性无效。

以下是GridItem行列号异常值的处理规则：

| 属性设置情况  | 异常类型 | 修正后布局规则  |
| ----- |----| ------------------------ |
| 仅设置columnsTemplate  |  任意行列异常 | 按一行一列布局。 |
| 仅设置rowsTemplate |  任意行列异常 | 按一行一列布局。 |
| 同时设置rows/columnsTemplate |  rowStart < rowEnd | 行跨度 = min(rowEnd-rowStart+1, 总行数)。 |
| 同时设置rows/columnsTemplate |  rowStart > rowEnd | 按一行一列布局。 |
| 同时设置rows/columnsTemplate |  columnStart < columnEnd | 列跨度 = min(columnEnd-columnStart+1, 总列数)。 |
| 同时设置rows/columnsTemplate |  columnStart > columnEnd | 按一行一列布局。 |

### forceRebuild<sup>(deprecated)</sup>

forceRebuild(value: boolean)

设置在触发组件build时是否重新创建此节点。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃。GridItem会根据自身属性和子组件变化自行决定是否需要重新创建，无需设置。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                    |
| ------ | ------- | ---- | ------------------------------------------------------- |
| value  | boolean | 是   | 设置为true时，在触发组件build时重新创建此节点；设置为false时，不强制重新创建此节点。<br/>默认值：false |

### selectable<sup>8+</sup>

selectable(value: boolean)

设置当前GridItem元素是否可以被鼠标框选。外层Grid容器的鼠标框选开启时，GridItem的框选才生效。

该属性需要在设置[多态样式](./ts-universal-attributes-polymorphic-style.md)前使用才能生效选中态样式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                  |
| ------ | ------- | ---- | ----------------------------------------------------- |
| value  | boolean | 是   | 当前GridItem元素是否可以被鼠标框选。设置为true时可以被鼠标框选，设置为false时无法被鼠标框选。<br/>默认值：true |

### selected<sup>10+</sup>

selected(value: boolean)

设置当前GridItem选中状态。该属性支持[$$](../../../ui/state-management/arkts-two-way-sync.md)双向绑定变量。

该属性需要在设置[多态样式](./ts-universal-attributes-polymorphic-style.md)前使用才能生效选中态样式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                     |
| ------ | ------- | ---- | ---------------------------------------- |
| value  | boolean | 是   | 当前GridItem选中状态。设置为true时为选中状态，设置为false时为非选中状态。<br/>默认值：false |

## GridItemOptions<sup>11+</sup>对象说明

GridItem样式对象，用于配置GridItem的样式选项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型                  | 只读 | 可选 | 说明                         |
| ----- | -------------------- | ---- | --- | ---------------------------- |
| style | [GridItemStyle](#griditemstyle11枚举说明) | 否   | 是 | 设置GridItem样式。<br/>默认值：GridItemStyle.NONE<br/>设置为GridItemStyle.NONE时无样式。<br/>设置为GridItemStyle.PLAIN时，显示Hover、Press态样式。Hover态为鼠标悬停时的样式，Press态为按下时的样式。 |

## GridItemStyle<sup>11+</sup>枚举说明

GridItem样式枚举，用于定义GridItem的交互态样式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  |值| 说明                   |
| ----- |----| ------------------------ |
| NONE  |  0 | 无样式，不显示Hover、Press态样式。                 |
| PLAIN |  1 | 显示Hover、Press态样式。Hover态为鼠标悬停时的样式，Press态为按下时的样式。 |

> **说明：**
>
> GridItem焦点态样式设置：Grid组件需要设置4vp规格以上的内边距，用于显示GridItem的焦点框。

## 事件

### onSelect<sup>8+</sup>

onSelect(event: (isSelected: boolean) => void)

GridItem元素被鼠标框选的状态改变时触发回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名     | 类型    | 必填 | 说明                                                         |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| isSelected | boolean | 是   | 进入鼠标框选范围即被选中返回true，移出鼠标框选范围即未被选中返回false。 |

## 示例

### 示例1（GridItem设置自身位置）
GridItem通过设置合理的rowStart、rowEnd、columnStart、columnEnd属性来设置自身位置。需要指定GridItem起始行列号和所占行列数的场景推荐使用Grid的[GridLayoutOptions](ts-container-grid.md#gridlayoutoptions10对象说明)参数，详细可参考Grid的[示例1（固定行列Grid）](ts-container-grid.md#示例1固定行列grid)和[示例3（可滚动Grid设置跨行跨列节点）](ts-container-grid.md#示例3可滚动grid设置跨行跨列节点)。

```ts
// xxx.ets
@Entry
@Component
struct GridItemExample {
  @State numbers: string[] = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15'];

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
        }.columnStart(1).columnEnd(4) // 未设置行号，不按columnStart(1)定位；此处从第5行、索引为0的列开始并跨4列布局
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .width('90%').height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![gridItem](figures/gridItem.gif)

### 示例2（设置GridItem样式）

使用GridItemOptions设置GridItem样式。

```ts
// xxx.ets
@Entry
@Component
struct GridItemExample {
  @State numbers: string[] = ['0', '1', '2'];

  build() {
    Column({ space: 5 }) {
      Grid() {
        ForEach(this.numbers, (rowItem: string) => {
          ForEach(this.numbers, (item: string) => {
            GridItem({ style: GridItemStyle.NONE }) {
              Text(item)
                .fontSize(16)
                .width('100%')
                .height('100%')
                .textAlign(TextAlign.Center)
                .focusable(true)
            }
            .backgroundColor(0xF9CF93)
          }, (item: string) => item)
        }, (rowItem: string) => rowItem)
      }
      .columnsTemplate('1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr')
      .columnsGap(4)
      .rowsGap(4)
      .width('60%')
      .backgroundColor(0xFAEEE0)
      .height(150)
      .padding(4)

      Grid() {
        ForEach(this.numbers, (rowItem: string) => {
          ForEach(this.numbers, (item: string) => {
            GridItem({ style: GridItemStyle.PLAIN }) {
              Text(item)
                .fontSize(16)
                .width('100%')
                .height('100%')
                .textAlign(TextAlign.Center)
                .focusable(true)
            }
            .backgroundColor(0xF9CF93)
          }, (item: string) => item)
        }, (rowItem: string) => rowItem)
      }
      .columnsTemplate('1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr')
      .columnsGap(4)
      .rowsGap(4)
      .width('60%')
      .backgroundColor(0xFAEEE0)
      .height(150)
      .padding(4)
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_griditem_griditemoptions](figures/griditem-griditemoptions.png)
