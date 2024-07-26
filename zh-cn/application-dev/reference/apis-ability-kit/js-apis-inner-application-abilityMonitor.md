# AbilityMonitor

AbilityMonitor模块提供匹配满足指定条件的受监视能力对象的方法的能力，最近匹配的ability对象将保存在[AbilityMonitor](js-apis-inner-application-abilityMonitor.md#abilitymonitor-1)对象中。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

## 导入模块

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
```

## 使用说明

可以作为abilityDelegator中的[addAbilityMonitor](../apis-test-kit/js-apis-inner-application-abilityDelegator.md#addabilitymonitor9)的入参来监听指定Ability的生命周期变化。

## 属性

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                                                         | 类型     | 只读 | 可选 | 说明                                                         |
| ------------------------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName                                                  | string   | 否   | 否   | 当前AbilityMonitor绑定的ability名称。 |
| moduleName                                                  | string   | 否   | 是   | 当前AbilityMonitor绑定的模块名称。 |
| onAbilityCreate | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | 否   | 是   | ability被启动初始化时的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onAbilityForeground | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | 否   | 是   | ability状态变成前台时的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onAbilityBackground | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | 否   | 是   | ability状态变成后台时的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onAbilityDestroy | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | 否   | 是   | ability被销毁前的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onWindowStageCreate | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | 否   | 是   | window stage被创建时的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onWindowStageRestore | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | 否   | 是   | window stage被重载时的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |
| onWindowStageDestroy | (ability: [UIAbility](js-apis-app-ability-uiAbility.md)) => void | 否   | 是   | window stage被销毁前的回调函数。<br/>不设置该属性则不能收到该生命周期回调。 |

**示例：**

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

function onAbilityCreateCallback(data: UIAbility) {
  console.info(`onAbilityCreateCallback, data: ${JSON.stringify(data)}`);
}

let monitor: abilityDelegatorRegistry.AbilityMonitor = {
  abilityName: 'abilityname',
  moduleName: "moduleName",
  onAbilityCreate: onAbilityCreateCallback
}

let abilityDelegator: abilityDelegatorRegistry.AbilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitor(monitor, (error: BusinessError) => {
  if (error) {
    console.error(`addAbilityMonitor fail, error: ${JSON.stringify(error)}`);
  }
});
```
