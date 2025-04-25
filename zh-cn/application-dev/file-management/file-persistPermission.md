# 授权持久化

## 场景介绍

应用通过Picker获取临时授权，临时授权在应用退出后或者设备重启后会清除。如果应用重启或者设备重启后需要直接访问之前已访问过的文件，则对文件进行持久化授权。

## 通过Picker获取临时授权并进行授权持久化

通过Picker选择文件或文件夹进行临时授权，然后应用可以按需通过文件分享接口（[ohos.fileshare](../reference/apis-core-file-kit/js-apis-fileShare.md)）进行持久化授权。

1.应用仅临时需要访问公共目录的数据，例如：通讯类应用需要发送用户的文件或者图片。应用调用Picker的([select](../reference/apis-core-file-kit/js-apis-file-picker.md#select-3))接口选择需要发送的文件或者图片，此时应用获取到是该文件的临时访问权限，应用重启或者设备重启后，再次访问该文件则仍需使用Picker进行文件选择。

2.应用如果需要长期访问某个文件或目录时，可以通过Picker选择文件或文件夹进行临时授权，然后利用persistPermission接口（[ohos.fileshare.persistPermission](../reference/apis-core-file-kit/js-apis-fileShare.md#filesharepersistpermission11)）对授权进行持久化（在授权方同意被持久化的情况下），例如：文档编辑类应用本次编辑完一个用户文件，期望在历史记录中可以直接选中打开，无需再拉起Picker进行选择授权。

可使用canIUse接口，确认设备是否具有以下系统能力：SystemCapability.FileManagement.AppFileService.FolderAuthorization。

```ts
if (!canIUse('SystemCapability.FileManagement.AppFileService.FolderAuthorization')) {
    console.error('this api is not supported on this device');
    return;
}
```

**需要权限**
ohos.permission.FILE_ACCESS_PERSIST，具体参考[访问控制-申请应用权限](../security/AccessToken/determine-application-mode.md)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { picker } from '@kit.CoreFileKit';
import { fileShare } from '@kit.CoreFileKit';

async function persistPermissionExample() {
    try {
        let DocumentSelectOptions = new picker.DocumentSelectOptions();
        let documentPicker = new picker.DocumentViewPicker();
        let uris = await documentPicker.select(DocumentSelectOptions);
        let policyInfo: fileShare.PolicyInfo = {
            uri: uris[0],
            operationMode: fileShare.OperationMode.READ_MODE,
        };
        let policies: Array<fileShare.PolicyInfo> = [policyInfo];
        fileShare.persistPermission(policies).then(() => {
            console.info("persistPermission successfully");
        }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
            console.error("persistPermission failed with error message: " + err.message + ", error code: " + err.code);
            if (err.code == 13900001 && err.data) {
                for (let i = 0; i < err.data.length; i++) {
                    console.error("error code : " + JSON.stringify(err.data[i].code));
                    console.error("error uri : " + JSON.stringify(err.data[i].uri));
                    console.error("error reason : " + JSON.stringify(err.data[i].message));
                }
            }
        });
    } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error('persistPermission failed with err: ' + JSON.stringify(err));
    }
}
```

> **注意**
>
> 1. 持久化授权文件信息建议应用在本地存储数据，供后续按需激活持久化文件。
> 2. 持久化授权的数据存储在系统的数据库中，应用或者设备重启后需要激活已持久化的授权才可以正常使用[激活持久化授权](#激活已经持久化的权限访问文件或目录)。
> 3. 持久化权限接口(仅在2in1上生效，可以使用canIUse接口进行校验能力是否可用)，且需要申请对应的权限。
> 4. 应用在卸载时会将之前的授权数据全部清除，重新安装后需要重新授权。

**备注**：C/C++持久化授权接口说明及开发指南具体参考：[OH_FileShare_PersistPermission持久化授权接口](native-fileshare-guidelines.md)。

3.可以通过revokePermission接口（[ohos.fileshare.revokePermission](../reference/apis-core-file-kit/js-apis-fileShare.md#filesharerevokepermission11)）对已持久化的文件取消授权，同时更新应用存储的数据以删除最近访问数据。

**需要权限**
ohos.permission.FILE_ACCESS_PERSIST，具体参考[访问控制-申请应用权限](../security/AccessToken/determine-application-mode.md)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { picker } from '@kit.CoreFileKit';
import { fileShare } from '@kit.CoreFileKit';

async function revokePermissionExample() {
    try {
        let uri = "file://docs/storage/Users/username/tmp.txt";
        let policyInfo: fileShare.PolicyInfo = {
            uri: uri,
            operationMode: fileShare.OperationMode.READ_MODE,
        };
        let policies: Array<fileShare.PolicyInfo> = [policyInfo];
        fileShare.revokePermission(policies).then(() => {
            console.info("revokePermission successfully");
        }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
            console.error("revokePermission failed with error message: " + err.message + ", error code: " + err.code);
            if (err.code == 13900001 && err.data) {
                for (let i = 0; i < err.data.length; i++) {
                    console.error("error code : " + JSON.stringify(err.data[i].code));
                    console.error("error uri : " + JSON.stringify(err.data[i].uri));
                    console.error("error reason : " + JSON.stringify(err.data[i].message));
                }
            }
        });
    } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error('revokePermission failed with err: ' + JSON.stringify(err));
    }
}
```

> **注意**
>
> 1. 示例中的URI来源自应用存储的持久化数据中。
> 2. 建议按照使用需求去激活对应的持久化权限，不要盲目的全量激活。
> 3. 持久化权限接口(仅在2in1上生效，可以使用canIUse接口进行校验能力是否可用)，且需要申请对应的权限。

**备注**：C/C++去持久化授权接口说明及开发指南具体参考：[OH_FileShare_RevokePermission去持久化授权接口](native-fileshare-guidelines.md)。

## 激活已经持久化的权限访问文件或目录

对于应用已经持久化的授权，应用每次启动时实际未加载到内存中，需要应用按需进行手动激活已持久化授权的权限，通过activatePermission接口（[ohos.fileshare.activatePermission](../reference/apis-core-file-kit/js-apis-fileShare.md#fileshareactivatepermission11)）对已经持久化授权的权限进行使能操作，否则已经持久化授权的权限仍存在不能使用的情况。

**需要权限**
ohos.permission.FILE_ACCESS_PERSIST，具体参考[访问控制-申请应用权限](../security/AccessToken/determine-application-mode.md)。

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { picker } from '@kit.CoreFileKit';
import { fileShare } from '@kit.CoreFileKit';

async function activatePermissionExample() {
    try {
        let uri = "file://docs/storage/Users/username/tmp.txt";
        let policyInfo: fileShare.PolicyInfo = {
            uri: uri,
            operationMode: fileShare.OperationMode.READ_MODE,
        };
        let policies: Array<fileShare.PolicyInfo> = [policyInfo];
        fileShare.activatePermission(policies).then(() => {
            console.info("activatePermission successfully");
        }).catch((err: BusinessError<Array<fileShare.PolicyErrorResult>>) => {
            console.error("activatePermission failed with error message: " + err.message + ", error code: " + err.code);
            if (err.code == 13900001 && err.data) {
                for (let i = 0; i < err.data.length; i++) {
                    console.error("error code : " + JSON.stringify(err.data[i].code));
                    console.error("error uri : " + JSON.stringify(err.data[i].uri));
                    console.error("error reason : " + JSON.stringify(err.data[i].message));
                    if (err.data[i].code == fileShare.PolicyErrorCode.PERMISSION_NOT_PERSISTED) {
                        //可以选择进行持久化后再激活。
                    }
                }
            }
        });
    } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error('activatePermission failed with err: ' + JSON.stringify(err));
    }
}
```

> **注意**
>
> 1. 示例中的URI来源自应用存储的持久化数据中。
> 2. 建议按照使用需求去激活对应的持久化权限，不要盲目的全量激活。
> 3. 如果激活失败显示未持久化的权限可以按照示例进行持久化。
> 4. 持久化权限接口(仅在2in1上生效可以使用canIUse接口进行校验能力是否可用)，且需要申请对应的权限。

**备注**：C/C++持久化授权激活接口说明及开发指南具体参考：[OH_FileShare_ActivatePermission持久化授权激活接口](native-fileshare-guidelines.md)。