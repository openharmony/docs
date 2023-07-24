# 包管理子系统ChangeLog
## cl.bundlemanager.1 module.json配置文件schema变更

module.json配置文件中，module字段的name属性、ability字段的name属性、extensionAbility字段的name属性，需要以英文字母开头，并仅含有英文字母、数字以及下划线和点符号。

**变更影响**<br>
升级新版本sdk后，如果module字段的name属性、ability字段的name属性、extensionAbility字段的name属性不符合上述要求，则编译失败。

**关键的接口/组件变更**<br>
module.json配置文件中，module字段的name属性、ability字段的name属性、extensionAbility字段的name属性，需要以英文字母开头，并仅含有英文字母、数字以及下划线和点符号。

**适配指导**<br>
修改对应的字段，使其满足以英文字母开头，并仅含有英文字母、数字以及下划线和点符号的要求。
