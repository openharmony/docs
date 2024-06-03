# AbilityStartCallback

定义拉起UIExtensionAbility执行结果的回调。

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
| onError  | function               | 是   | 拉起UIExtensionAbility失败后的回调函数。**元服务API：** 从API version 11开始，该接口支持在元服务中使用。                                |
| onResult<sup>12+</sup> | function               | 否   | 拉起UIExtensionAbility后，UIExtensionAbility调用terminateSelfWithResult的回调函数。**元服务API：** 从API version 12开始，该接口支持在元服务中使用。                        |

**示例：**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import common from '@ohos.app.ability.common';
  import { BusinessError } from '@ohos.base';

  export default class EntryAbility extends UIAbility {
    onForeground() {
      let wantParam: Record<string, Object> = {
        'time': '2023-10-23 20:45',
      };
      let abilityStartCallback: common.AbilityStartCallback = {
        onError: (code: number, name: string, message: string) => {
          console.log(`code:` + code + `name:` + name + `message:` + message);
        },
        onResult: (abilityResult: common.AbilityResult) => {
          console.log(`resultCode:` + abilityResult.resultCode + `bundleName:` + abilityResult.want?.bundleName);
        }
      };

      this.context.startAbilityByType("photoEditor", wantParam, abilityStartCallback, (err: BusinessError) => {
        if (err) {
          console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
        } else {
          console.log(`success`);
        }
      });
    }
  }
  ```

