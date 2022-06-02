# ImageData对象

>  **说明：**
> 从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


ImageData对象可以存储canvas渲染的像素数据。


## 属性

| 属性 | 类型 | 描述 | 
| -------- | -------- | -------- |
| width | number | 矩形区域实际像素宽度。 | 
| height | number | 矩形区域实际像素高度。 | 
| data | &lt;Uint8ClampedArray&gt; | 一维数组，保存了相应的颜色数据，数据值范围为0到255。 | 
