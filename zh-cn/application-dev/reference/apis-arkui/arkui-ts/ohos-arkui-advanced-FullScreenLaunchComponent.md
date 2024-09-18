# FullScreenLaunchComponent


全屏启动原子化服务组件，当被拉起方授权使用方可以嵌入式运行原子化服务时，使用方全屏嵌入式运行原子化服务；未授权时，使用方跳出式拉起原子化服务。


> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 如果需要在该组件中实现一个可嵌入式运行的原子化服务时，必须继承自[EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md)。若不继承自EmbeddableUIAbility，系统无法保证原子化服务功能正常。


## 导入模块

```
import { FullScreenLaunchComponent } from '@kit.ArkUI'
```


## 子组件

无

## 属性
不支持[通用属性](ts-universal-attributes-size.md)

## FullScreenLaunchComponent

FullScreenLaunchComponent({ content: Callback\<void>, appId: string, options?: AtomicServiceOptions })

**装饰器类型：**\@Component

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full


**参数：**


| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | 是 | \@BuilderParam | 组件显示内容。 |
| appId | string | 是 | - | 原子化服务appId。 |
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | 否 | - | 拉起原子化服务参数。 |

## 事件
不支持[通用事件](ts-universal-events-click.md)

## 示例

```ts
import { FullScreenLaunchComponent } from '@kit.ArkUI';

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
