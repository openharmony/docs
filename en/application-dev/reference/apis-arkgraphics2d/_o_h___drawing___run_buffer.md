# OH_Drawing_RunBuffer


## Overview

The OH_Drawing_RunBuffer struct describes a run, which provides storage for glyphs and positions.

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| uint16_t \* [glyphs](#glyphs) | Storage for glyph indexes in the run. |
| float \* [pos](#pos) | Storage for glyph positions in the run. |
| char \* [utf8text](#utf8text) | Storage for UTF-8 encoded text units in the run. |
| uint32_t \* [clusters](#clusters) | Storage for glyph clusters (index of the UTF-8 encoded text unit) in the run. |


## Member Variable Description


### clusters

```
uint32_t* OH_Drawing_RunBuffer::clusters
```
**Description**

Storage for glyph clusters (index of the UTF-8 encoded text unit) in the run.


### glyphs

```
uint16_t* OH_Drawing_RunBuffer::glyphs
```
**Description**

Storage for glyph indexes in the run.


### pos

```
float* OH_Drawing_RunBuffer::pos
```
**Description**

Storage for glyph positions in the run.


### utf8text

```
char* OH_Drawing_RunBuffer::utf8text
```
**Description**

Storage for UTF-8 encoded text units in the run.
