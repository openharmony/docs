# Node-API接口返回状态码介绍
## 概述
绝大部分Node-API接口在执行结束后，会返回一个数据类型为napi_status的状态码枚举，表示操作成功与否的相关信息。本文将重点介绍Node-API接口返回的非napi_ok的状态码详情与修复建议。
## 各Node-API接口返回的非napi_ok状态码介绍
<table width="1499.75" border="0" cellpadding="0" cellspacing="0" style='width:899.85pt;border-collapse:collapse;table-layout:fixed;'>
   <col width="319" class="xl65" style='mso-width-source:userset;mso-width-alt:9332;'/>
   <col width="259" class="xl65" style='mso-width-source:userset;mso-width-alt:7577;'/>
   <col width="278.75" class="xl65" style='mso-width-source:userset;mso-width-alt:8155;'/>
   <col width="317" class="xl65" style='mso-width-source:userset;mso-width-alt:9274;'/>
   <col width="326" class="xl65" style='mso-width-source:userset;mso-width-alt:9537;'/>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="26" width="319" style='height:15.60pt;width:191.40pt;' x:str><b>接口名称</b></td>
    <td class="xl66" width="259" style='width:155.40pt;' x:str><b>接口功能</b></td>
    <td class="xl67" width="278.75" style='width:167.25pt;' x:str><b>可能返回的非napi_ok状态码</b></td>
    <td class="xl67" width="317" style='width:190.20pt;' x:str><b>原因</b></td>
    <td class="xl67" width="326" style='width:195.60pt;' x:str><b>修复建议</b></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="26" style='height:15.60pt;' x:str>napi_module_register</td>
    <td class="xl66" x:str>napi native模块注册接口。</td>
    <td class="xl67" x:str>不涉及</td>
    <td class="xl67" x:str>不涉及</td>
    <td class="xl67" x:str>不涉及</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_get_last_error_info</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>获取napi_extended_error_info结构体，其中包含最近一次<span style='display:none;'>出现的error信息。</span></td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_throw</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>抛出一个js value。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参error为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参error不为js Error类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_throw_error</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>抛出一个带文本信息的js Error。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参msg为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_throw_type_error</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>抛出一个带文本信息的js TypeError。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参msg为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_throw_range_error</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>抛出一个带文本信息的js RangeError。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参msg为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_is_error</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>判断napi_value是否表示为一个error对象。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_create_error</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>创建并获取一个带文本信息的js Error。</td>
    <td class="xl67" rowspan="5" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参msg为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参code不为nullptr，但不为js St<span style='display:none;'>ring或js Number类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参msg不为nullptr，但不为js Str<span style='display:none;'>ing类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_create_type_error</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>创建并获取一个带文本信息的js TypeError。</td>
    <td class="xl67" rowspan="5" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参msg为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参code不为nullptr，但不为js St<span style='display:none;'>ring或js Number类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参msg不为nullptr，但不为js Str<span style='display:none;'>ing类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_create_range_error</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>创建并获取一个带文本信息的js RangeError。</td>
    <td class="xl67" rowspan="5" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参msg为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参code不为nullptr，但不为js St<span style='display:none;'>ring或js Number类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参msg不为nullptr，但不为js Str<span style='display:none;'>ing类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_get_and_clear_last_exception</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>获取并清除最近一次出现的异常。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_is_exception_pending</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>判断是否出现了异常。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="26" style='height:15.60pt;' x:str>napi_fatal_error</td>
    <td class="xl66" x:str>引发致命错误以立即终止进程<span style='display:none;'>。</span></td>
    <td class="xl67" x:str>不涉及</td>
    <td class="xl67" x:str>不涉及</td>
    <td class="xl67" x:str>不涉及</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_open_handle_scope</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>创建一个上下文环境使用。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_close_handle_scope</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>关闭传入的上下文环境，关闭后，全部在其中声明的引用都将被关闭。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参scope为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_handle_scope_mismatch</td>
    <td class="xl67" x:str>napi_open_handle_scope调用次数小<span style='display:none;'>于napi_close_handle_scope</span></td>
    <td class="xl67" x:str>napi_open_handle_scope和napi_clos<span style='display:none;'>e_handle_scope需要成对使用</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_open_escapable_handle_scope</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>创建出一个可逃逸的handle scope，可将范围内声明的值返<span style='display:none;'>回到父作用域。</span></td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_close_escapable_handle_scope</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>关闭传入的可逃逸的handle scope。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参scope为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_handle_scope_mismatch</td>
    <td class="xl67" x:str>napi_open_escapable_handle_scope<span style='display:none;'>调用次数小于napi_close_escapable_handle_scope</span></td>
    <td class="xl67" x:str>napi_open_escapable_handle_scope<span style='display:none;'>和napi_close_escapable_handle_scope需要成对使用</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_escape_handle</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>提升传入的js object的生命周期到其父作用域。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参scope为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参escapee为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_escape_called_twice</td>
    <td class="xl67" x:str>该scope已经调用过napi_escape_han<span style='display:none;'>dle</span></td>
    <td class="xl67" x:str>请勿重复调用napi_escape_handle</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_create_reference</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>为Object创建一个reference，以延长其生命周期。调用者需要自己管理reference生命周<span style='display:none;'>期。</span></td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_delete_reference</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>删除传入的reference。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参ref为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_reference_ref</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>增加传入的reference的引用计数，并获取该计数。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参ref为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_reference_unref</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>减少传入的reference的引用计数，并获取该计数。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参ref为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_get_reference_value</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>获取与reference相关联的js Object。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参ref为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_array</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>创建并获取一个js Array。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_array_with_length</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>创建并获取一个指定长度的js Array。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_create_arraybuffer</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>创建并获取一个指定大小的js ArrayBuffer。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参data为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_create_external</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>分配一个附加有外部数据的js value。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_create_external_arraybuffer</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>分配一个附加有外部数据的js ArrayBuffer。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参external_data为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参finalize_cb为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_object</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>创建一个默认的js Object。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_create_symbol</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>创建一个js Symbol。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参description不为nullptr，且不<span style='display:none;'>是js String类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_create_typedarray</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>通过现有的ArrayBuffer创建一个js TypeArray。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参arraybuffer为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参type不为napi_typedarray_type<span style='display:none;'>类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_arraybuffer_expected</td>
    <td class="xl67" x:str>入参arraybuffer不为js ArrayBuffe<span style='display:none;'>r类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_create_dataview</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>通过现有的ArrayBuffer创建一个js DataView。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参arraybuffer为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_arraybuffer_expected</td>
    <td class="xl67" x:str>入参arraybuffer不为js ArrayBuffe<span style='display:none;'>r类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" rowspan="2" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>入参length与入参byte_offset相加<span style='display:none;'>超过入参arraybuffer的byte长度</span></td>
    <td class="xl67" x:str>需要检查访问长度</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_int32</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>通过一个C的int32_t数据创建js Number。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_uint32</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>通过一个C的uint32_t数据创建js Number。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_int64</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>通过一个C的int64_t数据创建js Number。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_double</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>通过一个C的double数据创建js Number。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_create_string_latin1</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>通过ISO-8859-1编码的C字符串数据创建js String。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参str为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_create_string_utf8</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>通过UTF8编码的C字符串数据创建js String。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参str为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_create_string_utf16</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>通过UTF16编码的C字符串数据创建js String。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参str为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参length值不为NAPI_AUTO_LENGTH<span style='display:none;'>，但超过INT_MAX</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_get_array_length</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>获取array的length。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_array_expected</td>
    <td class="xl67" x:str>入参value既不是js Array类型，也<span style='display:none;'>不是SharedArray类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_arraybuffer_info</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取ArrayBuffer的底层data buffer及其长度。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参arraybuffer为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参byte_length为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_arraybuffer_expected</td>
    <td class="xl67" x:str>入参arraybuffer既不是js ArrayBuf<span style='display:none;'>fer类型，也不是SharedArrayBuffer类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_get_prototype</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>获取给定js Object的prototype。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_get_typedarray_info</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>获取给定TypedArray的各种属性。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参typedarray为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参typedarray既不是js TypedArra<span style='display:none;'>y类型，也不是ShareTypedArray类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_get_dataview_info</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>获取给定DataView的各种属性。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参dataview为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参dataview不为js DataView类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_value_bool</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取给定js Boolean对应的C bool值。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_boolean_expected</td>
    <td class="xl67" x:str>入参value不为js Bool类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_value_double</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取给定js Number对应的C double值。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_number_expected</td>
    <td class="xl67" x:str>入参value不为js Number类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_value_external</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取先前通过napi_create_external()传递的外部数据指针。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参value不为external类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_value_int32</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取给定js Number对应的C int32值。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_number_expected</td>
    <td class="xl67" x:str>入参value不为js Number类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_value_int64</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取给定js Number对应的C int64值。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_number_expected</td>
    <td class="xl67" x:str>入参value不为js Number类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_value_string_latin1</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取给定js value对应的ISO-8859-1编码的字符串。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参buf与result都为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_string_expected</td>
    <td class="xl67" x:str>入参value不为js String类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_value_string_utf8</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取给定js value对应的UTF8编码的字符串。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参buf与result都为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_string_expected</td>
    <td class="xl67" x:str>入参value不为js String类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_value_string_utf16</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取给定js value对应的UTF16编码的字符串。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参buf与result都为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_string_expected</td>
    <td class="xl67" x:str>入参value不为js String类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_value_uint32</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取给定js Number对应的C uint32值。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_number_expected</td>
    <td class="xl67" x:str>入参value不为js Number类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_get_boolean</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>根据给定的C boolean值，获取js bool对象。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_get_global</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>获取global对象。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_get_null</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>获取null对象。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_get_undefined</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>获取undefined对象。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_coerce_to_bool</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>将给定的js value强转成js Boolean。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_coerce_to_number</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>将给定的js value强转成js Number。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_coerce_to_object</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>将给定的js value强转成js Object。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_coerce_to_string</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>将给定的js value强转成js String。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_typeof</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>获取给定js value的js type。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="182" rowspan="7" style='height:109.20pt;border-right:none;border-bottom:none;' x:str>napi_instanceof</td>
    <td class="xl66" rowspan="7" style='border-right:none;border-bottom:none;' x:str>判断给定object是否为给定constructor的实例。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="6" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参constructor为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_function_expected</td>
    <td class="xl67" x:str>入参constructor不为js Function类<span style='display:none;'>型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_is_array</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>判断给定js value是否为array。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_is_arraybuffer</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>判断给定js value是否为ArrayBuffer。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_is_typedarray</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>判断给定js value是否表示一个TypedArray。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_is_dataview</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>判断给定js value是否表示一个DataView。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_is_date</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>判断给定js value是否为js Date对象。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_strict_equals</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>判断给定的两个js value是否严格相等。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参lhs为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参rhs为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_property_names</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>以字符串数组的形式获取对象的可枚举属性的名称。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_set_property</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>对给定Object设置属性。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参key为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_get_property</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>获取给定Object的给定属性。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参key为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_has_property</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>判断给定对象中是否存在给定属性。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参key为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_delete_property</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>尝试从给定Object中删除给定key属性。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参key为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_has_own_property</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>判断给定Object中是否有名为key的own property。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参key为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_set_named_property</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>对给定Object设置一个给定名称的属性。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参utf8name为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_get_named_property</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>获取给定Object中指定名称的属性。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参utf8name为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_has_named_property</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>判断给定Object中是否有给定名称的属性。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参utf8name为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_set_element</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>在给定Object的指定索引处，设置元素。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_get_element</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>获取给定Object指定索引处的元素。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_has_element</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>若给定Object的指定索引处拥有属性，获取该元素。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_delete_element</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>尝试删除给定Object的指定索引处的元素。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_define_properties</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>批量的向给定Object中定义属性。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参properties为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_name_expected</td>
    <td class="xl67" x:str>入参properties中的某个property没<span style='display:none;'>有设utf8name，且它的name既不是js String类型也不是js Symbol类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="182" rowspan="7" style='height:109.20pt;border-right:none;border-bottom:none;' x:str>napi_type_tag_object</td>
    <td class="xl66" rowspan="7" style='border-right:none;border-bottom:none;' x:str>将tag指针的值与Object关联。</td>
    <td class="xl67" rowspan="5" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参type_tag为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>js对象已被打过tag标记</td>
    <td class="xl67" x:str>js对象需未被打过标记</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>调用过程中出现未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参js_object不是js Object类型</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_check_object_type_tag</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>判断给定的tag指针是否被关联到了js Object上。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参type_tag为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参js_object不是js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_call_function</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>在Native方法中调用js function，即native call js。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参func为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参argc大于0且argv为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_function_expected</td>
    <td class="xl67" x:str>入参func不为js Function类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_create_function</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>创建native方法给js使用，以便于js call native。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参cb为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>new c++对象失败</td>
    <td class="xl67" x:str>内存不足，检查是否有c++内存泄漏</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_get_cb_info</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>从给定的callback info中获取有关调用的详细信息，如参<span style='display:none;'>数和this指针。</span></td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参cbinfo为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_new_target</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取构造函数调用的new.target。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参cbinfo为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_new_instance</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>通过给定的构造函数，构建一个实例。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参constructor为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参argc大于0且argv为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_function_expected</td>
    <td class="xl67" x:str>入参constructor不为js Function类<span style='display:none;'>型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="182" rowspan="7" style='height:109.20pt;border-right:none;border-bottom:none;' x:str>napi_define_class</td>
    <td class="xl66" rowspan="7" style='border-right:none;border-bottom:none;' x:str>定义与C++类相对应的JavaScript类。</td>
    <td class="xl67" rowspan="5" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="6" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参utf8name为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参constructor为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参property_count大于0且propert<span style='display:none;'>ies为nullptr</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参length值不为NAPI_AUTO_LENGTH<span style='display:none;'>，但超过INT_MAX</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_wrap</td>
    <td class="xl66" rowspan="6" style='border-right:none;border-bottom:none;' x:str>在js object上绑定一个native对象实例。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参native_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参finalize_cb为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参js_object不是js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_unwrap</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>从js object上获取先前绑定的native对象实例。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参js_object不是js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_remove_wrap</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>从js object上获取先前绑定的native对象实例，并解除绑定。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参js_object不是js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_create_async_work</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>创建一个异步工作对象。</td>
    <td class="xl67" rowspan="5" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参async_resource_name为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参execute为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参complete为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_delete_async_work</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>释放先前创建的异步工作对象。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参work为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_queue_async_work</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>将异步工作对象加到队列，由底层去调度执行。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参work为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_cancel_async_work</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>取消入队的异步任务。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参work为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_async_init</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>创建一个异步资源上下文环境（不支持与async_hook相关能力）。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参async_resource_name为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="182" rowspan="7" style='height:109.20pt;border-right:none;border-bottom:none;' x:str>napi_make_callback</td>
    <td class="xl66" rowspan="7" style='border-right:none;border-bottom:none;' x:str>在异步资源上下文环境中回调JS函数(不支持与async_hook相关能力)。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="6" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参func为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参recv为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参argc大于0且argv为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参recv不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_function_expected</td>
    <td class="xl67" x:str>入参func不为js Function类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_async_destroy</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>销毁先前创建的异步资源上下文环境（不支持与async_hook<span style='display:none;'>相关能力）。</span></td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参async_context为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_open_callback_scope</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>创建一个回调作用域（不支持与async_hook相关能力）。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_close_callback_scope</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>关闭先前创建的回调作用域（不支持与async_hook相关能力）。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参scope为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>new c++对象失败</td>
    <td class="xl67" x:str>内存不足，检查是否有c++内存泄漏</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_callback_scope_mismatch</td>
    <td class="xl67" x:str>napi_open_callback_scope调用次数<span style='display:none;'>小于napi_close_callback_scope</span></td>
    <td class="xl67" x:str>napi_open_callback_scope和napi_cl<span style='display:none;'>ose_callback_scope需要成对使用</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="26" style='height:15.60pt;' x:str>napi_get_node_version</td>
    <td class="xl66" x:str>获取node的版本信息。</td>
    <td class="xl67" x:str>不涉及</td>
    <td class="xl67" x:str>不涉及</td>
    <td class="xl67" x:str>不涉及</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_get_version</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>获取Node运行时支持的最高 N-API 版本。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_create_promise</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>创建一个延迟对象和js promise。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参deferred为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参promise为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_resolve_deferred</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>resolve与js promise对象关联的延迟函数。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参deferred为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参resolution为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_reject_deferred</td>
    <td class="xl66" rowspan="4" style='border-right:none;border-bottom:none;' x:str>reject与js promise对象关联的延迟函数。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参deferred为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参rejection为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_is_promise</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>判断给定js value是否为promise对象。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参is_promise为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_get_uv_event_loop</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>获取当前libuv loop实例。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参loop为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>入参env已销毁</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="208" rowspan="8" style='height:124.80pt;border-right:none;border-bottom:none;' x:str>napi_create_threadsafe_function</td>
    <td class="xl66" rowspan="8" style='border-right:none;border-bottom:none;' x:str>创建线程安全函数。</td>
    <td class="xl67" rowspan="6" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参async_resource_name为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参initial_thread_count为0或者<span style='display:none;'>大于128</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参func与call_js_cb都为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>new c++对象失败</td>
    <td class="xl67" x:str>内存不足，检查是否有c++内存泄漏</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" rowspan="2" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>uv_loop_t为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>NA</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>uv_async_init失败</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_get_threadsafe_function_context</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>获取线程安全函数中的context。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参func为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="182" rowspan="7" style='height:109.20pt;border-right:none;border-bottom:none;' x:str>napi_call_threadsafe_function</td>
    <td class="xl66" rowspan="7" style='border-right:none;border-bottom:none;' x:str>调用线程安全函数。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参func为nullptr</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>threadsafe_function已关闭</td>
    <td class="xl67" x:str>请勿在napi_release_threadsafe_fun<span style='display:none;'>ction关闭了func后再调用本接口</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_queue_full</td>
    <td class="xl67" x:str>入参is_blocking为napi_tsfn_nonbl<span style='display:none;'>ocking且queue已满</span></td>
    <td class="xl67" x:str>增大max_queue_size大小。或is_bloc<span style='display:none;'>king改为napi_tsfn_blocking</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" rowspan="2" x:str>napi_closing</td>
    <td class="xl67" x:str>threadsafe_function正在关闭</td>
    <td class="xl67" x:str>请勿在napi_release_threadsafe_fun<span style='display:none;'>ction关闭了func后再调用本接口</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参env已销毁，且env地址又被新en<span style='display:none;'>v复用</span></td>
    <td class="xl67" x:str>请勿在env销毁后再使用本接口</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" rowspan="2" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>uv_async_send失败</td>
    <td class="xl67" x:str>NA</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参env已销毁</td>
    <td class="xl67" x:str>请勿在env销毁后再使用本接口</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_acquire_threadsafe_function</td>
    <td class="xl66" rowspan="2" style='border-right:none;border-bottom:none;' x:str>指示线程安全函数可以开始使用。</td>
    <td class="xl67" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参func为nullptr</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>threadsafe_function正在关闭/已关<span style='display:none;'>闭</span></td>
    <td class="xl67" x:str>请勿在napi_release_threadsafe_fun<span style='display:none;'>ction关闭了func后再调用本接口</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_release_threadsafe_function</td>
    <td class="xl66" rowspan="5" style='border-right:none;border-bottom:none;' x:str>指示线程安全函数将停止使用。</td>
    <td class="xl67" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参func为nullptr</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" rowspan="4" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>threadsafe_function正在关闭/已关<span style='display:none;'>闭</span></td>
    <td class="xl67" x:str>请勿在napi_release_threadsafe_fun<span style='display:none;'>ction关闭了func后再调用本接口</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>调用本接口时，占用threadsafe_fun<span style='display:none;'>ction的线程数是0</span></td>
    <td class="xl67" x:str>release次数需要与initial_thread_c<span style='display:none;'>ount和aquire匹配</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>uv_async_send失败</td>
    <td class="xl67" x:str>NA</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参env已销毁</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_ref_threadsafe_function</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>指示在主线程上运行的事件循环在线程安全函数被销毁之前不应退出。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参func为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>当前线程不是env所在线程</td>
    <td class="xl67" x:str>该接口只能从env所在线程调用</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_unref_threadsafe_function</td>
    <td class="xl66" rowspan="3" style='border-right:none;border-bottom:none;' x:str>指示在主线程上运行的事件循环可能会在线程安全函数被销毁之前退出。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参func为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>当前线程不是env所在线程</td>
    <td class="xl67" x:str>该接口只能从env所在线程调用</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_create_date</td>
    <td class="xl69" rowspan="3" style='border-right:none;border-bottom:none;' x:str>通过一个C的double数据创建js Date。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_get_date_value</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>获取给定js Date对应的C double值。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_date_expected</td>
    <td class="xl67" x:str>入参value不为js Date类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_bigint_int64</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>通过一个C的int64数据创建js BigInt。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_bigint_uint64</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>通过一个C的uint64数据创建js BigInt。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_create_bigint_words</td>
    <td class="xl69" rowspan="6" style='border-right:none;border-bottom:none;' x:str>通过一个C的uint64数组创建单个js BigInt。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参words为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参word_count大于等于INT_MAX</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" rowspan="2" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参(word_count*2)&gt;(1_MB/32)</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_get_value_bigint_int64</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>获取给定js BigInt对应的C int64值。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参lossless为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_bigint_expected</td>
    <td class="xl67" x:str>入参value不为js BigInt类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_get_value_bigint_uint64</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>获取给定js BigInt对应的C uint64值。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参lossless为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_bigint_expected</td>
    <td class="xl67" x:str>入参value不为js BigInt类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_get_value_bigint_words</td>
    <td class="xl69" rowspan="4" style='border-right:none;border-bottom:none;' x:str>获取给定js BigInt对应的信息，包括符号位、64位小端序数组和数组中的元素个数。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参word_count为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参value不为js BigInt类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_create_buffer</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>创建并获取一个指定大小的js Buffer。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参data为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参size为0或超过2MiB(2097152)</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_create_buffer_copy</td>
    <td class="xl69" rowspan="6" style='border-right:none;border-bottom:none;' x:str>创建并获取一个指定大小的js Buffer，并以给定数据进行初始化。</td>
    <td class="xl67" rowspan="5" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参data为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result_data为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参size为0或超过2MiB(2097152)</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_create_external_buffer</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>创建并获取一个指定大小的js Buffer，并以给定数据进行初始化，该接口可为Buffer附带额外数据。</td>
    <td class="xl67" rowspan="4" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参data为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参size为0或超过2MiB(2097152)</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_get_buffer_info</td>
    <td class="xl69" rowspan="3" style='border-right:none;border-bottom:none;' x:str>获取js Buffer底层data及其长度。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_arraybuffer_expected</td>
    <td class="xl67" x:str>入参value不为js ArrayBuffer类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_is_buffer</td>
    <td class="xl69" rowspan="3" style='border-right:none;border-bottom:none;' x:str>判断给定js value是否为Buffer对象。</td>
    <td class="xl67" rowspan="3" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_object_freeze</td>
    <td class="xl69" rowspan="4" style='border-right:none;border-bottom:none;' x:str>冻结给定的对象。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_object_seal</td>
    <td class="xl69" rowspan="4" style='border-right:none;border-bottom:none;' x:str>密封给定的对象。</td>
    <td class="xl67" rowspan="2" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="182" rowspan="7" style='height:109.20pt;border-right:none;border-bottom:none;' x:str>napi_get_all_property_names</td>
    <td class="xl69" rowspan="7" style='border-right:none;border-bottom:none;' x:str>获取一个数组，其中包含此对象过滤后的属性名称。</td>
    <td class="xl67" rowspan="5" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" rowspan="6" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参key_mode不在napi_key_collect<span style='display:none;'>ion_mode枚举范围内</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参key_conversion不在napi_key_c<span style='display:none;'>onversion枚举范围内</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参object不为js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_detach_arraybuffer</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>分离给定ArrayBuffer的底层数据。</td>
    <td class="xl71" rowspan="4" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参arraybuffer为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参arraybuffer是js Object类型，<span style='display:none;'>但不是js ArrayBuffer类型，也不是SharedArrayBuffer类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参arraybuffer已被detach过</td>
    <td class="xl67" x:str>需arraybuffer未被detach过</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参arraybuffer不为js Object类型</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_is_detached_arraybuffer</td>
    <td class="xl69" rowspan="4" style='border-right:none;border-bottom:none;' x:str>判断给定的ArrayBuffer是否已被分离过。</td>
    <td class="xl71" rowspan="4" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参arraybuffer为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参arraybuffer不为js ArrayBuffe<span style='display:none;'>r类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_run_script</td>
    <td class="xl69" rowspan="3" style='border-right:none;border-bottom:none;' x:str>将给定对象作为js代码运行。当前接口实际为空实现，可使用系统拓展接口napi_run_scr<span style='display:none;'>ipt_path接口，提升安全性。</span></td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参script为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="26" style='height:15.60pt;' x:str>napi_set_instance_data</td>
    <td class="xl66" x:str>绑定与当前运行的环境相关联<span style='display:none;'>的数据项。</span></td>
    <td class="xl67" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_get_instance_data</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>检索与当前运行的环境相关联的数据项。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参data为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_add_env_cleanup_hook</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>注册环境清理钩子函数。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参func为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_remove_env_cleanup_hook</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>取消环境清理钩子函数。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参func为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_add_async_cleanup_hook</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>注册清理异步钩子函数。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参hook为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl66" height="26" style='height:15.60pt;' x:str>napi_remove_async_cleanup_hook</td>
    <td class="xl66" x:str>取消清理异步钩子函数。</td>
    <td class="xl67" x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参remove_handle为nullptr</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>node_api_get_module_file_name</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>用于获取加载项加载位置的绝对路径。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_add_finalizer</td>
    <td class="xl69" rowspan="4" style='border-right:none;border-bottom:none;' x:str>当js Object中的对象被垃圾回收时调用注册的napi_finalize回调。</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参finalize_cb为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参js_object不是js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_fatal_exception</td>
    <td class="xl69" rowspan="4" style='border-right:none;border-bottom:none;' x:str>向js抛出 UncaughtException。</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参err为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参error不为js Error类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_queue_async_work_with_qos</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>将异步工作对象加到队列，由底层根据传入的qos优先级去<span style='display:none;'>调度执行。</span></td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参work为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_run_script_path</td>
    <td class="xl69" rowspan="3" style='border-right:none;border-bottom:none;' x:str>运行abc文件。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_load_module</td>
    <td class="xl69" rowspan="3" style='border-right:none;border-bottom:none;' x:str>将abc文件作为模块加载，返回模块的命名空间。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_object_with_properties</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>使用给定的napi_property_descriptor创建js Object。de<span style='display:none;'>scriptor的键名必须为 string，且不可转为number。</span></td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_object_with_named_properties</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>使用给定的napi_value和键名创建js Object。键名必须为<span style='display:none;'><span style='mso-spacerun:yes;'>&nbsp;</span>string，且不可转为number。</span></td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="208" rowspan="8" style='height:124.80pt;border-right:none;border-bottom:none;' x:str>napi_coerce_to_native_binding_object</td>
    <td class="xl69" rowspan="8" style='border-right:none;border-bottom:none;' x:str>强制将js Object和Native对象绑定。</td>
    <td class="xl71" rowspan="6" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参detach_cb为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参attach_cb为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参native_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>new c++对象失败</td>
    <td class="xl67" x:str>内存不足，检查是否有c++内存泄漏</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>js_object不是js Object类型</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_create_ark_runtime</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>创建基础运行时环境。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>g_createNapiEnvCallback为nullptr</td>
    <td class="xl67" x:str>NA</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_create_ark_runtime_only<span style='display:none;'>_one_env_per_thread</span></td>
    <td class="xl67" x:str>当前线程以创建过env</td>
    <td class="xl67" x:str>避免重复创建</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_create_ark_runtime_too_<span style='display:none;'>many_envs</span></td>
    <td class="xl67" x:str>达到最大ArkRuntime数量（64）或js<span style='display:none;'>线程数超上限（80）</span></td>
    <td class="xl67" x:str>避免滥用接口</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>创建ark_runtime失败</td>
    <td class="xl67" x:str>根据hilog信息排查原因</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_destroy_ark_runtime</td>
    <td class="xl69" rowspan="3" style='border-right:none;border-bottom:none;' x:str>销毁基础运行时环境。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>g_createNapiEnvCallback为nullptr</td>
    <td class="xl67" x:str>NA</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl67" x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_destroy_ark_runtime_env<span style='display:none;'>_not_exist</span></td>
    <td class="xl67" x:str>env未创建</td>
    <td class="xl67" x:str>与create接口配套使用</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_run_event_loop</td>
    <td class="xl69" rowspan="4" style='border-right:none;border-bottom:none;' x:str>触发底层的事件循环。</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参mode不为napi_event_mode枚举<span style='display:none;'>类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>env的loop为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>当前线程不是native线程</td>
    <td class="xl67" x:str>请使用napi_create_ark_runtime接口<span style='display:none;'>创建出来的env</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_stop_event_loop</td>
    <td class="xl69" rowspan="3" style='border-right:none;border-bottom:none;' x:str>停止底层的事件循环。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>env的loop为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>当前线程不是native线程</td>
    <td class="xl67" x:str>请使用napi_create_ark_runtime接口<span style='display:none;'>创建出来的env</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_load_module_with_info</td>
    <td class="xl69" rowspan="4" style='border-right:none;border-bottom:none;' x:str>将abc文件作为模块加载，返回模块的命名空间。可在新创建的ArkTS基础运行时环境中使用。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl73" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_generic_failure</td>
    <td class="xl67" x:str>模块加载失败</td>
    <td class="xl67" x:str>根据hilog信息排查原因</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用接口前有未捕获的js异常</td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="182" rowspan="7" style='height:109.20pt;border-right:none;border-bottom:none;' x:str>napi_serialize</td>
    <td class="xl69" rowspan="7" style='border-right:none;border-bottom:none;' x:str>将ArkTS对象转换为native数据。</td>
    <td class="xl71" rowspan="7" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="7" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参transfer_list为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参clone_list为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参transfer_list既不是undefined<span style='display:none;'>，也不是js Array</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参clone_list既不是undefined，<span style='display:none;'>也不是js Array</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_deserialize</td>
    <td class="xl69" rowspan="3" style='border-right:none;border-bottom:none;' x:str>将native数据转为ArkTS对象。</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参buffer为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_delete_serialization_data</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>删除序列化数据。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参buffer为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_call_threadsafe_function_with_priority</td>
    <td class="xl69" rowspan="4" style='border-right:none;border-bottom:none;' x:str>将指定优先级和入队方式的任务投递到ArkTS主线程。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参func为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参priority不为napi_task_priori<span style='display:none;'>ty枚举类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_generic_failure</td>
    <td class="xl67" x:str>入参func非法</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>根据hilog信息排查原因</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>EventHandler不支持或EventHandler<span style='display:none;'>执行失败</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="78.00" rowspan="3" style='height:46.80pt;border-right:none;border-bottom:none;' x:str>napi_is_sendable</td>
    <td class="xl69" rowspan="3" style='border-right:none;border-bottom:none;' x:str>判断给定JS value是否是Sendable的。</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参value为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="182" rowspan="7" style='height:109.20pt;border-right:none;border-bottom:none;' x:str>napi_define_sendable_class</td>
    <td class="xl69" rowspan="7" style='border-right:none;border-bottom:none;' x:str>创建一个Sendable类。</td>
    <td class="xl71" rowspan="5" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="6" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参utf8name为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参constructor为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参property_count大于0且入参pro<span style='display:none;'>perties为nullptr</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参length值不为NAPI_AUTO_LENGTH<span style='display:none;'>，但超过INT_MAX</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_sendable_object_with_properties</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>使用给定的napi_property_descriptor创建一个Sendable对<span style='display:none;'>象。</span></td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_sendable_array</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>创建一个Sendable数组。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="52" rowspan="2" style='height:31.20pt;border-right:none;border-bottom:none;' x:str>napi_create_sendable_array_with_length</td>
    <td class="xl69" rowspan="2" style='border-right:none;border-bottom:none;' x:str>创建一个指定长度的Sendable数组。</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="2" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="104" rowspan="4" style='height:62.40pt;border-right:none;border-bottom:none;' x:str>napi_create_sendable_arraybuffer</td>
    <td class="xl69" rowspan="4" style='border-right:none;border-bottom:none;' x:str>创建一个Sendable ArrayBuffer。</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参data为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="156.00" rowspan="6" style='height:93.60pt;border-right:none;border-bottom:none;' x:str>napi_create_sendable_typedarray</td>
    <td class="xl69" rowspan="6" style='border-right:none;border-bottom:none;' x:str>创建一个Sendable TypedArray。</td>
    <td class="xl75" rowspan="4" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="5" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参arraybuffer为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参type不为napi_typedarray_type<span style='display:none;'>类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参arraybuffer不为SharedArrayBu<span style='display:none;'>ffer类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_wrap_sendable</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>包裹一个native实例到ArkTS对象中。</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参native_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参js_object不是SendableObject<span style='display:none;'>类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_wrap_sendable_with_size</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>包裹一个native实例到ArkTS对象中并指定大小。</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参native_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参js_object不是SendableObject<span style='display:none;'>类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_unwrap_sendable</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>获取ArkTS对象包裹的native实例。</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参js_object不是SendableObject<span style='display:none;'>类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_remove_wrap_sendable</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>移除并获取ArkTS对象包裹的native实例。</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参result为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参js_object不是SendableObject<span style='display:none;'>类型</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl69" height="130" rowspan="5" style='height:78.00pt;border-right:none;border-bottom:none;' x:str>napi_wrap_enhance</td>
    <td class="xl69" rowspan="5" style='border-right:none;border-bottom:none;' x:str>在ArkTS对象上绑定一个Node-API模块对象实例并指定实例大小，开发者可以指定绑定的回调函数是否异步执行（若异步则需线程安全）。</td>
    <td class="xl71" rowspan="3" style='border-right:none;border-bottom:none;' x:str>napi_invalid_arg</td>
    <td class="xl67" x:str>入参env为nullptr</td>
    <td class="xl71" rowspan="4" style='border-right:none;border-bottom:none;' x:str>确保入参正确</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参js_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>入参native_object为nullptr</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_object_expected</td>
    <td class="xl67" x:str>入参js_object不是js Object类型</td>
   </tr>
   <tr height="26" style='height:15.60pt;'>
    <td class="xl67" x:str>napi_pending_exception</td>
    <td class="xl67" x:str>调用该接口前或调用过程中出现未捕<span style='display:none;'>获的js异常</span></td>
    <td class="xl67" x:str>根据异常信息（hilog/crash栈）处理<span style='display:none;'>异常</span></td>
   </tr>
  </table>
