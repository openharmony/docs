# @ohos.dlpPermission (DLP)
<!--Kit: Data Protection Kit-->
<!--Subsystem: Security-->
<!--Owner: @winnieHuYu-->
<!--SE: @lucky-jinduo-->
<!--TSE: @nacyli-->

Data loss prevention (DLP) is a system solution provided to prevent data disclosure. The **dlpPermission** module provides APIs for cross-device file access management, encrypted storage, and access authorization.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The kit to which **@ohos.dlpPermission** belongs has been changed from **DataLossPreventionKit** to **DataProtectionKit**. You are advised to use the new module name **@kit.DataProtectionKit** to import the module. If **@kit.DataLossPreventionKit** is imported, only the APIs before the change can be called and the APIs after the change cannot be used.

## Modules to Import

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
```

## dlpPermission.isDLPFile

isDLPFile(fd: number): Promise&lt;boolean&gt;

Checks whether a file is a DLP file based on the file descriptor (FD). This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fd | number | Yes| FD of the file to be checked.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the file is a DLP file; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file: number | undefined = undefined;
try {
  file = fileIo.openSync(uri).fd;
  let res = dlpPermission.isDLPFile(file); // Check whether the file is a DLP file.
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
} finally {
  if (file !== undefined) {
    fileIo.closeSync(file);
  }
}
```

## dlpPermission.isDLPFile

isDLPFile(fd: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a file is a DLP file based on the FD. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fd | number | Yes| FD of the file to be checked.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. The value **true** means the file is a DLP file; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

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

Obtains the permission information of this DLP file. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[DLPPermissionInfo](#dlppermissioninfo)&gt; | Promise used to return the permission information about the DLP file. The operation is successful if no error is reported.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100006 | No permission to call this API, which is available only for DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.isInSandbox().then((inSandbox) => { // Check whether the application is running in a sandbox.
    if (inSandbox) {
      let res: dlpPermission.DLPPermissionInfo = await dlpPermission.getDLPPermissionInfo(); // Obtain the permission information.
      console.info('res', JSON.stringify(res));
    }
  });
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.getDLPPermissionInfo

getDLPPermissionInfo(callback: AsyncCallback&lt;DLPPermissionInfo&gt;): void

Obtains the permission information of this DLP file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[DLPPermissionInfo](#dlppermissioninfo)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100006 | No permission to call this API, which is available only for DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.isInSandbox().then((inSandbox) => { // Check whether the application is running in a sandbox.
    if (inSandbox) {
      dlpPermission.getDLPPermissionInfo((err, res) => {
        if (err != undefined) {
          console.error('getDLPPermissionInfo error,', err.code, err.message);
        } else {
          console.info('res', JSON.stringify(res));
        }
      }); // Obtain the permission information.
    }
  });
} catch (err) {
  console.error('getDLPPermissionInfo error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.getOriginalFileName

getOriginalFileName(fileName: string): string

Obtains the original file name of a DLP file. This API returns the result synchronously.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fileName | string | Yes| Name of the target file. The value contains up to 255 bytes.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | Original name of the DLP file obtained. For example, if the DLP file name is **test.txt.dlp**, the original file name returned is **test.txt**.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let res = dlpPermission.getOriginalFileName('test.txt.dlp'); // Obtain the original file name.
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.getDLPSuffix

getDLPSuffix(): string

Obtains the DLP file name extension. This API returns the result synchronously.

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| string | DLP file name extension obtained. For example, if the original file name is **text.txt**, the encrypted DLP file name is **test.txt.dlp**, and the returned extension is **.dlp**.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let res = dlpPermission.getDLPSuffix(); // Obtain the DLP file name extension.
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.on('openDLPFile')

on(type: 'openDLPFile', listener: Callback&lt;AccessedDLPFileInfo&gt;): void

Subscribes to a DLP file open event. The application will be notified when the DLP file is opened.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | 'openDLPFile' | Yes| Event type. It has a fixed value of **openDLPFile**, which indicates the DLP file open event.|
| listener | Callback&lt;[AccessedDLPFileInfo](#accesseddlpfileinfo)&gt; | Yes| Callback invoked when a DLP file is opened. The application will be notified when the DLP file is opened.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.on('openDLPFile', (info: dlpPermission.AccessedDLPFileInfo) => {
    console.info('openDlpFile event', info.uri, info.lastOpenTime)
  }); // Subscribe to a DLP file open event.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.off('openDLPFile')

off(type: 'openDLPFile', listener?: Callback&lt;AccessedDLPFileInfo&gt;): void

Unsubscribes from the DLP file open event. The application will not be notified when a DLP file is opened.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | 'openDLPFile' | Yes| Event type. It has a fixed value of **openDLPFile**, which indicates the DLP file open event.|
| listener | Callback&lt;[AccessedDLPFileInfo](#accesseddlpfileinfo)&gt; | No| Callback for the DLP file open event. The application will not be notified when a DLP file is opened. By default, this parameter is left blank, which unregisters all callbacks for the file open event.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.off('openDLPFile', (info: dlpPermission.AccessedDLPFileInfo) => {
    console.info('openDlpFile event', info.uri, info.lastOpenTime)
  }); // Unsubscribe from the DLP file open event.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.isInSandbox

