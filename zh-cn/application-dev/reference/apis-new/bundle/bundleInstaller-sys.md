# bundleInstaller    
本模块提供设备上安装、升级和卸载应用的能力。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## InstallParam<sup>(deprecated)</sup>    
安装、恢复或卸载时需要指定的参数。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.installer#InstallParam替代。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| userId<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.installer.InstallParam#userId替代。<br>指示用户id, 默认值：调用方的userId |  
| installFlag<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.installer.InstallParam#installFlag替代。<br>指示安装标志, 默认值：1, 取值范围：</br>1: 覆盖安装, </br>16: 免安装 |  
| isKeepData<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.installer.InstallParam#isKeepData替代。<br>指示参数是否有数据，默认值：false |  
    
## InstallStatus<sup>(deprecated)</sup>    
应用程序安装卸载的结果。    
从API version 7 开始支持，从API version 9 开始废弃。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| status<sup>(deprecated)</sup> | bundle.InstallErrorCode | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示安装或卸载错误状态码。取值范围：枚举值[InstallErrorCode](js-apis-Bundle.md#installerrorcode) |  
| statusMessage<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示安装或卸载的字符串结果信息。取值范围包括：<br/> "SUCCESS" : 安装成功，</br> "STATUS_INSTALL_FAILURE": 安装失败（不存在安装文件）, </br> "STATUS_INSTALL_FAILURE_ABORTED": 安装中止, </br> "STATUS_INSTALL_FAILURE_INVALID": 安装参数无效, </br> "STATUS_INSTALL_FAILURE_CONFLICT":  安装冲突（常见于升级和已有应用基本信息不一致）, </br> "STATUS_INSTALL_FAILURE_STORAGE": 存储包信息失败, </br> "STATUS_INSTALL_FAILURE_INCOMPATIBLE": 安装不兼容（常见于版本降级安装或者签名信息错误）, </br> "STATUS_UNINSTALL_FAILURE": 卸载失败（不存在卸载的应用）, </br> "STATUS_UNINSTALL_FAILURE_ABORTED": 卸载中止（没有使用）, </br> "STATUS_UNINSTALL_FAILURE_ABORTED": 卸载冲突（卸载系统应用失败， 结束应用进程失败）, </br> "STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT": 安装失败（下载超时）, </br> "STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED": 安装失败（下载失败）, </br> "STATUS_RECOVER_FAILURE_INVALID": 恢复预置应用失败, </br> "STATUS_ABILITY_NOT_FOUND": Ability未找到, </br> "STATUS_BMS_SERVICE_ERROR": BMS服务错误, </br> "STATUS_FAILED_NO_SPACE_LEFT": 设备空间不足, </br> "STATUS_GRANT_REQUEST_PERMISSIONS_FAILED": 应用授权失败, </br> "STATUS_INSTALL_PERMISSION_DENIED": 缺少安装权限, </br> "STATUS_UNINSTALL_PERMISSION_DENIED": 缺少卸载权限 |  
    
## BundleInstaller<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bundle.installer#BundleInstaller替代。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework    
### install<sup>(deprecated)</sup>    
以异步方法在应用中安装hap，支持多hap安装。使用callback形式返回结果。  
 **调用形式：**     
- install(bundleFilePaths: Array\<string>, param: InstallParam, callback: AsyncCallback\<InstallStatus>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.installer.BundleInstaller#install。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.INSTALL_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleFilePaths<sup>(deprecated)</sup> | Array<string> | true | 指示存储HAP的沙箱路径。沙箱路径的获取方法参见[获取应用的沙箱路径](#获取应用的沙箱路径)。 |  
| param<sup>(deprecated)</sup> | InstallParam | true | 指定安装所需的其他参数。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<InstallStatus> | true | 程序启动作为入参的回调函数，返回安装状态信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundleInstall from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/files/'];  
let installParam: bundleInstall.InstallParam = {  
  userId: 100,  
  isKeepData: false,  
  installFlag: 1,  
};  
  
bundleInstall.getBundleInstaller().then(installer => {  
  installer.install(hapFilePaths, installParam, err => {  
    if (err) {  
      console.error('install failed:' + JSON.stringify(err));  
    } else {  
      console.info('install successfully.');  
    }  
  });  
}).catch((error: BusinessError)=> {  
  let message = (error as BusinessError).message;  
  console.error('getBundleInstaller failed. Cause: ' + message);  
});  
    
```    
  
    
### uninstall<sup>(deprecated)</sup>    
以异步方法卸载应用程序，使用callback异步回调，返回安装状态信息。  
 **调用形式：**     
- uninstall(bundleName: string, param: InstallParam, callback: AsyncCallback\<InstallStatus>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.installer.BundleInstaller#uninstall。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.INSTALL_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 应用Bundle名称。 |  
| param<sup>(deprecated)</sup> | InstallParam | true | 指定卸载所需的其他参数。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<InstallStatus> | true | 程序启动作为入参的回调函数，返回安装状态信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundleInstall from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = 'com.example.myapplication';  
let installParam: bundleInstall.InstallParam = {  
  userId: 100,  
  isKeepData: false,  
  installFlag: 1,  
};  
  
bundleInstall.getBundleInstaller().then(installer => {  
  installer.uninstall(bundleName, installParam, err => {  
    if (err) {  
      console.error('uninstall failed:' + JSON.stringify(err));  
    } else {  
      console.info('uninstall successfully.');  
    }  
  });  
}).catch((error: BusinessError) => {  
  let message = (error as BusinessError).message;  
  console.error('getBundleInstaller failed. Cause: ' + message);  
});  
    
```    
  
    
### recover<sup>(deprecated)</sup>    
以异步方法恢复一个应用程序，使用callback形式返回结果。当预置应用被卸载后，可以通过此接口进行恢复。  
 **调用形式：**     
- recover(bundleName: string, param: InstallParam, callback: AsyncCallback\<InstallStatus>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bundle.installer.BundleInstaller#recover。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework  
 **需要权限：** ohos.permission.INSTALL_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName<sup>(deprecated)</sup> | string | true | 应用Bundle名称。 |  
| param<sup>(deprecated)</sup> | InstallParam | true | 指定应用恢复所需的其他参数。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<InstallStatus> | true | 程序启动作为入参的回调函数，返回应用恢复状态信息。 |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import bundleInstall from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
let bundleName: string = 'com.example.myapplication';  
let installParam: bundleInstall.InstallParam = {  
  userId: 100,  
  isKeepData: false,  
  installFlag: 1,  
};  
  
bundleInstall.getBundleInstaller().then(installer => {  
  installer.uninstall(bundleName, installParam, err => {  
    if (err) {  
      console.error('uninstall failed:' + JSON.stringify(err));  
    } else {  
      console.info('uninstall successfully.');  
    }  
  });  
}).catch((error: BusinessError) => {  
  let message = (error as BusinessError).message;  
  console.error('getBundleInstaller failed. Cause: ' + message);  
});  
    
```    
  
