# ConnectOptions

在连接指定的后台服务时作为入参，用于接收连接过程中的状态变化，如作为[connectServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#connectserviceextensionability)的入参，连接指定的ServiceExtensionAbility。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## ConnectOptions

### onConnect

onConnect(elementName: ElementName, remote: rpc.IRemoteObject): void

建立连接时的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | 是    | Ability的elementName。 |
| remote | [rpc.IRemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject) | 是    | IRemoteObject实例。 |

**示例：**

```ts
import { UIAbility, common, Want, AbilityConstant } from '@kit.AbilityKit';
import { bundleManager } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

let connectWant: Want = {
  bundleName: 'com.example.myapp',
  abilityName: 'MyAbility'
};

let connectOptions: common.ConnectOptions = {
  onConnect(elementName: bundleManager.ElementName, remote: rpc.IRemoteObject) {
    console.log(`onConnect elementName: ${elementName}`);
  },
  onDisconnect(elementName: bundleManager.ElementName) {
    console.log(`onDisconnect elementName: ${elementName}`);
  },
  onFailed(code: number) {
    console.error(`onFailed code: ${code}`);
  }
};

class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let connection: number = this.context.connectServiceExtensionAbility(connectWant, connectOptions);
  }
}
```

### onDisconnect

onDisconnect(elementName: ElementName): void

断开连接时的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | 是    | Ability的elementName。 |

**示例：**

```ts
import { UIAbility, common, Want, AbilityConstant } from '@kit.AbilityKit';
import { bundleManager } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

let connectWant: Want = {
  bundleName: 'com.example.myapp',
  abilityName: 'MyAbility'
};

let connectOptions: common.ConnectOptions = {
  onConnect(elementName: bundleManager.ElementName, remote: rpc.IRemoteObject) {
    console.log(`onConnect elementName: ${elementName}`);
  },
  onDisconnect(elementName: bundleManager.ElementName) {
    console.log(`onDisconnect elementName: ${elementName}`);
  },
  onFailed(code: number) {
    console.error(`onFailed code: ${code}`);
  }
};

class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let connection: number = this.context.connectServiceExtensionAbility(connectWant, connectOptions);
  }
}
```

### onFailed

onFailed(code: number): void

连接失败时的回调函数。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| code | number | 是    | 连接指定Ability返回的结果code。<br>值为0表示连接成功，值为-1表示参数错误，值为-2表示未找到对应Ability。 |

**示例：**

```ts
import { UIAbility, common, Want, AbilityConstant } from '@kit.AbilityKit';
import { bundleManager } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

let connectWant: Want = {
  bundleName: 'com.example.myapp',
  abilityName: 'MyAbility'
};

let connectOptions: common.ConnectOptions = {
  onConnect(elementName: bundleManager.ElementName, remote: rpc.IRemoteObject) {
    console.log(`onConnect elementName: ${elementName}`);
  },
  onDisconnect(elementName: bundleManager.ElementName) {
    console.log(`onDisconnect elementName: ${elementName}`);
  },
  onFailed(code: number) {
    console.error(`onFailed code: ${code}`);
  }
};

class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let connection: number = this.context.connectServiceExtensionAbility(connectWant, connectOptions);
  }
}
```
