# Router Error Codes

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @huangxiaolinabc-->
<!--Designer: @fangzhiyuan1-->
<!--Tester: @Giacinta-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=c8d89821f92b220ca7659a1de29fb1e3b0412c5b translatedAt=2026-08-13T01:29:26.696Z pushedAt=2026-08-13T01:50:48.617Z -->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

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

**Solution**

Verify that the specified route name for redirection is correct and exists.

## 100005 Builder Function Not Registered During Navigation

**Error Message**

Builder function not registered.

**Description**

This error code is reported during navigation when the builder function for creating the **NavDestination** component is not registered.

**Possible Causes**

- The builder function for creating the **NavDestination** component is not registered during navigation.

- The target page for navigation does not contain the **Navigation** component.

- The route table is not configured.

**Solution**

Check whether **Navigation** provides the builder function for creating the **NavDestination** component. Make sure the route table is correctly configured and the target page for navigation contains the **Navigation** component.

## 100006 NavDestination Not Found

**Error Message**

NavDestination not found.

**Description**

This error code is reported when no **NavDestination** component is found for navigation.

**Possible Causes**

No **NavDestination** component is available for navigation.

**Solution**

Make sure there is a **NavDestination** component for navigation.

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

The current node may not be mounted under the page.

**Solution**

Check whether the current node is on the page.

## 106202 Buffer Size Not Sufficient to Hold the Target Data

**Error Message**

buffer size is not large enough.

**Description**

This error code is reported when the input buffer size is not large enough to hold the target data.

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

## 300001 Silent Installation of the HSP Failed Before Navigation

**Error Message**

hsp silent install fail.

**Description**

This error code is reported when the silent installation of the HSP containing the target page fails before **Navigation** performs the redirection.

**Possible Causes**

The target HSP to be downloaded does not exist.

**Solution**

Verify that the HSP for the target navigation page actually exists. Make sure the value of **moduleName** passed in is correct.