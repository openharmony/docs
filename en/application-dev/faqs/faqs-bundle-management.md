# Bundle Management Development


## How do I determine whether an application is a system application? (API version 9)

**Solution**

Use **bundleManager.getApplicationInfo** (available only for system applications) to obtain application information, and check the value of **systemApp** in the information. The application is a system application if the value is **true**.

**References**

[bundleManager](../reference/apis-ability-kit/js-apis-bundleManager.md)


## How do I obtain the version code and version name of an application? (API version 9)

**Solution**

Use **bundleManager.getBundleInfoForSelf()** to obtain the bundle information, which contains the version code (specified by **BundleInfo.versionCode**) and version name (specified by **BundleInfo.versionName**) .

**Example**

```
import bundleManager from '@ohos.bundle.bundleManager';
import hilog from '@ohos.hilog';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
try {
  bundleManager.getBundleInfoForSelf(bundleFlags).then((data) => {
    const versionCode = data.versionCode;
    const versionName = data.versionName;
    hilog.info(0x0000, 'testTag', `successfully. versionCode: ${versionCode}, versionName: ${versionName}`);    
  }).catch(err => {
    hilog.error(0x0000, 'testTag', 'failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  hilog.error(0x0000, 'testTag', 'failed: %{public}s', err.message);
}
```

**References**

[getBundleInfoForSelf](../reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)


## How do I obtain the bundle name of the current application? (API version 9)

**Solution**

Obtain the bundle name from **UIAbilityContext.abilityInfo.bundleName**.

**Example**

```
import common from '@ohos.app.ability.common';
const context = getContext(this) as common.UIAbilityContext
console.log(`bundleName: ${context.abilityInfo.bundleName}`)
```

**References**

[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) and [AbilityInfo](../reference/apis-ability-kit/js-apis-bundleManager-abilityInfo.md)


## How do I obtain the application version number, version name, and screen resolution? (API version 9)

**Solution**

1. Obtain the bundle information from the **\@ohos.bundle.bundleManager** module.

   The bundle information contains the application version number and version name.

   ```
   import bundleManager from '@ohos.bundle.bundleManager';
   ...
   bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION).then((bundleInfo)=>{
     let versionName = bundleInfo.versionName; // Application version name.
     let versionNo = bundleInfo.versionCode; // Application version number.
   }).catch((error)=>{
     console.error("get bundleInfo failed,error is "+error)
   })
   ```

2. Obtain **screenDensity** from the **\@ohos.app.ability.Configuration** module. **screenDensity** contains the screen resolution information.

   ```
   import common from '@ohos.app.ability.common';
   ...
   let context = getContext(this) as common.UIAbilityContext;
   let screenDensity = context.config.screenDensity;
   ```


## How do I obtain the source file path of the current application? (API version 9)

**Solution**

- Method 1: Use the application context to obtain the source file path.

  ```
  this.uiAbilityContext.abilityInfo.applicationInfo.codePath
  ```

- Method 2: Use **\@ohos.bundle.bundleManager** to obtain the source file path.

  1. Import the **\@ohos.bundle.bundleManager** module and use **bundleManager.getBundleInfoForSelf()** to obtain the bundle information.
  2. Obtain the source file path from **bundleInfo.appInfo.codePath**.

  ```
  import bundleManager from '@ohos.bundle.bundleManager';
  bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION).then((bundleInfo)=>{
    this.sourcePath = bundleInfo.appInfo.codePath;
  })
  ```


## Can I obtain the HAP information of other applications from the current application? (API version 9)

**Symptom**

 

**Solution**

Currently, only system applications can call the API to query information about other applications.

- To query information about an application in the system, you must obtain the normal-level permission **ohos.permission.GET_BUNDLE_INFO** and call the **bundleManager.getApplicationInfo()** API.

- To query information about all applications in the system, you must obtain the **system_basic**-level permission **ohos.permission.GET_BUNDLE_INFO_PRIVILEGED** and call the **bundleManager.getAllApplicationInfo()** API.

**References**

[@ohos.bundle.bundleManager \(bundleManager\)](../reference/apis-ability-kit/js-apis-bundleManager.md)


## How do I query the PID of a process? (API version 9)

**Solution**

You can obtain the PID through the **\@ohos.process** interface.

**Example**

```
import process from '@ohos.process';
private pid = process.pid;
```

**References**

[@ohos.process (Obtaining Process Information)](../reference/apis-arkts/js-apis-process.md)


## How do I disable the maximize button? (API version 9)

**Solution**

You can use the **supportWindowModes** field to specify whether to display the maximize button.

- **full_screen** means that a window in full-screen mode is supported.

- **split** means that a window in split-screen mode is supported.

- **floating** means that a floating window is supported.

**Example**

```
"abilities": [
  {
    "name": "EntryAbility",
    "srcEntry": "./ets/entryability/EntryAbility.ets",
    "description": "$string:EntryAbility_desc",
    "icon": "$media:icon",
    "label": "$string:EntryAbility_label",
    "startWindowIcon": "$media:icon",
    "startWindowBackground": "$color:start_window_background",
    "exported": true,
    "supportWindowMode": ["split", "floating"],
    "skills": [
      {
        "entities": [
          "entity.system.home"
        ],
        "actions": [
          "action.system.home"
        ]
      }
    ]
  }
]
```

**References**

[supportWindowModes](../reference/apis-ability-kit/js-apis-bundleManager-abilityInfo.md)
