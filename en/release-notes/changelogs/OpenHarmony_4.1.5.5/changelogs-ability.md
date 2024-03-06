# Ability Subsystem Changelog

## cl.ability.1 Permission Changed for Calling autoStartupManager APIs
**Access Level**

System APIs

**Reason for the Change**

Permission verification is not performed when any of the following APIs is called: **on**, **off**, **setApplicationAutoStartup**, **cancelApplicationAutoStartup**, and **queryAllAutoStartupApplications**. Only system application verification is performed. This poses security risks.

**Change Impact**

The API calling permission is changed.

The APIs can be used only after the corresponding permission is configured.

**API Level**

11

**Change Since**

Openharmony SDK OpenHarmony_4.1.5.5

**Key API/Component Changes**
| API| Before Change| After Change|
| ------- | ----- | ------ |
| on(type: 'systemAutoStartup', callback: AutoStartupCallback)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| off(type: 'systemAutoStartup', callback: AutoStartupCallback)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| setApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| setApplicationAutoStartup(info: AutoStartupInfo)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| cancelApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| cancelApplicationAutoStartup(info: AutoStartupInfo)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| queryAllAutoStartupApplications(info: AutoStartupInfo, callback: AsyncCallback<void>)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| queryAllAutoStartupApplications(info: AutoStartupInfo)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|

**Adaptation Guide**

Declare the corresponding permission before calling any of the following APIs: **on**, **off**, **setApplicationAutoStartup** (in both callback and promise modes), **cancelApplicationAutoStartup** (in both callback and promise modes), and **queryAllAutoStartupApplications** (in both callback and promise modes).
