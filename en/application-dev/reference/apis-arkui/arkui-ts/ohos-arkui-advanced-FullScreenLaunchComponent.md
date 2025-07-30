# FullScreenLaunchComponent


**FullScreenLaunchComponent** is a component designed for launching atomic services in full screen. If the invoked application (the one being launched) grants the invoker the authorization to run the atomic service in an embedded manner, the invoker can operate the atomic service in full-screen embedded mode. If authorization is not provided, the invoker will launch the atomic service in a pop-up manner.


> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>
> This component is not supported on wearables.
>
> To implement an embeddable atomic service within this component, it must inherit from [EmbeddableUIAbility](../../apis-ability-kit/js-apis-app-ability-embeddableUIAbility.md). Otherwise, the system cannot guarantee that the atomic service will function properly.


## Modules to Import

```ts
import { FullScreenLaunchComponent } from '@kit.ArkUI';
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
| onTerminated<sup>18+<sup> | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<[TerminationInfo](ts-container-embedded-component.md#terminationinfo)> | No| - | Triggered when an embedded atomic service exits properly by calling [terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult) or [terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself)<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| onReceive<sup>20+<sup> | [Callback](../../apis-basic-services-kit/js-apis-base.md#callback)\<Record<string, Object>> | No| - | Callback triggered when the embedded atomic service is launched through [Window](../../../windowmanager/application-window-stage.md) API calls.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

> **NOTE**
>
> - If the atomic service exits by calling [terminateSelfWithResult](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateselfwithresult), the information it carries is passed to the callback parameter.
> - If the atomic service exits by calling [terminateSelf](../../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself), the callback parameter has a default **code** value of **0** and **want** of **undefined**.

## Example
This example demonstrates component usage with extended atomic service capabilities. In real-world development, replace the sample **appId** with the actual application of your ID atomic service.

**User Implementation**
```ts
// The entry point file Index.ets for the user side is as follows:
import { FullScreenLaunchComponent } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State appId: string = '6917573653426122083'; // Application ID of the atomic service.

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
          },
          onReceive: (data) => {
            console.info("onReceive, data: " + JSON.stringify(data));
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
    Image($r('app.media.startIcon'))
    Text('test')
  }
}
```
**Provider Implementation**

You need to modify the following files for the atomic service provider:
- Entry point file: **/src/main/ets/entryability/EntryAbility.ets**
```ts
import { AbilityConstant, Want, EmbeddableUIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;

export default class EntryAbility extends EmbeddableUIAbility {
  storage = new LocalStorage();
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onCreate');
  }

  onDestroy(): void {
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    let mainWindow = windowStage.getMainWindowSync()
    this.storage.setOrCreate("window", mainWindow)
    this.storage.setOrCreate("windowStage", windowStage)
    windowStage.loadContent('pages/Index', this.storage);
  }

  onWindowStageDestroy(): void {
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onBackground');
  }
}
```

- Extended ability entry page file: **/src/main/ets/pages/Index.ets**
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;

@Entry({ storage : new LocalStorage() })
@Component
struct Index {
  storage = new LocalStorage()

  build() {
    Row() {
      Column() {
        GridRow({ columns: 2 }) {
          GridCol() {
            Button("setWindowSystemBar")
              .onClick(() => {
                this.testSetSystemBarEnable()
              }).width(120)
          }.height(60)
          GridCol() {
            Button("setGestureBack")
              .onClick(() => {
                this.testSetGestureBackEnable()
              }).width(120)
          }.height(60)
          GridCol() {
            Button("setImmersive")
              .onClick(() => {
                this.testSetImmersiveEnable()
              }).width(120)
          }.height(60)
          GridCol() {
            Button("setSpecificSystemBarEnabled")
              .onClick(() => {
                this.testSetSpecificSystemBarEnabled()
              }).width(120)
          }.height(60)
        }
      }
      .width('100%')
    }
    .height('100%')
  }
  testSetSystemBarEnable() {
    let window: window.Window | undefined = this.storage.get("window");
    let p = window?.setWindowSystemBarEnable(["status"])
    p?.then(() => {
      console.info('setWindowSystemBarEnable success');
    }).catch((err: BusinessError) => {
      console.info('setWindowSystemBarEnable failed, error = ' + JSON.stringify(err));
    })
  }
  testSetGestureBackEnable() {
    let window: window.Window | undefined = this.storage.get("window");
    let p = window?.setGestureBackEnabled(true)
    p?.then(() => {
      console.info('setGestureBackEnabled success');
    }).catch((err: BusinessError) => {
      console.info('setGestureBackEnabled failed, error = ' + JSON.stringify(err));
    })
  }
  testSetImmersiveEnable() {
    let window: window.Window | undefined = this.storage.get("window");
    try{
      window?.setImmersiveModeEnabledState(true)
    } catch(err) {
      console.info('setImmersiveModeEnabledState failed, error = ' + JSON.stringify(err));
    }
  }
  testSetSpecificSystemBarEnabled() {
    let window: window.Window | undefined = this.storage.get("window");
    let p = window?.setSpecificSystemBarEnabled('navigationIndicator', false, false)
    p?.then(() => {
      console.info('setSpecificSystemBarEnabled success');
    }).catch((err: BusinessError) => {
      console.info('setSpecificSystemBarEnabled failed, error = ' + JSON.stringify(err));
    })
  }
}
```
