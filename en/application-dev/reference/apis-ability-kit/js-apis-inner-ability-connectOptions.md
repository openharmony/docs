# ConnectOptions
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yewei0794-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

**ConnectOptions** can be used as an input parameter to receive status changes during the connection to a background service. For example, it is used as an input parameter of [connectServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#connectserviceextensionability) to connect to a ServiceExtensionAbility.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## ConnectOptions

### onConnect

onConnect(elementName: ElementName, remote: rpc.IRemoteObject): void

Callback invoked when a connection is set up.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | Yes   | Element name of the ability.|
| remote | [rpc.IRemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject) | Yes   | IRemoteObject instance.|

**Example**

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

Callback invoked when a connection is interrupted.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | Yes   | Element name of the ability.|

**Example**

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

Callback invoked when a connection fails.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| code | number | Yes   | Result code.<br>The value **0** means that the connection is successful, **-1** means that a parameter is incorrect, and **-2** means that the ability is not found.|

**Example**

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
