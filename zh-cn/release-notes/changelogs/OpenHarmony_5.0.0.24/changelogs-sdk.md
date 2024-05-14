# SDK子系统Changelog

## cl.sdk.1 api接口对于fa,stage模型使用错误告警

**变更原因**

fa，stage模型使用错误的API，现阶段抛出告警，在5.0上改为Error。

**变更影响**

moduleJson只能使用fa模型API接口，在开发者使用不合理的接口时，将出现错误提示，提示内容如下：

"This API is used only in FA Mode, but the current Mode is Stage."

非moduleJson只能使用stage模型API接口，在开发者使用不合理的接口时，将出现错误提示，提示内容如下：

"This API is used only in Stage Mode, but the current Mode is FA."

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.24开始。

**变更的接口/组件**

只包含编译结果的改变。

**适配指导**

fa模型的工程只能使用带famodelonly标签的接口，stage模型的工程只能使用带stagemodelonly标签的接口

## cl.sdk.2 ts文件使用component目录中的API告警

**变更原因**

ts文件中使用累component目录中的API，现阶段抛出告警，在5.0上改为Error。

**变更影响**

不能在ts文件中import导入component目录下的API，在开发者使用不合理的接口时，将出现告警提示，提示内容如下：

“Cannot find name '{0}'.”

{0}为对应的API。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.24开始。

**变更的接口/组件**

只包含编译结果的改变。

**适配指导**

ts文件中需要使用非component目录下的接口。

## cl.sdk.3 引用二级目录下的API告警

**变更原因**

引用二级目录下的API，现阶段抛出告警，在5.0上改为Error

**变更影响**

不能导入sdk中二级目录下的API，在开发者使用不合理的接口时，将出现告警提示，提示内容如下：

“Cannot find module '${module}' or its corresponding type declarations.”

${module}为对应二级目录文件。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.24开始。

**变更的接口/组件**

只包含编译结果的改变。

**适配指导**

不能使用二级目录下的接口。
