# FileShare_PolicyInfo


## Overview

Represents the permission policy information.

**Since**: 12

**Related module**: [FileShare](file_share.md)

**Header file**: [oh_file_share.h](oh__file__share_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \* [uri](#uri) | Pointer to the URI, on which the permission is to be granted or activated.| 
| unsigned int [length](#length) | Length of the URI, in bytes.| 
| unsigned int [operationMode](#operationmode) | URI operation mode.| 


## Member Variable Description


### length

```
unsigned int FileShare_PolicyInfo::length
```

**Description**

Length of the URI, in bytes.


### operationMode

```
unsigned int FileShare_PolicyInfo::operationMode
```

**Description**

URI operation mode.

Example:

- FileShare_OperationMode.READ_MODE

- FileShare_OperationMode.WRITE_MODE

- FileShare_OperationMode.READ_MODE | FileShare_OperationMode.WRITE_MODE


### uri

```
char* FileShare_PolicyInfo::uri
```

**Description**

Pointer to the URI, on which the permission is to be granted or activated.
