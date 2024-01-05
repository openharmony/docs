# Contacts Kit开发概述

提供联系人管理能力，包括添加联系人、删除联系人、更新联系人等功能。

详情请参考[@ohos.contact API](../reference/apis/js-apis-contact.md)。


## 约束与限制

读取联系人需要声明接口调用的权限：ohos.permission.READ_CONTACTS。

添加联系人、删除联系人、更新联系人需要声明接口调用的权限：ohos.permission.WRITE_CONTACTS。

此权限级别为system_basic，在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[访问控制-声明权限](../security/AccessToken/declare-permissions.md)声明对应权限。