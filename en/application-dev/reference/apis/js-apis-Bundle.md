# Bundle Module (JavaScript SDK APIs)

## Modules to Import

```
import bundle from '@ohos.bundle';
```

## System Capabilities

SystemCapability.BundleManager.BundleFramework

## Required Permissions

None

## bundle.getApplicationInfo

getApplicationInfo(bundleName: string, bundleFlags: number, userId: number): Promise\<ApplicationInfo>

Obtains the application information of the specified user based on a given bundle name in asynchronous mode. This method uses a promise to return the result.

**Permission required**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | Yes| Bundle name of the application.|
| bundleFlags | number | Yes| Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number | Yes| User ID.|

**Return value**

| Type| Description|
| ----------- | -------- |
| Promise\<ApplicationInfo> | Promise used to return the application information.|

**Example**

```js
bundle.getApplicationInfo('com.example.myapplicationInstall', 8, 0).then((data) => {
  console.info("name: for begin");
  console.info("name:" + data.name);
  console.info("bundleName:" + data.bundleName);
  console.info("description:" + data.description);
  console.info("descriptionId:" + data.descriptionId);
  console.info("iconPath:" + data.iconPath);
  console.info("iconId:" + data.iconId);
  console.info("label:" + data.label);
  console.info("labelId:" + data.labelId);
  console.info("deviceId:" + data.deviceId);
  console.info("signatureKey:" + data.signatureKey);
  console.info("process:" + data.process);
  console.info("isSystemApp:" + data.isSystemApp);
  console.info("isLauncherApp:" + data.isLauncherApp);
  console.info("supportedModes:" + data.supportedModes);

  console.info('getApplicationInfo permissions length [' + data.permissions.length + ']');
  for (var j = 0; j < data.permissions.length; j++) {
      console.info("permissions[" + j + "]:" + data.permissions[j]);
  }
  console.info('getApplicationInfo moduleSourceDirs length [' + data.moduleSourceDirs.length + ']');
  for (var j = 0; j < data.moduleSourceDirs.length; j++) {
      console.info("moduleSourceDirs[" + j + "]:" + data.moduleSourceDirs[j]);
  }
  console.info('getApplicationInfo moduleInfos length [' + data.moduleInfos.length + ']');
  for (var j = 0; j < data.moduleInfos.length; j++) {
      console.info("moduleInfos[" + j + "]moduleName:" + data.moduleInfos[j].moduleName);
      console.info("moduleInfos[" + j + "]moduleSourceDir:" + data.moduleInfos[j].moduleSourceDir);
  }
  console.info("entryDir:" + data.entryDir);
  console.info("codePath:" + data.codePath);
  console.info("dataDir:" + data.dataDir);
  console.info("dataBaseDir:" + data.dataBaseDir);
  console.info("cacheDir:" + data.cacheDir);
})
```



## bundle.getApplicationInfo

getApplicationInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<ApplicationInfo>): void

Obtains the application information of the specified user based on a given bundle name in asynchronous mode. This method uses a callback to return the result.

**Permission required**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                          | Yes| Bundle name of the application.|
| bundleFlags | number                          | Yes| Type of information that will be returned. The default value is **0**. The value must be greater than or equal to 0.|
| userId      | number                          | Yes| User ID.|
| callback    | AsyncCallback\<ApplicationInfo> | Yes| Callback used to return the application information.|

**Example**

```js
bundle.getApplicationInfo('com.example.myapplicationInstall', 8, 0, OnReceiveEvent);

function OnReceiveEvent(err, data) {
    console.info("name: for begin");
    console.info("name:" + data.name);
    console.info("bundleName:" + data.bundleName);
    console.info("description:" + data.description);
    console.info("descriptionId:" + data.descriptionId);
    console.info("iconPath:" + data.iconPath);
    console.info("iconId:" + data.iconId);
    console.info("label:" + data.label);
    console.info("labelId:" + data.labelId);
    console.info("deviceId:" + data.deviceId);
    console.info("signatureKey:" + data.signatureKey);
    console.info("process:" + data.process);
    console.info("isSystemApp:" + data.isSystemApp);
    console.info("isLauncherApp:" + data.isLauncherApp);
    console.info("supportedModes:" + data.supportedModes);

    console.info('getApplicationInfo permissions length [' + data.permissions.length + ']');
    for (var j = 0; j < data.permissions.length; j++) {
        console.info("permissions[" + j + "]:" + data.permissions[j]);
    }
    console.info('getApplicationInfo moduleSourceDirs length [' + data.moduleSourceDirs.length + ']');
    for (var j = 0; j < data.moduleSourceDirs.length; j++) {
        console.info("moduleSourceDirs[" + j + "]:" + data.moduleSourceDirs[j]);
    }
    console.info('getApplicationInfo moduleInfos length [' + data.moduleInfos.length + ']');
    for (var j = 0; j < data.moduleInfos.length; j++) {
        console.info("moduleInfos[" + j + "]moduleName:" + data.moduleInfos[j].moduleName);
        console.info("moduleInfos[" + j + "]moduleSourceDir:" + data.moduleInfos[j].moduleSourceDir);
    }
    console.info("entryDir:" + data.entryDir);
    console.info("codePath:" + data.codePath);
    console.info("dataDir:" + data.dataDir);
    console.info("dataBaseDir:" + data.dataBaseDir);
    console.info("cacheDir:" + data.cacheDir);
}
```



## bundle.getAllBundleInfo

getAllBundleInfo(bundleFlag: BundleFlag): Promise<Array\<BundleInfo>>

Obtains the information of all available bundles in the system in asynchronous mode. This method uses a promise to return the result.

**Permission required**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ---------- | ---- | ----------------------------------------------------------- |
| bundleFlag | BundleFlag | Yes| Type of information that will be returned.<br/>**0**: The default bundle information will be returned.<br/>**1**: The bundle information containing the ability information will be returned.|

**Return value**

| Type| Description|
| --------------------------- | ----------------------------------- |
| Promise<Array\<BundleInfo>> | Promise used to return the information of all available bundles.|

**Example**

