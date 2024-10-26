# Ability Subsystem Changelog

## cl.ability.1 Added a Restriction to childProcessManager to Limit the Maximum Number of Child Processes Allowed

**Access Level**

Public API

**Reason for Change**

There is a potential risk of malicious calls when applications can initiate an unlimited number of child processes, so it is necessary to set a restriction on the number of child processes allowed.

**Change Impact**

This change is a non-compatible change.

Before change: The total number of child processes that can be started by an application through **childProcessManager** is not limited.

After change: An application can start a maximum of 512 child processes through **childProcessManager** (non-SELF_FORK mode).

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.1.1

**Key API/Component Changes**

**startChildProcess** (non-SELF_FORK mode) and **startArkChildProcess** in **childProcessManager**

**Adaptation Guide**

No adaptation is required. An application can start a maximum of 512 child processes through **childProcessManager**. When the maximum number is reached, no more child processes can be started.
