# QuantParam


## 概述

量化参数结构体。

相关的公式如下，q为量化后的参数，r为真实参数， \( r_{max} \)为待量化数据的最大值， \( r_{min} \)待量化数据的最小值，round(x)为x四舍五入取整，clamp(x,min,max)为如下运算：

\[ \text{clamp}(x,min,max) = \begin{cases} \text{max} &amp; \text{ if } x &gt; \text{ max } \\ \text{min} &amp; \text{ if } x &lt; \text{ min } \\ x &amp; \text{ otherwise } \\ \end{cases} \]

- 浮点到定点的量化公式：
  $ \text{q}(x_i) = clamp(round(\frac{r}{scale}+zeroPoint), min , max) $

- 定点到浮点的反量化公式：
  $ \text{r}= (q-zeroPoint)\*scale $

- 量化参数scale由如下公式计算：
  $ scale = \frac{r_{max}-r_{min}}{q_{max}-q_{min}} $

- 量化参数zeroPoint由如下公式计算：
  $ zeroPoint = round(q_{min}-\frac{r_{min}}{scale}) $

- 量化参数 \( q_{min},q_{max} \) 如下公式计算：
  $ q_{min} = -(1&lt;&lt;(numBits-1)) $

  $ q_{max} = (1&lt;&lt;(numBits-1))-1 $

  特殊情况：当$ r_{min} $和$ r_{max} $同时为0时，scale 和 zeroPoint均为0。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [numBits](#numbits) | 量化的bit数 | 
| int [zeroPoint](#zeropoint) | 零值 | 
| double [scale](#scale) | 量化器的步长 | 


## 类成员变量说明


### numBits

```
int QuantParam::numBits
```

**描述**


量化的bit数


### scale

```
double QuantParam::scale
```

**描述**


量化器的步长


### zeroPoint

```
int QuantParam::zeroPoint
```

**描述**


零值