```js
bundle.getAllBundleInfo(0).then((data) => {
    for (var i = 0; i < data.length; i++) {
        console.info("index[" + i + "].name: for begin");
        console.info("index[" + i + "].name:" + data[i].name);
        console.info("index[" + i + "].label:" + data[i].label);
        console.info("index[" + i + "].description:" + data[i].description);
        console.info("index[" + i + "].vendor:" + data[i].vendor);
        console.info("index[" + i + "].versionCode:" + data[i].versionCode);
        console.info("index[" + i + "].versionName:" + data[i].versionName);
        console.info("index[" + i + "].jointUserId:" + data[i].jointUserId);
        console.info("index[" + i + "].minSdkVersion:" + data[i].minSdkVersion);
        console.info("index[" + i + "].maxSdkVersion:" + data[i].maxSdkVersion);
        console.info("index[" + i + "].mainEntry:" + data[i].mainEntry);
        console.info("index[" + i + "].cpuAbi:" + data[i].cpuAbi);
        console.info("index[" + i + "].appId:" + data[i].appId);
        console.info("index[" + i + "].compatibleVersion:" + data[i].compatibleVersion);
        console.info("index[" + i + "].targetVersion:" + data[i].targetVersion);
        console.info("index[" + i + "].releaseType:" + data[i].releaseType);
        console.info("index[" + i + "].uid:" + data[i].uid);
        console.info("index[" + i + "].gid:" + data[i].gid);
        console.info("index[" + i + "].seInfo:" + data[i].seInfo);
        console.info("index[" + i + "].entryModuleName:" + data[i].entryModuleName);
        console.info("index[" + i + "].isKeepAlive:" + data[i].isKeepAlive);
        console.info("index[" + i + "].isNativeApp:" + data[i].isNativeApp);
        console.info("index[" + i + "].installTime:" + data[i].installTime);
        console.info("index[" + i + "].updateTime:" + data[i].updateTime);
        console.info("index[" + i + "].appInfo.name:" + data[i].applicationInfo.name);
        console.info("index[" + i + "].appInfo.bundleName:" + data[i].applicationInfo.bundleName);
        console.info('getAllBundleInfo reqPermissions length [' + data[i].reqPermissions.length + ']');
        for (var j = 0; j < data[i].reqPermissions.length; j++) {
            console.info("index[" + i + "]reqPermissions[" + j + "]:" + data[i].reqPermissions[j]);
        }
        console.info('getAllBundleInfo defPermissions length [' + data[i].defPermissions.length + ']');
        for (var j = 0; j < data[i].defPermissions.length; j++) {
            console.info("index[" + i + "]defPermissions[" + j + "]:" + data[i].defPermissions[j]);
        }

        console.info('getAllBundleInfo hapModuleNames length [' + data[i].hapModuleNames.length + ']');
        for (var j = 0; j < data[i].hapModuleNames.length; j++) {
            console.info("index[" + i + "]hapModuleNames[" + j + "]:" + data[i].hapModuleNames[j]);
        }
        console.info('getAllBundleInfo moduleNames length [' + data[i].moduleNames.length + ']');
        for (var j = 0; j < data[i].moduleNames.length; j++) {
            console.info("index[" + i + "]moduleNames[" + j + "]:" + data[i].moduleNames[j]);
        }
        console.info('getAllBundleInfo modulePublicDirs length [' + data[i].modulePublicDirs.length + ']');
        for (var j = 0; j < data[i].modulePublicDirs.length; j++) {
            console.info("index[" + i + "]modulePublicDirs[" + j + "]:" + data[i].modulePublicDirs[j]);
        }
        console.info('getAllBundleInfo moduleDirs length [' + data[i].moduleDirs.length + ']');
        for (var j = 0; j < data[i].moduleDirs.length; j++) {
            console.info("index[" + i + "]moduleDirs[" + j + "]:" + data[i].moduleDirs[j]);
        }
        console.info('getAllBundleInfo moduleResPaths length [' + data[i].moduleResPaths.length + ']');
        for (var j = 0; j < data[i].moduleResPaths.length; j++) {
            console.info("index[" + i + "]moduleResPaths[" + j + "]:" + data[i].moduleResPaths[j]);
        }
        console.info('getAllBundleInfo abilityInfo length [' + data[i].abilityInfos.length + ']');
        for (var j = 0; j < data[i].abilityInfos.length; j++) {
            console.info("index[" + i + "]abilityInfos[" + j + "]name:" + data[i].abilityInfos[j].name);
            console.info("index[" + i + "]abilityInfos[" + j + "]package:" + data[i].abilityInfos[j].package);
        }
    }
})
```



## bundle.getAllBundleInfo

getAllBundleInfo(bundleFlag: BundleFlag, callback: AsyncCallback<Array\<BundleInfo>>): void

Obtains the information of all available bundles in the system in asynchronous mode. This method uses a callback to return the result.

**Permission required**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| bundleFlag | BundleFlag                        | Yes| Type of information that will be returned.<br/>**0**: The default bundle information will be returned.<br/>**1**: The bundle information containing the ability information will be returned.|
| callback   | AsyncCallback<Array\<BundleInfo>> | Yes| Callback used to return the information of all available bundles.|

**Example**

```js
bundle.getAllBundleInfo(0, OnReceiveEvent);

function OnReceiveEvent(err, data) {
    console.info('xxx getAllBundleInfo data length [' + data.length + ']');
    for (var i = 0; i < data.length; i++) {
        console.info("index[" + i + "].name: for begin");
        console.info("index[" + i + "].name:" + data[i].name);
        console.info("index[" + i + "].label:" + data[i].label);
        console.info("index[" + i + "].description:" + data[i].description);
        console.info("index[" + i + "].vendor:" + data[i].vendor);
        console.info("index[" + i + "].versionCode:" + data[i].versionCode);
        console.info("index[" + i + "].versionName:" + data[i].versionName);
        console.info("index[" + i + "].jointUserId:" + data[i].jointUserId);
        console.info("index[" + i + "].minSdkVersion:" + data[i].minSdkVersion);
        console.info("index[" + i + "].maxSdkVersion:" + data[i].maxSdkVersion);
        console.info("index[" + i + "].mainEntry:" + data[i].mainEntry);
        console.info("index[" + i + "].cpuAbi:" + data[i].cpuAbi);
        console.info("index[" + i + "].appId:" + data[i].appId);
        console.info("index[" + i + "].compatibleVersion:" + data[i].compatibleVersion);
        console.info("index[" + i + "].targetVersion:" + data[i].targetVersion);
        console.info("index[" + i + "].releaseType:" + data[i].releaseType);
        console.info("index[" + i + "].uid:" + data[i].uid);
        console.info("index[" + i + "].gid:" + data[i].gid);
        console.info("index[" + i + "].seInfo:" + data[i].seInfo);
        console.info("index[" + i + "].entryModuleName:" + data[i].entryModuleName);
        console.info("index[" + i + "].isKeepAlive:" + data[i].isKeepAlive);
        console.info("index[" + i + "].isNativeApp:" + data[i].isNativeApp);
        console.info("index[" + i + "].installTime:" + data[i].installTime);
        console.info("index[" + i + "].updateTime:" + data[i].updateTime);
        console.info("index[" + i + "].appInfo.name:" + data[i].applicationInfo.name);
        console.info("index[" + i + "].appInfo.bundleName:" + data[i].applicationInfo.bundleName);
        console.info('getAllBundleInfo reqPermissions length [' + data[i].reqPermissions.length + ']');
        for (var j = 0; j < data[i].reqPermissions.length; j++) {
            console.info("index[" + i + "]reqPermissions[" + j + "]:" + data[i].reqPermissions[j]);
        }
        console.info('getAllBundleInfo defPermissions length [' + data[i].defPermissions.length + ']');
        for (var j = 0; j < data[i].defPermissions.length; j++) {
            console.info("index[" + i + "]defPermissions[" + j + "]:" + data[i].defPermissions[j]);
        }

        console.info('getAllBundleInfo hapModuleNames length [' + data[i].hapModuleNames.length + ']');
        for (var j = 0; j < data[i].hapModuleNames.length; j++) {
            console.info("index[" + i + "]hapModuleNames[" + j + "]:" + data[i].hapModuleNames[j]);
        }
        console.info('getAllBundleInfo moduleNames length [' + data[i].moduleNames.length + ']');
        for (var j = 0; j < data[i].moduleNames.length; j++) {
            console.info("index[" + i + "]moduleNames[" + j + "]:" + data[i].moduleNames[j]);
        }
        console.info('getAllBundleInfo modulePublicDirs length [' + data[i].modulePublicDirs.length + ']');
        for (var j = 0; j < data[i].modulePublicDirs.length; j++) {
            console.info("index[" + i + "]modulePublicDirs[" + j + "]:" + data[i].modulePublicDirs[j]);
        }
        console.info('getAllBundleInfo moduleDirs length [' + data[i].moduleDirs.length + ']');
        for (var j = 0; j < data[i].moduleDirs.length; j++) {
            console.info("index[" + i + "]moduleDirs[" + j + "]:" + data[i].moduleDirs[j]);
        }
        console.info('getAllBundleInfo moduleResPaths length [' + data[i].moduleResPaths.length + ']');
        for (var j = 0; j < data[i].moduleResPaths.length; j++) {
            console.info("index[" + i + "]moduleResPaths[" + j + "]:" + data[i].moduleResPaths[j]);
        }
        console.info('getAllBundleInfo abilityInfo length [' + data[i].abilityInfos.length + ']');
        for (var j = 0; j < data[i].abilityInfos.length; j++) {
            console.info("index[" + i + "]abilityInfos[" + j + "]name:" + data[i].abilityInfos[j].name);
            console.info("index[" + i + "]abilityInfos[" + j + "]package:" + data[i].abilityInfos[j].package);
        }
    }
}
```



