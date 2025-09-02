# InnerFullScreenLaunchComponent (System API)


**InnerFullScreenLaunchComponent** is a component that allows the invoker to choose the timing for launching an atomic service. If the invoked application (the one being launched) grants the invoker the authorization to run the atomic service in an embedded manner, the invoker can operate the atomic service in full-screen embedded mode. If authorization is not provided, the invoker will launch the atomic service in a pop-up manner.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>
> To implement an embeddable atomic service within this component, it must inherit from [EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md). If it does not inherit from **EmbeddableUIAbility**, the system cannot guarantee that the atomic service will function properly.


## Modules to Import

```ts
import { InnerFullScreenLaunchComponent, LauncherController } from '@kit.ArkUI';
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-component-general-attributes.md) are not supported.

## InnerFullScreenLaunchComponent

InnerFullScreenLaunchComponent({ content: Callback\<void>, controller: LaunchController })

**Decorator**: \@Component

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full


**Parameters**


| Name| Type| Mandatory| Decorator Type| Description|
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | Yes| \@BuilderParam | Content displayed in the component.|
| controller | [LaunchController](#launchcontroller) | Yes| - | Controller for launching the atomic service.|
| onReceive<sup>20+<sup> | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<Record<string, Object>> | No| - | Callback triggered when the embedded atomic service is launched through [Window](../../../windowmanager/application-window-stage.md) API calls.|

## LaunchController

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| ---- | ---------- | ------ |------ |
|launchAtomicService | [LaunchAtomicServiceCallback](#launchatomicservicecallback) | Yes| Launches an atomic service.|

## LaunchAtomicServiceCallback

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| --------------- | ------ |------ |------ |
|appId | string |Yes| Application ID for the atomic service.|
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | No| Parameters for launching the atomic service.|

## Events
The [universal events](ts-component-general-events.md) are not supported.

## Example

```ts
import { InnerFullScreenLaunchComponent, LaunchController } from '@kit.ArkUI';

@Entry
@Component
struct Index {

  @Builder
  ColumChild() {
    Column() {
      Text('InnerFullScreenLaunchComponent').fontSize(16).margin({top: 100})
      Button('Start Sunrise/Sunset')
        .onClick(()=>{
          let appId1: string = '5765880207854372375';
          this.controller.launchAtomicService(appId1, {});
        }).height(30).width('50%').margin({top: 50})
      Button('Start Recharge')
        .onClick(()=>{
          let appId2: string = '5765880207853275489';
          this.controller.launchAtomicService(appId2, {});
        }).height(30).width('50%').margin({top: 50})
    }.backgroundColor(Color.Pink).height('100%').width('100%')
  }
  controller: LaunchController = new LaunchController();

  build() {
    Column() {
      InnerFullScreenLaunchComponent({
          content: this.ColumChild,
          controller: this.controller,
          onReceive: (data) => {
            console.info("onReceive, data: " + data['ohos.atomicService.window']);
          }
        })
    }
    .width('100%').height('100%')
  }
}

```
