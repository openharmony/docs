# @ohos.bluetooth.opp (Bluetooth OPP Module) (System API)

The OPP module provides the Bluetooth-based file transfer functions, including sending files, receiving files, and obtaining the file transfer progress.

> **NOTE**
>
> The initial APIs of this module are supported since API version 16. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only the system APIs provided by the module.

## Modules to Import

```js
import { opp } from '@kit.ConnectivityKit';
```

## createOppServerProfile

createOppServerProfile(): OppServerProfile

Creates an **OppServerProfile** instance.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| OppServerProfile | **OppServerProfile** instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|202 | Non-system applications are not allowed to use system APIs.          |
|801 | Capability not supported.          |

**Example**

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

Represents the **OppServerProfile** class. Before using APIs of this class, you need to create an **OppServerProfile** instance by using the [createOppServerProfile ()](#createoppserverprofile).

### sendFile

sendFile(deviceId: string, fileHolds: Array&lt;FileHolder&lt;): Promise&lt;void&gt;

Send files over Bluetooth.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                         | Mandatory  | Description                      |
| ------- | --------------------------- | ---- | ------------------------ |
| deviceId | string | Yes   | Bluetooth MAC address of the receiver.|
| fileHolds | Array&lt;[FileHolder](#fileholder)&gt;| Yes   | File data to transfer. Data is sent according to the sequence it is inserted into the array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
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

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// Create fileHolders.
try {
    let oppProfile = opp.createOppServerProfile();
    let fileHolders : Array<opp.FileHolder> = [];
    // Valid URIs
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
    // After the file transfer is complete, call fs.close(file.fd) to close the file descriptor.
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setIncomingFileConfirmation

setIncomingFileConfirmation(accept: boolean, fileFd: number): Promise&lt;void&gt;

Receives files over Bluetooth.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                         | Mandatory  | Description                      |
| ------- | --------------------------- | ---- | ------------------------ |
| accept | boolean | Yes   | Whether to accept the file transfer request. The value **true** means to accept the file transfer request, and the value **false** means the opposite.|
| fileFd | number| Yes   | File descriptor, which must be enabled during file receiving.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
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

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// Create fileHolders.
try {
    let oppProfile = opp.createOppServerProfile();
    let pathDir = this.context.filesDir + "/test.jpg";
    let file = fs.openSync(pathDir, fs.OpenMode.CREATE | fs.OpenMode.READ_WRITE);
    oppProfile.setIncomingFileConfirmation(true, file.fd);
    // Close the file descriptor after file receiving is complete. 
    fs.close(file.fd);
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### on('transferStateChange')

on(type: 'transferStateChange', callback: Callback&lt;OppTransferInformation&gt;): void

Subscribes to the progress and status changes of Bluetooth file transfer.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The field has a fixed value of **transferStateChange**. After **on('transferStateChange')** is called, the file transfer progress and status change events will be returned.|
| callback | Callback&lt;[OppTransferInformation](#opptransferinformation)&gt; | Yes   | Callback used to return the file transfer progress and status change events.                 |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
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

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// Create fileHolders.
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

Unsubscribes from the progress and status changes of Bluetooth file transfer.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The field has a fixed value of **transferStateChange**. After **off('transferStateChange')** is called, the file transfer progress and status change events will not be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
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

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// Create fileHolders.
try {
    let oppProfile = opp.createOppServerProfile();
    oppProfile.off("transferStateChange");
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### on('receiveIncomingFile')

on(type: 'receiveIncomingFile', callback: Callback&lt;OppTransferInformation&gt;): void

Subscribes to Bluetooth file transfer start events.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The field has a fixed value of **receiveIncomingFile**. After **on('receiveIncomingFile')** is called, an event will be returned when file transfer begins.|
| callback | Callback&lt;[OppTransferInformation](#opptransferinformation)&gt; | Yes   | Callback used to return the file transfer progress and status change events.                 |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
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

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// Create fileHolders.
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

Unsubscribes from Bluetooth file transfer completion events.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The field has a fixed value of **receiveIncomingFile**. After **off('receiveIncomingFile')** is called, an event will be returned when file transfer is complete.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
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

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// Create fileHolders.
try {
    let oppProfile = opp.createOppServerProfile();
    oppProfile.off("receiveIncomingFile");
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### cancelTransfer

cancelTransfer(): Promise&lt;void&gt;

Cancels Bluetooth file transfer.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
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

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// Create fileHolders.
try {
    let oppProfile = opp.createOppServerProfile();
    oppProfile.cancelTransfer();
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getCurrentTransferInformation

getCurrentTransferInformation(): Promise&lt;[OppTransferInformation](#opptransferinformation)&gt;

Obtains the information about the file that is being transferred.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
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

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// Create fileHolders.
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

Sets the URI of the last received file.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                         | Mandatory  | Description                      |
| ------- | --------------------------- | ---- | ------------------------ |
| uri | string | Yes   | URI of the last received file.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
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

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';
import { opp } from '@kit.ConnectivityKit';
// Create fileHolders.
try {
    let oppProfile = opp.createOppServerProfile();
    oppProfile.setLastReceivedFileUri("file://media/Photo/1/IMG_1739266559_000/screenshot_20250211_173419.jpg ");
} catch (err) {
      console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## FileHolder

Describes the information about the file to be sent.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                                    | Read-Only  | Optional  | Description                                      |
| --------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| filePath     | string                                   | No   | No   | URI of the file to be sent, for example, **file://media/Photo/1/IMG_1739266559_000/test.jpg**.|
| fileSize       | number                                  | No   | No   | Size of the file to be sent, in bytes.         |
| fileFd | number | No   | No   | Opened file descriptor of the file to be sent. The file descriptor must be kept open until the file transfer is complete.                                   |

## OppTransferInformation

Describes the file transfer information.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                                    | Read-Only  | Optional  | Description                                      |
| --------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| filePath     | string                                   | No   | No   | URI of the file to be sent, for example, **file://media/Photo/1/IMG_1739266559_000/test.jpg**.|
| remoteDeviceName       | string                                  | No   | No   | Name of the peer device.               |
| remoteDeviceId | string | No   | No   | MAC address of the peer device.               |
| direction | [DirectionType](#directiontype) | No   | No   | Transfer direction.               |
| status | [TransferStatus](#transferstatus) | No   | No   | Transfer status.               |
| result | [TransferResult](#transferresult) | No   | No   | Transfer result.               |
| currentBytes | number | No   | No   | Number of transferred bytes.               |
| totalBytes | number | No   | No   | Total number of bytes to be transferred.               |
| currentCount | number | No   | No   | Sequence number of the file to be transferred.               |
| totalCount | number | No   | No   | Total number of transferred files.               |

## DirectionType

Enumerates file transfer directions.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description          |
| --------------------- | ---- | ------------ |
| OUTBOUND   | 0    | File sending.|
| INBOUND    | 1    | File receiving.     |

## TransferStatus

Enumerates the file transfer states.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description          |
| --------------------- | ---- | ------------ |
| PENDING   | 0    | Waiting for transfer.|
| RUNNING    | 1    | File transfer in progress.     |
| FINISH | 2    | File transfer completed.    |

## TransferResult

Enumerates file transfer results.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description          |
| --------------------- | ---- | ------------ |
| SUCCESS   | 0    | File transfer is successful.|
| ERROR_UNSUPPORTED_TYPE    | 1    | The type of files to be transferred is not supported.     |
| ERROR_BAD_REQUEST | 2    | The peer device cannot process the file transfer request.    |
| ERROR_NOT_ACCEPTABLE   | 3    | The peer device rejects the file transfer request.|
| ERROR_CANCELED    | 4    | The peer device cancels the file transfer.     |
| ERROR_CONNECTION_FAILED | 5    | The peer device is disconnected.    |
| ERROR_TRANSFER   | 6    | An error occurs during file transfer.|
| ERROR_UNKNOWN    | 7    | An unknown error occurs.     |
