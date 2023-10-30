# 包管理子系统ChangeLog

## cl.bundlemanager.1 module.json配置文件中distroFilter修改为distributionFilter
配置文件module.json中[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)标签修改为distributionFilter

**变更影响**<br>
删除配置文件module.json[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)标签，IDE中不再支持配置该标签，使用该标签会导致IDE编译报错

**适配指导**<br>
删除module.json中[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)标签，使用distributionFilter替代