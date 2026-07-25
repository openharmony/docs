# @ohos.InputMethodExtensionContext (InputMethodExtensionContext)
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

@ohos.InputMethodExtensionContext模块是InputMethodExtensionAbility的上下文环境，继承于ExtensionContext，为输入法扩展能力提供上下文级别的操作接口。

本模块是输入法ExtensionAbility的上下文类，继承自`ExtensionContext`，作为`InputMethodExtensionAbility`实例的`context`属性提供。它承载了输入法扩展应用在其生命周期内可使用的上下文能力，包括销毁自身和拉起其他应用。

本模块提供两大核心能力：1）通过`destroy()`销毁输入法ExtensionAbility自身，实现输入法应用的生命周期终止；2）通过`startAbility()`拉起目标应用，使输入法应用能够启动其他Ability进行交互，拓展输入法功能的灵活性和可扩展性。

当开发输入法ExtensionAbility并需要在其生命周期内执行上下文级操作时使用本模块。典型场景包括：输入法应用在`onDestroy`回调中主动销毁自身、输入法应用需要拉起设置页面或其他辅助应用等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

模块内的核心API按功能分为两类：
1. 生命周期管理：`destroy()`用于销毁输入法ExtensionAbility自身，终止输入法应用运行。
2. Ability交互：`startAbility()`用于从输入法应用拉起目标Ability（如设置页面等），拓展输入法应用与其他应用的交互能力。

典型使用流程：在`InputMethodExtensionAbility`的`onCreate`回调中获取`this.context` → 在需要终止输入法时调用`context.destroy()` → 在需要拉起其他应用时调用`context.startAbility(want)`。

| Class | 说明 |
|---|---|
| InputMethodExtensionContext | 输入法扩展上下文类，继承自`ExtensionContext`，为`InputMethodExtensionAbility`提供上下文操作能力。关键方法包括：`destroy()`销毁输入法自身（支持callback和Promise两种异步方式）、`startAbility(want)`拉起目标应用（Promise方式，API 12+新增）。 |

> **说明：**
> 
> 继承关系：`InputMethodExtensionContext`继承自`ExtensionContext`（来自`@ohos.app.ability`模块），泛化关系不在本模块内描述。

本模块的`InputMethodExtensionContext`需通过`InputMethodExtensionAbility`子类实例获取，其API与InputMethodExtensionAbility生命周期回调组合使用。

```javascript
// 以下为阐述调用逻辑的伪代码

// 1. 定义InputMethodExtensionAbility子类
class InputMethodExtAbility extends InputMethodExtensionAbility {
  onCreate(want) {
    // 获取上下文对象
    let context = this.context;  // InputMethodExtensionContext实例
  }

  onDestroy() {
    // 在生命周期回调中销毁自身
    this.context.destroy();
  }
}

// 2. 拉起目标应用（如输入法设置页面）
let targetWant = {
  bundleName: "com.example.settings",
  abilityName: "SettingsAbility"
};
this.context.startAbility(targetWant);
```

> **说明：**
>
> `InputMethodExtensionContext`实例通过`InputMethodExtensionAbility`子类的`this.context`属性获取，不可直接创建。`destroy()`通常在`onDestroy`生命周期回调中调用，也可在其他时机主动调用以终止输入法ExtensionAbility。

## 导入模块

```ts
import { InputMethodExtensionContext } from '@kit.IMEKit';
```

## 使用说明

在使用InputMethodExtensionContext的功能前，需要通过InputMethodExtensionAbility子类实例获取。

```ts
import { InputMethodExtensionAbility, InputMethodExtensionContext } from '@kit.IMEKit';
import { Want } from '@kit.AbilityKit';

class InputMethodExtAbility extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    console.info('onCreate, want:' + want.abilityName);
  }
}
```

## InputMethodExtensionContext

### destroy

destroy(callback: AsyncCallback&lt;void&gt;): void

销毁输入法应用。使用callback异步回调。