## bundle.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number): Promise\<BundleInfo>

Obtains the bundle information based on a given bundle name in asynchronous mode. This method uses a promise to return the result.

**Permission required**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | Yes| Bundle name.|
| bundleFlags | number | Yes| Type of information that will be returned.<br/>**0**: The default bundle information will be returned.<br/>**1**: The bundle information containing the ability information will be returned.|

**Return value**

| Type| Description|
| -------------------- | ------------------------------------------ |
| Promise\<BundleInfo> | Promise used to return the bundle information.|

**Example**

```js
bundle.getBundleInfo('com.example.myapplicationInstall', 1).then((data) => {
    console.info("name:" + data.name);
    console.info("label:" + data.label);
    console.info("description:" + data.description);
    console.info("vendor:" + data.vendor);
    console.info("versionCode:" + data.versionCode);
    console.info("versionName:" + data.versionName);
    console.info("jointUserId:" + data.jointUserId);
    console.info("minSdkVersion:" + data.minSdkVersion);
    console.info("maxSdkVersion:" + data.maxSdkVersion);
    console.info("mainEntry:" + data.mainEntry);
    console.info("cpuAbi:" + data.cpuAbi);
    console.info("appId:" + data.appId);
    console.info("compatibleVersion:" + data.compatibleVersion);
    console.info("targetVersion:" + data.targetVersion);
    console.info("releaseType:" + data.releaseType);
    console.info("uid:" + data.uid);
    console.info("gid:" + data.gid);
    console.info("seInfo:" + data.seInfo);
    console.info("entryModuleName:" + data.entryModuleName);
    console.info("isKeepAlive:" + data.isKeepAlive);
    console.info("isNativeApp:" + data.isNativeApp);
    console.info("installTime:" + data.installTime);
    console.info("updateTime:" + data.updateTime);
    console.info("appInfo.name:" + data.applicationInfo.name);
    console.info("appInfo.bundleName:" + data.applicationInfo.bundleName);
    console.info('getBundleInfo reqPermissions length [' + data.reqPermissions.length + ']');
    for (var j = 0; j < data.reqPermissions.length; j++) {
        console.info("reqPermissions[" + j + "]:" + data.reqPermissions[j]);
    }
    console.info('getBundleInfo defPermissions length [' + data.defPermissions.length + ']');
    for (var j = 0; j < data.defPermissions.length; j++) {
        console.info("defPermissions[" + j + "]:" + data.defPermissions[j]);
    }

    console.info('getBundleInfo hapModuleNames length [' + data.hapModuleNames.length + ']');
    for (var j = 0; j < data.hapModuleNames.length; j++) {
        console.info("hapModuleNames[" + j + "]:" + data.hapModuleNames[j]);
    }
    console.info('getBundleInfo moduleNames length [' + data.moduleNames.length + ']');
    for (var j = 0; j < data.moduleNames.length; j++) {
        console.info("moduleNames[" + j + "]:" + data.moduleNames[j]);
    }
    console.info('getBundleInfo modulePublicDirs length [' + data.modulePublicDirs.length + ']');
    for (var j = 0; j < data.modulePublicDirs.length; j++) {
        console.info("modulePublicDirs[" + j + "]:" + data.modulePublicDirs[j]);
    }
    console.info('getBundleInfo moduleDirs length [' + data.moduleDirs.length + ']');
    for (var j = 0; j < data.moduleDirs.length; j++) {
        console.info("moduleDirs[" + j + "]:" + data.moduleDirs[j]);
    }
    console.info('getBundleInfo moduleResPaths length [' + data.moduleResPaths.length + ']');
    for (var j = 0; j < data.moduleResPaths.length; j++) {
        console.info("moduleResPaths[" + j + "]:" + data.moduleResPaths[j]);
    }
    console.info('getBundleInfo abilityInfo length [' + data.abilityInfos.length + ']');
    for (var j = 0; j < data.abilityInfos.length; j++) {
        console.info("abilityInfos[" + j + "]name:" + data.abilityInfos[j].name);
        console.info("abilityInfos[" + j + "]package:" + data.abilityInfos[j].package);
    }
})
```



## bundle.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information based on a given bundle name in asynchronous mode. This method uses a callback to return the result.

**Permission required**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | -------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                     | Yes| Bundle name.|
| bundleFlags | number                     | Yes| Type of information that will be returned.<br/>**0**: The default bundle information will be returned.<br/>**1**: The bundle information containing the ability information will be returned.|
| callback    | AsyncCallback\<BundleInfo> | Yes| Callback used to return the bundle information.|

**Example**

