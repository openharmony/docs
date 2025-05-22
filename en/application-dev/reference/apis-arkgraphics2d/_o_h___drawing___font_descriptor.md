# OH_Drawing_FontDescriptor


## Overview

The **OH_Drawing_FontDescriptor** struct describes the detailed information about a system font.

**Since**: 12

**Related module**: [Drawing](_drawing.md)

**Header file**: [drawing_text_typography.h](drawing__text__typography_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| char \* [path](#path) | File path of the system font.| 
| char \* [postScriptName](#postscriptname) | PostScript name that uniquely identifies the system font.| 
| char \* [fullName](#fullname) | Full name of the system font.| 
| char \* [fontFamily](#fontfamily) | Family of the system font.| 
| char \* [fontSubfamily](#fontsubfamily) | Subfamily of the system font.| 
| int [weight](#weight) | Weight of the system font.| 
| int [width](#width) | Width of the system font.| 
| int [italic](#italic) | Slope of the system font.| 
| bool [monoSpace](#monospace) | Whether the system font is monospaced. The value **true** means that the system font is monospaced, and **false** means the opposite.| 
| bool [symbolic](#symbolic) | Whether the system font supports symbols. The value **true** means that the system font supports symbols, and **false** means the opposite.| 


## Member Variable Description


### fontFamily

```
char* OH_Drawing_FontDescriptor::fontFamily
```

**Description**

Family of the system font.


### fontSubfamily

```
char* OH_Drawing_FontDescriptor::fontSubfamily
```

**Description**

Subfamily of the system font.


### fullName

```
char* OH_Drawing_FontDescriptor::fullName
```

**Description**

Full name of the system font.


### italic

```
int OH_Drawing_FontDescriptor::italic
```

**Description**

Slope of the system font.


### monoSpace

```
bool OH_Drawing_FontDescriptor::monoSpace
```

**Description**

Whether the system font is monospaced. The value **true** means that the system font is monospaced, and **false** means the opposite.


### path

```
char* OH_Drawing_FontDescriptor::path
```

**Description**

File path of the system font.


### postScriptName

```
char* OH_Drawing_FontDescriptor::postScriptName
```

**Description**

PostScript name that uniquely identifies the system font.


### symbolic

```
bool OH_Drawing_FontDescriptor::symbolic
```

**Description**

Whether the system font supports symbols. The value **true** means that the system font supports symbols, and **false** means the opposite.


### weight

```
int OH_Drawing_FontDescriptor::weight
```

**Description**

Weight of the system font.


### width

```
int OH_Drawing_FontDescriptor::width
```

**Description**

Width of the system font.
