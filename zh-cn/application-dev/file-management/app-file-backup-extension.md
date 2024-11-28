# 应用接入数据备份恢复

应用接入数据备份恢复需要通过BackupExtensionAbility实现。

BackupExtensionAbility，是[Stage模型](../application-models/stage-model-development-overview.md)中扩展组件[ExtensionAbility](../application-models/extensionability-overview.md)的派生类。开发者可以通过修改配置文件定制备份恢复框架的行为，包括是否允许备份恢复，备份哪些文件等。

## 接口说明

备份恢复扩展能力API的接口使用指导请参见[BackupExtensionAbility API参考](../reference/apis-core-file-kit/js-apis-application-backupExtensionAbility.md#backupextensionability)和[BackupExtensionContext API参考](../reference/apis-core-file-kit/js-apis-file-backupextensioncontext.md)。

## 约束与限制

- 当备份恢复时，所有待备份文件及目录的路径不得超过4095字节，否则将导致未定义行为。
- 当备份目录时，应用进程必须拥有读取该目录及其所有子目录的权限（DAC中的`r`），否则将导致备份失败。
- 当备份文件时，应用进程必须拥有搜索该文件所有祖父级目录的权限（DAC中的`x`），否则将导致备份失败。
- 当备份恢复时，所有待备份恢复的文件及目录不支持相对路径(../)和软链接。

## 开发步骤

1. 在应用配置文件`module.json5`中注册`extensionAbilities`相关配置

   新增`"extensionAbilities"`字段，其中注册类型`"type"`设置为`"backup"`，元数据信息["metadata"](../reference/apis-ability-kit/js-apis-bundleManager-metadata.md)新增一个`"name"`为`"ohos.  extension. backup"`的条目。

   BackupExtensionAbility配置文件示例：

   ```json
   {
       "extensionAbilities": [
           {
               "description": "$string:ServiceExtAbility",
               "icon": "$media:icon",
               "name": "BackupExtensionAbility",
               "type": "backup",
               "exported": false,
               "metadata": [
                   {
                       "name": "ohos.extension.backup",
                       "resource": "$profile:backup_config"
                   }
               ],
               // 在BackupExtension.ets文件里自定义继承BackupExtensionAbility，重写其中的onBackup/onBackupEx和
               // onRestore/onRestoreEx方法，推荐使用onBackupEx/onRestoreEx。
               // 如果没有特殊要求可以空实现，则备份恢复服务会按照统一的备份恢复数据规则进行备份恢复。
               "srcEntry": "./ets/BackupExtension/BackupExtension.ets", 
           }      
       ]
   }
   ```

2. 新增元数据资源配置文件

   在元数据资源配置文件中，定义备份恢复时需要传输的文件。元数据资源配置文件名称需要与`module.json5`中`"metadata.resource"例如"backup_config.json"`名称保持一致，其保存位置在工程的`resources/base/profile`文件夹下。

   元数据资源配置文件示例：

   ```json
   {
       "allowToBackupRestore": true,
       "includes": [
           "/data/storage/el2/base/files/users/"
       ],
       "excludes": [
           "/data/storage/el2/base/files/users/hidden/"
       ],
       "fullBackupOnly": false,
       "restoreDeps": ""
   }
   ```

3. 开发者可以在`BackupExtension.ets`文件中自定义类继承的`BackupExtensionAbility`，通过重写其`onBackup/onBackupEx`和`onRestore/onRestoreEx`方法，使其达到在备份预加工应用数据或者在恢复阶段加工待恢复文件。

   如果没有特殊要求可以空实现，则备份恢复服务会按照统一的备份恢复数据规则进行备份恢复。

   下面的示例展示了一个空实现的`BackupExtension.ets`文件：

    ```ts
    //onBackup && onRestore
    import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
    import {hilog} from '@kit.PerformanceAnalysisKit';
    
    const TAG = `FileBackupExtensionAbility`;
    export default class BackupExtension extends  BackupExtensionAbility {
      //onBackup
      async onBackup ()   {
        hilog.info(0x0000, TAG, `onBackup ok`);
      }
      //onRestore
      async onRestore (bundleVersion : BundleVersion) {
        hilog.info(0x0000, TAG, `onRestore ok ${JSON.stringify(bundleVersion)}`);
        hilog.info(0x0000, TAG, `onRestore end`);
      }
    }
    ```

    ```ts
    //onBackupEx && onRestoreEx
    import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';

    interface ErrorInfo {
      type: string,
      errorCode: number,
      errorInfo: string
    }

    class BackupExt extends BackupExtensionAbility {
      //onBackupEx
      async onBackupEx(backupInfo: string): Promise<string> {
        console.log(`onBackupEx ok`);
        let errorInfo: ErrorInfo = {
          type: "ErrorInfo",
          errorCode: 0,
          errorInfo: "app diy error info"       
        }
        return JSON.stringify(errorInfo);
      }

      // onRestoreEx
      async onRestoreEx(bundleVersion : BundleVersion, restoreInfo: string): Promise<string> {
        console.log(`onRestoreEx ok ${JSON.stringify(bundleVersion)}`);
        let errorInfo: ErrorInfo = {
          type: "ErrorInfo",
          errorCode: 0,
          errorInfo: "app diy error info"
        }
        return JSON.stringify(errorInfo);
      }
    }
    ```

### 元数据资源配置文件说明

| 属性名称             | 数据类型   | 必填 | 含义                                                         |
| -------------------- | ---------- | ---- | ------------------------------------------------------------ |
| allowToBackupRestore | 布尔值     | 是   | 是否允许备份恢复，默认为false。                              |
| includes             | 字符串数组 | 否   | 应用沙箱中需要备份的文件和目录。<br>当模式串以非/开始时，表示一个相对于根路径的相对路径。<br>`includes`支持的路径清单列表如下述代码段内容所示，当配置`includes`时请确保配置路径范围包含在其中。<br>当`includes`已配置时，备份恢复框架会采用开发者配置的模式串，否则将会采用下述代码段内容作为默认值。 |
| excludes             | 字符串数组 | 否   | `includes`中无需备份的例外项。格式同`includes`。<br>在配置`excludes`时，请确保其范围在`includes`的子集中。<br>当`excludes`已配置时，备份恢复框架会采用开发者配置的模式串，否则将会采用**空数组**作为默认值。 |
| fullBackupOnly       | 布尔值     | 否   | 是否使用应用默认恢复目录，默认值为false。当值为true时，恢复数据时会通过临时路径进行缓存，临时路径可通过[backupDir](../reference/apis-core-file-kit/js-apis-file-backupextensioncontext.md)获取。当值为false或者不配置该字段时，恢复数据会以'/'为根目录解压数据。 |
| restoreDeps          | 字符串     | 否   | **不推荐使用**，应用恢复时依赖其他应用数据，默认值为""，需要配置依赖应用名称。当前仅支持最多一个依赖项。配置的依赖仅在一次恢复任务上下文生效，如果一次恢复任务中没有检测到依赖应用，则忽略该依赖描述继续执行恢复任务。**依赖应用未恢复或者恢复失败都会导致本应用恢复失败**。 |
| extraInfo            | json串     | 否   | 额外信息可通过该字段传递。                                   |

> **说明：**
>
> 1、**有关fullBackupOnly字段的说明**
>
> - 当fullBackupOnly为false时，恢复数据会以 **/** 为根目录解压数据，同路径下的同名文件会被覆盖。
> - 当fullBackupOnly为true时，恢复数据会以临时目录为根目录解压数据，开发者需要在OnRestore/OnRestoreEx内自行实现恢复数据的逻辑，进行最终的恢复。
>
> 开发者可根据自身的业务场景，选择对应的恢复数据方式。
>
> 示例：
> 假设应用的数据备份路径为：**data/storage/el2/base/files/A/** 。那么在恢复时，如果配置了fullBackupOnly为false，数据会被直接解压到：**/data/storage/el2/base/files/A/**目录下，如果配置了fullBackupOnly为true，数据则会被解压到：**临时路径[backupDir](../reference/apis-core-file-kit/js-apis-file-backupextensioncontext.md) + /restore/data/storage/el2/base/files/A/** 目录下。

**includes支持的路径清单列表如下：**

```json
{
    "includes": [
    "data/storage/el1/database/",
    "data/storage/el1/base/files/",
    "data/storage/el1/base/preferences/",
    "data/storage/el1/base/haps/*/files/",
    "data/storage/el1/base/haps/*/preferences/",
    "data/storage/el2/database/",
    "data/storage/el2/base/files/",
    "data/storage/el2/base/preferences/",
    "data/storage/el2/base/haps/*/files/",
    "data/storage/el2/base/haps/*/preferences/",
    "data/storage/el2/distributedfiles/",
    "data/storage/el5/database/",
    "data/storage/el5/base/files/",
    "data/storage/el5/base/preferences/",
    "data/storage/el5/base/haps/*/files/",
    "data/storage/el5/base/haps/*/preferences/"
    ]
}
```

## 相关实例

针对应用接入数据的备份与恢复，有以下相关实例可供参考：

- [应用接入数据备份恢复（ArkTS）（Full SDK）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/FileBackupExtension)
