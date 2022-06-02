# 列表选择弹窗

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


列表弹窗。


## 权限

无


## ActionSheet.show

show(options: {&nbsp;paramObject1})

定义列表弹窗并弹出。

- paramObject1参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | title | string&nbsp;\|&nbsp;[Resource](../../ui/ts-types.md#resource类型) | 否 | 无标题 | 弹窗标题。 |
  | message | string&nbsp;\|&nbsp;[Resource](../../ui/ts-types.md#resource类型) | 是 | - | 弹窗内容。 |
  | autoCancel | boolean | 否 | true | 点击遮障层时，是否关闭弹窗。 |
  | confirm | {<br/>value:&nbsp;string&nbsp;\|&nbsp;[Resource](../../ui/ts-types.md#resource类型),<br/>action:&nbsp;()&nbsp;=&gt;&nbsp;void<br/>} | 否 | - | 确认按钮的文本内容和点击回调。<br/>value：按钮文本内容。<br/>action:&nbsp;按钮选中时的回调。 |
  | cancel | ()&nbsp;=&gt;&nbsp;void | 否 | - | 点击遮障层关闭dialog时的回调。 |
  | alignment | [DialogAlignment](ts-methods-custom-dialog-box.md) | 否 | DialogAlignment.Default | 弹窗在竖直方向上的对齐方式。 |
  | offset | {<br/>dx:&nbsp;Length,<br/>dy:&nbsp;Length<br/>} | 否 | {<br/>dx:&nbsp;0,<br/>dy:&nbsp;0<br/>} | 弹窗相对alignment所在位置的偏移量。 |
  | sheets | Array<SheetInfo&gt; | 是 | - | 设置选项内容，每个选择项支持设置图片、文本和选中的回调。 |

- SheetInfo接口说明
  
  | 参数名 | 参数类型                                                     | 必填 | 默认值 | 参数描述          |
  | ------ | ------------------------------------------------------------ | ---- | ------ | ----------------- |
  | title  | string&nbsp;\|&nbsp;[Resource](../../ui/ts-types.md#resource类型) | 是   | -      | sheet文本。       |
  | icon   | string&nbsp;\|&nbsp;[Resource](../../ui/ts-types.md#resource类型) | 否   | 无     | sheet图标。       |
  | action | ()=&gt;void                                                  | 是   | -      | sheet选中的回调。 |


## 示例


```ts
// xxx.ets
@Entry
@Component
struct ActionSheetExapmle {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Button('Click to Show ActionSheet')
        .onClick(() => {
          ActionSheet.show({
            title: 'ActionSheet title',
            message: 'message',
            confirm: {
              value: 'Confirm button',
              action: () => {
                console.log('Get Alert Dialog handled')
              }
            },
            sheets: [
              {
                title: 'apples',
                action: () => {
                  console.error('apples')
                }
              },
              {
                title: 'bananas',
                action: () => {
                  console.error('bananas')
                }
              },
              {
                title: 'pears',
                action: () => {
                  console.error('pears')
                }
              }
            ]
          })
        })
    }.width('100%')
    .height('100%')
  }
}
```


![zh-cn_image_0000001241668363](figures/zh-cn_image_0000001241668363.gif)