- 含义/功能：销毁当前的InputMethodExtensionAbility，终止输入法应用的运行。调用后系统将触发`InputMethodExtensionAbility.onDestroy()`生命周期回调。
- 使用场景：当输入法应用需要主动终止自身运行时使用。例如：输入法应用在处理完特定任务后主动退出、或在`onDestroy`回调中配合销毁以确保资源释放。
- 使用后效果：调用成功后，当前的InputMethodExtensionAbility将被销毁，系统触发`onDestroy()`生命周期回调，输入法应用进程终止。调用后再进行其他上下文操作将不起效。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| callback | [AsyncCallback](../apis-basic-services-kit/js-apis-base.md#asynccallback)&lt;void&gt;  | 是   | 回调函数。当销毁输入法应用成功时，err为undefined；否则为错误对象。 |

**示例：**

```ts
import { InputMethodExtensionAbility, InputMethodExtensionContext } from '@kit.IMEKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

class InputMethodExtAbility extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    console.info('onCreate, want:' + want.abilityName);
  }

  onDestroy() {
    this.context.destroy((err: BusinessError) => {
      if (err) {
        console.error(`Failed to destroy context, err code = ${err.code}`);
        return;
      }
      console.info('Succeeded in destroying context.');
    });
  }
}
```

### destroy

destroy(): Promise&lt;void&gt;

销毁输入法应用。使用Promise异步回调。

- 含义/功能：销毁当前的InputMethodExtensionAbility，终止输入法应用的运行。调用后系统将触发`InputMethodExtensionAbility.onDestroy()`生命周期回调。
- 使用场景：当输入法应用需要主动终止自身运行时使用。与callback形式功能相同，适合需要使用Promise链式调用的场景。
- 使用后效果：调用成功后，当前的InputMethodExtensionAbility将被销毁，系统触发`onDestroy()`生命周期回调，输入法应用进程终止。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt;  | Promise对象，无返回结果。 |

**示例：**

```ts
import { InputMethodExtensionAbility, InputMethodExtensionContext } from '@kit.IMEKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

class InputMethodExtAbility extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    console.info('onCreate, want:' + want.abilityName);
  }

  onDestroy() {
    this.context.destroy().then(() => {
      console.info('Succeeded in destroying context.');
    }).catch((err: BusinessError)=>{
      console.error(`Failed to destroy context, err code = ${err.code}`);
    });
  }
}
```

### startAbility<sup>12+</sup>

startAbility(want: Want): Promise&lt;void&gt;

拉起目标应用。使用Promise异步回调。

- 含义/功能：从输入法应用启动指定的Ability，使输入法应用能够与其他应用交互。通过Want参数指定目标应用的Ability名称和Bundle名称。
- 使用场景：当输入法应用需要拉起其他应用时使用。例如：输入法应用拉起系统设置页面供用户配置输入法、拉起浏览器打开帮助文档等。
- 使用后效果：调用成功后，目标Ability被启动并显示在前台。输入法应用自身不会受到影响，继续正常运行。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 用于指定目标应用的Want类型信息，包括ability名称、bundle名称等。 |

want参数使用建议：

- 含义/功能：Want类型信息，描述要启动的目标Ability。
- 必填属性：`bundleName`（目标应用包名）和`abilityName`（目标Ability名称）为必填项，否则无法定位目标Ability。
- 取值范围：Want对象的属性值均为string类型，需与目标应用在module.json5中配置的bundleName和abilityName保持一致。
- 注意事项：want中的bundleName和abilityName必须与目标应用的配置严格一致（包括大小写），否则将返回16000001错误（指定的Ability不存在）。开发者可通过查看目标应用的module.json5配置文件或使用AppGallery获取正确的包名和Ability名。

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[输入法框架错误码](errorcode-inputmethod-framework.md)，[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)，[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000001 | The specified ability does not exist.                   |
| 16000002 | Incorrect ability type.                                 |
| 16000004 | Cannot start an invisible component.                    |
| 16000005 | The specified process does not have the permission.     |
| 16000006 | Cross-user operations are not allowed.                  |
| 16000008 | The crowdtesting application expires.                   |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist.                             |
| 16000012 | The application is controlled.                          |
| 16000013 | The application is controlled by EDM.                   |
| 16000019 | No matching ability is found.                            |
| 16000050 | Internal error.                                         |
| 16000053 | The ability is not on the top of the UI.                |
| 16000055 | Installation-free timed out.                            |
| 16000061 | Operation not supported.                                |
| 16200001 | The caller has been released.                           |
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service.                 |

**示例：**

```ts
import { InputMethodExtensionAbility, InputMethodExtensionContext } from '@kit.IMEKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

class InputMethodExtAbility extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    const context: InputMethodExtensionContext = this.context;
    const targetWant: Want = {
      bundleName: "com.example.aafwk.test",
      abilityName: "com.example.aafwk.test.TwoAbility"
    };

    context.startAbility(targetWant)
      .then(() => console.info('startAbility success'))
      .catch((err: BusinessError) => {
        console.error(`StartAbility failed. Code: ${err.code}, Message: ${err.message}`);
      });
  }

  onDestroy() {
    this.context.destroy().then(() => {
      console.info('Succeeded in destroying context.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to destroy context, err code = ${err.code}`);
    });
  }
}
```

