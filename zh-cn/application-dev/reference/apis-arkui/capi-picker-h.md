# picker.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @luoying_ace_admin-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

为NativeNode API提供Picker节点类型定义，支持日期选择器、文本选择器等多种类型的选择器组件，适用于需要在原生层实现滚动选择功能的场景，提供了丰富的样式配置和数据联动能力，帮助开发者灵活构建各类选择交互。

**引用文件：** <arkui/node_attributes/picker.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ARKUI_TextPickerRangeContent](capi-arkui-nativemodule-arkui-textpickerrangecontent.md) | ARKUI_TextPickerRangeContent | 定义单列滑动数据选择器支持的图片资源结构体。 |
| [ARKUI_TextPickerCascadeRangeContent](capi-arkui-nativemodule-arkui-textpickercascaderangecontent.md) | ARKUI_TextPickerCascadeRangeContent | 定义多列联动滑动数据选择器的结构体。 |
| [ArkUI_PickerIndicatorBackground](capi-arkui-nativemodule-arkui-pickerindicatorbackground.md) | ArkUI_PickerIndicatorBackground | 背景样式指示器的样式参数。 |
| [ArkUI_PickerIndicatorDivider](capi-arkui-nativemodule-arkui-pickerindicatordivider.md) | ArkUI_PickerIndicatorDivider | 分割线样式指示器的样式参数。 |
| [ArkUI_PickerIndicatorStyle](capi-arkui-nativemodule-arkui-pickerindicatorstyle.md) | ArkUI_PickerIndicatorStyle | 选中项指示器的样式。 |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md) | ArkUI_TextPickerRangeContentArray | 定义文本选择器的数据选择列表。 |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md) | ArkUI_TextCascadePickerRangeContentArray | 定义多列联动数据选择器的列表。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_DatePickerMode](#arkui_datepickermode) | ArkUI_DatePickerMode | 定义日期选择器列显示模式的枚举值。 |
| [ArkUI_TextPickerRangeType](#arkui_textpickerrangetype) | ArkUI_TextPickerRangeType | 定义滑动选择文本选择器输入类型。 |
| [ArkUI_CalendarAlignment](#arkui_calendaralignment) | ArkUI_CalendarAlignment | 日历选择器与入口组件对齐方式。 |
| [ArkUI_PickerIndicatorType](#arkui_pickerindicatortype) | ArkUI_PickerIndicatorType | 选择器的选中指示器类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [ArkUI_TextPickerRangeContentArray* OH_ArkUI_TextPickerRangeContentArray_Create(int32_t length)](#oh_arkui_textpickerrangecontentarray_create) | 创建TextPickerRangeContent数组的对象，用于构建单列滑动数据选择器的数据列表，常见于日期选择、时间选择、列表选择等场景。创建后必须在使用完毕后调用OH_ArkUI_TextPickerRangeContentArray_Destroy释放资源，否则会导致内存泄漏。 |
| [void OH_ArkUI_TextPickerRangeContentArray_SetIconAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* icon, int32_t index)](#oh_arkui_textpickerrangecontentarray_seticonatindex) | 设置TextPickerRangeContent数组指定位置的icon数据，用于在单列文本选择器中设置带图标的选项，常见于图文混排列表、带图标提示的选项列表等场景。 |
| [void OH_ArkUI_TextPickerRangeContentArray_SetTextAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* text, int32_t index)](#oh_arkui_textpickerrangecontentarray_settextatindex) | 设置TextPickerRangeContent数组指定位置的text数据，用于在数据选择器中设置文本内容，是构建选择器选项的必备步骤。 |
| [void OH_ArkUI_TextPickerRangeContentArray_Destroy(ArkUI_TextPickerRangeContentArray* handle)](#oh_arkui_textpickerrangecontentarray_destroy) | 销毁TextPickerRangeContent数组对象。此方法必须与OH_ArkUI_TextPickerRangeContentArray_Create配对使用，用于释放创建的数组对象资源。 |
| [ArkUI_TextCascadePickerRangeContentArray* OH_ArkUI_TextCascadePickerRangeContentArray_Create(int32_t length)](#oh_arkui_textcascadepickerrangecontentarray_create) | 创建TextCascadePickerRangeContent数组对象，用于构建多列联动数据选择器，常见于年月日联动选择、省市区三级联动选择等场景。创建后必须在使用完毕后调用OH_ArkUI_TextCascadePickerRangeContentArray_Destroy释放资源，否则会导致内存泄漏。 |
| [void OH_ArkUI_TextCascadePickerRangeContentArray_SetTextAtIndex (ArkUI_TextCascadePickerRangeContentArray* handle, char* text, int32_t index)](#oh_arkui_textcascadepickerrangecontentarray_settextatindex) | 设置TextCascadePickerRangeContent数组指定位置的text数据，用于设置多列联动选择器的文本内容。 |
| [void OH_ArkUI_TextCascadePickerRangeContentArray_SetChildAtIndex (ArkUI_TextCascadePickerRangeContentArray* handle, ArkUI_TextCascadePickerRangeContentArray* child, int32_t index)](#oh_arkui_textcascadepickerrangecontentarray_setchildatindex) | 设置TextCascadePickerRangeContent数组指定位置的child数据，用于设置多列联动选择器的子级数据，实现联动效果。 |
| [void OH_ArkUI_TextCascadePickerRangeContentArray_Destroy (ArkUI_TextCascadePickerRangeContentArray* handle)](#oh_arkui_textcascadepickerrangecontentarray_destroy) | 销毁TextCascadePickerRangeContent数组对象。此方法必须与OH_ArkUI_TextCascadePickerRangeContentArray_Create配对使用，用于释放创建的数组对象资源。 |
| [ArkUI_PickerIndicatorStyle* OH_ArkUI_PickerIndicatorStyle_Create(ArkUI_PickerIndicatorType type)](#oh_arkui_pickerindicatorstyle_create) | 创建选中项指示器的样式实例，用于高亮显示用户当前选中的选项，提升用户交互体验。创建后必须在使用完毕后调用OH_ArkUI_PickerIndicatorStyle_Dispose释放资源，否则会导致内存泄漏。 |
| [void  OH_ArkUI_PickerIndicatorStyle_Dispose(ArkUI_PickerIndicatorStyle* style)](#oh_arkui_pickerindicatorstyle_dispose) | 销毁选中项指示器的样式实例。此方法必须与OH_ArkUI_PickerIndicatorStyle_Create配对使用，用于释放创建的样式实例资源。 |

## 枚举类型说明

### ArkUI_DatePickerMode

```c
enum ArkUI_DatePickerMode
```

**描述**

定义日期选择器列显示模式的枚举值。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_DATEPICKER_MODE_DATE = 0 | 默认值。日期列显示年、月、日三列，适用于需要完整日期信息的场景，如出生日期选择、预约日期选择等。 |
| ARKUI_DATEPICKER_YEAR_AND_MONTH = 1 | 日期列显示年、月二列，适用于只需年月信息的场景，如信用卡有效期选择、合同期限选择等。 |
| ARKUI_DATEPICKER_MONTH_AND_DAY = 2 | 日期列显示月、日二列，适用于只需月日信息的场景，如生日选择（不关注年份）、纪念日选择等。 |

### ArkUI_TextPickerRangeType

```c
enum ArkUI_TextPickerRangeType
```

**描述**

定义滑动选择文本选择器输入类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_TEXTPICKER_RANGETYPE_SINGLE = 0 | 单列数据选择器，适用于单列数据选择场景，如性别选择、学历选择等。 |
| ARKUI_TEXTPICKER_RANGETYPE_MULTI = 1 | 多列数据选择器，适用于多列独立数据选择场景，如时间选择（时、分、秒）、日期选择（年、月、日）等。 |
| ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT = 2 | 支持图片资源的单列数据选择器，适用于带图标的单列数据选择场景，如城市选择（带国旗图标）、产品分类选择等。 |
| ARKUI_TEXTPICKER_RANGETYPE_CASCADE_RANGE_CONTENT = 3 | 支持联动的多列数据选择器，适用于多列联动数据选择场景，如省市区三级联动选择、年月日联动选择等。 |

### ArkUI_CalendarAlignment

```c
enum ArkUI_CalendarAlignment
```

**描述**

日历选择器与入口组件对齐方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_CALENDAR_ALIGNMENT_START = 0 | 设置选择器与入口组件的对齐方式为左对齐。 |
| ARKUI_CALENDAR_ALIGNMENT_CENTER = 1 | 设置选择器与入口组件的对齐方式为居中对齐。 |
| ARKUI_CALENDAR_ALIGNMENT_END = 2 | 设置选择器与入口组件的对齐方式为右对齐。 |

### ArkUI_PickerIndicatorType

``` c
enum ArkUI_PickerIndicatorType
```

**描述**

选择器的选中指示器类型。

**起始版本：** 23

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_PICKER_INDICATOR_BACKGROUND  = 0 | 背景样式，适用于需要突出选中项的场景，如深色主题选择器、需要强调选中项的表单选择等。 |
| ARKUI_PICKER_INDICATOR_DIVIDER  = 1 | 分割线样式，适用于需要简洁风格的场景，如轻量级选择器、分割线风格UI设计等。 |

## 函数说明

### OH_ArkUI_TextPickerRangeContentArray_Create()

```c
ArkUI_TextPickerRangeContentArray* OH_ArkUI_TextPickerRangeContentArray_Create(int32_t length)
```

**描述**

创建[ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)数组的对象，用于构建单列滑动数据选择器的数据列表，常见于日期选择、时间选择、列表选择等场景。创建后必须在使用完毕后调用OH_ArkUI_TextPickerRangeContentArray_Destroy释放资源，否则会导致内存泄漏。

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t length | 指定ArkUI_TextPickerRangeContentArray数组的长度。取值必须大于0；传入非正整数或创建失败时返回空指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* | 返回指向ArkUI_TextPickerRangeContentArray数组对象的指针（数组长度由length参数指定）。如果返回空指针，表示创建失败。 |

### OH_ArkUI_TextPickerRangeContentArray_SetIconAtIndex()

```c
void OH_ArkUI_TextPickerRangeContentArray_SetIconAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* icon, int32_t index)
```

**描述**

设置ArkUI_TextPickerRangeContentArray数组指定位置的icon数据，用于在单列文本选择器中设置带图标的选项，常见于图文混排列表、带图标提示的选项列表等场景。

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* handle | 指向ArkUI_TextPickerRangeContentArray数组的指针，需先通过OH_ArkUI_TextPickerRangeContentArray_Create创建。 |
| char* icon | 图标路径，支持相对路径或绝对路径。相对路径相对于应用资源目录。路径必须指向有效的图标资源文件。 |
| int32_t index | 数组索引，取值范围为[0, 数组长度-1]，从0开始。超出范围时不生效。 |

### OH_ArkUI_TextPickerRangeContentArray_SetTextAtIndex()

```c
void OH_ArkUI_TextPickerRangeContentArray_SetTextAtIndex(ArkUI_TextPickerRangeContentArray* handle, char* text, int32_t index)
```

**描述**

设置ArkUI_TextPickerRangeContentArray数组指定位置的text数据，用于在数据选择器中设置文本内容，是构建选择器选项的必备步骤。常见于日期选择器设置日期文本、城市选择器设置城市名称、产品分类选择器设置分类名称等场景。

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* handle | 指向ArkUI_TextPickerRangeContentArray数组的指针，需先通过OH_ArkUI_TextPickerRangeContentArray_Create创建。 |
| char* text | 文本内容。 |
| int32_t index | 数组索引，取值范围为[0, 数组长度-1]，从0开始。超出范围时不生效。 |

### OH_ArkUI_TextPickerRangeContentArray_Destroy()

```c
void OH_ArkUI_TextPickerRangeContentArray_Destroy(ArkUI_TextPickerRangeContentArray* handle)
```

**描述**

销毁ArkUI_TextPickerRangeContentArray数组对象。此方法必须与OH_ArkUI_TextPickerRangeContentArray_Create配对使用，用于释放创建的数组对象资源。

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)* handle | 指向ArkUI_TextPickerRangeContentArray数组的指针。 |

### OH_ArkUI_TextCascadePickerRangeContentArray_Create()

```c
ArkUI_TextCascadePickerRangeContentArray* OH_ArkUI_TextCascadePickerRangeContentArray_Create(int32_t length)
```

**描述**

创建[ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)数组对象，用于构建多列联动数据选择器，常见于年月日联动选择、省市区三级联动选择等场景。创建后必须在使用完毕后调用OH_ArkUI_TextCascadePickerRangeContentArray_Destroy释放资源，否则会导致内存泄漏。

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t length | 指定ArkUI_TextCascadePickerRangeContentArray数组的长度。取值必须大于0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* | 返回指向ArkUI_TextCascadePickerRangeContentArray数组对象的指针（数组长度由length参数指定）。如果返回空指针，表示创建失败。 |

### OH_ArkUI_TextCascadePickerRangeContentArray_SetTextAtIndex()

```c
void OH_ArkUI_TextCascadePickerRangeContentArray_SetTextAtIndex(ArkUI_TextCascadePickerRangeContentArray* handle, char* text, int32_t index)
```

**描述**

设置ArkUI_TextCascadePickerRangeContentArray数组指定位置的text数据，用于设置多列联动选择器的文本内容。常见于省市区三级联动选择器设置省份名称、年月日联动选择器设置年份、品牌车型联动选择器设置品牌名称等场景。

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* handle | 指向ArkUI_TextCascadePickerRangeContentArray数组的指针，需先通过OH_ArkUI_TextCascadePickerRangeContentArray_Create创建。 |
| char* text | 文本内容。 |
| int32_t index | 数组索引，取值范围为[0, 数组长度-1]，从0开始。超出范围时不生效。 |

### OH_ArkUI_TextCascadePickerRangeContentArray_SetChildAtIndex()

```c
void OH_ArkUI_TextCascadePickerRangeContentArray_SetChildAtIndex(ArkUI_TextCascadePickerRangeContentArray* handle, ArkUI_TextCascadePickerRangeContentArray* child, int32_t index)
```

**描述**

设置ArkUI_TextCascadePickerRangeContentArray数组指定位置的child数据，用于设置多列联动选择器的子级数据，实现联动效果。常见于省市区三级联动选择器设置省份对应的市级数据、年月日联动选择器设置月份对应的日期数据、品牌车型联动选择器设置品牌对应的车型列表等场景。

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* handle | 指向ArkUI_TextCascadePickerRangeContentArray数组的指针，需先通过OH_ArkUI_TextCascadePickerRangeContentArray_Create创建。 |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* child | 指向级联选择器指定位置子级数据列表的指针，需先通过OH_ArkUI_TextCascadePickerRangeContentArray_Create创建。 |
| int32_t index | 数组索引，取值范围为[0, 数组长度-1]，从0开始。超出范围时不生效。 |

### OH_ArkUI_TextCascadePickerRangeContentArray_Destroy()

```c
void OH_ArkUI_TextCascadePickerRangeContentArray_Destroy(ArkUI_TextCascadePickerRangeContentArray* handle)
```

**描述**

销毁ArkUI_TextCascadePickerRangeContentArray数组对象。此方法必须与OH_ArkUI_TextCascadePickerRangeContentArray_Create配对使用，用于释放创建的数组对象资源。

**起始版本：** 19

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)* handle | 指向ArkUI_TextCascadePickerRangeContentArray数组的指针。 |

### OH_ArkUI_PickerIndicatorStyle_Create()

``` c
ArkUI_PickerIndicatorStyle* OH_ArkUI_PickerIndicatorStyle_Create(ArkUI_PickerIndicatorType type)
```

**描述**

创建选中项指示器的样式实例，用于高亮显示用户当前选中的选项，提升用户交互体验。创建后必须在使用完毕后调用OH_ArkUI_PickerIndicatorStyle_Dispose释放资源，否则会导致内存泄漏。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_PickerIndicatorType](#arkui_pickerindicatortype) type | 选择器选中项指示器类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [ArkUI_PickerIndicatorStyle](capi-arkui-nativemodule-arkui-pickerindicatorstyle.md)* | ArkUI_PickerIndicatorStyle实例的指针。如果返回空指针，表示创建失败，失败原因可能是地址空间已满或类型不支持。 |

### OH_ArkUI_PickerIndicatorStyle_Dispose()

``` c
void OH_ArkUI_PickerIndicatorStyle_Dispose(ArkUI_PickerIndicatorStyle* style)
```

**描述**

销毁选中项指示器的样式实例。此方法必须与OH_ArkUI_PickerIndicatorStyle_Create配对使用，用于释放创建的样式实例资源。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkUI_PickerIndicatorStyle](capi-arkui-nativemodule-arkui-pickerindicatorstyle.md)* style | 要销毁的[ArkUI_PickerIndicatorStyle](capi-arkui-nativemodule-arkui-pickerindicatorstyle.md)实例。 |
