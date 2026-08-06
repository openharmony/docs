# Using the AgentExtensionAbility Component to Implement Agent Services

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=b7286236f07669dfc3e12dcda7340166731612d2 translatedAt=2026-07-28T07:26:01.866Z pushedAt=2026-07-29T02:31:53.165Z -->

## Overview

In cross-app collaboration scenarios, developers often need to call agent services provided by other apps from system apps, but the lack of a standardized communication mechanism leads to high integration costs and complex security authentication. Starting from API version 24, developers can use the [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md) component to provide agent services. System apps can connect to the [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md) component implemented by other apps and use the corresponding agent services. Using this component reduces cross-app integration costs, ensures communication security, and supports real-time interaction through a bidirectional data channel.

> **NOTE**
>
> In this document, the connected [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md) is referred to as the server, and the component that connects to the [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md) is referred to as the client.

## Implementing the AgentExtensionAbility Component

Manually create an [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md) in the DevEco Studio project. The specific steps are as follows:

1. In the ets directory of the project module, right-click and choose **New > Directory**, then create a new directory named agentextability.

2. In the AgentExtAbility directory, right-click and choose **New > ArkTS File**, then create a new file named AgentExtAbility.ets.

    ``` txt
    ├── ets
    │ ├── agentextability
    │ │   ├── AgentExtAbility.ets
    ```

3. In the AgentExtAbility.ets file, add the import module for [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md), and define a custom class AgentExtAbility that inherits from [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md) and implements the lifecycle callbacks.

    <!-- @[ability_agent_service_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/AgentExtensionAbility/entry/src/main/ets/agentextability/AgentExtAbility.ets) -->

    ``` TypeScript
    import { common, AgentExtensionAbility, Want } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    
    export default class AgentExtAbility extends AgentExtensionAbility {
      private comProxy: common.AgentHostProxy | null = null;
      // Create the AgentExtensionAbility.
      onCreate(want: Want) {
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
      }
    
      // Connect.
      onConnect(want: Want, proxy: common.AgentHostProxy) {
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onConnect');
        this.comProxy = proxy;
      }
    
      // Disconnect.
      onDisconnect(want: Want, proxy: common.AgentHostProxy) {
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDisconnect');
        this.comProxy = null;
      }
      // Receive data.
      onData(proxy: common.AgentHostProxy, data: string) {
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onData');
        try {
          let replyData = 'reply message';
          proxy.sendData(replyData);
        } catch (err) {
          let code = (err as BusinessError).code;
          let msg = (err as BusinessError).message;
          console.error(`sendData failed, err code: ${code}, err msg: ${msg}.`);
        }
      }
      // Perform authentication.
      onAuth(proxy: common.AgentHostProxy, handshakeData: string) {
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onAuth');
        try {
          // Handle the authentication logic.
          let authResult = 'auth success';
          proxy.authorize(authResult);
        } catch (err) {
          let code = (err as BusinessError).code;
          let msg = (err as BusinessError).message;
          console.error(`sendData failed, err code: ${code}, err msg: ${msg}.`);
        }
      }
      // Destroy.
      onDestroy() {
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
      }
    }
    ```

4. Register the AgentExtensionAbility in the [module.json5 Configuration File](../quick-start/module-configuration-file.md) of the project module. Set the type tag to "agent", and use the srcEntry tag to specify the code path of the current ExtensionAbility component.

    ```json
    {
      "module": {
        "extensionAbilities": [
          {
            "name": "AgentExtAbility",
            "icon": "$media:icon",
            "description": "agent",
            "type": "agent",
            "exported": true,
            "srcEntry": "./ets/agentextability/AgentExtAbility.ets",
            "metadata": [
              {
                "name": "ohos.extension.agent",
                "resource": "$profile:agent_config",
              }
            ]
          }
        ]
      }
    }
    ```

5. Create an agent_config.json file in the `resources/base/profile/` directory of the project module, and then configure the [AgentCard](../reference/apis-ability-kit/js-apis-inner-application-AgentCard.md) information in it. For detailed steps, see [Agent Configuration File ](./agent-extension-configuration.md).

## Sending and Receiving Data Using the AgentExtensionAbility Component

An app can receive data passed by the client and the [AgentHostProxy](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md) object in the [onData()](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md#ondata) method of the server-side AgentExtensionAbility component. It can also send data to the client by calling the [sendData()](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md#senddata) method of the [AgentHostProxy](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md) object.

<!-- @[ability_agent_service_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/AgentExtensionAbility/entry/src/main/ets/agentextability/AgentExtAbility.ets) -->

``` TypeScript
import { common, AgentExtensionAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class AgentExtAbility extends AgentExtensionAbility {
  // ...
  // Receive data.
  onData(proxy: common.AgentHostProxy, data: string) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onData');
    try {
      let replyData = 'reply message';
      proxy.sendData(replyData);
    } catch (err) {
      let code = (err as BusinessError).code;
      let msg = (err as BusinessError).message;
      console.error(`sendData failed, err code: ${code}, err msg: ${msg}.`);
    }
  }
  // ...
}
```

## Using the AgentExtensionAbility Component to Receive and Send Security Authentication Requests

An app can receive a client's security authentication request and the [AgentHostProxy](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md) object in the [onAuth()](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md#onauth) method of the server-side AgentExtensionAbility component, and can send a security authentication request to the client through the [authorize()](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md#authorize) method of [AgentHostProxy](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md).

<!-- @[ability_agent_service_three](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/AgentExtensionAbility/entry/src/main/ets/agentextability/AgentExtAbility.ets) -->

``` TypeScript
import { common, AgentExtensionAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class AgentExtAbility extends AgentExtensionAbility {
  // ...
  // Perform authentication.
  onAuth(proxy: common.AgentHostProxy, handshakeData: string) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onAuth');
    try {
      // Handle the authentication logic.
      let authResult = 'auth success';
      proxy.authorize(authResult);
    } catch (err) {
      let code = (err as BusinessError).code;
      let msg = (err as BusinessError).message;
      console.error(`sendData failed, err code: ${code}, err msg: ${msg}.`);
    }
  }
  // ...
}
```
<!--no_check-->