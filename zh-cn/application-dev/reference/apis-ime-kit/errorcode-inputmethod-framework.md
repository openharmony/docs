# 输入法框架错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 12800001 包管理服务异常

**错误信息**

Bundle manager error.

**错误描述**

当依赖包管理接口来获取一些信息失败时，系统会报此错误码。

**可能原因**

在调用getInputMethods、listCurrentInputMethodSubtype等接口获取输入法及子类型的时候，由于获取包管理服务异常时会报错。

**处理步骤**

无

## 12800002 输入法应用异常

**错误信息**

Input method engine error.

**错误描述**

用户调用输入法应用接口失败时，系统会报此错误码。

**可能原因**

在执行显示键盘、隐藏键盘等操作时，由于输入法应用进程死亡导致操作失败时会报错。

**处理步骤**

查看输入法应用进程是否正常。例如再次在普通应用（微信、联系人等第三方应用）中点击对话框看键盘能否被正常拉起。

## 12800003 客户端应用异常

**错误信息**

Input method client error.

**错误描述**

当三方应用（微信、设置、联系人等）的对话框等编辑控件调用显示键盘、隐藏键盘失败时，系统会报此错误码。

**可能原因**

1、三方应用客户端服务异常导致输入法应用与三方应用客户端断链。
2、三方应用没有获得焦点。

**处理步骤**

1、重新将输入法应用与三方应用进行绑定：将三方应用后台进程杀死，重新启动三方应用，通过点击对话框等方式触发输入法键盘的显示，若键盘正常显示，则问题解决。
2、将三方应用置于前台且确保没有其他应用或者窗口覆盖。通过点击对话框等方式拉起键盘。

## 12800004 不是输入法应用

**错误信息**

Not an input method.

**错误描述**

当其他应用调用了仅支持输入法应用调用的接口时，系统会报此错误码。

**可能原因**

在其他应用中调用了仅支持输入法应用调用的接口。

**处理步骤**

在输入法应用中调用此接口。

## 12800005 配置固化失败

**错误信息**

Configuration persistence error.

**错误描述**

当保存配置失败时，系统会报此错误码。

**可能原因**

当调用切换输入法接口的时候，会保存输入法的配置参数，系统参数配置模块异常导致参数保存失败时会报错。

**处理步骤**

执行hdc shell param get persist.sys.default_ime查看默认输入法参数，若可查看，则系统参数配置模块正常，可重启设备进行尝试。

## 12800006 输入法控制器异常

**错误信息**

Input method controller error.

**错误描述**

当获取到输入法控制器失败时，系统会报此错误码。

**可能原因**

在调用getCotroller接口获取输入法控制器InputMethodController时发生异常时会报错。

**处理步骤**

无。

## 12800007 输入法设置器异常

**错误信息**

Input method setter error.

**错误描述**

当获取到输入法设置器发生错误时，系统会报此错误码。

**可能原因**

在调用getSetting接口获取输入法设置器InputMethodSetting时发生异常时会报错。

**处理步骤**

无。

## 12800008 输入法管理服务异常

**错误信息**

Input method manager service error.

**错误描述**

获取输入法管理服务异常时，系统会报此错误码。

**可能原因**

当调用[输入法框架](js-apis-inputmethod.md)中的任何接口都有可能由于依赖输入法管理服务，而服务找不到时发生此异常。

**处理步骤**

通过ps -A|grep inputmethod查看是否存在输入法服务的进程号，如果存在，则服务正常。

## 12800009 输入法客户端未绑定

**错误信息**

Input method client detached.

**错误描述**

当前应用未绑定输入法应用。

**可能原因**

当前应用在没有绑定输入法的情况下执行了比如showTextInput、hideTextInput等操作。

**处理步骤**

先执行attach接口操作即可。

## 12800010 不是系统配置的默认输入法

**错误信息**

Not the preconfigured default input method.

**错误描述**

调用者应用不是系统配置的默认输入法。

