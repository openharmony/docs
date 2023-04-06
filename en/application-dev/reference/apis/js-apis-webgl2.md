# WebGL2

The **WebGL2** module supports graphics drawing, such as processing the graphics position and color. WebGL2 provides enhanced capabilities in the rendering pipeline and shader language than WebGL.

This module provides WebGL APIs that correspond to the OpenGL ES 3.0 feature set. For more information, see [WebGL™](https://www.khronos.org/registry/webgl/specs/latest/2.0/).

>  **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> WebGL2 complies with the OpenGL protocol and does not support multi-thread calling.
>
> This module can be used only in the JavaScript-compatible web-like development paradigm.


## Invoking Method

Create a **\<canvas>** component in the HML file. The following is an example:


```html
<!--xxx.hml-->
<div class="container">
    <canvas ref="canvas1" style="width : 400px; height : 200px; background-color : lightyellow;"></canvas>
    <button class="btn-button" onclick="BtnDraw2D">BtnDraw2D</button>
</div>
```

Obtain the **\<canvas>** component instance in the JS file. The following is an example:


```js
// Obtain the <canvas> component instance.
const el = this.$refs.canvas1;
// Obtain the WebGL context from the <canvas> component instance.
const gl = el.getContext('webgl2');
// Call the WebGL API.
gl.clearColor(0.0, 0.0, 0.0, 1.0);
```


## Type

**System capability**: SystemCapability.Graphic.Graphic2D.WebGL2

**Table 1** Type

| Name| Type|
| -------- | -------- |
| GLenum | number |
| GLint64 | number |
| GLuint64 | number |
| Uint32List | array |


## APIs

**System capability**: SystemCapability.Graphic.Graphic2D.WebGL2

**Table 2** APIs

| Name|
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


### Attributes

  | Name| Type| Mandatory| 
| -------- | -------- | -------- |
| READ_BUFFER | GLenum | Yes| 
| UNPACK_ROW_LENGTH | GLenum | Yes| 
| UNPACK_SKIP_ROWS | GLenum | Yes| 
| UNPACK_SKIP_PIXELS | GLenum | Yes| 
| PACK_ROW_LENGTH | GLenum | Yes| 
| PACK_SKIP_ROWS | GLenum | Yes| 
| PACK_SKIP_PIXELS | GLenum | Yes| 
| COLOR | GLenum | Yes| 
| DEPTH | GLenum | Yes| 
| STENCIL | GLenum | Yes| 
| RED | GLenum | Yes| 
| RGB8 | GLenum | Yes| 
| RGBA8 | GLenum | Yes| 
| RGB10_A2 | GLenum | Yes| 
| TEXTURE_BINDING_3D | GLenum | Yes| 
| UNPACK_SKIP_IMAGES | GLenum | Yes| 
| UNPACK_IMAGE_HEIGHT | GLenum | Yes| 
| TEXTURE_3D | GLenum | Yes| 
| TEXTURE_WRAP_R | GLenum | Yes| 
| MAX_3D_TEXTURE_SIZE | GLenum | Yes| 
| UNSIGNED_INT_2_10_10_10_REV | GLenum | Yes| 
| MAX_ELEMENTS_VERTICES | GLenum | Yes| 
| MAX_ELEMENTS_INDICES | GLenum | Yes| 
| TEXTURE_MIN_LOD | GLenum | Yes| 
| TEXTURE_MAX_LOD | GLenum | Yes| 
| TEXTURE_BASE_LEVEL | GLenum | Yes| 
| TEXTURE_MAX_LEVEL | GLenum | Yes| 
| MIN | GLenum | Yes| 
| MAX | GLenum | Yes| 
| DEPTH_COMPONENT24 | GLenum | Yes| 
| MAX_TEXTURE_LOD_BIAS | GLenum | Yes| 
| TEXTURE_COMPARE_MODE | GLenum | Yes| 
| TEXTURE_COMPARE_FUNC | GLenum | Yes| 
| CURRENT_QUERY | GLenum | Yes| 
| QUERY_RESULT | GLenum | Yes| 
| QUERY_RESULT_AVAILABLE | GLenum | Yes| 
| STREAM_READ | GLenum | Yes| 
| STREAM_COPY | GLenum | Yes| 
| STATIC_READ | GLenum | Yes| 
| STATIC_COPY | GLenum | Yes| 
| DYNAMIC_READ | GLenum | Yes| 
| DYNAMIC_COPY | GLenum | Yes| 
| MAX_DRAW_BUFFERS | GLenum | Yes| 
| DRAW_BUFFER0 | GLenum | Yes| 
| DRAW_BUFFER1 | GLenum | Yes| 
| DRAW_BUFFER2 | GLenum | Yes| 
| DRAW_BUFFER3 | GLenum | Yes| 
| DRAW_BUFFER4 | GLenum | Yes| 
| DRAW_BUFFER5 | GLenum | Yes| 
| DRAW_BUFFER6 | GLenum | Yes| 
| DRAW_BUFFER7 | GLenum | Yes| 
| DRAW_BUFFER8 | GLenum | Yes| 
| DRAW_BUFFER9 | GLenum | Yes| 
| DRAW_BUFFER10 | GLenum | Yes| 
| DRAW_BUFFER11 | GLenum | Yes| 
| DRAW_BUFFER12 | GLenum | Yes| 
| DRAW_BUFFER13 | GLenum | Yes| 
| DRAW_BUFFER14 | GLenum | Yes| 
| DRAW_BUFFER15 | GLenum | Yes| 
| MAX_FRAGMENT_UNIFORM_COMPONENTS | GLenum | Yes| 
| MAX_VERTEX_UNIFORM_COMPONENTS | GLenum | Yes| 
| SAMPLER_3D | GLenum | Yes| 
| SAMPLER_2D_SHADOW | GLenum | Yes| 
| FRAGMENT_SHADER_DERIVATIVE_HINT | GLenum | Yes| 
| PIXEL_PACK_BUFFER | GLenum | Yes| 
| PIXEL_UNPACK_BUFFER | GLenum | Yes| 
| PIXEL_PACK_BUFFER_BINDING | GLenum | Yes| 
| PIXEL_UNPACK_BUFFER_BINDING | GLenum | Yes| 
| FLOAT_MAT2x3 | GLenum | Yes| 
| FLOAT_MAT2x4 | GLenum | Yes| 
| FLOAT_MAT3x2 | GLenum | Yes| 
| FLOAT_MAT3x4 | GLenum | Yes| 
| FLOAT_MAT4x2 | GLenum | Yes| 
| FLOAT_MAT4x3 | GLenum | Yes| 
| SRGB | GLenum | Yes| 
| SRGB8 | GLenum | Yes| 
| SRGB8_ALPHA8 | GLenum | Yes| 
| COMPARE_REF_TO_TEXTURE | GLenum | Yes| 
| RGBA32F | GLenum | Yes| 
| RGB32F | GLenum | Yes| 
| RGBA16F | GLenum | Yes| 
| RGB16F | GLenum | Yes| 
| VERTEX_ATTRIB_ARRAY_INTEGER | GLenum | Yes| 
| MAX_ARRAY_TEXTURE_LAYERS | GLenum | Yes| 
| MIN_PROGRAM_TEXEL_OFFSET | GLenum | Yes| 
| MAX_PROGRAM_TEXEL_OFFSET | GLenum | Yes| 
| MAX_VARYING_COMPONENTS | GLenum | Yes| 
| TEXTURE_2D_ARRAY | GLenum | Yes| 
| TEXTURE_BINDING_2D_ARRAY | GLenum | Yes| 
| R11F_G11F_B10F | GLenum | Yes| 
| UNSIGNED_INT_10F_11F_11F_REV | GLenum | Yes| 
| RGB9_E5 | GLenum | Yes| 
| UNSIGNED_INT_5_9_9_9_REV | GLenum | Yes| 
| TRANSFORM_FEEDBACK_BUFFER_MODE | GLenum | Yes| 
| MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS | GLenum | Yes| 
| TRANSFORM_FEEDBACK_VARYINGS | GLenum | Yes| 
| TRANSFORM_FEEDBACK_BUFFER_START | GLenum | Yes| 
| TRANSFORM_FEEDBACK_BUFFER_SIZE | GLenum | Yes| 
| TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN | GLenum | Yes| 
| RASTERIZER_DISCARD | GLenum | Yes| 
| MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS | GLenum | Yes| 
| MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS | GLenum | Yes| 
| INTERLEAVED_ATTRIBS | GLenum | Yes| 
| SEPARATE_ATTRIBS | GLenum | Yes| 
| TRANSFORM_FEEDBACK_BUFFER | GLenum | Yes| 
| TRANSFORM_FEEDBACK_BUFFER_BINDING | GLenum | Yes| 
| RGBA32UI | GLenum | Yes| 
| RGB32UI | GLenum | Yes| 
| RGBA16UI | GLenum | Yes| 
| RGB16UI | GLenum | Yes| 
| RGBA8UI | GLenum | Yes| 
| RGB8UI | GLenum | Yes| 
| RGBA32I | GLenum | Yes| 
| RGB32I | GLenum | Yes| 
| RGBA16I | GLenum | Yes| 
| RGB16I | GLenum | Yes| 
| RGBA8I | GLenum | Yes| 
| RGB8I | GLenum | Yes| 
| RED_INTEGER | GLenum | Yes| 
| RGB_INTEGER | GLenum | Yes| 
| RGBA_INTEGER | GLenum | Yes| 
| SAMPLER_2D_ARRAY | GLenum | Yes| 
| SAMPLER_2D_ARRAY_SHADOW | GLenum | Yes| 
| SAMPLER_CUBE_SHADOW | GLenum | Yes| 
| UNSIGNED_INT_VEC2 | GLenum | Yes| 
| UNSIGNED_INT_VEC3 | GLenum | Yes| 
| UNSIGNED_INT_VEC4 | GLenum | Yes| 
| INT_SAMPLER_2D | GLenum | Yes| 
| INT_SAMPLER_3D | GLenum | Yes| 
| INT_SAMPLER_CUBE | GLenum | Yes| 
| INT_SAMPLER_2D_ARRAY | GLenum | Yes| 
| UNSIGNED_INT_SAMPLER_2D | GLenum | Yes| 
| UNSIGNED_INT_SAMPLER_3D | GLenum | Yes| 
| UNSIGNED_INT_SAMPLER_CUBE | GLenum | Yes| 
| UNSIGNED_INT_SAMPLER_2D_ARRAY | GLenum | Yes| 
| DEPTH_COMPONENT32F | GLenum | Yes| 
| DEPTH32F_STENCIL8 | GLenum | Yes| 
| FLOAT_32_UNSIGNED_INT_24_8_REV | GLenum | Yes| 
| FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING | GLenum | Yes| 
| FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE | GLenum | Yes| 
| FRAMEBUFFER_ATTACHMENT_RED_SIZE | GLenum | Yes| 
| FRAMEBUFFER_ATTACHMENT_GREEN_SIZE | GLenum | Yes| 
| FRAMEBUFFER_ATTACHMENT_BLUE_SIZE | GLenum | Yes| 
| FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE | GLenum | Yes| 
| FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE | GLenum | Yes| 
| FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE | GLenum | Yes| 
| FRAMEBUFFER_DEFAULT | GLenum | Yes| 
| UNSIGNED_INT_24_8 | GLenum | Yes| 
| DEPTH24_STENCIL8 | GLenum | Yes| 
| UNSIGNED_NORMALIZED | GLenum | Yes| 
| DRAW_FRAMEBUFFER_BINDING | GLenum | Yes| 
| READ_FRAMEBUFFER | GLenum | Yes| 
| DRAW_FRAMEBUFFER | GLenum | Yes| 
| READ_FRAMEBUFFER_BINDING | GLenum | Yes| 
| RENDERBUFFER_SAMPLES | GLenum | Yes| 
| FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER | GLenum | Yes| 
| MAX_COLOR_ATTACHMENTS | GLenum | Yes| 
| COLOR_ATTACHMENT1 | GLenum | Yes| 
| COLOR_ATTACHMENT2 | GLenum | Yes| 
| COLOR_ATTACHMENT3 | GLenum | Yes| 
| COLOR_ATTACHMENT4 | GLenum | Yes| 
| COLOR_ATTACHMENT5 | GLenum | Yes| 
| COLOR_ATTACHMENT6 | GLenum | Yes| 
| COLOR_ATTACHMENT7 | GLenum | Yes| 
| COLOR_ATTACHMENT8 | GLenum | Yes| 
| COLOR_ATTACHMENT9 | GLenum | Yes| 
| COLOR_ATTACHMENT10 | GLenum | Yes| 
| COLOR_ATTACHMENT11 | GLenum | Yes| 
| COLOR_ATTACHMENT12 | GLenum | Yes| 
| COLOR_ATTACHMENT13 | GLenum | Yes| 
| COLOR_ATTACHMENT14 | GLenum | Yes| 
| COLOR_ATTACHMENT15 | GLenum | Yes| 
| FRAMEBUFFER_INCOMPLETE_MULTISAMPLE | GLenum | Yes| 
| MAX_SAMPLES | GLenum | Yes| 
| HALF_FLOAT | GLenum | Yes| 
| RG | GLenum | Yes| 
| RG_INTEGER | GLenum | Yes| 
| R8 | GLenum | Yes| 
| RG8 | GLenum | Yes| 
| R16F | GLenum | Yes| 
| R32F | GLenum | Yes| 
| RG16F | GLenum | Yes| 
| RG32F | GLenum | Yes| 
| R8I | GLenum | Yes| 
| R8UI | GLenum | Yes| 
| R16I | GLenum | Yes| 
| R16UI | GLenum | Yes| 
| R32I | GLenum | Yes| 
| R32UI | GLenum | Yes| 
| RG8I | GLenum | Yes| 
| RG8UI | GLenum | Yes| 
| RG16I | GLenum | Yes| 
| RG16UI | GLenum | Yes| 
| RG32I | GLenum | Yes| 
| RG32UI | GLenum | Yes| 
| VERTEX_ARRAY_BINDING | GLenum | Yes| 
| R8_SNORM | GLenum | Yes| 
| RG8_SNORM | GLenum | Yes| 
| RGB8_SNORM | GLenum | Yes| 
| SIGNED_NORMALIZED | GLenum | Yes| 
| COPY_READ_BUFFER | GLenum | Yes| 
| COPY_WRITE_BUFFER | GLenum | Yes| 
| COPY_READ_BUFFER_BINDING | GLenum | Yes| 
| COPY_WRITE_BUFFER_BINDING | GLenum | Yes| 
| UNIFORM_BUFFER | GLenum | Yes| 
| UNIFORM_BUFFER_BINDING | GLenum | Yes| 
| UNIFORM_BUFFER_START | GLenum | Yes| 
| UNIFORM_BUFFER_SIZE | GLenum | Yes| 
| MAX_VERTEX_UNIFORM_BLOCKS | GLenum | Yes| 
| MAX_FRAGMENT_UNIFORM_BLOCKS | GLenum | Yes| 
| MAX_COMBINED_UNIFORM_BLOCKS | GLenum | Yes| 
| MAX_UNIFORM_BUFFER_BINDINGS | GLenum | Yes| 
| MAX_UNIFORM_BLOCK_SIZE | GLenum | Yes| 
| MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS | GLenum | Yes| 
| MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS | GLenum | Yes| 
| UNIFORM_BUFFER_OFFSET_ALIGNMENT | GLenum | Yes| 
| ACTIVE_UNIFORM_BLOCKS | GLenum | Yes| 
| UNIFORM_TYPE | GLenum | Yes| 
| UNIFORM_SIZE | GLenum | Yes| 
| UNIFORM_BLOCK_INDEX | GLenum | Yes| 
| UNIFORM_OFFSET | GLenum | Yes| 
| UNIFORM_ARRAY_STRIDE | GLenum | Yes| 
| UNIFORM_MATRIX_STRIDE | GLenum | Yes| 
| UNIFORM_IS_ROW_MAJOR | GLenum | Yes| 
| UNIFORM_BLOCK_BINDING | GLenum | Yes| 
| UNIFORM_BLOCK_DATA_SIZE | GLenum | Yes| 
| UNIFORM_BLOCK_ACTIVE_UNIFORMS | GLenum | Yes| 
| UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES | GLenum | Yes| 
| UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER | GLenum | Yes| 
| UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER | GLenum | Yes| 
| INVALID_INDEX | GLenum | Yes| 
| MAX_VERTEX_OUTPUT_COMPONENTS | GLenum | Yes| 
| MAX_FRAGMENT_INPUT_COMPONENTS | GLenum | Yes| 
| MAX_SERVER_WAIT_TIMEOUT | GLenum | Yes| 
| OBJECT_TYPE | GLenum | Yes| 
| SYNC_CONDITION | GLenum | Yes| 
| SYNC_STATUS | GLenum | Yes| 
| SYNC_FLAGS | GLenum | Yes| 
| SYNC_FENCE | GLenum | Yes| 
| SYNC_GPU_COMMANDS_COMPLETE | GLenum | Yes| 
| UNSIGNALED | GLenum | Yes| 
| SIGNALED | GLenum | Yes| 
| ALREADY_SIGNALED | GLenum | Yes| 
| TIMEOUT_EXPIRED | GLenum | Yes| 
| CONDITION_SATISFIED | GLenum | Yes| 
| WAIT_FAILED | GLenum | Yes| 
| SYNC_FLUSH_COMMANDS_BIT | GLenum | Yes| 
| VERTEX_ATTRIB_ARRAY_DIVISOR | GLenum | Yes| 
| ANY_SAMPLES_PASSED | GLenum | Yes| 
| ANY_SAMPLES_PASSED_CONSERVATIVE | GLenum | Yes| 
| SAMPLER_BINDING | GLenum | Yes| 
| RGB10_A2UI | GLenum | Yes| 
| INT_2_10_10_10_REV | GLenum | Yes| 
| TRANSFORM_FEEDBACK | GLenum | Yes| 
| TRANSFORM_FEEDBACK_PAUSED | GLenum | Yes| 
| TRANSFORM_FEEDBACK_ACTIVE | GLenum | Yes| 
| TRANSFORM_FEEDBACK_BINDING | GLenum | Yes| 
| TEXTURE_IMMUTABLE_FORMAT | GLenum | Yes| 
| MAX_ELEMENT_INDEX | GLenum | Yes| 
| TEXTURE_IMMUTABLE_LEVELS | GLenum | Yes| 
| TIMEOUT_IGNORED | GLint64 | Yes| 
| MAX_CLIENT_WAIT_TIMEOUT_WEBGL | GLenum | Yes| 


### Methods

  | Method| Return Value Type| 
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

  | Method| Return Value Type| 
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
