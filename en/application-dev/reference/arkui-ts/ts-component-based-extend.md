# @Extend<a name="EN-US_TOPIC_0000001134698822"></a>

The  **@Extend**  decorator adds new attribute functions to preset components, such as  **<Text\>**,  **<Column\>**, and  **<Button\>**. You can use the  **@Extend**  decorator to quickly define and reuse the custom style of a component.

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

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The  **@Extend**  decorator cannot be used in the struct definition box of a custom component.

