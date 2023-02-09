# 包管理子系统ChangeLog

## cl.bundlemanager.1 包管理删除@ohos.bundle.bundleManager.d.ts中的getAbilityIcon接口，可以使用@ohos.resourceManager.d.ts中的getMediaContent替换。

包管理删除[@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)中的getAbilityIcon接口，可以使用[@ohos.resourceManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.resourceManager.d.ts)中的getMediaContent替换。

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了getAbilityIcon接口的，需要改为使用getMediaContent接口。

**关键的接口/组件变更**<br>
删除@ohos.bundle.bundleManager.d.ts中的getAbilityIcon接口。

**适配指导**<br>
使用@ohos.bundle.bundleManager.d.ts下面的getAbilityIcon，需要修改为@ohos.resourceManager.d.ts中的getMediaContent。需要提前获取到图标的资源ID值，可参考该接口的[使用指导](../../../application-dev/reference/apis/js-apis-resource-manager.md#getmediacontent9)。

## cl.bundlemanager.2 包管理新增202错误码

包管理系统新增202错误码，非系统应用调用api9及之后包管理提供的系统api，将返回错误202。

**变更影响**<br>
非系统应用调用api9及之后包管理提供的系统api，将返回错误202。

**关键的接口/组件变更**<br>
所有包管理提供的api9及之后的系统api，非系统应用调用将返回错误202。

**适配指导**<br>
不影响已开发的程序，无需适配。