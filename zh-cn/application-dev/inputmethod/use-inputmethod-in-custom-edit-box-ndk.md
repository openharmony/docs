# 在自绘编辑框中使用输入法开发指导 (C/C++)
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy1984-->
<!--Adviser: @zhang_yixin13-->

## 场景介绍

IME Kit支持开发者在自绘编辑框中使用输入法，与输入法应用交互，包括显示、隐藏输入法，接收来自输入法应用的文本编辑操作通知等，本文档介绍开发者如何使用C/C++完成此功能开发。

## 接口说明

详细接口说明请参考[InputMethod接口文档](../reference/apis-ime-kit/capi-inputmethod.md)。

## 添加动态链接库

CMakeLists.txt中添加以下lib。

```txt
libohinputmethod.so
```

## 引用头文件

```c
#include <inputmethod/inputmethod_controller_capi.h>
```


## 绑定输入法

开发者需要在输入框获焦时，通过调用接口[OH_InputMethodController_Attach](../reference/apis-ime-kit/capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)绑定输入法，绑定成功后用户可以通过输入法输入文字。

1. 创建InputMethod_TextEditorProxy实例，示例代码如下所示：

   ```c
   // 创建InputMethod_TextEditorProxy实例
   InputMethod_TextEditorProxy *textEditorProxy = OH_TextEditorProxy_Create();
   ```
   
3. 创建InputMethod_AttachOptions实例，设置绑定输入法时的选项。示例代码如下所示：

   ```c
   // 创建InputMethod_AttachOptions实例，选项showKeyboard用于指定此次绑定成功后是否显示键盘，此处以目标显示键盘为例
   bool showKeyboard = true;
   InputMethod_AttachOptions *options = OH_AttachOptions_Create(showKeyboard);
   ```

4. 调用OH_InputMethodController_Attach发起绑定输入法服务，调用成功后，可以获取到用于和输入法交互的InputMethod_InputMethodProxy。示例代码如下所示：

   ```c
   InputMethod_InputMethodProxy *inputMethodProxy = nullptr;
   // 发起绑定请求
   if (OH_InputMethodController_Attach(textEditorProxy, options, &inputMethodProxy) != InputMethod_ErrorCode::IME_ERR_OK) {
       OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Attach failed!");
   }
   ```

## 显示/隐藏面板功能

绑定成功后，可以使用获取到的[InputMethod_InputMethodProxy](../reference/apis-ime-kit/capi-inputmethod-inputmethod-inputmethodproxy.md)对象向输入法发送消息。示例代码如下所示：

```c
// 显示键盘
if (OH_InputMethodProxy_ShowKeyboard(inputMethodProxy) != InputMethod_ErrorCode::IME_ERR_OK) {
    OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "ShowKeyboard failed!");
}
// 隐藏键盘
if (OH_InputMethodProxy_HideKeyboard(inputMethodProxy) != InputMethod_ErrorCode::IME_ERR_OK) {
    OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "HideKeyboard failed!");
}
// 通知输入框配置信息变化
if (OH_InputMethodProxy_NotifyConfigurationChange(inputMethodProxy, InputMethod_EnterKeyType::IME_ENTER_KEY_GO, InputMethod_TextInputType::IME_TEXT_INPUT_TYPE_TEXT) != InputMethod_ErrorCode::IME_ERR_OK) {
    OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "NotifyConfigurationChange failed!");
}
```

## 监听输入法应用的请求/通知

1. 需要先实现对输入法应用发送的请求或通知的响应处理函数，示例代码如下所示：

   ```c
   // 实现InputMethod_TextEditorProxy中的输入法应用事件响应函数
   void GetTextConfig(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config)
   {
       // 处理输入法发送的获取输入框配置请求
   }
   void InsertText(InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length)
   {
       // 处理输入法发送的插入文本请求
   }
   void DeleteForward(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
   {
       // 处理输入法发送的删除文本请求
   }
   // ......
   ```

