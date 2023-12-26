# Component3D

3D渲染组件，可以加载3D模型资源并做自定义渲染，通常用于3D动效场景

>  **说明：**
>
>  该组件从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无


## 接口

Component3D((sceneOptions?: SceneOptions))


**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| sceneOptions | [SceneOptions](#SceneOptions对象说明) | 否 | 3D场景配置选项。 |


## SceneOptions对象说明

Component3D组件配置选项。

| 名称  | 类型                                                         | 必填 | 说明                                                         |
| ----- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| scene  | [Resource]([Resource](ts-types.md#resource))                | 否   | 3D模型资源文件。<br/>**说明：** <br/>目前仅支持GLTF格式资源。 |
| modelType | [ModelType](#ModelType枚举说明)                       | 否   | 3D场景显示合成方式。<br/>默认值：ModelType.SURFACE<br/>**说明：** <br/>设置为ModelType.TEXTURE时通过GPU合成显示<br/>设置为ModelType.SURFACE时通过专有硬件合成显示<br/>一般开发者可以使用默认值而无需关心此项设置 |

## ModelType枚举说明

| 名称 | 描述 |
| -------- | -------- |
| TEXTURE | 使用GPU合成显示3D场景。 |
| SURFACE | 使用专有硬件显示3D场景。 |


## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| environment | [Resource]([Resource](ts-types.md#resource)) | 设置3D环境资源。 <br/>**说明：** <br/>目前仅支持GLTF格式资源。|
| customRender | uri: [Resource]([Resource](ts-types.md#resource))<br/> selfRenderUpdate: boolean | uri:自定义渲染管线的配置文件。<br/> selfRenderUpdate: 当设置为true时外部UI没有更新时也能触发动效渲染，当设置为false时只有外部UI更新才能触发渲染 |
| shader | [Resource]([Resource](ts-types.md#resource)) | 自定义渲染的shader文件资源 |
| shaderImageTexture | [Resource]([Resource](ts-types.md#resource)) | 自定义渲染用到的纹理资源。<br/>**说明：** <br/>若自定义渲染用到多个纹理资源则则调用多次，绑定点与调用顺序一致，不支持纹理更换 |
| shaderInputBuffer | Array<number\> | 自定义渲染用到的动效参数 |
| renderWidth | [Dimension](ts-types.md#dimension10) | 3D渲染分辨率的宽度。<br/>**说明：** <br/> 渲染分辨率的长宽可以不同于控件的长宽，若渲染分辨率与控件分辨率长宽不一致时会上采样或下采样到控件长宽。<br/> 不调用此属性时默认渲染分辨率 |
| renderHeight | [Dimension](ts-types.md#dimension10) | 3D渲染分辨率的长度。<br/>**说明：** <br/> 渲染分辨率的长宽可以不同于控件的长宽，若渲染分辨率与控件分辨率长宽不一致时会上采样或下采样到控件长宽。<br/> 不调用此属性时默认渲染分辨率 |