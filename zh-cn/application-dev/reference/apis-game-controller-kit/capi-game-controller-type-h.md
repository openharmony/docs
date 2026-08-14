# game_controller_type.h
<!--Kit: Game Controller Kit-->
<!--Subsystem: Game-->
<!--Owner: @weixin_42784160-->
<!--Designer: @wudejun2025-->
<!--Tester: @fei_0805-->
<!--Adviser: @ywx1056672-->

## 概述

定义GameController模块的通用枚举类型。

**引用文件：** <GameControllerKit/game_controller_type.h>

**库：** libohgame_controller.z.so

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

**相关模块：** [GameController](capi-gamecontroller.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [GameController_ErrorCode](#gamecontroller_errorcode) | GameController_ErrorCode | 此枚举定义游戏控制器的错误码。 |

## 枚举类型说明

### GameController_ErrorCode

```c
enum GameController_ErrorCode
```

**描述**

此枚举定义游戏控制器的错误码。

**系统能力：** SystemCapability.Game.GameController

**起始版本：** 21

| 枚举项 | 描述 |
| -- | -- |
| GAME_CONTROLLER_SUCCESS = 0 | 成功。<br>**起始版本：** 21 |
| GAME_CONTROLLER_PARAM_ERROR = 401 |  参数非法。<br>**起始版本：** 21 |
| GAME_CONTROLLER_MULTIMODAL_INPUT_ERROR = 32200001 |  查询多模输入中所有设备信息失败。<br>**起始版本：** 21 |
| GAME_CONTROLLER_NO_MEMORY = 32200002 |  设备内存不足。<br>**起始版本：** 21 |


