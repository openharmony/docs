# @ohos.InputMethodExtensionContext (InputMethodExtensionContext)

InputMethodExtensionContext模块是InputMethodExtensionAbility的上下文环境，继承于ExtensionContext，提供InputMethodExtensionAbility具有的能力和接口，包括启动、停止、绑定、解绑Ability。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import InputMethodExtensionContext from '@ohos.InputMethodExtensionContext';
```

## 使用说明

在使用InputMethodExtensionContext的功能前，需要通过InputMethodExtensionAbility子类实例获取。

```ts
import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
import Want from '@ohos.app.ability.Want';
class InputMethodExtnAbility extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    let context = this.context;
  }
}
```

## InputMethodExtensionContext.destroy

destroy(callback: AsyncCallback\<void>): void

销毁输入法应用。使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当销毁输入法应用成功时，err为undefined；否则为错误对象。 |

**示例：**

```ts
import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class InputMethodExtnAbility extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    let context = this.context;
  }
  onDestroy() {
    this.context.destroy((err: BusinessError) => {
      if(err) {
        console.log(`Failed to destroy context, err code = ${err.code}`);
        return;
      }
      console.log('Succeeded in destroying context.');
    });
  }
}
```

## InputMethodExtensionContext.destroy

destroy(): Promise\<void>;

销毁输入法应用。使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**示例：**

```ts
import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class InputMethodExtnAbility extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    let context = this.context;
  }
  onDestroy() {
    this.context.destroy().then(() => {
      console.log('Succeed in destroying context.');
    }).catch((err: BusinessError)=>{
      console.log(`Failed to destroy context, err code = ${err.code}`);
    });
  }
}
```
