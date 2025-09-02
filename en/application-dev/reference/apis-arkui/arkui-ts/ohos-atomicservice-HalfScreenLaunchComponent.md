# HalfScreenLaunchComponent

**HalfScreenLaunchComponent** is a component designed for launching atomic services in half screen. If the invoked application (the one being launched) grants the invoker the authorization to run the atomic service in an embedded manner, the invoker can operate the atomic service in half-screen embedded mode. If authorization is not provided, the invoker will launch the atomic service in a pop-up manner.

> **NOTE**
>
> This component is supported since API version 18. Updates will be marked with a superscript to indicate their earliest API version.
>
> To implement an embeddable atomic service, make sure it inherits from [EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md). This ensures that it functions properly.

## Modules to Import

```
import { HalfScreenLaunchComponent } from '@kit.ArkUI';
```

## Child Components

Not supported

## Attributes
The [universal attributes](ts-component-general-attributes.md) are not supported.

## HalfScreenLaunchComponent

HalfScreenLaunchComponent({  
&emsp;content: Callback\<void>,  
&emsp;appId: string,  
&emsp;options?: AtomicServiceOptions,  
&emsp;onError?: ErrorCallback,  
&emsp;onTerminated?: Callback&lt;TerminationInfo&gt;   
  })

**Decorator**: \@Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | Yes| \@BuilderParam | Content displayed in the component.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| appId | string | Yes| - | Application ID for the atomic service.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | No| - | Parameters for starting the atomic service. The default value is empty.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| onError |[ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | No| - | Invoked when an error occurs during the running of the atomic service.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| onTerminated | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<TerminationInfo> | No| - |  Callback used to return the result of the atomic service. The input parameter is of type **TerminationInfo**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| onReceive<sup>20+<sup> | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<Record<string, Object>> | No| - | Callback triggered when the embedded atomic service is launched through [Window](../../../windowmanager/application-window-stage.md) API calls.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## Example

This example demonstrates how to start a top-up service in embedded mode.

```ts
import { HalfScreenLaunchComponent } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  appId: string = "5765880207853275489"; // Application ID of the atomic service.

  build() {
    Column() {
      HalfScreenLaunchComponent({
        appId: this.appId,
        options: {},
        onTerminated:  (info:TerminationInfo)=> {
          console.info('onTerminated info = '+ info.want);
        },
        onError: (err) => {
          console.error(" onError code: " + err.code + ", message: ", err.message);
        },
        onReceive: (data) => {
          console.info("onReceive, data: " + data['ohos.atomicService.window']);
        }
      }) {
        Column() {
          Image($r('app.media.app_icon'))
          Text('Start top-up')
        }.width("80vp").height("80vp").margin({bottom:30})
      } // Content is passed as a trailing closure.
    }
  }

}
```
