# \@ohos.dlpPermission (数据防泄漏)

数据防泄漏（DLP）是OpenHarmony提供的系统级的数据防泄漏解决方案，提供跨设备的文件的权限管理、加密存储、授权访问等能力。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import dlpPermission from '@ohos.dlpPermission';
```

## dlpPermission.isDLPFile

isDLPFile(fd: number): Promise&lt;boolean&gt;

根据文件的fd，查询该文件是否是DLP文件，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fd | number | 是 | 文件的fd(file descriptor, 文件描述符)。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示是DLP文件，返回false表示非DLP文件。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  let res = dlpPermission.isDLPFile(file.fd); // 是否加密DLP文件
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
fs.closeSync(file);
```

## dlpPermission.isDLPFile

isDLPFile(fd: number, callback: AsyncCallback&lt;boolean&gt;): void

根据文件的fd，查询该文件是否是DLP文件，使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fd | number | 是 | 文件的fd。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。返回true表示是DLP文件，返回false表示非DLP文件。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.isDLPFile(file.fd, (err, res) => {
    if (err != undefined) {
      console.error('isDLPFile error,', err.code, err.message);
    } else {
      console.info('res', res);
    }
    fs.closeSync(file);
  });
} catch (err) {
  console.error('isDLPFile error,', (err as BusinessError).code, (err as BusinessError).message);
  fs.closeSync(file);
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100006 | This API can only be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let inSandbox = dlpPermission.isInSandbox(); // 是否在沙箱内
  if (inSandbox) {
    let res: Promise<dlpPermission.DLPPermissionInfo> = dlpPermission.getDLPPermissionInfo(); // 获取当前权限信息
    console.info('res', JSON.stringify(res));
  }
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100006 | This API can only be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

try {
  let inSandbox = dlpPermission.isInSandbox(); // 是否在沙箱内
  if (inSandbox) {
    dlpPermission.getDLPPermissionInfo((err, res) => {
      if (err != undefined) {
        console.error('getDLPPermissionInfo error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
    }); // 获取当前权限信息
  }
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
| fileName | string | 是 | 指定要查询的文件名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回DLP文件的原始文件名。例如：DLP文件名为test.txt.dlp，则返回的原始文件名为test.txt。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res = dlpPermission.getOriginalFileName('test.txt.dlp'); // 获取原始文件名
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
```

## dlpPermission.getDLPSuffix

getDLPSuffix(): string

获取DLP文件扩展名。接口为同步接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回DLP文件扩展名。例如：原文件"text.txt"，返回拓展名为".dlp"，加密后的DLP文件名为"test.txt.dlp"。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res = dlpPermission.getDLPSuffix(); // 获取DLP拓展名
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.on('openDLPFile', (info: dlpPermission.AccessedDLPFileInfo) => {
    console.info('openDlpFile event', info.uri, info.lastOpenTime)
  }); // 订阅
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.off('openDLPFile', (info: dlpPermission.AccessedDLPFileInfo) => {
    console.info('openDlpFile event', info.uri, info.lastOpenTime)
  }); // 取消订阅
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
```

## dlpPermission.isInSandbox

isInSandbox(): Promise&lt;boolean&gt;

查询当前应用是否运行在DLP沙箱环境。使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回当前应用是否运行在沙箱中。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let inSandbox = dlpPermission.isInSandbox(); // 是否在沙箱内
  console.info('res', inSandbox);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
```

## dlpPermission.isInSandbox

isInSandbox(callback: AsyncCallback&lt;boolean&gt;): void

查询当前应用是否运行在DLP沙箱环境。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.isInSandbox((err, data) => {
    if (err) {
      console.error('isInSandbox error,', err.code, err.message);
    } else {
      console.info('isInSandbox, data');
    }
  }); // 是否在沙箱内
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res = dlpPermission.getDLPSupportedFileTypes(); // 获取支持DLP的文件类型
  console.info('res', JSON.stringify(res));
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.getDLPSupportedFileTypes((err, res) => {
    if (err != undefined) {
      console.error('getDLPSupportedFileTypes error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 获取支持DLP的文件类型
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100006 | This API can only be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  let inSandbox = dlpPermission.isInSandbox(); // 是否在沙箱内
  if (inSandbox) {
    dlpPermission.setRetentionState([uri]); // 设置沙箱保留
  }
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
```

## dlpPermission.setRetentionState

setRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

打开DLP文件时自动安装沙箱，关闭DLP文件时自动卸载沙箱。设置沙箱保留状态时DLP文件关闭时自动卸载暂时失效。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | 是 | 表示需要设置保留状态的文件uri列表。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。err为undefine时表示设置成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100006 | This API can only be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.setRetentionState([uri], (err, res) => {
    if (err != undefined) {
      console.error('setRetentionState error,', err.code, err.message);
    } else {
      console.info('setRetentionState success');
    }
  }); // 设置沙箱保留
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
| docUris | Array&lt;string&gt; | 是 | 表示需要设置保留状态的文件uri列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.cancelRetentionState([uri]); // 取消沙箱保留
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
```

## dlpPermission.cancelRetentionState

cancelRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

取消沙箱保留状态即恢复DLP文件关闭时自动卸载沙箱策略。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | 是 | 表示需要设置保留状态的文件uri列表。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。err为undefine时表示设置成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.cancelRetentionState([uri], (err, res) => {
    if (err != undefined) {
      console.error('cancelRetentionState error,', err.code, err.message);
    } else {
      console.info('cancelRetentionState success');
    }
  }); // 取消沙箱保留
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
| bundleName | string | 否 | 指定应用包名。默认为空，查询当前应用的保留沙箱信息列表。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[RetentionSandboxInfo](#retentionsandboxinfo)&gt;&gt; | Promise对象。返回查询的沙箱信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res: Promise<Array<dlpPermission.RetentionSandboxInfo>> = dlpPermission.getRetentionSandboxList(); // 获取沙箱保留列表
  console.info('res', JSON.stringify(res))
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
```

## dlpPermission.getRetentionSandboxList

getRetentionSandboxList(bundleName: string, callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void

查询指定应用的保留沙箱信息列表。使用callback方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 指定应用包名。 |
| callback | AsyncCallback&lt;Array&lt;[RetentionSandboxInfo](#retentionsandboxinfo)&gt;&gt; | 是 | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.getRetentionSandboxList("bundleName", (err, res) => {
    if (err != undefined) {
      console.error('getRetentionSandboxList error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 获取沙箱保留列表
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.getRetentionSandboxList((err, res) => {
    if (err != undefined) {
      console.error('getRetentionSandboxList error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 获取沙箱保留列表
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res: Promise<Array<dlpPermission.AccessedDLPFileInfo>> = dlpPermission.getDLPFileAccessRecords(); // 获取DLP访问列表
  console.info('res', JSON.stringify(res))
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.getDLPFileAccessRecords((err, res) => {
    if (err != undefined) {
      console.error('getDLPFileAccessRecords error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 获取DLP访问列表
} catch (err) {
  console.error('getDLPFileAccessRecords error,', (err as BusinessError).code, (err as BusinessError).message);
}
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res: Promise<dlpPermission.GatheringPolicyType> = dlpPermission.getDLPGatheringPolicy(); // 获取沙箱聚合策略
  console.info('res', JSON.stringify(res));
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
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
| callback | AsyncCallback&lt;[GatheringPolicyType](#gatheringpolicytype)&gt; | 是 | 回调函数。err为undefine时表示查询成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.getDLPGatheringPolicy((err, res) => {
    if (err != undefined) {
      console.error('getDLPGatheringPolicy error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 获取沙箱聚合策略
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
| bundleName | string | 是 | 应用包名。 |
| access | [DLPFileAccess](#dlpfileaccess) | 是 | DLP文件授权类型。 |
| userId | number | 是 | 当前的用户ID，通过帐号子系统获取的OS帐号ID，默认主用户ID：100。 |
| uri | string | 是 | DLP文件的URI。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[DLPSandboxInfo](#dlpsandboxinfo)&gt; | Promise对象。安装沙箱应用，返回应用沙箱信息。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  let res: Promise<dlpPermission.DLPSandboxInfo> = dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri); // 安装DLP沙箱
  console.info('res', JSON.stringify(res));
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
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
| bundleName | string | 是 | 应用包名。 |
| access | [DLPFileAccess](#dlpfileaccess) | 是 | DLP文件授权类型。 |
| userId | number | 是 | 当前的用户ID，通过帐号子系统获取的系帐号ID，默认主用户ID：100。 |
| uri | string | 是 | DLP文件的URI。 |
| callback | AsyncCallback&lt;[DLPSandboxInfo](#dlpsandboxinfo)&gt; | 是 | 获取应用沙箱信息的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri, (err, res) => {
    if (err != undefined) {
      console.error('installDLPSandbox error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 安装DLP沙箱
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
| bundleName | string | 是 | 应用包名。 |
| userId | number | 是 | 当前的用户ID，通过帐号子系统获取的系统帐号ID，默认主用户ID：100 |
| appIndex | number | 是 | DLP沙箱号。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri).then((res)=>{
    console.info('res', JSON.stringify(res));
    dlpPermission.uninstallDLPSandbox('com.ohos.note', 100, res.appIndex); // 卸载DLP沙箱
  }); // 安装DLP沙箱
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
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
| bundleName | string | 是 | 应用包名。 |
| userId | number | 是 | 当前的用户ID，通过帐号子系统获取的系统帐号ID，默认主用户ID：100。 |
| appIndex | number | 是 | DLP沙箱号，即installDLPSandbox接口调用成功后的返回值。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取卸载结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri).then((res)=>{
    console.info('res', JSON.stringify(res));
    dlpPermission.uninstallDLPSandbox('com.ohos.note', 100, res.appIndex, (err, res) => {
      if (err != undefined) {
        console.error('uninstallDLPSandbox error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  }); // 安装DLP沙箱
} catch (err) {
  console.error('uninstallDLPSandbox error,', (err as BusinessError).code, (err as BusinessError).message);
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
| type | 'uninstallDLPSandbox' | 是 | 监听事件类型。固定值为'uninstallDLPSandbox':DLP沙箱卸载事件 |
| listener | Callback&lt;[DLPSandboxState](#dlpsandboxstate)&gt; | 是 | 沙箱应用卸载事件的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.on('uninstallDLPSandbox', (info: dlpPermission.DLPSandboxState) => {
    console.info('uninstallDLPSandbox event', info.appIndex, info.bundleName)
  }); // 订阅
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
| type | 'uninstallDLPSandbox' | 是 | 监听事件类型。固定值为'uninstallDLPSandbox':DLP沙箱卸载事件 |
| listener | Callback&lt;[DLPSandboxState](#dlpsandboxstate)&gt; | 否 | 沙箱应用卸载事件的回调。默认为空，表示取消该类型事件的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.off('uninstallDLPSandbox', (info: dlpPermission.DLPSandboxState) => {
    console.info('uninstallDLPSandbox event', info.appIndex, info.bundleName)
  }); // 取消订阅
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
```

## DLPFile

管理DLPFile的实例，表示一个DLP文件对象，需要通过[generateDLPFile](#dlppermissiongeneratedlpfile)/[openDLPFile](#dlppermissionopendlpfile)获取DLPFile的示例。

### 属性

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| dlpProperty | [DLPProperty](#dlpproperty) | 否 | 是 | 表示DLP文件授权相关信息。 |

### addDLPLinkFile

addDLPLinkFile(linkFileName: string): Promise&lt;void&gt;

在FUSE文件系统(Filesystem in Userspace)添加link文件(FUSE文件系统中映射到密文的虚拟文件，对该文件的读写操作会同步到DLP文件)。使用Promise方式异步返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件
    dlpFile.closeDLPFile(); //关闭DLP对象
  }); // 打开DLP文件
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
fs.closeSync(file);
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
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取添加结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link', async (err, res) => {
      if (err != undefined) {
        console.error('addDLPLinkFile error,', err.code, err.message);
        await dlpFile.closeDLPFile(); //关闭DLP对象
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  }); // 打开DLP文件
} catch (err) {
  console.error('addDLPLinkFile error,', (err as BusinessError).code, (err as BusinessError).message);
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件
    dlpFile.stopFuseLink(); // 暂停link读写
    dlpFile.closeDLPFile(); //关闭DLP对象
  }); // 打开DLP文件
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
fs.closeSync(file);
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件
    dlpFile.stopFuseLink(async (err, res) => {
      if (err != undefined) {
        console.error('stopFuseLink error,', err.code, err.message);
        await dlpFile.closeDLPFile(); //关闭DLP对象
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  }); // 打开DLP文件
} catch (err) {
  console.error('stopFuseLink error,', (err as BusinessError).code, (err as BusinessError).message);
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件
    dlpFile.stopFuseLink(); // 暂停link读写
    dlpFile.resumeFuseLink(); // 恢复link读写
    dlpFile.closeDLPFile(); //关闭DLP对象
  }); // 打开DLP文件
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
fs.closeSync(file);
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件
    dlpFile.stopFuseLink(); // 暂停link读写
    dlpFile.resumeFuseLink(async (err, res) => {
      if (err != undefined) {
        console.error('resumeFuseLink error,', err.code, err.message);
        await dlpFile.closeDLPFile(); //关闭DLP对象
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  }); // 打开DLP文件
} catch (err) {
  console.error('resumeFuseLink error,', (err as BusinessError).code, (err as BusinessError).message);
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
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件
    dlpFile.stopFuseLink(); // 暂停link读写
    dlpFile.replaceDLPLinkFile('test_new.txt.dlp.link'); // 替换link文件
    dlpFile.resumeFuseLink(); // 恢复link读写
    dlpFile.closeDLPFile(); //关闭DLP对象
  }); // 打开DLP文件
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
fs.closeSync(file);
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
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取替换结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件
    dlpFile.stopFuseLink(); // 暂停link读写
    dlpFile.replaceDLPLinkFile('test_new.txt.dlp.link', async (err, res) => { // 替换link文件
      if (err != undefined) {
        console.error('replaceDLPLinkFile error,', err.code, err.message);
        await dlpFile.closeDLPFile(); //关闭DLP对象
      } else {
        console.info('res', JSON.stringify(res));
        await dlpFile.resumeFuseLink(); // 恢复link读写
      }
    });
  }); // 打开DLP文件
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
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
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件
    dlpFile.deleteDLPLinkFile('test.txt.dlp.link'); // 删除link文件
    dlpFile.closeDLPFile(); //关闭DLP对象
  }); // 打开DLP文件
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
fs.closeSync(file);
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
| linkFileName | string | 是 | 用于fuse文件系统的link文件名。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 获取删除结果的回调。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件
    dlpFile.deleteDLPLinkFile('test.txt.dlp.link', async (err, res) => { // 删除link文件
      if (err != undefined) {
        console.error('deleteDLPLinkFile error,', err.code, err.message);
        await dlpFile.closeDLPFile(); //关闭DLP对象
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  }); // 打开DLP文件
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential task error. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Remote credential server error. |
| 19100008 | Not DLP file. |
| 19100009 | Failed to operate the DLP file. |
| 19100010 | DLP file is read-only. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let destFile = fs.openSync("destUri");
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.recoverDLPFile(destFile.fd); // 还原DLP文件
    dlpFile.closeDLPFile(); //关闭DLP对象
  }); // 打开DLP文件
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
fs.closeSync(file);
fs.closeSync(destFile);
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential task error. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Remote credential server error. |
| 19100008 | Not DLP file. |
| 19100009 | Failed to operate the DLP file. |
| 19100010 | DLP file is read-only. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let destFile = fs.openSync("destUri");
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.recoverDLPFile(destFile.fd, async (err, res) => { // 还原DLP文件
      if (err != undefined) {
        console.error('recoverDLPFile error,', err.code, err.message);
        await dlpFile.closeDLPFile(); //关闭DLP对象
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  }); // 打开DLP文件
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.closeDLPFile(); //关闭DLP对象
  }); // 打开DLP文件
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
fs.closeSync(file);
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.closeDLPFile((err, res) => { // 关闭DLP文件
      if (err != undefined) {
        console.error('closeDLPFile error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
      fs.closeSync(file);
    });
  }); // 打开DLP文件
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
  fs.closeSync(file);
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
| property | [DLPProperty](#dlpproperty) | 是 | 授权用户信息：授权用户列表、owner帐号、联系人帐号。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[DLPFile](#dlpfile)&gt; | Promise对象。返回对象表示成功生成DLP文件，返回null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential task error. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Remote credential server error. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let dlpUri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt";
let file = fs.openSync(uri);
let dlp = fs.openSync(dlpUri);
try {
  let dlpProperty: dlpPermission.DLPProperty = {
    ownerAccount: 'zhangsan',
    ownerAccountType: dlpPermission.AccountType.DOMAIN_ACCOUNT,
    authUserList: [],
    contactAccount: 'zhangsan',
    offlineAccess: true,
    ownerAccountID: 'xxxxxxx',
    everyoneAccessList: []
  };
  dlpPermission.generateDLPFile(file.fd, dlp.fd, dlpProperty).then((dlpFile)=>{
    dlpFile.closeDLPFile(); //关闭DLP对象
  }); // 生成DLP文件
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
fs.closeSync(file);
fs.closeSync(dlp);
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
| property | [DLPProperty](#dlpproperty) | 是 | 授权用户信息：授权用户列表、owner帐号、联系人帐号。 |
| callback | AsyncCallback&lt;[DLPFile](#dlpfile)&gt; | 是 | 回调函数。返回DLPFile对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential task error. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Remote credential server error. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let dlpUri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt";
let file = fs.openSync(uri);
let dlp = fs.openSync(dlpUri);
try {
  let dlpProperty: dlpPermission.DLPProperty = {
    ownerAccount: 'zhangsan',
    ownerAccountType: dlpPermission.AccountType.DOMAIN_ACCOUNT,
    authUserList: [],
    contactAccount: 'zhangsan',
    offlineAccess: true,
    ownerAccountID: 'xxxxxxx',
    everyoneAccessList: []
  };
  dlpPermission.generateDLPFile(file.fd, dlp.fd, dlpProperty, (err, res) => { // 生成DLP文件
    if (err != undefined) {
      console.error('generateDLPFile error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  });
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
  fs.closeSync(file);
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
| appId | string | 是 | 调用方身份。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[DLPFile](#dlpfile)&gt; | Promise对象。返回对象表示打开生成DLP文件，返回null表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential task error. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Remote credential server error. |
| 19100008 | Not DLP file. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |
| 19100018 | Not authorized application. |
| 19100019 | The DLP file has expired. |
| 19100020 | No network connection. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.sinagtureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.closeDLPFile(); //关闭DLP对象
  }); // 打开DLP文件
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
fs.closeSync(file);
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
| appId | string | 是 | 调用方身份。 |
| callback | AsyncCallback&lt;[DLPFile](#dlpfile)&gt; | 是 | 回调函数。返回DLPFile对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential task error. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Remote credential server error. |
| 19100008 | Not DLP file. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |
| 19100018 | Not authorized application. |
| 19100019 | The DLP file has expired. |
| 19100020 | No network connection. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.sinagtureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId, (err, res) => { // 打开DLP文件
    if (err != undefined) {
      console.error('openDLPFile error,', err.code, err.message);
    } else {
      console.info('res', JSON.stringify(res));
    }
  });
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
  fs.closeSync(file);
}
```

## dlpPermission.setSandboxAppConfig<sup>11+<sup>
setSandboxAppConfig(configInfo: string): Promise&lt;void&gt;

设置沙箱应用配置信息，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| configInfo | string | 是 | 沙箱应用配置信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |
| 19100018 | Not authorized application. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.setSandboxAppConfig('configInfo'); // 设置沙箱应用配置信息
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
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

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |
| 19100018 | Not authorized application. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.cleanSandboxAppConfig(); // 清理沙箱应用配置信息
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
```

## dlpPermission.getSandboxAppConfig<sup>11+<sup>
getSandboxAppConfig(): Promise&lt;string&gt;

获取沙箱应用配置信息，使用Promise方式异步返回结果

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise对象。返回沙箱应用配置信息。 |

**错误码：**

以下错误码的详细介绍请参见[DLP服务错误码](../errorcodes/errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |
| 19100018 | Not authorized application. |

**示例：**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.getSandboxAppConfig().then((res) => {
    console.info('res', JSON.stringify(res));
  }); // 获取沙箱应用配置信息
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // 失败报错
}
```

## ActionFlagType

可以对DLP文件进行的操作类型枚举。例如：DLP沙箱应用可以根据是否具有操作权限，对其按钮进行置灰

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
| dlpFileAccess | [DLPFileAccess](#dlpfileaccess) | 是 | 否 | 表示DLP文件针对用户的授权类型，例如：只读 |
| flags | number | 是 | 否 | 表示DLP文件的详细操作权限，是不同[ActionFlagType](#actionflagtype)的组合。 |

## AccessedDLPFileInfo

表示被打开的DLP文件的信息。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| uri | string | 是 | 否 | 表示DLP文件的uri。 |
| lastOpenTime | number | 是 | 否 | 表示DLP文件最近打开时间。 |

## DLPSandboxInfo

表示DLP沙箱的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| appIndex | number | 是 | 否 | 表示DLP沙箱应用索引。 |
| tokenID | number | 是 | 否 | 表示DLP沙箱应用的tokenID。 |

## DLPSandboxState

DLP沙箱身份。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 否 | 表示应用包名。 |
| appIndex | number | 是 | 否 | 表示DLP沙箱应用索引。 |

## RetentionSandboxInfo

保留沙箱的沙箱信息。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| appIndex | number | 是 | 否 | 表示DLP沙箱应用索引。 |
| bundleName | string | 是 | 否 | 表示应用包名。 |
| docUris | Array&lt;string&gt; | 是 | 否 | 表示DLP文件的URI列表。 |

## AccountType

授权帐号类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| CLOUD_ACCOUNT | 1 | 表示云帐号。 |
| DOMAIN_ACCOUNT | 2 | 表示域帐号。 |

## AuthUser

表示授权用户数据。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| authAccount | string | 否 | 是 | 表示被授权用户帐号。 |
| authAccountType | [AccountType](#accounttype) | 否 | 是 | 表示被授权用户帐号类型。 |
| dlpFileAccess | [DLPFileAccess](#dlpfileaccess) | 否 | 是 | 表示被授予的权限。 |
| permExpiryTime | number | 否 | 是 | 表示授权到期时间。 |

## DLPProperty

表示授权相关信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ownerAccount | string | 否 | 是 | 表示权限设置者帐号。 |
| ownerAccountID | string | 否 | 是 | 表示权限设置者帐号的ID。 |
| ownerAccountType | [AccountType](#accounttype) | 否 | 是 | 表示权限设置者帐号类型。 |
| authUserList | Array&lt;[AuthUser](#authuser)&gt; | 否 | 否 | 表示授权用户列表，默认为空。 |
| contactAccount | string | 否 | 是 | 表示联系人帐号。 |
| offlineAccess | boolean | 否 | 是 | 表示是否是离线打开。 |
| everyoneAccessList | Array&lt;[DLPFileAccess](#dlpfileaccess)&gt; | 否 | 否 | 表示授予所有人的权限，默认为空。 |
| expireTime<sup>11+</sup> | number | 否 | 否 | 表示文件权限到期时间戳，默认为空。 |

## GatheringPolicyType

DLP沙箱聚合策略类型的枚举。沙箱聚合表示同一权限类型的DLP文件，在同一个沙箱内打开，例如在同一个沙箱内使用不同tab页打开；沙箱非聚合表示不同DLP文件在不同沙箱打开。

**系统能力：** SystemCapability.Security.DataLossPrevention

**系统接口：** 此接口为系统接口。

**参数：**

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| GATHERING | 1 | 表示沙箱聚合。 |
| NON_GATHERING | 2 | 表示沙箱非聚合。 |
