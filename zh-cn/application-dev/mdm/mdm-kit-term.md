# MDM Kit术语
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima-->
<!--Designer: @liuzuming-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->


## BYOD
Bring Your Own Device，自带设备办公。指一些企业允许员工携带自己的笔记本电脑、平板电脑、智能手机等移动终端设备到公司，并使用这些设备获取公司内部信息和企业特许应用的政策。

## MDM应用（设备管理应用）
又称企业MDM应用，指集成了MDM（Mobile Device Management，移动设备管理）管理功能的应用，能够集中管理、监控和保护企业内的移动设备（如智能手机、平板电脑、笔记本电脑等）。它允许IT管理员远程配置设备、强制执行安全策略、部署应用程序，并确保企业数据的安全。

## 企业设备管理扩展能力
企业设备管理扩展能力（EnterpriseAdminExtensionAbility）组件是MDM应用必备组件。开发者为企业开发MDM应用时，需继承EnterpriseAdminExtensionAbility，在EnterpriseAdminExtensionAbility实例中实现MDM业务逻辑，EnterpriseAdminExtensionAbility实现了系统管理状态变化通知功能，并定义了管理应用激活、去激活、应用安装、卸载事件等回调接口。当MDM应用的企业设备管理扩展能力被激活后，此企业设备管理扩展能力会被保活，当重启、切换用户后会自动启动。企业设备管理扩展能力激活后的MDM应用无法被卸载。

