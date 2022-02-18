# Bundle模块(JS端SDK接口)

## 导入模块

```
import bundle from '@ohos.bundle';
```

## 系统能力

SystemCapability.BundleManager.BundleFramework

## 权限列表

无

## bundle.getApplicationInfo

getApplicationInfo(bundleName: string, bundleFlags: number, userId: number): Promise\<ApplicationInfo>

以异步方法根据给定的包名获取ApplicationInfo，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型   | 必填 | 描述                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | 是   | 要查询的应用程序包名称。                                     |
| bundleFlags | number | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0 |
| userId      | number | 是   | 用户ID                                                       |

**返回值：**

| 类型      | 说明 |
| ----------- | -------- |
| Promise\<ApplicationInfo> | Promise形式返回应用程序信息。 |

**示例：**

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

以异步方法根据给定的包名获取ApplicationInfo，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型                            | 必填 | 描述                                                         |
| ----------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                          | 是   | 要查询的应用程序包名称。                                     |
| bundleFlags | number                          | 是   | 用于指定返回的应用信息对象中包含信息的标记。默认值：0，取值范围：大于等于0 |
| userId      | number                          | 是   | 用户ID                                                       |
| callback    | AsyncCallback\<ApplicationInfo> | 是   | 程序启动作为入参的回调函数，返回应用程序信息。               |

**示例：**

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

以异步方法获取系统中所有可用的BundleInfo，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

| 名称       | 类型       | 必填 | 描述                                                        |
| ---------- | ---------- | ---- | ----------------------------------------------------------- |
| bundleFlag | BundleFlag | 是   | 0：返回默认BundleInfo<br>1：返回包含abilityInfo的BundleInfo |

**返回值：**

| 类型                        | 说明                                |
| --------------------------- | ----------------------------------- |
| Promise<Array\<BundleInfo>> | Promise形式返回所有可用的BundleInfo |

**示例：**

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

以异步方法获取系统中所有可用的BundleInfo，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**参数：**

| 名称       | 类型                              | 必填 | 描述                                                         |
| ---------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| bundleFlag | BundleFlag                        | 是   | 0：返回默认BundleInfo<br/>1：返回包含abilityInfo的BundleInfo |
| callback   | AsyncCallback<Array\<BundleInfo>> | 是   | 程序启动作为入参的回调函数，返回所有可用的BundleInfo。       |

**示例：**

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

以异步方法根据给定的包名获取BundleInfo，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型   | 必填 | 描述                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| bundleName  | string | 是   | 包名                                                         |
| bundleFlags | number | 是   | 0：返回默认BundleInfo<br/>1：返回包含abilityInfo的BundleInfo |

**返回值：**

| 类型                 | 说明                                       |
| -------------------- | ------------------------------------------ |
| Promise\<BundleInfo> | 返回值为Promise对象，Promise中包含包信息。 |

**示例：**

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

以异步方法根据给定的包名获取BundleInfo，使用callback形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型                       | 必填 | 描述                                                         |
| ----------- | -------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                     | 是   | 包名                                                         |
| bundleFlags | number                     | 是   | 0：返回默认BundleInfo<br/>1：返回包含abilityInfo的BundleInfo |
| callback    | AsyncCallback\<BundleInfo> | 是   | 程序启动作为入参的回调函数，返回包信息。                     |

**示例：**

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

获取指定用户下所有已安装的应用信息，通过Promise获取返回值。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型   | 必填 | 描述                                                   |
| ----------- | ------ | ---- | ------------------------------------------------------ |
| bundleFlags | number | 是   | 0：返回默认应用信息<<br/>8：返回包含权限信息的应用信息 |
| userId      | number | 是   | 用户ID                                                 |

**返回值：**

| 类型                             | 说明                                             |
| -------------------------------- | ------------------------------------------------ |
| Promise<Array\<ApplicationInfo>> | 返回值为Promise对象，Promise中包含应用信息列表。 |

**示例：**

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

获取指定用户下所有已安装的应用信息，通过回调函数获取返回值。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型                                   | 必填 | 描述                                                   |
| ----------- | -------------------------------------- | ---- | ------------------------------------------------------ |
| bundleFlags | number                                 | 是   | 0：返回默认应用信息<<br/>8：返回包含权限信息的应用信息 |
| userId      | number                                 | 是   | 用户ID                                                 |
| callback    | AsyncCallback<Array\<ApplicationInfo>> | 是   | 程序启动作为入参的回调函数，返回应用信息列表。         |

