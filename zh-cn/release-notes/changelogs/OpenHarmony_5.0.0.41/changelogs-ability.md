# 元能力子系统Changelog

## cl.ability.1 借助Want分享文件URI时无权限的URI会被拦截

**访问级别**

公开接口

**变更原因**


在want的flags字段设置了授权flag前提下，禁止在want中的URI字段和wantConstant.Params.PARAMS_STREAM字段中传入无权限的[File URI](../../../application-dev/reference/apis-core-file-kit/js-apis-file-fileuri.md#fileuri10)。

> **说明：**
>
> 有权限的File URI是指应用通过[getUriFromPath](../../../application-dev/reference/apis-core-file-kit/js-apis-file-fileuri.md#fileurigeturifrompath)接口将自身沙箱路径转换后的URI或持久化过的File URI。

**变更影响**

该变更为不兼容变更。

变更前：
在want的flags字段设置了授权flag前提下，借助want实现File URI文件分享时，want中的URI字段和wantConstant.Params.PARAMS_STREAM字段会原封不动地传递给被授权方。

变更后：
在want的flags字段设置了授权flag前提下，借助want实现file URI文件分享时want的URI字段和wantConstant.Params.PARAMS_STREAM字段中无权限的file URI不会传递给被授权方。file URI拦截规则如下：
1. want中URI字段如果是File URI，且授权方没有该URI的权限, 则URI字段将被擦除。
2. WantConstant.Params.PARAMS_STREAM字段中授权方无权限的File URI将被擦除。
3. want中的URI字段与WantConstant.Params.PARAMS_STREAM字段中的File URI合并后超过500的部分将会被截断。


**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.41开始。

**变更的接口/组件**

不涉及。

**适配指导**

默认行为变更，无需适配。

