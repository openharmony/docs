# @Extend<a name="EN-US_TOPIC_0000001134698822"></a>

The  **@Extend**  decorator adds new attribute functions to preset components, such as  **<Text\>**,  **<Column\>**, and  **<Button\>**. You can use the  **@Extend**  decorator to quickly define and reuse the custom styles of a component.

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

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The  **@Extend**  decorator cannot be used in the struct definition of a custom component.

