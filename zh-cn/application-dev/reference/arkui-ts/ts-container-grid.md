# Grid

>  **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

网格容器，由“行”和“列”分割的单元格所组成，通过指定“项目”所在的单元格做出各种各样的布局。




## 权限列表

无


## 子组件

包含[GridItem](ts-container-griditem.md)子组件。


## 接口

Grid()


## 属性

| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| columnsTemplate | string | '1fr' | 用于设置当前网格布局列的数量，不设置时默认1列&nbsp;示例,&nbsp;'1fr&nbsp;1fr&nbsp;2fr'&nbsp;分三列，将父组件允许的宽分为4等份，第一列占1份，第二列占一份，第三列占2份。 |
| rowsTemplate | string | '1fr' | 用于设置当前网格布局行的数量，不设置时默认1行&nbsp;示例,&nbsp;'1fr&nbsp;1fr&nbsp;2fr'分三行，将父组件允许的高分为4等份，第一行占1份，第二行占一份，第三行占2份。 |
| columnsGap | Length | 0 | 用于设置列与列的间距。 |
| rowsGap | Length | 0 | 用于设置行与行的间距。 |
| editMode<font color=ff0000><sup>8+</sup></font> | boolean | flase | 是否进入编辑模式，进入编辑模式可以拖拽Gird组件内部[GridItem](ts-container-griditem.md)。 |
| layoutDirection<font color=ff0000><sup>8+</sup></font>  | number | 0 |设置布局的主轴方向，目前支持的主轴布局方向如下：<br/>-&nbsp;0：主轴布局方向沿水平方向布局，即先填满一列，再去填下一列。 <br/>-&nbsp;1：主轴布局方向沿垂直方向布局，即先填满一行，再去填下一行。|
| maxCount<font color=ff0000><sup>8+</sup></font> | number | 1 | 当layoutDirection是Row时，表示可显示的最大行数<br/>当layoutDirection是Column时，表示可显示的最大列数。 |
| minCount<font color=ff0000><sup>8+</sup></font> | number | 1 | 当layoutDirection是Row时，表示可显示的最小行数<br/>当layoutDirection是Column时，表示可显示的最小列数。 |
| cellLength<font color=ff0000><sup>8+</sup></font> | number | 0 | 当layoutDirection是Row时，表示一行的高度<br/>当layoutDirection是Column时，表示一列的宽度。 |
| multiSelectable<font color=ff0000><sup>8+</sup></font> | boolean | false | 是否开启鼠标框选。<br/>-&nbsp;false：关闭框选。<br/>-&nbsp;true：开启框选。 |
| supportAnimation<font color=ff0000><sup>8+</sup></font> | boolean         | false                 | 控制Grid是否支持动画。 |

## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onScrollIndex(first:&nbsp;number)&nbsp;=&gt;&nbsp;void | 当前列表显示的起始位置item发生变化时触发。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct GridExample {
  @State Number: String[] = ['0', '1', '2', '3', '4']

  build() {
    Column({ space: 5 }) {
      Grid() {
        ForEach(this.Number, (day: string) => {
          ForEach(this.Number, (day: string) => {
            GridItem() {
              Text(day)
                .fontSize(16)
                .backgroundColor(0xF9CF93)
                .width('100%')
                .height('100%')
                .textAlign(TextAlign.Center)
            }
          }, day => day)
        }, day => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)

      Text('scroll').fontColor(0xCCCCCC).fontSize(9).width('90%')
      Grid() {
        ForEach(this.Number, (day: string) => {
          ForEach(this.Number, (day: string) => {
            GridItem() {
              Text(day)
                .fontSize(16)
                .backgroundColor(0xF9CF93)
                .width('100%')
                .height(80)
                .textAlign(TextAlign.Center)
            }
          }, day => day)
        }, day => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .onScrollIndex((first: number) => {
        console.info(first.toString())
      })
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001219744183](figures/zh-cn_image_0000001219744183.gif)