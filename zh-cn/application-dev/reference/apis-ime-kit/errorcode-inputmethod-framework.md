# 输入法框架错误码
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 12800001 包管理服务异常

**错误信息**

Bundle manager error.

**错误描述**

当依赖包管理接口来获取输入法应用包名、版本号等信息失败时，系统会报此错误码。

**可能原因**

调用getInputMethods、listCurrentInputMethodSubtype等接口获取输入法及子类型时，若获取包管理服务异常，则抛出此错误码。

**处理步骤**

开发者检查包管理服务状态，确保服务正常运行。

## 12800002 输入法应用异常

**错误信息**

Input method engine error. Possible causes:
1. input method panel not created.
2. input method application does not subscribe to input method panel lifecycle events.

**错误描述**

在执行显示键盘、隐藏键盘等操作时，由于输入法面板未创建或输入法应用未订阅相关事件导致操作失败，系统会报此错误码。

**可能原因**

1. 输入法面板未创建。
2. 输入法应用未订阅相关事件。

**处理步骤**

检查输入法应用进程是否正常运行。点击应用对话框，触发键盘显示，若键盘正常显示，则进程运行正常。

## 12800003 客户端应用异常

**错误信息**

Input method client error. Possible causes: 
1. the edit box is not focused.
2. no edit box is bound to current input method application.
3. ipc failed due to data transferred exceeding 1MB or invalid data format.

**错误描述**

当应用（微信、设置、联系人等）的对话框等编辑控件调用显示键盘、隐藏键盘失败时，系统会报此错误码。

**可能原因**

1. 应用没有获得焦点。
2. 应用客户端服务异常，导致输入法应用与应用客户端断连。
3. 传输的数据量超过1MB或数据格式不正确等原因，导致IPC失败。

**处理步骤**

1. 开发者重新将输入法应用与应用进行绑定：将应用后台进程杀死，重新启动应用，触发输入法键盘的显示，若键盘正常显示则问题解决。隐藏键盘时需调用hideTextInput接口与showTextInput配对使用。
2. 开发者将应用切换至前台，确保无其他应用或窗口遮挡，触发键盘弹出。
3. 开发者根据IPC的约束与限制，调整传输数据量为较小规模后再发起请求。一次接口调用在IPC层的总传输数据量等于应用侧发送的数据量加系统层处理所需的必要数据量，应用调用接口时实际可发送的最大数据量（约1MB），会小于IPC本身限制的最大数据量（约1.2MB）。注意：showTextInput与hideTextInput需配对调用，避免资源泄漏。

## 12800004 不是输入法应用

**错误信息**

Not an input method application.

**错误描述**

当其他应用调用了仅支持输入法应用调用的接口时，系统会报此错误码。

**可能原因**

非输入法应用调用了仅支持输入法应用的接口。

**处理步骤**

在输入法应用中调用此接口。

## 12800005 配置持久化失败

**错误信息**

Configuration persistence error.

**错误描述**

当配置持久化失败时，系统会报此错误码。

**可能原因**

当调用切换输入法接口的时候，会保存输入法的配置参数，系统参数配置模块异常导致参数保存失败时会报错。

**处理步骤**

开发者执行命令`hdc shell param get persist.sys.default_ime`查看默认输入法参数。若参数可正常显示则系统参数配置模块正常，建议重启设备后重试。

## 12800006 输入法控制器异常

**错误信息**

Input method controller error. Possible cause: create InputMethodController object failed.

**错误描述**

当获取输入法控制器失败时，系统会报此错误码。

**可能原因**

调用getController接口获取输入法控制器InputMethodController时发生异常，则抛出此错误码。

**处理步骤**

无

## 12800007 输入法设置器异常

**错误信息**

Input method setter error. Possible cause: create InputMethodSetting object failed.

**错误描述**

当获取输入法设置器失败时，系统会报此错误码。

**可能原因**

调用getSetting接口获取输入法设置器InputMethodSetting时发生异常，则抛出此错误码。

**处理步骤**

无

## 12800008 输入法管理服务异常

**错误信息**

Input method manager service error. Possible cause: a system error, such as null pointer, IPC exception.

**错误描述**

当调用输入法框架中的接口时，由于依赖输入法管理服务而服务获取异常时，系统会报此错误码。

**可能原因**

当调用[输入法框架](js-apis-inputmethod.md)中的任何接口都有可能由于依赖输入法管理服务，而服务找不到时发生此异常。

**处理步骤**

开发者执行命令`ps -A | grep inputmethod`检查输入法服务的进程号。若进程存在则服务正常运行。

## 12800009 输入法客户端未绑定

**错误信息**

Input method client detached.

**错误描述**

