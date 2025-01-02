# FullScreenLaunchComponent


**FullScreenLaunchComponent** is a component designed for launching atomic services in full screen. If the invoked application (the one being launched) grants the invoker the authorization to run the atomic service in an embedded manner, the invoker can operate the atomic service in full-screen embedded mode. If authorization is not provided, the invoker will launch the atomic service in a pop-up manner.


> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>
> To implement an embeddable atomic service within this component, it must inherit from [EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md). If it does not inherit from **EmbeddableUIAbility**, the system cannot guarantee that the atomic service will function properly.


## Modules to Import

```
import { FullScreenLaunchComponent } from '@kit.ArkUI'
```


## Child Components

Not supported

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are not supported.

## FullScreenLaunchComponent

FullScreenLaunchComponent({ content: Callback\<void>, appId: string, options?: AtomicServiceOptions })

**Decorator**: \@Component

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full


**Parameters**


| Name| Type| Mandatory| Decorator Type| Description|
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | Yes| \@BuilderParam | Content displayed in the component.|
| appId | string | Yes| - | Application ID for the atomic service.|
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | No| - | Parameters for launching the atomic service.|

## Events
The [universal events](ts-universal-events-click.md) are not supported.

## Example

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
