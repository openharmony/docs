# @ohos.bluetooth.opp (蓝牙opp模块)(系统接口)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

OPP模块提供了使用蓝牙传输文件的功能，包括发送文件、接收文件和获取文件传输进度等。

> **说明：**
>
> 本模块首批接口从API version 16开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口。

## 导入模块

```js
import { opp } from '@kit.ConnectivityKit';
```

## createOppServerProfile

createOppServerProfile(): OppServerProfile

创建oppServer profile实例。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| OppServerProfile | 返回profile实例。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|202 | Non-system applications are not allowed to use system APIs.          |
|801 | Capability not supported.          |

**示例：**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let oppProfile = opp.createOppServerProfile();
    console.info('oppServer success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## OppServerProfile

Profile类，使用opp方法之前需要创建该类的实例进行操作，通过[createOppServerProfile()](#createoppserverprofile)方法构造此实例。

### sendFile

sendFile(deviceId: string, fileHolds: Array&lt;FileHolder&lt;): Promise&lt;void&gt;

使用蓝牙发送文件。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名     | 类型                          | 必填   | 说明                       |
| ------- | --------------------------- | ---- | ------------------------ |
| deviceId | string | 是    | 接收端的蓝牙MAC地址。 |
| fileHolds | Array&lt;[FileHolder](#fileholder)&gt;| 是    | 发送的文件数据，依据插入Array的次序进行发送。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Permission denied. Non-system applications are not allowed to use system APIs.                 |
|203 | This function is prohibited by enterprise management policies.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile is not supported.                 |
|2900099 | Failed to send file.                        |
|2903001 | The file type is not supported.                 |
|2903002 | Current Transfer Information is busy.                 |
|2903003 | The file is not accessible.                        |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs} from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// 创建fileHolders
try {
    let oppProfile = opp.createOppServerProfile();
    let fileHolders : Array<opp.FileHolder> = [];
    // 有效的URIS
    let uris: Array<string> = ['test1.jpg', 'test2.jpg'];
    for (let i = 0; i < uris.length; i++) {
        let filePath = uris[i];
        console.info('opp deal filePath is :' + filePath);
        let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
        let stat: fs.Stat = fs.statSync(file.fd);
        let fileHolder: opp.FileHolder = {
        filePath:filePath,
        fileSize:stat.size,
        fileFd:file.fd
        };
        fileHolders.push(fileHolder);
    }
    oppProfile.sendFile("11:22:33:44:55:66", fileHolders);
    // 等待文件传输完后，记得关闭文件描述符  fs.close(file.fd);
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setIncomingFileConfirmation

setIncomingFileConfirmation(accept: boolean, fileFd: number): Promise&lt;void&gt;

蓝牙接收文件。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名     | 类型                          | 必填   | 说明                       |
| ------- | --------------------------- | ---- | ------------------------ |
| accept | boolean | 是    | 表示是否接受接收文件。true表示接受，false表示不接受。 |
| fileFd | number| 是    | 接收的文件描述符，接收过程中需要保持开启。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Permission denied. Non-system applications are not allowed to use system APIs.                 |
|203 | This function is prohibited by enterprise management policies.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile is not supported.                 |
|2900099 | Failed to confirm the received file information.                        |
|2903002 | Current Transfer Information is busy.                 |
|2903003 | The file is not accessible.                        |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs} from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// 创建fileHolders
try {
    let oppProfile = opp.createOppServerProfile();
    let pathDir = "/test.jpg"; // 应用根据实际情况填写路径
    let file = fs.openSync(pathDir, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
    oppProfile.setIncomingFileConfirmation(true, file.fd);
    // 接收完成后关闭  
    fs.close(file.fd);
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### on('transferStateChange')

on(type: 'transferStateChange', callback: Callback&lt;OppTransferInformation&gt;): void

订阅蓝牙文件传输的进度和状态变化。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'transferStateChange'，当on('transferStateChange')调用完成后，可以收到文件传输进度和状态变化事件。 |
| callback | Callback&lt;[OppTransferInformation](#opptransferinformation)&gt; | 是    | 表示文件传输进度和状态变化事件的回调函数。                  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Permission denied. Non-system applications are not allowed to use system APIs.                 |
|203 | This function is prohibited by enterprise management policies.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile is not supported.                 |
|2903001 | The file type is not supported.                 |
|2903002 | Current Transfer Information is busy.                 |
|2903003 | The file is not accessible.                        |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// 创建fileHolders
try {
    let oppProfile = opp.createOppServerProfile();
    oppProfile.on("transferStateChange", (data: opp.OppTransferInformation) => {
        if (data.status == opp.TransferStatus.PENDING) {
          console.info("[opp_js] waiting to transfer : " + data.remoteDeviceName);
        } else if (data.status == opp.TransferStatus.RUNNING){
          console.info("[opp_js] running data.currentBytes " + data.currentBytes + " data.totalBytes" + data.totalBytes);
        } else if (data.status == opp.TransferStatus.FINISH){
          console.info("[opp_js] transfer finished, result is " + data.result);
        }
      });
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### off('transferStateChange')

off(type: 'transferStateChange', callback?: Callback&lt;OppTransferInformation&gt;): void

取消订阅蓝牙文件传输的进度和状态变化事件。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'transferStateChange'，调用off('transferStateChange')后，停止接收文件传输进度和状态变化事件。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Permission denied. Non-system applications are not allowed to use system APIs.          |
|203 | This function is prohibited by enterprise management policies.          |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile is not supported.                 |
|2903001 | The file type is not supported.                 |
|2903002 | Current Transfer Information is busy.                 |
|2903003 | The file is not accessible.                        |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// 创建fileHolders
try {
    let oppProfile = opp.createOppServerProfile();
    oppProfile.off("transferStateChange");
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### on('receiveIncomingFile')

on(type: 'receiveIncomingFile', callback: Callback&lt;OppTransferInformation&gt;): void

订阅蓝牙文件传输事件以接收文件。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'receiveIncomingFile'，当on('receiveIncomingFile')调用完成后，表示可以收到是否有文件传输通知的事件。 |
| callback | Callback&lt;[OppTransferInformation](#opptransferinformation)&gt; | 是    | 表示文件传输进度和状态变化事件的回调函数。                  |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Permission denied. Non-system applications are not allowed to use system APIs.          |
|203 | This function is prohibited by enterprise management policies.          |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile is not supported.                 |
|2903001 | The file type is not supported.                 |
|2903002 | Current Transfer Information is busy.                 |
|2903003 | The file is not accessible.                        |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// 创建fileHolders
try {
    let oppProfile = opp.createOppServerProfile();
    oppProfile.on("receiveIncomingFile", (data: opp.OppTransferInformation) => {
        if (data.status == opp.TransferStatus.PENDING) {
          console.info("[opp_js] received file waiting to confirm : " + data.remoteDeviceName);
        } else if (data.status == opp.TransferStatus.RUNNING){
          console.info("[opp_js] running data.currentBytes " + data.currentBytes + " data.totalBytes" + data.totalBytes);
        } else if (data.status == opp.TransferStatus.FINISH){
          console.info("[opp_js] transfer finished, result is " + data.result);
        }
      });
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### off('receiveIncomingFile')

off(type: 'receiveIncomingFile', callback?: Callback&lt;OppTransferInformation&gt;): void

取消订阅蓝牙文件传输完成的事件。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 事件回调类型，支持的事件为'receiveIncomingFile'，调用off('receiveIncomingFile')后，停止接收文件传输通知的事件。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Permission denied. Non-system applications are not allowed to use system APIs.          |
|203 | This function is prohibited by enterprise management policies.          |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile is not supported.                 |
|2903001 | The file type is not supported.                 |
|2903002 | Current Transfer Information is busy.                 |
|2903003 | The file is not accessible.                        |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { opp } from '@kit.ConnectivityKit';
// 创建fileHolders
try {
    let oppProfile = opp.createOppServerProfile();
    oppProfile.off("receiveIncomingFile");
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### cancelTransfer

cancelTransfer(): Promise&lt;void&gt;

取消文件传输。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Permission denied. Non-system applications are not allowed to use system APIs.          |
|203 | This function is prohibited by enterprise management policies.          |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile is not supported.                 |
|2900099 | Failed to cancel the current transfer.                        |
|2903002 | Current Transfer Information is busy.                 |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// 创建fileHolders
try {
    let oppProfile = opp.createOppServerProfile();
    oppProfile.cancelTransfer();
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getCurrentTransferInformation

getCurrentTransferInformation(): Promise&lt;[OppTransferInformation](#opptransferinformation)&gt;

获取当前传输的文件信息。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Permission denied. Non-system applications are not allowed to use system APIs.          |
|203 | This function is prohibited by enterprise management policies.          |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile is not supported.                 |
|2900099 | Failed to obtain the current transmission information.                        |
|2903004 | Current Transfer Information is empty.                 |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// 创建fileHolders
try {
    let oppProfile = opp.createOppServerProfile();
    let data = oppProfile.getCurrentTransferInformation();
    console.info('[opp_js] data ', data.status);
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setLastReceivedFileUri

setLastReceivedFileUri(uri: string): Promise&lt;void&gt;

设置最后一个接收文件的URI。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core

**参数：**

| 参数名     | 类型                          | 必填   | 说明                       |
| ------- | --------------------------- | ---- | ------------------------ |
| uri | string | 是    | 最后一个接收文件的URI。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[蓝牙服务子系统错误码](errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Permission denied. Non-system applications are not allowed to use system APIs.          |
|203 | This function is prohibited by enterprise management policies.          |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile is not supported.                 |
|2900099 | Failed to set the URI of the last file.                        |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { opp } from '@kit.ConnectivityKit';
// 创建fileHolders
try {
    let oppProfile = opp.createOppServerProfile();
    oppProfile.setLastReceivedFileUri("file://media/Photo/1/IMG_1739266559_000/screenshot_20250211_173419.jpg"); // 应用根据实际情况填写路径
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## FileHolder

描述发送的文件信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称              | 类型                                     | 只读   | 可选   | 说明                                       |
| --------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| filePath     | string                                   | 否    | 否    | 待传输文件的URI，例如：file://media/Photo/1/IMG_1739266559_000/test.jpg 。 |
| fileSize       | number                                  | 否    | 否    | 待传输文件的大小，以字节为单位。          |
| fileFd | number | 否    | 否    | 待传输文件的已打开的文件描述符（传输过程中需要保持打开直到传输完成）。                                    |

## OppTransferInformation

描述文件的传输信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称              | 类型                                     | 只读   | 可选   | 说明                                       |
| --------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| filePath     | string                                   | 否    | 否    | 待传输文件的URI，例如：file://media/Photo/1/IMG_1739266559_000/test.jpg 。 |
| remoteDeviceName       | string                                  | 否    | 否    | 传输对端设备名。                |
| remoteDeviceId | string | 否    | 否    | 传输对端MAC地址。                |
| direction | [DirectionType](#directiontype) | 否    | 否    | 传输方向。                |
| status | [TransferStatus](#transferstatus) | 否    | 否    | 传输状态。                |
| result | [TransferResult](#transferresult) | 否    | 否    | 传输结果。                |
| currentBytes | number | 否    | 否    | 当前传输的字节数。                |
| totalBytes | number | 否    | 否    | 需要传输的总字节数。                |
| currentCount | number | 否    | 否    | 本次传输当前文件序列。                |
| totalCount | number | 否    | 否    | 本次传输总传输的文件个数。                |

## DirectionType

枚举，文件传输方向。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                    | 值  | 说明           |
| --------------------- | ---- | ------------ |
| OUTBOUND   | 0    | 表示本文件是发送方向。 |
| INBOUND    | 1    | 表示本文件是接收方向。      |

## TransferStatus

枚举，文件传输状态。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                    | 值  | 说明           |
| --------------------- | ---- | ------------ |
| PENDING   | 0    | 表示等待传输。 |
| RUNNING    | 1    | 表示正在传输。      |
| FINISH | 2    | 表示传输完成。     |

## TransferResult

枚举，文件传输结果。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.Bluetooth.Core

| 名称                    | 值  | 说明           |
| --------------------- | ---- | ------------ |
| SUCCESS   | 0    | 表示传输成功。 |
| ERROR_UNSUPPORTED_TYPE    | 1    | 表示传输文件类型不支持。      |
| ERROR_BAD_REQUEST | 2    | 表示对端设备不能处理该请求。     |
| ERROR_NOT_ACCEPTABLE   | 3    | 表示对端设备拒绝接收该文件。 |
| ERROR_CANCELED    | 4    | 表示对端设备取消正在传输的该文件。      |
| ERROR_CONNECTION_FAILED | 5    | 表示对端设备失去连接。     |
| ERROR_TRANSFER   | 6    | 表示传输过程中发生错误。 |
| ERROR_UNKNOWN    | 7    | 表示发生未知错误。      |
