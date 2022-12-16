# Native API 差异报告

OpenHarmony 3.2 Beta1相较于OpenHarmony 3.1 Release版本的API变更如下:

## 标准系统接口变更

| 模块名称 | 接口名称                                                     | 变更类型 | 变更说明                                        |
| -------- | ------------------------------------------------------------ | -------- | ----------------------------------------------- |
| ArkUI-xcomponent | int32_t OH_NativeXComponent_GetMouseEvent(<br/>    OH_NativeXComponent* component, const void* window, OH_NativeXComponent_MouseEvent* mouseEvent) | 新增     | 通过XComponent获取鼠标事件 |
| ArkUI-xcomponent | int32_t OH_NativeXComponent_RegisterMouseEventCallback(<br/>    OH_NativeXComponent* component, OH_NativeXComponent_MouseEvent_Callback* callback) | 新增     | 注册XComponent回调事件 |

  