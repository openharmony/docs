# Video Processing Engine Error Codes

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xjtu_liushang-->
<!--Designer: @changjiuy-->
<!--Tester: @yangwang01-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 29200001 Unknown Error

**Error Message**

Some unknown error occurred, such as GPU calculation failure or memcpy failure. 

**Description**

An unknown error occurs. For example, GPU computation fails or content copy fails.

**Possible Causes**

1. GPU computation fails.
2. Content copy fails.

**Handling Procedure**

1. Check whether the resources have been initialized.
2. Check whether the memory is valid.

## 29200002 Initialization Failure

**Error Message**

The global environment initialization for image processing failed, such as failure to initialize the GPU environment.

**Description**

Initialization of the global environment for image processing fails. For example, GPU environment initialization fails.

**Possible Causes**

GPU initialization fails.

**Handling Procedure**

Check the log for any GPU exceptions.

## 29200003 Creation Failure

**Error Message**

Failed to create image processing instance. For example, the number of instances exceeds the upper limit.

**Description**

Creation of an image processing instance fails. For example, the number of instances exceeds the upper limit.

**Possible Causes**

Too many instances have been created.

**Handling Procedure**

Reduce the number of instances created.

## 29200004 Processing Failure

**Error Message**

Failed to process image buffer. For example, the processing times out.

**Description**

Processing the image buffer fails. For example, processing timed out.

**Possible Causes**

Processing timed out.

**Handling Procedure**

Reduce the load.

## 29200005 Unsupported Operations

**Error Message**

The processing is not supported. You may call OH_ImageProcessing_IsXXXSupported to check whether the capability is supported.

**Description**

The processing is not supported. You can call **OH_ImageProcessing_Is*XXX*Supported** to check whether the capability is supported.

**Possible Causes**

The capability is not supported.

**Handling Procedure**

Check the log for details.

## 29200006 Operation Not Allowed

**Error Message**

The operation is not permitted. This may be caused by incorrect status.

**Description**

The operation is not permitted due to incorrect status.

**Possible Causes**

The status is abnormal.

**Handling Procedure**

Check the log for details.

## 29200007 Insufficient Memory

**Error Message**

Out of memory.

**Description**

The memory is insufficient.

**Possible Causes**

The memory is insufficient.

**Handling Procedure**

Reduce memory allocation.

## 29200008 Invalid Instance

**Error Message**

The image processing instance is invalid. This may be caused by null instance.

**Description**

The image processing instance is invalid, possibly due to a null instance.

**Possible Causes**

Invalid instance.

**Handling Procedure**

Check instance creation.

## 29200009 Invalid Value

**Error Message**

Input value is invalid. This error is returned for all of the following error conditions:
1. Invalid input or output image buffer - The image buffer width(height) is too large or colorspace is incorrect.
2. Invalid parameter - The parameter does not contain valid information, such as detail enhancer level is incorrect.

**Description**

The input value is invalid. This error code is returned for all the following cases:

1. Invalid input or output image buffer: The image buffer width (height) is too large or the color space is incorrect.
2. Invalid parameter: The parameter does not contain valid information (for example, incorrect algorithm level).

**Possible Causes**

1. The input or output resolution is too large or the color space is incorrect.
2. The algorithm level is incorrect.

**Handling Procedure**

1. Check the input and output resolutions and color spaces.
2. Check the algorithm level.
