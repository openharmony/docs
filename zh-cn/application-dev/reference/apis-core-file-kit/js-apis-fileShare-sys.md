# @ohos.fileshare (文件分享)(系统接口)

该模块提供文件分享能力，提供系统应用将公共目录文件统一资源标志符（Uniform Resource Identifier，URI）以读写权限授权给其他应用的接口，授权后应用可通过[@ohos.file.fs](js-apis-file-fs.md)的相关接口进行相关open、read、write等操作，实现文件分享。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.fileshare (文件分享)](js-apis-fileShare-sys.md)。

## 导入模块

```ts
import  { fileShare } from '@kit.CoreFileKit';
```

## fileShare.grantUriPermission

grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags, callback: AsyncCallback&lt;void&gt;): void

对公共目录文件URI进行授权操作，使用callback异步回调。

**需要权限**：ohos.permission.WRITE_MEDIA

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型| 必填 | 说明|
| ------ |---------| ---- |-----------|
| uri   | string| 是   | 公共目录文件uri |
| bundleName   | string| 是   | 分享目标的包名   |
| flag   | [wantConstant.Flags](../apis-ability-kit/js-apis-app-ability-wantConstant.md#flags) | 是   | 授权的权限     |
| callback | AsyncCallback&lt;void&gt;| 是    | 异步授权之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)

| 错误码ID| 错误信息|
| ------ | ------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types |
| 143000001 | IPC error |

**示例：**

  ```ts
  import { wantConstant } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  let uri: string = 'file://docs/storage/Users/currentUser/Document/1.txt';  // 推荐使用系统接口生成URI。fileUri.getUriFromPath("沙箱路径");
  let bundleName: string = 'com.demo.test';
  try {
    fileShare.grantUriPermission(uri, bundleName, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION |
      wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION, (err: BusinessError) => {
      if (err) {
        console.error("grantUriPermission failed with error: " + JSON.stringify(err));
        return;
      }
      console.info("grantUriPermission success!");
    });
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("grantUriPermission failed with error:" + JSON.stringify(error));
  }
  ```

## fileShare.grantUriPermission

grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags): Promise&lt;void&gt;

将公共目录文件URI进行授权操作，使用Promise异步回调。

**需要权限**：ohos.permission.WRITE_MEDIA

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型| 必填 | 说明        |
| ------ |-------| ---- |-----------|
| uri   | string| 是   | 公共目录文件uri |
| bundleName   | string| 是   | 分享目标的包名   |
| flag   | [wantConstant.Flags](../apis-ability-kit/js-apis-app-ability-wantConstant.md#flags) | 是   | 授权的权限     |

**返回值：**

| 类型                           | 说明         |
  | ---------- | ---------- |
| Promise&lt;void&gt; | Promise对象，无返回值 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID| 错误信息|
| ------- | ---------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types |
| 143000001 | IPC error |

**示例：**

  ```ts
  import { wantConstant } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  let uri: string = 'file://docs/storage/Users/currentUser/Document/1.txt'; // 推荐使用系统接口生成URI。fileUri.getUriFromPath("沙箱路径");
  let bundleName: string = 'com.demo.test';
  try {
    fileShare.grantUriPermission(uri, bundleName, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION |
      wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION).then(() => {
      console.info("grantUriPermission success!");
    }).catch((error: BusinessError) => {
      console.error("grantUriPermission failed with error:" + JSON.stringify(error));
    });
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("grantUriPermission failed with error:" + JSON.stringify(error));
  }
  ```
