# Ability Error Codes

## 16000001 Ability Name Does Not Exist

**Error Message**

Input error. The specified ability name does not exist.

**Description**

This error code is reported when the specified ability name does not exist.

**Possible Causes**

The ability to query does not exist.

**Solution**

1. Check whether the bundle name is correct.
2. Check whether the ability name corresponding to the bundle name is correct.

## 16000002 Incorrect Ability Type

**Error Message**

Ability type error. The specified ability type is wrong.

**Description**

This error code is reported when the ability type invoked by the API is incorrect.

**Possible Causes**

The ability with the specified type does not support the API invocation.

**Solution**

1. Check whether the ability name corresponding to the bundle name is correct.
2. Call the supported APIs based on the ability type.

## 16000003 Nonexistent ID

**Error Message**

Input error. The specified id does not exist.

**Description**

This error code is reported when the specified ID does not exist.

**Possible Causes**

The target with the specified ID does not exist.

**Solution**

Use the correct ID.

## 16000004 Visibility Verification Failure

**Error Message**

Visibility verification failed.

**Description**

This error code is reported when the application fails visibility verification.

**Possible Causes**

Visibility verification fails.

**Solution**

Check whether the application meets the visibility restriction of the started application.

## 16000006 Cross-User Operation Is Not Allowed

**Error Message**

Can not cross user operations.

**Description**

This error code is reported when an application tries to perform a cross-user operation.

**Possible Causes**

The application initiates a cross-user operation.

**Solution**

Do not perform a cross-user operation.

## 16000007 Service Busy

**Error Message**

Service busyness. There are concurrent tasks, waiting for retry.

**Description**

This error code is reported when the service requested is busy.

**Possible Causes**

The service is busy.

**Solution**

Try again later.

## 16000008 Crowdtesting Application Expires

**Error Message**

Crowdtest App Expiration.

**Description**

This error code is reported when users try to open a crowdtesting application that has expired.

**Possible Causes**

The crowdtesting application has expired.

**Solution**

Check whether the crowdtesting application has expired.

## 16000009 Ability Start or Stop Failure in Wukong Mode

**Error Message**

Can not start ability in wukong mode.

**Description**

This error code is returned when the application tries to start or stop an ability in Wukong mode.

**Possible Causes**

An ability cannot be started or stopped in Wukong mode.

**Solution**

Do not start or stop an ability in Wukong mode.

## 16000010 Continuation Flag Forbidden

**Error Message**

Can not operation with continue flag.

**Description**

This error code is reported when the API call carries the continuation flag.

**Possible Causes**

The continuation flag is not allowed for the API call.

**Solution**

Remove the continuation flag.

## 16000011 Nonexistent Context

**Error Message**

Context does not exist.

**Description**

This error code is reported when the specified context does not exist.

**Possible Causes**

The context passed in the API does not exist.

**Solution**

Use the correct context.

## 100001 Internal Error

**Error Message**

Internal Error.

**Description**

This error code is reported when an error occurs during internal processing, such as memory application or multi-thread processing.

**Possible Causes**

Common kernel errors such as memory application and multi-thread processing errors occur.

**Solution**

Ensure sufficient sytem memory.

## 16000051 Network Error

**Error Message**

Network error. The network is abnormal.

**Description**

This error code is reported when the network is abnormal.

**Possible Causes**

The network is unavailable.

**Solution**

Try again later or reconnect to the network.

## 16000052 Installation-Free Is Not Supported

**Error Message**

Free install not support. The applicaiotn dose not support free install.

**Description**

This error code is reported when the application does not support installation-free.

**Possible Causes**

The application package does not meet the installation-free requirements. For example, the package is too large.

**Solution**

Check whether the application supports installation-free.

## 16000053 Ability Is Not on Top

**Error Message**

Not top ability. The application is not top ability.

**Description**

This error code is reported when the ability is not displayed on the top of the UI.

**Possible Causes**

The ability is not displayed on the top of the UI.

**Solution**

Ensure that the ability is displayed on the top of the UI.

## 16000054 Installation-Free Busy

**Error Message**

Free install busyness. There are concurrent tasks, waiting for retry.

**Description**

This error code is reported when the installation-free service is busy.

**Possible Causes**

Another installation-free task is in progress.

**Solution**

Try again later.

## 16000055 Installation-Free Timeout

**Error Message**

Free install timeout.

**Description**

This error code is reported when the installation-free task times out.

**Possible Causes**

Installation-free times out.

**Solution**

Try again later.

## 16000056 Installation-Free Is Not Allowed for Other Applications

**Error Message**

Can not free install other ability.

**Description**

This error code is reported when users try to apply installation-free for other applications.

**Possible Causes**

Installation-free is allowed only for the current application.

**Solution**

Apply installation-free only for the current application.

## 16000057 Cross-Device Installation-Free Is Not Supported

**Error Message**

Not support cross device free install.

**Description**

This error code is reported when users try to apply installation-free across devices.

**Possible Causes**

Cross-device installation-free is not supported.

**Solution**

Use installation-free on the same device.

## 16000101 shell Command Failure

**Error Message**

execute shell command failed.

**Description**

This error code is reported when the command is not a valid shell command.

**Possible Causes**

The command is not a valid shell command.

**Solution**

Use a valid shell command.

