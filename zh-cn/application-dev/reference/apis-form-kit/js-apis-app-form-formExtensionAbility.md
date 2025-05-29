# @ohos.app.form.FormExtensionAbility (FormExtensionAbility)

FormExtensionAbility为卡片扩展模块，提供卡片创建、销毁、刷新等生命周期回调。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 如下模块不支持在FormExtensionAbility引用，可能会导致程序异常退出。
> - @ohos.ability.particleAbility (ParticleAbility模块)
> - @ohos.multimedia.audio (音频管理)
> - @ohos.multimedia.camera (相机管理)
> - @ohos.multimedia.media (媒体服务)
> - @ohos.resourceschedule.backgroundTaskManager (后台任务管理)

## 导入模块

```ts
import { FormExtensionAbility } from '@kit.FormKit';
```

## FormExtensionAbility

卡片扩展类。包含卡片提供方接收创建卡片、修改可见性等的通知接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

### 属性

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

| 名称    | 类型                                                         | 可读 | 可写 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| context | [FormExtensionContext](js-apis-inner-application-formExtensionContext.md) | 是   | 否   | FormExtensionAbility的上下文环境，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|

### FormExtensionAbility.onAddForm

onAddForm(want: Want): formBindingData.FormBindingData

卡片提供方接收创建卡片的通知接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                                                         |
| ------ | -------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 当前卡片相关的Want类型信息，包括卡片ID、卡片名称、卡片样式等。这些卡片信息必须作为持久数据进行管理，以便后续更新和删除卡片。 |

**返回值：**

| 类型                                                         | 说明                                                        |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | formBindingData.FormBindingData对象，卡片要显示的数据。 |

**示例：**

```ts
import { formBindingData, FormExtensionAbility } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAddForm(want: Want) {
    console.log(`FormExtensionAbility onAddForm, want: ${want.abilityName}`);
    let dataObj1: Record<string, string> = {
      'temperature': '11c',
      'time': '11:00'
    };

    let obj1: formBindingData.FormBindingData = formBindingData.createFormBindingData(dataObj1);
    return obj1;
  }
}
```

### FormExtensionAbility.onCastToNormalForm

onCastToNormalForm(formId: string): void

卡片提供方接收临时卡片转常态卡片的通知接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| formId | string | 是   | 请求转换为常态的卡片标识。 |

**示例：**

```ts
import { FormExtensionAbility } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onCastToNormalForm(formId: string) {
    console.log(`FormExtensionAbility onCastToNormalForm, formId: ${formId}`);
  }
};
```

### FormExtensionAbility.onUpdateForm

onUpdateForm(formId: string, wantParams?: Record<string, Object>): void

