# error_code.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

定义ArkUI Native API的错误码枚举值，用于表示接口调用结果或失败原因。

**引用文件：** <arkui/error_code.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_ErrorCode](#arkui_errorcode) | ArkUI_ErrorCode | 定义ArkUI Native API的错误码枚举值，用于表示接口调用结果或失败原因。 |

## 枚举类型说明

### ArkUI_ErrorCode

```c
enum ArkUI_ErrorCode
```

**描述：**

定义ArkUI Native API的错误码枚举值，用于表示接口调用结果或失败原因。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_ERROR_CODE_NO_ERROR = 0 | 无错误。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_PARAM_INVALID = 401 | 参数错误。 <br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_CAPI_INIT_ERROR = 500 |  接口初始化错误。<br>**起始版本：** 18 |
| ARKUI_ERROR_CODE_INTERNAL_ERROR = 100001 | 出现内部错误，例如运行环境异常导致接口调用失败，或接口内部执行失败。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_PARAM_ERROR = 100023 |  参数错误。错误码的详细介绍请参见[100023 参数错误](errorcode-node.md#100023-参数错误)。<br>**起始版本：** 21 |
| ARKUI_ERROR_CODE_XCOMPONENT_STATE_INVALID = 103501 |  当前XComponent状态异常，方法调用失败。错误码的详细介绍请参见[XComponent组件错误码](errorcode-xcomponent.md)。<br>**起始版本：** 18 |
| ARKUI_ERROR_CODE_ATTRIBUTE_OR_EVENT_NOT_SUPPORTED = 106102 | 组件不支持特定的属性或者事件。错误码的详细介绍请参见[交互事件错误码](errorcode-event.md)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_ARKTS_NODE_NOT_SUPPORTED = 106103 | 不支持对ArkTS创建的节点执行对应的操作。错误码的详细介绍请参见[106103 对应的操作不支持ArkTS创建的节点](errorcode-node.md#106103-对应的操作不支持arkts创建的节点)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_ADAPTER_NOT_BOUND = 106104 | 懒加载适配器未绑定到组件上。错误码的详细介绍请参见[106104 适配器未绑定](errorcode-nodeadapter.md#106104-适配器未绑定)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_ADAPTER_EXIST = 106105 | 适配器已存在。错误码的详细介绍请参见[106105 适配器已存在](errorcode-nodeadapter.md#106105-适配器已存在)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_CHILD_NODE_EXIST = 106106 | 对应节点已存在子节点，无法添加适配器。错误码的详细介绍请参见[106106 子节点已存在](errorcode-nodeadapter.md#106106-子节点已存在)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INDEX_OUT_OF_RANGE = 106107 | 组件事件中的参数下标越界。错误码的详细介绍请参见[106107 组件事件中的参数下标越界](errorcode-nodeadapter.md#106107-组件事件中的参数下标越界)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_NODE_EVENT_PARAM_INVALID = 106108 | 组件事件中不存在调用方请求获取的数据。错误码的详细介绍请参见[106108 组件事件中不存在调用方请求获取的数据](errorcode-nodeadapter.md#106108-组件事件中不存在调用方请求获取的数据)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_NODE_EVENT_NO_RETURN = 106109 | 组件事件不支持返回值。错误码的详细介绍请参见[106109 不支持返回值](errorcode-nodeadapter.md#106109-不支持返回值)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_NODE_UNSUPPORTED_EVENT_TYPE = 106110 | 暂不支持该事件类型。错误码的详细介绍请参见[106110 暂不支持该事件类型](errorcode-nodeadapter.md#106110-暂不支持该事件类型)。<br>**起始版本：** 21 |
| ARKUI_ERROR_CODE_NODE_INDEX_INVALID = 106200 | 传入的索引值非法。<br/>错误码的详细介绍请参见[106200 传入的索引值非法](errorcode-router.md#106200-传入的索引值非法)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_GET_INFO_FAILED = 106201 | 查询路由导航信息失败。<br/>错误码的详细介绍请参见[106201 查询路由导航信息失败](errorcode-router.md#106201-查询路由导航信息失败)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR = 106202 | 传入的buffer size不足以容纳目标数据。<br/>错误码的详细介绍请参见[106202 传入的buffer size不足以容纳目标数据](errorcode-router.md#106202-传入的buffer-size不足以容纳目标数据)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_NODE_NOT_ON_MAIN_TREE = 106203 |  传入的节点未挂载到组件树上。错误码的详细介绍请参见[106203 传入的节点未挂载到组件树上](errorcode-node.md#106203-传入的节点未挂载到组件树上)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_NODE_ON_INVALID_THREAD = 106204 |  不支持在非UI线程操作传入的节点。错误码的详细介绍请参见[106204 不支持在非UI线程操作传入的节点](errorcode-node.md#106204-不支持在非ui线程操作传入的节点)。<br>**起始版本：** 22 |
| ARKUI_ERROR_CODE_FORCE_DARK_CONFIG_INVALID = 106205 |  反色能力入参错误。错误码的详细介绍请参见[106205 反色能力配置错误](errorcode-force-dark.md#106205-反色能力配置错误)。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_NODE_IS_ADOPTED = 106206 |  节点已被接纳为附属节点。错误码的详细介绍请参见[106206 节点已被接纳为附属节点](errorcode-adopt.md#106206-节点已被接纳为附属节点)。<br>**起始版本：** 22 |
| ARKUI_ERROR_CODE_NODE_HAS_PARENT = 106207 |  被接纳的节点已有父节点。错误码的详细介绍请参见[106207 被接纳的附属节点已有父节点](errorcode-adopt.md#106207-被接纳的附属节点已有父节点)。<br>**起始版本：** 22 |
| ARKUI_ERROR_CODE_NODE_CAN_NOT_BE_ADOPTED = 106208 |  节点无法被接纳为附属节点。错误码的详细介绍请参见[106208 节点无法被接纳为附属节点](errorcode-adopt.md#106208-节点无法被接纳为附属节点)。<br>**起始版本：** 22 |
| ARKUI_ERROR_CODE_NODE_CAN_NOT_ADOPT_TO = 106209 |  节点无法接纳其他节点。错误码的详细介绍请参见[106209 节点无法接纳其他节点](errorcode-adopt.md#106209-节点无法接纳其他节点)。<br>**起始版本：** 22 |
| ARKUI_ERROR_CODE_NODE_IS_NOT_IN_ADOPTED_CHILDREN = 106210 |  节点不是被目标节点接纳的附属节点。错误码的详细介绍请参见[106210 节点不是被目标节点接纳的附属节点](errorcode-adopt.md#106210-节点不是被目标节点接纳的附属节点)。<br>**起始版本：** 22 |
| ARKUI_ERROR_CODE_NOT_CUSTOM_NODE = 106401 |  当前节点不是自定义节点。错误码的详细介绍请参见[渲染节点错误码](errorcode-node-render.md)。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_CHILD_EXISTED = 106402 |  当前节点已存在子节点。错误码的详细介绍请参见[渲染节点错误码](errorcode-node-render.md)。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_RENDER_PARENT_EXISTED = 106403 |  当前渲染节点存在父节点。错误码的详细介绍请参见[渲染节点错误码](errorcode-node-render.md)。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_RENDER_CHILD_NOT_EXIST = 106404 |  未找到对应的渲染子节点。错误码的详细介绍请参见[渲染节点错误码](errorcode-node-render.md)。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_PARAM_OUT_OF_RANGE = 106405 |  参数值超出范围。错误码的详细介绍请参见[渲染节点错误码](errorcode-node-render.md)。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_RENDER_IS_FROM_FRAME_NODE = 106406 |  当前渲染节点从[FrameNode](js-apis-arkui-frameNode.md)中获取。错误码的详细介绍请参见[106406 当前渲染节点从FrameNode中获取](errorcode-node-render.md#106406-当前渲染节点从framenode中获取)。<br>**起始版本：** 22 |
| ARKUI_ERROR_CODE_RENDER_HAS_INVALID_FRAME_NODE = 106407 |  当前渲染节点从[FrameNode](js-apis-arkui-frameNode.md)中获取且该[FrameNode](js-apis-arkui-frameNode.md)已被取消接纳为附属节点或销毁。错误码的详细介绍请参见[106407 当前渲染节点从FrameNode中获取且该FrameNode已被取消接纳为附属节点或销毁](errorcode-node-render.md#106407-当前渲染节点从framenode中获取且该framenode已被取消接纳为附属节点或销毁)。<br>**起始版本：** 22 |
| ARKUI_ERROR_CODE_RENDER_NOT_ADOPTED_NODE = 106408 |  当前节点不处于被接纳状态。错误码的详细介绍请参见[106408 当前节点不处于被接纳状态](errorcode-node-render.md#106408-当前节点不处于被接纳状态)。<br>**起始版本：** 22 |
| ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE = 150001 |  当前节点无法获得焦点。错误码的详细介绍请参见[150001 节点无法获得焦点](errorcode-focus.md#150001-节点无法获得焦点)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_FOCUS_NON_FOCUSABLE_ANCESTOR = 150002 |  当前节点对应的祖先节点中存在无法获焦节点。错误码的详细介绍请参见[150002 祖先节点无法获得焦点](errorcode-focus.md#150002-祖先节点无法获得焦点)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_FOCUS_NON_EXISTENT = 150003 |  当前节点不存在。错误码的详细介绍请参见[150003 节点不存在](errorcode-focus.md#150003-节点不存在)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_TIMEOUT = 160002 |  截图超时。错误码的详细介绍请参见[截图错误码](errorcode-snapshot.md)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_MODE_NOT_SUPPORTED = 160003 | 截图选项中设置的色彩空间或动态范围模式不受支持。错误码的详细介绍请参见[截图错误码](errorcode-snapshot.md)。<br>**起始版本：** 23 |
| ARKUI_ERROR_CODE_COMPONENT_SNAPSHOT_AUTO_NOT_SUPPORTED = 160004 | 离屏节点截图不支持将色彩空间或动态范围模式对应的isAuto参数设置为true。错误码的详细介绍请参见[截图错误码](errorcode-snapshot.md)。<br>**起始版本：** 23 |
| ARKUI_ERROR_CODE_NON_SCROLLABLE_CONTAINER = 180001 | 非滚动类容器。错误码的详细介绍请参见[交互事件错误码](errorcode-event.md)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH = 180002 | 存储区大小不足。错误码的详细介绍请参见[交互事件错误码](errorcode-event.md)。<br>**起始版本：** 12 |
| ARKUI_ERROR_CODE_NOT_CLONED_POINTER_EVENT = 180003 |  该事件不是克隆事件。错误码的详细介绍请参见[交互事件错误码](errorcode-event.md)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL = 180004 |  组件状态异常。错误码的详细介绍请参见[交互事件错误码](errorcode-event.md)。<br>**起始版本：** 15 |
| ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT = 180005 |  未命中可响应事件的组件。错误码的详细介绍请参见[交互事件错误码](errorcode-event.md)。<br>**起始版本：** 15 |
| ARKUI_ERROR_INPUT_EVENT_TYPE_NOT_SUPPORTED = 180006 |  接口不支持此输入事件类型。<br>**起始版本：** 20 |
| ARKUI_ERROR_CODE_INVALID_STYLED_STRING = 180101 |  无效的属性字符串。错误码的详细介绍请参见[属性字符串错误码](errorcode-styled-string.md)。<br>**起始版本：** 14 |
| ARKUI_ERROR_CODE_UI_CONTEXT_INVALID = 190001 |  无效的UIContext对象。错误码的详细介绍请参见[UI上下文错误码](errorcode-uicontext.md)。<br>**起始版本：** 18 |
| ARKUI_ERROR_CODE_CALLBACK_INVALID = 190002 |  无效的回调函数。错误码的详细介绍请参见[UI上下文错误码](errorcode-uicontext.md)。<br>**起始版本：** 18 |
| ARKUI_ERROR_CODE_RECOGNIZER_TYPE_NOT_SUPPORTED = 180102 |  不支持手势识别器类型。错误码的详细介绍请参见[交互事件错误码](errorcode-event.md)。<br>**起始版本：** 18 |
| ARKUI_ERROR_CODE_DRAG_DROP_OPERATION_NOT_ALLOWED = 190004 | 当前拖放事件处理阶段不允许执行请求的操作。错误码的详细介绍请参见[拖拽事件错误码](errorcode-drag-event.md)。<br>**起始版本：** 19 |
