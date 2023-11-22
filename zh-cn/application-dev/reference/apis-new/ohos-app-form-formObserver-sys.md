# @ohos.app.form.formObserver    
formObserver模块提供了卡片监听方相关接口的能力，包括对同一用户下安装的卡片新增、删除、可见性变化事件的订阅和取消订阅，获取正在运行的卡片信息等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import formObserver from '@ohos.app.form.formObserver'    
```  
    
## on('formAdd')    
订阅卡片新增事件。使用callback异步回调，返回当前新增卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。  
 **调用形式：**     
- on(type: 'formAdd', observerCallback: Callback\<formInfo.RunningFormInfo>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 填写'formAdd'，表示卡片新增事件。 |  
| observerCallback | Callback<formInfo.RunningFormInfo> | true | 回调函数。返回新增卡片的RunningFormInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
formObserver.on('formAdd', (data: formInfo.RunningFormInfo) => {  console.log(`a new form added, data: ${JSON.stringify(data)}`);});    
```    
  
    
## on('formAdd')    
订阅卡片新增事件。使用callback异步回调，返回指定卡片使用方应用新增卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。  
 **调用形式：**     
- on(type: 'formAdd', hostBundleName: string, observerCallback: Callback\<formInfo.RunningFormInfo>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 填写'formAdd'，表示卡片新增事件。 |  
| hostBundleName | string | true | 指定订阅卡片使用方包的bundleName。缺省则订阅所有卡片使用方的卡片新增事件。 |  
| observerCallback | Callback<formInfo.RunningFormInfo> | true | 回调函数。返回新增卡片的RunningFormInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
let bundleName: string = 'ohos.samples.FormApplication';  
formObserver.on('formAdd', bundleName, (data: formInfo.RunningFormInfo) => {  console.log(`a new form added, data: ${JSON.stringify(data)}`);});    
```    
  
    
## off('formAdd')    
取消订阅卡片新增事件。使用callback异步回调，返回当前新增卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。  
 **调用形式：**     
- off(type: 'formAdd', hostBundleName?: string, observerCallback?: Callback\<formInfo.RunningFormInfo>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 填写'formAdd'，表示卡片新增事件。 |  
| hostBundleName | string | false | 指定订阅卡片使用方包的bundleName。<br> 填写该参数时，与注册时填写bundleName的on接口对应。<br> 缺省则订阅所有卡片使用方的卡片删除事件，与注册时未填写bundleName的on接口相对应。 |  
| observerCallback | Callback<formInfo.RunningFormInfo> | false | 回调函数。返回卡片RunningFormInfo。缺省时，表示注销对应已注册事件回调。<br> 需与对应on('formAdd')的callback一致。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
let bundleName: string = 'ohos.samples.FormApplication';formObserver.off('formAdd', bundleName, (data: formInfo.RunningFormInfo) => {  console.log(`a new form added, data: ${JSON.stringify(data)}`);});    
```    
  
    
## on('formRemove')    
订阅卡片删除事件。使用callback异步回调，返回当前删除卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。  
 **调用形式：**     
- on(type: 'formRemove', observerCallback: Callback\<formInfo.RunningFormInfo>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | <span style="letter-spacing: 0px;">填</span>写'formRemove'，表示卡片删除事件。 |  
| observerCallback | Callback<formInfo.RunningFormInfo> | true | 回调函数。返回删除卡片的RunningFormInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
formObserver.on('formRemove', (data: formInfo.RunningFormInfo) => {  console.log(`form deleted, data: ${JSON.stringify(data)}`);});    
```    
  
    
## on('formRemove')    
订阅卡片删除事件。使用callback异步回调，返回指定卡片使用方应用被删除卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。  
 **调用形式：**     
- on(type: 'formRemove', hostBundleName: string, observerCallback: Callback\<formInfo.RunningFormInfo>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 填写'formRemove'，表示卡片删除事件。 |  
| hostBundleName | string | true | 指定订阅卡片使用方包的bundleName。缺省则订阅所有卡片使用方的卡片删除事件。 |  
| observerCallback | Callback<formInfo.RunningFormInfo> | true | 回调函数。返回删除卡片的RunningFormInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
let bundleName: string = 'ohos.samples.FormApplication';formObserver.on('formRemove', bundleName, (data: formInfo.RunningFormInfo) => {  console.log(`form deleted, data: ${JSON.stringify(data)}`);});    
```    
  
    
## off('formRemove')    
取消订阅卡片删除事件。使用callback异步回调，返回当前删除卡片的[RunningFormInfo](js-apis-app-form-formInfo.md)。  
 **调用形式：**     
- off(type: 'formRemove', hostBundleName?: string, observerCallback?: Callback\<formInfo.RunningFormInfo>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 填写'formRemove'，表示卡片删除事件。 |  
| hostBundleName | string | false | 指定订阅卡片使用方包的bundleName。<br> 填写该参数时，与注册时填写bundleName的on接口对应。<br> 缺省则订阅所有卡片使用方的卡片删除事件，与注册时未填写bundleName的on接口相对应。 |  
| observerCallback | Callback<formInfo.RunningFormInfo> | false | 回调函数。返回卡片RunningFormInfo。缺省时，表示注销对应已注册事件回调。<br> 需与对应on('formRemove')的callback一致。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
let bundleName: string = 'ohos.samples.FormApplication';formObserver.off('formRemove', bundleName, (data: formInfo.RunningFormInfo) => {  console.log(`a new form added, data: ${JSON.stringify(data)}`);});    
```    
  
    
## on('notifyVisible')    
订阅通知卡片可见的事件。触发通知卡片可见场景为：调用notifyVisibleForms接口通知对应卡片可见性变更为可见状态。  
 **调用形式：**     
- on(type: 'notifyVisible', observerCallback: Callback\<Array\<formInfo.RunningFormInfo>>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 仅允许填写'notifyVisible'，表示订阅通知卡片可见的事件。 |  
| observerCallback | Callback<Array<formInfo.RunningFormInfo>> | true | 回调函数。返回订阅通知卡片可见的RunningFormInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
formObserver.on('notifyVisible', (data: formInfo.RunningFormInfo[]) => {  console.log(`form change visibility, data: ${JSON.stringify(data)}`);});    
```    
  
    
## on('notifyVisible')  
 **调用形式：**     
- on(     type: 'notifyVisible',     hostBundleName: string,     observerCallback: Callback\<Array\<formInfo.RunningFormInfo>>   ): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 仅允许填写'notifyVisible'，表示订阅通知卡片可见的事件。 |  
| hostBundleName | string | true | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。 |  
| observerCallback | Callback<Array<formInfo.RunningFormInfo>> | true | 回调函数。返回订阅通知卡片可见的RunningFormInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
let bundleName: string = 'ohos.samples.FormApplication';formObserver.on('notifyVisible', bundleName, (data: formInfo.RunningFormInfo[]) => {  console.log(`form change visibility, data: ${JSON.stringify(data)}`);});    
```    
  
    
## on('notifyInvisible')    
订阅通知卡片不可见的事件。触发通知卡片不可见场景为：调用notifyInvisibleForms接口通知对应卡片可见性变更为不可见状态。  
 **调用形式：**     
- on(type: 'notifyInvisible', observerCallback: Callback\<Array\<formInfo.RunningFormInfo>>): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 仅允许填写'notifyInvisible'，表示订阅卡片不可见的事件。 |  
| observerCallback | Callback<Array<formInfo.RunningFormInfo>> | true | 回调函数。返回订阅通知卡片不可见的RunningFormInfo。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
formObserver.on('notifyInvisible', (data: formInfo.RunningFormInfo[]) => {  console.log(`form change invisibility, data: ${JSON.stringify(data)}`);});    
```    
  
    
## on('notifyInvisible')  
 **调用形式：**     
- on(     type: 'notifyInvisible',     hostBundleName: string,     observerCallback: Callback\<Array\<formInfo.RunningFormInfo>>,   ): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 仅允许填写'notifyVisible'，表示取消订阅通知卡片为可见的事件。 |  
| hostBundleName | string | true | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。<br> 填写该参数时，与注册时填写bundleName的on接口对应。 |  
| observerCallback | Callback<Array<formInfo.RunningFormInfo>> | true | 入参，注册时注册进去的callback。缺省时，表示注销对应已注册订阅的回调。<br> 需与对应on('notifyVisible')的callback一致。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
let bundleName: string = 'ohos.samples.FormApplication';formObserver.on('notifyVisible', bundleName, (data: formInfo.RunningFormInfo[]) => {  console.log(`form change visibility, data: ${JSON.stringify(data)}`);});    
```    
  
    
## off('notifyVisible')    
取消订阅通知卡片可见的事件。  
 **调用形式：**     
- off(     type: 'notifyVisible',     hostBundleName?: string,     observerCallback?: Callback\<Array\<formInfo.RunningFormInfo>>   ): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 允许填写'notifyVisible'，表示取消订阅通知卡片为可见的事件。 |  
| hostBundleName | string | false | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。<br> 填写该参数时，与注册时填写bundleName的on接口对应。 |  
| observerCallback | Callback<Array<formInfo.RunningFormInfo>> | false | 入参，注册时注册进去的callback。缺省时，表示注销对应已注册订阅的回调。<br> 需与对应on('notifyVisible')的callback一致。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
let bundleName: string = 'ohos.samples.FormApplication';formObserver.off('notifyVisible', bundleName, (data: formInfo.RunningFormInfo[]) => {  console.log(`form change visibility, data: ${JSON.stringify(data)}`);});    
```    
  
    
## off('notifyInvisible')    
取消订阅通知卡片不可见事件。  
 **调用形式：**     
- off(     type: 'notifyInvisible',     hostBundleName?: string,     observerCallback?: Callback\<Array\<formInfo.RunningFormInfo>>   ): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 仅允许填写'notifyInvisible'，表示卡片可见性变更为不可见。 |  
| hostBundleName | string | false | 指定卡片使用方的bundleName，用于订阅卡片在该使用方的可见状态变更事件。<br> 填写该参数时，与注册时填写bundleName的on接口对应。<br> |  
| observerCallback | Callback<Array<formInfo.RunningFormInfo>> | false | 入参，注册时注册进去的callback。缺省时，表示注销对应已注册事件回调。<br/> 需与对应on('notifyInvisible')的callback一致。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
import formObserver from '@ohos.app.form.formObserver';import formInfo from '@ohos.app.form.formInfo';  
let bundleName: string = 'ohos.samples.FormApplication';formObserver.off('notifyInvisible', bundleName, (data: formInfo.RunningFormInfo[]) => {  console.log(`form change invisibility, data: ${JSON.stringify(data)}`);});    
```    
  
    
## getRunningFormInfos    
获取设备上正在运行的所有非临时卡片信息。使用callback异步回调。  
 **调用形式：**     
    
- getRunningFormInfos(callback: AsyncCallback\<Array\<formInfo.RunningFormInfo>>, hostBundleName?: string): void    
起始版本： 10    
- getRunningFormInfos(hostBundleName?: string): Promise\<Array\<formInfo.RunningFormInfo>>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hostBundleName | string | false | 指定要查询的卡片使用方名称，指定后会仅返回该卡片使用方下正在运行的非临时卡片信息。 <br> 缺省时，返回设备上所有正在运行的非临时卡片信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。获取设备上指定应用为卡片使用方的当前卡片信息成功，error为undefined，data为查询到的卡片信息。 |  
| Promise<Array<formInfo.RunningFormInfo>> | Promise对象，返回查询到的卡片信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16500050 | An IPC connection error happened. |  
| 16500060 | A service connection error happened, please try again later. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import formObserver from '@ohos.app.form.formObserver';  
import formInfo from '@ohos.app.form.formInfo';  
import Base from '@ohos.base';  
  
try {  
  formObserver.getRunningFormInfos((error: Base.BusinessError, data: formInfo.RunningFormInfo[]) => {  
    if (error) {  
      console.error(`error, code: ${error.code}, message: ${error.message}`);  
    } else {  
      console.log(`formObserver getRunningFormInfos, data: ${JSON.stringify(data)}`);  
    }  
  }, true, 'com.example.ohos.formjsdemo');  
} catch(error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import formObserver from '@ohos.app.form.formObserver';  
import formInfo from '@ohos.app.form.formInfo';  
import Base from '@ohos.base';  
  
try {  
  formObserver.getRunningFormInfos(true, 'com.example.ohos.formjsdemo').then((data: formInfo.RunningFormInfo[]) => {  
    console.log(`formObserver getRunningFormInfos, data: ${JSON.stringify(data)}`);  
  }).catch((error: Base.BusinessError) => {  
    console.error(`error, code: ${error.code}, message: ${error.message}`);  
  });  
} catch(error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);  
}  
    
```    
  
    
## getRunningFormInfosByFilter    
根据提供方信息查询卡片已有的使用方列表信息。使用Promise异步回调。  
 **调用形式：**     
    
- getRunningFormInfosByFilter(     formProviderFilter: formInfo.FormProviderFilter   ): Promise\<Array\<formInfo.RunningFormInfo>>    
起始版本： 10    
- getRunningFormInfosByFilter(     formProviderFilter: formInfo.FormProviderFilter,     callback: AsyncCallback\<Array\<formInfo.RunningFormInfo>>   ): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formProviderFilter | formInfo.FormProviderFilter | true | 卡片提供方应用信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回查询到的使用方列表信息，error为undefined，data为查询到的使用方列表信息；否则为错误对象。 |  
| Promise<Array<formInfo.RunningFormInfo>> | Promise对象，返回查询到的使用方列表信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permissions denied. |  
| 202 | The application is not a system application. |  
| 401 | If the input parameter is not valid parameter. |  
| 16500050 | An IPC connection error happened. |  
| 16500100 | Failed to obtain the configuration information. |  
| 16501000 | An internal functional error occurred. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import formObserver from '@ohos.app.form.formObserver';  
import formInfo from '@ohos.app.form.formInfo';  
import Base from '@ohos.base';  
  
let formInstanceFilter: formInfo.FormProviderFilter = {  
  bundleName: "com.example.formprovide",  
  abilityName: "EntryFormAbility",  
  formName: "widget",  
  moduleName: "entry"  
}  
try {  
  formObserver.getRunningFormInfosByFilter(formInstanceFilter).then((data: formInfo.RunningFormInfo[]) => {  
    console.info('formObserver getRunningFormInfosByFilter success, data:' + JSON.stringify(data));  
  }).catch((error: Base.BusinessError) => {  
    console.error(`error, code: ${error.code}, message: ${error.message}`);  
  });  
} catch(error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码2：**   
  
示例(callback):  
```ts    
import formObserver from '@ohos.app.form.formObserver';  
import formInfo from '@ohos.app.form.formInfo';  
import Base from '@ohos.base';  
  
let formInstanceFilter: formInfo.FormProviderFilter = {  
  bundleName: "com.example.formprovide",  
  abilityName: "EntryFormAbility",  
  formName: "widget",  
  moduleName: "entry"  
}  
try {  
  formObserver.getRunningFormInfosByFilter(formInstanceFilter,(error: Base.BusinessError, data: formInfo.RunningFormInfo[]) => {  
    if (error) {  
      console.error(`error, code: ${error.code}, message: ${error.message}`);  
    } else {  
      console.log(`formObserver getRunningFormInfosByFilter, data: ${JSON.stringify(data)}`);  
    }  
  });  
} catch(error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);  
}  
    
```    
  
    
## getRunningFormInfoById    
根据formId查询卡片已有的使用方列表信息。使用Promise异步回调。  
 **调用形式：**     
    
- getRunningFormInfoById(formId: string): Promise\<formInfo.RunningFormInfo>    
起始版本： 10    
- getRunningFormInfoById(formId: string, callback: AsyncCallback\<formInfo.RunningFormInfo>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.OBSERVE_FORM_RUNNING    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId | string | true | 卡片标识。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回查询到的使用方列表信息，error为undefined，data为查询到的使用方列表信息；否则为错误对象。 |  
| Promise<formInfo.RunningFormInfo> | Promise对象，返回查询到的使用方列表信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permissions denied. |  
| 202 | The application is not a system application. |  
| 401 | If the input parameter is not valid parameter. |  
| 16500050 | An IPC connection error happened. |  
| 16500100 | Failed to obtain the configuration information. |  
| 16501000 | An internal functional error occurred. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import formObserver from '@ohos.app.form.formObserver';  
import formInfo from '@ohos.app.form.formInfo';  
import Base from '@ohos.base';  
  
let formId: string = '12400633174999288';  
try {  
  formObserver.getRunningFormInfoById(formId).then((data: formInfo.RunningFormInfo) => {  
    console.info('formObserver getRunningFormInfoById success, data:' + JSON.stringify(data));  
  }).catch((error: Base.BusinessError) => {  
    console.error(`error, code: ${error.code}, message: ${error.message}`);  
  });  
} catch(error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import formObserver from '@ohos.app.form.formObserver';  
import formInfo from '@ohos.app.form.formInfo';  
import Base from '@ohos.base';  
  
let formId: string = '12400633174999288';  
try {  
  formObserver.getRunningFormInfoById(formId, true, (error: Base.BusinessError, data: formInfo.RunningFormInfo) => {  
    if (error) {  
      console.error(`error, code: ${error.code}, message: ${error.message}`);  
    } else {  
      console.log(`formObserver getRunningFormInfoById, data: ${JSON.stringify(data)}`);  
    }  
  });  
} catch(error) {  
  console.error(`catch error, code: ${(error as Base.BusinessError).code}, message: ${(error as Base.BusinessError).message}`);  
}  
    
```    
  
