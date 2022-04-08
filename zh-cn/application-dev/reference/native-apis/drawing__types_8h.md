# drawing_types.h


## **Overview**

**Related Modules:**

[Drawing](_drawing.md)

**Description:**

文件中定义了用于绘制2d图形的数据类型，包括画布、画笔、画刷、位图和路径

**Since:**
8
**Version:**
1.0

## **Summary**


### Typedefs

  | Typedef&nbsp;Name | Description | 
| -------- | -------- |
| [OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a) | typedef&nbsp;struct&nbsp;[OH_Drawing_Canvas](_drawing.md#ga086e2de47ef7bfe6c96e6b09e87da33a)<br/>OH_Drawing_Canvas定义为一块矩形的画布，可以结合画笔和画刷在上面绘制各种形状、图片和文字 | 
| [OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2) | typedef&nbsp;struct&nbsp;[OH_Drawing_Pen](_drawing.md#ga88e73d9d7b62e6113237fc0f828910d2)<br/>OH_Drawing_Pen定义为画笔，画笔用于描述绘制图形轮廓的样式和颜色 | 
| [OH_Drawing_Brush](_drawing.md#ga178c83de4a084d35c30e4681319ea711) | typedef&nbsp;struct&nbsp;[OH_Drawing_Brush](_drawing.md#ga178c83de4a084d35c30e4681319ea711)<br/>OH_Drawing_Brush定义为画刷，画刷用于描述填充图形的样式和颜色 | 
| [OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023) | typedef&nbsp;struct&nbsp;[OH_Drawing_Path](_drawing.md#gab7e53fc0181099b4a0a3e4a08d3c9023)<br/>OH_Drawing_Path定义为路径，路径用于自定义各种形状 | 
| [OH_Drawing_Bitmap](_drawing.md#ga8ac4e64cd1e2c651d11325e04c72ddeb) | typedef&nbsp;struct&nbsp;[OH_Drawing_Bitmap](_drawing.md#ga8ac4e64cd1e2c651d11325e04c72ddeb)<br/>OH_Drawing_Bitmap定义为位图，位图是一块内存，内存中包含了描述一张图片的像素数据 | 


### Enumerations

  | Enumeration&nbsp;Name | Description | 
| -------- | -------- |
| [OH_Drawing_ColorFormat](_drawing.md#ga6a37fff6c3e0b0d9d81b01755ef846db)&nbsp;{&nbsp;&nbsp;&nbsp;[COLOR_FORMAT_UNKNOWN](_drawing.md#gga6a37fff6c3e0b0d9d81b01755ef846dbab58141bf00d632ba06094d3c4b6446c2),&nbsp;[COLOR_FORMAT_ALPHA_8](_drawing.md#gga6a37fff6c3e0b0d9d81b01755ef846dbabe54d848a7de45ac9a9a89a6eb6a1886),&nbsp;[COLOR_FORMAT_RGB_565](_drawing.md#gga6a37fff6c3e0b0d9d81b01755ef846dbabc7b2f524d90d876ad222dd595c287d9),&nbsp;[COLOR_FORMAT_ARGB_4444](_drawing.md#gga6a37fff6c3e0b0d9d81b01755ef846dba3dac16f10989bdacb479e7fcd9b8861e),&nbsp;&nbsp;&nbsp;[COLOR_FORMAT_RGBA_8888](_drawing.md#gga6a37fff6c3e0b0d9d81b01755ef846dba3b1984f6b8b6fe5f5d65215c95e80ac2),&nbsp;[COLOR_FORMAT_BGRA_8888](_drawing.md#gga6a37fff6c3e0b0d9d81b01755ef846dba44017098e353684bc3bbd2cd0878df15)&nbsp;} | OH_Drawing_ColorFormat用于描述位图像素的存储格式 | 
| [OH_Drawing_AlphaFormat](_drawing.md#gac4dc831be312bb0a7a4745448f4407d3)&nbsp;{&nbsp;[ALPHA_FORMAT_UNKNOWN](_drawing.md#ggac4dc831be312bb0a7a4745448f4407d3ac7e2536628ce62acfc14ec2538425a4a),&nbsp;[ALPHA_FORMAT_OPAQUE](_drawing.md#ggac4dc831be312bb0a7a4745448f4407d3abd3d60c5f30c90748393276a5845f662),&nbsp;[ALPHA_FORMAT_PREMUL](_drawing.md#ggac4dc831be312bb0a7a4745448f4407d3ac0ad416cd779ddc62466d6dceb9a757f),&nbsp;[ALPHA_FORMAT_UNPREMUL](_drawing.md#ggac4dc831be312bb0a7a4745448f4407d3a0b8120300ddca06e3d5db79bfad59a32)&nbsp;} | OH_Drawing_AlphaFormat用于描述位图像素的透明度分量 | 
