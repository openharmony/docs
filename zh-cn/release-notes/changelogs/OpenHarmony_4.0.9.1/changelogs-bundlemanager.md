# 包管理子系统ChangeLog
## cl.bundlemanager.1 包管理@ohos.bundle.d.ts中getAllBundleInfo接口底层实现变更。

@ohos.bundle.d.ts中getAllBundleInfo接口已标记废弃，在targetAPILevel为API9及之后的版本镜像上，返回数据列表为空。

**变更影响**<br>
升级新版本镜像后，使用@ohos.bundle.d.ts中的getAllBundleInfo的接口调用成功后返回数据列表为空。需要应用调用新的接口@ohos.bundle.bundleManager.d.ts中的getAllBundleInfo。

**关键的接口/组件变更**<br>
底层实现变更，使用@ohos.bundle.d.ts中的getAllBundleInfo的接口调用成功后返回数据列表为空。

**适配指导**<br>
1. 应用在使用@ohos.bundle.d.ts中getAllBundleInfo接口的地方可以修改为使用@ohos.bundle.bundleManager.d.ts中getAllBundleInfo，新接口使用方法可参考[指南](../../../application-dev/reference/apis/js-apis-bundleManager.md#bundlemanagergetallbundleinfo)。
```ets
import bundleManager from '@ohos.bundle.bundleManager';
```

## cl.bundlemanager.2 包管理@ohos.bundle.d.ts中getAllApplicationInfo接口底层实现变更。

@ohos.bundle.d.ts中getAllApplicationInfo接口已标记废弃，在targetAPILevel为API9及之后的版本镜像上，返回数据列表为空。

**变更影响**<br>
升级新版本镜像后，使用@ohos.bundle.d.ts中的getAllApplicationInfo的接口调用成功后返回数据列表为空。需要应用调用新的接口@ohos.bundle.bundleManager.d.ts中的getAllApplicationInfo。

**关键的接口/组件变更**<br>
底层实现变更，使用@ohos.bundle.d.ts中的getAllApplicationInfo的接口调用成功后返回数据列表为空。

**适配指导**<br>
1. 应用在使用@ohos.bundle.d.ts中getAllApplicationInfo接口的地方可以修改为使用@ohos.bundle.bundleManager.d.ts中getAllApplicationInfo，新接口使用方法可参考[指南](../../../application-dev/reference/apis/js-apis-bundleManager.md#bundlemanagergetallapplicationinfo)。
```ets
import bundleManager from '@ohos.bundle.bundleManager';
```

## cl.bundlemanager.3 包管理@ohos.bundle.bundleManager.d.ts中getAllBundleInfo接口权限变更。

获取应用列表接口需要由用户选择是否同意授权，因此将
@ohos.bundle.bundleManager.d.ts中getAllBundleInfo接口权限变更为ohos.permission.GET_INSTALLED_BUNDLE_LIST。

**变更影响**<br>
升级新版本镜像后，使用getAllBundleInfo的接口需要申请新的权限ohos.permission.GET_INSTALLED_BUNDLE_LIST，否则接口会调用失败。

**关键的接口/组件变更**<br>
@ohos.bundle.bundleManager.d.ts中getAllBundleInfo接口权限变更为ohos.permission.GET_INSTALLED_BUNDLE_LIST。

**适配指导**<br>
1. 应用可以在配置文件中新增申请权限ohos.permission.GET_INSTALLED_BUNDLE_LIST。
2. 该权限为user_grant类型的，安装时默认不会授权，需要应用调用弹框接口由用户选择是否授权或者使用预授权进行授权。
3. 使用弹框授权方式可以参考[向用户申请授权](../../../application-dev/security/accesstoken-guidelines.md#向用户申请授权)。
4. 使用预授权方式可以参考[权限预授权](../../../application-dev/security/accesstoken-guidelines.md#user_grant权限预授权)。

## cl.bundlemanager.4 包管理@ohos.bundle.bundleManager.d.ts中getAllApplicationInfo接口权限变更。

获取应用列表接口需要由用户选择是否同意授权，因此将
@ohos.bundle.bundleManager.d.ts中getAllApplicationInfo接口权限变更为ohos.permission.GET_INSTALLED_BUNDLE_LIST。

**变更影响**<br>
升级新版本镜像后，使用getAllApplicationInfo的接口需要申请新的权限ohos.permission.GET_INSTALLED_BUNDLE_LIST，否则接口会调用失败。

**关键的接口/组件变更**<br>
@ohos.bundle.bundleManager.d.ts中getAllApplicationInfo接口权限变更为ohos.permission.GET_INSTALLED_BUNDLE_LIST。

**适配指导**<br>
1. 应用可以在配置文件中新增申请权限ohos.permission.GET_INSTALLED_BUNDLE_LIST。
2. 该权限为user_grant类型的，安装时默认不会授权，需要应用调用弹框接口由用户选择是否授权或者使用预授权进行授权。
3. 使用弹框授权方式可以参考[向用户申请授权](../../../application-dev/security/accesstoken-guidelines.md#向用户申请授权)。
4. 使用预授权方式可以参考[权限预授权](../../../application-dev/security/accesstoken-guidelines.md#user_grant权限预授权)。

## cl.bundlemanager.5 包管理@ohos.bundle.installer.d.ts中getSpecifiedDistributionType接口移动到@ohos.bundle.bundleManager.d.ts中。

包管理@ohos.bundle.installer.d.ts中getSpecifiedDistributionType接口移动到@ohos.bundle.bundleManager.d.ts中。

**变更影响**<br>
升级新版本SDK后，包管理@ohos.bundle.installer.d.ts中getSpecifiedDistributionType接口移动到@ohos.bundle.bundleManager.d.ts中。

**关键的接口/组件变更**<br>
包管理@ohos.bundle.installer.d.ts中getSpecifiedDistributionType接口移动到@ohos.bundle.bundleManager.d.ts中。

**适配指导**<br>
1. 修改导入模块，使用bundleManager中的getSpecifiedDistributionType
```ets
import bundleManager form '@ohos.bundle.bundleManager'
```

## cl.bundlemanager.6 包管理@ohos.bundle.installer.d.ts中getAdditionalInfo接口移动到@ohos.bundle.bundleManager.d.ts中。

包管理@ohos.bundle.installer.d.ts中getAdditionalInfo接口移动到@ohos.bundle.bundleManager.d.ts中。

**变更影响**<br>
升级新版本SDK后，包管理@ohos.bundle.installer.d.ts中getAdditionalInfo接口移动到@ohos.bundle.bundleManager.d.ts中。

**关键的接口/组件变更**<br>
包管理@ohos.bundle.installer.d.ts中getAdditionalInfo接口移动到@ohos.bundle.bundleManager.d.ts中。

**适配指导**<br>
1. 修改导入模块，使用bundleManager中的getAdditionalInfo
```ets
import bundleManager form '@ohos.bundle.bundleManager'
```

## cl.bundlemanager.7 应用配置文件module.json5中proxyDatas更名为proxyData。

由于命名规范问题，proxyDatas更名为proxyData。

**变更影响**<br>
升级新版本SDK后，proxyDatas更名为proxyData，应用如果不进行适配，将会编译失败。

**关键的接口/组件变更**<br>
proxyDatas更名为proxyData。

**适配指导**<br>
请使用proxyData替换proxyDatas，其内容不需要变更。