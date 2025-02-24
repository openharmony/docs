# @ohos.multimedia.avCastPicker (投播组件)

本模块提供创建投播组件AVCastPicker的功能，提供设备发现连接的统一入口。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 示例效果请以真机为准，当前DevEco Studio预览器无实际投播功能。<!--Del-->
> - 当前组件的使用，依赖于设备支持“设备选择界面”。当前暂无OpenHarmony设备支持，需要OEM厂商实现具体的“设备选择界面”。<!--DelEnd-->
> <!--RP2--><!--RP2End-->

## 导入模块

```js
import { AVCastPicker } from '@kit.AVSessionKit';
```

## AVCastPicker

AVCastPicker()

投播组件，可用于将音视频资源投放到其它设备播放。

该组件为自定义组件，开发者在使用前需要先了解[@Component](../../quick-start/arkts-create-custom-components.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

## 属性

除支持[通用属性](../apis-arkui/arkui-ts/ts-component-general-attributes.md)外，还支持以下属性：

| 名称 | 参数类型 | 必填 | 装饰器修饰类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| normalColor<sup>11+</sup> | Color &#124; number &#124; string | 否 | @Prop | 指正常状态下投播组件的颜色。<br>未设置将采用colorMode下的颜色设置。 |
| activeColor<sup>11+</sup> | Color &#124; number &#124; string | 否 | @Prop | 指设备切换成功状态下投播组件的颜色。未设置系统将优先根据normalColor的颜色匹配；如果normalColor也未设置，将采用colorMode下的颜色设置。 |
| pickerStyle<sup>12+</sup> | [AVCastPickerStyle](js-apis-avCastPickerParam.md#avcastpickerstyle12) | 否 | @Prop | 投播样式。<br>- 当时sessionType是audio或者video时，默认值为STYLE_PANEL；<br>- 当sessionType是voice_call或者video_call时，默认值为STYLE_MENU，且不可修改为STYLE_PANEL。|
| colorMode<sup>12+</sup> | [AVCastPickerColorMode](js-apis-avCastPickerParam.md#avcastpickercolormode12) | 否 |  @Prop | 显示模式。默认值为AUTO。<br>- 当colorMode设置为AUTO时，跟随系统的深浅色模式的默认色值；<br>- 当colorMode设置为DARK、LIGHT时，使用对应模式的系统预定色值。 |
| sessionType<sup>12+</sup> | string | 否| @Prop | 会话类型，可参考[AVSessionType](js-apis-avsession.md#avsessiontype10)。默认值为当前应用创建的AVSessionType。 |
| customPicker<sup>12+</sup> | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8) | 否 | @Prop | 自定义样式。建议应用自定义组件样式，可有效提升组件显示速度。 |
| onStateChange<sup>11+</sup> | (state: [AVCastPickerState](js-apis-avCastPickerParam.md)) => void | 否 | @Prop | 投播状态更改回调。 |

## 事件

支持[通用事件](../apis-arkui/arkui-ts/ts-component-general-events.md)。

## 示例

投播功能的示例说明参考如下。
<!--RP1--><!--RP1End-->

```ts
import { AVCastPickerState, AVCastPicker } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {

  @State pickerImage: ResourceStr = $r('app.media.castPicker'); // 自定义资源

  private onStateChange(state: AVCastPickerState) {
    if (state == AVCastPickerState.STATE_APPEARING) {
      console.log('The picker starts showing.');
    } else if (state == AVCastPickerState.STATE_DISAPPEARING) {
      console.log('The picker finishes presenting.');
    }
  }

  @Builder
  customPickerBuilder(): void {
    Image(this.pickerImage)
      .width('100%')
      .height('100%')
      .fillColor(Color.Black)
  }

  build() {
    Row() {
      Column() {
        AVCastPicker({
          normalColor: Color.Red,
          customPicker: () => this.customPickerBuilder(),
          onStateChange: this.onStateChange
        })
          .width('40vp')
          .height('40vp')
          .border({ width: 1, color: Color.Red })
      }.height('50%')
    }.width('50%')
  }
}
```
