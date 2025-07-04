# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Verifying Signature Consistency When Installing a Preset Application That Has Been Uninstalled

**Access Level**

Public API

**Reason for Change**

After a preset application is uninstalled, an application with the same bundle name but different signature information can be installed, which poses security risks.

**Change Impact**

This change is a non-compatible change.

Before change: After a preset application is uninstalled, an application with the same bundle name but different keys and APP ID in the signature information can be installed.

After change: After a preset application is uninstalled, an application with the same bundle name but different keys and APP ID in the signature information fails to be installed.

**Start API Level**

7

**Change Since**

OpenHarmony 5.0.0.54

**Key API/Component Changes**

Installation command provided by the [bm Tool](https://gitee.com/openharmony/docs/blob/master/en/application-dev/tools/bm-tool.md#installation-command)

**Adaptation Guide**

1. Re-sign the application to ensure that either the (https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section462703710326) or [APP ID](https://developer.huawei.com/consumer/en/doc/app/agc-help-createharmonyapp-0000001945392297) in the application's signature information matches that of the preset application.
2. Modify the [bundleName](https://gitee.com/openharmony/docs/blob/master/en/application-dev/quick-start/app-configuration-file.md) of the application to make it different from that of the preset application.

## cl.bundlemanager.2 Command bm uninstall Cannot Directly Uninstall Applications with App Lock

**Access Level**

System API

**Reason for Change**

For security management reasons, a new app lock feature has been introduced. The **bm uninstall** command now requires unlocking or disabling the app lock before it can uninstall an application that has an app lock set.

**Change Impact**

This change does not require application adaptation.

Before the change:

The **bm uninstall** command can directly uninstall an application without additional handling.

After the change:

The **bm uninstall** command fails to uninstall an application if the application has an app lock set.

**Start API Level**

API 6

**Change Since**

OpenHarmony 5.0.0.54

**Key API/Component Changes**

bm uninstall command

**Adaptation Guide**

Before using the **bm uninstall** command to uninstall an application with an app lock, use [deleteUninstallDisposedRule](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-ability-kit/js-apis-appControl-sys.md#appcontroldeleteuninstalldisposedrule15) to disable the app lock. For a terminal device, you can also disable the app lock on the **Settings > Privacy & security > App lock** screen of the device. Alternatively, enter the password to unlock the app lock when prompted after executing the uninstall command.
