# @ohos.multimedia.avInputCastPicker (录音设备选择组件)

本模块提供创建录音设备选择组件AVInputCastPicker的功能，提供录音设备发现连接的统一入口。

> **说明：**
>
> - 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 示例效果请以真机为准，当前DevEco Studio预览器无实际录音设备选择功能。<!--Del-->
> - 当前组件的使用，依赖于设备支持“录音设备选择界面”。当前暂无OpenHarmony设备支持，需要OEM厂商实现具体的“录音设备选择界面”。
> - 此组件仅支持在PC上使用。<!--DelEnd-->

## 导入模块

```js
import { AVInputCastPicker } from '@kit.AVSessionKit';
```

## 属性

支持[通用属性](../apis-arkui/arkui-ts/ts-component-general-attributes.md)。

## AVInputCastPicker

```
AVInputCastPicker({
  customPicker?: CustomBuilder;
  onStateChange?: (state: AVCastPickerState) => void;
})
```

录音设备选择组件，可用于切换音频输入设备。

该组件为自定义组件，开发者在使用前需要先了解[@Component](../../ui/state-management/arkts-create-custom-components.md#component)。

**装饰器类型：** [@Component](../../ui/state-management/arkts-create-custom-components.md#component)

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVInputCast

**参数：**

| 参数名 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| customPicker | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8) | 否 | @Prop | 自定义样式。建议应用自定义组件样式，可有效提升组件显示速度。 |
| onStateChange | (state: [AVCastPickerState](js-apis-avCastPickerParam.md#avcastpickerstate11)) => void | 否 | - | 设备列表状态变更回调。<br>state：设备列表状态变更回调函数参数。 |

## 事件

支持[通用事件](../apis-arkui/arkui-ts/ts-component-general-events.md)。

## 示例

录音设备选择组件功能的示例说明参考如下。

```ts
import { AVCastPickerState, AVInputCastPicker } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {

  @State pickerImage: ResourceStr = $r('app.media.castPicker'); // 自定义资源。

  private onStateChange(state: AVCastPickerState) {
    if (state == AVCastPickerState.STATE_APPEARING) {
      console.info('The picker starts showing.');
    } else if (state == AVCastPickerState.STATE_DISAPPEARING) {
      console.info('The picker finishes presenting.');
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
        AVInputCastPicker({
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