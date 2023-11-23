# @ohos.file.backup    
该模块为应用提供备份/恢复数据的能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import backup from '@ohos.file.backup'    
```  
    
## FileMeta    
文件的元数据，包含一个应用名称以及文件uri。FileMeta在执行备份/恢复时是不可缺少的对象。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundleName | string | false | true | 应用名称，可通过[bundle.BundleInfo](js-apis-bundle-BundleInfo.md)提供的获取方式获取。 |  
| uri | string | false | true | 应用沙箱内待传输文件的名称，当前uri尚未升级为标准格式，仅接受0-9a-zA-Z下划线(_)点(.)组成的名称 |  
    
## FileData    
文件的元数据，包含一个已经打开的文件描述符。FileData在执行备份/恢复时是不可缺少的对象  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fd | number | false | true | 已经打开的文件描述符，通过备份服务获取。 |  
    
## File    
一个文件对象。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup    
## getLocalCapabilities    
用于获取一个描述本地能力的Json文件。  
 **调用形式：**     
    
- getLocalCapabilities(): Promise\<FileData>    
起始版本： 10    
- getLocalCapabilities(callback: AsyncCallback\<FileData>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup  
 **需要权限：** ohos.permission.BACKUP    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当获取成功，err为undefined，否则为错误对象。 |  
| Promise<FileData> | Promise对象，返回描述本地能力的Json文件的FileData。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13600001 | IPC error |  
| 13900005 | I/O error |  
| 13900011 | Out of memory |  
| 13900025 | No space left on device |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
try {  
  backup.getLocalCapabilities((err: BusinessError, fileData: backup.FileData) => {  
    if (err) {  
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));  
    }  
    console.info('getLocalCapabilities success');  
    fs.closeSync(fileData.fd);  
  });  
} catch (error) {  
  let err: BusinessError = error as BusinessError;  
  console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
async function getLocalCapabilities() {  
  try {  
    let fileData = await backup.getLocalCapabilities();  
    console.info('getLocalCapabilities success');  
    fs.closeSync(fileData.fd);  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
## GeneralCallbacks    
备份/恢复过程中的通用回调，备份服务将通过这些回调通知客户端其应用的备份/恢复阶段。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup    
### 属性    
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onFileReady | AsyncCallback<File> | false | true | 回调函数。当服务端返向客户端发送文件成功时触发回调，err为undefined，否则为错误对象。 |  
| onBundleBegin | AsyncCallback<string> | false | true | 回调函数。当应用备份/恢复开始时返回bundle名称成功时触发回调，err为undefined，否则为错误对象。 |  
| onBundleEnd | AsyncCallback<string> | false | true | 回调函数。当应用备份/恢复结束后返回bundle名称成功时触发回调，err为undefined，否则为错误对象。 |  
| onAllBundlesEnd | AsyncCallback<undefined> | false | true | 回调函数。当所有bundle的备份/恢复过程结束成功时触发回调，err为undefined，否则为错误对象。 |  
| onBackupServiceDied | Callback<undefined> | false | true | 回调函数。备份服务死亡时触发回调。 |  
    
## SessionBackup    
备份流程对象，用来支撑应用备份的流程。在使用前，需要先创建SessionBackup实例。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup    
### appendBundles    
添加需要备份的应用。当前整个流程中，在获取SessionBackup类的实例后只能调用一次。  
 **调用形式：**     
    
- appendBundles(bundlesToBackup: string[]): Promise\<void>    
起始版本： 10    
- appendBundles(bundlesToBackup: string[], callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup  
 **需要权限：** ohos.permission.BACKUP    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundlesToBackup | string[] | true | 需要备份的应用名称的数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当添加备份应用成功，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13600001 | IPC error |  
| 13900001 | Operation not permitted |  
| 13900005 | I/O error |  
| 13900011 | Out of memory |  
| 13900020 | Invalid argument |  
| 13900025 | No space left on device |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
let generalCallbacks: backup.GeneralCallbacks = {  
  onFileReady: (err: BusinessError, file: backup.File) => {  
    if (err) {  
      console.error('onFileReady failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onFileReady success');  
    fs.closeSync(file.fd);  
  },  
  onBundleBegin: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleBegin failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleBegin success');  
  },  
  onBundleEnd: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleEnd success');  
  },  
  onAllBundlesEnd: (err: BusinessError) => {  
    if (err) {  
      console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onAllBundlesEnd success');  
  },  
  onBackupServiceDied: () => {  
    console.info('service died');  
  }  
};  
let sessionBackup = new backup.SessionBackup(generalCallbacks);  
try {  
  let backupApps: Array<string> = [  
    "com.example.hiworld",  
  ];  
  sessionBackup.appendBundles(backupApps, (err: BusinessError) => {  
    if (err) {  
      console.error('appendBundles failed with err: ' + JSON.stringify(err));  
    }  
    console.info('appendBundles success');  
  });  
} catch (error) {  
  let err: BusinessError = error as BusinessError;  
  console.error('appendBundles failed with err: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
let generalCallbacks: backup.GeneralCallbacks = {  
  onFileReady: (err: BusinessError, file: backup.File) => {  
    if (err) {  
      console.error('onFileReady failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onFileReady success');  
    fs.closeSync(file.fd);  
  },  
  onBundleBegin: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleBegin failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleBegin success');  
  },  
  onBundleEnd: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleEnd success');  
  },  
  onAllBundlesEnd: (err: BusinessError) => {  
    if (err) {  
      console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onAllBundlesEnd success');  
  },  
  onBackupServiceDied: () => {  
    console.info('service died');  
  }  
};  
let sessionBackup = new backup.SessionBackup(generalCallbacks);  
async function appendBundles() {  
  try {  
    let backupApps: Array<string> = [  
      "com.example.hiworld",  
    ];  
    await sessionBackup.appendBundles(backupApps);  
    console.info('appendBundles success');  
  } catch (error) {  
  let err: BusinessError = error as BusinessError;  
  console.error('appendBundles failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
## SessionRestore    
恢复流程对象，用来支撑应用恢复的流程。在使用前，需要先创建SessionRestore实例。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup    
### appendBundles    
添加需要恢复的应用。当前整个流程中，在获取SessionRestore类的实例后只能调用一次。  
 **调用形式：**     
    
- appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[]): Promise\<void>    
起始版本： 10    
- appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[], callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup  
 **需要权限：** ohos.permission.BACKUP    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| remoteCapabilitiesFd | number | true | 用于恢复所需能力文件的文件描述符。 |  
| bundlesToBackup | string[] | true | 需要恢复的应用名称的数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当添加恢复应用成功，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13600001 | IPC error |  
| 13900001 | Operation not permitted |  
| 13900005 | I/O error |  
| 13900011 | Out of memory |  
| 13900020 | Invalid argument |  
| 13900025 | No space left on device |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
let generalCallbacks: backup.GeneralCallbacks = {  
  onFileReady: (err: BusinessError, file: backup.File) => {  
    if (err) {  
      console.error('onFileReady failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onFileReady success');  
    fs.closeSync(file.fd);  
  },  
  onBundleBegin: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleBegin failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleBegin success');  
  },  
  onBundleEnd: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleEnd success');  
  },  
  onAllBundlesEnd: (err: BusinessError) => {  
    if (err) {  
      console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onAllBundlesEnd success');  
  },  
  onBackupServiceDied: () => {  
    console.info('service died');  
  }  
};  
let sessionRestore = new backup.SessionRestore(generalCallbacks);  
async function appendBundles() {  
  try {  
    let fileData = await backup.getLocalCapabilities();  
    console.info('getLocalCapabilities success');  
    let restoreApps: Array<string> = [  
      "com.example.hiworld",  
    ];  
    sessionRestore.appendBundles(fileData.fd, restoreApps, (err: BusinessError) => {  
      if (err) {  
        console.error('appendBundles failed with err: ' + JSON.stringify(err));  
      }  
      console.info('appendBundles success');  
    });  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
let generalCallbacks: backup.GeneralCallbacks = {  
  onFileReady: (err: BusinessError, file: backup.File) => {  
    if (err) {  
      console.error('onFileReady failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onFileReady success');  
    fs.closeSync(file.fd);  
  },  
  onBundleBegin: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleBegin failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleBegin success');  
  },  
  onBundleEnd: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleEnd success');  
  },  
  onAllBundlesEnd: (err: BusinessError) => {  
    if (err) {  
      console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onAllBundlesEnd success');  
  },  
  onBackupServiceDied: () => {  
    console.info('service died');  
  }  
};  
let sessionRestore = new backup.SessionRestore(generalCallbacks);  
async function appendBundles() {  
  try {  
    let fileData = await backup.getLocalCapabilities();  
    console.info('getLocalCapabilities success');  
    let restoreApps: Array<string> = [  
      "com.example.hiworld",  
    ];  
    await sessionRestore.appendBundles(fileData.fd, restoreApps);  
    console.info('appendBundles success');  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
    
### publishFile    
用于将FileMeta发布到备份服务，使服务知道文件的内容已经准备完成。  
 **调用形式：**     
    
- publishFile(fileMeta: FileMeta): Promise\<void>    
起始版本： 10    
- publishFile(fileMeta: FileMeta, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup  
 **需要权限：** ohos.permission.BACKUP    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fileMeta | FileMeta | true | 恢复文件元数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当发布文件成功，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13600001 | IPC error |  
| 13900001 | Operation not permitted |  
| 13900020 | Invalid argument |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
let g_session: backup.SessionRestore;  
function createSessionRestore() {  
  let generalCallbacks: backup.GeneralCallbacks = {  
    onFileReady: (err: BusinessError, file: backup.File) => {  
      if (err) {  
        console.error('onFileReady failed with err: ' + JSON.stringify(err));  
      }  
      console.info('onFileReady success');  
      fs.closeSync(file.fd);  
      let fileMeta: backup.FileMeta = {  
        bundleName: file.bundleName,  
        uri: file.uri  
      }  
      g_session.publishFile(fileMeta, (err: BusinessError) => {  
        if (err) {  
          console.error('publishFile failed with err: ' + JSON.stringify(err));  
        }  
        console.info('publishFile success');  
      });  
    },  
    onBundleBegin: (err: BusinessError, bundleName: string) => {  
      if (err) {  
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));  
      }  
      console.info('onBundleBegin success');  
    },  
    onBundleEnd: (err: BusinessError, bundleName: string) => {  
      if (err) {  
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));  
      }  
      console.info('onBundleEnd success');  
    },  
    onAllBundlesEnd: (err: BusinessError) => {  
      if (err) {  
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));  
      }  
      console.info('onAllBundlesEnd success');  
    },  
    onBackupServiceDied: () => {  
      console.info('service died');  
    }  
  };  
  let sessionRestore = new backup.SessionRestore(generalCallbacks);  
  return sessionRestore;  
}  
g_session = createSessionRestore();  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
let g_session: backup.SessionRestore;  
async function publishFile(file: backup.FileMeta) {  
  let fileMeta: backup.FileMeta = {  
    bundleName: file.bundleName,  
    uri: file.uri  
  }  
  await g_session.publishFile(fileMeta);  
}  
function createSessionRestore() {  
  let generalCallbacks: backup.GeneralCallbacks = {  
    onFileReady: (err: BusinessError, file: backup.File) => {  
      if (err) {  
        console.error('onFileReady failed with err: ' + JSON.stringify(err));  
      }  
      console.info('onFileReady success');  
      fs.closeSync(file.fd);  
      publishFile(file);  
      console.info('publishFile success');  
    },  
    onBundleBegin: (err: BusinessError, bundleName: string) => {  
      if (err) {  
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));  
      }  
      console.info('onBundleBegin success');  
    },  
    onBundleEnd: (err: BusinessError, bundleName: string) => {  
      if (err) {  
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));  
      }  
      console.info('onBundleEnd success');  
    },  
    onAllBundlesEnd: (err: BusinessError) => {  
      if (err) {  
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));  
      }  
      console.info('onAllBundlesEnd success');  
    },  
    onBackupServiceDied: () => {  
      console.info('service died');  
    }  
  };  
  let sessionRestore = new backup.SessionRestore(generalCallbacks);  
  return sessionRestore;  
}  
g_session = createSessionRestore();  
    
```    
  
    
### getFileHandle    
用于请求从服务中获取共享文件。  
 **调用形式：**     
    
