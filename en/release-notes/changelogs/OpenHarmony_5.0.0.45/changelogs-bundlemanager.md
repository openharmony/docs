# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Encrypted Applications Using Debug-Type Signing Certificates or Encrypted Applications of the Debug Type Cannot Be Installed

**Access Level**

Public API

**Reason for Change**

Encrypted applications using debug-type signing certificates or encrypted applications of the debugging type have security problems, causing information leakage.

**Change Impact**

This change is a non-compatible change.

In normal cases, there is no impact. Applications are encrypted before being released. Locally packaged applications are not encrypted.

Before change:

Encrypted applications with debug-type signing certificates or encrypted applications of the debug type can be successfully installed.

After change:

Encrypted applications with debug-type signing certificates or encrypted applications of the debug type cannot be installed.


**Start API Level**

13

**Change Since**

OpenHarmony SDK 5.0.0.45

**Key API/Component Changes**

N/A

**Adaptation Guide**

1. For an encrypted application with a debug-type signing certificate, sign the application using a release-type certificate before installing it.
2. For an encrypted application of the debugging type, change it to a non-debugging type before installing it.
