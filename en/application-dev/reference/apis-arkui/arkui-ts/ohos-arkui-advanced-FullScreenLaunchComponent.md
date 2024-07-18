# @ohos.arkui.advanced.FullScreenLaunchComponent (Full Screen Launch Component)


The atomic service component is started in full screen mode. When the user authorized by the started party can run the atomic service in embedded mode, the user runs the atomic service in full screen mode. When the user is not authorized, the user starts the atomic service in jump-out mode.


> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>
> If you need to implement an atomic service that can run in embedded mode in the component, the service must be inherited from [EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md). If this parameter is not inherited from EmbeddableUIAbility, the system cannot ensure that atomic services are normal.


## Import modules.

```
import { FullScreenLaunchComponent } from "@ohos.arkui.advanced.FullScreenLaunchComponent"
```


## Child Components

Not supported

## Name
The [universal attributes](ts-universal-attributes-size.md) are not supported.

## FullScreenLaunchComponent

FullScreenLaunchComponent({ content: Callback\<void>, appId: string, options?: AtomicServiceOptions })

**Decorator**: \@Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full


**Parameters**


| Name | Type | Mandatory | Decorator Type | **Description** |
| -------- | -------- | -------- | -------- | -------- |
| content | Callback\<void> | M | \@BuilderParam | Content displayed on the widget. |
| appId | string | M | - | App ID of the atomic service. |
| options | [AtomicServiceOptions](../../apis-ability-kit/js-apis-app-ability-atomicServiceOptions.md) | No | - | Parameter for starting atomic services. |

## Event
The [universal events](ts-universal-events-click.md) are not supported.

## Example

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
