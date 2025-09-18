# OH_Drawing_String

## Overview

This struct describes a string of characters encoded in UTF-16.

**Since**: 14

**Related module**: [Drawing](capi-drawing.md)

**Header file**: [drawing_types.h](capi-drawing-types-h.md)

## Summary

### Member Variables

| Name            | Description                                         |
| ---------------- | --------------------------------------------- |
| uint8_t* strData | Pointer to a byte array that stores characters in the UTF-16 encoding format.         |
| uint32_t strLen  | Actual length of the string that **strData** points to, in bytes.|
