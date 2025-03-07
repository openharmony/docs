# Form Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 16500001 Internal Error

**Error Message**

Internal error.

**Description**

A common kernel error, for example, a malloc failure, occurs.

**Possible Causes**

The memory is insufficient.

**Solution**

Analyze the memory usage of the entire process, and check whether memory leakage occurs.

## 16500050 IPC Failure

**Error Message**

IPC connection error.

**Description**

An error occurs when the system initiates inter-process communications (IPC) to complete the request.

**Possible Causes**

The parameter value passed in the API is too large, causing IPC data verification failure.

**Solution**

Pass appropriate parameter values.

## 16500060 Service Connection Failure

**Error Message**

Service connection error.

**Description**

An error occurs when the system attempts to connect to a service to complete the request.

**Possible Causes**

The service is busy or abnormal.

**Solution**

Try again after the service is restarted.

## 16500100 Failed to Obtain Widget Configuration Information

**Error Message**

Failed to obtain configuration information.

**Description**

An error occurs when the system attempts to obtain widget configuration information to complete the request.

**Possible Causes**

The widget configuration information field is missing or invalid.

**Solution**

Use the correct configuration information.

## 16501000 Functional Error

**Error Message**

A functional error occurred.

**Description**

An internal error occurs when the system executes the request.

## 16501001 Widget ID Not Exist

**Error Message**

The ID of the form to be operated does not exist.

**Description**

The specified widget in the request is not found.

**Possible Causes**

The widget ID passed in the API does not exist or is invalid.

**Solution**

Use a valid widget ID.

## 16501002 Too Many Widgets

**Error Message**

The number of forms exceeds the maximum allowed.

**Description**

The application attempts to add more widgets when the number of widgets has reached the upper limit.

**Possible Causes**

The number of widgets has reached the upper limit.

**Solution**

Delete unnecessary widgets and then add the required widgets.

## 16501003 Widget Not Operatable

**Error Message**

The form cannot be operated by the current application.

**Description**

The application cannot perform operations on a widget.

**Possible Causes**

The widget does not belong to the application.

**Solution**

1. Check the ownership of the widget ID.
2. Upgrade the application permission to **SystemApp**.

## 16501004 Ability Not Installed

**Error Message**

The ability is not installed.

**Description**

The specified ability is not installed.

**Possible Causes**

The specified ability is not installed.

**Solution**

Pass in valid **abilityName** and **bundleName**.

## 16501005 Failed to Connect to FormRenderService

**Error Message**

Failed to connect to FormRenderService.

**Description**

The FormRenderService fails to be connected.

**Possible Causes**

The service is busy.

**Solution**

Try again later.

## 16501008 Adding a Widget to the Home Screen Times Out

**Error Message**

Waiting for the form addition to the desktop timed out.

**Description**

A request for adding a widget to the home screen is sent, but the widget is not added within the specified duration.

**Possible Causes**

The service is busy.

**Solution**

Try again later.
