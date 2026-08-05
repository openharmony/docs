# ArkUI_NodeAttributeType（信息选择类组件相关属性）

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @luoying_ace_admin-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @Brilliantry_Rui-->

```c
enum ArkUI_NodeAttributeType
```

## 概述

定义ArkUI在Native侧可以设置信息选择类组件相关属性样式集合，包含DatePicker、TimePicker、TextPicker、CalendarPicker等组件属性设置。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)


## NODE_DATE_PICKER_LUNAR

```c
NODE_DATE_PICKER_LUNAR = MAX_NODE_SCOPE_NUM * ARKUI_NODE_DATE_PICKER = 13000
```

设置日期选择器组件的日期是否显示农历，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否显示农历，默认值0。0表示不展示农历，1表示展示农历。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否显示农历。返回0表示不展示农历，返回1表示展示农历。 |

## NODE_DATE_PICKER_START

```c
NODE_DATE_PICKER_START = 13001
```

设置日期选择器组件的起始日期，支持属性设置，属性重置和属性获取接口。设置的起始日期会限定日期选择的有效范围，超出范围的选中日期会自动调整。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 日期，默认值"1970-1-1"。格式：年-月-日，年份支持1或4位，月份和日期为1-2位数字。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 设置的起始日期，格式为年-月-日。 |

## NODE_DATE_PICKER_END

```c
NODE_DATE_PICKER_END = 13002
```

设置日期选择器组件的结束日期，支持属性设置，属性重置和属性获取接口。设置的结束日期会限定日期选择的有效范围，超出范围的选中日期会自动调整。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 日期，默认值"2100-12-31"。格式：年-月-日，年份支持1或4位，月份和日期为1-2位数字。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 设置的结束日期，格式为年-月-日。 |

## NODE_DATE_PICKER_SELECTED

```c
NODE_DATE_PICKER_SELECTED = 13003
```

设置日期选择器组件选中项的日期，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 日期，默认值"2024-01-22"，未设置时使用默认值。格式：年-月-日，年份支持1或4位，月份和日期为1-2位数字。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 选中的日期，格式为年-月-日。 |

## NODE_DATE_PICKER_DISAPPEAR_TEXT_STYLE

```c
NODE_DATE_PICKER_DISAPPEAR_TEXT_STYLE = 13004
```

设置日期选择器组件的所有选项中最上和最下两个选项的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。未设置时使用系统默认样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。 |

## NODE_DATE_PICKER_TEXT_STYLE

```c
NODE_DATE_PICKER_TEXT_STYLE = 13005
```

设置日期选择器组件的所有选项中除了边缘项及选中项以外的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。未设置时使用系统默认样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。 |

## NODE_DATE_PICKER_SELECTED_TEXT_STYLE

```c
NODE_DATE_PICKER_SELECTED_TEXT_STYLE = 13006
```

设置日期选择器组件的选中项的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。未设置时使用系统默认样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。 |

## NODE_DATE_PICKER_MODE

```c
NODE_DATE_PICKER_MODE = 13007
```

设置要显示的日期选项列。DatePicker显示不同样式的日期列，支持属性设置，属性重置和属性获取接口。

