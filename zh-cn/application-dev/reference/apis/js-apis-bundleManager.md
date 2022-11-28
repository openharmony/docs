# bundleManager模块(JS端SDK接口)

本模块提供应用信息查询能力，支持BundleInfo、ApplicationInfo、Ability、ExtensionAbility等信息的查询

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import bundleManager from '@ohos.bundle.bundleManager'
```
## 权限列表

| 权限                                       | 权限等级     | 描述            |
| ------------------------------------------ | ------------ | ------------------|
| ohos.permission.GET_BUNDLE_INFO            | normal       | 查询指定应用信息。   |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED | system_basic | 可查询所有应用信息。 |
| ohos.permission.REMOVE_CACHE_FILES         | system_basic | 清理应用缓存。       |
|ohos.permission.CHANGE_ABILITY_ENABLED_STATE| system_basic | 设置禁用使能所需的权限。  |

权限等级参考[权限等级说明](../../security/accesstoken-overview.md#权限等级说明)。

## 枚举

### BundleFlag

包信息标志，指示需要获取的包信息的内容。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称                                      | 值         | 说明                                                         |
| ----------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_BUNDLE_INFO_DEFAULT                   | 0x00000000 | 用于获取默认bundleInfo，获取的bundleInfo不包含signatureInfo、applicationInfo、hapModuleInfo、ability、extensionAbility和permission的信息。 |
| GET_BUNDLE_INFO_WITH_APPLICATION          | 0x00000001 | 用于获取包含applicationInfo的bundleInfo，获取的bundleInfo不包含signatureInfo、hapModuleInfo、ability、extensionAbility和permission的信息。 |
| GET_BUNDLE_INFO_WITH_HAP_MODULE           | 0x00000002 | 用于获取包含hapModuleInfo的bundleInfo，获取的bundleInfo不包含signatureInfo、applicationInfo、ability、extensionAbility和permission的信息。 |
| GET_BUNDLE_INFO_WITH_ABILITY              | 0x00000004 | 用于获取包含ability的bundleInfo，获取的bundleInfo不包含signatureInfo、applicationInfo、extensionAbility和permission的信息。它不能单独使用，需要与GET_BUNDLE_INFO_WITH_HAP_MODULE一起使用。 |
| GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY    | 0x00000008 | 用于获取包含extensionAbility的bundleInfo，获取的bundleInfo不包含signatureInfo、applicationInfo、ability 和permission的信息。它不能单独使用，需要与GET_BUNDLE_INFO_WITH_HAP_MODULE一起使用。 |
| GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION | 0x00000010 | 用于获取包含permission的bundleInfo。获取的bundleInfo不包含signatureInfo、applicationInfo、hapModuleInfo、extensionAbility和ability的信息。 |
| GET_BUNDLE_INFO_WITH_METADATA             | 0x00000020 | 用于获取applicationInfo、moduleInfo和abilityInfo中包含的metadata。它不能单独使用，它需要与GET_BUNDLE_INFO_WITH_APPLICATION、GET_BUNDLE_INFO_WITH_HAP_MODULE、GET_BUNDLE_INFO_WITH_ABILITY、GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY一起使用。 |
| GET_BUNDLE_INFO_WITH_DISABLE              | 0x00000040 | 用于获取application被禁用的BundleInfo和被禁用的Ability信息。获取的bundleInfo不包含signatureInfo、applicationInfo、hapModuleInfo、ability、extensionAbility和permission的信息。 |
| GET_BUNDLE_INFO_WITH_SIGNATURE_INFO       | 0x00000080 | 用于获取包含signatureInfo的bundleInfo。获取的bundleInfo不包含applicationInfo、hapModuleInfo、extensionAbility、ability和permission的信息。 |

### ApplicationFlag

应用信息标志，指示需要获取的应用信息的内容。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

 **系统接口：** 系统接口，不支持三方应用调用。

| 名称                                 | 值         | 说明                                                         |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| GET_APPLICATION_INFO_DEFAULT         | 0x00000000 | 用于获取默认的applicationInfo，获取的applicationInfo不包含permission和metadata信息。 |
| GET_APPLICATION_INFO_WITH_PERMISSION | 0x00000001 | 用于获取包含permission的applicationInfo。                    |
| GET_APPLICATION_INFO_WITH_METADATA   | 0x00000002 | 用于获取包含metadata的applicationInfo。                      |
| GET_APPLICATION_INFO_WITH_DISABLE    | 0x00000004 | 用于获取包含禁用应用程序的applicationInfo。                  |

### AbilityFlag

功能组件信息标志，指示需要获取的功能组件信息的内容。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

 **系统接口：** 系统接口，不支持三方应用调用。

| 名称                              | 值         | 说明                                                         |
| --------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_ABILITY_INFO_DEFAULT          | 0x00000000 | 用于获取默认abilityInfo，获取的abilityInfo不包含permission、metadata和禁用的abilityInfo。 |
| GET_ABILITY_INFO_WITH_PERMISSION  | 0x00000001 | 用于获取包含permission的abilityInfo。                          |
| GET_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | 用于获取包含applicationInfo的abilityInfo。                     |
| GET_ABILITY_INFO_WITH_METADATA    | 0x00000004 | 用于获取包含metadata的abilityInfo。                            |
| GET_ABILITY_INFO_WITH_DISABLE     | 0x00000008 | 用于获取包含禁用的abilityInfo的abilityInfo。                   |
| GET_ABILITY_INFO_ONLY_SYSTEM_APP  | 0x00000010 | 用于仅为系统应用程序获取abilityInfo。                         |

### ExtensionAbilityFlag

扩展组件信息标志，指示需要获取的扩展组件信息的内容。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

 **系统接口：** 系统接口，不支持三方应用调用。

| 名称                                        | 值         | 说明                                                         |
| ------------------------------------------- | ---------- | ------------------------------------------------------------ |
| GET_EXTENSION_ABILITY_INFO_DEFAULT          | 0x00000000 | 用于获取默认extensionAbilityInfo。获取的extensionAbilityInfo不包含permission、metadata 和禁用的abilityInfo。 |
| GET_EXTENSION_ABILITY_INFO_WITH_PERMISSION  | 0x00000001 | 用于获取包含permission的extensionAbilityInfo。               |
| GET_EXTENSION_ABILITY_INFO_WITH_APPLICATION | 0x00000002 | 用于获取包含applicationInfo的extensionAbilityInfo。         |
| GET_EXTENSION_ABILITY_INFO_WITH_METADATA    | 0x00000004 | 用于获取包含metadata的extensionAbilityInfo。                 |

### ExtensionAbilityType

指示扩展组件的类型。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称 | 值 | 说明 |
|:----------------:|:---:|-----|
| FORM             | 0   | [FormExtensionAbility](../../ability/stage-formextension.md)：卡片扩展能力，提供卡片开发能力。 |
| WORK_SCHEDULER   | 1   | [WorkSchedulerExtensionAbility](../../task-management/work-scheduler-dev-guide.md)：延时任务扩展能力，允许应用在系统闲时执行实时性不高的任务。 |
| INPUT_METHOD     | 2   | [InputMethodExtensionAbility](js-apis-inputmethod-extension-ability.md)：输入法扩展能力，用于开发输入法应用。 |
| SERVICE          | 3   | [ServiceExtensionAbility](../../ability/stage-serviceextension.md)：后台服务扩展能力，提供后台运行并对外提供相应能力。 |
| ACCESSIBILITY    | 4   | [AccessibilityExtensionAbility](js-apis-application-AccessibilityExtensionAbility.md)：无障碍服务扩展能力，支持访问与操作前台界面。 |
| DATA_SHARE       | 5   | [DataShareExtensionAbility](../../database/database-datashare-guidelines.md)：数据共享扩展能力，用于对外提供数据读写服务。 |
| FILE_SHARE       | 6   | FileShareExtensionAbility：文件共享扩展能力，用于应用间的文件分享。预留能力，当前暂未支持。 |
| STATIC_SUBSCRIBER| 7   | [StaticSubscriberExtensionAbility](js-apis-application-staticSubscriberExtensionAbility.md)：静态广播扩展能力，用于处理静态事件，比如开机事件。 |
| WALLPAPER        | 8   | WallpaperExtensionAbility：壁纸扩展能力，用于实现桌面壁纸。预留能力，当前暂未支持。 |
| BACKUP           |  9  | BackupExtensionAbility：数据备份扩展能力，提供应用数据和公共数据备份回复能力。预留能力，当前暂未支持。 |
| WINDOW           |  10 | [WindowExtensionAbility](js-apis-application-WindowExtensionAbility.md)：界面组合扩展能力，允许系统应用进行跨应用的界面拉起和嵌入。 |
| ENTERPRISE_ADMIN |  11 | [EnterpriseAdminExtensionAbility](js-apis-EnterpriseAdminExtensionAbility.md)：企业设备管理扩展能力，提供企业管理时处理管理事件的能力，比如设备上应用安装事件、锁屏密码输入错误次数过多事件等。 |
| THUMBNAIL        | 13  | ThumbnailExtensionAbility：文件缩略图扩展能力，用于为文件提供图标缩略图的能力。预留能力，当前暂未支持。 |
| PREVIEW          | 14  | PreviewExtensionAbility：文件预览扩展能力，提供文件预览的能力，其他应用可以直接在应用中嵌入显示。预留能力，当前暂未支持。 |
| UNSPECIFIED      | 255 | 不指定类型，配合queryExtensionAbilityInfo接口可以查询所有类型的ExtensionAbility。 |


### PermissionGrantState

指示权限授予信息。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称 | 值 | 说明 |
|:----------------:|:---:|:---:|
| PERMISSION_DENIED|  -1 | 拒绝授予权限。 |
| PERMISSION_GRANTED |  0  |  授予权限。  |

### SupportWindowMode

标识该组件所支持的窗口模式。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称 | 值 | 说明 |
|:----------------:|:---:|:---:|
| FULL_SCREEN      | 0   | 窗口支持全屏显示。 |
| SPLIT            | 1   | 窗口支持分屏显示。 |
| FLOATING         | 2   | 支持窗口化显示。   |

### LaunchType

指示组件的启动方式。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称 | 值 | 说明 |
|:----------------:|:---:|:---:|
| SINGLETON        | 0   | ability的启动模式,表示单实例。 |
| STANDARD         | 1   | ability的启动模式,表示普通多实例。 |
| SPECIFIED        | 2   | ability的启动模式,表示该ability内部根据业务自己置顶多实例。 |

### AbilityType

指示Ability组件的类型。

 **模型约束:** 仅可在FA模型下使用

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

|  名称   | 值   |                            说明                            |
| :-----: | ---- | :--------------------------------------------------------: |
|  PAGE   | 1    |     表示基于Page模板开发的FA，用于提供与用户交互的能力。     |
| SERVICE | 2    |  表示基于Service模板开发的PA，用于提供后台运行任务的能力。   |
|  DATA   | 3    | 表示基于Data模板开发的PA，用于对外部提供统一的数据访问对象。 |

### DisplayOrientation

标识该Ability的显示模式。该标签仅适用于page类型的Ability。

 **系统能力:** 以下各项对应的系统能力均为SystemCapability.BundleManager.BundleFramework.Core。

| 名称                               |值 |说明 |
|:----------------------------------|---|---|
| UNSPECIFIED                        |0 |表示未定义方向模式，由系统判定。 |
| LANDSCAPE                          |1 |表示横屏显示模式。 |
| PORTRAIT                           |2 |表示竖屏显示模式。 |
| FOLLOW_RECENT                      |3 |表示跟随上一个显示模式。 |
| LANDSCAPE_INVERTED                 |4 |表示反向横屏显示模式。 |
| PORTRAIT_INVERTED                  |5 |表示反向竖屏显示模式。 |
| AUTO_ROTATION                      |6 |表示传感器自动旋转模式。 |
| AUTO_ROTATION_LANDSCAPE            |7 |表示传感器自动横向旋转模式。 |
| AUTO_ROTATION_PORTRAIT             |8 |表示传感器自动竖向旋转模式。 |
| AUTO_ROTATION_RESTRICTED           |9 |表示受开关控制的自动旋转模式。 |
| AUTO_ROTATION_LANDSCAPE_RESTRICTED |10|表述受开关控制的自动横向旋转模式。|
| AUTO_ROTATION_PORTRAIT_RESTRICTED  |11|表示受开关控制的自动竖向旋转模式。|
| LOCKED                             |12|表示锁定模式。|

## 方法

### bundleManager.getBundleInfoForSelf

getBundleInfoForSelf(bundleFlags: [number](#bundleflag)): Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>;

以异步方法根据给定的bundleFlags获取当前应用的BundleInfo，使用Promise形式返回结果。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| bundleFlags | [number](#bundleflag) | 是   | 指定返回的BundleInfo所包含的信息。 |

**返回值：**

| 类型                                                        | 说明                                  |
| ----------------------------------------------------------- | ------------------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise对象，返回当前应用的BundleInfo。|

**错误码：**

错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;
try {
    bundleManager.getBundleInfoForSelf(bundleFlags).then((data) => {
        console.info('getBundleInfoForSelf successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getBundleInfoForSelf failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInfoForSelf failed:' + error.message);
}
```

