# multimedia子系统变更说明

## cl.multimedia.1 getValidCommandsSync接口变更

**访问级别**

公开接口

**变更原因**

接口原实现返回成错误的int类型，现按照接口定义，修改返回为正确的AVControlCommandType类型。

**变更影响**

该变更为非兼容性变更，需要开发者进行适配。

**变更发生版本**

从OpenHarmony SDK 4.1.3.5 开始。

**变更的接口/组件**

getValidCommandsSync(): Array<AVControlCommandType>

**适配指导**

变更前：

使用已创建的AVSession，获取controller支持的指令，返回值为int数组

let validCommands = avsession.getController().getValidCommandsSync();

例如若应用只注册了play指令回调，validCommands[0]就等于0

变更后：

使用已创建的AVSession，获取controller支持的指令，返回值为AVControlCommandType类型的string数组

let validCommands = avsession.getController().getValidCommandsSync();

例如若应用只注册了play指令回调，validCommands[0]就等于'play'