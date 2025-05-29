# UIServiceExtensionAbility

## Overview

UIServiceExtensionAbility is an [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) component of the UIService type. It provides UI pages (such as preview pages) and background service capabilities. This component internally holds a UIServiceExtensionContext, which provides a variety of APIs for external systems.

In this document, the component that starts or connects to a UIServiceExtensionAbility is called the client, and the UIServiceExtensionAbility is called the server.

An application can use a UIServiceExtensionAbility in two modes:
- Call [startUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartuiserviceextensionability14) in the [UIExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-uiExtensionContext.md) class to start a UIServiceExtensionAbility.
- Call [connectUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectuiserviceextensionability14) in the [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) or [UIExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-uiExtensionContext.md) class to connect to a UIServiceExtensionAbility.


> **NOTE**
>
> 1. Third-party applications can use a UIServiceExtensionAbility but cannot implement a UIServiceExtensionAbility. (The implementation requires system permissions.)
>
> 2. Third-party applications can connect to a UIServiceExtensionAbility provided by a system application only when they gain focus in the foreground.
>
> 3. The UIServiceExtensionAbility lifecycle is closely related to the window it binds. It is destroyed once the window is destroyed.


## Starting a UIServiceExtensionAbility

An application (client) calls [startUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartuiserviceextensionability14) to start a UIServiceExtensionAbility. Once the UIServiceExtensionAbility is started, its lifecycle is independent of the client. Even if the client is destroyed, the background service remains alive. However, the service is destroyed if the window fails to be created or is destroyed.


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
                console.log('startUIServiceExtensionAbility success');
              }).catch((error: BusinessError) => {
                console.log('startUIServiceExtensionAbility error', JSON.stringify(error));
              })
            } catch (err) {
              console.log('startUIServiceExtensionAbility failed', JSON.stringify(err));
            }
          })
      }
    }
  }
}
```

## Connecting to a UIServiceExtensionAbility

The client connects to the server through [connectUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectuiserviceextensionability14) and obtains a [UIServiceProxy](../reference/apis-ability-kit/js-apis-inner-application-uiserviceproxy.md) object. The client calls [sendData()](../reference/apis-ability-kit/js-apis-inner-application-uiserviceproxy.md#uiserviceproxysenddata) of the proxy object to send data to the server. The server calls the system API **onData()** of the UIServiceExtensionAbility class to receive data from the client.


```ts
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  comProxy: common.UIServiceProxy | null = null;
  connectCallback : common.UIServiceExtensionConnectCallback = {
    onData:(data: Record<string, Object>) => {
      console.log("received data", JSON.stringify(data));
    },
    onDisconnect:() => {
      console.log("onDisconnect ");
    }
  }

  build() {
    Column() {
      Row() {
        // Create a Connect button.
        Button("connect ability")
          .enabled(true)
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            let startWant:Want = {
              bundleName: 'com.acts.uiserviceextensionability',
              abilityName: 'UiServiceExtAbility',
            };
            try {
              // Connect to the UIServiceExtensionAbility.
              context.connectUIServiceExtensionAbility(startWant, this.connectCallback).then((proxy: common.UIServiceProxy) => {
                this.comProxy = proxy;
                let formData: Record<string, string> = {
                  'test': 'test'
                };
                try {
                  this.comProxy.sendData(formData);
                } catch (err) {
                  console.log('sendData failed', JSON.stringify(err));
                };
              }).catch((err: BusinessError) => {
                console.log("connectUIServiceExtensionAbility failed", JSON.stringify(err));
              });
            } catch(err) {
              console.log("connectUIServiceExtensionAbility failed", JSON.stringify(err));
            };
          })
      }
    }
  }
}
```
