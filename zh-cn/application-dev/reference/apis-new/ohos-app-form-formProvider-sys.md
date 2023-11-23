# @ohos.app.form.formProvider    
FormProvider模块提供了卡片提供方相关接口的能力，开发者在开发卡片时，可通过该模块提供接口实现更新卡片、设置卡片更新时间、获取卡片信息、请求发布卡片等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import formProvider from '@ohos.app.form.formProvider'    
```  
    
## requestPublishForm    
请求发布一张卡片到使用方。使用方通常为桌面，使用callback异步回调。  
 **调用形式：**     
    
- requestPublishForm(     want: Want,     formBindingData: formBindingData.FormBindingData,     callback: AsyncCallback\<string>   ): void    
起始版本： 9    
- requestPublishForm(want: Want, callback: AsyncCallback\<string>): void    
起始版本： 9    
- requestPublishForm(want: Want, formBindingData?: formBindingData.FormBindingData): Promise\<string>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 发布请求。需包含以下字段。<br>abilityName: 目标卡片ability<br>parameters:<br>'ohos.extra.param.key.form_dimension'<br>'ohos.extra.param.key.form_name'<br>'ohos.extra.param.key.module_name'。 |  
| formBindingData | formBindingData.FormBindingData | true | 创建卡片的数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 创建卡片的数据。 |  
| Promise<string> | Promise对象。返回卡片标识。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | The application is not a system application |  
| 401 | If the input parameter is not valid parameter. |  
| 16500050 | An IPC connection error happened. |  
| 16500100 | Failed to obtain the configuration information. |  
| 16501000 | An internal functional error occurred. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import formBindingData from '@ohos.app.form.formBindingData';  
import Want from '@ohos.app.ability.Want';  
import Base from '@ohos.base';  
  
let want: Want = {  
  abilityName: 'FormAbility',  
  parameters: {  
    'ohos.extra.param.key.form_dimension': 2,  
    'ohos.extra.param.key.form_name': 'widget',  
    'ohos.extra.param.key.module_name': 'entry'  
  }  
};  
try {  
  let param: Record<string, string> = {  
    'temperature': '22c',  
    'time': '22:00'  
  }  
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);  
  formProvider.requestPublishForm(want, obj, (error: Base.BusinessError, data: string) => {  
    if (error) {  
      console.error(`callback error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
      return;  
    }  
    console.log('formProvider requestPublishForm, form ID is: ${JSON.stringify(data)}');  
  });  
} catch (error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import Want from '@ohos.app.ability.Want';  
import Base from '@ohos.base';  
  
let want: Want = {  
  abilityName: 'FormAbility',  
  parameters: {  
    'ohos.extra.param.key.form_dimension': 2,  
    'ohos.extra.param.key.form_name': 'widget',  
    'ohos.extra.param.key.module_name': 'entry'  
  }  
};  
try {  
  formProvider.requestPublishForm(want).then((data: string) => {  
    console.log(`formProvider requestPublishForm success, form ID is : ${JSON.stringify(data)}`);  
  }).catch((error: Base.BusinessError) => {  
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);  
  });  
} catch (error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
}  
    
```    
  
    
## isRequestPublishFormSupported    
查询是否支持发布一张卡片到使用方，使用callback异步回调。  
 **调用形式：**     
    
- isRequestPublishFormSupported(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isRequestPublishFormSupported(): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回是否支持发布一张卡片到使用方。 |  
| Promise<boolean> | Promise对象。返回是否支持发布一张卡片到使用方。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | The application is not a system application |  
| 401 | If the input parameter is not valid parameter. |  
| 16500050 | An IPC connection error happened. |  
| 16501000 | An internal functional error occurred. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import Want from '@ohos.app.ability.Want';  
import Base from '@ohos.base';  
  
try {  
  formProvider.isRequestPublishFormSupported((error: Base.BusinessError, isSupported: boolean) => {  
    if (error) {  
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);  
    } else {  
      if (isSupported) {  
        let want: Want = {  
          abilityName: 'FormAbility',  
          parameters: {  
            'ohos.extra.param.key.form_dimension': 2,  
            'ohos.extra.param.key.form_name': 'widget',  
            'ohos.extra.param.key.module_name': 'entry'  
          }  
        };  
        try {  
          formProvider.requestPublishForm(want, (error: Base.BusinessError, data: string) => {  
            if (error) {  
              console.error(`callback error, code: ${error.code}, message: ${error.message})`);  
              return;  
            }  
            console.log(`formProvider requestPublishForm, form ID is: ${JSON.stringify(data)}`);  
          });  
        } catch (error) {  
          console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
        }  
      }  
    }  
  });  
} catch (error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import Want from '@ohos.app.ability.Want';  
import Base from '@ohos.base';  
  
try {  
  formProvider.isRequestPublishFormSupported().then((isSupported: boolean) => {  
    if (isSupported) {  
      let want: Want = {  
        abilityName: 'FormAbility',  
        parameters: {  
          'ohos.extra.param.key.form_dimension': 2,  
          'ohos.extra.param.key.form_name': 'widget',  
          'ohos.extra.param.key.module_name': 'entry'  
        }  
      };  
      try {  
        formProvider.requestPublishForm(want).then((data: string) => {  
          console.log(`formProvider requestPublishForm success, form ID is : ${JSON.stringify(data)}`);  
        }).catch((error: Base.BusinessError) => {  
          console.error(`promise error, code: ${error.code}, message: ${error.message})`);  
        });  
      } catch (error) {  
        console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
      }  
    }  
  }).catch((error: Base.BusinessError) => {  
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);  
  });  
} catch (error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
}  
    
```    
  
