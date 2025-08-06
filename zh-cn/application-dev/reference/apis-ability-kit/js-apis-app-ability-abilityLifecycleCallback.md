# @ohos.app.ability.abilityLifecycleCallback (UIAbility生命周期回调监听器)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wkljy; @xuzhihao666-->
<!--SE: @ccllee1-->
<!--TSE: @lixueqing513-->

AbilityLifecycleCallback类提供监听[UIAbility](js-apis-app-ability-uiAbility.md)生命周期变化的能力。应用创建AbilityLifecycleCallback对象，调用接口[ApplicationContext.on('abilityLifecycle')](js-apis-inner-application-applicationContext.md#applicationcontextonabilitylifecycle)注册生命周期变化监听。

[UIAbility](js-apis-app-ability-uiAbility.md)的[生命周期](../../application-models/uiability-lifecycle.md)管理UIAbility从创建到销毁的全过程。UIAbility运行过程中状态发生变化时，UIAbility对应的生命周期函数被执行。AbilityLifecycleCallback则提供一种方式，让应用可以在UIAbility外部监听UIAbility的生命周期变化。</br>
这些场景适合使用生命周期监听：作为全局监听器，统计应用内每个UIAbility页面时长；做生命周期相关数据加载，但是和UIAbility业务逻辑解耦；应用使用生命周期监听机制对外提供SDK，通知其他模块应用状态变化。</br>
具体使用流程如下：
1. 应用创建AbilityLifecycleCallback对象，然后调用接口[ApplicationContext.on('abilityLifecycle')](js-apis-inner-application-applicationContext.md#applicationcontextonabilitylifecycle)注册生命周期变化监听。
2. 系统调度UIAbility生命周期，并通知[ApplicationContext](js-apis-inner-application-applicationContext.md)相关UIAbility的生命周期变化。
3. ApplicationContext收到UIAbility生命周期的变化通知，调用应用注册进来的AbilityLifecycleCallback监听回调函数。
4. 不需要监听UIAbility生命周期变化时，应用通过[ApplicationContext.off('abilityLifecycle')](js-apis-inner-application-applicationContext.md#applicationcontextoffabilitylifecycle)接口取消监听。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口只能监听进程内UIAbility生命周期变化。

## 导入模块

```ts
import { AbilityLifecycleCallback } from '@kit.AbilityKit';
```

## AbilityLifecycleCallback

### onAbilityCreate

onAbilityCreate(ability: UIAbility): void

在UIAbility的[onCreate](js-apis-app-ability-uiAbility.md#oncreate)触发后回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onWindowStageCreate

onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility的[onWindowStageCreate](js-apis-app-ability-uiAbility.md#onwindowstagecreate)触发后回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility主窗管理器。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onWindowStageActive

onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility主窗获焦时触发回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility主窗管理器。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onWindowStageInactive

onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility主窗失焦时触发回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility主窗管理器。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onWindowStageDestroy

onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility的[onWindowStageDestroy](js-apis-app-ability-uiAbility.md#onwindowstagedestroy)触发后回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility主窗管理器。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onAbilityDestroy

onAbilityDestroy(ability: UIAbility): void

在UIAbility的[onDestroy](js-apis-app-ability-uiAbility.md#ondestroy)触发后回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onAbilityForeground

onAbilityForeground(ability: UIAbility): void

在UIAbility的[onForeground](js-apis-app-ability-uiAbility.md#onforeground)触发后回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onAbilityBackground

onAbilityBackground(ability: UIAbility): void

在UIAbility的[onBackground](js-apis-app-ability-uiAbility.md#onbackground)触发后回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onAbilityContinue

onAbilityContinue(ability: UIAbility): void

在UIAbility的[onContinue](js-apis-app-ability-uiAbility.md#oncontinue)触发后回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onAbilityWillCreate<sup>12+</sup>

onAbilityWillCreate?(ability: UIAbility): void

在UIAbility的[onCreate](js-apis-app-ability-uiAbility.md#oncreate)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onWindowStageWillCreate<sup>12+</sup>

onWindowStageWillCreate?(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility的[onWindowStageCreate](js-apis-app-ability-uiAbility.md#onwindowstagecreate)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility主窗管理器。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onWindowStageWillDestroy<sup>12+</sup>

onWindowStageWillDestroy?(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility的[onWindowStageDestroy](js-apis-app-ability-uiAbility.md#onwindowstagedestroy)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility主窗管理器。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onAbilityWillForeground<sup>12+</sup>

onAbilityWillForeground?(ability: UIAbility): void

在UIAbility的[onForeground](js-apis-app-ability-uiAbility.md#onforeground)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onAbilityWillDestroy<sup>12+</sup>

onAbilityWillDestroy?(ability: UIAbility): void

在UIAbility的[onDestroy](js-apis-app-ability-uiAbility.md#ondestroy)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onAbilityWillBackground<sup>12+</sup>

onAbilityWillBackground?(ability: UIAbility): void

在UIAbility的[onBackground](js-apis-app-ability-uiAbility.md#onbackground)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onWillNewWant<sup>12+</sup>

onWillNewWant?(ability: UIAbility): void

在UIAbility的[onNewWant](js-apis-app-ability-uiAbility.md#onnewwant)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onNewWant<sup>12+</sup>

onNewWant?(ability: UIAbility): void

在UIAbility的[onNewWant](js-apis-app-ability-uiAbility.md#onnewwant)触发后回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onAbilityWillContinue<sup>12+</sup>

onAbilityWillContinue?(ability: UIAbility): void

在UIAbility的[onContinue](js-apis-app-ability-uiAbility.md#oncontinue)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onWindowStageWillRestore<sup>12+</sup>

onWindowStageWillRestore?(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility的[onWindowStageRestore](js-apis-app-ability-uiAbility.md#onwindowstagerestore)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility主窗管理器。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onWindowStageRestore<sup>12+</sup>

onWindowStageRestore?(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility的[onWindowStageRestore](js-apis-app-ability-uiAbility.md#onwindowstagerestore)触发后回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility主窗管理器。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onAbilityWillSaveState<sup>12+</sup>

onAbilityWillSaveState?(ability: UIAbility): void

在UIAbility的[onSaveState](js-apis-app-ability-uiAbility.md#onsavestate)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### onAbilitySaveState<sup>12+</sup>

onAbilitySaveState?(ability: UIAbility): void

在UIAbility的[onSaveState](js-apis-app-ability-uiAbility.md#onsavestate)触发后回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象。 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

### AbilityLifecycleCallback使用

**示例：**

AbilityLifecycleCallback提供在UIAbility外部监听UIAbility生命周期的能力，比如应用可以在[AbilityStage](../../application-models/abilitystage.md)加载的时候注册监听，这样能监听到应用内所有UIAbility的状态变化。示例代码展示在[AbilityStage](../../application-models/abilitystage.md)创建时注册监听，在[AbilityStage](../../application-models/abilitystage.md)销毁时注销监听；监听到对应UIAbility创建时加载资源，监听到对应UIAbility销毁时释放资源；此外UIAbility创建销毁、前后台状态切换时，做相关事件记录和对外发通知。</br>
MyStage.ets
AbilityStage文件
```ts
import { AbilityLifecycleCallback, AbilityStage, application, UIAbility } from "@kit.AbilityKit";
import { hilog } from '@kit.PerformanceAnalysisKit';
import { JSON } from "@kit.ArkTS";
import { window } from "@kit.ArkUI";
import { BusinessError } from "@kit.BasicServicesKit";

const DOMAIN = 0x0000;
const TAG = 'testTag';

function loadContent() {
  // load something
}

function releaseContent() {
  // release something
}

function recordAbilityEvent(abilityName: string) {
  // record something
}

function publishEvent() {
  // publish event to notify
}

let abilityLifecycleCallback: AbilityLifecycleCallback = {
  onAbilityCreate(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'onAbilityCreate: ' + ability.context.abilityInfo.name);
    // UIAbility事件打点记录
    recordAbilityEvent(ability.context.abilityInfo.name);
    // 模拟入口UIAbility创建时，加载资源对外发布通知
    if (ability.context.abilityInfo.name === 'EntryAbility') {
      loadContent();
      publishEvent();
    }
  },
  onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageCreate.');
  },
  onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageActive.');
  },
  onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageInactive.');
  },
  onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageDestroy.');
  },
  onAbilityDestroy(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'onAbilityDestroy: ' + ability.context.abilityInfo.name);
    recordAbilityEvent(ability.context.abilityInfo.name);
    // 模拟入口UIAbility销毁时，释放资源
    if (ability.context.abilityInfo.name === 'EntryAbility') {
      releaseContent();
      publishEvent();
    }
  },
  onAbilityForeground(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityForeground.');
    recordAbilityEvent(ability.context.abilityInfo.name);
    if (ability.context.abilityInfo.name === 'EntryAbility') {
      publishEvent();
    }
  },
  onAbilityBackground(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityBackground.');
    recordAbilityEvent(ability.context.abilityInfo.name);
    if (ability.context.abilityInfo.name === 'EntryAbility') {
      publishEvent();
    }
  },
  onAbilityContinue(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityContinue.');
  },
  onNewWant(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onNewWant');
  },
  onWillNewWant(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWillNewWant');
  },
  onAbilityWillCreate(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillCreate');
  },
  onWindowStageWillCreate(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageWillCreate');
  },
  onWindowStageWillDestroy(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageWillDestroy');
  },
  onAbilityWillDestroy(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillDestroy');
  },
  onAbilityWillForeground(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillForeground');
  },
  onAbilityWillBackground(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillBackground');
  },
  onAbilityWillContinue(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillContinue.');
  },
  onWindowStageWillRestore(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageWillRestore.');
  },
  onWindowStageRestore(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageRestore.');
  },
  onAbilityWillSaveState(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillSaveState.');
  },
  onAbilitySaveState(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilitySaveState.');
  }
};

let lifecycleId = -1;

export default class MyStage extends AbilityStage {
  onCreate(): void {
    hilog.info(DOMAIN, TAG, 'AbilityStage onCreate')

    // AbilityStage创建时注册监听，并把监听id保存起来
    try {
      let applicationContext = application.getApplicationContext();
      lifecycleId = applicationContext.on('abilityLifecycle', abilityLifecycleCallback);
    } catch (e) {
      hilog.error(DOMAIN, TAG, `register abilityLifecycle failed: ${JSON.stringify(e)}`);
    }
  }

  onDestroy(): void {
    // AbilityStage销毁时取消注册
    let applicationContext = application.getApplicationContext();
    applicationContext.off('abilityLifecycle', lifecycleId).catch((e: BusinessError) => {
      hilog.error(DOMAIN, TAG, `unregister abilityLifecycle failed: ${JSON.stringify(e)}`);
    });
  }
}
```

EntryAbility.ets
应用入口UIAbility
```ts
import { AbilityConstant, ConfigurationConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;
const TAG = 'testTag';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    this.context.getApplicationContext().setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_NOT_SET);
    hilog.info(DOMAIN, TAG, 'EntryAbility onCreate');
  }

  onDestroy(): void {
    hilog.info(DOMAIN, TAG, 'EntryAbility onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(DOMAIN, TAG, 'EntryAbility onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(DOMAIN, TAG, 'Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      hilog.info(DOMAIN, TAG, 'Succeeded in loading the content.');
    });
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(DOMAIN, TAG, 'EntryAbility onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(DOMAIN, TAG, 'EntryAbility onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    hilog.info(DOMAIN, TAG, 'EntryAbility  onBackground');
  }
}
```