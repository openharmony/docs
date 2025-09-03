# Node-API接口返回状态码介绍
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## 概述

绝大部分Node-API接口在执行结束后，会返回一个数据类型为napi_status的状态码枚举，表示操作成功与否的相关信息。本文将重点介绍Node-API接口返回的非napi_ok的状态码详情与修复建议。

## 各Node-API接口返回的非napi_ok状态码介绍

| 接口名称 | 接口功能 | 可能返回的非napi_ok状态码 | 原因 | 修复建议 |
| ------- | ------- | ------------------------ | ---- | ------- |
| napi_module_register | napi native模块注册接口。 | 不涉及 | 不涉及 | 不涉及 |
| napi_get_last_error_info | 获取napi_extended_error_info结构体，其中包含最近一次出现的error信息。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_last_error_info | 获取napi_extended_error_info结构体，其中包含最近一次出现的error信息。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_throw | 抛出一个js value。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_throw | 抛出一个js value。 | napi_invalid_arg | 入参error为nullptr | 确保入参正确 |
| napi_throw | 抛出一个js value。 | napi_invalid_arg | 入参error不为js Error类型 | 确保入参正确 |
| napi_throw_error | 抛出一个带文本信息的js Error。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_throw_error | 抛出一个带文本信息的js Error。 | napi_invalid_arg | 入参msg为nullptr | 确保入参正确 |
| napi_throw_type_error | 抛出一个带文本信息的js TypeError。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_throw_type_error | 抛出一个带文本信息的js TypeError。 | napi_invalid_arg | 入参msg为nullptr | 确保入参正确 |
| napi_throw_range_error | 抛出一个带文本信息的js RangeError。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_throw_range_error | 抛出一个带文本信息的js RangeError。 | napi_invalid_arg | 入参msg为nullptr | 确保入参正确 |
| napi_is_error | 判断napi_value是否表示为一个error对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_is_error | 判断napi_value是否表示为一个error对象。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_is_error | 判断napi_value是否表示为一个error对象。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_error | 创建并获取一个带文本信息的js Error。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_error | 创建并获取一个带文本信息的js Error。 | napi_invalid_arg | 入参msg为nullptr | 确保入参正确 |
| napi_create_error | 创建并获取一个带文本信息的js Error。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_error | 创建并获取一个带文本信息的js Error。 | napi_invalid_arg | 入参code不为nullptr，但不为js String或js Number类型 | 确保入参正确 |
| napi_create_error | 创建并获取一个带文本信息的js Error。 | napi_invalid_arg | 入参msg不为nullptr，但不为js String类型 | 确保入参正确 |
| napi_create_type_error | 创建并获取一个带文本信息的js TypeError。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_type_error | 创建并获取一个带文本信息的js TypeError。 | napi_invalid_arg | 入参msg为nullptr | 确保入参正确 |
| napi_create_type_error | 创建并获取一个带文本信息的js TypeError。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_type_error | 创建并获取一个带文本信息的js TypeError。 | napi_invalid_arg | 入参code不为nullptr，但不为js String或js Number类型 | 确保入参正确 |
| napi_create_type_error | 创建并获取一个带文本信息的js TypeError。 | napi_invalid_arg | 入参msg不为nullptr，但不为js String类型 | 确保入参正确 |
| napi_create_range_error | 创建并获取一个带文本信息的js RangeError。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_range_error | 创建并获取一个带文本信息的js RangeError。 | napi_invalid_arg | 入参msg为nullptr | 确保入参正确 |
| napi_create_range_error | 创建并获取一个带文本信息的js RangeError。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_range_error | 创建并获取一个带文本信息的js RangeError。 | napi_invalid_arg | 入参code不为nullptr，但不为js String或js Number类型 | 确保入参正确 |
| napi_create_range_error | 创建并获取一个带文本信息的js RangeError。 | napi_invalid_arg | 入参msg不为nullptr，但不为js String类型 | 确保入参正确 |
| napi_get_and_clear_last_exception | 获取并清除最近一次出现的异常。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_and_clear_last_exception | 获取并清除最近一次出现的异常。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_is_exception_pending | 判断是否出现了异常。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_is_exception_pending | 判断是否出现了异常。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_fatal_error | 引发致命错误以立即终止进程。 | 不涉及 | 不涉及 | 不涉及 |
| napi_open_handle_scope | 创建一个上下文环境使用。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_open_handle_scope | 创建一个上下文环境使用。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_close_handle_scope | 关闭传入的上下文环境，关闭后，全部在其中声明的引用都将被关闭。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_close_handle_scope | 关闭传入的上下文环境，关闭后，全部在其中声明的引用都将被关闭。 | napi_invalid_arg | 入参scope为nullptr | 确保入参正确 |
| napi_close_handle_scope | 关闭传入的上下文环境，关闭后，全部在其中声明的引用都将被关闭。 | napi_handle_scope_mismatch | napi_open_handle_scope调用次数小于napi_close_handle_scope | napi_open_handle_scope和napi_close_handle_scope需要成对使用 |
| napi_open_escapable_handle_scope | 创建出一个可逃逸的handle scope，可将范围内声明的值返回到父作用域。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_open_escapable_handle_scope | 创建出一个可逃逸的handle scope，可将范围内声明的值返回到父作用域。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_close_escapable_handle_scope | 关闭传入的可逃逸的handle scope。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_close_escapable_handle_scope | 关闭传入的可逃逸的handle scope。 | napi_invalid_arg | 入参scope为nullptr | 确保入参正确 |
| napi_close_escapable_handle_scope | 关闭传入的可逃逸的handle scope。 | napi_handle_scope_mismatch | napi_open_escapable_handle_scope调用次数小于napi_close_escapable_handle_scope | napi_open_escapable_handle_scope和napi_close_escapable_handle_scope需要成对使用 |
| napi_escape_handle | 提升传入的js object的生命周期到其父作用域。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_escape_handle | 提升传入的js object的生命周期到其父作用域。 | napi_invalid_arg | 入参scope为nullptr | 确保入参正确 |
| napi_escape_handle | 提升传入的js object的生命周期到其父作用域。 | napi_invalid_arg | 入参escapee为nullptr | 确保入参正确 |
| napi_escape_handle | 提升传入的js object的生命周期到其父作用域。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_escape_handle | 提升传入的js object的生命周期到其父作用域。 | napi_escape_called_twice | 该scope已经调用过napi_escape_handle | 请勿重复调用napi_escape_handle |
| napi_create_reference | 为Object创建一个reference，以延长其生命周期。调用者需要自己管理reference生命周期。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_reference | 为Object创建一个reference，以延长其生命周期。调用者需要自己管理reference生命周期。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_create_reference | 为Object创建一个reference，以延长其生命周期。调用者需要自己管理reference生命周期。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_delete_reference | 删除传入的reference。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_delete_reference | 删除传入的reference。 | napi_invalid_arg | 入参ref为nullptr | 确保入参正确 |
| napi_reference_ref | 增加传入的reference的引用计数，并获取该计数。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_reference_ref | 增加传入的reference的引用计数，并获取该计数。 | napi_invalid_arg | 入参ref为nullptr | 确保入参正确 |
| napi_reference_unref | 减少传入的reference的引用计数，并获取该计数。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_reference_unref | 减少传入的reference的引用计数，并获取该计数。 | napi_invalid_arg | 入参ref为nullptr | 确保入参正确 |
| napi_get_reference_value | 获取与reference相关联的js Object。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_reference_value | 获取与reference相关联的js Object。 | napi_invalid_arg | 入参ref为nullptr | 确保入参正确 |
| napi_get_reference_value | 获取与reference相关联的js Object。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_array | 创建并获取一个js Array。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_array | 创建并获取一个js Array。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_array_with_length | 创建并获取一个指定长度的js Array。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_array_with_length | 创建并获取一个指定长度的js Array。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_arraybuffer | 创建并获取一个指定大小的js ArrayBuffer。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_arraybuffer | 创建并获取一个指定大小的js ArrayBuffer。 | napi_invalid_arg | 入参data为nullptr | 确保入参正确 |
| napi_create_arraybuffer | 创建并获取一个指定大小的js ArrayBuffer。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_arraybuffer | 创建并获取一个指定大小的js ArrayBuffer。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_external | 分配一个附加有外部数据的js value。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_external | 分配一个附加有外部数据的js value。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_external | 分配一个附加有外部数据的js value。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_external_arraybuffer | 分配一个附加有外部数据的js ArrayBuffer。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_external_arraybuffer | 分配一个附加有外部数据的js ArrayBuffer。 | napi_invalid_arg | 入参external_data为nullptr | 确保入参正确 |
| napi_create_external_arraybuffer | 分配一个附加有外部数据的js ArrayBuffer。 | napi_invalid_arg | 入参finalize_cb为nullptr | 确保入参正确 |
| napi_create_external_arraybuffer | 分配一个附加有外部数据的js ArrayBuffer。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_external_arraybuffer | 分配一个附加有外部数据的js ArrayBuffer。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_object | 创建一个默认的js Object。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_object | 创建一个默认的js Object。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_symbol | 创建一个js Symbol。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_symbol | 创建一个js Symbol。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_symbol | 创建一个js Symbol。 | napi_invalid_arg | 入参description不为nullptr，且不是js String类型 | 确保入参正确 |
| napi_create_typedarray | 通过现有的ArrayBuffer创建一个js TypeArray。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_typedarray | 通过现有的ArrayBuffer创建一个js TypeArray。 | napi_invalid_arg | 入参arraybuffer为nullptr | 确保入参正确 |
| napi_create_typedarray | 通过现有的ArrayBuffer创建一个js TypeArray。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_typedarray | 通过现有的ArrayBuffer创建一个js TypeArray。 | napi_invalid_arg | 入参type不为napi_typedarray_type类型 | 确保入参正确 |
| napi_create_typedarray | 通过现有的ArrayBuffer创建一个js TypeArray。 | napi_arraybuffer_expected | 入参arraybuffer不为js ArrayBuffer类型 | 确保入参正确 |
| napi_create_typedarray | 通过现有的ArrayBuffer创建一个js TypeArray。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_dataview | 通过现有的ArrayBuffer创建一个js DataView。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_dataview | 通过现有的ArrayBuffer创建一个js DataView。 | napi_invalid_arg | 入参arraybuffer为nullptr | 确保入参正确 |
| napi_create_dataview | 通过现有的ArrayBuffer创建一个js DataView。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_dataview | 通过现有的ArrayBuffer创建一个js DataView。 | napi_arraybuffer_expected | 入参arraybuffer不为js ArrayBuffer类型 | 确保入参正确 |
| napi_create_dataview | 通过现有的ArrayBuffer创建一个js DataView。 | napi_pending_exception | 入参length与入参byte_offset相加超过入参arraybuffer的byte长度 | 需要检查访问长度 |
| napi_create_dataview | 通过现有的ArrayBuffer创建一个js DataView。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_int32 | 通过一个C的int32_t数据创建js Number。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_int32 | 通过一个C的int32_t数据创建js Number。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_uint32 | 通过一个C的uint32_t数据创建js Number。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_uint32 | 通过一个C的uint32_t数据创建js Number。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_int64 | 通过一个C的int64_t数据创建js Number。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_int64 | 通过一个C的int64_t数据创建js Number。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_double | 通过一个C的double数据创建js Number。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_double | 通过一个C的double数据创建js Number。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_string_latin1 | 通过ISO-8859-1编码的C字符串数据创建js String。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_string_latin1 | 通过ISO-8859-1编码的C字符串数据创建js String。 | napi_invalid_arg | 入参str为nullptr | 确保入参正确 |
| napi_create_string_latin1 | 通过ISO-8859-1编码的C字符串数据创建js String。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_string_utf8 | 通过UTF8编码的C字符串数据创建js String。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_string_utf8 | 通过UTF8编码的C字符串数据创建js String。 | napi_invalid_arg | 入参str为nullptr | 确保入参正确 |
| napi_create_string_utf8 | 通过UTF8编码的C字符串数据创建js String。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_string_utf16 | 通过UTF16编码的C字符串数据创建js String。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_string_utf16 | 通过UTF16编码的C字符串数据创建js String。 | napi_invalid_arg | 入参str为nullptr | 确保入参正确 |
| napi_create_string_utf16 | 通过UTF16编码的C字符串数据创建js String。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_string_utf16 | 通过UTF16编码的C字符串数据创建js String。 | napi_invalid_arg | 入参length值不为NAPI_AUTO_LENGTH，但超过INT_MAX | 确保入参正确 |
| napi_get_array_length | 获取array的length。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_array_length | 获取array的length。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_array_length | 获取array的length。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_array_length | 获取array的length。 | napi_array_expected | 入参value既不是js Array类型，也不是SharedArray类型 | 确保入参正确 |
| napi_get_array_length | 获取array的length。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_get_arraybuffer_info | 获取ArrayBuffer的底层data buffer及其长度。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_arraybuffer_info | 获取ArrayBuffer的底层data buffer及其长度。 | napi_invalid_arg | 入参arraybuffer为nullptr | 确保入参正确 |
| napi_get_arraybuffer_info | 获取ArrayBuffer的底层data buffer及其长度。 | napi_invalid_arg | 入参byte_length为nullptr | 确保入参正确 |
| napi_get_arraybuffer_info | 获取ArrayBuffer的底层data buffer及其长度。 | napi_arraybuffer_expected | 入参arraybuffer既不是js ArrayBuffer类型，也不是SharedArrayBuffer类型 | 确保入参正确 |
| napi_get_prototype | 获取给定js Object的prototype。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_prototype | 获取给定js Object的prototype。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_get_prototype | 获取给定js Object的prototype。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_prototype | 获取给定js Object的prototype。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_get_prototype | 获取给定js Object的prototype。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_get_typedarray_info | 获取给定TypedArray的各种属性。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_typedarray_info | 获取给定TypedArray的各种属性。 | napi_invalid_arg | 入参typedarray为nullptr | 确保入参正确 |
| napi_get_typedarray_info | 获取给定TypedArray的各种属性。 | napi_invalid_arg | 入参typedarray既不是js TypedArray类型，也不是ShareTypedArray类型 | 确保入参正确 |
| napi_get_dataview_info | 获取给定DataView的各种属性。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_dataview_info | 获取给定DataView的各种属性。 | napi_invalid_arg | 入参dataview为nullptr | 确保入参正确 |
| napi_get_dataview_info | 获取给定DataView的各种属性。 | napi_invalid_arg | 入参dataview不为js DataView类型 | 确保入参正确 |
| napi_get_value_bool | 获取给定js Boolean对应的C bool值。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_bool | 获取给定js Boolean对应的C bool值。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_bool | 获取给定js Boolean对应的C bool值。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_value_bool | 获取给定js Boolean对应的C bool值。 | napi_boolean_expected | 入参value不为js Bool类型 | 确保入参正确 |
| napi_get_value_double | 获取给定js Number对应的C double值。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_double | 获取给定js Number对应的C double值。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_double | 获取给定js Number对应的C double值。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_value_double | 获取给定js Number对应的C double值。 | napi_number_expected | 入参value不为js Number类型 | 确保入参正确 |
| napi_get_value_external | 获取先前通过napi_create_external()传递的外部数据指针。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_external | 获取先前通过napi_create_external()传递的外部数据指针。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_external | 获取先前通过napi_create_external()传递的外部数据指针。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_value_external | 获取先前通过napi_create_external()传递的外部数据指针。 | napi_object_expected | 入参value不为external类型 | 确保入参正确 |
| napi_get_value_int32 | 获取给定js Number对应的C int32值。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_int32 | 获取给定js Number对应的C int32值。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_int32 | 获取给定js Number对应的C int32值。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_value_int32 | 获取给定js Number对应的C int32值。 | napi_number_expected | 入参value不为js Number类型 | 确保入参正确 |
| napi_get_value_int64 | 获取给定js Number对应的C int64值。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_int64 | 获取给定js Number对应的C int64值。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_int64 | 获取给定js Number对应的C int64值。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_value_int64 | 获取给定js Number对应的C int64值。 | napi_number_expected | 入参value不为js Number类型 | 确保入参正确 |
| napi_get_value_string_latin1 | 获取给定js value对应的ISO-8859-1编码的字符串。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_string_latin1 | 获取给定js value对应的ISO-8859-1编码的字符串。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_string_latin1 | 获取给定js value对应的ISO-8859-1编码的字符串。 | napi_invalid_arg | 入参buf与result都为nullptr | 确保入参正确 |
| napi_get_value_string_latin1 | 获取给定js value对应的ISO-8859-1编码的字符串。 | napi_string_expected | 入参value不为js String类型 | 确保入参正确 |
| napi_get_value_string_utf8 | 获取给定js value对应的UTF8编码的字符串。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_string_utf8 | 获取给定js value对应的UTF8编码的字符串。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_string_utf8 | 获取给定js value对应的UTF8编码的字符串。 | napi_invalid_arg | 入参buf与result都为nullptr | 确保入参正确 |
| napi_get_value_string_utf8 | 获取给定js value对应的UTF8编码的字符串。 | napi_string_expected | 入参value不为js String类型 | 确保入参正确 |
| napi_get_value_string_utf16 | 获取给定js value对应的UTF16编码的字符串。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_string_utf16 | 获取给定js value对应的UTF16编码的字符串。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_string_utf16 | 获取给定js value对应的UTF16编码的字符串。 | napi_invalid_arg | 入参buf与result都为nullptr | 确保入参正确 |
| napi_get_value_string_utf16 | 获取给定js value对应的UTF16编码的字符串。 | napi_string_expected | 入参value不为js String类型 | 确保入参正确 |
| napi_get_value_uint32 | 获取给定js Number对应的C uint32值。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_uint32 | 获取给定js Number对应的C uint32值。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_uint32 | 获取给定js Number对应的C uint32值。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_value_uint32 | 获取给定js Number对应的C uint32值。 | napi_number_expected | 入参value不为js Number类型 | 确保入参正确 |
| napi_get_boolean | 根据给定的C boolean值，获取js bool对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_boolean | 根据给定的C boolean值，获取js bool对象。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_global | 获取global对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_global | 获取global对象。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_null | 获取null对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_null | 获取null对象。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_undefined | 获取undefined对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_undefined | 获取undefined对象。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_coerce_to_bool | 将给定的js value强转成js Boolean。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_coerce_to_bool | 将给定的js value强转成js Boolean。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_coerce_to_bool | 将给定的js value强转成js Boolean。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_coerce_to_bool | 将给定的js value强转成js Boolean。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_coerce_to_number | 将给定的js value强转成js Number。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_coerce_to_number | 将给定的js value强转成js Number。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_coerce_to_number | 将给定的js value强转成js Number。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_coerce_to_object | 将给定的js value强转成js Object。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_coerce_to_object | 将给定的js value强转成js Object。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_coerce_to_object | 将给定的js value强转成js Object。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_coerce_to_string | 将给定的js value强转成js String。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_coerce_to_string | 将给定的js value强转成js String。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_coerce_to_string | 将给定的js value强转成js String。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_typeof | 获取给定js value的js type。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_typeof | 获取给定js value的js type。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_typeof | 获取给定js value的js type。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_instanceof | 判断给定object是否为给定constructor的实例。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_instanceof | 判断给定object是否为给定constructor的实例。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_instanceof | 判断给定object是否为给定constructor的实例。 | napi_invalid_arg | 入参constructor为nullptr | 确保入参正确 |
| napi_instanceof | 判断给定object是否为给定constructor的实例。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_instanceof | 判断给定object是否为给定constructor的实例。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_instanceof | 判断给定object是否为给定constructor的实例。 | napi_function_expected | 入参constructor不为js Function类型 | 确保入参正确 |
| napi_instanceof | 判断给定object是否为给定constructor的实例。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_is_array | 判断给定js value是否为array。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_is_array | 判断给定js value是否为array。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_is_array | 判断给定js value是否为array。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_is_arraybuffer | 判断给定js value是否为ArrayBuffer。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_is_arraybuffer | 判断给定js value是否为ArrayBuffer。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_is_arraybuffer | 判断给定js value是否为ArrayBuffer。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_is_typedarray | 判断给定js value是否表示一个TypedArray。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_is_typedarray | 判断给定js value是否表示一个TypedArray。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_is_typedarray | 判断给定js value是否表示一个TypedArray。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_is_dataview | 判断给定js value是否表示一个DataView。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_is_dataview | 判断给定js value是否表示一个DataView。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_is_dataview | 判断给定js value是否表示一个DataView。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_is_date | 判断给定js value是否为js Date对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_is_date | 判断给定js value是否为js Date对象。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_is_date | 判断给定js value是否为js Date对象。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_strict_equals | 判断给定的两个js value是否严格相等。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_strict_equals | 判断给定的两个js value是否严格相等。 | napi_invalid_arg | 入参lhs为nullptr | 确保入参正确 |
| napi_strict_equals | 判断给定的两个js value是否严格相等。 | napi_invalid_arg | 入参rhs为nullptr | 确保入参正确 |
| napi_strict_equals | 判断给定的两个js value是否严格相等。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_property_names | 以字符串数组的形式获取对象的可枚举属性的名称。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_property_names | 以字符串数组的形式获取对象的可枚举属性的名称。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_get_property_names | 以字符串数组的形式获取对象的可枚举属性的名称。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_property_names | 以字符串数组的形式获取对象的可枚举属性的名称。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_set_property | 对给定Object设置属性。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_set_property | 对给定Object设置属性。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_set_property | 对给定Object设置属性。 | napi_invalid_arg | 入参key为nullptr | 确保入参正确 |
| napi_set_property | 对给定Object设置属性。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_set_property | 对给定Object设置属性。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_set_property | 对给定Object设置属性。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_get_property | 获取给定Object的给定属性。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_property | 获取给定Object的给定属性。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_get_property | 获取给定Object的给定属性。 | napi_invalid_arg | 入参key为nullptr | 确保入参正确 |
| napi_get_property | 获取给定Object的给定属性。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_property | 获取给定Object的给定属性。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_get_property | 获取给定Object的给定属性。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_has_property | 判断给定对象中是否存在给定属性。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_has_property | 判断给定对象中是否存在给定属性。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_has_property | 判断给定对象中是否存在给定属性。 | napi_invalid_arg | 入参key为nullptr | 确保入参正确 |
| napi_has_property | 判断给定对象中是否存在给定属性。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_has_property | 判断给定对象中是否存在给定属性。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_has_property | 判断给定对象中是否存在给定属性。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_delete_property | 尝试从给定Object中删除给定key属性。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_delete_property | 尝试从给定Object中删除给定key属性。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_delete_property | 尝试从给定Object中删除给定key属性。 | napi_invalid_arg | 入参key为nullptr | 确保入参正确 |
| napi_delete_property | 尝试从给定Object中删除给定key属性。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_delete_property | 尝试从给定Object中删除给定key属性。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_has_own_property | 判断给定Object中是否有名为key的own property。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_has_own_property | 判断给定Object中是否有名为key的own property。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_has_own_property | 判断给定Object中是否有名为key的own property。 | napi_invalid_arg | 入参key为nullptr | 确保入参正确 |
| napi_has_own_property | 判断给定Object中是否有名为key的own property。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_has_own_property | 判断给定Object中是否有名为key的own property。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_has_own_property | 判断给定Object中是否有名为key的own property。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_set_named_property | 对给定Object设置一个给定名称的属性。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_set_named_property | 对给定Object设置一个给定名称的属性。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_set_named_property | 对给定Object设置一个给定名称的属性。 | napi_invalid_arg | 入参utf8name为nullptr | 确保入参正确 |
| napi_set_named_property | 对给定Object设置一个给定名称的属性。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_set_named_property | 对给定Object设置一个给定名称的属性。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_set_named_property | 对给定Object设置一个给定名称的属性。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_get_named_property | 获取给定Object中指定名称的属性。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_named_property | 获取给定Object中指定名称的属性。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_get_named_property | 获取给定Object中指定名称的属性。 | napi_invalid_arg | 入参utf8name为nullptr | 确保入参正确 |
| napi_get_named_property | 获取给定Object中指定名称的属性。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_named_property | 获取给定Object中指定名称的属性。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_get_named_property | 获取给定Object中指定名称的属性。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_has_named_property | 判断给定Object中是否有给定名称的属性。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_has_named_property | 判断给定Object中是否有给定名称的属性。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_has_named_property | 判断给定Object中是否有给定名称的属性。 | napi_invalid_arg | 入参utf8name为nullptr | 确保入参正确 |
| napi_has_named_property | 判断给定Object中是否有给定名称的属性。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_has_named_property | 判断给定Object中是否有给定名称的属性。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_has_named_property | 判断给定Object中是否有给定名称的属性。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_set_element | 在给定Object的指定索引处，设置元素。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_set_element | 在给定Object的指定索引处，设置元素。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_set_element | 在给定Object的指定索引处，设置元素。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_set_element | 在给定Object的指定索引处，设置元素。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_set_element | 在给定Object的指定索引处，设置元素。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_get_element | 获取给定Object指定索引处的元素。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_element | 获取给定Object指定索引处的元素。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_get_element | 获取给定Object指定索引处的元素。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_element | 获取给定Object指定索引处的元素。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_get_element | 获取给定Object指定索引处的元素。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_has_element | 若给定Object的指定索引处拥有属性，获取该元素。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_has_element | 若给定Object的指定索引处拥有属性，获取该元素。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_has_element | 若给定Object的指定索引处拥有属性，获取该元素。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_has_element | 若给定Object的指定索引处拥有属性，获取该元素。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_has_element | 若给定Object的指定索引处拥有属性，获取该元素。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_delete_element | 尝试删除给定Object的指定索引处的元素。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_delete_element | 尝试删除给定Object的指定索引处的元素。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_delete_element | 尝试删除给定Object的指定索引处的元素。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_delete_element | 尝试删除给定Object的指定索引处的元素。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_define_properties | 批量的向给定Object中定义属性。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_define_properties | 批量的向给定Object中定义属性。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_define_properties | 批量的向给定Object中定义属性。 | napi_invalid_arg | 入参properties为nullptr | 确保入参正确 |
| napi_define_properties | 批量的向给定Object中定义属性。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_define_properties | 批量的向给定Object中定义属性。 | napi_name_expected | 入参properties中的某个property没有设utf8name，且它的name既不是js String类型也不是js Symbol类型 | 确保入参正确 |
| napi_define_properties | 批量的向给定Object中定义属性。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_type_tag_object | 将tag指针的值与Object关联。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_type_tag_object | 将tag指针的值与Object关联。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_type_tag_object | 将tag指针的值与Object关联。 | napi_invalid_arg | 入参type_tag为nullptr | 确保入参正确 |
| napi_type_tag_object | 将tag指针的值与Object关联。 | napi_invalid_arg | js对象已被打过tag标记 | js对象需未被打过标记 |
| napi_type_tag_object | 将tag指针的值与Object关联。 | napi_invalid_arg | 调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_type_tag_object | 将tag指针的值与Object关联。 | napi_object_expected | 入参js_object不是js Object类型 | 确保入参正确 |
| napi_type_tag_object | 将tag指针的值与Object关联。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_check_object_type_tag | 判断给定的tag指针是否被关联到了js Object上。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_check_object_type_tag | 判断给定的tag指针是否被关联到了js Object上。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_check_object_type_tag | 判断给定的tag指针是否被关联到了js Object上。 | napi_invalid_arg | 入参type_tag为nullptr | 确保入参正确 |
| napi_check_object_type_tag | 判断给定的tag指针是否被关联到了js Object上。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_check_object_type_tag | 判断给定的tag指针是否被关联到了js Object上。 | napi_object_expected | 入参js_object不是js Object类型 | 确保入参正确 |
| napi_check_object_type_tag | 判断给定的tag指针是否被关联到了js Object上。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_call_function | 在Native方法中调用js function，即native call js。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_call_function | 在Native方法中调用js function，即native call js。 | napi_invalid_arg | 入参func为nullptr | 确保入参正确 |
| napi_call_function | 在Native方法中调用js function，即native call js。 | napi_invalid_arg | 入参argc大于0且argv为nullptr | 确保入参正确 |
| napi_call_function | 在Native方法中调用js function，即native call js。 | napi_function_expected | 入参func不为js Function类型 | 确保入参正确 |
| napi_call_function | 在Native方法中调用js function，即native call js。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_function | 创建native方法给js使用，以便于js call native。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_function | 创建native方法给js使用，以便于js call native。 | napi_invalid_arg | 入参cb为nullptr | 确保入参正确 |
| napi_create_function | 创建native方法给js使用，以便于js call native。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_function | 创建native方法给js使用，以便于js call native。 | napi_invalid_arg | new c++对象失败 | 内存不足，检查是否有c++内存泄漏 |
| napi_create_function | 创建native方法给js使用，以便于js call native。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_get_cb_info | 从给定的callback info中获取有关调用的详细信息，如参数和this指针。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_cb_info | 从给定的callback info中获取有关调用的详细信息，如参数和this指针。 | napi_invalid_arg | 入参cbinfo为nullptr | 确保入参正确 |
| napi_get_new_target | 获取构造函数调用的new.target。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_new_target | 获取构造函数调用的new.target。 | napi_invalid_arg | 入参cbinfo为nullptr | 确保入参正确 |
| napi_get_new_target | 获取构造函数调用的new.target。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_new_target | 获取构造函数调用的new.target。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_new_instance | 通过给定的构造函数，构建一个实例。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_new_instance | 通过给定的构造函数，构建一个实例。 | napi_invalid_arg | 入参constructor为nullptr | 确保入参正确 |
| napi_new_instance | 通过给定的构造函数，构建一个实例。 | napi_invalid_arg | 入参argc大于0且argv为nullptr | 确保入参正确 |
| napi_new_instance | 通过给定的构造函数，构建一个实例。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_new_instance | 通过给定的构造函数，构建一个实例。 | napi_function_expected | 入参constructor不为js Function类型 | 确保入参正确 |
| napi_new_instance | 通过给定的构造函数，构建一个实例。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_define_class | 定义与C++类相对应的JavaScript类。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_define_class | 定义与C++类相对应的JavaScript类。 | napi_invalid_arg | 入参utf8name为nullptr | 确保入参正确 |
| napi_define_class | 定义与C++类相对应的JavaScript类。 | napi_invalid_arg | 入参constructor为nullptr | 确保入参正确 |
| napi_define_class | 定义与C++类相对应的JavaScript类。 | napi_invalid_arg | 入参property_count大于0且properties为nullptr | 确保入参正确 |
| napi_define_class | 定义与C++类相对应的JavaScript类。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_define_class | 定义与C++类相对应的JavaScript类。 | napi_object_expected | 入参length值不为NAPI_AUTO_LENGTH，但超过INT_MAX | 确保入参正确 |
| napi_define_class | 定义与C++类相对应的JavaScript类。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_wrap | 在js object上绑定一个native对象实例。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_wrap | 在js object上绑定一个native对象实例。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_wrap | 在js object上绑定一个native对象实例。 | napi_invalid_arg | 入参native_object为nullptr | 确保入参正确 |
| napi_wrap | 在js object上绑定一个native对象实例。 | napi_invalid_arg | 入参finalize_cb为nullptr | 确保入参正确 |
| napi_wrap | 在js object上绑定一个native对象实例。 | napi_object_expected | 入参js_object不是js Object类型 | 确保入参正确 |
| napi_wrap | 在js object上绑定一个native对象实例。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_unwrap | 从js object上获取先前绑定的native对象实例。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_unwrap | 从js object上获取先前绑定的native对象实例。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_unwrap | 从js object上获取先前绑定的native对象实例。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_unwrap | 从js object上获取先前绑定的native对象实例。 | napi_object_expected | 入参js_object不是js Object类型 | 确保入参正确 |
| napi_unwrap | 从js object上获取先前绑定的native对象实例。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_remove_wrap | 从js object上获取先前绑定的native对象实例，并解除绑定。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_remove_wrap | 从js object上获取先前绑定的native对象实例，并解除绑定。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_remove_wrap | 从js object上获取先前绑定的native对象实例，并解除绑定。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_remove_wrap | 从js object上获取先前绑定的native对象实例，并解除绑定。 | napi_object_expected | 入参js_object不是js Object类型 | 确保入参正确 |
| napi_remove_wrap | 从js object上获取先前绑定的native对象实例，并解除绑定。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_async_work | 创建一个异步工作对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_async_work | 创建一个异步工作对象。 | napi_invalid_arg | 入参async_resource_name为nullptr | 确保入参正确 |
| napi_create_async_work | 创建一个异步工作对象。 | napi_invalid_arg | 入参execute为nullptr | 确保入参正确 |
| napi_create_async_work | 创建一个异步工作对象。 | napi_invalid_arg | 入参complete为nullptr | 确保入参正确 |
| napi_create_async_work | 创建一个异步工作对象。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_delete_async_work | 释放先前创建的异步工作对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_delete_async_work | 释放先前创建的异步工作对象。 | napi_invalid_arg | 入参work为nullptr | 确保入参正确 |
| napi_queue_async_work | 将异步工作对象加到队列，由底层去调度执行。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_queue_async_work | 将异步工作对象加到队列，由底层去调度执行。 | napi_invalid_arg | 入参work为nullptr | 确保入参正确 |
| napi_cancel_async_work | 取消入队的异步任务。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_cancel_async_work | 取消入队的异步任务。 | napi_invalid_arg | 入参work为nullptr | 确保入参正确 |
| napi_async_init | 创建一个异步资源上下文环境（不支持与async_hook相关功能）。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_async_init | 创建一个异步资源上下文环境（不支持与async_hook相关功能）。 | napi_invalid_arg | 入参async_resource_name为nullptr | 确保入参正确 |
| napi_async_init | 创建一个异步资源上下文环境（不支持与async_hook相关功能）。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_make_callback | 在异步资源上下文环境中回调JS函数(不支持与async_hook相关功能)。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_make_callback | 在异步资源上下文环境中回调JS函数(不支持与async_hook相关功能)。 | napi_invalid_arg | 入参func为nullptr | 确保入参正确 |
| napi_make_callback | 在异步资源上下文环境中回调JS函数(不支持与async_hook相关功能)。 | napi_invalid_arg | 入参recv为nullptr | 确保入参正确 |
| napi_make_callback | 在异步资源上下文环境中回调JS函数(不支持与async_hook相关功能)。 | napi_invalid_arg | 入参argc大于0且argv为nullptr | 确保入参正确 |
| napi_make_callback | 在异步资源上下文环境中回调JS函数(不支持与async_hook相关功能)。 | napi_object_expected | 入参recv不为js Object类型 | 确保入参正确 |
| napi_make_callback | 在异步资源上下文环境中回调JS函数(不支持与async_hook相关功能)。 | napi_function_expected | 入参func不为js Function类型 | 确保入参正确 |
| napi_make_callback | 在异步资源上下文环境中回调JS函数(不支持与async_hook相关功能)。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_async_destroy | 销毁先前创建的异步资源上下文环境（不支持与async_hook相关功能）。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_async_destroy | 销毁先前创建的异步资源上下文环境（不支持与async_hook相关功能）。 | napi_invalid_arg | 入参async_context为nullptr | 确保入参正确 |
| napi_open_callback_scope | 创建一个回调作用域（不支持与async_hook相关功能）。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_open_callback_scope | 创建一个回调作用域（不支持与async_hook相关功能）。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_close_callback_scope | 关闭先前创建的回调作用域（不支持与async_hook相关功能）。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_close_callback_scope | 关闭先前创建的回调作用域（不支持与async_hook相关功能）。 | napi_invalid_arg | 入参scope为nullptr | 确保入参正确 |
| napi_close_callback_scope | 关闭先前创建的回调作用域（不支持与async_hook相关功能）。 | napi_invalid_arg | new c++对象失败 | 内存不足，检查是否有c++内存泄漏 |
| napi_close_callback_scope | 关闭先前创建的回调作用域（不支持与async_hook相关功能）。 | napi_callback_scope_mismatch | napi_open_callback_scope调用次数小于napi_close_callback_scope | napi_open_callback_scope和napi_close_callback_scope需要成对使用 |
| napi_get_node_version | 获取node的版本信息。 | 不涉及 | 不涉及 | 不涉及 |
| napi_get_version | 获取Node运行时支持的最高 N-API 版本。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_version | 获取Node运行时支持的最高 N-API 版本。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_promise | 创建一个延迟对象和js promise。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_promise | 创建一个延迟对象和js promise。 | napi_invalid_arg | 入参deferred为nullptr | 确保入参正确 |
| napi_create_promise | 创建一个延迟对象和js promise。 | napi_invalid_arg | 入参promise为nullptr | 确保入参正确 |
| napi_create_promise | 创建一个延迟对象和js promise。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_resolve_deferred | resolve与js promise对象关联的延迟函数。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_resolve_deferred | resolve与js promise对象关联的延迟函数。 | napi_invalid_arg | 入参deferred为nullptr | 确保入参正确 |
| napi_resolve_deferred | resolve与js promise对象关联的延迟函数。 | napi_invalid_arg | 入参resolution为nullptr | 确保入参正确 |
| napi_resolve_deferred | resolve与js promise对象关联的延迟函数。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_reject_deferred | reject与js promise对象关联的延迟函数。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_reject_deferred | reject与js promise对象关联的延迟函数。 | napi_invalid_arg | 入参deferred为nullptr | 确保入参正确 |
| napi_reject_deferred | reject与js promise对象关联的延迟函数。 | napi_invalid_arg | 入参rejection为nullptr | 确保入参正确 |
| napi_reject_deferred | reject与js promise对象关联的延迟函数。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_is_promise | 判断给定js value是否为promise对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_is_promise | 判断给定js value是否为promise对象。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_is_promise | 判断给定js value是否为promise对象。 | napi_invalid_arg | 入参is_promise为nullptr | 确保入参正确 |
| napi_get_uv_event_loop | 获取当前libuv loop实例。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_uv_event_loop | 获取当前libuv loop实例。 | napi_invalid_arg | 入参loop为nullptr | 确保入参正确 |
| napi_get_uv_event_loop | 获取当前libuv loop实例。 | napi_generic_failure | 入参env已销毁 | 确保入参正确 |
| napi_create_threadsafe_function | 创建线程安全函数。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_threadsafe_function | 创建线程安全函数。 | napi_invalid_arg | 入参async_resource_name为nullptr | 确保入参正确 |
| napi_create_threadsafe_function | 创建线程安全函数。 | napi_invalid_arg | 入参initial_thread_count为0或者大于128 | 确保入参正确 |
| napi_create_threadsafe_function | 创建线程安全函数。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_threadsafe_function | 创建线程安全函数。 | napi_invalid_arg | 入参func与call_js_cb都为nullptr | 确保入参正确 |
| napi_create_threadsafe_function | 创建线程安全函数。 | napi_invalid_arg | new c++对象失败 | 内存不足，检查是否有c++内存泄漏 |
| napi_create_threadsafe_function | 创建线程安全函数。 | napi_generic_failure | uv_loop_t为nullptr | NA |
| napi_create_threadsafe_function | 创建线程安全函数。 | napi_generic_failure | uv_async_init失败 | NA |
| napi_get_threadsafe_function_context | 获取线程安全函数中的context。 | napi_invalid_arg | 入参func为nullptr | 确保入参正确 |
| napi_get_threadsafe_function_context | 获取线程安全函数中的context。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_call_threadsafe_function | 调用线程安全函数。 | napi_invalid_arg | 入参func为nullptr | 确保入参正确 |
| napi_call_threadsafe_function | 调用线程安全函数。 | napi_invalid_arg | threadsafe_function已关闭 | 请勿在napi_release_threadsafe_function关闭了func后再调用本接口 |
| napi_call_threadsafe_function | 调用线程安全函数。 | napi_queue_full | 入参is_blocking为napi_tsfn_nonblocking且queue已满 | 增大max_queue_size大小。或is_blocking改为napi_tsfn_blocking |
| napi_call_threadsafe_function | 调用线程安全函数。 | napi_closing | threadsafe_function正在关闭 | 请勿在napi_release_threadsafe_function关闭了func后再调用本接口 |
| napi_call_threadsafe_function | 调用线程安全函数。 | napi_closing | 入参env已销毁，且env地址又被新env复用 | 请勿在env销毁后再使用本接口 |
| napi_call_threadsafe_function | 调用线程安全函数。 | napi_generic_failure | uv_async_send失败 | NA |
| napi_call_threadsafe_function | 调用线程安全函数。 | napi_generic_failure | 入参env已销毁 | 请勿在env销毁后再使用本接口 |
| napi_acquire_threadsafe_function | 指示线程安全函数可以开始使用。 | napi_invalid_arg | 入参func为nullptr | 确保入参正确 |
| napi_acquire_threadsafe_function | 指示线程安全函数可以开始使用。 | napi_generic_failure | threadsafe_function正在关闭/已关闭 | 请勿在napi_release_threadsafe_function关闭了func后再调用本接口 |
| napi_release_threadsafe_function | 指示线程安全函数将停止使用。 | napi_invalid_arg | 入参func为nullptr | 确保入参正确 |
| napi_release_threadsafe_function | 指示线程安全函数将停止使用。 | napi_generic_failure | threadsafe_function正在关闭/已关闭 | 请勿在napi_release_threadsafe_function关闭了func后再调用本接口 |
| napi_release_threadsafe_function | 指示线程安全函数将停止使用。 | napi_generic_failure | 调用本接口时，占用threadsafe_function的线程数是0 | release次数需要与initial_thread_count和aquire匹配 |
| napi_release_threadsafe_function | 指示线程安全函数将停止使用。 | napi_generic_failure | uv_async_send失败 | NA |
| napi_release_threadsafe_function | 指示线程安全函数将停止使用。 | napi_generic_failure | 入参env已销毁 | 确保入参正确 |
| napi_ref_threadsafe_function | 指示在主线程上运行的事件循环在线程安全函数被销毁之前不应退出。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_ref_threadsafe_function | 指示在主线程上运行的事件循环在线程安全函数被销毁之前不应退出。 | napi_invalid_arg | 入参func为nullptr | 确保入参正确 |
| napi_ref_threadsafe_function | 指示在主线程上运行的事件循环在线程安全函数被销毁之前不应退出。 | napi_generic_failure | 当前线程不是env所在线程 | 该接口只能从env所在线程调用 |
| napi_unref_threadsafe_function | 指示在主线程上运行的事件循环可能会在线程安全函数被销毁之前退出。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_unref_threadsafe_function | 指示在主线程上运行的事件循环可能会在线程安全函数被销毁之前退出。 | napi_invalid_arg | 入参func为nullptr | 确保入参正确 |
| napi_unref_threadsafe_function | 指示在主线程上运行的事件循环可能会在线程安全函数被销毁之前退出。 | napi_generic_failure | 当前线程不是env所在线程 | 该接口只能从env所在线程调用 |
| napi_create_date | 通过一个C的double数据创建js Date。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_date | 通过一个C的double数据创建js Date。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_date | 通过一个C的double数据创建js Date。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_get_date_value | 获取给定js Date对应的C double值。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_date_value | 获取给定js Date对应的C double值。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_date_value | 获取给定js Date对应的C double值。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_date_value | 获取给定js Date对应的C double值。 | napi_date_expected | 入参value不为js Date类型 | 确保入参正确 |
| napi_get_date_value | 获取给定js Date对应的C double值。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_bigint_int64 | 通过一个C的int64数据创建js BigInt。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_bigint_int64 | 通过一个C的int64数据创建js BigInt。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_bigint_uint64 | 通过一个C的uint64数据创建js BigInt。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_bigint_uint64 | 通过一个C的uint64数据创建js BigInt。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_bigint_words | 通过一个C的uint64数组创建单个js BigInt。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_bigint_words | 通过一个C的uint64数组创建单个js BigInt。 | napi_invalid_arg | 入参words为nullptr | 确保入参正确 |
| napi_create_bigint_words | 通过一个C的uint64数组创建单个js BigInt。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_bigint_words | 通过一个C的uint64数组创建单个js BigInt。 | napi_invalid_arg | 入参word_count大于等于INT_MAX | 确保入参正确 |
| napi_create_bigint_words | 通过一个C的uint64数组创建单个js BigInt。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_bigint_words | 通过一个C的uint64数组创建单个js BigInt。 | napi_pending_exception | 入参(word_count*2)>(1_MB/32) | 确保入参正确 |
| napi_get_value_bigint_int64 | 获取给定js BigInt对应的C int64值。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_bigint_int64 | 获取给定js BigInt对应的C int64值。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_bigint_int64 | 获取给定js BigInt对应的C int64值。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_value_bigint_int64 | 获取给定js BigInt对应的C int64值。 | napi_invalid_arg | 入参lossless为nullptr | 确保入参正确 |
| napi_get_value_bigint_int64 | 获取给定js BigInt对应的C int64值。 | napi_bigint_expected | 入参value不为js BigInt类型 | 确保入参正确 |
| napi_get_value_bigint_uint64 | 获取给定js BigInt对应的C uint64值。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_bigint_uint64 | 获取给定js BigInt对应的C uint64值。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_bigint_uint64 | 获取给定js BigInt对应的C uint64值。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_value_bigint_uint64 | 获取给定js BigInt对应的C uint64值。 | napi_invalid_arg | 入参lossless为nullptr | 确保入参正确 |
| napi_get_value_bigint_uint64 | 获取给定js BigInt对应的C uint64值。 | napi_bigint_expected | 入参value不为js BigInt类型 | 确保入参正确 |
| napi_get_value_bigint_words | 获取给定js BigInt对应的信息，包括符号位、64位小端序数组和数组中的元素个数。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_value_bigint_words | 获取给定js BigInt对应的信息，包括符号位、64位小端序数组和数组中的元素个数。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_get_value_bigint_words | 获取给定js BigInt对应的信息，包括符号位、64位小端序数组和数组中的元素个数。 | napi_invalid_arg | 入参word_count为nullptr | 确保入参正确 |
| napi_get_value_bigint_words | 获取给定js BigInt对应的信息，包括符号位、64位小端序数组和数组中的元素个数。 | napi_object_expected | 入参value不为js BigInt类型 | 确保入参正确 |
| napi_create_buffer | 创建并获取一个指定大小的js Buffer。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_buffer | 创建并获取一个指定大小的js Buffer。 | napi_invalid_arg | 入参data为nullptr | 确保入参正确 |
| napi_create_buffer | 创建并获取一个指定大小的js Buffer。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_buffer | 创建并获取一个指定大小的js Buffer。 | napi_invalid_arg | 入参size为0或超过2MiB(2097152) | 确保入参正确 |
| napi_create_buffer | 创建并获取一个指定大小的js Buffer。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_buffer_copy | 创建并获取一个指定大小的js Buffer，并以给定数据进行初始化。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_buffer_copy | 创建并获取一个指定大小的js Buffer，并以给定数据进行初始化。 | napi_invalid_arg | 入参data为nullptr | 确保入参正确 |
| napi_create_buffer_copy | 创建并获取一个指定大小的js Buffer，并以给定数据进行初始化。 | napi_invalid_arg | 入参result_data为nullptr | 确保入参正确 |
| napi_create_buffer_copy | 创建并获取一个指定大小的js Buffer，并以给定数据进行初始化。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_buffer_copy | 创建并获取一个指定大小的js Buffer，并以给定数据进行初始化。 | napi_invalid_arg | 入参size为0或超过2MiB(2097152) | 确保入参正确 |
| napi_create_buffer_copy | 创建并获取一个指定大小的js Buffer，并以给定数据进行初始化。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_external_buffer | 创建并获取一个指定大小的js Buffer，并以给定数据进行初始化，该接口可为Buffer附带额外数据。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_external_buffer | 创建并获取一个指定大小的js Buffer，并以给定数据进行初始化，该接口可为Buffer附带额外数据。 | napi_invalid_arg | 入参data为nullptr | 确保入参正确 |
| napi_create_external_buffer | 创建并获取一个指定大小的js Buffer，并以给定数据进行初始化，该接口可为Buffer附带额外数据。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_external_buffer | 创建并获取一个指定大小的js Buffer，并以给定数据进行初始化，该接口可为Buffer附带额外数据。 | napi_invalid_arg | 入参size为0或超过2MiB(2097152) | 确保入参正确 |
| napi_create_external_buffer | 创建并获取一个指定大小的js Buffer，并以给定数据进行初始化，该接口可为Buffer附带额外数据。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_get_buffer_info | 获取js Buffer底层data及其长度。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_buffer_info | 获取js Buffer底层data及其长度。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_buffer_info | 获取js Buffer底层data及其长度。 | napi_arraybuffer_expected | 入参value不为js ArrayBuffer类型 | 确保入参正确 |
| napi_is_buffer | 判断给定js value是否为Buffer对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_is_buffer | 判断给定js value是否为Buffer对象。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_is_buffer | 判断给定js value是否为Buffer对象。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_object_freeze | 冻结给定的对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_object_freeze | 冻结给定的对象。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_object_freeze | 冻结给定的对象。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_object_freeze | 冻结给定的对象。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_object_seal | 密封给定的对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_object_seal | 密封给定的对象。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_object_seal | 密封给定的对象。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_object_seal | 密封给定的对象。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_get_all_property_names | 获取一个数组，其中包含此对象过滤后的属性名称。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_all_property_names | 获取一个数组，其中包含此对象过滤后的属性名称。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_get_all_property_names | 获取一个数组，其中包含此对象过滤后的属性名称。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_get_all_property_names | 获取一个数组，其中包含此对象过滤后的属性名称。 | napi_invalid_arg | 入参key_mode不在napi_key_collection_mode枚举范围内 | 确保入参正确 |
| napi_get_all_property_names | 获取一个数组，其中包含此对象过滤后的属性名称。 | napi_invalid_arg | 入参key_conversion不在napi_key_conversion枚举范围内 | 确保入参正确 |
| napi_get_all_property_names | 获取一个数组，其中包含此对象过滤后的属性名称。 | napi_object_expected | 入参object不为js Object类型 | 确保入参正确 |
| napi_get_all_property_names | 获取一个数组，其中包含此对象过滤后的属性名称。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_detach_arraybuffer | 分离给定ArrayBuffer的底层数据。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_detach_arraybuffer | 分离给定ArrayBuffer的底层数据。 | napi_invalid_arg | 入参arraybuffer为nullptr | 确保入参正确 |
| napi_detach_arraybuffer | 分离给定ArrayBuffer的底层数据。 | napi_invalid_arg | 入参arraybuffer是js Object类型，但不是js ArrayBuffer类型，也不是SharedArrayBuffer类型 | 确保入参正确 |
| napi_detach_arraybuffer | 分离给定ArrayBuffer的底层数据。 | napi_invalid_arg | 入参arraybuffer已被detach过 | 需arraybuffer未被detach过 |
| napi_detach_arraybuffer | 分离给定ArrayBuffer的底层数据。 | napi_object_expected | 入参arraybuffer不为js Object类型 | 确保入参正确 |
| napi_is_detached_arraybuffer | 判断给定的ArrayBuffer是否已被分离过。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_is_detached_arraybuffer | 判断给定的ArrayBuffer是否已被分离过。 | napi_invalid_arg | 入参arraybuffer为nullptr | 确保入参正确 |
| napi_is_detached_arraybuffer | 判断给定的ArrayBuffer是否已被分离过。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_is_detached_arraybuffer | 判断给定的ArrayBuffer是否已被分离过。 | napi_invalid_arg | 入参arraybuffer不为js ArrayBuffer类型 | 确保入参正确 |
| napi_run_script | 将给定对象作为js代码运行。当前接口实际为空实现，可使用系统拓展接口napi_run_script_path接口，提升安全性。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_run_script | 将给定对象作为js代码运行。当前接口实际为空实现，可使用系统拓展接口napi_run_script_path接口，提升安全性。 | napi_invalid_arg | 入参script为nullptr | 确保入参正确 |
| napi_run_script | 将给定对象作为js代码运行。当前接口实际为空实现，可使用系统拓展接口napi_run_script_path接口，提升安全性。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_set_instance_data | 绑定与当前运行的环境相关联的数据项。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_instance_data | 检索与当前运行的环境相关联的数据项。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_get_instance_data | 检索与当前运行的环境相关联的数据项。 | napi_invalid_arg | 入参data为nullptr | 确保入参正确 |
| napi_add_env_cleanup_hook | 注册环境清理钩子函数。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_add_env_cleanup_hook | 注册环境清理钩子函数。 | napi_invalid_arg | 入参func为nullptr | 确保入参正确 |
| napi_remove_env_cleanup_hook | 取消环境清理钩子函数。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_remove_env_cleanup_hook | 取消环境清理钩子函数。 | napi_invalid_arg | 入参func为nullptr | 确保入参正确 |
| napi_add_async_cleanup_hook | 注册清理异步钩子函数。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_add_async_cleanup_hook | 注册清理异步钩子函数。 | napi_invalid_arg | 入参hook为nullptr | 确保入参正确 |
| napi_remove_async_cleanup_hook | 取消清理异步钩子函数。 | napi_invalid_arg | 入参remove_handle为nullptr | 确保入参正确 |
| node_api_get_module_file_name | 用于获取加载项加载位置的绝对路径。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| node_api_get_module_file_name | 用于获取加载项加载位置的绝对路径。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_add_finalizer | 当js Object中的对象被垃圾回收时调用注册的napi_finalize回调。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_add_finalizer | 当js Object中的对象被垃圾回收时调用注册的napi_finalize回调。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_add_finalizer | 当js Object中的对象被垃圾回收时调用注册的napi_finalize回调。 | napi_invalid_arg | 入参finalize_cb为nullptr | 确保入参正确 |
| napi_add_finalizer | 当js Object中的对象被垃圾回收时调用注册的napi_finalize回调。 | napi_object_expected | 入参js_object不是js Object类型 | 确保入参正确 |
| napi_fatal_exception | 向js抛出 UncaughtException。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_fatal_exception | 向js抛出 UncaughtException。 | napi_invalid_arg | 入参err为nullptr | 确保入参正确 |
| napi_fatal_exception | 向js抛出 UncaughtException。 | napi_invalid_arg | 入参error不为js Error类型 | 确保入参正确 |
| napi_fatal_exception | 向js抛出 UncaughtException。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_queue_async_work_with_qos | 将异步工作对象加到队列，由底层根据传入的qos优先级去调度执行。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_queue_async_work_with_qos | 将异步工作对象加到队列，由底层根据传入的qos优先级去调度执行。 | napi_invalid_arg | 入参work为nullptr | 确保入参正确 |
| napi_run_script_path | 运行abc文件。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_run_script_path | 运行abc文件。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_run_script_path | 运行abc文件。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_load_module | 将abc文件作为模块加载，返回模块的命名空间。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_load_module | 将abc文件作为模块加载，返回模块的命名空间。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_load_module | 将abc文件作为模块加载，返回模块的命名空间。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_object_with_properties | 使用给定的napi_property_descriptor创建js Object。descriptor的键名必须为 string，且不可转为number。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_object_with_properties | 使用给定的napi_property_descriptor创建js Object。descriptor的键名必须为 string，且不可转为number。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_object_with_named_properties | 使用给定的napi_value和键名创建js Object。键名必须为 string，且不可转为number。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_object_with_named_properties | 使用给定的napi_value和键名创建js Object。键名必须为 string，且不可转为number。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_coerce_to_native_binding_object | 强制将js Object和Native对象绑定。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_coerce_to_native_binding_object | 强制将js Object和Native对象绑定。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_coerce_to_native_binding_object | 强制将js Object和Native对象绑定。 | napi_invalid_arg | 入参detach_cb为nullptr | 确保入参正确 |
| napi_coerce_to_native_binding_object | 强制将js Object和Native对象绑定。 | napi_invalid_arg | 入参attach_cb为nullptr | 确保入参正确 |
| napi_coerce_to_native_binding_object | 强制将js Object和Native对象绑定。 | napi_invalid_arg | 入参native_object为nullptr | 确保入参正确 |
| napi_coerce_to_native_binding_object | 强制将js Object和Native对象绑定。 | napi_invalid_arg | new c++对象失败 | 内存不足，检查是否有c++内存泄漏 |
| napi_coerce_to_native_binding_object | 强制将js Object和Native对象绑定。 | napi_object_expected | js_object不是js Object类型 | 确保入参正确 |
| napi_coerce_to_native_binding_object | 强制将js Object和Native对象绑定。 | napi_generic_failure | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_ark_runtime | 创建基础运行时环境。 | napi_invalid_arg | g_createNapiEnvCallback为nullptr | NA |
| napi_create_ark_runtime | 创建基础运行时环境。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_ark_runtime | 创建基础运行时环境。 | napi_create_ark_runtime_only_one_env_per_thread | 当前线程已创建过env | 避免重复创建 |
| napi_create_ark_runtime | 创建基础运行时环境。 | napi_create_ark_runtime_too_many_envs | 达到最大ArkRuntime数量（64）或js线程数超上限（80） | 避免滥用接口 |
| napi_create_ark_runtime | 创建基础运行时环境。 | napi_generic_failure | 创建ark_runtime失败 | 根据hilog信息排查原因 |
| napi_destroy_ark_runtime | 销毁基础运行时环境。 | napi_invalid_arg | g_createNapiEnvCallback为nullptr | NA |
| napi_destroy_ark_runtime | 销毁基础运行时环境。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_destroy_ark_runtime | 销毁基础运行时环境。 | napi_destroy_ark_runtime_env_not_exist | env未创建 | 与create接口配套使用 |
| napi_run_event_loop | 触发底层的事件循环。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_run_event_loop | 触发底层的事件循环。 | napi_invalid_arg | 入参mode不为napi_event_mode枚举类型 | 确保入参正确 |
| napi_run_event_loop | 触发底层的事件循环。 | napi_invalid_arg | env的loop为nullptr | 确保入参正确 |
| napi_run_event_loop | 触发底层的事件循环。 | napi_generic_failure | 当前线程不是native线程 | 请使用napi_create_ark_runtime接口创建出来的env |
| napi_stop_event_loop | 停止底层的事件循环。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_stop_event_loop | 停止底层的事件循环。 | napi_invalid_arg | env的loop为nullptr | 确保入参正确 |
| napi_stop_event_loop | 停止底层的事件循环。 | napi_generic_failure | 当前线程不是native线程 | 请使用napi_create_ark_runtime接口创建出来的env |
| napi_load_module_with_info | 将abc文件作为模块加载，返回模块的命名空间。可在新创建的ArkTS基础运行时环境中使用。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_load_module_with_info | 将abc文件作为模块加载，返回模块的命名空间。可在新创建的ArkTS基础运行时环境中使用。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_load_module_with_info | 将abc文件作为模块加载，返回模块的命名空间。可在新创建的ArkTS基础运行时环境中使用。 | napi_generic_failure | 模块加载失败 | 根据hilog信息排查原因 |
| napi_load_module_with_info | 将abc文件作为模块加载，返回模块的命名空间。可在新创建的ArkTS基础运行时环境中使用。 | napi_pending_exception | 调用接口前有未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_serialize | 将ArkTS对象转换为native数据。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_serialize | 将ArkTS对象转换为native数据。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_serialize | 将ArkTS对象转换为native数据。 | napi_invalid_arg | 入参transfer_list为nullptr | 确保入参正确 |
| napi_serialize | 将ArkTS对象转换为native数据。 | napi_invalid_arg | 入参clone_list为nullptr | 确保入参正确 |
| napi_serialize | 将ArkTS对象转换为native数据。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_serialize | 将ArkTS对象转换为native数据。 | napi_invalid_arg | 入参transfer_list既不是undefined，也不是js Array | 确保入参正确 |
| napi_serialize | 将ArkTS对象转换为native数据。 | napi_invalid_arg | 入参clone_list既不是undefined，也不是js Array | 确保入参正确 |
| napi_deserialize | 将native数据转为ArkTS对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_deserialize | 将native数据转为ArkTS对象。 | napi_invalid_arg | 入参buffer为nullptr | 确保入参正确 |
| napi_deserialize | 将native数据转为ArkTS对象。 | napi_invalid_arg | 入参object为nullptr | 确保入参正确 |
| napi_delete_serialization_data | 删除序列化数据。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_delete_serialization_data | 删除序列化数据。 | napi_invalid_arg | 入参buffer为nullptr | 确保入参正确 |
| napi_call_threadsafe_function_with_priority | 将指定优先级和入队方式的任务投递到ArkTS主线程。 | napi_invalid_arg | 入参func为nullptr | 确保入参正确 |
| napi_call_threadsafe_function_with_priority | 将指定优先级和入队方式的任务投递到ArkTS主线程。 | napi_invalid_arg | 入参priority不为napi_task_priority枚举类型 | 确保入参正确 |
| napi_call_threadsafe_function_with_priority | 将指定优先级和入队方式的任务投递到ArkTS主线程。 | napi_generic_failure | 入参func非法 | 根据hilog信息排查原因 |
| napi_call_threadsafe_function_with_priority | 将指定优先级和入队方式的任务投递到ArkTS主线程。 | napi_generic_failure | EventHandler不支持或EventHandler执行失败 | 根据hilog信息排查原因 |
| napi_is_sendable | 判断给定JS value是否是Sendable的。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_is_sendable | 判断给定JS value是否是Sendable的。 | napi_invalid_arg | 入参value为nullptr | 确保入参正确 |
| napi_is_sendable | 判断给定JS value是否是Sendable的。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_define_sendable_class | 创建一个Sendable类。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_define_sendable_class | 创建一个Sendable类。 | napi_invalid_arg | 入参utf8name为nullptr | 确保入参正确 |
| napi_define_sendable_class | 创建一个Sendable类。 | napi_invalid_arg | 入参constructor为nullptr | 确保入参正确 |
| napi_define_sendable_class | 创建一个Sendable类。 | napi_invalid_arg | 入参property_count大于0且入参properties为nullptr | 确保入参正确 |
| napi_define_sendable_class | 创建一个Sendable类。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_define_sendable_class | 创建一个Sendable类。 | napi_object_expected | 入参length值不为NAPI_AUTO_LENGTH，但超过INT_MAX | 确保入参正确 |
| napi_define_sendable_class | 创建一个Sendable类。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_sendable_object_with_properties | 使用给定的napi_property_descriptor创建一个Sendable对象。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_sendable_object_with_properties | 使用给定的napi_property_descriptor创建一个Sendable对象。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_sendable_array | 创建一个Sendable数组。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_sendable_array | 创建一个Sendable数组。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_sendable_array_with_length | 创建一个指定长度的Sendable数组。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_sendable_array_with_length | 创建一个指定长度的Sendable数组。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_sendable_arraybuffer | 创建一个Sendable ArrayBuffer。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_sendable_arraybuffer | 创建一个Sendable ArrayBuffer。 | napi_invalid_arg | 入参data为nullptr | 确保入参正确 |
| napi_create_sendable_arraybuffer | 创建一个Sendable ArrayBuffer。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_sendable_arraybuffer | 创建一个Sendable ArrayBuffer。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_create_sendable_typedarray | 创建一个Sendable TypedArray。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_create_sendable_typedarray | 创建一个Sendable TypedArray。 | napi_invalid_arg | 入参arraybuffer为nullptr | 确保入参正确 |
| napi_create_sendable_typedarray | 创建一个Sendable TypedArray。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_create_sendable_typedarray | 创建一个Sendable TypedArray。 | napi_invalid_arg | 入参type不为napi_typedarray_type类型 | 确保入参正确 |
| napi_create_sendable_typedarray | 创建一个Sendable TypedArray。 | napi_object_expected | 入参arraybuffer不为SharedArrayBuffer类型 | 确保入参正确 |
| napi_create_sendable_typedarray | 创建一个Sendable TypedArray。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_wrap_sendable | 包裹一个native实例到ArkTS对象中。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_wrap_sendable | 包裹一个native实例到ArkTS对象中。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_wrap_sendable | 包裹一个native实例到ArkTS对象中。 | napi_invalid_arg | 入参native_object为nullptr | 确保入参正确 |
| napi_wrap_sendable | 包裹一个native实例到ArkTS对象中。 | napi_object_expected | 入参js_object不是SendableObject类型 | 确保入参正确 |
| napi_wrap_sendable | 包裹一个native实例到ArkTS对象中。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_wrap_sendable_with_size | 包裹一个native实例到ArkTS对象中并指定大小。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_wrap_sendable_with_size | 包裹一个native实例到ArkTS对象中并指定大小。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_wrap_sendable_with_size | 包裹一个native实例到ArkTS对象中并指定大小。 | napi_invalid_arg | 入参native_object为nullptr | 确保入参正确 |
| napi_wrap_sendable_with_size | 包裹一个native实例到ArkTS对象中并指定大小。 | napi_object_expected | 入参js_object不是SendableObject类型 | 确保入参正确 |
| napi_wrap_sendable_with_size | 包裹一个native实例到ArkTS对象中并指定大小。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_unwrap_sendable | 获取ArkTS对象包裹的native实例。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_unwrap_sendable | 获取ArkTS对象包裹的native实例。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_unwrap_sendable | 获取ArkTS对象包裹的native实例。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_unwrap_sendable | 获取ArkTS对象包裹的native实例。 | napi_object_expected | 入参js_object不是SendableObject类型 | 确保入参正确 |
| napi_unwrap_sendable | 获取ArkTS对象包裹的native实例。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_remove_wrap_sendable | 移除并获取ArkTS对象包裹的native实例。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_remove_wrap_sendable | 移除并获取ArkTS对象包裹的native实例。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_remove_wrap_sendable | 移除并获取ArkTS对象包裹的native实例。 | napi_invalid_arg | 入参result为nullptr | 确保入参正确 |
| napi_remove_wrap_sendable | 移除并获取ArkTS对象包裹的native实例。 | napi_object_expected | 入参js_object不是SendableObject类型 | 确保入参正确 |
| napi_remove_wrap_sendable | 移除并获取ArkTS对象包裹的native实例。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
| napi_wrap_enhance | 在ArkTS对象上绑定一个Node-API模块对象实例并指定实例大小，开发者可以指定绑定的回调函数是否异步执行（若异步则需线程安全）。 | napi_invalid_arg | 入参env为nullptr | 确保入参正确 |
| napi_wrap_enhance | 在ArkTS对象上绑定一个Node-API模块对象实例并指定实例大小，开发者可以指定绑定的回调函数是否异步执行（若异步则需线程安全）。 | napi_invalid_arg | 入参js_object为nullptr | 确保入参正确 |
| napi_wrap_enhance | 在ArkTS对象上绑定一个Node-API模块对象实例并指定实例大小，开发者可以指定绑定的回调函数是否异步执行（若异步则需线程安全）。 | napi_invalid_arg | 入参native_object为nullptr | 确保入参正确 |
| napi_wrap_enhance | 在ArkTS对象上绑定一个Node-API模块对象实例并指定实例大小，开发者可以指定绑定的回调函数是否异步执行（若异步则需线程安全）。 | napi_object_expected | 入参js_object不是js Object类型 | 确保入参正确 |
| napi_wrap_enhance | 在ArkTS对象上绑定一个Node-API模块对象实例并指定实例大小，开发者可以指定绑定的回调函数是否异步执行（若异步则需线程安全）。 | napi_pending_exception | 调用该接口前或调用过程中出现未捕获的js异常 | 根据异常信息（hilog/crash栈）处理异常 |