**可能原因**

其他应用调用了仅支持系统配置的默认输入法应用调用的接口。

**处理步骤**

开发者可以通过接口[getDefaultInputMethod](js-apis-inputmethod.md#inputmethodgetdefaultinputmethod11)查询系统配置默认输入法，判断当前应用是否为默认输入法，若不是，则不支持调用此接口。

## 12800011 当前输入框不支持预上屏

**错误信息**

Text preview not supported.

**错误描述**

当前输入框不支持预上屏。

**可能原因**

当前输入框未支持预上屏功能。

**处理步骤**

开发者可通过接口[getEditorAttributeSync](js-apis-inputmethodengine.md#geteditorattributesync10)获取编辑框属性[EditorAttribute](js-apis-inputmethodengine.md#editorattribute)的isTextPreviewSupported，读取当前输入框是否支持预上屏，若不支持，则此接口不支持调用。

## 12800012 软键盘类型面板未创建

**错误信息**

The input method panel does not exist.

**错误描述**

软键盘类型输入法面板未创建。

**可能原因**

调用者输入法应用未创建软键盘类型面板。

**处理步骤**

开发者可以通过接口[createPanel](js-apis-inputmethodengine.md#createpanel10)创建[软键盘类型](js-apis-inputmethodengine.md#paneltype10)的[面板](js-apis-inputmethodengine.md#panel10)。

## 12800013 窗口管理服务错误

**错误信息**

Window manager service error.

**错误描述**

窗口管理服务错误。

**可能原因**

开发者调用此接口后，系统会使用窗口管理服务模块的能力。若由于系统的窗口管理服务功能问题导致接口功能异常，则抛出此错误码。

**处理步骤**

建议重启设备后重试调用接口。

## 12800014 输入法应用非完全访问模式

**错误信息**

The input method is basic mode.

**错误描述**

输入法应用非完全访问模式。

**可能原因**

开发者调用要求需开启完全访问模式的接口后，若当前输入法非完全访问模式，则抛出此错误码。

**处理步骤**

在设置中开启当前输入法的完全访问模式。

## 12800015 消息接收端无法接收自定义通信数据

**错误信息**

The another side does not accept the request.

**错误描述**

消息接收端无法接收自定义通信数据。

**可能原因**

开发者调用发送自定义通信数据接口时，若消息接收端未注册[MessageHandler](js-apis-inputmethodengine.md#messagehandler15)接收数据，则抛出此错误码。

**处理步骤**

消息接收端需注册MessageHandler接收自定义通信数据，输入法应用侧调用[recvMessage](js-apis-inputmethodengine.md#recvmessage15)，输入法客户端侧调用[recvMessage](js-apis-inputmethod.md#recvmessage15)。

## 12800016 输入法客户端未处于编辑状态

**错误信息**

The edit mode need enable.

**错误描述**

输入法客户端未处于编辑状态。

**可能原因**

输入法客户端绑定后退出了编辑状态。如：自绘控件调用Attach后又调用了[hideTextInput](js-apis-inputmethod.md#hidetextinput10)操作等。

**处理步骤**

输入法客户端绑定后退出编辑状态，需重新进入编辑状态。如：自绘控件需调用[showTextInput](js-apis-inputmethod.md#showtextinput10)重新进入编辑状态。

## 12800017 无效的面板类型或面板状态

**错误信息**

Invalid panel type or panel flag.

**错误描述**

无效的面板类型或面板状态。

**可能原因**

当前的输入法[面板类型](js-apis-inputmethodengine.md#paneltype10)或[面板状态](js-apis-inputmethodengine.md#panelflag10)不支持其调用此接口，或者此接口不支持开发者传入当前面板类型或面板状态，则抛出此错误码。

**处理步骤**

建议开发者进一步阅读接口使用说明，按要求调整当前输入法面板类型或面板状态、调整传入的参数，或者即当前面板无法使用此接口能力。