```js
bundle.getBundleInfo('com.example.myapplicationInstall', 1, OnReceiveEvent);

function OnReceiveEvent(err, data) {
    console.info("name:" + data.name);
    console.info("label:" + data.label);
    console.info("description:" + data.description);
    console.info("vendor:" + data.vendor);
    console.info("versionCode:" + data.versionCode);
    console.info("versionName:" + data.versionName);
    console.info("jointUserId:" + data.jointUserId);
    console.info("minSdkVersion:" + data.minSdkVersion);
    console.info("maxSdkVersion:" + data.maxSdkVersion);
    console.info("mainEntry:" + data.mainEntry);
    console.info("cpuAbi:" + data.cpuAbi);
    console.info("appId:" + data.appId);
    console.info("compatibleVersion:" + data.compatibleVersion);
    console.info("targetVersion:" + data.targetVersion);
    console.info("releaseType:" + data.releaseType);
    console.info("uid:" + data.uid);
    console.info("gid:" + data.gid);
    console.info("seInfo:" + data.seInfo);
    console.info("entryModuleName:" + data.entryModuleName);
    console.info("isKeepAlive:" + data.isKeepAlive);
    console.info("isNativeApp:" + data.isNativeApp);
    console.info("installTime:" + data.installTime);
    console.info("updateTime:" + data.updateTime);
    console.info("appInfo.name:" + data.applicationInfo.name);
    console.info("appInfo.bundleName:" + data.applicationInfo.bundleName);
    console.info('getBundleInfo reqPermissions length [' + data.reqPermissions.length + ']');
    for (var j = 0; j < data.reqPermissions.length; j++) {
        console.info("reqPermissions[" + j + "]:" + data.reqPermissions[j]);
    }
    console.info('getBundleInfo defPermissions length [' + data.defPermissions.length + ']');
    for (var j = 0; j < data.defPermissions.length; j++) {
        console.info("defPermissions[" + j + "]:" + data.defPermissions[j]);
    }

    console.info('getBundleInfo hapModuleNames length [' + data.hapModuleNames.length + ']');
    for (var j = 0; j < data.hapModuleNames.length; j++) {
        console.info("hapModuleNames[" + j + "]:" + data.hapModuleNames[j]);
    }
    console.info('getBundleInfo moduleNames length [' + data.moduleNames.length + ']');
    for (var j = 0; j < data.moduleNames.length; j++) {
        console.info("moduleNames[" + j + "]:" + data.moduleNames[j]);
    }
    console.info('getBundleInfo modulePublicDirs length [' + data.modulePublicDirs.length + ']');
    for (var j = 0; j < data.modulePublicDirs.length; j++) {
        console.info("modulePublicDirs[" + j + "]:" + data.modulePublicDirs[j]);
    }
    console.info('getBundleInfo moduleDirs length [' + data.moduleDirs.length + ']');
    for (var j = 0; j < data.moduleDirs.length; j++) {
        console.info("moduleDirs[" + j + "]:" + data.moduleDirs[j]);
    }
    console.info('getBundleInfo moduleResPaths length [' + data.moduleResPaths.length + ']');
    for (var j = 0; j < data.moduleResPaths.length; j++) {
        console.info("moduleResPaths[" + j + "]:" + data.moduleResPaths[j]);
    }
    console.info('getBundleInfo abilityInfo length [' + data.abilityInfos.length + ']');
    for (var j = 0; j < data.abilityInfos.length; j++) {
        console.info("abilityInfos[" + j + "]name:" + data.abilityInfos[j].name);
        console.info("abilityInfos[" + j + "]package:" + data.abilityInfos[j].package);
    }
}
```



## bundle.getAllApplicationInfo

getAllApplicationInfo(bundleFlags: number, userId: number): Promise<Array\<ApplicationInfo>>

Obtains the information about all applications of the specified user. This method uses a promise to return the result.

**Permission required**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------ | ---- | ------------------------------------------------------ |
| bundleFlags | number | Yes| Type of information that will be returned.<br/>**0**: The default application information will be returned. <br/>**8**: The application information containing the permission information will be returned.|
| userId      | number | Yes| User ID.|

**Return value**

| Type| Description|
| -------------------------------- | ------------------------------------------------ |
| Promise<Array\<ApplicationInfo>> | Promise used to return the application information.|

**Example**

```js
bundle.getAllApplicationInfo(8, 0).then((data) => {
    console.info('xxx getAllApplicationInfo data length [' + data.length + ']');
    for (var i = 0; i < data.length; i++) {
        console.info("index[" + i + "].name: for begin");
        console.info("index[" + i + "].name:" + data[i].name);
        console.info("index[" + i + "].bundleName:" + data[i].bundleName);
        console.info("index[" + i + "].description:" + data[i].description);
        console.info("index[" + i + "].descriptionId:" + data[i].descriptionId);
        console.info("index[" + i + "].iconPath:" + data[i].iconPath);
        console.info("index[" + i + "].iconId:" + data[i].iconId);
        console.info("index[" + i + "].label:" + data[i].label);
        console.info("index[" + i + "].labelId:" + data[i].labelId);
        console.info("index[" + i + "].deviceId:" + data[i].deviceId);
        console.info("index[" + i + "].signatureKey:" + data[i].signatureKey);
        console.info("index[" + i + "].process:" + data[i].process);
        console.info("index[" + i + "].isSystemApp:" + data[i].isSystemApp);
        console.info("index[" + i + "].isLauncherApp:" + data[i].isLauncherApp);
        console.info("index[" + i + "].supportedModes:" + data[i].supportedModes);

        console.info('getAllApplicationInfo Async permissions length [' + data[i].permissions.length + ']');
        for (var j = 0; j < data[i].permissions.length; j++) {
            console.info("index[" + i + "]permissions[" + j + "]:" + data[i].permissions[j]);
        }
        console.info('getAllApplicationInfo Async moduleSourceDirs length [' + data[i].moduleSourceDirs.length + ']');
        for (var j = 0; j < data[i].moduleSourceDirs.length; j++) {
            console.info("index[" + i + "]moduleSourceDirs[" + j + "]:" + data[i].moduleSourceDirs[j]);
        }
        console.info('getAllApplicationInfo Async moduleInfos length [' + data[i].moduleInfos.length + ']');
        for (var j = 0; j < data[i].moduleInfos.length; j++) {
            console.info("index[" + i + "]moduleInfos[" + j + "]moduleName:" + data[i].moduleInfos[j].moduleName);
            console.info("index[" + i + "]moduleInfos[" + j + "]moduleSourceDir:" + data[i].moduleInfos[j].moduleSourceDir);
        }
        console.info("index[" + i + "].entryDir:" + data[i].entryDir);
        console.info("index[" + i + "].codePath:" + data[i].codePath);
        console.info("index[" + i + "].dataDir:" + data[i].dataDir);
        console.info("index[" + i + "].dataBaseDir:" + data[i].dataBaseDir);
        console.info("index[" + i + "].cacheDir:" + data[i].cacheDir);
    }
})
```



## bundle.getAllApplicationInfo

getAllApplicationInfo(bundleFlags: number, userId: number, callback: AsyncCallback<Array\<ApplicationInfo>>): void

Obtains the information about all installed applications of the specified user. This method uses a callback to return the result.

**Permission required**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | -------------------------------------- | ---- | ------------------------------------------------------ |
| bundleFlags | number                                 | Yes| Type of information that will be returned.<br/>**0**: The default application information will be returned. <br/>**8**: The application information containing the permission information will be returned.|
| userId      | number                                 | Yes| User ID.|
| callback    | AsyncCallback<Array\<ApplicationInfo>> | Yes| Callback used to return the application information.|

**Example**

