# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Prohibiting the Installation of Applications Without Code Signatures

**Access Level**

System API

**Reason for Change**

Applications without code signatures can be installed but cannot run on the device. This breaches the device regulatory measures for managing the installation of applications lacking code signatures.

**Change Impact**

This change is a non-compatible change.

Before change:

Applications without code signatures can be installed but cannot run.

After change:

Applications without code signatures fail to be installed, and the related installation API returns error code 17700048.


**Start API Level**

13

**Change Since**

OpenHarmony SDK 5.0.0.50

**Key API/Component Changes**

N/A

**Adaptation Guide**

Sign the application code and try again.

## cl.bundlemanager.2 Enhanced the Installation Process to Include Signature Consistency Verification for Applications with Their Databases Preserved During Uninstallation

**Access Level**

System API

**Reason for Change**

If an application is uninstalled but its data is kept, and a new application with the same bundle name is later installed, it is necessary to check that the identity details match. If **appId** and **appIdentifier** do not match for both the uninstalled and newly installed applications, the installation fails.

**Change Impact**

This change is a non-compatible change.

Before change:

If an application is uninstalled but its data is kept, a new application with the same bundle name but different identity information can be installed.

After change:

If an application is uninstalled but its data is kept, a new application with the same bundle name but different identity information cannot be installed. The related installation API returns error code 17700073.


**Start API Level**

13

**Change Since**

OpenHarmony SDK 5.0.0.50

**Key API/Component Changes**

N/A

**Adaptation Guide**

If an application is uninstalled but its data is kept, a new application with the same bundle name but different signature information fails to be installed. To install the new application, you must first reinstall the uninstalled application and uninstall it without retaining the data.
