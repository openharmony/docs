# 焦点控制

自定义组件的走焦效果，可设置组件是否走焦和具体的走焦顺序，tab键或者方向键切换焦点。

>  **说明：**
> 从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 属性

| **名称** | **参数类型** | **默认值** | **描述** |
| -------- | -------- | -------- | -------- |
| focusable | boolean | false | 设置当前组件是否可以获焦。 |
| tabIndex<sup>9+<sup> | number | 0 | 自定义组件tab键走焦能力，走焦顺序为：tabIndex大于0的组件依次递增走焦, tabIndex等于0的组件按组件树先后顺序走焦。<br />- tabIndex >= 0：表示元素是可聚焦的，并且可以通过tab键走焦来访问到该元素，按照tabIndex的数值递增而先后获焦。如果多个元素拥有相同的tabIndex，按照元素在当前组件树中的先后顺序获焦<br />- tabIndex < 0（通常是tabIndex = -1）：表示元素是可聚焦的，但是不能通过tab键走焦来访问到该元素 |

>  **说明：**
> 支持焦点控制的组件：Button、Text、Image、List、Grid。

## 示例

焦点事件当前仅支持在真机上显示运行效果。

```ts
// xxx.ets
@Entry
@Component
struct FocusableExample {
  @State text1: string = 'TabIndex=3'
  @State text2: string = 'TabIndex=2'
  @State text3: string = 'focusable=false'
  @State text4: string = 'TabIndex=-1'
  @State text5: string = 'TabIndex=1'
  @State text6: string = 'TabIndex=1'
  @State text7: string = 'focusable=true'
  @State text8: string = 'focusable=true'

  build() {
    Column({ space:20 }){
      Button(this.text1)  // 按下TAB键第四个获焦的组件
        .width(300).height(70).fontColor(Color.Black)
        .tabIndex(3)
      Button(this.text2)  // 按下TAB键第三个获焦的组件
        .width(300).height(70).fontColor(Color.Black)
        .tabIndex(2)
      Button(this.text3)  // 无法获焦的组件
        .width(300).height(70).fontColor(Color.Black)
        .focusable(false)
      Button(this.text4)  // 无法使用TAB键，但可以使用方向键走焦的组件
        .width(300).height(70).fontColor(Color.Black)
        .tabIndex(-1)
      Button(this.text5)  // 按下TAB键第一个获焦的组件
        .width(300).height(70).fontColor(Color.Black)
        .tabIndex(1)
      Button(this.text6)  // 按下TAB键第二个获焦的组件
        .width(300).height(70).fontColor(Color.Black)
        .tabIndex(1)
      Button(this.text7)  // 按下TAB键第五个获焦的组件
        .width(300).height(70).fontColor(Color.Black)
        .focusable(true)
      Button(this.text8)  // 按下TAB键第六个获焦的组件
        .width(300).height(70).fontColor(Color.Black)
        .focusable(true)
    }.width('100%').margin({ top:20 })
  }
}
```

![focus](figures/focus.png)