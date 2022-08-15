# Native API Differences

The table below lists the native APIs changes in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## Standard System API Changes

| Module| API                                                    | Change Type| Change Description                                       |
| -------- | ------------------------------------------------------------ | -------- | ----------------------------------------------- |
| ArkUI-xcomponent | int32_t OH_NativeXComponent_GetMouseEvent(<br>    OH_NativeXComponent* component, const void* window, OH_NativeXComponent_MouseEvent* mouseEvent) | Added    | You can obtain mouse events by using the XComponent.|
| ArkUI-xcomponent | int32_t OH_NativeXComponent_RegisterMouseEventCallback(<br>    OH_NativeXComponent* component, OH_NativeXComponent_MouseEvent_Callback* callback) | Added    | You can register an XComponent callback event.|

  
