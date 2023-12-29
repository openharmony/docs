# 包管理子系统ChangeLog
## cl.bundlemanager.1 ApplicationInfo结构体废弃metadata字段

从API version 10开始不再维护，建议使用metadataArray替代。

**变更影响**<br>
ApplicationInfo结构体从API version 10开始不再维护metadata字段。

**关键的接口/组件变更**<br>
ApplicationInfo结构体从API version 10开始，废弃metadata字段。

**适配指导**<br>
使用metadataArray字段替代metadata字段。

```ts
import bundleManager from '@ohos.bundle.bundleManager';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';
let bundleName = 'com.example.myapplication';
let appFlags = bundleManager.ApplicationFlag.GET_APPLICATION_INFO_WITH_METADATA;
let userId = 100;

try {
    bundleManager.getApplicationInfo(bundleName, appFlags, userId, (err, data) => {
        if (err) {
            hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', err.message);
        } else {
            hilog.info(0x0000, 'testTag', 'getApplicationInfo successfully: %{public}s', JSON.stringify(data));
            hilog.info(0x0000, 'testTag', 'metadataArray is: %{public}s', JSON.stringify(data.metadataArray));
        }
    });
} catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getApplicationInfo failed: %{public}s', message);
}
```
## cl.bundlemanager.1 打包工具modulecheck、configcheck校验schema变更

schema校验文件app.json、module.json、configSchema_lite.json和configSchema_rich.json中，对bundleName的长度限定由最大127改为最大128。

**变更影响**<br>
变更前，项目允许的bundleName最大长度为127，设置项目bundleName的长度大于等于128时，DevEco Studio IDE无法编译、打包该项目，IDE报错：Schema validate failed。

变更后，项目允许的bundleName最大长度为128，设置项目bundleName的长度等于128时，DevEco Studio IDE可以成功编译、打包该项目；设置项目bundleName的长度大于128时，DevEco Studio IDE无法编译、打包该项目，IDE报错：Schema validate failed。

**关键的接口/组件变更**<br>
无关联接口/组件

**适配指导**<br>
升级SDK即可，开发者无需适配。

## cl.bundlemanager.1 安装应用时，系统允许的安装包的最大bundleName长度改为128

安装应用时，包管理系统会校验安装包bundleName的长度，允许的最大长度由127改为128。

**变更影响**<br>
变更前，系统允许安装包的bundleName最大长度为127，若安装包bundleName的长度大于等于128时，系统报错，无法成功安装应用。

变更后，系统允许安装包的bundleName最大长度为128，若安装包bundleName的长度等于128时，系统可以成功安装应用；若安装包bundleName的长度大于128时，系统报错，无法成功安装应用。

**关键的接口/组件变更**<br>
无关联接口/组件

**适配指导**<br>
开发者无需适配

## cl.bundlemanager.1 系统应用判断逻辑调整。

系统应用判断逻辑修改为只根据[签名证书](../../../application-dev/security/app-provision-structure.md)中的app-feature字段来判断是否为系统应用，规则如下：
* app-feature为hos_system_app，则为系统应用。
* app-feature为hos_normal_app，则为三方应用。

**变更影响**<br>
如果应用位于"/system/app"下面，并且路径配置在"/****/etc/app/install_list.json”文件中，但是app-feature为hos_normal_app，该应用将无法使用systemApi。

**关键的接口/组件变更**<br>
不涉及接口及组件变更。

**适配指导**<br>
业务需要确认自身是否为系统应用，如果是，则需要修改app-feature为hos_system_app，并对HAP重新签名。


## c2.bundlemanager.2 包管理ApplicationInfo结构体中新增dataUnclearable字段。

包管理[ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts)结构体中新增dataUnclearable字段，参考：[API文档链接](../../../application-dev/reference/apis/js-apis-bundle-ApplicationInfo.md)。

**变更影响**<br>
对之前接口使用无影响。

**关键的接口/组件变更**<br>
包管理[ApplicationInfo](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/ApplicationInfo.d.ts)结构体中新增dataUnclearable字段，参考：[API文档链接](../../../application-dev/reference/apis/js-apis-bundle-ApplicationInfo.md)。

**适配指导**<br>
无

## c3.bundlemanager.3 非调试模式下不允许安装调试应用

**访问级别**
其他

**变更原因**

当前对调试应用安装做了管控，无法在非调试模式的设备上安装调试应用，可以由[签名证书](../../../application-dev/security/app-provision-structure.md)中的type字段来判断是否为调试应用。

**变更影响**

如果应用的签名证书类型为debug，设备为非调试模式，会导致无法安装。

**变更发生版本**
从OpenHarmony SDK 4.1.2.5开始

**变更的接口/组件**

不涉及接口及组件变更。

**适配指导**

如果应用需要安装在非调试模式的设备上，在构建时，使用release的证书进行签名。

## cl.bundlemanager.1 非MDM应用不能申请MDM权限，否则安装失败。

**访问级别**

系统接口

**变更原因**

MDM类型的权限仅限MDM类型的应用使用。

**变更影响**

非MDM应用不能申请MDM权限，否则安装失败。

MDM应用判断逻辑只根据[签名证书](../../../application-dev/security/app-provision-structure.md)中的app-distribution-type字段来判断是否为MDM应用，规则如下：
* app-distribution-type为enterprise_mdm，则为MDM应用。
* app-distribution-type不为enterprise_mdm，则为非MDM应用。

MDM权限判断逻辑是根据[权限定义](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json)中definePermissions字段中availableType属性来判断是否为MDM权限，规则如下：
* availableType为MDM，则为MDM权限。
* availableType不为MDM，则为非MDM权限。

**变更发生版本**

