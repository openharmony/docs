# 文本样式设置

针对包含文本元素的组件，设置文本样式。

>  **说明：**
>
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。



## 属性


| 名称         | 参数类型                                      | 描述                                    |
| -----------| ---------------------------------------- | ------------------------------------ |
| fontColor  | [ResourceColor](ts-types.md#resourcecolor)  | 设置字体颜色。                                 |
| fontSize   | [Length](ts-types.md#length)  | 设置字体大小，Length为number类型时，使用fp单位。字体默认大小10。不支持设置百分比字符串。    |
| fontStyle  | [FontStyle](ts-appendix-enums.md#fontstyle)  | 设置字体样式。<br>默认值：FontStyle.Normal         |
| fontWeight | number&nbsp;\|&nbsp;[FontWeight](ts-appendix-enums.md#fontweight)&nbsp;\|&nbsp;string  | 设置文本的字体粗细，number类型取值[100,&nbsp;900]，取值间隔为100，默认为400，取值越大，字体越粗。string类型仅支持number类型取值的字符串形式，例如"400"，以及"bold"、"bolder"、"lighter"、"regular"、"medium"，分别对应FontWeight中相应的枚举值。<br/>默认值：FontWeight.Normal  |
| fontFamily | string&nbsp;\|&nbsp;[Resource](ts-types.md#resource)  | 设置字体列表。默认字体'HarmonyOS Sans'，且当前只支持这种字体。|


## 示例

```ts
// xxx.ets
@Entry
@Component
struct TextStyleExample {
  build() {
    Column({ space: 5 }) {
      Text('default text')
      Divider()
      
      Text('text font color red').fontColor(Color.Red)
      Divider()
      
      Text('text font default')
      Text('text font size 10').fontSize(10)
      Text('text font size 10fp').fontSize('10fp')
      Text('text font size 20').fontSize(20)
      Divider()
      
      Text('text font style Italic').fontStyle(FontStyle.Italic)
      Divider()
      
      Text('text fontWeight bold').fontWeight(700)
      Text('text fontWeight lighter').fontWeight(FontWeight.Lighter)
      Divider()
      
      Text('red 20 Italic bold text')
        .fontColor(Color.Red)
        .fontSize(20)
        .fontStyle(FontStyle.Italic)
        .fontWeight(FontWeight.Bold)
      Divider()
      
      Text('Orange 18 Normal text')
        .fontColor(Color.Orange)
        .fontSize(18)
        .fontStyle(FontStyle.Normal)
    }.width('100%')
  }
}
```

![textstyle](figures/textstyle.png)
