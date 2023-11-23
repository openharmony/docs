# @ohos.application.formInfo    
formInfo模块提供了卡片信息和状态等相关类型和枚举。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import formInfo from '@ohos.application.formInfo'    
```  
    
## FormInfo<sup>(deprecated)</sup>    
卡片信息    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo#FormInfo替代。  
 **系统能力:**  SystemCapability.Ability.Form    
### 属性    
 **系统能力:**  SystemCapability.Ability.Form    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#bundleName替代。<br>表示卡片所属包的Bundle名称。     |  
| moduleName<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#moduleName替代。<br>表示卡片所属模块的模块名。 |  
| abilityName<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#abilityName替代。<br>表示卡片所属的Ability名称。   |  
| name<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#name替代。<br>表示卡片名称。  |  
| description<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#description替代。<br>表示卡片描述。  |  
| type<sup>(deprecated)</sup> | FormType | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#type替代。<br>表示卡片类型，当前支持JS卡片。 |  
| jsComponentName<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#jsComponentName替代。<br>表示js卡片的组件名。   |  
| colorMode<sup>(deprecated)</sup> | ColorMode | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#colorMode替代。<br>表示卡片颜色模式。 |  
| isDefault<sup>(deprecated)</sup> | boolean | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#isDefault替代。<br>表示是否是默认卡片。 |  
| updateEnabled<sup>(deprecated)</sup> | boolean | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#updateEnabled替代。<br>表示卡片是否使能更新。  |  
| formVisibleNotify<sup>(deprecated)</sup> | boolean | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#formVisibleNotify替代。<br>表示卡片是否使能可见通知。 |  
| relatedBundleName<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示卡片所属的相关联Bundle名称。  |  
| scheduledUpdateTime<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#scheduledUpdateTime替代。<br>表示卡片更新时间。 |  
| formConfigAbility<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#formConfigAbility替代。<br>表示卡片配置ability。 |  
| updateDuration<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#updateDuration替代。<br>表示卡片更新周期。 |  
| defaultDimension<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#defaultDimension替代。<br>表示卡片规格  |  
| supportDimensions<sup>(deprecated)</sup> | Array<number> | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#supportDimensions替代。<br>表示卡片支持的规格。 |  
| customizeData<sup>(deprecated)</sup> | object | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormInfo#customizeData替代。<br>表示卡片用户数据。  |  
    
## FormType<sup>(deprecated)</sup>    
支持的卡片类型枚举。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo#FormType替代。    
    
 **系统能力:**  SystemCapability.Ability.Form    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| JS<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormType#JS替代。<br>卡片类型为JS。 |  
    
## ColorMode<sup>(deprecated)</sup>    
卡片支持的颜色模式枚举。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo#ColorMode替代。    
    
 **系统能力:**  SystemCapability.Ability.Form    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MODE_AUTO<sup>(deprecated)</sup> | -1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.ColorMode#MODE_AUTO替代。<br>表示自动模式。  |  
| MODE_DARK<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.ColorMode#MODE_DARK替代。<br>表示暗色。 |  
| MODE_LIGHT<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.ColorMode#MODE_LIGHT替代。<br>表示亮色。  |  
    
## FormStateInfo<sup>(deprecated)</sup>    
卡片状态信息。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo#FormStateInfo替代。  
 **系统能力:**  SystemCapability.Ability.Form    
### 属性    
 **系统能力:**  SystemCapability.Ability.Form    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| formState<sup>(deprecated)</sup> | FormState | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormStateInfo#formState替代。<br>表示卡片状态。  |  
| want<sup>(deprecated)</sup> | Want | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormStateInfo#want替代。<br>Want文本内容。  |  
    
## FormState<sup>(deprecated)</sup>    
卡片状态枚举。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo#FormState替代。    
    
 **系统能力:**  SystemCapability.Ability.Form    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN<sup>(deprecated)</sup> | -1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormState#UNKNOWN替代。<br>表示未知状态。 |  
| DEFAULT<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormState#DEFAULT替代。<br>表示默认状态。 |  
| READY<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormState#READY替代。<br>表示就绪状态。 |  
    
## FormParam<sup>(deprecated)</sup>    
卡片参数枚举。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo#FormParam替代。    
    
 **系统能力:**  SystemCapability.Ability.Form    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DIMENSION_KEY<sup>(deprecated)</sup> | ohos.extra.param.key.form_dimension | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormParam#DIMENSION_KEY替代。<br>卡片规格样式。 |  
| NAME_KEY<sup>(deprecated)</sup> | ohos.extra.param.key.form_name | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormParam#NAME_KEY替代。<br>卡片名称。 |  
| MODULE_NAME_KEY<sup>(deprecated)</sup> | ohos.extra.param.key.module_name | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormParam#MODULE_NAME_KEY替代。<br>卡片所属模块名称。  |  
| WIDTH_KEY<sup>(deprecated)</sup> | ohos.extra.param.key.form_width | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormParam#WIDTH_KEY替代。<br>卡片宽度。  |  
| HEIGHT_KEY<sup>(deprecated)</sup> | ohos.extra.param.key.form_height | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormParam#HEIGHT_KEY替代。<br>卡片高度。 |  
| TEMPORARY_KEY<sup>(deprecated)</sup> | ohos.extra.param.key.form_temporary | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formInfo/formInfo.FormParam#TEMPORARY_KEY替代。<br>临时卡片。 |  
