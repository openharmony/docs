# UIServiceExtension

## 概述

UIServiceExtension是UIService类型的[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)浮窗类组件，提供UI界面（例如预览界面）和后台服务能力。组件内部持有了一个UIServiceExtensionContext，通过UIServiceExtensionContext提供了丰富的接口供外部使用。

本文描述中称被启动的UIServiceExtension为服务端，称启动UIServiceExtension的组件为客户端。

应用可以通过启动和连接两种形式使用UIServiceExtension：
- 通过[UIExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-uiExtensionContext.md)调用[startUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startuiserviceextensionability14)方法启动UIServiceExtension。
- 通过[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)、[UIExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-uiExtensionContext.md)调用[connectUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectuiserviceextensionability14)方法连接UIServiceExtension。


> **说明：**
>
> 1. 三方应用可以使用UIServiceExtension，不支持实现UIServiceExtension（需要系统权限）。
>
> 2. 三方应用需要在前台获焦的情况下才能连接系统提供的UIServiceExtension。
>
> 3. UIServiceExtension的生命周期与绑定的窗口强关联，窗口销毁后UIServiceExtension也一起销毁。


## 启动UIServiceExtension

应用通过[startUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startuiserviceextensionability14)方法启动一个UIServiceExtension。UIServiceExtension启动后，其生命周期独立于客户端，即使客户端已经销毁，该后台服务仍可继续运行，窗口创建失败或销毁后该服务会被销毁。


示例中的context的获取方式请参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。

```ts
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Column() {
      Row() {
        // 创建启动按钮
        Button('start ability')
          .enabled(true)
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            let startWant: Want = {
              bundleName: 'com.acts.uiserviceextensionability',
              abilityName: 'UiServiceExtAbility',
            };
            try {
              // 启动UIServiceExtensionAbility
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

## 客户端连接服务端

  客户端通过[connectUIServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectuiserviceextensionability14)连接服务端，获取并保存[UIServiceProxy](../reference/apis-ability-kit/js-apis-inner-application-uiserviceproxy.md)对象。通过该proxy对象的[sendData()](../reference/apis-ability-kit/js-apis-inner-application-uiserviceproxy.md#uiserviceproxysenddata)方法发送数据给服务端。服务端通过UIServiceExtensionAbility类onData()（系统接口）方法接收客户端数据。


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
        // 创建连接按钮
        Button("connect ability")
          .enabled(true)
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            let startWant:Want = {
              bundleName: 'com.acts.uiserviceextensionability',
              abilityName: 'UiServiceExtAbility',
            };
            try {
              // 连接UIServiceExtensionAbility
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