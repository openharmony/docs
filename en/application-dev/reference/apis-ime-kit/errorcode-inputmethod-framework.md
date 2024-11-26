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

The input method is disconnected from the third-party application due to a service error with the application.

**Solution**

Bind the input method to the third-party application again: Close the background process of the third-party application, start the application again, and touch a text input box. If the keyboard is displayed properly, the issue is resolved.

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
