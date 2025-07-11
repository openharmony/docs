# FileShare_PolicyErrorResult


## Overview

Represents the permission policy error result.

**Since**: 12

**Related module**: [FileShare](file_share.md)

**Header file**: [oh_file_share.h](oh__file__share_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \* [uri](#uri) | Pointer to the URI, for which the permission fails to be granted or activated. | 
| [FileShare_PolicyErrorCode](file_share.md#fileshare_policyerrorcode) [code](#code) | Error code corresponding to the URI. | 
| char \* [message](#message) | Pointer to the error message. | 


## Member Variable Description


### code

```
FileShare_PolicyErrorCode FileShare_PolicyErrorResult::code
```
**Description**
Error code corresponding to the URI.


### message

```
char* FileShare_PolicyErrorResult::message
```
**Description**
Pointer to the error message.


### uri

```
char* FileShare_PolicyErrorResult::uri
```
**Description**
Pointer to the URI, for which the permission fails to be granted or activated.
