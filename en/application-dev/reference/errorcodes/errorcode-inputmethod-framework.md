# Input Method Framework Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 12800001 Package Manager Error

**Error Message**

Package manager error.

**Description**

This error code is reported when an API of the package manager, such as **getInputMethods** and **listCurrentInputMethodSubtype**, fails to be invoked to obtain information.

**Possible Causes**

The package manager is not working correctly.

**Solution**

None

## 12800002 Input Method Engine Error

**Error Message**

Input method engine error.

**Description**

This error code is reported when an input method API fails to be invoked.

**Possible Causes**

The input method process is suspended.

**Solution**

Check whether the input method process is running properly. For example, click the input text box in an application and check whether the input keyboard is displayed.

## 12800003 Input Method Client Error

**Error Message**

Input method client error.

**Description**

This error code is reported when the API for showing or hiding the keyboard fails to be invoked by a third-party application.

**Possible Causes**

The input method is disconnected from the third-party application due to a service error with the application.

**Solution**

Bind the input method to the third-party application again: Close the background process of the third-party application, start the application again, and touch an input text box. If the keyboard is displayed properly, the issue is resolved.

## 12800004 Not an Input Method.

**Error Message**

Not an input method extension.

**Description**

This error code is reported when an API exclusive to input methods is called by an application of another type.

**Possible Causes**

An API that can be called only by an input method is called by an application of another type.

**Solution**

Call the API only in an input method.

## 12800005 Configuration Persistence Error

**Error Message**

Configuration persisting error.

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

Input method settings extension error.

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

This error code is reported when an API of the [input method framework](../apis/js-apis-inputmethod.md) fails to be invoked.

**Possible Causes**

The input method manager service fails to be obtained.

**Solution**

Run the **ps -A|grep inputmethod** command to check for the process ID of the input method service. If the process ID is found, the service is working properly.

## 12800009 Input Method Client Detached

**Error Message**

Input method client is detached.

**Description**

This error code is reported when the current application is not attached to an input method.

**Possible Causes**

The current application calls **showTextInput** or **hideTextInput** when not attached to an input method.

**Solution**

Call the **attach** API and then try again.

## 12800010 Not Preconfigured Default Input Method

**Error Message**

Not default input method configured by system.

**Description**

This error code is reported when the invoking application is not the preconfigured default input method.

**Possible Causes**

The API is called by an application that is not the preconfigured default input method.

**Solution**

Make sure the application to call the API is the preconfigured default input method.
