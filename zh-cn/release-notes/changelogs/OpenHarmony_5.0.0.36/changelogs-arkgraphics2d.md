# ArkGraphics2D变更说明

## cl.arkgraphics2d.1 OH_Drawing_CanvasDrawVertices接口入参校验条件变更

**访问级别**

公开接口

**变更原因**

1. texs, colors, indices入参应该允许为空，当前不允许为空限制了开发者正常使用该接口进行绘制的能力。
2. vertexCount, indexCount入参校验需要优化，避免出现使用该接口无任何绘制内容且无错误码提示的情况。

**变更影响**

该变更为兼容性变更。
更改后扩充了该接口的绘制能力，优化了部分入参的校验规则。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.36 版本开始。

**变更的接口/组件**

OH_Drawing_CanvasDrawVertices接口入参校验变化如下表格所示。
| 参数 | 描述 | 变更前 | 变更后 |
|--------|--------|--------|--------|
| vertexCount | 顶点数组元素的数量 | 必须大于等于0 | 必须大于等于3 |
| texs | 顶点对应纹理空间坐标的数组指针 | 不允许为空 | 可以为空 |
| colors | 顶点对应颜色的数组指针 | 不允许为空 | 可以为空 |
| indexCount | 索引的数量 | 必须大于等于0 | 等于0或必须大于等于3 |
| indices | 顶点对应索引的数组指针 | 不允许为空 | 可以为空 |

**适配指导**

如果开发者当前已使用该接口且绘制效果符合预期的，不需要做适配修改。
新使用或当前使用效果不符合预期的开发者，请参考[接口说明](../../../application-dev/reference/apis-arkgraphics2d/_drawing.md#oh_drawing_canvasdrawvertices)进行适配。