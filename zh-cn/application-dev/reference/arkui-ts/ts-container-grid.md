# Grid

网格容器，由“行”和“列”分割的单元格所组成，通过指定“项目”所在的单元格做出各种各样的布局。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

仅支持[GridItem](ts-container-griditem.md)子组件。

>  **说明：**
>
>  Grid子组件的索引值计算规则：
>
>  按子组件的顺序依次递增。
>
>  if/else语句中，只有条件成立分支内的子组件会参与索引值计算，条件不成立分支内的子组件不计算索引值。
>
>  ForEach/LazyForEach语句中，会计算展开所有子节点索引值。
>
>  [if/else](../../quick-start/arkts-rendering-control-ifelse.md)、[ForEach](../../quick-start/arkts-rendering-control-foreach.md)和[LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)发生变化以后，会更新子节点索引值。
>
>  Grid子组件的visibility属性设置为Hidden或None时依然会计算索引值。
>
>  Grid子组件的visibility属性设置为None时不显示，但依然会占用子组件对应的网格。
>
>  Grid子组件设置position属性，会占用子组件对应的网格，子组件将显示在相对Grid左上角偏移position的位置。该子组件不会随其对应网格滚动，在对应网格滑出Grid显示范围外后不显示。
>
>  当Grid子组件之间留有空隙时，会根据当前的展示区域尽可能填补空隙，因此GridItem可能会随着网格滚动而改变相对位置。

## 接口

Grid(scroller?: Scroller, layoutOptions?: GridLayoutOptions)

**参数：**

