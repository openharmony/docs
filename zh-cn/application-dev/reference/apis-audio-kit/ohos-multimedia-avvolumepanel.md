# @ohos.multimedia.avVolumePanel (音量面板)

本模块提供创建音量面板AVVolumePanel的功能，提供展示和调节系统音量的统一面板。

应用无法直接调节系统音量，可以通过系统音量面板，让用户通过界面操作来调节音量。当用户通过应用内音量面板调节音量时，系统会展示音量提示界面，显性地提示用户系统音量发生改变。


> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 示例效果请以真机为准，当前DevEco Studio预览器无真实音量展示和调节功能。
> <!--RP1--><!--RP1End-->

## 导入模块

```js
import { AVVolumePanel } from '@kit.AudioKit';
```
## 属性

支持[通用属性](../apis-arkui/arkui-ts/ts-universal-attributes-size.md)。

## AVVolumePanel

AVVolumePanel({volumeLevel?: number, volumeParameter?: AVVolumePanelParameter})

音量面板，可用于在当前应用内展示音量调节面板。

**装饰器类型：** [@Component](../../quick-start/arkts-create-custom-components.md)

**系统能力：** SystemCapability.Multimedia.Audio.Volume

## 属性

除支持[通用属性](../apis-arkui/arkui-ts/ts-universal-attributes-size.md)外，还支持以下属性：

**参数：**

| 名称 | 类型 | 必填 | 装饰器类型 | 描述                                                                                                                                                                                                    |
| -------- | -------- | -------- | -------- |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|volumeLevel | number | 否 | @Prop | 通过音量面板设置设备音量。该值应介于当前设备音量的最小值和最大值之间。如果该值大于当前设备音量的最大值，则视为设置设备最大音量值；如果该值小于当前设备音量的最小值，则视为设置设备最小音量值。获取音量的最大值与最小值可参考[AudioVolumeGroupManager](../apis-audio-kit/js-apis-audio.md#audiovolumegroupmanager9)。 |
|volumeParameter | [AVVolumePanelParameter](#avvolumepanelparameter)  | 否 |  @Prop | 设置音量面板的自定义参数。 如果不传入该参数，则调用系统音量条。                                                                                                                                                                      |

## AVVolumePanelParameter

| 名称 | 类型 | 必填 | 说明
| -------- | -------- | -------- | -------- |
|position | [Position](../apis-arkui/arkui-ts/ts-types.md#position) | 否 | 设置音量面板的位置。 |

## 事件

支持[通用事件](../apis-arkui/arkui-ts/ts-universal-events-click.md)。

## 示例

音量面板功能的示例说明参考如下。

```ts
import { AVVolumePanel } from '@kit.AudioKit';

@Entry
@Component
struct Index {

  @State volume: number = 0;

  build() {
    Row() {
      Column() {
        AVVolumePanel({
          volumeLevel: this.volume,
          volumeParameter: {
            position: {
              x: 100,
              y: 200
            }
          }
        })
      }
    }.width('50%').height('50%')
  }
}
```
