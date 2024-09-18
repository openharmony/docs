# @ohos.dlpPermission (DLP) (System API)

Data loss prevention (DLP) is a system solution provided to prevent data disclosure. The **dlpPermission** module provides APIs for cross-device file access management, encrypted storage, and access authorization.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.dlpPermission](js-apis-dlppermission.md).

## Modules to Import

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
```

## dlpPermission.getDLPGatheringPolicy

getDLPGatheringPolicy(): Promise&lt;GatheringPolicyType&gt;

Obtains the DLP sandbox gathering policy. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;[GatheringPolicyType](#gatheringpolicytype)&gt; | Promise used to return the DLP sandbox aggregation policy obtained. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[GatheringPolicyType](#gatheringpolicytype)&gt; | Yes | Callback invoked to return the result.<br>If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

Installs a DLP sandbox application for an application. This API uses a promise to return the sandbox application installed.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes | Bundle name of the application. |
| access | [DLPFileAccess](js-apis-dlppermission.md#dlpfileaccess) | Yes | Permission on the DLP file. |
| userId | number | Yes | Current user ID, which is the system account ID obtained by the account subsystem. The default super user ID is **100**. |
| uri | string | Yes | URI of the DLP file. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;[DLPSandboxInfo](#dlpsandboxinfo)&gt; | Promise used to return the information about the sandbox application installed. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes | Bundle name of the application. |
| access | [DLPFileAccess](js-apis-dlppermission.md#dlpfileaccess) | Yes | Permission on the DLP file. |
| userId | number | Yes | Current user ID, which is the system account ID obtained by the account subsystem. The default super user ID is **100**. |
| uri | string | Yes | URI of the DLP file. |
| callback | AsyncCallback&lt;[DLPSandboxInfo](#dlpsandboxinfo)&gt; | Yes | Callback invoked to return the information about the sandbox application installed. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes | Bundle name of the application. |
| userId | number | Yes | Current user ID, which is the system account ID obtained by the account subsystem. The default super user ID is **100**. |
| appIndex | number | Yes | DLP sandbox index. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes | Bundle name of the application. |
| userId | number | Yes | Current user ID, which is the system account ID obtained by the account subsystem. The default super user ID is **100**. |
| appIndex | number | Yes | DLP sandbox application index, which is the value returned after **installDLPSandbox** is successfully called. |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback invoked to return the uninstallation result. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | 'uninstallDLPSandbox' | Yes | Event type. It has a fixed value of **uninstallDLPSandbox**, which indicates the DLP sandbox application uninstall event. |
| listener | Callback&lt;[DLPSandboxState](#dlpsandboxstate)&gt; | Yes | Callback invoked when a sandbox application is uninstalled. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | 'uninstallDLPSandbox' | Yes | Event type. It has a fixed value of **uninstallDLPSandbox**, which indicates the DLP sandbox application uninstall event. |
| listener | Callback&lt;[DLPSandboxState](#dlpsandboxstate)&gt; | No | Callback for the sandbox uninstall event. By default, this parameter is left blank, which unregisters all callbacks for the sandbox uninstall event. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 19100001 | Invalid parameter value. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  dlpPermission.off('uninstallDLPSandbox', (info: dlpPermission.DLPSandboxState) => {
    console.info('uninstallDLPSandbox event', info.appIndex, info.bundleName)
  // Unsubscribe from the DLP sandbox uninstall events.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
```

## DLPFile

