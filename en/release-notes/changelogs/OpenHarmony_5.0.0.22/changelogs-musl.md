# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Field __unused in the stat, shminfo, msqid_ds, icmphdr, mq_attr, and utmpx Structs Is Renamed __unused1

**Access Level**

Public API

**Change Reason**

The **__unused** field in the **stat**, **shminfo**, **msqid_ds**, **icmphdr**, **mq_attr**, and **utmpx** structs conflicts with the **__unused** macro definition in **sys/cdefs.h**. If both of them are imported, a build error is reported.

**Change Impact**

This change is a non-compatible change.

In API version 11 and earlier versions, the **__unused** field in the preceding structs can be used normally.

In API version 12 and later versions, a build error is reported when the **__unused** field in the preceding structs is used. You need to change the **__unused** field to **__unused1**.

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.0.0.22

**Key API/Component Changes**

Structs **stat**, **shminfo**, **msqid_ds**, **icmphdr**, **mq_attr**, and **utmpx**

**Adaptation Guide**

If the **__unused** field in the preceding structs is used, change it to **__unused1**.

If the field is not used, no adaptation is required.

The **__unused** macro definition in **cdefs.h** is not affected.
