# Media Subsystem Changelog

## c1.multimedia.1 Error Code Implementation of the AudioRenderer and AudioCapturer Classes in ohos.multimedia.audio Is Corrected

**Access Level**

Public API

**Reason for Change**

The audio framework standardizes the following error codes:
6800101: The input parameter type does not match. 401: The number of input parameters does not match. 6800104: The enumerated value is not in the specified range.
In the original implementation, error code 6800104 is returned when the input parameter type does not match, and error code 6800101 is returned when the number of input parameters does not match.

**Change Impact**

This change is a non-compatible change.

If your application uses these error codes, make an adaptation accordingly.

Before change:

**audioRenderer.off**: If the number of input parameters does not match, error code 6800101 is returned. If the input parameter type does not match, error code 6800104 is returned.

After change:

**audioRenderer.off**: If the number of input parameters does not match, error code 401 is returned. If the input parameter type does not match, error code 6800101 is returned.

Before change:

**audioCapturer.off**: If the number of input parameters does not match, error code 6800101 is returned. If the input parameter type does not match, error code 6800104 is returned.

After change:

**audioCapturer.off**: If the number of input parameters does not match, error code 401 is returned. If the input parameter type does not match, error code 6800101 is returned.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.24

**Key API/Component Changes**

AudioRenderer.off

AudioCapturer.off

**Adaptation Guide**

Change the error code from 6800104 to 6800101 in the code for the scenario where the input parameter type does not match; change the error code from 6800101 to 401 in the code for the scenario where the number of input parameters does not match.
