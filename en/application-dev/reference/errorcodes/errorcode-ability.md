# Ability Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

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

Incorrect Ability type.

**Description**

This error code is reported when the ability type invoked by the API is incorrect.

**Possible Causes**

The ability with the specified type does not support the API invocation.

**Solution**

1. Pass in correct values of **bundleName**, **moduleName**, and **abilityName** in **want**.
2. Call APIs based on the ability type. For example, call [startServiceExtensionAbility](../apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartserviceextensionability) to start the ServiceExtensionAbility, or call [connectServiceExtensionAbility()](../apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability) to connect to the ServiceExtensionAbility.

## 16000003 Nonexistent ID

**Error Message**

Id does not exist.

**Description**

This error code is reported when the specified ID does not exist.

**Possible Causes**

The target with the specified ID does not exist.

**Solution**

Use the correct ID.

## 16000004 Visibility Verification Failure

**Error Message**

Can not start invisible component.

**Description**

This error code is reported when the application fails visibility verification.

**Possible Causes**

Visibility verification fails.

**Solution**

1. Check whether [exported](../../quick-start/module-configuration-file.md#abilities) under the **Ability** field in the **module.json5** file of the ability is set to **true**. If this parameter is set to **true**, the ability can be started by other applications. If this parameter is set to **false**, the ability cannot be started by other applications.
2. To start the ability for which **exported** is set to **false**, the caller must request the [ohos.permission.START_INVISIBLE_ABILITY](../../security/permission-list.md#ohospermissionstart_invisible_ability) permission.

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

Service busy, there are concurrent tasks, waiting for retry.

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

## 16000011 Nonexistent Context

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

This error code is reported when an application is controlled by [Enterprise Device Manager (EDM)](../apis/enterpriseDeviceManagement-overview.md).

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

The previous ability is starting, wait start later.

**Description**

Too many abilities need to be started. Due to the limited processing capability of the system, the requests are cached in the queue and processed in sequence.

**Possible Causes**

The system has a large number of concurrent requests.

**Solution**

No action is required. Wait for the previous abilities to finish startup.

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

Installation-free service is busy, please wait and try again later.

**Description**

This error code is reported when the installation-free service is busy.

**Possible Causes**

Another installation-free task is in progress.

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

Sandbox application can not grant URI permission.

**Description**

This error code is reported when a sandbox application authorizes a URI.

**Possible Causes**

Sandbox applications cannot authorize URIs.

**Solution**

Use a non-sandbox application.

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

the wantAgent object does not exist.

**Description**

This error code is reported when the **wantAgent** object passed in the API does not exist.

**Possible Causes**

The **wantAgent** object does not exist.

**Solution**

Pass a valid **wantAgent** object in the API.

## 16000153 wangAgent Object Canceled

**Error Message**

wangAgent object has been canceled.

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

Callee invalid. The callee does not exist.

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

Method registered. The method has registered.

**Description**

This error code is reported when the method has been registered.

**Possible Causes**

The method has been registered by the callee.

**Solution**

Check whether the method has been registered.

## 16200005 Method Not Registered

**Error Message**

Method not registered. The method has not registered.

**Description**

This error code is reported when the method has not been registered.

**Possible Causes**

The method has not been registered by the callee.

**Solution**

Check whether the method has been registered.

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

Input error. The specified mission listener does not exist.

**Description**

This error code is reported when the specified mission listener does not exist.

**Possible Causes**

The mission listener does not exist.

**Solution**

Check the mission listener ID.

## 16300003 Target Application Is Not the Invoker Application

**Error Message**

The target application is not self application.

**Description**

This error code is reported when the application to start is not the application that calls the API.

**Possible Causes**

The application to start and the invoker application are not the same application.

**Solution**

Ensure that the application to start is the invoker application.

## 18500001 Invalid Bundle Name

**Error Message**

The bundle is not exist or no patch has applied.

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

Failed to enable the patch package.

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

The application has a apply quick fix task that is being processed.

**Description**

This error code is reported when the application has a quick fix task that is under processing.

**Possible Causes**

When you try to cancel a quick fix task for an application, the application has a quick repair task that is under processing.

**Solution**

Wait until the quick fix task is complete.
