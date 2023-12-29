# @ohos.app.ability.abilityLifecycleCallback (AbilityLifecycleCallback)

AbilityLifecycleCallback模块提供应用上下文[ApplicationContext](js-apis-inner-application-applicationContext.md)的生命周期发生变化时触发相应回调的能力，包括[onAbilityCreate](#abilitylifecyclecallbackonabilitycreate)、[onWindowStageCreate](#abilitylifecyclecallbackonwindowstagecreate)、[onWindowStageActive](#abilitylifecyclecallbackonwindowstageactive)、[onWindowStageInactive](#abilitylifecyclecallbackonwindowstageinactive)、[onWindowStageDestroy](#abilitylifecyclecallbackonwindowstagedestroy)、[onAbilityDestroy](#abilitylifecyclecallbackonabilitydestroy)、[onAbilityForeground](#abilitylifecyclecallbackonabilityforeground)、[onAbilityBackground](#abilitylifecyclecallbackonabilitybackground)、[onAbilityContinue](#abilitylifecyclecallbackonabilitycontinue)方法。

> **说明：**
>
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';
```

## AbilityLifecycleCallback.onAbilityCreate

onAbilityCreate(ability: UIAbility): void;

注册监听应用上下文的生命周期后，在ability创建时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |

**示例：**
```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';

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
    }
};
```

## AbilityLifecycleCallback.onWindowStageCreate

onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage): void;

注册监听应用上下文的生命周期后，在windowStage创建时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |

**示例：**
```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';

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
    }
};
```

## AbilityLifecycleCallback.onWindowStageActive

onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage): void;

注册监听应用上下文的生命周期后，在windowStage获焦时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |

**示例：**
```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';

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
    }
};
```

## AbilityLifecycleCallback.onWindowStageInactive

onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage): void;

注册监听应用上下文的生命周期后，在windowStage失焦时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |

**示例：**
```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';

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
    }
};
```

## AbilityLifecycleCallback.onWindowStageDestroy

onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage): void;

注册监听应用上下文的生命周期后，在windowStage销毁时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | 是 | 当前WindowStage对象 |

**示例：**
```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';

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
    }
};
```

## AbilityLifecycleCallback.onAbilityDestroy

onAbilityDestroy(ability: UIAbility): void;

注册监听应用上下文的生命周期后，在ability销毁时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |

**示例：**
```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';

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
    }
};
```

## AbilityLifecycleCallback.onAbilityForeground

onAbilityForeground(ability: UIAbility): void;

注册监听应用上下文的生命周期后，在ability的状态从后台转到前台时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |

**示例：**
```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';

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
    }
};
```

## AbilityLifecycleCallback.onAbilityBackground

onAbilityBackground(ability: UIAbility): void;

注册监听应用上下文的生命周期后，在ability的状态从前台转到后台时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |

**示例：**
```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';

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
    }
};
```

## AbilityLifecycleCallback.onAbilityContinue

onAbilityContinue(ability: UIAbility): void;

注册监听应用上下文的生命周期后，在ability迁移时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | 是 | 当前Ability对象 |

**示例：**
```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';

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
    }
};
```

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
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';
import AbilityStage from '@ohos.app.ability.AbilityStage';
import UIAbility from '@ohos.app.ability.UIAbility';

// 导入GlobalContext，以开发者自己声明的路径为准
import { GlobalContext } from '../GlobalContext'

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
import UIAbility from '@ohos.app.ability.UIAbility';

// 导入GlobalContext，以开发者自己声明的路径为准
import { GlobalContext } from '../GlobalContext'

export default class MySecondAbility extends UIAbility {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        let lifecycleId = GlobalContext.getContext().getObject("lifecycleId") as number;
        // 3.通过applicationContext注销监听应用内生命周期
        applicationContext.off('abilityLifecycle', lifecycleId, (error) => {
            if (error && error.code !== 0) {
                console.error(`unregisterAbilityLifecycleCallback fail, error: ${JSON.stringify(error)}`);
            } else {
                console.log('unregisterAbilityLifecycleCallback success.');
            }
        });
    }
}
```