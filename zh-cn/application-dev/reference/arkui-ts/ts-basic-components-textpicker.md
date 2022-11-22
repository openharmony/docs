# TextPicker

滑动选择文本内容的组件。

>  **说明：**
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无


## 接口

TextPicker(options?: {range: string[]|Resource, selected?: number, value?: string})

根据range指定的选择范围创建文本选择器。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| range | string[]&nbsp;\|&nbsp;[Resource](ts-types.md#resource类型) | 是 | 选择器的数据选择列表。 |
| selected | number | 否 | 设置默认选中项在数组中的索引值。<br/>默认值：0 |
| value | string | 否 | 设置默认选中项的值，优先级低于selected。<br/>默认值：第一个元素值 |

## 属性

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| defaultPickerItemHeight | number \| string | 设置Picker各选择项的高度。 |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称 | 描述 |
| -------- | -------- |
| onChange(callback:&nbsp;(value:&nbsp;string,&nbsp;index:&nbsp;number)&nbsp;=&gt;&nbsp;void) | 滑动选中TextPicker文本内容后，触发该回调。<br/>-&nbsp;value:&nbsp;当前选中项的文本。<br/>-&nbsp;index:&nbsp;当前选中项的索引值。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct TextPickerExample {
  private select: number = 1
  private fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4']

  build() {
    Column() {
      TextPicker({ range: this.fruits, selected: this.select })
        .onChange((value: string, index: number) => {
          console.info('Picker item changed, value: ' + value + ', index: ' + index)
        })
    }
  }
}
```

![zh-cn_image_0000001219662657](figures/zh-cn_image_0000001219662657.png)
