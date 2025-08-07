# @ohos.dlpPermission (数据防泄漏)
<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @winnieHuYu-->
<!--SE: @lucky-jinduo-->
<!--TSE: @nacyli-->

数据防泄漏（DLP）是系统提供的系统级的数据防泄漏解决方案，提供跨设备的文件的权限管理、加密存储、授权访问等能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - @ohos.dlpPermission归属的Kit已由'DataLossPreventionKit'变更为'DataProtectionKit'，建议开发者使用新模块名'@kit.DataProtectionKit'完成模块导入。如果使用'@kit.DataLossPreventionKit'导入，仅能调用改名前的接口，无法使用新增接口。

## 导入模块

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
```

## dlpPermission.isDLPFile

isDLPFile(fd: number): Promise&lt;boolean&gt;

根据文件的fd，查询该文件是否是DLP文件。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fd | number | 是 | 待查询文件的fd（文件描述符）。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示是DLP文件，返回false表示非DLP文件。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file: number | undefined = undefined;
try {
  file = fileIo.openSync(uri).fd;
  let res = dlpPermission.isDLPFile(file); // 是否加密DLP文件。
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
} finally {
  if (file !== undefined) {
    fileIo.closeSync(file);
  }
}
```

## dlpPermission.isDLPFile

isDLPFile(fd: number, callback: AsyncCallback&lt;boolean&gt;): void

根据文件的fd，查询该文件是否是DLP文件。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fd | number | 是 | 待查询文件的fd（文件描述符）。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示是DLP文件，返回false表示非DLP文件。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file: number | undefined = undefined;
try {
  file = fileIo.openSync(uri).fd;
  dlpPermission.isDLPFile(file, (err, res) => {
    if (err != undefined) {
      console.error('isDLPFile error,', err.code, err.message);
    } else {
      console.info('res', res);
    }
    fileIo.closeSync(file);
  });
} catch (err) {
  console.error('isDLPFile error,', (err as BusinessError).code, (err as BusinessError).message);
  if (file !== undefined) {
    fileIo.closeSync(file);
  }
}
```

## dlpPermission.getDLPPermissionInfo

getDLPPermissionInfo(): Promise&lt;DLPPermissionInfo&gt;

查询当前DLP沙箱的权限信息。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[DLPPermissionInfo](#dlppermissioninfo)&gt; | Promise对象。返回查询的DLP文件的权限信息，无异常则表明查询成功。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100006 | No permission to call this API, which is available only for DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  try {
    dlpPermission.isInSandbox().then(async (inSandbox) => { // 是否在沙箱内。
      if (inSandbox) {
        let res: dlpPermission.DLPPermissionInfo = await dlpPermission.getDLPPermissionInfo(); // 获取当前权限信息。
        console.info('res', JSON.stringify(res));
      }
    });
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  }
}
```

## dlpPermission.getDLPPermissionInfo

getDLPPermissionInfo(callback: AsyncCallback&lt;DLPPermissionInfo&gt;): void

查询当前DLP沙箱的权限信息。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[DLPPermissionInfo](#dlppermissioninfo)&gt; | 是 | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100006 | No permission to call this API, which is available only for DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.isInSandbox().then((inSandbox) => { // 是否在沙箱内。
    if (inSandbox) {
      dlpPermission.getDLPPermissionInfo((err, res) => {
        if (err != undefined) {
          console.error('getDLPPermissionInfo error,', err.code, err.message);
        } else {
          console.info('res', JSON.stringify(res));
        }
      }); // 获取当前权限信息。
    }
  });
} catch (err) {
  console.error('getDLPPermissionInfo error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.getOriginalFileName

getOriginalFileName(fileName: string): string

获取指定DLP文件名的原始文件名。接口为同步接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fileName | string | 是 | 指定要查询的文件名。不超过255字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回DLP文件的原始文件名。例如：DLP文件名为test.txt.dlp，则返回的原始文件名为test.txt。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let res = dlpPermission.getOriginalFileName('test.txt.dlp'); // 获取原始文件名。
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
}
```

## dlpPermission.getDLPSuffix

getDLPSuffix(): string

获取DLP文件扩展名。接口为同步接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回DLP文件扩展名。例如：原文件"text.txt"，加密后的DLP文件名为"test.txt.dlp"，返回拓展名为".dlp"。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let res = dlpPermission.getDLPSuffix(); // 获取DLP拓展名。
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
}
```

## dlpPermission.on('openDLPFile')

on(type: 'openDLPFile', listener: Callback&lt;AccessedDLPFileInfo&gt;): void

监听打开DLP文件。在当前应用的沙箱应用打开DLP文件时，通知当前应用。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | 'openDLPFile' | 是 | 监听事件类型。固定值为'openDLPFile'：打开DLP文件事件。 |
| listener | Callback&lt;[AccessedDLPFileInfo](#accesseddlpfileinfo)&gt; | 是 | DLP文件打开事件的回调。在当前应用的沙箱应用打开DLP文件时，通知当前应用。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.on('openDLPFile', (info: dlpPermission.AccessedDLPFileInfo) => {
    console.info('openDlpFile event', info.uri, info.lastOpenTime)
  }); // 订阅。
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
}
```

## dlpPermission.off('openDLPFile')

off(type: 'openDLPFile', listener?: Callback&lt;AccessedDLPFileInfo&gt;): void

取消监听打开DLP文件。在当前应用的沙箱应用打开DLP文件时，取消通知当前应用。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | 'openDLPFile' | 是 | 监听事件类型。固定值为'openDLPFile'：打开DLP文件事件。 |
| listener | Callback&lt;[AccessedDLPFileInfo](#accesseddlpfileinfo)&gt; | 否 | DLP文件被打开的事件的回调。在当前应用的沙箱应用打开DLP文件时，取消通知当前应用。默认为空，表示取消该类型事件的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.off('openDLPFile', (info: dlpPermission.AccessedDLPFileInfo) => {
    console.info('openDlpFile event', info.uri, info.lastOpenTime)
  }); // 取消订阅。
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
}
```

