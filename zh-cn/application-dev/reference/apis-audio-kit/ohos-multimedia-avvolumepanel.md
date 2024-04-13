# @ohos.multimedia.avVolumePanel (音量面板)

本模块提供创建音量面板AVVolumePanel的功能，提供展示和调节系统的统一面板。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 示例效果请以真机为准，当前IDE预览器无真实音量展示和调节功能。

## 导入模块

```js
import AVVolume from '@ohos.multimedia.avVolumePanel';
```

## 接口

AVVolumePanel()

音量面板，可用于在当前应用内展示音量调节面板。

该组件为自定义组件，开发者在使用前需要先了解[@Component](../../quick-start/arkts-create-custom-components.md)。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

## 属性

除支持[通用属性](../apis-arkui/arkui-ts/ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
|volumeLevel | number | 通过音量面板设置设备音量。该值应介于当前设备音量的最小值和最大值之间，否则将被丢弃。 |
|volumeParameter | AVVolumePanelParameter(https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.multimedia.avVolumePanel.d.ets) | 设置音量面板的自定义参数 |

其中AVVolumePanelParameter自定义参数支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
|position | Position | 设置音量面板的位置 |

## 事件

支持[通用事件](../apis-arkui/arkui-ts/ts-universal-events-click.md)。

## 示例

音量面板功能的示例说明参考如下。

```ts
import AVVolume from '@ohos.multimedia.avVolumePanel'

@Entry
@Component
struct Index {

  @Prop volume: number = 0;

  build() {
    Row() {
      Column() {
        AVVolume({
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
