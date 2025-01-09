# ArkCompiler Subsystem Changelog
## cl.arkcompiler.1 Deleted /dev/ubsan/

**Access Level**

Others

**Reason for Change**

1. The **/dev/ubsan** directory on the device is used to archive UBSan logs. With DFX integration, logs are saved to the **/data/log/faultlog/faultlogger** directory. The **/dev/ubsan** directory is no longer required.
2. The **/dev/ubsan** directory cannot isolate read and write permissions among different users, which poses security risks.

**Change Impact**

This change is a non-compatible change.

The **/dev/ubsan** directory can no longer be read or written.

**Change Since**

OpenHarmony 5.0.0.46

**Key API/Component Changes**

Before change: The **/dev/ubsan/** directory can be read and written.

After change: The **/dev/ubsan/** directory cannot be read or written.

**Adaptation Guide**

N/A
