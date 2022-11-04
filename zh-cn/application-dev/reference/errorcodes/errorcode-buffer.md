# buffer错误码

## 10200001 参数范围越界错误

**错误信息**

The value of ${param} is out of range.

**错误描述**

调用接口时某个参数超出了其正常范围的取值。

**可能原因**

某个参数取值超出可用范围。

**处理步骤**

检查所传参数是否在可用取值范围内。

## 10200009 Buffer size 错误

**错误信息**

Buffer size must be a multiple of ${size}

**错误描述**

Buffer的长度必须是${size}的整数倍,${size}为16-bits,32-bits或者64-bits。

**可能原因**

Buffer的长度不是${size}的整数倍,${size}为16-bits,32-bits或者64-bits。

**处理步骤**

请检查Buffer的长度值。

## 10200013 只读属性设置错误

**错误信息**

Cannot set property ${propertyName} of Buffer which has only a getter.

**错误描述**

Buffer的属性${propertyName}只读，不能进行设置。

**可能原因**

将${propertyName}放在了等号左边（即对属性值进行设置）。

**处理步骤**

请检查属性${propertyName}是否在等号左边。