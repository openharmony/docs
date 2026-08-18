# White Balance Issues

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=46a890d188d7f6818c431e97e537193ed2cefcf2 translatedAt=2026-08-10T09:16:57.675Z pushedAt=2026-08-10T12:55:54.400Z -->

## Symptom

White balance is unavailable, manually set white balance values do not take effect, or issues occur when switching between white balance mode and manually setting the color temperature value.

## Possible Causes

The issue lies in the timing of white balance-related API calls. An incorrect white balance mode causes the color temperature value setting to fail. The specific causes may include the following:

1. Timing issue between the white balance mode and the manual setting of the white balance color temperature value.

2. Failure to manually set the white balance value.

**Troubleshooting Steps**

Step 1: Both the white balance mode and the manual white balance value can be set independently. If the white balance mode is set first, you must switch the mode to [WhiteBalanceMode.MANUAL](../../reference/apis-camera-kit/arkts-apis-camera-e.md#whitebalancemode20) before manually setting the white balance value. However, if the white balance value is manually set first, you can directly set the white balance mode afterward.

Step 2: If manually setting the white balance color temperature value fails, you can check the `SetManualWhiteBalance`-related logs to diagnose the issue, including whether the session has been committed. If a white balance mode was previously set, check whether the white balance mode has been switched to [WhiteBalanceMode.MANUAL](../../reference/apis-camera-kit/arkts-apis-camera-e.md#whitebalancemode20) before setting the color temperature value.

Related log search keyword: whiteBalance

## Solution

Correct usage of `setWhiteBalance`:

1. Timing: Ensure that it is called after `commitConfig`.

2. Color temperature value range: Call the `getWhiteBalanceRange` method first to obtain the color temperature value range supported by the current device model, and then set the value based on the range. If the retrieval fails, the device model or version may not support this method.

3. If a white balance mode was set before setting the color temperature value, adjust the white balance mode to `WhiteBalanceMode.MANUAL` first, and then set the color temperature value.

For the white balance sample code, see [White Balance Settings (ArkTS)](camera-whitebalance.md).