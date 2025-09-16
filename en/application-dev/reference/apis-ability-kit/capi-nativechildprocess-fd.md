# NativeChildProcess_Fd

## Overview

The struct describes the information about the file descriptor passed to the child process.

**Since**: 13

**Related module**: [ChildProcess](capi-childprocess.md)

**Header file**: [native_child_process.h](capi-native-child-process-h.md)

## Summary

### Member Variables

| Name                                    | Description|
|----------------------------------------| -- |
| char* fdName                           | Pointer to the name of the file descriptor. It contains a maximum of 20 characters.|
| int32_t fd                             | Value of the file descriptor.|
| struct [NativeChildProcess_Fd](capi-nativechildprocess-fd.md)* next | Pointer to the next file descriptor.|
