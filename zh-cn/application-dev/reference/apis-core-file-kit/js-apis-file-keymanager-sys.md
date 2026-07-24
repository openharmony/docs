# @ohos.file.keyManager (用户密钥管理)(系统接口)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @gzhuangzhuang-->
<!--Designer: @renguang1116; @wang_zhangjun-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->

该模块提供用户密钥管理功能，当前支持在用户锁屏时同步卸载指定用户的密钥，满足锁屏应用在设备锁屏时保护用户数据安全的需求。用户密钥与用户数据的加密保护相关，在用户锁屏等场景下需要对密钥进行卸载以管理数据的加密状态。当前版本仅提供卸载密钥的接口，密钥加载的机制请参考系统安全相关文档。

> **说明：**
>
> - 本模块首批接口从API version 15开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口。

## 导入模块

```ts
import { keyManager } from '@kit.CoreFileKit';
```

## keyManager.deactivateUserKey

deactivateUserKey(userId: number):void

用户锁屏时，同步卸载指定用户对应的密钥。卸载后，该用户对应的加密数据将无法被解密访问，从而保护用户数据安全。**（该接口目前仅开放给锁屏应用）**

**需要权限**：ohos.permission.STORAGE_MANAGER_CRYPT

**系统能力**：SystemCapability.FileManagement.StorageService.Encryption

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | userId | number | 是   | 用户ID。取值范围[100, 10738]。锁屏应用获取设备当前登录的用户，将userId指定为该用户的ID。|

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | void | 无返回值。该方法为同步调用，调用成功后密钥即被卸载，调用失败时抛出异常。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified; Or input parameter has type different from the type the interface requires. |
| 13600001 | IPC error. |
| 13600008 | No such object. Possible causes: Cannot find userkey for the specified user. |
| 13600009 | User ID out of range. Possible causes: input parameter userId < 100 or userId > 10736. |

**示例：**

  ```ts
  import { keyManager } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  let userId: number = 100;
  try {
    keyManager.deactivateUserKey(userId);
    console.info('deactivateUserKey success');
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error(`deactivateUserKey failed with error. Code: ${error.code}, message: ${error.message}`);
  }
  ```