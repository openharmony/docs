# ArkGraphics2D Changelog

## cl.arkgraphics2d.1 Input Parameter Verification Conditions of OH_Drawing_CanvasDrawVertices Changed

**Access Level**

Public API

**Reason for Change**

1. The input parameters **texs**, **colors**, and **indices** of the **OH_Drawing_CanvasDrawVertices** API cannot be empty. This constraint restricts the drawing capability of this API.
2. The verification of the input parameters **vertexCount** and **indexCount** of the **OH_Drawing_CanvasDrawVertices** API should be optimized to avoid the situation where no drawing content is displayed while no error code is displayed.

**Change Impact**

This change is a compatible change.

After the change, the drawing capability of this API is expanded, and the verification rules of certain input parameters are optimized.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.36

**Key API/Component Changes**

The following table describes the input parameter verification changes of the **OH_Drawing_CanvasDrawVertices** API.
| Parameter | Description | Before Change | After Change |
|--------|--------|--------|--------|
| vertexCount | Number of vertices in the vertex array. | The value must be greater than or equal to 0. | The value must be greater than or equal to 3. |
| texs | Pointer to the array of texture space coordinates corresponding to the vertices. | The parameter cannot be left empty. | The parameter can be left empty. |
| colors | Pointer to the array of colors corresponding to the vertices. | The parameter cannot be left empty. | The parameter can be left empty. |
| indexCount | Number of indices. | The value must be greater than or equal to 0. | The value must be equal to 0 or greater than or equal to 3. |
| indices | Pointer to the array of indexes corresponding to the vertices. | The parameter cannot be left empty. | The parameter can be left empty. |

**Adaptation Guide**

If you have used this API in your code and the drawing effect meets the expectation, no adaptation modification is required.

If you newly use the API or if the drawing effect does not meet expectations, make adaptation by following the instructions provided in [API Reference](../../../application-dev/reference/apis-arkgraphics2d/_drawing.md#oh_drawing_canvasdrawvertices).