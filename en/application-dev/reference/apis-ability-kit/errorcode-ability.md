# Ability Error Codes

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

The ability with the specified type does not support the API invocation.

**Solution**

1. Pass in correct values of **bundleName**, **moduleName**, and **abilityName** in **want**.
2. Call APIs based on the ability type. For example, call <!--Del-->[startServiceExtensionAbility](js-apis-inner-application-uiAbilityContext-sys.md#uiabilitycontextstartserviceextensionability) to start the ServiceExtensionAbility, or call <!--DelEnd-->[connectServiceExtensionAbility()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability) to connect to the ServiceExtensionAbility.

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

Failed to start the invisible ability.

**Description**

This error code is reported when the application fails visibility verification.

**Possible Causes**

Visibility verification fails.

**Solution**

1. Check whether [exported](../../quick-start/module-configuration-file.md#abilities) under the **Ability** field in the **module.json5** file of the ability is set to **true**. If this parameter is set to **true**, the ability can be started by other applications. If this parameter is set to **false**, the ability cannot be started by other applications.
2. To start the ability for which **exported** is set to **false**, the caller must request the **ohos.permission.START_INVISIBLE_ABILITY** permission, which is available only for system applications.

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

Exit Wukong mode, and then start or stop the ability. An ability cannot be started or stopped in Wukong mode.

## 16000010 Continuation Flag Forbidden

**Error Message**

The call with the continuation flag is forbidden.

**Description**

This error code is reported when the API call carries the continuation flag.

**Possible Causes**

The continuation flag is not allowed for the API call.

**Solution**

Remove the continuation flag.

## 16000011 Context Not Exist

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

This error code is reported when an application is controlled by the application market.

**Possible Causes**

The application is suspected to have malicious behavior and is not allowed to start due to application market control.

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

## 16000017 Waiting for the Previous Abilities to Finish Startup

**Error Message**

Another ability is being started. Wait until it finishes starting.

**Description**

Too many abilities need to be started. Due to the limited processing capability of the system, the requests are cached in the queue and processed in sequence.

**Possible Causes**

The system has a large number of concurrent requests.

**Solution**

No action is required. Wait for the previous abilities to finish startup.

## 16000018 Restricting Redirection to Third-Party Applications of API Version 11 or Later

**Error Message**

Redirection to a third-party application is not allowed in API version 11 or later.

**Description**

When the API version of an application is later than 11, the application cannot be explicitly redirected to a third-party application.

**Solution**

Use implicit startup or [openLink](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12) for redirection.

## 16000019 No Matching Application Is Found During Implicit Startup

**Error Message**

No matching ability is found.

**Description**

A matching ability is not found during implicit startup.

**Solution**

Modify the items used for matching in implicit startup.

## 16000050 Internal Error

**Error Message**

Internal error.

**Description**

This error code is reported when an error occurs during internal processing, such as memory application or multi-thread processing.

**Possible Causes**

Common kernel errors such as memory application and multi-thread processing errors occur. The possible causes are as follows: empty internal object, processing timeout, failure in obtaining application information, failing in obtaining the system service, and too many started ability instances.

**Solution**

1. Ensure sufficient system memory. Ensure that the system version used by the device is normal.
2. Limit the number of ability processes started.
3. Restart the device.

## 16000051 Network Error

**Error Message**

Network error.

**Description**

This error code is reported when the network is abnormal.

**Possible Causes**

The network is unavailable.

**Solution**

Try again later or reconnect to the network.

## 16000052 Installation-Free Is Not Supported

**Error Message**

Installation-free is not supported.

**Description**

This error code is reported when the application does not support installation-free.

**Possible Causes**

The application package does not meet the installation-free requirements. For example, the package is too large.

**Solution**

Check whether the application supports installation-free.

## 16000053 Ability Is Not on Top

**Error Message**

The ability is not on the top of the UI.

**Description**

This error code is reported when the ability is not displayed on the top of the UI.

**Possible Causes**

During the installation-free startup process, the ability is not displayed on the top of the UI.

**Solution**

Ensure that the ability is displayed on the top of the UI.

## 16000054 Installation-Free Busy

**Error Message**

The installation-free service is busy. Try again later.

**Description**

This error code is reported when the installation-free service is busy.

**Possible Causes**

A download and installation task is being executed for the atomic service.

**Solution**

Try again later.

## 16000055 Installation-Free Timeout

**Error Message**

Installation-free timed out.

**Description**

This error code is reported when the installation-free task times out.

**Possible Causes**

Installation-free times out.

**Solution**

Try again later.

## 16000056 Installation-Free Is Not Allowed for Other Applications

**Error Message**

Installation-free is not allowed for other applications.

**Description**

This error code is reported when users try to apply installation-free for other applications.

**Possible Causes**

Installation-free is allowed only for the current application.

**Solution**

Apply installation-free only for the current application.

## 16000057 Cross-Device Installation-Free Is Not Supported

**Error Message**

Cross-device installation-free is not supported.

**Description**

This error code is reported when users try to apply installation-free across devices.

**Possible Causes**

Cross-device installation-free is not supported.

**Solution**

Use installation-free on the same device.

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

## 16000061 Unsupport Operation

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

Restart too frequently. Try again at least 10s later.

**Description**

An API is called to restart the application and start a specified ability. This error code is reported when the API is called again within 10 seconds.

**Possible Causes**

The API is frequently called.

**Solution**

Call the API again after 10 seconds.

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

An application that does not support clones calls **getCurrentAppCloneIndex()**.

**Solution**

Avoid calling **getCurrentAppCloneIndex()** in applications that do not support clones.

<!--Del-->
## 16000072 Multi-app Mode Is Not Supported

**Error Message**

App clone or multi-instance is not supported.

**Description**

This error code is reported when the application does not support the multi-app mode.

**Possible Causes**

The **getRunningMultiAppInfo()** API is called to query the information about an application that does not support the multi-app mode.

**Solution**

When calling **getCurrentAppCloneIndex()**, ensure that the application supports the multi-app mode.
<!--DelEnd-->

## 16000073 appCloneIndex Is Invalid

**Error Message**

The app clone index is invalid.

**Description**

This error code is reported when an invalid value of **appCloneIndex** is passed in.

**Possible Causes**

1. **startAbility()** is called, with **appCloneIndex** carried in **ohos.extra.param.key.appCloneIndex** set to an invalid value.
<!--Del-->
2. **isAppRunning()** is called, with **appCloneIndex** set to an invalid value.
<!--DelEnd-->

**Solution**

Check whether the constraints of **appCloneIndex** are met.

## 16000074 Caller Corresponding to requestCode Does Not Exist When the Result Is Returned

**Error Message**

The caller does not exist.

**Description**

This error code is reported when the **backTocallerAbilityResult** API attempts to return the result to the caller but fails to find the caller based on **requestCode**.

**Possible Causes**

1. **requestCode** is not obtained from the **CALLER_REQUEST_CODE** field in **want**.

2. The caller corresponding to **requestCode** has been destroyed or the result has been returned.

**Solution**

1. Check whether **requestCode** is obtained from **CALLER_REQUEST_CODE** in **want**.

2. Check whether the caller has been destroyed or the result has been returned.

## 16000075 Caller Cannot Be Started When the Result Is Returned

**Error Message**

Not support back to caller.

**Description**

This error code is reported when the **backToCallerAbilityWithResult** API fails to return the result to the caller.

**Possible Causes**

The link feature is not configured for the application or the configuration is not approved by the system.

**Solution**

1. Ensure that the **linkFeature** field is configured in the **module.json5** file of the application.
2. Ensure that the **linkFeature** field value of the application is correct, the functionality it describes matches the actual capability of the application link, and the configuration has been approved by the system.

## 16000076 APP_INSTANCE_KEY Does Not Exist

**Error Message**

The APP_INSTANCE_KEY is invalid.

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

## 16000078 Application Multi-Instance Not Supported

**Error Message**

The multi-instance is not supported.

**Description**

This error code is reported when the application does not support the multi-instance mode.

**Possible Causes**

1. The multi-instance mode is not configured for the application.
2. The current device type does not support the multi-instance mode.

**Solution**

1. Configure the multi-instance mode for the application.
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

Creating an instance is not supported.

**Description**

Applications can use [CREATE_APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params) to create their own instances, but not for other applications. Otherwise, this error code is reported.

**Possible Causes**

The parameter use scenario is incorrect.

**Solution**

Delete the [CREATE_APP_INSTANCE_KEY](js-apis-app-ability-wantConstant.md#params) parameter.

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

Creating an **AbilityDelegatorRegistry** instance fails.

**Solution**

Check whether an **AbilityDelegatorRegistry** instance is created.

## 16000101 shell Command Failure

**Error Message**

Failed to run the shell command.

**Description**

This error code is reported when the command is not a valid shell command.

**Possible Causes**

The command is not a valid shell command.

**Solution**

Use a valid shell command.

## 16000151 Invalid wantAgent Object

**Error Message**

Invalid wantAgent object.

**Description**

This error code is reported when the **wantAgent** object passed in the API is invalid.

**Possible Causes**

The **wantAgent** object is invalid.

**Solution**

Pass a valid **wantAgent** object in the API.

## 16000152 wantAgent Object Does Not Exist

**Error Message**

The wantAgent object does not exist.

**Description**

This error code is reported when the **wantAgent** object passed in the API does not exist.

**Possible Causes**

The **wantAgent** object does not exist.

**Solution**

Pass a valid **wantAgent** object in the API.

## 16000153 wangAgent Object Canceled

**Error Message**

The wantAgent object has been canceled.

**Description**

This error code is reported when the **wangAgent** object passed in the API has been canceled.

**Possible Causes**

The **wantAgent** object has been canceled.

**Solution**

Pass a valid **wantAgent** object in the API.

## 16100001 Ability of the Specified URI Does Not Exist

**Error Message**

The ability with the specified URI does not exist.

**Description**

This error code is reported when the ability with the specified URI does not exist.

**Possible Causes**

The ability to query does not exist.

**Solution**

Check the ability with the specified URI.

## 16100002 Incorrect Ability Type

**Error Message**

Incorrect ability type.

**Description**

This error code is reported when the ability type invoked by the API is incorrect.

**Possible Causes**

The ability with the specified type does not support the API invocation.

**Solution**

1. Check whether the ability name corresponding to the bundle name is correct.
2. Call the supported APIs based on the ability type.

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

## 16200003 Release Failure

**Error Message**

Release error. The caller does not call any callee.

**Description**

This error code is reported when the release fails.

**Possible Causes**

The caller is not registered with a callee.

**Solution**

Check whether the caller has registered.

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

## 16300003 Target Application Is Not the Invoker Application

**Error Message**

The target application is not the current application.

**Description**

This error code is reported when the application to start is not the application that calls the API.

**Possible Causes**

The application to start and the invoker application are not the same application.

**Solution**

Ensure that the application to start is the invoker application.

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

## 18500003 Patch Deployment Failure

**Error Message**

Failed to deploy the patch.

**Description**

This error code is reported when the patch package fails to be deployed.

**Possible Causes**

1. The **type** field in the **patch.json** file is set to a value other than **patch** or **hotreload**.
2. The HAP corresponding to the bundle name is not installed.
3. The values of **bundleName** and **versionCode** are different from those of the installed HAP. If the **type** field is set to **patch**, the values of **versionName**, **bundleName**, and **versionCode** are different from those of the installed HAP.
4. If a patch package has been deployed, the **versionCode** of the new patch package is not later than that of the previous patch package.
5. If the **type** field is set to **patch**, the signature information is different from that of the application.
6. If the **type** field is set to **patch** and a debug version is to be installed, a **hotreload** patch is in use.
7. If the **type** field is set to **hotreload** and a debug version is to be installed, a **patch** package is in use. If the **type** field is set to **hotreload**, a release version is to be installed.

**Solution**

Check whether the patch package complies with the deployment rules.

## 18500004 Patch Package Enablement Failure

**Error Message**

Failed to enable the patch package.

**Description**

This error code is reported when the patch package fails to be enabled.

**Possible Causes**

The patch package is in an incorrect state.

**Solution**

Check the state of the patch package.

## 18500005 Patch Package Deletion Failure

**Error Message**

Failed to remove the patch package.

**Description**

This error code is reported when the patch package fails to be deleted.

**Possible Causes**

The patch package is in an incorrect state.

**Solution**

Check the state of the patch package.

## 18500006 Patch Installation Failure

**Error Message**

Failed to load the patch.

**Description**

This error code is reported when the patch fails to be installed.

**Possible Causes**

The Ark engine fails to install the patch.

**Solution**

Check whether the patch package is correct.

## 18500007 Patch Uninstall Failure

**Error Message**

Failed to unload the patch.

**Description**

This error code is reported when the Ark engine fails to uninstall the patch.

**Possible Causes**

The Ark engine fails to uninstall the patch.

**Solution**

Check whether the patch package is correct.

## 18500008 Internal Error

**Error Message**

Internal error.

**Description**

This error code is reported when an error occurs during internal processing, such as memory application or multi-thread processing.

**Possible Causes**

Common kernel errors such as memory application and multi-thread processing errors occur.

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

## 16300004 Observer Does Not Exist

**Error Message**

observer not found.

**Description**

This error code is reported when the specified observer does not exist.

**Possible Causes**

The observer does not exist or has been unregistered.

**Solution**

Check whether the observer exists.

## 16300005 Bundle Information Does Not Exist

**Error Message**

The target bundle does not exist.

**Description**

This error code is reported when the bundle information of the preinstalled application does not exist.

**Possible Causes**

The value of **bundleName**, **userId**, or **appIndex** is incorrect, leading to the query failure.

**Solution**

Pass in correct values for **bundleName**, **userId**, and **appIndex**.

## 29600001 Internal Error During Image Editing

**Error Message**

Internal error.

**Description**

This error code is reported when an internal error such as memory allocation or multithreaded processing exception occurs during image saving.

**Possible Causes**

Common kernel errors such as memory application and multi-thread processing errors occur. The possible causes are as follows: The internal object is empty, and the processing times out.

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

## 29600002 Image Too Large

**Error Message**

Image too big.

**Description**

The image is too large.

**Possible Causes**

This error code is reported when the size of the image exceeds 50 MB.

**Solution**

1. Limit the size of the edited image to less than 50 MB.
2. Verify the image size in advance.
## 16300007 Download and Installation Task Information of the Atomic Service Does Not Exist

**Error Message**

The target free install task does not exist.

**Description**

This error code is reported when the download and installation task of the specified atomic service does not exist while the atomic service window is opened.

**Possible Causes**

The value of **bundleName**, **moduleName**, **abilityName**, or **startTime** is incorrect, leading to the query failure.

**Solution**

Pass in correct values for **bundleName**, **moduleName**, **abilityName**, and **startTime**.
