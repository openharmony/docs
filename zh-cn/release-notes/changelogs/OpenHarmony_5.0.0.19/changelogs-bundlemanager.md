# 包管理子系统变更说明

## cl.bundlemanager.1 abilities必选字段校验规则变更

**访问级别**

其他

**变更原因**

abilities字段属性srcEntrance在API9中已经被srcEntry替代，但校验规则中依然还保留有srcEntrance，造成某些情况下会产生包含srcEntrance字段的错误提示信息。

**变更影响**

该变更为非兼容性变更。

变更后，如果原有工程中使用的是srcEntrance字段，在新版本SDK中编译构建时，会产生如下报错信息：
```
> hvigor ERROR: Failed :entry:default@PreBuild... 
> hvigor ERROR: Schema validate failed.
{
  instancePath: 'module.abilities[0]',
  keyword: 'required',
  params: { missingProperty: 'srcEntry' },
  message: "must have required property 'srcEntry'",
  location: 'C:/.../Projects/MyApp/entry/src/main/module.json5:15:8'
} 
```

**API Level**

12

**变更发生版本**

从系统OpenHarmony 5.0.0.19 版本开始。

**适配指导**

开发者可以将工程中的srcEntrance字段名称改为srcEntry，即可正常编译构建。