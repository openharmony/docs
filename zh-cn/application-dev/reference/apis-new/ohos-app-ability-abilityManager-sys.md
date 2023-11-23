# @ohos.app.ability.abilityManager    
AbilityManager模块提供获取、新增、修改Ability相关信息和状态信息进行的能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import abilityManager from '@ohos.app.ability.abilityManager'    
```  
    
## AbilityState    
Ability的状态，该类型为枚举，可配合[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)返回Ability的状态。  
。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INITIAL | 0 | 表示ability为初始化状态。 |  
| FOCUS | 2 | 表示ability为获焦状态。 |  
| FOREGROUND | 9 | 表示ability为前台状态。 |  
| BACKGROUND | 10 | 表示ability为后台状态。  |  
| FOREGROUNDING | 11 | 表示ability为前台调度中状态。  |  
| BACKGROUNDING | 12 | 表示ability为后台调度中状态。 |  
    
## updateConfiguration    
通过传入修改的配置项来更新配置（callback形式）。  
 **调用形式：**     
    
- updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void    
起始版本： 9    
- updateConfiguration(config: Configuration): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.UPDATE_CONFIGURATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | Configuration | true | 新的配置项，仅需配置需要更新的项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 16000050 |  |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import { Configuration } from '@ohos.app.ability.Configuration';  
import ConfigurationConstant from '@ohos.app.ability.ConfigurationConstant';  
  
const config: Configuration = {  
  language: 'Zh-Hans',                 // 简体中文  
  colorMode: ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT,         // 浅色模式  
  direction: ConfigurationConstant.Direction.DIRECTION_VERTICAL,       // 垂直方向  
  screenDensity: ConfigurationConstant.ScreenDensity.SCREEN_DENSITY_SDPI,  // 屏幕像素密度为'sdpi'  
  displayId: 1,                        // 应用在Id为1的物理屏上显示  
  hasPointerDevice: true,              // 指针类型设备已连接  
};  
  
try {  
    abilityManager.updateConfiguration(config, (err) => {  
        if (err) {  
            console.error(`updateConfiguration fail, err: ${JSON.stringify(err)}`);  
        } else {  
            console.log('updateConfiguration success.');  
        }  
    });  
} catch (paramError) {  
    console.error(`error.code: ${paramError.code}, error.message: ${paramError.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import { Configuration } from '@ohos.app.ability.Configuration';  
import ConfigurationConstant from '@ohos.app.ability.ConfigurationConstant';  
import { BusinessError } from '@ohos.base';  
  
const config: Configuration = {  
  language: 'Zh-Hans',                 // 简体中文  
  colorMode: ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT,         // 浅色模式  
  direction: ConfigurationConstant.Direction.DIRECTION_VERTICAL,       // 垂直方向  
  screenDensity: ConfigurationConstant.ScreenDensity.SCREEN_DENSITY_SDPI,  // 屏幕像素密度为'sdpi'  
  displayId: 1,                        // 应用在Id为1的物理屏上显示  
  hasPointerDevice: true,              // 指针类型设备已连接  
};  
  
try {  
    abilityManager.updateConfiguration(config).then(() => {  
        console.log('updateConfiguration success.');  
    }).catch((err: BusinessError) => {  
        console.error(`updateConfiguration fail, err: ${JSON.stringify(err)}`);  
    });  
} catch (paramError) {  
    console.error(`error.code: ${paramError.code}, error.message: ${paramError.message}`);  
}  
    
```    
  
    
## getAbilityRunningInfos  
 **调用形式：**     
    
- getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>    
起始版本： 9    
- getAbilityRunningInfos(callback: AsyncCallback\<Array\<AbilityRunningInfo>>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_RUNNING_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。 |  
| Promise<Array<AbilityRunningInfo>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 16000050 | Internal error |  
| 401 |  |  
    
 **示例代码1：**   
callback回调。  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
  
try {  
    abilityManager.getAbilityRunningInfos((err, data) => {  
        if (err) {  
            console.error(`getAbilityRunningInfos fail, error: ${JSON.stringify(err)}`);  
        } else {  
            console.log(`getAbilityRunningInfos success, data: ${JSON.stringify(data)}`);  
        }  
    });  
} catch (paramError) {  
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
}  
    
```    
  
    
 **示例代码2：**   
Promise回调。  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    abilityManager.getAbilityRunningInfos().then((data) => {  
        console.log(`getAbilityRunningInfos success, data: ${JSON.stringify(data)}`);  
    }).catch((err: BusinessError) => {  
        console.error(`getAbilityRunningInfos fail, err: ${JSON.stringify(err)}`);  
    });  
} catch (paramError) {  
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
}  
    
```    
  
    
## getExtensionRunningInfos    
获取关于运行扩展能力的信息（callback形式）。  
 **调用形式：**     
    
- getExtensionRunningInfos(upperLimit: number): Promise\<Array\<ExtensionRunningInfo>>    
起始版本： 9    
- getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback\<Array\<ExtensionRunningInfo>>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core  
 **需要权限：** ohos.permission.GET_RUNNING_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| upperLimit | number | true | 获取消息数量的最大限制，最大为2<sup>31</sup>-1。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果及运行中的extension信息，可进行错误处理或其他自定义处理。 |  
| Promise<Array<ExtensionRunningInfo>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
callback回调。  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
  
let upperLimit = 10;  
  
try {  
    abilityManager.getExtensionRunningInfos(upperLimit, (err, data) => {  
        if (err) {  
            console.error(`getExtensionRunningInfos fail, err: ${JSON.stringify(err)}`);  
        } else {  
            console.log(`getExtensionRunningInfos success, data: ${JSON.stringify(data)}`);  
        }  
    });  
} catch (paramError) {  
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
}  
    
```    
  
    
 **示例代码2：**   
