# InputMethodExtensionAbility

InputMethodExtensionAbility模块，提供生态输入法应用开发者通过InputMethodExtensionAbility、InputMethodExtensionContext接口创作输入法应用，并管理输入法应用生命周期。

> **说明：**
> 
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```
import InputMethodExtensionAbility from '@ohos.inputmethodextensionability';
```

## 属性

**系统能力**：SystemCapability.MiscServices.InputMethodFramework

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context | [InputMethodExtensionContext](js-apis-inputmethod-extension-context.md) | 是 | 否 | InputMethodExtension的上下文环境，继承自ExtensionContext。 |


## InputMethodExtensionAbility.onCreate()

onCreate(want: Want): void

Extension生命周期回调，在拉起Extension输入法应用时调用，执行初始化输入法应用操作。

**模型约束**： 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.MiscServices.InputMethodFramework

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want |  [Want](js-apis-application-Want.md) | 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 | 

**示例：**

```ts
class InputMethodExt extends InputMethodExtensionAbility {
    onCreate(want) {
        console.log('onCreate, want:' + want.abilityName);
    }
}
```


## InputMethodExtensionAbility.onDestroy()

onDestroy(): void

Extension生命周期回调，在销毁输入法应用时回调，执行资源清理等操作。

**模型约束**： 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.MiscServices.InputMethodFramework

**示例：**

```ts
class InputMethodExt extends InputMethodExtensionAbility {
    onDestroy() {
        console.log('onDestroy');
    }
}
```

## InputMethodExtensionAbility.onRequest()

onRequest(want: Want, startId: number): void

Extension生命周期回调，在一个输入法extention开始时回调，执行输入法的相关操作。

**模型约束**： 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.MiscServices.InputMethodFramework

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want |  [Want](js-apis-application-Want.md) | 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 | 
  | startId | number | 是 | 返回拉起次数。首次拉起初始值返回1，多次之后自动递增。 |

**示例：**

```ts
class InputMethodExt extends InputMethodExtensionAbility {
    onRequest(want, startId) {
        console.log('onRequest, want:' + want.abilityName + 'startId:' + startId);
    }
}
```

## InputMethodExtensionAbility.onConnect()

onConnect(want: Want): rpc.RemoteObject

Extension生命周期回调，在输入法extention首次连接输入法ability时回调。

**模型约束**： 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.MiscServices.InputMethodFramework

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want |  [Want](js-apis-application-Want.md) | 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 | 

**返回值**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| rpc.RemoteObject |  一个RemoteObject对象，用于和客户端进行通信。   |

**示例：**

```ts
import rpc from '@ohos.rpc'
class StubTest extends rpc.RemoteObject{
    constructor(des) {
        super(des);
    }
    onConnect(code, data, reply, option) {
    }
}
class ServiceExt extends ServiceExtension {
    onConnect(want) {
        console.log('onConnect , want:' + want.abilityName);
        return new StubTest("test");
    }
}
```

## InputMethodExtensionAbility.onDisconnect()

onDisconnect(want: Want): void

Extension生命周期回调，在所有连接在输入法extention上的ability都断开的时候回调。

**模型约束**： 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.MiscServices.InputMethodFramework

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want |  [Want](js-apis-application-Want.md) | 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 | 

**示例：**

```ts
class InputMethodExt extends InputMethodExtensionAbility {
    onDisconnect(want) {
        console.log('onDisconnect, want:' + want.abilityName);
    }
}
```

## InputMethodExtensionAbility.onReconnect()

onReconnect(want: Want): void

Extension生命周期回调，在一个新的客户端去尝试连接输入法extention的时候回调（先前连接在extention上的客户端全部断开的情况下）。

**模型约束**： 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.MiscServices.InputMethodFramework

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want |  [Want](js-apis-application-Want.md) | 是 | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 | 

**示例：**

```ts
class InputMethodExt extends InputMethodExtensionAbility {
    onReconnect(want) {
        console.log('onReconnect, want:' + want.abilityName);
    }
}
```