## dlpPermission.isInSandbox

isInSandbox(): Promise&lt;boolean&gt;

查询当前应用是否运行在DLP沙箱环境。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前应用运行在沙箱中，返回false表示当前应用不是运行在沙箱中。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let inSandbox = dlpPermission.isInSandbox(); // 是否在沙箱内。
  console.info('res', inSandbox);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
}
```

## dlpPermission.isInSandbox

isInSandbox(callback: AsyncCallback&lt;boolean&gt;): void

查询当前应用是否运行在DLP沙箱环境。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。err为undefine时表示查询成功；否则为错误对象。返回true表示当前应用运行在沙箱中，返回false表示当前应用不是运行在沙箱中。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.isInSandbox((err, data) => {
    if (err) {
      console.error('isInSandbox error,', err.code, err.message);
    } else {
      console.info('isInSandbox, data', JSON.stringify(data));
    }
  }); // 是否在沙箱内。
} catch (err) {
  console.error('isInSandbox error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.getDLPSupportedFileTypes

getDLPSupportedFileTypes(): Promise&lt;Array&lt;string&gt;&gt;

查询当前可支持权限设置和校验的文件扩展名类型列表。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象。返回当前可支持权限设置和校验的文件扩展名类型列表。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let res = dlpPermission.getDLPSupportedFileTypes(); // 获取支持DLP的文件类型。
  console.info('res', JSON.stringify(res));
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
}
```

## dlpPermission.getDLPSupportedFileTypes

