# @Extend

**@Extend**装饰器将新的属性函数添加到内置组件上，如**Text**、**Column**、**Button**等。通过**\@Extend**装饰器可以快速定义并复用组件的自定义样式。


```
@Extend(Text) function fancy(fontSize: number) {
  .fontColor(Color.Red)
  .fontSize(fontSize)
  .fontStyle(FontStyle.Italic)
}

@Entry
@Component
struct FancyUse {
  build() {
    Row({ space: 10 }) {
      Text("Fancy")
        .fancy(16)
      Text("Fancy")
        .fancy(24)
    }
  }
}
```


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> @Extend装饰器不能用在自定义组件struct定义框内。
