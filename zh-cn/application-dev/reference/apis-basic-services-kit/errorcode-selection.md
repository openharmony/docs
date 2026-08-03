# 划词服务错误码

<!--Kit: Basic Services Kit-->
<!--Subsystem: SelectionInput-->
<!--Owner: @no86-->
<!--Designer: @no86-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 33600001 划词服务调用异常

**错误信息**

Selection service invocation exception.

**错误描述**

划词应用调用划词服务接口时，若划词服务或其依赖服务出现异常，或调用createPanel接口重复创建同类型面板，系统会报此错误码。

**可能原因**

1. 划词服务内部运行异常。
2. 划词服务依赖的其他系统服务出现异常。
3. 重复创建同类型面板。单个划词应用仅允许创建一个MENU_PANEL和一个MAIN_PANEL。

**处理步骤**

1. 检查划词服务是否正常运行。
2. 若服务异常，重启设备后重新调用接口。
3. 若重启后问题仍然存在，请联系技术人员获取支持。
4. 避免重复创建同类型面板，单个划词应用仅允许创建一个MENU_PANEL和一个MAIN_PANEL。

## 33600002 划词面板已被销毁

**错误信息**

This selection panel has been destroyed.

**错误描述**

当对划词面板进行操作时，若该面板已被销毁，系统会报此错误码。

**可能原因**

划词面板已被销毁，对已销毁的面板对象继续操作。

**处理步骤**

1. 在操作划词面板前，判断面板对象是否有效。
2. 若面板已被销毁，需重新创建面板后再进行操作。
3. 避免在面板销毁后继续持有并操作该面板对象。

## 33600003 调用接口的应用与系统设置中选择的应用不匹配

**错误信息**

The application calling the API does not match the application selected in the system settings.

**错误描述**

当用户使用非系统设置中选中的划词应用调用划词服务接口时，系统会报此错误码。

**可能原因**

调用划词服务接口的应用不是用户在系统设置中选定的划词应用。

**处理步骤**

1. 在系统设置中检查当前选中的划词应用是否为本应用。
2. 若本应用不是当前选中的划词应用，请切换划词应用为本应用后再调用接口。

## 33600004 该接口被调用过于频繁

**错误信息**

The interface is called too frequently.

**错误描述**

当同一接口在短时间内被频繁调用时，系统会报此错误码。

**可能原因**

该接口在500ms内被调用超过了50次。

**处理步骤**

确保在监听到selectionCompleted事件后再调用getSelectionContent接口，不要频繁调用。

## 33600005 接口调用时机错误

**错误信息**

The interface is called at the wrong time.

**错误描述**

在未监听到selectionCompleted事件的情况下调用getSelectionContent接口时，系统会报此错误码。

**可能原因**

接口调用时机错误，用户此时未进行划词操作，划词流程尚未触发。正确的调用时序为：监听到selectionCompleted事件后，方可调用getSelectionContent接口。

**处理步骤**

重新触发划词，在监听到selectionCompleted事件后调用getSelectionContent接口。

## 33600006 当前应用禁止获取内容

**错误信息**

The current application is prohibited from accessing content.

**错误描述**

当划词服务尝试获取当前应用的文本内容时，若当前应用禁止该获取操作，系统会报此错误码。

**可能原因**

当前应用设置了文本内容不可被其他应用获取（如设置了CopyOptions.InApp）。

**处理步骤**

1. 切换到允许划词的应用后，在监听到selectionCompleted事件后再调用getSelectionContent接口。
2. 若需要在当前应用中使用划词功能，请联系应用开发者确认该应用是否支持获取文本内容。

## 33600007 划词内容长度超出范围

**错误信息**

The length of selected content is out of range.

**错误描述**

当划词选中的文本内容长度超出允许范围（6000字节）时，系统会报此错误码。

**可能原因**

当前选中的文本内容超过了6000个字节的长度限制。

**处理步骤**

选中1到6000个字节（包含1和6000）的文本后，在监听到selectionCompleted事件后再调用getSelectionContent接口。

## 33600008 获取选中内容超时

**错误信息**

Getting the selected content times out.

**错误描述**

当划词服务从目标应用获取选中的文本内容时，若目标应用在规定时间（100ms）内未返回内容，系统会报此错误码。

**可能原因**

1. 整机负载较高。
2. 目标应用出现异常。
3. 目标应用的复制逻辑较为复杂。

**处理步骤**

1. 在监听到selectionCompleted事件后重新调用getSelectionContent接口，确认是否为偶发超时。
2. 若持续超时，检查目标应用的响应状态及系统资源情况。
3. 如问题持续存在，请联系技术人员获取支持。
