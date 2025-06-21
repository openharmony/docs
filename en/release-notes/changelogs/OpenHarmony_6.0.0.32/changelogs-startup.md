# Startup Subsystem Changelog
## cl.startup.1 ptrace Available Only in Developer Mode

**Access Level**

Public API

**Reason for the Change**

To further ensure security and privacy, the use of **ptrace** for application debugging is prohibited in non-developer mode when a developer certificate is absent.

**Change Impact**

This change requires application adaptation.

Before change: Third-party applications can call the **ptrace** API in any mode.

After change: Third-party applications can call the **ptrace** API only when the device is in developer mode and the application is compiled in debug mode.

 **Start API Level**

N/A.

**Change Since**

OpenHarmony SDK 6.0.0.32

**Key API/Component Changes**

sys/ptrace.h

**Adaptation Guide**

Apply for a developer certificate for a third-party application, compile the application in debug mode, and call the **ptrace** API when the developer mode is enabled on the device.
