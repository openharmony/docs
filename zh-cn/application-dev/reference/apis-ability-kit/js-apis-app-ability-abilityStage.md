# @ohos.app.ability.AbilityStage 组件管理器

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

AbilityStage是一个[Module](../../../application-dev/quick-start/application-package-overview.md#应用的多module设计机制)级别的组件管理器，用于进行Module级别的资源预加载、线程创建等初始化操作，以及维护Module下的应用状态。AbilityStage与Module一一对应，即一个Module拥有一个AbilityStage。

应用的[HAP](../../../application-dev/quick-start/hap-package.md)/[HSP](../../../application-dev/quick-start/in-app-hsp.md)在首次加载时会创建一个AbilityStage实例。当一个Module中存在AbilityStage和其他组件（UIAbility/ExtensionAbility组件），AbilityStage实例会早于其他组件实例创建。

AbilityStage拥有[onCreate()](#oncreate)、[onDestroy()](#ondestroy12)生命周期回调和[onAcceptWant()](#onacceptwant)、[onConfigurationUpdate()](#onconfigurationupdate)、[onMemoryLevel()](#onmemorylevel)事件回调等。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { AbilityStage } from '@kit.AbilityKit';
```

## AbilityStage

### 属性

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context  | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | 否 | 否 | AbilityStage上下文。 |

### onCreate

onCreate(): void

在加载Module的第一个Ability实例前，系统会先创建对应的AbilityStage实例，并在AbilityStage创建完成后，自动触发该回调。

开发者可以在该回调中执行Module的初始化操作（如资源预加载、线程创建等）。同步接口，不支持异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**示例：**

```ts
import { AbilityStage } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onCreate() {
    console.log('MyAbilityStage.onCreate is called');
  }
}
```


### onAcceptWant

onAcceptWant(want: Want): string

当启动模式配置为[specified](../../application-models/uiability-launch-type.md#specified启动模式)的UIAbility被拉起时，会触发该回调，并返回一个string作为待启动的UIAbility实例的唯一标识。同步接口，不支持异步回调。

如果系统中已经有相同标识的UIAbility实例存在，则复用已有实例，否则创建新的实例。

> **说明：**
>
> 从API version 20开始，当[AbilityStage.onAcceptWantAsync](#onacceptwantasync20)实现时，本回调函数将不会被触发。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，此处表示调用方传入的启动参数，如Ability名称，Bundle名称等。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回开发者自定义的UIAbility标识。如果已经启动了相同标识的UIAbility，则复用该UIAbility，否则创建新的实例并启动。 |

**示例：**


```ts
import { AbilityStage, Want } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onAcceptWant(want: Want) {
    console.log('MyAbilityStage.onAcceptWant called');
    return 'com.example.test';
  }
}
```

### onNewProcessRequest<sup>11+</sup>

onNewProcessRequest(want: Want): string

如果UIAbility或UIExtensionAbility配置了在独立进程中运行（即[module.json5配置文件](../../quick-start/module-configuration-file.md)中UIAbility或UIExtensionAbility的isolationProcess字段取值为true），当该UIAbility或UIExtensionAbility被拉起时，会触发该回调，并返回一个string作为进程唯一标识。同步接口，不支持异步回调。

如果该应用已有相同标识的进程存在，则待启动的UIAbility或UIExtensionAbility运行在此进程中，否则创建新的进程。

如果开发者同时实现onNewProcessRequest和[onAcceptWant](#onacceptwant)，将先收到onNewProcessRequest回调，再收到onAcceptWant回调。

<!--Del-->
仅支持sys/commonUI类型的UIExtensionAbility组件在[module.json5配置文件](../../quick-start/module-configuration-file.md)配置文件中配置isolationProcess字段为true。
<!--DelEnd-->

> **说明：**
>
> - 在API version 19及之前版本，仅支持在指定进程中启动UIAbility。从API version 20开始，新增支持在指定进程中启动UIExtensionAbility。
> - 从API version 20开始，当[AbilityStage.onNewProcessRequestAsync](#onnewprocessrequestasync20)实现时，本回调函数将不执行。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口仅在2in1和Tablet设备中可正常执行回调，在其他设备上不执行回调。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，此处表示调用方传入的启动参数，如UIAbility或UIExtensionAbility名称、Bundle名称等。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回一个由开发者自行决定的进程字符串标识，如果之前此标识对应的进程已被创建，就让ability在此进程中运行，否则创建新的进程。 |

**示例：**

```ts
import { AbilityStage, Want } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onNewProcessRequest(want: Want) {
    console.log('MyAbilityStage.onNewProcessRequest called');
    return 'com.example.test';
  }
}
```


### onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void

当系统全局配置（例如系统语言、深浅色等）发生变更时，会触发该回调。配置项均定义在[Configuration](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-configuration.md)类中。同步接口，不支持异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | newConfig | [Configuration](js-apis-app-ability-configuration.md) | 是 | 发生全局配置变更时触发回调，当前全局配置包括系统语言、深浅色模式。 |

**示例：**

```ts
import { AbilityStage, Configuration } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onConfigurationUpdate(config: Configuration) {
    console.log(`MyAbilityStage.onConfigurationUpdate, language: ${config.language}`);
  }
}
```

### onMemoryLevel

onMemoryLevel(level: AbilityConstant.MemoryLevel): void

该接口用于监听系统内存状态变化。当整机可用内存变化到指定程度时，系统会触发该回调。开发者可通过实现此接口，在收到内存紧张事件时，及时释放非必要资源（如缓存数据、临时对象等），以避免应用进程被系统强制终止。

同步接口，不支持异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | level | [AbilityConstant.MemoryLevel](js-apis-app-ability-abilityConstant.md#memorylevel) | 是 | 回调返回内存微调级别，显示当前内存使用状态。<br>**说明：**<br>不同产品的触发条件可能存在差异。以12G内存的标准设备为例：<br>- 当可用内存下降至1700M~1800M时，会触发取值为0的onMemoryLevel回调。<br>- 当可用内存下降至1600M~1700M时，会触发取值为1的onMemoryLevel回调。<br>- 当可用内存下降至1600M以下时，会触发取值为2的onMemoryLevel回调。|

**示例：**

```ts
import { AbilityStage, AbilityConstant } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onMemoryLevel(level: AbilityConstant.MemoryLevel) {
    console.log(`MyAbilityStage.onMemoryLevel, level: ${JSON.stringify(level)}`);
  }
}
```

### onDestroy<sup>12+<sup>

onDestroy(): void

在对应Module的最后一个Ability实例退出后会触发该回调。此方法将在正常的调度生命周期中调用，当应用程序异常退出或被终止时，将不会调用此方法。同步接口，不支持异步回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**示例：**

```ts
import { AbilityStage } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onDestroy() {
    console.log('MyAbilityStage.onDestroy is called');
  }
}
```

### onPrepareTermination<sup>15+<sup>

onPrepareTermination(): AbilityConstant.PrepareTermination

当应用被用户关闭时调用，可用于询问用户选择立即执行操作还是取消操作。同步接口，不支持异步回调。

> **说明：**
>
> - 仅当应用正常退出（例如，通过doc栏/托盘关闭应用，或者应用随设备关机而退出）时会调用该接口。如果应用被强制关闭，则不会调用该接口。
>
> - 当[AbilityStage.onPrepareTerminationAsync](#onprepareterminationasync15)实现时，本回调函数将不执行。

**需要权限**：ohos.permission.PREPARE_APP_TERMINATE

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：
- 从API version 15开始，该接口仅在2in1设备中可正常执行回调，在其他设备上不执行回调。
- 从API version 19开始，该接口仅在2in1和Tablet设备中可正常执行回调，在其他设备上不执行回调。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [AbilityConstant.PrepareTermination](js-apis-app-ability-abilityConstant.md#preparetermination15) | 用于返回用户的选择结果。 |

**示例：**

```ts
import { AbilityConstant, AbilityStage } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onPrepareTermination(): AbilityConstant.PrepareTermination {
    console.info('MyAbilityStage.onPrepareTermination is called');
    return AbilityConstant.PrepareTermination.CANCEL;
  }
}
```

### onPrepareTerminationAsync<sup>15+<sup>

onPrepareTerminationAsync(): Promise\<AbilityConstant.PrepareTermination>

当应用被用户关闭时调用，可用于询问用户选择立即执行操作还是取消操作。使用Promise异步回调。

> **说明：**
>
> - 仅当应用正常退出（例如，通过doc栏/托盘关闭应用，或者应用随设备关机而退出）时会调用该接口。如果应用被强制关闭，则不会调用该接口。
>
> - 若异步回调内发生crash，按超时处理，执行等待超过10秒未响应，应用将被强制关闭。

**需要权限**：ohos.permission.PREPARE_APP_TERMINATE

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：
- 从API version 15开始，该接口仅在2in1设备中可正常执行回调，在其他设备上不执行回调。
- 从API version 19开始，该接口仅在2in1和Tablet设备中可正常执行回调，在其他设备上不执行回调。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<[AbilityConstant.PrepareTermination](js-apis-app-ability-abilityConstant.md#preparetermination15)> | Promise对象，返回用户的选择结果。 |

**示例：**

```ts
import { AbilityConstant, AbilityStage } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  async onPrepareTerminationAsync(): Promise<AbilityConstant.PrepareTermination> {
    await new Promise<AbilityConstant.PrepareTermination>((res, rej) => {
      setTimeout(res, 3000); // 延时3秒后执行
    });
    return AbilityConstant.PrepareTermination.CANCEL;
  }
}
```

### onAcceptWantAsync<sup>20+</sup>

onAcceptWantAsync(want: Want): Promise\<string\>

当启动模式配置为[specified](../../application-models/uiability-launch-type.md#specified启动模式)的UIAbility被拉起时，会触发该回调，并返回一个string作为待启动的UIAbility实例的唯一标识。使用Promise异步回调。

如果系统中已经有相同标识的UIAbility实例存在，则复用已有实例，否则创建新的实例。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的UIAbility的信息，如UIAbility名称、Bundle名称等。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise\<string\> | Promise对象，返回一个string作为待启动的UIAbility实例的唯一标识。如果系统中已经有该标识的UIAbility实例存在，则复用已有实例，否则创建新的实例。 |

**示例：**

```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  async onAcceptWantAsync(): Promise<string> {
    await new Promise<string>((res, rej) => {
      setTimeout(res, 1000); // 延时1秒后执行
    });
    return 'default';
  }
}
```

### onNewProcessRequestAsync<sup>20+</sup>

onNewProcessRequestAsync(want: Want): Promise\<string\>

如果UIAbility或UIExtensionAbility配置了在独立进程中运行（即[module.json5配置文件](../../quick-start/module-configuration-file.md)中UIAbility或UIExtensionAbility的isolationProcess字段取值为true），当该UIAbility或UIExtensionAbility被拉起时，会触发该回调，并返回一个string作为进程唯一标识。使用Promise异步回调。

如果该应用已有相同标识的进程存在，则待启动的UIAbility或UIExtensionAbility运行在此进程中，否则创建新的进程。

<!--Del-->
仅支持sys/commonUI类型的UIExtensionAbility组件在[module.json5配置文件](../../quick-start/module-configuration-file.md)中配置isolationProcess字段为true。
<!--DelEnd-->

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口仅在2in1和Tablet设备中可正常执行回调，在其他设备上不执行回调。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，此处表示调用方传入的启动参数，如UIAbility或UIExtensionAbility名称、Bundle名称等。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<string\> | Promise对象，返回一个由开发者自定义的进程字符串标识。如果该应用已有相同标识的进程存在，则UIAbility或UIExtensionAbility在此进程中运行，否则创建新的进程。 |

**示例：**

```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  async onNewProcessRequestAsync(): Promise<string> {
    await new Promise<string>((res, rej) => {
      setTimeout(res, 1000); // 延时1秒后执行
    });
    return '';
  }
}
```
