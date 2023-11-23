# @ohos.app.form.formProvider    
FormProvider模块提供了卡片提供方相关接口的能力，开发者在开发卡片时，可通过该模块提供接口实现更新卡片、设置卡片更新时间、获取卡片信息、请求发布卡片等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import formProvider from '@ohos.app.form.formProvider'    
```  
    
## setFormNextRefreshTime    
设置指定卡片的下一次更新时间，使用callback异步回调。  
 **调用形式：**     
    
- setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setFormNextRefreshTime(formId: string, minute: number): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId | string | true | 卡片标识。 |  
| minute | number | true | 指定多久之后更新，单位分钟，大于等于5。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | If the input parameter is not valid parameter. |  
| 16500050 | An IPC connection error happened. |  
| 16500060 | A service connection error happened, please try again later. |  
| 16500100 | Failed to obtain the configuration information. |  
| 16501000 | An internal functional error occurred. |  
| 16501001 | The ID of the form to be operated does not exist. |  
| 16501002 | The number of forms exceeds upper bound. |  
| 16501003 | The form can not be operated by the current application. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import Base from '@ohos.base';  
  
let formId: string = '12400633174999288';  
try {  
  formProvider.setFormNextRefreshTime(formId, 5, (error: Base.BusinessError) => {  
    if (error) {  
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);  
      return;  
    }  
    console.log(`formProvider setFormNextRefreshTime success`);  
  });  
} catch (error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import Base from '@ohos.base';  
  
let formId: string = '12400633174999288';  
try {  
  formProvider.setFormNextRefreshTime(formId, 5).then(() => {  
    console.log(`formProvider setFormNextRefreshTime success`);  
  }).catch((error: Base.BusinessError) => {  
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);  
  });  
} catch (error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
}  
    
```    
  
    
## updateForm    
更新指定的卡片，使用callback异步回调。  
 **调用形式：**     
    
- updateForm(     formId: string,     formBindingData: formBindingData.FormBindingData,     callback: AsyncCallback\<void>   ): void    
起始版本： 9    
- updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId | string | true | 请求更新的卡片标识。 |  
| formBindingData | formBindingData.FormBindingData | true | 用于更新的数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | If the input parameter is not valid parameter. |  
| 16500050 | An IPC connection error happened. |  
| 16500060 | A service connection error happened, please try again later. |  
| 16500100 | Failed to obtain the configuration information. |  
| 16501000 | An internal functional error occurred. |  
| 16501001 | The ID of the form to be operated does not exist. |  
| 16501003 | The form can not be operated by the current application. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import formBindingData from '@ohos.app.form.formBindingData';  
import Base from '@ohos.base';  
  
let formId: string = '12400633174999288';  
try {  
  let param: Record<string, string> = {  
    'temperature': '22c',  
    'time': '22:00'  
  }  
  let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);  
  formProvider.updateForm(formId, obj, (error: Base.BusinessError) => {  
    if (error) {  
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);  
      return;  
    }  
    console.log(`formProvider updateForm success`);  
  });  
} catch (error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
  
```ts    
import formBindingData from '@ohos.app.form.formBindingData';  
import Base from '@ohos.base';  
  
let formId: string = '12400633174999288';  
let param: Record<string, string> = {  
  'temperature': '22c',  
  'time': '22:00'  
}  
let obj: formBindingData.FormBindingData = formBindingData.createFormBindingData(param);  
try {  
  formProvider.updateForm(formId, obj).then(() => {  
    console.log(`formProvider updateForm success`);  
  }).catch((error: Base.BusinessError) => {  
    console.error(`promise error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
  });  
} catch (error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
}  
    
```    
  
    
## getFormsInfo    
获取设备上当前应用程序的卡片信息，使用callback异步回调。  
 **调用形式：**     
    
- getFormsInfo(filter: formInfo.FormInfoFilter, callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void    
起始版本： 9    
- getFormsInfo(callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void    
起始版本： 9    
- getFormsInfo(filter?: formInfo.FormInfoFilter): Promise\<Array\<formInfo.FormInfo>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filter | formInfo.FormInfoFilter | true | 卡片信息过滤器。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回查询到的卡片信息。 |  
| Promise<Array<formInfo.FormInfo>> | Promise对象。返回查询到符合条件的卡片信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | If the input parameter is not valid parameter. |  
| 16500050 | An IPC connection error happened. |  
| 16500100 | Failed to obtain the configuration information. |  
| 16501000 | An internal functional error occurred. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import Base from '@ohos.base';  
import formInfo from '@ohos.app.form.formInfo';  
  
const filter: formInfo.FormInfoFilter = {  
  // get info of forms belong to module entry.  
  moduleName: 'entry'  
};  
try {  
  formProvider.getFormsInfo(filter, (error, data) => {  
    if (error) {  
      console.error(`callback error, code: ${error.code}, message: ${error.message})`);  
      return;  
    }  
    console.log(`formProvider getFormsInfo, data: ${JSON.stringify(data)}`);  
  });  
} catch (error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import formInfo from '@ohos.app.form.formInfo';  
import Base from '@ohos.base';  
  
const filter: formInfo.FormInfoFilter = {  
  // get info of forms belong to module entry.  
  moduleName: 'entry'  
};  
try {  
  formProvider.getFormsInfo(filter).then((data: formInfo.FormInfo[]) => {  
    console.log(`formProvider getFormsInfo, data: ${JSON.stringify(data)}`);  
  }).catch((error: Base.BusinessError) => {  
    console.error(`promise error, code: ${error.code}, message: ${error.message})`);  
  });  
} catch (error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message})`);  
}  
    
```    
  
