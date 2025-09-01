# ArkUI子系统Changelog

## cl.arkui.1 Tabs组件底部页签默认高度由52vp变更为48vp

**访问级别**

公开接口

**变更原因**

Tabs组件底部页签默认高度由52vp调整到48vp，优化用户体验。

**变更影响**

该变更为不兼容性变更。

变更前：设置BottomTabBarStyle样式且vertical属性为false时，barHeight的默认值为52vp。

变更后：设置BottomTabBarStyle样式且vertical属性为false时，barHeight的默认值为48vp。

|               变更前                |              变更后               |
| :---------------------------------: | :-------------------------------: |
| ![](figures/before_tabs_barHeight.jpg) | ![](figures/after_tabs_barHeight.jpg) |

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.53开始

**变更的接口/组件**

barHeight

**适配指导**

若发现组件高度变化导致界面内容出现留白，可通过修改内容区高度或自适应内容区高度。

若组件高度发生变化，开发者期望保持原有高度样式。示例如下：

```ts
@Entry
@Component
struct barHeightTest {
  build() {
    Column() {
      Tabs({ barPosition: BarPosition.End }) {
        TabContent() {
          Column().width('100%').width('100%').height('100%').backgroundColor(Color.Pink)
        }
        .tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), "Pink"))

        TabContent() {
          Column().width('100%').width('100%').height('100%').backgroundColor(Color.Green)
        }
        .tabBar(new BottomTabBarStyle($r('sys.media.ohos_app_icon'), "Green"))
      }
      .barHeight(52)
    }
  }
}
```

## cl.arkui.2 轴事件分发机制变更

**访问级别**

其他

**变更原因**

轴事件分发错误，开发者如果改了组件z序，组件显示、隐藏后不能正确分发到挂载轴事件的XComponent组件上。

**变更影响**

该变更为不兼容变更。

变更前：在多层级组件堆叠场景下，zIndex属性会影响兄弟组件响应轴事件的顺序。堆叠场景下，先绑定挂载轴事件且zIndex大的组件，然后绑定挂载轴事件且zIndex小的组件，轴事件无法正常分发给挂载轴事件且zIndex较大的组件，而会分发给挂载轴事件但zIndex较小的组件。

变更后：在多层级组件堆叠场景下，zIndex属性会影响兄弟组件响应轴事件的顺序。堆叠场景下，先绑定挂载轴事件且zIndex大的组件，然后绑定挂载轴事件且zIndex小的组件，轴事件可以正常分发给挂载轴事件且zIndex较大的组件，挂载轴事件但zIndex较小的组件无法收到事件。

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.53开始

**变更的接口/组件**

不涉及

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.3 getSnapshot接口行为变更

**访问级别**

系统接口

**变更原因**

window.getSnapshot接口当前获取到的图片尺寸是windowRect*0.5，不是窗口实际尺寸。

**变更影响**

该变更为不兼容变更。

变更前：window.getSnapshot接口获取到的图片尺寸是windowRect*0.5。

变更后：window.getSnapshot接口获取到的图片尺寸是窗口实际尺寸。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.0.0.53版本开始。

**变更的接口/组件**

@ohos.window.d.ts

getSnapshot接口

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.4 setWindowBrightness在2in1设备的行为变更

**访问级别**

公开接口

**变更原因**

2in1设备下，在视频播放页面，通过快捷键调节屏幕亮度不生效，原因是快捷键调节系统亮度，而在视频播放页面屏幕亮度跟随窗口亮度值。

**变更影响**

该变更为不兼容变更。

变更前：2in1设备下，窗口设置屏幕亮度生效时，控制中心和快捷键不可以调整系统屏幕亮度，窗口恢复默认系统亮度之后，控制中心和快捷键可以调整屏幕亮度。

变更后：2in1设备下，窗口设置屏幕亮度生效时，控制中心和快捷键也可以调整系统屏幕亮度。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.0.0.53版本开始。

**变更的接口/组件**

@ohos.window.d.ts

setWindowBrightness接口

**适配指导**

默认行为变更，无需适配。