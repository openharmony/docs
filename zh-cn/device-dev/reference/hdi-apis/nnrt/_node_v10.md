# Node


## 概述

算子节点结构体。

nodeAttr参数是一段被序列化的数据，并调用OHOS的hdi的反序列化接口才能得到具体参数。 大致流程如下：

1. 定义算子参数的结构体，OP op{}，其中OP可以被替换为[NodeAttrTypes.idl](_node_attr_types_8idl_v10.md)的算子参数结构体，op是变量名；

2. 申明MessageParcle对象，用存储反序列化的数据，OHOS::MessageParcel data；

3. 将nodeAttr写入data中，data.WriteBuffer(nodeAttr.data(),nodeAttr.size())；

4. 将data中的数据反序列化到op结构体中，(void)OPBlockUnmarshalling(data, op)；

然后就可以在op中查看具体的算子的参数值。

例如： 某一个算子的 nodeType为NODE_TYPE_FULL_CONNECTION，那么它所对应的算子参数结构体应该为[FullConnection](_full_connection_v10.md)， 则该算子具有四个参数：hasBias，useAxis，axis和activationType。

则按照如下流程调用：

1. [FullConnection](_full_connection_v10.md) full_connection{};

2. OHOS::MessageParcel data;

3. data.WriteBuffer(nodeAttr.data(),nodeAttr.size());

4. (void)FullConnectionBlockUnmarshalling(data, full_connection);

至此FullConnection的四个参数就写入了full_connection中。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [name](#name) | 算子节点的名称。 | 
| enum [NodeType](_n_n_rt_v10.md#nodetype)[nodeType](#nodetype) | 算子节点的类型，详情请参考：[NodeType](_n_n_rt_v10.md#nodetype)。 | 
| byte[] [nodeAttr](#nodeattr) | 算子节点的参数对应的序列化数组。 | 
| unsigned int[] [inputIndex](#inputindex) | 算子节点的输入节点下标。 | 
| unsigned int[] [outputIndex](#outputindex) | 算子节点的输出节点下标。 | 
| enum [QuantType](_n_n_rt_v10.md#quanttype)[quantType](#quanttype) | 算子节点的量化参数，详情请参考：[QuantType](_n_n_rt_v10.md#quanttype)。 | 


## 类成员变量说明


### inputIndex

```
unsigned int [] Node::inputIndex
```

**描述**


算子节点的输入节点下标。


### name

```
String Node::name
```

**描述**


算子节点的名称。


### nodeAttr

```
byte [] Node::nodeAttr
```

**描述**


算子节点的参数对应的序列化数组。


### nodeType

```
enum NodeType Node::nodeType
```

**描述**


算子节点的类型，详情请参考：[NodeType](_n_n_rt_v10.md#nodetype)。


### outputIndex

```
unsigned int [] Node::outputIndex
```

**描述**


算子节点的输出节点下标。


### quantType

```
enum QuantType Node::quantType
```

**描述**


算子节点的量化参数，详情请参考：[QuantType](_n_n_rt_v10.md#quanttype)。
