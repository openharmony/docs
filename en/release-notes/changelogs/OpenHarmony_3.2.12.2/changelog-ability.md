# Ability Framework Changelog

Compared with OpenHarmony 3.2 Release, OpenHarmony 3.2.12.2 provides more detailed error code information for the APIs of the ability framework.

## cl.ability.1 Added and Optimized API Error Code Description

The error code description and all error codes that may be returned by the APIs are commented out. This helps developers control the error process more accurately.

**Change Impact**

The external declaration of the JS APIs of API version 9 is affected, but the API functionalities are not affected. You can determine whether to adapt to the JS APIs.

**Key API/Component Changes**

The comments of the following modules are updated. For details, see the corresponding external API declaration and API development guide.

| Module                               | Description of Major Changes                                              |
| ----------------------------------- | ------------------------------------------------------------ |
| @ohos.app.ability.UIAbility         | Added the description of error codes 16200001, 16200002, 16200004, 16200005, 16000050.|
| @ohos.app.ability.abilityManager    | Added the description of error codes 201, 202, and 16000050, and adjusted the description of error code 401.|
| @ohos.app.ability.appManager        | Added the description of error codes 201, 202, and 16000050, and adjusted the description of error code 401.|
| @ohos.app.ability.dataUriUtils      | Added the description of error code 401.                                     |
| @ohos.app.ability.errorManager      | Added the description of error code 16000003.                                |
| @ohos.app.ability.missionManager    | Added the description of error codes 201, 202, 16300001, 16300002, and 16000009, and adjusted the description of error code 401.|
| @ohos.app.ability.quickFixManager   | Added the description of error codes 201, 202, 18500001, 18500002, and 18500008.  |
| @ohos.app.ability.wantAgent         | Added the description of error codes 16000007, 16000015, and 16000151.            |
| application/AbilityDelegator        | Added the description of error codes 16000001, 16000002, 16000004, 16000005, 16000006, 16000008, 16000009, 16000010, 16000011, 16000050, 16000053, 16000055, 16200001, and 16000100.|
| application/ApplicationContext      | Added the description of error codes 16000011 and 16000050.                      |
| application/Context                 | Added the description of error codes 201, 202, and 401.                           |
| application/ServiceExtensionContext | Added the description of error codes 201, 202, 16000001, 16000002, 16000004, 16000005, 16000006, 16000008, 16000009, 16000010, 16000011, 16000050, 16000053, 16000055, and 16200001.|
| application/UIAbilityContext        | Added the description of error codes 201, 16000001, 16000002, 16000004, 16000005, 16000006, 16000008, 16000009, 16000010, 16000011, 16000050, 16000053, 16000055, 16200001, and 16000100.|
| @ohos.app.form.formHost             | Added the description of error codes 201, 202, 16500050, 16500060, 16501000, 16501001, and 16501003, and adjusted the description of error code 401.|
| @ohos.app.form.formProvider         | Added the error codes 202, 16500050, 16500060, 16500100, 16501000, 16501001, 16501002, and 16501003, and adjusted the description of error code 401.|
| application/FormExtensionContext    | Added the description of error codes 202, 401, 16500050, 16500100, 16500101, and 16501000.|
