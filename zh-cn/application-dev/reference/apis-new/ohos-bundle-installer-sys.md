# @ohos.bundle.installer    
在设备上安装、升级和卸载应用。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import installer from '@ohos.bundle.installer'    
```  
    
## getBundleInstaller    
获取BundleInstaller对象，使用callback形式返回结果。  
 **调用形式：**     
    
- getBundleInstaller(callback: AsyncCallback\<BundleInstaller>): void    
起始版本： 9    
- getBundleInstaller(): Promise\<BundleInstaller>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，获取BundleInstaller对象，err为null，data为获取到的BundleInstaller对象；否则为错误对象。 |  
| Promise<BundleInstaller> | Promise对象，返回BundleInstaller对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import installer from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
try {  
    installer.getBundleInstaller((err: BusinessError, data: installer.BundleInstaller) => {  
        if (err) {  
            console.error('getBundleInstaller failed:' + err.message);  
        } else {  
            console.info('getBundleInstaller successfully');  
        }  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getBundleInstaller failed:' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import installer from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
try {  
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {  
        console.info('getBundleInstaller successfully.');  
    }).catch((error: BusinessError) => {  
        console.error('getBundleInstaller failed. Cause: ' + error.message);  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getBundleInstaller failed. Cause: ' + message);  
}  
    
```    
  
    
## getBundleInstallerSync<sup>(10+)</sup>    
获取并返回BundleInstaller对象。  
 **调用形式：**     
- getBundleInstallerSync(): BundleInstaller  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BundleInstaller | 返回BundleInstaller对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
import installer from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
try {  
    installer.getBundleInstallerSync();  
    console.info('getBundleInstallerSync successfully.');  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getBundleInstallerSync failed. Cause: ' + message);  
}  
    
```    
  
    
## BundleInstaller  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### install    
以异步方法安装应用，使用callback形式返回结果。  
 **调用形式：**     
    
- install(hapFilePaths: Array\<string>, installParam: InstallParam, callback: AsyncCallback\<void>): void    
起始版本： 9    
- install(hapFilePaths: Array\<string>, installParam: InstallParam, callback: AsyncCallback\<void>): void    
起始版本： 10    
- install(hapFilePaths: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 9    
- install(hapFilePaths: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- install(hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>    
起始版本： 9    
- install(hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.INSTALL_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hapFilePaths | Array<string> | true | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP，且这些HAP的签名需要保持一致。<br/> |  
| installParam | InstallParam | true | 指定安装所需的其他参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，安装应用成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700004 | The specified user ID is not found. |  
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |  
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |  
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |  
| 17700015 | Failed to install the HAPs because they have different configuration information. |  
| 17700016 | Failed to install the HAP because of insufficient system disk space. |  
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |  
| 17700018 | Failed to install because the dependent module does not exist. |  
| 17700031 | Failed to install the HAP because the overlay check of the HAP is failed. |  
| 17700036 | Failed to install the HSP because lacks appropriate permissions. |  
| 17700039 | Failed to install because disallow install a shared bundle by hapFilePaths. |  
| 17700041 | Failed to install because enterprise device management disallow install. |  
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |  
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |  
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |  
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |  
| 17700048 | Failed to install the HAP because the code signature verification is failed. |  
| 17700050 | Failed to install the HAP because enterprise normal/MDM bundle cannot be installed on non-enterprise device. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import installer from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];  
let installParam: installer.InstallParam = {  
    userId: 100,  
    isKeepData: false,  
    installFlag: 1,  
};  
  
try {  
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {  
        data.install(hapFilePaths, installParam, (err: BusinessError) => {  
            if (err) {  
                console.error('install failed:' + err.message);  
            } else {  
                console.info('install successfully.');  
            }  
        });  
    }).catch((error: BusinessError) => {  
        console.error('getBundleInstaller failed. Cause: ' + error.message);  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getBundleInstaller failed. Cause: ' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import installer from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];  
let installParam: installer.InstallParam = {  
    userId: 100,  
    isKeepData: false,  
    installFlag: 1,  
};  
  
try {  
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {  
        data.install(hapFilePaths, installParam)  
            .then((data: void) => {  
                console.info('install successfully: ' + JSON.stringify(data));  
        }).catch((error: BusinessError) => {  
            console.error('install failed:' + error.message);  
        });  
    }).catch((error: BusinessError) => {  
        console.error('getBundleInstaller failed. Cause: ' + error.message);  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getBundleInstaller failed. Cause: ' + message);  
}  
    
```    
  
    
### uninstall    
以异步方法卸载应用，使用callback形式返回结果。  
 **调用形式：**     
    
