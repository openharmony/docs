# @ohos.app.agent.agentManager (Agent智能组件管理)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

agentManager模块提供Agent管理能力，支持AgentExtensionAbility的连接、断开连接等操作，支持LOW_CODE类型Agent的生命周期管理，支持AgentExtensionAbility与ServiceExtensionAbility的连接管理，同时提供获取设备上的AgentCard信息。

> **说明：**
>
> 本模块首批接口从API version 24开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口均为系统接口。

## 导入模块

```ts
import { agentManager } from '@kit.AbilityKit';
```

## agentManager.getAllAgentCards

getAllAgentCards(): Promise\<Array\<AgentCard>>

获取设备上所有的AgentCard。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.GET_AGENT_CARD

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**系统接口**：此接口为系统接口。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise<Array<[AgentCard](./js-apis-inner-application-AgentCard.md#agentcard-1)>> | Promise对象，返回设备上所有的AgentCard数组。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |

**示例：**

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

获取指定应用的所有AgentCard。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.GET_AGENT_CARD

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | AgentCard所属的bundle名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise<Array<[AgentCard](./js-apis-inner-application-AgentCard.md#agentcard-1)>> | Promise对象，返回指定bundleName内的所有AgentCard数组。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 18500001 | The bundle does not exist or no patch has been applied. |

**示例：**

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

获取指定应用agentId对应的AgentCard。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.GET_AGENT_CARD

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | AgentCard所属的bundle名称。 |
| agentId | string | 是 | AgentCard所属的agentId。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise<[AgentCard](./js-apis-inner-application-AgentCard.md#agentcard-1)> | Promise对象，返回指定的AgentCard。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 18500001 | The bundle does not exist or no patch has been applied. |
| 35600001 | The specified agentId does not exist. |

**示例：**

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

将当前调用方组件连接到[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)。通过返回的[AgentProxy](js-apis-inner-application-agentProxy-sys.md)与[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)进行通信，以使用AgentExtensionAbility对外提供的能力。

> **说明：**
>
> - 当目标Agent的AgentCard为[LOW_CODE](js-apis-app-agent-agentConstant-sys.md#agentconstantagentcardtype)类型时，AgentExtensionAbility的[onConnect](js-apis-app-agent-agentExtensionAbility.md#onconnect)只在此类Agent连接成功时回调；后续连接的此类Agent，只回调[onAgentInvoked](js-apis-app-agent-agentExtensionAbility-sys.md#onagentinvoked)。
>
> - 同一个AgentExtensionAbility中，最多只能同时运行100个LOW_CODE类型的Agent，否则会报35600003错误码。
>
> - 同一个AgentExtensionAbility中，不允许重复连接同一个LOW_CODE类型的Agent。

**系统接口**：该接口为系统接口。

**模型约束**： 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.CONNECT_AGENT

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明           |
| -------- | ------------------------------------- | ---- | ------------ |
| want     | [Want](js-apis-app-ability-want.md)   | 是   | [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)所属的Want信息，通常需要包括bundle名称、ability名称。 |
| agentId  | string                                | 是   | [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)所属的agentId。 |
| callback | [AgentExtensionConnectCallback](js-apis-inner-application-agentExtensionConnectCallback-sys.md) | 是   | 连接回调函数，包含接收[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)服务端的数据、安全认证数据以及断开连接事件的回调接口。 |

**返回值：**

| 类型                       | 说明                         |
| -------------------------- | ---------------------------- |
| Promise\<[AgentProxy](js-apis-inner-application-agentProxy-sys.md)> | Promise对象，返回的AgentProxy对象，用于从客户端向AgentExtensionAbility服务端发送数据或安全认证请求。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
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

**示例：**

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
        // 创建连接按钮
        Button('connect ability')
          .enabled(true)
          .onClick(() => {
            let connectWant: Want = {
              bundleName: 'com.acts.agentextensionability',
              abilityName: 'AgentExtAbility',
            };
            let agentId: string = 'test';
            try {
              // 连接AgentExtensionAbility
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

注册AgentCard到系统中，使系统能够识别和调用对应的AgentExtensionAbility。

系统会根据类型对appInfo进行校验：
- APP、LOW_CODE类型：校验bundle和ability是否存在，并验证ability是否为agent类型。
- ATOMIC_SERVICE类型：在原子化服务已安装时，校验ability是否存在，并验证ability是否为agent类型。

**起始版本：** 26.0.0

**系统接口**：此接口为系统接口。

**模型约束**： 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.MODIFY_AGENT_CARD

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名    | 类型                                              | 必填 | 说明           |
| --------- | ------------------------------------------------- | ---- | ------------ |
| agentCard | [AgentCard](./js-apis-inner-application-AgentCard.md#agentcard-1) | 是   | 要注册的AgentCard信息。 |

**返回值：**

| 类型            | 说明            |
| --------------- | --------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
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

**示例：**

```ts
import { agentManager, agentConstant, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let agentCard: common.AgentCard = {
  agentId: 'agent_001',
  name: '智能助手',
  description: '这是一个智能助手',
  version: '1.0.0',
  defaultInputModes: ['text/plain'],
  defaultOutputModes: ['text/plain'],
  skills: [{
    id: 'skill_001',
    name: '基础技能',
    description: '这是一个基础技能',
    tags: ['助手', '查询']
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

更新系统中已存在的AgentCard信息，当[SemVer版本](https://semver.org/)不低于当前已存在的AgentCard时执行覆盖更新。当SemVer版本相同时，系统优先保存通过[registerAgentCard](#agentmanagerregisteragentcard)或[updateAgentCard](#agentmanagerupdateagentcard)接口调用时传入的AgentCard。

系统会根据类型对appInfo进行校验：
- APP、LOW_CODE类型：校验bundle和ability是否存在，并验证ability是否为agent类型。
- ATOMIC_SERVICE类型：在原子化服务已安装时，校验ability是否存在，并验证ability是否为agent类型。

**起始版本：** 26.0.0

**系统接口**：此接口为系统接口。

**模型约束**： 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.MODIFY_AGENT_CARD

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名    | 类型                                              | 必填 | 说明           |
| --------- | ------------------------------------------------- | ---- | ------------ |
| agentCard | [AgentCard](./js-apis-inner-application-AgentCard.md#agentcard-1) | 是   | 要更新的AgentCard信息。 |

**返回值：**

| 类型            | 说明            |
| --------------- | --------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
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

**示例：**

```ts
import { agentManager, agentConstant, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let agentCard: common.AgentCard = {
  agentId: 'agent_001',
  name: '智能助手',
  description: '这是更新后的智能助手',
  version: '1.0.1',
  defaultInputModes: ['text/plain'],
  defaultOutputModes: ['text/plain'],
  skills: [{
    id: 'skill_001',
    name: '基础技能',
    description: '这是一个基础技能',
    tags: ['助手', '查询']
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

删除指定应用agentId对应的AgentCard。

**起始版本：** 26.0.0

**系统接口**：此接口为系统接口。

**模型约束**： 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.MODIFY_AGENT_CARD

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                               |
| ---------- | ------ | ---- | ---------------------------------- |
| bundleName | string | 是   | 用于标识AgentCard所属的包名。              |
| agentId    | string | 是   | 用于标识AgentCard所属的agentId。          |

**返回值：**

| 类型            | 说明            |
| --------------- | --------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 35600001 | The specified agentId does not exist. |

**示例：**

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

断开与指定proxy的[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)的连接。

**系统接口**：此接口为系统接口。

**模型约束**： 此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.CONNECT_AGENT

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名 | 类型                                             | 必填 | 说明           |
| ------ | ------------------------------------------------ | ---- | ------------ |
| proxy  | [AgentProxy](js-apis-inner-application-agentProxy-sys.md) | 是   | 要断开连接的[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)对应的Proxy对象，在调用[connectAgentExtensionAbility](#agentmanagerconnectagentextensionability)接口连接[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)时会返回其对应的proxy对象。 |

**返回值：**

| 类型            | 说明            |
| --------------- | --------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |

**示例：**

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
        // 创建连接按钮
        Button('connect ability')
          .enabled(true)
          .onClick(() => {
            try {
              // 连接AgentExtensionAbility
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

通知指定的[LOW_CODE](js-apis-app-agent-agentConstant-sys.md#agentconstantagentcardtype)类型的AgentCard关联的Agent生命周期已结束。

**起始版本**：26.0.0

**系统接口**：该接口为系统接口。

**模型约束**：此接口仅可在Stage模型下使用。

**需要权限**：ohos.permission.CONNECT_AGENT

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                  |
| ------- | ------ | ---- | --------------------- |
| agentId | string | 是   | 用于标识AgentCard的agentId。 |

**返回值：**

| 类型            | 说明            |
| --------------- | --------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |
| 35600001 | The specified agentId does not exist. |

**示例：**

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

将AgentExtensionAbility连接到ServiceExtensionAbility。若目标ServiceExtensionAbility可见，可直接连接；若不可见，需申请`ohos.permission.START_INVISIBLE_ABILITY`权限；若目标ServiceExtensionAbility位于远程设备上，需申请`ohos.permission.DISTRIBUTED_DATASYNC`权限。

> **说明：**
>
> 该接口不支持在多线程和子进程中调用。在多线程中调用将引发CppCrash；在子进程中调用将返回16000050错误码。

**起始版本**：26.0.0

**系统接口**：该接口为系统接口。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                |
| -------- | ----------------------------------------------------------- | ---- | ----------------------------------- |
| context  | [AgentExtensionContext](js-apis-inner-application-agentExtensionContext.md) | 是   | 当前Agent扩展能力的上下文，包含AgentCard信息。    |
| want     | [Want](js-apis-app-ability-want.md)                          | 是   | 目标ServiceExtensionAbility的Want信息，包含bundleName、abilityName等。              |
| callback | [ConnectOptions](js-apis-inner-ability-connectOptions.md)      | 是   | ConnectOptions类型的回调函数，返回服务连接成功、连接失败、断开的信息。  |

**返回值：**

| 类型 | 说明 |
| ---- | ------------------------------------------------------------ |
| number | 返回一个连接ID，用于标识当前AgentExtensionAbility与ServiceExtensionAbility之间的连接。该连接ID可用于后续调用[disconnectServiceExtensionAbility](#agentmanagerdisconnectserviceextensionability)接口断开连接。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
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

**示例：**

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

断开AgentExtensionAbility与ServiceExtensionAbility的连接。

**起始版本**：26.0.0

**系统接口**：该接口为系统接口。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**参数**：

| 参数名     | 类型                                                        | 必填 | 说明                                           |
| ---------- | ----------------------------------------------------------- | ---- | ---------------------------------------------- |
| context    | [AgentExtensionContext](js-apis-inner-application-agentExtensionContext.md) | 是   | 当前Agent扩展能力的上下文，包含AgentCard信息。    |
| connectId  | number                                                        | 是   | [connectServiceExtensionAbility](#agentmanagerconnectserviceextensionability)返回的连接ID，用于标识要断开的目标连接。 |

**返回值：**

| 类型            | 说明            |
| --------------- | --------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 202      | Not system application. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. Possible causes: 1.Connect to system service failed. 2.System service failed to communicate with dependency module. |

**示例：**

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