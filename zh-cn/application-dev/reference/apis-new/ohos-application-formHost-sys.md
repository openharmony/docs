# @ohos.application.formHost    
formHost模块提供了卡片使用方相关接口的能力，包括对使用方同一用户下安装的卡片进行删除、释放、请求更新，获取信息、状态等操作。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import formHost from '@ohos.application.formHost'    
```  
    
## deleteForm<sup>(deprecated)</sup>    
删除指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务不再保留有关该卡片的信息。使用callback异步回调。  
 **调用形式：**     
- deleteForm(formId: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#deleteForm。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId<sup>(deprecated)</sup> | string | true | 卡片标识。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当删除指定的卡片成功，error为undefined，否则为错误对象 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string = '12400633174999288';formHost.deleteForm(formId, (error: Base.BusinessError) => { if (error.code) {  console.error(`formHost deleteForm, error: ${JSON.stringify(error)}`); }});    
```    
  
    
## deleteForm<sup>(deprecated)</sup>    
删除指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务不再保留有关该卡片的信息。使用Promise异步回调。  
 **调用形式：**     
- deleteForm(formId: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#deleteForm。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId<sup>(deprecated)</sup> | string | true | 卡片标识。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string = '12400633174999288';formHost.deleteForm(formId).then(() => { console.log('formHost deleteForm success');}).catch((error: Base.BusinessError) => { console.error(`formHost deleteForm, error: ${JSON.stringify(error)}`);});    
```    
  
    
## releaseForm<sup>(deprecated)</sup>    
释放指定的卡片。调用此方法后，应用程序将无法使用该卡片，但卡片管理器服务仍然保留有关该卡片的缓存信息和存储信息。使用callback异步回调。  
 **调用形式：**     
- releaseForm(formId: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#releaseForm。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId<sup>(deprecated)</sup> | string | true | 卡片标识。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当释放指定的卡片成功，error为undefined；否则为错误对象。 |  
    
## releaseForm<sup>(deprecated)</sup>    
释放指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务保留有关该卡片的存储信息，可以选择是否保留缓存信息。使用callback异步回调。  
 **调用形式：**     
- releaseForm(formId: string, isReleaseCache: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#releaseForm。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId<sup>(deprecated)</sup> | string | true | 卡片标识。  |  
| isReleaseCache<sup>(deprecated)</sup> | boolean | true | 是否释放缓存。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当释放指定的卡片成功，error为undefined；否则为错误对象。<br/> |  
    
## releaseForm<sup>(deprecated)</sup>    
释放指定的卡片。调用此方法后，应用程序将无法使用该卡片，卡片管理器服务保留有关该卡片的存储信息，可以选择是否保留缓存信息。使用Promise异步回调。  
  
 **调用形式：**     
- releaseForm(formId: string, isReleaseCache?: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#releaseForm。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId<sup>(deprecated)</sup> | string | true | 卡片标识。 |  
| isReleaseCache<sup>(deprecated)</sup> | boolean | false | 是否释放缓存，默认为false。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
## requestForm<sup>(deprecated)</sup>    
请求卡片更新。使用callback异步回调。  
 **调用形式：**     
- requestForm(formId: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#requestForm。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId<sup>(deprecated)</sup> | string | true | 卡片标识。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当请求卡片更新成功，error为undefined；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string = '12400633174999288';formHost.castTempForm(formId, (error: Base.BusinessError) => { if (error.code) {  console.error(`formHost castTempForm, error: ${JSON.stringify(error)}`); }});    
```    
  
    
## requestForm<sup>(deprecated)</sup>    
请求卡片更新。使用Promise异步回调。  
 **调用形式：**     
- requestForm(formId: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#requestForm。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId<sup>(deprecated)</sup> | string | true | 卡片标识。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string = '12400633174999288';formHost.requestForm(formId).then(() => { console.log('formHost requestForm success');}).catch((error: Base.BusinessError) => { console.error(`formHost requestForm, error: ${JSON.stringify(error)}`);});    
```    
  
    
## castTempForm<sup>(deprecated)</sup>    
将指定的临时卡片转换为普通卡片。使用callback异步回调。  
 **调用形式：**     
- castTempForm(formId: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#castTempForm。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId<sup>(deprecated)</sup> | string | true | 卡片标识。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当将指定的临时卡片转换为普通卡片成功，error为undefined，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string = '12400633174999288';formHost.castTempForm(formId, (error: Base.BusinessError) => { if (error.code) {  console.error(`formHost castTempForm, error: ${JSON.stringify(error)}`); }});    
```    
  
    
## castTempForm<sup>(deprecated)</sup>    
将指定的临时卡片转换为普通卡片。使用Promise异步回调。  
 **调用形式：**     
- castTempForm(formId: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#castTempForm。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formId<sup>(deprecated)</sup> | string | true | 卡片标识。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string = '12400633174999288';formHost.castTempForm(formId).then(() => { console.log('formHost castTempForm success');}).catch((error: Base.BusinessError) => { console.error(`formHost castTempForm, error: ${JSON.stringify(error)}`);});    
```    
  
    
## notifyVisibleForms<sup>(deprecated)</sup>    
向卡片框架发送通知以使指定的卡片可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用callback异步回调。  
 **调用形式：**     
- notifyVisibleForms(formIds: Array\<string>, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#notifyVisibleForms。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 卡片标识列表。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当向卡片框架发送通知以使指定的卡片可见成功，error为undefined，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string[] = ['12400633174999288'];formHost.notifyVisibleForms(formId, (error: Base.BusinessError) => { if (error.code) {  console.error(`formHost notifyVisibleForms, error: ${JSON.stringify(error)}`); }});    
```    
  
    
## notifyVisibleForms<sup>(deprecated)</sup>    
向卡片框架发送通知以使指定的卡片可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用Promise异步回调。  
 **调用形式：**     
- notifyVisibleForms(formIds: Array\<string>): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#notifyVisibleForms。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 卡片标识列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string[] = ['12400633174999288'];formHost.notifyVisibleForms(formId).then(() => { console.log('formHost notifyVisibleForms success');}).catch((error: Base.BusinessError) => { console.error(`formHost notifyVisibleForms, error: ${JSON.stringify(error)}`);});    
```    
  
    
## notifyInvisibleForms<sup>(deprecated)</sup>    
向卡片框架发送通知以使指定的卡片不可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用callback异步回调。  
 **调用形式：**     
- notifyInvisibleForms(formIds: Array\<string>, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#notifyInvisibleForms。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 卡片标识列表。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当向卡片框架发送通知以使指定的卡片不可见成功，error为undefined，否则为错误对象。  |  
    
## notifyInvisibleForms<sup>(deprecated)</sup>    
向卡片框架发送通知以使指定的卡片不可见。该方法调用成功后，会调用onVisibilityChange通知卡片提供方。使用Promise异步回调。  
 **调用形式：**     
- notifyInvisibleForms(formIds: Array\<string>): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#notifyInvisibleForms。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 卡片标识列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
## enableFormsUpdate<sup>(deprecated)</sup>    
向卡片框架发送通知以使指定的卡片可以更新。该方法调用成功后，卡片刷新状态设置为使能，卡片可以接收来自卡片提供方的更新。使用callback异步回调。  
 **调用形式：**     
- enableFormsUpdate(formIds: Array\<string>, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#enableFormsUpdate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 卡片标识列表。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当向卡片框架发送通知以使指定的卡片可以更新成功，error为undefined，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string[] = ['12400633174999288'];formHost.enableFormsUpdate(formId, (error: Base.BusinessError) => { if (error.code) {  console.error(`formHost enableFormsUpdate, error: ${JSON.stringify(error)}`); }});    
```    
  
    
## enableFormsUpdate<sup>(deprecated)</sup>    
向卡片框架发送通知以使指定的卡片可以更新。该方法调用成功后，卡片刷新状态设置为使能，卡片可以接收来自卡片提供方的更新。使用Promise异步回调。  
。  
 **调用形式：**     
- enableFormsUpdate(formIds: Array\<string>): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#enableFormsUpdate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 卡片标识列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string[] = ['12400633174999288'];formHost.enableFormsUpdate(formId).then(() => { console.log('formHost enableFormsUpdate success');}).catch((error: Base.BusinessError) => { console.error(`formHost enableFormsUpdate, error: ${JSON.stringify(error)}`);});    
```    
  
    
## disableFormsUpdate<sup>(deprecated)</sup>    
向卡片框架发送通知以使指定的卡片不可以更新。该方法调用成功后，卡片刷新状态设置为去使能，卡片不可以接收来自卡片提供方的更新。使用callback异步回调。  
 **调用形式：**     
- disableFormsUpdate(formIds: Array\<string>, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#disableFormsUpdate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 卡片标识列表。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当向卡片框架发送通知以使指定的卡片不可以更新成功，error为undefined，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string[] = ['12400633174999288'];formHost.disableFormsUpdate(formId, (error: Base.BusinessError) => { if (error.code) {  console.error(`formHost disableFormsUpdate, error: ${JSON.stringify(error)}`); }});    
```    
  
    
## disableFormsUpdate<sup>(deprecated)</sup>    
向卡片框架发送通知以使指定的卡片不可以更新。该方法调用成功后，卡片刷新状态设置为去使能，卡片不可以接收来自卡片提供方的更新。使用Promise异步回调。  
 **调用形式：**     
- disableFormsUpdate(formIds: Array\<string>): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#disableFormsUpdate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 卡片标识列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string[] = ['12400633174999288'];formHost.disableFormsUpdate(formId).then(() => { console.log('formHost disableFormsUpdate success');}).catch((error: Base.BusinessError) => { console.error(`formHost disableFormsUpdate, error: ${JSON.stringify(error)}`);});    
```    
  
    
## isSystemReady<sup>(deprecated)</sup>    
检查系统是否准备好。使用callback异步回调。  
 **调用形式：**     
- isSystemReady(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#isSystemReady。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当检查系统是否准备好成功，error为undefined，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string = '12400633174999288';formHost.isSystemReady((error: Base.BusinessError) => { if (error.code) {  console.error(`formHost isSystemReady, error: ${JSON.stringify(error)}`); }});    
```    
  
    
## isSystemReady<sup>(deprecated)</sup>    
检查系统是否准备好。使用Promise异步回调。  
。  
 **调用形式：**     
- isSystemReady(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#isSystemReady。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formId: string = '12400633174999288';formHost.isSystemReady().then(() => { console.log('formHost isSystemReady success');}).catch((error: Base.BusinessError) => { console.error(`formHost isSystemReady, error: ${JSON.stringify(error)}`);});    
```    
  
    
## getAllFormsInfo<sup>(deprecated)</sup>    
获取设备上所有应用提供的卡片信息。使用callback异步回调。  
 **调用形式：**     
- getAllFormsInfo(callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#getAllFormsInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<formInfo.FormInfo>> | true | 回调函数。当获取设备上所有应用提供的卡片信息成功，error为undefined，data为查询到的卡片信息；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import formInfo from '@ohos.app.form.formInfo';  
import Base from '@ohos.base';  
  
formHost.getAllFormsInfo((error: Base.BusinessError, data: formInfo.FormInfo[]) => {  
  if (error.code) {  
    console.error(`formHost getAllFormsInfo, error: ${JSON.stringify(error)}`);  
  } else {  
    console.log(`formHost getAllFormsInfo, data: ${JSON.stringify(data)}`);  
  }  
});  
    
```    
  
    
## getAllFormsInfo<sup>(deprecated)</sup>    
获取设备上所有应用提供的卡片信息。使用Promise异步回调。  
 **调用形式：**     
- getAllFormsInfo(): Promise\<Array\<formInfo.FormInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#getAllFormsInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<formInfo.FormInfo>> | Promise对象，返回查询到的卡片信息。 |  
    
 **示例代码：**   
```ts    
 import formInfo from '@ohos.app.form.formInfo'; import Base from '@ohos.base';  
 formHost.getAllFormsInfo().then((data: formInfo.FormInfo[]) => {  console.log(`formHost getAllFormsInfo data: ${JSON.stringify(data)}`); }).catch((error: Base.BusinessError) => {  console.error(`formHost getAllFormsInfo, error: ${JSON.stringify(error)}`); });    
```    
  
    
## getFormsInfo<sup>(deprecated)</sup>    
获取设备上指定应用程序提供的卡片信息。使用callback异步回调。  
 **调用形式：**     
- getFormsInfo(bundleName: string, callback: AsyncCallback\<Array\<formInfo.FormInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#getFormsInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用Bundle名称。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<formInfo.FormInfo>> | true | 回调函数。当获取设备上指定应用程序提供的卡片信息成功，error为undefined，data为查询到的卡片信息；否则为错误对象。 |  
    
## getFormsInfo<sup>(deprecated)</sup>  
 **调用形式：**     
- getFormsInfo(     bundleName: string,     moduleName: string,     callback: AsyncCallback\<Array\<formInfo.FormInfo>>   ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#getFormsInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true |  |  
| moduleName<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<formInfo.FormInfo>> | true |  |  
    
## getFormsInfo<sup>(deprecated)</sup>    
获取设备上指定应用程序提供的卡片信息。使用Promise异步回调。  
 **调用形式：**     
- getFormsInfo(bundleName: string, moduleName?: string): Promise\<Array\<formInfo.FormInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#getFormsInfo。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 要查询的应用程序Bundle名称。  |  
| moduleName<sup>(deprecated)</sup> | string | false | 要查询的模块名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<formInfo.FormInfo>> | Promise对象，返回查询到的卡片信息。 |  
    
## deleteInvalidForms<sup>(deprecated)</sup>    
根据列表删除应用程序的无效卡片。使用callback异步回调。  
 **调用形式：**     
- deleteInvalidForms(formIds: Array\<string>, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#deleteInvalidForms。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 有效卡片标识列表。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数。当根据列表删除应用程序的无效卡片成功，error为undefined，data为删除的卡片个数；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
  
let formIds: string[] = new Array('12400633174999288', '12400633174999289');  
formHost.deleteInvalidForms(formIds, (error: Base.BusinessError, data: number) => {  
  if (error.code) {  
    console.error(`formHost deleteInvalidForms, error: ${JSON.stringify(error)}`);  
  } else {  
    console.log(`formHost deleteInvalidForms, data: ${JSON.stringify(data)}`);  
  }  
});  
    
```    
  
    
## deleteInvalidForms<sup>(deprecated)</sup>    
根据列表删除应用程序的无效卡片。使用Promise异步回调。  
 **调用形式：**     
- deleteInvalidForms(formIds: Array\<string>): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#deleteInvalidForms。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 有效卡片标识列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，返回删除的卡片个数。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formIds: string[] = new Array('12400633174999288', '12400633174999289');formHost.deleteInvalidForms(formIds).then((data: number) => { console.log(`formHost deleteInvalidForms, data: ${JSON.stringify(data)}`);}).catch((error: Base.BusinessError) => { console.error(`formHost deleteInvalidForms, error: ${JSON.stringify(error)}`);});    
```    
  
    
## acquireFormState<sup>(deprecated)</sup>    
获取卡片状态。使用callback异步回调。  
 **调用形式：**     
- acquireFormState(want: Want, callback: AsyncCallback\<formInfo.FormStateInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#acquireFormState。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want<sup>(deprecated)</sup> | Want | true | 查询卡片状态时携带的want信息。需要包含bundle名、ability名、module名、卡片名、卡片规格等。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<formInfo.FormStateInfo> | true | 回调函数。当获取卡片状态成功，error为undefined，data为获取到的卡片状态；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import Want from '@ohos.app.ability.Want';  
import formInfo from '@ohos.app.form.formInfo';  
import Base from '@ohos.base';  
  
let want: Want = {  
  'deviceId': '',  
  'bundleName': 'ohos.samples.FormApplication',  
  'abilityName': 'FormAbility',  
  'parameters': {  
    'ohos.extra.param.key.module_name': 'entry',  
    'ohos.extra.param.key.form_name': 'widget',  
    'ohos.extra.param.key.form_dimension': 2  
  }  
};  
formHost.acquireFormState(want, (error:Base.BusinessError, data: formInfo.FormStateInfo) => {  
  if (error.code) {  
    console.error(`formHost acquireFormState, error: ${JSON.stringify(error)}`);  
  } else {  
    console.log(`formHost acquireFormState, data: ${JSON.stringify(data)}`);  
  }  
});  
    
```    
  
    
## acquireFormState<sup>(deprecated)</sup>    
获取卡片状态。使用Promise异步回调。  
 **调用形式：**     
- acquireFormState(want: Want): Promise\<formInfo.FormStateInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#acquireFormState。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM and ohos.permission.GET_BUNDLE_INFO_PRIVILEGED    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want<sup>(deprecated)</sup> | Want | true | 查询卡片状态时携带的want信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<formInfo.FormStateInfo> | Promise对象，返回卡片状态。 |  
    
 **示例代码：**   
```ts    
import Want from '@ohos.app.ability.Want';import formInfo from '@ohos.app.form.formInfo';import Base from '@ohos.base';  
let want: Want = { 'deviceId': '', 'bundleName': 'ohos.samples.FormApplication', 'abilityName': 'FormAbility', 'parameters': {  'ohos.extra.param.key.module_name': 'entry',  'ohos.extra.param.key.form_name': 'widget',  'ohos.extra.param.key.form_dimension': 2 }};formHost.acquireFormState(want).then((data: formInfo.FormStateInfo) => { console.log(`formHost acquireFormState, data: ${JSON.stringify(data)}`);}).catch((error: Base.BusinessError) => { console.error(`formHost acquireFormState, error: ${JSON.stringify(error)}`);});    
```    
  
    
## on('formUninstall')<sup>(deprecated)</sup>    
订阅卡片卸载事件。使用callback异步回调。  
 **调用形式：**     
- on(type: 'formUninstall', callback: Callback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#on。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写'formUninstall'，表示卡片卸载事件。 |  
| callback<sup>(deprecated)</sup> | Callback<string> | true | 回调函数。返回卡片标识。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
formHost.on('formUninstall', (formId: string) => { console.log(`formHost on formUninstall, formId: ${formId}`);});    
```    
  
    
## off('formUninstall')<sup>(deprecated)</sup>    
取消订阅卡片卸载事件。使用callback异步回调。  
 **调用形式：**     
- off(type: 'formUninstall', callback?: Callback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#off。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写'formUninstall'，表示卡片卸载事件。 |  
| callback<sup>(deprecated)</sup> | Callback<string> | false | 回调函数。返回卡片标识。缺省时，表示注销所有已注册事件回调。<br> 需与对应on('formUninstall')的callback一致。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
formHost.on('formUninstall', (formId: string) => { console.log(`formHost on formUninstall, formId: ${formId}`);});    
```    
  
    
## notifyFormsVisible<sup>(deprecated)</sup>    
通知卡片是否可见。使用callback异步回调。  
 **调用形式：**     
- notifyFormsVisible(formIds: Array\<string>, isVisible: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#notifyFormsVisible。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 卡片标识列表。 |  
| isVisible<sup>(deprecated)</sup> | boolean | true | 是否可见。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当通知卡片是否可见成功，error为undefined，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formIds: string[]= new Array('12400633174999288', '12400633174999289');formHost.notifyFormsVisible(formIds, true, (error: Base.BusinessError) => { if (error.code) {  console.error(`formHost notifyFormsVisible, error: ${JSON.stringify(error)}`); }});    
```    
  
    
## notifyFormsVisible<sup>(deprecated)</sup>    
通知卡片是否可见。使用Promise异步回调。  
 **调用形式：**     
- notifyFormsVisible(formIds: Array\<string>, isVisible: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#notifyFormsVisible。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 卡片标识列表。 |  
| isVisible<sup>(deprecated)</sup> | boolean | true | 是否可见。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formIds: string[] = new Array('12400633174999288', '12400633174999289');formHost.notifyFormsVisible(formIds, true).then(() => { console.log('formHost notifyFormsVisible success');}).catch((error: Base.BusinessError) => { console.error(`formHost notifyFormsVisible, error: ${JSON.stringify(error)}`);});    
```    
  
    
## notifyFormsEnableUpdate<sup>(deprecated)</sup>  
 **调用形式：**     
- notifyFormsEnableUpdate(     formIds: Array\<string>,     isEnableUpdate: boolean,     callback: AsyncCallback\<void>   ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#notifyFormsEnableUpdate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true |  |  
| isEnableUpdate<sup>(deprecated)</sup> | boolean | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true |  |  
    
## notifyFormsEnableUpdate<sup>(deprecated)</sup>    
通知卡片是否启用更新状态。使用Promise异步回调。  
 **调用形式：**     
- notifyFormsEnableUpdate(formIds: Array\<string>, isEnableUpdate: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.app.form.formHost/formHost#notifyFormsEnableUpdate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.Form  
 **需要权限：** ohos.permission.REQUIRE_FORM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| formIds<sup>(deprecated)</sup> | Array<string> | true | 卡片标识列表。 |  
| isEnableUpdate<sup>(deprecated)</sup> | boolean | true | 是否使能更新。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import Base from '@ohos.base';  
let formIds: string[] = new Array('12400633174999288', '12400633174999289');formHost.notifyFormsEnableUpdate(formIds, true).then(() => { console.log('formHost notifyFormsEnableUpdate success');}).catch((error: Base.BusinessError) => { console.error(`formHost notifyFormsEnableUpdate, error: ${JSON.stringify(error)}`);});    
```    
  
