# HalfScreenLaunchComponent

半屏嵌入式启动原子化服务组件，当被拉起方未授权嵌入式运行原子化服务时，宿主将使用跳出式拉起原子化服务。

> **说明：**
>
> 该组件从API Version 16开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 如果需要在该组件中实现一个可嵌入式运行的原子化服务时，原子化服务必须继承自[EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md)。若不继承自EmbeddableUIAbility，系统无法保证原子化服务功能正常。

## 导入模块

```
import { HalfScreenLaunchComponent } from '@kit.ArkUI';
```

## 子组件

无

## 属性
不支持[通用属性](ts-component-general-attributes.md)

## HalfScreenLaunchComponent

HalfScreenLaunchComponent({  
&emsp;content: Callback\<void>,  
&emsp;appId: string,  
&emsp;options?: AtomicServiceOptions,  
&emsp;onError?: ErrorCallback,  
&emsp;onTerminated?: Callback&lt;TerminationInfo&gt;   
  })

**装饰器类型：**\@Component

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | 是 | \@BuilderParam | 组件显示内容。 |
| appId | string | 是 | - | 原子化服务appId。 |
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | 否 | - | 拉起原子化服务参数，默认为空。 |
| onError |[ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否 | - | 被拉起的原子化服务扩展在运行过程中发生异常时触发本回调。 |
| onTerminated | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<TerminationInfo> | 否 | - |  回调函数，入参用于接收原子化服务的返回结果，类型为TerminationInfo。 |

## 示例

该示例展示如何嵌入式拉起手机充值服务。

```ts
import { HalfScreenLaunchComponent } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  appId: string = "5765880207853275489"; //手机充值

  build() {
    Column() {
      HalfScreenLaunchComponent({
        appId: this.appId,
        options: {},
        onTerminated:  (info:TerminationInfo)=> {
          console.log('onTerminated info = '+ info.want);
        },
        onError: (err) => {
          console.error(" onError code: " + err.code + ", message: ", err.message);
        }
      }) {
        Column() {
          Image($r('app.media.app_icon'))
          Text('拉起手机充值')
        }.width("80vp").height("80vp").margin({bottom:30})
      } // 通过尾随必包形式传入content
    }
  }

}
```