2. 将实现后的响应函数，设置到[InputMethod_TextEditorProxy](../reference/apis-ime-kit/capi-inputmethod-inputmethod-texteditorproxy.md)中，再通过绑定输入法时调用的[OH_InputMethodController_Attach](../reference/apis-ime-kit/capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach)将其设置到输入法框架中，完成监听注册。示例代码如下所示：

   ```c
   // 将实现好的响应处理函数设置到InputMethod_TextEditorProxy中
   OH_TextEditorProxy_SetGetTextConfigFunc(textEditorProxy, GetTextConfig);
   OH_TextEditorProxy_SetInsertTextFunc(textEditorProxy, InsertText);
   OH_TextEditorProxy_SetDeleteForwardFunc(textEditorProxy, DeleteForward);
   ```

## 解绑输入法

当编辑框失焦，需要结束使用输入法，通过接口[OH_InputMethodController_Detach](../reference/apis-ime-kit/capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_detach)与输入法框架解绑。

```c
// 发起解绑请求
if (OH_InputMethodController_Detach(inputMethodProxy) != InputMethod_ErrorCode::IME_ERR_OK) {
    OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Detach failed!");
}
inputMethodProxy = nullptr;
OH_TextEditorProxy_Destroy(textEditorProxy);
textEditorProxy = nullptr;
OH_AttachOptions_Destroy(options);
options = nullptr;
```

## 完整示例

示例代码展示了绑定输入法、隐藏输入法、解绑输入法的完整流程。

示例代码总入口为InputMethodNdkDemo函数。

