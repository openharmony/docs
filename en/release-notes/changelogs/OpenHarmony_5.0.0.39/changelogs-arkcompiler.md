# ArkCompiler Subsystem Changelog

## Fixed the Issue Where App Crashes Might Occur When Mega Functions Are Used

**Access Level**

Other

**Reason for Change**

The source code contains mega functions or classes. In some rare scenarios, incorrect bytecode files are compiled, causing a crash or running error. The crash information is "Reason:Signal:SIGSEGV" or "Segmentation Fault."

**Change Impact**

This change is a non-compatible change.

Before the change, a crash or running error may occur in specific scenarios.

After the change, the issue is resolved.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.39

**Key API/Component Changes**

N/A

**Adaptation Guide**

Update the OpenHarmony SDK to 5.0.0.39 or later, and rebuild the application.
