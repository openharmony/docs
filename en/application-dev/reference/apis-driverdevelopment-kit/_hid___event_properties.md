# Hid_EventProperties


## Overview

Defines the event properties of a device.

**Since**

11

**Related module**

[HID DDK](_hid_ddk.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [hidEventTypes](#hideventtypes) | Array of event types.| 
| [hidKeys](#hidkeys) | Array of key codes.| 
| [hidAbs](#hidabs) | Array of absolute coordinates.| 
| [hidRelBits](#hidrelbits) | Array of relative coordinates.| 
| [hidMiscellaneous](#hidmiscellaneous) | Array of miscellaneous events.| 
| [hidAbsMax](#hidabsmax) | Maximum values of the absolute coordinates.| 
| [hidAbsMin](#hidabsmin) | Minimum values of the absolute coordinates.| 
| [hidAbsFuzz](#hidabsfuzz) | Fuzzy values of the absolute coordinates.| 
| [hidAbsFlat](#hidabsflat) | Fixed values of the absolute coordinates.| 


## Member Variable Description


### hidEventTypes


```
struct Hid_EventTypeArray Hid_EventProperties::hidEventTypes
```

**Description**

Array of event types.


### hidKeys


```
struct Hid_KeyCodeArray Hid_EventProperties::hidKeys
```

**Description**

Array of key codes.


### hidAbs


```
struct Hid_AbsAxesArray Hid_EventProperties::hidAbs
```

**Description**

Array of absolute coordinates.


### hidRelBits


```
struct Hid_RelAxesArray Hid_EventProperties::hidRelBits
```

**Description**

Array of relative coordinates.


### hidMiscellaneous


```
struct Hid_MscEventArray Hid_EventProperties::hidMiscellaneous
```

**Description**

Array of miscellaneous events.


### hidAbsMax


```
int32_t Hid_EventProperties::hidAbsMax[64]
```

**Description**

Maximum values of the absolute coordinates.


### hidAbsMin


```
int32_t Hid_EventProperties::hidAbsMin[64]
```

**Description**

Minimum values of the absolute coordinates.


### hidAbsFuzz


```
int32_t Hid_EventProperties::hidAbsFuzz[64]
```

**Description**

Fuzzy values of the absolute coordinates.


### hidAbsFlat


```
int32_t Hid_EventProperties::hidAbsFlat[64]
```

**Description**

Fixed values of the absolute coordinates.
