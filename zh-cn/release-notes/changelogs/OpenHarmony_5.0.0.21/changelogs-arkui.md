# ArkUI子系统Changelog

## cl.arkui.1 Toggle组件Switch样式移除宽高比1.8倍限制

**访问级别**

公开接口

**变更原因**

a)当前Toggle组件Switch样式宽高比固定1.8倍，依照UX规范移除1.8倍限制。

**变更影响**

该变更为非兼容性变更。API version 11及以前，Toggle组件Switch样式宽高比固定1.8倍。API version 12及以后，Toggle组件Switch样式宽高比没有限制。

**API Level**

12 

**变更发生版本**

从OpenHarmony SDK 5.0.0.21 版本开始。

**变更的接口/组件**

Toggle组件

**适配指导**

请查阅[Toggle组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-toggle.md)文档进行适配。

## cl.arkui.2  Radio组件单选项样式风格增强、支持显示自定义图标 

**访问级别**

公开接口

**变更原因**

允许用户自定义单选项的选中状态：

1.可以选择不同的样式，如圆饼样式，对勾样式，自定义图标样式。

2.用户自定义图标时，设置选中状态时图标显示，非选中状态时图标不显示。

**变更影响**

该变更为非兼容性变更。

- 变更前：默认选中状态DOT（圆圈样式）。
- 变更后：默认选中状态TICK（对勾样式）。

| DOT | TICK |
|---------|---------|
| ![](figures/radio_changelog_DOT.jpg) | ![](figures/radio_changelog_TICK.jpg) |

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.21版本开始。

**示例：**
该示例实现了自定义选中状态
```
@Entry
@Component
struct RadioExample {
  @Builder 
  indicatorBuilder() {
    Image($r("app.media.star"))
  }
  build() {
    Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Column() {
        Text('Radio1')
        Radio({ value: 'Radio1', group: 'radioGroup',
          indicatorType:RadioIndicatorType.TICK
        }).checked(true)
          .height(50)
          .width(80)
          .onChange((isChecked: boolean) => {
            console.log('Radio1 status is ' + isChecked)
          })
      }
      Column() {
        Text('Radio2')
        Radio({ value: 'Radio2', group: 'radioGroup',
          indicatorType:RadioIndicatorType.DOT
        }).checked(false)
          .height(50)
          .width(80)
          .onChange((isChecked: boolean) => {
            console.log('Radio2 status is ' + isChecked)
          })
      }
      Column() {
        Text('Radio3')
        Radio({ value: 'Radio3', group: 'radioGroup',
          indicatorType:RadioIndicatorType.CUSTOM,
          indicatorBuilder:()=>{this.indicatorBuilder()}
        }).checked(false)
          .height(50)
          .width(80)
          .onChange((isChecked: boolean) => {
            console.log('Radio3 status is ' + isChecked)
          })
      }
    }.padding({ top: 30 })
  }
}
```

**变更的接口/组件**

Radio组件

**适配指导**

请查阅[Radio组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-radio.md)文档进行适配。

## cl.arkui.3 文本组件的文本选择行为变更

**访问级别**

公开接口

**变更原因**

依照UX规范

**变更影响**

该变更为非兼容性变更。API version 11及以前：

a)当前Text组件长按出现菜单时，旋转屏幕，此时依旧出现菜单。

b)当前Text/TextInput/TextArea/Search/RichEditor组件长按出现菜单，进行复制行为，文本退出选中态。

c)当前TextInput/TextArea/Search/RichEditor组件在手机和平板设备上通过代码选区，只出现选中态，无手柄。

API version 12及以后：

a)当前Text组件长按出现菜单时，旋转屏幕，隐藏菜单，保持选中态。

b)当前TextInput/TextArea/Search/RichEditor组件长按出现菜单时，隐藏菜单，保持选中态。

c)当前TextInput/TextArea/Search/RichEditor组件在手机和平板设备上通过代码选区，出现选中态和手柄，用户可自定义出现菜单。

**API Level**

12 

**变更发生版本**

从OpenHarmony SDK 5.0.0.21 版本开始。

**变更的接口/组件**

Text/TextInput/TextArea/Search/RichEditor组件。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响

## c1.arkui.4 TextInput组件underline默认样式变更

**访问级别**

公开接口

**变更原因**

依照UX规范

**变更影响**

该变更为非兼容性变更。API version 11及以前，TextInput组件设置underline时，组件出现的时候无圆角，组件获焦失焦后有圆角，且圆角值不同。API version 12及以后，依照UX规范统一默认都设置无圆角。

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/init.png) | ![](figures/init.png) |
| ![](figures/focus.png) | ![](figures/init.png) |
| ![](figures/blur.png) | ![](figures/init.png) |

**API Level**

12 

**变更发生版本**

从OpenHarmony SDK 5.0.0.21 版本开始。

**变更的接口/组件**

TextInput组件。

**适配指导**

默认效果变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则应自定义修改效果控制变量以达到预期
