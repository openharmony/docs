# Input Method Framework Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 12800001 Package Manager Error

**Error Message**

Bundle manager error.

**Description**

This error code is reported when an API of the package manager, such as **getInputMethods** and **listCurrentInputMethodSubtype**, fails to be called to obtain information.

**Possible Causes**

The package manager is not working correctly when APIs such as **getInputMethods** and **listCurrentInputMethodSubtype** are called to obtain the input method subtype.

**Solution**

None

## 12800002 Input Method Engine Error

**Error Message**

Input method engine error. Possible causes:
1. input method panel not created.
2. the input method application does not subscribe to related events.

**Description**

The input method process is suspended in operations such as displaying and hiding the keyboard.

**Possible Causes**

1. The input method panel is not created.
2. The input method application does not subscribe to related events.

**Solution**

Check whether the input method process is running properly. For example, click the text input box in an application to check whether the input keyboard is displayed.

## 12800003 Input Method Client Error

**Error Message**

Input method client error. Possible causes: 
1. the edit box is not focused.
2. no edit box is bound to current input method application.

**Description**

This error code is reported when the API for showing or hiding the keyboard fails to be called by an application.

**Possible Causes**

1. The application is not focused.
2. The input method is disconnected from the application due to a service error with the application.

**Solution**

1. Bind the input method to the application again: Close the background process of the application, start the application again, and touch a text input box. If the keyboard is displayed properly, the issue is resolved.
2. Place the application in the foreground and ensure that it is not covered by other applications or windows. Then touch the text input box to display the input method.

## 12800004 Not an Input Method

**Error Message**

Not an input method application.

**Description**

This error code is reported when an API exclusive to input methods is called by an application of another type.

**Possible Causes**

An API that can be called only by an input method is called by an application of another type.

**Solution**

Call the API only in an input method.

## 12800005 Configuration Persistence Error

**Error Message**

Configuration persistence error.

**Description**

This error code is reported when the configuration fails to be saved during input method switching.

**Possible Causes**

An exception occurs with the system parameter configuration module.

**Solution**

Run `hdc shell param get persist.sys.default_ime` to view the default input method parameters. If the parameters are displayed, the system parameter configuration module is working properly. In this case, restart the device and try again.

## 12800006 Input Method Controller Error

**Error Message**

Input method controller error. Possible cause: create InputmethodController object failed.

**Description**

This error code is reported when the input method controller fails to be obtained.

**Possible Causes**

An error occurs during invoking of the **getCotroller** API.

**Solution**

None

## 12800007 Input Method Setter Error

**Error Message**

Input method setter error. Possible cause: create InputmethodSetting object failed.

**Description**

This error code is reported when an **InputMethodSetting** instance fails to be obtained.

**Possible Causes**

An error occurs during invoking of the **getSetting** API.

**Solution**

None

## 12800008 Input Method Manager Service Error

**Error Message**

Input method manager service error. Possible cause: a system error, such as null pointer, IPC exception.

**Description**

This error code is reported when an API of the [input method framework](js-apis-inputmethod.md) fails to be called.

**Possible Causes**

The input method manager service fails to be found.

**Solution**

Run `ps -A | grep inputmethod` to check the process ID of the input method service. If the process ID is found, the service is working properly.

## 12800009 Input Method Client Detached

**Error Message**

Input method client detached.

**Description**

This error code is reported when the current application is not attached to an input method.

**Possible Causes**

The current application calls **showTextInput** or **hideTextInput** when not attached to an input method.

**Solution**

Call the `attach` API and then try again.

## 12800010 Not Preconfigured Default Input Method

**Error Message**

Not the preconfigured default input method.

**Description**

This error code is reported when the invoking application is not the preconfigured default input method.

**Possible Causes**

The API is called by an application other than the preconfigured default input method.

**Solution**

