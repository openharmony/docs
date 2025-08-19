# 应用数据备份恢复概述
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie-->
<!--Designer: @wang_zhangjun; @chenxi0605-->
<!--Tester: @liuhonggang123-->
<!--Adviser: @foryourself-->

用户在使用应用的过程中，会产生对应的应用数据，如配置信息、业务数据等。为了保证用户数据不会因为应用升级、迁移等操作而丢失，应用需要接入数据备份恢复。

在开发前，需要先了解ExtensionAbility组件，建议参考[ExtensionAbility组件概述](../application-models/extensionability-overview.md)。

BackupExtensionAbility是Stage模型中扩展组件ExtensionAbility的派生类，用于提供备份及恢复应用数据的能力。它是一种无界面的扩展组件，随着备份恢复任务的启动而运行，随着备份恢复任务的结束而退出。

不同应用所需实现的场景不同，分为：

- [应用接入数据备份恢复](app-file-backup-extension.md)：应用均可以接入数据备份恢复，在接入后，应用可通过修改配置文件定制备份恢复框架的行为，包括是否允许备份恢复、备份哪些数据。

  应用本身无法触发数据的备份和恢复，仅能进行备份恢复的配置。
<!--RP1-->
- [应用触发数据备份恢复（仅对系统应用开放）](app-file-backup.md)：仅系统应用可以触发数据备份恢复，触发后备份恢复框架会确认各个应用是否接入了数据备份恢复。如果应用已接入，备份恢复框架将会根据应用的配置文件备份、恢复数据。<!--RP1End-->