# native_avsource.h


## Overview

The **native_avsource.h** file declares the native APIs used to construct audio and video resource objects.

**Since**

10

**Related Modules**

[AVSource](_a_v_source.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| \*[OH_AVSource_CreateWithURI](_a_v_source.md#oh_avsource_createwithuri) (char \*uri) | Creates an **OH_AVSource** instance based on a URI.| 
| \*[OH_AVSource_CreateWithFD](_a_v_source.md#oh_avsource_createwithfd) (int32_t fd, int64_t offset, int64_t size) | Creates an **OH_AVSource** instance based on a file descriptor (FD).| 
| [OH_AVSource_Destroy](_a_v_source.md#oh_avsource_destroy) (OH_AVSource \*source) | Destroys an **OH_AVSource** instance and clears internal resources. An instance can be destroyed only once.| 
| \*[OH_AVSource_GetSourceFormat](_a_v_source.md#oh_avsource_getsourceformat) (OH_AVSource \*source) | Obtains the basic information about a media resource.| 
| \*[OH_AVSource_GetTrackFormat](_a_v_source.md#oh_avsource_gettrackformat) (OH_AVSource \*source, uint32_t trackIndex) | Obtains the basic information about a track.| 
