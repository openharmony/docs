# WebGL2

WebGL2支持图形的绘制，包括对当前绘制图形的位置、颜色等进行处理，其中相对WebGL来说对渲染管道和着色语言进行了增强。

WebGL标准图形API，对应OpenGL ES 3.0特性集。更多信息请参考[WebGL™标准](https://www.khronos.org/registry/webgl/specs/latest/2.0/)。

>  **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> WebGL2遵循OpenGL协议，不支持多线程调用。
>
> 目前该功能仅支持使用兼容JS的类Web开发范式开发。


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
| copyBufferSubData(readTarget: GLenum, writeTarget: GLenum, readOffset: GLintptr, writeOffset: GLintptr, size: GLsizeiptr) | void | 
| getBufferSubData(target: GLenum, srcByteOffset: GLintptr, dstBuffer: ArrayBufferView, dstOffset?: GLuint, length?: GLuint) | void | 
| blitFramebuffer(srcX0: GLint, srcY0: GLint, srcX1: GLint, srcY1: GLint, dstX0: GLint, dstY0: GLint, dstX1: GLint, dstY1: GLint, mask: GLbitfield, filter: GLenum) | void | 
| framebufferTextureLayer(target: GLenum, attachment: GLenum, texture: WebGLTexture \| null, level: GLint, layer: GLint) | void | 
| invalidateFramebuffer(target: GLenum, attachments: GLenum[]) | void | 
| invalidateSubFramebuffer(target: GLenum, attachments: GLenum[], x: GLint, y: GLint, width: GLsizei, height: GLsizei) | void | 
| readBuffer(src: GLenum) | void | 
| getInternalformatParameter(target: GLenum, internalformat: GLenum, pname: GLenum) | any | 
| renderbufferStorageMultisample(target: GLenum, samples: GLsizei, internalformat: GLenum, width: GLsizei, height: GLsizei) | void | 
| texStorage2D(target: GLenum, levels: GLsizei, internalformat: GLenum, width: GLsizei, height: GLsizei) | void | 
| texStorage3D(target: GLenum, levels: GLsizei, internalformat: GLenum, width: GLsizei, height: GLsizei, depth: GLsizei) | void | 
| texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, pboOffset: GLintptr) | void | 
| texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, source: TexImageSource) | void | 
| texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, srcData: ArrayBufferView \| null) | void | 
| texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, srcData: ArrayBufferView, srcOffset: GLuint) | void | 
| texSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, type: GLenum, pboOffset: GLintptr) | void | 
| texSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, type: GLenum, source: TexImageSource) | void | 
| texSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, type: GLenum, srcData: ArrayBufferView \| null, srcOffset?: GLuint) | void | 
| copyTexSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, x: GLint, y: GLint, width: GLsizei, height: GLsizei) | void | 
| compressedTexImage3D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, imageSize: GLsizei, offset: GLintptr) | void | 
| compressedTexImage3D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint) | void | 
| compressedTexSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, imageSize: GLsizei, offset: GLintptr) | void | 
| compressedTexSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint) | void | 
| getFragDataLocation(program: WebGLProgram, name: string) | GLint | 
| uniform1ui(location: WebGLUniformLocation \| null, v0: GLuint) | void | 
| uniform2ui(location: WebGLUniformLocation \| null, v0: GLuint, v1: GLuint) | void | 
| uniform3ui(location: WebGLUniformLocation \| null, v0: GLuint, v1: GLuint, v2: GLuint) | void | 
| uniform4ui(location: WebGLUniformLocation \| null, v0: GLuint, v1: GLuint, v2: GLuint, v3: GLuint) | void | 
| uniform1uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniform2uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniform3uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniform4uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniformMatrix3x2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniformMatrix4x2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniformMatrix2x3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniformMatrix4x3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniformMatrix2x4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniformMatrix3x4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| vertexAttribI4i(index: GLuint, x: GLint, y: GLint, z: GLint, w: GLint) | void | 
| vertexAttribI4iv(index: GLuint, values: Int32List) | void | 
| vertexAttribI4ui(index: GLuint, x: GLuint, y: GLuint, z: GLuint, w: GLuint) | void | 
| vertexAttribI4uiv(index: GLuint, values: Uint32List) | void | 
| vertexAttribIPointer(index: GLuint, size: GLint, type: GLenum, stride: GLsizei, offset: GLintptr) | void | 
| vertexAttribDivisor(index: GLuint, divisor: GLuint) | void | 
| drawArraysInstanced(mode: GLenum, first: GLint, count: GLsizei, instanceCount: GLsizei) | void | 
| drawElementsInstanced(mode: GLenum, count: GLsizei, type: GLenum, offset: GLintptr, instanceCount: GLsizei) | void | 
| drawRangeElements(mode: GLenum, start: GLuint, end: GLuint, count: GLsizei, type: GLenum, offset: GLintptr) | void | 
| drawBuffers(buffers: GLenum[]) | void | 
| clearBufferfv(buffer: GLenum, drawbuffer: GLint, values: Float32List, srcOffset?: GLuint) | void | 
| clearBufferiv(buffer: GLenum, drawbuffer: GLint, values: Int32List, srcOffset?: GLuint) | void | 
| clearBufferuiv(buffer: GLenum, drawbuffer: GLint, values: Uint32List, srcOffset?: GLuint) | void | 
| clearBufferfi(buffer: GLenum, drawbuffer: GLint, depth: GLfloat, stencil: GLint) | void | 
| createQuery() | WebGLQuery \| null | 
| deleteQuery(query: WebGLQuery \| null) | void | 
| isQuery(query: WebGLQuery \| null) | GLboolean | 
| beginQuery(target: GLenum, query: WebGLQuery) | void | 
| endQuery(target: GLenum) | void | 
| getQuery(target: GLenum, pname: GLenum) | WebGLQuery \| null | 
| getQueryParameter(query: WebGLQuery, pname: GLenum) | any | 
| createSampler() | WebGLSampler \| null | 
| deleteSampler(sampler: WebGLSampler \| null) | void | 
| isSampler(sampler: WebGLSampler \| null) | GLboolean | 
| bindSampler(unit: GLuint, sampler: WebGLSampler \| null) | void | 
| samplerParameteri(sampler: WebGLSampler, pname: GLenum, param: GLint) | void | 
| samplerParameterf(sampler: WebGLSampler, pname: GLenum, param: GLfloat) | void; | 
| getSamplerParameter(sampler: WebGLSampler, pname: GLenum) | any | 
| fenceSync(condition: GLenum, flags: GLbitfield) | WebGLSync \| null | 
| isSync(sync: WebGLSync \| null) | GLboolean | 
| deleteSync(sync: WebGLSync \| null) | void | 
| clientWaitSync(sync: WebGLSync, flags: GLbitfield, timeout: GLuint64) | GLenum | 
| waitSync(sync: WebGLSync, flags: GLbitfield, timeout: GLint64) | void | 
| getSyncParameter(sync: WebGLSync, pname: GLenum) | any | 
| createTransformFeedback() | WebGLTransformFeedback \| null | 
| deleteTransformFeedback(tf: WebGLTransformFeedback \| null) | void | 
| isTransformFeedback(tf: WebGLTransformFeedback \| null) | GLboolean | 
| bindTransformFeedback(target: GLenum, tf: WebGLTransformFeedback \| null) | void | 
| beginTransformFeedback(primitiveMode: GLenum) | void | 
| endTransformFeedback() | void | 
| transformFeedbackVaryings(program: WebGLProgram, varyings: string[], bufferMode: GLenum) | void | 
| getTransformFeedbackVarying(program: WebGLProgram, index: GLuint) | WebGLActiveInfo \| null | 
| pauseTransformFeedback() | void | 
| resumeTransformFeedback() | void | 
| bindBufferBase(target: GLenum, index: GLuint, buffer: WebGLBuffer \| null) | void | 
| bindBufferRange(target: GLenum, index: GLuint, buffer: WebGLBuffer \| null, offset: GLintptr, size: GLsizeiptr) | void | 
| getIndexedParameter(target: GLenum, index: GLuint) | any | 
| getUniformIndices(program: WebGLProgram, uniformNames: string[]) | GLuint[] \| null | 
| getActiveUniforms(program: WebGLProgram, uniformIndices: GLuint[], pname: GLenum) | any | 
| getUniformBlockIndex(program: WebGLProgram, uniformBlockName: string) | GLuint | 
| getActiveUniformBlockParameter(program: WebGLProgram, uniformBlockIndex: GLuint, pname: GLenum) | any | 
| getActiveUniformBlockName(program: WebGLProgram, uniformBlockIndex: GLuint) | string \| null | 
| uniformBlockBinding(program: WebGLProgram, uniformBlockIndex: GLuint, uniformBlockBinding: GLuint) | void | 
| createVertexArray() | WebGLVertexArrayObject \| null | 
| deleteVertexArray(vertexArray: WebGLVertexArrayObject \| null) | void | 
| isVertexArray(vertexArray: WebGLVertexArrayObject \| null) | GLboolean | 
| bindVertexArray(array: WebGLVertexArrayObject \| null) | void | 