Promise回调。  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import { BusinessError } from '@ohos.base';  
  
let upperLimit = 10;  
  
try {  
    abilityManager.getExtensionRunningInfos(upperLimit).then((data) => {  
        console.log(`getExtensionRunningInfos success, data: ${JSON.stringify(data)}`);  
    }).catch((err: BusinessError) => {  
        console.error(`getExtensionRunningInfos fail, err: ${JSON.stringify(err)}`);  
    });  
} catch (paramError) {  
    console.error('error.code: ${paramError.code}, error.message: ${paramError.message}');  
}  
    
```    
  
    
## getTopAbility    
获取窗口焦点的ability接口（callback形式）。  
 **调用形式：**     
    
- getTopAbility(): Promise\<ElementName>    
起始版本： 9    
- getTopAbility(callback: AsyncCallback\<ElementName>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以回调方式返回接口运行结果及应用名，可进行错误处理或其他自定义处理。 |  
| Promise<ElementName> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 16000050 | Internal error. |  
| 401 |  |  
    
 **示例代码1：**   
callback回调。  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
  
abilityManager.getTopAbility((err, data) => {   
    if (err) {  
        console.error(`getTopAbility fail, err: ${JSON.stringify(err)}`);  
    } else {  
        console.log(`getTopAbility success, data: ${JSON.stringify(data)}`);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
Promise回调。  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import { BusinessError } from '@ohos.base';  
  
abilityManager.getTopAbility().then((data) => {  
    console.log(`getTopAbility success, data: ${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getTopAbility fail, err: ${JSON.stringify(err)}`);  
});  
    
```    
  
    
## acquireShareData<sup>(10+)</sup>  
 **调用形式：**     
    
- acquireShareData(missionId: number, callback: AsyncCallback\<{ [key: string]: Object }>): void    
起始版本： 10    
- acquireShareData(missionId: number): Promise\<{ [key: string]: Object }>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| missionId | number | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<{ [key: string]: Object }> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 16000050 |  |  
    
 **示例代码1：**   
callback回调。  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    abilityManager.acquireShareData(1, (err, wantParam) => {   
        if (err) {  
            console.error(`acquireShareData fail, err: ${JSON.stringify(err)}`);  
        } else {  
            console.log(`acquireShareData success, data: ${JSON.stringify(wantParam)}`);  
        }  
    });  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`error.code: ${JSON.stringify(code)}, error.message: ${JSON.stringify(message)}`);  
}  
    
```    
  
    
 **示例代码2：**   
Promise回调。  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import { BusinessError } from '@ohos.base';  
  
try {  
    abilityManager.acquireShareData(1).then((wantParam) => {  
    console.log(`acquireShareData success, data: ${JSON.stringify(wantParam)}`);  
    }).catch((err: BusinessError) => {  
    console.error(`acquireShareData fail, err: ${JSON.stringify(err)}`);  
    });  
} catch (paramError) {  
    let code = (paramError as BusinessError).code;  
    let message = (paramError as BusinessError).message;  
    console.error(`error.code: ${JSON.stringify(code)}, error.message: ${JSON.stringify(message)}`);  
}  
    
```    
  
    
## notifySaveAsResult<sup>(10+)</sup>    
该接口仅供DLP（Data Loss Prevention, 数据丢失防护）管理应用使用，其他应用禁止使用，DLP管理应用通过该接口通知沙箱应用另存为结果。使用callback异步回调。  
 **调用形式：**     
    
- notifySaveAsResult(parameter: AbilityResult, requestCode: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- notifySaveAsResult(parameter: AbilityResult, requestCode: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parameter | AbilityResult | true | 返回给调用startAbilityForResult接口调用方的相关信息。  |  
| requestCode | number | true | DLP管理应用传入的请求代码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当另存为结果通知成功，err为undefined，否则为错误对象。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 16000050 | Internal error. |  
    
 **示例代码1：**   
callback回调。  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import common from '@ohos.app.ability.common';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let want: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility'  
};  
let resultCode = 100;  
// 返回给另存为行为发起方AbilityResult信息  
let abilityResult: common.AbilityResult = {  
    want,  
    resultCode  
};  
let requestCode = 1;  
try {  
  abilityManager.notifySaveAsResult(abilityResult, requestCode, (err) => {  
    if (err  err.code != 0) {  
      console.error(`notifySaveAsResult fail, err: ${JSON.stringify(err)}`);  
    } else {  
      console.log(`notifySaveAsResult success`);  
    }  
  });  
} catch (paramError) {  
  let code = (paramError as BusinessError).code;  
  let message = (paramError as BusinessError).message;  
  console.error(`error.code: ${JSON.stringify(code)}, error.message: ${JSON.stringify(message)}`);  
}  
    
```    
  
    
 **示例代码2：**   
Promise回调。  
```ts    
import abilityManager from '@ohos.app.ability.abilityManager';  
import common from '@ohos.app.ability.common';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let want: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility'  
};  
let resultCode = 100;  
// 返回给另存为行为发起方AbilityResult信息  
let abilityResult: common.AbilityResult = {  
    want,  
    resultCode  
};  
let requestCode = 1;  
try {  
  abilityManager.notifySaveAsResult(abilityResult, requestCode).catch((err) => {  
    console.error(`notifySaveAsResult fail, err: ${JSON.stringify(err)}`);  
  }).then(() => {  
    console.log(`notifySaveAsResult success`);  
  });  
} catch (paramError) {  
  let code = (paramError as BusinessError).code;  
  let message = (paramError as BusinessError).message;  
  console.error(`error.code: ${JSON.stringify(code)}, error.message: ${JSON.stringify(message)}`);  
}  
    
```    
  
