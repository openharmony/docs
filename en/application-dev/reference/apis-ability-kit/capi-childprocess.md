# ChildProcess

## Overview

The module provides APIs to manage child processes. You can call the APIs to create a native child process and establish an IPC channel between the parent and child processes to implement multi-process application development.

The created child process does not support the UI or the calling of context-related APIs. A maximum of 512 child processes can be started through this module and [childProcessManager](js-apis-app-ability-childProcessManager.md) (in non-SELF_FORK mode).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 12

## Files

| Name| Description|
| -- | -- |
| [native_child_process.h](capi-native-child-process-h.md) | Declares the APIs used to create a native child process and establish an IPC channel between the main process and child process.<br>File to include: <AbilityKit/native_child_process.h><br>Library: libchild_process.so|
