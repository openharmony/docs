# AI Image Analyzer Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 110001 AI Image Analysis Not Supported

**Error Message**

AI analysis is unsupported.

**Description**

This error code is reported when **startImageAnalyzer()** is called while AI image analysis is not supported.

**Possible Causes**

An unsupported API is called.

**Solution**

N/A

## 110002 AI Image Analysis in Progress

**Error Message**

AI analysis is ongoing.

**Description**

This error code is reported when **startImageAnalyzer()** is called while the previous analysis session is still ongoing.

**Possible Causes**

The API is called at a wrong time.

**Solution**

N/A
