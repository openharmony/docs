# AI Image Analyzer Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../../errorcode-universal.md).

## 110001 AI Image Analysis Not Supported

**Error Message**

Image analysis feature is unsupported.

**Description**

This error code is reported when **startImageAnalyzer()** is called while AI image analysis is not supported.

**Possible Causes**

An unsupported API is called.

**Solution**

N/A

## 110002 AI Image Analysis Already In Progress

**Error Message**

Image analysis is currently being executed.

**Description**

This error code is reported when **startImageAnalyzer()** is called while the previous analysis session is still ongoing.

**Possible Causes**

The API is called at an incorrect time.

**Solution**

N/A

## 110003 AI Image Analysis Terminated

**Error Message**

Image analysis is stopped.

**Description**

This error code is reported when **stopImageAnalyzer()** interrupts an ongoing analysis operation initiated by **startImageAnalyzer()**.

**Possible Causes**

The API is called at an incorrect time.

**Solution**

N/A
