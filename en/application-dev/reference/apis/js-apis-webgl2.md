# webgl2

>  **NOTE**<br/>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


This module provides WebGL APIs that correspond to the OpenGL ES 3.0 feature set. For more information, see [WebGL™](https://www.khronos.org/registry/webgl/specs/latest/2.0/).


## Invoking Method

Create a **<canvas\>** component in the HML file. The following is an example:


```html
<!--xxx.hml-->
<div class="container">
    <canvas ref="canvas1" style="width : 400px; height : 200px; background-color : lightyellow;"></canvas>
    <button class="btn-button" onclick="BtnDraw2D">BtnDraw2D</button>
</div>
```

Obtain the **<canvas\>** component instance in the JS file. The following is an example:


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


## Interface

**System capability**: SystemCapability.Graphic.Graphic2D.WebGL2

  **Table 2** Interface

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

  | Method| Return Value Type| 
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