Use [getDefaultInputMethod](js-apis-inputmethod.md#inputmethodgetdefaultinputmethod11) to query the default input method of the system and determine whether the application uses the default input method. If the application does not use the default input method, this API cannot be called.

## 12800011 Text Preview Not Supported

**Error Message**

Text preview not supported.

**Description**

Preview of the text input box is not supported.

**Possible Causes**

Preview of the text input box is not supported.

**Solution**

Use [getEditorAttributeSync](js-apis-inputmethodengine.md#geteditorattributesync10) to obtain the value of **isTextPreviewSupported** of [EditorAttribute](js-apis-inputmethodengine.md#editorattribute). If **isTextPreviewSupported** is **false**, this API cannot be called.

## 12800012 Soft Keyboard Panel Not Created

**Error Message**

The input method panel does not exist.

**Description**

The input method panel of the soft keyboard type is not created.

**Possible Causes**

The input method panel of the soft keyboard type is not created.

**Solution**

Use [createPanel](js-apis-inputmethodengine.md#createpanel10) to create a [panel](js-apis-inputmethodengine.md#panel10) of the [soft keyboard type](js-apis-inputmethodengine.md#paneltype10).

## 12800013 Window Manager Service Error

**Error Message**

Window manager service error.

**Description**

The window manager service is not running properly.

**Possible Causes**

After the API is called, the system uses the capabilities of the window manager module. This error is thrown due to an error of the window manager service.

**Solution**

Restart the device and try again.

## 12800014 Non-Full Access Mode of the Input Method Application

**Error Message**

The input method is in basic mode.

**Description**

The input method application is in non-full access mode.

**Possible Causes**

This error is thrown if the input method is in non-full access mode after you call an API that requires the full access mode to be enabled.

**Solution**

Enable the full access mode of the input method in **Settings**.

## 12800015 Message Receiver Unable to Receive Custom Communication Data

**Error Message**

The other side does not accept the request.

**Description**

The message receiver cannot receive custom communication data.

**Possible Causes**

This error is thrown if the message receiver does not register [MessageHandler](js-apis-inputmethodengine.md#messagehandler15) to receive data when you call the API for sending custom communication data.

**Solution**

To receive custom communication data, register a **MessageHandler** for the message receiver, call [recvMessage](js-apis-inputmethodengine.md#recvmessage15) in the input method application, and call [recvMessage](js-apis-inputmethod.md#recvmessage15) for the input method client.

## 12800016 Input Method Client Not in Edit Mode

**Error Message**

Input method client is not editable.

**Description**

The input method client is not in edit mode.

**Possible Causes**

The input method client exits the edit mode after being attached. For example, [hideTextInput](js-apis-inputmethod.md#hidetextinput10) is called after the self-drawing component is attached to the input method through `Attach`.

**Solution**

Enter the edit mode again after the input method client is attached and exits the edit mode. For example, the self-drawing component should enter the edit mode again by calling [showTextInput](js-apis-inputmethod.md#showtextinput10).

## 12800017 Invalid Panel Type or Panel Flag

**Error Message**

Invalid panel type or panel flag.

**Description**

Invalid panel type or panel flag.

**Possible Causes**

This error is thrown if the [panel type](js-apis-inputmethodengine.md#paneltype10) or [panel flag](js-apis-inputmethodengine.md#panelflag10) of the input method does not support API call, or you cannot pass the type or flag to the API.

**Solution**

Read the API usage description and adjust the input method panel type or panel status as required.

## 12800018 Input Method Not Found

**Error Message**

The input method is not found.

**Description**

The input method is not found.

**Possible Causes**

The input method is not installed.

**Solution**

Call the [getAllInputMethods](js-apis-inputmethod.md#getallinputmethods11) to query all installed input methods.

<!--Del-->
## 12800019 Unsupported Operation by Default Input Method

**Error Message**

Current operation cannot be applied to the preconfigured default input method.

**Description**

The default input method configured in the system does not support this operation.

**Possible Causes**

[enableInputMethod](js-apis-inputmethod-sys.md#enableinputmethod20) or [EnabledState](js-apis-inputmethod.md#enabledstate15) is called to enable or disable the default input method.

**Solution**

Call the [getDefaultInputMethod](js-apis-inputmethod.md#inputmethodgetdefaultinputmethod11) API to query the default input method configured in the system, and check whether the input method in use is the default input method. If yes, no processing is performed.

<!--DelEnd-->

## 12800020 Invalid Immersive Effect

**Error Message**

invalid immersive effect.
1. The gradient mode and the fluid light mode can only be used when the immersive mode is enabled.
2. The fluid light mode can only be used when the gradient mode is enabled.
3. When the gradient mode is not enabled, the gradient height can only be 0.

**Description**

1. Gradient mode and fluid light mode can be used only when the immersive mode is enabled.
2. The fluid light mode can be used only when the gradient mode is enabled.
3. If the gradient mode is disabled, the gradient height can only be 0 px.

**Possible Causes**

The input parameters do not meet the preceding requirements when the [setImmersiveEffect](js-apis-inputmethodengine.md#setimmersiveeffect20) API is called to set the [ImmersiveEffect](js-apis-inputmethodengine.md#immersiveeffect20).

**Solution**
1. Enable the immersive mode, and then set the gradient mode and fluid light mode.
2. Enable the gradient mode and then set the fluid light mode.
3. If the gradient mode is disabled, set the gradient height to 0 px.


## 12800021 Unsupported Operation by Default Input Method

**Error Message**

this operation is allowed only after adjustPanelRect or resize is called.

**Description**

The current API can be called only after any of the following APIs is called:
  - [adjustPanelRect](js-apis-inputmethodengine.md#adjustpanelrect12) (available since API version 12)
  - [adjustPanelRect](js-apis-inputmethodengine.md#adjustpanelrect15) (available since API version 15)
  - [resize](js-apis-inputmethodengine.md#resize10) (available since API version 10)

**Possible Causes**

The [setImmersiveEffect](js-apis-inputmethodengine.md#setimmersiveeffect20) API can be called only after any of the following APIs is called:
  - [adjustPanelRect](js-apis-inputmethodengine.md#adjustpanelrect12) (available since API version 12)
  - [adjustPanelRect](js-apis-inputmethodengine.md#adjustpanelrect15) (available since API version 15)
  - [resize](js-apis-inputmethodengine.md#resize10) (available since API version 10)

**Solution**

The **setImmersiveEffect** API can be called only after any of the following APIs is called:
  - [adjustPanelRect](js-apis-inputmethodengine.md#adjustpanelrect12) (available since API version 12)
  - [adjustPanelRect](js-apis-inputmethodengine.md#adjustpanelrect15) (available since API version 15)
  - [resize](js-apis-inputmethodengine.md#resize10) (available since API version 10)
