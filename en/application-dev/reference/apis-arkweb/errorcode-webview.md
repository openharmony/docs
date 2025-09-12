# Webview Error Codes
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 17100001 WebviewController Not Associated with a Web Component

**Error Message**

Init error. The WebviewController must be associated with a Web component.

**Description**

This error code is reported when the **WebviewController** object is not associated with any **Web** component.

**Solution**

Use [onControllerAttached()](./arkts-basic-components-web-events.md#oncontrollerattached10) to check whether the **WebViewController** object is attached with the **Web** component.


## 17100002 Invalid URL

**Error Message**

URL error. Possible causes: 1. No valid cookie found for the specified URL. 2. The webpage corresponding to the URL is invalid, or the URL length exceeds 2048.

**Description**

The URL is incorrect. Possible causes are as follows:

1. No valid cookie is found for the specified URL.

2. The web page corresponding to the URL is invalid, or the URL length exceeds 2048 characters.

**Solution**

Check whether the URL is correct and contains a maximum of 2048 characters.


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

The provided cookie value is invalid. It must follow the format specified in RFC 6265.

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


## 17100008 javaScriptProxy Does Not Exist

**Error Message**

Failed to delete JavaScriptProxy because it does not exist.

**Description**

This error code is reported when the **javaScriptProxy** object to delete does not exist.

**Possible Causes**

The target **javaScriptProxy** object is not yet registered.

**Solution**

Make sure the **javaScriptProxy** object is registered.


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

Invalid origin.The origin format must follow defined in RFC 6454.

**Description**

This error code is reported when the input parameter **origin** is invalid. The origin value must in the format defined in RFC 6454.

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


## 17100016 Download Task Not Paused

**Error Message**

The download task is not paused.

**Description**

This error code is reported when an attempt is made to resume a download task that is not paused.

**Possible Causes**

**WebDownloadItem.resume** is called when the download task is not paused.

**Solution**

N/A


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

## 17100023 Port Number Not Allowed

**Error Message**

The port number is not within the allowed range.

**Description**

The port number is not within the allowed range.

**Possible Causes**

Some port numbers (for example, port numbers less than 1024) are well-known or system ports. These ports can be enabled on the operating system only when the privilege is granted. Therefore, applications are not allowed to use these port numbers.

**Solution**

Check whether the port number is within the allowed range.

## 17100101 Incorrect Network Error Code

**Error Message**

The errorCode is either ARKWEB_NET_OK or outside the range of error codes in WebNetErrorList.

**Description**

The network error code is **ARKWEB_NET_OK** or out of the range in **WebNetErrorList**.

**Possible Causes**

The error code is not within the range of [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist), or **NET_OK** is used when the **didFail** API is called.

**Solution**

Check whether the error code is within the range of [WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist) or whether **NET_OK** is used when the **difFail** API is called.
