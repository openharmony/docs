# OH_Drawing_FontDescriptor


## 概述

描述系统字体详细信息的结构体。

**起始版本：** 12

**相关模块：**[Drawing](_drawing.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| char \* [path](#path) | 系统字体的文件路径。 | 
| char \* [postScriptName](#postscriptname) | 唯一标识字体的名称。 | 
| char \* [fullName](#fullname) | 系统字体的名称。 | 
| char \* [fontFamily](#fontfamily) | 系统字体的字体家族。 | 
| char \* [fontSubfamily](#fontsubfamily) | 系统字体的子字体家族。 | 
| int [weight](#weight) | 系统字体的粗细程度。 | 
| int [width](#width) | 系统字体的宽窄风格属性。 | 
| int [italic](#italic) | 系统字体倾斜度。 | 
| bool [monoSpace](#monospace) | 系统字体是否紧凑，true表示字体紧凑，false表示字体非紧凑。 | 
| bool [symbolic](#symbolic) | 系统字体是否支持符号字体，true表示支持符号字体，false表示不支持符号字体。 | 


## 结构体成员变量说明


### fontFamily

```
char* OH_Drawing_FontDescriptor::fontFamily
```

**描述**

系统字体的字体家族。


### fontSubfamily

```
char* OH_Drawing_FontDescriptor::fontSubfamily
```

**描述**

系统字体的子字体家族。


### fullName

```
char* OH_Drawing_FontDescriptor::fullName
```

**描述**

系统字体的名称。


### italic

```
int OH_Drawing_FontDescriptor::italic
```

**描述**

系统字体倾斜度。


### monoSpace

```
bool OH_Drawing_FontDescriptor::monoSpace
```

**描述**

系统字体是否紧凑，true表示字体紧凑，false表示字体非紧凑。


### path

```
char* OH_Drawing_FontDescriptor::path
```

**描述**

系统字体的文件路径。


### postScriptName

```
char* OH_Drawing_FontDescriptor::postScriptName
```

**描述**

唯一标识字体的名称。


### symbolic

```
bool OH_Drawing_FontDescriptor::symbolic
```

**描述**

系统字体是否支持符号字体，true表示支持符号字体，false表示不支持符号字体。


### weight

```
int OH_Drawing_FontDescriptor::weight
```

**描述**

系统字体的粗细程度。


### width

```
int OH_Drawing_FontDescriptor::width
```

**描述**

系统字体的宽窄风格属性。
