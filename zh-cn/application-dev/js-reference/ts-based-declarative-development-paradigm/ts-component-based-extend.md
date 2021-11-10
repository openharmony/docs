# @Extend<a name="ZH-CN_TOPIC_0000001134698822"></a>

**@Extend**装饰器将新的属性函数添加到内置组件上，如**Text**、**Column**、**Button**等。通过**@Extend**装饰器可以快速定义并复用组件的自定义样式。

```
@Extend(Text) function fancy(color: number) {
  .fontColor(color)
  .fontSize(24)
  .fontStyle(FontStyle.Italic)
}

@Entry
@Component
struct FancyUse {
  build() {
    Row({ space: 10 }) {
      Text("Fancy")
        .fancy(Color.Blue)
      Text("Fancy")
        .fancy(Color.Red)
    }
  }
}
```

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>@Extend装饰器不能用在自定义组件struct定义框内。