Provides APIs for managing DLP files. A **DLPFile** instance indicates a DLP file object. You can use [generateDLPFile](#dlppermissiongeneratedlpfile) or [openDLPFile](#dlppermissionopendlpfile11) to obtain a **DLPFile** instance.

### Attributes

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name | Type | Read Only | Mandatory | Description |
| -------- | -------- | -------- | -------- | -------- |
| dlpProperty | [DLPProperty](#dlpproperty) | No | Yes | Authorized user information. |

### addDLPLinkFile

addDLPLinkFile(linkFileName: string): Promise&lt;void&gt;

Adds a link file to the Filesystem in Userspace (FUSE). The link file is a virtual file mapped to the ciphertext in the FUSE. The read and write operations on the link file will be synchronized to the DLP file. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes | Name of the link file to add. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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
fileIo.closeSync(file);
```

### addDLPLinkFile

addDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

Adds a link file to the FUSE. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes | Name of the link file to add. |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback invoked to return the result. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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
fileIo.closeSync(file);
```

### stopFuseLink

stopFuseLink(callback: AsyncCallback&lt;void&gt;): void

Stops the read and write on the FUSE. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback invoked to return the result. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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
fileIo.closeSync(file);
```

### resumeFuseLink

resumeFuseLink(callback: AsyncCallback&lt;void&gt;): void

Resumes the read and write on the FUSE. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback invoked to return the result. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes| Name of the link file to replace.|

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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
fileIo.closeSync(file);
```

### replaceDLPLinkFile

replaceDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

Replaces a link file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes| Name of the link file to replace.|
| callback | AsyncCallback&lt;void&gt; | Yes | Callback invoked to return the result. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes| Name of the link file to delete.|

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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
fileIo.closeSync(file);
```

### deleteDLPLinkFile

deleteDLPLinkFile(linkFileName: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a link file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| linkFileName | string | Yes| Name of the link file to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes | Callback invoked to return the result. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | Yes | FD of the target plaintext file. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
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

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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

let destFile = fileIo.openSync("destUri");
try {
  dlpPermission.openDLPFile(file.fd, appId).then((dlpFile)=>{
    dlpFile.recoverDLPFile(destFile.fd); // Recover the plain text from the DLP file.
    dlpFile.closeDLPFile(); // Close the DLPFile instance.
  }); // Open a DLP file.
} catch (err) {
  console.error('error', (err as BusinessError).code, (err as BusinessError).message); // Error reported if the operation fails.
}
fileIo.closeSync(file);
fileIo.closeSync(destFile);
```

### recoverDLPFile

recoverDLPFile(plaintextFd: number, callback: AsyncCallback&lt;void&gt;): void

Recovers the plaintext of a DLP file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | Yes | FD of the target plaintext file. |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback invoked to return the result. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
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

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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

let destFile = fileIo.openSync("destUri");
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

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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
fileIo.closeSync(file);
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

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback invoked to return the result. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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
      fileIo.closeSync(file);
    });
  }); // Open a DLP file.
} catch (err) {
  console.error('error,', (err as BusinessError).code, (err as BusinessError).message);
  fileIo.closeSync(file);
}
```

## dlpPermission.generateDLPFile

generateDLPFile(plaintextFd: number, ciphertextFd: number, property: DLPProperty): Promise&lt;DLPFile&gt;

Generates a DLP file, which is an encrypted file that can be accessed only by authorized users. The users can have the full control permission or read-only permission on the DLP file. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | Yes | FD of the plaintext file to be encrypted. |
| ciphertextFd | number | Yes | FD of the encrypted file. |
| property | [DLPProperty](#dlpproperty) | Yes | Authorization information, which includes the authorized user list, owner account, and contact account information. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;[DLPFile](#dlpfile)&gt; | Promise used to return the result. If the operation is successful, a **DLPFile** instance is returned. Otherwise, **null** is returned. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential task error. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Credential authentication server error. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dlpUri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt";
let file = fileIo.openSync(uri);
let dlp = fileIo.openSync(dlpUri);
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
fileIo.closeSync(file);
fileIo.closeSync(dlp);
```

## dlpPermission.generateDLPFile

generateDLPFile(plaintextFd: number, ciphertextFd: number, property: DLPProperty, callback: AsyncCallback&lt;DLPFile&gt;): void