- uninstall(bundleName: string, installParam: InstallParam, callback: AsyncCallback\<void>): void    
起始版本： 9    
- uninstall(bundleName: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- uninstall(bundleName: string, installParam?: InstallParam): Promise\<void>    
起始版本： 9    
- uninstall(uninstallParam: UninstallParam, callback: AsyncCallback\<void>): void    
起始版本： 10    
- uninstall(uninstallParam: UninstallParam): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.INSTALL_BUNDLE or ohos.permission.UNINSTALL_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 待卸载应用的包名。<br/> |  
| installParam | InstallParam | true | 指定安装所需的其他参数。<br/> |  
| uninstallParam<sup>(10+)</sup> | UninstallParam | true | 共享包卸载需指定的参数信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，回滚应用成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundle name is not found. |  
| 17700004 | The specified user ID is not found. |  
| 17700020 | The specified bundle is pre-installed bundle which cannot be uninstalled. |  
| 17700040 | The specified bundle is a shared bundle which cannot be uninstalled. |  
| 17700045 | Failed to uninstall because enterprise device management disallow uninstall. |  
| 17700037 | The version of shared bundle is dependent on other applications. |  
| 17700038 | The specified shared bundle does not exist. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import installer from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'com.ohos.demo';  
let installParam: installer.InstallParam = {  
    userId: 100,  
    isKeepData: false,  
    installFlag: 1  
};  
  
try {  
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {  
        data.uninstall(bundleName, installParam, (err: BusinessError) => {  
            if (err) {  
                console.error('uninstall failed:' + err.message);  
            } else {  
                console.info('uninstall successfully.');  
            }  
        });  
    }).catch((error: BusinessError) => {  
        console.error('getBundleInstaller failed. Cause: ' + error.message);  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getBundleInstaller failed. Cause: ' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import installer from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'com.ohos.demo';  
let installParam: installer.InstallParam = {  
    userId: 100,  
    isKeepData: false,  
    installFlag: 1,  
};  
  
try {  
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {  
        data.uninstall(bundleName, installParam)  
            .then((data: void) => {  
                console.info('uninstall successfully: ' + JSON.stringify(data));  
        }).catch((error: BusinessError) => {  
            console.error('uninstall failed:' + error.message);  
        });  
    }).catch((error: BusinessError) => {  
        console.error('getBundleInstaller failed. Cause: ' + error.message);  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getBundleInstaller failed. Cause: ' + message);  
}  
    
```    
  
    
### recover    
以异步方法回滚应用到初次安装时的状态，使用callback形式返回结果。  
 **调用形式：**     
    
- recover(bundleName: string, installParam: InstallParam, callback: AsyncCallback\<void>): void    
起始版本： 9    
- recover(bundleName: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- recover(bundleName: string, installParam?: InstallParam): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.INSTALL_BUNDLE or ohos.permission.RECOVER_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 待恢复应用的包名。<br/> |  
| installParam | InstallParam | true | 指定安装所需的其他参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，回滚应用成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700001 | The specified bundle name is not found. |  
| 17700004 | The specified user ID is not found. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import installer from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'com.ohos.demo';  
let installParam: installer.InstallParam = {  
    userId: 100,  
    isKeepData: false,  
    installFlag: 1  
};  
  
try {  
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {  
        data.recover(bundleName, installParam, (err: BusinessError) => {  
            if (err) {  
                console.error('recover failed:' + err.message);  
            } else {  
                console.info('recover successfully.');  
            }  
        });  
    }).catch((error: BusinessError) => {  
        console.error('getBundleInstaller failed. Cause: ' + error.message);  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getBundleInstaller failed. Cause: ' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import installer from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
let bundleName = 'com.ohos.demo';  
let installParam: installer.InstallParam = {  
    userId: 100,  
    isKeepData: false,  
    installFlag: 1,  
};  
  
try {  
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {  
        data.recover(bundleName, installParam)  
            .then((data: void) => {  
                console.info('recover successfully: ' + JSON.stringify(data));  
        }).catch((error: BusinessError) => {  
            console.error('recover failed:' + error.message);  
        });  
    }).catch((error: BusinessError) => {  
        console.error('getBundleInstaller failed. Cause: ' + error.message);  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getBundleInstaller failed. Cause: ' + message);  
}  
    
```    
  
    
### updateBundleForSelf<sup>(10+)</sup>    
以异步方法更新当前应用，仅限企业设备上的企业MDM应用调用，且传入的hapFilePaths中的hap必须都属于当前应用，使用callback形式返回结果。  
 **调用形式：**     
    
- updateBundleForSelf(hapFilePaths: Array\<string>, installParam: InstallParam, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updateBundleForSelf(hapFilePaths: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updateBundleForSelf(hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core  
 **需要权限：** ohos.permission.INSTALL_SELF_BUNDLE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| hapFilePaths | Array<string> | true | 存储应用程序包的路径。路径应该是当前应用程序中存放HAP的数据目录。当传入的路径是一个目录时， 该目录下只能放同一个应用的HAP，且这些HAP的签名需要保持一致。<br/> |  
| installParam | InstallParam | true | 指定安装所需的其他参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，安装应用成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 17700004 | The specified user ID is not found. |  
| 17700010 | Failed to install the HAP because the HAP fails to be parsed. |  
| 17700011 | Failed to install the HAP because the HAP signature fails to be verified. |  
| 17700012 | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |  
| 17700015 | Failed to install the HAPs because they have different configuration information. |  
| 17700016 | Failed to install the HAP because of insufficient system disk space. |  
| 17700017 | Failed to install the HAP since the version of the HAP to install is too early. |  
| 17700018 | Failed to install because the dependent module does not exist. |  
| 17700039 | Failed to install because disallow install a shared bundle by hapFilePaths. |  
| 17700041 | Failed to install because enterprise device management disallow install. |  
| 17700042 | Failed to install the HAP because of incorrect URI in the data proxy. |  
| 17700043 | Failed to install the HAP because of low APL in the non-system data proxy (required APL: system_basic or system_core). |  
| 17700044 | Failed to install the HAP because the isolationMode configured is not supported. |  
| 17700047 | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |  
| 17700048 | Failed to install the HAP because the bundleName is different from the bundleName of the caller application. |  
| 17700049 | Failed to install the HAP because enterprise normal/MDM bundle cannot be installed on non-enterprise device. |  
| 17700050 | Failed to install the HAP because enterprise normal/MDM bundle cannot be installed on non-enterprise device. |  
| 17700051 | Failed to install the HAP because the distribution type of caller application is not enterprise_mdm. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import installer from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];  
let installParam: installer.InstallParam = {  
    userId: 100,  
    isKeepData: false,  
    installFlag: 1,  
};  
  
try {  
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {  
        data.updateBundleForSelf(hapFilePaths, installParam, (err: BusinessError) => {  
            if (err) {  
                console.error('updateBundleForSelf failed:' + err.message);  
            } else {  
                console.info('updateBundleForSelf successfully.');  
            }  
        });  
    }).catch((error: BusinessError) => {  
        console.error('getBundleInstaller failed. Cause: ' + error.message);  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getBundleInstaller failed. Cause: ' + message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import installer from '@ohos.bundle.installer';  
import { BusinessError } from '@ohos.base';  
  
let hapFilePaths = ['/data/storage/el2/base/haps/entry/files/'];  
let installParam: installer.InstallParam = {  
    userId: 100,  
    isKeepData: false,  
    installFlag: 1,  
};  
  
try {  
    installer.getBundleInstaller().then((data: installer.BundleInstaller) => {  
        data.updateBundleForSelf(hapFilePaths, installParam)  
            .then((data: void) => {  
                console.info('updateBundleForSelf successfully: ' + JSON.stringify(data));  
        }).catch((error: BusinessError) => {  
            console.error('updateBundleForSelf failed:' + error.message);  
        });  
    }).catch((error: BusinessError) => {  
        console.error('getBundleInstaller failed. Cause: ' + error.message);  
    });  
} catch (error) {  
    let message = (error as BusinessError).message;  
    console.error('getBundleInstaller failed. Cause: ' + message);  
}  
    
```    
  
    
## HashParam    
应用程序安装卸载哈希参数信息。  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| moduleName | string | false | true | 应用程序模块名称。<br/> |  
| hashValue | string | false | true | 哈希值。<br/> |  
    
## VerifyCodeParam<sup>(10+)</sup>    
应用程序代码签名文件信息。  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| moduleName<sup>(10+)</sup> | string | false | true | 应用程序模块名称。<br/> |  
| signatureFilePath<sup>(10+)</sup> | string | false | true | 代码签名文件路径。<br/> |  
    
## InstallParam    
应用程序安装、卸载或恢复需指定的参数信息。  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| userId | number | false | false | 指示用户id，默认值：调用方所在用户，取值范围：大于等于0，可使用[queryOsAccountLocalIdFromProcess](js-apis-osAccount.md#getOsAccountLocalId)获取当前进程所在用户。  |  
| installFlag | number | false | false | 指示安装标志，枚举值：0x00：应用初次安装，0x01：应用覆盖安装，0x10：应用免安装，默认值为应用初次安装。<br/> |  
| isKeepData | boolean | false | false | 卸载时是否保留数据目录，默认值为false。 |  
| hashParams | Array<HashParam> | false | false | 哈希值参数，默认值为空。 |  
| crowdtestDeadline | number | false | false | 众测活动的截止日期，默认值为-1，表示无截止日期约束。<br/> |  
| sharedBundleDirPaths<sup>(10+)</sup> | Array<String> | false | false | 共享包文件所在路径，默认值为空。<br/> |  
| specifiedDistributionType<sup>(10+)</sup> | string | false | false | 应用安装时指定的分发类型，默认值为空，最大长度为128字节。该字段通常由操作系统运营方的应用市场指定。<br/> |  
| additionalInfo<sup>(10+)</sup> | string | false | false | 应用安装时的额外信息，默认值为空，最大长度为3000字节。该字段通常由操作系统运营方的应用市场在安装企业应用时指定，用于保存应用的额外信息。<br/> |  
| verifyCodeParams<sup>(10+)</sup> | Array<VerifyCodeParam> | false | false | 代码签名文件参数，默认值为空。<br/> |  
    
## UninstallParam<sup>(10+)</sup>    
共享包卸载需指定的参数信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
### 属性    
 **系统能力:**  SystemCapability.BundleManager.BundleFramework.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName<sup>(10+)</sup> | string | false | true | 共享包包名。<br/> |  
| versionCode<sup>(10+)</sup> | number | false | false | 指示共享包的版本号。默认值：如果不填写versionCode，则卸载该包名的所有共享包。 |  
