# @ohos.app.agent.agentManager (Agent Intelligent Component Management) (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=249c9154cca3bfd8d247bc281ba57ee999bfbe43 translatedAt=2026-08-13T13:20:05.610Z pushedAt=2026-08-17T01:58:04.750Z -->

The agentManager module provides Agent management capabilities, including connecting to and disconnecting from AgentExtensionAbility, lifecycle management of LOW_CODE Agents, connection management between AgentExtensionAbility and ServiceExtensionAbility, and obtaining AgentCard information on the device.

> **NOTE**
>
> The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> All APIs of this module are system APIs.

## Modules to Import

```ts
import { agentManager } from '@kit.AbilityKit';
```

## agentManager.getAllAgentCards

getAllAgentCards(): Promise\<Array\<AgentCard>>

Obtains all AgentCards on the device. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_AGENT_CARD

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**System API**: This is a system API.

**Return value**

| Type | Description |
| -------- | -------- |
| Promise<Array<[AgentCard](./js-apis-inner-application-AgentCard.md#agentcard-1)>> | Promise used to return the result, which is an array of all AgentCards on the device. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |

**Example**

```ts
import { agentManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

agentManager.getAllAgentCards()
  .then((data) => {
    console.info(`GetAllAgentCards success, data: ${JSON.stringify(data)}.`);
  })
  .catch((err: BusinessError) => {
    console.error(`GetAllAgentCards failed, error code: ${err.code}, error msg: ${err.message}.`);
  });
```

## agentManager.getAgentCardsByBundleName

getAgentCardsByBundleName(bundleName: string): Promise\<Array\<AgentCard>>

Obtains all AgentCards of a specified app. This API uses a promise to return the result.

**Model Constraint**: This API can be used only in the stage model.

**Required Permissions**: ohos.permission.GET_AGENT_CARD

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes | Name of the bundle to which the AgentCard belongs. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise<Array<[AgentCard](./js-apis-inner-application-AgentCard.md#agentcard-1)>> | Promise used to return all AgentCard arrays in the specified bundleName. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 18500001 | The bundle does not exist or no patch has been applied. |

**Example**

```ts
import { agentManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'com.example.myapplication';

agentManager.getAgentCardsByBundleName(bundleName)
  .then((data) => {
    console.info(`GetAgentCardsByBundleName success, data: ${JSON.stringify(data)}.`);
  })
  .catch((err: BusinessError) => {
    console.error(`GetAgentCardsByBundleName failed, error code: ${err.code}, error msg: ${err.message}.`);
  });
```

## agentManager.getAgentCardByAgentId

getAgentCardByAgentId(bundleName: string, agentId: string): Promise\<AgentCard>

Obtains the AgentCard corresponding to the specified app agentId. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required Permissions**: ohos.permission.GET_AGENT_CARD

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes | Name of the bundle to which the AgentCard belongs. |
| agentId | string | Yes | ID of the agent to which the AgentCard belongs. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise<[AgentCard](./js-apis-inner-application-AgentCard.md#agentcard-1)> | Promise used to return the specified AgentCard. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 18500001 | The bundle does not exist or no patch has been applied. |
| 35600001 | The specified agentId does not exist. |

**Example**

```ts
import { agentManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'com.example.myapplication';
let agentId = 'agent_001';

agentManager.getAgentCardByAgentId(bundleName, agentId)
  .then((data) => {
    console.info(`GetAgentCardByAgentId success, data: ${JSON.stringify(data)}.`);
  })
  .catch((err: BusinessError) => {
    console.error(`GetAgentCardByAgentId failed, error code: ${err.code}, error msg: ${err.message}.`);
  });
```

## agentManager.connectAgentExtensionAbility

connectAgentExtensionAbility(want: Want, agentId: string, callback: AgentExtensionConnectCallback): Promise\<AgentProxy>

Connects the current caller component to [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md). Communicates with [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md) through the returned [AgentProxy](js-apis-inner-application-agentProxy-sys.md) to use the capabilities provided by AgentExtensionAbility.

> **NOTE**
>
> - When the AgentCard of the target agent is of the [LOW_CODE](js-apis-app-agent-agentConstant-sys.md#agentconstantagentcardtype) type, the [onConnect](js-apis-app-agent-agentExtensionAbility.md#onconnect) callback of AgentExtensionAbility is invoked only when this type of agent is connected successfully. For subsequent agents of this type that are connected, only [onAgentInvoked](js-apis-app-agent-agentExtensionAbility-sys.md#onagentinvoked) is invoked.
>
> - In the same AgentExtensionAbility, a maximum of 100 LOW_CODE agents can run simultaneously. Otherwise, error code 35600003 is reported.
>
> - In the same AgentExtensionAbility, connecting to the same LOW_CODE agent repeatedly is not allowed.

**System API**: This is a system API.

**Model Constraint:** This API can be used only in the stage model.

**Required Permissions:** ohos.permission.CONNECT_AGENT

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name     | Type                                  | Mandatory | Description           |
| -------- | ------------------------------------- | --------- | --------------------- |
| want     | [Want](js-apis-app-ability-want.md)   | Yes       | Want information of the [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md), which usually includes the bundle name and ability name. |
| agentId  | string                                | Yes       | Agent ID of the [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md). |
| callback | [AgentExtensionConnectCallback](js-apis-inner-application-agentExtensionConnectCallback-sys.md) | Yes       | Callback used to receive data and security authentication data from the [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md) server and handle the disconnection event. |

**Return value**

| Type                       | Description                         |
| -------------------------- | ----------------------------------- |
| Promise\<[AgentProxy](js-apis-inner-application-agentProxy-sys.md)> | Promise used to return the AgentProxy object, which is used to send data or security authentication requests from the client to the AgentExtensionAbility server. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000008 | The crowdtesting application expires. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by enterprise device management (EDM). |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000073 | The app clone index is invalid. |
| 35600001 | The specified agentId does not exist. |
| 35600003 | Maximum connections from the same caller have been reached. Please disconnect at least one agent extension beforehand.|
| 35600007 | The specified LOW_CODE agent is already active and is not yet completed. |

**Example**

```ts
import { common, Want, agentManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  comProxy: common.AgentProxy | null = null;
  connectCallback: common.AgentExtensionConnectCallback = {
    onData: (data: string) => {
      console.info(`onData, data: ${data}.`);
    },
    onAuth: (handShakeData: string): void => {
      console.info(`onData, data: ${handShakeData}.`);
    },
    onDisconnect: () => {
      console.info(`onDisconnect.`);
      this.comProxy = null;
    }
  }
  build() {
    Column() {
      Row() {
        // Create the connect button.
        Button('connect ability')
          .enabled(true)
          .onClick(() => {
            let connectWant: Want = {
              bundleName: 'com.acts.agentextensionability',
              abilityName: 'AgentExtAbility',
            };
            let agentId: string = 'test';
            try {
              // Connect the AgentExtensionAbility.
              agentManager.connectAgentExtensionAbility(connectWant, agentId, this.connectCallback)
                .then((proxy: common.AgentProxy) => {
                  this.comProxy = proxy;
                })
                .catch((err: BusinessError) => {
                  console.error(`connectAgentExtensionAbility failed, err code: ${err.code}, err msg: ${err.message}.`);
                });
            } catch (err) {
              let code = (err as BusinessError).code;
              let msg = (err as BusinessError).message;
              console.error(`connectAgentExtensionAbility failed, err code: ${code}, err msg: ${msg}.`);
            }
          })
      }
    }
  }
}
```

## agentManager.registerAgentCard

registerAgentCard(agentCard: AgentCard): Promise\<void>

Registers an AgentCard with the system so that the system can identify and invoke the corresponding AgentExtensionAbility.

The system validates the appInfo based on the type:

- APP and LOW_CODE types: validates whether the bundle and ability exist, and whether the ability is of the agent type.

- ATOMIC_SERVICE type: when the atomic service is installed, validates whether the ability exists and verifies whether the ability is of the agent type.

**Since**: 26.0.0

**System API**: This is a system API.

**Model Constraint**: This API can be used only in the stage model.

**Required Permissions**: ohos.permission.MODIFY_AGENT_CARD

**System capability**: SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name    | Type                                              | Mandatory | Description           |
| ------- | ------------------------------------------------- | --------- | --------------------- |
| agentCard | [AgentCard](./js-apis-inner-application-AgentCard.md#agentcard-1) | Yes   | Information about the AgentCard to register. |

**Return value**

| Type            | Description            |
| --------------- | ---------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 18500001 | The bundle does not exist or no patch has been applied. |
| 35600005 | The specified AgentCard version is invalid. |
| 35600006 | The specified AgentCard has already been registered. Use updateAgentCard instead. |
| 35600008 | The number of AgentCards in the bundle reaches the limit. |

**Example**

```ts
import { agentManager, agentConstant, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let agentCard: common.AgentCard = {
  agentId: 'agent_001',
  name: 'Smart Assistant',
  description: 'This is a smart assistant',
  version: '1.0.0',
  defaultInputModes: ['text/plain'],
  defaultOutputModes: ['text/plain'],
  skills: [{
    id: 'skill_001',
    name: 'Basic skill',
    description: 'This is a basic skill',
    tags: ['Assistant', 'Query']
  }],
  iconUrl: 'common/weather_icon.png',
  category: 'productivity',
  type: agentConstant.AgentCardType.APP,
  appInfo: {
    bundleName: 'com.example.myapplication',
    moduleName: 'entry',
    abilityName: 'AgentExtAbility'
  }
};

agentManager.registerAgentCard(agentCard)
  .then(() => {
    console.info('RegisterAgentCard success.');
  })
  .catch((err: BusinessError) => {
    console.error(`RegisterAgentCard failed, error code: ${err.code}, error msg: ${err.message}.`);
  });
```

## agentManager.updateAgentCard

updateAgentCard(agentCard: AgentCard): Promise\<void>

Updates the information of an existing AgentCard in the system. The overwrite update is performed when the [SemVer version](https://semver.org/) is not lower than that of the existing AgentCard. When the SemVer versions are the same, the system preferentially saves the AgentCard passed in when [registerAgentCard](#agentmanagerregisteragentcard) or [updateAgentCard](#agentmanagerupdateagentcard) is called.

The system validates appInfo based on the type:

- APP and LOW_CODE types: validates whether the bundle and ability exist, and verifies whether the ability is of the agent type.

- ATOMIC_SERVICE type: when the atomic service is installed, validates whether the ability exists and whether the ability is of the agent type.

**Since**: 26.0.0

**System API**: This is a system API.

**Model Constraint**: This API can be used only in the stage model.

**Required Permissions**: ohos.permission.MODIFY_AGENT_CARD

**System capability**: SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name    | Type                                              | Mandatory | Description           |
| ------- | ------------------------------------------------- | --------- | --------------------- |
| agentCard | [AgentCard](./js-apis-inner-application-AgentCard.md#agentcard-1) | Yes   | Information about the AgentCard to update. |

**Return value**

| Type            | Description            |
| --------------- | ---------------------- |
| Promise\<void> | Promise used to return the result. No value is returned. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 18500001 | The bundle does not exist or no patch has been applied. |
| 35600001 | The specified agentId does not exist. |
| 35600004 | The specified AgentCard version is older than the current version. |
| 35600005 | The specified AgentCard version is invalid. |

**Example**

```ts
import { agentManager, agentConstant, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let agentCard: common.AgentCard = {
  agentId: 'agent_001',
  name: 'Smart Assistant',
  description: 'This is the updated smart assistant.',
  version: '1.0.1',
  defaultInputModes: ['text/plain'],
  defaultOutputModes: ['text/plain'],
  skills: [{
    id: 'skill_001',
    name: 'Basic skill',
    description: 'This is a basic skill.',
    tags: ['Assistant', 'Query']
  }],
  iconUrl: 'common/weather_icon.png',
  category: 'productivity',
  type: agentConstant.AgentCardType.APP,
  appInfo: {
    bundleName: 'com.example.myapplication',
    moduleName: 'entry',
    abilityName: 'AgentExtAbility'
  }
};

agentManager.updateAgentCard(agentCard)
  .then(() => {
    console.info('UpdateAgentCard success.');
  })
  .catch((err: BusinessError) => {
    console.error(`UpdateAgentCard failed, error code: ${err.code}, error msg: ${err.message}.`);
  });
```

## agentManager.deleteAgentCard

deleteAgentCard(bundleName: string, agentId: string): Promise\<void>

Deletes the AgentCard corresponding to the specified agentId of an app.

**Since**: 26.0.0

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**Required Permissions**: ohos.permission.MODIFY_AGENT_CARD

**System capability**: SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name       | Type   | Mandatory | Description                               |
| ---------- | ------ | --------- | ----------------------------------------- |
| bundleName | string | Yes       | Used to identify the bundle name of the AgentCard. |
| agentId    | string | Yes       | Used to identify the agentId of the AgentCard.     |

**Return value**

| Type            | Description            |
| --------------- | ---------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 35600001 | The specified agentId does not exist. |

**Example**

```ts
import { agentManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let bundleName = 'com.example.myapplication';
let agentId = 'agent_001';

agentManager.deleteAgentCard(bundleName, agentId)
  .then(() => {
    console.info('DeleteAgentCard success.');
  })
  .catch((err: BusinessError) => {
    console.error(`DeleteAgentCard failed, error code: ${err.code}, error msg: ${err.message}.`);
  });
```

## agentManager.disconnectAgentExtensionAbility

disconnectAgentExtensionAbility(proxy: AgentProxy): Promise\<void>

Disconnects from the [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md) of the specified proxy.

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**Required permissions:** ohos.permission.CONNECT_AGENT

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name  | Type                                             | Mandatory | Description           |
| ------ | ------------------------------------------------ | ---- | ------------ |
| proxy  | [AgentProxy](js-apis-inner-application-agentProxy-sys.md) | Yes   | Proxy object corresponding to the [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md) to disconnect. The proxy object is returned when [connectAgentExtensionAbility](#agentmanagerconnectagentextensionability) is called to connect to the [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md). |

**Return value**

| Type            | Description            |
| --------------- | --------------- |
| Promise\<void> | Promise used to return the result. No value is returned. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |

**Example**

```ts
import { common, agentManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
@Entry
@Component
struct Index {
  comProxy: common.AgentProxy | null = null;
  build() {
    Column() {
      Row() {
        // Create the connect button.
        Button('connect ability')
          .enabled(true)
          .onClick(() => {
            try {
              // Connect the AgentExtensionAbility.
              agentManager.disconnectAgentExtensionAbility(this.comProxy)
                .then(() => {
                })
                .catch((err: BusinessError) => {
                  console.error(`connectAgentExtensionAbility failed, error code: ${err.code}, error msg: ${err.message}.`);
                });
            } catch (err) {
              let code = (err as BusinessError).code;
              let msg = (err as BusinessError).message;
              console.error(`connectAgentExtensionAbility failed, error code: ${code}, error msg: ${msg}.`);
            }
          })
      }
    }
  }
}
```

## agentManager.notifyLowCodeAgentComplete

notifyLowCodeAgentComplete(agentId: string): Promise\<void>

Notifies that the lifecycle of the AgentCard associated with the specified [LOW_CODE](js-apis-app-agent-agentConstant-sys.md#agentconstantagentcardtype) type has ended.

**Since**: 26.0.0

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**Required Permissions:** ohos.permission.CONNECT_AGENT

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name    | Type   | Mandatory | Description                  |
| ------- | ------ | --------- | ---------------------------- |
| agentId | string | Yes       | Agent ID used to identify the AgentCard. |

**Return value**

| Type            | Description            |
| --------------- | ---------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 35600001 | The specified agentId does not exist. |

**Example**

```ts
import { agentManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let agentId = 'agent_001';

agentManager.notifyLowCodeAgentComplete(agentId)
  .then(() => {
    console.info('NotifyLowCodeAgentComplete success.');
  })
  .catch((err: BusinessError) => {
    console.error(`NotifyLowCodeAgentComplete failed, error code: ${err.code}, error msg: ${err.message}.`);
  });
```

## agentManager.connectServiceExtensionAbility

connectServiceExtensionAbility(context: AgentExtensionContext, want: Want, callback: ConnectOptions): number

Connects an AgentExtensionAbility to a ServiceExtensionAbility. If the target ServiceExtensionAbility is visible, it can be connected directly. If it is invisible, the **ohos.permission.START_INVISIBLE_ABILITY** permission is required. If the target ServiceExtensionAbility is on a remote device, the **ohos.permission.DISTRIBUTED_DATASYNC** permission is required.

> **NOTE**
>
> This API cannot be called in a multithread or child process. Calling it in a multithread causes a CppCrash, and calling it in a child process returns error code 16000050.

**Since**: 26.0.0

**System API**: This is a system API.

**Model Constraint**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name     | Type                                                        | Mandatory | Description                                |
| -------- | ----------------------------------------------------------- | --------- | ----------------------------------- |
| context  | [AgentExtensionContext](js-apis-inner-application-agentExtensionContext.md) | Yes   | Context of the current Agent extension ability, including the AgentCard information.    |
| want     | [Want](js-apis-app-ability-want.md)                          | Yes   | Want information of the target ServiceExtensionAbility, including bundleName and abilityName.              |
| callback | [ConnectOptions](js-apis-inner-ability-connectOptions.md)      | Yes   | Callback of the ConnectOptions type, used to return the information about successful connection, connection failure, and disconnection.  |

**Return value**

| Type | Description |
| ---- | ------------------------------------------------------------ |
| number | Connection ID used to identify the connection between the current AgentExtensionAbility and the ServiceExtensionAbility. This connection ID can be used to call [disconnectServiceExtensionAbility](#agentmanagerdisconnectserviceextensionability) to disconnect the connection. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 202      | Not system application. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by enterprise device management (EDM). |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000073 | The app clone index is invalid. |

**Example**

```ts
import { common, Want, AgentExtensionAbility, agentManager, bundleManager } from '@kit.AbilityKit';
import { JSON } from '@kit.ArkTS';
import { rpc } from '@kit.IPCKit';

let TAG = 'DemoAgentForConnect';

export default class DemoAgentForConnect extends AgentExtensionAbility {

  connectService(want: Want): number {
    try {
      let options: common.ConnectOptions = {
        onConnect(elementName: bundleManager.ElementName, remote: rpc.IRemoteObject) {
          console.info(`${TAG} onConnect ${JSON.stringify(elementName)}`);
        },
        onDisconnect(elementName: bundleManager.ElementName) {
          console.info(`${TAG} onDisconnect ${JSON.stringify(elementName)}`);
        },
        onFailed(code: number) {
          console.info(`${TAG} onFailed... ${code}`);
        }
      };
      console.info(`${TAG} start connect`);
      const connectId = agentManager.connectServiceExtensionAbility(this.context, want, options);
      console.info(`${TAG} connect end, connectId=${connectId} `);
      return connectId;
    } catch (err) {
      console.error(`${TAG} connectServiceExtensionAbility failed.`);
    }
    return -1;
  }
}
```

## agentManager.disconnectServiceExtensionAbility

disconnectServiceExtensionAbility(context: AgentExtensionContext, connectId: number): Promise\<void>

Disconnects the AgentExtensionAbility from the ServiceExtensionAbility.

**Since**: 26.0.0

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name     | Type                                                        | Mandatory | Description                                           |
| -------- | ----------------------------------------------------------- | --------- | ---------------------------------------------- |
| context    | [AgentExtensionContext](js-apis-inner-application-agentExtensionContext.md) | Yes   | Context of the current Agent extension ability, which contains the AgentCard information.    |
| connectId  | number                                                        | Yes   | Connection ID returned by [connectServiceExtensionAbility](#agentmanagerconnectserviceextensionability), used to identify the target connection to disconnect. |

**Return value**

| Type            | Description            |
| --------------- | --------------- |
| Promise\<void> | Promise used to return the result. No value is returned. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | -------- |
| 202      | Not system application. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |

**Example**

```ts
import { AgentExtensionAbility, agentManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let TAG = 'DemoAgentForDisConnect';

export default class DemoAgentForDisConnect extends AgentExtensionAbility {

  disconnectService(connectId: number) {
    try {
      console.info(`${TAG} start disconnect:${connectId}`);
      agentManager.disconnectServiceExtensionAbility(this.context, connectId);
      console.info(`${TAG} disconnect end:${connectId}`);
    } catch (err) {
      console.error(`${TAG} client disconnectServiceExtensionAbility failed.`);
    }
  }
}
```