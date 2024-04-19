# FileShare_PolicyInfo


## Overview

Represents a permission policy, that is, a policy for granting or activating the permission on a file.

**Since**: 12

**Related module**: [FileShare](file_share.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \* [uri](#uri) | Pointer to the URI of the file, on which the permission is to be granted or activated.| 
| unsigned int [length](#length) | Length of the URI, in bytes.| 
| unsigned int [operationMode](#operationmode) | Permission on the URI.| 


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

Permission on the URI.

Example:

- FileShare_OperationMode.READ_MODE

- FileShare_OperationMode.WRITE_MODE

- FileShare_OperationMode.READ_MODE | FileShare_OperationMode.WRITE_MODE


### uri

```
char* FileShare_PolicyInfo::uri
```

**Description**

Pointer to the URI of the file, on which the permission is to be granted or activated.
