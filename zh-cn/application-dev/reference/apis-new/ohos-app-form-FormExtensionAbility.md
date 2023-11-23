# @ohos.app.form.FormExtensionAbility    
FormExtensionAbility为卡片扩展模块，提供卡片创建、销毁、刷新等生命周期回调。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## FormExtensionAbility    
FormExtensionAbility为卡片扩展模块，提供卡片创建、销毁、刷新等生命周期回调。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.Form    
### 属性    
 **系统能力:**  SystemCapability.Ability.Form    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| context | FormExtensionContext | false | true | FormExtensionAbility的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)。 |  
    
### onAddForm    
卡片提供方接收创建卡片的通知接口。  
 **调用形式：**     
- onAddForm(want: Want): formBindingData.FormBindingData  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 当前卡片相关的Want类型信息，包括卡片ID、卡片名称、卡片样式等。这些卡片信息必须作为持久数据进行管理，以便后续更新和删除卡片。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| formBindingData.FormBindingData | formBindingData.FormBindingData对象，卡片要显示的数据。 |  
    
 **示例代码：**   
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
  
    
### onCastToNormalForm    
卡片提供方接收临时卡片转常态卡片的通知接口。  
 **调用形式：**     
- onCastToNormalForm(formId: string): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId | string | true | 请求转换为常态的卡片标识。 |  
    
 **示例代码：**   
```ts    
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';  
  
export default class MyFormExtensionAbility extends FormExtensionAbility {  
  onCastToNormalForm(formId: string) {  
    console.log(`FormExtensionAbility onCastToNormalForm, formId: ${formId}`);  
  }  
};  
    
```    
  
    
### onUpdateForm    
卡片提供方接收更新卡片的通知接口。获取最新数据后调用formProvider的[updateForm](js-apis-app-form-formProvider.md#updateform)接口刷新卡片数据。  
 **调用形式：**     
- onUpdateForm(formId: string): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId | string | true | 请求更新的卡片ID。 |  
    
 **示例代码：**   
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
  
    
### onChangeFormVisibility    
卡片提供方接收修改可见性的通知接口。  
 **调用形式：**     
- onChangeFormVisibility(newStatus: { [key: string]: number }): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| newStatus | { [key: string]: number } | true | 请求修改的卡片标识和可见状态。 |  
    
 **示例代码：**   
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
  
    
### onFormEvent    
卡片提供方接收处理卡片事件的通知接口。  
 **调用形式：**     
- onFormEvent(formId: string, message: string): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId | string | true | 请求触发事件的卡片标识。 |  
| message | string | true | 事件消息。 |  
    
 **示例代码：**   
```ts    
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';  
  
export default class MyFormExtensionAbility extends FormExtensionAbility {  
  onFormEvent(formId: string, message: string) {  
    console.log(`FormExtensionAbility onFormEvent, formId: ${formId}, message: ${message}`);  
  }  
};  
    
```    
  
    
### onRemoveForm    
卡片提供方接收销毁卡片的通知接口。  
 **调用形式：**     
- onRemoveForm(formId: string): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId | string | true | 请求销毁的卡片标识。 |  
    
 **示例代码：**   
```ts    
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';  
  
export default class MyFormExtensionAbility extends FormExtensionAbility {  
  onRemoveForm(formId: string) {  
    console.log(`FormExtensionAbility onRemoveForm, formId: ${formId}`);  
  }  
};  
    
```    
  
    
### onConfigurationUpdate    
当系统配置更新时调用。  
 **调用形式：**     
- onConfigurationUpdate(newConfig: Configuration): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| newConfig | Configuration | true | 表示需要更新的配置信息。 |  
    
 **示例代码：**   
```ts    
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';  
import { Configuration } from '@ohos.app.ability.Configuration';  
  
export default class MyFormExtensionAbility extends FormExtensionAbility {  
  onConfigurationUpdate(config: Configuration) {  
    console.log(`onConfigurationUpdate, config: ${JSON.stringify(config)}`);  
  }  
};  
    
```    
  
    
### onAcquireFormState    
卡片提供方接收查询卡片状态通知接口。默认返回卡片初始状态。  
 **调用形式：**     
- onAcquireFormState?(want: Want): formInfo.FormState  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | want表示获取卡片状态的描述。描述包括Bundle名称、能力名称、模块名称、卡片名和卡片维度。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| formInfo.FormState |  |  
    
 **示例代码：**   
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
  