**示例：**

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

以异步方法根据给定的意图获取Ability信息，使用Promise形式返回结果。

**需要权限：**

ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，ohos.permission.GET_BUNDLE_INFO

**参数：**

| 名称        | 类型   | 必填 | 描述                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| want        | Want   | 是   | 包含要查询的应用程序包名称的意图。                           |
| bundleFlags | number | 是   | 0：返回默认AbilityInfo<br/>2：返回包含权限信息的AbilityInfo<br/>4：返回包含应用信息的AbilityInfo |
| userId      | number | 否   | 用户ID。默认值：调用方所在用户，取值范围：大于等于0          |

**返回值：**

| 类型                         | 说明                         |
| ---------------------------- | ---------------------------- |
| Promise<Array\<AbilityInfo>> | Promise形式返回Ability信息。 |

**示例：**

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

queryAbilityByWant(want: Want, bundleFlags: number, userId: number, callback: AsyncCallback<Array\<AbilityInfo>>): void

以异步方法根据给定的意图获取Ability信息，使用callback形式返回结果。

**参数：**

| 名称        | 类型                               | 必填 | 描述                                                         |
| ----------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| want        | Want                               | 是   | 指示包含要查询的应用程序包名称的意图。                       |
| bundleFlags | number                             | 是   | 0：返回默认AbilityInfo<br/>2：返回包含权限信息的AbilityInfo<br/>4：返回包含应用信息的AbilityInfo |
| userId      | number                             | 是   | 用户ID                                                       |
| callback    | AsyncCallback<Array\<AbilityInfo>> | 是   | 程序启动作为入参的回调函数，返回Ability信息。                |

**示例：**

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

以异步方法根据给定的意图获取Ability信息，使用callback形式返回结果。

**参数：**

| 名称        | 类型                               | 必填 | 描述                                                         |
| ----------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| want        | Want                               | 是   | 指示包含要查询的应用程序包名称的意图。                       |
| bundleFlags | number                             | 是   | 0：返回默认AbilityInfo<br/>2：返回包含权限信息的AbilityInfo<br/>4：返回包含应用信息的AbilityInfo |
| callback    | AsyncCallback<Array\<AbilityInfo>> | 是   | 程序启动作为入参的回调函数，返回Ability信息。                |

**示例：**

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

以异步方法从给定的HAP中获取BundleInfo，使用Promise形式返回结果。

**参数：**

| 名称        | 类型   | 必填 | 描述                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| hapFilePath | string | 是   | HAP文件路径                                                  |
| bundleFlags | number | 是   | 0：返回默认BundleInfo<br/>1：返回包含abilityInfo的BundleInfo |

**返回值：**

| 类型                 | 说明                                       |
| -------------------- | ------------------------------------------ |
| Promise\<BundleInfo> | 返回值为Promise对象，Promise中包含包信息。 |

**示例：**

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

以异步方法从给定的HAP中获取BundleInfo，使用callback形式返回结果。

**参数：**

| 名称        | 类型                      | 必填 | 描述                                                         |
| ----------- | ------------------------- | ---- | ------------------------------------------------------------ |
| hapFilePath | string                    | 是   | HAP文件路径                                                  |
| bundleFlags | number                    | 是   | 0：返回默认BundleInfo<br/>1：返回包含abilityInfo的BundleInfo |
| callback    | AsyncCallback<BundleInfo> | 是   | 程序启动作为入参的回调函数，返回包信息。                     |

**示例：**

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

以异步方法获取BundleInstaller，使用Promise形式返回结果。

**返回值：**

| 类型                     | 说明                                                |
| ------------------------ | --------------------------------------------------- |
| Promise<BundleInstaller> | 返回值为Promise对象，Promise中包含BundleInstaller。 |

**示例：**

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

以异步方法获取BundleInstaller，使用callback形式返回结果。

**参数：**

| 名称     | 类型                           | 必填 | 描述                                              |
| -------- | ------------------------------ | ---- | ------------------------------------------------- |
| callback | AsyncCallback<BundleInstaller> | 是   | 程序启动作为入参的回调函数，返回BundleInstaller。 |

**示例：**

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

以异步方法获取指定bundle的Shortcut信息，使用Promise形式返回结果。

**参数：**

| 名称       | 类型   | 必填 | 描述     |
| ---------- | ------ | ---- | -------- |
| bundleName | string | 是   | bundle名 |

