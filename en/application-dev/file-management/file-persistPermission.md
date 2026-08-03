# Persisting Temporary Permissions

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie; @hongjin-li_admin-->
<!--Designer: @chenxi0605; @JerryH1011-->
<!--Tester: @leiyuqian; @zsyztt; @yue-ye2-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=a4bb221ea8dcccf781d5793faa6c8f62723e3e12 translatedAt=2026-08-01T07:26:55.705Z pushedAt=2026-08-01T09:24:22.084Z -->

## When to Use

An app can obtain temporary authorization through Picker by [selecting a file](select-user-file.md) or [saving a file](save-user-file.md). The temporary authorization is cleared after the app exits or the device restarts. If the app needs to directly access previously accessed files after restarting or after a device restart, persistent authorization is required for the files.

## Persisting a Temporary Permission Granted by Picker

When you select a file or folder through Picker for temporary authorization, the URI obtained has only **temporary read/write permission**. The app can subsequently persist the authorization through the file sharing API ([ohos.fileshare](../reference/apis-core-file-kit/js-apis-fileShare.md)) as needed.

1. When an app only temporarily needs to access data in a public directory, for example, a communication app needs to send a user file or image, the app calls the Picker's [select()](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3) API to select the file or image to send. In this case, the app obtains temporary access permission to the file. After the app restarts or the device restarts, the app must use Picker again to select the file for access.

