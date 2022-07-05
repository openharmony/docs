# WebGL2

WebGL2支持图形的绘制，包括对当前绘制图形的位置、颜色等进行处理，其中相对WebGL来说对渲染管道和着色语言进行了增强。

WebGL标准图形API，对应OpenGL ES 3.0特性集。更多信息请参考[WebGL™标准](https://www.khronos.org/registry/webgl/specs/latest/2.0/)。

>  **说明：** 
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。





## 调用方式

hml内创建canvas，示例如下：


```html
<!--xxx.hml-->
<div class="container">
    <canvas ref="canvas1" style="width : 400px; height : 200px; background-color : lightyellow;"></canvas>
    <button class="btn-button" onclick="BtnDraw2D">BtnDraw2D</button>
</div>
```

js内获取canvas实例，示例如下：


```js
// 获取canvas组件实例
const el = this.$refs.canvas1;
// 从canvas组件实例获取WebGL上下文
const gl = el.getContext('webgl2');
// 调用WebGL API
gl.clearColor(0.0, 0.0, 0.0, 1.0);
```


## Type

**系统能力：** 以下各项对应的系统能力均为 SystemCapability.Graphic.Graphic2D.WebGL2。

  **表1**  Type

| 名称 | 类型 |
| -------- | -------- |
| GLenum | number |
| GLint64 | number |
| GLuint64 | number |
| Uint32List | array |


## Interface

**系统能力：** 以下各项对应的系统能力均为 SystemCapability.Graphic.Graphic2D.WebGL2。

  **表2**  Interface

| 名称 |
| -------- |
| [WebGL2RenderingContextBase](#webgl2renderingcontextbase) |
| [WebGL2RenderingContextOverloads](#webgl2renderingcontextoverloads) |
| WebGLQuery |
| WebGLSampler |
| WebGLSync |
| WebGLTransformFeedback |
| WebGLVertexArrayObject |


## WebGL2RenderingContextBase

WebGL2RenderingContextBase


### 属性

  | 名称 | 参数类型 | 必填 | 
| -------- | -------- | -------- |
| READ_BUFFER | GLenum | 是 | 
| UNPACK_ROW_LENGTH | GLenum | 是 | 
| UNPACK_SKIP_ROWS | GLenum | 是 | 
| UNPACK_SKIP_PIXELS | GLenum | 是 | 
| PACK_ROW_LENGTH | GLenum | 是 | 
| PACK_SKIP_ROWS | GLenum | 是 | 
| PACK_SKIP_PIXELS | GLenum | 是 | 
| COLOR | GLenum | 是 | 
| DEPTH | GLenum | 是 | 
| STENCIL | GLenum | 是 | 
| RED | GLenum | 是 | 
| RGB8 | GLenum | 是 | 
| RGBA8 | GLenum | 是 | 
| RGB10_A2 | GLenum | 是 | 
| TEXTURE_BINDING_3D | GLenum | 是 | 
| UNPACK_SKIP_IMAGES | GLenum | 是 | 
| UNPACK_IMAGE_HEIGHT | GLenum | 是 | 
| TEXTURE_3D | GLenum | 是 | 
| TEXTURE_WRAP_R | GLenum | 是 | 
| MAX_3D_TEXTURE_SIZE | GLenum | 是 | 
| UNSIGNED_INT_2_10_10_10_REV | GLenum | 是 | 
| MAX_ELEMENTS_VERTICES | GLenum | 是 | 
| MAX_ELEMENTS_INDICES | GLenum | 是 | 
| TEXTURE_MIN_LOD | GLenum | 是 | 
| TEXTURE_MAX_LOD | GLenum | 是 | 
| TEXTURE_BASE_LEVEL | GLenum | 是 | 
| TEXTURE_MAX_LEVEL | GLenum | 是 | 
| MIN | GLenum | 是 | 
| MAX | GLenum | 是 | 
| DEPTH_COMPONENT24 | GLenum | 是 | 
| MAX_TEXTURE_LOD_BIAS | GLenum | 是 | 
| TEXTURE_COMPARE_MODE | GLenum | 是 | 
| TEXTURE_COMPARE_FUNC | GLenum | 是 | 
| CURRENT_QUERY | GLenum | 是 | 
| QUERY_RESULT | GLenum | 是 | 
| QUERY_RESULT_AVAILABLE | GLenum | 是 | 
| STREAM_READ | GLenum | 是 | 
| STREAM_COPY | GLenum | 是 | 
| STATIC_READ | GLenum | 是 | 
| STATIC_COPY | GLenum | 是 | 
| DYNAMIC_READ | GLenum | 是 | 
| DYNAMIC_COPY | GLenum | 是 | 
| MAX_DRAW_BUFFERS | GLenum | 是 | 
| DRAW_BUFFER0 | GLenum | 是 | 
| DRAW_BUFFER1 | GLenum | 是 | 
| DRAW_BUFFER2 | GLenum | 是 | 
| DRAW_BUFFER3 | GLenum | 是 | 
| DRAW_BUFFER4 | GLenum | 是 | 
| DRAW_BUFFER5 | GLenum | 是 | 
| DRAW_BUFFER6 | GLenum | 是 | 
| DRAW_BUFFER7 | GLenum | 是 | 
| DRAW_BUFFER8 | GLenum | 是 | 
| DRAW_BUFFER9 | GLenum | 是 | 
| DRAW_BUFFER10 | GLenum | 是 | 
| DRAW_BUFFER11 | GLenum | 是 | 
| DRAW_BUFFER12 | GLenum | 是 | 
| DRAW_BUFFER13 | GLenum | 是 | 
| DRAW_BUFFER14 | GLenum | 是 | 
| DRAW_BUFFER15 | GLenum | 是 | 
| MAX_FRAGMENT_UNIFORM_COMPONENTS | GLenum | 是 | 
| MAX_VERTEX_UNIFORM_COMPONENTS | GLenum | 是 | 
| SAMPLER_3D | GLenum | 是 | 
| SAMPLER_2D_SHADOW | GLenum | 是 | 
| FRAGMENT_SHADER_DERIVATIVE_HINT | GLenum | 是 | 
| PIXEL_PACK_BUFFER | GLenum | 是 | 
| PIXEL_UNPACK_BUFFER | GLenum | 是 | 
| PIXEL_PACK_BUFFER_BINDING | GLenum | 是 | 
| PIXEL_UNPACK_BUFFER_BINDING | GLenum | 是 | 
| FLOAT_MAT2x3 | GLenum | 是 | 
| FLOAT_MAT2x4 | GLenum | 是 | 
| FLOAT_MAT3x2 | GLenum | 是 | 
| FLOAT_MAT3x4 | GLenum | 是 | 
| FLOAT_MAT4x2 | GLenum | 是 | 
| FLOAT_MAT4x3 | GLenum | 是 | 
| SRGB | GLenum | 是 | 
| SRGB8 | GLenum | 是 | 
| SRGB8_ALPHA8 | GLenum | 是 | 
| COMPARE_REF_TO_TEXTURE | GLenum | 是 | 
| RGBA32F | GLenum | 是 | 
| RGB32F | GLenum | 是 | 
| RGBA16F | GLenum | 是 | 
| RGB16F | GLenum | 是 | 
| VERTEX_ATTRIB_ARRAY_INTEGER | GLenum | 是 | 
| MAX_ARRAY_TEXTURE_LAYERS | GLenum | 是 | 
| MIN_PROGRAM_TEXEL_OFFSET | GLenum | 是 | 
| MAX_PROGRAM_TEXEL_OFFSET | GLenum | 是 | 
| MAX_VARYING_COMPONENTS | GLenum | 是 | 
| TEXTURE_2D_ARRAY | GLenum | 是 | 
| TEXTURE_BINDING_2D_ARRAY | GLenum | 是 | 
| R11F_G11F_B10F | GLenum | 是 | 
| UNSIGNED_INT_10F_11F_11F_REV | GLenum | 是 | 
| RGB9_E5 | GLenum | 是 | 
| UNSIGNED_INT_5_9_9_9_REV | GLenum | 是 | 
| TRANSFORM_FEEDBACK_BUFFER_MODE | GLenum | 是 | 
| MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS | GLenum | 是 | 
| TRANSFORM_FEEDBACK_VARYINGS | GLenum | 是 | 
| TRANSFORM_FEEDBACK_BUFFER_START | GLenum | 是 | 
| TRANSFORM_FEEDBACK_BUFFER_SIZE | GLenum | 是 | 
| TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN | GLenum | 是 | 
| RASTERIZER_DISCARD | GLenum | 是 | 
| MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS | GLenum | 是 | 
| MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS | GLenum | 是 | 
| INTERLEAVED_ATTRIBS | GLenum | 是 | 
| SEPARATE_ATTRIBS | GLenum | 是 | 
| TRANSFORM_FEEDBACK_BUFFER | GLenum | 是 | 
| TRANSFORM_FEEDBACK_BUFFER_BINDING | GLenum | 是 | 
| RGBA32UI | GLenum | 是 | 
| RGB32UI | GLenum | 是 | 
| RGBA16UI | GLenum | 是 | 
| RGB16UI | GLenum | 是 | 
| RGBA8UI | GLenum | 是 | 
| RGB8UI | GLenum | 是 | 
| RGBA32I | GLenum | 是 | 
| RGB32I | GLenum | 是 | 
| RGBA16I | GLenum | 是 | 
| RGB16I | GLenum | 是 | 
| RGBA8I | GLenum | 是 | 
| RGB8I | GLenum | 是 | 
| RED_INTEGER | GLenum | 是 | 
| RGB_INTEGER | GLenum | 是 | 
| RGBA_INTEGER | GLenum | 是 | 
| SAMPLER_2D_ARRAY | GLenum | 是 | 
| SAMPLER_2D_ARRAY_SHADOW | GLenum | 是 | 
| SAMPLER_CUBE_SHADOW | GLenum | 是 | 
| UNSIGNED_INT_VEC2 | GLenum | 是 | 
| UNSIGNED_INT_VEC3 | GLenum | 是 | 
| UNSIGNED_INT_VEC4 | GLenum | 是 | 
| INT_SAMPLER_2D | GLenum | 是 | 
| INT_SAMPLER_3D | GLenum | 是 | 
| INT_SAMPLER_CUBE | GLenum | 是 | 
| INT_SAMPLER_2D_ARRAY | GLenum | 是 | 
| UNSIGNED_INT_SAMPLER_2D | GLenum | 是 | 
| UNSIGNED_INT_SAMPLER_3D | GLenum | 是 | 
| UNSIGNED_INT_SAMPLER_CUBE | GLenum | 是 | 
| UNSIGNED_INT_SAMPLER_2D_ARRAY | GLenum | 是 | 
| DEPTH_COMPONENT32F | GLenum | 是 | 
| DEPTH32F_STENCIL8 | GLenum | 是 | 
| FLOAT_32_UNSIGNED_INT_24_8_REV | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_RED_SIZE | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_GREEN_SIZE | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_BLUE_SIZE | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE | GLenum | 是 | 
| FRAMEBUFFER_DEFAULT | GLenum | 是 | 
| UNSIGNED_INT_24_8 | GLenum | 是 | 
| DEPTH24_STENCIL8 | GLenum | 是 | 
| UNSIGNED_NORMALIZED | GLenum | 是 | 
| DRAW_FRAMEBUFFER_BINDING | GLenum | 是 | 
| READ_FRAMEBUFFER | GLenum | 是 | 
| DRAW_FRAMEBUFFER | GLenum | 是 | 
| READ_FRAMEBUFFER_BINDING | GLenum | 是 | 
| RENDERBUFFER_SAMPLES | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER | GLenum | 是 | 
| MAX_COLOR_ATTACHMENTS | GLenum | 是 | 
| COLOR_ATTACHMENT1 | GLenum | 是 | 
| COLOR_ATTACHMENT2 | GLenum | 是 | 
| COLOR_ATTACHMENT3 | GLenum | 是 | 
| COLOR_ATTACHMENT4 | GLenum | 是 | 
| COLOR_ATTACHMENT5 | GLenum | 是 | 
| COLOR_ATTACHMENT6 | GLenum | 是 | 
| COLOR_ATTACHMENT7 | GLenum | 是 | 
| COLOR_ATTACHMENT8 | GLenum | 是 | 
| COLOR_ATTACHMENT9 | GLenum | 是 | 
| COLOR_ATTACHMENT10 | GLenum | 是 | 
| COLOR_ATTACHMENT11 | GLenum | 是 | 
| COLOR_ATTACHMENT12 | GLenum | 是 | 
| COLOR_ATTACHMENT13 | GLenum | 是 | 
| COLOR_ATTACHMENT14 | GLenum | 是 | 
| COLOR_ATTACHMENT15 | GLenum | 是 | 
| FRAMEBUFFER_INCOMPLETE_MULTISAMPLE | GLenum | 是 | 
| MAX_SAMPLES | GLenum | 是 | 
| HALF_FLOAT | GLenum | 是 | 
| RG | GLenum | 是 | 
| RG_INTEGER | GLenum | 是 | 
| R8 | GLenum | 是 | 
| RG8 | GLenum | 是 | 
| R16F | GLenum | 是 | 
| R32F | GLenum | 是 | 
| RG16F | GLenum | 是 | 
| RG32F | GLenum | 是 | 
| R8I | GLenum | 是 | 
| R8UI | GLenum | 是 | 
| R16I | GLenum | 是 | 
| R16UI | GLenum | 是 | 
| R32I | GLenum | 是 | 
| R32UI | GLenum | 是 | 
| RG8I | GLenum | 是 | 
| RG8UI | GLenum | 是 | 
| RG16I | GLenum | 是 | 
| RG16UI | GLenum | 是 | 
| RG32I | GLenum | 是 | 
| RG32UI | GLenum | 是 | 
| VERTEX_ARRAY_BINDING | GLenum | 是 | 
| R8_SNORM | GLenum | 是 | 
| RG8_SNORM | GLenum | 是 | 
| RGB8_SNORM | GLenum | 是 | 
| SIGNED_NORMALIZED | GLenum | 是 | 
| COPY_READ_BUFFER | GLenum | 是 | 
| COPY_WRITE_BUFFER | GLenum | 是 | 
| COPY_READ_BUFFER_BINDING | GLenum | 是 | 
| COPY_WRITE_BUFFER_BINDING | GLenum | 是 | 
| UNIFORM_BUFFER | GLenum | 是 | 
| UNIFORM_BUFFER_BINDING | GLenum | 是 | 
| UNIFORM_BUFFER_START | GLenum | 是 | 
| UNIFORM_BUFFER_SIZE | GLenum | 是 | 
| MAX_VERTEX_UNIFORM_BLOCKS | GLenum | 是 | 
| MAX_FRAGMENT_UNIFORM_BLOCKS | GLenum | 是 | 
| MAX_COMBINED_UNIFORM_BLOCKS | GLenum | 是 | 
| MAX_UNIFORM_BUFFER_BINDINGS | GLenum | 是 | 
| MAX_UNIFORM_BLOCK_SIZE | GLenum | 是 | 
| MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS | GLenum | 是 | 
| MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS | GLenum | 是 | 
| UNIFORM_BUFFER_OFFSET_ALIGNMENT | GLenum | 是 | 
| ACTIVE_UNIFORM_BLOCKS | GLenum | 是 | 
| UNIFORM_TYPE | GLenum | 是 | 
| UNIFORM_SIZE | GLenum | 是 | 
| UNIFORM_BLOCK_INDEX | GLenum | 是 | 
| UNIFORM_OFFSET | GLenum | 是 | 
| UNIFORM_ARRAY_STRIDE | GLenum | 是 | 
| UNIFORM_MATRIX_STRIDE | GLenum | 是 | 
| UNIFORM_IS_ROW_MAJOR | GLenum | 是 | 
| UNIFORM_BLOCK_BINDING | GLenum | 是 | 
| UNIFORM_BLOCK_DATA_SIZE | GLenum | 是 | 
| UNIFORM_BLOCK_ACTIVE_UNIFORMS | GLenum | 是 | 
| UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES | GLenum | 是 | 
| UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER | GLenum | 是 | 
| UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER | GLenum | 是 | 
| INVALID_INDEX | GLenum | 是 | 
| MAX_VERTEX_OUTPUT_COMPONENTS | GLenum | 是 | 
| MAX_FRAGMENT_INPUT_COMPONENTS | GLenum | 是 | 
| MAX_SERVER_WAIT_TIMEOUT | GLenum | 是 | 
| OBJECT_TYPE | GLenum | 是 | 
| SYNC_CONDITION | GLenum | 是 | 
| SYNC_STATUS | GLenum | 是 | 
| SYNC_FLAGS | GLenum | 是 | 
| SYNC_FENCE | GLenum | 是 | 
| SYNC_GPU_COMMANDS_COMPLETE | GLenum | 是 | 
| UNSIGNALED | GLenum | 是 | 
| SIGNALED | GLenum | 是 | 
| ALREADY_SIGNALED | GLenum | 是 | 
| TIMEOUT_EXPIRED | GLenum | 是 | 
| CONDITION_SATISFIED | GLenum | 是 | 
| WAIT_FAILED | GLenum | 是 | 
| SYNC_FLUSH_COMMANDS_BIT | GLenum | 是 | 
| VERTEX_ATTRIB_ARRAY_DIVISOR | GLenum | 是 | 
| ANY_SAMPLES_PASSED | GLenum | 是 | 
| ANY_SAMPLES_PASSED_CONSERVATIVE | GLenum | 是 | 
| SAMPLER_BINDING | GLenum | 是 | 
| RGB10_A2UI | GLenum | 是 | 
| INT_2_10_10_10_REV | GLenum | 是 | 
| TRANSFORM_FEEDBACK | GLenum | 是 | 
| TRANSFORM_FEEDBACK_PAUSED | GLenum | 是 | 
| TRANSFORM_FEEDBACK_ACTIVE | GLenum | 是 | 
| TRANSFORM_FEEDBACK_BINDING | GLenum | 是 | 
| TEXTURE_IMMUTABLE_FORMAT | GLenum | 是 | 
| MAX_ELEMENT_INDEX | GLenum | 是 | 
| TEXTURE_IMMUTABLE_LEVELS | GLenum | 是 | 
| TIMEOUT_IGNORED | GLint64 | 是 | 
| MAX_CLIENT_WAIT_TIMEOUT_WEBGL | GLenum | 是 | 


### 方法

  | 方法 | 返回值类型 | 
| -------- | -------- |
| copyBufferSubData(readTarget:&nbsp;GLenum,&nbsp;writeTarget:&nbsp;GLenum,&nbsp;readOffset:&nbsp;GLintptr,&nbsp;writeOffset:&nbsp;GLintptr,&nbsp;size:&nbsp;GLsizeiptr) | void | 
| getBufferSubData(target:&nbsp;GLenum,&nbsp;srcByteOffset:&nbsp;GLintptr,&nbsp;dstBuffer:&nbsp;ArrayBufferView,&nbsp;dstOffset?:&nbsp;GLuint,&nbsp;length?:&nbsp;GLuint) | void | 
| blitFramebuffer(srcX0:&nbsp;GLint,&nbsp;srcY0:&nbsp;GLint,&nbsp;srcX1:&nbsp;GLint,&nbsp;srcY1:&nbsp;GLint,&nbsp;dstX0:&nbsp;GLint,&nbsp;dstY0:&nbsp;GLint,&nbsp;dstX1:&nbsp;GLint,&nbsp;dstY1:&nbsp;GLint,&nbsp;mask:&nbsp;GLbitfield,&nbsp;filter:&nbsp;GLenum) | void | 
| framebufferTextureLayer(target:&nbsp;GLenum,&nbsp;attachment:&nbsp;GLenum,&nbsp;texture:&nbsp;WebGLTexture&nbsp;\|&nbsp;null,&nbsp;level:&nbsp;GLint,&nbsp;layer:&nbsp;GLint) | void | 
| invalidateFramebuffer(target:&nbsp;GLenum,&nbsp;attachments:&nbsp;GLenum[]) | void | 
| invalidateSubFramebuffer(target:&nbsp;GLenum,&nbsp;attachments:&nbsp;GLenum[],&nbsp;x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei) | void | 
| readBuffer(src:&nbsp;GLenum) | void | 
| getInternalformatParameter(target:&nbsp;GLenum,&nbsp;internalformat:&nbsp;GLenum,&nbsp;pname:&nbsp;GLenum) | any | 
| renderbufferStorageMultisample(target:&nbsp;GLenum,&nbsp;samples:&nbsp;GLsizei,&nbsp;internalformat:&nbsp;GLenum,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei) | void | 
| texStorage2D(target:&nbsp;GLenum,&nbsp;levels:&nbsp;GLsizei,&nbsp;internalformat:&nbsp;GLenum,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei) | void | 
| texStorage3D(target:&nbsp;GLenum,&nbsp;levels:&nbsp;GLsizei,&nbsp;internalformat:&nbsp;GLenum,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei) | void | 
| texImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;pboOffset:&nbsp;GLintptr) | void | 
| texImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;source:&nbsp;TexImageSource) | void | 
| texImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;srcData:&nbsp;ArrayBufferView&nbsp;\|&nbsp;null) | void | 
| texImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;srcData:&nbsp;ArrayBufferView,&nbsp;srcOffset:&nbsp;GLuint) | void | 
| texSubImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;zoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;pboOffset:&nbsp;GLintptr) | void | 
| texSubImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;zoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;source:&nbsp;TexImageSource) | void | 
| texSubImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;zoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;srcData:&nbsp;ArrayBufferView&nbsp;\|&nbsp;null,&nbsp;srcOffset?:&nbsp;GLuint) | void | 
| copyTexSubImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;zoffset:&nbsp;GLint,&nbsp;x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei) | void | 
| compressedTexImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLenum,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;imageSize:&nbsp;GLsizei,&nbsp;offset:&nbsp;GLintptr) | void | 
| compressedTexImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLenum,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;srcData:&nbsp;ArrayBufferView,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLengthOverride?:&nbsp;GLuint) | void | 
| compressedTexSubImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;zoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;imageSize:&nbsp;GLsizei,&nbsp;offset:&nbsp;GLintptr) | void | 
| compressedTexSubImage3D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;zoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;depth:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;srcData:&nbsp;ArrayBufferView,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLengthOverride?:&nbsp;GLuint) | void | 
| getFragDataLocation(program:&nbsp;WebGLProgram,&nbsp;name:&nbsp;string) | GLint | 
| uniform1ui(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v0:&nbsp;GLuint) | void | 
| uniform2ui(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v0:&nbsp;GLuint,&nbsp;v1:&nbsp;GLuint) | void | 
| uniform3ui(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v0:&nbsp;GLuint,&nbsp;v1:&nbsp;GLuint,&nbsp;v2:&nbsp;GLuint) | void | 
| uniform4ui(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v0:&nbsp;GLuint,&nbsp;v1:&nbsp;GLuint,&nbsp;v2:&nbsp;GLuint,&nbsp;v3:&nbsp;GLuint) | void | 
| uniform1uiv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Uint32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniform2uiv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Uint32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniform3uiv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Uint32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniform4uiv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Uint32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniformMatrix3x2fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniformMatrix4x2fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniformMatrix2x3fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniformMatrix4x3fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniformMatrix2x4fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniformMatrix3x4fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| vertexAttribI4i(index:&nbsp;GLuint,&nbsp;x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;z:&nbsp;GLint,&nbsp;w:&nbsp;GLint) | void | 
| vertexAttribI4iv(index:&nbsp;GLuint,&nbsp;values:&nbsp;Int32List) | void | 
| vertexAttribI4ui(index:&nbsp;GLuint,&nbsp;x:&nbsp;GLuint,&nbsp;y:&nbsp;GLuint,&nbsp;z:&nbsp;GLuint,&nbsp;w:&nbsp;GLuint) | void | 
| vertexAttribI4uiv(index:&nbsp;GLuint,&nbsp;values:&nbsp;Uint32List) | void | 
| vertexAttribIPointer(index:&nbsp;GLuint,&nbsp;size:&nbsp;GLint,&nbsp;type:&nbsp;GLenum,&nbsp;stride:&nbsp;GLsizei,&nbsp;offset:&nbsp;GLintptr) | void | 
| vertexAttribDivisor(index:&nbsp;GLuint,&nbsp;divisor:&nbsp;GLuint) | void | 
| drawArraysInstanced(mode:&nbsp;GLenum,&nbsp;first:&nbsp;GLint,&nbsp;count:&nbsp;GLsizei,&nbsp;instanceCount:&nbsp;GLsizei) | void | 
| drawElementsInstanced(mode:&nbsp;GLenum,&nbsp;count:&nbsp;GLsizei,&nbsp;type:&nbsp;GLenum,&nbsp;offset:&nbsp;GLintptr,&nbsp;instanceCount:&nbsp;GLsizei) | void | 
| drawRangeElements(mode:&nbsp;GLenum,&nbsp;start:&nbsp;GLuint,&nbsp;end:&nbsp;GLuint,&nbsp;count:&nbsp;GLsizei,&nbsp;type:&nbsp;GLenum,&nbsp;offset:&nbsp;GLintptr) | void | 
| drawBuffers(buffers:&nbsp;GLenum[]) | void | 
| clearBufferfv(buffer:&nbsp;GLenum,&nbsp;drawbuffer:&nbsp;GLint,&nbsp;values:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint) | void | 
| clearBufferiv(buffer:&nbsp;GLenum,&nbsp;drawbuffer:&nbsp;GLint,&nbsp;values:&nbsp;Int32List,&nbsp;srcOffset?:&nbsp;GLuint) | void | 
| clearBufferuiv(buffer:&nbsp;GLenum,&nbsp;drawbuffer:&nbsp;GLint,&nbsp;values:&nbsp;Uint32List,&nbsp;srcOffset?:&nbsp;GLuint) | void | 
| clearBufferfi(buffer:&nbsp;GLenum,&nbsp;drawbuffer:&nbsp;GLint,&nbsp;depth:&nbsp;GLfloat,&nbsp;stencil:&nbsp;GLint) | void | 
| createQuery() | WebGLQuery&nbsp;\|&nbsp;null | 
| deleteQuery(query:&nbsp;WebGLQuery&nbsp;\|&nbsp;null) | void | 
| isQuery(query:&nbsp;WebGLQuery&nbsp;\|&nbsp;null) | GLboolean | 
| beginQuery(target:&nbsp;GLenum,&nbsp;query:&nbsp;WebGLQuery) | void | 
| endQuery(target:&nbsp;GLenum) | void | 
| getQuery(target:&nbsp;GLenum,&nbsp;pname:&nbsp;GLenum) | WebGLQuery&nbsp;\|&nbsp;null | 
| getQueryParameter(query:&nbsp;WebGLQuery,&nbsp;pname:&nbsp;GLenum) | any | 
| createSampler() | WebGLSampler&nbsp;\|&nbsp;null | 
| deleteSampler(sampler:&nbsp;WebGLSampler&nbsp;\|&nbsp;null) | void | 
| isSampler(sampler:&nbsp;WebGLSampler&nbsp;\|&nbsp;null) | GLboolean | 
| bindSampler(unit:&nbsp;GLuint,&nbsp;sampler:&nbsp;WebGLSampler&nbsp;\|&nbsp;null) | void | 
| samplerParameteri(sampler:&nbsp;WebGLSampler,&nbsp;pname:&nbsp;GLenum,&nbsp;param:&nbsp;GLint) | void | 
| samplerParameterf(sampler:&nbsp;WebGLSampler,&nbsp;pname:&nbsp;GLenum,&nbsp;param:&nbsp;GLfloat) | void; | 
| getSamplerParameter(sampler:&nbsp;WebGLSampler,&nbsp;pname:&nbsp;GLenum) | any | 
| fenceSync(condition:&nbsp;GLenum,&nbsp;flags:&nbsp;GLbitfield) | WebGLSync&nbsp;\|&nbsp;null | 
| isSync(sync:&nbsp;WebGLSync&nbsp;\|&nbsp;null) | GLboolean | 
| deleteSync(sync:&nbsp;WebGLSync&nbsp;\|&nbsp;null) | void | 
| clientWaitSync(sync:&nbsp;WebGLSync,&nbsp;flags:&nbsp;GLbitfield,&nbsp;timeout:&nbsp;GLuint64) | GLenum | 
| waitSync(sync:&nbsp;WebGLSync,&nbsp;flags:&nbsp;GLbitfield,&nbsp;timeout:&nbsp;GLint64) | void | 
| getSyncParameter(sync:&nbsp;WebGLSync,&nbsp;pname:&nbsp;GLenum) | any | 
| createTransformFeedback() | WebGLTransformFeedback&nbsp;\|&nbsp;null | 
| deleteTransformFeedback(tf:&nbsp;WebGLTransformFeedback&nbsp;\|&nbsp;null) | void | 
| isTransformFeedback(tf:&nbsp;WebGLTransformFeedback&nbsp;\|&nbsp;null) | GLboolean | 
| bindTransformFeedback(target:&nbsp;GLenum,&nbsp;tf:&nbsp;WebGLTransformFeedback&nbsp;\|&nbsp;null) | void | 
| beginTransformFeedback(primitiveMode:&nbsp;GLenum) | void | 
| endTransformFeedback() | void | 
| transformFeedbackVaryings(program:&nbsp;WebGLProgram,&nbsp;varyings:&nbsp;string[],&nbsp;bufferMode:&nbsp;GLenum) | void | 
| getTransformFeedbackVarying(program:&nbsp;WebGLProgram,&nbsp;index:&nbsp;GLuint) | WebGLActiveInfo&nbsp;\|&nbsp;null | 
| pauseTransformFeedback() | void | 
| resumeTransformFeedback() | void | 
| bindBufferBase(target:&nbsp;GLenum,&nbsp;index:&nbsp;GLuint,&nbsp;buffer:&nbsp;WebGLBuffer&nbsp;\|&nbsp;null) | void | 
| bindBufferRange(target:&nbsp;GLenum,&nbsp;index:&nbsp;GLuint,&nbsp;buffer:&nbsp;WebGLBuffer&nbsp;\|&nbsp;null,&nbsp;offset:&nbsp;GLintptr,&nbsp;size:&nbsp;GLsizeiptr) | void | 
| getIndexedParameter(target:&nbsp;GLenum,&nbsp;index:&nbsp;GLuint) | any | 
| getUniformIndices(program:&nbsp;WebGLProgram,&nbsp;uniformNames:&nbsp;string[]) | GLuint[]&nbsp;\|&nbsp;null | 
| getActiveUniforms(program:&nbsp;WebGLProgram,&nbsp;uniformIndices:&nbsp;GLuint[],&nbsp;pname:&nbsp;GLenum) | any | 
| getUniformBlockIndex(program:&nbsp;WebGLProgram,&nbsp;uniformBlockName:&nbsp;string) | GLuint | 
| getActiveUniformBlockParameter(program:&nbsp;WebGLProgram,&nbsp;uniformBlockIndex:&nbsp;GLuint,&nbsp;pname:&nbsp;GLenum) | any | 
| getActiveUniformBlockName(program:&nbsp;WebGLProgram,&nbsp;uniformBlockIndex:&nbsp;GLuint) | string&nbsp;\|&nbsp;null | 
| uniformBlockBinding(program:&nbsp;WebGLProgram,&nbsp;uniformBlockIndex:&nbsp;GLuint,&nbsp;uniformBlockBinding:&nbsp;GLuint) | void | 
| createVertexArray() | WebGLVertexArrayObject&nbsp;\|&nbsp;null | 
| deleteVertexArray(vertexArray:&nbsp;WebGLVertexArrayObject&nbsp;\|&nbsp;null) | void | 
| isVertexArray(vertexArray:&nbsp;WebGLVertexArrayObject&nbsp;\|&nbsp;null) | GLboolean | 
| bindVertexArray(array:&nbsp;WebGLVertexArrayObject&nbsp;\|&nbsp;null) | void | 