isInSandbox(): Promise&lt;boolean&gt;

Checks whether this application is running in a DLP sandbox environment. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the application is running in a sandbox; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let inSandbox = dlpPermission.isInSandbox(); // Check whether the application is running in a sandbox.
  console.info('res', inSandbox);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.isInSandbox

isInSandbox(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this application is running in a DLP sandbox environment. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object. The value **true** means the application is running in a sandbox; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

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
  }); // Whether the application is running in a sandbox.
} catch (err) {
  console.error('isInSandbox error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.getDLPSupportedFileTypes

getDLPSupportedFileTypes(): Promise&lt;Array&lt;string&gt;&gt;

Obtains the file name extension types that support DLP. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the file name extension types obtained.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let res = dlpPermission.getDLPSupportedFileTypes(); // Obtain the file types that support DLP.
  console.info('res', JSON.stringify(res));
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.getDLPSupportedFileTypes

getDLPSupportedFileTypes(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the file name extension types that support DLP. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

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
  }); // Obtain the file types that support DLP.
} catch (err) {
  console.error('getDLPSupportedFileTypes error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.setRetentionState

setRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt;

Sets the sandbox retention state. This API uses an asynchronous callback to return the result. A sandbox application is automatically installed when a DLP file is opened, and automatically uninstalled when the DLP file is closed. Once the sandbox retention state is set for a DLP file, the sandbox application will not be automatically uninstalled when the DLP file is closed. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | Yes| URIs of the files to be set with the retention state.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100006 | No permission to call this API, which is available only for DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  let inSandbox = await dlpPermission.isInSandbox(); // Check whether the application is running in a sandbox.
  if (inSandbox) {
    dlpPermission.setRetentionState([uri]); // Set the retention state for a sandbox application.
  }
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.setRetentionState

setRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Sets the sandbox retention state. This API uses an asynchronous callback to return the result. A sandbox application is automatically installed when a DLP file is opened, and automatically uninstalled when the DLP file is closed. Once the sandbox retention state is set for a DLP file, the sandbox application will not be automatically uninstalled when the DLP file is closed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | Yes| URIs of the files to be set with the retention state. The array has no length limit, but each string cannot exceed 4095 bytes.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100006 | No permission to call this API, which is available only for DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**Example**

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
  }); // Set the sandbox retention state.
} catch (err) {
  console.error('setRetentionState error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.cancelRetentionState

cancelRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt;

Cancels the sandbox retention state, that is, allows the sandbox application to be automatically uninstalled when the DLP file is closed. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | Yes| URIs of the files to be set with the retention state. The array has no length limit, but each string cannot exceed 4095 bytes.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.cancelRetentionState([uri]); // Cancel the retention state for a sandbox application.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.cancelRetentionState

cancelRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Cancels the sandbox retention state, that is, allows the sandbox application to be automatically uninstalled when the DLP file is closed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | Yes| URIs of the files to be set with the retention state. The array has no length limit, but each string cannot exceed 4095 bytes.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

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
  }); // Cancel the sandbox retention state.
} catch (err) {
  console.error('cancelRetentionState error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.getRetentionSandboxList

getRetentionSandboxList(bundleName?: string): Promise&lt;Array&lt;RetentionSandboxInfo&gt;&gt;

Obtains the sandbox applications in the retention state of an application. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | No| Bundle name of the application. By default, this parameter is left empty, which obtains the sandbox retention information about the current application. The value contains 7 to 128 bytes.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[RetentionSandboxInfo](#retentionsandboxinfo)&gt;&gt; | Promise used to return the sandbox retention information obtained.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let res:Array<dlpPermission.RetentionSandboxInfo> = await dlpPermission.getRetentionSandboxList(); // Obtain the sandbox apps in the retention state.
  console.info('res', JSON.stringify(res))
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.getRetentionSandboxList

getRetentionSandboxList(bundleName: string, callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void

Obtains the sandbox applications in the retention state of an application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name of the application. The value contains 7 to 128 bytes.|
| callback | AsyncCallback&lt;Array&lt;[RetentionSandboxInfo](#retentionsandboxinfo)&gt;&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**Example**

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
  }); // Obtain the sandbox retention information.
} catch (err) {
  console.error('getRetentionSandboxList error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.getRetentionSandboxList

getRetentionSandboxList(callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void

Obtains the sandbox applications in the retention state of an application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[RetentionSandboxInfo](#retentionsandboxinfo)&gt;&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**Example**

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
  }); // Obtain the sandbox retention information.
} catch (err) {
  console.error('getRetentionSandboxList error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.getDLPFileAccessRecords

getDLPFileAccessRecords(): Promise&lt;Array&lt;AccessedDLPFileInfo&gt;&gt;

Obtains the list of DLP files that are accessed recently. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[AccessedDLPFileInfo](#accesseddlpfileinfo)&gt;&gt; | Promise used to return the list of recently accessed files obtained.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let res:Array<dlpPermission.AccessedDLPFileInfo> = await dlpPermission.getDLPFileAccessRecords(); // Obtain the list of recently accessed DLP files.
  console.info('res', JSON.stringify(res))
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.getDLPFileAccessRecords

getDLPFileAccessRecords(callback: AsyncCallback&lt;Array&lt;AccessedDLPFileInfo&gt;&gt;): void

Obtains the list of DLP files that are accessed recently. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[AccessedDLPFileInfo](#accesseddlpfileinfo)&gt;&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |

**Example**

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
  }); // Obtain the list of recently accessed DLP files.
} catch (err) {
  console.error('getDLPFileAccessRecords error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.startDLPManagerForResult<sup>11+</sup>

startDLPManagerForResult(context: common.UIAbilityContext, want: Want): Promise&lt;DLPManagerResult&gt;

Starts the DLP manager application on the current UIAbility page in borderless mode. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | [common.UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | Yes| UIAbility context.|
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Object that requests the start of the DLP manager application.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[DLPManagerResult](#dlpmanagerresult11)&gt; | Promise used to return the **DLPManagerResult** object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |
| 19100016 | The uri field is missing in the want parameter. |
| 19100017 | The displayName field is missing in the want parameter. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { common, Want } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';

try {
  let context = new UIContext().getHostContext() as common.UIAbilityContext; // Obtain the current UIAbilityContext.
  let want: Want = {
    "uri": "file://docs/storage/Users/currentUser/Desktop/1.txt",
    "parameters": {
      "displayName": "1.txt"
    }
  }; // Request parameters.
  dlpPermission.startDLPManagerForResult(context, want).then((res) => {
    console.info('res.resultCode', res.resultCode);
    console.info('res.want', JSON.stringify(res.want));
  }); // Start the DLP manager application.
} catch (err) {
  console.error('error', err.code, err.message); // Throw an error if the operation fails.
}
```

## dlpPermission.setSandboxAppConfig<sup>11+<sup>
setSandboxAppConfig(configInfo: string): Promise&lt;void&gt;

Sets sandbox application configuration. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| configInfo | string | Yes| Sandbox application configuration. The length is less than 4 MB.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |
| 19100018 | The application is not authorized. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.setSandboxAppConfig('configInfo'); // Set sandbox application configuration.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.cleanSandboxAppConfig<sup>11+<sup>
cleanSandboxAppConfig(): Promise&lt;void&gt;

Cleans sandbox application configuration. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100007 | No permission to call this API, which is available only for non-DLP sandbox applications. |
| 19100011 | The system ability works abnormally. |
| 19100018 | The application is not authorized. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.cleanSandboxAppConfig(); // Clean sandbox application configuration.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.getSandboxAppConfig<sup>11+<sup>
getSandboxAppConfig(): Promise&lt;string&gt;

Obtains sandbox application configuration. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the sandbox application configuration obtained.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |
| 19100018 | The application is not authorized. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let res = await dlpPermission.getSandboxAppConfig() // Obtain the sandbox application configuration.
  console.info('res', JSON.stringify(res));
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
}
```

## dlpPermission.isDLPFeatureProvided<sup>12+<sup>
isDLPFeatureProvided(): Promise&lt;boolean&gt;

Queries whether the current system provides the DLP feature. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the current system provides the DLP feature; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

dlpPermission.isDLPFeatureProvided().then((res) => {
  console.info('res', JSON.stringify(res));
}).catch((err: BusinessError) => {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Throw an error if the operation fails.
});
```

## ActionFlagType

Enumerates the operations that can be performed on a DLP file. For example, the DLP sandbox application can dim its button based on this parameter.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Value| Description|
| -------- | -------- | -------- |
| ACTION_VIEW | 0x00000001 | View the file.|
| ACTION_SAVE | 0x00000002 | Save the file.|
| ACTION_SAVE_AS | 0x00000004 | Save the file as another file.|
| ACTION_EDIT | 0x00000008 | Edit the file.|
| ACTION_SCREEN_CAPTURE | 0x00000010 | Capture screenshots of the file.|
| ACTION_SCREEN_SHARE | 0x00000020 | Share the screen of the file.|
| ACTION_SCREEN_RECORD | 0x00000040 | Record the screen on which the file is open.|
| ACTION_COPY | 0x00000080 | Copy the file.|
| ACTION_PRINT | 0x00000100 | Print the file.|
| ACTION_EXPORT | 0x00000200 | Export the file.|
| ACTION_PERMISSION_CHANGE | 0x00000400 | Modify the permissions on the file.|

## DLPFileAccess

Enumerates the permissions on a DLP file.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Value| Description|
| -------- | -------- | -------- |
| NO_PERMISSION | 0 | The user has no permission on the file.|
| READ_ONLY | 1 | The user has only the permission to read the file.|
| CONTENT_EDIT | 2 | The user has the permission to edit the file.|
| FULL_CONTROL | 3 | The user has full control on the file.|

## DLPPermissionInfo

Represents the permission information about a DLP file.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| dlpFileAccess | [DLPFileAccess](#dlpfileaccess) | Yes| No| User permission on the DLP file, for example, read-only.|
| flags | number | Yes| No| Operations that can be performed on the DLP file. It is a combination of different [ActionFlagTypes](#actionflagtype).|

## AccessedDLPFileInfo

Represents the information about a DLP file opened.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| uri | string | Yes| No| URI of the DLP file. The value contains up to 4095 bytes.|
| lastOpenTime | number | Yes| No| Time when the file was last opened.|

## DLPManagerResult<sup>11+</sup>

Represents information about the trigger of the DLP manager application.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| resultCode | number | Yes| No| Result code returned after the DLP manager application is started and exits.|
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| No| Data returned after the DLP manager application is started and exits.|

## RetentionSandboxInfo

Represents the sandbox retention information.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| appIndex | number | Yes| No| Index of the DLP sandbox application.|
| bundleName | string | Yes| No| Bundle name of the application. The value contains 7 to 128 bytes.|
| docUris | Array&lt;string&gt; | Yes| No| URI list of the DLP files. The array has no length limit, but each string cannot exceed 4095 bytes.|
