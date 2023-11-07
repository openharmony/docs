# @ohos.arkui.advanced.TabTitleBar（页签型标题栏）


页签型标题栏，用于页面之间的切换。仅一级页面适用。


> **说明：**
>
> 该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { TabTitleBar } from "@ohos.arkui.advanced.TabTitleBar"
```


## 子组件

无

## 属性
不支持[通用属性](ts-universal-attributes-size.md)


## TabTitleBar

TabTitleBar({tabItems: Array&lt;TabTitleBarTabItem&gt;, menuItems?: Array&lt;TabTitleBarMenuItem&gt;, swiperContent: () =&gt; void})

**装饰器类型：**\@Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 名称 | 参数类型 | 必填 | 装饰器类型 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| tabItems | Array&lt;[TabTitleBarTabItem](#tabtitlebartabitem)&gt; | 是 | - | 左侧页签项目列表，定义标题栏左侧的页签项目。 | 
| menuItems | Array&lt;[TabTitleBarMenuItem](#tabtitlebarmenuitem)&gt; | 否 | - | 右侧菜单项目列表，定义标题栏右侧的菜单项目。 | 
| swiperContent | ()&nbsp;=&gt;&nbsp;void | 否 | \@BuilderParam | 页签列表关联的页面内容构造器。 | 


## TabTitleBarMenuItem

| 名称 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| value | [ResourceStr](ts-types.md#resourcestr) | 是 | 图标资源。 | 
| isEnabled | boolean | 是 | 是否启用。 | 
| action | ()&nbsp;=&gt;&nbsp;void | 否 | 触发时的动作闭包。 | 


## TabTitleBarTabItem

| 名称 | 类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| title | [ResourceStr](ts-types.md#resourcestr) | 是 | 文字页签。 | 
| icon | [ResourceStr](ts-types.md#resourcestr) | 否 | 图片页签资源。 | 


## 事件
不支持[通用事件](ts-universal-events-click.md)

## 示例

```ts
import { TabTitleBar } from "@ohos.arkui.advanced.TabTitleBar"
import promptAction from '@ohos.promptAction'

@Entry
@Component
struct Index {
  @Builder
  componentBuilder() {
    Text("#1ABC9C\nTURQUOISE")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#1ABC9C")
    Text("#16A085\nGREEN SEA")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#16A085")
    Text("#2ECC71\nEMERALD")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#2ECC71")
    Text("#27AE60\nNEPHRITIS")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#27AE60")
    Text("#3498DB\nPETER RIVER")
      .fontWeight(FontWeight.Bold)
      .fontSize(14)
      .width("100%")
      .textAlign(TextAlign.Center)
      .fontColor("#CCFFFFFF")
      .backgroundColor("#3498DB")
  }

  private readonly tabItems: {
    title: ResourceStr,
    icon?: ResourceStr
  }[] =
    [
      { title: "页签1" },
      { title: "页签2" },
      { title: "页签3" },
      { title: "Happy",
        icon: $r('app.media.emoji_happy') },
      { title: "页签4" },
    ]
  private readonly menuItems: {
    value: Resource,
    isEnabled: boolean,
    action: () => void
  }[] =
    [
      { isEnabled: true, value: $r('app.media.ic_public_reduce'),
        action: () => promptAction.showToast({ message: "on item click! index 0" })
      },
      { isEnabled: true, value: $r('app.media.ic_public_edit'),
        action: () => promptAction.showToast({ message: "on item click! index 1" })
      },
      { isEnabled: true, value: $r('app.media.ic_public_save'),
        action: () => promptAction.showToast({ message: "on item click! index 2" })
      }
    ]

  build() {
    Row() {
      Column() {
        TabTitleBar({
          swiperContent: this.componentBuilder,
          tabItems: this.tabItems,
          menuItems: this.menuItems,
        })
      }.width('100%')
    }.height('100%')
  }
}
```

![zh-cn_image_0000001616916278](figures/zh-cn_image_0000001616916278.png)