当前应用未绑定输入法应用。

**可能原因**

当前应用未绑定输入法时，执行了showTextInput、hideTextInput等操作。

**处理步骤**

需先执行[attach](js-apis-inputmethod.md#attach10)接口操作建立绑定，然后再调用showTextInput等接口进行键盘操作。完整调用流程：attach → showTextInput（显示键盘）→ hideTextInput（隐藏键盘），hideTextInput与showTextInput需配对使用以释放资源。

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

当前输入框未支持预上屏功能。

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

输入法应用未创建软键盘类型面板。

**处理步骤**

开发者可以通过接口[createPanel](js-apis-inputmethodengine.md#createpanel10)创建。

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

The input method is in basic mode.

**错误描述**

输入法应用非完全访问模式。

**可能原因**

调用需开启完全访问模式的接口时，若当前输入法非完全访问模式，则抛出此错误码。

**处理步骤**

在设置中开启当前输入法的完全访问模式。

## 12800015 消息接收端无法接收自定义通信数据

**错误信息**

The other side does not accept the request.

**错误描述**

消息接收端无法接收自定义通信数据。

**可能原因**

开发者调用发送自定义通信数据接口时，若消息接收端未注册[MessageHandler](js-apis-inputmethodengine.md#messagehandler15)接收数据，则抛出此错误码。

**处理步骤**

消息接收端需先注册MessageHandler接收自定义通信数据，然后才能调用recvMessage接收消息。调用顺序：先注册MessageHandler（监听数据），再调用recvMessage（接收数据）。输入法应用侧调用[recvMessage](js-apis-inputmethodengine.md#recvmessage15)，输入法客户端侧调用[recvMessage](js-apis-inputmethod.md#recvmessage15)。未注册MessageHandler即调用recvMessage会导致无法接收数据。

## 12800016 输入法客户端未处于编辑状态

**错误信息**

Input method client is not editable.

**错误描述**

输入法客户端未处于编辑状态。

**可能原因**

输入法客户端绑定后退出编辑状态。例如：自绘控件调用`Attach`后，又调用了[hideTextInput](js-apis-inputmethod.md#hidetextinput10)操作等。

**处理步骤**

输入法客户端绑定后退出编辑状态，需重新进入编辑状态。完整调用流程：attach（建立绑定）→ showTextInput（进入编辑状态）→ hideTextInput（退出编辑状态）。如：自绘控件需调用[showTextInput](js-apis-inputmethod.md#showtextinput10)重新进入编辑状态。注意：hideTextInput后不能直接调用其他编辑操作，必须先调用showTextInput重新进入编辑状态。

## 12800017 无效的面板类型或面板状态

**错误信息**

Invalid panel type or panel flag. Valid values are defined in PanelType and PanelFlag enums.

**错误描述**

无效的面板类型或面板状态。

**可能原因**

当输入法的面板类型或面板状态不支持被调用，或者被调用的接口不接受当前传入的面板类型或面板状态时，系统会抛出此错误码。

**处理步骤**

建议开发者进一步阅读接口使用说明，按要求调整当前的输入法面板类型或者面板状态。

## 12800018 输入法未找到

**错误信息**

The input method is not found.

**错误描述**

通过查询系统已安装输入法列表，输入法未找到。

**可能原因**

该输入法未安装。

**处理步骤**

开发者可以通过接口[getAllInputMethods](js-apis-inputmethod.md#getallinputmethods11)查询所有已经安装的输入法。

<!--Del-->
## 12800019 系统配置的默认输入法不支持此操作

**错误信息**

Current operation cannot be applied to the preconfigured default input method.

**错误描述**

系统配置的默认输入法不支持此操作。

**可能原因**

开发者调用接口[enableInputMethod](js-apis-inputmethod-sys.md#enableinputmethod20)设置系统配置的默认输入法的启用状态或访问模式[EnabledState](js-apis-inputmethod.md#enabledstate15)。

**处理步骤**

开发者可以通过接口[getDefaultInputMethod](js-apis-inputmethod.md#inputmethodgetdefaultinputmethod11)查询系统配置的默认输入法，判断当前操作的输入法是否为系统配置的默认输入法，若是，则不做处理。

<!--DelEnd-->

## 12800020 沉浸效果参数配置错误

**错误信息**

Invalid immersive effect.
1. The gradient mode and the fluid light mode can only be used when the immersive mode is enabled.
2. The fluid light mode can only be used when the gradient mode is enabled.
3. When the gradient mode is not enabled, the gradient height can only be 0.

**错误描述**

1. 只有在启用沉浸式模式时，才能使用渐变模式和流光模式。
2. 只有在启用渐变模式时，才能使用流光模式。
3. 未启用渐变模式时，渐变高度只能为0px。

**可能原因**

开发者调用接口[setImmersiveEffect](js-apis-inputmethodengine.md#setimmersiveeffect20)设置输入法沉浸效果[ImmersiveEffect](js-apis-inputmethodengine.md#immersiveeffect20)时，传入的参数不满足上述条件。

**处理步骤**
1. 先设置ImmersiveEffect的immersiveEnabled属性为true启用沉浸模式，再设置gradientMode启用渐变模式和fluidLightMode启用流光模式。
2. 先设置gradientMode属性启用渐变模式，再设置fluidLightMode属性启用流光模式。
3. 未启用渐变模式（gradientMode为false）时，将gradientHeight属性设置为0px。


## 12800021 调用顺序错误

**错误信息**

This operation is allowed only after adjustPanelRect or resize is called.

**错误描述**

必须先调用以下任一接口，才能调用setImmersiveEffect接口：
  - [adjustPanelRect](js-apis-inputmethodengine.md#adjustpanelrect12)(支持API version 12)
  - [adjustPanelRect](js-apis-inputmethodengine.md#adjustpanelrect15)(支持API version 15)
  - [resize](js-apis-inputmethodengine.md#resize10)(支持API version 10)

**可能原因**

开发者调用接口[setImmersiveEffect](js-apis-inputmethodengine.md#setimmersiveeffect20)之前，没有调用以下任一接口：
  - [adjustPanelRect](js-apis-inputmethodengine.md#adjustpanelrect12)(支持API version 12)
  - [adjustPanelRect](js-apis-inputmethodengine.md#adjustpanelrect15)(支持API version 15)
  - [resize](js-apis-inputmethodengine.md#resize10)(支持API version 10)

**处理步骤**

先调用以下任一接口，再调用setImmersiveEffect接口：
  - adjustPanelRect（支持API version 12或15）
  - resize（支持API version 10）
  
## 12800022 无效的displayId

**错误信息**

Invalid displayId.

**错误描述**

displayId无效或不存在。

**可能原因**

调用[getSystemPanelCurrentInsets](js-apis-inputmethodengine.md#getsystempanelcurrentinsets21)接口传入的displayId为无效的值时，会导致接口调用失败并抛出此错误码。

**处理步骤**

开发者可以通过接口[getDisplayId](js-apis-inputmethodengine.md#getdisplayid15)获取当前窗口的所在id。

## 12800023 指定的用户不存在

**错误信息**

The specified user does not exist.

**错误描述**

指定的用户不存在。

**可能原因**

调用带有userId参数的接口时，传入的userId对应的用户不存在。

**处理步骤**

开发者可以通过getOsAccountLocalIdFromNumber等系统用户管理接口确认用户ID的有效性，或检查传入的userId参数是否正确。

## 12800024 指定的用户未在前台

**错误信息**

The specified user is not in the foreground.

**错误描述**

指定的用户未在前台。

**可能原因**

调用带有userId参数的接口时，传入的userId对应的用户当前未处于前台状态。

**处理步骤**

确保目标用户处于前台状态后再调用相关接口。

## 12800025 跨用户操作被拒绝

**错误信息**

Cross-user operation denied. Only user 0 applications are authorized for this operation.

**错误描述**

跨用户操作被拒绝。只有用户0的应用才有权执行此操作。

**可能原因**

非用户0的应用尝试访问或操作其他用户的数据或功能。

**处理步骤**

开发者确保只有用户0的应用才调用此类跨用户操作接口。
<!--Del-->
## 12800026 输入法系统面板错误

**错误信息**

Input method system panel error. Possible causes: 
1. system panel not connected.
2. ipc failed due to data transferred exceeding 1MB or invalid data format.
3. the caller is not system panel.

**错误描述**

输入法系统面板相关操作失败，如调用系统面板接口时发生异常。

**可能原因**

1. 系统面板未连接。
2. 传输的数据量超过1MB或数据格式不正确等原因，导致IPC失败。
3. 调用者不是系统面板。

**处理步骤**

1. 开发者确保已调用[connectSystemChannel](js-apis-inputmethod-system-panel-manager-sys.md#inputmethodsystempanelmanagerconnectsystemchannel)接口连接系统通道。
2. 开发者根据[IPC的约束与限制](../../ipc/ipc-rpc-overview.md#约束与限制)，需先调整传输数据量，控制为较小规模后再发起请求。需特别注意：一次接口调用在IPC层的总传输数据量=应用侧发送的数据量+系统层处理所需的必要数据量，因此应用调用接口时实际可发送的最大数据量，会小于IPC本身限制的最大数据量。
3. 开发者确保调用者为系统面板。
<!--DelEnd-->