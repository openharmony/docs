# Enterprise Device Management Error Codes
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 9200001 DeviceAdmin Not Enabled

**Error Message**

The application is not an administrator application of the device.

**Description**

This error code is reported when the caller is not an enabled device administrator application.

**Possible Causes**

The enterprise device management APIs can be called only by a device administrator application that has been enabled.

**Solution**

Check whether the caller is a device administrator application enabled.

## 9200002 Permission Denied

**Error Message**

The administrator application does not have permission to manage the device.

**Description**

This error code is reported when the device administrator application does not have the permission to invoke the API.

**Possible Causes**

The device administrator application calls an API that is accessible only by a super device administrator application.

**Solution**

Check that the device administrator type enabled for the caller is the same as that required by the API.

## 9200003 Invalid Administrator Ability Component

**Error Message**

The administrator ability component is invalid.

**Description**

This error code is reported when the specified device manager ability component is invalid.

**Possible Causes**

The specified administrator ability component is invalid due to any of the following causes:
1. The administrator ability component does not exist when the device administrator application is enabled.
2. The administrator ability component is not a valid enterprise administrator ability component.

**Solution**

1. Check that the name of the administrator ability component is included in the application bundle when the application is enabled as a device administrator application.
2. Check that the administrator ability component inherits the **EnterpriseAdminExtensionAbility** component defined by the enterprise device management framework.

## 9200004 Failed to Enable the Device Administrator Application

**Error Message**

Failed to activate the administrator application of the device.

**Description**

This error code is reported when an application fails to be enabled as a device administrator application.

**Possible Causes**

The possible causes are as follows:
1. Multiple applications are enabled as the super device administrator application.
2. The application has been enabled as a device administrator application, but the administrator type has changed.
3. Multiple device administrator ability components are enabled for the same application.

**Solution**

1. Check that only one super device administrator application exists.
2. Check whether the current application has been enabled as a device administrator with a different device administrator type. If yes, disable the device administrator application and try again.
3. Check whether a device administrator ability component has been enabled for the application. Only one device administrator ability component can be enabled for an application.

## 9200005 Failed to Disable the Device Administrator Application

**Error Message**

Failed to deactivate the administrator application of the device.

**Description**

This error code is reported when the application has not been enabled, or when another device administrator application is disabled.

**Possible Causes**

The possible causes are as follows:
1. The application to be disabled has not been enabled.
2. Another administrator application is disabled.

**Solution**

1. Check that the target device administrator application has been enabled.
2. Check that the specified device administrator ability component of the target device administrator application has been enabled.
3. Ensure that the device administrator application to be disabled is the caller itself.

<!--Del-->
## 9200006 Invalid User ID

**Error Message**

The specified user ID is invalid.

**Description**

This error code is reported when the specified user ID does not exist or the specified user ID is different from the caller's user ID.

**Possible Causes**

The possible causes are as follows:
1. The user ID specified for setting a user policy does not exist.
2. The specified user ID is different from the caller user ID.

**Solution**

1. Ensure that the user ID specified for the API is valid.
2. Ensure that the caller user ID and the specified user ID are the same. If the application is a device administrator application, policies cannot be set across users.
<!--DelEnd-->

## 9200007 System Ability Error

**Error Message**

The system ability works abnormally.

**Description**

This error code is reported when the enterprise device management ability is not working properly.

**Possible Causes**

The possible causes are as follows:
1. The EnterpriseAdminAbility is not started.
2. The RPC object for enterprise device management cannot be obtained.
3. Other abilities, on which the EnterpriseAdminAbility depends, are not started, or the RPC object cannot be obtained.
4. A system exception occurs during the running of EnterpriseAdminAbility.

**Solution**

Try again later or restart the device.

## 9200008 Invalid System Subscription Event

**Error Message**

The specified system event is invalid.

**Description**

This error code is reported when the enterprise device management module does not support subscription to the specified event or the specified event is invalid.

**Possible Causes**

The enterprise device management module does not support subscription to the specified event or the specified event is invalid.

**Solution**

Check that the specified event is valid and supported by the enterprise device management module.

## 9200009 Failed to Grant Permissions to an Application

**Error Message**

Failed to grant the permission to the application.

**Description**