> 说明：
>
> 需要在CMakeList.txt中添加libohinputmethod.so libhilog_ndk.z.so依赖。
```c++
#include <codecvt>
#include <locale>
#include <string>

#include "hilog/log.h"
#include "inputmethod/inputmethod_controller_capi.h"

void GetTextConfigFunc(InputMethod_TextEditorProxy *proxy, InputMethod_TextConfig *config) { // 处理获取输入框配置请求
    auto ret = OH_TextConfig_SetEnterKeyType(config, InputMethod_EnterKeyType::IME_ENTER_KEY_SEND);
    if (ret != IME_ERR_OK) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "SetEnterKeyType failed, ret=%{public}d", ret);
        return;
    }

    ret = OH_TextConfig_SetInputType(config, InputMethod_TextInputType::IME_TEXT_INPUT_TYPE_PHONE);
    if (ret != IME_ERR_OK) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "SetInputType failed, ret=%{public}d", ret);
        return;
    }
}
void InsertTextFunc(InputMethod_TextEditorProxy *proxy, const char16_t *text, size_t length) {
    // 处理插入文本请求
    // 将char16_t类型的字符串转换为u16string
    std::u16string u16Str(text);

    // 转换为UTF-8编码的string
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
    std::string utf8Str = converter.to_bytes(u16Str);

    OH_LOG_Print(LOG_APP, LOG_INFO, 0, "testTag", "insertText=%{public}s", utf8Str.c_str());
}
void DeleteForwardFunc(InputMethod_TextEditorProxy *proxy, int32_t length) {
    // 处理删除光标右侧文本请求
}
void DeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, int32_t length) {
    // 处理删除光标左侧文本请求
}
void SendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, InputMethod_KeyboardStatus status) {
    // 处理键盘状态发生变化请求
}
void SendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, InputMethod_EnterKeyType type) {
    // 处理回车键功能发生变化请求
}
void MoveCursorFunc(InputMethod_TextEditorProxy *proxy, InputMethod_Direction direction) {
    // 处理移动光标请求
}
void HandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, int32_t start, int32_t end) {
    // 处理选中文本请求
}
void HandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, InputMethod_ExtendAction action) {
    // 处理扩展编辑请求
}
void GetleftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, int32_t number, char16_t text[], size_t *length) {
    // 处理获取光标左侧文本请求
}
void GetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, int32_t number, char16_t text[], size_t *length) {
    // 处理获取光标右侧文本请求
}
int32_t GetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy) {
// 处理获取光标所在输入框文本索引请求
    return 0;
}
int32_t ReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, InputMethod_PrivateCommand *privateCommand[],
                                  size_t size) {
    // 处理私有数据命令请求
    return 0;
}
int32_t SetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, const char16_t *text, size_t length, int32_t start,
                           int32_t end) {
    // 处理设置预上屏文本请求
    return 0;
}
void FinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy) {
    // 处理结束预上屏请求
}

void ConstructTextEditorProxy(InputMethod_TextEditorProxy *textEditorProxy) {
    OH_TextEditorProxy_SetGetTextConfigFunc(textEditorProxy, GetTextConfigFunc);
    OH_TextEditorProxy_SetInsertTextFunc(textEditorProxy, InsertTextFunc);
    OH_TextEditorProxy_SetDeleteForwardFunc(textEditorProxy, DeleteForwardFunc);
    OH_TextEditorProxy_SetDeleteBackwardFunc(textEditorProxy, DeleteBackwardFunc);
    OH_TextEditorProxy_SetSendKeyboardStatusFunc(textEditorProxy, SendKeyboardStatusFunc);
    OH_TextEditorProxy_SetSendEnterKeyFunc(textEditorProxy, SendEnterKeyFunc);
    OH_TextEditorProxy_SetMoveCursorFunc(textEditorProxy, MoveCursorFunc);
    OH_TextEditorProxy_SetHandleSetSelectionFunc(textEditorProxy, HandleSetSelectionFunc);
    OH_TextEditorProxy_SetHandleExtendActionFunc(textEditorProxy, HandleExtendActionFunc);
    OH_TextEditorProxy_SetGetLeftTextOfCursorFunc(textEditorProxy, GetleftTextOfCursorFunc);
    OH_TextEditorProxy_SetGetRightTextOfCursorFunc(textEditorProxy, GetRightTextOfCursorFunc);
    OH_TextEditorProxy_SetGetTextIndexAtCursorFunc(textEditorProxy, GetTextIndexAtCursorFunc);
    OH_TextEditorProxy_SetReceivePrivateCommandFunc(textEditorProxy, ReceivePrivateCommandFunc);
    OH_TextEditorProxy_SetSetPreviewTextFunc(textEditorProxy, SetPreviewTextFunc);
    OH_TextEditorProxy_SetFinishTextPreviewFunc(textEditorProxy, FinishTextPreviewFunc);
}

void InputMethodNdkDemo() {
    // 创建InputMethod_TextEditorProxy实例
    InputMethod_TextEditorProxy *textEditorProxy = OH_TextEditorProxy_Create();
    if (textEditorProxy == nullptr) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Create TextEditorProxy failed.");
        return;
    }

    // 将实现好的响应处理函数设置到InputMethod_TextEditorProxy中
    ConstructTextEditorProxy(textEditorProxy);

    // 创建InputMethod_AttachOptions实例，选项showKeyboard用于指定此次绑定成功后是否显示键盘，此处以目标显示键盘为例
    bool showKeyboard = true;
    InputMethod_AttachOptions *attachOptions = OH_AttachOptions_Create(showKeyboard);
    if (attachOptions == nullptr) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Create AttachOptions failed.");
        OH_TextEditorProxy_Destroy(textEditorProxy);
        return;
    }

    InputMethod_InputMethodProxy *inputMethodProxy = nullptr;
    // 发起绑定请求
    auto ret = OH_InputMethodController_Attach(textEditorProxy, attachOptions, &inputMethodProxy);
    if (ret != IME_ERR_OK) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Attach failed, ret=%{public}d.", ret);
        OH_TextEditorProxy_Destroy(textEditorProxy);
        OH_AttachOptions_Destroy(attachOptions);
        return;
    }

    // 让键盘显示3s
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // 隐藏键盘
    ret = OH_InputMethodProxy_HideKeyboard(inputMethodProxy);
    if (ret != IME_ERR_OK) {
        OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "HideKeyboard failed, ret=%{public}d.", ret);
        OH_TextEditorProxy_Destroy(textEditorProxy);
        OH_AttachOptions_Destroy(attachOptions);
        return;
    }

    // 发起解绑请求
    OH_InputMethodController_Detach(inputMethodProxy);
    OH_TextEditorProxy_Destroy(textEditorProxy);
    OH_AttachOptions_Destroy(attachOptions);
    OH_LOG_Print(LOG_APP, LOG_INFO, 0, "testTag", "Finished.");
}
```