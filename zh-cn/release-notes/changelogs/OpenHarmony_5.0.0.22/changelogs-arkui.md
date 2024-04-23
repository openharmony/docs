# ArkUI子系统变更说明

## cl.arkui.1 TextInput组件默认样式变更

**访问级别**

公开接口

**变更原因**

默认样式变更。

**变更影响**

TextInput组件默认样式变更。

变更前：下划线模式输入框设置borderRadius未生效，还是默认样式radius为0。下划线模式输入框左右padding为12vp。非下划线模式输入框默认高度为48vp。

![默认样式变更前效果图](figures/underlineBeforeAPI12.png)

变更后：下划线模式输入框设置borderRadius正常生效，不设置则显示默认样式radius为0。下划线模式输入框左右padding为0vp。非下划线模式输入框默认高度为40vp。

![默认样式变更后效果图](figures/underlineAPI12.png)

示例：

```ts
@Entry
@Component
struct TextInputExample {
  @State Text: string = ''
  build() {
    Column({ space: 20 }) {
      Text(`下划线模式`)
        .width('95%')
      // 下划线模式
      TextInput({ placeholder: 'underline style' })
        .showUnderline(true)
        .backgroundColor(Color.Pink)
        .width(380)
        .borderRadius(10)
      Text(`非下划线模式`)
        .width('95%')
      TextInput({ placeholder: '请输入用户名', text: this.Text })
        .showUnderline(false)
        .width(380)
        .borderRadius(10)

    }.width('100%')
  }
}
```

**API Level**

起始支持版本为 API 10。

**变更发生版本**

从OpenHarmony SDK 5.0.0.22开始。

**适配指导**

组件默认样式变更调整，无需适配。

## cl.arkui.2 Text组件clip通用属性默认值变更

**访问级别**

公开接口

**变更原因**

默认值false符合更多应用场景。

**变更影响**

Text组件clip通用属性默认值变更。

变更前：Text组件clip通用属性默认值为true, 超出组件区域内容会被截断不显示。

![Text组件默认值变更前效果图](figures/textcliptrue.png)

变更后：Text组件clip通用属性默认值为false, 超出组件区域内容不会被截断全部显示。

![Text组件默认值变更后效果图](figures/textclipfalse.png)

示例：

```ts
@Entry
@Component
struct TextClipExample {
  build() {
    Column({ space: 20 }) {
      Text('This is set wordBreak to WordBreak text Taumatawhakatangihangakoauauotamateaturipukakapikimaungahoronukupokaiwhenuakitanatahu.')
        .fontSize(12)
        .border({ width: 1 })
        .wordBreak(WordBreak.NORMAL)
        .lineHeight(20)
        .maxLines(2)
    }.height(300).width(335).padding({ left: 35, right: 35, top: 35 })
  }
}
```

**API Level**

起始支持版本为 API 7。

**变更发生版本**

从OpenHarmony SDK 5.0.0.22开始。

**适配指导**

组件clip通用属性默认值变更调整，无需适配。