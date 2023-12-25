# AbilityStartCallback

定义拉起UIExtensionAbility失败后的回调。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import common from '@ohos.app.ability.common';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称        |  类型                 | 必填 | 说明                                                         |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| onError<sup>11+</sup>  | function               | 是   | 拉起UIExtensionAbility失败后的回调函数。                                |

**示例：**

  ```ts
  import common from '@ohos.app.ability.common';
  let context = getContext(this) as common.UIAbilityContext;
  let wantParam: Record<string, Object> = {
    'time':'2023-10-23 20:45',
  };
  let abilityStartCallback: common.AbilityStartCallback = {
    onError: (code: number, name: string, message: string) => {
      console.log(`code:` + code + `name:` + name + `message:` + message);
    }
  }
  context.startAbilityByType("photoEditor", wantParam, abilityStartCallback, (err) => {
    if (err) {
      console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log(`success`);
    }
  });
  ```

