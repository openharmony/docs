# FormExtension

FormExtension模块提供了FormExtension卡片扩展相关接口。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 从API version 9 开始不再维护，建议使用[FormExtensionAbility](js-apis-app-form-formExtensionAbility.md)替代。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import FormExtension from '@ohos.application.FormExtension';
```

## 属性

**系统能力**：SystemCapability.Ability.Form

| 名称    | 类型                                                | 可读 | 可写 | 说明                                                |
| ------- | ------------------------------------------------------- | ---- | ---- | --------------------------------------------------- |
| context | [FormExtensionContext](js-apis-inner-application-formExtensionContext.md) | 是   | 否   | FormExtension的上下文环境，继承自ExtensionContext。 |

## onCreate

onCreate(want: Want): formBindingData.FormBindingData

卡片提供方接收创建卡片的通知接口。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                                                         |
| ------ | -------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](js-apis-application-want.md) | 是   | 当前Extension相关的Want类型信息，包括卡片ID、卡片名称、卡片样式等。这些卡片信息必须作为持久数据进行管理，以便后续更新和删除卡片。 |

**返回值：**

| 类型                                                         | 说明                                                        |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| [formBindingData.FormBindingData](js-apis-application-formBindingData.md#formbindingdata) | formBindingData.FormBindingData对象，卡片要显示的数据。 |

**示例：**

```ts
import formBindingData from '@ohos.application.formBindingData'
export default class MyFormExtension extends FormExtension {
  onCreate(want) {
    console.log('FormExtension onCreate, want:' + want.abilityName);
    let dataObj1 = {
      temperature:"11c",
      "time":"11:00"
    };
    let obj1 = formBindingData.createFormBindingData(dataObj1);
    return obj1;
  }
}
```

## FormExtension.onCastToNormal

onCastToNormal(formId: string): void

卡片提供方接收临时卡片转常态卡片的通知接口。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| formId | string | 是   | 请求转换为常态的卡片标识。 |

**示例：**

```ts
export default class MyFormExtension extends FormExtension {
  onCastToNormal(formId) {
    console.log('FormExtension onCastToNormal, formId:' + formId);
  }
}
```

## FormExtension.onUpdate

onUpdate(formId: string): void

卡片提供方接收更新卡片的通知接口。获取最新数据后调用[FormExtensionContext](js-apis-inner-application-formExtensionContext.md)的updateForm接口刷新卡片数据。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| formId | string | 是   | 请求更新的卡片ID。 |

**示例：**

```ts
import formBindingData from '@ohos.application.formBindingData'
export default class MyFormExtension extends FormExtension {
  onUpdate(formId) {
    console.log('FormExtension onUpdate, formId:' + formId);
    let obj2 = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});
    this.context.updateForm(formId, obj2).then((data)=>{
      console.log('FormExtension context updateForm, data:' + data);
    }).catch((error) => {
      console.error('Operation updateForm failed. Cause: ' + error);});
    }
}
```

## FormExtension.onVisibilityChange

onVisibilityChange(newStatus: { [key: string]: number }): void

卡片提供方接收修改可见性的通知接口。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名    | 类型                      | 必填 | 说明                         |
| --------- | ------------------------- | ---- | ---------------------------- |
| newStatus | { [key: string]: number } | 是   | 请求修改的卡片ID和可见状态。 |

**示例：**

```ts
import formBindingData from '@ohos.application.formBindingData'
export default class MyFormExtension extends FormExtension {
  onVisibilityChange(newStatus) {
  console.log('FormExtension onVisibilityChange, newStatus:' + newStatus);
  let obj2 = formBindingData.createFormBindingData({temperature:"22c", time:"22:00"});

  for (let key in newStatus) {
    console.log('FormExtension onVisibilityChange, key:' + key + ", value=" + newStatus[key]);
    this.context.updateForm(key, obj2).then((data)=>{
        console.log('FormExtension context updateForm, data:' + data);
    }).catch((error) => {
        console.error('Operation updateForm failed. Cause: ' + error);});
    }
  }
}
```

## FormExtension.onEvent

onEvent(formId: string, message: string): void

卡片提供方接收处理卡片事件的通知接口。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名  | 类型   | 必填 | 说明                   |
| ------- | ------ | ---- | ---------------------- |
| formId  | string | 是   | 请求触发事件的卡片标识。 |
| message | string | 是   | 事件消息。             |

**示例：**

```ts
export default class MyFormExtension extends FormExtension {
  onEvent(formId, message) {
    console.log('FormExtension onEvent, formId:' + formId + ", message:" + message);
  }
}
```

## FormExtension.onDestroy

onDestroy(formId: string): void

卡片提供方接收销毁卡片的通知接口。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| formId | string | 是   | 请求销毁的卡片标识。 |

**示例：**

```ts
export default class MyFormExtension extends FormExtension {
  onDestroy(formId) {
    console.log('FormExtension onDestroy, formId:' + formId);
  }
}
```

## FormExtension.onConfigurationUpdated

onConfigurationUpdated(config: Configuration): void;

当系统配置更新时调用。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| config | [Configuration](js-apis-application-configuration.md) | 是 | 表示需要更新的配置信息。 |

**示例：**

```ts
class MyFormExtension extends FormExtension {
  onConfigurationUpdated(config) {
    console.log('onConfigurationUpdated, config:' + JSON.stringify(config));
  }
}
```

## FormExtension.onAcquireFormState

onAcquireFormState?(want: Want): formInfo.FormState;

卡片提供方接收查询卡片状态通知接口。默认返回卡片初始状态。

**系统能力**：SystemCapability.Ability.Form

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md) | 是 | want表示获取卡片状态的描述。描述包括包名称、能力名称、模块名称、卡片名和卡片维度。 |

**示例：**

```ts
import formInfo from '@ohos.application.formInfo'
class MyFormExtension extends FormExtension {
  onAcquireFormState(want) {
    console.log('FormExtension onAcquireFormState, want:' + want);
    return formInfo.FormState.UNKNOWN;
  }
}
```

## FormExtension.onShare

onShare?(formId: string): {[key: string]: any};

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
| {[key: string]: any} | 卡片要分享的数据，由开发者自行决定传入的键值对。 |

**示例：**

```ts
class MyFormExtension extends FormExtension {
  onShare(formId) {
    console.log('FormExtension onShare, formId:' + formId);
    let wantParams = {
      "temperature":"20",
      "time":"2022-8-8 09:59",
    };
    return wantParams;
  }
}
```