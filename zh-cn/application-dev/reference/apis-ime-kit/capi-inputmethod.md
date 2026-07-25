# InputMethod
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

## 概述

InputMethod模块提供C语言接口来使用输入法和开发输入法。"使用输入法"面向应用侧调用，"开发输入法"面向输入法应用开发者。

功能定位：该模块为应用侧开发者提供自绘输入框与输入法服务交互的完整C API，支持应用绑定/解绑输入法服务、向输入法发送请求和通知、接收输入法的回调通知、配置输入框属性、管理光标和避让信息等核心功能。

使用场景：适用于使用NDK开发自绘输入框的应用，需要与系统输入法服务进行交互的场景。典型流程为：应用创建TextEditorProxy和AttachOptions，通过Controller绑定输入法服务，绑定成功后通过InputMethodProxy与输入法交互，使用完毕后通过Controller解绑。

使用后效果：绑定输入法后，应用可接收输入法的文本插入、删除、光标移动等回调通知，也可主动向输入法发送光标更新、选区变更、私有命令等请求。解绑后，所有交互通道关闭，相关资源释放。

生命周期管理：本模块遵循严格的创建/销毁配对原则和绑定/解绑配对原则：

- 绑定/解绑配对：OH_InputMethodController_Attach必须与OH_InputMethodController_Detach配对调用，未解绑会导致输入法资源泄漏。
- 创建/销毁配对：所有Create函数创建的对象必须通过对应的Destroy函数销毁，否则会导致内存泄漏。
- 调用顺序：先创建依赖对象（TextEditorProxy、AttachOptions），再执行Attach绑定，绑定成功后使用InputMethodProxy交互，最后Detach解绑并销毁所有创建的对象。

线程安全：本模块的API非线程安全，建议在主线程调用。TextEditorProxy的回调执行线程可通过OH_TextEditorProxy_SetCallbackInMainThread配置。

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

## 模块架构

本模块由9个头文件组成，按职责分为四层：

- 控制层：inputmethod_controller_capi.h —— 模块核心入口，提供绑定/解绑输入法服务的能力，是所有交互的起点和终点。
- 交互层：inputmethod_text_editor_proxy_capi.h和inputmethod_inputmethod_proxy_capi.h —— 双向交互通道。TextEditorProxy是输入法→应用方向的回调注册通道，应用通过它接收输入法的文本插入、删除等通知；InputMethodProxy是应用→输入法方向的请求发送通道，应用通过它向输入法发送光标更新、选区变更等通知。
- 配置层：inputmethod_attach_options_capi.h、inputmethod_text_config_capi.h、inputmethod_cursor_info_capi.h、inputmethod_text_avoid_info_capi.h —— 各类配置和信息的承载对象，分别管理绑定选项、输入框配置、光标位置信息、避让区域信息。
- 数据层：inputmethod_private_command_capi.h和inputmethod_types_capi.h —— 私有命令数据和公共类型定义（枚举、错误码等）。

典型调用流程：
1. 通过inputmethod_text_editor_proxy_capi.h创建TextEditorProxy并注册回调。
2. 通过inputmethod_attach_options_capi.h创建AttachOptions配置绑定选项。
3. 通过inputmethod_controller_capi.h调用Attach绑定输入法，获取InputMethodProxy。
4. 通过inputmethod_inputmethod_proxy_capi.h使用InputMethodProxy与输入法交互。
5. 通过inputmethod_text_config_capi.h、inputmethod_cursor_info_capi.h等管理配置信息。
6. 通过inputmethod_controller_capi.h调用Detach解绑。
7. 销毁所有创建的对象。

## 文件汇总