## 16000151 Invalid wantAgent Object

**Error Message**

Invalid wantagent object.

**Description**

This error code is reported when the **wantAgent** object passed in the API is invalid.

**Possible Causes**

The **wantAgent** object is invalid.

**Solution**

Pass a valid **wantAgent** object in the API.

## 16000152 wantAgent Object Does Not Exist

**Error Message**

wantAgent object not found.

**Description**

This error code is reported when the **wantAgent** object passed in the API does not exist.

**Possible Causes**

The **wantAgent** object does not exist.

**Solution**

Pass a valid **wantAgent** object in the API.

## 16000153 wangAgent Object Canceled

**Error Message**

wangAgent object canceled.

**Description**

This error code is reported when the **wangAgent** object passed in the API has been canceled.

**Possible Causes**

The **wantAgent** object has been canceled.

**Solution**

Pass a valid **wantAgent** object in the API.

## 16100001 Ability of the Specified URI Does Not Exist

**Error Message**

Input error. The specified uri does not exist.

**Description**

This error code is reported when the ability with the specified URI does not exist.

**Possible Causes**

The ability to query does not exist.

**Solution**

Check the ability with the specified URI.

## 16100002 Incorrect Ability Type

**Error Message**

Ability type error. The specified ability type is wrong.

**Description**

This error code is reported when the ability type invoked by the API is incorrect.

**Possible Causes**

The ability with the specified type does not support the API call.

**Solution**

1. Check whether the ability name corresponding to the bundle name is correct.
2. Call the supported APIs based on the ability type.

## 16200001 Caller Released

**Error Message**

Caller released. The caller has been released.

**Description**

This error code is reported when the caller has been released.

**Possible Causes**

The caller has been released.

**Solution**

Register a valid caller again.

## 16200002 Invalid Callee

**Error Message**

Callee Invalid. The callee does not exist.

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

THis error code is reported when the method has been registered.

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

Mission id error. The specified mission id does not exist.

**Description**

This error code is reported when the specified mission does not exist.

**Possible Causes**

The mission does not exist.

**Solution**

Check the mission ID.

## 16300002 Nonexistent Mission Listener

**Error Message**

Input  error. The specified mission listener id does not exist.

**Description**

This error code is reported when the specified mission listener does not exist.

**Possible Causes**

The mission listener does not exist.

**Solution**

Check the mission listener ID.

## 18500001 Invalid Bundle Name

**Error Message**

The specified bundleName is invalid.

**Description**

This error code is reported when the specified bundle name is invalid.

**Possible Causes**

The bundle does not exist or is not installed.

**Solution**

Check whether the bundle has been installed.

## 18500002 Invalid Patch Package

**Error Message**

The specified hqf is invalid. Hqf may not exist or inaccessible.

**Description**

This error code is returned when the specified patch package is invalid.

**Possible Causes**

The patch package does not exist or is inaccessible.

**Solution**

1. Check whether the path of the patch package is valid.
2. Check whether the application has the permission to access the patch package.

## 18500003 Patch Deployment Failure

**Error Message**

Deploy hqf failed.

**Description**

This error code is reported when the patch package fails to be deployed.

**Possible Causes**

1. The **type** field in the **patch.json** file is set to a value other than **patch** or **hotreload**.
2. The HAP corresponding to the bundle name is not installed.
3. The values of **bundleName** and **versionCode** are different from those of the installed HAP. If the **type** field is set to **patch**, the values of **versionName**, **bundleName**, and **versionCode** are different from those of the installed HAP.
4. If a patch package has been deployed, the **versionCode** of the new patch package is not later than that of the previous patch package.
5. If the **type** field is set to **patch**, the signature information is different from that of the application.
6. If the **type** field is set to **patch** and a debug version is to be installed, a **hotreload** patch is in use.
7. If the **type** field is set to **hotreload** and a debug version is to be installed, a **patch** patch is in use. If the **type** field is set to **hotreload**, a release version is to be installed.

**Solution**

Check whether the patch package complies with the deployment rules.

## 18500004 Patch Package Enablement Failure

**Error Message**

Switch hqf failed.

**Description**

This error code is reported when the patch package fails to be enabled.

**Possible Causes**

The patch package is in an incorect state.

**Solution**

Check the state of the patch package.

## 18500005 Patch Package Deletion Failure

**Error Message**

Delete hqf failed.

**Description**

This error code is reported when the patch package fails to be deleted.

**Possible Causes**

The patch package is in an incorrect state.

**Solution**

Check the state of the patch package.

## 18500006 Patch Installation Failure

**Error Message**

Load patch failed.

**Description**

This error code is reported when the patch fails to be installed.

**Possible Causes**

The Ark engine fails to install the patch.

**Solution**

Check whether the patch package is correct.

## 18500007 Patch Uninstall Failure

**Error Message**

Unload patch failed.

**Description**

This error code is reported when when the Ark engine fails to uninstall the patch.

**Possible Causes**

The Ark engine fails to uninstall the patch.

**Solution**

Check whether the patch package is correct.

## 18500008 Internal Error

**Error Message**

Internal error.

**Description**

This error code is returned when an error occurs during internal processing, such as memory application or multi-thread processing.

**Possible Causes**

Common kernel errors such as memory application and multi-thread processing errors occur.

**Solution**

Ensure sufficient system memory.
