# Ability Error Codes

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @duan-sizhao; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 16000001 Ability Name Does Not Exist

**Error Message**

The specified ability does not exist.

**Description**

This error code is reported when the specified ability name does not exist.

**Possible Causes**

The ability to query does not exist.

**Solution**

1. Pass in correct values of **bundleName**, **moduleName**, and **abilityName** in **want**.
2. Check whether the application corresponding to **bundleName** in **want** is installed. You can run the following command to query the list of installed applications. If **bundleName** is not in the query result, the application is not installed.
    ```
    hdc shell bm dump -a
    ```
3. For a multi-HAP application, check whether the HAP to which the ability belongs is installed. You can run the following command to query the bundle information. If the installed application does not contain the corresponding HAP and ability, the HAP to which the ability belongs is not installed.
    ```
    hdc shell bm dump -n bundleName
    ```

## 16000002 Incorrect Ability Type

**Error Message**

Incorrect ability type.

**Description**

This error code is reported when the ability type invoked by the API is incorrect.

**Possible Causes**

The ability with the specified type does not support the API call.

**Solution**

1. Pass in correct values of **bundleName**, **moduleName**, and **abilityName** in **want**.
2. Call APIs based on the ability type. For example, call <!--Del-->[startServiceExtensionAbility](js-apis-inner-application-uiAbilityContext-sys.md#startserviceextensionability) to start the ServiceExtensionAbility, or call <!--DelEnd-->[connectServiceExtensionAbility()](js-apis-inner-application-uiAbilityContext.md#connectserviceextensionability) to connect to the ServiceExtensionAbility. Additionally, ensure that the value of **type** under **extensionAbilities** in the [module.json5](../../quick-start/module-configuration-file.md) file matches the service you are using.

## 16000003 ID Not Exist

**Error Message**

The specified ID does not exist.

**Description**

This error code is reported when the specified ID does not exist.

**Possible Causes**

The target with the specified ID does not exist.

**Solution**

Use the correct ID.

## 16000004 Visibility Verification Failure

**Error Message**

Cannot start an invisible component.

**Description**

This error code is reported when the application fails visibility verification.

**Possible Causes**

Visibility verification fails.

**Solution**

1. Check whether [exported](../../quick-start/module-configuration-file.md#abilities) under the **Ability** field in the **module.json5** file of the ability is set to **true**. If this parameter is set to **true**, the ability can be started by other applications. If this parameter is set to **false**, the ability cannot be started by other applications.
2. To start the ability for which **exported** is set to **false**, the caller must request the ohos.permission.START_INVISIBLE_ABILITY permission, which is available only for system applications.

## 16000005 Process Permission Verification Failure

**Error Message**

The specified process does not have the permission.

**Description**

This error code is reported when the specified process fails permission verification.

**Possible Causes**

Permission verification for the specified process fails.

**Solution**

Check whether the permission of the specified process is correct.

## 16000006 Cross-User Operation Is Not Allowed

**Error Message**

Cross-user operations are not allowed.

**Description**

This error code is reported when an application tries to perform a cross-user operation.

**Possible Causes**

The application initiates a cross-user operation.

**Solution**

Do not perform a cross-user operation.

## 16000007 Service Busy

**Error Message**

Service busy. There are concurrent tasks. Try again later.

**Description**

This error code is reported when the service requested is busy.

**Possible Causes**

The service is busy.

**Solution**

Try again later.

## 16000008 Crowdtesting Application Expires

**Error Message**

The crowdtesting application expires.

**Description**

This error code is reported when users try to open a crowdtesting application that has expired.

**Possible Causes**

The crowdtesting application has expired.

**Solution**

Expired crowdtesting applications cannot be started.

## 16000009 Ability Start or Stop Failure in Wukong Mode

**Error Message**

An ability cannot be started or stopped in Wukong mode.

**Description**

This error code is returned when the application tries to start or stop an ability in Wukong mode.

**Possible Causes**

An ability cannot be started or stopped in Wukong mode.

**Solution**

Exit Wukong mode, and then start or stop the ability.  

## 16000010 Continuation Flag Forbidden

**Error Message**

The call with the continuation and prepare continuation flag is forbidden.

**Description**

This error code is reported when the API call carries the continuation flag.

**Possible Causes**

The continuation flag is not allowed for the API call.

**Solution**

Remove the continuation flag.

## 16000011 Context Does Not Exist

**Error Message**

The context does not exist.

**Description**

This error code is reported when the specified context does not exist.

**Possible Causes**

The context passed in the API does not exist.

**Solution**

Use the correct context.

## 16000012 Application Under Control

**Error Message**

The application is controlled.

**Description**

This error code is reported when the application is under control.

**Possible Causes**

The application is controlled by the system control module and is not allowed to start.

**Solution**

It is recommended that end users uninstall the application.

## 16000013 Application Controlled by EDM

**Error Message**

The application is controlled by EDM.

**Description**

This error code is reported when an application is controlled by [Enterprise Device Manager (EDM)](../../mdm/mdm-kit-admin.md).

**Possible Causes**

The application is controlled by EDM.

**Solution**

Contact the enterprise device management personnel.

## 16000015 Service Timeout

**Error Message**

Service timeout.

**Description**

This error code is reported when the service requested times out.

**Possible Causes**

The service times out.

**Solution**

Try again later.

## 16000018 Restricting Redirection to Third-Party Applications of API Version 11 or Later

**Error Message**

Redirection to a third-party application is not allowed in API version greater than 11.

**Description**

When the API version of an application is later than 11, the application cannot be explicitly redirected to a third-party application.

**Possible Causes**

The application is using an API version later than 11 and is trying to explicitly redirect to a third-party application.

**Solution**

Use implicit startup or [openLink](js-apis-inner-application-uiAbilityContext.md#openlink12) for redirection.

## 16000019 No Matching Application Is Found During Implicit Startup

**Error Message**

No matching ability is found.

**Description**

A matching ability is not found during implicit startup.

**Possible Causes**

1. The parameter settings for implicit startup are incorrect.
2. The specified HAP is not installed.

**Solution**

1. Correct the parameter settings for implicit startup.
2. Install the specified HAP.

<!--Del-->
## 16000020 Context Is Not an Ability-level Context

**Error Message**

The context is not ability context.

**Description**

This error code is reported when the passed Context object is not an ability-level context.

**Possible Causes**

The passed Context object is not a UIAbilityContext or an ExtensionContext, and does not inherit from the UIAbilityContext or ExtensionContext class.

**Solution**

Use a UIAbilityContext object or an ExtensionContext object as the input parameter, or use the object that inherits from the UIAbilityContext or ExtensionContext class as the input parameter.
<!--DelEnd-->

## 16000050 Internal Error

**Error Message**

Internal error.

**Description**

This error code is reported when an internal exception occurs that is beyond the control of the developer, such as memory allocation failure, multithreading issues, or IPC failure.

**Possible Causes**

This is a generic system error code and can be triggered by various issues depending on the API. Common causes include: null pointer exceptions for internal objects, processing timeouts, IPC failures, failure in obtaining application information, failure in obtaining system services, and reaching the maximum limit of launched ability instances.

**Solution**

1. Since this is a system-level error, it is typically out of the developer's control. You can try the operation again.
2. If the ability fails to start, check whether the data passed in Want is too large.

## 16000053 Ability Is Not on Top

**Error Message**

The ability is not on the top of the UI.

**Description**

This error code is reported when the ability is not displayed on the top of the UI.

**Possible Causes**

During the installation-free startup process, the ability is not displayed on the top of the UI.

**Solution**

Ensure that the ability is displayed on the top of the UI.

## 16000055 Installation-Free Timeout

**Error Message**

Installation-free timed out.

**Description**

This error code is reported when the installation-free task times out.

**Possible Causes**

Installation-free times out.

**Solution**

Try again later.

<!--Del-->
## 16000058 Specified URI Flag Is Invalid

**Error Message**

Invalid URI flag.

**Description**

This error code is reported when the specified URI flag is invalid.

**Possible Causes**

An incorrect parameter is passed in.

**Solution**

Pass in a valid URI flag.

## 16000059 Specified URI Type Is Invalid

**Error Message**

Invalid URI type.

**Description**

This error code is reported when the specified URI type is invalid.

**Possible Causes**

An incorrect parameter is passed in. Currently, URI authorization management supports only URIs of the file type.

**Solution**

Ensure that the input parameter is of the supported URI type.

## 16000060 Sandbox Applications Cannot Authorize URIs

**Error Message**

A sandbox application cannot grant URI permission.

**Description**

This error code is reported when a sandbox application authorizes a URI.

**Possible Causes**

Sandbox applications cannot authorize URIs.

**Solution**

Use a non-sandbox application.
<!--DelEnd-->

## 16000061 Unsupported Operation

**Error Message**

Operation not supported.

**Description**

This error code is reported when an operation is not supported.

**Possible Causes**

The operation is not supported.

**Solution**

Perform a supported operation.

## 16000062 Too Many Child Processes

**Error Message**

The number of child processes exceeds the upper limit.

**Description**

This error code is reported when the number of created child processes reaches the upper limit.

**Possible Causes**

The number of created child processes has reached the upper limit.

**Solution**

Limit the number of created child processes. The maximum number is 512.

## 16000063 Invalid Ability During Application Restart

**Error Message**

The target to restart does not belong to the current application or is not a UIAbility.

**Description**

This error code is reported when the specified ability name or type is invalid during application restart.

**Possible Causes**

The specified ability name or type is invalid.

**Solution**

Ensure that the specified ability name exists in the current application and the ability type is UIAbility.

## 16000064 Frequent Application Restart

**Error Message**

Restart too frequently. Try again at least 3s later.

**Description**

An API is called to restart the application and start a specified ability. This error code is reported when the API is called again within 3 seconds.

**Possible Causes**

The API is frequently called.

**Solution**

Call the API again after 3 seconds.

## 16000065 API Can Be Called for a Foreground Ability

**Error Message**

The API can be called only when the ability is running in the foreground.

**Description**

This error code is reported when the API is called while the ability is not running in the foreground.

**Possible Causes**

The ability is not in the foreground when the API is called.

**Solution**

Switch the ability to the foreground before calling the API.

## 16000066 Ability Cannot Be Switched to the Foreground or Background in Wukong Mode

**Error Message**

An ability cannot switch to the foreground or background in Wukong mode.

**Description**

This error code is reported when the API used to switch the ability to the foreground or background is called in Wukong mode.

**Possible Causes**

In Wukong mode, the ability cannot be switched to the foreground or background.

**Solution**

Exit wukong mode, and then call the API to switch the ability to the foreground or background.  

## 16000067 Ability Startup Parameter Verification Failure

**Error Message**

The StartOptions check failed.

**Description**

This error code is reported when verification on **StartOptions** fails.

**Possible Causes**

1. **startAbility()**, with **processMode** set to **NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM** or **ATTACH_TO_STATUS_BAR_ITEM**, is called, but the application icon is not displayed in the status bar.
2. **showAbility()** or **hideAbility()** is called, but the caller is not started in **NEW_PROCESS_ATTACH_TO_STATUS_BAR_ITEM** or **ATTACH_TO_STATUS_BAR_ITEM** mode.

**Solution**

Check whether the constraints for **StartOptions** are met.

## 16000068 Ability Is Already Running

**Error Message**

The ability is already running.

**Description**

This error code is reported when the target ability is already running.

**Possible Causes**

**startAbility()** is called, with **processMode** and **startupVisibility** specified. **launchType** of the target ability is singleton or specified, and the target ability is running.

**Solution**

When **launchType** of the target ability is singleton or specified, do not specify **processMode** and **startupVisibility** in **startAbility()**.

## 16000069 ExtensionAbility Fails to Start a Third-Party Application in Strict Mode

**Error Message**

The extension cannot start the third party application.

**Description**

This type of ExtensionAbility cannot start a third-party application in strict mode.

**Possible Causes**

The ExtensionAbility is in strict mode, and this type of ExtensionAbility is forbidden to start third-party applications in strict mode.

**Solution**

1. Check the conditions for enabling the strict mode of this [type of ExtensionAbility](../../application-models/extensionability-overview.md).
2. Start the ExtensionAbility in non-strict mode.

## 16000070 ExtensionAbility Fails to Start a ServiceExtensionAbility in Strict Mode

**Error Message**

The extension cannot start the service.

**Description**

This type of ExtensionAbility cannot start a ServiceExtensionAbility in strict mode.

**Possible Causes**

The ExtensionAbility is in strict mode, and this type of ExtensionAbility is forbidden to start a ServiceExtensionAbility in strict mode.

**Solution**

1. Check the conditions for enabling the strict mode of this [type of ExtensionAbility](../../application-models/extensionability-overview.md).
2. Start the ExtensionAbility in non-strict mode.

## 16000071 Application Clone Is Not Supported

**Error Message**

App clone is not supported.

**Description**

This error code is reported when the application does not support clones.

**Possible Causes**

This error code is reported when the [getCurrentAppCloneIndex](./js-apis-inner-application-applicationContext.md#applicationcontextgetcurrentappcloneindex12) API is called while the [multiAppMode](../../quick-start/app-configuration-file.md#multiappmode) field in the **app.json5** file is not set to **appClone** (meaning that the application does not support app clone mode).

**Solution**

Configure the **multiAppMode** field in the **app.json5** file by referring to [Creating an Application Multi-Instance](../../quick-start/multiInstance.md). After app clone mode is enabled, call the [getCurrentAppCloneIndex](./js-apis-inner-application-applicationContext.md#applicationcontextgetcurrentappcloneindex12) API.

<!--Del-->
## 16000072 Multi-App Mode Is Not Supported

**Error Message**

App clone or multi-instance is not supported.

**Description**

This error code is reported when the application does not support multi-app mode.

**Possible Causes**

The **getRunningMultiAppInfo()** API is called to query the information about an application that does not support multi-app mode.

**Solution**

When calling **getCurrentAppCloneIndex()**, ensure that the application supports multi-app mode.
<!--DelEnd-->

## 16000073 appCloneIndex Is Invalid

**Error Message**

The app clone index is invalid.

**Description**

This error code is reported when an invalid value of **appCloneIndex** is passed in.

**Possible Causes**

1. **startAbility()** is called, with **appCloneIndex** carried in **ohos.extra.param.key.appCloneIndex** set to an invalid value.
2. **isAppRunning()** is called, with **appCloneIndex** set to an invalid value.

**Solution**

Check whether the constraints of **appCloneIndex** are met.

## 16000074 Caller Corresponding to requestCode Does Not Exist When the Result Is Returned

**Error Message**

The caller does not exist.

**Description**

This error code is reported when the **backToCallerAbilityWithResult** API attempts to return the result to the caller but fails to find the caller based on **requestCode**.

**Possible Causes**

1. **requestCode** is not obtained from the **CALLER_REQUEST_CODE** field in **want**.

2. The caller corresponding to **requestCode** has been destroyed or the result has been returned.

**Solution**

1. Check whether **requestCode** is obtained from **CALLER_REQUEST_CODE** in **want**.

2. Check whether the caller has been destroyed or the result has been returned.

## 16000075 Caller Cannot Be Started When the Result Is Returned

**Error Message**

BackToCaller is not supported.

**Description**

This error code is reported when the **backToCallerAbilityWithResult** API fails to return the result to the caller.

**Possible Causes**

The link feature is not configured for the application or the configuration is not approved by the system.

**Solution**

1. Ensure that the **linkFeature** field is configured in the **module.json5** file of the application.
2. Ensure that the **linkFeature** field value of the application is correct, the functionality it describes matches the actual capability of the application link, and the configuration has been approved by the system.

## 16000076 APP_INSTANCE_KEY Does Not Exist

**Error Message**

The app instance key is invalid.

**Description**

This error code is reported when the specified [APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params) does not exist.

**Possible Causes**

The instance specified by [APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params) does not exist.

**Solution**

Ensure that the value of [APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params) is valid.

## 16000077 Number of Application Instances Reaches the Upper Limit

**Error Message**

The number of app instances reaches the limit.

**Description**

This error code is reported when the number of application instances reaches the upper limit and more application instances try to be created.

**Possible Causes**

Before creating an application instance, the application does not check whether the number of application instances reaches the upper limit.

**Solution**

You can create application instances only after adjusting the upper limit of application instances or deleting existing application instances.

## 16000078 Multi-Instance Mode Is Not Supported

**Error Message**

The multi-instance is not supported.

**Description**

This error code is reported when the application does not support multi-instance mode.

**Possible Causes**

1. Multi-instance mode is not configured for the application.
2. The current device type does not support multi-instance mode.

**Solution**

1. Configure multi-instance mode for the application.
2. Call the API to create multiple instances on a 2-in-1 device.

## 16000079 APP_INSTANCE_KEY Cannot Be Specified

**Error Message**

The APP_INSTANCE_KEY cannot be specified.

**Description**

[APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params) and [CREATE_APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params) cannot be specified at the same time. This error code is reported when both of them are specified.

**Possible Causes**

Too many parameters are passed.

**Solution**

Specify either [APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params) or [CREATE_APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params).

## 16000080 New Instances Cannot Be Created

**Error Message**

Creating a new instance is not supported.

**Description**

Applications can use [CREATE_APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params) to create their own instances, but not for other applications. Otherwise, this error code is reported.

**Possible Causes**

The parameter use scenario is incorrect.

**Solution**

Delete the [CREATE_APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params) parameter.

<!--Del-->
## 16000081 Failed to Obtain the Target Application Information

**Error Message**

Failed to obtain the target application information.

**Description**

In the call of an [API related to URI authorization](js-apis-uripermissionmanager-sys.md), the information about the target application cannot be obtained based on the bundle name and clone index.

**Possible Causes**

1. The target application is not installed.
2. The clone index is out of range.
3. The target application does not have a clone of the specified index.

**Solution**

1. Check whether the application has been installed.
2. Check whether the index is within the allowed range.
3. Check whether the target application has created a clone of the specified index.
<!--DelEnd-->

## 16000084 Only One DelegatorAbility Is Allowed to Call the API

**Error Message**

Only DelegatorAbility is allowed to call this API, and only once.

**Description**

The system allows the DelegatorAbility to call this API only once.

**Possible Causes**

1. The caller is not a DelegatorAbility.
2. The caller is a DelegatorAbility, but it calls the API repeatedly.

**Solution**

1. Check whether the caller is a DelegatorAbility.
2. Check whether the API is being called repeatedly.

## 16000085 Error Occurs During the Interaction Between the Ability and Window

**Error Message**

An error occurred during the interaction between the ability and window.

**Description**

An error occurs during the interaction between the ability and the window.

**Possible Causes**

The window service process is abnormal.

**Solution**

This is a system error. Try calling the API again.

## 16000086 Context Is Not a UIAbilityContext

**Error Message**

The context is not UIAbilityContext.

**Description**

This error code is reported when the passed Context object is not a UIAbilityContext.

**Possible Causes**

The passed Context object is not a UIAbilityContext or does not inherit from the UIAbilityContext class.

**Solution**

Use a UIAbilityContext object or an object that inherits from the UIAbilityContext class as the input parameter.

## 16000090 Caller Is Not an Atomic Service

**Error Message**

The caller is not an atomic service.

**Description**

This error code is reported when the caller is not an atomic service.

**Possible Causes**

The API caller is not an atomic service.

**Solution**

The application does not support this API.

<!--Del-->
## 16000091 Failed to Obtain a File URI by Key

**Error Message**

Failed to get the file URI from the key.

**Description**

This error code is reported when attempting to obtain a file URI based on the key fails.

**Possible Causes**

1. The key is empty.
2. The key does not belong to the current caller.
3. The key is not a data path of a specific service.
4. The data corresponding to the key in the UDMF is not entirely composed of file URIs.

**Solution**

1. Ensure that the key is created by the caller.
2. Ensure that the key is a data path of a specific service. For details, see [UDMF Data Path](../apis-arkdata/js-apis-data-unifiedDataChannel.md#intention).
3. Ensure that the data written in the UDMF when creating the key is entirely composed of file URIs.

## 16000092 No Permission to Authorize URI

**Error Message**

No permission to authorize the URI.

**Description**

This error code is reported when the caller does not have the permission to authorize the URI.

**Possible Causes**

The URIs written when the key is created include URIs that cannot be authorized.

**Solution**

Ensure that all URIs written when the key is created are authorized.

## 16000093 Invalid Caller Token ID

**Error Message**

The caller token ID is invalid.

**Description**

This error code is reported when the token ID of the caller is invalid.

**Possible Causes**

The system does not find the application corresponding to **callerTokenId**.

**Solution**

Check whether the application corresponding to **callerTokenId** is installed.

## 16000094 Invalid Target Token ID

**Error Message**

The target token ID is invalid.

**Description**

This error code is reported when the token ID of the target application is invalid.

**Possible Causes**

1. The system does not find the application corresponding to **targetTokenId**.
2. **targetTokenId** and **callerTokenId** are the same application.

**Solution**

1. Ensure that the application corresponding to **targetTokenId** is installed.
2. Ensure that **callerTokenId** and **targetTokenId** are not the same application.
<!--DelEnd-->

## 16000100 Failed to Call AbilityMonitor APIs to Listen for Ability Lifecycle Changes

**Error Message**

 - Calling AddAbilityMonitor failed.

 - Calling AddAbilityMonitorSync failed.

 - Calling RemoveAbilityMonitor failed.

 - Calling RemoveAbilityMonitorSync failed.

 - Calling WaitAbilityMonitor failed.

 - Calling GetCurrentTopAbility failed.

 - Calling DoAbilityForeground failed.

 - Calling DoAbilityBackground failed.

 - Calling FinishTest failed.

 - Calling AddAbilityStageMonitor failed.

 - Calling AddAbilityStageMonitorSync failed.

 - Calling RemoveAbilityStageMonitor failed.

 - Calling RemoveAbilityStageMonitorSync failed.

 - Calling WaitAbilityStageMonitor failed.

**Description**

This error code is reported when an AbilityMonitor API for monitoring the lifecycle change of a specified ability fails to be executed.

**Possible Causes**

Creating an AbilityDelegatorRegistry instance fails.

**Solution**

Check whether an AbilityDelegatorRegistry instance is created.

## 16000110 Application Is Not in the Kiosk Mode List

**Error Message**

Current application is not in kiosk app list, can not exit kiosk mode.

**Description**

The current application is not in the list of applications configured to support kiosk mode in EDM. Attempting to enter or exit kiosk mode will return this error code.

**Possible Causes**

The application is not in the list of applications configured to support kiosk mode in EDM.

**Solution**

Check whether the application is in the list of applications configured to support kiosk mode in EDM.

## 16000111 Application Is Already in Kiosk Mode

**Error Message**

System is already in kiosk mode, can not enter again.

**Description**

The system already has an application in kiosk mode. Attempting to enter kiosk mode again will return this error code.

**Possible Causes**

An application is already in kiosk mode.

**Solution**

Check whether any application in the system is already in kiosk mode.

## 16000112 No Application Is in Kiosk Mode

**Error Message**

Current application is not in kiosk mode, can not exit.

**Description**

No application in the system is in Kiosk mode. Attempting to exit kiosk mode will return this error code.

**Possible Causes**

No application is in kiosk mode.

**Solution**

Check whether any application in the system is in Kiosk mode.

## 16000113 Ability Is Not in the Foreground

**Error Message**

Current ability is not in foreground.

**Description**

When the ability is not in the foreground, attempting to perform operations that require the foreground will return this error code.

**Possible Causes**

The current ability is not in the foreground.

**Solution**

Check whether the ability is in the foreground.

<!--Del-->
## 16000120 Number of Elements in wantList Exceeds 4 or Is Less Than 1

**Error Message**

A maximum of four UIAbility instances can be started simultaneously.The current parameter exceeds the maximum number or is less than 1.

**Description**

The input parameter is incorrect. The **wantList** parameter must contain 1 to 4 Want objects.

**Possible Causes**

The **wantList** parameter contains more than four or less than one element.

**Solution**

Ensure that the **wantList** parameter contains 1 to 4 Want objects.

## 16000121 Target Component Is Not a UIAbility

**Error Message**

The target component type is not a UIAbility.

**Description**

The target component is not a UIAbility.

**Possible Causes**

**startUIAbilities** can start only UIAbility components. This error code is reported when the target component is not a UIAbility.

**Solution**

Check the component type passed in the Want and ensure that the component is a UIAbility.

## 16000122 Target Component Is Intercepted by the System Control Module

**Error Message**

The target component is blocked by the system module and does not support startup.

**Description**

The target component is intercepted by the system control module and cannot be started.

**Possible Causes**

The system control module has blocked the startup of the target application.

**Solution**

If the target UIAbility cannot be started, try to start another UIAbility.

## 16000123 Implicit Startup Is Not Supported

**Error Message**

Implicit startup is not supported.

**Description**

Implicit startup is not supported.

**Possible Causes**

The **wantList** parameter contains an implicit Want.

**Solution**

Check the **wantList** parameter and ensure that no implicit Want exists. If implicit Want exists, change it to explicit Want.

## 16000124 Starting a Distributed UIAbility Is Not Supported

**Error Message**

Starting a remote UIAbility is not supported.

**Description**

This error code is reported when you attempt to start a remote UIAbility.

**Possible Causes**

The **deviceId** field in the Want is not empty and is not the local device ID.

**Solution**

Set the **deviceId** field in the Want to an empty string or the local device ID.

## 16000125 Starting a Plugin Is Not Supported

**Error Message**

Starting a plugin UIAbility is not supported.

**Description**

This error code is reported when you attempt to start a plugin.

**Possible Causes**

The **parameters** field in the Want is set to start the UIAbility of the plugin.

**Solution**

Check the **parameters** field in the Want and do not set **ohos.params.pluginAbility** to **true**.

## 16000126 DLP Files Cannot Be Started

**Error Message**

Starting DLP files is not supported.

**Description**

This error code is reported when you attempt to start a DLP file.

**Possible Causes**

A DLP file is passed in the Want.

**Solution**

Check whether the Want carries a DLP file.
<!--DelEnd-->

## 16000151 Invalid wantAgent Object

**Error Message**

Invalid wantAgent object.

**Description**

This error code is reported when the wantAgent object passed in the API is invalid.

**Possible Causes**

1. The wantAgent object is invalid.
2. A third-party application attempts to set the ability of another application.
3. An internal communication error occurs.

**Solution**

1. Ensure that the wantAgent object passed in the API exists.
2. Check whether the caller is a third-party application. Third-party applications cannot set the abilities of other applications.

<!--Del-->
## 16000153 wantAgent Object Is Canceled

**Error Message**

The WantAgent has been canceled.

**Description**

This error code is reported when the wantAgent object passed in the API has been canceled.

**Possible Causes**

The wantAgent object passed to the API has been canceled.

**Solution**

Use the wantAgent object that is not canceled.
<!--DelEnd-->

## 16000200 Caller Is Not Allowed to Start a Background Service of the Application

**Error Message**

The caller is not in the appIdentifierAllowList of the target application.

**Description**

This error code is reported when the caller is not in the [appIdentifierAllowList](../../quick-start/module-configuration-file.md#extensionabilities) of the target application.

**Possible Causes**

The **app-identifier** of the caller of [startAppServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#startappserviceextensionability20) or [stopAppServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#stopappserviceextensionability20) is not in the [appIdentifierAllowList](../../quick-start/module-configuration-file.md#extensionabilities) of the target [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md).

**Solution**

Configure the **app-identifier** of the API caller in the [appIdentifierAllowList](../../quick-start/module-configuration-file.md#extensionabilities) of the target [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md).

## 16000201 Target Service Is Not Started

**Error Message**

The target service has not been started yet.

**Description**

This error code is reported when the target service is not started.

**Possible Causes**

When the [connectAppServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20) API is used, the server is not started, and the current application does not have the permission to start the target service.

**Solution**

1. Wait until the service is started and then reconnect to it.
2. When the current application starts the target service, the **app-identifier** of the API caller must be configured in the [appIdentifierAllowList](../../quick-start/module-configuration-file.md#extensionabilities) of the target [AppServiceExtensionAbility](js-apis-app-ability-appServiceExtensionAbility.md).

## 16200001 Caller Released

**Error Message**

The caller has been released.

**Description**

This error code is reported when the caller has been released.

**Possible Causes**

The caller has been released.

**Solution**

1. Register a valid caller again.
2. Check whether the ability corresponding to the context is still running when **context.startAbility** is called. This error code is thrown when the ability has been destructed.
3. If **startAbility()** and **terminateSelf()** are called consecutively, ensure that a success or failure callback for **startAbility()** is received before calling **terminateSelf()**.

## 16200002 Invalid Callee

**Error Message**

The callee does not exist.

**Description**

This error code is reported when the callee is invalid.

**Possible Causes**

The callee does not exist.

**Solution**

Use a valid callee.

## 16200004 Method Registered

**Error Message**

The method has been registered.

**Description**

This error code is reported when the method has been registered.

**Possible Causes**

The method has been registered by the callee.

**Solution**

Check whether the method has been registered.

## 16200005 Method Not Registered

**Error Message**

The method has not been registered.

**Description**

This error code is reported when the method has not been registered.

**Possible Causes**

The method has not been registered by the callee.

**Solution**

Check whether the method has been registered.

<!--Del-->
## 16200006 No Permission to Enable or Disable the Resident Process

**Error Message**

The caller application can only set the resident status of the configured process.

**Description**

This error code is reported when the caller does not have the permission to enable or disable the resident process.

**Possible Causes**

The caller does not have the permission to enable or disable the resident process.

**Solution**

Ensure that the caller has the required permission before calling this API.

## 16300001 Nonexistent Mission

**Error Message**

Mission not found.

**Description**

This error code is reported when the specified mission does not exist.

**Possible Causes**

The mission does not exist.

**Solution**

Check the mission ID.

## 16300002 Nonexistent Mission Listener

**Error Message**

The specified mission listener does not exist.

**Description**

This error code is reported when the specified mission listener does not exist.

**Possible Causes**

The mission listener does not exist.

**Solution**

Check the mission listener ID.
<!--DelEnd-->

## 16300003 Target Application Is Not the Invoker Application

**Error Message**

The target application is not the current application.

**Description**

This error code is reported when the application to start is not the application that calls the API.

**Possible Causes**

The application to start and the invoker application are not the same application.

**Solution**

Ensure that the application to start is the invoker application.

<!--Del-->
## 18500001 Invalid Bundle Name

**Error Message**

The bundle does not exist or no patch has been applied.

**Description**

This error code is reported when the specified bundle name is invalid.

**Possible Causes**

The bundle does not exist or is not installed.

**Solution**

Check whether the bundle has been installed.

## 18500002 Invalid Patch Package

**Error Message**

Invalid patch package.

**Description**

This error code is returned when the specified patch package is invalid.

**Possible Causes**

The patch package does not exist or is inaccessible.

**Solution**

1. Check whether the path of the patch package is valid.
2. Check whether the application has the permission to access the patch package.

## 18500008 Internal Error

**Error Message**

Internal error.

**Description**

This error code is reported when an error occurs during internal processing, such as memory application or multithreading processing.

**Possible Causes**

Common kernel errors such as memory application and multithreading processing errors occur.

**Solution**

Ensure sufficient system memory.

## 18500009 Application Has a Quick Fix Task Being Processed

**Error Message**

The application has an ongoing quick fix task.

**Description**

This error code is reported when the application has a quick fix task that is under processing.

**Possible Causes**

When you try to cancel a quick fix task for an application, the application has a quick repair task that is under processing.

**Solution**

Wait until the quick fix task is complete.
<!--DelEnd-->

## 16300004 Observer Does Not Exist

**Error Message**

The observer does not exist.

**Description**

This error code is reported when the specified observer does not exist.

**Possible Causes**

The observer does not exist or has been unregistered.

**Solution**

Check whether the observer exists.

<!--Del-->
## 16300005 Bundle Information Does Not Exist

**Error Message**

The target bundle does not exist.

**Description**

This error code is reported when the bundle information of the preinstalled application does not exist.

**Possible Causes**

The value of **bundleName**, **userId**, or **appIndex** is incorrect, leading to the query failure.

**Solution**

Pass in correct values for **bundleName**, **userId**, and **appIndex**.

## 16300008 Specified Package Does Not Have a Main UIAbility

**Error Message**

The target bundle has no MainAbility.

**Description**

This error code is reported when the application does not have a main UIAbility.

**Possible Causes**

The ability configured for **mainElement** is not a UIAbility.

**Solution**

Check whether the ability configured for **mainElement** in the **module.json** file is a UIAbility.

## 16300009 Specified Package Does Not Have a Status Bar

**Error Message**

The target bundle has no status-bar ability.

**Description**

This error code is reported when the application does not have a status bar.

**Possible Causes**

The application does not have a status bar.

**Solution**

Check whether the application has a status bar.

## 16300010 Running Application Is Not Attached to a Status Bar

**Error Message**

The target application is not attached to the status bar.

**Description**

This error code is reported when the application is not attached to a status bar after running.

**Possible Causes**

The application has a status bar, but it is not attached to the status bar during running.

**Solution**

Check whether the application is attached to a status bar.
<!--DelEnd-->

## 29600001 Internal Error During Image Editing

**Error Message**

Internal error.

**Description**

This error code is reported when an internal error such as memory allocation or multithreaded processing exception occurs during image saving.

**Possible Causes**

Common kernel errors such as memory application and multithreading processing errors occur. The possible causes are as follows: The internal object is empty, and the processing times out.

**Solution**

1. Ensure sufficient system memory. Ensure that the system version used by the device is normal.
2. Restart the device.

## 29600002 Internal Error During Image Editing

**Error Message**

Image input error.

**Description**

This error code is reported when the image URI does not exist or the image cannot be parsed.

**Possible Causes**

The URI does not exist or the URI does not point to an image file.

**Solution**

Check whether the file exists and whether the file type is image.

## 29600003 Image Too Large

**Error Message**

Image too big.

**Description**

The image is too large.

**Possible Causes**

This error code is reported when the size of the image exceeds 50 MB.

**Solution**

1. Limit the size of the edited image to less than 50 MB.
2. Verify the image size in advance.

<!--Del-->
## 16300007 Download and Installation Task Information of the Atomic Service Does Not Exist

**Error Message**

The target free-installation task does not exist.

**Description**

This error code is reported when the download and installation task of the specified atomic service does not exist while the atomic service window is opened.

**Possible Causes**

The value of **bundleName**, **moduleName**, **abilityName**, or **startTime** is incorrect, leading to the query failure.

**Solution**

Pass in correct values for **bundleName**, **moduleName**, **abilityName**, and **startTime**.
<!--DelEnd-->

## 28800001 Startup Task or Dependency Not Found

**Error Message**

Startup task or its dependency not found.

**Description**

This error code is reported if the startup task or its dependency is not found during task startup.

**Possible Causes**

The startup task or dependency is not correctly configured.

**Solution**

Check whether the AppStartup configuration file is correctly compiled, and ensure that all configured startup tasks are implemented.

## 28800002 Circular Dependencies Between Startup Tasks

**Error Message**

The startup tasks have circular dependencies.

**Description**

This error code is reported if circular dependencies are detected between startup tasks during startup task loading.

**Possible Causes**

There are circular dependencies between startup tasks.

**Solution**

Check the AppStartup configuration file, and ensure that no circular dependency exists between startup tasks.

## 28800003 Error Occurs During Task Startup

**Error Message**

An error occurred while running the startup tasks.

**Description**

This error code is reported when an error occurs during task startup.

**Possible Causes**

The code logic for starting the task is incorrect, or no exception handling is available.

**Solution**

Check whether the startup task has logic errors, and ensure that each startup task contains the exception handling logic.

## 28800004 Executing the Startup Task Times Out

**Error Message**

Running startup tasks timeout.

**Description**

This error code is reported if the execution time of a task exceeds the timeout interval (10000 ms by default).

**Possible Causes**

The startup task contains a large number of time-consuming operations, or the configured timeout interval is too short.

**Solution**

Adjust the timeout interval as required. For details about how to set the timeout interval, see [Setting Startup Parameters](../../application-models/app-startup.md#setting-startup-parameters).

<!--Del-->
## 16400001 Target Application Type Is Not a System HSP

**Error Message**

The input bundleName is not a system HSP.

**Description**

When the [createSystemHspModuleResourceManager](js-apis-inner-application-context-sys.md#createsystemhspmoduleresourcemanager12) API is used to create a [ResourceManager](../apis-localization-kit/js-apis-resource-manager.md#resourcemanager), if the passed **bundleName** does not belong to a module of a [system HSP](../../quick-start/application-package-glossary.md#system-level-hsp), this error code is reported.

**Possible Causes**

The **bundleName** parameter passed to **createSystemHspModuleResourceManager** is not the bundle name of the HSP preconfigured in the system by the OEM.

**Solution**

Check whether the value of **bundleName** is correct.

## 16000202 Keep-Alive Can Be Set Only for an ExtensionAbility of the appService Type

**Error Message**

Invalid main element type.

**Description**

This error code is reported when the object to be kept alive is not an ExtensionAbility of the appService type.

**Possible Causes**

The **mainElement** field in the **module.json5** file of the entry HAP is not an ExtensionAbility of the appService type.

**Solution**

Change the **mainElement** field of the entry HAP in the **module.json5** file to an ExtensionAbility of the appService type.

## 16000203 Cannot Change the Keep-alive Status of an AppServiceExtensionAbility

**Error Message**

Cannot change the keep-alive status.

**Description**

This error code is reported when the keep-alive status of an AppServiceExtensionAbility cannot be changed.

**Possible Causes**

The keep-alive policy of the AppServiceExtensionAbility is set by the MDM to be uncancelable by users or is set to keep-alive by other users.

**Solution**

Cancel the keep-alive setting on the MDM server, or set the keep-alive policy to allow users to cancel the keep-alive. Cancel the keep-alive of the AppServiceExtensionAbility for the user who has the keep-alive permission.

## 16000204 Application Is Not Installed for the User with userId of 1

**Error Message**

The target bundle is not in u1.

**Description**

This error code is reported when the specified application is not installed under the user with **userId** of 1.

**Possible Causes**

The specified application is not installed under the user with **userId** of 1.

**Solution**

Install the specified application under the user with **userId** of 1.
<!--DelEnd-->

## 16000115 Process Is Not Running the Component with isolationProcess Set to true

**Error Message**

The current process is not running a component configured with "isolationProcess" and cannot be set as a candidate master process.

**Description**

This error code is reported when you attempt to set a process, which is not running any component configured with **isolationProcess**, as a candidate master process.

**Possible Causes**

The current process is not running any component configured with **isolationProcess** and therefore cannot be designated as a candidate master process.

**Solution**

No action can be taken. Since the current process is not running any component with **isolationProcess** set to **true**, it cannot be set as a candidate master process.

## 16000116 Process Is Already a Master Process

**Error Message**

The current process is already a master process and does not support cancellation.

**Description**

This error code is reported when you attempt to cancel the current process, which is already the master process, as a candidate master process.

**Possible Causes**

The current process is already the main process.

**Solution**

No action can be taken. Cancellation is not supported since the current process is already the master process.

## 16000117 Process Is Not a Candidate Master Process

**Error Message**

The current process is not a candidate master process and does not support cancellation.

**Description**

This error code is reported when you attempt to cancel the current process, which is not a candidate master process , as a candidate master process.

**Possible Causes**

The current process is not a candidate master process and cannot be canceled.

**Solution**

No action can be taken. Cancellation is not supported since the current process is not a candidate master process.