getDLPSupportedFileTypes(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

查询当前可支持权限设置和校验的文件扩展名类型列表。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | 是 | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.getDLPSupportedFileTypes((err, res) => {
    if (err != undefined) {
      console.error('getDLPSupportedFileTypes error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 获取支持DLP的文件类型。
} catch (err) {
  console.error('getDLPSupportedFileTypes error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.setRetentionState

setRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt;

打开DLP文件时自动安装沙箱，关闭DLP文件时自动卸载沙箱。设置沙箱保留状态时DLP文件关闭时自动卸载暂时失效。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | 是 | 表示需要设置保留状态的文件uri列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100006 | No permission to call this API, which is available only for DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
  try {
    let inSandbox = await dlpPermission.isInSandbox(); // 是否在沙箱内。
    if (inSandbox) {
      dlpPermission.setRetentionState([uri]); // 设置沙箱保留。
    }
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  }
}
```

## dlpPermission.setRetentionState

setRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

打开DLP文件时自动安装沙箱，关闭DLP文件时自动卸载沙箱。设置沙箱保留状态时DLP文件关闭时自动卸载暂时失效。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | 是 | 表示需要设置保留状态的文件uri列表。Array不限长度，每个string不超过4095字节。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。err为undefine时表示设置成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100006 | No permission to call this API, which is available only for DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.setRetentionState([uri], (err, res) => {
    if (err != undefined) {
      console.error('setRetentionState error,', err.code, err.message);
    } else {
      console.info('setRetentionState success');
      console.info('res', JSON.stringify(res));
    }
  }); // 设置沙箱保留。
} catch (err) {
  console.error('setRetentionState error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.cancelRetentionState

cancelRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt;

取消沙箱保留状态即恢复DLP文件关闭时自动卸载沙箱策略。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | 是 | 表示需要设置保留状态的文件uri列表。Array不限长度，每个string不超过4095字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.cancelRetentionState([uri]); // 取消沙箱保留。
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
}
```

## dlpPermission.cancelRetentionState

cancelRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

取消沙箱保留状态即恢复DLP文件关闭时自动卸载沙箱策略。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | 是 | 表示需要设置保留状态的文件uri列表。Array不限长度，每个string不超过4095字节。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。err为undefine时表示设置成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.cancelRetentionState([uri], (err, res) => {
    if (err != undefined) {
      console.error('cancelRetentionState error,', err.code, err.message);
    } else {
      console.info('cancelRetentionState success');
    }
  }); // 取消沙箱保留。
} catch (err) {
  console.error('cancelRetentionState error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.getRetentionSandboxList

getRetentionSandboxList(bundleName?: string): Promise&lt;Array&lt;RetentionSandboxInfo&gt;&gt;

查询指定应用的保留沙箱信息列表。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 否 | 指定应用包名。默认为空，查询当前应用的保留沙箱信息列表。最小7字节，最大128字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[RetentionSandboxInfo](#retentionsandboxinfo)&gt;&gt; | Promise对象。返回查询的沙箱信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  try {
    let res: Array<dlpPermission.RetentionSandboxInfo> = await dlpPermission.getRetentionSandboxList(); // 获取沙箱保留列表。
    console.info('res', JSON.stringify(res))
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  }
}
```

## dlpPermission.getRetentionSandboxList

getRetentionSandboxList(bundleName: string, callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void

查询指定应用的保留沙箱信息列表。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 指定应用包名。最小7字节，最大128字节。 |
| callback | AsyncCallback&lt;Array&lt;[RetentionSandboxInfo](#retentionsandboxinfo)&gt;&gt; | 是 | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.getRetentionSandboxList("bundleName", (err, res) => {
    if (err != undefined) {
      console.error('getRetentionSandboxList error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 获取沙箱保留列表。
} catch (err) {
  console.error('getRetentionSandboxList error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.getRetentionSandboxList

getRetentionSandboxList(callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void

查询指定应用的保留沙箱信息列表。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[RetentionSandboxInfo](#retentionsandboxinfo)&gt;&gt; | 是 | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.getRetentionSandboxList((err, res) => {
    if (err != undefined) {
      console.error('getRetentionSandboxList error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 获取沙箱保留列表。
} catch (err) {
  console.error('getRetentionSandboxList error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.getDLPFileAccessRecords

getDLPFileAccessRecords(): Promise&lt;Array&lt;AccessedDLPFileInfo&gt;&gt;

查询最近访问的DLP文件列表。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[AccessedDLPFileInfo](#accesseddlpfileinfo)&gt;&gt; | Promise对象。返回最近访问的DLP文件列表。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  try {
    let res: Array<dlpPermission.AccessedDLPFileInfo> = await dlpPermission.getDLPFileAccessRecords(); // 获取DLP访问列表。
    console.info('res', JSON.stringify(res))
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  }
}
```

## dlpPermission.getDLPFileAccessRecords

getDLPFileAccessRecords(callback: AsyncCallback&lt;Array&lt;AccessedDLPFileInfo&gt;&gt;): void

查询最近访问的DLP文件列表。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[AccessedDLPFileInfo](#accesseddlpfileinfo)&gt;&gt; | 是 | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.getDLPFileAccessRecords((err, res) => {
    if (err != undefined) {
      console.error('getDLPFileAccessRecords error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 获取DLP访问列表。
} catch (err) {
  console.error('getDLPFileAccessRecords error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.startDLPManagerForResult<sup>11+</sup>

startDLPManagerForResult(context: common.UIAbilityContext, want: Want): Promise&lt;DLPManagerResult&gt;

在当前UIAbility界面以无边框形式打开DLP权限管理应用。使用Promise方式异步返回结果。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| context | [common.UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是 | 当前窗口UIAbility上下文。 |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 请求对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[DLPManagerResult](#dlpmanagerresult11)&gt; | Promise对象。打开DLP权限管理应用并退出后的结果。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |
| 19100016 | The uri field is missing in the want parameter. |
| 19100017 | The displayName field is missing in the want parameter. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { common, Want } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

try {
  let context = new UIContext().getHostContext() as common.UIAbilityContext; // 获取当前UIAbilityContext。
  let want: Want = {
    "uri": "file://docs/storage/Users/currentUser/Desktop/1.txt",
    "parameters": {
      "displayName": "1.txt"
    }
  }; // 请求参数。
  dlpPermission.startDLPManagerForResult(context, want).then((res) => {
    console.info('res.resultCode', res.resultCode);
    console.info('res.want', JSON.stringify(res.want));
  }); // 打开DLP权限管理应用。
} catch (err) {
  console.error('error', err.code, err.message); // 失败报错。
}
```

## dlpPermission.setSandboxAppConfig<sup>11+<sup>
setSandboxAppConfig(configInfo: string): Promise&lt;void&gt;

设置沙箱应用配置信息，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| configInfo | string | 是 | 沙箱应用配置信息。长度小于4MB。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |
| 19100018 | The application is not authorized. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.setSandboxAppConfig('configInfo'); // 设置沙箱应用配置信息。
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
}
```

## dlpPermission.cleanSandboxAppConfig<sup>11+<sup>
cleanSandboxAppConfig(): Promise&lt;void&gt;

清理沙箱应用配置信息，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |
| 19100018 | The application is not authorized. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.cleanSandboxAppConfig(); // 清理沙箱应用配置信息。
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
}
```

## dlpPermission.getSandboxAppConfig<sup>11+<sup>
getSandboxAppConfig(): Promise&lt;string&gt;

获取沙箱应用配置信息，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise对象。返回沙箱应用配置信息。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |
| 19100018 | The application is not authorized. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function ExampleFunction() {
  try {
    let res = await dlpPermission.getSandboxAppConfig() // 获取沙箱应用配置信息。
    console.info('res', JSON.stringify(res));
  } catch (err) {
    console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
  }
}
```

## dlpPermission.isDLPFeatureProvided<sup>12+<sup>
isDLPFeatureProvided(): Promise&lt;boolean&gt;

查询当前系统是否提供DLP特性，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前系统提供DLP特性，返回false表示不提供DLP特性。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

dlpPermission.isDLPFeatureProvided().then((res) => {
  console.info('res', JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错。
});
```

## ActionFlagType

可以对DLP文件进行的操作类型枚举。例如：DLP沙箱应用可以根据是否具有操作权限，对其按钮进行置灰。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| ACTION_VIEW | 0x00000001 | 表示文件的查看权限。 |
| ACTION_SAVE | 0x00000002 | 表示文件的保存权限。 |
| ACTION_SAVE_AS | 0x00000004 | 表示文件的另存为权限。 |
| ACTION_EDIT | 0x00000008 | 表示文件的编辑权限。 |
| ACTION_SCREEN_CAPTURE | 0x00000010 | 表示文件的截屏权限。 |
| ACTION_SCREEN_SHARE | 0x00000020 | 表示文件的共享屏幕权限。 |
| ACTION_SCREEN_RECORD | 0x00000040 | 表示文件的录屏权限。 |
| ACTION_COPY | 0x00000080 | 表示文件的复制权限。 |
| ACTION_PRINT | 0x00000100 | 表示文件的打印权限。 |
| ACTION_EXPORT | 0x00000200 | 表示文件的导出权限。 |
| ACTION_PERMISSION_CHANGE | 0x00000400 | 表示文件的修改文件权限。 |

## DLPFileAccess

DLP文件授权类型的枚举。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| NO_PERMISSION | 0 | 表示无文件权限。 |
| READ_ONLY | 1 | 表示文件的只读权限。 |
| CONTENT_EDIT | 2 | 表示文件的编辑权限。 |
| FULL_CONTROL | 3 | 表示文件的完全控制权限。 |

## DLPPermissionInfo

表示DLP文件的权限信息。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| dlpFileAccess | [DLPFileAccess](#dlpfileaccess) | 是 | 否 | 表示DLP文件针对用户的授权类型，例如：只读。 |
| flags | number | 是 | 否 | 表示DLP文件的详细操作权限，是不同[ActionFlagType](#actionflagtype)的组合。 |

## AccessedDLPFileInfo

表示被打开的DLP文件的信息。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| uri | string | 是 | 否 | 表示DLP文件的uri。不超过4095字节。 |
| lastOpenTime | number | 是 | 否 | 表示DLP文件最近打开时间。 |

## DLPManagerResult<sup>11+</sup>

表示打开DLP权限管理应用的结果。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| resultCode | number | 是 | 否 | 表示打开DLP权限管理应用并退出后返回的结果码。 |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 否 | 表示打开DLP权限管理应用并退出后返回的数据。 |

## RetentionSandboxInfo

保留沙箱的沙箱信息。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| appIndex | number | 是 | 否 | 表示DLP沙箱应用索引。 |
| bundleName | string | 是 | 否 | 表示应用包名。最小7字节，最大128字节。 |
| docUris | Array&lt;string&gt; | 是 | 否 | 表示DLP文件的URI列表。Array不限长度，每个string不超过4095字节。 |