卡片提供方接收携带参数的更新卡片的通知接口。获取最新数据后调用formProvider的[updateForm](js-apis-app-form-formProvider.md#updateform)接口刷新卡片数据。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| formId | string | 是   | 请求更新的卡片ID。 |
| wantParams<sup>12+</sup> | Record<string, Object> | 否   | 更新参数。 |

**示例：**

```ts
import { formBindingData, FormExtensionAbility, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onUpdateForm(formId: string, wantParams?: Record<string, Object>) {
    console.log(`FormExtensionAbility onUpdateForm, formId: ${formId},
        wantPara: ${wantParams?.['ohos.extra.param.key.host_bg_inverse_color']}`);
    let param: Record<string, string> = {
      'temperature': '22c',
      'time': '22:00'
    }
    let obj2: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
    formProvider.updateForm(formId, obj2).then(() => {
      console.log(`FormExtensionAbility context updateForm`);
    }).catch((error: BusinessError) => {
      console.error(`FormExtensionAbility context updateForm failed, data: ${error}`);
    });
  }
};
```

### FormExtensionAbility.onChangeFormVisibility

onChangeFormVisibility(newStatus: Record\<string, number>): void

卡片提供方接收修改可见性的通知接口。
该接口仅对系统应用生效，且需要将formVisibleNotify配置为true。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名  | 类型   | 必填 | 说明                   |
| ------- | ------ | ---- | ---------------------- |
| newStatus  | Record\<string, number> | 是   | 请求修改的卡片标识和可见状态。 |

**示例：**

```ts
import { formBindingData, FormExtensionAbility, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

// ArkTS规范中ets文件无法使用Object.keys和for..in...获取Object的key值，请使用自定义函数getObjKeys代替。
// 使用时请将此函数单独抽离至一个ts文件中并导出，在需要用到的ets文件中导入此函数后使用。
function getObjKeys(obj: Object): string[] {
  let keys = Object.keys(obj);
  return keys;
}

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onChangeFormVisibility(newStatus: Record<string, number>) {
    console.log(`FormExtensionAbility onChangeFormVisibility, newStatus: ${newStatus}`);
    let param: Record<string, string> = {
      'temperature': '22c',
      'time': '22:00'
    }
    let obj2: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);

    let keys: string[] = getObjKeys(newStatus);

    for (let i: number = 0; i < keys.length; i++) {
      console.log(`FormExtensionAbility onChangeFormVisibility, key: ${keys[i]}, value= ${newStatus[keys[i]]}`);
      formProvider.updateForm(keys[i], obj2).then(() => {
        console.log(`FormExtensionAbility context updateForm`);
      }).catch((error: BusinessError) => {
        console.error(`Operation updateForm failed. Cause: ${JSON.stringify(error)}`);
      });
    }
  }
};
```

### FormExtensionAbility.onFormEvent

onFormEvent(formId: string, message: string): void

卡片提供方接收处理卡片事件的通知接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名  | 类型   | 必填 | 说明                   |
| ------- | ------ | ---- | ---------------------- |
| formId  | string | 是   | 请求触发事件的卡片标识。 |
| message | string | 是   | 事件消息。             |

**示例：**

```ts
import { FormExtensionAbility } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    console.log(`FormExtensionAbility onFormEvent, formId: ${formId}, message: ${message}`);
  }
};
```

### FormExtensionAbility.onRemoveForm

onRemoveForm(formId: string): void

卡片提供方接收销毁卡片的通知接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| formId | string | 是   | 请求销毁的卡片标识。 |

**示例：**

```ts
import { FormExtensionAbility } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onRemoveForm(formId: string) {
    console.log(`FormExtensionAbility onRemoveForm, formId: ${formId}`);
  }
};
```

### FormExtensionAbility.onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void

当系统配置更新时调用。  
仅当前formExtensionAbility存活时更新配置才会触发此生命周期。需要注意：formExtensionAbility创建后10秒内无操作将会被清理。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| newConfig | [Configuration](../apis-ability-kit/js-apis-app-ability-configuration.md) | 是 | 表示需要更新的配置信息。 |

**示例：**

```ts
import { FormExtensionAbility } from '@kit.FormKit';
import { Configuration } from '@kit.AbilityKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onConfigurationUpdate(newConfig: Configuration) {
    // 仅当前formExtensionAbility存活时更新配置才会触发此生命周期。
    // 需要注意：formExtensionAbility创建后10秒内无操作将会被清理。
    console.log(`onConfigurationUpdate, config: ${JSON.stringify(newConfig)}`);
  }
};
```

### FormExtensionAbility.onAcquireFormState

onAcquireFormState?(want: Want): formInfo.FormState

卡片提供方接收查询卡片状态通知接口，默认返回卡片初始状态(该方法可以选择性重写)。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | want表示获取卡片状态的描述。描述包括Bundle名称、能力名称、模块名称、卡片名和卡片维度。 |

**示例：**

```ts
import { FormExtensionAbility, formInfo } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAcquireFormState(want: Want) {
    console.log(`FormExtensionAbility onAcquireFormState, want: ${want}`);
    return formInfo.FormState.UNKNOWN;
  }
};
```

### FormExtensionAbility.onStop<sup>12+</sup>

onStop?(): void

当卡片提供方的卡片进程退出时，触发该回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。
  
**系统能力：** SystemCapability.Ability.Form

**示例：**

```ts
import { FormExtensionAbility } from '@kit.FormKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onStop() {
    console.log(`FormExtensionAbility onStop`);
  }
}
```
