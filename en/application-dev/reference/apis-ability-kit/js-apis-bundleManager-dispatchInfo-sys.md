# DispatchInfo (System API)

The **DispatchInfo** module provides version information about the **dispatchInfo** struct and dispatch API. The information can be obtained through [freeInstall.getDispatchInfo](js-apis-freeInstall-sys.md#getdispatchinfo).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## DispatchInfo

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.FreeInstall

| Name       | Type  | Readable| Writable| Description                    |
| ----------- | ------ | ---- | ---- | ------------------------ |
| version     | string | Yes  | No  | Version of the **dispatchInfo** struct.|
| dispatchAPIVersion | string | Yes  | No  | Version of the dispatch API.    |
