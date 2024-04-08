# @ohos.arkui.advanced.EmbeddedAtomicServiceComponent (嵌入式元服务组件)


嵌入式元服务组件，当使用方被拉起方授权时嵌入式运行元服务，未授权时跳出式拉起元服务。


> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { EmbeddedAtomicServiceComponent } from "@ohos.arkui.advanced.EmbeddedAtomicServiceComponent"
```


## 子组件

无

## 属性
不支持通用属性

## EmbeddedAtomicServiceComponent

EmbeddedAtomicServiceComponent({ content: Callback\<void>, appId: string, options?: AtomicServiceOptions })

**装饰器类型：**\@Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


**参数：**


| 名称 | 参数类型 | 必填 | 说明 | 
| -------- | -------- | -------- | -------- |
| content | Callback\<void> | 是 | 组件显示内容。 |
| appId | string | 是 | 元服务appId。 |
| options | AtomicServiceOptions | 是 | 拉起元服务参数。 |

## 事件
不支持通用事件

## 示例

```ts
import EmbeddedAtomicServiceComponent from '@ohos.arkui.advanced.EmbeddedAtomicServiceComponent';

@Entry
@Component
struct Index {
  @State appId: string = '6918661953712445909';

  build() {
    Row() {
      Column() {
        EmbeddedAtomicServiceComponent({
          builder: ColumChild,
          appId: this.appId,
          options: {}
        }).width("80vp").height("80vp")
      }
      .width('100%')
    }
    .height('100%')
  }
}

@Builder
function ColumChild() {
  Column() {
    Image($r('app.media.icon'))
    Text('test')
  }
}
```
