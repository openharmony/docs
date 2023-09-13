# @ohos.multimedia.avCastPicker (投播组件)

本模块提供创建投播组件AVCastPicker的功能，提供设备发现连接的统一入口。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 示例效果请以真机为准，当前IDE预览器无实际投播功能。

## 导入模块

```js
import AVCastPicker from '@ohos.multimedia.avCastPicker';
```

## 接口

AVCastPicker()

投播组件，可用于将音视频资源投放到其它设备播放。

该组件为自定义组件，开发者在使用前需要先了解[@Component](../../quick-start/arkts-create-custom-components.md)。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

## 属性

支持[通用属性](ts-universal-attributes-size.md)。

## 事件

支持[通用事件](ts-universal-events-click.md)。

## 示例

投播功能的示例说明参考如下。

```ts
import AVCastPicker from '@ohos.multimedia.avCastPicker'

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        AVCastPicker()
          .width('40vp')
          .height('40vp')
          .border({ width: 1, color: Color.Red })
      }.height('50%')
    }.width('50%')
  }
}
```
