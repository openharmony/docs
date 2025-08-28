# NativeChildProcess_FdList

## Overview

The struct describes a list of file descriptors passed to the child process. The list can contain a maximum of 16 entries.

**Since**: 13

**Related module**: [ChildProcess](capi-childprocess.md)

**Header file**: [native_child_process.h](capi-native-child-process-h.md)

## Summary

### Member Variables

| Name                                    | Description|
|----------------------------------------| -- |
| struct [NativeChildProcess_Fd](capi-nativechildprocess-fd.md)* head | Pointer to the first file descriptor in the linked list passed to the child process.|
