# @ohos.avcastpicker (AVCastPicker)

本模块提供创建投播组件的功能，提供了设备发现连接的统一入口。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 示例效果请以真机运行为准，当前IDE预览器不支持。

## 导入模块

```js
import { AVCastPicker} from '@ohos.avcastpicker';
```

**系统能力：** SystemCapability.Multimedia.AVSession

**示例：**
```ts
import { AVCastPicker } from '@ohos.avcastpicker'

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
