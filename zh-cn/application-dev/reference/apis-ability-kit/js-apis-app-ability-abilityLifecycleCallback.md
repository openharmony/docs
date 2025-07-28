# @ohos.app.ability.abilityLifecycleCallback (UIAbility生命周期回调监听器)

AbilityLifecycleCallback提供监听[UIAbility](js-apis-app-ability-uiAbility.md)生命周期变化的能力。应用实现该接口后，通过应用上下文相关接口注册该监听[ApplicationContext.on('abilityLifecycle')](js-apis-inner-application-applicationContext.md#applicationcontextonabilitylifecycle)。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口只能监听进程内UIAbility生命周期变化。

## AbilityLifecycleCallback机制

[UIAbility](js-apis-app-ability-uiAbility.md)中定义了[生命周期状态](js-apis-app-ability-uiAbility.md#uiability生命周期状态)，当UIAbility状态发生变化时，UIAbility对应的生命周期函数被执行。AbilityLifecycleCallback则提供一种方式，让应用可以在UIAbility外部监听UIAbility的生命周期变化。流程如下：
1. 需要监听UIAbility生命周期变化的模块，实现abilityLifecycleCallback接口，然后通过应用上下问题[ApplicationContext](js-apis-inner-application-applicationContext.md)注册回调。
2. UIAbility生命周期管理模块，调度UIAbility生命周期，并通知ApplicationContext对应UIAbility的生命周期变化。
3. ApplicationContext收到UIAbility生命周期的变化通知，调用应用注册进来的abilityLifecycleCallback回调。
4. 不需要监听UIAbility生命周期变化时，通过[ApplicationContext.off('abilityLifecycle')](js-apis-inner-application-applicationContext.md#applicationcontextoffabilitylifecycle)取消监听。

> **说明：**
>
> 接口中带有will的回调函数，在UIAbility生命周期执行之前被调用；不带will的，在UIAbility生命周期执行之后被调用。

## 导入模块

```ts
import { AbilityLifecycleCallback } from '@kit.AbilityKit';
```

## AbilityLifecycleCallback.onAbilityCreate

onAbilityCreate(ability: UIAbility): void

在UIAbility创建时触发回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onWindowStageCreate

onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility关联的WindowStage创建时触发回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility关联的WindowStage对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onWindowStageActive

onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility关联的WindowStage获焦时触发回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility关联的WindowStage对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onWindowStageInactive

onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility关联的WindowStage失焦时触发回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility关联的WindowStage对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onWindowStageDestroy

onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility关联的WindowStage销毁时触发回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility关联的WindowStage对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onAbilityDestroy

onAbilityDestroy(ability: UIAbility): void

在UIAbility销毁时触发回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onAbilityForeground

onAbilityForeground(ability: UIAbility): void

在UIAbility的状态从后台转到前台时触发回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onAbilityBackground

onAbilityBackground(ability: UIAbility): void

在UIAbility的状态从前台转到后台时触发回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onAbilityContinue

onAbilityContinue(ability: UIAbility): void

在UIAbility[迁移](../../application-models/hop-cross-device-migration.md)[onContinue](js-apis-app-ability-uiAbility.md#onontinue)时触发回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onAbilityWillCreate<sup>12+</sup>

onAbilityWillCreate?(ability: UIAbility): void

在UIAbility的[onCreate](js-apis-app-ability-uiAbility.md#oncreate)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onWindowStageWillCreate<sup>12+</sup>

onWindowStageWillCreate?(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility的[onWindowStageCreate](js-apis-app-ability-uiAbility.md#onwindowstagecreate)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility关联的WindowStage对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onWindowStageWillDestroy<sup>12+</sup>

onWindowStageWillDestroy?(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility的[onWindowStageDestroy](js-apis-app-ability-uiAbility.md#onwindowstagedestroy)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility关联的WindowStage对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onAbilityWillForeground<sup>12+</sup>

onAbilityWillForeground?(ability: UIAbility): void

在UIAbility的[onForeground](js-apis-app-ability-uiAbility.md#onforeground)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onAbilityWillDestroy<sup>12+</sup>

onAbilityWillDestroy?(ability: UIAbility): void

在UIAbility的[onDestroy](js-apis-app-ability-uiAbility.md#ondestroy)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onAbilityWillBackground<sup>12+</sup>

onAbilityWillBackground?(ability: UIAbility): void

在UIAbility的[onBackground](js-apis-app-ability-uiAbility.md#onbackground)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onWillNewWant<sup>12+</sup>

onWillNewWant?(ability: UIAbility): void

在UIAbility的[onNewWant](js-apis-app-ability-uiAbility.md#onnewwant)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onNewWant<sup>12+</sup>

onNewWant?(ability: UIAbility): void

在UIAbility的[onNewWant](js-apis-app-ability-uiAbility.md#onnewwant)触发后回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onAbilityWillContinue<sup>12+</sup>

onAbilityWillContinue?(ability: UIAbility): void

在UIAbility的[onContinue](js-apis-app-ability-uiAbility.md#oncontinue)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onWindowStageWillRestore<sup>12+</sup>

onWindowStageWillRestore?(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility的[onWindowStageRestore](js-apis-app-ability-uiAbility.md#onwindowstagerestore)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility关联的WindowStage对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onWindowStageRestore<sup>12+</sup>

onWindowStageRestore?(ability: UIAbility, windowStage: window.WindowStage): void

在UIAbility的[onWindowStageRestore](js-apis-app-ability-uiAbility.md#onwindowstagerestore)触发后回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | 是 | 回调事件对应的UIAbility关联的WindowStage对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onAbilityWillSaveState<sup>12+</sup>

onAbilityWillSaveState?(ability: UIAbility): void

在UIAbility的[onSaveState](js-apis-app-ability-uiAbility.md#onsavestate)触发前回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback.onAbilitySaveState<sup>12+</sup>

onAbilitySaveState?(ability: UIAbility): void

在UIAbility的[onSaveState](js-apis-app-ability-uiAbility.md#onsavestate)触发后回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 回调事件对应的UIAbility对象 |

**示例：**

参见[AbilityLifecycleCallback使用](#abilitylifecyclecallback使用)。

## AbilityLifecycleCallback使用

**示例：**
GlobalContext.ts
全局Context
```ts
// 构造单例对象
export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}
```

MyFirstAbility.ts
应用的第一个Ability
```ts
import { AbilityLifecycleCallback, UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

// 导入GlobalContext，以开发者自己声明的路径为准
import { GlobalContext } from '../GlobalContext';

// 声明ability生命周期回调，需配置所有回调后才可以在applicationContext注册
let abilityLifecycleCallback: AbilityLifecycleCallback = {
  onAbilityCreate(ability){
    console.log('AbilityLifecycleCallback onAbilityCreate.');
  },
  onWindowStageCreate(ability, windowStage){
    console.log('AbilityLifecycleCallback onWindowStageCreate.');
  },
  onWindowStageActive(ability, windowStage){
    console.log('AbilityLifecycleCallback onWindowStageActive.');
  },
  onWindowStageInactive(ability, windowStage){
    console.log('AbilityLifecycleCallback onWindowStageInactive.');
  },
  onWindowStageDestroy(ability, windowStage){
    console.log('AbilityLifecycleCallback onWindowStageDestroy.');
  },
  onAbilityDestroy(ability){
    console.log('AbilityLifecycleCallback onAbilityDestroy.');
  },
  onAbilityForeground(ability){
    console.log('AbilityLifecycleCallback onAbilityForeground.');
  },
  onAbilityBackground(ability){
    console.log('AbilityLifecycleCallback onAbilityBackground.');
  },
  onAbilityContinue(ability){
    console.log('AbilityLifecycleCallback onAbilityContinue.');
  },
  onNewWant(ability) {
    console.log('AbilityLifecycleCallback onNewWant');
  },
  onWillNewWant(ability) {
    console.log('AbilityLifecycleCallback onWillNewWant');
  },
  onAbilityWillCreate(ability) {
    console.log('AbilityLifecycleCallback onAbilityWillCreate');
  },
  onWindowStageWillCreate(ability, windowStage) {
    console.log('AbilityLifecycleCallback onWindowStageWillCreate');
  },
  onWindowStageWillDestroy(ability, windowStage) {
    console.log('AbilityLifecycleCallback onWindowStageWillDestroy');
  },
  onAbilityWillDestroy(ability) {
    console.log('AbilityLifecycleCallback onAbilityWillDestroy');
  },
  onAbilityWillForeground(ability) {
    console.log('AbilityLifecycleCallback onAbilityWillForeground');
  },
  onAbilityWillBackground(ability) {
    console.log('AbilityLifecycleCallback onAbilityWillBackground');
  },
  onAbilityWillContinue(ability: UIAbility) {
    console.log('AbilityLifecycleCallback onAbilityWillContinue.');
  },
  onWindowStageWillRestore(ability: UIAbility, windowStage: window.WindowStage) {
    console.log('AbilityLifecycleCallback onWindowStageWillRestore.');
  },
  onWindowStageRestore(ability: UIAbility, windowStage: window.WindowStage) {
    console.log('AbilityLifecycleCallback onWindowStageRestore.');
  },
  onAbilityWillSaveState(ability: UIAbility) {
    console.log('AbilityLifecycleCallback onAbilityWillSaveState.');
  },
  onAbilitySaveState(ability: UIAbility) {
    console.log('AbilityLifecycleCallback onAbilitySaveState.');
  }
};

export default class MyFirstAbility extends UIAbility {
  onCreate() {
    console.log('MyAbilityStage onCreate');
    // 1.通过context属性获取applicationContext
    let applicationContext = this.context.getApplicationContext();
    // 2.通过applicationContext注册监听应用内生命周期
    try {
      let lifecycleId = applicationContext.on('abilityLifecycle', abilityLifecycleCallback);
      GlobalContext.getContext().setObject("lifecycleId", lifecycleId);
      console.log(`registerAbilityLifecycleCallback lifecycleId: ${GlobalContext.getContext().getObject('lifecycleId')}`);
    } catch (paramError) {
      console.error(`error: ${paramError.code}, ${paramError.message}`);
    }
  }
}
```

MySecondAbility.ts
应用的第二个Ability
```ts
import { UIAbility } from '@kit.AbilityKit';

// 导入GlobalContext，以开发者自己声明的路径为准
import { GlobalContext } from '../GlobalContext';
import { BusinessError } from '@ohos.base';

export default class MySecondAbility extends UIAbility {
  onDestroy() {
    let applicationContext = this.context.getApplicationContext();
    let lifecycleId = GlobalContext.getContext().getObject("lifecycleId") as number;
    try {
    // 3.通过applicationContext注销监听应用内生命周期
      applicationContext.off('abilityLifecycle', lifecycleId, (error) => {
        if (error && error.code !== 0) {
          console.error(`unregisterAbilityLifecycleCallback fail, error: ${JSON.stringify(error)}`);
        } else {
          console.log('unregisterAbilityLifecycleCallback success.');
        }
      });
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```