# OH_Drawing_RunBuffer


## Overview

The **OH_Drawing_RunBuffer** struct describes a run, which provides storage for glyphs and positions.

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| uint16_t \* [glyphs](#glyphs) | Describes the storage for glyph indexes in the run.|
| float \* [pos](#pos) | Describes the storage for glyph positions in the run.|
| char \* [utf8text](#utf8text) | Describes the storage for UTF-8 encoded text units in the run.|
| uint32_t \* [clusters](#clusters) | Describes the storage for glyph clusters (index of the UTF-8 encoded text unit) in the run.|


## Member Variable Description


### clusters

```
uint32_t* OH_Drawing_RunBuffer::clusters
```

**Description**

Describes the storage for glyph clusters (index of the UTF-8 encoded text unit) in the run.


### glyphs

```
uint16_t* OH_Drawing_RunBuffer::glyphs
```

**Description**

Describes the storage for glyph indexes in the run.


### pos

```
float* OH_Drawing_RunBuffer::pos
```

**Description**

Describes the storage for glyph positions in the run.


### utf8text

```
char* OH_Drawing_RunBuffer::utf8text
```

**Description**

Describes the storage for UTF-8 encoded text units in the run.
