# context    
Context模块提供了ability或application的上下文的能力，包括允许访问特定于应用程序的资源、请求和验证权限等。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## Context    
Context对象是在featureAbility中创建实例，并通过featureAbility的[getContext](js-apis-ability-featureAbility.md#featureabilitygetcontext)接口返回，因此在使用Context时，必须导入eAbility库。示例如下：  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### getOrCreateLocalDir<sup>(7+)</sup>    
获取应用程序的本地根目录。  如果是第一次调用，将创建目录。  
 **调用形式：**     
    
- getOrCreateLocalDir(): Promise\<string>    
起始版本： 7    
- getOrCreateLocalDir(callback: AsyncCallback\<string>): void    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回应用程序的本地根目录。 |  
| Promise<string> | 应用程序的本地根目录。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getOrCreateLocalDir((error, data)=>{  
    if (error  error.code !== 0) {  
        console.error(`getOrCreateLocalDir fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getOrCreateLocalDir success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getOrCreateLocalDir().then((data) => {    console.info(`getOrCreateLocalDir data: ${JSON.stringify(data)}`);});    
```    
  
    
### verifyPermission<sup>(7+)</sup>    
验证系统中运行的特定pid和uid是否允许指定的权限。  
 **调用形式：**     
    
- verifyPermission(permission: string, options?: PermissionOptions): Promise\<number>    
起始版本： 7    
- verifyPermission(permission: string, options: PermissionOptions, callback: AsyncCallback\<number>): void    
起始版本： 7    
- verifyPermission(permission: string, callback: AsyncCallback\<number>): void    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| permission | string | true | 指定权限的名称。 |  
| options | PermissionOptions | false | 权限选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回权限验证结果，0有权限，-1无权限。 |  
| Promise<number> | 如果pid和uid具有权限，则使用0进行异步回调；否则使用-1回调。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
import bundle from '@ohos.bundle.bundleManager';  
let context: featureAbility.Context = featureAbility.getContext();  
bundle.getBundleInfo('com.context.test', 1, (err, datainfo) =>{  
    context.verifyPermission('com.example.permission', {uid:datainfo.appInfo.uid}, (error, data) =>{  
        if (error  error.code !== 0) {  
            console.error(`verifyPermission fail, error: ${JSON.stringify(error)}`);  
        } else {  
            console.log(`verifyPermission success, data: ${JSON.stringify(data)}`);  
        }  
    });  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.verifyPermission('com.context.permission', {pid:1}).then((data) => {    console.info(`verifyPermission data: ${JSON.stringify(data)}`);});    
```    
  
    
### requestPermissionsFromUser<sup>(7+)</sup>    
从系统请求某些权限。  
 **调用形式：**     
- requestPermissionsFromUser(     permissions: Array\<string>,     requestCode: number,     resultCallback: AsyncCallback\<PermissionRequestResult>   ): void  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| permissions | Array<string> | true | 指示要请求的权限列表。此参数不能为null。 |  
| requestCode | number | true | 指示要传递给PermissionRequestResult的请求代码。 |  
| resultCallback | AsyncCallback<PermissionRequestResult> | true | 返回授权结果信息。 |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.requestPermissionsFromUser(  
    ['com.example.permission1',  
     'com.example.permission2',  
     'com.example.permission3',  
     'com.example.permission4',  
     'com.example.permission5'],  
    1,  
    (error, data) => {  
        if (error  error.code !== 0) {  
            console.error(`requestPermissionsFromUser fail, error: ${JSON.stringify(error)}`);  
        } else {  
            console.log(`requestPermissionsFromUser success, data: ${JSON.stringify(data)}`);  
        }  
    }  
);  
    
```    
  
    
### requestPermissionsFromUser<sup>(7+)</sup>    
从系统请求某些权限  
 **调用形式：**     
    
- requestPermissionsFromUser(permissions: Array\<string>, requestCode: number): Promise\<PermissionRequestResult>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| permissions | Array<string> | true | 指示要请求的权限列表。此参数不能为null。 |  
| requestCode | number | true | 指示要传递给PermissionRequestResult的请求代码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回授权结果信息。 |  
| Promise<PermissionRequestResult> | 返回授权结果信息。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.requestPermissionsFromUser(  
    ['com.example.permission1',  
     'com.example.permission2',  
     'com.example.permission3',  
     'com.example.permission4',  
     'com.example.permission5'],  
    1,  
    (error, data) => {  
        if (error  error.code !== 0) {  
            console.error(`requestPermissionsFromUser fail, error: ${JSON.stringify(error)}`);  
        } else {  
            console.log(`requestPermissionsFromUser success, data: ${JSON.stringify(data)}`);  
        }  
    }  
);  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.requestPermissionsFromUser(    ['com.example.permission1',     'com.example.permission2',     'com.example.permission3',     'com.example.permission4',     'com.example.permission5'],    1).then((data)=>{        console.info(`requestPermissionsFromUser data: ${JSON.stringify(data)}`);    });    
```    
  
    
### getApplicationInfo<sup>(7+)</sup>    
获取有关当前应用程序的信息  
 **调用形式：**     
    
- getApplicationInfo(callback: AsyncCallback\<ApplicationInfo>): void    
起始版本： 7    
- getApplicationInfo(): Promise\<ApplicationInfo>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回当前应用程序的信息。 |  
| Promise<ApplicationInfo> | 当前应用程序的信息 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getApplicationInfo((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getApplicationInfo fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getApplicationInfo success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getApplicationInfo().then((data) => {    console.info(`getApplicationInfo data: ${JSON.stringify(data)}`);});    
```    
  
    
### getBundleName<sup>(7+)</sup>    
获取当前ability的Bundle名称  
 **调用形式：**     
    
- getBundleName(callback: AsyncCallback\<string>): void    
起始版本： 7    
- getBundleName(): Promise\<string>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回当前ability的Bundle名称。 |  
| Promise<string> | 当前ability的Bundle名称。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getBundleName((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getBundleName fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getBundleName success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getBundleName().then((data) => {    console.info(`getBundleName data: ${JSON.stringify(data)}`);});    
```    
  
    
### getDisplayOrientation<sup>(7+)</sup>    
获取当前ability的显示方向  
 **调用形式：**     
    
- getDisplayOrientation(callback: AsyncCallback\<bundle.DisplayOrientation>): void    
起始版本： 7    
- getDisplayOrientation(): Promise\<bundle.DisplayOrientation>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示屏幕显示方向。 |  
| Promise<bundle.DisplayOrientation> | 表示屏幕显示方向。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getDisplayOrientation((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getDisplayOrientation fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getDisplayOrientation success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
<span style="letter-spacing: 0px;">示例（Promise）:</span>  
  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getDisplayOrientation().then((data) => {    console.info(`getDisplayOrientation data: ${JSON.stringify(data)}`);});    
```    
  
    
### getExternalCacheDir<sup>(deprecated)</sup>    
获取应用程序的外部缓存目录。  
 **调用形式：**     
- getExternalCacheDir(callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 7 开始废弃。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 返回应用程序的缓存目录的绝对路径。 |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getExternalCacheDir((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getExternalCacheDir fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getExternalCacheDir success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
### getExternalCacheDir<sup>(deprecated)</sup>    
获取应用程序的外部缓存目录（Promise形式）。  
 **调用形式：**     
- getExternalCacheDir(): Promise\<string>  
  
 **废弃说明：** 从API version 7 开始废弃。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | 返回应用程序的缓存目录的绝对路径。 |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getExternalCacheDir().then((data) => {    console.info(`getExternalCacheDir data: ${JSON.stringify(data)}`);});    
```    
  
    
### setDisplayOrientation<sup>(7+)</sup>    
设置当前能力的显示方向  
 **调用形式：**     
    
- setDisplayOrientation(orientation: bundle.DisplayOrientation, callback: AsyncCallback\<void>): void    
起始版本： 7    
- setDisplayOrientation(orientation: bundle.DisplayOrientation): Promise\<void>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| orientation | bundle.DisplayOrientation | true | 指示当前能力的新方向。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示屏幕显示方向。 |  
| Promise<void> | 表示屏幕显示方向。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';import bundleManager from '@ohos.bundle';let context: featureAbility.Context = featureAbility.getContext();let orientation = bundleManager.DisplayOrientation.LANDSCAPE;context.setDisplayOrientation(orientation, (error) => {    console.error(`setDisplayOrientation fail, error: ${JSON.stringify(error)}`);});    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';import bundleManager from '@ohos.bundle';let context: featureAbility.Context = featureAbility.getContext();let orientation = bundleManager.DisplayOrientation.UNSPECIFIED;context.setDisplayOrientation(orientation).then((data) => {    console.info(`setDisplayOrientation data: ${JSON.stringify(data)}`);});    
```    
  
    
### setShowOnLockScreen<sup>(deprecated)</sup>    
设置每当显示锁屏时是否在锁屏顶部显示此功能，使该功能保持激活状态（callback形式）。  
 **调用形式：**     
- setShowOnLockScreen(show: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window/window.WindowStage#setShowOnLockScreen。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| show<sup>(deprecated)</sup> | boolean | true | 指定是否在锁屏顶部显示此功能。值true表示在锁屏上显示，值false表示不显示。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 返回回调结果。 |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();let show = true;context.setShowOnLockScreen(show, (error) => {    console.error(`setShowOnLockScreen fail, error: ${JSON.stringify(error)}`);});    
```    
  
    
### setShowOnLockScreen<sup>(deprecated)</sup>    
设置每当显示锁屏时是否在锁屏顶部显示此功能，使该功能保持激活状态（Promise形式）。  
 **调用形式：**     
- setShowOnLockScreen(show: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.window/window.WindowStage#setShowOnLockScreen。  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| show<sup>(deprecated)</sup> | boolean | true | 指定是否在锁屏顶部显示此功能。值true表示在锁屏上显示，值false表示不显示。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 使用Promise形式返回结果 |  
    
 **示例代码：**   
```null    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();let show = true;context.setShowOnLockScreen(show).then((data) => {    console.info(`setShowOnLockScreen data: ${JSON.stringify(data)}`);});    
```    
  
    
### setWakeUpScreen<sup>(7+)</sup>    
设置恢复此功能时是否唤醒屏幕  
 **调用形式：**     
    
- setWakeUpScreen(wakeUp: boolean, callback: AsyncCallback\<void>): void    
起始版本： 7    
- setWakeUpScreen(wakeUp: boolean): Promise\<void>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| wakeUp | boolean | true | 指定是否唤醒屏幕。值true表示唤醒它，值false表示不唤醒它。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回回调结果。 |  
| Promise<void> | 使用Promise形式返回结果 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();let wakeUp = true;context.setWakeUpScreen(wakeUp, (error) => {    console.error(`setWakeUpScreen fail, error: ${JSON.stringify(error)}`);});    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();let wakeUp = true;context.setWakeUpScreen(wakeUp).then((data) => {    console.info(`setWakeUpScreen data: ${JSON.stringify(data)}`);});    
```    
  
    
### getProcessInfo<sup>(7+)</sup>    
获取有关当前进程的信息，包括进程ID和名称  
 **调用形式：**     
    
- getProcessInfo(callback: AsyncCallback\<ProcessInfo>): void    
起始版本： 7    
- getProcessInfo(): Promise\<ProcessInfo>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回当前进程的信息。 |  
| Promise<ProcessInfo> | 当前进程的信息 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getProcessInfo((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getProcessInfo fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getProcessInfo success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getProcessInfo().then((data) => {    console.info(`getProcessInfo data: ${JSON.stringify(data)}`);});    
```    
  
    
### getElementName<sup>(7+)</sup>    
获取当前ability的ohos.bundleManager.ElementName对象,此方法仅适用于页面功能。  
 **调用形式：**     
    
- getElementName(callback: AsyncCallback\<ElementName>): void    
起始版本： 7    
- getElementName(): Promise\<ElementName>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回当前ability的ohos.bundleManager.ElementName对象。 |  
| Promise<ElementName> | 当前ability的ohos.bundleManager.ElementName对象。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getElementName((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getElementName fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getElementName success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getElementName().then((data) => {    console.info(`getElementName data: ${JSON.stringify(data)}`);});    
```    
  
    
### getProcessName<sup>(7+)</sup>    
获取当前进程的名称  
 **调用形式：**     
    
- getProcessName(callback: AsyncCallback\<string>): void    
起始版本： 7    
- getProcessName(): Promise\<string>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回当前进程的名称。 |  
| Promise<string> | 获取当前进程的名称 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getProcessName((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getProcessName fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getProcessName success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getProcessName().then((data) => {    console.info(`getProcessName data: ${JSON.stringify(data)}`);});    
```    
  
    
### getCallingBundle<sup>(7+)</sup>    
获取ability调用方的Bundle名称  
 **调用形式：**     
    
- getCallingBundle(callback: AsyncCallback\<string>): void    
起始版本： 7    
- getCallingBundle(): Promise\<string>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回ability调用方的Bundle名称。 |  
| Promise<string> | 返回ability调用方的Bundle名称。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getCallingBundle((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getCallingBundle fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getCallingBundle success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getCallingBundle().then((data) => {    console.info(`getCallingBundle data: ${JSON.stringify(data)}`);});    
```    
  
    
### getFilesDir    
获取内部存储器上此应用程序的文件目录  
 **调用形式：**     
    
- getFilesDir(callback: AsyncCallback\<string>): void    
起始版本： 6    
- getFilesDir(): Promise\<string>    
起始版本： 6  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回内部存储器上此应用程序的文件目录。 |  
| Promise<string> | 返回内部存储器上此应用程序的文件目录。 |  
    
 **示例代码1：**   
<span style="letter-spacing: 0px;">示例（callback）:</span>  
```null    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getFilesDir((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getFilesDir fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getFilesDir success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getFilesDir().then((data) => {    console.info(`getFilesDir data: ${JSON.stringify(data)}`);});    
```    
  
    
### getCacheDir    
获取该应用程序的内部存储目录  
 **调用形式：**     
    
- getCacheDir(callback: AsyncCallback\<string>): void    
起始版本： 6    
- getCacheDir(): Promise\<string>    
起始版本： 6  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回该应用程序的内部存储目录。 |  
| Promise<string> | 返回该应用程序的内部存储目录。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getCacheDir((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getCacheDir fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getCacheDir success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getCacheDir().then((data) => {    console.info(`getCacheDir data: ${JSON.stringify(data)}`);});    
```    
  
    
### getOrCreateDistributedDir<sup>(7+)</sup>    
获取Ability或应用的分布式文件路径。  如果分布式文件路径不存在，系统将创建一个路径并返回创建的路径  
 **调用形式：**     
    
- getOrCreateDistributedDir(): Promise\<string>    
起始版本： 7    
- getOrCreateDistributedDir(callback: AsyncCallback\<string>): void    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回Ability或应用的分布式文件路径。<br>若路径不存在，系统将创建一个路径并返回创建的路径。 |  
| Promise<string> | 返回Ability或应用的分布式文件路径。若为首次调用，则将创建目录。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getOrCreateDistributedDir((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getOrCreateDistributedDir fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getOrCreateDistributedDir success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getOrCreateDistributedDir().then((data) => {    console.info(`getOrCreateDistributedDir data: ${JSON.stringify(data)}`);});    
```    
  
    
### getAppType<sup>(7+)</sup>    
获取此应用的类型  
 **调用形式：**     
    
- getAppType(callback: AsyncCallback\<string>): void    
起始版本： 7    
- getAppType(): Promise\<string>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回此应用程序的类型。 |  
| Promise<string> | 返回此应用的类型。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getAppType((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getAppType fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getAppType success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getAppType().then((data) => {    console.info(`getAppType data: ${JSON.stringify(data)}`);});    
```    
  
    
### getHapModuleInfo<sup>(7+)</sup>    
获取应用的ModuleInfo对象  
 **调用形式：**     
    
- getHapModuleInfo(callback: AsyncCallback\<HapModuleInfo>): void    
起始版本： 7    
- getHapModuleInfo(): Promise\<HapModuleInfo>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回应用的ModuleInfo对象。 |  
| Promise<HapModuleInfo> | 返回应用的ModuleInfo对象。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getHapModuleInfo((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getHapModuleInfo fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getHapModuleInfo success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getHapModuleInfo().then((data) => {    console.info(`getHapModuleInfo data: ${JSON.stringify(data)}`);});    
```    
  
    
### getAppVersionInfo<sup>(7+)</sup>    
获取应用的版本信息  
 **调用形式：**     
    
- getAppVersionInfo(callback: AsyncCallback\<AppVersionInfo>): void    
起始版本： 7    
- getAppVersionInfo(): Promise\<AppVersionInfo>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回应用版本信息。 |  
| Promise<AppVersionInfo> | 返回应用版本信息。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getAppVersionInfo((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getAppVersionInfo fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getAppVersionInfo success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getAppVersionInfo().then((data) => {    console.info(`getAppVersionInfo data: ${JSON.stringify(data)}`);});    
```    
  
    
### getApplicationContext<sup>(7+)</sup>    
获取应用上下文信息。  
 **调用形式：**     
- getApplicationContext(): Context  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Context | 返回应用上下文信息。 |  
    
 **示例代码：**   
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext().getApplicationContext();    
```    
  
    
### getAbilityInfo<sup>(7+)</sup>    
查询当前归属Ability详细信息  
 **调用形式：**     
    
- getAbilityInfo(callback: AsyncCallback\<AbilityInfo>): void    
起始版本： 7    
- getAbilityInfo(): Promise\<AbilityInfo>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回当前归属Ability详细信息。 |  
| Promise<AbilityInfo> | 返回当前归属Ability详细信息。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.getAbilityInfo((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`getAbilityInfo fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`getAbilityInfo success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.getAbilityInfo().then((data) => {    console.info(`getAbilityInfo data: ${JSON.stringify(data)}`);});    
```    
  
    
### isUpdatingConfigurations<sup>(7+)</sup>    
检查此能力的配置是否正在更改  
 **调用形式：**     
    
- isUpdatingConfigurations(callback: AsyncCallback\<boolean>): void    
起始版本： 7    
- isUpdatingConfigurations(): Promise\<boolean>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 如果该能力的配置正在更改，则为true，否则为false。 |  
| Promise<boolean> | 如果该能力的配置正在更改，则为true，否则为false。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';  
let context: featureAbility.Context = featureAbility.getContext();  
context.isUpdatingConfigurations((error, data) => {  
    if (error  error.code !== 0) {  
        console.error(`isUpdatingConfigurations fail, error: ${JSON.stringify(error)}`);  
    } else {  
        console.log(`isUpdatingConfigurations success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.isUpdatingConfigurations().then((data) => {    console.info(`isUpdatingConfigurations data: ${JSON.stringify(data)}`);});    
```    
  
    
### printDrawnCompleted<sup>(7+)</sup>    
通知系统绘制此页面功能所需的时间  
 **调用形式：**     
    
- printDrawnCompleted(callback: AsyncCallback\<void>): void    
起始版本： 7    
- printDrawnCompleted(): Promise\<void>    
起始版本： 7  
  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示被指定的回调方法。 |  
| Promise<void> | 以Promise形式返回结果。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.printDrawnCompleted((err) => {    console.error(`printDrawnCompleted err: ${JSON.stringify(err)}`);});    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import featureAbility from '@ohos.ability.featureAbility';let context: featureAbility.Context = featureAbility.getContext();context.printDrawnCompleted().then((data) => {    console.info(`printDrawnCompleted data: ${JSON.stringify(data)}`);});    
```    
  
    
## PermissionRequestResult<sup>(7+)</sup>  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| requestCode<sup>(7+)</sup> | number | false | true | 用户传入的请求代码。 |  
| permissions<sup>(7+)</sup> | Array<string> | false | true | 用户传入的权限。 |  
| authResults<sup>(7+)</sup> | Array<number> | false | true | 请求权限的结果。 |  
    
## PermissionOptions<sup>(7+)</sup>  
 **模型约束：** 此接口仅可在FA模型下使用。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **模型约束：** 本模块接口仅可在FA模型下使用。    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pid<sup>(7+)</sup> | number | false | false | 进程id。 |  
| uid<sup>(7+)</sup> | number | false | false | 用户id。 |  
