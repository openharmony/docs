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
