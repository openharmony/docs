# ListItem

用来展示列表具体item，宽度默认充满List组件，必须配合List来使用。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含单个子组件。


## 接口

ListItem(value?: string)


## 属性

| 名称                      | 参数类型    | 默认值         | 描述                                       |
| ----------------------- | ------- | ----------- | ---------------------------------------- |
| sticky                  | Sticky  | Sticky.None | 设置ListItem吸顶效果，参见Sticky枚举描述。<br/>默认值：Sticky.None |
| editable                | boolean&nbsp;\|&nbsp;EditMode | false       | 当前ListItem元素是否可编辑，进入编辑模式后可删除或移动。<br/>默认值：false |
| selectable<sup>8+</sup> | boolean | true        | 当前ListItem元素是否可以被鼠标框选。<br/>默认值：true<br/>**说明：**<br/>外层List容器的鼠标框选开启时，ListItem的框选才生效。 |

## Sticky枚举说明

| 名称     | 描述        |
| ------ | --------- |
| None   | 无吸顶效果。    |
| Normal | 当前item吸顶。 |
| Opacity | 当前item吸顶显示透明度变化效果。 |

## EditMode枚举说明

| 名称     | 描述        |
| ------ | --------- |
| None   | 编辑操作不限制。    |
| Deletable | 可删除。 |
| Movable | 可移动。 |

## 事件

| 名称                                       | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| onSelect(event:&nbsp;(isSelected:&nbsp;boolean)&nbsp;=&gt;&nbsp;void)<sup>8+</sup> | ListItem元素被鼠标框选的状态改变时触发回调。<br/>isSelected：进入鼠标框选范围即被选中返回true，&nbsp;移出鼠标框选范围即未被选中返回false。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ListItemExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ListItem() {
          Text('sticky:Normal , click me edit list')
            .width('100%').height(40).fontSize(12).fontColor(0xFFFFFF)
            .textAlign(TextAlign.Center).backgroundColor(0x696969)
            .onClick(() => {
              this.editFlag = !this.editFlag
            })
        }.sticky(Sticky.Normal)

        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          }.editable(this.editFlag)
        }, item => item)
      }
      .editMode(true)
      .onItemDelete((index: number) => {
        console.info(this.arr[index - 1] + 'Delete')
        this.arr.splice(index - 1,1)
        this.editFlag = false
        return true
      }).width('90%')
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001219864159](figures/zh-cn_image_0000001219864159.gif)
