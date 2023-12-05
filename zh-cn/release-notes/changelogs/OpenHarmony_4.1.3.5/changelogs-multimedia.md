# multimedia子系统变更说明

## cl.multimedia.1 getVaildCommandsSync接口变更

**访问级别**

公开接口

**变更原因**

接口原实现返回类型为int数组，不利于开发者理解。修改实现返回字符串数组，类型为AVControlCommandType，更便于开发者的理解与使用。

**变更影响**

该变更为非兼容性变更，需要开发者进行适配。

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的接口/组件**

getValidCommandsSync(): Array<AVControlCommandType>

**适配指导**

变更前：

使用已创建的AVSession，获取controller支持的指令，返回值为int数组

let validCommands = avsession.getController().getVaildCommandsSync();

例如若应用只注册了play指令回调，validCommands[0]就等于0

变更后：

使用已创建的AVSession，获取controller支持的指令，返回值为AVControlCommandType类型的string数组

let validCommands = avsession.getController().getVaildCommandsSync();

例如若应用只注册了play指令回调，validCommands[0]就等于'play'