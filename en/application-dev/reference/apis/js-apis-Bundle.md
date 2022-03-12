# Bundle Module (JavaScript SDK APIs)

## Modules to Import

```
import bundle from '@ohos.bundle';
```

## System Capabilities

SystemCapability.BundleManager.BundleFramework

## Required Permissions

|  Required Permissions| Permission Level| Description|
|-------| --------- | ---- |
| ohos.permission.GET_BUNDLE_INFO | normal | Permission to query information about the current application.|
| ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED| system_basic | Permission to query information about all applications.|
| ohos.permission.INSTALL_BUNDLE | system_core | Permission to install or uninstall applications.|

## bundle.getApplicationInfo

getApplicationInfo(bundleName: string, bundleFlags: number, userId: number): Promise\<ApplicationInfo>

Obtains the application information of the specified user based on a given bundle name in asynchronous mode. This method uses a promise to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | Yes  | Bundle name of the application.                                    |
| bundleFlags | number | Yes  | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.                    |

**Return value**

| Type     | Description|
| ----------- | -------- |
| Promise\<ApplicationInfo> | Promise used to return the application information.|

**Example**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 0;
let userId = 100;
bundle.getApplicationInfo(bundleName, bundleFlags, userId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.getApplicationInfo

getApplicationInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<ApplicationInfo>): void

Obtains the application information of the specified user based on a given bundle name in asynchronous mode. This method uses a callback to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name       | Type                           | Mandatory| Description                                                        |
| ----------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                          | Yes  | Bundle name of the application.                                    |
| bundleFlags | number                          | Yes  | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number                          | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.                    |
| callback    | AsyncCallback\<ApplicationInfo> | Yes  | Callback used to return the application information.              |