Generates a DLP file, which is an encrypted file that can be accessed only by authorized users. The users can have the full control permission or read-only permission on the DLP file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| plaintextFd | number | Yes | FD of the plaintext file to be encrypted. |
| ciphertextFd | number | Yes | FD of the encrypted file. |
| property | [DLPProperty](#dlpproperty) | Yes | Authorization information, which includes the authorized user list, owner account, and contact account information. |
| callback | AsyncCallback&lt;[DLPFile](#dlpfile)&gt; | Yes | Callback invoked to return the **DLPFile** instance created. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 19100001 | Invalid parameter value. |
| 19100002 | Credential task error. |
| 19100003 | Credential task time out. |
| 19100004 | Credential service error. |
| 19100005 | Credential authentication server error. |
| 19100009 | Failed to operate the DLP file. |
| 19100011 | The system ability works abnormally. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dlpUri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt";
let file = fileIo.openSync(uri);
let dlp = fileIo.openSync(dlpUri);
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
  fileIo.closeSync(file);
}
```

## dlpPermission.openDLPFile<sup>11+</sup>

openDLPFile(ciphertextFd: number, appId: string): Promise&lt;DLPFile&gt;

Opens a DLP file. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| ciphertextFd | number | Yes | FD of the encrypted file. |
| appId | string | Yes | ID of the caller. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;[DLPFile](#dlpfile)&gt; | Promise used to return the result. If the operation is successful, a **DLPFile** instance is returned. Otherwise, **null** is returned. |

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
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
| 19100011 | The system ability works abnormally. |
| 19100018 | Not authorized application. |
| 19100019 | The DLP file has expired. |
| 19100020 | No network connection. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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
fileIo.closeSync(file);
```

## dlpPermission.openDLPFile<sup>11+</sup>

openDLPFile(ciphertextFd: number, appId: string, callback: AsyncCallback&lt;DLPFile&gt;): void

Opens a DLP file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_DLP_FILE

**System capability**: SystemCapability.Security.DataLossPrevention

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| ciphertextFd | number | Yes | FD of the encrypted file. |
| appId | string | Yes | ID of the caller. |
| callback | AsyncCallback&lt;[DLPFile](#dlpfile)&gt; | Yes| Callback invoked to return the **DLPFile** instance opened.|

**Error codes**

For details about the error codes, see [DLP Service Error Codes](errorcode-dlp.md).

| ID | Error Message |
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
| 19100011 | The system ability works abnormally. |
| 19100018 | Not authorized application. |
| 19100019 | The DLP file has expired. |
| 19100020 | No network connection. |

**Example**

```ts
import { dlpPermission } from '@kit.DataProtectionKit';
import { fileIo } from '@kit.CoreFileKit';
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let uri = "file://docs/storage/Users/currentUser/Desktop/test.txt.dlp";
let file = fileIo.openSync(uri);
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
  fileIo.closeSync(file);
}
```

## DLPSandboxInfo

Represents the DLP sandbox information.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| appIndex | number | Yes | No | Index of the DLP sandbox application. |
| tokenID | number | Yes | No | Token ID of the DLP sandbox application. |

## DLPSandboxState

Represents the DLP sandbox identity information.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| bundleName | string | Yes | No | Bundle name of the application. |
| appIndex | number | Yes | No | Index of the DLP sandbox application. |

## AccountType

Enumerates the types of authorized accounts.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name | Value | Description |
| -------- | -------- | -------- |
| CLOUD_ACCOUNT | 1 | Cloud account. |
| DOMAIN_ACCOUNT | 2 | Domain account. |

## AuthUser

Represents the user authorization information.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name | Type | Read Only | Mandatory | Description |
| -------- | -------- | -------- | -------- | -------- |
| authAccount | string | No | Yes | Account of the user who can access the DLP file. |
| authAccountType | [AccountType](#accounttype) | No | Yes | Type of the account. |
| dlpFileAccess | [DLPFileAccess](js-apis-dlppermission.md#dlpfileaccess) | No | Yes | Permission granted to the user. |
| permExpiryTime | number | No | Yes | Time when the authorization expires. |

## DLPProperty

Represents the authorization information.

**System API**: This is a system API.

**System capability**: SystemCapability.Security.DataLossPrevention

| Name | Type | Read Only | Mandatory | Description |
| -------- | -------- | -------- | -------- | -------- |
| ownerAccount | string | No | Yes | Account of the owner who can set the permission. |
| ownerAccountID | string | No | Yes | Account ID of the owner. |
| ownerAccountType | [AccountType](#accounttype) | No | Yes | Account type of the owner. |
| authUserList | Array&lt;[AuthUser](#authuser)&gt; | No | No | List of users who are authorized to access the DLP file. By default, this parameter is left blank. |
| contactAccount | string | No| Yes| Account of the contact.|
| offlineAccess | boolean | No | Yes | Whether the file can be accessed offline. |
| everyoneAccessList | Array&lt;[DLPFileAccess](js-apis-dlppermission.md#dlpfileaccess)&gt; | No | No | Permission granted to everyone. This parameter is left blank by default. |
| expireTime<sup>11+</sup> | number | No | No | Timestamp when the file permission has expired. This parameter is left blank by default. |

## GatheringPolicyType

Enumerates the DLP sandbox gathering policy types. **GATHERING** allows the DLP files of the same permission type to be opened in a sandbox. For example, open different tab pages in a sandbox. **NON_GATHERING** allows different DLP files to be opened in different sandboxes.

**System capability**: SystemCapability.Security.DataLossPrevention

**System API**: This is a system API.

**Parameters**

| Name | Value | Description |
| -------- | -------- | -------- |
| GATHERING | 1 | Allows the DLP files of the same permission type to be opened in a sandbox. For example, the files of the same permission type can be opened in tab pages of a window. |
| NON_GATHERING | 2 | Allows the DLP files of different permission types to be opened in different sandboxes. |
