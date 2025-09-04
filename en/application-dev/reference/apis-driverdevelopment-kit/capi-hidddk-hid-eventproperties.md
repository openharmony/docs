# Hid_EventProperties
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

## Overview

Defines a struct for the event properties of a device.

**Since**: 11

**Related module**: [HidDdk](capi-hidddk.md)

**Header file:** [hid_ddk_types.h](capi-hid-ddk-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| struct Hid_EventTypeArray hidEventTypes | Array of event types.|
| struct Hid_KeyCodeArray hidKeys | Array of key codes.|
| struct Hid_AbsAxesArray hidAbs | Array of absolute coordinate properties.|
| struct Hid_RelAxesArray hidRelBits | Array of relative coordinate properties.|
| struct Hid_MscEventArray hidMiscellaneous | Array of miscellaneous events.|
| int32_t hidAbsMax[64] | Maximum values of the absolute coordinates.|
| int32_t hidAbsMin[64] | Minimum values of the absolute coordinates.|
| int32_t hidAbsFuzz[64] | Fuzzy values of the absolute coordinates.|
| int32_t hidAbsFlat[64] | Fixed values of the absolute coordinates.|
