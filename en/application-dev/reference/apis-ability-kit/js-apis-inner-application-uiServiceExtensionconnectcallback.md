# UIServiceExtensionConnectCallback

UIServiceExtensionConnectCallback provides callbacks for the connection to a UIServiceExtensionAbility.


> **NOTE**
>
>  - The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - The APIs of this module must be used in the main thread, but not in sub-threads such as Worker and TaskPool.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## UIServiceExtensionConnectCallback.onData

 onData(data: Record&lt;string, Object&gt;): void

Called to receive data when a connection to the UIServiceExtensionAbility is established.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
>

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type                  | Mandatory| Description        |
| ------ | ---------------------- | ---- | ------------ |
| data   | Record&lt;string, Object&gt; | Yes| Data about the UIServiceExtensionAbility connection.|

**Example**

```ts
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Extension] ';

@Entry
@Component
struct UIServiceExtensionAbility {
  comProxy: common.UIServiceProxy | null = null;
  dataCallBack: common.UIServiceExtensionConnectCallback = {
    onData: (data: Record<string, Object>) => {
      console.log(TAG + `dataCallBack received data: `, JSON.stringify(data));
    },
    onDisconnect: () => {
      console.log(TAG + `dataCallBack onDisconnect`);
      this.comProxy = null;
    }
  }

  build() {
    Scroll() {
      Column() {
        // Create a button for connecting to the UIServiceExtensionAbility.
        Button('connectUIServiceExtensionAbility', { type: ButtonType.Capsule, stateEffect: true })
          .margin({
            top: 5,
            left: 10,
            right: 10,
            bottom: 5
          })
          .alignRules({
            center: { anchor: '__container__', align: VerticalAlign.Center },
            middle: { anchor: '__container__', align: HorizontalAlign.Center }
          })
          .onClick(() => {
            this.myConnectUIServiceExtensionAbility()
          });
      }
      .width('100%')
    }
    .height('100%')
  }

  myConnectUIServiceExtensionAbility() {
    // Obtain the context.
    let context = getContext(this) as common.UIAbilityContext;
    let startWant: Want = {
      deviceId: '',
      bundleName: 'com.acts.myapplication',
      abilityName: 'UiServiceExtensionAbility'
    };

    try {
      // Connect to the UIServiceExtensionAbility.
      context.connectUIServiceExtensionAbility(startWant, this.dataCallBack)
        .then((proxy: common.UIServiceProxy) => {
          console.log(TAG + `try to connectUIServiceExtensionAbility ${proxy}}`);
          this.comProxy = proxy;
          let formData: Record<string,string> = {
            'PATH': '/tmp/aaa.jpg'
          };
          try {
            console.log(TAG + `sendData`);
            this.comProxy.sendData(formData);
          } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.log(TAG + `sendData failed, code is ${code}, message is ${message}`);
          }
        }).catch((err: Error) => {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.log(TAG + `connectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.log(TAG + `connectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## UIServiceExtensionConnectCallback.onDisconnect

onDisconnect(): void

Called when the connection to the UIServiceExtensionAbility is interrupted.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
>

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**
```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Extension] ';

@Entry
@Component
struct UIServiceExtensionAbility {
  comProxy: common.UIServiceProxy | null = null;
  // Callback for the connection.
  dataCallBack: common.UIServiceExtensionConnectCallback = {
    onData: (data: Record<string, Object>) => {
      console.log(TAG + `dataCallBack received data: `, JSON.stringify(data));
    },
    onDisconnect: () => {
      // Callback for the disconnection.
      console.log(TAG + `dataCallBack onDisconnect`);
      this.comProxy = null;
    }
  }

  build() {
    Scroll() {
      Column() {
        // Create a button for disconnecting from the UIServiceExtensionAbility.
        Button('disConnectUIServiceExtensionAbility', { type: ButtonType.Capsule, stateEffect: true })
          .margin({
            top: 5,
            left: 10,
            right: 10,
            bottom: 5
          })
          .alignRules({
            center: { anchor: '__container__', align: VerticalAlign.Center },
            middle: { anchor: '__container__', align: HorizontalAlign.Center }
          })
          .onClick(() => {
            this.myConnectUIServiceExtensionAbility()
          });
      }
      .width('100%')
    }
    .height('100%')
  }

  myConnectUIServiceExtensionAbility() {
    // Obtain the context.
    let context = getContext(this) as common.UIAbilityContext;
    // Disconnect from the UIServiceExtensionAbility.
    try {
      // this.comProxy is saved when the connection is established.
      context.disconnectUIServiceExtensionAbility(this.comProxy).then(() => {
        console.log(TAG + `disconnectUIServiceExtensionAbility success`);
      }).catch((err: Error) => {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.log(TAG + `disconnectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.log(TAG + `disconnectUIServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```
