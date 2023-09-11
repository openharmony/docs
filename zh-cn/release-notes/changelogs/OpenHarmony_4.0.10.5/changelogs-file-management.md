# 文件子系统ChangeLog

## cl.file.1 @ohos.file.storageStatistics和@ohos.file.volumeManager 文档错误码变更

[@ohos.file.storageStatistics](../../../application-dev/reference/apis/js-apis-file-storage-statistics.md#)和[@ohos.file.volumeManager](../../../application-dev/reference/apis/js-apis-file-volumemanager.md#)两个模块中所有接口Unknown error错误码变更, d.ts中记录的错误码与实际功能代码中返回的不相符。

变更前每个接口Unknown error的错误码为13900032。

变更后每个接口Unknown error的错误码为13900042。

**变更影响**

功能代码中，针对“Unknown error”从首版本开始一直返回13900042，仅接口定义d.ts文件与API文档记录错误。

对原来的“13900032 Unknown error”进行了特殊处理的应用，需要进行排查，并修改为139000342。

**关键接口/组件变更**

涉及@ohos.file.storageStatistics模块和@ohos.file.volumemanager模块中的所有接口。

**适配指导**

针对Unknown error进行特殊处理的应用需要将错误码更改为13900042。
