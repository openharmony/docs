# OH_Drawing_RunBuffer

## Overview

This struct describes a run, which provides storage for glyphs and positions.

**Since**: 11

**Related module**: [Drawing](capi-drawing.md)

**Header file**: [drawing_text_blob.h](capi-drawing-text-blob-h.md)

## Summary

### Member Variables

| Name              | Description                                 |
| ------------------ | ------------------------------------- |
| uint16_t* glyphs   | Storage for glyph indexes in the run.                       |
| float* pos         | Storage for glyph positions in the run.                     |
| char* utf8text     | Storage for UTF-8 encoded text units in the run.                  |
| uint32_t* clusters | Storage for glyph clusters (index of the UTF-8 encoded text unit) in the run.|
