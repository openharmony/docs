# Widget Management Subsystem Changelog

## cl.form.1 Deleted Error Codes That Are No Longer Used

**Access Level**

System API

**Change Reason**

For **FormExtensionContext.startAbility**, error code 16500101 is no longer used. When a non-system application uses a system API, error code 202 is reported.

**Change Impact**

The external declaration of the APIs of API version 12 is affected, but the API functionalities are not affected. You can determine whether to adapt to the APIs.

**API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.17

**Key API/Component Changes**

The comments of the following modules are updated. For details, see the corresponding external API declaration and API development guide.

| Module                               | Description of Major Changes                                              |
| ----------------------------------- | ------------------------------------------------------------ |
| application/FormExtensionContext    | Deleted error code 16500101 and its return description.|

**Adaptation Guide**

When a non-system application uses a system API, error code 202 is reported. Error code 16500101 is no longer used.
