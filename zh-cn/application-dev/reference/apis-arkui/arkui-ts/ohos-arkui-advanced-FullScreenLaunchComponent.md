# @ohos.arkui.advanced.FullScreenLaunchComponent (全屏启动元服务组件)


全屏启动元服务组件，当被拉起方授权使用方可以嵌入式运行元服务时，使用方全屏嵌入式运行元服务；未授权时，使用方跳出式拉起元服务。


> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 导入模块

```
import { FullScreenLaunchComponent } from "@ohos.arkui.advanced.FullScreenLaunchComponent"
```


## 子组件

无

## 属性
不支持[通用属性](ts-universal-attributes-size.md)

## FullScreenLaunchComponent

FullScreenLaunchComponent({ content: Callback\<void>, appId: string, options?: AtomicServiceOptions })

**装饰器类型：**\@Component

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


**参数：**


| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | 是 | \@BuilderParam | 组件显示内容。 |
| appId | string | 是 | - | 元服务appId。 |
| options | AtomicServiceOptions | 是 | - | 拉起元服务参数。 |

## 事件
不支持[通用事件](ts-universal-events-click.md)

## 示例

```ts
import { FullScreenLaunchComponent } from '@ohos.arkui.advanced.FullScreenLaunchComponent';

@Entry
@Component
struct Index {
  @State appId: string = '6918661953712445909';

  build() {
    Row() {
      Column() {
        FullScreenLaunchComponent({
          content: ColumChild,
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
