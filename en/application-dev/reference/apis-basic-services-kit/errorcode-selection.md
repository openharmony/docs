# Word Selection Error Codes

<!--Kit: Basic Services Kit-->
<!--Subsystem: SelectionInput-->
<!--Owner: @no86-->
<!--Designer: @no86-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=7bd9d64d06b09f010cde4ca5a86285027d09b51a translatedAt=2026-08-04T10:28:47.232Z pushedAt=2026-08-06T03:23:06.329Z -->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 33600001 Word Selection Service Invocation Error

**Error Message**

Selection service invocation exception.

**Description**

When a word selection app calls the word selection service API, this error code is reported if the word selection service or its dependent service is abnormal, or if the **createPanel** API is called to repeatedly create a panel of the same type.

**Possible Causes**

1. The word selection service is abnormal.

2. Other system services that the word selection service depends on are abnormal.

3. A panel of the same type is created repeatedly. One word selection app is allowed to create **MENU_PANEL** and **MAIN_PANEL** only once.

**Solution**

1. Check whether the word selection service is running properly.

2. If the service is abnormal, restart the device and call the API again.

3. If the issue persists after restart, contact technical personnel for support.

4. Avoid creating panels of the same type repeatedly. One word selection app is allowed to create **MENU_PANEL** and **MAIN_PANEL** only once.

## 33600002 Word Selection Panel Has Been Destroyed

**Error Message**

This selection panel has been destroyed.

**Description**

This error code is reported when the word selection panel has been destroyed during operation on the panel.

**Possible Causes**

The word selection panel has been destroyed, and operations continue to be performed on the destroyed panel object.

**Solution**

1. Before operating on the word selection panel, determine whether the panel object is valid.

2. If the panel has been destroyed, recreate the panel before performing any operation.

3. Do not continue to hold and operate on the panel object after it has been destroyed.

## 33600003 API Caller and Word Selection Application Mismatched

**Error Message**

The application calling the API does not match the application selected in the system settings.

**Description**

This error code is reported when a user calls the word selection service API using a word selection app not selected in system settings.

**Possible Causes**

The app calling the word selection service API is not the one selected by the user in system settings.

**Solution**

1. In system settings, check whether the currently selected word selection app is this app.

2. If not, switch the word selection app to this app before calling the API.

## 33600004 The API Is Called Too Frequently

**Error Message**

The interface is called too frequently.

**Description**

This error code is reported when the API is called too frequently.

**Possible Causes**

The API is called more than 50 times within 500 ms.

**Solution**

Ensure that the **getSelectionContent** API is called only after the **selectionCompleted** event is detected. Do not call it frequently.

## 33600005 Incorrect API Call Timing

**Error Message**

The interface is called at the wrong time.

**Description**

This error code is reported when the **getSelectionContent** API is called without the **selectionCompleted** event being detected.

**Possible Causes**

The API is called at an incorrect time when the user is not performing any word selection operation and the word selection process is not triggered. The correct call sequence is as follows: call the **getSelectionContent** API only after the **selectionCompleted** event is detected.

**Solution**

Trigger word selection again, and call the **getSelectionContent** API after the **selectionCompleted** event is detected.

## 33600006 Word Selection Prohibited in the Current Application

**Error Message**

The current application is prohibited from accessing content.

**Description**

When the word selection service attempts to obtain the text content of the current app, this error code is reported if the current app prohibits this operation.

**Possible Causes**

The text content of the app cannot be accessed by other apps through settings such as **CopyOptions.InApp**.

**Solution**

1. Switch to an app that allows word selection, and call the **getSelectionContent** API after the **selectionCompleted** event is detected.

2. If you need to use the word selection feature in the current app, contact the app developer to confirm whether the app text content can be obtained.

## 33600007 Selected Text Is Out of Range

**Error Message**

The length of selected content is out of range.

**Description**

This error code is reported when the length of the text content selected by word selection exceeds the allowed range (6000 bytes).

**Possible Causes**

The selected text content exceeds the length limit of 6000 bytes.

**Solution**

Select text within the range of 1 to 6000 bytes (inclusive), and call the **getSelectionContent** API after the **selectionCompleted** event is detected.

## 33600008 Content Acquisition Timed Out

**Error Message**

Getting the selected content times out.

**Description**

When the word selection service attempts to obtain the selected text content from the target app, this error code is reported if the target app does not return the content within the specified time (100 ms).

**Possible Causes**

1. The system load is high.

2. The target app is abnormal.

3. The copy logic of the target app is complex.

**Solution**

1. Call the **getSelectionContent** API again after the **selectionCompleted** event is detected to check whether the timeout is occasional.

2. If the timeout persists, check the response status of the target app and the system resource usage.

3. If the issue persists, contact technical personnel for support.