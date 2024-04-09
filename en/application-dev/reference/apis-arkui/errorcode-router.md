# Router Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 100001 Internal Error

**Error Message**

Internal error.

**Description**

This error code is reported when an internal error that cannot be rectified by developers occurs. The internal error type is included in the error information.

**Possible Causes**

The operation for obtaining the rendering engine or parsing parameters fails.

**Solution**

NA

## 100002 Incorrect URI During Page Redirection

**Error Message**

Uri error. The uri of router is not exist.

**Description**

This error code is reported when the URI of the page to redirect is incorrect or does not exist.

**Possible Causes**

The entered URI is incorrect or does not exist.

**Solution**

Ensure that the URI is correct.

## 100003 Too Many Pages Are Pushed into the Page Stack

**Error Message**

Page stack error. The pages are pushed too much.

**Description**

This error code is reported when more than 32 pages are pushed into the page stack.

**Possible Causes**

Too many pages are pushed.

**Solution**

Delete unnecessary or invalid pages.

## 100004 Incorrect Route Name

**Error Message**

Named route error. The named route is not exist.

**Description**

This error code is reported when the specified route name for redirection is incorrect or does not exist.

**Possible Causes**

The specified route name for redirection is incorrect or does not exist.

## 100005 Builder Function Not Registered

**Error Message**

Builder function not registered.

**Description**

This error code is reported when the builder function for creating the navigation destination page is not registered.

**Possible Causes**

The builder function for creating the **\<NavDestiantion>** component is not registered at the time of navigation.

**Solution**

Make sure the builder function for creating the **\<NavDestiantion>** component is registered.

## 100006 NavDestination Not Found

**Error Message**

NavDestination not found.

**Description**

This error code is reported when no **\<NavDestiantion>** component is found for the target page of navigation.

**Possible Causes**

The **\<NavDestiantion>** component is unavailable for the target page of navigation.

**Solution**

Make sure there is a **\<NavDestiantion>** component for the target page of navigation.

## 200002 Incorrect URI During Page Replacement

**Error Message**

Uri error. The uri of router is not exist.

**Description**

This error code is reported when the URI of the page to be used for replacement is incorrect or does not exist.

**Possible Causes**

The entered URI is incorrect or does not exist.

**Solution**

Ensure that the URI is correct.
