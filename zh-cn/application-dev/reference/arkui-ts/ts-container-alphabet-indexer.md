# AlphabetIndexer

可以与容器组件联动用于按逻辑结构快速定位容器显示区域的组件。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无


## 接口

AlphabetIndexer(value: {arrayValue: Array&lt;string&gt;, selected: number})

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| arrayValue | Array&lt;string&gt; | 是 | 字母索引字符串数组，不可设置为空。 |
| selected   | number              | 是    | 初始选中项索引值，若超出索引值范围，则取默认值0。     |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称                  | 参数类型     | 描述                                                              |
| ----------------------- | --------------- | ----------------------------------------------------------- |
| color                   | [ResourceColor](ts-types.md#resourcecolor)       | 设置文字颜色。<br/>默认值：0x99000000。                           |
| selectedColor           | [ResourceColor](ts-types.md#resourcecolor)     | 设置选中项文字颜色。<br/>默认值：0xFF254FF7。                           |
| popupColor              | [ResourceColor](ts-types.md#resourcecolor)        | 设置提示弹窗文字颜色。<br/>默认值：0xFF254FF7。                         |
| selectedBackgroundColor | [ResourceColor](ts-types.md#resourcecolor)       | 设置选中项背景颜色。<br/>默认值：0x1F0A59F7。                           |
| popupBackground         | [ResourceColor](ts-types.md#resourcecolor)        | 设置提示弹窗背景色。<br/>默认值：0xFFF1F3F5。                            |
| usingPopup              | boolean                                  | 设置是否使用提示弹窗。<br/>默认值：false。                         |
| selectedFont            | [Font](ts-types.md#font) | 设置选中项文字样式。<br/>默认值：<br/>{<br/>fontSize:10,<br/> fontStyle:FontStyle.Normal,<br/> fontWeight:FontWeight.Normal,<br/> fontFamily:HarmonyOS Sans<br/>}                          |
| popupFont               | [Font](ts-types.md#font) | 设置提示弹窗字体样式。<br/>默认值：<br/>{<br/>fontSize:10,<br/> fontStyle:FontStyle.Normal,<br/> fontWeight:FontWeight.Normal,<br/> fontFamily:HarmonyOS Sans<br/>}                         |
| font                    | [Font](ts-types.md#font) | 设置字母索引条默认字体样式。<br/>默认值：<br/>{<br/>fontSize:10,<br/> fontStyle:FontStyle.Normal,<br/> fontWeight:FontWeight.Normal,<br/> fontFamily:HarmonyOS Sans<br/>}                      |
| itemSize                | string&nbsp;\|&nbsp;number            | 设置字母索引条字母区域大小，字母区域为正方形，即正方形边长。不支持设置为百分比。<br/>默认值：24.0。       |
| alignStyle              | IndexerAlign                             | 设置字母索引条弹框的对齐样式，支持弹窗显示在索引条右侧和左侧。<br/>默认值:IndexerAlign.Right。 |
| selected | number | 设置选中项索引值。<br/>默认值：0。 |
| popupPosition | [Position](ts-types.md#position8) | 设置弹出窗口相对于索引器条上边框中点的位置。<br/>默认值：{x:96.0, y:48.0}。 |

## IndexerAlign枚举说明

| 名称 | 描述 |
| -------- | -------- |
| Left | 弹框显示在索引条右侧。 |
| Right | 弹框显示在索引条左侧。 |

## 事件

仅支持以下事件：

| 名称 | 功能描述 |
| -------- | -------- |
| onSelected(callback:&nbsp;(index:&nbsp;number)&nbsp;=&gt;&nbsp;void)<sup>(deprecated)</sup> | 索引条选中回调,返回值为当前选中索引。 从API Version 8开始废弃，建议使用onSelect代替。                             |
| onSelect(callback:&nbsp;(index:&nbsp;number)&nbsp;=&gt;&nbsp;void)<sup>8+</sup> | 索引条选中回调,返回值为当前选中索引。                                 |
| onRequestPopupData(callback:&nbsp;(index:&nbsp;number)&nbsp;=&gt;&nbsp;Array&lt;string&gt;)<sup>8+</sup> | 选中字母索引后，请求索引提示弹窗显示内容回调。<br/>返回值：索引对应的字符串数组，此字符串数组在弹窗中竖排显示，字符串列表最多显示5个，超出部分可以滑动显示。 |
| onPopupSelect(callback:&nbsp;(index:&nbsp;number)&nbsp;=&gt;&nbsp;void)<sup>8+</sup> | 字母索引提示弹窗字符串列表选中回调。                            |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct AlphabetIndexerSample {
  private arrayA: string[] = ['安']
  private arrayB: string[] = ['卜', '白', '包', '毕', '丙']
  private arrayC: string[] = ['曹', '成', '陈', '催']
  private arrayL: string[] = ['刘', '李', '楼', '梁', '雷', '吕', '柳', '卢']
  private value: string[] = ['#', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
  'H', 'I', 'J', 'K', 'L', 'M', 'N',
  'O', 'P', 'Q', 'R', 'S', 'T', 'U',
  'V', 'W', 'X', 'Y', 'Z']

  build() {
    Stack({ alignContent: Alignment.Start }) {
      Row() {
        List({ space: 20, initialIndex: 0 }) {
          ForEach(this.arrayA, (item) => {
            ListItem() {
              Text(item)
                .width('80%')
                .height('5%')
                .fontSize(30)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)

          ForEach(this.arrayB, (item) => {
            ListItem() {
              Text(item)
                .width('80%')
                .height('5%')
                .fontSize(30)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)

          ForEach(this.arrayC, (item) => {
            ListItem() {
              Text(item)
                .width('80%')
                .height('5%')
                .fontSize(30)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)

          ForEach(this.arrayL, (item) => {
            ListItem() {
              Text(item)
                .width('80%')
                .height('5%')
                .fontSize(30)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)
        }
        .width('50%')
        .height('100%')

        AlphabetIndexer({ arrayValue: this.value, selected: 0 })
          .selectedColor(0xFFFFFF) // 选中项文本颜色
          .popupColor(0xFFFAF0) // 弹出框文本颜色
          .selectedBackgroundColor(0xCCCCCC) // 选中项背景颜色
          .popupBackground(0xD2B48C) // 弹出框背景颜色
          .usingPopup(true) // 是否显示弹出框
          .selectedFont({ size: 16, weight: FontWeight.Bolder }) // 选中项字体样式
          .popupFont({ size: 30, weight: FontWeight.Bolder }) // 弹出框内容的字体样式
          .itemSize(28) // 每一项的尺寸大小
          .alignStyle(IndexerAlign.Left) // 弹出框在索引条右侧弹出
          .onSelect((index: number) => {
            console.info(this.value[index] + ' Selected!')
          })
          .onRequestPopupData((index: number) => {
            if (this.value[index] == 'A') {
              return this.arrayA // 当选中A时，弹出框里面的提示文本列表显示A对应的列表arrayA，选中B、C、L时也同样
            } else if (this.value[index] == 'B') {
              return this.arrayB
            } else if (this.value[index] == 'C') {
              return this.arrayC
            } else if (this.value[index] == 'L') {
              return this.arrayL
            } else {
              return [] // 选中其余子母项时，提示文本列表为空
            }
          })
          .onPopupSelect((index: number) => {
            console.info('onPopupSelected:' + index)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
}
```

![alphabet](figures/alphabet.gif)