**返回值：**
| 类型                          | 说明                                                 |
| ----------------------------- | ---------------------------------------------------- |
| Promise\<Array<ShortcutInfo>> | 返回值为Promise对象，Promise中包含Shortcut信息列表。 |

**示例：**

```js
bundle.getAllShortcutInfo('com.example.third1').then((data) => {
    console.log("getAllShortcutInfo data:" + data);
});
```



## bundle.getAllShortcutInfo

getAllShortcutInfo(bundleName: string, callback: AsyncCallback<Array\<ShortcutInfo>>): void

以异步方法获取指定bundle的Shortcut信息，使用callback形式返回结果。

**参数：**

| 名称       | 类型                                 | 必填 | 描述                                               |
| ---------- | ------------------------------------ | ---- | -------------------------------------------------- |
| bundleName | string                               | 是   | bundle名                                           |
| callback   | AsyncCallback<<Array\<ShortcutInfo>> | 是   | 程序启动作为入参的回调函数，返回Shortcut信息列表。 |

**示例：**

```js
bundle.getAllShortcutInfo('com.example.third1', OnReceiveEvent);

function OnReceiveEvent(err, data) {
   console.log("getAllShortcutInfo data:" + data);
}
```

## bundle.checkPermission

checkPermission(bundleName: string, permission: string): Promise\<GrantStatus>

以异步方法校验指定bundle是否具有指定权限，使用Promise形式返回结果。

**参数：**

| 名称       | 类型   | 必填 | 描述     |
| ---------- | ------ | ---- | -------- |
| bundleName | string | 是   | bundle名 |
| permission | string | 是   | 权限名   |

**返回值：**
| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise\<GrantStatus> | 返回值为Promise对象，Promise中包含校验结果。<br/>-1: 未授权 <br/>0: 已授权 |

**示例：**

```js
bundle.checkPermission('com.example.actsbmscheckpermissiontest', 'com.permission.CAMERA').then((data) => {
    console.log("checkPermission data:" + data);
});
```

## bundle.checkPermission

checkPermission(bundleName: string, permission: string, callback: AsyncCallback\<GrantStatus>): void

以异步方法校验指定bundle是否具有指定权限，使用callback形式返回结果。

**参数：**

| 名称       | 类型                        | 必填 | 描述                                                         |
| ---------- | --------------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string                      | 是   | bundle名                                                     |
| permission | string                      | 是   | 权限名                                                       |
| callback   | AsyncCallback\<GrantStatus> | 是   | 程序启动作为入参的回调函数，返回校验结果。<br/>-1: 未授权 <br/>0: 已授权 |

**示例：**

```js
bundle.checkPermission('com.example.actsbmscheckpermissiontest', 'com.permission.CAMERA', OnReceiveEvent);

function OnReceiveEvent(err, data) {
   console.log("checkPermission data:" + data);
}
```

## ElementName

| 名称        | 读写属性 | 类型   | 必填 | 描述                                                         |
| ----------- | -------- | ------ | ---- | ------------------------------------------------------------ |
| deviceId    | 只读     | string | 否   | 表示运行指定Ability的设备ID。                                |
| bundleName  | 只读     | string | 是   | 表示包描述。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。 |
| abilityName | 只读     | string | 是   | 表示待启动的Ability名称。如果在Want中同时指定了BundleName和AbilityName，则Want可以直接匹配到指定的Ability。 |

## InstallStatus

| 名称          | 读写属性 | 类型             | 必填 | 描述                                                         |
| ------------- | -------- | ---------------- | ---- | ------------------------------------------------------------ |
| status        | 只读     | InstallErrorCode | 是   | 安装结果code<br/>SUCCESS = 0<br/>STATUS_INSTALL_FAILURE = 1<br/>STATUS_INSTALL_FAILURE_ABORTED = 2,<br/>STATUS_INSTALL_FAILURE_INVALID = 3<br/>STATUS_INSTALL_FAILURE_CONFLICT = 4<br/>STATUS_INSTALL_FAILURE_STORAGE = 5<br/>STATUS_INSTALL_FAILURE_INCOMPATIBLE = 6<br/>STATUS_INSTALL_FAILURE_DOWNLOAD_TIMEOUT = 0x0B<br/>STATUS_INSTALL_FAILURE_DOWNLOAD_FAILED = 0x0C<br/>STATUS_ABILITY_NOT_FOUND = 0x40<br/>STATUS_BMS_SERVICE_ERROR = 0x41 |
| statusMessage | 只读     | string           | 是   | 安装结果Message                                              |
