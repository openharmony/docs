# Form Error Codes

## 16500001 Internal Error

**Error Message**

Internal Error.

**Description**

A common kernel error, for example, a malloc failure, occurs.

**Possible Causes**

The memory is insufficient.

**Solution**

Analyze the memory usage of the entire process, and check whether memory leakage occurs.

## 16500050 IPC Failure

**Error Message**

An IPC connection error happened.

**Description**

An error occurs when the system initiates inter-process communications (IPC) to complete the request.

**Possible Causes**

The parameter value passed in the API is too large, causing IPC data verification failure.

**Solution**

Pass appropriate parameter values.

## 16500060 Service Connection Failure

**Error Message**

A service connection error happened, please try again later.

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

The number of forms exceeds the upper bound.

**Description**

The application attempts to add more widgets when the number of widgets has reached the upper limit.

**Possible Causes**

The number of widgets has reached the upper limit.

**Solution**

Delete unnecessary widgets and then add the required widgets.

## 16501003 Widget Not Operatable

**Error Message**

The form can not be operated by the current application.

**Description**

The application cannot perform operations on a widget.

**Possible Causes**

The widget does not belong to the application.

**Solution**

1. Check the ownership of the widget ID.
2. Upgrade the application permission to **SystemApp**.
