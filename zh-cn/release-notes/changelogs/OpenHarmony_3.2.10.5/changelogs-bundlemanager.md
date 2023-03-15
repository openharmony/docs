# 包管理子系统ChangeLog

## cl.bundlemanager.1 底层能力变更，安装应用时增加签名证书中bundle-name的校验，需要与应用的bundleName相同，否则会安装失败。

安装应用时增加了对[签名证书profile文件](../../../application-dev/security/app-provision-structure.md)中bundle-name字段的校验，该字段内容需要配置为对应应用的bundleName。

如果bundle-name的内容与应用配置文件中的bundleName不一致，会出现安装失败。具体报错为：
```
error: verify signature failed.
```

**变更影响**<br>
对之前的版本镜像无影响，对使用3.2.10.5版本及之后的系统镜像，如果未修改签名证书中的bundle-name字段，会出现应用安装失败问题。

**关键的接口/组件变更**<br>
不涉及接口及组件变更

**适配指导**<br>
原有应用在新的系统镜像上出现'error: verify signature failed'，可以修改签名证书profile文件中的bundle-name为对应应用的bundleName，生成新的签名证书（后缀为.p7b），重新给应用签名即可。
签名工具及签名证书的生成方式可以参考：[签名工具指导](../../../application-dev/security/hapsigntool-guidelines.md)

## cl.bundlemanager.2 底层能力变更，增加对无图标应用的管控，如果应用未配置入口图标，则会在桌面上显示一个默认图标，点击后跳转至应用详情页。

增加对无图标应用的管控，如果应用未配置入口图标且未申请隐藏图标特权(AllowHideDesktopIcon)，则会在桌面上显示一个默认图标，点击后跳转至应用详情页。此处的未配置入口图标规则如下：
1. 应用中未配置abilities字段
2. 应用中配置了abilities字段，但是没有任何一个page类型的ability中skills如下，即同时包含"ohos.want.action.home"和"entity.system.home"：
    ```json
     "skills": [
              {
                "actions": [
                  "ohos.want.action.home"
                ],
                "entities": [
                  "entity.system.home"
                ]
              }
            ]
    ```
对于符合上面规则的应用，均属于无图标应用，通过hdc_std install 或者 bm install的方式安装，均会在桌面上显示一个默认图标。

如果应用不需要再桌面显示图标，需要申请相应的隐藏图标特权AllowHideDesktopIcon，并在签名证书文件中或者白名单(install_list_capability.json)配置，可以参考：[应用特权配置指南](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md)。

如果应该需要在桌面显示图标，则需要在abilities中选择一个ability配置skills，同时包含"ohos.want.action.home"和"entity.system.home"。

**变更影响**<br>
对之前的版本镜像无影响，对使用3.2.10.5版本及之后的系统镜像，如果应用未配置图标，通过命令行的安装方式会在桌面显示默认图标。

**关键的接口/组件变更**<br>
不涉及接口及组件变更

**适配指导**<br>
如果应用不需要再桌面显示图标，需要申请相应的隐藏图标特权AllowHideDesktopIcon，并在签名证书文件中或者白名单(install_list_capability.json)配置，可以参考：[应用特权配置指南](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md)。

如果应该需要在桌面显示图标，则需要在abilities中选择一个ability配置skills，同时包含"ohos.want.action.home"和"entity.system.home"。

## cl.bundlemanager.3 底层能力变更，特权AllowAppUsePrivilegeExtension、AllowAppMultiProcess和AllowFormVisibleNotify不支持通过签名证书配置，仅支持通过白名单install_list_capability.json申请这三个特权。

特权AllowAppUsePrivilegeExtension、AllowAppMultiProcess和AllowFormVisibleNotify不支持通过签名证书配置，仅支持通过白名单install_list_capability.json申请这三个特权。对于在签名证书中申请使用上面三个特权的应用，在新版本上可能出现安装失败或者配置特权无效的问题。

如果出现了下面的报错，可能是因为特权整改导致的，应用需要适配新的规则，可以参考：[应用特权配置指南](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md)。
```
error: install parse profile prop check error.
```

对于xts或者本地调试的demo，无法修改板子上install_list_capability.json的，可以修改应用的bundleName，需要以"com.acts."为开头，同时在签名证书中申请对应的特权。

申请特权AllowAppUsePrivilegeExtension，通常是在应用的配置文件中使用了extensionAbilities字段，且其中的type属性为dataShare或者service。如果未配置特权，就会出现安装失败问题。

**变更影响**<br>
对之前的版本镜像无影响，对使用3.2.10.5版本及之后的系统镜像，如果未在白名单install_list_capability.json中申请所需的特权，可能会出现应用安装失败问题。

**关键的接口/组件变更**<br>
不涉及接口及组件变更

**适配指导**<br>
如果出现了下面的报错，可能是因为特权整改导致的，应用需要适配新的规则，可以参考：[应用特权配置指南](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md)。
```
error: install parse profile prop check error.
```

对于xts或者本地调试的demo，无法修改开发板上install_list_capability.json的，可以修改应用的bundleName，需要以"com.acts."为开头，同时在签名证书中申请对应的特权。

## cl.bundlemanager.4 底层能力变更，安装hap时，hap中的文件不再解压到安装目录。

安装hap后，安装目录下只会存在hap文件，应用不能再使用拼接路径访问解压后的资源文件，应用想要访问资源文件，需要使用标准的资源管理接口。

**变更影响**<br>
如果应用使用拼接路径的形式访问资源文件，会访问失败。需要修改成使用资源管理接口访问资源文件。

**关键的接口/组件变更**<br>
不涉及接口及组件变更

**适配指导**<br>
资源管理子系统提供Js接口访问资源文件。参考[访问资源文件](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-resource-manager.md#getrawfilecontent9)