| 参数名   | 参数类型                                    | 必填 | 参数描述                                                     |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| scroller | [Scroller](ts-container-scroll.md#scroller) | 否   | 可滚动组件的控制器。用于与可滚动组件进行绑定。<br/>**说明：** <br/>不允许和其他[滚动类组件](ts-container-list.md)绑定同一个滚动控制对象。 |
| layoutOptions<sup>10+</sup> | GridLayoutOptions | 否 | 滚动Grid布局选项。 |

### GridLayoutOptions<sup>10+</sup>

布局选项，配合rowsTemplate、columnsTemplate仅设置其中一个的Grid使用，可以替代通过columnStart/columnEnd控制GridItem占用多列、rowStart/rowEnd控制GridItem占用多行的场景。

**参数：**
| 名称    | 类型      | 必填   | 描述                    |
| ----- | ------- | ---- | --------------------- |
| regularSize  | [number, number]  | 是    | 大小规则的GridItem在Grid中占的行数和列数，只支持占1行1列即[1, 1]。   |
| irregularIndexes | number[] | 否    | 大小不规则的GridItem在Grid所有子节点中的索引值。onGetIrregularSizeByIndex不设置时irregularIndexes中的GridItem默认占垂直滚动Grid的一整行或水平滚动Grid的一整列。 |
| onGetIrregularSizeByIndex | (index: number) => [number, number] | 否    | 获取不规则GridItem占用的行数和列数，布局过程中针对irregularIndexes中的index调用，开发者应返回index对应GridItem占用的行数和列数。垂直滚动Grid不支持GridItem占多行，水平滚动Grid不支持GridItem占多列。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| columnsTemplate | string | 设置当前网格布局列的数量或最小列宽值，不设置时默认1列。<br/>例如,&nbsp;'1fr&nbsp;1fr&nbsp;2fr'&nbsp;是将父组件分3列，将父组件允许的宽分为4等份，第一列占1份，第二列占1份，第三列占2份。<br/>‘repeat(auto-fit, 90px)’是设置最小列宽值为90，自动计算列数和实际列宽。<br/>**说明：** <br/>设置为'0fr'时，该列的列宽为0，不显示GridItem。设置为其他非法值时，GridItem显示为固定1列。 |
| rowsTemplate | string | 设置当前网格布局行的数量或最小行高值，不设置时默认1行。<br/>例如,&nbsp;'1fr&nbsp;1fr&nbsp;2fr'是将父组件分三行，将父组件允许的高分为4等份，第一行占1份，第二行占一份，第三行占2份。<br/>‘repeat(auto-fit, 90px)’是设置最小行高值为90，自动计算行数和实际行高。<br/>**说明：** <br/>设置为'0fr'，则这一行的行宽为0，这一行GridItem不显示。设置为其他非法值，按固定1行处理。 |
| columnsGap | [Length](ts-types.md#length) | 设置列与列的间距。<br/>默认值：0<br/>**说明：** <br/>设置为小于0的值时，按默认值显示。 |
| rowsGap | [Length](ts-types.md#length) | 设置行与行的间距。<br/>默认值：0<br/>**说明：** <br/>设置为小于0的值时，按默认值显示。 |
| scrollBar      | [BarState](ts-appendix-enums.md#barstate) | 设置滚动条状态。<br/>默认值：BarState.Off<br/>**说明：** <br/>API version 9及以下版本默认值为BarState.Off，API version 10的默认值为BarState.Auto。 |
| scrollBarColor | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;[Color](ts-appendix-enums.md#color) | 设置滚动条的颜色。 |
| scrollBarWidth | string \| number    | 设置滚动条的宽度。宽度设置后，滚动条正常状态和按压状态宽度均为滚动条的宽度值。<br/>默认值：4<br/>单位：vp |
| cachedCount | number                                   | 设置预加载的GridItem的数量，只在[LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)中生效。具体使用可参考[减少应用白块说明](../../performance/arkts-performance-improvement-recommendation.md#减少应用滑动白块)。<br/>默认值：1<br/>**说明：** <br>设置缓存后会在Grid显示区域上下各缓存cachedCount*列数个GridItem。<br/>[LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)超出显示和缓存范围的GridItem会被释放。<br/>设置为小于0的值时，按默认值显示。 |
| editMode <sup>8+</sup>                   | boolean | 设置Grid是否进入编辑模式，进入编辑模式可以拖拽Grid组件内部[GridItem](ts-container-griditem.md)。<br/>默认值：flase |
| layoutDirection<sup>8+</sup>             | [GridDirection](#griddirection8枚举说明) | 设置布局的主轴方向。<br/>默认值：GridDirection.Row |
| maxCount<sup>8+</sup> | number  | 当layoutDirection是Row/RowReverse时，表示可显示的最大列数<br/>当layoutDirection是Column/ColumnReverse时，表示可显示的最大行数。<br/>默认值：Infinity<br/>**说明：** <br/>当maxCount小于minCount时，maxCount和minCount都按默认值处理。<br/>设置为小于1的值时，按默认值显示。 |
| minCount<sup>8+</sup> | number  | 当layoutDirection是Row/RowReverse时，表示可显示的最小列数。<br/>当layoutDirection是Column/ColumnReverse时，表示可显示的最小行数。<br/>默认值：1<br/>**说明：** <br/>设置为小于1的值时，按默认值显示。 |
| cellLength<sup>8+</sup> | number  | 当layoutDirection是Row/RowReverse时，表示一行的高度。<br/>当layoutDirection是Column/ColumnReverse时，表示一列的宽度。<br/>默认值：第一个元素的大小 |
| multiSelectable<sup>8+</sup> | boolean | 是否开启鼠标框选。<br/>默认值：false<br/>-&nbsp;false：关闭框选。<br/>-&nbsp;true：开启框选。<br/>**说明：**<br/> 开启框选后，可以配合Griditem的selected属性和onSelect事件获取GridItem的选中状态，还可以设置[选中态样式](./ts-universal-attributes-polymorphic-style.md)（无默认选中样式）。 |
| supportAnimation<sup>8+</sup> | boolean | 是否支持动画。当前支持GridItem拖拽动画。<br/>默认值：false<br/>**说明：**<br/> 仅在滚动模式下（只设置rowsTemplate、columnsTemplate其中一个）支持动画。|
| edgeEffect<sup>10+</sup> | [EdgeEffect](ts-appendix-enums.md#edgeeffect), [EdgeEffectOptions<sup>11+</sup>](ts-container-scroll.md#edgeeffectoptions11对象说明)?: | 设置组件的滑动效果，支持弹簧效果和阴影效果。<br/>默认值：EdgeEffect.None<br/> edgeEffectOptions用于设置组件内容大小小于组件自身时，是否开启滑动效果<br/>默认值：false|
| enableScrollInteraction<sup>10+</sup>  |  boolean  |   设置是否支持滚动手势，当设置为false时，无法通过手指或者鼠标滚动，但不影响控制器的滚动接口。<br/>默认值：true      |
| nestedScroll<sup>10+</sup>                 | [NestedScrollOptions](ts-container-scroll.md#nestedscrolloptions10对象说明)         | 嵌套滚动选项。设置向前向后两个方向上的嵌套滚动模式，实现与父组件的滚动联动。 |
| friction<sup>10+</sup> | number \| [Resource](ts-types.md#resource)    | 设置摩擦系数，手动划动滚动区域时生效，只对惯性滚动过程有影响，对惯性滚动过程中的链式效果有间接影响。<br/>默认值：非可穿戴设备为0.6，可穿戴设备为0.9<br/>**说明：** <br/>设置为小于等于0的值时，按默认值处理 |

Grid组件根据rowsTemplate、columnsTemplate属性的设置情况，可分为以下三种布局模式：

1、rowsTemplate、columnsTemplate同时设置：

- Grid只展示固定行列数的元素，其余元素不展示，且Grid不可滚动。
- 此模式下以下属性不生效：layoutDirection、maxCount、minCount、cellLength。
- Grid的宽高没有设置时，默认适应父组件尺寸。
- Gird网格列大小按照Gird自身内容区域大小减去所有行列Gap后按各个行列所占比重分配。
- GridItem默认填满网格大小。

2、rowsTemplate、columnsTemplate仅设置其中的一个：

- 元素按照设置的方向进行排布，超出Grid显示区域后，Grid可通过滚动的方式展示。
- 如果设置了columnsTemplate，Gird滚动方向为垂直方向，主轴方向为垂直方向，交叉轴方向为水平方向。
- 如果设置了rowsTemplate，Gird滚动方向为水平方向，主轴方向为水平方向，交叉轴方向为垂直方向。
- 此模式下以下属性不生效：layoutDirection、maxCount、minCount、cellLength。
- 网格交叉轴方向尺寸根据Gird自身内容区域交叉轴尺寸减去交叉轴方向所有Gap后按所占比重分配。
- 网格主轴方向尺寸取当前网格交叉轴方向所有GridItem高度最大值。

3、rowsTemplate、columnsTemplate都不设置：

- 元素在layoutDirection方向上排布，列数由Grid的宽度、首个元素的宽度、minCount、maxCount、columnsGap共同决定。
- 行数由Grid高度、首个元素高度、cellLength、rowsGap共同决定。超出行列容纳范围的元素不显示，也不能通过滚动进行展示。
- 此模式下仅生效以下属性：layoutDirection、maxCount、minCount、cellLength、editMode、columnsGap、rowsGap。
- 当前layoutDirection设置为Row时，先从左到右排列，排满一行再排一下一列。剩余高度不足时不再布局，整体内容顶部居中。
- 当前layoutDirection设置为Column时，先从上到下排列，排满一列再排一下一列，剩余宽度度不足时不再。整体内容顶部居中。

## GridDirection<sup>8+</sup>枚举说明

| 名称   | 描述                                   |
| ------ | -------------------------------------- |
| Row  | 主轴布局方向沿水平方向布局，即自左往右先填满一行，再去填下一行。 |
| Column | 主轴布局方向沿垂直方向布局，即自上往下先填满一列，再去填下一列。 |
| RowReverse    | 主轴布局方向沿水平方向反向布局，即自右往左先填满一行，再去填下一行。 |
| ColumnReverse   | 主轴布局方向沿垂直方向反向布局，即自下往上先填满一列，再去填下一列。 |

> **说明：** 
>
> Grid组件[通用属性clip](ts-universal-attributes-sharp-clipping.md)的默认值为true。

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称 | 功能描述 |
| -------- | -------- |
| onScrollIndex(event: (first: number, last<sup>10+</sup>: number) => void) | 当前网格显示的起始位置/终止位置的item发生变化时触发。网格初始化时会触发一次。<br/>- first: 当前显示的网格起始位置的索引值。<br/>- last: 当前显示的网格终止位置的索引值。<br/>Grid显示区域上第一个子组件/最后一个组件的索引值有变化就会触发。 |
| onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => (() => any) \| void) | 开始拖拽网格元素时触发。<br/>- event: 见[ItemDragInfo对象说明](#itemdraginfo对象说明)。<br/>- itemIndex: 被拖拽网格元素索引值。<br/>**说明：** <br/>返回void表示不能拖拽。<br/>手指长按GridItem时触发该事件。<br/>由于拖拽检测也需要长按，且事件处理机制优先触发子组件事件，GridItem上绑定LongPressGesture时无法触发拖拽；如有长按和拖拽同时使用的需求可以使用通用拖拽事件。 |
| onItemDragEnter(event: (event: ItemDragInfo) => void) | 拖拽进入网格元素范围内时触发。<br/>- event: 见[ItemDragInfo对象说明](#itemdraginfo对象说明)。 |
| onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void) | 拖拽在网格元素范围内移动时触发。<br/>- event: 见[ItemDragInfo对象说明](#itemdraginfo对象说明)。<br/>- itemIndex: 拖拽起始位置。<br/>- insertIndex: 拖拽插入位置。 |
| onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void) | 拖拽离开网格元素时触发。<br/>- event: 见[ItemDragInfo对象说明](#itemdraginfo对象说明)。<br/>- itemIndex: 拖拽离开的网格元素索引值。 |
| onItemDrop(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void) | 绑定该事件的网格元素可作为拖拽释放目标，当在网格元素内停止拖拽时触发。<br/>- event: 见[ItemDragInfo对象说明](#itemdraginfo对象说明)。<br/>- itemIndex: 拖拽起始位置。<br/>- insertIndex: 拖拽插入位置。<br/>- isSuccess: 是否成功释放。 |
| onScrollBarUpdate(event: (index: number, offset: number) => ComputedBarAttribute) | 当前网格显示的起始位置item发生变化时触发，可通过该回调设置滚动条的位置及长度。<br/>- index: 当前显示的网格起始位置的索引值。<br/>- offset: 当前显示的网格起始位置元素相对网格显示起始位置的偏移。<br/>- ComputedBarAttribute: 见[ComputedBarAttribute对象说明](#computedbarattribute对象说明)。  |
| onScroll<sup>10+</sup>(event: (scrollOffset: number, scrollState: ScrollState) => void) | 网格滑动时触发。<br/>- scrollOffset: 每帧滚动的偏移量，Grid的内容向上滚动时偏移量为正，向下滚动时偏移量为负。<br/>- [scrollState](ts-container-list.md#scrollstate枚举说明): 当前滑动状态。 |
| onReachStart<sup>10+</sup>(event: () => void)          | 网格到达起始位置时触发。<br/>**说明：** <br>Grid初始化时如果initialIndex为0会触发一次，Grid滚动到起始位置时触发一次。Grid边缘效果为弹簧效果时，划动经过起始位置时触发一次，回弹回起始位置时再触发一次。 |
| onReachEnd<sup>10+</sup>(event: () => void)            | 网格到底末尾位置时触发。<br/>**说明：** <br/>Grid边缘效果为弹簧效果时，划动经过末尾位置时触发一次，回弹回末尾位置时再触发一次。 |
| onScrollFrameBegin<sup>10+</sup>(event: (offset: number, state: ScrollState) => { offsetRemain }) | 网格开始滑动时触发，事件参数传入即将发生的滑动量，事件处理函数中可根据应用场景计算实际需要的滑动量并作为事件处理函数的返回值返回，网格将按照返回值的实际滑动量进行滑动。<br/>\- offset：即将发生的滑动量，单位vp。<br/>\- state：当前滑动状态。<br/>- offsetRemain：实际滑动量，单位vp。<br/>触发该事件的条件：手指拖动Grid、Grid惯性划动时每帧开始时触发；Grid超出边缘回弹、使用滚动控制器的滚动不会触发。<br/>**说明：** <br/>当gridDirection的值为Axis.Vertical时，返回垂直方向滑动量，当gridDirection的值为Axis.Horizontal时，返回水平方向滑动量。 |
| onScrollStart<sup>10+</sup>(event: () => void) | 网格滑动开始时触发。手指拖动网格或网格的滚动条触发的滑动开始时，会触发该事件。使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画开始时会触发该事件。 |
| onScrollStop<sup>10+</sup>(event: () => void)          | 网格滑动停止时触发。手指拖动网格或网格的滚动条触发的滑动，手指离开屏幕并且滑动停止时会触发该事件；使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画停止会触发该事件。 |

## ItemDragInfo对象说明

| 名称         | 类型         |   描述         |
| ---------- | ---------- | ---------- |
| x | number |  当前拖拽点的x坐标。    |
| y   | number |  当前拖拽点的y坐标。    |

## ComputedBarAttribute对象说明

| 名称         | 类型         |   描述         |
| ---------- | ---------- | ---------- |
| totalOffset | number |  Grid内容相对显示区域的总偏移。    |
| totalLength   | number |  Grid内容总长度。    |

## 示例

### 示例1

```ts
// xxx.ets
@Entry
@Component
struct GridExample {
  @State Number: String[] = ['0', '1', '2', '3', '4']
  scroller: Scroller = new Scroller()

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
          }, (day: string) => day)
        }, (day: string) => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)

      Text('scroll').fontColor(0xCCCCCC).fontSize(9).width('90%')
      Grid(this.scroller) {
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
          }, (day: string) => day)
        }, (day: string) => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .friction(0.6)
      .edgeEffect(EdgeEffect.Spring)
      .scrollBar(BarState.On)
      .onScrollIndex((first: number) => {
        console.info(first.toString())
      })
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
      Button('next page')
        .onClick(() => { // 点击后滑到下一页
          this.scroller.scrollPage({ next: true })
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001219744183](figures/zh-cn_image_0000001219744183.gif)

### 示例2

1.  设置属性editMode\(true\)设置Grid是否进入编辑模式，进入编辑模式可以拖拽Grid组件内部GridItem。

2.  在[onItemDragStart](#事件)回调中设置拖拽过程中显示的图片。

3.  在[onItemDrop](#事件)中获取拖拽起始位置，和拖拽插入位置，在[onDrag](#事件)回调中完成交换数组位置逻辑。

```ts
@Entry
@Component
struct GridExample {
  @State numbers: string[] = []
  scroller: Scroller = new Scroller()
  @State text: string = 'drag'

  @Builder pixelMapBuilder() { //拖拽过程样式
    Column() {
      Text(this.text)
        .fontSize(16)
        .backgroundColor(0xF9CF93)
        .width(80)
        .height(80)
        .textAlign(TextAlign.Center)
    }
  }

  aboutToAppear() {
    for (let i = 1;i <= 15; i++) {
      this.numbers.push(i + '')
    }
  }

  changeIndex(index1: number, index2: number) { //交换数组位置
    let temp: string;
    temp = this.numbers[index1];
    this.numbers[index1] = this.numbers[index2];
    this.numbers[index2] = temp;
  }

  build() {
    Column({ space: 5 }) {
      Grid(this.scroller) {
        ForEach(this.numbers, (day: string) => {
          GridItem() {
            Text(day)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width(80)
              .height(80)
              .textAlign(TextAlign.Center)
          }
        })
      }
      .columnsTemplate('1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .onScrollIndex((first: number) => {
        console.info(first.toString())
      })
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
      .editMode(true) //设置Grid是否进入编辑模式，进入编辑模式可以拖拽Grid组件内部GridItem
      .onItemDragStart((event: ItemDragInfo, itemIndex: number) => { //第一次拖拽此事件绑定的组件时，触发回调。
        this.text = this.numbers[itemIndex]
        return this.pixelMapBuilder() //设置拖拽过程中显示的图片。
      })
      .onItemDrop((event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => { //绑定此事件的组件可作为拖拽释放目标，当在本组件范围内停止拖拽行为时，触发回调。
        // isSuccess=false时，说明drop的位置在grid外部；insertIndex > length时，说明有新增元素的事件发生
        if (!isSuccess || insertIndex >= this.numbers.length) {
          return
        }
        console.info('beixiang' + itemIndex + '', insertIndex + '') //itemIndex拖拽起始位置，insertIndex拖拽插入位置
        this.changeIndex(itemIndex, insertIndex)
      })
    }.width('100%').margin({ top: 5 })
  }
}
```

示例图：

网格子组件开始拖拽：

![gridDrag](figures/gridDrag.png)

网格子组件拖拽过程中：

![gridDrag](figures/gridDrag1.png)

网格子组件1与子组件6拖拽交换位置后：

![gridDrag](figures/gridDrag2.png)

### 示例3

使用GridLayoutOptions

```ts
// xxx.ets
@Entry
@Component
struct GridExample {
  @State Number: String[] = ['0', '1', '2', '3', '4']
  scroller: Scroller = new Scroller()
  layoutOptions1: GridLayoutOptions = {
    regularSize: [1, 1],        // 只支持[1, 1]
    irregularIndexes: [0, 6],   // 索引为0和6的GridItem占用一行
  }

  layoutOptions2: GridLayoutOptions = {
    regularSize: [1, 1],
    irregularIndexes: [0, 7],   // 索引为0和7的GridItem占用的列数由onGetIrregularSizeByIndex指定
    onGetIrregularSizeByIndex: (index: number) => {
      if (index === 0) {
        return [1, 5]
      }
      return [1, index % 6 + 1]
    }
  }

  build() {
    Column({ space: 5 }) {
      Grid(this.scroller, this.layoutOptions1) {
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
          }, (day: string) => day)
        }, (day: string) => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .scrollBar(BarState.Off)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)

      Text('scroll').fontColor(0xCCCCCC).fontSize(9).width('90%')
      // 不使用scroll，需要undefined占位
      Grid(undefined, this.layoutOptions2) {
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
          }, (day: string) => day)
        }, (day: string) => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .scrollBar(BarState.Off)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![gridLayoutOptions](figures/gridLayoutOptions.png)