# MetadataOutput_Callbacks


## Overview

The **MetadataOutput_Callbacks** struct defines the callbacks used for metadata output.

**See**

[OH_MetadataOutput_RegisterCallback](_o_h___camera.md#oh_metadataoutput_registercallback)

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [onMetadataObjectAvailable](#onmetadataobjectavailable) | Callback to report the metadata output result.|
| [onError](#onerror) | Callback to report a metadata output error.|


## Member Variable Description


### onError

```
OH_MetadataOutput_OnError MetadataOutput_Callbacks::onError
```

**Description**

Callback to report a metadata output error.


### onMetadataObjectAvailable

```
OH_MetadataOutput_OnMetadataObjectAvailable MetadataOutput_Callbacks::onMetadataObjectAvailable
```

**Description**

Callback to report the metadata output result.
