# ExtensionContext
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yewei0794-->
<!--SE: @jsjzju-->
<!--TSE: @lixueqing513-->

ExtensionContext是Extension的上下文环境，继承自Context。

ExtensionContext模块提供访问特定Extension的资源的能力，对于拓展的Extension，可直接将ExtensionContext作为上下文环境，或者定义一个继承自ExtensionContext的类型作为上下文环境。

> **说明：**
>
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## 属性

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | 否 | 否 | 所属Hap包的信息。<br>(详见SDK目录下的 `api\bundle\hapModuleInfo.d.ts`)  |
| config   | [Configuration](js-apis-app-ability-configuration.md) | 否 | 否 | 所属Module的配置信息。<br>(详见SDK目录下的 `api\@ohos.app.ability.Configuration.d.ts`) |
| extensionAbilityInfo | [ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md) | 否 | 否 | 所属Extension的信息。<br>(详见SDK目录下的 `api\bundle\extensionAbilityInfo.d.ts`) |

## 使用场景
ExtensionContext主要用于查询所属Extension的信息、Module的配置信息以及HAP包的信息，开发者可根据自身业务需求使用对应的信息。

**示例：**

```ts
// 单例对象 GlobalContext.ts
export class GlobalContext {
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  private constructor() {
  }

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

```ts
import { FormExtensionAbility, formBindingData } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { GlobalContext } from '../GlobalContext';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAddForm(want: Want) {
    console.info(`FormExtensionAbility onAddForm, want: ${want.abilityName}`);
    let dataObj1: Record<string, string> = {
      'temperature': '11c',
      'time': '11:00'
    };
    GlobalContext.getContext().setObject("ExtensionContext", this.context);
    let obj1: formBindingData.FormBindingData = formBindingData.createFormBindingData(dataObj1);
    return obj1;
  }
};
```
