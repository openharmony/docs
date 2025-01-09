# 文件管理子系统Changelog

## cl.filemanagement.1 CopyResult @stagemodelonly标签变更

**访问级别**

系统接口

**变更原因**

CopyResult 及其相关属性sourceUri、destUri、errCode、errMsg的@stagemodelonly拼写错误(修改前stagemodeonly),需要改成正确的写法stagemodelonly。

**变更影响**

该变更为不兼容变更。

变更前:CopyResult 及其相关属性sourceUri、destUri、errCode、errMsg的标签为@stagemodeonly。

变更后:CopyResult 及其相关属性sourceUri、destUri、errCode、errMsg的标签为@stagemodelonly。

**起始API Level**

API 10

**变更发生版本**

从OpenHarmony_5.0.0.57 版本开始。

**变更的接口/组件**

[@ohos.file.fileAccess.d.ts](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-core-file-kit/js-apis-fileAccess-sys.md)中如下接口：CopyResult、sourceUri、destUri、errCode、errMsg

**适配指导**

无需适配，标签的变更，对实际功能无影响。
