# @ohos.file.cloudDiskManager (云盘管理)(系统接口)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @yangwei_814916-->
<!--Designer: @hwzhangchuang; @Dyylll-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->

本模块为系统文件管理应用提供获取三方云盘注册的同步根信息（包括路径、包名、状态等）的能力，适用于展示和管理三方云盘同步根目录的场景。同步根是指三方云盘应用在系统中注册的本地同步目录的根路径，系统文件管理应用可通过该信息识别和管理不同云盘的同步状态。


> **说明：**
>
> 本模块首批接口从API version 21开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { cloudDiskManager } from '@kit.CoreFileKit';
```

## SyncFolderAccessor

同步根访问器，为系统文件管理应用提供获取所有已注册的同步根列表（包括路径、包名、状态等详细信息）的能力。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.CloudDiskManager

### constructor

constructor()

SyncFolderAccessor的构造函数，用于创建SyncFolderAccessor类的实例。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.CloudDiskManager

**需要权限**：ohos.permission.ACCESS_CLOUD_DISK_INFO

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | Permission verification failed, application which is not a system application uses system API. |

**示例：**

  ```ts
  import { cloudDiskManager } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct Index {
    build() {
      Column() {
        Button('constructor')
        .onClick(async() => {
            try {
              let syncFolderAccessor: cloudDiskManager.SyncFolderAccessor = new cloudDiskManager.SyncFolderAccessor();
            } catch (err) {
                let error: BusinessError = err as BusinessError;
                console.error(`SyncFolderAccessor constructor failed. Code: ${error.code}, message: ${error.message}`);
            }
        });
      }
    }
  }

  ```
  
### getAllSyncFolders

getAllSyncFolders(): Promise&lt;Array&lt;SyncFolder&gt;&gt;

获取所有注册的同步根信息，适用于系统文件管理应用展示和管理三方云盘同步根列表的场景。使用Promise异步回调。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.CloudDiskManager

**需要权限**：ohos.permission.ACCESS_CLOUD_DISK_INFO

**返回值：**

| 类型 | 说明 |
| --- | -- |
| Promise&lt;Array&lt;[SyncFolder](#syncfolder)&gt;&gt; | Promise对象。resolve时返回所有三方云盘应用的同步根列表，reject时返回BusinessError错误对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[云盘管理错误码](errorcode-clouddiskmanager-sys.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 801 | Device not supported. |
| 34400003 | IPC communication failed. |
| 34400014 | Temporary failure. Retry is recommended (e.g., network issues). |
| 34400015 | Cloud disk is not allowed on this device. |

**示例：**

```ts
import { cloudDiskManager } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
const TAG: string = '[cloudDiskManager]';

try {
    console.info(`${TAG}getAllSyncFolders start`);
    let syncFolderAccessor: cloudDiskManager.SyncFolderAccessor = new cloudDiskManager.SyncFolderAccessor();
    syncFolderAccessor.getAllSyncFolders().then((syncFolders) => {
        console.info(`${TAG}getAllSyncFolders success, length: ${syncFolders.length}`);
        for (let i = 0; i < syncFolders.length; ++i) {
            console.info(`${TAG}syncFolders[${i}].path: ${syncFolders[i].path}`);
            console.info(`${TAG}syncFolders[${i}].bundleName: ${syncFolders[i].bundleName}`);
            console.info(`${TAG}syncFolders[${i}].state: ${syncFolders[i].state}`);
            if (syncFolders[i].displayNameResId) {
                console.info(`${TAG}syncFolders[${i}].displayNameResId: ${syncFolders[i].displayNameResId}`);
            }
            if (syncFolders[i].customAlias) {
                console.info(`${TAG}syncFolders[${i}].customAlias: ${syncFolders[i].customAlias}`);
            }
        }
    }).catch((err: BusinessError<object>) => {
        console.error(`${TAG}Failed to getAllSyncFolders. Code: ${err.code}, message: ${err.message}`);
    });
} catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error(`${TAG}getAllSyncFolders failed. Code: ${error.code}, message: ${error.message}`);
}
```

## SyncFolder

表示同步根信息，包含同步根的路径、包名、状态以及显示别名等详细信息，用于系统文件管理应用识别和管理不同云盘的同步根。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.CloudDiskManager

| 名称      | 类型   | 只读 | 可选 | 说明      |
| --------- | ------ | ---- | ---- | ---------------------------- |
| path | string | 否   | 否   | 同步根对应的本地绝对路径，表示三方云盘应用在系统中注册的本地同步目录的根路径。     |
| bundleName   | string | 否   | 否   | 注册该同步根的三方云盘应用的包名。   |
| state   | [SyncFolderState](#syncfolderstate) | 否   | 否   | 同步根的同步状态，取值为INACTIVE（未激活）或ACTIVE（激活），详见SyncFolderState。   |
| displayNameResId   | number | 否   | 是   | 资源ID，用于映射文件管理应用列表中显示的别名。当三方云盘应用通过资源ID指定显示别名时，此字段包含对应的资源ID；未指定时默认值为undefined，表示不使用资源ID指定的别名。与customAlias均可用于设置显示别名，两者同时存在时以系统实现为准。   |
| customAlias   | string | 否   | 是   | 在文件管理应用列表显示的自定义别名。当三方云盘应用直接指定自定义别名时，此字段包含对应的别名内容；未指定时默认值为undefined。与displayNameResId均可用于设置显示别名，两者同时存在时以系统实现为准。   |

## SyncFolderState

枚举，三方云盘同步根的状态。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.CloudDiskManager

| 名称      | 值  | 说明      |
| --------- | -----| ------------------------|
| INACTIVE  |  0   | 表示同步根处于未激活状态。|
| ACTIVE    |  1   | 表示同步根处于激活状态。  |