```js
bundle.getAllApplicationInfo(8, 0, OnReceiveEvent);

function OnReceiveEvent(err, data) {
    console.info('xxx getAllApplicationInfo data length [' + data.length + ']');
    for (var i = 0; i < data.length; i++) {
        console.info("index[" + i + "].name: for begin");
        console.info("index[" + i + "].name:" + data[i].name);
        console.info("index[" + i + "].bundleName:" + data[i].bundleName);
        console.info("index[" + i + "].description:" + data[i].description);
        console.info("index[" + i + "].descriptionId:" + data[i].descriptionId);
        console.info("index[" + i + "].iconPath:" + data[i].iconPath);
        console.info("index[" + i + "].iconId:" + data[i].iconId);
        console.info("index[" + i + "].label:" + data[i].label);
        console.info("index[" + i + "].labelId:" + data[i].labelId);
        console.info("index[" + i + "].deviceId:" + data[i].deviceId);
        console.info("index[" + i + "].signatureKey:" + data[i].signatureKey);
        console.info("index[" + i + "].process:" + data[i].process);
        console.info("index[" + i + "].isSystemApp:" + data[i].isSystemApp);
        console.info("index[" + i + "].isLauncherApp:" + data[i].isLauncherApp);
        console.info("index[" + i + "].supportedModes:" + data[i].supportedModes);

        console.info('getAllApplicationInfo Async permissions length [' + data[i].permissions.length + ']');
        for (var j = 0; j < data[i].permissions.length; j++) {
            console.info("index[" + i + "]permissions[" + j + "]:" + data[i].permissions[j]);
        }
        console.info('getAllApplicationInfo Async moduleSourceDirs length [' + data[i].moduleSourceDirs.length + ']');
        for (var j = 0; j < data[i].moduleSourceDirs.length; j++) {
            console.info("index[" + i + "]moduleSourceDirs[" + j + "]:" + data[i].moduleSourceDirs[j]);
        }
        console.info('getAllApplicationInfo Async moduleInfos length [' + data[i].moduleInfos.length + ']');
        for (var j = 0; j < data[i].moduleInfos.length; j++) {
            console.info("index[" + i + "]moduleInfos[" + j + "]moduleName:" + data[i].moduleInfos[j].moduleName);
            console.info("index[" + i + "]moduleInfos[" + j + "]moduleSourceDir:" + data[i].moduleInfos[j].moduleSourceDir);
        }
        console.info("index[" + i + "].entryDir:" + data[i].entryDir);
        console.info("index[" + i + "].codePath:" + data[i].codePath);
        console.info("index[" + i + "].dataDir:" + data[i].dataDir);
        console.info("index[" + i + "].dataBaseDir:" + data[i].dataBaseDir);
        console.info("index[" + i + "].cacheDir:" + data[i].cacheDir);
    }
}
```



## bundle.queryAbilityByWant

queryAbilityByWant(want: Want, bundleFlags: number, userId?: number): Promise<Array\<AbilityInfo>>

Obtains the ability information of the specified user based on a given want. This method uses a promise to return the result.

**Permission required**

ohos.permission.GET\_BUNDLE\_INFO\_PRIVILEGED or ohos.permission.GET\_BUNDLE\_INFO

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| want        | Want   | Yes| Want that contains the bundle name.|
| bundleFlags | number | Yes| Type of information that will be returned.<br/>**0**: The default ability information will be returned.<br/>**2**: The ability information containing the permission information will be returned.<br/>**4**: The ability information containing the application information will be returned.|
| userId      | number | No| User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type| Description|
| ---------------------------- | ---------------------------- |
| Promise\<Array\<AbilityInfo>>| Promise used to return the ability information.|

**Example**

```js
bundle.queryAbilityByWant({
    want: {
        action: "action.system.home",
        entities: ["entity.system.home"],
        elementName: {
            deviceId: "0",
            bundleName: "com.example.myapplicationInstall",
            abilityName: "com.example.myapplication.MainAbility",
        },
    }
},  1, 0,
}).then((data) => {
    console.info("name:" + data.name);
    console.info("label:" + data.label);
    console.info("description:" + data.description);
    console.info("iconPath:" + data.iconPath);
    console.info("visible:" + data.visible);
    console.info("kind:" + data.kind);
    console.info("uri:" + data.uri);
    console.info("process:" + data.process);
    console.info("package:" + data.package);
    console.info("bundleName:" + data.bundleName);
    console.info("moduleName:" + data.moduleName);
    console.info("applicationName:" + data.applicationName);
    console.info("deviceId:" + data.deviceId);
    console.info("codePath:" + data.codePath);
    console.info("resourcePath:" + data.resourcePath);
    console.info("libPath:" + data.libPath);

    console.info('queryAbilityInfo permissions length [' + data.permissions.length + ']');
    for (var j = 0; j < data.permissions.length; j++) {
        console.info("permissions[" + j + "]:" + data.permissions[j]);
    }
    console.info('queryAbilityInfo deviceTypes length [' + data.deviceTypes.length + ']');
    for (var j = 0; j < data.deviceTypes.length; j++) {
        console.info("deviceTypes[" + j + "]:" + data.deviceTypes[j]);
    }
    console.info('queryAbilityInfo deviceCapabilities length [' + data.deviceCapabilities.length + ']');
    for (var j = 0; j < data.deviceCapabilities.length; j++) {
        console.info("deviceCapabilities[" + j + "]:" + data.deviceCapabilities[j]);
    }
    console.info("appInfo.name:" + data.applicationInfo.name);
    console.info("appInfo.bundleName:" + data.applicationInfo.bundleName);
    // ability type: 0:UNKNOWN, 1:PAGE, 2:SERVICE, 3:DATA
    console.info("type:" + data.type);
    // orientation: 0:UNSPECIFIED, 1:LANDSCAPE, 2:PORTRAIT, 3:FOLLOWRECENT,
    console.info("orientation:" + data.orientation);
    // launchMode: 0:SINGLETON, 1:SINGLETOP, 2:STANDARD
    console.info("launchMode:" + data.launchMode);

    // the enum of AbilityType
    console.info("AbilityType:" + bundle.AbilityType.UNKNOWN);
    console.info("AbilityType:" + bundle.AbilityType.PAGE);
    console.info("AbilityType:" + bundle.AbilityType.SERVICE);
    console.info("AbilityType:" + bundle.AbilityType.DATA);
    if (data.type == bundle.AbilityType.PAGE) {
        console.info("this AbilityType is PAGE");
    }
    // the enum of DisplayOrientation
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.UNSPECIFIED);
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.LANDSCAPE);
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.PORTRAIT);
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.FOLLOWRECENT);
    if (data.orientation == bundle.DisplayOrientation.UNSPECIFIED) {
        console.info("this DisplayOrientation is UNSPECIFIED");
    }
    // the enum of LaunchMode
    console.info("LaunchMode:" + bundle.LaunchMode.SINGLETON);
    console.info("LaunchMode:" + bundle.LaunchMode.SINGLETOP);
    console.info("LaunchMode:" + bundle.LaunchMode.STANDARD);
    if (data.launchMode == bundle.LaunchMode.STANDARD) {
        console.info("this LaunchMode is STANDARD");
    }

})
```



## bundle.queryAbilityByWant

queryAbilityByWant(want: Want, bundleFlags: number, userId: number, callback: AsyncCallback\<Array\<AbilityInfo>>): void

Obtains the ability information of the specified user based on a given want. This method uses an asynchronous callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| want        | Want                               | Yes| Want that contains the bundle name.|
| bundleFlags | number                             | Yes| Type of information that will be returned.<br/>**0**: The default ability information will be returned.<br/>**2**: The ability information containing the permission information will be returned.<br/>**4**: The ability information containing the application information will be returned.|
| userId      | number                             | Yes| User ID.|
| callback    | AsyncCallback<Array\<AbilityInfo>> | Yes| Callback used to return the ability information.|

**Example**

