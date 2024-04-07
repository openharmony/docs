# @ohos.multimedia.avVolumeComponent (音量组件)

本模块提供创建音量组件AVVolumeComponent的功能，提供展示和调节系统的统一组件。

> **说明：**
>
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 示例效果请以真机为准，当前IDE预览器无真实音量展示和调节功能。

## 导入模块

```js
import {AVVolume} from '@ohos.multimedia.avVolumeComponent';
```

## 接口

AVVolumeComponent()

音量组件，可用于在当前应用内展示音量调节组件。

该组件为自定义组件，开发者在使用前需要先了解[@Component](../../quick-start/arkts-create-custom-components.md)。

**系统能力：** SystemCapability.Multimedia.Audio.AudioVolume

## 属性

除支持[通用属性](../apis-arkui/arkui-ts/ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
|volumeLevel | number | 应用传入的音量值，应当在最大最小值范围内 |
|sliderParameter | AVVolumeSliderParameter | 设置Slider样式的自定义参数 |

其中AVVolumeSliderParameter自定义样式支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
|sliderPosition | Position | 组件的位置 |

## 事件

支持[通用事件](../apis-arkui/arkui-ts/ts-universal-events-click.md)。

## 示例

音量组件功能的示例说明参考如下。

```ts
import AVVolume from '@ohos.multimedia.avVolumeComponent'

@Entry
@Component
struct Index {

  @Prop volume: number = 0;

  build() {
    Row() {
      Column() {
        AVVolume({
          volumeLevel: this.volume,
          sliderParameter: {
            sliderPosition: {
              x: 100,
              y: 200
            }
          }
        })
        .width('40vp').height('40vp')
        .border({ width: 1, color: Color.Red })
      }
    }.width('50%').height('50%')
  }
}
```
