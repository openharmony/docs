# @ohos.app.form.FormExtensionAbility (FormExtensionAbility)

FormExtensionAbility为卡片扩展模块，提供卡片创建、销毁、刷新等生命周期回调。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
```

## 属性

**系统能力**：SystemCapability.Ability.Form

| 名称    | 类型                                                         | 可读 | 可写 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| context | [FormExtensionContext](js-apis-inner-application-formExtensionContext.md) | 是   | 否   | FormExtensionAbility的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)。 |

## onAddForm

onAddForm(want: Want): formBindingData.FormBindingData

卡片提供方接收创建卡片的通知接口。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                                                         |
| ------ | -------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](js-apis-app-ability-want.md) | 是   | 当前卡片相关的Want类型信息，包括卡片ID、卡片名称、卡片样式等。这些卡片信息必须作为持久数据进行管理，以便后续更新和删除卡片。 |

**返回值：**

| 类型                                                         | 说明                                                        |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| [formBindingData.FormBindingData](js-apis-app-form-formBindingData.md#formbindingdata) | formBindingData.FormBindingData对象，卡片要显示的数据。 |

**示例：**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import formBindingData from '@ohos.app.form.formBindingData';
import Want from '@ohos.app.ability.Want';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAddForm(want: Want) {
    console.log(`FormExtensionAbility onAddForm, want: ${want.abilityName}`);
    let dataObj1 = new Map<string, string>();
    dataObj1.set('temperature', '11c');
    dataObj1.set('time', '11:00');

    let obj1: formBindingData.FormBindingData = formBindingData.createFormBindingData(dataObj1);
    return obj1;
  }
}
```

## onCastToNormalForm

onCastToNormalForm(formId: string): void

卡片提供方接收临时卡片转常态卡片的通知接口。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| formId | string | 是   | 请求转换为常态的卡片标识。 |

**示例：**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onCastToNormalForm(formId: string) {
    console.log(`FormExtensionAbility onCastToNormalForm, formId: ${formId}`);
  }
};
```

## onUpdateForm

onUpdateForm(formId: string): void

卡片提供方接收更新卡片的通知接口。获取最新数据后调用formProvider的[updateForm](js-apis-app-form-formProvider.md#updateform)接口刷新卡片数据。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| formId | string | 是   | 请求更新的卡片ID。 |

**示例：**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import formBindingData from '@ohos.app.form.formBindingData';
import formProvider from '@ohos.app.form.formProvider';
import Base from '@ohos.base';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onUpdateForm(formId: string) {
    console.log(`FormExtensionAbility onUpdateForm, formId: ${formId}`);
    let param: Record<string, string> = {
      'temperature': '22c',
      'time': '22:00'
    }
    let obj2: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);
    formProvider.updateForm(formId, obj2).then(() => {
      console.log(`FormExtensionAbility context updateForm`);
    }).catch((error: Base.BusinessError) => {
      console.error(`FormExtensionAbility context updateForm failed, data: ${error}`);
    });
  }
};
```

## onChangeFormVisibility

onChangeFormVisibility(newStatus: { [key: string]: number }): void

卡片提供方接收修改可见性的通知接口。  
该接口仅对系统应用生效，且需要将formVisibleNotify配置为true。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名    | 类型                      | 必填 | 说明                         |
| --------- | ------------------------- | ---- | ---------------------------- |
| newStatus | { [key: string]: number } | 是   | 请求修改的卡片标识和可见状态。 |

**示例：**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import formBindingData from '@ohos.app.form.formBindingData';
import formProvider from '@ohos.app.form.formProvider';
import Base from '@ohos.base';

// 由于arkTs中无Object.keys，且无法使用for..in...
// 若报arkTs问题，请将此方法单独抽离至一个ts文件中并暴露，在需要用到的ets文件中引入使用
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
      }).catch((error: Base.BusinessError) => {
        console.error(`Operation updateForm failed. Cause: ${JSON.stringify(error)}`);
      });
    }
  }
};
```

## onFormEvent

onFormEvent(formId: string, message: string): void

卡片提供方接收处理卡片事件的通知接口（此方法仅可在JS卡片中使用）。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名  | 类型   | 必填 | 说明                   |
| ------- | ------ | ---- | ---------------------- |
| formId  | string | 是   | 请求触发事件的卡片标识。 |
| message | string | 是   | 事件消息。             |

**示例：**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onFormEvent(formId: string, message: string) {
    console.log(`FormExtensionAbility onFormEvent, formId: ${formId}, message: ${message}`);
  }
};
```

## onRemoveForm

onRemoveForm(formId: string): void

卡片提供方接收销毁卡片的通知接口。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| formId | string | 是   | 请求销毁的卡片标识。 |

**示例：**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onRemoveForm(formId: string) {
    console.log(`FormExtensionAbility onRemoveForm, formId: ${formId}`);
  }
};
```

## onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void

当系统配置更新时调用。  
仅当前formExtensionAbility存活时更新配置才会触发此生命周期。需要注意，formExtensionAbility创建后5秒内无操作将会被清理。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| newConfig | [Configuration](js-apis-application-configuration.md) | 是 | 表示需要更新的配置信息。 |

**示例：**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import { Configuration } from '@ohos.app.ability.Configuration';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onConfigurationUpdate(newConfig: Configuration) {
    // 仅当前formExtensionAbility存活时更新配置才会触发此生命周期。
    // 需要注意，formExtensionAbility创建后5秒内无操作将会被清理。
    console.log(`onConfigurationUpdate, config: ${JSON.stringify(config)}`);
  }
};
```

## onAcquireFormState

onAcquireFormState?(want: Want): formInfo.FormState

卡片提供方接收查询卡片状态通知接口，默认返回卡片初始状态(该方法可以选择性重写)。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | want表示获取卡片状态的描述。描述包括Bundle名称、能力名称、模块名称、卡片名和卡片维度。 |

**示例：**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import formInfo from '@ohos.app.form.formInfo';
import Want from '@ohos.app.ability.Want';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAcquireFormState(want: Want) {
    console.log(`FormExtensionAbility onAcquireFormState, want: ${want}`);
    return formInfo.FormState.UNKNOWN;
  }
};
```

## onShareForm

onShareForm?(formId: string): { [key: string]: Object }

卡片提供方接收卡片分享的通知接口。

**系统接口**: 此接口为系统接口。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| formId | string | 是   | 卡片标识。 |

**返回值：**

| 类型                                                         | 说明                                                        |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| {[key: string]: Object} | 卡片要分享的数据，由开发者自行决定传入的键值对。 |

**示例：**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onShareForm(formId: string) {
    console.log(`FormExtensionAbility onShareForm, formId: ${formId}`);
    let wantParams: Record<string, Object> = {
      'temperature': '20',
      'time': '2022-8-8 09:59',
    };
    return wantParams;
  }
};
```

## onAcquireFormData<sup>10+</sup>

onAcquireFormData?(formId: string): { [key: string]: Object }

卡片提供方接收卡片请求自定义数据的通知接口。

**系统接口**: 此接口为系统接口。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| formId | string | 是   | 卡片标识。 |

**返回值：**

| 类型                                                         | 说明                                                        |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| {[key: string]: Object} | 卡片的自定义数据，由开发者自行决定传入的键值对。 |

**示例：**

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAcquireFormData(formId: string) {
    console.log(`FormExtensionAbility onAcquireFormData, formId: ${formId}`);
    let wantParams: Record<string, Object> = {
      'temperature': '20',
      'time': '2022-8-8 09:59',
    };
    return wantParams;
  }
};
```