```js
bundle.queryAbilityByWant(
    {
        want: {
            action: "action.system.home",
            entities: ["entity.system.home"],
            elementName: {
                deviceId: "0",
                bundleName: "com.example.myapplicationInstall",
                abilityName: "com.example.myapplication.MainAbility",
            },
        }
    }, 1, 0,
    }, OnReceiveEvent);

function OnReceiveEvent(err, data) {
    console.info("name:" + data.name);
    console.info("label:" + data.label);
    console.info("description:" + data.description);
    console.info("iconPath:" + data.iconPath);
    console.info("visible:" + data.visible);
    console.info("kind:" + data.kind);
    console.info("uri:" + data.uri);
    console.info("process:" + data.process);
    console.info("package:" + data.package);
    console.info("bundleName:" + data.bundleName);
    console.info("moduleName:" + data.moduleName);
    console.info("applicationName:" + data.applicationName);
    console.info("deviceId:" + data.deviceId);
    console.info("codePath:" + data.codePath);
    console.info("resourcePath:" + data.resourcePath);
    console.info("libPath:" + data.libPath);

    console.info('queryAbilityInfo permissions length [' + data.permissions.length + ']');
    for (var j = 0; j < data.permissions.length; j++) {
        console.info("permissions[" + j + "]:" + data.permissions[j]);
    }
    console.info('queryAbilityInfo deviceTypes length [' + data.deviceTypes.length + ']');
    for (var j = 0; j < data.deviceTypes.length; j++) {
        console.info("deviceTypes[" + j + "]:" + data.deviceTypes[j]);
    }
    console.info('queryAbilityInfo deviceCapabilities length [' + data.deviceCapabilities.length + ']');
    for (var j = 0; j < data.deviceCapabilities.length; j++) {
        console.info("deviceCapabilities[" + j + "]:" + data.deviceCapabilities[j]);
    }
    console.info("appInfo.name:" + data.applicationInfo.name);
    console.info("appInfo.bundleName:" + data.applicationInfo.bundleName);
    // ability type: 0:UNKNOWN, 1:PAGE, 2:SERVICE, 3:DATA
    console.info("type:" + data.type);
    // orientation: 0:UNSPECIFIED, 1:LANDSCAPE, 2:PORTRAIT, 3:FOLLOWRECENT,
    console.info("orientation:" + data.orientation);
    // launchMode: 0:SINGLETON, 1:SINGLETOP, 2:STANDARD
    console.info("launchMode:" + data.launchMode);

    // the enum of AbilityType
    console.info("AbilityType:" + bundle.AbilityType.UNKNOWN);
    console.info("AbilityType:" + bundle.AbilityType.PAGE);
    console.info("AbilityType:" + bundle.AbilityType.SERVICE);
    console.info("AbilityType:" + bundle.AbilityType.DATA);
    if (data.type == bundle.AbilityType.PAGE) {
        console.info("this AbilityType is PAGE");
    }
    // the enum of DisplayOrientation
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.UNSPECIFIED);
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.LANDSCAPE);
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.PORTRAIT);
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.FOLLOWRECENT);
    if (data.orientation == bundle.DisplayOrientation.UNSPECIFIED) {
        console.info("this DisplayOrientation is UNSPECIFIED");
    }
    // the enum of LaunchMode
    console.info("LaunchMode:" + bundle.LaunchMode.SINGLETON);
    console.info("LaunchMode:" + bundle.LaunchMode.SINGLETOP);
    console.info("LaunchMode:" + bundle.LaunchMode.STANDARD);
    if (data.launchMode == bundle.LaunchMode.STANDARD) {
        console.info("this LaunchMode is STANDARD");
    }
}
```

## bundle.queryAbilityByWant

queryAbilityByWant(want: Want, bundleFlags: number, callback: AsyncCallback<Array<AbilityInfo>>): void

Obtains the ability information based on a given want. This method uses an asynchronous callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| want        | Want                               | Yes| Want that contains the bundle name.|
| bundleFlags | number                             | Yes| Type of information that will be returned.<br/>**0**: The default ability information will be returned.<br/>**2**: The ability information containing the permission information will be returned.<br/>**4**: The ability information containing the application information will be returned.|
| callback    | AsyncCallback<Array\<AbilityInfo>> | Yes| Callback used to return the ability information.|

**Example**

```js
bundle.queryAbilityByWant(
    {
        want: {
            action: "action.system.home",
            entities: ["entity.system.home"],
            elementName: {
                deviceId: "0",
                bundleName: "com.example.myapplicationInstall",
                abilityName: "com.example.myapplication.MainAbility",
            },
        }
    }, 1,
    }, OnReceiveEvent);

function OnReceiveEvent(err, data) {
    console.info("name:" + data.name);
    console.info("label:" + data.label);
    console.info("description:" + data.description);
    console.info("iconPath:" + data.iconPath);
    console.info("visible:" + data.visible);
    console.info("kind:" + data.kind);
    console.info("uri:" + data.uri);
    console.info("process:" + data.process);
    console.info("package:" + data.package);
    console.info("bundleName:" + data.bundleName);
    console.info("moduleName:" + data.moduleName);
    console.info("applicationName:" + data.applicationName);
    console.info("deviceId:" + data.deviceId);
    console.info("codePath:" + data.codePath);
    console.info("resourcePath:" + data.resourcePath);
    console.info("libPath:" + data.libPath);

    console.info('queryAbilityInfo permissions length [' + data.permissions.length + ']');
    for (var j = 0; j < data.permissions.length; j++) {
        console.info("permissions[" + j + "]:" + data.permissions[j]);
    }
    console.info('queryAbilityInfo deviceTypes length [' + data.deviceTypes.length + ']');
    for (var j = 0; j < data.deviceTypes.length; j++) {
        console.info("deviceTypes[" + j + "]:" + data.deviceTypes[j]);
    }
    console.info('queryAbilityInfo deviceCapabilities length [' + data.deviceCapabilities.length + ']');
    for (var j = 0; j < data.deviceCapabilities.length; j++) {
        console.info("deviceCapabilities[" + j + "]:" + data.deviceCapabilities[j]);
    }
    console.info("appInfo.name:" + data.applicationInfo.name);
    console.info("appInfo.bundleName:" + data.applicationInfo.bundleName);
    // ability type: 0:UNKNOWN, 1:PAGE, 2:SERVICE, 3:DATA
    console.info("type:" + data.type);
    // orientation: 0:UNSPECIFIED, 1:LANDSCAPE, 2:PORTRAIT, 3:FOLLOWRECENT,
    console.info("orientation:" + data.orientation);
    // launchMode: 0:SINGLETON, 1:SINGLETOP, 2:STANDARD
    console.info("launchMode:" + data.launchMode);

    // the enum of AbilityType
    console.info("AbilityType:" + bundle.AbilityType.UNKNOWN);
    console.info("AbilityType:" + bundle.AbilityType.PAGE);
    console.info("AbilityType:" + bundle.AbilityType.SERVICE);
    console.info("AbilityType:" + bundle.AbilityType.DATA);
    if (data.type == bundle.AbilityType.PAGE) {
        console.info("this AbilityType is PAGE");
    }
    // the enum of DisplayOrientation
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.UNSPECIFIED);
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.LANDSCAPE);
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.PORTRAIT);
    console.info("DisplayOrientation:" + bundle.DisplayOrientation.FOLLOWRECENT);
    if (data.orientation == bundle.DisplayOrientation.UNSPECIFIED) {
        console.info("this DisplayOrientation is UNSPECIFIED");
    }
    // the enum of LaunchMode
    console.info("LaunchMode:" + bundle.LaunchMode.SINGLETON);
    console.info("LaunchMode:" + bundle.LaunchMode.SINGLETOP);
    console.info("LaunchMode:" + bundle.LaunchMode.STANDARD);
    if (data.launchMode == bundle.LaunchMode.STANDARD) {
        console.info("this LaunchMode is STANDARD");
    }
}
```

