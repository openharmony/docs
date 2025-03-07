# 包管理子系统Changelog

## cl.bundlemanager.1 app.json中bundleName字段正则匹配规则修改

**访问级别**

公开接口

**变更原因**

app.json中对bundleName的正则匹配规则较简单，不符合应用包名规范，进行整改。

**变更影响**

该变更为不兼容变更。

变更前，规则如下：
- 由字母、数字、下划线（_）和符号“.”组成，且必须以字母开头。

变更后，规则如下：
- 由字母、数字、下划线和符号“.”组成。
- 必须为以点号（.）分隔的字符串，且至少包含三段。
- 首段以英文字母开头，非首段以数字或英文字母开头，每一段以数字或者英文字母结尾。
- 不允许多个点号（.）连续出现。

**起始API Level**

API 8

**变更发生版本**

从OpenHarmony 5.0.0.55 版本开始。

**变更的接口/组件**

Openharmony SDK目录下toolchains/modulecheck/app.json scheme文件。

**适配指导**

升级SDK版本后，如果DevEco Studio编辑器中提示如下报错，请按照新规则修改应用的bundleName。<br>![](figures/err_example.png) 