- getFileHandle(fileMeta: FileMeta): Promise\<void>    
起始版本： 10    
- getFileHandle(fileMeta: FileMeta, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.FileManagement.StorageService.Backup  
 **需要权限：** ohos.permission.BACKUP    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fileMeta | FileMeta | true | 恢复文件的元数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当请求文件句柄成功，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 13600001 | IPC error |  
| 13900001 | Operation not permitted |  
| 13900020 | Invalid argument |  
| 13900042 | Unknown error |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
let generalCallbacks: backup.GeneralCallbacks = {  
  onFileReady: (err: BusinessError, file: backup.File) => {  
    if (err) {  
      console.error('onFileReady failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onFileReady success');  
    fs.closeSync(file.fd);  
  },  
  onBundleBegin: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleBegin failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleBegin success');  
  },  
  onBundleEnd: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleEnd success');  
  },  
  onAllBundlesEnd: (err: BusinessError) => {  
    if (err) {  
      console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onAllBundlesEnd success');  
  },  
  onBackupServiceDied: () => {  
    console.info('service died');  
  }  
};  
let sessionRestore = new backup.SessionRestore(generalCallbacks);  
let fileMeta: backup.FileMeta = {  
  bundleName: "com.example.hiworld",  
  uri: "test.txt"  
}  
sessionRestore.getFileHandle(fileMeta, (err: BusinessError) => {  
  if (err) {  
    console.error('getFileHandle failed with err: ' + JSON.stringify(err));  
  }  
  console.info('getFileHandle success');  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import fs from '@ohos.file.fs';  
import { BusinessError } from '@ohos.base';  
let generalCallbacks: backup.GeneralCallbacks = {  
  onFileReady: (err: BusinessError, file: backup.File) => {  
    if (err) {  
      console.error('onFileReady failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onFileReady success');  
    fs.closeSync(file.fd);  
  },  
  onBundleBegin: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleBegin failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleBegin success');  
  },  
  onBundleEnd: (err: BusinessError, bundleName: string) => {  
    if (err) {  
      console.error('onBundleEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onBundleEnd success');  
  },  
  onAllBundlesEnd: (err: BusinessError) => {  
    if (err) {  
      console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));  
    }  
    console.info('onAllBundlesEnd success');  
  },  
  onBackupServiceDied: () => {  
    console.info('service died');  
  }  
};  
let sessionRestore = new backup.SessionRestore(generalCallbacks);  
async function getFileHandle() {  
  try {  
    let fileMeta: backup.FileMeta = {  
      bundleName: "com.example.hiworld",  
      uri: "test.txt"  
    }  
    await sessionRestore.getFileHandle(fileMeta);  
    console.info('getFileHandle success');  
  } catch (error) {  
    let err: BusinessError = error as BusinessError;  
    console.error('getFileHandle failed with err: ' + JSON.stringify(err));  
  }  
}  
    
```    
  