**Example**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 0;
let userId = 100;
bundle.getApplicationInfo(bundleName, bundleFlags, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```



## bundle.getAllBundleInfo

getAllBundleInfo(bundleFlag: BundleFlag, userId?: number): Promise<Array\<BundleInfo>>

Obtains the information of all available bundles in the system in asynchronous mode. This method uses a promise to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED

**Parameters**

| Name      | Type      | Mandatory| Description                                                       |
| ---------- | ---------- | ---- | ----------------------------------------------------------- |
| bundleFlag | BundleFlag | Yes  | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId     | number     | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0. |

**Return value**

| Type                       | Description                               |
| --------------------------- | ----------------------------------- |
| Promise<Array\<BundleInfo>> | Promise used to return the information of all available bundles.|

**Example**

```js
let bundleFlag = 0;
let userId = 100;
bundle.getAllBundleInfo(bundleFlag, userId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.getAllBundleInfo

getAllBundleInfo(bundleFlag: BundleFlag, callback: AsyncCallback<Array\<BundleInfo>>): void

Obtains the information of all available bundles in the system in asynchronous mode. This method uses a callback to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED

**Parameters**

| Name      | Type                             | Mandatory| Description                                                        |
| ---------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| bundleFlag | BundleFlag                        | Yes  | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| callback   | AsyncCallback<Array\<BundleInfo>> | Yes  | Callback used to return the information of all available bundles.      |

**Example**

```js
let bundleFlag = 0;
bundle.getAllBundleInfo(bundleFlag, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```


## bundle.getAllBundleInfo

getAllBundleInfo(bundleFlag: BundleFlag, userId: number, callback: AsyncCallback<Array\<BundleInfo>>): void

Obtains the information of all available bundles in the system in asynchronous mode. This method uses a callback to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED

**Parameters**

| Name      | Type                             | Mandatory| Description                                                        |
| ---------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| bundleFlag | BundleFlag                        | Yes  | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId     | number                            | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0. |
| callback   | AsyncCallback<Array\<BundleInfo>> | Yes  | Callback used to return the information of all available bundles.      |

**Example**

```js
let bundleFlag = 0;
let userId = 100;
bundle.getAllBundleInfo(bundleFlag, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
 })
```



## bundle.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, options?: BundleOptions): Promise\<BundleInfo>

Obtains the bundle information based on a given bundle name in asynchronous mode. This method uses a promise to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | Yes  | Bundle name.                                                        |
| bundleFlags | number | Yes  | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| options     | BundleOptions              | No  | Includes **userId** and **networkId**.                                   |

**Return value**

| Type                | Description                                      |
| -------------------- | ------------------------------------------ |
| Promise\<BundleInfo> | Promise used to return the bundle information.|

**Example**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 1;
let options = {
  "userId" : 100,
  "networkId" : null
};
bundle.getBundleInfo(bundleName, bundleFlags, options)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on a given bundle name in asynchronous mode. This method uses a callback to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name       | Type                      | Mandatory| Description                                                        |
| ----------- | -------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                     | Yes  | Bundle name.                                                        |
| bundleFlags | number                     | Yes  | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| callback    | AsyncCallback\<BundleInfo> | Yes  | Callback used to return the bundle information.                    |

**Example**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 1;
bundle.getBundleInfo(bundleName, bundleFlags, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```


## bundle.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, options: BundleOptions, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on a given bundle name in asynchronous mode. This method uses a callback to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name       | Type                      | Mandatory| Description                                                        |
| ----------- | -------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                     | Yes  | Bundle name.                                                        |
| bundleFlags | number                     | Yes  | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| options     | BundleOptions              | Yes  | Includes **userId** and **networkId**.                                   |
| callback    | AsyncCallback\<BundleInfo> | Yes  | Callback used to return the bundle information.                    |

**Example**

```js
let bundleName = "com.example.myapplication";
let bundleFlags = 1;
let options = {
  "userId" : 100,
  "networkId" : null
};
bundle.getBundleInfo(bundleName, bundleFlags, options, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```


## bundle.getAllApplicationInfo

getAllApplicationInfo(bundleFlags: number, userId: number): Promise<Array\<ApplicationInfo>>

Obtains the information about all applications of the specified user. This method uses a promise to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED

**Parameters**

| Name       | Type  | Mandatory| Description                                                  |
| ----------- | ------ | ---- | ------------------------------------------------------ |
| bundleFlags | number | Yes  | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.  |

**Return value**

| Type                            | Description                                            |
| -------------------------------- | ------------------------------------------------ |
| Promise<Array\<ApplicationInfo>> | Promise used to return the application information.|

**Example**

```js
let bundleFlags = 8;
let userId = 100;
bundle.getAllApplicationInfo(bundleFlags, userId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.getAllApplicationInfo

getAllApplicationInfo(bundleFlags: number, userId: number, callback: AsyncCallback<Array\<ApplicationInfo>>): void

Obtains the information about all installed applications of the specified user. This method uses a callback to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED

**Parameters**

| Name       | Type                                  | Mandatory| Description                                                  |
| ----------- | -------------------------------------- | ---- | ------------------------------------------------------ |
| bundleFlags | number                                 | Yes  | Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number                                 | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.   |
| callback    | AsyncCallback<Array\<ApplicationInfo>> | Yes  | Callback used to return the application information.        |

**Example**

```js
let bundleFlags = 8;
let userId = 100;
bundle.getAllApplicationInfo(bundleFlags, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```



## bundle.queryAbilityByWant

queryAbilityByWant(want: Want, bundleFlags: number, userId?: number): Promise<Array\<AbilityInfo>>

Obtains the ability information of the specified user based on a given want. This method uses a promise to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| want        | Want   | Yes  | Want that contains the bundle name.                          |
| bundleFlags | number | Yes  | Ability information to be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number | No  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.         |

**Return value**

| Type                        | Description                        |
| ---------------------------- | ---------------------------- |
| Promise\<Array\<AbilityInfo>>| Promise used to return the ability information.|

**Example**

```js
let bundleFlags = 0;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
bundle.queryAbilityByWant(want, bundleFlags, userId)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```



## bundle.queryAbilityByWant

queryAbilityByWant(want: Want, bundleFlags: number, userId: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void

Obtains the ability information of the specified user based on a given want. This method uses an asynchronous callback to return the result.

**Parameters**

| Name       | Type                              | Mandatory| Description                                                        |
| ----------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| want        | Want                               | Yes  | Want that contains the bundle name.                      |
| bundleFlags | number                             | Yes  | Ability information to be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number                             | Yes  | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.         |
| callback    | AsyncCallback<Array\<AbilityInfo>> | Yes  | Callback used to return the ability information.               |

**Example**

```js
let bundleFlags = 0;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
bundle.queryAbilityByWant(want, bundleFlags, userId, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.queryAbilityByWant

queryAbilityByWant(want: Want, bundleFlags: number, callback: AsyncCallback<Array<AbilityInfo>>): void

Obtains the ability information based on a given want. This method uses an asynchronous callback to return the result.

**Parameters**

| Name       | Type                              | Mandatory| Description                                                        |
| ----------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| want        | Want                               | Yes  | Want that contains the bundle name.                      |
| bundleFlags | number                             | Yes  | Ability information to be returned. The default value is **0**. The value must be greater than or equal to 0.|
| callback    | AsyncCallback<Array\<AbilityInfo>> | Yes  | Callback used to return the ability information.               |

**Example**

```js
let bundleFlags = 0;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
bundle.queryAbilityByWant(want, bundleFlags, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```

## bundle.getBundleInstaller

getBundleInstaller(): Promise<BundleInstaller>

Obtains the bundle installer in asynchronous mode. This method uses a promise to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**Return value**

| Type                    | Description                                               |
| ------------------------ | --------------------------------------------------- |
| Promise<BundleInstaller> | Promise used to return the bundle installer.|

**Example**

```js
let bundleFilePaths = ['/data/test.hap'];
let param = {
    userId : 100,
    installFlag : 1,
    isKeepData : false
};
bundle.getBundleInstaller()
.then((installerObject) => {
    console.info('Operation successful. ');
    installerObject.install(bundleFilePaths, param)
    .then((data) => {
        console.info('Operation successful. Data:' + JSON.stringify(data));
    }).catch((error) => {
        console.error('Operation failed. Cause: ' + JSON.stringify(error));
    })
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getBundleInstaller

getBundleInstaller(callback: AsyncCallback<BundleInstaller>): void;

Obtains the bundle installer in asynchronous mode. This method uses a callback to return the result.

**Required permissions**

ohos.permission.INSTALL_BUNDLE

**Parameters**

| Name    | Type                          | Mandatory| Description                                             |
| -------- | ------------------------------ | ---- | ------------------------------------------------- |
| callback | AsyncCallback<BundleInstaller> | Yes  | Callback used to return the bundle installer.|

**Example**

```js
let bundleFilePaths = ['/data/test.hap'];
let param = {
    userId : 100,
    installFlag : 1,
    isKeepData : false
};
bundle.getBundleInstaller((err, installerObject) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
    }
    console.info('Operation successful. Data:' + JSON.stringify(installerObject));
    installerObject.install(bundleFilePaths, param, (err, data) => {
        if (err) {
            console.error('Operation failed. Cause: ' + JSON.stringify(err));
        }
        console.info('Operation successful. Data:' + JSON.stringify(data));
    })
})
```


## bundle.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string): Promise\<Want>

Obtains the **Want** object that launches the specified application in asynchronous mode. This method uses a promise to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED

**Parameters**

| Name      | Type  | Mandatory| Description    |
| ---------- | ------ | ---- | -------- |
| bundleName | string | Yes  | Bundle name of the application.|

**Return value**
| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise\<Want> | Promise used to return the **Want** object.|

**Example**

```js
let bundleName = "com.example.myapplication";
bundle.getLaunchWantForBundle(bundleName)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, callback: AsyncCallback<Want>): void;

Obtains the **Want** object that launches the specified application in asynchronous mode. This method uses a callback to return the result.

**Required permissions**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED

**Parameters**

| Name      | Type  | Mandatory| Description    |
| ---------- | ------ | ---- | -------- |
| bundleName | string | Yes  | Bundle name of the application.|
| callback   | AsyncCallback\<Want> | Yes  | Callback used to return the **Want** object.|

**Example**

```js
let bundleName = "com.example.myapplication";
bundle.getLaunchWantForBundle(bundleName, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```


## bundle.getNameForUid

getNameForUid(uid: number): Promise\<string>

Obtains the bundle name based on a UID in asynchronous mode. This method uses a promise to return the result.

**Parameters**

| Name      | Type  | Mandatory| Description    |
| ---------- | ------ | ---- | -------- |
| uid | number | Yes  | UID based on which the bundle name is to obtain.|

**Return value**
| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise\<string> | Promise used to return the bundle name.|

**Example**

```js
let uid = 20010005;
bundle.getNameForUid(uid)
.then((data) => {
    console.info('Operation successful. Data: ' + JSON.stringify(data));
}).catch((error) => {
    console.error('Operation failed. Cause: ' + JSON.stringify(error));
})
```

## bundle.getNameForUid

getNameForUid(uid: number, callback: AsyncCallback<string>): void;

Obtains the bundle name based on a UID in asynchronous mode. This method uses a callback to return the result.

**Parameters**

| Name      | Type  | Mandatory| Description    |
| ---------- | ------ | ---- | -------- |
| uid | number | Yes  | UID based on which the bundle name is to obtain.|
| callback   | AsyncCallback\<string> | Yes  | Callback used to return the bundle name.|

**Example**

```js
let uid = 20010005;
bundle.getNameForUid(uid, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Operation successful. Data:' + JSON.stringify(data));
})
```


## ElementName

| Name       | Readable/Writable| Type  | Mandatory| Description                                                        |
| ----------- | -------- | ------ | ---- | ------------------------------------------------------------ |
| deviceId    | Read-only    | string | No  | ID of the device that runs the ability.                               |
| bundleName  | Read-only    | string | Yes  | Bundle name of the ability. If both **bundleName** and **abilityName** are specified in a **Want**, the **Want** can directly match the specified ability.|
| abilityName | Read-only    | string | Yes  | Name of the ability. If both **bundleName** and **abilityName** are specified in a **Want**, the **Want** can directly match the specified ability.|
| uri | Read-only    | string | No  | Resource ID.|
| shortName | Read-only    | string | No  | Short name of the **ElementName**.|

## InstallStatus

| Name         | Readable/Writable| Type            | Mandatory| Description                                                        |
| ------------- | -------- | ---------------- | ---- | ------------------------------------------------------------ |
| status        | Read-only    | InstallErrorCode | Yes  | Installation result code.<br>SUCCESS = 0<br>STATUS_INSTALL_FAILURE = 1<br>STATUS_INSTALL_FAILURE_ABORTED = 2,<br>STATUS_INSTALL_FAILURE_INVALID = 3<br>STATUS_INSTALL_FAILURE_CONFLICT = 4<br>STATUS_INSTALL_FAILURE_STORAGE = 5<br>STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br>STATUS_UNINSTALL_FAILURE = 7<br>STATUS_UNINSTALL_FAILURE_BLOCKED = 8<br>STATUS_UNINSTALL_FAILURE_ABORTED = 9<br>STATUS_UNINSTALL_FAILURE_CONFLICT = 10<br>STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br>STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br>STATUS_RECOVER_FAILURE_INVALID = 0x0D<br>STATUS_ABILITY_NOT_FOUND = 0x40<br>STATUS_BMS_SERVICE_ERROR = 0x41<br>STATUS_FAILED_NO_SPACE_LEFT = 0x42<br>STATUS_GRANT_REQUEST_PERMISSIONS_FAILED = 0x43<br>STATUS_INSTALL_PERMISSION_DENIED = 0x44<br>STATUS_UNINSTALL_PERMISSION_DENIED = 0x45 |

## BundleFlag

Enumerates the bundle flags.

| Name              | Default Value| Description  |
| ------ | ------ | ------ |
| GET_BUNDLE_DEFAULT | 0x00000000 | Obtains the default application information.|
| GET_BUNDLE_WITH_ABILITIES | 0x00000001 | Obtains the bundle information with the ability information.|
| GET_ABILITY_INFO_WITH_PERMISSION | 0x00000002 | Obtains the ability information with the permission information.|
| GET_ABILITY_INFO_WITH_APPLICATION | 0x00000004 | Obtains the ability information with the application information.|
| GET_APPLICATION_INFO_WITH_PERMISSION | 0x00000008 | Obtains the application information with the permission information.|
| GET_BUNDLE_WITH_REQUESTED_PERMISSION | 0x00000010 | Obtains the bundle information with the information about the required permissions.|
| GET_ABILITY_INFO_WITH_METADATA | 0x00000020 | Obtains the ability metadata information.|
| GET_APPLICATION_INFO_WITH_METADATA | 0x00000040 | Obtains the application metadata information.|
| GET_ABILITY_INFO_SYSTEMAPP_ONLY | 0x00000080 | Obtains only the ability information with information about system applications.|
| GET_ABILITY_INFO_WITH_DISABLE | 0x00000100 | Obtains information about disabled abilities.|
| GET_APPLICATION_INFO_WITH_DISABLE | 0x00000200 | Obtains information about disabled applications.|
| GET_ALL_APPLICATION_INFO | 0xFFFF0000 | Obtains all application information.|

## BundleOptions

Describes the bundle options.

| Name              | Type| Readable| Writable| Description|
| ------ | ------ | ------ | ------ | ------ |
| userId | number | Yes| Yes| User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| networkId | string | Yes| Yes| Network ID. The default value is **null**.|

## BundleInfo

Describes the application bundle information.

| Name              | Type| Readable| Writable| Description|
| ------ | ------ | ------ | ------ | ------ |
| name                     | string                     | Yes  | No  | Bundle name.                              |
| type                     | string                     | Yes  | No  | Bundle type.                                |
| appId                    | string                     | Yes  | No  | ID of the application to which the bundle belongs.                      |
| uid                      | number                     | Yes  | No  | UID of the application to which the bundle belongs.                     |
| installTime              | number                     | Yes  | No  | Time when the HAP file is installed.                             |
| updateTime               | number                     | Yes  | No  | Time when the HAP file is updated.                             |
| appInfo                  | ApplicationInfo        | Yes  | No  | Application configuration information.                        |
| abilityInfo              | Array<AbilityInfo>         | Yes  | No  | Ability configuration information.                         |
| reqPermissions           | Array<string>              | Yes  | No  | Array of the permissions to request from the system.          |
| reqPermissionDetails     | Array<ReqPermissionDetail> | Yes  | No  | Detailed information of the permissions to request from the system.|
| vendor                   | string                     | Yes  | No  | Vendor of the bundle.                            |
| versionCode              | number                     | Yes  | No  | Version number of the bundle.                            |
| versionName              | string                     | Yes  | No  | Version description of the bundle.                  |
| compatibleVersion        | number                     | Yes  | No  | Earliest SDK version required for running the bundle.           |
| targetVersion            | number                     | Yes  | No  | Latest SDK version required for running the bundle.             |
| isCompressNativeLibs     | boolean                    | Yes  | No  | Whether to compress the native library of the bundle. The default value is **true**.        |
| hapModuleInfo            | Array<HapModuleInfo>       | Yes  | No  | Module configuration information.                            |
| entryModuleName          | string                     | Yes  | No  | Name of the entry module.                           |
| cpuAbi                   | string                     | Yes  | No  | cpuAbi information of the bundle.                        |
| isSilentInstallation     | string                     | Yes  | No  | Whether to install the bundle in silent mode.                          |
| minCompatibleVersionCode | number                     | Yes  | No  | Earliest version compatible with the bundle in the distributed scenario.        |
| entryInstallationFree | boolean | Yes| No| Whether installation-free is supported for the entry.|
| reqPermissionStates | Array<number> | Yes| No| Permission grant state.|

## ApplicationInfo

Describes the application information.

| Name              | Type| Readable| Writable| Description|
| ------ | ------ | ------ | ------ | ------ |
| name             | string        | Yes  | No  | Application name.                            |
| description      | string        | Yes  | No  | Application description.                            |
| descriptionId    | number        | Yes  | No  | Application description ID.                          |
| systemApp        | boolean       | Yes  | No  | Whether the application is a system application. The default value is **false**.       |
| enabled          | boolean       | Yes  | No  | Whether the application is enabled. The default value is **true**.      |
| label            | string        | Yes  | No  | Application label.                            |
| labelId          | string        | Yes  | No  | Application label ID.                          |
| icon             | string        | Yes  | No  | Application icon.                            |
| iconId           | string        | Yes  | No  | Application icon ID.                          |
| process          | string        | Yes  | No  | Process in which this application runs. If this parameter is not set, the bundle name is used by default.|
| supportedModes   | number        | Yes  | No  | Running modes supported by the application.                    |
| moduleSourceDirs | Array<string> | Yes  | No  | Relative paths for storing application resources.              |
| permissions      | Array<string> | Yes  | No  | Permissions required for accessing the application.                    |
| moduleInfos | Array<ModuleInfo> | Yes  | No  | Application module information.                        |
| entryDir         | string        | Yes  | No  | Path for storing application files.                    |
| customizeData    | Map<string, Array<CustomizeData>> | Yes  | Yes  | Custom data of the application.                      |
| codePath | string | Yes| No| Installation directory of the application.|
| metaData | Map<string, Array<CustomizeData>> | Yes| No| Custom metadata of the application.|
| removable | boolean | Yes| No| Whether the application is removable.|
| accessTokenId | number | Yes| No| Access token ID of the application.|
| uid | number | Yes| No| UID of the application.|

## ModuleInfo

Describes the application module information.

| Name              | Type| Readable| Writable| Description|
| ------ | ------ | ------ | ------ | ------ |
| moduleName      | string | Yes  | No  | Module name.|
| moduleSourceDir | string | Yes  | No  | Installation directory.|

## CustomizeData

Describes the custom metadata.

| Name | Type  | Readable| Writable| Description            |
| ----- | ------ | ---- | ---- | ---------------- |
| name  | string | Yes  | Yes  | Custom metadata name.|
| value | string | Yes  | Yes  | Custom metadata value.  |
| extra | string | Yes  | Yes  | Custom resources.      |


## HapModuleInfo

Describes the HAP module information.

| Name              | Type| Readable| Writable| Description|
| ------ | ------ | ------ | ------ | ------ |
| name             | string        | Yes  | No  | Module name.          |
| description      | string        | Yes  | No  | Module description.      |
| descriptionId    | number        | Yes  | No  | Module description ID.        |
| icon             | string        | Yes  | No  | Module icon.          |
| label            | string        | Yes  | No  | Module label.          |
| labelId          | number        | Yes  | No  | Module label ID.        |
| iconId           | number        | Yes  | No  | Module icon ID.        |
| backgroundImg    | string        | Yes  | No  | Module background image.      |
| supportedModes   | number        | Yes  | No  | Modes supported by the module.    |
| reqCapabilities  | Array<string> | Yes  | No  | Capabilities required for module running.|
| deviceTypes      | Array<string> | Yes  | No  | An array of supported device types.|
| abilityInfo      | Array<AbilityInfo> | Yes  | No  | Ability information.       |
| moduleName       | string        | Yes  | No  | Module name.            |
| mainAbilityName  | string        | Yes  | No  | Name of the entry ability.   |
| installationFree | boolean       | Yes  | No  | Whether installation-free is supported.    |
| mainElementName | string | Yes| No| Information about the entry ability.|

## ReqPermissionDetail

Describes the detailed information of the permissions to request from the system.

| Name              | Type| Readable| Writable| Description|
| ------ | ------ | ------ | ------ | ------ |
| name      | string    | Yes  | Yes  | Name of the permission to request.  |
| reason    | string    | Yes  | Yes  | Reason for requesting the permission.  |
| usedScene | UsedScene | Yes| Yes| Application scenario and timing for using the permission.|

## UsedScene

Describes the application scenario and timing for using the permission.

| Name              | Type| Readable| Writable| Description|
| ------ | ------ | ------ | ------ | ------ |
| abilities | Array<string> | Yes  | Yes  | Abilities that use the permission.|
| when      | string        | Yes  | Yes  | Time when the permission is used.         |


## AbilityInfo

Describes ability information.

| Name              | Type| Readable| Writable| Description|
| ------ | ------ | ------ | ------ | ------ |
| bundleName         | string                                                       | Yes  | No  | Application bundle name.                                 |
| name               | string                                                       | Yes  | No  | Ability name.                              |
| label              | string                                                       | Yes  | No  | Ability name visible to users.                  |
| description        | string                                                       | Yes  | No  | Ability description.                            |
| icon               | string                                                       | Yes  | No  | Index of the ability icon resource file.                |
| descriptionId      | number                                                       | Yes  | No  | Ability description ID.                          |
| iconId             | number                                                       | Yes  | No  | Ability icon ID.                          |
| moduleName         | string                                                       | Yes  | No  | Name of the HAP file to which the ability belongs.                 |
| process            | string                                                       | Yes  | No  | Process in which this ability runs. If this parameter is not set, the bundle name is used by default.|
| targetAbility      | string                                                       | Yes  | No  | Target ability that this ability alias points to.             |
| backgroundModes    | number                                                       | Yes  | No  | Background service mode of the ability.                       |
| isVisible          | boolean                                                      | Yes  | No  | Whether the ability can be called by other applications.        |
| formEnabled        | boolean                                                      | Yes  | No  | Whether the ability provides the service widget capability.              |
| type               | AbilityType | Yes  | No  | Ability type.                              |
| orientation        | DisplayOrientation | Yes  | No  | Ability display orientation.                        |
| launchMode         | LaunchMode | Yes  | No  | Ability launch mode.                        |
| permissions        | Array<string>                                                | Yes  | No  | Permissions required for other applications to call the ability.|
| deviceTypes        | Array<string>                                                | Yes  | No  | Device types supported by the ability.                    |
| deviceCapabilities | Array<string>                                                | Yes  | No  | Device capabilities required for the ability.                    |
| readPermission     | string                                                       | Yes  | No  | Permission required for reading the ability data.                |
| writePermission    | string                                                       | Yes  | No  | Permission required for writing data to the ability.                |
| applicationInfo    | ApplicationInfo | Yes  | No  | Application configuration information.                       |
| formEntity         | number                                                       | Yes  | No  | Area where the ability form can be displayed.                           |
| minFormHeight      | number                                                       | Yes  | No  | Minimum height of the ability form.                        |
| defaultFormHeight  | number                                                       | Yes  | No  | Default height of the ability form.                        |
| minFormWidth       | number                                                       | Yes  | No  | Minimum width of the ability form.                        |
| defaultFormWidth   | number                                                       | Yes  | No  | Default width of the ability form.                        |
| uri                | string                                                       | Yes  | No  | URI of the ability.       |
| customizeData      | Map<string, Array<CustomizeData>> | Yes  | Yes  | Custom data of the ability.                      |
| labelId            | number                                                       | Yes  | No  | Ability label ID.                          |
| subType            | AbilitySubType | Yes  | No  | Subtype of the template that can be used by the ability.          |
| metaData | Array<Metadata> | Yes| No| Custom metadata of the ability.|
| enabled | boolean | Yes| No| Whether the ability is enabled.|

## AbilityType

Describes the ability type.

| Name   | Type| Description                       |
| ------- | ---- | --------------------------- |
| UNKNOWN | None  | Unknown ability type.            |
| PAGE    | None  | Ability that has a UI.        |
| SERVICE | None  | Ability that does not have a UI.          |
| DATA    | None  | Ability that is used to provide data access services.|

## DisplayOrientation

Describes the display orientation.

| Name         | Type| Description                    |
| ------------- | ---- | ------------------------ |
| UNSPECIFIED   | None  | The system automatically determines the display orientation.        |
| LANDSCAPE     | None  | Landscape orientation.          |
| PORTRAIT      | None  | Portrait orientation.          |
| FOLLOW_RECENT | None  | The page ability orientation is the same as that of the nearest ability in the stack.|

## LaunchMode

Describes the launch mode.

| Name       | Type| Description               |
| ----------- | ---- | ------------------- |
| UNSPECIFIED | 0    | The ability has only one instance.|
| STANDARD    | 1    | The ability can have multiple instances.  |

## AbilitySubType

Describes the ability subtype.

| Name       | Type| Description                         |
| ----------- | ---- | ----------------------------- |
| UNSPECIFIED | 0    | Undefined ability subtype.          |
| CA          | 1    | Ability that has a UI.|
