# \@ohos.dlpPermission (DLP)

Data loss prevention (DLP) is a system solution provided by OpenHarmony to prevent data disclosure. The **dlpPermission** module provides APIs for cross-device file access management, encrypted storage, and access authorization.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import dlpPermission from '@ohos.dlpPermission';
```

## dlpPermission.isDLPFile

isDLPFile(fd: number): Promise&lt;boolean&gt;

Checks whether a file is a DLP file. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fd | number | Yes| File descriptor (FD) of the file to check.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the file is a DLP file; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);

try {
  let res = dlpPermission.isDLPFile(file.fd);  // Check whether the file is a DLP file.
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
fs.closeSync(file);
```

## dlpPermission.isDLPFile

isDLPFile(fd: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a file is a DLP file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fd | number | Yes| FD of the file to check.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback invoked to return the result.<br>The value **true** means the file is a DLP file; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

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

Obtains the permission information of this DLP file. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[DLPPermissionInfo](#dlppermissioninfo)&gt; | Promise used to return the permission information about the DLP file. The operation is successful if no error is reported.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100006 | This API can only be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let inSandbox: boolean = await dlpPermission.isInSandbox(); // Check whether the application is running in a sandbox.
  if (inSandbox) {
    let res: Promise<dlpPermission.DLPPermissionInfo> = dlpPermission.getDLPPermissionInfo(); // Obtain the permission information.
    console.info('res', JSON.stringify(res));
  }
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.getDLPPermissionInfo

getDLPPermissionInfo(callback: AsyncCallback&lt;DLPPermissionInfo&gt;): void

Obtains the permission information of this DLP file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[DLPPermissionInfo](#dlppermissioninfo)&gt; | Yes| Callback invoked to return the result.<br>If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100006 | This API can only be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

try {
  let inSandbox: boolean = await dlpPermission.isInSandbox(); // Check whether the application is running in a sandbox.
  if (inSandbox) {
    dlpPermission.getDLPPermissionInfo((err, res) => {
      if (err != undefined) {
        console.error('getDLPPermissionInfo error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
    }); // Obtain the permission information.
  }
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
| fileName | string | Yes| Name of the target file.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | Original name of the DLP file obtained. For example, if the DLP file name is **test.txt.dlp**, the original file name returned is **test.txt**.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res = dlpPermission.getOriginalFileName('test.txt.dlp'); // Obtain the original file name.
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.getDLPSuffix

getDLPSuffix(): string

Obtains the DLP file name extension. This API returns the result synchronously.

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| string | DLP file name extension obtained. For example, if the original file is **text.txt** and the returned file name extension is .dlp, the DLP file name is **test.txt.dlp**.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res = dlpPermission.getDLPSuffix(); // Obtain the DLP file name extension.
  console.info('res', res);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
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
| listener | Callback&lt;[AccessedDLPFileInfo](#accesseddlpfileinfo)&gt; | Yes| Callback invoked when a DLP file is opened. A notification will be sent to the application.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.on('openDLPFile', (info: dlpPermission.AccessedDLPFileInfo) => {
    console.info('openDlpFile event', info.uri, info.lastOpenTime)
  // Subscribe to the DLP file open event.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
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

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.off('openDLPFile', (info: dlpPermission.AccessedDLPFileInfo) => {
    console.info('openDlpFile event', info.uri, info.lastOpenTime)
  // Unsubscribe from the DLP file open events.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.isInSandbox

isInSandbox(): Promise&lt;boolean&gt;

Checks whether this application is running in a DLP sandbox environment. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let inSandbox = dlpPermission.isInSandbox(); // Check whether the application is running in a sandbox.
  console.info('res', inSandbox);
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.isInSandbox

isInSandbox(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this application is running in a DLP sandbox environment. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback invoked to return the result.<br>If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.isInSandbox((err, data) => {
    if (err) {
      console.error('isInSandbox error,', err.code, err.message);
    } else {
      console.info('isInSandbox, data', JSON.stringify(data));
    }
  }); // Whether the application is running in the sandbox.
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

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res = dlpPermission.getDLPSupportedFileTypes(); // Obtain the file types that support DLP.
  console.info('res', JSON.stringify(res));
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.getDLPSupportedFileTypes

getDLPSupportedFileTypes(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the file name extension types that support DLP. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes| Callback invoked to return the result.<br>If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

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
  }); // Obtain the file types that support DLP.
} catch (err) {
  console.error('getDLPSupportedFileTypes error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.setRetentionState

setRetentionState(docUris: Array&lt;string&gt;): Promise&lt;void&gt;

Sets the sandbox retention state. This API uses a promise to return the result. 
A sandbox application is automatically installed when a DLP file is opened, and automatically uninstalled when the DLP file is closed. Once the sandbox retention state is set for a DLP file, the sandbox application will not be automatically uninstalled when the DLP file is closed.

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

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100006 | This API can only be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  let inSandbox: boolean = await dlpPermission.isInSandbox(); // Check whether the application is running in a sandbox.
  if (inSandbox) {
    dlpPermission.setRetentionState([uri]); // Set the retention state for a sandbox application.
  }
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.setRetentionState

setRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Sets the sandbox retention state. This API uses an asynchronous callback to return the result. 
A sandbox application is automatically installed when a DLP file is opened, and automatically uninstalled when the DLP file is closed. Once the sandbox retention state is set for a DLP file, the sandbox application will not be automatically uninstalled when the DLP file is closed.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | Yes| URIs of the files to be set with the retention state.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.<br>If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100006 | This API can only be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**Example**

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
| docUris | Array&lt;string&gt; | Yes| URIs of the files whose retention state is to be canceled.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.cancelRetentionState([uri]); // Cancel the retention state for a sandbox application.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.cancelRetentionState

cancelRetentionState(docUris: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Cancels the sandbox retention state, that is, allows the sandbox application to be automatically uninstalled when the DLP file is closed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| docUris | Array&lt;string&gt; | Yes| URIs of the files whose retention state is to be canceled.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.<br>If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

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
| bundleName | string | No| Bundle name of the application. By default, this parameter is left empty, which obtains the sandbox retention information about the current application.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[RetentionSandboxInfo](#retentionsandboxinfo)&gt;&gt; | Promise used to return the sandbox retention information obtained.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res: Promise<Array<dlpPermission.RetentionSandboxInfo>> = dlpPermission.getRetentionSandboxList(); // Obtain all the sandbox applications in the retention state.
  console.info('res', JSON.stringify(res))
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.getRetentionSandboxList

getRetentionSandboxList(bundleName: string, callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void

Obtains the sandbox applications in the retention state of an application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name of the application.|
| callback | AsyncCallback&lt;Array&lt;[RetentionSandboxInfo](#retentionsandboxinfo)&gt;&gt; | Yes| Callback invoked to return the result.<br>If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**Example**

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
  }); // Obtain the sandbox retention information.
} catch (err) {
  console.error('getRetentionSandboxList error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.getRetentionSandboxList

getRetentionSandboxList(callback: AsyncCallback&lt;Array&lt;RetentionSandboxInfo&gt;&gt;): void

Obtains the sandbox applications in the retention state of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[RetentionSandboxInfo](#retentionsandboxinfo)&gt;&gt; | Yes| Callback invoked to return the result.<br>If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**Example**

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

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res: Promise<Array<dlpPermission.AccessedDLPFileInfo>> = dlpPermission.getDLPFileAccessRecords(); // Obtain the list of recently accessed DLP files.
  console.info('res', JSON.stringify(res))
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.getDLPFileAccessRecords

getDLPFileAccessRecords(callback: AsyncCallback&lt;Array&lt;AccessedDLPFileInfo&gt;&gt;): void

Obtains the list of DLP files that are accessed recently. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[AccessedDLPFileInfo](#accesseddlpfileinfo)&gt;&gt; | Yes| Callback invoked to return the result.<br>If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |

**Example**

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
| context | [common.UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) | Yes| UIAbility context.|
| want | [Want](js-apis-app-ability-want.md) | Yes| Object that requests the start of the DLP manager application.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[DLPManagerResult](#dlpmanagerresult11)&gt; | Promise used to return the **DLPManagerResult** object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |
| 19100016 | Uri does not exist in want. |
| 19100017 | DisplayName does not exist in want (under parameters). |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import common from '@ohos.app.ability.common';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import UIAbility from '@ohos.app.ability.UIAbility'
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

try {
  let context = getContext () as common.UIAbilityContext; // Obtain the UIAbility context.
  let want: Want = {
    "uri": "file://docs/storage/Users/currentUser/Desktop/1.txt",
    "parameters": {
      "displayName": "1.txt"
    }
  }; // Request parameters.
  dlpPermission.startDLPManagerForResult(context, want).then((res) => {
    console.info('res.resultCode', res.resultCode);
    console.info('res.want', JSON.stringifg(res.want));
  }); // Start the DLP manager application.
} catch (err) {
  console.error('error', err.code, err.message); // Error reported if the operation fails.
}
```

## dlpPermission.getDLPGatheringPolicy

getDLPGatheringPolicy(): Promise&lt;GatheringPolicyType&gt;

Obtains the DLP sandbox gathering policy. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[GatheringPolicyType](#gatheringpolicytype)&gt; | Promise used to return the DLP sandbox aggregation policy obtained.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  let res: Promise<dlpPermission.GatheringPolicyType> = dlpPermission.getDLPGatheringPolicy(); // Obtain the sandbox gathering policy.
  console.info('res', JSON.stringify(res));
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.getDLPGatheringPolicy

getDLPGatheringPolicy(callback: AsyncCallback&lt;GatheringPolicyType&gt;): void

Obtains the DLP sandbox gathering policy. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[GatheringPolicyType](#gatheringpolicytype)&gt; | Yes| Callback invoked to return the result.<br>If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

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
  }); // Obtain the sandbox gathering policy.
} catch (err) {
  console.error('getDLPGatheringPolicy error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.installDLPSandbox

installDLPSandbox(bundleName: string, access: DLPFileAccess, userId: number, uri: string): Promise&lt;DLPSandboxInfo&gt;

Installs a DLP sandbox application for an application. This API uses a promise to return the application sandbox installed.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name of the application.|
| access | [DLPFileAccess](#dlpfileaccess) | Yes| Permission on the DLP file.|
| userId | number | Yes| Current user ID, which is the OS account ID obtained by the account subsystem. The default super user ID is **100**.|
| uri | string | Yes| URI of the DLP file.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[DLPSandboxInfo](#dlpsandboxinfo)&gt; | Promise used to return the information about the sandbox application installed.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  let res: Promise<dlpPermission.DLPSandboxInfo> = dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri); // Install a DLP sandbox application.
  console.info('res', JSON.stringify(res));
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.installDLPSandbox

installDLPSandbox(bundleName: string, access: DLPFileAccess, userId: number, uri:string, callback: AsyncCallback&lt;DLPSandboxInfo&gt;): void

Installs a DLP sandbox application for an application. This API uses an asynchronous callback to return the index of the sandbox application installed.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name of the application.|
| access | [DLPFileAccess](#dlpfileaccess) | Yes| Permission on the DLP file.|
| userId | number | Yes| Current user ID, which is the OS account ID obtained by the account subsystem. The default super user ID is **100**.|
| uri | string | Yes| URI of the DLP file.|
| callback | AsyncCallback&lt;[DLPSandboxInfo](#dlpsandboxinfo)&gt; | Yes| Callback invoked to return the information about the sandbox application installed.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

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
  }); // Install a DLP sandbox application.
} catch (err) {
  console.error('installDLPSandbox error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.uninstallDLPSandbox

uninstallDLPSandbox(bundleName: string, userId: number, appIndex: number): Promise&lt;void&gt;

Uninstalls a DLP sandbox application for an application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name of the application.|
| userId | number | Yes| Current user ID, which is the OS account ID obtained by the account subsystem. The default super user ID is **100**.|
| appIndex | number | Yes| Index of the DLP sandbox application.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
try {
  dlpPermission.installDLPSandbox('com.ohos.note', dlpPermission.DLPFileAccess.READ_ONLY, 100, uri).then((res)=>{
    console.info('res', JSON.stringify(res));
    dlpPermission.uninstallDLPSandbox('com.ohos.note', 100, res.appIndex); // Uninstall a DLP sandbox application.
  }); // Install a DLP sandbox application.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.uninstallDLPSandbox

uninstallDLPSandbox(bundleName: string, userId: number, appIndex: number, callback: AsyncCallback&lt;void&gt;): void

Uninstalls a DLP sandbox application for an application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name of the application.|
| userId | number | Yes| Current user ID, which is the OS account ID obtained by the account subsystem. The default super user ID is **100**.|
| appIndex | number | Yes| DLP sandbox appliction index, which is the value returned after **installDLPSandbox** is successfully called.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the uninstallation result.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

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
  }); // Install a DLP sandbox application.
} catch (err) {
  console.error('uninstallDLPSandbox error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

## dlpPermission.on('uninstallDLPSandbox')

on(type: 'uninstallDLPSandbox', listener: Callback&lt;DLPSandboxState&gt;): void

Subscribes to a DLP sandbox uninstall event.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | 'uninstallDLPSandbox' | Yes| Event type. It has a fixed value of **uninstallDLPSandbox**, which indicates the DLP sandbox application uninstall event.|
| listener | Callback&lt;[DLPSandboxState](#dlpsandboxstate)&gt; | Yes| Callback invoked when a sandbox application is uninstalled.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.on('uninstallDLPSandbox', (info: dlpPermission.DLPSandboxState) => {
    console.info('uninstallDLPSandbox event', info.appIndex, info.bundleName)
  // Subscribe to the DLP sandbox application uninstall event.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## dlpPermission.off('uninstallDLPSandbox')

off(type: 'uninstallDLPSandbox', listener?: Callback&lt;DLPSandboxState&gt;): void

Unsubscribes from the DLP sandbox uninstall event.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | 'uninstallDLPSandbox' | Yes| Event type. It has a fixed value of **uninstallDLPSandbox**, which indicates the DLP sandbox application uninstall event.|
| listener | Callback&lt;[DLPSandboxState](#dlpsandboxstate)&gt; | No| Callback for the sandbox uninstall event. By default, this parameter is left blank, which unregisters all callbacks for the sandbox uninstall event.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.off('uninstallDLPSandbox', (info: dlpPermission.DLPSandboxState) => {
    console.info('uninstallDLPSandbox event', info.appIndex, info.bundleName)
  // Unsubscribe from the DLP sandbox uninstall events.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## DLPFile

Provides APIs for managing DLP files. A **DLPFile** instance indicates a DLP file object. You can call [generateDLPFile](#dlppermissiongeneratedlpfile) or [openDLPFile](#dlppermissionopendlpfile) to obtain a **DLPFile** instance.

### Attributes

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Type| Read Only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| dlpProperty | [DLPProperty](#dlpproperty) | No| Yes| Authorized user information.|

### addDLPLinkFile

addDLPLinkFile(linkFileName: string): Promise&lt;void&gt;

Adds a link file to the Filesystem in Userspace (FUSE). The link file is a virtual file mapped to the ciphertext in the FUSE. The read and write operations on the link file will be synchronized to the DLP file. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes| Name of the link file to add.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // Add a link file.
    dlpFile.closeDLPFile(); // Close the DLPFile instance.
  }); // Open a DLP file.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
fs.closeSync(file);
```

### addDLPLinkFile

addDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

Adds a link file to the FUSE. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes| Name of the link file to add.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link', async (err, res) => {
      if (err != undefined) {
        console.error('addDLPLinkFile error,', err.code, err.message);
        await dlpFile.closeDLPFile(); // Close the DLPFile instance.
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  }); // Open a DLP file.
} catch (err) {
  console.error('addDLPLinkFile error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

### stopFuseLink

stopFuseLink(): Promise&lt;void&gt;

Stops the read and write on the FUSE. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // Add a link file.
    dlpFile.stopFuseLink(); // Stop read/write on the link file.
    dlpFile.closeDLPFile(); // Close the DLPFile instance.
  }); // Open a DLP file.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
fs.closeSync(file);
```

### stopFuseLink

stopFuseLink(callback: AsyncCallback&lt;void&gt;): void

Stops the read and write on the FUSE. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // Add a link file.
    dlpFile.stopFuseLink(async (err, res) => {
      if (err != undefined) {
        console.error('stopFuseLink error,', err.code, err.message);
        await dlpFile.closeDLPFile(); // Close the DLPFile instance.
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  }); // Open a DLP file.
} catch (err) {
  console.error('stopFuseLink error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

### resumeFuseLink

resumeFuseLink(): Promise&lt;void&gt;

Resumes the read and write on the FUSE. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // Add a link file.
    dlpFile.stopFuseLink(); // Stop read/write on the link file.
    dlpFile.resumeFuseLink(); // Resume read/write on the link file.
    dlpFile.closeDLPFile(); // Close the DLPFile instance.
  }); // Open a DLP file.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
fs.closeSync(file);
```

### resumeFuseLink

resumeFuseLink(callback: AsyncCallback&lt;void&gt;): void

Resumes the read and write on the FUSE. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // Add a link file.
    dlpFile.stopFuseLink(); // Stop read/write on the link file.
    dlpFile.resumeFuseLink(async (err, res) => {
      if (err != undefined) {
        console.error('resumeFuseLink error,', err.code, err.message);
        await dlpFile.closeDLPFile(); // Close the DLPFile instance.
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  }); // Open a DLP file.
} catch (err) {
  console.error('resumeFuseLink error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

### replaceDLPLinkFile

replaceDLPLinkFile(linkFileName: string): Promise&lt;void&gt;

Replaces a link file. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes| Name of the link file to replace.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // Add a link file.
    dlpFile.stopFuseLink(); // Stop read/write on the link file.
    dlpFile.replaceDLPLinkFile('test_new.txt.dlp.link'); // Replace the link file.
    dlpFile.resumeFuseLink(); // Resume read/write on the link file.
    dlpFile.closeDLPFile(); // Close the DLPFile instance.
  }); // Open a DLP file.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
fs.closeSync(file);
```

### replaceDLPLinkFile

replaceDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

Replaces a link file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes| Name of the link file to replace.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // Add a link file.
    dlpFile.stopFuseLink(); // Stop read/write on the link file.
    dlpFile.replaceDLPLinkFile('test_new.txt.dlp.link', async (err, res) => { // Replace a link file.
      if (err != undefined) {
        console.error('replaceDLPLinkFile error,', err.code, err.message);
        await dlpFile.closeDLPFile(); // Close the DLPFile instance.
      } else {
        console.info('res', JSON.stringify(res));
        await dlpFile.resumeFuseLink(); // Resume read/write on the link file.
      }
    });
  }); // Open a DLP file.
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

### deleteDLPLinkFile

deleteDLPLinkFile(linkFileName: string): Promise&lt;void&gt;

Deletes a link file from the FUSE. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes| Name of the link file to delete.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // Add a link file.
    dlpFile.deleteDLPLinkFile('test.txt.dlp.link'); // Delete the link file.
    dlpFile.closeDLPFile(); // Close the DLPFile instance.
  }); // Open a DLP file.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
fs.closeSync(file);
```

### deleteDLPLinkFile

deleteDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a link file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes| Name of the link file to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.addDLPLinkFile('test.txt.dlp.link'); // Add a link file.
    dlpFile.deleteDLPLinkFile('test.txt.dlp.link', async (err, res) => { // Delete a link file.
      if (err != undefined) {
        console.error('deleteDLPLinkFile error,', err.code, err.message);
        await dlpFile.closeDLPFile(); // Close the DLPFile instance.
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  }); // Open a DLP file.
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

### recoverDLPFile

recoverDLPFile(plaintextFd: number): Promise&lt;void&gt;

Recovers the plaintext of a DLP file. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| plaintextFd | number | Yes| FD of the target plaintext file.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
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

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

let destFile = fs.openSync("destUri");
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.recoverDLPFile(destFile.fd); // Recover the plain text from the DLP file.
    dlpFile.closeDLPFile(); // Close the DLPFile instance.
  }); // Open a DLP file.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
fs.closeSync(file);
fs.closeSync(destFile);
```

### recoverDLPFile

recoverDLPFile(plaintextFd: number, callback: AsyncCallback&lt;void&gt;): void

Recovers the plaintext of a DLP file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| plaintextFd | number | Yes| FD of the target plaintext file.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
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

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

let destFile = fs.openSync("destUri");
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.recoverDLPFile(destFile.fd, async (err, res) => { // Recover the plaintext of a DLP file.
      if (err != undefined) {
        console.error('recoverDLPFile error,', err.code, err.message);
        await dlpFile.closeDLPFile(); // Close the DLPFile instance.
      } else {
        console.info('res', JSON.stringify(res));
      }
    });
  }); // Open a DLP file.
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
}
```

### closeDLPFile

closeDLPFile(): Promise&lt;void&gt;

Closes this **DLPFile** instance. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

> **NOTE**
>
> If a DLP file is no longer used, close the **dlpFile** instance to release the memory.

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.closeDLPFile(); // Close the DLPFile instance.
  }); // Open a DLP file.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
fs.closeSync(file);
```

### closeDLPFile

closeDLPFile(callback: AsyncCallback&lt;void&gt;): void

Closes this **DLPFile** instance. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

> **NOTE**
>
> If a DLP file is no longer used, close the **dlpFile** instance to release the memory.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | System service exception. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.closeDLPFile((err, res) => {// Close the DLP file.
      if (err != undefined) {
        console.error('closeDLPFile error,', err.code, err.message);
      } else {
        console.info('res', JSON.stringify(res));
      }
      fs.closeSync(file);
    });
  }); // Open a DLP file.
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
  fs.closeSync(file);
}
```

## dlpPermission.generateDLPFile

generateDLPFile(plaintextFd: number, ciphertextFd: number, property: DLPProperty): Promise&lt;DLPFile&gt;

Generates a DLP file, which is an encrypted file that can be accessed only by authorized users. The users can have the full control permission or read-only permission on the DLP file. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| plaintextFd | number | Yes| FD of the plaintext file to be encrypted.|
| ciphertextFd | number | Yes| FD of the encrypted file.|
| property | [DLPProperty](#dlpproperty) | Yes| Authorized user information, which includes the authorized user list, owner account, and contact account information.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[DLPFile](#dlpfile)&gt; | Promise used to return the result. If the operation is successful, a **DLPFile** instance is returned. Otherwise, **null** is returned.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
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

**Example**

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
    dlpFile.closeDLPFile(); // Close the DLPFile instance.
  }); // Generate a DLP file.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
fs.closeSync(file);
fs.closeSync(dlp);
```

## dlpPermission.generateDLPFile

generateDLPFile(plaintextFd: number, ciphertextFd: number, property: DLPProperty, callback: AsyncCallback&lt;DLPFile&gt;): void

Generates a DLP file, which is an encrypted file that can be accessed only by authorized users. The users can have the full control permission or read-only permission on the DLP file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| plaintextFd | number | Yes| FD of the plaintext file to be encrypted.|
| ciphertextFd | number | Yes| FD of the encrypted file.|
| property | [DLPProperty](#dlpproperty) | Yes| Authorized user information, which includes the authorized user list, owner account, and contact account information.|
| callback | AsyncCallback&lt;[DLPFile](#dlpfile)&gt; | Yes| Callback invoked to return the DLPFile instance created.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
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

**Example**

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
  dlpPermission.generateDLPFile(file.fd, dlp.fd, dlpProperty, (err, res) => { // Generate a DLP file.
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

Opens a DLP file. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| ciphertextFd | number | Yes| FD of the encrypted file.|
| appId | string | Yes| ID of the caller.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[DLPFile](#dlpfile)&gt; | Promise used to return the result. If the operation is successful, a **DLPFile** instance is returned. Otherwise, **null** is returned.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
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

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.closeDLPFile(); // Close the DLPFile instance.
  }); // Open a DLP file.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
fs.closeSync(file);
```

## dlpPermission.openDLPFile<sup>11+</sup>

openDLPFile(ciphertextFd: number, appId: string, callback: AsyncCallback&lt;DLPFile&gt;): void

Opens a DLP file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| ciphertextFd | number | Yes| FD of the encrypted file.|
| appId | string | Yes| ID of the caller.|
| callback | AsyncCallback&lt;[DLPFile](#dlpfile)&gt; | Yes| Callback invoked to return the **DLPFile** instance opened.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
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

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import fs from '@ohos.file.fs';
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fs.openSync(uri);
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let appId = "";
let bundleName = 'com.ohos.note';
let userId = 100;

try{
  bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
      console.error('error', err.code, err.message);
    } else {
      appId = data.signatureInfo.appId;
    }
  })
} catch (err) {
  console.error('error', err.code, err.message);
}

try {
  dlpPermission.openDLPFile(file.fd, appId, (err, res) => { // Open a DLP file.
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

Sets sandbox application configuration. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| configInfo | string | Yes| Sandbox application configuration to set. |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |
| 19100018 | Not authorized application. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.setSandboxAppConfig('configInfo'); // Set sandbox application configuration.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
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

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100007 | This API cannot be called by DLP sandbox applications. |
| 19100011 | System service exception. |
| 19100018 | Not authorized application. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.cleanSandboxAppConfig(); // Clean sandbox application configuration.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
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

For details about the error codes, see [DLP Service Error Codes](../errorcodes/errorcode-dlp.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. |
| 19100001 | Invalid parameter value. |
| 19100011 | System service exception. |
| 19100018 | Not authorized application. |

**Example**

```ts
import dlpPermission from '@ohos.dlpPermission';
import { BusinessError } from '@ohos.base';

try {
  dlpPermission.getSandboxAppConfig().then((res) => {
    console.info('res', JSON.stringify(res));
  }); // Obtain sandbox application configuration.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
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
| uri | string | Yes| No| URI of the DLP file.|
| lastOpenTime | number | Yes| No| Time when the file was last opened.|

## DLPManagerResult<sup>11+</sup>

Represents what is returned on DLP manager application startup.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| resultCode | number | Yes| No| Result code returned after the DLP manager application is started and exits.|
| want | [Want](js-apis-app-ability-want.md) | Yes| No| Data returned after the DLP manager application is started and exits.|

## DLPSandboxInfo

Represents the DLP sandbox information.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| appIndex | number | Yes| No| Index of the DLP sandbox application.|
| tokenID | number | Yes| No| Token ID of the DLP sandbox application.|

## DLPSandboxState

Represents the DLP sandbox identity information.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| bundleName | string | Yes| No| Bundle name of the application.|
| appIndex | number | Yes| No| Index of the DLP sandbox application.|

## RetentionSandboxInfo

Represents the sandbox retention information.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| appIndex | number | Yes| No| Index of the DLP sandbox application.|
| bundleName | string | Yes| No| Bundle name of the application.|
| docUris | Array&lt;string&gt; | Yes| No| URI list of the DLP files.|

## AccountType

Enumerates the types of authorized accounts.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Value| Description|
| -------- | -------- | -------- |
| CLOUD_ACCOUNT | 1 | Cloud account.|
| DOMAIN_ACCOUNT | 2 | Domain account.|

## AuthUser

Represents the user authorization information.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Type| Read Only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| authAccount | string | No| Yes| Account of the user who can access the DLP file.|
| authAccountType | [AccountType](#accounttype) | No| Yes| Type of the account.|
| dlpFileAccess | [DLPFileAccess](#dlpfileaccess) | No| Yes| Permission granted to the user.|
| permExpiryTime | number | No| Yes| Time when the authorization expires.|

## DLPProperty

Represents the authorization information.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name| Type| Read Only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| ownerAccount | string | No| Yes| Account of the owner who can set the permission.|
| ownerAccountID | string | No| Yes| Account ID of the owner.|
| ownerAccountType | [AccountType](#accounttype) | No| Yes| Account type of the owner.|
| authUserList | Array&lt;[AuthUser](#authuser)&gt; | No| No| List of users who are authorized to access the DLP file. By default, this parameter is left blank.|
| contactAccount | string | No| Yes| Account of the contact.|
| offlineAccess | boolean | No| Yes| Whether the file can be accessed offline.|
| everyoneAccessList | Array&lt;[DLPFileAccess](#dlpfileaccess)&gt; | No| No| Permission granted to everyone. This parameter is left blank by default.|
| expireTime<sup>11+</sup> | number | No| No| Timestamp when the file permission has expired. This parameter is left blank by default.|

## GatheringPolicyType

Enumerates the DLP sandbox gathering policy types. **GATHERING** allows the DLP files of the same permission type to be opened in a sandbox. For example, open different tab pages in a sandbox. **NON_GATHERING** allows different DLP files to be opened in different sandboxes.

**System capability**: SystemCapability.Security.DataLossPrevention

**System API**: This is a system API.

**Parameters**

| Name| Value| Description|
| -------- | -------- | -------- |
| GATHERING | 1 | Allows the DLP files of the same permission type to be opened in a sandbox. For example, the files of the same permission type can be opened in tab pages of a window.|
| NON_GATHERING | 2 | Allows the DLP files of different permission types to be opened in different sandboxes.|