2. Sometimes, an app needs to access a file or directory multiple times. For example, after editing a user file, a file editor app needs to select and open the file directly from the history records. In this case, you can use Picker to select the file, and use [ohos.fileshare.persistPermission](../reference/apis-core-file-kit/js-apis-fileShare.md#filesharepersistpermission11) to persist the temporary permission granted by Picker.

Before persisting a temporary permission, ensure that:<br>The device must have the system capability SystemCapability.FileManagement.AppFileService.FolderAuthorization. You can use **canIUse()** to check whether the device has the required system capability.

```ts
if (!canIUse('SystemCapability.FileManagement.AppFileService.FolderAuthorization')) {
    console.error('this api is not supported on this device');
    return;
}
```

**Required Permissions**<br>
ohos.permission.FILE_ACCESS_PERSIST. For details about how to request the permission, see [Workflow for Requesting Permissions](../security/AccessToken/determine-application-mode.md).

**Example**

<!-- @[persist_permission_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/PersistPermission/entry/src/main/ets/persistpermission/PersistPermission.ets) -->    

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { picker } from '@kit.CoreFileKit';
import { fileShare } from '@kit.CoreFileKit';

export async function persistPermissionExample() {
  try {
    // ...
    let documentSelectOptions = new picker.DocumentSelectOptions();
    let documentPicker = new picker.DocumentViewPicker();
    let uris = await documentPicker.select(documentSelectOptions);
    // Multiple permissions can be granted in combination. For example, for read and write permissions, use fileShare.OperationMode.READ_MODE | fileShare.OperationMode.WRITE_MODE.
    // Note: Persistent authorization can only be performed on obtained temporary permissions. Otherwise, an error is reported.
    let policyInfo: fileShare.PolicyInfo = {
      uri: uris[0],
      operationMode: fileShare.OperationMode.READ_MODE,
    };
    let policies: fileShare.PolicyInfo[] = [policyInfo];
    fileShare.persistPermission(policies).then(() => {
      console.info('persistPermission successfully');
    }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
      console.error('persistPermission failed with error message: ' + err.message + ', error code: ' + err.code);
      if (err.code == 13900001 && err.data) {
        for (let i = 0; i < err.data.length; i++) {
          console.error('error code : ' + JSON.stringify(err.data[i].code));
          console.error('error uri : ' + JSON.stringify(err.data[i].uri));
          console.error('error reason : ' + JSON.stringify(err.data[i].message));
        }
      }
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`persistPermission failed with err, Error code: ${err.code}, message: ${err.message}`);
  }
}
```

> **NOTE**
>
> 1. It is recommended that the app store the persistent authorization file information locally for subsequent activation of persistent files as needed.
> 2. The persistent authorization data is stored in the system database. After the app or device restarts, you must activate the persisted authorization before using it. For details, see [Activating Persisted Permissions to Access Files or Directories](#activating-a-persistent-permission-for-accessing-a-file-or-folder).
> 3. For the persistent permission API, you can use the **canIUse** API to check whether the capability is available, and you need to request the corresponding permission.
> 4. When the app is uninstalled, all previous authorization data is cleared. After reinstallation, re-authorization is required.
> 5. You can only persist a temporary permission that has already been obtained. Otherwise, an error is reported.

For details about how to persist a temporary permission using C/C++ APIs, see [OH_FileShare_PersistPermission](native-fileshare-guidelines.md).

You can use [ohos.fileshare.revokePermission](../reference/apis-core-file-kit/js-apis-fileShare.md#filesharerevokepermission11) to revoke the persistent permission from a file, and update the data stored in the application to delete the file URI from the recently accessed data.

**Required Permissions**<br>
ohos.permission.FILE_ACCESS_PERSIST. For details about how to request the permission, see [Workflow for Requesting Permissions](../security/AccessToken/determine-application-mode.md).

**Example**

<!-- @[revoke_permission_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/PersistPermission/entry/src/main/ets/persistpermission/PersistPermission.ets) -->    

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { picker } from '@kit.CoreFileKit';
import { fileShare } from '@kit.CoreFileKit';

// ...
export async function revokePermissionExample() {
  try {
    let uri = 'file://docs/storage/Users/username/tmp.txt';
    // Multiple permissions can be combined for cancellation. For example, read and write permissions can use fileShare.OperationMode.READ_MODE | fileShare.OperationMode.WRITE_MODE.
    // Note: You can only deauthorize persistent permissions that have already been obtained. Otherwise, an error will be reported.
    let policyInfo: fileShare.PolicyInfo = {
      uri: uri,
      operationMode: fileShare.OperationMode.READ_MODE,
    };
    let policies: fileShare.PolicyInfo[] = [policyInfo];
    fileShare.revokePermission(policies).then(() => {
      console.info('revokePermission successfully');
    }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
      console.error('revokePermission failed with error message: ' + err.message + ', error code: ' + err.code);
      if (err.code == 13900001 && err.data) {
        for (let i = 0; i < err.data.length; i++) {
          console.error('error code : ' + JSON.stringify(err.data[i].code));
          console.error('error uri : ' + JSON.stringify(err.data[i].uri));
          console.error('error reason : ' + JSON.stringify(err.data[i].message));
        }
      }
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`revokePermission failed with err, Error code: ${err.code}, message: ${err.message}`);
  }
}
```

> **NOTE**
>
> 1. The URI in the example comes from the persistent data stored by the app.
> 2. You can only revoke a persistent permission that has already been obtained. It is recommended that you revoke the corresponding persistent permission based on your usage requirements.
> 3. For the persistent permission API, you can use the **canIUse** API to check whether the capability is available, and you need to request the corresponding permission.

For details about how to revoke a persistent permission using C/C++ APIs, see [OH_FileShare_RevokePermission](native-fileshare-guidelines.md).

## Activating a Persistent Permission for Accessing a File or Folder

Each time an application is started, its persistent permissions have not been loaded to the memory. To make a persistent permission still valid after the application is restarted, use [ohos.fileshare.activatePermission](../reference/apis-core-file-kit/js-apis-fileShare.md#fileshareactivatepermission11) to activate the permission.

**Required Permissions**<br>
ohos.permission.FILE_ACCESS_PERSIST. For details about how to request the permission, see [Workflow for Requesting Permissions](../security/AccessToken/determine-application-mode.md).

**Example**

<!-- @[activate_permission_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/PersistPermission/entry/src/main/ets/persistpermission/PersistPermission.ets) -->    

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { picker } from '@kit.CoreFileKit';
import { fileShare } from '@kit.CoreFileKit';

// ...
export async function activatePermissionExample() {
  try {
    let uri = 'file://docs/storage/Users/username/tmp.txt';
    // Multiple permissions can be activated in combination. For example, for read and write permissions, use fileShare.OperationMode.READ_MODE | fileShare.OperationMode.WRITE_MODE.
    // Note: Activation of persistent authorization can only be performed on permissions that have already been persisted. Otherwise, an error will be reported.
    let policyInfo: fileShare.PolicyInfo = {
      uri: uri,
      operationMode: fileShare.OperationMode.READ_MODE,
    };
    let policies: fileShare.PolicyInfo[] = [policyInfo];
    fileShare.activatePermission(policies).then(() => {
      console.info('activatePermission successfully');
    }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
      console.error('activatePermission failed with error message: ' + err.message + ', error code: ' + err.code);
      if (err.code == 13900001 && err.data) {
        for (let i = 0; i < err.data.length; i++) {
          console.error('error code : ' + JSON.stringify(err.data[i].code));
          console.error('error uri : ' + JSON.stringify(err.data[i].uri));
          console.error('error reason : ' + JSON.stringify(err.data[i].message));
          if (err.data[i].code == fileShare.PolicyErrorCode.PERMISSION_NOT_PERSISTED) {
          // You can choose to persist first and then activate.
          }
        }
      }
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`activatePermission failed with err, Error code: ${err.code}, message: ${err.message}`);
  }
}
```

> **NOTE**
>
> 1. The URI in the example comes from the persistent data stored by the app.
> 2. It is recommended that you activate the corresponding persistent permissions based on your usage requirements. Do not blindly activate all of them.
> 3. If activation fails and indicates that the permission is not persisted, you can persist it by following the example.
> 4. For the persistent permission API, you can use the **canIUse** API to check whether the capability is available, and you need to request the corresponding permission.

For details about how to activate a persistent permission using C/C++ APIs, see [OH_FileShare_ActivatePermission](native-fileshare-guidelines.md).

## Persistent Permission Retention Configuration

Starting from API version 24, the system supports the persistent permission retention capability. When the app is uninstalled, the persistent permissions are retained based on the **ohos.fileshare.supportPreservePersistentPermission** tag. When the app is reinstalled, the previously retained persistent permissions are restored.

### Configuration Method

You can configure the ohos.fileshare.supportPreservePersistentPermission tag in the metadata under the module tag in the app module-level configuration file [src/main/module.json5](../quick-start/module-configuration-file.md) to enable the persistent permission retention capability.

**metadata Tag Configuration Example**

``` JSON5
{
  "module": {
    // ...
    "metadata": [
      {
        "name": "ohos.fileshare.supportPreservePersistentPermission"
      }
    ],
    // ...
  }
}
```

**Description of the ohos.fileshare.supportPreservePersistentPermission Tag**

| Name | Description | Type | Mandatory |
| -------- | -------- | -------- | -------- |
| name | Identifies the metadata name. The value is fixed as **ohos.fileshare.supportPreservePersistentPermission**. | String | Yes |