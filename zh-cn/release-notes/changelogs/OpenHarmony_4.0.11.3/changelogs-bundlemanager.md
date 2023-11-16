# 包管理子系统ChangeLog

## cl.bundlemanager.1 module.json配置文件中distroFilter修改为distributionFilter
配置文件module.json中[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)标签修改为distributionFilter。

**变更影响**<br>
该变更为兼容性变更。配置文件module.json中[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)标签已废弃，IDE编译不会报错，编辑器中会有波浪线提示。

**适配指导**<br>
删除module.json中[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)标签，使用distributionFilter替代。