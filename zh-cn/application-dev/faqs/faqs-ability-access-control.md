# 程序访问控制开发常见问题


## 在系统设置修改了应用权限，应用能否监听到权限变化(API 9)

在系统设置修改了应用权限，三方应用无法监听到权限变化的。


## 应用申请LOCATION位置信息权限为什么没有弹窗(API 9)

使用API version 9以下版本的SDK开发的应用，可以直接申请ohos.permission.LOCATION权限。

使用API version 9及API version 9以上版本的SDK开发的应用，需要先申请权限ohos.permission.APPROXIMATELY_LOCATION，才可申请此权限。

**参考链接**

[应用权限列表 - ohos.permission.LOCATION](../security/AccessToken/permissions-for-all.md#ohospermissionlocation)


## 向用户申请授予权限但被用户拒绝后，如何处理才能避免应用二次进入时崩溃(API 9)

**可能原因**

- 业务功能所需要的权限被用户拒绝后不再弹窗请求权限而是直接返回结果。

- 若开发者在请求权限后未进行相关判断，会导致应用直接访问受权限管控的目标对象，此时应用可能会因为没有对应权限而被拒绝访问，从而导致应用意外终止。

**解决措施**

1. 应用在调用受权限保护的接口前，需要先校验应用是否已经获取该权限。如果校验结果显示，应用已经获取了该权限，那么应用可以直接访问该目标接口，否则，应用需要通过动态弹框先申请用户授权，并根据授权结果进行相应处理。

2. 如果用户拒绝授予某个权限时，需要确保与此权限无关的其他业务功能应能正常使用，不能影响应用的正常注册或登录。

3. 当用户主动触发使用此业务功能或为实现业务功能所必须时，应用程序可通过界面内文字引导，让用户主动到“系统设置”中授权。

**参考链接**

[应用权限管控概述](../security/AccessToken/access-token-overview.md)

## module.json5配置文件中extensionAbilities和requestPermissions的权限声明有何区别(API 9)

- requestPermissions：标识当前应用运行时需向系统申请的权限集合，应用申请的权限只有在此处配置的才会生效。

- extensionAbilitie.permissions：标识当前ExtensionAbility组件自定义的权限信息，表示当其他应用访问该ExtensionAbility时，需要申请相应的权限信息，仅做权限校验使用。

**参考链接**

[module.json5配置文件](../quick-start/module-configuration-file.md)

