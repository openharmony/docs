# BackgroundProcessManager

## Overview

The **BackgroundProcessManager** module provides C APIs for managing the scheduling policy of background child processes.

**Since**: 17
## Files

| Name| Description|
| -- | -- |
| [background_process_manager.h](capi-background-process-manager-h.md) | The **background_process_manager.h** file declares the APIs for background child process management. You can use these APIs to suppress and unsuppress child processes to prevent child processes from occupying too many system resources and causing system stuttering. The APIs take effect only for the child processes created through **OH_Ability_StartNativeChildProcess**.|