使用场景：根据应用需求选择合适的日期显示模式，如需要精确选择到日时使用年/月/日模式，只需要月份时使用年/月模式等。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 显示的日期列类型。参数类型[ArkUI_DatePickerMode](capi-picker-h.md#arkui_datepickermode)。默认值：完整的日期列（年、月、日）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 当前设置的日期列类型枚举值，类型为[ArkUI_DatePickerMode](capi-picker-h.md#arkui_datepickermode)。 |

## NODE_DATE_PICKER_ENABLE_HAPTIC_FEEDBACK

```c
NODE_DATE_PICKER_ENABLE_HAPTIC_FEEDBACK = 13008
```

设置是否开启触控反馈。支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否开启触控反馈。1表示开启触控反馈，0表示不开启触控反馈。开启后，是否存在触控反馈取决于系统硬件支持情况。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否开启触控反馈。1表示开启触控反馈，0表示不开启触控反馈。 |

## NODE_DATE_PICKER_CAN_LOOP

```c
NODE_DATE_PICKER_CAN_LOOP = 13009
```

Picker组件可循环滚动属性，支持属性设置，属性重置和属性获取接口。

使用场景：循环滚动适用于选项有限且希望提供快速选择体验的场景（如月份选择）；非循环滚动适用于选项有明确边界、需要限制用户选择范围的场景（如日期选择避免跨年混淆）。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否可循环。1表示可循环，0表示不可循环。默认值：1，设置异常值时使用默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 0表示不可循环，1表示可循环。<br>说明：可循环情况下，年份随着月份的循环滚动进行联动加减，月份随着日的循环滚动进行联动加减。<br>不可循环情况下，年/月/日到达本列的顶部或底部时，无法再进行滚动，年/月/日之间也无法再联动加减。 |

## NODE_TIME_PICKER_SELECTED

```c
NODE_TIME_PICKER_SELECTED = MAX_NODE_SCOPE_NUM * ARKUI_NODE_TIME_PICKER = 14000
```

设置时间选择器组件的选中项时间，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 时间。默认值：当前系统时间。设置格式：时:分或时-分（例：23:59或23-59）。返回格式：时,分,秒（例：23,59,0）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 选中的时间。格式：时,分,秒，使用`,`分隔（例：23,59,0）。 |

## NODE_TIME_PICKER_USE_MILITARY_TIME

```c
NODE_TIME_PICKER_USE_MILITARY_TIME = 14001
```

设置时间选择组件展示时间是否为24小时制，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否为24小时制，默认值：0。0表示展示时间为12小时制，1表示展示时间为24小时制。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否为24小时制。返回0表示展示时间为12小时制（对应false），返回1表示展示时间为24小时制（对应true）。 |

## NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE

```c
NODE_TIME_PICKER_DISAPPEAR_TEXT_STYLE = 14002
```

设置边缘项（以选中项为基准向上或向下的第二项）的文本样式，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。未设置时使用系统默认样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。 |

## NODE_TIME_PICKER_TEXT_STYLE

```c
NODE_TIME_PICKER_TEXT_STYLE = 14003
```

设置时间选择组件所有选项中除了边缘项及选中项以外的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。未设置时使用系统默认样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。 |

## NODE_TIME_PICKER_SELECTED_TEXT_STYLE

```c
NODE_TIME_PICKER_SELECTED_TEXT_STYLE = 14004
```

设置时间选择组件选中项的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。未设置时使用系统默认样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。 |

## NODE_TIME_PICKER_START

```c
NODE_TIME_PICKER_START = 14005
```

设置时间选择器组件的起始时间，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 时间。默认值："0:0"。设置时仅支持时:分，使用`:`或`-`分隔（例：12:59或12-59）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 设置的起始时间。格式：时:分:秒（例：0:0:0）。 |

## NODE_TIME_PICKER_END

```c
NODE_TIME_PICKER_END = 14006
```

设置时间选择器组件的结束时间，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 时间。默认值："23:59"。设置时仅支持时:分，使用`:`或`-`分隔（例：23:59或23-59）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 设置的结束时间。格式：时:分:秒（例：23:59:0）。 |

## NODE_TIME_PICKER_ENABLE_CASCADE

```c
NODE_TIME_PICKER_ENABLE_CASCADE = 14007
```

在设置12小时制时，上午和下午的标识会根据小时数自动切换，支持属性设置、重置和获取；在24小时制时，该参数不生效。

使用场景：适用于需要提供友好的12小时制选择体验的场景，例如用户滚动选择小时时，上午/下午标识自动跟随变化，无需用户手动切换。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 在12小时制时，设置上午和下午的标识是否会根据小时数自动切换，默认值：0。0表示不自动切换，1表示自动切换。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 在12小时制时，上午和下午的标识是否会根据小时数自动切换。返回0表示不自动切换（对应false），返回1表示自动切换（对应true）。 |

## NODE_TEXT_PICKER_OPTION_RANGE

```c
NODE_TEXT_PICKER_OPTION_RANGE = MAX_NODE_SCOPE_NUM * ARKUI_NODE_TEXT_PICKER = 15000
```

设置滑动选择文本选择器的选择列表，支持属性设置，属性重置和属性获取接口。

使用场景：单列选择器适用于单一类别选择（如省份、品牌），多列选择器适用于多个独立类别组合选择（如省-市），多列联动选择器适用于有层级关系的选择场景（如省-市-区，第二列根据第一列自动更新）。需先设置该参数后，才能使用 [NODE_TEXT_PICKER_OPTION_SELECTED](#node_text_picker_option_selected) 和 [NODE_TEXT_PICKER_SELECTED_INDEX](#node_text_picker_selected_index) 设置选中项。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 使用的选择器类型[ArkUI_TextPickerRangeType](capi-picker-h.md#arkui_textpickerrangetype)，默认值为ARKUI_TEXTPICKER_RANGETYPE_SINGLE。ARKUI_TEXTPICKER_RANGETYPE_SINGLE适用于单列选择，ARKUI_TEXTPICKER_RANGETYPE_MULTI适用于多列独立选择，ARKUI_TEXTPICKER_RANGETYPE_RANGE_CONTENT适用于单列带图片选择，ARKUI_TEXTPICKER_RANGETYPE_CASCADE适用于多列联动选择。 |
| ?.string | 针对不同选择器类型有如下输入范式：<br>1：单列选择器，入参格式为用分号分隔的一组字符串；<br>2：多列选择器，支持多对纯文本字符串对，多对之间使用分号分隔，每对内部使用逗号分隔。不传此参数时不设置选择列表。 |
| ?.object | 针对不同选择器类型有如下输入范式：<br>1：单列支持图片的选择器，输入结构体为[ARKUI_TextPickerRangeContentArray](capi-arkui-nativemodule-arkui-textpickerrangecontentarray.md)；<br>2：多列联动选择器，输入结构体为[ARKUI_TextCascadePickerRangeContentArray](capi-arkui-nativemodule-arkui-textcascadepickerrangecontentarray.md)。不传此参数时不设置选择列表。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 使用的选择器类型[ArkUI_TextPickerRangeType](capi-picker-h.md#arkui_textpickerrangetype)。 |
| ?.string | 针对不同选择器类型有如下输出范式：<br>1：单列选择器，输出格式为用分号分隔的一组字符串；<br>2：多列选择器，输出多对纯文本字符串对，多对之间使用分号分隔，每对内部使用逗号分隔。 |

## NODE_TEXT_PICKER_OPTION_SELECTED

```c
NODE_TEXT_PICKER_OPTION_SELECTED = 15001
```

设置滑动选择文本内容的组件默认选中项在数组中的索引值，支持属性设置，属性重置和属性获取接口。需先通过 [NODE_TEXT_PICKER_OPTION_RANGE](#node_text_picker_option_range) 设置选项列表后才能使用该参数。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 默认选中项在选择器选项数组中的索引值，取值范围为[0, length-1]。超出范围时抛出异常。多列选择器时，如存在多个索引值则逐个添加。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 选中项在选择器选项数组中的索引值，如存在多个索引值则逐个添加。 |

## NODE_TEXT_PICKER_OPTION_VALUE

```c
NODE_TEXT_PICKER_OPTION_VALUE = 15002
```

设置滑动选择文本内容的组件默认选中项的值，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 选中项的值，如存在多个值则逐个添加，用分号分隔。默认值：空字符串，未设置时使用默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 选中项的值，如存在多个值则逐个添加，用分号分隔。 |

## NODE_TEXT_PICKER_DISAPPEAR_TEXT_STYLE

```c
NODE_TEXT_PICKER_DISAPPEAR_TEXT_STYLE = 15003
```

设置滑动选择文本内容的组件所有选项中最上和最下两个选项的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型；<br>参数2：文本大小，数字类型，单位fp；<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）；<br>参数4：文本字体列表，使用“,”进行分割；<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。未设置时使用系统默认样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型；<br>参数2：文本大小，数字类型，单位fp；<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）；<br>参数4：文本字体列表，使用“,”进行分割；<br>参数5：文本样式，字符串枚举（“normal”, “italic”）；<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。 |

## NODE_TEXT_PICKER_TEXT_STYLE

```c
NODE_TEXT_PICKER_TEXT_STYLE = 15004
```

设置滑动选择文本内容的组件所有选项中除了最上、最下及选中项以外的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。未设置时使用系统默认样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型。<br>参数2：文本大小，数字类型，单位fp。<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）。<br>参数4：文本字体列表，使用“,”进行分割。<br>参数5：文本样式，字符串枚举（“normal”, “italic”）。<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。 |

## NODE_TEXT_PICKER_SELECTED_TEXT_STYLE

```c
NODE_TEXT_PICKER_SELECTED_TEXT_STYLE = 15005
```

设置滑动选择文本内容的组件选中项的文本颜色、字号、字体粗细，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型；<br>参数2：文本大小，数字类型，单位fp；<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）；<br>参数4：文本字体列表，使用“,”进行分割；<br>参数5：文本样式，字符串枚举（“normal”, “italic”）；<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。未设置时使用系统默认样式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 参数5个，格式为字符串，以“;”分割：<br>参数1：文本颜色，#ARGB类型；<br>参数2：文本大小，数字类型，单位fp；<br>参数3：文本粗细，字符串枚举（“bold”，“normal”，“bolder”，“lighter”，“medium”，“regular”）；<br>参数4：文本字体列表，使用“,”进行分割；<br>参数5：文本样式，字符串枚举（“normal”, “italic”）；<br>如“#ff182431;14;normal;Arial,HarmonyOS Sans;normal”。 |

## NODE_TEXT_PICKER_SELECTED_INDEX

```c
NODE_TEXT_PICKER_SELECTED_INDEX = 15006
```

设置滑动选择文本内容的组件默认选中项的索引数组，支持属性设置，属性重置和属性获取接口。需先通过 [NODE_TEXT_PICKER_OPTION_RANGE](#node_text_picker_option_range) 设置选项列表后才能使用该参数。设置选项列表后，如未通过本参数设置索引数组，则默认选中各列的第1项。<br>
作为属性设置方法参数[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0...].i32 | 默认选中项在选择器选项数组中的索引值数组。用于多列选择器时设置每列的默认选中项索引。默认值：每列均为0。取值范围：每列索引值为[0, 对应列长度-1]，超出范围时抛出异常。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0...].i32 | 当前选中的索引值数组，用于多列选择器时表示每列的选中项索引。 |

## NODE_TEXT_PICKER_CAN_LOOP

```c
NODE_TEXT_PICKER_CAN_LOOP = 15007
```

Picker组件可循环滚动属性，支持属性设置，属性重置和属性获取接口。

使用场景：循环滚动适用于选项有限且希望提供快速选择体验的场景（如省份选择）；非循环滚动适用于选项有明确边界、需要限制用户选择范围的场景（如数量选择避免误操作）。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 0表示不可循环，1表示可循环。默认值：1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 0表示不可循环，1表示可循环。 |

## NODE_TEXT_PICKER_DEFAULT_PICKER_ITEM_HEIGHT

```c
NODE_TEXT_PICKER_DEFAULT_PICKER_ITEM_HEIGHT = 15008
```

设置Picker组件各选择项的高度，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 当前设置的选项高度值，单位为vp。默认值：40.0vp，未设置时使用默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 当前设置的选项高度值，单位为vp。 |

## NODE_TEXT_PICKER_COLUMN_WIDTHS

```c
NODE_TEXT_PICKER_COLUMN_WIDTHS = 15009
```

设置每一个选择项列宽，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 设置的第1个选择项列宽，为总宽度的百分比。默认情况下，所有选择项的列宽相等，默认值为不设置时各列均分。 |
| .value[1]?.f32 | 设置的第2个选择项列宽，为总宽度的百分比。默认情况下，所有选择项的列宽相等。 |
| .value[2]?.f32 | 设置的第3个选择项列宽，为总宽度的百分比。默认情况下，所有选择项的列宽相等。 |
| ... | ... |
| .value[n]?.f32 | 设置的第n+1个选择项列宽，为总宽度的百分比。默认情况下，所有选择项的列宽相等。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 第1列宽度，总宽度的百分比。 |
| .value[1].f32 | 第2列宽度，总宽度的百分比。 |
| .value[2].f32 | 第3列宽度，总宽度的百分比。 |
| ... | ... |
| .value[n].f32 | 第n+1列宽度，总宽度的百分比。 |

## NODE_TEXT_PICKER_ENABLE_HAPTIC_FEEDBACK

```c
NODE_TEXT_PICKER_ENABLE_HAPTIC_FEEDBACK = 15010
```

设置是否开启触控反馈。支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否开启触控反馈。1表示开启触控反馈，0表示不开启触控反馈。开启后，是否存在触控反馈取决于系统硬件支持情况。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否开启触控反馈。1表示开启触控反馈，0表示不开启触控反馈。 |

## NODE_TEXT_PICKER_SELECTED_BACKGROUND_STYLE

```c
NODE_TEXT_PICKER_SELECTED_BACKGROUND_STYLE = 15011
```

设置选中项的背景颜色和边框圆角。支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 背景颜色，采用 0xARGB 格式。其中A表示透明度(0x00完全透明~0xFF完全不透明)，RGB表示颜色值(0x000000~0xFFFFFF)，每个字节取值范围0x00~0xFF。例如，0xFF1122FF表示完全不透明的蓝色。 |
| .value[1].f32 | 左上角的圆角半径，单位为VP。 |
| .value[2].f32 | 右上角的圆角半径，单位为VP。 |
| .value[3].f32 | 左下角的圆角半径，单位为VP。 |
| .value[4].f32 | 右下角的圆角半径，单位为VP。<br>背景颜色默认值：0x0C182431；圆角半径默认值：24.0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 背景颜色，采用 0xARGB 格式，例如，<b>0xFF1122FF</b>。 |
| .value[1].f32 | 左上角的圆角半径，单位为VP。 |
| .value[2].f32 | 右上角的圆角半径，单位为VP。 |
| .value[3].f32 | 左下角的圆角半径，单位为VP。 |
| .value[4].f32 | 右下角的圆角半径，单位为VP。 |

## NODE_PICKER_OPTION_SELECTED_INDEX

```c
NODE_PICKER_OPTION_SELECTED_INDEX = MAX_NODE_SCOPE_NUM * ARKUI_NODE_PICKER
```

定义选择器数据选择范围内默认选中项的索引。支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 索引值。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 选择器数据选择范围内当前选中项的索引。 |

## NODE_PICKER_ENABLE_HAPTIC_FEEDBACK

```c
NODE_PICKER_ENABLE_HAPTIC_FEEDBACK = 1018001
```

定义是否启用触控反馈。支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否启用触控反馈。1表示启用反馈，0表示不启用。默认值：1。开启后，是否存在触控反馈取决于系统硬件支持情况。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否启用触控反馈。1表示启用反馈，0表示不启用。是否存在触控反馈取决于系统硬件支持情况。 |

## NODE_PICKER_CAN_LOOP

```c
NODE_PICKER_CAN_LOOP = 1018002
```

定义选择器是否支持滚动循环。支持属性设置，属性重置和属性获取接口。

使用场景：循环滚动适用于选项有限且希望提供快速选择体验的场景（如性别选择）；非循环滚动适用于选项有明确边界、需要限制用户选择范围的场景。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 是否支持滚动循环。1表示支持滚动循环，0表示不支持。默认值：1。<br>如果子组件的个数小于8个，无论设置为1还是0，都不会循环滚动。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 是否支持滚动循环。返回0表示不支持滚动循环，返回1表示支持滚动循环。 |

## NODE_PICKER_SELECTION_INDICATOR

```c
NODE_PICKER_SELECTION_INDICATOR = 1018003
```

设置选择指示器的类型和参数。支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 23


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .object | 参数类型为[ArkUI_PickerIndicatorStyle](capi-arkui-nativemodule-arkui-pickerindicatorstyle.md)。默认值：<br>{<br>type: PickerIndicatorType.BACKGROUND,<br>borderRadius: {<br>value:12,<br>unit:LengthUnit.vp<br>},<br>backgroundColor: 'sys.color.comp_background_tertiary'<br>}<br>未设置时使用默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .object | 当前设置的选择指示器样式对象，类型为[ArkUI_PickerIndicatorStyle](capi-arkui-nativemodule-arkui-pickerindicatorstyle.md)。 |

## NODE_PICKER_DISPLAYED_ITEM_COUNT

```c
NODE_PICKER_DISPLAYED_ITEM_COUNT = 1018004
```

设置Picker容器可见选项的数量，语义与ArkTS侧[UIPickerComponent](arkui-ts/ts-container-ui-picker-component.md)的[displayedItemCount](arkui-ts/ts-container-ui-picker-component.md#displayeditemcount)一致。未设置时，可见选项为7行。Picker为立体滚轮样式时，除选中项外的选项会按角度旋转，实际可视高度会小于选项行高；若增大可见行数或行高，请相应增大容器高度，详见[UIPickerComponent](arkui-ts/ts-container-ui-picker-component.md)。支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 可见选项数量。取值范围为<b>[2, 9]</b>内的整数。传入小数时按向下取整处理；传入偶数时，会规范为不小于该值的奇数（例如2变为3、8变为9）。不在取值范围内时使用默认值<b>7</b>。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 当前Picker容器可见选项的数量，取值范围为[2, 9]内的整数。 |

## NODE_PICKER_ITEM_HEIGHT

```c
NODE_PICKER_ITEM_HEIGHT = 1018005
```

设置Picker容器每个选项的高度，语义与ArkTS侧[UIPickerComponent](arkui-ts/ts-container-ui-picker-component.md)的[itemHeight](arkui-ts/ts-container-ui-picker-component.md#itemheight)一致。未设置时，每个选项高度为40vp。CAPI以vp为单位传入高度值。支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 26.0.0


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 选项高度，单位为vp。有效范围为<b>[40, 64]</b>。小于40vp或大于64vp时使用默认值<b>40</b>vp。不支持百分比。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 当前选项高度，单位为vp。 |

## NODE_CALENDAR_PICKER_HINT_RADIUS

```c
NODE_CALENDAR_PICKER_HINT_RADIUS = MAX_NODE_SCOPE_NUM * ARKUI_NODE_CALENDAR_PICKER = 16000
```

设置日历选中态底板圆角半径的参数，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].f32 | 日历选中态底板圆角半径，默认值：16.0，单位为vp，表示底板样式为圆形。当输入参数为0.0时表示底板样式为直角矩形；当输入参数为(0.0, 16.0)时，底板样式为圆角矩形；当输入参数为负数或大于16.0时，恢复成默认值16.0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].f32 | 日历选中态底板圆角半径，默认值：16.0，单位为vp，表示底板样式为圆形。取值范围[0.0, 16.0]，其中取值为0.0表示底板样式为直角矩形。 |

## NODE_CALENDAR_PICKER_SELECTED_DATE

```c
NODE_CALENDAR_PICKER_SELECTED_DATE = 16001
```

设置日历选择选中日期的参数，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].u32 | 选中的年。默认值：当前系统年份。传入无效值时使用默认值。 |
| .value[1].u32 | 选中的月。默认值：当前系统月份。传入无效值时使用默认值。 |
| .value[2].u32 | 选中的日。默认值：当前系统日期。传入无效值时使用默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 选中的年。 |
| .value[1].u32 | 选中的月。 |
| .value[2].u32 | 选中的日。 |

## NODE_CALENDAR_PICKER_EDGE_ALIGNMENT

```c
NODE_CALENDAR_PICKER_EDGE_ALIGNMENT = 16002
```

设置日历选择器与入口组件的对齐方式，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 对齐方式类型，参数类型[ArkUI_CalendarAlignment](capi-picker-h.md#arkui_calendaralignment)。用于设置日历选择器相对入口组件的对齐位置。 |
| .value[1]?.f32 | 按照对齐方式对齐后，选择器相对入口组件的x轴方向相对偏移，单位为vp。默认值：0。 |
| .value[2]?.f32 | 按照对齐方式对齐后，选择器相对入口组件的y轴方向相对偏移，单位为vp。默认值：0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 对齐方式类型，参数类型[ArkUI_CalendarAlignment](capi-picker-h.md#arkui_calendaralignment)。 |
| .value[1].f32 | 按照对齐方式对齐后，选择器相对入口组件的x轴方向相对偏移，单位为vp。 |
| .value[2].f32 | 按照对齐方式对齐后，选择器相对入口组件的y轴方向相对偏移，单位为vp。 |

## NODE_CALENDAR_PICKER_TEXT_STYLE

```c
NODE_CALENDAR_PICKER_TEXT_STYLE = 16003
```

设置日历选择器入口区的文本颜色、字号、字体粗细。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0]?.u32 | 入口区的文本颜色。未设置或执行resetAttribute后，使用系统主题 `calendar_picker_entry_font_color` 解析的值（具体色值随主题变化，可通过getAttribute获取）。 |
| .value[1]?.f32 | 入口区的文本字号，单位为fp。未设置或执行resetAttribute后，使用系统主题 `calendar_picker_entry_font_size` 解析的值（具体数值随主题变化，可通过getAttribute获取）。 |
| .value[2]?.i32 | 入口区的文本字体粗细，参数类型[ArkUI_FontWeight](capi-text-h.md#arkui_fontweight)。未设置或执行resetAttribute后，默认值为ARKUI_FONT_WEIGHT_NORMAL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].u32 | 入口区的文本颜色。 |
| .value[1].f32 | 入口区的文本字号，单位为fp。 |
| .value[2].i32 | 入口区的文本字体粗细，参数类型[ArkUI_FontWeight](capi-text-h.md#arkui_fontweight)。 |

## NODE_CALENDAR_PICKER_START

```c
NODE_CALENDAR_PICKER_START = 16004
```

设置日历选择器的开始日期，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 日期。格式：年-月-日，年份支持1或4位，月份和日期为1-2位数字，如"1970-1-1"、"2024-05-20"。默认值：1970-1-1。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 设置的日历选择器开始日期，格式为年-月-日。 |

## NODE_CALENDAR_PICKER_END

```c
NODE_CALENDAR_PICKER_END = 16005
```

设置日历选择器的结束日期，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 日期。格式：年-月-日，年份支持1或4位，月份和日期为1-2位数字，如"2100-12-31"、"2025-1-25"。默认值："2100-12-31"。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 设置的日历选择器结束日期，格式为年-月-日。 |

## NODE_CALENDAR_PICKER_DISABLED_DATE_RANGE

```c
NODE_CALENDAR_PICKER_DISABLED_DATE_RANGE = 16006
```

设置日历选择器的禁用日期区间，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .string | 禁用日期区间字符串。禁用日期区间："第一个区间开始日期，第一个区间结束日期，第二个区间开始日期，第二个区间结束日期，……，第n个区间开始日期，第n个区间结束日期"。<br>设置的禁用日期区间格式："1910-01-01,1910-12-31,2020-01-01,2020-12-31"。默认值：空字符串，表示不设置禁用日期区间。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .string | 设置的禁用日期区间字符串，格式为"开始日期,结束日期,..."，如"1910-01-01,1910-12-31"。 |

## NODE_CALENDAR_PICKER_MARK_TODAY

```c
NODE_CALENDAR_PICKER_MARK_TODAY = 16007
```

设置日历选择器在系统当前日期时，是否保持高亮显示，支持属性设置，属性重置和属性获取接口。<br>
作为属性设置方法参数、属性获取方法返回值[ArkUI_AttributeItem](capi-arkui-nativemodule-arkui-attributeitem.md)格式如下。<br>

**起始版本：** 19


**参数：**

| 参数项 | 描述 |
| -- | -- |
| .value[0].i32 | 日历选择器在系统当前日期时，是否保持高亮显示。返回0表示不保持高亮显示，返回1表示保持高亮显示。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| .value[0].i32 | 日历选择器在系统当前日期时，是否保持高亮显示。 |
