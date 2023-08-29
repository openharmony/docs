# @ohos.app.ability.ApplicationStateChangeCallback (ApplicationStateChangeCallback)

ApplicationStateChangeCallback模块提供应用上下文ApplicationContext对当前应用前后台变化监听回调的能力，包括onApplicationForeground、onApplicationBackground方法。

> **说明：**
>
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import ApplicationStateChangeCallback from '@ohos.app.ability.ApplicationStateChangeCallback';
```

## ApplicationStateChangeCallback.onApplicationForeground

onApplicationForeground(): void;

注册当前应用前后台变化的监听后，在当前应用从后台切换到前台时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import ApplicationStateChangeCallback from '@ohos.app.ability.ApplicationStateChangeCallback';

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

let applicationStateChangeCallback: ApplicationStateChangeCallback = {
    onApplicationForeground() {
        console.info('applicationStateChangeCallback onApplicationForeground');
    }
}
GlobalContext.getContext().setObject("applicationStateChangeCallback", applicationStateChangeCallback);

export default class MyAbility extends UIAbility {
    onCreate() {
        console.log('MyAbility onCreate');
        GlobalContext.getContext().setObject("applicationContext", this.context.getApplicationContext());
        // 1.获取applicationContext
        let applicationContext = GlobalContext.getContext().getObject("applicationContext");
        // 2.通过applicationContext注册应用前后台状态监听
        if (applicationContext != undefined) {
            applicationContext.on('applicationStateChange',
                GlobalContext.getContext().getObject("applicationStateChangeCallback"));
        }
    }
    onDestroy() {
        let applicationContext = GlobalContext.getContext().getObject("applicationContext");
        // 1.通过applicationContext解除注册应用前后台状态监听
        if (applicationContext != undefined) {
            applicationContext.off('applicationStateChange',
                GlobalContext.getContext().getObject("applicationStateChangeCallback"));
        }
    }
}
```

## ApplicationStateChangeCallback.onApplicationBackground

onApplicationBackground(): void;

注册当前应用前后台变化的监听后，在当前应用从前台切换到后台时触发回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import ApplicationStateChangeCallback from '@ohos.app.ability.ApplicationStateChangeCallback';

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

let applicationStateChangeCallback: ApplicationStateChangeCallback = {
    onApplicationBackground() {
        console.info('applicationStateChangeCallback onApplicationBackground');
    }
}
GlobalContext.getContext().setObject("applicationStateChangeCallback", applicationStateChangeCallback);

export default class MyAbility extends UIAbility {
    onCreate() {
        console.log('MyAbility onCreate');
        GlobalContext.getContext().setObject("applicationContext", this.context.getApplicationContext());
        // 1.获取applicationContext
        let applicationContext = GlobalContext.getContext().getObject("applicationContext");
        // 2.通过applicationContext注册应用前后台状态监听
        if (applicationContext != undefined) {
            applicationContext.on('applicationStateChange',
                GlobalContext.getContext().getObject("applicationStateChangeCallback"));
        }
        console.log('Resgiter applicationStateChangeCallback');
    }
    onDestroy() {
        let applicationContext = GlobalContext.getContext().getObject("applicationContext");
        // 1.通过applicationContext解除注册应用前后台状态监听
        if (applicationContext != undefined) {
            applicationContext.off('applicationStateChange',
                GlobalContext.getContext().getObject("applicationStateChangeCallback"));
        }
    }
}
```