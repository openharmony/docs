# Pasteboard Subsystem Changelog

Compared with earlier versions, OpenHarmony 5.0.0.18 has the following API changes in its pasteboard subsystem:

## cl.pasteboard.1 Change of the Permission for Accessing getData()

Added a permission required for accessing the **getData()** API.

**Access Level**

Public API

**Reason for Change**

To use a custom component to access the pasteboard in the background, the application must request ohos.permission.READ_PASTEBOARD.

**Change Impact**

The change is not compatible with earlier versions. You are advised to use new APIs.

Before change: The ohos.permission.READ_PASTEBOARD permission is not verified when services access pasteboard data.

After change: Without ohos.permission.READ_PASTEBOARD, services are intercepted when accessing pasteboard data using insecure components.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.18

**Key API/Component Changes**

SetAppShareOptions()/pasteboard_service

**Adaptation Guide**

Declare ohos.permission.READ_PASTEBOARD in **module.json5** as required. The sample code is as follows:
```ts
"requestPermissions": [
  {
    "name": "ohos.permission.READ_PASTEBOARD"
  }
]
```