This error code is reported when the super device administrator application fails to grant administrator rights to other applications.

**Possible Causes**

The target application is not installed by the administrator.

**Solution**

Check that the target application has been installed by the administrator.

## 9200010 Policy Conflict

**Error Message**

A conflict policy has been configured.

**Description**

This error code is reported when a conflict policy is being delivered.

**Possible Causes**

A conflict policy is defined and to be delivered.

**Solution**

Resolve the conflict, and then deliver the policy.

<!--Del-->
## 9200011 Failed to Replace the Device Administrator Application

**Error Message**

Failed to replace the administrator application of the device.

**Description**

Failed to replace the device administrator application.

**Possible Causes**

The specified application is a delegated or authorized device administrator application or a common device administrator application. It cannot be a super administrator application.

**Solution**

1. Call [disableSuperAdmin](js-apis-enterprise-adminManager-sys.md#adminmanagerdisablesuperadmin) to disable the super device management permission of a specified application.
2. Call [disableAdmin](js-apis-enterprise-adminManager.md#adminmanagerdisableadmin) to disable the common device management permission of a specified application.
<!--DelEnd-->

## 9200012 Parameter Verification Failed

**Error Message**

Parameter verification failed.

**Description**

This error code is returned when the parameter verification fails.

**Possible Causes**

The possible causes are as follows:
1. The passed **EnterpriseAdminExtensionAbility** component does not belong to the current application.
2. The length of the input parameter exceeds the upper limit.
3. The length of the input array exceeds the upper limit.
4. The parameter value is out of the value range.
5. A removal operation is performed on a blocklist or trustlist that has not been set yet.

**Solution**

1. Ensure that the input **EnterpriseAdminExtensionAbility** belongs to the current application.
2. Ensure that the length of the input parameter does not exceed the upper limit.
3. Ensure that the length of the input array does not exceed the upper limit.
4. Ensure that the input parameter value is within the supported value range.
5. Before removing the list, ensure that the corresponding list is set.

## 9200013 Control Not Immediately Effective

**Error Message**

The enterprise management policy has been successfully set, but the function has not taken effect in real time.

**Description**

The enterprise control policy is set successfully, but the control does not take effect immediately.

**Possible Causes**

In external storage management scenarios, disabling external storage may not take effect immediately if files on it are in use. In such cases, the external storage cannot be unmounted right away.

**Solution**

Restart the device for the control to take effect. In external storage management scenarios, disabling external storage takes effect after the device is restarted. The external storage is not automatically loaded.

## 9200014 Failed to Start the Component

**Error Message**

Failed to start the ability.

**Description**

This error code is generated when the component fails to be started.

**Possible Causes**

1. If the list of applications that are forbidden to run is set (for example, by calling the [addDisallowedRunningBundlesSync](js-apis-enterprise-applicationManager.md#applicationmanageradddisallowedrunningbundlessync) API) and the application is in the list, the component fails to be started.
2. If the list of applications that are allowed to run is set (for example, by calling the [addAllowedRunningBundles](js-apis-enterprise-applicationManager.md#applicationmanageraddallowedrunningbundles21) API) and the application is not in the list, the component fails to be started.

**Solution**

1. Remove the application from the list of applications that are forbidden to run, for example, by calling the [removeDisallowedRunningBundlesSync](js-apis-enterprise-applicationManager.md#applicationmanagerremovedisallowedrunningbundlessync) API.
2. Add the application to the list of applications that are allowed to run, for example, by calling the [addAllowedRunningBundles](js-apis-enterprise-applicationManager.md#applicationmanageraddallowedrunningbundles21) API.

## 9200015 Component Not Exist

**Error Message**

The ability does not exist.

**Description**

This error code is generated when a component that does not exist is started.

**Possible Causes**

1. The input **bundleName** and **abilityName** do not exist.
2. The passed component is not visible to the outside.

**Solution**

1. Check whether the values of **bundleName** and **abilityName** in **want** are correct.
2. Check whether the passed component is visible to the outside.

## 9200016 Service Timeout

**Error Message**

Service timeout.

**Description**

This error code is reported when the service times out.

**Possible Causes**

The service times out.

**Solution**

Try again later.

## 9200017 Invalid Self-Activation Credential of the Enterprise Device Administrator

**Error Message**

The self-activation credential of the enterprise device administrator is invalid.

**Description**

This error code is reported when the self-activation credential of the enterprise device administrator is invalid.

**Possible Causes**

1. The enterprise ID does not match.

2. Failed to configure the application's **appidentifier**.

3. The activation credential does not contain mandatory parameters or the certificate chain verification fails.

**Solution**

Ensure that the self-activation credential of the enterprise device administrator is correct.

## 9200018 The Device Is Not an Enterprise Device

**Error Message**

This device is not an enterprise device.

**Description**

The device is not an enterprise device.

**Possible Causes**

The device is not an enterprise device.

**Solution**

Ensure that the device is an enterprise device.

## 9201001 Failed to Manage the Certificate

**Error Message**

Failed to manage the certificate.

**Description**

This error code is reported when the super device administrator application fails to install or uninstall a user certificate.

**Possible Causes**

The user certificate is incorrect.

**Solution**

Check that the user certificate is correct.

## 9201002 Failed to Install the Enterprise Application

**Error Message**

Failed to install the application.

**Description**

This error code is reported when a device administrator application fails to install an enterprise application.

**Possible Causes**

The enterprise application failed to be installed.

If the called API is [bundleManager.install](./js-apis-enterprise-bundleManager.md#bundlemanagerinstall), the possible causes are as follows:
1. The application installation path is empty or invalid, or does not exist.
2. The operation attempts to install multiple apps with different bundle names.
3. The application to be installed already exists when the installation parameter flag is 0.
4. The user ID is invalid.

<!--RP3--><!--RP3End-->

**Solution**

If the called API is [bundleManager.install](./js-apis-enterprise-bundleManager.md#bundlemanagerinstall), perform the following steps:

1. Check that the application installation path is valid.
2. Check that all the installation parameters are valid.
3. Check that the same application is installed.

<!--RP4--><!--RP4End-->

## 9201003 Failed to Add an Account

**Error Message**

Failed to add an OS account.

**Description**

This error code is reported when an account fails to be added.

**Possible Causes**

The possible causes are as follows:

1. The account already exists.
2. The account name is invalid.
3. The network is not connected when the account is added.
4. The system does not support multiple accounts.

**Solution**

1. Check whether the account name exists. If yes, change the account name and try again.
2. Check that the account name is valid.
3. Check that the network is connected when the account is added.

## 9201004 Update Package Not Exist or Fails to be Parsed

**Error Message**

The update packages do not exist or analyzing failed.

**Description**

This error code is reported when the enterprise device administrator application fails to notify the system of the package update.

**Possible Causes**

The possible causes are as follows:

1. The system update package does not exist.
2. The verification of the system update package name fails.
3. The system update package fails to be opened.
4. The system update package fails to be parsed.

**Solution**

1. Check whether the system update package exists.
2. Check whether the name of the system update package is valid.
3. Check whether the system update package is readable.
4. Check whether the system update package is complete.

## 9201005 Failed to Add an Application Kept Alive

**Error Message**

Add keep alive applications failed.

**Description**

This error code is reported when an application kept alive fails to be added.

**Possible Causes**

The possible causes are as follows:

1. The application is not installed.
2. The application does not have the MainAbility.
3. The application does not have the tray service.
4. The application is not added to the tray.
5. The current device does not support adding applications kept alive.

**Solution**

1. Check whether the application is installed.
2. Check whether the application has the MainAbility.
3. Check whether the application has the tray service.
4. Check whether the application has been added to the tray.

## 9201006 Installed Enterprise Re-signing Certificate Exceeding the Limit

**Error Message**

The number of certificates has reached the limit.

**Description**

This error code is reported when the number of installed enterprise re-signing certificates reaches 10.

**Possible Causes**

The number of installed enterprise re-signing certificates reaches the upper limit.

**Solution**

Check whether the number of installed enterprise re-signing certificates reaches 10. If yes, uninstall unnecessary certificates.

## 9201007 Invalid Enterprise Re-signing Certificate

**Error Message**

The certificate is invalid.

**Description**

This error code is generated when the enterprise re-signing certificate fails to be installed.

**Possible Causes**

The enterprise re-signing certificate fails to be installed. The possible causes are as follows:

1. The certificate is invalid.
2. A certificate with the same name has been installed.

**Solution**

1. Check whether the certificate is a valid enterprise re-signing certificate.
2. Check whether a certificate with the same name has been installed.

## 9201008 Enterprise Re-signing Certificate Not Exist

**Error Message**

The certificate does not exist.

**Description**

This error code is generated when the enterprise re-signing certificate fails to be uninstalled.

**Possible Causes**

The uninstalled certificate does not exist.

**Solution**

Check whether the uninstalled certificate exists.

## 9201009 Failed to Create a Log Collection Task

**Error Message**

Collecting logs, please try again later.

**Description**

This error code is generated when a log collection task fails to be created.

**Possible Causes**

When a log collection task is being executed, the [systemManager.startCollectLog](./js-apis-enterprise-systemManager.md#systemmanagerstartcollectlog23) API is called to create a log collection task.

**Solution**

Wait until the previous log collection task is complete (that is, the [EnterpriseAdminExtensionAbility.onLogCollected](js-apis-EnterpriseAdminExtensionAbility.md#onlogcollected23) callback is received), and then call the [systemManager.startCollectLog](./js-apis-enterprise-systemManager.md#systemmanagerstartcollectlog23) API to create a new log collection task.

## 9201010 Failed to Configure the Ethernet Network Interface

**Error Message**

Ethernet configuration failed. Ethernet device not connected.

**Description**

The Ethernet configuration fails, or the Ethernet device is not connected.

**Possible Causes**

The Ethernet configuration fails. The possible causes are as follows:

1. The NIC is not enabled.
2. The NIC name is incorrect.
3. The configuration parameters are incorrect.

**Solution**

1. Check whether the NIC is enabled.
2. Check whether the input NIC name is correct.
3. Check whether the configured parameters are correct.

## 9201011 Invalid Activation Lock Credential

**Error Message**

The credential of the activation lock is invalid.

**Description**

The credential for the activation lock is invalid.

**Possible Causes**

1. The format of the passed activation lock credential is incorrect.
2. The values of fields in the passed activation lock credential are incorrect.
3. The passed activation lock credential does not match the current device.

**Solution**

1. Ensure that the format of the activation lock credential is correct.
2. Ensure that the values of fields in the activation lock credential are correct.
3. Ensure that the activation lock credential is for the current device.

## 9201012 Failed to Enable or Disable Activation Lock

**Error Message**

Failed to enable or disable the activation lock.

**Description**

Failed to disable or enable the activation lock.

**Possible Causes**

<!--RP1-->The device does not support the activation lock service.
<!--RP1End-->

**Solution**

<!--RP2-->Ensure that the device supports the activation lock service.
<!--RP2End-->

## 9201013 Number of Applications in Dock Reaches Maximum

**Error Message**

The number of applications in the Dock has reached the maximum.

**Description**

This error code is reported when an enterprise device administrator fails to add an application to the Dock.

**Possible Causes**

The number of applications in the Dock has reached the maximum.

**Solution**

Delete unnecessary applications from the Dock.

## 9201014 Specified Application Already in Docker

**Error Message**

The application is already in the Dock.

**Description**

This error code is reported when an enterprise device administrator fails to add an application to the Dock.

**Possible Causes**

The specified application has already in the Dock.

**Solution**

Remove the specified application from the Dock and add it to the specified location in the Dock again.

## 9201015 Specified Application Not Installed

**Error Message**

The application is not installed.

**Description**

This error code is reported when the policy of an application needs to be delivered but the application has not been installed.

**Possible Causes**

The specified application has not been installed yet.

**Solution**

Install the specified application and try again.

## 9201016 Specified Application Not in Dock

**Error Message**

The application has not been added to the Dock.

**Description**

This error code is reported when an enterprise device administrator removes an application from the Dock.

**Possible Causes**

The application to be removed is not in the Dock.

**Solution**

Ensure that the package name of the application to be removed from the Dock is correct.

## 9201017 Failed to Enable or Disable the SIM Card

**Error Message**

SIM card activation or deactivation failed.

**Description**

Failed to enable or disable the SIM card.

**Possible Causes**

This error code indicates that the SIM card fails to be enabled or disabled. The possible causes are as follows:

1. The airplane mode is not disabled.
2. No SIM card found.

**Solution**

1. Ensure that the airplane mode is disabled.
2. Ensure that a SIM card is inserted.

## 9201018 Specified Application Inoperable

**Error Message**

The application is inoperable.

**Description**

This error code is reported when an enterprise device administrator fails to add an application to the Dock.

**Possible Causes**

The specified application, such as Application Center, Task Center, Files, Recycle Bin, or an application without an icon, is inoperable.

**Solution**

The specified application cannot be added to the Dock. Add another application.

## 9201019 Specified Location Inoperable

**Error Message**

The location is inoperable.

**Description**

This error code is reported when an enterprise device administrator fails to add an application to the Dock.

**Possible Causes**

If the application in position 0 or 1 in the Dock is Application Center or Task Center, the application at that location cannot be changed.

**Solution**

Add the application to another location.

## 9201020 Failed to Set the Default Mobile Data SIM

**Error Message**

set default data sim failed.

**Description**

Failed to set the default mobile data SIM.

**Possible Causes**

The possible causes are as follows:

1. The airplane mode is not disabled.
2. No SIM card found.

**Solution**

1. Ensure that the airplane mode is disabled.
2. Ensure that a SIM card is inserted.

## 9201021 The Device Has a Screen Lock Password

**Error Message**

A lock screen password has been set for the device.

**Description**

This error code is reported when an enterprise device administrator adds a policy to disable the swipe-to-unlock capability.

**Possible Causes**

A screen lock password has been set on the device. In this case, the device needs to verify the password before accessing the home screen.

**Solution**

Delete the lock screen password.

## 9201022 Application Installation Failure Due to Insufficient System Disk Space

**Error Message**

Failed to install the HAP because of insufficient system disk space.

**Description**

This error code is reported when an application fails to be installed due to insufficient system disk space.

**Possible Causes**

The system disk space is insufficient.

**Solution**

Clear system disk space and try again.

## 9201023 Application Installation Failure Due to Prohibition by Enterprise Device Management

**Error Message**

Failed to install the HAP because enterprise device management disallows the installation.

**Description**

This error code is reported when an application fails to be installed because enterprise device management prohibits the installation.

**Possible Causes**

1. The application is not in the list of applications that can be installed.
2. The application is in the list of applications that are not allowed to be installed.

**Solution**

1. Ensure that the application is in the list of applications that can be installed. Applications not in this list cannot be installed.
2. Ensure that the application is not in the list of applications that are not allowed to be installed. Applications in this list cannot be installed.

## 9201024 Application Installation Failed Due to HAP Parsing Failure

**Error Message**

Failed to install the HAP because the HAP fails to be parsed.

**Description**

This error code is reported when the application fails to be installed due to HAP parsing failure.

**Possible Causes**

The possible causes are as follows:
1. The HAP file is damaged or incomplete.
2. The format of the HAP file is incorrect.
3. The HAP configuration file is incorrect.

**Solution**

1. Ensure that the HAP file is complete and intact.
2. Ensure that the HAP format is correct.
3. Ensure that the HAP configuration file complies with the specifications.

## 9201025 Application Installation Failed Due to HAP Signature Verification Failure

**Error Message**

Failed to install the HAP because the HAP signature fails to be verified.

**Description**

This error code is reported when the application fails to be installed due to HAP signature verification failure.

**Possible Causes**

The possible causes are as follows:
1. The HAP signature is invalid.
2. The HAP signing certificate has expired.
3. The HAP signing certificate is not trusted.

**Solution**

1. Ensure that the HAP signature is valid.
2. Ensure that the HAP signing certificate has not expired.
3. Ensure that the HAP signing certificate is trusted.

## 9201026 Application Installation Failed Due to an Invalid HAP Path or an Extra-Large HAP

**Error Message**

Failed to install the HAP because the HAP path is invalid or the HAP is too large.

**Description**

This error code is reported when the application fails to be installed due to an invalid HAP path or an extra-large HAP.

**Possible Causes**

The possible causes are as follows:
1. The HAP path does not exist or is invalid.
2. The HAP file size exceeds the upper limit.

**Solution**

1. Ensure that the HAP path exists and is valid.
2. Ensure that the size of the HAP file is within the allowed range.

## 9201027 Installation Failed Due to Inconsistent HAP Configuration Information

**Error Message**

Failed to install the HAPs because they have different configuration information.

**Description**

This error code is reported when the installation fails because the configuration information of multiple HAP files are inconsistent.

**Possible Causes**

The configuration information of the HAP files to be installed is inconsistent.

**Solution**

Ensure that the configuration information of the HAP files to be installed is consistent.

## 9201028 Application Installation Failed Due to Unsupported isolationMode Configuration

**Error Message**

Failed to install the HAP because the isolationMode configured is not supported.

**Description**

This error code is reported when the application fails to be installed because **isolationMode** of the HAP is not supported.

**Possible Causes**

**isolationMode** specified for the HAP is not supported by the current system.

**Solution**

Ensure that **isolationMode** set of the HAP is supported by the system.

## 9201029 Application Installation Failed Due to Outdated HAP Version

**Error Message**

Failed to install the HAP since the version of the HAP to install is too early.

**Description**

This error code is reported when the application fails to be installed due to outdated HAP version.

**Possible Causes**

The version of the HAP package to be installed is lower than the version of the installed application.

**Solution**

Use the HAP of a later version for installation.

## 9201030 Application Installation Failed Because VersionCode Is Not Greater Than the Current Version

**Error Message**

Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode.

**Description**

This error code is reported when the installation fails because **VersionCode** of the HAP used for updating is not greater than that of the currently installed version.

**Possible Causes**

**VersionCode** of the HAP used for updating is not greater than that of the installed application.

**Solution**

Ensure that **VersionCode** of the HAP used for updating is greater than that of the installed application.

## 9201031 Application Installation Failed Because the Dependent Module Does Not Exist

**Error Message**

Installation failed because the dependent module does not exist.

**Description**

This error code is reported when the application fails to be installed because the dependent module does not exist.

**Possible Causes**

The module on which the application depends is not installed or does not exist.

**Solution**

Install the dependent module and then install the application.

## 9201032 Specified User Does Not Exist

**Error Message**

The specified user ID is not found.

**Description**

This error code is reported if the specified user ID does not exist.

**Possible Causes**

The specified user ID does not exist in the system.

**Solution**

Ensure that the specified user ID is valid.

For details, see error code 17700004 in [Bundle Management Subsystem Error Codes](../apis-ability-kit/errorcode-bundle.md).

## 9201033 Application Installation Failed Due to Overlay Check Failure

**Error Message**

Failed to install the HAP because the overlay check failed.

**Description**

The target application and the to-be-installed application with the overlay feature are not preset applications, or the target application or target module is one with the overlay feature.

**Possible Causes**

1. To use the overlay feature between applications, the application with the overlay feature must be a preset application.
2. To use the overlay feature between applications, the target application must be a preset application.
3. To use the overlay feature between applications, the target application cannot be an application with the overlay feature.
4. The target module cannot be a module with the overlay feature.

**Solution**

1. Ensure that the application with the overlay feature is a preset application.
2. Ensure that the target application is a preset application.
3. Ensure that the target application is not an application with the overlay feature.
4. Ensure that the target module is not a module with the overlay feature.

## 9201034 Application Installation Failed Due to Lack of Required Permissions in the HSP

**Error Message**

Failed to install the HSP due to missing required permissions.

**Description**

This error code is reported when the HSP fails to be installed due to lack of required permissions.

**Possible Causes**

The HSP does not contain the required permission configuration.

**Solution**

Ensure that the HSP contains all required permission configurations.

## 9201035 Application Installation Failed Because Cross-Application Shared Library Installation Is Not Allowed

**Error Message**

Installation failed because the installation of cross-app shared libraries is not allowed.

**Description**

This error code is reported when the application fails to be installed because the installation of the cross-application shared library is not allowed.

**Possible Causes**

The system does not allow the installation of the cross-application shared library.

**Solution**

Ensure that the installation of the cross-application shared library is allowed in the current scenario.

## 9201036 App Installation Failed Due to Incorrect Data Proxy URI

**Error Message**

Failed to install the HAP due to incorrect URI in the data proxy.

**Description**

This error code is reported when the application fails to be installed due to incorrect data proxy URI.

**Possible Causes**

The URI of the data proxy in the HAP is incorrect.

**Solution**

Ensure that the URI of the data proxy in the HAP is correct.

## 9201037 App Installation Failed Due to Incorrect Data Proxy Permission Configuration

**Error Message**

Failed to install the HAP due to incorrect permission configuration in the data proxy.

**Description**

This error code is reported when the application fails to be installed due to incorrect data proxy permission configuration.

**Possible Causes**

The data proxy permission configuration in the HAP is incorrect.

**Solution**

Ensure that the data proxy permission configuration in the HAP is correct.

## 9201038 Application Installation Failed Due to Code Signature Verification Failure

**Error Message**

Failed to install the HAP due to code signature verification failure.

**Description**

This error code is reported when the application fails to be installed due to code signature verification failure.

**Possible Causes**

The possible causes are as follows:
1. The code signature of the HAP is invalid.
2. The code signing certificate of the HAP is not trusted.

**Solution**

1. Ensure that the code signature of the HAP is valid.
2. Ensure that the code signing certificate of the HAP is trusted.

## 9201039 Application Installation Failed Due to Enterprise Device Verification Failure

**Error Message**

Failed to install the HAP due to enterprise device verification failure.

**Description**

This error code is reported when the application fails to be installed due to enterprise device verification failure.

**Possible Causes**

The possible causes are as follows:
1. The device is not within the enterprise device management scope.
2. The device fails the enterprise device management verification.

**Solution**

Ensure that the device is within the enterprise device management scope and has passed the enterprise device management verification.

## 9201040 System Account Count Has Reached the Upper Limit

**Error Message**

The number of accounts reaches the upper limit.

**Description**

The number of created system accounts has reached the upper limit.

**Possible Causes**

This error code is generated when an attempt is made to create a new system account after the number of system accounts has reached the upper limit.

**Solution**

Check whether the number of created system accounts has reached the upper limit. If so, delete unnecessary system accounts in a timely manner.

## 9201041 System Account Type Restricted

**Error Message**

Restricted account.

**Description**

The system account of the current type does not support this operation.

**Possible Causes**

1. The operation attempts to remove the default system account.
2. Switching to this type of system account is not supported.

**Solution**

Check whether the system account of the current type supports this operation.

## 9201043 Prerequisites for Calling the API Not Met

**Error Message**

Prerequisites for the API call have not been satisfied. For example, distributed outgoing transmission is not disallowed before adding the distributed bidirectional collaboration trustlist.

**Description**

This error code is reported when the prerequisites for calling the API are not met.

**Possible Causes**

Before adding the list of applications allowed for distributed two-way collaboration, the one-way data transmission capability between devices has not been disabled.

**Solution**

Disable the one-way data transmission capability between devices through the [setDisallowedPolicyForAccount](./js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated) API, and then add the list of applications allowed for distributed two-way collaboration.

## 9201044 Specified Permission Not Disabled

**Error Message**

This permission is not disallowed. Applications cannot be added to or removed from the trustlist.

**Description**

This error code is reported when an exception list for a permission is added while the permission itself has not been disabled.

**Possible Causes**

The specified permission has not been disabled before you add an app that is allowed to use the disabled permission to the exception list.

**Solution**

Call the [setDisallowedPermission](./js-apis-enterprise-securityManager.md#securitymanagersetdisallowedpermission) API to disable the specified permission, and then add an exception list for the permission.

## 9201045 Specified Permission Cannot Be Disabled

**Error Message**

This permission cannot be disallowed.

**Description**

This error code is reported when an attempt is made to disable a specified permission.

**Possible Causes**

The APL level of the permission to be disabled is not normal or system_basic.

**Solution**

Ensure that the APL level of the permission to be disabled is normal or system_basic.

## 9201046 Signed-in System Account Count Reached the Upper Limit

**Error Message**

The number of signed-in accounts reaches the upper limit.

**Description**

The number of signed-in system accounts on the current device has reached the upper limit.

**Possible Causes**

The number of created and signed-in system accounts has reached the upper limit.

**Solution**

Try to sign out unnecessary system accounts and promptly remove system accounts that no longer need to be retained.
