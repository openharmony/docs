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

The package manager is not working correctly.

**Solution**

None

## 12800002 Input Method Engine Error

**Error Message**

Input method engine error.

**Description**

This error code is reported when an input method API fails to be called.

**Possible Causes**

The input method process is suspended.

**Solution**

Check whether the input method process is running properly. For example, click the text input box in an application to check whether the input keyboard is displayed.

## 12800003 Input Method Client Error

**Error Message**

Input method client error.

**Description**

This error code is reported when the API for showing or hiding the keyboard fails to be called by a third-party application.

**Possible Causes**

1. The input method is disconnected from the third-party application due to a service error with the application.
2. The third-party application is not focused.

**Solution**

1. Bind the input method to the third-party application again: Close the background process of the third-party application, start the application again, and touch a text input box. If the keyboard is displayed properly, the issue is resolved.
2. Place the third-party application in the foreground and ensure that it is not covered by other applications or windows. Enable the input method by touching a text input box.

## 12800004 Not an Input Method

**Error Message**

Not an input method.

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

Run the **hdc shell param get persist.sys.default_ime** command to check the default input method parameters. If the parameters are displayed, the system parameter configuration module is working properly. In this case, restart the device and try again.

## 12800006 Input Method Controller Error

**Error Message**

Input method controller error.

**Description**

This error code is reported when the input method controller fails to be obtained.

**Possible Causes**

An error occurs during invoking of the **getCotroller** API.

**Solution**

None

## 12800007 Input Method Setter Error

**Error Message**

Input method setter error.

**Description**

This error code is reported when an **InputMethodSetting** instance fails to be obtained.

**Possible Causes**

An error occurs during invoking of the **getSetting** API.

**Solution**

None

## 12800008 Input Method Manager Service Error

**Error Message**

Input method manager service error.

**Description**

This error code is reported when an API of the [input method framework](js-apis-inputmethod.md) fails to be called.

**Possible Causes**

The input method manager service fails to be found.

**Solution**

Run the **ps -A|grep inputmethod** command to check for the process ID of the input method service. If the process ID is found, the service is working properly.

## 12800009 Input Method Client Detached

**Error Message**

Input method client detached.

**Description**

This error code is reported when the current application is not attached to an input method.

**Possible Causes**

The current application calls **showTextInput** or **hideTextInput** when not attached to an input method.

**Solution**

Call the **attach** API and then try again.

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

The intput method is basic mode.

**Description**

The input method application is in non-full access mode.

**Possible Causes**

This error is thrown if the input method is in non-full access mode after you call an API that requires the full access mode to be enabled.

**Solution**

Enable the full access mode of the input method in **Settings**.

## 12800015 Message Receiver Unable to Receive Custom Communication Data

**Error Message**

The another side does not accept the request.

**Description**

The message receiver cannot receive custom communication data.

**Possible Causes**

This error is thrown if the message receiver does not register [MessageHandler](js-apis-inputmethodengine.md#messagehandler15) to receive data when you call the API for sending custom communication data.

**Solution**

To receive custom communication data, register a **MessageHandler** for the message receiver, call [recvMessage](js-apis-inputmethodengine.md#recvmessage15) in the input method application, and call [recvMessage](js-apis-inputmethod.md#recvmessage15) for the input method client.

## 12800016 Input Method Client Not in Edit Mode

**Error Message**

The edit mode need enable.

**Description**

The input method client is not in edit mode.

**Possible Causes**

The input method client exits the edit mode after being attached. For example, [hideTextInput](js-apis-inputmethod.md#hidetextinput10) is called after the self-drawing component is attached to the input method through **Attach**.

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

Read the API usage description and call the API if you need to adjust the panel type or panel flag of the input method, and input parameters. Otherwise, do not call the API.
