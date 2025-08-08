# FileShare_PolicyInfo
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie; @hongjin-li_admin-->
<!--SE: @chenxi0605; @JerryH1011-->
<!--TSE: @leiyuqian-->

## Overview

Represents the permission policy information.

**Since**: 12

**Related module**: [fileShare](capi-fileshare.md)

**Header file**: [oh_file_share.h](capi-oh-file-share-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| char* uri | Pointer to the URI, on which the permission is to be granted or activated.|
| unsigned int length | Length of the URI, in bytes.|
| unsigned int operationMode | URI operation mode.<br> Example:<br>FileShare_OperationMode.READ_MODE<br>FileShare_OperationMode.WRITE_MODE<br> Or FileShare_OperationMode.READ_MODE\|FileShare_OperationMode.WRITE_MODE| |