### bundleManager.getBundleInfoForSelf

getBundleInfoForSelf(bundleFlags: [number](#bundleflag), callback: AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>): void;

以异步方法根据给定的bundleFlags获取当前应用的BundleInfo，使用callback形式返回结果。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                |
| ----------- | ------ | ---- | --------------------- |
| bundleFlags | [number](#bundleflag) | 是   | 指定返回的BundleInfo所包含的信息。 |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | 是 | 回调函数，当获取成功时，err为null，data为获取到的当前应用的BundleInfo；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleInfoForSelf(bundleFlags, (err, data) => {
        if (err) {
            console.error('getBundleInfoForSelf failed:' + err.message);
        } else {
            console.info('getBundleInfoForSelf successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleInfoForSelf failed:' + err.message);
}
```

### bundleManager.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, userId: number, callback: AsyncCallback\<BundleInfo>): void;

以异步方法根据给定的bundleName、bundleFlags和userId获取BundleInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 表示要查询的应用程序包名称。    |
| bundleFlags | [number](#bundleflag) | 是   | 指定返回的BundleInfo所包含的信息。|
| userId      | number | 是   | 表示用户ID。  |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | 是 | 回调函数，当获取成功时，err为null，data为获取到的bundleInfo；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
// 额外获取AbilityInfo
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_ABILITY;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
        if (err) {
            console.error('getBundleInfo failed:' + err.message);
        } else {
            console.info('getBundleInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleInfo failed:' + err.message);
}
```

```ts
// 额外获取ApplicationInfo中的metadata
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_METADATA;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId, (err, data) => {
        if (err) {
            console.error('getBundleInfo failed:' + err.message);
        } else {
            console.info('getBundleInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleInfo failed:' + err.message);
}
```

### bundleManager.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: number, callback: AsyncCallback\<BundleInfo>): void;

以异步方法根据给定的bundleName和bundleFlags获取BundleInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 表示要查询的应用程序包名称。    |
| bundleFlags | [number](#bundleflag) | 是   | 指定返回的BundleInfo所包含的信息。|
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | 是 | 回调函数，当获取成功时，err为null，data为获取到的BundleInfo；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
// 额外获取extensionAbility
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_HAP_MODULE | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_EXTENSION_ABILITY;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, (err, data) => {
        if (err) {
            console.error('getBundleInfo failed:' + err.message);
        } else {
            console.info('getBundleInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleInfo failed:' + err.message);
}
```

### bundleManager.getBundleInfo

getBundleInfo(bundleName: string, bundleFlags: [number](#bundleflag), userId?: number): Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>;

以异步方法根据给定的bundleName、bundleFlags和userId获取BundleInfo，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ----------- | ------ | ---- | ---------------------------- |
| bundleName  | string | 是   | 表示要查询的应用程序包名称。 |
| bundleFlags | [number](#bundleflag) | 是   | 指定返回的BundleInfo所包含的信息。       |
| userId      | number | 否   | 表示用户ID。  |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise对象，返回BundleInfo。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。
| 错误码ID | 错误信息                            |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
// 额外获取ApplicationInfo和SignatureInfo
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
let userId = 100;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags, userId).then((data) => {
        console.info('getBundleInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getBundleInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInfo failed. Cause: ' + error.message);
}
```

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleInfo(bundleName, bundleFlags).then((data) => {
        console.info('getBundleInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getBundleInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleInfo failed. Cause: ' + error.message);
}

```

### bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: [number](#applicationflag), userId: number, callback: AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>): void;

以异步方法根据给定的bundleName、appFlags和userId获取ApplicationInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | 是   | 表示要查询的应用程序包名称。 |
| appFlags   | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。    |
| userId     | number | 是   | 表示用户ID。  |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | 是 | 回调函数，当获取成功时，err为null，data为获取到的ApplicationInfo；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, userId, (err, data) => {
        if (err) {
            console.error('getApplicationInfo failed:' + err.message);
        } else {
            console.info('getApplicationInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getApplicationInfo failed:' + err.message);
}
```

### bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: [number](#applicationflag), callback: AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>): void;

以异步方法根据给定的bundleName和appFlags获取ApplicationInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | 是   | 表示要查询的应用程序包名称。 |
| appFlags   | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。    |
| callback | AsyncCallback\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | 是 | 回调函数，当获取成功时，err为null，data为获取到的ApplicationInfo；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, (err, data) => {
        if (err) {
            console.error('getApplicationInfo failed:' + err.message);
        } else {
            console.info('getApplicationInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getApplicationInfo failed:' + err.message);
}
```

### bundleManager.getApplicationInfo

getApplicationInfo(bundleName: string, appFlags: [number](#applicationflag), userId?: number): Promise\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>;

以异步方法根据给定的bundleName、appFlags和userId获取ApplicationInfo，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ---------------------------- |
| bundleName | string | 是   | 表示要查询的应用程序包名称。 |
| appFlags   | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。    |
| userId     | number | 否   | 表示用户ID。 |

**返回值：**

| 类型                                                         | 说明                             |
| ------------------------------------------------------------ | -------------------------------- |
| Promise\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Promise对象，返回ApplicationInfo。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_PERMISSION;
let userId = 100;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, userId).then((data) => {
        console.info('getApplicationInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getApplicationInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getApplicationInfo failed. Cause: ' + error.message);
}
```

### bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: [number](#bundleflag), userId: number, callback: AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>>): void;

以异步方法根据给定的bundleFlags和userId获取多个BundleInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                             |
| ----------- | ------ | ---- | -------------------------------------------------- |
| bundleFlags | [number](#bundleflag) | 是   | 指定返回的BundleInfo所包含的信息。                    |
| userId      | number | 是   | 表示用户ID。                      |
| callback | AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | 是 | 回调函数，当获取成功时，err为null，data为获取到的Array\<BundleInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                         |
| -------- | --------------------------------- |
| 17700004 | The specified userId is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
let userId = 100;

try {
    bundleManager.getAllBundleInfo(bundleFlags, userId, (err, data) => {
        if (err) {
            console.error('getAllBundleInfo failed:' + err.message);
        } else {
            console.info('getAllBundleInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAllBundleInfo failed:' + err.message);
}
```

### bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: [number](#bundleflag), callback: AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>>): void;

以异步方法根据给定的bundleFlags获取多个BundleInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                             |
| ----------- | ------ | ---- | -------------------------------------------------- |
| bundleFlags | [number](#bundleflag) | 是   | 指定返回的BundleInfo所包含的信息。   |
| callback | AsyncCallback<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | 是 | 回调函数，当获取成功时，err为null，data为获取到的Array\<BundleInfo>；否则为错误对象。 |

**错误码：**

错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getAllBundleInfo(bundleFlags, (err, data) => {
        if (err) {
            console.error('getAllBundleInfo failed:' + err.message);
        } else {
            console.info('getAllBundleInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAllBundleInfo failed:' + err.message);
}
```

### bundleManager.getAllBundleInfo

getAllBundleInfo(bundleFlags: [number](#bundleflag), userId?: number): Promise<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>>;

以异步方法根据给定的bundleFlags和userId获取多个BundleInfo，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                             |
| ----------- | ------ | ---- | -------------------------------------------------- |
| bundleFlags | [number](#bundleflag) | 是   | 指定返回的BundleInfo所包含的信息。                   |
| userId      | number | 否   | 表示用户ID。                         |

**返回值：**

| 类型                                                         | 说明                                |
| ------------------------------------------------------------ | ----------------------------------- |
| Promise<Array\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>> | Promise对象，返回Array\<BundleInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                         |
| -------- | ---------------------------------- |
| 17700004 | The specified userId is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getAllBundleInfo(bundleFlags).then((data) => {
        console.info('getAllBundleInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getAllBundleInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getAllBundleInfo failed. Cause: ' + error.message);
}
```

### bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: [number](#applicationflag), userId: number, callback: AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>>): void;

以异步方法根据给定的appFlags和userId获取多个ApplicationInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                      |
| -------- | ------ | ---- | ----------------------------------------------------------- |
| appFlags | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。                       |
| userId   | number | 是   | 表示用户ID。         |
| callback | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | 是 | 回调函数，当获取成功时，err为null，data为获取到的Array\<ApplicationInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                         |
| -------- | ---------------------------------- |
| 17700004 | The specified userId is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    bundleManager.getAllApplicationInfo(appFlags, userId, (err, data) => {
        if (err) {
            console.error('getAllApplicationInfo failed:' + err.message);
        } else {
            console.info('getAllApplicationInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAllApplicationInfo failed:' + err.message);
}
```

### bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: [number](#applicationflag), callback: AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>>): void;

以异步方法根据给定的appFlags获取多个ApplicationInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                      |
| -------- | ------ | ---- | ----------------------------------------------------------- |
| appFlags | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。                       |
| callback | AsyncCallback<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | 是 | 回调函数，当获取成功时，err为null，data为获取到的Array\<ApplicationInfo>；否则为错误对象。 |

**错误码：**

错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    bundleManager.getAllApplicationInfo(appFlags, (err, data) => {
        if (err) {
            console.error('getAllApplicationInfo failed:' + err.message);
        } else {
            console.info('getAllApplicationInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAllApplicationInfo failed:' + err.message);
}
```

### bundleManager.getAllApplicationInfo

getAllApplicationInfo(appFlags: [number](#applicationflag), userId?: number): Promise<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>>;

以异步方法根据给定的appFlags和userId获取多个ApplicationInfo，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                      |
| -------- | ------ | ---- | ---------------------------------------------------------- |
| appFlags | [number](#applicationflag) | 是   | 指定返回的ApplicationInfo所包含的信息。                       |
| userId   | number | 否   | 表示用户ID。                                  |

**返回值：**

| 类型                                                         | 说明                                     |
| ------------------------------------------------------------ | ---------------------------------------- |
| Promise<Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)>> | Promise对象，返回Array\<ApplicationInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                         |
| -------- | ---------------------------------- |
| 17700004 | The specified userId is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    bundleManager.getAllApplicationInfo(appFlags).then((data) => {
        console.info('getAllApplicationInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getAllApplicationInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getAllApplicationInfo failed. Cause: ' + error.message);
}

```

### bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: [number](#abilityflag), userId: number, callback: AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>>): void;

以异步方法根据给定的want、abilityFlags和userId获取多个AbilityInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                                                  |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | 是   | 表示包含要查询的应用程序包名称的Want。                    |
| abilityFlags | [number](#abilityflag) | 是   | 指定返回的AbilityInfo所包含的信息。                       |
| userId       | number | 是   | 表示用户ID。                               |
| callback | AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | 是 | 回调函数，当获取成功时，err为null，data为获取到的Array\<AbilityInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId, (err, data) => {
        if (err) {
            console.error('queryAbilityInfo failed:' + err.message);
        } else {
            console.info('queryAbilityInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('queryAbilityInfo failed:' + err.message);
}
```

### bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: [number](#abilityflag), callback: AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>>): void;

以异步方法根据给定的want和abilityFlags获取一个或多个AbilityInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                                                  |
| ------------ | ------ | ---- | -------------------------------------------------------|
| want         | Want   | 是   | 表示包含要查询的应用程序包名称的Want。                    |
| abilityFlags | [number](#abilityflag) | 是   | 指定返回的AbilityInfo所包含的信息。       |
| callback | AsyncCallback<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | 是 | 回调函数，当获取成功时，err为null，data为获取到的Array\<AbilityInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid. |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, (err, data) => {
        if (err) {
            console.error('queryAbilityInfo failed:' + err.message);
        } else {
            console.info('queryAbilityInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('queryAbilityInfo failed:' + err.message);
}
```

### bundleManager.queryAbilityInfo

queryAbilityInfo(want: Want, abilityFlags: [number](#abilityflag), userId?: number): Promise<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>>;

以异步方法根据给定的want、abilityFlags和userId获取一个或多个AbilityInfo，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                                                  |
| ------------ | ------ | ---- | ------------------------------------------------------- |
| want         | Want   | 是   | 表示包含要查询的应用程序包名称的Want。                    |
| abilityFlags | [number](#abilityflag) | 是   | 表示指定返回的AbilityInfo所包含的信息。 |
| userId       | number | 否   | 表示用户ID。                               |

**返回值：**

| 类型                                                         | 说明                                 |
| ------------------------------------------------------------ | ------------------------------------ |
| Promise<Array\<[AbilityInfo](js-apis-bundleManager-abilityInfo.md)>> | Promise对象，返回Array\<AbilityInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified ability is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |
| 17700029 | The specified ability is disabled.     |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((data) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryAbilityInfo(want, abilityFlags).then((data) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    })
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: [ExtensionAbilityType](#extensionabilitytype), extensionAbilityFlags: [number](#extensionabilityflag), userId: number, callback: AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>>): void;

以异步方法根据给定的want、extensionAbilityType、extensionAbilityFlags和userId获取一个或多个ExtensionAbilityInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型                                                         | 必填 | 说明                                                         |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want                  | Want                                                         | 是   | 表示包含要查询的应用程序包名称的Want。                         |
| extensionAbilityType  | [ExtensionAbilityType](#extensionabilitytype)                | 是   | 标识extensionAbility的类型。                                   |
| extensionAbilityFlags | [number](#extensionabilityflag)                              | 是   | 表示用于指定将返回的ExtensionInfo对象中包含的信息的标志。      |
| userId                | number                                                       | 是   | 表示用户ID。                                                   |
| callback              | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | 是   | 回调函数，当获取成功时，err为null，data为获取到Array\<ExtensionAbilityInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.             |
| 17700026 | The specified bundle is disabled.            |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, userId, (err, data) => {
        if (err) {
            console.error('queryExtensionAbilityInfo failed:' + err.message);
        } else {
            console.info('queryExtensionAbilityInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('queryExtensionAbilityInfo failed:' + err.message);
}
```

### bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: [ExtensionAbilityType](#extensionabilitytype), extensionAbilityFlags: [number](#extensionabilityflag), callback: AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>>): void;

以异步方法根据给定的want、extensionAbilityType和extensionAbilityFlags获取一个或多个ExtensionAbilityInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型                                                         | 必填 | 说明                                                         |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| want                  | Want                                                         | 是   | 表示包含要查询的应用程序包名称的Want。                         |
| extensionAbilityType  | [ExtensionAbilityType](#extensionabilitytype)                | 是   | 标识extensionAbility的类型。                                   |
| extensionAbilityFlags | [number](#extensionabilityflag)                              | 是   | 表示用于指定将返回的ExtensionInfo对象中包含的信息的标志。      |
| callback              | AsyncCallback<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | 是   | 回调函数，当获取成功时，err为null，data为获取到Array\<ExtensionAbilityInfo>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 17700001 | The specified bundleName is not found.       |
| 17700003 | The specified extensionAbility is not found. |
| 17700004 | The specified userId is invalid.             |
| 17700026 | The specified bundle is disabled.            |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, (err, data) => {
        if (err) {
            console.error('queryExtensionAbilityInfo failed:' + err.message);
        } else {
            console.info('queryExtensionAbilityInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('queryExtensionAbilityInfo failed:' + err.message);
}
```

### bundleManager.queryExtensionAbilityInfo

queryExtensionAbilityInfo(want: Want, extensionAbilityType: [ExtensionAbilityType](#extensionabilitytype), extensionAbilityFlags: [number](#extensionabilityflag), userId?: number): Promise<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>>;

以异步方法根据给定的want、extensionAbilityType、extensionAbilityFlags和userId获取ExtensionAbilityInfo，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型                                          | 必填 | 说明                                                    |
| --------------------- | --------------------------------------------- | ---- | ------------------------------------------------------- |
| want                  | Want                                          | 是   | 表示包含要查询的应用程序包名称的Want。                    |
| extensionAbilityType  | [ExtensionAbilityType](#extensionabilitytype) | 是   | 标识extensionAbility的类型。                              |
| extensionAbilityFlags | [number](#extensionabilityflag)               | 是   | 表示用于指定将返回的ExtensionInfo对象中包含的信息的标志。 |
| userId                | number                                        | 否   | 表示用户ID。                                              |

**返回值：**

| 类型                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise<Array\<[ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md)>> | Promise对象，返回Array\<ExtensionAbilityInfo>。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700003 | The specified extensionAbility is not found.    |
| 17700004 | The specified userId is invalid.       |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'

let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags, userId).then((data) => {
        console.info('queryExtensionAbilityInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('queryExtensionAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryExtensionAbilityInfo failed. Cause: ' + error.message);
}
```

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let extensionAbilityType = bundleManager.ExtensionAbilityType.FORM;
let extensionFlags = bundleManager.ExtensionAbilityFlag.GET_EXTENSION_ABILITY_INFO_DEFAULT;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};

try {
    bundleManager.queryExtensionAbilityInfo(want, extensionAbilityType, extensionFlags).then((data) => {
        console.info('queryExtensionAbilityInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('queryExtensionAbilityInfo failed. Cause: ' + error.message);
    })
} catch (error) {
    console.error('queryExtensionAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.getBundleNameByUid

getBundleNameByUid(uid: number, callback: AsyncCallback\<string>): void;

以异步方法根据给定的uid获取bundleName，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uid      | number                 | 是   | 表示应用程序的UID。                                            |
| callback | AsyncCallback\<string> | 是   | 回调函数，当获取成功时，err为null，data为获取到的BundleName；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息            |
| -------- | --------------------- |
| 17700021 | The uid is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let uid = 20010005;
try {
    bundleManager.getBundleNameByUid(uid, (err, data) => {
        if (err) {
            console.error('getBundleNameByUid failed:' + err.message);
        } else {
            console.info('getBundleNameByUid successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleNameByUid failed:' + err.message);
}
```

### bundleManager.getBundleNameByUid

getBundleNameByUid(uid: number): Promise\<string>;

以异步方法根据给定的uid获取bundleName，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                |
| ---- | ------ | ---- | ------------------ |
| uid  | number | 是   | 表示应用程序的UID。 |

**返回值：**

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| Promise\<string> | Promise对象，返回bundleName。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息            |
| -------- | ---------------------|
| 17700021 | The uid is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let uid = 20010005;
try {
    bundleManager.getBundleNameByUid(uid).then((data) => {
        console.info('getBundleNameByUid successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getBundleNameByUid failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleNameByUid failed. Cause: ' + error.message);
}
```

### bundleManager.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string, bundleFlags: [number](#bundleflag), callback: AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>): void;

以异步方法根据给定的hapFilePath和bundleFlags获取BundleInfo，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                         |
| ----------- | ------ | ---- | ----------------------------------------------------------- |
| hapFilePath | string | 是   | 表示存储HAP的路径，路径应该是当前应用程序数据目录的相对路径。 |
| bundleFlags | [number](#bundleflag) | 是   | 表示用于指定要返回的BundleInfo对象中包含的信息的标志。       |
| callback | AsyncCallback\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | 是 | 回调函数，当获取成功时，err为null，data为获取到的BundleInfo；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                  |
| -------- | --------------------------- |
| 17700022 | The hapFilePath is invalid. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleArchiveInfo(hapFilePath, bundleFlags, (err, data) => {
        if (err) {
            console.error('getBundleArchiveInfo failed:' + err.message);
        } else {
            console.info('getBundleArchiveInfo successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getBundleArchiveInfo failed:' + err.message);
}
```

### bundleManager.getBundleArchiveInfo

getBundleArchiveInfo(hapFilePath: string,  bundleFlags: [number](#bundleflag)): Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)>;

以异步方法根据给定的hapFilePath和bundleFlags获取BundleInfo，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| hapFilePath | string | 是   | 表示存储HAP的路径，路径应该是当前应用程序数据目录的相对路径。 |
| bundleFlags | [number](#bundleflag) | 是   | 表示用于指定要返回的BundleInfo对象中包含的信息的标志。       |

**返回值：**

| 类型                                                        | 说明                        |
| ----------------------------------------------------------- | --------------------------- |
| Promise\<[BundleInfo](js-apis-bundleManager-bundleInfo.md)> | Promise对象，返回BundleInfo。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                   |
| -------- | -------------------------- |
| 17700022 | The hapFilePath is invalid. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let hapFilePath = "/data/xxx/test.hap";
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_DEFAULT;

try {
    bundleManager.getBundleArchiveInfo(hapFilePath, bundleFlags).then((data) => {
        console.info('getBundleArchiveInfo successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getBundleArchiveInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getBundleArchiveInfo failed. Cause: ' + error.message);
}
```

### bundleManager.cleanBundleCacheFiles

cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void;

以异步方法根据给定的bundleName清理BundleCache，并获取清理结果，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REMOVE_CACHE_FILES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                                                         |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | 是   | 表示要清理其缓存数据的应用程序的bundleName。                   |
| callback   | AsyncCallback\<void> | 是   | 回调函数，当清理应用缓存目录数据成功，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17700001 | The specified bundleName is not found.                        |
| 17700030 | The specified bundleName does not support cleaning cache files. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.cleanBundleCacheFiles(bundleName, err => {
        if (err) {
            console.error('cleanBundleCacheFiles failed:' + err.message);
        } else {
            console.info('cleanBundleCacheFiles successfully.');
        }
    });
} catch (err) {
    console.error('cleanBundleCacheFiles failed:' + err.message);
}
```

### bundleManager.cleanBundleCacheFiles

cleanBundleCacheFiles(bundleName: string): Promise\<void>;

以异步方法根据给定的bundleName清理BundleCache，并获取清理结果，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.REMOVE_CACHE_FILES

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                       |
| ---------- | ------ | ---- | ------------------------------------------ |
| bundleName | string | 是   | 表示要清理其缓存数据的应用程序的bundleName。 |

**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象，返回true表示清理应用缓存目录数据成功，返回false表示清理应用缓存目录数据失败。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                   |
| -------- | ---------------------------------------------------------- |
| 17700001 | The specified bundleName is not found.                      |
| 17700030 | The specified bundle does not support cleaning cache files. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.cleanBundleCacheFiles(bundleName).then(()=> {
        console.info('cleanBundleCacheFiles successfully.');
    }).catch(err=> {
        console.error('cleanBundleCacheFiles failed:' + err.message);
    });
} catch (err) {
    console.error('cleanBundleCacheFiles failed:' + err.message);
}
```

### bundleManager.setApplicationEnabled

setApplicationEnabled(bundleName: string, isEnabled: boolean, callback: AsyncCallback\<void>): void;

设置指定应用的禁用使能状态，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                                  |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | 是   | 指定应用的bundleName。                |
| isEnabled  | boolean | 是   | 值为true表示使能，值为false表示禁用。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，当设置应用禁用使能状态成功时，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabled(bundleName, false, err => {
        if (err) {
            console.error('setApplicationEnabled failed:' + err.message);
        } else {
            console.info('setApplicationEnabled successfully.');
        }
    });
} catch (err) {
    console.error('setApplicationEnabled failed:' + err.message);
}
```

### bundleManager.setApplicationEnabled

setApplicationEnabled(bundleName: string, isEnabled: boolean): Promise\<void>;

设置指定应用的禁用使能状态，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型    | 必填 | 说明                                  |
| ---------- | ------- | ---- | ------------------------------------- |
| bundleName | string  | 是   | 表示应用程序的bundleName。            |
| isEnabled  | boolean | 是   | 值为true表示使能，值为false表示禁用。 |

**返回值：**

| 类型           | 说明                                 |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = "com.ohos.myapplication";

try {
    bundleManager.setApplicationEnabled(bundleName, false).then(()=> {
        console.info('setApplicationEnabled successfully.');
    }).catch(err=> {
        console.error('setApplicationEnabled failed:' + err.message);
    });
} catch (err) {
    console.error('setApplicationEnabled failed:' + err.message);
}
```

### bundleManager.setAbilityEnabled

setAbilityEnabled(info: [AbilityInfo](js-apis-bundleManager-abilityInfo.md), isEnabled: boolean, callback: AsyncCallback\<void>): void;

设置指定组件的禁用使能状态，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型        | 必填 | 说明                                  |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 需要被设置的组件。              |
| isEnabled| boolean     | 是   | 值为true表示使能，值为false表示禁用。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，当设置组件禁用使能状态成功时，err为null，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ---------------------------------------|
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
var info;

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(abilitiesInfo));
        info = abilitiesInfo[0];

        bundleManager.setAbilityEnabled(info, false, err => {
            if (err) {
                console.error('setAbilityEnabled failed:' + err.message);
            } else {
                console.info('setAbilityEnabled successfully.');
            }
        });
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.setAbilityEnabled

setAbilityEnabled(info: [AbilityInfo](js-apis-bundleManager-abilityInfo.md), isEnabled: boolean): Promise\<void>;

设置指定组件的禁用使能状态，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CHANGE_ABILITY_ENABLED_STATE

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名    | 类型        | 必填 | 说明                                  |
| -------- | ----------- | ---- | ------------------------------------- |
| info     | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 需要被设置的组件。                   |
| isEnabled| boolean     | 是   | 值为true表示使能，值为false表示禁用。 |

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityInfo is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
var info;

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(abilitiesInfo));
        info = abilitiesInfo[0];

        bundleManager.setAbilityEnabled(info, false).then(()=> {
            console.info('setAbilityEnabled successfully.');
        }).catch(err=> {
            console.error('setAbilityEnabled failed:' + err.message);
        });
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.isApplicationEnabled

isApplicationEnabled(bundleName: string, callback: AsyncCallback\<boolean>): void;

以异步的方法获取指定应用的禁用使能状态，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | 是   | 表示应用程序的bundleName。 |
| callback | AsyncCallback\<boolean> | 是 | 回调函数，返回true表示当前应用为使能状态，返回false表示应用为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';

try {
    bundleManager.isApplicationEnabled(bundleName, (err, data) => {
        if (err) {
            console.error('isApplicationEnabled failed:' + err.message);
        } else {
            console.info('isApplicationEnabled successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('isApplicationEnabled failed:' + err.message);
}
```

### bundleManager.isApplicationEnabled

isApplicationEnabled(bundleName: string): Promise\<boolean>;

以异步的方法获取指定应用的禁用使能状态，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | -------------------------- |
| bundleName | string | 是   | 表示应用程序的bundleName。  |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise对象，返回true表示当前应用为使能状态，返回false表示当前应用为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';

try {
    bundleManager.isApplicationEnabled(bundleName).then((data) => {
        console.info('isApplicationEnabled successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('isApplicationEnabled failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('isApplicationEnabled failed. Cause: ' + error.message);
}
```

### bundleManager.isAbilityEnabled

isAbilityEnabled(info: [AbilityInfo](js-apis-bundleManager-abilityInfo.md), callback: AsyncCallback\<boolean>): void;

以异步的方法获取指定组件的禁用使能状态，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                        |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 表示关于检查ability的信息。 |
| callback | AsyncCallback\<boolean> | 是 | 回调函数，返回true表示当前应用组件为使能状态，返回false表示应用组件为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | --------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
var info;

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(abilitiesInfo));
        info = abilitiesInfo[0];

        bundleManager.isAbilityEnabled(info, (err, data) => {
            if (err) {
                console.error('isAbilityEnabled failed:' + err.message);
            } else {
                console.info('isAbilityEnabled successfully:' + JSON.stringify(data));
            }
        });
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.isAbilityEnabled

isAbilityEnabled(info: [AbilityInfo](js-apis-bundleManager-abilityInfo.md)): Promise\<boolean>;

以异步的方法获取指定组件的禁用使能状态，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名 | 类型        | 必填 | 说明                        |
| ---- | ----------- | ---- | --------------------------- |
| info | [AbilityInfo](js-apis-bundleManager-abilityInfo.md) | 是   | 表示关于检查ability的信息。 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise对象，返回true表示当前应用组件为使能状态，返回false表示当前应用组件为禁用状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | --------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700003 | The specified abilityName is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let abilityFlags = bundleManager.AbilityFlag.GET_ABILITY_INFO_DEFAULT;
let userId = 100;
let want = {
    bundleName : "com.example.myapplication",
    abilityName : "com.example.myapplication.MainAbility"
};
var info;

try {
    bundleManager.queryAbilityInfo(want, abilityFlags, userId).then((abilitiesInfo) => {
        console.info('queryAbilityInfo successfully. Data: ' + JSON.stringify(abilitiesInfo));
        info = abilitiesInfo[0];

        bundleManager.isAbilityEnabled(info).then((data) => {
            console.info('isAbilityEnabled successfully. Data: ' + JSON.stringify(data));
        }).catch(err => {
            console.error('isAbilityEnabled failed. Cause: ' + err.message);
        });
    }).catch(error => {
        console.error('queryAbilityInfo failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('queryAbilityInfo failed. Cause: ' + error.message);
}
```

### bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, userId: number, callback: AsyncCallback\<Want>): void;

以异步方法根据给定的bundleName和userId获取用于启动应用程序主要功能，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                                                         |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | 是   | 表示应用程序的bundleName。                                     |
| userId     | number               | 是   | 表示用户ID。                                                   |
| callback   | AsyncCallback\<Want> | 是   | 回调函数，当获取成功时，err为null，data为获取到的Want；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    bundleManager.getLaunchWantForBundle(bundleName, userId, (err, data) => {
        if (err) {
            console.error('getLaunchWantForBundle failed:' + err.message);
        } else {
            console.info('getLaunchWantForBundle successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getLaunchWantForBundle failed:' + err.message);
}
```

### bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, callback: AsyncCallback\<Want>): void;

以异步方法根据给定的bundleName获取用于启动应用程序主要功能，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                                                         |
| ---------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string               | 是   | 表示应用程序的bundleName。                                     |
| callback   | AsyncCallback\<Want> | 是   | 回调函数，当获取成功时，err为null，data为获取到的Want；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified user ID is not found. |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';

try {
    bundleManager.getLaunchWantForBundle(bundleName, (err, data) => {
        if (err) {
            console.error('getLaunchWantForBundle failed:' + err.message);
        } else {
            console.info('getLaunchWantForBundle successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getLaunchWantForBundle failed:' + err.message);
}
```

### bundleManager.getLaunchWantForBundle

getLaunchWantForBundle(bundleName: string, userId?: number): Promise\<Want>;

以异步方法根据给定的bundleName和userId获取用于启动应用程序主要功能，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                       |
| ---------- | ------ | ---- | ------------------------- |
| bundleName | string | 是   | 表示应用程序的bundleName。 |
| userId     | number | 否   | 表示用户ID。               |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<Want> | Promise对象，返回Want对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | --------------------------------------|
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let userId = 100;

try {
    bundleManager.getLaunchWantForBundle(bundleName, userId).then((data) => {
        console.info('getLaunchWantForBundle successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getLaunchWantForBundle failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getLaunchWantForBundle failed. Cause: ' + error.message);
}
```

### bundleManager.getProfileByAbility

getProfileByAbility(moduleName: string, abilityName: string, metadataName: string, callback: AsyncCallback<Array\<string>>): void;

以异步方法根据给定的moduleName、abilityName和metadataName获取相应配置文件的json格式字符串，使用callback形式返回结果。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| moduleName   | string                        | 是   | 表示应用程序的moduleName。                                     |
| abilityName  | string                        | 是   | 表示应用程序的abilityName。                                    |
| metadataName | string                        | 是   | 表示应用程序的metadataName。                                  |
| callback     | AsyncCallback<Array\<string>> | 是   | 回调函数，当获取成功时，err为null，data为获取到的Array\<string>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified abilityName is not existed.                     |
| 17700024 | The specified metadataName is not existed or the profile is not json-format. |
| 17700026 | The specified bundle is disabled.                             |
| 17700029 | The specified ability is disabled.                            |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let moduleName = 'entry';
let abilityName = 'MainAbility';
let metadataName = 'com.example.myapplication.metadata';

try {
    bundleManager.getProfileByAbility(moduleName, abilityName, metadataName, (err, data) => {
        if (err) {
            console.error('getProfileByAbility failed:' + err.message);
        } else {
            console.info('getProfileByAbility successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getProfileByAbility failed:' + err.message);
}
```

### bundleManager.getProfileByAbility

getProfileByAbility(moduleName: string, abilityName: string, metadataName?: string): Promise<Array\<string>>;

以异步方法根据给定的moduleName、abilityName和metadataName获取相应配置文件的json格式字符串，使用Promise形式返回结果。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                       |
| ------------ | ------ | ---- | -------------------------- |
| moduleName   | string | 是   | 表示应用程序的moduleName。   |
| abilityName  | string | 是   | 表示应用程序的abilityName。  |
| metadataName | string | 否   | 表示应用程序的metadataName。 |

**返回值：**

| 类型                    | 说明                            |
| ----------------------- | ------------------------------- |
| Promise<Array\<string>> | Promise对象，返回Array\<string>。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified abilityName is not existed.                     |
| 17700024 | The specified metadataName is not existed or the profile is not json-format. |
| 17700026 | The specified bundle is disabled.                             |
| 17700029 | The specified ability is disabled.                            |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let moduleName = 'entry';
let abilityName = 'MainAbility';

try {
    bundleManager.getProfileByAbility(moduleName, abilityName).then((data) => {
        console.info('getProfileByAbility successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getProfileByAbility failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getProfileByAbility failed. Cause: ' + error.message);
}
```

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let moduleName = 'entry';
let abilityName = 'MainAbility';
let metadataName = 'com.example.myapplication.metadata';
try {
    bundleManager.getProfileByAbility(moduleName, abilityName, metadataName).then((data) => {
        console.info('getProfileByAbility successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getProfileByAbility failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getProfileByAbility failed. Cause: ' + error.message);
}
```

### bundleManager.getProfileByExtensionAbility

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName: string, callback: AsyncCallback<Array\<string>>): void;

以异步方法根据给定的moduleName、extensionAbilityName和metadataName获取相应配置文件的json格式字符串，使用callback形式返回结果。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名               | 类型                          | 必填 | 说明                                                         |
| -------------------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| moduleName           | string                        | 是   | 表示应用程序的moduleName。                                   |
| extensionAbilityName | string                        | 是   | 表示应用程序的extensionAbilityName。                         |
| metadataName         | string                        | 是   | 表示应用程序的metadataName。                                 |
| callback             | AsyncCallback<Array\<string>> | 是   | 回调函数，当获取成功时，err为null，data为获取到的Array\<string>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified extensionAbilityName is not existed.            |
| 17700024 | The specified metadataName is not existed or the profile is not json-format. |
| 17700026 | The specified bundle is disabled.                             |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let moduleName = 'entry';
let extensionAbilityName = 'com.example.myapplication.extension';
let metadataName = 'com.example.myapplication.metadata';

try {
    bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName, metadataName, (err, data) => {
        if (err) {
            console.error('getProfileByExtensionAbility failed:' + err.message);
        } else {
            console.info('getProfileByExtensionAbility successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getProfileByExtensionAbility failed:' + err.message);
}
```

### bundleManager.getProfileByExtensionAbility

getProfileByExtensionAbility(moduleName: string, extensionAbilityName: string, metadataName?: string): Promise<Array\<string>>;

以异步方法根据给定的moduleName、extensionAbilityName和metadataName获取相应配置文件的json格式字符串，使用Promise形式返回结果。

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名                | 类型   | 必填 | 说明                               |
| -------------------- | ------ | ---- | ---------------------------------- |
| moduleName           | string | 是   | 表示应用程序的moduleName。           |
| extensionAbilityName | string | 是   | 表示应用程序的extensionAbilityName。 |
| metadataName         | string | 否   | 表示应用程序的metadataName。         |

**返回值：**

| 类型                    | 说明                                |
| ----------------------- | ----------------------------------- |
| Promise<Array\<string>> | Promise对象，返回Array\<string>对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 17700002 | The specified moduleName is not existed.                      |
| 17700003 | The specified extensionAbilityName is not existed.            |
| 17700024 | The specified metadataName is not existed or the profile is not json-format. |
| 17700026 | The specified bundle is disabled.                             |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let moduleName = 'entry';
let extensionAbilityName = 'com.example.myapplication.extension';
let metadataName = 'com.example.myapplication.metadata';

try {
    bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName).then((data) => {
        console.info('getProfileByExtensionAbility successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getProfileByExtensionAbility failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getProfileByExtensionAbility failed. Cause: ' + error.message);
}

try {
    bundleManager.getProfileByExtensionAbility(moduleName, extensionAbilityName, metadataName).then((data) => {
        console.info('getProfileByExtensionAbility successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getProfileByExtensionAbility failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getProfileByExtensionAbility failed. Cause: ' + error.message);
}
```

### bundleManager.getPermissionDef

getPermissionDef(permissionName: string, callback: AsyncCallback\<[PermissionDef](js-apis-bundleManager-permissionDef.md)>): void;

以异步方法根据给定的permissionName获取PermissionDef，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名         | 类型                                                         | 必填 | 说明                                                         |
| -------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| permissionName | string                                                       | 是   | 表示权限名称。                                               |
| callback       | AsyncCallback\<[PermissionDef](js-apis-bundleManager-permissionDef.md)> | 是   | 回调函数，当获取成功时，err为null，data为获取到的Array\<PermissionDef>；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17700006 | The specified permission is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let permission = "ohos.permission.GET_BUNDLE_INFO";
try {
    bundleManager.getPermissionDef(permission, (err, data) => {
        if (err) {
            console.error('getPermissionDef failed:' + err.message);
        } else {
            console.info('getPermissionDef successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getPermissionDef failed:' + err.message);
}
```

### bundleManager.getPermissionDef

getPermissionDef(permissionName: string): Promise\<[PermissionDef](js-apis-bundleManager-permissionDef.md)>;

以异步方法根据给定的permissionName获取PermissionDef，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名          | 类型   | 必填 | 说明           |
| -------------- | ------ | ---- | -------------- |
| permissionName | string | 是   | 表示权限参数名。 |

**返回值：**

| 类型                                                         | 说明                                       |
| ------------------------------------------------------------ | ------------------------------------------ |
| Promise\<[PermissionDef](js-apis-bundleManager-permissionDef.md)> | Promise对象，返回Array\<PermissionDef>对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17700006 | The specified permission is not found. |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let permissionName = "ohos.permission.GET_BUNDLE_INFO";
try {
    bundleManager.getPermissionDef(permissionName).then((data) => {
        console.info('getPermissionDef successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getPermissionDef failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getPermissionDef failed. Cause: ' + error.message);
}
```

### bundleManager.getAbilityLabel

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string, callback: AsyncCallback\<string>): void;

以异步的方法获取指定bundleName、moduleName和abilityName的label，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名      | 类型                   | 必填 | 说明                                                         |
| ----------- | ---------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                 | 是   | 表示应用程序的bundleName。                                     |
| moduleName  | string                 | 是   | 表示应用程序的moduleName。                                     |
| abilityName | string                 | 是   | 表示应用程序的abilityName。                                    |
| callback    | AsyncCallback\<string> | 是   | 回调函数，当获取成功时，err为null，data为获指定组件的Label值；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'MainAbility';

try {
    bundleManager.getAbilityLabel(bundleName, moduleName, abilityName, (err, data) => {
        if (err) {
            console.error('getAbilityLabel failed:' + err.message);
        } else {
            console.info('getAbilityLabel successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAbilityLabel failed:' + err.message);
}
```

### bundleManager.getAbilityLabel

getAbilityLabel(bundleName: string, moduleName: string, abilityName: string): Promise\<string>;

以异步的方法获取指定bundleName、moduleName和abilityName的label，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名      | 类型   | 必填 | 说明                      |
| ----------- | ------ | ---- | ------------------------- |
| bundleName  | string | 是   | 表示应用程序的bundleName。  |
| moduleName  | string | 是   | 表示应用程序的moduleName。  |
| abilityName | string | 是   | 表示应用程序的abilityName。 |

**返回值：**

| 类型             | 说明                                |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise对象，返回指定组件的Lablel值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | --------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'MainAbility';

try {
    bundleManager.getAbilityLabel(bundleName, moduleName, abilityName).then((data) => {
        console.info('getAbilityLabel successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getAbilityLabel failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getAbilityLabel failed. Cause: ' + error.message);
}
```

### bundleManager.getAbilityIcon

getAbilityIcon(bundleName: string, moduleName: string, abilityName: string, callback: AsyncCallback<[image.PixelMap](js-apis-image.md#pixelmap7)>): void;

以异步的方法获取指定bundleName、moduleName和abilityName的icon，使用callback形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名      | 类型                                                        | 必填 | 说明                                                         |
| ----------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName  | string                                                      | 是   | 表示应用程序的bundleName。                                     |
| moduleName  | string                                                      | 是   | 表示应用程序的moduleName。                                     |
| abilityName | string                                                      | 是   | 表示应用程序的abilityName。                                    |
| callback    | AsyncCallback<[image.PixelMap](js-apis-image.md#pixelmap7)> | 是   | 回调函数，当获取成功时，err为null，data为指定组件icon的PixelMap对象；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                              |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'MainAbility';

try {
    bundleManager.getAbilityIcon(bundleName, moduleName, abilityName, (err, data) => {
        if (err) {
            console.error('getAbilityIcon failed:' + err.message);
        } else {
            console.info('getAbilityIcon successfully:' + JSON.stringify(data));
        }
    });
} catch (err) {
    console.error('getAbilityIcon failed:' + err.message);
}
```

### bundleManager.getAbilityIcon

getAbilityIcon(bundleName: string, moduleName: string, abilityName: string): Promise<[image.PixelMap](js-apis-image.md#pixelmap7)>;

以异步的方法获取指定bundleName、moduleName和abilityName的icon，使用Promise形式返回结果。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Resource

**参数：**

| 参数名      | 类型   | 必填 | 说明                      |
| ----------- | ------ | ---- | ------------------------- |
| bundleName  | string | 是   | 表示应用程序的bundleName。  |
| moduleName  | string | 是   | 表示应用程序的moduleName。  |
| abilityName | string | 是   | 表示应用程序的abilityName。 |

**返回值：**

| 类型                                                  | 说明                                        |
| ----------------------------------------------------- | ------------------------------------------- |
| Promise<[image.PixelMap](js-apis-image.md#pixelmap7)> | Promise对象，返回指定组件icon的PixelMap对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found.  |
| 17700002 | The specified moduleName is not found.  |
| 17700003 | The specified abilityName is not found. |
| 17700026 | The specified bundle is disabled.       |
| 17700029 | The specified ability is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let moduleName = 'entry';
let abilityName = 'MainAbility';

try {
    bundleManager.getAbilityIcon(bundleName, moduleName, abilityName).then((data) => {
        console.info('getAbilityIcon successfully. Data: ' + JSON.stringify(data));
    }).catch(error => {
        console.error('getAbilityIcon failed. Cause: ' + error.message);
    });
} catch (error) {
    console.error('getAbilityIcon failed. Cause: ' + error.message);
}
```

### bundleManager.getApplicationInfoSync

getApplicationInfoSync(bundleName: string, applicationFlags: number, userId: number) : [ApplicationInfo](js-apis-bundleManager-applicationInfo.md);

以同步方法根据给定的bundleName、applicationFlags和userId获取ApplicationInfo

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                       |
| ----------- | ------ | ---- | ----------------------------------------------------------|
| bundleName  | string | 是   | 表示应用程序的bundleName。                                  |
| applicationFlags | [number](#applicationflag) | 是   | 表示用于指定将返回的ApplicationInfo对象中包含的信息。       |
| userId      | number | 是   | 表示用户ID。                                         |

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | 返回ApplicationInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let applicationFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;
let userId = 100;

try {
    let data = bundleManager.getApplicationInfoSync(bundleName, applicationFlags, userId);
    console.info("getApplicationInfoSync successfully:" + JSON.stringify(data));
} catch (err) {
    console.error('getApplicationInfoSync failed:' + err.message);
}
```

### bundleManager.getApplicationInfoSync

getApplicationInfoSync(bundleName: string, applicationFlags: number) : [ApplicationInfo](js-apis-bundleManager-applicationInfo.md);

以同步方法根据给定的bundleName和applicationFlags获取ApplicationInfo

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                       |
| ----------- | ------ | ---- | ----------------------------------------------------------|
| bundleName  | string | 是   | 表示应用程序的bundleName。                                  |
| applicationFlags | [number](#applicationflag) | 是   | 表示用于指定将返回的ApplicationInfo对象中包含的信息。       |

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | 返回ApplicationInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | -------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let applicationFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_DEFAULT;

try {
    let data = bundleManager.getApplicationInfoSync(bundleName, applicationFlags);
    console.info("getApplicationInfoSync successfully:" + JSON.stringify(data));
} catch (err) {
    console.error('getApplicationInfoSync failed:' + err.message);
}
```

### bundleManager.getBundleInfoSync

getBundleInfoSync(bundleName: string, bundleFlags: [number](#bundleflag), userId: number): [BundleInfo](js-apis-bundleManager-bundleInfo.md);

以同步方法根据给定的bundleName、bundleFlags和userId获取BundleInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ----------- | ------ | ---- | -------------------------------------------------------- |
| bundleName  | string | 是   | 表示应用程序的bundleName。                                 |
| bundleFlags | [number](#bundleflag) | 是   | 表示用于指定将返回的BundleInfo对象中包含的信息的标志。 |
| userId      | number | 是   | 表示用户ID。                                             |

**返回值：**

| 类型       | 说明                 |
| ---------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | 返回BundleInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700004 | The specified userId is not found.     |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
let userId = 100;

try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags, userId);
    console.info("getBundleInfoSync successfully :" + JSON.stringify(data));
} catch (err) {
    console.error('getBundleInfoSync failed:' + err.message);
}
```

### bundleManager.getBundleInfoSync

getBundleInfoSync(bundleName: string, bundleFlags: [number](#bundleflag)): [BundleInfo](js-apis-bundleManager-bundleInfo.md);

以同步方法根据给定的bundleName和bundleFlags获取BundleInfo。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_BUNDLE_INFO_PRIVILEGED or ohos.permission.GET_BUNDLE_INFO

**系统能力：** SystemCapability.BundleManager.BundleFramework.Core

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                     |
| ----------- | ------ | ---- | -------------------------------------------------------- |
| bundleName  | string | 是   | 表示应用程序的bundleName。                                 |
| bundleFlags | [number](#bundleflag) | 是   | 表示用于指定将返回的BundleInfo对象中包含的信息的标志。 |

**返回值：**

| 类型       | 说明                 |
| ---------- | -------------------- |
| [BundleInfo](js-apis-bundleManager-bundleInfo.md) | 返回BundleInfo对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.bundle错误码](../errorcodes/errorcode-bundle.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------- |
| 17700001 | The specified bundleName is not found. |
| 17700026 | The specified bundle is disabled.      |

**示例：**

```ts
import bundleManager from '@ohos.bundle.bundleManager'
let bundleName = 'com.example.myapplication';
let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_REQUESTED_PERMISSION;
try {
    let data = bundleManager.getBundleInfoSync(bundleName, bundleFlags);
    console.info("getBundleInfoSync successfully :" + JSON.stringify(data));
} catch (err) {
    console.error('getBundleInfoSync failed:' + err.message);
}
```