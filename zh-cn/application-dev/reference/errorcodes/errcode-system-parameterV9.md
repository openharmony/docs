# 系统参数错误码

## 401 输入参数丢失或无效

**错误信息**

Input parameter is missing or invalid.

**错误描述**

当系统参数key值为空字符、非法字符或长度超出范围时，系统会报此错误码。

**可能原因**

接口的参数值超出设置范围或者含有特殊字符，比如，key最长96个字符。

**处理步骤**

修改key值为合法字符串。

## 14700101 找不到系统参数

**错误信息**

System parameter can not be found.

**错误描述**

workspace中没有相应节点，或者没有设置key值，系统会报此错误码。

**可能原因**

改参数没有设置， 或者没有设置成功。

**处理步骤**

成功设置参数。

## 14700102 系统参数值无效

**错误信息**

System parameter value is invalid.

**错误描述**

当系统参数value值为空字符、非法字符或长度超出范围时，系统会报此错误码。

**可能原因**

接口的参数值超出设置范围或者含有特殊字符，比如，"const..param.xxx"。

**处理步骤**

修改value值为合法字符串。

## 14700103 系统权限操作权限被拒绝

**错误信息**

System permission operation permission denied.

**错误描述**

系统参数没有DAC或MAC权限时，系统会报此错误码。

**可能原因**

没有配置DAC或MAC权限。

**处理步骤**

添加相应的DAC或MAC权限。

## 14700104 系统内部错误，包括内存不足，死锁等

**错误信息**

System internal error including out of memory, deadlock etc.

**错误描述**

当试图修改const属性参数、socket连接失败、内存拷贝失败等错误时，系统会报此错误码。

**可能原因**

当socket连接异常，添加节点或获取节点失败。

**处理步骤**

无法预知的系统错误，如内存申请失败。