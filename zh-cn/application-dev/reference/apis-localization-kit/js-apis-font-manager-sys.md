# @ohos.fontManager (字体管理)(系统接口)

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

本模块为系统应用提供第三方字体的安装、卸载以及字体数据迁移能力。具体为：
- 安装指定路径的字体文件（支持.ttf、.ttc格式）。
- 根据字体名称卸载已安装的字体。
- 在设备升级期间启动字体数据迁移任务，并提供迁移进度和结果回调。

>  **说明：**
>  
>  - 本模块首批接口从API version 19开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
>  - 本模块为系统接口。

## 导入模块

```js
import { fontManager } from '@kit.LocalizationKit';
```

## installFont

installFont(path: string): Promise&lt;number&gt;

将指定路径下的字体文件安装到系统字体库中。使用Promise异步回调。

安装成功后，应用可以通过字体名称使用该字体。

**需要权限:** ohos.permission.UPDATE_FONT

**系统能力:** SystemCapability.Global.FontManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| path | string | 是    | 待安装的字体文件路径，仅支持.ttf和.ttc格式的字体文件。 |

**返回值：**

| 类型                    | 说明                     |
| --------------------- | ---------------------- |
| Promise&lt;number&gt; | Promise对象，返回安装结果。<br>- 返回0：安装成功，字体已添加到系统字体库。<br>- 返回其他值：安装失败，请根据错误码排查原因。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[字体管理错误码](errorcode-font-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 31100101 | The font does not exist.      |
| 31100102 | The font is not supported.    |
| 31100103 | Failed to copy the font file. |
| 31100104 | The font file is installed.   |
| 31100105 | Exceeded the maximum number of installed files. |
| 31100106 | The system ability works abnormally. |

**示例：**
  ```ts
  import { fontManager } from '@kit.LocalizationKit';

  async function installFont() {
    try {
      let res = await fontManager.installFont('fontPath');
      console.info('installFont suc. res is ' + res);
    } catch (error) {
      console.error('installFont err.' + error.code);
    }
    return;
  }
  ```

## uninstallFont

uninstallFont(fullName: string): Promise&lt;number&gt;

根据字体名称从系统字体库中卸载已安装的字体文件。使用Promise异步回调。

**需要权限:** ohos.permission.UPDATE_FONT

**系统能力:** SystemCapability.Global.FontManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| fullName | string | 是    | 需要卸载的字体名称，可通过打开.ttf或.ttc字体文件获取。<br>字体名称区分大小写，请确保与实际字体名称完全一致。 |

**返回值：**

| 类型                    | 说明                     |
| --------------------- | ---------------------- |
| Promise&lt;number&gt; | Promise对象，返回卸载结果。<br>- 返回0：卸载成功，字体已从系统字体库中移除。<br>- 返回其他值：卸载失败，请根据错误码排查原因。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[字体管理错误码](errorcode-font-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 31100107 | The font file does not exist. |
| 31100108 | Failed to delete the font file. |
| 31100109 | The system ability works abnormally. |

**示例：**
  ```ts
  import { fontManager } from '@kit.LocalizationKit';

  async function uninstallFont() {
    try {
      let res = await fontManager.uninstallFont('fontName');
      console.info('uninstallFont suc. res is ' + res);
    } catch (error) {
      console.error('uninstallFont err.' + error.code);
    }
    return;
  }
  ```

## dataMigration<sup>23+</sup>

dataMigration(callback: DataMigrationCallback): number

设备升级时使用的数据迁移接口，用于启动迁移任务，通过回调函数实时反馈迁移进度和结果。

**需要权限:** ohos.permission.UPDATE_FONT

**系统能力:** SystemCapability.Global.FontManager

**参数：** 

| 参数名   | 类型     | 必填   | 说明    |
| ----- | ------ | ---- | ----- |
| callback | [DataMigrationCallback](#datamigrationcallback23) | 是    | 数据迁移的回调函数。 |

**返回值：**

| 类型                    | 说明                     |
| --------------------- | ---------------------- |
| number | 迁移任务启动结果。<br>- 0：迁移任务启动成功，迁移任务将在后台执行并通过回调通知进度和结果。<br>- 其他值：迁移任务启动失败，请根据错误码排查原因。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[字体管理错误码](errorcode-font-manager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 31100110 | Call failed due to system error. |
| 31100111 | Data migration is in progress. |

**示例：**
  ```ts
  import { fontManager } from '@kit.LocalizationKit';

  async function dataMigration() {
    const callback: fontManager.DataMigrationCallback = {
      onHeartBeat: () => {
        console.info('onHeartBeat callback');
      },
      onProgress: (progress : fontManager.DataMigrationProgress) => {
        console.info('onProgress callback');
      },
      onResult: (result : number) => {
        console.info('onResult callback');
      }
    }
    try {
      let res = await fontManager.dataMigration(callback);
      console.info('dataMigration suc. res is ' + res);
    } catch (error) {
      console.error('dataMigration err.' + error.code);
    }
  }
  ```

## DataMigrationCallback<sup>23+</sup>

数据迁移时使用的回调接口类型，定义了数据迁移过程中的回调方法。开发者需实现该接口的所有方法，以接收迁移过程中的心跳通知、进度更新和最终结果。

### onHeartBeat<sup>23+</sup>

onHeartBeat(): void

回调函数，在数据迁移任务执行期间定期调用，用于通知开发者迁移任务仍在正常运行，开发者可据此更新UI提示或执行其他业务逻辑。

**系统能力：** SystemCapability.Global.FontManager

**示例：**
  ```ts
  import { fontManager } from '@kit.LocalizationKit';

  async function dataMigration() {
    const callback: fontManager.DataMigrationCallback = {
      onHeartBeat: () => {
        console.info('onHeartBeat callback');
      },
      onProgress: (progress : fontManager.DataMigrationProgress) => {
        console.info('onProgress callback');
      },
      onResult: (result : number) => {
        console.info('onResult callback');
      }
    }
    try {
      let res = await fontManager.dataMigration(callback);
      console.info('dataMigration suc. res is ' + res);
    } catch (error) {
      console.error('dataMigration err.' + error.code);
    }
  }
  ```

### onProgress<sup>23+</sup>

onProgress(progress : DataMigrationProgress): void

回调函数，在数据迁移任务执行过程中定期调用，用于通知开发者当前的迁移进度和预估剩余时间。当需要在UI上展示进度条、剩余时间等信息时使用此回调。

**系统能力：** SystemCapability.Global.FontManager

**参数：**

| 参数名  | 类型   | 必填 | 说明                               |
| ------- | ------ | ---- | ---------------------------------- |
| progress | [DataMigrationProgress](#datamigrationprogress23) | 是   | 数据迁移进度信息。 |

**示例：**
  ```ts
  import { fontManager } from '@kit.LocalizationKit';

  async function dataMigration() {
    const callback: fontManager.DataMigrationCallback = {
      onHeartBeat: () => {
        console.info('onHeartBeat callback');
      },
      onProgress: (progress : fontManager.DataMigrationProgress) => {
        console.info('onProgress callback');
      },
      onResult: (result : number) => {
        console.info('onResult callback');
      }
    }
    try {
      let res = await fontManager.dataMigration(callback);
      console.info('dataMigration suc. res is ' + res);
    } catch (error) {
      console.error('dataMigration err.' + error.code);
    }
  }
  ```

### onResult<sup>23+</sup>

onResult(result : number): void

回调函数，在数据迁移任务完成（无论成功或失败）后调用，用于通知开发者迁移的最终结果。当需要在迁移完成后执行后续操作（如更新UI、记录日志、通知用户等）时使用此回调。

**系统能力：** SystemCapability.Global.FontManager

**参数：**

| 参数名  | 类型   | 必填 | 说明                               |
| ------- | ------ | ---- | ---------------------------------- |
| result | number | 是   | 数据迁移结果。<br>0：数据迁移成功。<br>1：无需进行数据迁移。<br>2：获取用户ID失败。<br>3：检查目录失败。<br>4：初始化缓存目录失败。<br>5：打开源文件失败。<br>6：拷贝失败。<br>7：文件重命名失败。<br>8：文件删除失败。|

**示例：**
  ```ts
  import { fontManager } from '@kit.LocalizationKit';

  async function dataMigration() {
    const callback: fontManager.DataMigrationCallback = {
      onHeartBeat: () => {
        console.info('onHeartBeat callback');
      },
      onProgress: (progress : fontManager.DataMigrationProgress) => {
        console.info('onProgress callback');
      },
      onResult: (result : number) => {
        console.info('onResult callback');
      }
    }
    try {
      let res = await fontManager.dataMigration(callback);
      console.info('dataMigration suc. res is ' + res);
    } catch (error) {
      console.error('dataMigration err.' + error.code);
    }
  }
  ```

## DataMigrationProgress<sup>23+</sup>

描述数据迁移的进度信息，包含进度百分比和预估剩余时间。该接口为数据迁移回调onProgress方法的参数类型。

**系统能力：** SystemCapability.Global.FontManager

| 名称     | 类型 | 只读 | 可选    | 说明  |
| -------- | ---------------|--------|---------|-------------------------------- |
| timeRemaining | number  |是 | 否 | 预计剩余时间，可能因设备性能、文件大小、系统负载等因素而有所差异。<br>取值范围为非负整数，最小值为0。<br>单位为s。    |
| progressPercentage | number |是 | 否 | 数据迁移百分比进度，进度值根据已迁移的字体文件数量或大小计算，可能不是均匀增长。当progressPercentage为100时，迁移任务即将完成，onResult回调即将被调用。<br>取值范围为[0, 100]。|