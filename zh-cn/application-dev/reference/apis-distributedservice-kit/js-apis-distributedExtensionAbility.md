# @ohos.application.DistributedExtensionAbility (协同Extension)

DistributedExtensionAbility模块提供分布式相关扩展能力，提供分布式创建、销毁、连接的生命周期回调。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { DistributedExtensionAbility} from '@kit.DistributedServiceKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称    | 类型                          | 可读 | 可写 | 说明                                                       |
| ------- | ----------------------------- | ---- | ---- | ---------------------------------------------------------- |
| context | DistributedExtensionContext() | 是   | 否   | DistributedExtension的上下文环境，继承自ExtensionContext。 |

## DistributedExtensionAbility.onCreate

onCreate(want: Want): void

Extension生命周期回调，在创建时回调，执行初始化业务逻辑操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名     | 类型 | 必填                                                             | 说明 |
| ----------| ---- | ---------------------------------------------------------------- | ---- |
| want      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 当前Extension相关的Want类型信息，包括ability名称、bundle名称等。 |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { DistributedExtensionAbility } from '@kit.DistributedServiceKit';

class MyDistributedExtensionAbility extends DistributedExtensionAbility {
   onCreate(want: Want) {
       console.info(`DistributedExterntion Create ok`);
       console.info(`DistributedExterntionon onCollabRequest ${JSON.stringify(want)}`);
       console.info(`DistributedExterntionon Create end`);
  }
}
```

## DistributedExtensionAbility.onCollaborate

onCollaborate(wantParam: Record <string, Object>) : AbilityConstant.CollaborateResult

多设备协作场景下返回协作结果的回调。

**系统功能**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名    | 类型   | 必填 | 说明                                                                                                                                   |
| --------- | ------ | ---- | -------------------------------------------------------------------------------------------------------------------------------------- |
| wantParam | Record <string, Object> | 是   | want相关参数，仅支持key值取"ohos.extra.param.key.supportCollaborateIndex"。通过该key值可以可以获取到调用方传输的数据并进行相应的处理。 |

**返回值：**

| 类型 | 说明 |
| ---------- | ---- |
| [AbilityConstant.CollaborateResult](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md#collaborateresult) | 协同方应用是否接受协同。 |

**示例**

```ts
import { DistributedExtensionAbility } from '@kit.DistributedServiceKit';
import { AbilityConstant } from '@kit.AbilityKit';

class MyDistributedExtensionAbility extends DistributedExtensionAbility  {
    onCollaborate(wantParam: Record<string, Object>)  {
        console.info(`DistributedExterntionon onCollabRequest Accept to the result of Ability collaborate`);
        let sessionId = -1;
        const collabrationType = wantParam["CollabrationType"] as abilityConnectionManager.CollabrationType;
        if (collabrationType == undefined) {
            return sessionId;
        }
        console.info(`onCollab, peerInfo: ${JSON.stringify(collabrationType)}`);
        return AbilityConstant.CollaborateResult.ACCEPT;
  }
}
```

## DistributedExtensionAbility.onDestroy

onDestroy(): void

Extension生命周期回调，在销毁时回调，执行资源清理等操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**示例：**

```ts
import { DistributedExtensionAbility } from '@kit.DistributedServiceKit';

class MyDistributedExtensionAbility extends DistributedExtensionAbility {
  onDestroy() {
    console.info('DistributedExterntion onDestroy ok');
  }
}
```
