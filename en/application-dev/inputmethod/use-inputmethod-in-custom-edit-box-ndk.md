# Using the Input Method in a Custom Edit Box (C/C++)


## When to Use

IME Kit allows you to use input method in the custom edit box to interact with input method applications, including displaying and hiding input methods and receiving text editing notifications from input method applications. This document describes how to use C/C++ to develop this function.

## APIs

For details about the APIs, see [InputMethod](../reference/apis-ime-kit/_input_method.md).

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

When the input box is focused, you can call the [OH_InputMethodController_Attach](../reference/apis-ime-kit/_input_method.md#oh_inputmethodcontroller_attach) API to bind the input method. After the binding is successful, you can use the input method to enter text.

1. Create an **InputMethod_TextEditorProxy** instance. The sample code is as follows:

   ```c
   // Create an InputMethod_TextEditorProxy instance.
   InputMethod_TextEditorProxy *textEditorProxy = OH_TextEditorProxy_Create();
   ```
   
3. Create an **InputMethod_AttachOptions** instance and set the options for binding the input method. The sample code is as follows:

   ```c
   // Create an InputMethod_AttachOptions instance. showKeyboard specifies whether to display the keyboard after the binding is successful. The following uses displaying the target keyboard as an example.
   bool showKeyboard = true;
   InputMethod_AttachOptions *options = OH_AttachOptions_Create(showKeyboard);
   ```

4. Call **OH_InputMethodController_Attach** to bind the input method service. After the call is successful, you can obtain **InputMethod_InputMethodProxy** used to interact with the input method. The sample code is as follows:

   ```c
   InputMethod_InputMethodProxy *inputMethodProxy = nullptr;
   // Send a binding request.
   if (OH_InputMethodController_Attach(textEditorProxy, options, &inputMethodProxy) != InputMethod_ErrorCode::IME_ERR_OK) {
       OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Attach failed!");
   }
   ```

## Displaying or Hiding the Panel

After the binding is successful, you can use the obtained [InputMethod_InputMethodProxy](../reference/apis-ime-kit/_input_method.md#inputmethod_inputmethodproxy) object to send a message to the input method. The sample code is as follows:

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
   void GetTextConfig(InputMethod_TextEditorProxy *textEditorProxy, InputMethod_TextConfig *config)
   {
       // Process the request sent by the input method for obtaining the input box configuration.
   }
   void InsertText(InputMethod_TextEditorProxy *textEditorProxy, const char16_t *text, size_t length)
   {
       // Process the text insertion request sent by the input method.
   }
   void DeleteForward(InputMethod_TextEditorProxy *textEditorProxy, int32_t length)
   {
       // Process the text deletion request sent by the input method.
   }
   // ......
   ```

2. Set the implemented response function to [InputMethod_TextEditorProxy](../reference/apis-ime-kit/_input_method.md#inputmethod_texteditorproxy), and then set the response function to the input method framework using [OH_InputMethodController_Attach](../reference/apis-ime-kit/_input_method.md#oh_inputmethodcontroller_attach) called when the input method is bound to complete listener registration. The sample code is as follows:

   ```c
   // Set the implemented response processing function to InputMethod_TextEditorProxy.
   OH_TextEditorProxy_SetGetTextConfigFunc(textEditorProxy, GetTextConfig);
   OH_TextEditorProxy_SetInsertTextFunc(textEditorProxy, InsertText);
   OH_TextEditorProxy_SetDeleteForwardFunc(textEditorProxy, DeleteForward);
   ```

## Unbinding an Input Method

When the edit box is out of focus, you need to stop using the input method and unbind the input method framework by calling [OH_InputMethodController_Detach](../reference/apis-ime-kit/_input_method.md#oh_inputmethodcontroller_detach).

```c
// Send an unbinding request.
if (OH_InputMethodController_Detach(inputMethodProxy) != InputMethod_ErrorCode::IME_ERR_OK) {
    OH_LOG_Print(LOG_APP, LOG_ERROR, 0, "testTag", "Detach failed!");
}
inputMethodProxy = nullptr;
OH_TextEditorProxy_Destroy(textEditorProxy);
textEditorProxy = nullptr;
OH_AttachOptions_Destroy(options);
options = nullptr;
```