## WebGL2RenderingContextOverloads

WebGL2RenderingContextOverloads

  | 方法 | 返回值类型 | 
| -------- | -------- |
| bufferData(target: GLenum, size: GLsizeiptr, usage: GLenum) | void | 
| bufferData(target: GLenum, srcData: BufferSource \| null, usage: GLenum) | void | 
| bufferSubData(target: GLenum, dstByteOffset: GLintptr, srcData: BufferSource) | void | 
| bufferData(target: GLenum, srcData: ArrayBufferView, usage: GLenum, srcOffset: GLuint, length?: GLuint) | void | 
| bufferSubData(target: GLenum, dstByteOffset: GLintptr, srcData: ArrayBufferView, srcOffset: GLuint, length?: GLuint) | void | 
| texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null) | void | 
| texImage2D(target: GLenum, level: GLint, internalformat: GLint, format: GLenum, type: GLenum, source: TexImageSource) | void | 
| texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null) | void | 
| texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, format: GLenum, type: GLenum, source: TexImageSource) | void | 
| texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, pboOffset: GLintptr) | void | 
| texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, source: TexImageSource) | void | 
| texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, srcData: ArrayBufferView, srcOffset: GLuint) | void | 
| texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pboOffset: GLintptr) | void | 
| texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, source: TexImageSource) | void | 
| texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, srcData: ArrayBufferView, srcOffset: GLuint) | void | 
| compressedTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, border: GLint, imageSize: GLsizei, offset: GLintptr) | void | 
| compressedTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, border: GLint, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint) | void | 
| compressedTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, imageSize: GLsizei, offset: GLintptr) | void | 
| compressedTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint) | void | 
| uniform1fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniform2fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniform3fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniform4fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniform1iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniform2iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniform3iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniform4iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniformMatrix2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniformMatrix3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| uniformMatrix4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint) | void | 
| readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, dstData: ArrayBufferView \| null) | void | 
| readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, offset: GLintptr) | void | 
| readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, dstData: ArrayBufferView, dstOffset: GLuint) | void | 
