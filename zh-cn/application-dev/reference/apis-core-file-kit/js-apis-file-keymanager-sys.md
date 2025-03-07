# @ohos.file.keyManager (用户秘钥管理)(系统接口)

该模块提供用户秘钥管理相关的常用功能：包括用户秘钥卸载等。

> **说明：**
>
> - 本模块首批接口从API version 15开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口。

## 导入模块

```ts
import { keyManager } from "@kit.CoreFileKit";
```

## keyManager.deactivateUserKey

deactivateUserKey(userId: number):void

用户锁屏时，同步卸载指定用户对应秘钥。**（该接口目前仅开放给锁屏应用）**

**需要权限**：ohos.permission.STORAGE_MANAGER_CRYPT

**系统能力**：SystemCapability.FileManagement.StorageService.Encryption

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | userId | number | 是   | 用户id。锁屏应用感知设备当前登录的用户，指定为该用户。|

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified; Or input parameter has type different from the type the interface requires. |
| 13600001 | IPC error. |
| 13600008 | No such object. Possible causes: Cannot find user key for the specified user. |
| 13600009 | User ID out of range. Possible causes: input parameter userId < 100 or userId > 10736. |

**示例：**

  ```ts
  import { keyManager } from "@kit.CoreFileKit";
  import { BusinessError } from '@ohos.base';
  let userId: number = 100;
  try {
    keyManager.deactivateUserKey(userId);
    console.info("deactivateUserKey success");
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("deactivateUserKey failed with error:" + JSON.stringify(error));
  }
  ```