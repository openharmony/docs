# NativeChildProcess_Args

## Overview

The struct describes the parameters passed to the child process.

**Since**: 13

**Related module**: [ChildProcess](capi-childprocess.md)

**Header file**: [native_child_process.h](capi-native-child-process-h.md)

## Summary

### Member Variables

| Name                                         | Description|
|---------------------------------------------| -- |
| char* entryParams                           | Pointer to the entry parameters. The size cannot exceed 150 KB.|
| struct [NativeChildProcess_FdList](capi-nativechildprocess-fdlist.md) fdList | List of file descriptors passed to the child process.|
