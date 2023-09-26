# Time Subsystem Changelog

## cl.time.1 Permission Verification Adding for setTime, setDate, and setTimezone

Added permission verification for the **setTime**, **setDate**, and **setTimezone** APIs for compliance with the OpenHarmony API specifications.

Specifically:

  - To call the **setTime** API, the **ohos.permission.SET_TIME** permission is required.
  - To call the **setDate** API, the **ohos.permission.SET_TIME** permission is required.
  - To call the **setTimezone** API, the **ohos.permission.SET_TIME_ZONE** permission is required.

**Key API/Component Changes**

Involved APIs:

  - systemDateTime.setTime;
  - systemDateTime.setDate;
  - systemDateTime.setTimezone;

Before change:
  - No permission is required for calling the APIs in question.

After change:
  - The APIs can be called only after the specific permission is obtained. If the permission request is invalid or the specific permission is not obtained, **201** is returned, indicating that permission verification fails.

**Adaptation Guide**

To call the **setTime**, **setDate**, and **setTimezone** APIs, an application must apply for the corresponding permission.
