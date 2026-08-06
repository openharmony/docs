# Using the Input Method in a Custom Edit Box (C/C++)

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=b8aa633cba260f62cfd1846a2d514205881380a2 translatedAt=2026-08-04T08:30:00.664Z pushedAt=2026-08-04T08:59:50.934Z -->

## When to Use

IME Kit allows you to use input method in the custom edit box to interact with input method applications, including displaying and hiding input methods and receiving text editing notifications from input method applications. This document describes how to use C/C++ to develop this function.

## APIs

For details about the APIs, see [API Reference](../reference/apis-ime-kit/capi-inputmethod.md).

## Adding Dynamic Link Libraries

Add the following library to **CMakeLists.txt**.

```txt
libohinputmethod.so
```

## Including Header Files

```c
#include <inputmethod/inputmethod_controller_capi.h>
```

## Binding an Input Method

When the text box is focused, you can call the [OH_InputMethodController_Attach](../reference/apis-ime-kit/capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) API to bind the input method. After the binding is successful, you can use the input method to enter text.

1. Create an **InputMethod_TextEditorProxy** instance. The sample code is as follows:

   <!-- @[input_case_input_TextEditorProxy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputMethod/KikaInputMethod/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   // Create an InputMethod_TextEditorProxy instance.
   textEditorProxy = OH_TextEditorProxy_Create();
   ```

2. Create an **InputMethod_AttachOptions** instance and set the options for binding the input method. The sample code is as follows:

   <!-- @[input_case_input_attachOptions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputMethod/KikaInputMethod/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   // Create an InputMethod_AttachOptions instance. The showKeyboard option specifies whether to display the keyboard after the attachment succeeds. Set to true to automatically display the keyboard after a successful attachment, or false to not display it automatically.
   bool showKeyboard = true;
   attachOptions = OH_AttachOptions_Create(showKeyboard);
   ```

3. Call **OH_InputMethodController_Attach** to bind the input method service. After the call is successful, you can obtain **InputMethod_InputMethodProxy** used to interact with the input method. The sample code is as follows:

   <!-- @[input_case_input_OH_InputMethodController_Attach](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputMethod/KikaInputMethod/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   // Send a binding request.
   auto ret = OH_InputMethodController_Attach(textEditorProxy, attachOptions, &inputMethodProxy);
   if (ret != IME_ERR_OK) {
       OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Attach failed, ret=%{public}d.", ret);
       OH_TextEditorProxy_Destroy(textEditorProxy);
       OH_AttachOptions_Destroy(attachOptions);
       return;
   }
   ```

## Displaying or Hiding the Panel

After the binding is successful, you can use the obtained [InputMethod_InputMethodProxy](../reference/apis-ime-kit/capi-inputmethod-inputmethod-inputmethodproxy.md) object to send a message to the input method. The sample code is as follows:

```c
// Display the keyboard.
if (OH_InputMethodProxy_ShowKeyboard(inputMethodProxy) != InputMethod_ErrorCode::IME_ERR_OK) {
    OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "ShowKeyboard failed!");
}
// Hide the keyboard.
if (OH_InputMethodProxy_HideKeyboard(inputMethodProxy) != InputMethod_ErrorCode::IME_ERR_OK) {
    OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "HideKeyboard failed!");
}
// Notify the change of the input box configuration.
if (OH_InputMethodProxy_NotifyConfigurationChange(inputMethodProxy, InputMethod_EnterKeyType::IME_ENTER_KEY_GO, InputMethod_TextInputType::IME_TEXT_INPUT_TYPE_TEXT) != InputMethod_ErrorCode::IME_ERR_OK) {
    OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "NotifyConfigurationChange failed!");
}
```

## Listening to Requests/Notifications from the Input Method Application

1. Implement the response processing function for the request or notification sent by the input method application. The sample code is as follows:

   ```c
   // Implement the input method application event response function in InputMethod_TextEditorProxy.
   void GetTextConfigFunc(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config)
   {
       // Process the request sent by the input method for obtaining the input box configuration.
   }
   void InsertTextFunc(InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length)
   {
       // Process the text insertion request sent by the input method.
   }
   void DeleteForwardFunc(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
   {
       // Process the text deletion request sent by the input method.
   }
   // ......
   ```

2. Set the implemented response function to [InputMethod_TextEditorProxy](../reference/apis-ime-kit/capi-inputmethod-inputmethod-texteditorproxy.md), and then set it to the input method framework using [OH_InputMethodController_Attach](../reference/apis-ime-kit/capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_attach) called when the input method is bound to complete listener registration. The sample code is as follows:

   <!-- @[input_case_input_ConstructTextEditorProxy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputMethod/KikaInputMethod/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   OH_TextEditorProxy_SetGetTextConfigFunc(textEditorProxy, GetTextConfigFunc);
   OH_TextEditorProxy_SetInsertTextFunc(textEditorProxy, InsertTextFunc);
   OH_TextEditorProxy_SetDeleteForwardFunc(textEditorProxy, DeleteForwardFunc);
   OH_TextEditorProxy_SetDeleteBackwardFunc(textEditorProxy, DeleteBackwardFunc);
   OH_TextEditorProxy_SetSendKeyboardStatusFunc(textEditorProxy, SendKeyboardStatusFunc);
   OH_TextEditorProxy_SetSendEnterKeyFunc(textEditorProxy, SendEnterKeyFunc);
   OH_TextEditorProxy_SetMoveCursorFunc(textEditorProxy, MoveCursorFunc);
   OH_TextEditorProxy_SetHandleSetSelectionFunc(textEditorProxy, HandleSetSelectionFunc);
   OH_TextEditorProxy_SetHandleExtendActionFunc(textEditorProxy, HandleExtendActionFunc);
   OH_TextEditorProxy_SetGetLeftTextOfCursorFunc(textEditorProxy, GetLeftTextOfCursorFunc);
   OH_TextEditorProxy_SetGetRightTextOfCursorFunc(textEditorProxy, GetRightTextOfCursorFunc);
   OH_TextEditorProxy_SetGetTextIndexAtCursorFunc(textEditorProxy, GetTextIndexAtCursorFunc);
   OH_TextEditorProxy_SetReceivePrivateCommandFunc(textEditorProxy, ReceivePrivateCommandFunc);
   OH_TextEditorProxy_SetSetPreviewTextFunc(textEditorProxy, SetPreviewTextFunc);
   OH_TextEditorProxy_SetFinishTextPreviewFunc(textEditorProxy, FinishTextPreviewFunc);
   ```

## Unbinding an Input Method

When the edit box is out of focus, you need to stop using the input method and unbind from the input method framework by calling [OH_InputMethodController_Detach](../reference/apis-ime-kit/capi-inputmethod-controller-capi-h.md#oh_inputmethodcontroller_detach).

   <!-- @[input_case_input_OH_InputMethodController_Detach](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputMethod/KikaInputMethod/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   // Send an unbinding request.
   OH_InputMethodController_Detach(inputMethodProxy);
   OH_TextEditorProxy_Destroy(textEditorProxy);
   OH_AttachOptions_Destroy(attachOptions);
   ```

## Sample Code

The sample code shows how to bind, hide, and unbind an input method.

The entry is the **InputMethodNdkDemo** function.

> **NOTE**
>
> Dependencies of **libohinputmethod.so** and **libhilog_ndk.z.so** should be added to the **CMakeList.txt** file.

   <!-- @[input_case_input_CPreview016](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputMethod/KikaInputMethod/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   #include "napi/native_api.h"
   #include <codecvt>
   #include <locale>
   #include <thread>
   
   #include "hilog/log.h"
   #include "inputmethod/inputmethod_controller_capi.h"
   
    constexpr int32_t TEXTSIZE = 1024;
   
   static std::string g_strText;
   char g_strTextChar[TEXTSIZE];
   int32_t g_strTextCharLen = 0;
   bool g_flagShow = false;
   std::mutex g_textMutex;
   InputMethod_TextEditorProxy *textEditorProxy = nullptr;
   InputMethod_AttachOptions *attachOptions = nullptr;
   InputMethod_InputMethodProxy *inputMethodProxy = nullptr;
   
   void InputMethodDestroy();
   
   void InitText()
   {
       std::lock_guard<std::mutex> lock(g_textMutex);
       if (g_flagShow) {
           memset(g_strTextChar, 0x00, sizeof(g_strTextChar));
           g_strTextCharLen = 0;
           g_flagShow = false;
       }
   }
   
   void SetText(const char* input)
   {
       std::lock_guard<std::mutex> lock(g_textMutex);
       g_strTextCharLen = strlen(input);
       if (g_strTextCharLen > TEXTSIZE) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Length greater than 1024 , ret=%{public}d", g_strTextCharLen);
       }
       strncpy(g_strTextChar, input, g_strTextCharLen);
   }
   
   void GetTextConfigFunc(InputMethod_TextEditorProxy *proxy, InputMethod_TextConfig *config)
   { // Process the request sent by the input method for obtaining the text box configuration.
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
   
   void InsertTextFunc(InputMethod_TextEditorProxy *proxy, const char16_t *text, size_t length)
   {
       InitText();
   
       // Process the text insertion request.
       // Convert the string of the char16_t type to u16string.
       std::u16string u16Str(text, length + 1);
   
       // Convert the string to the UTF-8 encoding format.
       std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
       std::string utf8Str = converter.to_bytes(u16Str);
       for (size_t i = 0; i < utf8Str.size(); ++i) {
           unsigned char c = static_cast<unsigned char>(utf8Str[i]);
           if (c != 0x00) {
               std::lock_guard<std::mutex> lock(g_textMutex);
               g_strTextChar[g_strTextCharLen] = c;
               g_strTextCharLen += 1;
           }
       }
   }
   
   void DeleteForwardFunc(InputMethod_TextEditorProxy *proxy, int32_t length)
   {
       std::lock_guard<std::mutex> lock(g_textMutex);
       if (g_strTextCharLen > 0) {
           strncpy(g_strTextChar, g_strTextChar + 1, g_strTextCharLen - 1);
           g_strTextCharLen = (g_strTextCharLen > 0) ? g_strTextCharLen - 1 : g_strTextCharLen;
       }
   }
   
   void DeleteBackwardFunc(InputMethod_TextEditorProxy *proxy, int32_t length)
   {
       std::lock_guard<std::mutex> lock(g_textMutex);
       g_strTextCharLen = (g_strTextCharLen > 0) ? g_strTextCharLen - 1 : g_strTextCharLen;
       g_strTextChar[g_strTextCharLen] = '\0';
   }
   
   void SendKeyboardStatusFunc(InputMethod_TextEditorProxy *proxy, InputMethod_KeyboardStatus status)
   {
       if (status == InputMethod_KeyboardStatus::IME_KEYBOARD_STATUS_HIDE) {
           g_flagShow = false;
           SetText("The keyboard is hidden.");
       } else if (status == InputMethod_KeyboardStatus::IME_KEYBOARD_STATUS_SHOW && g_flagShow != true) {
           g_flagShow = true;
           SetText("The keyboard is displayed.");
       }
   }
   
   void SendEnterKeyFunc(InputMethod_TextEditorProxy *proxy, InputMethod_EnterKeyType type)
   {
       SetText("Process the Enter key request.");
       g_flagShow = true;
   }
   
   void MoveCursorFunc(InputMethod_TextEditorProxy *proxy, InputMethod_Direction direction)
   {
       if (direction == InputMethod_Direction::IME_DIRECTION_UP) {
           SetText("The cursor is moving upward.");
       } else if (direction == InputMethod_Direction::IME_DIRECTION_DOWN) {
           SetText("The cursor is moving downward.");
       } else if (direction == InputMethod_Direction::IME_DIRECTION_LEFT) {
           SetText("The cursor is moving left.");
       } else if (direction == InputMethod_Direction::IME_DIRECTION_RIGHT) {
           SetText("The cursor is moving right.");
       } else {
           SetText("An error occurred while moving the cursor.");
       }
   }
   
   void HandleSetSelectionFunc(InputMethod_TextEditorProxy *proxy, int32_t start, int32_t end)
   {
       SetText("Process the selected text request.");
   }
   
   void HandleExtendActionFunc(InputMethod_TextEditorProxy *proxy, InputMethod_ExtendAction action)
   {
       SetText("Process the extended edit request.");
   }
   
   void GetLeftTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, int32_t number, char16_t text[], size_t *length)
   {
       OH_LOG_Print(LOG_APP, LOG_INFO, 0, "testTag", "Process the request for obtaining the text on the left of the cursor.");
   }
   
   void GetRightTextOfCursorFunc(InputMethod_TextEditorProxy *proxy, int32_t number, char16_t text[], size_t *length)
   {
       OH_LOG_Print(LOG_APP, LOG_INFO, 0, "testTag", "Process the request for obtaining the text on the right of the cursor.");
   }
   
   int32_t GetTextIndexAtCursorFunc(InputMethod_TextEditorProxy *proxy)
   {
       OH_LOG_Print(LOG_APP, LOG_INFO, 0, "testTag", "Process the request for obtaining the text index of the text box where the cursor is located.");
       return 0;
   }
   int32_t ReceivePrivateCommandFunc(InputMethod_TextEditorProxy *proxy, InputMethod_PrivateCommand *privateCommand[],
       size_t size)
   {
       SetText("Process the extended edit request.");
       return 0;
   }
   
   int32_t SetPreviewTextFunc(InputMethod_TextEditorProxy *proxy, const char16_t *text, size_t length, int32_t start,
       int32_t end)
   {
       SetText("Process the request for setting the preview text.");
       return 0;
   }
   
   void FinishTextPreviewFunc(InputMethod_TextEditorProxy *proxy)
   {
       SetText("Process the request for ending the preview.");
   }
   
   void ConstructTextEditorProxy(InputMethod_TextEditorProxy *textEditorProxy)
   {
       OH_TextEditorProxy_SetGetTextConfigFunc(textEditorProxy, GetTextConfigFunc);
       OH_TextEditorProxy_SetInsertTextFunc(textEditorProxy, InsertTextFunc);
       OH_TextEditorProxy_SetDeleteForwardFunc(textEditorProxy, DeleteForwardFunc);
       OH_TextEditorProxy_SetDeleteBackwardFunc(textEditorProxy, DeleteBackwardFunc);
       OH_TextEditorProxy_SetSendKeyboardStatusFunc(textEditorProxy, SendKeyboardStatusFunc);
       OH_TextEditorProxy_SetSendEnterKeyFunc(textEditorProxy, SendEnterKeyFunc);
       OH_TextEditorProxy_SetMoveCursorFunc(textEditorProxy, MoveCursorFunc);
       OH_TextEditorProxy_SetHandleSetSelectionFunc(textEditorProxy, HandleSetSelectionFunc);
       OH_TextEditorProxy_SetHandleExtendActionFunc(textEditorProxy, HandleExtendActionFunc);
       OH_TextEditorProxy_SetGetLeftTextOfCursorFunc(textEditorProxy, GetLeftTextOfCursorFunc);
       OH_TextEditorProxy_SetGetRightTextOfCursorFunc(textEditorProxy, GetRightTextOfCursorFunc);
       OH_TextEditorProxy_SetGetTextIndexAtCursorFunc(textEditorProxy, GetTextIndexAtCursorFunc);
       OH_TextEditorProxy_SetReceivePrivateCommandFunc(textEditorProxy, ReceivePrivateCommandFunc);
       OH_TextEditorProxy_SetSetPreviewTextFunc(textEditorProxy, SetPreviewTextFunc);
       OH_TextEditorProxy_SetFinishTextPreviewFunc(textEditorProxy, FinishTextPreviewFunc);
   }
   ```

   <!-- @[input_case_input_CPreview208](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/InputMethod/KikaInputMethod/entry/src/main/cpp/napi_init.cpp) -->

   ``` C++
   void InputMethodNdkDemo()
   {
       // Create an InputMethod_TextEditorProxy instance.
       textEditorProxy = OH_TextEditorProxy_Create();
       if (textEditorProxy == nullptr) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Create TextEditorProxy failed.");
           return;
       }
   
       // Set the implemented response processing function to InputMethod_TextEditorProxy.
       ConstructTextEditorProxy(textEditorProxy);
   
       // Create an InputMethod_AttachOptions instance. The showKeyboard option specifies whether to display the keyboard after a successful attach: true to automatically display the keyboard, false to not display it.
       bool showKeyboard = true;
       attachOptions = OH_AttachOptions_Create(showKeyboard);
       if (attachOptions == nullptr) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Create AttachOptions failed.");
           OH_TextEditorProxy_Destroy(textEditorProxy);
           return;
       }
   
       // Send a binding request.
       auto ret = OH_InputMethodController_Attach(textEditorProxy, attachOptions, &inputMethodProxy);
       if (ret != IME_ERR_OK) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Attach failed, ret=%{public}d.", ret);
           OH_TextEditorProxy_Destroy(textEditorProxy);
           OH_AttachOptions_Destroy(attachOptions);
           return;
       }
   }
   
   static napi_value InputMethodDestroy(napi_env env, napi_callback_info info)
   {
      // Hide the keyboard.
       int ret = OH_InputMethodProxy_HideKeyboard(inputMethodProxy);
       if (ret != IME_ERR_OK) {
           OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "HideKeyboard failed, ret=%{public}d.", ret);
           OH_TextEditorProxy_Destroy(textEditorProxy);
           OH_AttachOptions_Destroy(attachOptions);
           return nullptr;
       }
   
       // Send an unbinding request.
       OH_InputMethodController_Detach(inputMethodProxy);
       OH_TextEditorProxy_Destroy(textEditorProxy);
       OH_AttachOptions_Destroy(attachOptions);
       OH_LOG_Print(LOG_APP, LOG_INFO, 0, "testTag", "Finished.");
       return nullptr;
   }
   
   
   static napi_value AttachInputMethod(napi_env env, napi_callback_info info)
   {
       InputMethodNdkDemo();
   
       napi_value result;
       napi_create_string_utf8(env,  g_strText.c_str(),  g_strText.length(),  &result);
       return result;
   }
   
   static napi_value GetText(napi_env env, napi_callback_info info)
   {
       napi_value result;
       napi_create_string_utf8(env, g_strTextChar, g_strTextCharLen,  &result);
       return result;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "attachInputMethod", nullptr, AttachInputMethod, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "getText", nullptr, GetText, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "inputMethodDestroy", nullptr, InputMethodDestroy, nullptr, nullptr, nullptr, napi_default, nullptr },
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   
   static napi_module demoModule = {
       .nm_version = 1,
       .nm_flags = 0,
       .nm_filename = nullptr,
       .nm_register_func = Init,
       .nm_modname = "entry",
       .nm_priv = ((void*)0),
       .reserved = { 0 },
   };
   
   extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
   {
       napi_module_register(&demoModule);
   }
   ```