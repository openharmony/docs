# 包管理子系统变更说明

## cl.bundlemanager.1 abilities必选字段校验规则变更

**访问级别**

其他

**变更原因**

abilities字段属性srcEntrance在API9中已经被srcEntry替代，但校验规则中依然还保留有srcEntrance，造成某些情况下会产生包含srcEntrance字段的错误提示信息。

**变更影响**

该变更为非兼容性变更。

变更后，API8以及之前版本SDK生成的工程，将不能直接通过API12版本SDK进行编译。

**API Level**

12

**变更发生版本**

从系统OpenHarmony 5.0.0.19 版本开始。

**适配指导**

对于API8以及之前版本SDK生成的工程，如果开发者需要在API12版本SDK上进行编译，可以将工程module.json5中的srcEntrance字段名称改为srcEntry。