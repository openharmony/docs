# FullScreenLaunchComponent


**FullScreenLaunchComponent** is a component designed for launching atomic services in full screen. If the invoked application (the one being launched) grants the invoker the authorization to run the atomic service in an embedded manner, the invoker can operate the atomic service in full-screen embedded mode. If authorization is not provided, the invoker will launch the atomic service in a pop-up manner.


> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>
> To implement an embeddable atomic service within this component, it must inherit from [EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md). If it does not inherit from **EmbeddableUIAbility**, the system cannot guarantee that the atomic service will function properly.


## Modules to Import

```ts
import { FullScreenLaunchComponent } from '@kit.ArkUI'
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-component-general-attributes.md) are not supported.

## Events
The [universal events](ts-component-general-events.md) are not supported.

## FullScreenLaunchComponent

FullScreenLaunchComponent({ content: Callback\<void>, appId: string, options?: AtomicServiceOptions, onError?: ErrorCallback, onTerminated?: Callback\<TerminationInfo> })

**Decorator**: \@Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Decorator Type| Description|
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | Yes| \@BuilderParam | Custom placeholder icon displayed before launching the atomic service. This allows you to create a large launch icon similar to those used by desktop applications. Clicking the placeholder icon will launch the atomic service.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| appId | string | Yes| - |  Application ID of the atomic service to be launched. It is the unique identifier for the atomic service.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<!--RP1--><!--RP1End-->|
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | No| - | Parameters for launching the atomic service.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| onError<sup>18+<sup> | [ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | No| - | Triggered when an exception occurs during the execution of an embedded atomic service. You can obtain the error information based on the **code**, **name**, and **message** parameters in the callback and rectify the exception accordingly.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| onTerminated<sup>18+<sup> | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](ts-container-embedded-component.md#terminationinfo)> | No| - | Triggered when an embedded atomic service exits properly by calling [terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) or [terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself).<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

> **NOTE**
>
> - If the atomic service exits by calling [terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult), the information it carries is passed to the callback parameter.
> - If the atomic service exits by calling [terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself), the callback parameter has a default **code** value of **0** and **want** of **undefined**.

## Example

```ts
import { FullScreenLaunchComponent } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State appId: string = '6918661953712445909'; // Application ID of the atomic service.

  build() {
    Row() {
      Column() {
        FullScreenLaunchComponent({
          content: ColumChild,
          appId: this.appId,
          options: {},
          onTerminated: (info) => {
            console.info("onTerminated code: " + info.code.toString());
          },
          onError: (err) => {
            console.error("onError code: " + err.code + ", message: ", err.message);
          }
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