| 名称 | 描述 |
| --- | --- |
| [inputmethod_controller_capi.h](capi-inputmethod-controller-capi-h.md) | 输入法控制器的头文件，提供绑定（Attach）和解绑（Detach）输入法服务的核心方法，是应用与输入法服务交互的入口和终点。Attach必须在创建TextEditorProxy和AttachOptions之后调用，Detach必须在不再使用输入法时调用以释放资源。Attach/Detach必须配对使用。 |
| [inputmethod_text_editor_proxy_capi.h](capi-inputmethod-text-editor-proxy-capi-h.md) | 文本编辑器代理的头文件，提供创建/销毁TextEditorProxy实例以及注册/获取回调函数的方法。TextEditorProxy是应用接收输入法通知和请求的回调通道，应用需在绑定前创建TextEditorProxy并注册必要的回调函数（如InsertText、DeleteForward等），绑定后输入法将通过这些回调与应用交互。生命周期由调用者管理，Create/Destroy必须配对。 |
| [inputmethod_inputmethod_proxy_capi.h](capi-inputmethod-inputmethod-proxy-capi-h.md) | 输入法代理的头文件，提供应用主动向输入法服务发送请求和通知的方法，包括显示/隐藏键盘、通知选区变更、通知光标更新、通知配置变更、发送私有命令等。InputMethodProxy实例由OH_InputMethodController_Attach返回，不可自行创建，在Detach之前保持有效。 |
| [inputmethod_attach_options_capi.h](capi-inputmethod-attach-options-capi-h.md) | 输入法绑定选项的头文件，提供AttachOptions实例的创建、销毁与属性读写方法。AttachOptions用于配置绑定输入法时的行为参数，如是否显示键盘（showKeyboard）和请求键盘的原因（requestKeyboardReason），是调用Attach时的必要参数。Create/Destroy必须配对。 |
| [inputmethod_text_config_capi.h](capi-inputmethod-text-config-capi-h.md) | 输入框配置信息的头文件，提供TextConfig实例的创建、销毁与属性读写方法。TextConfig承载输入框的完整配置信息，包括输入类型、回车键类型、光标信息、避让信息、选区范围、窗口ID、占位文本等，在TextEditorProxy的GetTextConfig回调中返回给输入法。Create/Destroy必须配对。 |
| [inputmethod_cursor_info_capi.h](capi-inputmethod-cursor-info-capi-h.md) | 光标信息的头文件，提供CursorInfo实例的创建、销毁与属性读写方法。CursorInfo描述光标在物理屏幕上的位置和尺寸，坐标必须为物理屏幕绝对坐标（单位px），用于输入法定位光标区域以实现精准输入和光标跟随。可通过TextConfig传递给输入法，也可通过NotifyCursorUpdate主动通知输入法。Create/Destroy必须配对。 |
| [inputmethod_text_avoid_info_capi.h](capi-inputmethod-text-avoid-info-capi-h.md) | 输入框避让信息的头文件，提供TextAvoidInfo实例的创建、销毁与属性读写方法。TextAvoidInfo描述键盘弹起时需要避让的区域（positionY和height），用于应用在TextConfig中告知输入法当前的避让区域信息。Create/Destroy必须配对。 |
| [inputmethod_private_command_capi.h](capi-inputmethod-private-command-capi-h.md) | 私有命令的头文件，提供PrivateCommand实例的创建、销毁与属性读写方法。PrivateCommand用于应用与输入法之间传递自定义的私有数据，支持string、bool、int32三种值类型，通过SendPrivateCommand发送或在ReceivePrivateCommand回调中接收。命令总大小限制32KB，数组最大5个元素。Create/Destroy必须配对。 |
| [inputmethod_types_capi.h](capi-inputmethod-types-capi-h.md) | 输入法公共类型定义的头文件，提供模块内所有枚举和错误码的定义，包括键盘状态（KeyboardStatus）、回车键类型（EnterKeyType）、方向（Direction）、扩展动作（ExtendAction）、文本输入类型（TextInputType）、命令值类型（CommandValueType）、请求键盘原因（RequestKeyboardReason）和错误码（ErrorCode）。本头文件不包含可调用函数，仅作为类型定义被其他头文件引用。 |
