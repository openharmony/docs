# MDM Kit开发指南

## 功能介绍

设备管理应用可以提供企业设备管理与事件监听、应用管理、禁用管理、安全管理、设备设置、设备控制、设备信息获取、硬件外设管理、系统管理、网络通信管理等功能。具体功能内容可参考接口说明。

设备管理应用：具备[企业设备管理扩展能力](./mdm-kit-admin.md)的应用。

## 开发步骤

要完成一个设备管理应用开发，需要完成以下步骤：

<!--RP1-->

1. 创建EnterpriseAdminExtensionAbility；

2. 声明接口所需权限；

3. MDM功能开发与调试；

<!--RP1End-->


<!--RP2--><!--RP2End-->

### 创建EnterpriseAdminExtensionAbility

请参阅[EnterpriseAdminExtensionAbility开发指南](./mdm-kit-admin.md)完成EnterpriseAdminExtensionAbility的创建。

### 声明接口所需权限

在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后在工程Module对应的[module.json5](../quick-start/module-configuration-file.md)配置文件中"requestPermissions"标签下声明要使用的接口所需的权限。例如：

```ts
"requestPermissions": [
  {
    "name": "ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN"
  },
]
```

> **说明**
> 
> 所需要申请的权限请参考具体接口，这里提供了[企业设备管理](../reference/apis-mdm-kit/js-apis-enterprise-adminManager.md)的链接，可基于该文档查看MDM Kit内其他API文档。
>
> <!--RP4--><!--RP4End-->

### MDM功能开发

1. 导包。MDM Kit目前包含应用管理、通信管理、安全管理、限制策略、系统内管理、设备设置和查询、设备控制等多种类型的API。请根据业务需求。以下为导入adminManager和restrictions的示例。

   ```ts
   import { adminManager, restrictions } from '@kit.MDMKit';
   ```

2. 调用接口，实现相应的功能。以下为禁用设备Wi-Fi的示例。

   ```ts
   import { Want } from '@kit.AbilityKit';
   let wantTemp: Want = {
     bundleName: 'com.example.xxx',
     abilityName: 'EnterpriseAdminAbility',
   };
   try {
     restrictions.setDisallowedPolicy(wantTemp, "wifi", true);
     console.info("disable wifi success.");
   } catch (error) {
     console.info("disable wifi fail.");
   }
   ```

### 调试说明

由于MDM接口需要在激活企业设备管理扩展能力后使用，调试时需通过hdc命令来激活/解除激活扩展能力，命令如下：

```bash
:: 激活
hdc shell edm enable-admin -n 包名 -a 企业设备管理扩展能力类名
:: 解除激活
hdc shell edm disable-admin -n 包名
```

> **说明**
> 
> 正式使用时，在同一设备上只能能激活一个超级设备管理应用。
>
> <!--RP5--><!--RP5End-->
 
<!--RP6--><!--RP6End-->