## WebGL2RenderingContextOverloads

WebGL2RenderingContextOverloads

  | 方法 | 返回值类型 | 
| -------- | -------- |
| bufferData(target:&nbsp;GLenum,&nbsp;size:&nbsp;GLsizeiptr,&nbsp;usage:&nbsp;GLenum) | void | 
| bufferData(target:&nbsp;GLenum,&nbsp;srcData:&nbsp;BufferSource&nbsp;\|&nbsp;null,&nbsp;usage:&nbsp;GLenum) | void | 
| bufferSubData(target:&nbsp;GLenum,&nbsp;dstByteOffset:&nbsp;GLintptr,&nbsp;srcData:&nbsp;BufferSource) | void | 
| bufferData(target:&nbsp;GLenum,&nbsp;srcData:&nbsp;ArrayBufferView,&nbsp;usage:&nbsp;GLenum,&nbsp;srcOffset:&nbsp;GLuint,&nbsp;length?:&nbsp;GLuint) | void | 
| bufferSubData(target:&nbsp;GLenum,&nbsp;dstByteOffset:&nbsp;GLintptr,&nbsp;srcData:&nbsp;ArrayBufferView,&nbsp;srcOffset:&nbsp;GLuint,&nbsp;length?:&nbsp;GLuint) | void | 
| texImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;pixels:&nbsp;ArrayBufferView&nbsp;\|&nbsp;null) | void | 
| texImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;source:&nbsp;TexImageSource) | void | 
| texSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;pixels:&nbsp;ArrayBufferView&nbsp;\|&nbsp;null) | void | 
| texSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;source:&nbsp;TexImageSource) | void | 
| texImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;pboOffset:&nbsp;GLintptr) | void | 
| texImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;source:&nbsp;TexImageSource) | void | 
| texImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;srcData:&nbsp;ArrayBufferView,&nbsp;srcOffset:&nbsp;GLuint) | void | 
| texSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;pboOffset:&nbsp;GLintptr) | void | 
| texSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;source:&nbsp;TexImageSource) | void | 
| texSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;srcData:&nbsp;ArrayBufferView,&nbsp;srcOffset:&nbsp;GLuint) | void | 
| compressedTexImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLenum,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;imageSize:&nbsp;GLsizei,&nbsp;offset:&nbsp;GLintptr) | void | 
| compressedTexImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLenum,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;srcData:&nbsp;ArrayBufferView,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLengthOverride?:&nbsp;GLuint) | void | 
| compressedTexSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;imageSize:&nbsp;GLsizei,&nbsp;offset:&nbsp;GLintptr) | void | 
| compressedTexSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;srcData:&nbsp;ArrayBufferView,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLengthOverride?:&nbsp;GLuint) | void | 
| uniform1fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniform2fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniform3fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniform4fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniform1iv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Int32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniform2iv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Int32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniform3iv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Int32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniform4iv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;data:&nbsp;Int32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniformMatrix2fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniformMatrix3fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| uniformMatrix4fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;data:&nbsp;Float32List,&nbsp;srcOffset?:&nbsp;GLuint,&nbsp;srcLength?:&nbsp;GLuint) | void | 
| readPixels(x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;dstData:&nbsp;ArrayBufferView&nbsp;\|&nbsp;null) | void | 
| readPixels(x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;offset:&nbsp;GLintptr) | void | 
| readPixels(x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;dstData:&nbsp;ArrayBufferView,&nbsp;dstOffset:&nbsp;GLuint) | void | 
