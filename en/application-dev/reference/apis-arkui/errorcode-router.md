# Router Error Codes
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @mayaolll-->
<!--Designer: @jiangdayuan-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 100001 Internal Error

**Error Message**

When used as an error code for @ohos.router: Internal error. UI execution context is not found.

When used as an error code for the **Navigation** routing framework: Internal error. Create NavDestination failed, probably caused by wrong UIContext.

**Description**

This error code is reported when an internal error that cannot be rectified by developers occurs. The internal error type is included in the error information. When used in @ohos.router, this error code is represented as a string type. When used in the **Navigation** routing framework, this error code is represented as a number type.

**Possible Causes**

The operation for obtaining the rendering engine or parsing parameters fails.

**Solution**

NA

## 100002 Incorrect URI During Page Redirection

**Error Message**

Uri error. The URI of the page to redirect is incorrect or does not exist.

**Description**

This error code is reported when the URI of the page to redirect is incorrect or does not exist. This error code is represented as a string type.

**Possible Causes**

The entered URI is incorrect or does not exist.

**Solution**

Ensure that the URI is correct.

## 100003 Too Many Pages Are Pushed into the Page Stack

**Error Message**

Page stack error. Too many pages are pushed.

**Description**

This error code is reported when more than 32 pages are pushed into the page stack. This error code is represented as a string type.

**Possible Causes**

Too many pages are pushed.

**Solution**

Delete unnecessary or invalid pages.

## 100004 Incorrect Route Name

**Error Message**

Named route error. The named route does not exist.

**Description**

This error code is reported when the specified route name for redirection is incorrect or does not exist. This error code is represented as a string type.

**Possible Causes**

The specified route name for redirection is incorrect or does not exist.

## 100005 Builder Function Not Registered

**Error Message**

Builder function not registered.

**Description**

This error code is reported when the builder function for creating the navigation destination page is not registered.

**Possible Causes**

The builder function for creating the **NavDestination** component is not registered at the time of navigation.

**Solution**

Make sure the builder function for creating the **NavDestination** component is registered.

## 100006 NavDestination Not Found

**Error Message**

NavDestination not found.

**Description**

This error code is reported when no **NavDestination** component is found for the target page of navigation.

**Possible Causes**

The **NavDestination** component is unavailable for the target page of navigation.

**Solution**

Make sure there is a **NavDestiantion** component for the target page of navigation.

## 106200 Invalid Index Value

**Error Message**

index value is invalid.

**Description**

This error code is reported when an invalid index value is provided.

**Possible Causes**

The index value is invalid.

**Solution**

Check the provided index value.

## 106201 Failed to Obtain Route Navigation Information

**Error Message**

Failed to query route navigation information.

**Description**

This error code is reported when the system fails to obtain route navigation information.

**Possible Causes**

The current node may not be within a **Navigation** component.

**Solution**

Check whether the current node is within a **Navigation** component.

## 106202 Invalid Buffer Size

**Error Message**

buffer size is not large enough.

**Description**

This error code is reported when an invalid buffer size is provided.

**Possible Causes**

The provided buffer size is smaller than the minimum required to accommodate the target data.

**Solution**

Check the provided buffer size.

## 200002 Incorrect URI During Page Replacement

**Error Message**

Uri error. The URI of the page to be used for replacement is incorrect or does not exist.

**Description**

This error code is reported when the URI of the page to be used for replacement is incorrect or does not exist. This error code is represented as a string type.

**Possible Causes**

The entered URI is incorrect or does not exist.

**Solution**

Ensure that the URI is correct.

## 300001 HSP Download Failure Before Redirection

**Error Message**

hsp silent install fail.

**Description**

This error code is reported when the download of the HSP, which contains the target navigation page, fails before the navigation can occur.

**Possible Causes**

The target HSP to be downloaded does not exist.

**Solution**

Verify that the HSP for the target navigation page actually exists. Make sure the value of **moduleName** passed in is correct.
