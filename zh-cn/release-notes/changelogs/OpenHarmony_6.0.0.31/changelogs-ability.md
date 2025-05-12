# 元能力子系统Changelog

## cl.ability.1 借助Want进行文件分享时擦除不合法的URI

**访问级别**

公开接口

**变更原因**

在文件分享场景下（Want的flags字段中配置了[wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#flags)或[wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#flags)），应用可以通过Want的uri字段传递单个URI、或者通过[wantConstant.Params.PARAMS_STREAM](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#params)的Key值传递多个URI。为了确保传递给目标应用的参数合法，系统将主动擦除不满足条件的URI。

**变更影响**

此变更不涉及应用适配。

变更前：文件分享场景下，如果Want的uri字段中scheme为空，或wantConstant.Params.PARAMS_STREAM字段中的URI的scheme不为file，系统不做任何处理。

变更后：文件分享场景下，如果Want的uri字段中scheme为空，或wantConstant.Params.PARAMS_STREAM字段中的URI的scheme不为file，系统将擦除对应的URI取值。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 6.0.0.31开始。

**变更的接口/组件**

[@ohos.app.ability.Want (Want)](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-want.md)中的uri字段和parameters中的WantConstant.Params.PARAMS_STREAM字段。


**适配指导**

默认行为变更，无需适配。