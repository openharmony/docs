# @ohos.dlpPermission (数据防泄漏)(系统接口)
<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @winnieHuYu-->
<!--Designer: @lucky-jinduo-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

数据防泄漏（DLP）是系统提供的系统级的数据防泄漏解决方案，提供跨设备的文件的权限管理、加密存储、授权访问等能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.dlpPermission (数据防泄漏)](js-apis-dlppermission.md)。

## 导入模块

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
```

## dlpPermission.getDLPGatheringPolicy

getDLPGatheringPolicy(): Promise&lt;GatheringPolicyType&gt;

查询DLP沙箱聚合策略。使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[GatheringPolicyType](#gatheringpolicytype)&gt; | Promise对象。返回当前DLP沙箱聚合策略。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  try {
    let res: dlpPermission.GatheringPolicyType = await dlpPermission.getDLPGatheringPolicy(); // 获取沙箱聚合策略。
    console.info('res', JSON.stringify(res));
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  }
}
```

## dlpPermission.getDLPGatheringPolicy

getDLPGatheringPolicy(callback: AsyncCallback&lt;GatheringPolicyType&gt;): void

查询DLP沙箱聚合策略。使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[GatheringPolicyType](#gatheringpolicytype)&gt; | 是 | 回调函数。err为undefined时表示查询成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.getDLPGatheringPolicy((err, res) => {
    if (err !== undefined) {
      console.error('getDLPGatheringPolicy error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 获取沙箱聚合策略。
} catch (err) {
  console.error('getDLPGatheringPolicy error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.installDLPSandbox

installDLPSandbox(bundleName: string, access: DLPFileAccess, userId: number, uri: string): Promise&lt;DLPSandboxInfo&gt;

安装一个应用的DLP沙箱。使用Promise方式异步返回结果返回应用沙箱信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用包名。最小7字节，最大128字节。 |
| access | [DLPFileAccess](js-apis-dlppermission.md#dlpfileaccess) | 是 | DLP文件授权类型。 |
| userId | number | 是 | 当前的用户ID，通过账号子系统获取的OS账号ID，默认主用户ID：100。 |
| uri | string | 是 | DLP文件的URI。不超过4095字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[DLPSandboxInfo](#dlpsandboxinfo)&gt; | Promise对象。安装沙箱应用，返回应用沙箱信息。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  try {
    let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
    let res: dlpPermission.DLPSandboxInfo =
      await dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100,
        uri); // 安装DLP沙箱。
    console.info('res', JSON.stringify(res));
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  }
}
```

## dlpPermission.installDLPSandbox

installDLPSandbox(bundleName: string, access: DLPFileAccess, userId: number, uri:string, callback: AsyncCallback&lt;DLPSandboxInfo&gt;): void

安装一个应用的DLP沙箱。使用callback方式异步返回应用沙箱信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用包名。最小7字节，最大128字节。 |
| access | [DLPFileAccess](js-apis-dlppermission.md#dlpfileaccess) | 是 | DLP文件授权类型。 |
| userId | number | 是 | 当前的用户ID，通过账号子系统获取的系账号ID，默认主用户ID：100。 |
| uri | string | 是 | DLP文件的URI。不超过4095字节。 |
| callback | AsyncCallback&lt;[DLPSandboxInfo](#dlpsandboxinfo)&gt; | 是 | 获取应用沙箱信息的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
try {
  dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri, (err, res) => {
    if (err !== undefined) {
      console.error('installDLPSandbox error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 安装DLP沙箱。
} catch (err) {
  console.error('installDLPSandbox error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.uninstallDLPSandbox

uninstallDLPSandbox(bundleName: string, userId: number, appIndex: number): Promise&lt;void&gt;

卸载一个应用的DLP沙箱。使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用包名。最小7字节，最大128字节。 |
| userId | number | 是 | 当前的用户ID，通过账号子系统获取的系统账号ID，默认主用户ID：100。 |
| appIndex | number | 是 | DLP沙箱号。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  try {
    let res = await dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri);
    console.info('res', JSON.stringify(res));
    await dlpPermission.uninstallDLPSandbox('com.ohos.note', 100, res.appIndex); // 卸载DLP沙箱。
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  }
}
```

## dlpPermission.uninstallDLPSandbox

uninstallDLPSandbox(bundleName: string, userId: number, appIndex: number, callback: AsyncCallback&lt;void&gt;): void

卸载一个应用的DLP沙箱。使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用包名。最小7字节，最大128字节。 |
| userId | number | 是 | 当前的用户ID，通过账号子系统获取的系统账号ID，默认主用户ID：100。 |
| appIndex | number | 是 | DLP沙箱号，即installDLPSandbox接口调用成功后的返回值。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取卸载结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  try {
    let res = await dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100,
      uri) // 安装DLP沙箱。
    console.info('res', JSON.stringify(res));
    dlpPermission.uninstallDLPSandbox('com.ohos.note', 100, res.appIndex, (err, res) => {
      if (err !== undefined) {
        console.error('uninstallDLPSandbox error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  } catch (err) {
    console.error('uninstallDLPSandbox error,', (err as BusinessError).code, (err as BusinessError).message);
  }
}
```

## dlpPermission.on('uninstallDLPSandbox')

on(type: 'uninstallDLPSandbox', listener: Callback&lt;DLPSandboxState&gt;): void

注册监听DLP沙箱卸载事件。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | 'uninstallDLPSandbox' | 是 | 监听事件类型。固定值为'uninstallDLPSandbox'：DLP沙箱卸载事件。 |
| listener | Callback&lt;[DLPSandboxState](#dlpsandboxstate)&gt; | 是 | 沙箱应用卸载事件的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.on('uninstallDLPSandbox', (info: dlpPermission.DLPSandboxState) => {
    console.info('uninstallDLPSandbox event', info.appIndex, info.bundleName)
  }); // 订阅。
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
```

## dlpPermission.off('uninstallDLPSandbox')

off(type: 'uninstallDLPSandbox', listener?: Callback&lt;DLPSandboxState&gt;): void

取消监听DLP沙箱卸载事件。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | 'uninstallDLPSandbox' | 是 | 监听事件类型。固定值为'uninstallDLPSandbox'：DLP沙箱卸载事件。 |
| listener | Callback&lt;[DLPSandboxState](#dlpsandboxstate)&gt; | 否 | 沙箱应用卸载事件的回调。默认为空，表示取消该类型事件的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.off('uninstallDLPSandbox', (info: dlpPermission.DLPSandboxState) => {
    console.info('uninstallDLPSandbox event', info.appIndex, info.bundleName)
  }); // 取消订阅。
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
}
```

## DLPFile

管理DLPFile的实例，表示一个DLP文件对象，需要通过[generateDLPFile](#dlppermissiongeneratedlpfile)/[openDLPFile](#dlppermissionopendlpfile11)获取DLPFile的示例。

### 属性

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| dlpProperty | [DLPProperty](js-apis-dlppermission.md#dlpproperty21) | 否 | 否 | 表示DLP文件授权相关信息。 |

### addDLPLinkFile

addDLPLinkFile(linkFileName: string): Promise&lt;void&gt;

在FUSE文件系统(Filesystem in Userspace)添加link文件(FUSE文件系统中映射到密文的虚拟文件，对该文件的读写操作会同步到DLP文件)。使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。不超过255字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
    return;
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  } finally {
    dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

### addDLPLinkFile

addDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

在FUSE中添加link文件，使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。不超过255字节。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取添加结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    dlpFile.addDLPLinkFile('test.txt.dlp.link', async (err, res) => {
      if (err !== undefined) {
        console.error('addDLPLinkFile error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
      await dlpFile?.closeDLPFile(); // 关闭DLP对象。
      fileIo.closeSync(file);
    });
  } catch (err) {
    console.error('addDLPLinkFile error,', (err as BusinessError).code, (err as BusinessError).message);
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

### stopFuseLink

stopFuseLink(): Promise&lt;void&gt;

停止FUSE关联读写。使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId) // 打开DLP文件。
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
    dlpFile.stopFuseLink(); // 暂停link读写。
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  } finally {
    dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

### stopFuseLink

stopFuseLink(callback: AsyncCallback&lt;void&gt;): void

停止FUSE关联读写，使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取停止结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
    dlpFile.stopFuseLink(async (err, res) => {
      if (err !== undefined) {
        console.error('stopFuseLink error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
      await dlpFile?.closeDLPFile(); // 关闭DLP对象。
      fileIo.closeSync(file);
    });
  } catch (err) {
    console.error('stopFuseLink error,', (err as BusinessError).code, (err as BusinessError).message);
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

### resumeFuseLink

resumeFuseLink(): Promise&lt;void&gt;

恢复FUSE关联读写。使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
    await dlpFile.stopFuseLink(); // 暂停link读写。
    await dlpFile.resumeFuseLink(); // 恢复link读写。
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  } finally {
    dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

### resumeFuseLink

resumeFuseLink(callback: AsyncCallback&lt;void&gt;): void

恢复FUSE关联读写，使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取恢复结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
    await dlpFile.stopFuseLink(); // 暂停link读写。
    dlpFile.resumeFuseLink(async (err, res) => {
      if (err !== undefined) {
        console.error('resumeFuseLink error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
      await dlpFile?.closeDLPFile(); // 关闭DLP对象。
      fileIo.closeSync(file);
    });
  } catch (err) {
    console.error('resumeFuseLink error,', (err as BusinessError).code, (err as BusinessError).message);
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

### replaceDLPLinkFile

replaceDLPLinkFile(linkFileName: string): Promise&lt;void&gt;

替换link文件。使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。不超过255字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
    await dlpFile.stopFuseLink(); // 暂停link读写。
    await dlpFile.replaceDLPLinkFile('test_new.txt.dlp.link'); // 替换link文件。
    await dlpFile.resumeFuseLink(); // 恢复link读写。
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  } finally {
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

### replaceDLPLinkFile

replaceDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

替换link文件，使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。不超过255字节。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取替换结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
    await dlpFile.stopFuseLink(); // 暂停link读写。
    dlpFile.replaceDLPLinkFile('test_new.txt.dlp.link', async (err, res) => { // 替换link文件。
      if (err !== undefined) {
        console.error('replaceDLPLinkFile error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
        await dlpFile?.resumeFuseLink(); // 恢复link读写。
      }
      await dlpFile?.closeDLPFile(); // 关闭DLP对象。
      fileIo.closeSync(file);
    });
  } catch (err) {
    console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

### deleteDLPLinkFile

deleteDLPLinkFile(linkFileName: string): Promise&lt;void&gt;

删除fuse文件系统中创建的link文件。使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。不超过255字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
    await dlpFile.deleteDLPLinkFile('test.txt.dlp.link'); // 删除link文件。
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  } finally {
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

### deleteDLPLinkFile

deleteDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

删除link文件，使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。不超过255字节。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取删除结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
    dlpFile.deleteDLPLinkFile('test.txt.dlp.link', async (err, res) => { // 删除link文件。
      if (err !== undefined) {
        console.error('deleteDLPLinkFile error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
      await dlpFile?.closeDLPFile(); // 关闭DLP对象。
      fileIo.closeSync(file);
    });
  } catch (err) {
    console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

### recoverDLPFile

recoverDLPFile(plaintextFd: number): Promise&lt;void&gt;

移除DLP文件的权限控制，恢复成明文文件。使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | 是 | 目标明文文件的fd。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential task error. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Credential authentication server error. |
| 19100008 | The file is not a DLP file. |
| 19100009 | Failed to operate the DLP file. |
| 19100010 | The DLP file is read only. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let destFile: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    destFile = fileIo.openSync('destUri').fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    await dlpFile.recoverDLPFile(destFile); // 还原DLP文件。
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  } finally {
    dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
    if (destFile) {
      fileIo.closeSync(destFile);
    }
  }
}
```

### recoverDLPFile

recoverDLPFile(plaintextFd: number, callback: AsyncCallback&lt;void&gt;): void

移除DLP文件的权限控制，恢复成明文文件，使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | 是 | 目标明文文件的fd。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取恢复结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential task error. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Credential authentication server error. |
| 19100008 | The file is not a DLP file. |
| 19100009 | Failed to operate the DLP file. |
| 19100010 | The DLP file is read only. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let destFile: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    destFile = fileIo.openSync('destUri').fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    dlpFile.recoverDLPFile(destFile, async (err, res) => { // 还原DLP文件。
      if (err !== undefined) {
        console.error('recoverDLPFile error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
      await dlpFile?.closeDLPFile(); // 关闭DLP对象。
      fileIo.closeSync(file);
      fileIo.closeSync(destFile);
    });
  } catch (err) {
    console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
    if (destFile) {
      fileIo.closeSync(destFile);
    }
  }
}
```

### closeDLPFile

closeDLPFile(): Promise&lt;void&gt;

关闭DLPFile，释放对象。使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

> **说明：**
>
> dlpFile不再使用，应该关闭释放内存，且对象不应继续使用。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  } finally {
    dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

### closeDLPFile

closeDLPFile(callback: AsyncCallback&lt;void&gt;): void

关闭DLPFile，释放对象，使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

> **说明：**
>
> dlpFile不再使用，应该关闭释放内存，且对象不应继续使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取关闭结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
    dlpFile.closeDLPFile((err, res) => { // 关闭DLP文件。
      if (err !== undefined) {
        console.error('closeDLPFile error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
      fileIo.closeSync(file);
    });
  } catch (err) {
    console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

## dlpPermission.generateDLPFile

generateDLPFile(plaintextFd: number, ciphertextFd: number, property: DLPProperty): Promise&lt;DLPFile&gt;

将明文文件加密生成权限受控文件，仅在授权列表内的用户可以打开，授权又分为完全控制权限和只读权限。获取DLPFile管理对象，使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | 是 | 待加密明文文件的fd。 |
| ciphertextFd | number | 是 | 目标加密文件的fd。 |
| property | [DLPProperty](js-apis-dlppermission.md#dlpproperty21) | 是 | 授权用户信息：授权用户列表、owner账号、联系人账号。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[DLPFile](#dlpfile)&gt; | Promise对象。返回对象表示成功生成DLP文件，返回null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential service busy due to too many tasks or duplicate tasks. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Credential authentication server error. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let dlpUri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt';
  let file: number | undefined = undefined;
  let dlp: number | undefined = undefined;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    file = fileIo.openSync(uri).fd;
    dlp = fileIo.openSync(dlpUri).fd;
    let dlpProperty: dlpPermission.DLPProperty = {
      ownerAccount: 'zhangsan',
      ownerAccountType: dlpPermission.AccountType.DOMAIN_ACCOUNT,
      authUserList: [],
      contactAccount: 'zhangsan',
      offlineAccess: true,
      ownerAccountID: 'xxxxxxx',
      everyoneAccessList: []
    };
    dlpFile = await dlpPermission.generateDLPFile(file, dlp, dlpProperty); // 生成DLP文件。
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  } finally {
    dlpFile?.closeDLPFile(); // 关闭DLP对象。
    if (file) {
      fileIo.closeSync(file);
    }
    if (dlp) {
      fileIo.closeSync(dlp);
    }
  }
}
```

## dlpPermission.generateDLPFile

generateDLPFile(plaintextFd: number, ciphertextFd: number, property: DLPProperty, callback: AsyncCallback&lt;DLPFile&gt;): void

DLP管理应用调用该接口，将明文文件加密生成权限受控文件，仅在授权列表内的用户可以打开，授权又分为完全控制权限和只读权限。获取DLPFile管理对象，使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | 是 | 待加密明文文件的fd。 |
| ciphertextFd | number | 是 | 目标加密文件的fd。 |
| property | [DLPProperty](js-apis-dlppermission.md#dlpproperty21) | 是 | 授权用户信息：授权用户列表、owner账号、联系人账号。 |
| callback | AsyncCallback&lt;[DLPFile](#dlpfile)&gt; | 是 | 回调函数。返回DLPFile对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential service busy due to too many tasks or duplicate tasks. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Credential authentication server error. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dlpUri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt';
let file: number | undefined = undefined;
let dlp: number | undefined = undefined;

try {
  file = fileIo.openSync(uri).fd;
  dlp = fileIo.openSync(dlpUri).fd;
  let dlpProperty: dlpPermission.DLPProperty = {
    ownerAccount: 'zhangsan',
    ownerAccountType: dlpPermission.AccountType.DOMAIN_ACCOUNT,
    authUserList: [],
    contactAccount: 'zhangsan',
    offlineAccess: true,
    ownerAccountID: 'xxxxxxx',
    everyoneAccessList: []
  };
  dlpPermission.generateDLPFile(file, dlp, dlpProperty, (err, res) => { // 生成DLP文件。
    if (err !== undefined) {
      console.error('generateDLPFile error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
    fileIo.closeSync(file);
    fileIo.closeSync(dlp);
  });
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
  if (file) {
    fileIo.closeSync(file);
  }
  if (dlp) {
    fileIo.closeSync(dlp);
  }
}
```

## dlpPermission.openDLPFile<sup>11+</sup>

openDLPFile(ciphertextFd: number, appId: string): Promise&lt;DLPFile&gt;

打开DLP文件。获取DLPFile管理对象，使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| ciphertextFd | number | 是 | 加密文件的fd。 |
| appId | string | 是 | 调用方身份。最小8字节，最大1024字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[DLPFile](#dlpfile)&gt; | Promise对象。返回对象表示打开生成DLP文件，返回null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential service busy due to too many tasks or duplicate tasks. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Credential authentication server error. |
| 19100008 | The file is not a DLP file. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |
| 19100018 | The application is not authorized. |
| 19100019 | The DLP file has expired. |
| 19100020 | No network connection. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    appId = data.signatureInfo.appId;
  } catch (err) {
    console.error('error', err.code, err.message);
  }

  try {
    file = fileIo.openSync(uri).fd;
    dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
    dlpFile?.closeDLPFile(); // 关闭DLP对象。
  } finally {
    if (file) {
      fileIo.closeSync(file);
    }
  }
}
```

## dlpPermission.openDLPFile<sup>11+</sup>

openDLPFile(ciphertextFd: number, appId: string, callback: AsyncCallback&lt;DLPFile&gt;): void

DLP管理应用调用该接口，打开DLP文件。获取DLPFile管理对象，使用callback方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| ciphertextFd | number | 是 | 加密文件的fd。 |
| appId | string | 是 | 调用方身份。最小8字节，最大1024字节。 |
| callback | AsyncCallback&lt;[DLPFile](#dlpfile)&gt; | 是 | 回调函数。返回DLPFile对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential service busy due to too many tasks or duplicate tasks. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Credential authentication server error. |
| 19100008 | The file is not a DLP file. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |
| 19100018 | The application is not authorized. |
| 19100019 | The DLP file has expired. |
| 19100020 | No network connection. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
let file: number | undefined = undefined;
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = '';
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  file = fileIo.openSync(uri).fd;
  dlpPermission.openDLPFile(file, appId, (err, res) => { // 打开DLP文件。
    if (err !== undefined) {
      console.error('openDLPFile error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
    if (file) {
      fileIo.closeSync(file);
    }
  });
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
  if (file) {
    fileIo.closeSync(file);
  }
}
```

## DLPSandboxInfo

表示DLP沙箱的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| appIndex | number | 否 | 否 | 表示DLP沙箱应用索引。 |
| tokenID | number | 否 | 否 | 表示DLP沙箱应用的tokenID。 |

## DLPSandboxState

DLP沙箱身份。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| bundleName | string | 否 | 否 | 表示应用包名。最小7字节，最大128字节。 |
| appIndex | number | 否 | 否 | 表示DLP沙箱应用索引。 |

## GatheringPolicyType

DLP沙箱聚合策略类型的枚举。沙箱聚合表示同一权限类型的DLP文件，在同一个沙箱内打开，例如在同一个沙箱内使用不同tab页打开；沙箱非聚合表示不同DLP文件在不同沙箱打开。

**系统能力：** SystemCapability.Security.DataLossPrevention

**系统接口：** 此接口为系统接口。

**参数：**

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| GATHERING | 1 | 表示沙箱聚合。 |
| NON_GATHERING | 2 | 表示沙箱非聚合。 |