从OpenHarmony SDK 4.1.3.1开始

**变更的接口/组件**

应用在申请权限时，Stage模型对应[module.json5](../../../application-dev/quick-start/module-structure.md#reqpermissions权限申请)，FA模型对应[config.json](../../../application-dev/quick-start/module-configuration-file.md#requestpermissions标签)。非enterprise_mdm类型的应用（app-distribution-type不为enterprise_mdm），不再能申请MDM类型的权限。

**适配指导**

业务需要确认自身是否为MDM应用，如果不是，则不能继续申请MDM权限。

## cl.bundlemanager.1 包管理NDK结构体OH_NativeBundle_ApplicationInfo新增appId和appIdentifier字段，需手动释放。

**访问级别**

公开接口

**变更原因**

结构体[OH_NativeBundle_ApplicationInfo](../../../application-dev/reference/native-apis/_o_h___native_bundle_application_info.md)新增appId和appIdentifier字段。

**变更影响**

如果使用API 11及以上的开发的Native应用，如果不手动释放结构体OH_NativeBundle_ApplicationInfo中的appId和appIdentifier字段，会造成内存泄漏。如果使用API 11之前的开发的native应用，则无需适配。

**变更发生版本**

从OpenHarmony SDK 4.1.3.2开始

**变更的接口/组件**

应用调用包管理NDK接口[OH_NativeBundle_GetCurrentApplicationInfo](../../../application-dev/reference/native-apis/native__interface__bundle.md#oh_nativebundle_getcurrentapplicationinfo)查询应用自身信息。

**适配指导**

应用若是使用API 11及以上的版本开发的Native应用，则需要在代码里手动释放appId和appIdentifier申请的内存。

示例代码

 ```c++
    static napi_value GetCurrentApplicationInfo(napi_env env, napi_callback_info info)
    {
        // 调用Native接口获取应用信息
        OH_NativeBundle_ApplicationInfo nativeApplicationInfo = OH_NativeBundle_GetCurrentApplicationInfo();
        napi_value result = nullptr;
        napi_create_object(env, &result);
        // Native接口获取的应用包名转为js对象里的bundleName属性
        napi_value bundleName;
        napi_create_string_utf8(env, nativeApplicationInfo.bundleName, NAPI_AUTO_LENGTH, &bundleName);
        napi_set_named_property(env, result, "bundleName", bundleName);
        // Native接口获取的指纹信息转为js对象里的fingerprint属性
        napi_value fingerprint;
        napi_create_string_utf8(env, nativeApplicationInfo.fingerprint, NAPI_AUTO_LENGTH, &fingerprint);
        napi_set_named_property(env, result, "fingerprint", fingerprint);
        // Native接口获取的appId转为js对象里的appId属性
        napi_value appId;
        napi_create_string_utf8(env, nativeApplicationInfo.appId, NAPI_AUTO_LENGTH, &appId);
        napi_set_named_property(env, result, "appId", appId);
        // Native接口获取的appIdentifier转为js对象里的appIdentifier属性
        napi_value appIdentifier;
        napi_create_string_utf8(env, nativeApplicationInfo.appIdentifier, NAPI_AUTO_LENGTH, &appIdentifier);
        napi_set_named_property(env, result, "appIdentifier", appIdentifier);
        // 最后为了防止内存泄漏，手动释放
        free(nativeApplicationInfo.bundleName);
        free(nativeApplicationInfo.fingerprint);
        free(nativeApplicationInfo.appId);  // new
        free(nativeApplicationInfo.appIdentifier);  // new
        return result;
    }
```

详细开发指导可参考包[管理NDK开发指导](../../../application-dev/napi/native-bundle-guidelines.md)。

## cl.bundlemanager.1 废弃VerifyCodeParam接口和InstallParam中的verifyCodeParams字段

**访问级别**

系统接口

**废弃原因**

应用的代码签名文件将集成到安装包中，不再需要该接口来指定安装包的代码签名文件。

**废弃影响**

包管理[installer](../../../application-dev/reference/apis/js-apis-installer.md)模块中废弃VerifyCodeParam接口和InstallParam中的verifyCodeParams字段，不再需要该接口来指定安装包的代码签名文件。

**废弃发生版本**

从OpenHarmony SDK 4.1.3.3开始

**废弃的接口/组件**

| 接口声明 | 废弃说明 |
| --------------- | ------- |
| interface VerifyCodeParam | 不再需要该接口来指定安装包的代码签名文件。 |
| verifyCodeParams?: Array<VerifyCodeParam>; | 不再需要该接口来指定安装包的代码签名文件。 |

**适配指导**

调用安装接口时无需再指定安装包的代码签名文件，因为应用的代码签名文件将集成到安装包中。

## cl.bundlemanager.1 打包工具打包libs库是否压缩默认值变更

**访问级别**

其他

**变更原因**

打包工具默认以压缩方式打包libs库，虽然可以使打出的安装包更小，但却会增加打包耗时。开发者在开发调试阶段往往对包大小不敏感，对打包耗时要求较高。此次变更后，打包工具默认以不压缩方式打包libs库，在开发调试阶段为开发者带来时间收益。

**变更影响**

该变更为兼容性变更。对开发者打包时libs库是否默认压缩会有影响。

**变更发生版本**

从OpenHarmony SDK 4.1.3.5版本开始。

**变更的接口/组件**

修改前，打包工具默认以压缩方式打包libs库。

修改后，打包工具默认以不压缩方式打包libs库。

**适配指导**

打包工具默认以不压缩方式打包libs库，如果需要以压缩方式打包libs库，可以设置[module.json5配置文件](../../../application-dev/quick-start/module-configuration-file.md)中的compressNativeLibs参数为true。
