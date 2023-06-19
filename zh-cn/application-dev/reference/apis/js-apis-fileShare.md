# @ohos.fileshare (文件分享)

该模块提供文件分享能力，提供系统应用将公共目录文件统一资源标志符（Uniform Resource Identifier，URI）以读写权限授权给其他应用的接口，授权后应用可通过[@ohos.file.fs](js-apis-file-fs.md)的相关接口进行相关open、read、write等操作，实现文件分享。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import fileShare from '@ohos.fileshare';
```

## fileShare.grantUriPermission

grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags, callback: AsyncCallback&lt;void&gt;): void

对公共目录文件URI进行授权操作，使用callback异步回调。  

**需要权限**：ohos.permission.WRITE_MEDIA  

**系统接口**：此接口为系统接口  

**系统能力**：SystemCapability.FileManagement.AppFileService

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | 是   | 公共目录文件URI |
| bundleName   | string | 是   | 分享目标的包名 |
| flag   | wantConstant.Flags | 是   | 授权的权限，参考[wantConstant.Flags](js-apis-app-ability-wantConstant.md#wantconstantflags)<br/>wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION：读授权<br/>wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION：写授权|
 | callback | AsyncCallback&lt;void&gt;  | 是    | 异步授权之后的回调                             |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid |
| 143000001 | IPC error |

**示例：**

  ```js
import wantConstant from '@ohos.app.ability.wantConstant';


let uri = 'datashare:///media/image/8';
let bundleName = 'com.demo.test';
try {
    fileShare.grantUriPermission(uri, bundleName, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION | wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION, (err) => {
        if (err) {
            console.error("grantUriPermission failed with error: " + err);
            return;
        }
        console.info("grantUriPermission success!");
    });
} catch (error) {
    console.error("grantUriPermission failed with error:" + error);
}
  ```

## fileShare.grantUriPermission

grantUriPermission(uri: string, bundleName: string, flag: wantConstant.Flags): Promise&lt;void&gt;

将公共目录文件URI进行授权操作，使用Promise异步回调。  

**需要权限**：ohos.permission.WRITE_MEDIA  

**系统接口**：此接口为系统接口  

**系统能力**：SystemCapability.FileManagement.AppFileService  

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------- |
| uri   | string | 是   | 公共目录文件URI |
| bundleName   | string | 是   | 分享目标的包名 |
| flag   | wantConstant.Flags | 是   | 授权的权限，参考[wantConstant.Flags](js-apis-app-ability-wantConstant.md#wantconstantflags)<br/>wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION：读授权<br/>wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION：写授权|

**返回值：**

  | 类型                           | 说明         |
  | ---------------------------- | ---------- |
  | Promise&lt;void&gt; | Promise对象，无返回值 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed |
| 202 | The caller is not a system application |
| 401 | The input parameter is invalid |
| 143000001 | IPC error |

**示例：**

  ```js
import wantConstant from '@ohos.app.ability.wantConstant';

let uri = 'datashare:///media/image/8';
let bundleName = 'com.demo.test';
try {
    fileShare.grantUriPermission(uri, bundleName, wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION |
      wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION).then(function () {
        console.info("grantUriPermission success!");
    }).catch(function (error) {
        console.error("grantUriPermission failed with error:" + error);
    });
} catch (error) {
    console.error("grantUriPermission failed with error:" + error);
}
  ```
