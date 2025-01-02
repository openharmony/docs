# @ohos.ability.screenLockFileManager (锁屏敏感数据管理)(系统接口)

敏感数据密钥在锁屏后会触发销毁，销毁后敏感数据无法读写，需解锁屏幕触发恢复敏感数据密钥后方可访问。本模块提供应用锁屏下敏感数据保护的能力，支持申请和释放锁屏下敏感数据访问权限等。

> **说明：**
> - 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.ability.screenLockFileManager](js-apis-screenLockFileManager.md)。

## 导入模块

```ts
import { screenLockFileManager } from '@kit.AbilityKit';
```

## DataType

枚举，指定锁屏下访问的敏感数据类型。

 **系统能力：** SystemCapability.Security.ScreenLockFileManager

 **系统接口：** 此接口为系统接口。

| 名称       | 值         | 说明           |
| ---------- | ---------- | -------------- |
| MEDIA_DATA | 0x00000001 | 媒体类型数据。 |
| ALL_DATA   | 0xffffffff | 所有敏感加密数据。     |

## screenLockFileManager.acquireAccess

acquireAccess(dataType: DataType): AccessStatus

以同步方法申请锁屏下指定类型的敏感数据访问权限。 锁屏后，敏感数据无法被访问，但可通过调用该方法，访问指定类型的敏感数据。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_SCREEN_LOCK_MEDIA_DATA 或 ohos.permission.ACCESS_SCREEN_LOCK_ALL_DATA

**系统能力：** SystemCapability.Security.ScreenLockFileManager

**参数：**

| 参数名  | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| dataType | [DataType](#datatype) | 是   | 锁屏下访问的敏感数据类型。 |

**返回值：**

| 类型                                                        | 说明                                  |
| ----------------------------------------------------------- | ------------------------------------- |
| [AccessStatus](js-apis-screenLockFileManager.md#accessstatus) | 锁屏下敏感数据访问权限申请的状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.screenLockFileManager错误码](errorcode-screenLockFileManager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed, usually returned by VerifyAccessToken. |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801 | The specified SystemCapability name was not found. |
| 29300001 | Invalid parameter. |
| 29300002 | The system ability work abnormally. |
| 29300003 | The application is not enabled the data protection under lock screen. |
| 29300004 | File access is denied. |

**示例：**

```ts
// 申请锁屏下媒体类型数据的访问权限
import { screenLockFileManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    let acquireStatus = screenLockFileManager.acquireAccess(screenLockFileManager.DataType.MEDIA_DATA);
    if (acquireStatus === screenLockFileManager.AccessStatus.ACCESS_GRANTED) {
        hilog.info(0x0000, 'testTag', 'acquireAccess successfully.');
    }
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'acquireAccess failed: %{public}s', message);
}
```

## screenLockFileManager.releaseAccess

releaseAccess(dataType: DataType): ReleaseStatus

以同步方法取消锁屏下指定类型敏感数据访问权限。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_SCREEN_LOCK_MEDIA_DATA 或 ohos.permission.ACCESS_SCREEN_LOCK_ALL_DATA

**系统能力：** SystemCapability.Security.ScreenLockFileManager

**参数：**

| 参数名  | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| dataType | [DataType](#datatype) | 是   | 锁屏下访问的敏感数据类型。 |

**返回值：**

| 类型                                                         | 说明                           |
| ------------------------------------------------------------ | ------------------------------ |
| [ReleaseStatus](js-apis-screenLockFileManager.md#releasestatus) | 锁屏下敏感数据访问权限释放的状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[ohos.screenLockFileManager错误码](errorcode-screenLockFileManager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed, usually returned by VerifyAccessToken. |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801      | The specified SystemCapability name was not found.           |
| 29300001 | Invalid parameter.                                           |
| 29300002 | The system ability work abnormally.                          |
| 29300003 | The application is not enabled the data protection under lock screen. |
| 29300005 | File access was not acquired.                                |

**示例：**

```ts
// 释放锁屏下媒体类型数据的访问权限
import { screenLockFileManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

try {
    let releaseStatus = screenLockFileManager.releaseAccess(screenLockFileManager.DataType.MEDIA_DATA);
    if (releaseStatus === screenLockFileManager.ReleaseStatus.RELEASE_GRANTED) {
        hilog.info(0x0000, 'testTag', 'releaseAccess successfully.');
    }
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'releaseAccess failed: %{public}s', message);
}
```