# List

>  **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


列表包含一系列相同宽度的列表项。适合连续、多行呈现同类数据，例如图片和文本。


## 权限列表

无


## 子组件

包含[ListItem](ts-container-listitem.md)子组件。


## 接口

List(value:{space?: number, initialIndex?: number})

- 参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | space | number | 否 | 0 | 列表项间距。 | 
  | initialIndex | number | 否 | 0 | 设置当前List初次加载时视口起始位置显示的item，即显示第一个item，如设置的序号超过了最后一个item的序号，则设置不生效。 | 


## 属性

| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| listDirection | [Axis](ts-appendix-enums.md#axis枚举说明) | Vertical | 设置List组件排列方向参照Axis枚举说明。 |
| divider | {<br/>strokeWidth:&nbsp;Length,<br/>color?:Color,<br/>startMargin?:&nbsp;Length,<br/>endMargin?:&nbsp;Length<br/>} | - | 用于设置ListItem分割线样式，默认无分割线。<br/>strokeWidth:&nbsp;分割线的线宽。<br/>color:&nbsp;分割线的颜色。<br/>startMargin：&nbsp;分割线距离列表侧边起始端的距离。<br/>endMargin:&nbsp;分割线距离列表侧边结束端的距离。 |
| editMode | boolean | false | 声明当前List组件是否处于可编辑模式。 |
| edgeEffect | EdgeEffect | EdgeEffect.Spring | 滑动效果，目前支持的滑动效果参见EdgeEffect的枚举说明。 |
| chainAnimation | boolean | false | 用于设置当前list是否启用链式联动动效，开启后列表滑动以及顶部和底部拖拽时会有链式联动的效果。链式联动效果：list内的list-item间隔一定距离，在基本的滑动交互行为下，主动对象驱动从动对象进行联动，驱动效果遵循弹簧物理动效。<br/>-&nbsp;false：不启用链式联动。<br/>-&nbsp;true：启用链式联动。 |
| multiSelectable<sup>8+</sup> | boolean | false | 是否开启鼠标框选。<br/>-&nbsp;false：关闭框选。<br/>-&nbsp;true：开启框选。 |
| restoreId<sup>8+</sup> | number | - | 组件迁移标识符，标识后的组件在应用迁移时，组件状态会被迁移到被拉起方的同标识组件。<br/>列表组件状态，包括起始位置显示的item序号。 |

- EdgeEffect枚举说明
  | 名称 | 描述 | 
  | -------- | -------- |
  | Spring | 弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹。 | 
  | None | 滑动到边缘后无效果。 | 


## 事件

| 名称 | 功能描述 | 
| -------- | -------- |
| onItemDelete(index:&nbsp;number)&nbsp;=&gt;&nbsp;boolean | 列表项删除时触发。 | 
| onScrollIndex(firstIndex:&nbsp;number,&nbsp;lastIndex:&nbsp;number)&nbsp;=&gt;&nbsp;void | 当前列表显示的起始位置和终止位置发生变化时触发。 |

>  **说明：**
> List使能可编辑模式需配合onItemDelete事件和ListItem的editable属性，即可编辑模式实现删除列表项功能，需满足以下条件：
> 
> - editMode属性设置为true。
> 
> - 绑定onItemDelete事件，且事件回调返回true。
> 
> - ListItem的editable属性设置为true。
> 
> 实现ListItem拖拽，需满足以下条件：
> 
> - editMode属性设置为true。
> 
> - 绑定onDragStart事件，且事件回调中返回浮动UI布局。


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column() {
        List({ space: 20, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
            }.editable(true)
          }, item => item)
        }
        .listDirection(Axis.Vertical) // 排列方向
        .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 }) // 每行之间的分界线
        .edgeEffect(EdgeEffect.None) // 滑动到边缘无效果
        .chainAnimation(false) // 联动特效关闭
        .onScrollIndex((firstIndex: number, lastIndex: number) => {
          console.info('first' + firstIndex)
          console.info('last' + lastIndex)
        })
        .editMode(this.editFlag)
        .onItemDelete((index: number) => {
          console.info(this.arr[index] + 'Delete')
          this.arr.splice(index, 1)
          console.info(JSON.stringify(this.arr))
          this.editFlag = false
          return true
        }).width('90%')
      }.width('100%')

      Button('edit list')
        .onClick(() => {
          this.editFlag = !this.editFlag
        }).margin({ top: 5, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001174264378](figures/zh-cn_image_0000001174264378.gif)
