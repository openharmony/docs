# @ohos.application.formBindingData    
卡片数据绑定模块提供卡片数据绑定的能力。包括FormBindingData对象的创建、相关信息的描述。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import formBindingData from '@ohos.application.formBindingData'    
```  
    
## createFormBindingData<sup>(deprecated)</sup>    
创建一个FormBindingData对象。  
 **调用形式：**     
- createFormBindingData(obj?: Object | string): FormBindingData  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formBindingData/formBindingData#createFormBindingData。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| obj<sup>(deprecated)</sup> | string | false | js卡片要展示的数据。可以是包含若干键值对的Object或者 json 格式的字符串。其中图片数据以'formImages'作为标识，内容为图片标识与图片文件描述符的键值对{'formImages': {'key1': fd1, 'key2': fd2}} |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FormBindingData | 根据传入数据创建的FormBindingData对象。 |  
    
 **示例代码：**   
```ts    
import formBindingData from '@ohos.application.formBindingData';  
import fs from '@ohos.file.fs';  
import Base from '@ohos.base';  
  
try {  
  let fd = fs.openSync('/path/to/form.png');  
  let createFormBindingDataParam = new Map<Object, string | object>();  
  let formImagesParam = new Map<Object, object>();  
  formImagesParam.set('image', fd);  
  createFormBindingDataParam.set("name", '21°');  
  createFormBindingDataParam.set('formImages', formImagesParam);  
  
  formBindingData.createFormBindingData(createFormBindingDataParam);  
} catch (error) {  
  console.error(`catch error, error: ${JSON.stringify(error as Base.BusinessError)}`);  
}  
    
```    
  
    
## FormBindingData<sup>(deprecated)</sup>    
FormBindingData相关描述。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formBindingData/formBindingData#FormBindingData替代。  
 **系统能力:**  SystemCapability.Ability.Form    
### 属性    
 **系统能力:**  SystemCapability.Ability.Form    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| data<sup>(deprecated)</sup> | Object | false | true | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.app.form.formBindingData/formBindingData#FormBindingData替代。<br>js卡片要展示的数据。可以是包含若干键值对的Object或者 json 格式的字符串。 |  