## bundle.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number): Promise\<BundleInfo>

Obtains the bundle information from a given HAP file in asynchronous mode. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| hapFilePath | string | Yes| Path of the HAP file.|
| bundleFlags | number | Yes| Type of information that will be returned.<br/>**0**: The default bundle information will be returned.<br/>**1**: The bundle information containing the ability information will be returned.|

**Return value**

| Type| Description|
| -------------------- | ------------------------------------------ |
| Promise\<BundleInfo> | Promise used to return the bundle information.|

**Example**

```js
bundle.getBundleArchiveInfo('/data/test.hap', 1).then((data) => {
    console.info("name:" + data.name);
    console.info("label:" + data.label);
    console.info("description:" + data.description);
    console.info("vendor:" + data.vendor);
    console.info("versionCode:" + data.versionCode);
    console.info("versionName:" + data.versionName);
    console.info("jointUserId:" + data.jointUserId);
    console.info("minSdkVersion:" + data.minSdkVersion);
    console.info("maxSdkVersion:" + data.maxSdkVersion);
    console.info("mainEntry:" + data.mainEntry);
    console.info("cpuAbi:" + data.cpuAbi);
    console.info("appId:" + data.appId);
    console.info("compatibleVersion:" + data.compatibleVersion);
    console.info("targetVersion:" + data.targetVersion);
    console.info("releaseType:" + data.releaseType);
    console.info("uid:" + data.uid);
    console.info("gid:" + data.gid);
    console.info("seInfo:" + data.seInfo);
    console.info("entryModuleName:" + data.entryModuleName);
    console.info("isKeepAlive:" + data.isKeepAlive);
    console.info("isNativeApp:" + data.isNativeApp);
    console.info("installTime:" + data.installTime);
    console.info("updateTime:" + data.updateTime);
    console.info("appInfo.name:" + data.applicationInfo.name);
    console.info("appInfo.bundleName:" + data.applicationInfo.bundleName);
    console.info('getBundleArchiveInfo reqPermissions length [' + data.reqPermissions.length + ']');
    for (var j = 0; j < data.reqPermissions.length; j++) {
        console.info("reqPermissions[" + j + "]:" + data.reqPermissions[j]);
    }
    console.info('getBundleArchiveInfo defPermissions length [' + data.defPermissions.length + ']');
    for (var j = 0; j < data.defPermissions.length; j++) {
        console.info("defPermissions[" + j + "]:" + data.defPermissions[j]);
    }
    console.info('getBundleArchiveInfo hapModuleNames length [' + data.hapModuleNames.length + ']');
    for (var j = 0; j < data.hapModuleNames.length; j++) {
        console.info("hapModuleNames[" + j + "]:" + data.hapModuleNames[j]);
    }
    console.info('getBundleArchiveInfo moduleNames length [' + data.moduleNames.length + ']');
    for (var j = 0; j < data.moduleNames.length; j++) {
        console.info("moduleNames[" + j + "]:" + data.moduleNames[j]);
    }
    console.info('getBundleArchiveInfo modulePublicDirs length [' + data.modulePublicDirs.length + ']');
    for (var j = 0; j < data.modulePublicDirs.length; j++) {
        console.info("modulePublicDirs[" + j + "]:" + data.modulePublicDirs[j]);
    }
    console.info('getBundleArchiveInfo moduleDirs length [' + data.moduleDirs.length + ']');
    for (var j = 0; j < data.moduleDirs.length; j++) {
        console.info("moduleDirs[" + j + "]:" + data.moduleDirs[j]);
    }
    console.info('getBundleArchiveInfo moduleResPaths length [' + data.moduleResPaths.length + ']');
    for (var j = 0; j < data.moduleResPaths.length; j++) {
        console.info("moduleResPaths[" + j + "]:" + data.moduleResPaths[j]);
    }
    console.info('getBundleArchiveInfo abilityInfo length [' + data.abilityInfos.length + ']');
    for (var j = 0; j < data.abilityInfos.length; j++) {
        console.info("abilityInfos[" + j + "]name:" + data.abilityInfos[j].name);
        console.info("abilityInfos[" + j + "]package:" + data.abilityInfos[j].package);
    }
})
```

## bundle.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void

Obtains the bundle information from a given HAP file in asynchronous mode. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ----------- | ------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePath | string                    | Yes| Path of the HAP file.|
| bundleFlags | number                    | Yes| Type of information that will be returned.<br/>**0**: The default bundle information will be returned.<br/>**1**: The bundle information containing the ability information will be returned.|
| callback    | AsyncCallback<BundleInfo> | Yes| Callback used to return the bundle information.|

**Example**

```js
bundle.getBundleArchiveInfo('/data/test.hap', 1, OnReceiveEvent);

function OnReceiveEvent(err, data) {
    console.info("name:" + data.name);
    console.info("label:" + data.label);
    console.info("description:" + data.description);
    console.info("vendor:" + data.vendor);
    console.info("versionCode:" + data.versionCode);
    console.info("versionName:" + data.versionName);
    console.info("jointUserId:" + data.jointUserId);
    console.info("minSdkVersion:" + data.minSdkVersion);
    console.info("maxSdkVersion:" + data.maxSdkVersion);
    console.info("mainEntry:" + data.mainEntry);
    console.info("cpuAbi:" + data.cpuAbi);
    console.info("appId:" + data.appId);
    console.info("compatibleVersion:" + data.compatibleVersion);
    console.info("targetVersion:" + data.targetVersion);
    console.info("releaseType:" + data.releaseType);
    console.info("uid:" + data.uid);
    console.info("gid:" + data.gid);
    console.info("seInfo:" + data.seInfo);
    console.info("entryModuleName:" + data.entryModuleName);
    console.info("isKeepAlive:" + data.isKeepAlive);
    console.info("isNativeApp:" + data.isNativeApp);
    console.info("installTime:" + data.installTime);
    console.info("updateTime:" + data.updateTime);
    console.info("appInfo.name:" + data.applicationInfo.name);
    console.info("appInfo.bundleName:" + data.applicationInfo.bundleName);
    console.info('getBundleArchiveInfo reqPermissions length [' + data.reqPermissions.length + ']');
    for (var j = 0; j < data.reqPermissions.length; j++) {
        console.info("reqPermissions[" + j + "]:" + data.reqPermissions[j]);
    }
    console.info('getBundleArchiveInfo defPermissions length [' + data.defPermissions.length + ']');
    for (var j = 0; j < data.defPermissions.length; j++) {
        console.info("defPermissions[" + j + "]:" + data.defPermissions[j]);
    }
    console.info('getBundleArchiveInfo hapModuleNames length [' + data.hapModuleNames.length + ']');
    for (var j = 0; j < data.hapModuleNames.length; j++) {
        console.info("hapModuleNames[" + j + "]:" + data.hapModuleNames[j]);
    }
    console.info('getBundleArchiveInfo moduleNames length [' + data.moduleNames.length + ']');
    for (var j = 0; j < data.moduleNames.length; j++) {
        console.info("moduleNames[" + j + "]:" + data.moduleNames[j]);
    }
    console.info('getBundleArchiveInfo modulePublicDirs length [' + data.modulePublicDirs.length + ']');
    for (var j = 0; j < data.modulePublicDirs.length; j++) {
        console.info("modulePublicDirs[" + j + "]:" + data.modulePublicDirs[j]);
    }
    console.info('getBundleArchiveInfo moduleDirs length [' + data.moduleDirs.length + ']');
    for (var j = 0; j < data.moduleDirs.length; j++) {
        console.info("moduleDirs[" + j + "]:" + data.moduleDirs[j]);
    }
    console.info('getBundleArchiveInfo moduleResPaths length [' + data.moduleResPaths.length + ']');
    for (var j = 0; j < data.moduleResPaths.length; j++) {
        console.info("moduleResPaths[" + j + "]:" + data.moduleResPaths[j]);
    }
    console.info('getBundleArchiveInfo abilityInfo length [' + data.abilityInfos.length + ']');
    for (var j = 0; j < data.abilityInfos.length; j++) {
        console.info("abilityInfos[" + j + "]name:" + data.abilityInfos[j].name);
        console.info("abilityInfos[" + j + "]package:" + data.abilityInfos[j].package);
    }
}
```

