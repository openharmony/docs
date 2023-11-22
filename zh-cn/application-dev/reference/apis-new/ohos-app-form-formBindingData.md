# @ohos.app.form.formBindingData    
卡片数据绑定模块提供卡片数据绑定的能力。包括FormBindingData对象的创建、相关信息的描述。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import formBindingData from '@ohos.app.form.formBindingData'    
```  
    
## createFormBindingData    
创建一个FormBindingData对象。  
 **调用形式：**     
- createFormBindingData(obj?: Object | string): FormBindingData  
  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| obj | string | false | js卡片要展示的数据。可以是包含若干键值对的Object或者 json 格式的字符串。其中图片数据以'formImages'作为标识，内容为图片标识与图片文件描述符的键值对{'formImages': {'key1': fd1, 'key2': fd2}} |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FormBindingData | 根据传入数据创建的FormBindingData对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formBindingData from '@ohos.app.form.formBindingData';  
import fs from '@ohos.file.fs';  
import Base from '@ohos.base';  
  
try {  
  let fd = fs.openSync('/path/to/form.png');  
  
  let createFormBindingDataParam = new Map<string, string | Object>();  
  let formImagesParam = new Map<string, Object>();  
  formImagesParam.set('image', fd);  
  createFormBindingDataParam.set("name", '21°');  
  createFormBindingDataParam.set('formImages', formImagesParam);  
  
  formBindingData.createFormBindingData(createFormBindingDataParam);  
} catch (error) {  
  let code = (error as Base.BusinessError).code;  
  let message = (error as Base.BusinessError).message;  
  console.error(`catch error, code: ${code}, message: ${message}`);  
}  
    
```    
  
    
## FormBindingData    
FormBindingData相关描述。  
 **系统能力:**  SystemCapability.Ability.Form    
### 属性    
 **系统能力:**  SystemCapability.Ability.Form    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| data | Object | false | true | js卡片要展示的数据。可以是包含若干键值对的Object或者 json 格式的字符串。 |  
| proxies<sup>(10+)</sup> | Array<ProxyData> | false | false | 模型约束：本模块接口仅可在Stage模型下使用。<br>卡片代理刷新的订阅信息，默认为空数组。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |  
    
## ProxyData<sup>(10+)</sup>    
卡片代理刷新订阅数据信息。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.Ability.Form    
### 属性    
 **系统能力:**  SystemCapability.Ability.Form    
 **模型约束：** 本模块接口仅可在Stage模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| key<sup>(10+)</sup> | string | false | true | 卡片代理刷新的订阅标识，与数据发布者保持一致。 |  
| subscriberId<sup>(10+)</sup> | string | false | false | 卡片代理刷新的订阅条件，默认值为当前卡片的formId。 |  
