# 语言基础类库错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](errorcode-universal.md)。

## 10200001 参数范围越界错误

**错误信息**

The value of ${param} is out of range.

**错误描述**

调用接口时某个参数超出了其正常范围的取值。

**可能原因**

某个参数索引超出可用范围。

**处理步骤**

检查输入参数的索引是否越界。

## 10200002 参数解析错误

**错误信息**

Invalid ${param} string.

**错误描述**

规范字符串解析失败。

**可能原因**

调用接口时，某个字符串类型的参数为非规范的字符串，导致解析该字符串失败。

**处理步骤**

检查输入字符串的格式。

## 10200003 Worker初始化失败

**错误信息**

Worker initialization failure.

**错误描述**

调用接口时Worker未能正常初始化。

**可能原因**

1. 创建Worker的数量超出限制。
2. 设置Worker对象的选择项不正确。

**处理步骤**

1. 检查Worker的数量是否超出8个，如果存在，及时销毁空闲的Worker。
2. 如果设置WorkerOptions，检查参数类型及其合法性。

## 10200004 Worker处于非运行状态

**错误信息**

Worker instance is not running.

**错误描述**

调用接口时Worker对象处于非运行状态。

**可能原因**

当调用接口时，Worker实例化对象已经被销毁，或正在被销毁。

**处理步骤**

当调用接口时，确保Worker对象处于正常运行状态，未被执行销毁操作。

## 10200005 Worker不支持某API

**错误信息**

The invoked API is not supported in workers.

**错误描述**

Worker不支持某API。

**可能原因**

调用Worker线程中不支持的API。

**处理步骤**

确保使用Worker线程中支持的API。

## 10200006 Worker传输信息序列化异常

**错误信息**

An exception occurred during serialization.

**错误描述**

Worker传输信息序列化异常。

**可能原因**

传输信息不属于合法的可序列化对象。

**处理步骤**

确保传输信息属于Worker支持的合法序列化对象。

## 10200007 Worker文件路径异常

**错误信息**

The worker file patch is invalid path.

**错误描述**

文件路径异常，无法正确加载Worker。

**可能原因**

Worker文件路径异常导致无法正常编译生成合法的worker.abc。

**处理步骤**

确保Worker文件路径符合创建Worker对象的规范，参见API参考中[constructor<sup>9+</sup>](../apis/js-apis-worker.md#constructor9)接口的示例。

## 10200009 Buffer的长度错误

**错误信息**

Buffer size must be a multiple of ${size}.

**错误描述**

Buffer的长度错误，不符合要求。

**可能原因**

Buffer的长度错误，不符合要求。Buffer长度要求为size的整数倍。其中size为16-bits、32-bits或者64-bits。

**处理步骤**

确保Buffer长度符合要求。
Buffer长度要求为size的整数倍。其中size为16-bits、32-bits或者64-bits。

## 10200010 容器为空

**错误信息**

The container is empty.

**错误描述**

操作的容器为空。

**可能原因**

操作的容器为空，未添加相关元素。

**处理步骤**

确保操作的容器不为空，空容器请先向容器内添加元素。

## 10200011 传入的this.object不是容器类的实例

**错误信息**

The {methodName} method cannot be bound.

**错误描述**

调用语言容器类的方法时，传入的this.object不是容器类的实例语言，容器类的方法不支持bind。

**可能原因**

容器类的方法不支持bind。

**处理步骤**

1. 检查是否使用bind API调用语言容器类的方法。
2. 检查是否把语言容器类的方法赋值给不是语言容器实例的对象来调用。

## 10200012 构造函数调用异常

**错误信息**

The {className}'s constructor cannot be directly invoked.

**错误描述**

构造语言容器类的构造方法不支持直接调用。

**可能原因**

调用构造函数时未使用new关键字。

**处理步骤**

检查是否使用直接调用了语言容器类的方法，建议使用new关键字创建语言容器类。

## 10200013 只读属性设置错误

**错误信息**

Cannot set property ${propertyName} of Buffer which has only a getter.

**错误描述**

Buffer的属性${propertyName}只读，不能进行设置。

**可能原因**

对Buffer的只读属性进行设置，导致异常。

**处理步骤**

不要对Buffer只读属性进行相关设置。

## 10200014 非Concurrent函数错误

**错误信息**

The function is not mark as concurrent.

**错误描述**

Function未被标记为concurrent。

**可能原因**

任务池执行的任务所需的函数未添加@Concurrent。

**处理步骤**

检查任务池执行的任务所需的函数，并补上@Concurrent装饰器。

## 10200015 取消不存在的任务错误

**错误信息**

The task does not exist when it is canceled.

**错误描述**

取消一个不存在的任务。

**可能原因**

取消任务时，该任务并不存在于任务池中。

**处理步骤**

取消任务前，确保任务已被taskpool.execute调用进入任务池且任务未执行完成。无法保证时，需要捕获异常。

## 10200016 取消正在执行的任务错误

**错误信息**

The task is executing when it is canceled.

**错误描述**

取消正在执行的任务。

**可能原因**

取消任务时，该任务已经处于执行状态。

**处理步骤**

取消任务前，确保任务已被taskpool.execute调用进入任务池且任务未开始执行。无法保证时，需要捕获异常。

## 10200017 删除不存在的元素错误

**错误信息**

The element does not exist in this container.

**错误描述**

删除的元素不存在此容器中。

**可能原因**

删除元素时，此容器中不存在此元素。

**处理步骤**

删除元素前，确保元素存在于此容器中。

## 10200018 取消不存在的任务组错误

**错误信息**

The task group does not exist when it is canceled.

**错误描述**

取消一个不存在的任务组。

**可能原因**

取消任务组时，该任务组并不存在于任务池中。

**处理步骤**

取消任务组前，确保任务组已被taskpool.execute调用进入任务池且任务组内存在任务未执行完成。无法保证时，需要捕获异常。