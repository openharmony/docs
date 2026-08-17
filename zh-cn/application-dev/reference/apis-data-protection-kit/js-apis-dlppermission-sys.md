# @ohos.dlpPermission (数据防泄露)(系统接口)
<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @winnieHuYu-->
<!--Designer: @QRF-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

## 模型简介
数据防泄露（Data Loss Prevention，简称为DLP）是系统级的数据防泄露解决方案，提供跨设备文件的权限管理、加密存储、授权访问等能力。DLP通过加密技术对敏感文件进行保护，生成.dlp格式的加密文件（称为DLP文件）。当打开DLP文件时，系统会自动创建隔离的DLP沙箱环境，确保文件内容不会泄露到非授权环境。

典型应用场景：

- 企业安全管理应用获取DLP沙箱聚合策略配置。
- DLP文件管理应用安装/卸载沙箱环境。
- 企业文档管理系统生成受保护的DLP文件并设置访问权限。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.dlpPermission (数据防泄露)](js-apis-dlppermission.md)。

## 关键Class/Interface介绍

### 核心枚举类

- GatheringPolicyType：DLP沙箱聚合策略类型枚举，用于控制同权限类型DLP文件的沙箱打开方式。

### 核心接口类型

- DLPSandboxInfo：表示DLP沙箱信息，由installDLPSandbox()返回。
- DLPSandboxState：表示DLP沙箱状态信息，用于事件回调。

### 核心回调类型

- AsyncCallback\<DLPSandboxInfo>：沙箱安装的回调。
- AsyncCallback\<DLPFile>：文件操作的回调。
- AsyncCallback\<GatheringPolicyType>：沙箱聚合策略查询的回调。

### 核心类

- **DLPFile**：表示一个DLP文件对象。

![](figures/dlpPermission_main_class.png)

### API配对调用关系表

| 首次调用 | 配对调用 | 说明 |
| -------- | -------- | -------- |
| installDLPSandbox() | uninstallDLPSandbox() | 沙箱安装后必须卸载。 |
| on('uninstallDLPSandbox') | off('uninstallDLPSandbox') | 注册监听后应取消监听。 |
| generateDLPFile() | closeDLPFile() | 生成DLP文件后必须关闭。 |
| openDLPFile() | closeDLPFile() | 打开DLP文件后必须关闭。 |
| addDLPLinkFile() | deleteDLPLinkFile() | FUSE映射创建后应删除。 |
| stopFuseLink() | resumeFuseLink() | 停止读写后也可恢复。 |

## 导入模块

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
```

## dlpPermission.getDLPGatheringPolicy

getDLPGatheringPolicy(): Promise&lt;GatheringPolicyType&gt;

查询DLP沙箱聚合策略。使用Promise异步回调。

应用需要获取当前系统的DLP沙箱聚合策略配置时使用此接口。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[GatheringPolicyType](#gatheringpolicytype)&gt; | Promise对象。返回当前DLP沙箱聚合策略。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';

dlpPermission.getDLPGatheringPolicy().then((gatheringPolicy: dlpPermission.GatheringPolicyType) => {
  console.info('gatheringPolicy: ', JSON.stringify(gatheringPolicy));
}).catch((error: BusinessError) => {
  console.error(`Failed to get DLPGatheringPolicy. Code: ${error.code}, message: ${error.message}`);
}); // 获取沙箱聚合策略。
```

## dlpPermission.getDLPGatheringPolicy

getDLPGatheringPolicy(callback: AsyncCallback&lt;GatheringPolicyType&gt;): void

查询DLP沙箱聚合策略。使用callback异步回调。

