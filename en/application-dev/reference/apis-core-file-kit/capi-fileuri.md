# fileUri
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie-->
<!--SE: @wang_zhangjun; @chenxi0605-->
<!--TSE: @liuhonggang123-->

## Overview

The **FileUri** module provides APIs for manipulating file Uniform Resource Identifiers (URIs).<br> It supports URI-path conversion, validity verification, and conversion of pointed files or paths.<br> It is mainly used to verify the URI format and convert URIs. When files are shared between applications, the application sandbox path is converted into a URI based on specific rules.<br> You must ensure that all input parameters of the API are valid. The converted URI will be output regardless of whether it exists or not.

**System capability**: SystemCapability.FileManagement.AppFileService

**Since**: 12
## Files

| Name| Description|
| -- | -- |
| [oh_file_uri.h](capi-oh-file-uri-h.md) | Provides APIs for URI operations, including performing URI-path conversion, obtaining directory URIs, and verifying URIs.|
