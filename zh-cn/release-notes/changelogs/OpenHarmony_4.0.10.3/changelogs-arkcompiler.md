# ArkCompiler子系统Changelog

## cl.ArkCompiler.1 ArkTS语法检查变更

为了推进ArkTS语法规则落地，在编译流程中添加ArkTS语法检查，对工程中的文件进行检查。并根据compatibleSdkVersion划分不同模式，根据模式判断是报warning还是error，以及是否阻塞编译。compatibleSdkVersion一般配置在build-profile.json5文件中。

具体规则可参考[从TypeScript到ArkTS的适配规则](../../../application-dev/quick-start/typescript-to-arkts-migration-guide.md)。

  - compatibleSdkVersion < 10 为兼容模式。在该模式下，对于违法ArkTS语法规则的代码，编译时报warning，不阻塞编译。
  - compatibleSdkVersion >= 10 为标准模式。在该模式下，对于违法ArkTS语法规则的代码，编译时报error，并阻塞编译。

**变更影响**

变更之前没有做ArkTS语法的检查，变更后对应用代码增加了ArkTS语法的检查，并根据工程的compatibleSdkVersion判断是报warning还是error，以及是否阻塞编译。

  - OpenHarmony SDK从4.0.10.3版本起，会开启编译告警。应用的工程进行编译时会对不符合ArkTS语法规则的代码给出warning告警，各模块可以根据告警信息进行适配，但并不阻塞编译。
  - OpenHarmony SDK在API version 10 Release时预计将以error告警来提示ArkTS语法不规则的代码，此时工程将无法编译。

**关键的接口/组件变更**

在编译流程中添加了ArkTS语法的检查。

**适配指导**

不符合ArkTS语法的文件需要进行适配修改，报错规则的具体说明和修改方式请参考[从TypeScript到ArkTS的适配规则](../../../application-dev/quick-start/typescript-to-arkts-migration-guide.md)。

若需要了解ArkTS语言请参考[ArkTS语言简介](../../../application-dev/quick-start/introduction-to-arkts.md)。