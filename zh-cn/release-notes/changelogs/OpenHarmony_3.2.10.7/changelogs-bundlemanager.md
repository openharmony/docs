# 包管理子系统ChangeLog

## cl.bundlemanager.1 包管理删除@ohos.bundle.bundleManager.d.ts中的getAbilityIcon接口，可以使用@ohos.resourceManager.d.ts中的getMediaContent替换。

包管理删除[@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)中的getAbilityIcon接口，可以使用[@ohos.resourceManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.resourceManager.d.ts)中的getMediaContent替换。

**变更影响**<br>
使用之前已发布的API 9各beta版本切使用到了getAbilityIcon接口的，需要改为使用getMediaContent接口。

**关键的接口/组件变更**<br>
删除@ohos.bundle.bundleManager.d.ts中的getAbilityIcon接口。

**适配指导**<br>
使用@ohos.bundle.bundleManager.d.ts下面的getAbilityIcon，需要修改为@ohos.resourceManager.d.ts中的getMediaContent。需要提前获取到图标的资源ID值，可参考该接口的[使用指导](../../../application-dev/reference/apis/js-apis-resource-manager.md#getmediacontent9)。

## cl.bundlemanager.2 包管理底层能力变更，仅支持系统资源HAP自定义权限，其它HAP均不支持自定义权限。

仅支持系统资源HAP自定义权限，其它HAP均不支持自定义权限。包管理在解析HAP时，仅支持解析资源HAP(包名为：ohos.global.systemres)的配置文件中的definePermissions字段，该字段用来定义权限。其它HAP中配置的definePermissions字段将不会解析。
如果有应用需要自定义权限，可以在资源HAP的[配置文件](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json)中definePermissions字段下面新增定义权限。格式可参考[定义权限](../../../application-dev/quick-start/module-structure.md#definepermissions对象内部结构)。


**变更影响**<br>
升级新版本镜像后，应用自定义的权限将不会生效，使用方在申请该权限时，会授权失败。

**关键的接口/组件变更**<br>
包管理底层能力变更，仅支持系统资源HAP自定义权限，其它HAP均不支持自定义权限。

**适配指导**<br>
如果有应用需要自定义权限，可以在资源HAP的[配置文件](https://gitee.com/openharmony/utils_system_resources/blob/master/systemres/main/config.json)中definePermissions字段下面新增定义权限。格式可参考[定义权限](../../../application-dev/quick-start/module-structure.md#definepermissions对象内部结构)。
