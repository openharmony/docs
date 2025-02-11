# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Verifying Signature Consistency When Installing a Preset Application That Has Been Uninstalled

**Access Level**

Public API

**Reason for Change**

After a preset application is uninstalled, an HAP with the same bundle name but different signatures can be installed, which poses security risks.

**Change Impact**

This change is a non-compatible change.

Before change: After a preset application is uninstalled, an HAP with the same bundle name but different signatures can be installed.

After change: After a preset application is uninstalled, an HAP with the same bundle name but different signatures fails to be installed.

**Start API Level**

7

**Change Since**

OpenHarmony 5.0.0.54

**Key API/Component Changes**

Installation command provided by the [bm Tool](https://gitee.com/openharmony/docs/blob/master/en/application-dev/tools/bm-tool.md#installation-command)

**Adaptation Guide**

To install a preset application using the hdc command, the signature of the HAP to install must be the same as that of the preset HAP.
