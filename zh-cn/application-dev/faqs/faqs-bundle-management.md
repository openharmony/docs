# 包管理开发常见问题
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## 如何判断某个应用是否为系统应用(API 9)

**解决措施**

使用bundleManager模块的getApplicationInfo接口（仅系统应用可以使用）获取待检验应用的ApplicationInfo，根据ApplicationInfo中systemApp字段判断，若为true，则是系统应用，否则为非系统应用。

**参考链接**

[@ohos.bundle.bundleManager \(应用程序包管理模块\)](../reference/apis-ability-kit/js-apis-bundleManager.md)


## 如何获取应用配置的versionCode和versionName(API 9)

**解决措施**

首先通过\@ohos.bundle.bundleManager模块bundleManager.getBundleInfoForSelf()接口获取包信息BundleInfo，然后分别通过BundleInfo.versionCode、BundleInfo.versionName获取所需信息。

**代码示例**

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

**参考链接**

[getBundleInfoForSelf](../reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)


## 如何获取应用自身的bundleName(API 9)

**解决措施**

可以通过UIAbilityContext.abilityInfo.bundleName获取。

**代码示例**

```
import common from '@ohos.app.ability.common';
const context = getContext(this) as common.UIAbilityContext
console.log(`bundleName: ${context.abilityInfo.bundleName}`)
```

**参考链接**

[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)、[AbilityInfo](../reference/apis-ability-kit/js-apis-bundleManager-abilityInfo.md)


## 如何获取App版本号，版本名，屏幕分辨率等信息(API 9)

**解决措施**

1. 通过\@ohos.bundle.bundleManager模块中的bundleManager查询bundleInfo。

   在bundleInfo中包含App版本号、版本名信息。

   ```
   import bundleManager from '@ohos.bundle.bundleManager';
   ...
   bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION).then((bundleInfo)=>{
     let versionName = bundleInfo.versionName;//应用版本名
     let versionNo = bundleInfo.versionCode;//应用版本号
   }).catch((error)=>{
     console.error("get bundleInfo failed,error is "+error)
   })
   ```

2. 在模块\@ohos.app.ability.Configuration中获取screenDensity，其中包含屏幕分辨率信息。

   ```
   import common from '@ohos.app.ability.common';
   ...
   let context = getContext(this) as common.UIAbilityContext;
   let screenDensity = context.config.screenDensity;
   ```


## 如何获取应用自身的源文件路径(API 9)

**解决措施**

- 方式一：使用应用上下文context获取。

  ```
  this.uiAbilityContext.abilityInfo.applicationInfo.codePath
  ```

- 方式二：使用\@ohos.bundle.bundleManager获取。

  1. 导入\@ohos.bundle.bundleManager模块，使用bundleManager.getBundleInfoForSelf()获取bundleInfo信息。
  2. 使用bundleInfo.appInfo.codePath获取应用源文件路径。

  ```
  import bundleManager from '@ohos.bundle.bundleManager';
  bundleManager.getBundleInfoForSelf(bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION).then((bundleInfo)=>{
    this.sourcePath = bundleInfo.appInfo.codePath;
  })
  ```


## 能否在本应用中获取到其他应用的HAP包信息(API 9)

**问题现象**

如何查询系统内其他应用的信息

**解决措施**

查询系统内其他应用信息的API暂时只提供给系统应用使用，具体使用方法：

- 查询系统内指定应用信息需要获取normal级权限ohos.permission.GET_BUNDLE_INFO，使用接口bundleManager.getApplicationInfo()。

- 查询系统内所有应用信息需要获取system_basic级权限ohos.permission.GET_BUNDLE_INFO_PRIVILEGED，使用接口bundleManager.getAllApplicationInfo()。

**参考链接**

[@ohos.bundle.bundleManager \(应用程序包管理模块\)](../reference/apis-ability-kit/js-apis-bundleManager.md)


## 如何查询进程的pid(API 9)

**解决措施**

可以通过接口\@ohos.process来获取。

**代码示例**

```
import process from '@ohos.process';
private pid = process.pid;
```

**参考链接**

[@ohos.process (获取进程相关的信息)](../reference/apis-arkts/js-apis-process.md)


## 如何让最大化按钮不可用(API 9)

**解决措施**

可以通过supportWindowModes字段去指定是否显示。

- full_screen表示支持全屏显示

- split表示支持分屏显示

- floating表示支持窗口化显示

**代码示例**

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

**参考链接**

[supportWindowModes参考文档](../reference/apis-ability-kit/js-apis-bundleManager-abilityInfo.md)

