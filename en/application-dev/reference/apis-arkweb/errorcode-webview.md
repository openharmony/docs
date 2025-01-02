# Webview Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 17100001 WebviewController Not Associated with a Web Component

**Error Message**

Init error. The WebviewController must be associated with a Web component.

**Description**

This error code is reported when the **WebviewController** object is not associated with any **Web** component.

**Solution**

Use [onControllerAttached()](ts-basic-components-web.md#oncontrollerattached10) to check whether the **WebViewController** object is associated with the **Web** component.


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

Function not enabled.

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

Failed to register a message event for the port.

**Description**

This error code is reported when a callback fails to be registered for the message port.

**Possible Causes**

The port is closed.

**Solution**

Make sure the port is open.


## 17100007 Invalid Forward or Backward Operation

**Error Message**

Invalid backward or forward operation.

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

Failed to delete JavaScriptProxy because it does not exist.

**Description**

This error code is reported when the **javaScriptProxy** object to delete does not exist.

**Possible Causes**

The target **javaScriptProxy** object is not yet registered.

**Solution**

Make sure the **javaScriptProxy** object is registered.


## 17100009 Zoom Operation Failure

**Error Message**

The zoom operation failed.

**Description**

This error code is reported when the page cannot be zoomed in or out.

**Possible Causes**

The zoom ratio has reached its maximum or minimum.

**Solution**

Check whether the zoom ratio has reached its maximum or minimum.


## 17100010 Failure to Send Messages Through a Port

**Error Message**

Failed to post messages through the port.

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


## 17100013 Invalid Number of Sockets During Preconnection

**Error Message**

The number of sockets to be preconnected is invalid.

**Description**

This error code is reported when the number of sockets to be preconnected is invalid.

**Possible Causes**

The number of sockets is less than or equal to 0 or greater than 6.

**Solution**

Make sure the specified number of sockets is greater than 0 and less than or equal to 6.


## 17100014 Type and Value Mismatch

**Error Message**

The type and value of the message do not match.

**Description**

This error code is reported when the type and value of the message do not match.

**Possible Causes**

The value of the obtained message does not match the type of the message.

**Solution**

Call the API based on the message type to obtain the message value. For example, if the type is **BOOLEAN**, call the **GetBoolean** API to obtain the Boolean value.


## 17100015 Memory Allocation Failure

**Error Message**

Memory allocation failed.

**Description**

This error code is reported when memory allocation failed due to insufficient memory.

**Possible Causes**

The data to send is too large.

**Solution**

Check the length of the data to be sent.

## 17100016 Download Task Not Paused

**Error Message**

The download task is not paused.

**Description**

This error code is reported when an attempt is made to resume a download task that is not paused.

**Possible Causes**

**WebDownloadItem.resume** is called when the download task is not paused.

**Solution**

N/A

## 17100017 Invalid WebviewController

**Error Message**

No valid WebviewController is associated.

**Description**

This error code is reported when the current **WebviewController** object is invalid.

**Possible Causes**

The **WebviewController** object is not associated with a valid **Web** component.

**Solution**

Use a **WebviewController** object that is associated with a valid **Web** component.

## 17100018 No WebDownloadDelegate Available

**Error Message**

No WebDownloadDelegate has been set yet.

**Description**

This error code is reported when no **WebDownloadDelegate** is available to receive the download state.

**Possible Causes**

**WebDownloadManager.resumeDownload** is called when **WebDownloadDelegate** has not been set.

**Solution**

Use **WebDownloadManager.setDownloadDelegate** to set a **WebDownloadDelegate** class.

## 17100019 Download Not Started Yet

**Error Message**

The download task is not started yet.

**Description**

This error code is reported when an attempt is made to pause or resume a download task that has not been started.

**Possible Causes**

**pause** or **resume** is called when the download task that has not been started.

**Solution**

Call **start('xxx')** in **WebDownloadDelegate.onBeforeDownload** and specify the download path.

## 17100020 Failed to Register Custom Schemes

**Error Message**

Failed to register custom schemes.

**Description**

This error code is reported when a custom scheme failed to be registered.

**Possible Causes**

The custom scheme is set after the ArkWeb engine is initialized.

**Solution**

Register the custom scheme before initializing the ArkWeb engine.

## 17100021 WebResourceHandler Is Invalid

**Error Message**

The resource handler is invalid.

**Description**

This error code is reported when the **WebResourceHandler** object is invalid.

**Possible Causes**

1. The corresponding request is not intercepted in **WebSchemeHandler**.

2. The request is intercepted before the response body is constructed, and the request is ended due to some reasons.

3. The **WebResourceHandler** object has called **didFinish** and **didFail**.


**Solution**

Do not call the **WebResourceHandler** API in the preceding situations.

## 17100022 Failed to Initialize WebHttpBodyStream

**Error Message**

Failed to initialize the HTTP body stream.

**Description**

This error code is reported when data initialization of **WebHttpBodyStream** fails.

**Possible Causes**

The data carried in the POST request is invalid, for example, the data flow contains data in a file but the specified file path does not exist.

**Solution**

Verify that the data carried in the POST request is valid.