## bundle.getBundleInstaller

getBundleInstaller(): Promise<BundleInstaller>

Obtains the bundle installer in asynchronous mode. This method uses a promise to return the result.

**Return value**

| Type| Description|
| ------------------------ | --------------------------------------------------- |
| Promise<BundleInstaller> | Promise used to return the bundle installer.|

**Example**

```js
bundle.getBundleInstaller().then((data) => {
    data.install(['/data/test.hap'], {
        param: {
      		userId: 0,
      		installFlag: 1,
      		isKeepData: false
        }
    }, OnReceiveinstallEvent);

    function OnReceiveinstallEvent(err, data) {
        console.info("name: for begin");
        console.info("install result code:" + data.status);
        console.info("install result msg:" + data.statusMessage);
    }
})
```

## bundle.getBundleInstaller

getBundleInstaller(callback: AsyncCallback<BundleInstaller>): void;

Obtains the bundle installer in asynchronous mode. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------------ | ---- | ------------------------------------------------- |
| callback | AsyncCallback<BundleInstaller> | Yes| Callback used to return the bundle installer.|

**Example**

```js
bundle.getBundleInstaller((err, data)=>{
  data.uninstall('com.example.myapplication', {
      userId: 0,
      installFlag: 1,
      isKeepData: false
    }, OnReceiveinstallEvent);

  function OnReceiveinstallEvent(err, data) {
    console.info("name: for begin");
    console.info("uninstall result code:" + data.status);
    console.info("uninstall result msg:" + data.statusMessage);
  }
})
```

## bundle.getAllShortcutInfo

getAllShortcutInfo(bundleName: string): Promise<Array<ShortcutInfo>>

Obtains the shortcut information of the specified bundle in asynchronous mode. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ------ | ---- | -------- |
| bundleName | string | Yes| Bundle name.|

**Return value**
| Type| Description|
| ----------------------------- | ---------------------------------------------------- |
| Promise\<Array<ShortcutInfo>> | Promise used to return the shortcut information.|

**Example**

```js
bundle.getAllShortcutInfo('com.example.third1').then((data) => {
    console.log("getAllShortcutInfo data:" + data);
});
```



## bundle.getAllShortcutInfo

getAllShortcutInfo(bundleName: string, callback: AsyncCallback<Array\<ShortcutInfo>>): void

Obtains the shortcut information of the specified bundle in asynchronous mode. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ------------------------------------ | ---- | -------------------------------------------------- |
| bundleName | string                               | Yes| Bundle name.|
| callback   | AsyncCallback<<Array\<ShortcutInfo>> | Yes| Callback used to return the shortcut information.|

**Example**

```js
bundle.getAllShortcutInfo('com.example.third1', OnReceiveEvent);

function OnReceiveEvent(err, data) {
   console.log("getAllShortcutInfo data:" + data);
}
```

## bundle.checkPermission

checkPermission(bundleName: string, permission: string): Promise\<GrantStatus>

Checks whether a bundle has the specified permission in asynchronous mode. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | ------ | ---- | -------- |
| bundleName | string | Yes| Bundle name.|
| permission | string | Yes| Permission name.|

**Return value**
| Type| Description|
| --------------------- | ------------------------------------------------------------ |
| Promise\<GrantStatus> | Promise used to return the verification result. <br/>**-1**: The bundle does not have the specified permission.<br/>**0**: The bundle has the specified permission.|

**Example**

```js
bundle.checkPermission('com.example.actsbmscheckpermissiontest', 'com.permission.CAMERA').then((data) => {
    console.log("checkPermission data:" + data);
});
```

## bundle.checkPermission

checkPermission(bundleName: string, permission: string, callback: AsyncCallback\<GrantStatus>): void

Checks whether a bundle has the specified permission in asynchronous mode. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ---------- | --------------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string                      | Yes| Bundle name.|
| permission | string                      | Yes| Permission name.|
| callback   | AsyncCallback\<GrantStatus> | Yes| Callback used to return the verification result. <br/>**-1**: The bundle does not have the specified permission.<br/>**0**: The bundle has the specified permission.|

**Example**

```js
bundle.checkPermission('com.example.actsbmscheckpermissiontest', 'com.permission.CAMERA', OnReceiveEvent);

function OnReceiveEvent(err, data) {
   console.log("checkPermission data:" + data);
}
```

## ElementName

| Name| Readable/Writable| Type| Mandatory| Description|
| ----------- | -------- | ------ | ---- | ------------------------------------------------------------ |
| deviceId    | Read-only| string | No| ID of the device that runs the ability.|
| bundleName  | Read-only| string | Yes| Bundle name of the ability. If both **bundleName** and **abilityName** are specified in a **Want**, the **Want** can directly match the specified ability.|
| abilityName | Read-only| string | Yes| Name of the ability. If both **bundleName** and **abilityName** are specified in a **Want**, the **Want** can directly match the specified ability.|

## InstallStatus

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------- | -------- | ---------------- | ---- | ------------------------------------------------------------ |
| status        | Read-only| InstallErrorCode | Yes| Installation result code.<br/>SUCCESS = 0<br/>STATUS_INSTALL_FAILURE = 1<br/>STATUS_INSTALL_FAILURE_ABORTED = 2<br/>STATUS_INSTALL_FAILURE_INVALID = 3<br/>STATUS_INSTALL_FAILURE_CONFLICT = 4<br/>STATUS_INSTALL_FAILURE_STORAGE = 5<br/>STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br/>STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br/>STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br/>STATUS_ABILITY_NOT_FOUND = 0x40<br/>STATUS_BMS_SERVICE_ERROR = 0x41 |
| statusMessage | Read-only| string           | Yes| Message indicating the installation result.|
