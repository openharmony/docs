# StridedSlice


## 概述

根据步长和索引对输入张量进行切片提取。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_STRIDED_SLICE。

输入：

- x，n维tensor。

- begin，1维tensor，begin的长度等于n，begin[i]指定第i维上截取的起点。

- end，1维tensor，end的长度等于n，end[i]指定第i维上截取的终点。

- strides，1维张量，strides的长度等于n，strides[i]指定第i维上截取的步长，允许存在负值。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 输入的张量有如下情况：begin, end 和 strides 的shape必须相同。 begin,end 是从0开始进行索引。 strides 的元素必须非零。

输出：

- output，堆叠运算后的tensor，数据类型与x相同。输出维度rank(x[0])+1维。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long [beginMask](#beginmask) | 表示切片的起始索引。 | 
| long [endMask](#endmask) | 表示切片的结束索引。 | 
| long [ellipsisMask](#ellipsismask) | 一个整数，用于解除begin和end的限制。 | 
| long [newAxisMask](#newaxismask) | 用于新增维度。 | 
| long [shrinkAxisMask](#shrinkaxismask) | 用于压缩指定维度。 | 


## 类成员变量说明


### beginMask

```
long StridedSlice::beginMask
```

**描述**


表示切片的起始索引。

beginMask使用二进制编码方式对输入x的不同维度进行标志，beginMask的第i位设置为1则begin[i]参数对应的第i维度设置无效，表示该维度的起始索引从0开始。默认值为0。


### ellipsisMask

```
long StridedSlice::ellipsisMask
```

**描述**


一个整数，用于解除begin和end的限制。

不为0的维度不需要进行切片操作。 将ellipsisMask转成二进制表示，如果ellipsisMask的第i位为1，则对于第i维，从第一个元素开始，以strides[i]为步长，截取元素直到tensor边界。


### endMask

```
long StridedSlice::endMask
```

**描述**


表示切片的结束索引。功能类似begin_mask。

endMask使用二进制编码方式对输入x的不同维度进行标志，第i位设置为1则end参数对应的该维度设置无效，表示该维度切分的结束索引到列表最后，即切分到尽可能大的维度。默认值为0。


### newAxisMask

```
long StridedSlice::newAxisMask
```

**描述**


用于新增维度。

newAxisMask使用二进制编码方式对输入x的不同维度进行标志，如果第i位出现1，则begin、end、stride对所有维度参数无效，并在第i位上增加一个大小为1的维度。


### shrinkAxisMask

```
long StridedSlice::shrinkAxisMask
```

**描述**


用于压缩指定维度。

将shrinkAxisMask转成二进制表示，如果shrinkAxisMask的第i位位1，则舍去第i维所有元素，第i维长度压缩至1。
