# OH_AI_TensorHandleArray


## 概述

张量数组结构体，用于存储张量数组指针和张量数组长度。

**系统能力：** SystemCapability.Ai.MindSpore

**起始版本：** 9

**相关模块：**[MindSpore](_mind_spore.md)

**所在头文件：**[model.h](model_8h.md)

## 汇总


### 成员变量

| 成员变量名称 | 描述 |
| -------- | -------- |
| [handle_num](#handle_num) | 张量数组长度。 |
| [handle_list](#handle_list) | 指向张量数组的指针。 |


## 结构体成员变量说明


### handle_list


```
OH_AI_TensorHandle* OH_AI_TensorHandleArray::handle_list
```

**描述：**

指向张量数组的指针。


### handle_num


```
size_t OH_AI_TensorHandleArray::handle_num
```

**描述：**

张量数组长度。
