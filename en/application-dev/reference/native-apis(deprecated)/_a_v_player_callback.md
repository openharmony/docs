# AVPlayerCallback


## Overview

The **AVPlayerCallback** struct defines all the callback function pointers of an **OH_AVPlayer** instance. To ensure the normal running of **OH_AVPlayer**, you must register the instance of this struct with the **OH_AVPlayer** instance and process the information reported by the callback functions.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Related module**: [AVPlayer](_a_v_player.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [onInfo](_a_v_player.md#oninfo) | Defines the AVPlayer process information. For details, see [OH_AVPlayerOnInfo](_a_v_player.md#oh_avplayeroninfo).| 
| [onError](_a_v_player.md#onerror) | Defines the AVPlayer error information. For details, see [OH_AVPlayerOnError](_a_v_player.md#oh_avplayeronerror).| 
