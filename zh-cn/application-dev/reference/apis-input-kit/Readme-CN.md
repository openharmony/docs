# Input Kit（多模输入服务）<!--input-api-->

- ArkTS API<!--input-arkts-->
  - [@ohos.multimodalInput.inputDevice (输入设备)](js-apis-inputdevice.md)
  - [@ohos.multimodalInput.inputEvent (输入事件)](js-apis-inputevent.md)
  - [@ohos.multimodalInput.intentionCode (意图事件)](js-apis-intentioncode.md)
  - [@ohos.multimodalInput.keyCode (键值)](js-apis-keycode.md)
  - [@ohos.multimodalInput.keyEvent (按键输入事件)](js-apis-keyevent.md)
  - [@ohos.multimodalInput.mouseEvent (鼠标输入事件)](js-apis-mouseevent.md)
  - [@ohos.multimodalInput.gestureEvent (手势事件)](js-apis-multimodalinput-gestureevent.md)
  - [@ohos.multimodalInput.pointer (鼠标指针)](js-apis-pointer.md)
  - [@ohos.multimodalInput.touchEvent (触摸输入事件)](js-apis-touchevent.md)
  - [@ohos.multimodalInput.infraredEmitter (红外管理)](js-apis-infraredemitter.md)
  - [@ohos.multimodalInput.inputConsumer (全局快捷键)](js-apis-inputconsumer.md)
  <!--Del-->
  - [@ohos.multimodalInput.pointer (鼠标指针)(系统接口)](js-apis-pointer-sys.md)
  - [@ohos.multimodalInput.shortKey (系统预置全局快捷键)(系统接口)](js-apis-shortKey-sys.md)
  - [@ohos.multimodalInput.inputConsumer (全局快捷键)(系统接口)](js-apis-inputconsumer-sys.md)
  - [@ohos.multimodalInput.inputDevice (输入设备)(系统接口)](js-apis-inputdevice-sys.md)
  - [@ohos.multimodalInput.inputEventClient (输入事件注入)(系统接口)](js-apis-inputeventclient-sys.md)
  - [@ohos.multimodalInput.inputMonitor (输入监听)(系统接口)](js-apis-inputmonitor-sys.md)
  - [@ohos.multimodalInput.gestureEvent (手势事件)(系统接口)](js-apis-multimodalinput-gestureevent-sys.md)
  - [@ohos.multimodalInput.touchEvent (触摸输入事件)(系统接口)](js-apis-touchevent-sys.md)
  - 已停止维护的接口<!--input-arkts-dep-->
    - [@ohos.multimodalInput.inputDeviceCooperate (键鼠穿越)(系统接口)](js-apis-cooperate-sys.md)
  <!--DelEnd-->
- C API<!--input-c-->
  - 模块<!--input-module-->
    - [input](capi-input.md)
  - 头文件<!--input-headerfile-->
    - [oh_axis_type.h](capi-oh-axis-type-h.md)
    - [oh_input_manager.h](capi-oh-input-manager-h.md)
    - [oh_key_code.h](capi-oh-key-code-h.md)
  - 结构体<!--input-struct-->
    - [Input_InterceptorEventCallback](capi-input-interceptoreventcallback.md)
    - [Input_DeviceListener](capi-input-devicelistener.md)
    - [Input_KeyState](capi-input-keystate.md)
    - [Input_KeyEvent](capi-input-keyevent.md)
    - [Input_MouseEvent](capi-input-mouseevent.md)
    - [Input_TouchEvent](capi-input-touchevent.md)
    - [Input_AxisEvent](capi-input-axisevent.md)
    - [Input_Hotkey](capi-input-hotkey.md)
    - [Input_DeviceInfo](capi-input-deviceinfo.md)
    - [Input_InterceptorOptions](capi-input-interceptoroptions.md)
- 错误码<!--input-arkts-errcode-->
  <!--Del-->
  - [键鼠穿越管理错误码](errorcode-cooperator.md)
  - [按键前置监听错误码](errorcode-inputmonitor.md)
  <!--DelEnd-->
  - [全局快捷键管理错误码](errorcode-inputconsumer.md)
  - [输入设备错误码](errorcode-inputdevice.md)
  - [鼠标指针错误码](errorcode-pointer.md)