应用需要获取当前系统的DLP沙箱聚合策略配置时使用此接口。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[GatheringPolicyType](#gatheringpolicytype)&gt; | 是 | 回调函数。err为undefined时表示查询成功；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

dlpPermission.getDLPGatheringPolicy((err, gatheringPolicy) => {
  if (err) {
    console.error(`Failed to get DLPGatheringPolicy. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('gatheringPolicy：', JSON.stringify(gatheringPolicy));
  }
}); // 获取沙箱聚合策略。
```

## dlpPermission.installDLPSandbox

installDLPSandbox(bundleName: string, access: DLPFileAccess, userId: number, uri: string): Promise&lt;DLPSandboxInfo&gt;

安装一个应用的DLP沙箱。DLP沙箱为受保护的DLP文件创建独立的运行环境，与原应用进程隔离，确保数据在授权范围内安全流转。沙箱应用继承原应用的功能但仅能访问授权的DLP文件。使用Promise异步回调。

调用installDLPSandbox成功后必须在使用完毕后调用[uninstallDLPSandbox](#dlppermissionuninstalldlpsandbox)卸载沙箱。

DLP文件管理应用打开受保护文件前，需要先为目标应用安装DLP沙箱。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用包名。最小7字节，最大128字节。超出范围时抛出错误码401。 |
| access | [DLPFileAccess](js-apis-dlppermission.md#dlpfileaccess) | 是 | DLP文件授权类型。设置不同的授权类型将决定用户对DLP文件的访问权限范围。 |
| userId | number | 是 | 当前的用户ID，通过账号子系统获取的系统账号ID，默认主用户ID：100。<br>取值范围为[0, 2<sup>31</sup>-1]，超出范围将被截断。当传入参数值小于0时，输出错误日志。 |
| uri | string | 是 |  DLP文件的URI。不超过4095字节。超出范围时抛出错误码401。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[DLPSandboxInfo](#dlpsandboxinfo)&gt; | Promise对象。安装沙箱应用，返回应用沙箱信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100,
  uri).then((dlpSandboxInfo: dlpPermission.DLPSandboxInfo) => {
  console.info('dlpSandboxInfo: ', JSON.stringify(dlpSandboxInfo));
}).catch((error: BusinessError)=> {
  console.error(error.message);
}); // 安装DLP沙箱。
```

## dlpPermission.installDLPSandbox

installDLPSandbox(bundleName: string, access: DLPFileAccess, userId: number, uri:string, callback: AsyncCallback&lt;DLPSandboxInfo&gt;): void

安装一个应用的DLP沙箱。使用callback异步回调。调用成功后，系统为应用创建DLP沙箱环境并返回沙箱信息。

调用installDLPSandbox成功后必须在使用完毕后调用[uninstallDLPSandbox](#dlppermissionuninstalldlpsandbox)卸载沙箱。

DLP文件管理应用打开受保护文件前，需要先为目标应用安装DLP沙箱。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用包名。最小7字节，最大128字节。超出范围时抛出错误码401。 |
| access | [DLPFileAccess](js-apis-dlppermission.md#dlpfileaccess) | 是 | DLP文件授权类型。设置不同的授权类型将决定用户对DLP文件的访问权限范围。 |
| userId | number | 是 | 当前的用户ID，通过账号子系统获取的系统账号ID，默认主用户ID：100。<br>取值范围为[0, 2<sup>31</sup>-1]，超出范围将被截断。当传入参数值小于0时，输出错误日志。 |
| uri | string | 是 | DLP文件的URI。不超过4095字节。超出范围时抛出错误码401。|
| callback | AsyncCallback&lt;[DLPSandboxInfo](#dlpsandboxinfo)&gt; | 是 | 回调函数。当安装DLP沙箱成功，err为undefined，data为获取到的沙箱信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri, (err, res) => {
  if (err) {
    console.error(`Failed to install DLPSandbox. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('res', JSON.stringify(res));
  }
}); // 安装DLP沙箱。
```

## dlpPermission.uninstallDLPSandbox

uninstallDLPSandbox(bundleName: string, userId: number, appIndex: number): Promise&lt;void&gt;

卸载一个应用的DLP沙箱。使用Promise异步回调。调用成功后，系统销毁指定的DLP沙箱环境并释放相关资源。

需要清理对应的沙箱环境时使用此接口。

必须在调用[installDLPSandbox](#dlppermissioninstalldlpsandbox)安装沙箱后才能调用此方法卸载。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用包名。最小7字节，最大128字节。超出范围时抛出错误码401。 |
| userId | number | 是 | 当前的用户ID，通过账号子系统获取的系统账号ID，默认主用户ID：100。<br>取值范围为[0, 2<sup>31</sup>-1]，超出范围将被截断。当传入参数值小于0时，输出错误日志。 |
| appIndex | number | 是 | DLP沙箱号，即installDLPSandbox接口调用成功后的返回值，用于标识已安装的DLP沙箱。取值范围为[1000, 1100]，超出范围时输出错误日志。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100,
  uri).then(async (dlpSandboxInfo: dlpPermission.DLPSandboxInfo) => {
  console.info('dlpSandboxInfo：', JSON.stringify(dlpSandboxInfo));
  await dlpPermission.uninstallDLPSandbox('com.ohos.note', 100, dlpSandboxInfo.appIndex); // 卸载DLP沙箱。
}).catch((error: BusinessError)=> {
  console.error(error.message);
}); // 安装后卸载DLP沙箱。
```

## dlpPermission.uninstallDLPSandbox

uninstallDLPSandbox(bundleName: string, userId: number, appIndex: number, callback: AsyncCallback&lt;void&gt;): void

卸载一个应用的DLP沙箱。使用callback异步回调。调用成功后，系统销毁指定的DLP沙箱环境并释放相关资源。

需要清理沙箱环境时使用此接口。

必须在调用[installDLPSandbox](#dlppermissioninstalldlpsandbox)安装沙箱后才能调用此方法卸载。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 应用包名。最小7字节，最大128字节。超出范围时抛出错误码401。 |
| userId | number | 是 | 当前的用户ID，通过账号子系统获取的系统账号ID，默认主用户ID：100。取值范围为[0, 2<sup>31</sup>-1]，超出范围将被截断。当传入参数值小于0时，输出错误日志。  |
| appIndex | number | 是 | DLP沙箱号，即installDLPSandbox接口调用成功后的返回值，用于标识已安装的DLP沙箱。取值范围为[1000, 1100]，超出范围时输出错误日志。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当卸载DLP沙箱成功，err为undefined，否则为错误对象。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100,
  uri).then((dlpSandboxInfo: dlpPermission.DLPSandboxInfo) => {
  console.info('dlpSandboxInfo：', JSON.stringify(dlpSandboxInfo));
  dlpPermission.uninstallDLPSandbox('com.ohos.note', 100, dlpSandboxInfo.appIndex, (err, res) => {
    if (err) {
      console.error(`Failed to uninstall DLPSandbox. Code: ${err.code}, message: ${err.message}`); 
    } else {
      console.info('res', JSON.stringify(res));
    }
  }); // 卸载DLP沙箱。
}).catch((error: BusinessError)=> {
  console.error(`Failed to install or uninstall DLPSandbox. Code: ${error.code}, message: ${error.message}`);
}); // 安装后卸载DLP沙箱。
```

## dlpPermission.on('uninstallDLPSandbox')

on(type: 'uninstallDLPSandbox', listener: Callback&lt;DLPSandboxState&gt;): void

注册监听DLP沙箱卸载事件，用于感知沙箱环境的变化。注册成功后，当DLP沙箱被卸载时，系统会通过回调函数通知应用。

调用on注册监听后，建议在不需要监听时调用[off](#dlppermissionoffuninstalldlpsandbox)取消监听释放资源。

DLP管理应用需要追踪沙箱的创建和销毁状态，以便维护沙箱列表或执行相关的清理操作。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | 'uninstallDLPSandbox' | 是 | 监听事件类型。固定值为'uninstallDLPSandbox'：DLP沙箱卸载事件。 |
| listener | Callback&lt;[DLPSandboxState](#dlpsandboxstate)&gt; | 是 | 回调函数，用于接收沙箱应用卸载事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

dlpPermission.on('uninstallDLPSandbox', (info: dlpPermission.DLPSandboxState) => {
  console.info('uninstallDLPSandbox event', info.appIndex, info.bundleName);
}); // 订阅。
```

## dlpPermission.off('uninstallDLPSandbox')

off(type: 'uninstallDLPSandbox', listener?: Callback&lt;DLPSandboxState&gt;): void

取消监听DLP沙箱卸载事件。调用成功后，应用不再接收DLP沙箱卸载事件的回调通知。

必须在调用[on](#dlppermissiononuninstalldlpsandbox)注册监听后才能调用此方法取消监听。

DLP管理应用退出或不再需要追踪沙箱状态变化时，取消事件订阅以释放监听资源。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | 'uninstallDLPSandbox' | 是 | 监听事件类型。固定值为'uninstallDLPSandbox'：DLP沙箱卸载事件。 |
| listener | Callback&lt;[DLPSandboxState](#dlpsandboxstate)&gt; | 否 | 沙箱应用卸载事件的回调。默认为空，表示取消该类型事件的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

dlpPermission.off('uninstallDLPSandbox', (info: dlpPermission.DLPSandboxState) => {
  console.info('uninstallDLPSandbox event', info.appIndex, info.bundleName)
}); // 取消订阅。
```

## DLPFile

管理DLPFile的实例，表示一个DLP文件对象，需要通过[generateDLPFile](#dlppermissiongeneratedlpfile)/[openDLPFile](#dlppermissionopendlpfile11)获取DLPFile的实例。DLPFile对象代表一个已打开的DLP文件句柄，封装了对DLP文件的所有操作接口。对象在使用完毕后必须调用[closeDLPFile](#closedlpfile)方法释放资源，避免文件句柄泄漏。DLPFile对象在跨进程传递时，需要进行授权。

### 属性

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| dlpProperty | [DLPProperty](js-apis-dlppermission.md#dlpproperty21) | 否 | 否 | 表示DLP文件授权相关信息。 |

### addDLPLinkFile

addDLPLinkFile(linkFileName: string): Promise&lt;void&gt;

在FUSE文件系统（Filesystem in Userspace）添加link文件。FUSE是一种用户空间文件系统框架，允许在用户空间实现自定义文件系统逻辑。link文件是FUSE中映射到DLP密文的虚拟文件，对该文件的读写操作会同步到实际DLP文件。使用Promise异步回调。

在调用addDLPLinkFile后需要调用[deleteDLPLinkFile](#deletedlplinkfile)移除DLP link文件。

DLP应用需要通过标准文件接口访问加密文件内容时，先添加link文件将DLP文件映射为虚拟明文文件，应用可像操作普通文件一样读写该link文件。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于FUSE文件系统的link文件名。不超过255字节。超出范围时抛出错误码401。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function exampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;
  
  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。

  await dlpFile?.closeDLPFile(); // 关闭DLP对象。
  if (file) {
    fileIo.closeSync(file);
  }
}

exampleFunction();
```

### addDLPLinkFile

addDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

在FUSE文件系统添加link文件。使用callback异步回调。调用成功后，在FUSE文件系统中创建一个映射到DLP文件密文的虚拟文件。

在调用addDLPLinkFile后需要调用[deleteDLPLinkFile](#deletedlplinkfile)移除DLP link文件。

DLP应用需要通过标准文件接口访问加密文件内容时使用此接口。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于FUSE文件系统的link文件名。不超过255字节。超出范围时抛出错误码401。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，用于接收添加link文件的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;
  
  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  dlpFile.addDLPLinkFile('test.txt.dlp.link', async (err, res) => {
    if (err) {
      console.error(`Failed to add DLPLinkFile. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('res', JSON.stringify(res));
    }
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    fileIo.closeSync(file);
  }); // 添加link文件。
}

ExampleFunction();
```

### stopFuseLink

stopFuseLink(): Promise&lt;void&gt;

停止FUSE关联读写。使用Promise异步回调。调用成功后，暂停对link文件的读写操作。

调用stopFuseLink暂停FUSE关联读写后，必须调用[resumeFuseLink](#resumefuselink)恢复读写功能。

在删除link文件前，需要先停止关联读写以确保文件操作安全。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
  await dlpFile.stopFuseLink(); // 暂停link读写。
  await dlpFile?.closeDLPFile(); // 关闭DLP对象。
  if (file) {
    fileIo.closeSync(file);
  }
}

ExampleFunction();
```

### stopFuseLink

stopFuseLink(callback: AsyncCallback&lt;void&gt;): void

停止FUSE关联读写。使用callback异步回调。调用成功后，暂停对link文件的读写操作。

调用stopFuseLink暂停FUSE关联读写后，必须调用[resumeFuseLink](#resumefuselink)恢复读写功能。

删除link文件前需要暂停读写关联。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，用于接收停止FUSE关联的结果。回调参数包括：err（错误对象，成功时为undefined）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
  dlpFile.stopFuseLink(async (err, res) => {
    if (err) {
      console.error(`Failed to stop FuseLink. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('res', JSON.stringify(res));
    }
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    fileIo.closeSync(file);
  }); // 暂停link读写。
}

ExampleFunction();
```

### resumeFuseLink

resumeFuseLink(): Promise&lt;void&gt;

恢复FUSE关联读写。使用Promise异步回调。调用成功后，恢复对link文件的读写操作。 

必须在调用[stopFuseLink](#stopfuselink)暂停读写后才能调用此方法恢复读写功能。

link文件替换完成后，需要恢复读写关联以继续正常的文件访问。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
  await dlpFile.stopFuseLink(); // 暂停link读写。
  await dlpFile.resumeFuseLink(); // 恢复link读写。
  
  await dlpFile?.closeDLPFile(); // 关闭DLP对象。
  if (file) {
    fileIo.closeSync(file);
  }
}

ExampleFunction();
```

### resumeFuseLink

resumeFuseLink(callback: AsyncCallback&lt;void&gt;): void

恢复FUSE关联读写，使用callback异步回调。调用成功后，恢复对link文件的读写操作。

必须在调用[stopFuseLink](#stopfuselink)暂停读写后才能调用此方法恢复读写功能。

link文件替换完成后需要恢复读写关联。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，用于接收恢复FUSE关联的结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
  await dlpFile.stopFuseLink(); // 暂停link读写。
  dlpFile.resumeFuseLink(async (err, res) => {
    if (err) {
      console.error(`Failed to resume FuseLink. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('res', JSON.stringify(res));
    }
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    fileIo.closeSync(file);
  }); // 恢复link读写。
}

ExampleFunction();
```

### replaceDLPLinkFile

replaceDLPLinkFile(linkFileName: string): Promise&lt;void&gt;

替换link文件。使用Promise异步回调。调用成功后，使用新的link文件名替换当前link文件。需要先创建link文件并停止FUSE读写，才能执行此操作。

需要切换访问不同的DLP文件时，通过替换link文件实现文件映射的切换。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于FUSE文件系统的link文件名。不超过255字节。超出范围时抛出错误码401。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
  await dlpFile.stopFuseLink(); // 暂停link读写。
  await dlpFile.replaceDLPLinkFile('test_new.txt.dlp.link'); // 替换link文件。
  await dlpFile.resumeFuseLink(); // 恢复link读写。
  
  await dlpFile?.closeDLPFile(); // 关闭DLP对象。
  if (file) {
    fileIo.closeSync(file);
  }
}

ExampleFunction();
```

### replaceDLPLinkFile

replaceDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

替换link文件，使用callback异步回调。调用成功后，使用新的link文件名替换当前link文件。

需要切换访问不同的DLP文件时替换link文件。需要先创建link文件并停止FUSE读写，才能执行此操作。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于FUSE文件系统的link文件名。不超过255字节。超出范围时抛出错误码401。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，用于接收替换link文件的结果。回调参数包括：err（错误对象，成功时为undefined）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
  await dlpFile.stopFuseLink(); // 暂停link读写。
  dlpFile.replaceDLPLinkFile('test_new.txt.dlp.link', async (err, res) => { // 替换link文件。
    if (err) {
      console.error(`Failed to replace DLPLinkFile. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('res', JSON.stringify(res));
      await dlpFile?.resumeFuseLink(); // 恢复link读写。
    }
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    fileIo.closeSync(file);
  });
}

ExampleFunction();
```

### deleteDLPLinkFile

deleteDLPLinkFile(linkFileName: string): Promise&lt;void&gt;

删除FUSE文件系统中创建的link文件。使用Promise异步回调。调用成功后，从FUSE文件系统中移除指定的link文件。

在调用deleteDLPLinkFile前需要调用[addDLPLinkFile](#adddlplinkfile)添加DLP link文件。

DLP文件访问结束后清理link文件映射时使用此接口。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于FUSE文件系统的link文件名。不超过255字节。超出范围时抛出错误码401。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
  await dlpFile.deleteDLPLinkFile('test.txt.dlp.link'); // 删除link文件。
  
  await dlpFile?.closeDLPFile(); // 关闭DLP对象。
  if (file) {
    fileIo.closeSync(file);
  }
}

ExampleFunction();
```

### deleteDLPLinkFile

deleteDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

删除FUSE文件系统中创建的link文件，使用callback异步回调。调用成功后，从FUSE文件系统中移除指定的link文件。

在调用deleteDLPLinkFile前需要调用[addDLPLinkFile](#adddlplinkfile)添加DLP link文件。

DLP文件访问结束后清理link文件映射时使用此接口。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| linkFileName | string | 是 | 用于FUSE文件系统的link文件名。不超过255字节。超出范围时抛出错误码401。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，用于接收删除link文件的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  await dlpFile.addDLPLinkFile('test.txt.dlp.link'); // 添加link文件。
  dlpFile.deleteDLPLinkFile('test.txt.dlp.link', async (err, res) => { // 删除link文件。
    if (err) {
      console.error(`Failed to delete DLPLinkFile. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('res', JSON.stringify(res));
    }
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    fileIo.closeSync(file);
  });
}

ExampleFunction();
```

### recoverDLPFile

recoverDLPFile(plaintextFd: number): Promise&lt;void&gt;

移除DLP文件的权限控制，恢复成明文文件。使用Promise异步回调。

文件所有者决定取消文件的DLP保护时使用此接口，将其转换为普通文件以便自由分享。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | 是 | 目标明文文件的fd。取值范围为[0, 2<sup>31</sup>-1]。当fd小于0时，打印错误日志，函数停止运行；当fd大于2<sup>31</sup>-1时，fd的值被截断。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

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
| 19100010 | The DLP file is read only. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let destFile: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  destFile = fileIo.openSync('file://docs/storage/Users/currentUser/Desktop/dest.txt').fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  await dlpFile.recoverDLPFile(destFile); // 还原DLP文件。
  await dlpFile?.closeDLPFile(); // 关闭DLP对象。
  if (file) {
    fileIo.closeSync(file);
  }
  if (destFile) {
    fileIo.closeSync(destFile);
  }
}

ExampleFunction();
```

### recoverDLPFile

recoverDLPFile(plaintextFd: number, callback: AsyncCallback&lt;void&gt;): void

移除DLP文件的权限控制，恢复成明文文件，使用callback异步回调。

文件所有者决定取消文件的DLP保护时使用此接口。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | 是 | 目标明文文件的fd。取值范围为[0, 2<sup>31</sup>-1]。当fd小于0时，打印错误日志，函数停止运行；当fd大于2<sup>31</sup>-1时，fd的值被截断。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，用于接收恢复明文文件的结果。回调参数包括：err（错误对象，成功时为undefined）。 |

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
| 19100010 | The DLP file is read only. |
| 19100011 | The system ability works abnormally. |

**示例：**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let destFile: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  destFile = fileIo.openSync('destUri').fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  dlpFile.recoverDLPFile(destFile, async (err, res) => { // 还原DLP文件。
    if (err) {
      console.error(`Failed to recover DLPFile. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('res', JSON.stringify(res));
    }
    await dlpFile?.closeDLPFile(); // 关闭DLP对象。
    fileIo.closeSync(file);
    fileIo.closeSync(destFile);
  });
}

ExampleFunction();
```

### closeDLPFile

closeDLPFile(): Promise&lt;void&gt;

关闭DLPFile，释放对象。使用Promise异步回调。

调用[generateDLPFile](#dlppermissiongeneratedlpfile)/[openDLPFile](#dlppermissionopendlpfile11)成功后返回DLPFile对象，必须在使用完毕后调用closeDLPFile()释放资源。

文件所有者决定关闭DLP文件时使用此接口。

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

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。

  await dlpFile?.closeDLPFile(); // 关闭DLP对象。
  if (file) {
    fileIo.closeSync(file);
  }
}

ExampleFunction();
```

### closeDLPFile

closeDLPFile(callback: AsyncCallback&lt;void&gt;): void

关闭DLPFile，释放对象，使用callback异步回调。

调用openDLPFile()成功后返回DLPFile对象，必须在使用完毕后调用closeDLPFile()释放资源。

文件所有者决定关闭DLP文件时使用此接口。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

> **说明：**
>
> dlpFile不再使用，应该关闭释放内存，且对象不应继续使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，用于接收关闭DLPFile的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[DLP服务错误码](errorcode-dlp.md)。

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId;

  file = fileIo.openSync(uri).fd;
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  dlpFile.closeDLPFile((err, res) => { // 关闭DLP文件。
    if (err) {
      console.error(`Failed to close DLPFile. Code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('res', JSON.stringify(res));
    }
    fileIo.closeSync(file);
  });
}

ExampleFunction();
```

## dlpPermission.generateDLPFile

generateDLPFile(plaintextFd: number, ciphertextFd: number, property: DLPProperty): Promise&lt;DLPFile&gt;

DLP管理应用调用该接口，将明文文件加密生成DLPFile管理对象，对象仅在授权列表内的用户可以打开，授权又分为完全控制权限和只读权限。使用Promise异步回调。

调用generateDLPFile成功后返回DLPFile对象，必须在使用完毕后调用closeDLPFile释放资源。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | 是 | 待加密明文文件的fd。取值范围为[0, 2<sup>31</sup>-1]。当fd小于0时，打印错误日志，函数停止运行；当fd大于2<sup>31</sup>-1时，fd的值被截断。 |
| ciphertextFd | number | 是 | 目标加密文件的fd。取值范围为[0, 2<sup>31</sup>-1]。当fd小于0时，打印错误日志，函数停止运行；当fd大于2<sup>31</sup>-1时，fd的值被截断。 |
| property | [DLPProperty](js-apis-dlppermission.md#dlpproperty21) | 是 | 授权用户信息：授权用户列表、owner账号、联系人账号。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[DLPFile](#dlpfile)&gt; | Promise对象。resolve时返回DLPFile对象表示成功生成DLP文件，reject时抛出错误表示失败。|

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

async function ExampleFunction() {
  let dlpUri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt';
  let file: number | undefined = undefined;
  let dlp: number | undefined = undefined;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

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

  await dlpFile?.closeDLPFile(); // 关闭DLP对象。
  if (file) {
    fileIo.closeSync(file);
  }
  if (dlp) {
    fileIo.closeSync(dlp);
  }
}

ExampleFunction();
```

## dlpPermission.generateDLPFile

generateDLPFile(plaintextFd: number, ciphertextFd: number, property: DLPProperty, callback: AsyncCallback&lt;DLPFile&gt;): void

DLP管理应用调用该接口，将明文文件加密生成权限受控文件。仅授权列表内的用户可以打开该文件，授权又分为完全控制权限和只读权限。获取DLPFile管理对象，使用callback异步回调。使用完DLPFile对象后，应调用[closeDLPFile](#closedlpfile)释放对象，避免资源泄漏。

调用generateDLPFile()成功后返回DLPFile对象，必须在使用完毕后调用closeDLPFile()释放资源。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | 是 | 待加密明文文件的fd。取值范围为[0, 2<sup>31</sup>-1]。当fd小于0时，打印错误日志，函数停止运行；当fd大于2<sup>31</sup>-1时，fd的值被截断。 |
| ciphertextFd | number | 是 | 目标加密文件的fd。取值范围为[0, 2<sup>31</sup>-1]。当fd小于0时，打印错误日志，函数停止运行；当fd大于2<sup>31</sup>-1时，fd的值被截断。 |
| property | [DLPProperty](js-apis-dlppermission.md#dlpproperty21) | 是 | 授权用户信息：授权用户列表、owner账号、联系人账号。 |
| callback | AsyncCallback&lt;[DLPFile](#dlpfile)&gt; | 是 |回调函数。当生成DLP文件成功，err为undefined，data为获取到的DLP文件信息；否则为错误对象。 |

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

let dlpUri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt';
let file: number | undefined = undefined;
let dlp: number | undefined = undefined;

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
  if (err) {
    console.error(`Failed to generate DLPFile. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('res', JSON.stringify(res));
  }
  fileIo.closeSync(file);
  fileIo.closeSync(dlp);
});
```

## dlpPermission.openDLPFile<sup>11+</sup>

openDLPFile(ciphertextFd: number, appId: string): Promise&lt;DLPFile&gt;

DLP管理应用调用该接口，打开DLP文件。调用成功后返回DLPFile管理对象，可用于管理DLP文件的权限和进行相关操作。使用Promise异步回调。

调用openDLPFile()成功后返回DLPFile对象，必须在使用完毕后调用[closeDLPFile](#closedlpfile)释放资源。

DLP管理应用或授权应用需要访问受保护的DLP文件内容时，先打开文件获取管理对象。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| ciphertextFd | number | 是 | 加密文件的fd。取值范围为[0, 2<sup>31</sup>-1]。当fd小于0时，打印错误日志，函数停止运行；当fd大于2<sup>31</sup>-1时，fd的值被截断。 |
| appId | string | 是 | 调用方身份。最小8字节，最大1024字节。超出范围时抛出错误码401。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[DLPFile](#dlpfile)&gt; | Promise对象。resolve时返回DLPFile对象表示成功打开DLP文件，reject时抛出错误表示失败。 |

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

async function ExampleFunction() {
  let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
  let file: number | undefined = undefined;
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
  let appId = '';
  let bundleName = 'com.ohos.note';
  let userId = 100;
  let dlpFile: dlpPermission.DLPFile | undefined = undefined;

  let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
  appId = data.signatureInfo.appId; // appId通过应用包信息获取

  file = fileIo.openSync(uri).fd; // file通过文件打开获取fd
  dlpFile = await dlpPermission.openDLPFile(file, appId); // 打开DLP文件。
  await dlpFile?.closeDLPFile(); // 关闭DLP对象。

  if (file) {
    fileIo.closeSync(file);
  }
}

ExampleFunction();
```

## dlpPermission.openDLPFile<sup>11+</sup>

openDLPFile(ciphertextFd: number, appId: string, callback: AsyncCallback&lt;DLPFile&gt;): void

DLP管理应用调用该接口，打开DLP文件。使用callback异步回调。调用成功后返回DLPFile管理对象，可用于管理DLP文件的权限和进行相关操作。使用完DLPFile对象后，应调用closeDLPFile释放对象，避免资源泄漏。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_DLP_FILE

**系统能力：** SystemCapability.Security.DataLossPrevention

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| ciphertextFd | number | 是 | 加密文件的fd。取值范围为[0, 2<sup>31</sup>-1]。当fd小于0时，打印错误日志，函数停止运行；当fd大于2<sup>31</sup>-1时，fd的值被截断。 |
| appId | string | 是 | 调用方身份。最小8字节，最大1024字节。超出范围时抛出错误码401。 |
| callback | AsyncCallback&lt;[DLPFile](#dlpfile)&gt; | 是 | 回调函数。用于接收打开DLP文件的结果。回调参数包括：err（错误对象，成功时为undefined）和res（DLPFile对象，表示打开的DLP文件）。 |

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

let uri = 'file://docs/storage/Users/currentUser/Desktop/test.txt.dlp';
let file: number | undefined = undefined;
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = '';
let bundleName = 'com.ohos.note';
let userId = 100;

let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
appId = data.signatureInfo.appId; // appId通过应用包信息获取

file = fileIo.openSync(uri).fd; // file通过文件打开获取fd
dlpPermission.openDLPFile(file, appId, async (err, res) => { // 打开DLP文件。
  if (err) {
    console.error(`Failed to open DLPFile. Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('res', JSON.stringify(res));
  }
  await res?.closeDLPFile(); // 关闭DLP对象。
  if (file) {
    fileIo.closeSync(file);
  }
});
```

## DLPSandboxInfo

表示DLP沙箱的信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| appIndex | number | 否 | 否 | 表示DLP沙箱应用索引。 |
| tokenID | number | 否 | 否 | 表示DLP沙箱应用的tokenID。 |
| bindAppIndex<sup>24+</sup> | number | 否 | 是 | 表示被绑定的DLP沙箱应用的应用索引。默认不返回，仅当沙箱应用是文件预览（Preview）时返回。<br>**模型约束**：此接口仅可在Stage模型下使用。 |

## DLPSandboxState

DLP沙箱的状态信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.DataLossPrevention

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| bundleName | string | 否 | 否 | 表示应用包名。 |
| appIndex | number | 否 | 否 | 表示DLP沙箱应用索引。取值范围为[1000, 1100]，超出范围时输出错误日志。 |

## GatheringPolicyType

DLP沙箱聚合策略类型的枚举。沙箱聚合表示同一权限类型的DLP文件，在同一个沙箱内打开，例如在同一个沙箱内使用不同tab页打开；沙箱非聚合表示不同DLP文件在不同沙箱打开。

**系统能力：** SystemCapability.Security.DataLossPrevention

**系统接口：** 此接口为系统接口。

**参数：**

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| GATHERING | 1 | 表示沙箱聚合。 |
| NON_GATHERING | 2 | 表示沙箱非聚合。 |