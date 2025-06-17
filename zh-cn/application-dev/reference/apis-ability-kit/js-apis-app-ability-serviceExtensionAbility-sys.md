# @ohos.app.ability.ServiceExtensionAbility (ServiceExtensionAbility)(系统接口)

ServiceExtensionAbility模块提供后台服务相关扩展能力，提供后台服务创建、销毁、连接、断开等生命周期回调。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块为系统接口。

## 导入模块

```ts
import { ServiceExtensionAbility } from '@kit.AbilityKit';
```

## 权限

无

## ServiceExtensionAbility

### 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext-sys.md)  | 否 | 否 | ServiceExtension的上下文环境，继承自ExtensionContext。 |


### onCreate

onCreate(want: Want): void;

Extension生命周期回调，在创建时回调，执行初始化业务逻辑操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |

**示例：**

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onCreate(want: Want) {
    console.info(`onCreate, want: ${want.abilityName}`);
  }
}
```


### onDestroy

onDestroy(): void;

Extension生命周期回调，在销毁时回调，执行资源清理等操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**示例：**

```ts
import { ServiceExtensionAbility } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onDestroy() {
    console.info('onDestroy');
  }
}
```


### onRequest

onRequest(want: Want, startId: number): void;

Extension生命周期回调，如果是startAbility或者startServiceExtensionAbility拉起的服务，会在onCreate之后回调。每次拉起服务都会回调，startId会递增。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |
| startId | number | 是 | 返回拉起次数。首次拉起初始值返回1，多次之后自动递增。 |

**示例：**

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onRequest(want: Want, startId: number) {
    console.info('onRequest, want: ${want.abilityName}');
  }
}
```


### onConnect

onConnect(want: Want): rpc.RemoteObject | Promise<rpc.RemoteObject>;

Extension生命周期回调，如果是connectAbility拉起的服务，会在onCreate之后回调。返回一个RemoteObject对象，用于客户端和服务端进行通信。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md)| 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) \| Promise\<[rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)> | 返回RemoteObject对象或带有RemoteObject对象的Promise对象，用于客户端和服务端进行通信。 |

**示例：**

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

class StubTest extends rpc.RemoteObject{
  constructor(des: string) {
    super(des);
  }
  onConnect(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption) {
  }
}
class ServiceExt extends ServiceExtensionAbility {
  onConnect(want: Want) {
    console.info('onConnect , want: ${want.abilityName}');
    return new StubTest('test');
  }
}
```

如果生成返回值RemoteObject依赖一个异步接口，可以使用异步生命周期：

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

class StubTest extends rpc.RemoteObject{
  constructor(des: string) {
    super(des);
  }
  onConnect(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption) {
  }
}
async function getDescriptor() {
  // 调用异步函数...
  return "asyncTest"
}
class ServiceExt extends ServiceExtensionAbility {
  async onConnect(want: Want) {
    console.info(`onConnect , want: ${want.abilityName}`);
    let descriptor = await getDescriptor();
    return new StubTest(descriptor);
  }
}
```

### onDisconnect

onDisconnect(want: Want): void | Promise\<void>;

Extension的生命周期回调，客户端执行断开连接服务时回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md)| 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onDisconnect(want: Want) {
    console.info('onDisconnect, want: ${want.abilityName}');
  }
}
```

在执行完onDisconnect生命周期回调后，应用可能会退出，从而可能导致onDisconnect中的异步函数未能正确执行，比如异步写入数据库。可以使用异步生命周期，以确保异步onDisconnect完成后再继续后续的生命周期。

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  async onDisconnect(want: Want) {
    console.info('onDisconnect, want: ${want.abilityName}');
    // 调用异步函数...
  }
}
```

### onReconnect

onReconnect(want: Want): void;

Extension的生命周期回调，当所有以前的客户端都断开连接之后，新客户端尝试连接到服务时调用。预留能力，当前暂未支持。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md)| 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |

**示例：**

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onReconnect(want: Want) {
    console.info('onReconnect, want: ${want.abilityName}');
  }
}
```

### onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void;

当Extension更新配置信息时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| newConfig | [Configuration](js-apis-app-ability-configuration.md) | 是 | 表示需要更新的配置信息。 |

**示例：**
    
```ts
import { ServiceExtensionAbility, Configuration } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onConfigurationUpdate(newConfig: Configuration) {
    console.info(`onConfigurationUpdate, config: ${JSON.stringify(newConfig)}`);
  }
}
```

### onDump

onDump(params: Array\<string>): Array\<string>;

转储客户端信息时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| params | Array\<string> | 是 | 表示命令形式的参数。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array\<string> | 表示转存客户端信息数组。 |

**示例：**
    
```ts
import { ServiceExtensionAbility } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onDump(params: Array<string>) {
    console.info(`dump, params: ${JSON.stringify(params)}`);
    return ['params'];
  }
}
```
