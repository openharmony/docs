# Using UIServiceExtensionAbility for System Floating Windows

## Overview

Starting from API version 14, applications can leverage the UI (such as preview UI) and background service capabilities provided by the [UIServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-uiServiceExtensionAbility-sys.md). This component, classified as a floating window component of [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) of the UI Service type, encapsulates a [UIServiceExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-uiserviceExtensionContext-sys.md). This context offers a wide range of APIs for external use.

In this document, the component that starts or connects to a UIServiceExtensionAbility is called the client, and the UIServiceExtensionAbility is called the server.

An application can use a UIServiceExtensionAbility in two modes:
- Call [startUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startuiserviceextensionability14) in the [UIExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-uiExtensionContext.md) class to start a UIServiceExtensionAbility.
- Call [connectUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectuiserviceextensionability14) in the [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) or [UIExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-uiExtensionContext.md) class to connect to a UIServiceExtensionAbility.

## Constraints

- This API takes effect only for 2-in-1 devices.

- Third-party applications can use a UIServiceExtensionAbility but cannot implement a UIServiceExtensionAbility. (The implementation requires system permissions.)

- Third-party applications can connect to a UIServiceExtensionAbility provided by a system application only when they gain focus in the foreground.

- The UIServiceExtensionAbility lifecycle is closely related to the window it binds. It is destroyed once the window is destroyed.


## Starting a UIServiceExtensionAbility

An application (client) calls [startUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startuiserviceextensionability14) to start a UIServiceExtensionAbility. Once the UIServiceExtensionAbility is started, its lifecycle is independent of the client. Even if the client is destroyed, the background service remains alive. However, the service is destroyed if the window fails to be created or is destroyed.


For details about how to obtain the context, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).

```ts
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Column() {
      Row() {
        // Create a Start button.
        Button('start ability')
          .enabled(true)
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            let startWant: Want = {
              bundleName: 'com.acts.uiserviceextensionability',
              abilityName: 'UiServiceExtAbility',
            };
            try {
              // Start the UIServiceExtensionAbility.
              context.startUIServiceExtensionAbility(startWant).then(() => {
                console.info('startUIServiceExtensionAbility success.');
              }).catch((error: BusinessError) => {
                console.error(`startUIServiceExtensionAbility failed, err code: ${error.code}, err msg: ${error.message}.`);
              });
            } catch (err) {
              let code = (err as BusinessError).code;
              let msg = (err as BusinessError).message;
              console.error(`startUIServiceExtensionAbility failed, err code: ${code}, err msg: ${msg}.`);
            }
          })
      }
    }
  }
}
```

## Connecting to a UIServiceExtensionAbility

The client connects to the server through [connectUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectuiserviceextensionability14) and obtains a [UIServiceProxy](../reference/apis-ability-kit/js-apis-inner-application-uiserviceproxy.md) object. The client calls [sendData()](../reference/apis-ability-kit/js-apis-inner-application-uiserviceproxy.md#uiserviceproxysenddata) of the proxy object to send data to the server. The server calls the system API **onData()** of the UIServiceExtensionAbility class to receive data from the client.


```ts
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  comProxy: common.UIServiceProxy | null = null;
  connectCallback: common.UIServiceExtensionConnectCallback = {
    onData: (data: Record<string, Object>) => {
      console.info(`data received, data: ${JSON.stringify(data)}.`);
    },
    onDisconnect: () => {
      console.info(`onDisconnect.`);
    }
  }

  build() {
    Column() {
      Row() {
        // Create a Connect button.
        Button('connect ability')
          .enabled(true)
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            let startWant: Want = {
              bundleName: 'com.acts.uiserviceextensionability',
              abilityName: 'UiServiceExtAbility',
            };
            try {
              // Connect to the UIServiceExtensionAbility.
              context.connectUIServiceExtensionAbility(startWant, this.connectCallback)
                .then((proxy: common.UIServiceProxy) => {
                  this.comProxy = proxy;
                  let formData: Record<string, string> = {
                    'test': 'test'
                  };
                  try {
                    this.comProxy.sendData(formData);
                  } catch (err) {
                    let code = (err as BusinessError).code;
                    let msg = (err as BusinessError).message;
                    console.error(`sendData failed, err code:${code}, err msg:${msg}.`);
                  }
                })
                .catch((err: BusinessError) => {
                  console.error(`connectUIServiceExtensionAbility failed, err code: ${err.code}, err msg: ${err.message}.`);
                });
            } catch (err) {
              let code = (err as BusinessError).code;
              let msg = (err as BusinessError).message;
              console.error(`connectUIServiceExtensionAbility failed, err code:${code}, err msg:${msg}.`);
            }
          })
      }
    }
  }
}
```
