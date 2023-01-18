# Webview Error Codes


## 17100001 WebviewController Not Associated with a Web Component

**Error Message**

Init error. The WebviewController must be associated with a Web compoent.

**Description**

This error code is reported when the **WebviewController** object is not associated with any **\<Web>** component.

**Solution**

Bind the **WebviewController** object to a **\<Web>** component.


## 17100002 Invalid URL

**Error Message**

Invalid url.

**Description**

This error code is reported when the URL format is incorrect.

**Solution**

Verify the URL format.


## 17100003 Incorrect Resource Path

**Error Message**

Invalid resource path or file type.

**Description**

This error code is reported when the path to the resource file is incorrect.

**Possible Causes**

The resource file does not exist or cannot be accessed.

**Solution**

Make sure the path to the resource file is correct.


## 17100004 Function Not Enabled

**Error Message**

Function not enable.

**Description**

This error code is reported when the related function is not enabled.

**Solution**

Make sure the related function is enabled.


## 17100005 Invalid Cookie Value

**Error Message**

Invalid cookie value.

**Description**

This error code is reported when the cookie value type is invalid.

**Possible Causes**

The cookie value type is not supported.

**Solution**

Verify the cookie value type.


## 17100006 Message Port Callback Cannot Be Registered

**Error Message**

Can not register message event using this port.

**Description**

This error code is reported when a callback fails to be registered for the message port.

**Possible Causes**

The port is closed.

**Solution**

Make sure the port is open.


## 17100007 Invalid Forward or Backward Operation

**Error Message**

Invalid back or forward operation.

**Description**

This error code is reported when the specified forward or backward cannot be performed.

**Possible Causes**

1. The browsing history is cleared.

2. There is no browsing operation corresponding to the forward or backward operation.

**Solution**

1. Check whether **clearHistory** has been performed.

2. Check whether the number of pages specified by the forward or backward operation is available.


## 17100008 javaScriptProxy Does Not Exist

**Error Message**

Cannot delete JavaScriptProxy.

**Description**

This error code is reported when the **javaScriptProxy** object to delete does not exist.

**Possible Causes**

The target **javaScriptProxy** object is not yet registered.

**Solution**

Make sure the **javaScriptProxy** object is registered.


## 17100009 Zoom Operation Failure

**Error Message**

Cannot zoom in or zoom out.

**Description**

This error code is reported when the page cannot be zoomed in or out.

**Possible Causes**

The zoom ratio has reached its maximum or minimum.

**Solution**

Check whether the zoom ratio has reached its maximum or minimum.


## 17100010 Failure to Send Messages Through a Port

**Error Message**

Cannot post message using this port.

**Description**

This error code is reported when the current port cannot be used to send messages.

**Possible Causes**

The local or remote port is closed.

**Solution**

1. Make sure the local port is open.

2. Make sure an **onMessageEvent** callback is registered for the remote port.


## 17100011 Invalid Origin

**Error Message**

Invalid origin.

**Description**

This error code is reported when the input parameter **origin** is invalid.

**Possible Causes**

1. The **origin** parameter is empty.

2. The **origin** value is invalid.

**Solution**

Make sure the **origin** value is valid.


## 17100012 No Web Storage Origin

**Error Message**

Invalid web storage origin.

**Description**

This error code is reported when no web storage origin is available.

**Possible Causes**

The related JS database API is not used.

**Solution**

1. Check whether the JS database API is used.

2. If the JS database API is used, find out the failure cause, for example, check whether **databaseAccess** is enabled.
