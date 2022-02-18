# WebGL2

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


This module provides WebGL APIs that correspond to the OpenGL ES 3.0 feature set. For more information, see [WebGL™](https://www.khronos.org/registry/webgl/specs/latest/2.0/).



## Modules to Import

```
import webgl from 'ohos.webglnapi'
```


## System Capabilities

SystemCapability.Graphic.Graphic2D.WebGL2


## Invoking Method

```
// Obtain the <canvas\> component instance.
const el = this.$refs.canvas
// Obtain the WebGL context from the <canvas\> component instance.
const gl = el.getContext('webgl');
const gl2 = el.getContext('webgl2');
// Call the WebGL API.
gl2.readBuffer(gl.COLOR_ATTACHMENT0)
```


## GLenum

| Name| Type|
| -------- | -------- |
| GLenum | number |


## Glint64

| Name| Type|
| -------- | -------- |
| Glint64 | number |


## Gluint64

| Name| Type|
| -------- | -------- |
| Gluint64 | number |


## Uint32List

| Name| Type|
| -------- | -------- |
| Uint32List | array |


## webgl.webGL2RenderingContexBase

WebGL2RenderingContexBase


### Attributes

| Name| Type| Mandatory|
| -------- | ------- | --------- |
| READ_BUFFER | [GLenum](#GLenum) | Yes|
| UNPACK_ROW_LENGTH | [GLenum](#GLenum) | Yes|
| UNPACK_SKIP_ROWS  | [GLenum](#GLenum) | Yes|
| UNPACK_SKIP_PIXELS  | [GLenum](#GLenum) | Yes|
| PACK_ROW_LENGTH  | [GLenum](#GLenum) | Yes|
| PACK_SKIP_ROWS  | [GLenum](#GLenum) | Yes|
| PACK_SKIP_PIXELS  | [GLenum](#GLenum) | Yes|
| COLOR  | [GLenum](#GLenum) | Yes|
| DEPTH  | [GLenum](#GLenum) | Yes|
| STENCIL  | [GLenum](#GLenum) | Yes|
| RED  | [GLenum](#GLenum) | Yes|
| RGB8  | [GLenum](#GLenum) | Yes|
| RGBA8  | [GLenum](#GLenum) | Yes|
| RGB10_A2  | [GLenum](#GLenum) | Yes|
| TEXTURE_BINDING_3D  | [GLenum](#GLenum) | Yes|
| UNPACK_SKIP_IMAGES  | [GLenum](#GLenum) | Yes|
| UNPACK_IMAGE_HEIGHT  | [GLenum](#GLenum) | Yes|
| TEXTURE_3D  | [GLenum](#GLenum) | Yes|
| TEXTURE_WRAP_R  | [GLenum](#GLenum) | Yes|
| MAX_3D_TEXTURE_SIZE  | [GLenum](#GLenum) | Yes|
| UNSIGNED_INT_2_10_10_10_REV  | [GLenum](#GLenum) | Yes|
| MAX_ELEMENTS_VERTICES  | [GLenum](#GLenum) | Yes|
| MAX_ELEMENTS_INDICES  | [GLenum](#GLenum) | Yes|
| TEXTURE_MIN_LOD  | [GLenum](#GLenum) | Yes|
| TEXTURE_MAX_LOD  | [GLenum](#GLenum) | Yes|
| TEXTURE_BASE_LEVEL  | [GLenum](#GLenum) | Yes|
| TEXTURE_MAX_LEVEL  | [GLenum](#GLenum) | Yes|
| MIN  | [GLenum](#GLenum) | Yes|
| MAX  | [GLenum](#GLenum) | Yes|
| DEPTH_COMPONENT24  | [GLenum](#GLenum) | Yes|
| MAX_TEXTURE_LOD_BIAS  | [GLenum](#GLenum) | Yes|
| TEXTURE_COMPARE_MODE  | [GLenum](#GLenum) | Yes|
| TEXTURE_COMPARE_FUNC  | [GLenum](#GLenum) | Yes|
| CURRENT_QUERY  | [GLenum](#GLenum) | Yes|
| QUERY_RESULT  | [GLenum](#GLenum) | Yes|
| QUERY_RESULT_AVAILABLE  | [GLenum](#GLenum) | Yes|
| STREAM_READ  | [GLenum](#GLenum) | Yes|
| STREAM_COPY  | [GLenum](#GLenum) | Yes|
| STATIC_READ  | [GLenum](#GLenum) | Yes|
| STATIC_COPY  | [GLenum](#GLenum) | Yes|
| DYNAMIC_READ  | [GLenum](#GLenum) | Yes|
| DYNAMIC_COPY  | [GLenum](#GLenum) | Yes|
| MAX_DRAW_BUFFERS  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER0  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER1  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER2  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER3  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER4  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER5  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER6  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER7  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER8  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER9  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER10  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER11  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER12  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER13  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER14  | [GLenum](#GLenum) | Yes|
| DRAW_BUFFER15  | [GLenum](#GLenum) | Yes|
| MAX_FRAGMENT_UNIFORM_COMPONENTS  | [GLenum](#GLenum) | Yes|
| MAX_VERTEX_UNIFORM_COMPONENTS  | [GLenum](#GLenum) | Yes|
| SAMPLER_3D  | [GLenum](#GLenum) | Yes|
| SAMPLER_2D_SHADOW  | [GLenum](#GLenum) | Yes|
| FRAGMENT_SHADER_DERIVATIVE_HINT  | [GLenum](#GLenum) | Yes|
| PIXEL_PACK_BUFFER  | [GLenum](#GLenum) | Yes|
| PIXEL_UNPACK_BUFFER  | [GLenum](#GLenum) | Yes|
| PIXEL_PACK_BUFFER_BINDING  | [GLenum](#GLenum) | Yes|
| PIXEL_UNPACK_BUFFER_BINDING  | [GLenum](#GLenum) | Yes|
| FLOAT_MAT2x3  | [GLenum](#GLenum) | Yes|
| FLOAT_MAT2x4  | [GLenum](#GLenum) | Yes|
| FLOAT_MAT3x2  | [GLenum](#GLenum) | Yes|
| FLOAT_MAT3x4  | [GLenum](#GLenum) | Yes|
| FLOAT_MAT4x2  | [GLenum](#GLenum) | Yes|
| FLOAT_MAT4x3  | [GLenum](#GLenum) | Yes|
| SRGB  | [GLenum](#GLenum) | Yes|
| SRGB8  | [GLenum](#GLenum) | Yes|
| SRGB8_ALPHA8  | [GLenum](#GLenum) | Yes|
| COMPARE_REF_TO_TEXTURE  | [GLenum](#GLenum) | Yes|
| RGBA32F  | [GLenum](#GLenum) | Yes|
| RGB32F  | [GLenum](#GLenum) | Yes|
| RGBA16F  | [GLenum](#GLenum) | Yes|
| RGB16F  | [GLenum](#GLenum) | Yes|
| VERTEX_ATTRIB_ARRAY_INTEGER  | [GLenum](#GLenum) | Yes|
| MAX_ARRAY_TEXTURE_LAYERS  | [GLenum](#GLenum) | Yes|
| MIN_PROGRAM_TEXEL_OFFSET  | [GLenum](#GLenum) | Yes|
| MAX_PROGRAM_TEXEL_OFFSET  | [GLenum](#GLenum) | Yes|
| MAX_VARYING_COMPONENTS  | [GLenum](#GLenum) | Yes|
| TEXTURE_2D_ARRAY  | [GLenum](#GLenum) | Yes|
| TEXTURE_BINDING_2D_ARRAY  | [GLenum](#GLenum) | Yes|
| R11F_G11F_B10F  | [GLenum](#GLenum) | Yes|
| UNSIGNED_INT_10F_11F_11F_REV  | [GLenum](#GLenum) | Yes|
| RGB9_E5  | [GLenum](#GLenum) | Yes|
| UNSIGNED_INT_5_9_9_9_REV  | [GLenum](#GLenum) | Yes|
| TRANSFORM_FEEDBACK_BUFFER_MODE  | [GLenum](#GLenum) | Yes|
| MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS  | [GLenum](#GLenum) | Yes|
| TRANSFORM_FEEDBACK_VARYINGS  | [GLenum](#GLenum) | Yes|
| TRANSFORM_FEEDBACK_BUFFER_START  | [GLenum](#GLenum) | Yes|
| TRANSFORM_FEEDBACK_BUFFER_SIZE  | [GLenum](#GLenum) | Yes|
| TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN  | [GLenum](#GLenum) | Yes|
| RASTERIZER_DISCARD  | [GLenum](#GLenum) | Yes|
| MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS  | [GLenum](#GLenum) | Yes|
| MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS  | [GLenum](#GLenum) | Yes|
| INTERLEAVED_ATTRIBS  | [GLenum](#GLenum) | Yes|
| SEPARATE_ATTRIBS  | [GLenum](#GLenum) | Yes|
| TRANSFORM_FEEDBACK_BUFFER  | [GLenum](#GLenum) | Yes|
| TRANSFORM_FEEDBACK_BUFFER_BINDING  | [GLenum](#GLenum) | Yes|
| RGBA32UI  | [GLenum](#GLenum) | Yes|
| RGB32UI  | [GLenum](#GLenum) | Yes|
| RGBA16UI  | [GLenum](#GLenum) | Yes|
| RGB16UI  | [GLenum](#GLenum) | Yes|
| RGBA8UI  | [GLenum](#GLenum) | Yes|
| RGB8UI  | [GLenum](#GLenum) | Yes|
| RGBA32I  | [GLenum](#GLenum) | Yes|
| RGB32I  | [GLenum](#GLenum) | Yes|
| RGBA16I  | [GLenum](#GLenum) | Yes|
| RGB16I  | [GLenum](#GLenum) | Yes|
| RGBA8I  | [GLenum](#GLenum) | Yes|
| RGB8I  | [GLenum](#GLenum) | Yes|
| RED_INTEGER  | [GLenum](#GLenum) | Yes|
| RGB_INTEGER  | [GLenum](#GLenum) | Yes|
| RGBA_INTEGER  | [GLenum](#GLenum) | Yes|
| SAMPLER_2D_ARRAY  | [GLenum](#GLenum) | Yes|
| SAMPLER_2D_ARRAY_SHADOW  | [GLenum](#GLenum) | Yes|
| SAMPLER_CUBE_SHADOW  | [GLenum](#GLenum) | Yes|
| UNSIGNED_INT_VEC2  | [GLenum](#GLenum) | Yes|
| UNSIGNED_INT_VEC3  | [GLenum](#GLenum) | Yes|
| UNSIGNED_INT_VEC4  | [GLenum](#GLenum) | Yes|
| INT_SAMPLER_2D  | [GLenum](#GLenum) | Yes|
| INT_SAMPLER_3D  | [GLenum](#GLenum) | Yes|
| INT_SAMPLER_CUBE  | [GLenum](#GLenum) | Yes|
| INT_SAMPLER_2D_ARRAY  | [GLenum](#GLenum) | Yes|
| UNSIGNED_INT_SAMPLER_2D  | [GLenum](#GLenum) | Yes|
| UNSIGNED_INT_SAMPLER_3D  | [GLenum](#GLenum) | Yes|
| UNSIGNED_INT_SAMPLER_CUBE  | [GLenum](#GLenum) | Yes|
| UNSIGNED_INT_SAMPLER_2D_ARRAY  | [GLenum](#GLenum) | Yes|
| DEPTH_COMPONENT32F  | [GLenum](#GLenum) | Yes|
| DEPTH32F_STENCIL8  | [GLenum](#GLenum) | Yes|
| FLOAT_32_UNSIGNED_INT_24_8_REV  | [GLenum](#GLenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING  | [GLenum](#GLenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE  | [GLenum](#GLenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_RED_SIZE  | [GLenum](#GLenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_GREEN_SIZE  | [GLenum](#GLenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_BLUE_SIZE  | [GLenum](#GLenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE  | [GLenum](#GLenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE  | [GLenum](#GLenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE  | [GLenum](#GLenum) | Yes|
| FRAMEBUFFER_DEFAULT  | [GLenum](#GLenum) | Yes|
| UNSIGNED_INT_24_8  | [GLenum](#GLenum) | Yes|
| DEPTH24_STENCIL8  | [GLenum](#GLenum) | Yes|
| UNSIGNED_NORMALIZED  | [GLenum](#GLenum) | Yes|
| DRAW_FRAMEBUFFER_BINDING  | [GLenum](#GLenum) | Yes|
| READ_FRAMEBUFFER  | [GLenum](#GLenum) | Yes|
| DRAW_FRAMEBUFFER  | [GLenum](#GLenum) | Yes|
| READ_FRAMEBUFFER_BINDING  | [GLenum](#GLenum) | Yes|
| RENDERBUFFER_SAMPLES  | [GLenum](#GLenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER  | [GLenum](#GLenum) | Yes|
| MAX_COLOR_ATTACHMENTS  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT1  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT2  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT3  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT4  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT5  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT6  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT7  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT8  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT9  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT10  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT11  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT12  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT13  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT14  | [GLenum](#GLenum) | Yes|
| COLOR_ATTACHMENT15  | [GLenum](#GLenum) | Yes|
| FRAMEBUFFER_INCOMPLETE_MULTISAMPLE  | [GLenum](#GLenum) | Yes|
| MAX_SAMPLES  | [GLenum](#GLenum) | Yes|
| HALF_FLOAT  | [GLenum](#GLenum) | Yes|
| RG  | [GLenum](#GLenum) | Yes|
| RG_INTEGER  | [GLenum](#GLenum) | Yes|
| R8  | [GLenum](#GLenum) | Yes|
| RG8  | [GLenum](#GLenum) | Yes|
| R16F  | [GLenum](#GLenum) | Yes|
| R32F  | [GLenum](#GLenum) | Yes|
| RG16F  | [GLenum](#GLenum) | Yes|
| RG32F  | [GLenum](#GLenum) | Yes|
| R8I  | [GLenum](#GLenum) | Yes|
| R8UI  | [GLenum](#GLenum) | Yes|
| R16I  | [GLenum](#GLenum) | Yes|
| R16UI  | [GLenum](#GLenum) | Yes|
| R32I  | [GLenum](#GLenum) | Yes|
| R32UI  | [GLenum](#GLenum) | Yes|
| RG8I  | [GLenum](#GLenum) | Yes|
| RG8UI  | [GLenum](#GLenum) | Yes|
| RG16I  | [GLenum](#GLenum) | Yes|
| RG16UI  | [GLenum](#GLenum) | Yes|
| RG32I  | [GLenum](#GLenum) | Yes|
| RG32UI  | [GLenum](#GLenum) | Yes|
| VERTEX_ARRAY_BINDING  | [GLenum](#GLenum) | Yes|
| R8_SNORM  | [GLenum](#GLenum) | Yes|
| RG8_SNORM  | [GLenum](#GLenum) | Yes|
| RGB8_SNORM  | [GLenum](#GLenum) | Yes|
| SIGNED_NORMALIZED  | [GLenum](#GLenum) | Yes|
| COPY_READ_BUFFER  | [GLenum](#GLenum) | Yes|
| COPY_WRITE_BUFFER  | [GLenum](#GLenum) | Yes|
| COPY_READ_BUFFER_BINDING  | [GLenum](#GLenum) | Yes|
| COPY_WRITE_BUFFER_BINDING  | [GLenum](#GLenum) | Yes|
| UNIFORM_BUFFER  | [GLenum](#GLenum) | Yes|
| UNIFORM_BUFFER_BINDING  | [GLenum](#GLenum) | Yes|
| UNIFORM_BUFFER_START  | [GLenum](#GLenum) | Yes|
| UNIFORM_BUFFER_SIZE  | [GLenum](#GLenum) | Yes|
| MAX_VERTEX_UNIFORM_BLOCKS  | [GLenum](#GLenum) | Yes|
| MAX_FRAGMENT_UNIFORM_BLOCKS  | [GLenum](#GLenum) | Yes|
| MAX_COMBINED_UNIFORM_BLOCKS  | [GLenum](#GLenum) | Yes|
| MAX_UNIFORM_BUFFER_BINDINGS  | [GLenum](#GLenum) | Yes|
| MAX_UNIFORM_BLOCK_SIZE  | [GLenum](#GLenum) | Yes|
| MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS  | [GLenum](#GLenum) | Yes|
| MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS  | [GLenum](#GLenum) | Yes|
| UNIFORM_BUFFER_OFFSET_ALIGNMENT  | [GLenum](#GLenum) | Yes|
| ACTIVE_UNIFORM_BLOCKS  | [GLenum](#GLenum) | Yes|
| UNIFORM_TYPE  | [GLenum](#GLenum) | Yes|
| UNIFORM_SIZE  | [GLenum](#GLenum) | Yes|
| UNIFORM_BLOCK_INDEX  | [GLenum](#GLenum) | Yes|
| UNIFORM_OFFSET  | [GLenum](#GLenum) | Yes|
| UNIFORM_ARRAY_STRIDE  | [GLenum](#GLenum) | Yes|
| UNIFORM_MATRIX_STRIDE  | [GLenum](#GLenum) | Yes|
| UNIFORM_IS_ROW_MAJOR  | [GLenum](#GLenum) | Yes|
| UNIFORM_BLOCK_BINDING  | [GLenum](#GLenum) | Yes|
| UNIFORM_BLOCK_DATA_SIZE  | [GLenum](#GLenum) | Yes|
| UNIFORM_BLOCK_ACTIVE_UNIFORMS  | [GLenum](#GLenum) | Yes|
| UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES  | [GLenum](#GLenum) | Yes|
| UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER  | [GLenum](#GLenum) | Yes|
| UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER  | [GLenum](#GLenum) | Yes|
| INVALID_INDEX  | [GLenum](#GLenum) | Yes|
| MAX_VERTEX_OUTPUT_COMPONENTS  | [GLenum](#GLenum) | Yes|
| MAX_FRAGMENT_INPUT_COMPONENTS  | [GLenum](#GLenum) | Yes|
| MAX_SERVER_WAIT_TIMEOUT  | [GLenum](#GLenum) | Yes|
| OBJECT_TYPE  | [GLenum](#GLenum) | Yes|
| SYNC_CONDITION  | [GLenum](#GLenum) | Yes|
| SYNC_STATUS  | [GLenum](#GLenum) | Yes|
| SYNC_FLAGS  | [GLenum](#GLenum) | Yes|
| SYNC_FENCE  | [GLenum](#GLenum) | Yes|
| SYNC_GPU_COMMANDS_COMPLETE  | [GLenum](#GLenum) | Yes|
| UNSIGNALED  | [GLenum](#GLenum) | Yes|
| SIGNALED  | [GLenum](#GLenum) | Yes|
| ALREADY_SIGNALED  | [GLenum](#GLenum) | Yes|
| TIMEOUT_EXPIRED  | [GLenum](#GLenum) | Yes|
| CONDITION_SATISFIED  | [GLenum](#GLenum) | Yes|
| WAIT_FAILED  | [GLenum](#GLenum) | Yes|
| SYNC_FLUSH_COMMANDS_BIT  | [GLenum](#GLenum) | Yes|
| VERTEX_ATTRIB_ARRAY_DIVISOR  | [GLenum](#GLenum) | Yes|
| ANY_SAMPLES_PASSED  | [GLenum](#GLenum) | Yes|
| ANY_SAMPLES_PASSED_CONSERVATIVE  | [GLenum](#GLenum) | Yes|
| SAMPLER_BINDING  | [GLenum](#GLenum) | Yes|
| RGB10_A2UI  | [GLenum](#GLenum) | Yes|
| INT_2_10_10_10_REV  | [GLenum](#GLenum) | Yes|
| TRANSFORM_FEEDBACK  | [GLenum](#GLenum) | Yes|
| TRANSFORM_FEEDBACK_PAUSED  | [GLenum](#GLenum) | Yes|
| TRANSFORM_FEEDBACK_ACTIVE  | [GLenum](#GLenum) | Yes|
| TRANSFORM_FEEDBACK_BINDING  | [GLenum](#GLenum) | Yes|
| TEXTURE_IMMUTABLE_FORMAT  | [GLenum](#GLenum) | Yes|
| MAX_ELEMENT_INDEX  | [GLenum](#GLenum) | Yes|
| TEXTURE_IMMUTABLE_LEVELS  | [GLenum](#GLenum) | Yes|
| TIMEOUT_IGNORED | [GLenum](#GLenum) | Yes|
| MAX_CLIENT_WAIT_TIMEOUT_WEBGL  | [GLenum](#GLenum) | Yes|


### Methods

| Method| Return Value Type|
| -------- | ---------- |
| copyBufferSubData(readTarget:&nbsp; GLenum,&nbsp; writeTarget:&nbsp; GLenum,&nbsp; readOffset:&nbsp; GLintptr,&nbsp; writeOffset:&nbsp; GLintptr,&nbsp; size:&nbsp; GLsizeiptr) | void |
| getBufferSubData(target:&nbsp; GLenum,&nbsp; srcByteOffset:&nbsp; GLintptr,&nbsp; dstBuffer:&nbsp; ArrayBufferView,&nbsp; dstOffset?:&nbsp; GLuint,&nbsp; length?:&nbsp; GLuint) | void |
| blitFramebuffer(srcX0:&nbsp; GLint,&nbsp; srcY0:&nbsp; GLint,&nbsp; srcX1:&nbsp; GLint,&nbsp; srcY1:&nbsp; GLint,&nbsp; dstX0:&nbsp; GLint,&nbsp; dstY0:&nbsp; GLint,&nbsp; dstX1:&nbsp; GLint,&nbsp; dstY1:&nbsp; GLint,&nbsp; mask:&nbsp; GLbitfield,&nbsp; filter:&nbsp; GLenum) | void |
| framebufferTextureLayer(target:&nbsp; GLenum,&nbsp; attachment:&nbsp; GLenum,&nbsp; texture:&nbsp; WebGLTexture&nbsp;\|&nbsp;null,&nbsp; level:&nbsp; GLint,&nbsp; layer:&nbsp; GLint) | void |
| invalidateFramebuffer(target:&nbsp; GLenum,&nbsp; attachments:&nbsp; GLenum[]) | void |
| invalidateSubFramebuffer(target:&nbsp; GLenum,&nbsp; attachments:&nbsp; GLenum[],&nbsp; x:&nbsp; GLint,&nbsp; y:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei) | void |
| readBuffer(src:&nbsp; GLenum) | void |
| getInternalformatParameter(target:&nbsp; GLenum,&nbsp; internalformat:&nbsp; GLenum,&nbsp; pname:&nbsp; GLenum) | any |
| renderbufferStorageMultisample(target:&nbsp; GLenum,&nbsp; samples:&nbsp; GLsizei,&nbsp; internalformat:&nbsp; GLenum,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei) | void |
| texStorage2D(target:&nbsp; GLenum,&nbsp; levels:&nbsp; GLsizei,&nbsp; internalformat:&nbsp; GLenum,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei) | void |
| texStorage3D(target:&nbsp; GLenum,&nbsp; levels:&nbsp; GLsizei,&nbsp; internalformat:&nbsp; GLenum,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei) | void |
| texImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp;  GLenum,&nbsp; pboOffset:&nbsp; GLintptr) | void |
| texImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; source:&nbsp; TexImageSource) | void |
| texImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; srcData:&nbsp; ArrayBufferView&nbsp;\|&nbsp;null) | void |
| texImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; srcData:&nbsp; ArrayBufferView,&nbsp; srcOffset:&nbsp; GLuint) | void |
| texSubImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; zoffset:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; pboOffset:&nbsp; GLintptr) | void |
| texSubImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; zoffset:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; source:&nbsp; TexImageSource) | void |
| texSubImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; zoffset:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; srcData:&nbsp; ArrayBufferView&nbsp;\|&nbsp;null,&nbsp; srcOffset?:&nbsp; GLuint) | void |
| copyTexSubImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; zoffset:&nbsp; GLint,&nbsp; x:&nbsp; GLint,&nbsp; y:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei) | void |
| compressedTexImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLenum,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; imageSize:&nbsp; GLsizei,&nbsp; offset:&nbsp; GLintptr) | void |
| compressedTexImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLenum,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; srcData:&nbsp; ArrayBufferView,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLengthOverride?:&nbsp; GLuint) | void |
| compressedTexSubImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; zoffset:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; imageSize:&nbsp; GLsizei,&nbsp; offset:&nbsp; GLintptr) | void |
| compressedTexSubImage3D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; zoffset:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; depth:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; srcData:&nbsp; ArrayBufferView,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLengthOverride?:&nbsp; GLuint) | void |
| getFragDataLocation(program:&nbsp; WebGLProgram,&nbsp; name:&nbsp; string) | GLint |
| uniform1ui(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; v0:&nbsp; GLuint) | void |
| uniform2ui(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; v0:&nbsp; GLuint,&nbsp; v1:&nbsp; GLuint) | void |
| uniform3ui(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; v0:&nbsp; GLuint,&nbsp; v1:&nbsp; GLuint,&nbsp; v2:&nbsp; GLuint) | void |
| uniform4ui(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; v0:&nbsp; GLuint,&nbsp; v1:&nbsp; GLuint,&nbsp; v2:&nbsp; GLuint,&nbsp; v3:&nbsp; GLuint) | void |
| uniform1uiv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Uint32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniform2uiv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Uint32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniform3uiv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Uint32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniform4uiv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Uint32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniformMatrix3x2fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; transpose:&nbsp; GLboolean,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniformMatrix4x2fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; transpose:&nbsp; GLboolean,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniformMatrix2x3fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; transpose:&nbsp; GLboolean,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniformMatrix4x3fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; transpose:&nbsp; GLboolean,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniformMatrix2x4fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; transpose:&nbsp; GLboolean,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniformMatrix3x4fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; transpose:&nbsp; GLboolean,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| vertexAttribI4i(index:&nbsp; GLuint,&nbsp; x:&nbsp; GLint,&nbsp; y:&nbsp; GLint,&nbsp; z:&nbsp; GLint,&nbsp; w:&nbsp; GLint) | void |
| vertexAttribI4iv(index:&nbsp; GLuint,&nbsp; values:&nbsp; Int32List) | void |
| vertexAttribI4ui(index:&nbsp; GLuint,&nbsp; x:&nbsp; GLuint,&nbsp; y:&nbsp; GLuint,&nbsp; z:&nbsp; GLuint,&nbsp; w:&nbsp; GLuint) | void |
| vertexAttribI4uiv(index:&nbsp; GLuint,&nbsp; values:&nbsp; Uint32List) | void |
| vertexAttribIPointer(index:&nbsp; GLuint,&nbsp; size:&nbsp; GLint,&nbsp; type:&nbsp; GLenum,&nbsp; stride:&nbsp; GLsizei,&nbsp; offset:&nbsp; GLintptr) | void |
| vertexAttribDivisor(index:&nbsp; GLuint,&nbsp; divisor:&nbsp; GLuint) | void |
| drawArraysInstanced(mode:&nbsp; GLenum,&nbsp; first:&nbsp; GLint,&nbsp; count:&nbsp; GLsizei,&nbsp; instanceCount:&nbsp; GLsizei) | void |
| drawElementsInstanced(mode:&nbsp; GLenum,&nbsp; count:&nbsp; GLsizei,&nbsp; type:&nbsp; GLenum,&nbsp; offset:&nbsp; GLintptr,&nbsp; instanceCount:&nbsp; GLsizei) | void |
| drawRangeElements(mode:&nbsp; GLenum,&nbsp; start:&nbsp; GLuint,&nbsp; end:&nbsp; GLuint,&nbsp; count:&nbsp; GLsizei,&nbsp; type:&nbsp; GLenum,&nbsp; offset:&nbsp; GLintptr) | void |
| drawBuffers(buffers:&nbsp; GLenum[]) | void |
| clearBufferfv(buffer:&nbsp; GLenum,&nbsp; drawbuffer:&nbsp; GLint,&nbsp; values:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint) | void |
| clearBufferiv(buffer:&nbsp; GLenum,&nbsp; drawbuffer:&nbsp; GLint,&nbsp; values:&nbsp; Int32List,&nbsp; srcOffset?:&nbsp; GLuint) | void |
| clearBufferuiv(buffer:&nbsp; GLenum,&nbsp; drawbuffer:&nbsp; GLint,&nbsp; values:&nbsp; Uint32List,&nbsp; srcOffset?:&nbsp; GLuint) | void |
| clearBufferfi(buffer:&nbsp; GLenum,&nbsp; drawbuffer:&nbsp; GLint,&nbsp; depth:&nbsp; GLfloat,&nbsp; stencil:&nbsp; GLint) | void |
| createQuery() | WebGLQuery&nbsp;\|&nbsp;null |
| deleteQuery(query:&nbsp; WebGLQuery&nbsp;\|&nbsp;null) | void |
| isQuery(query:&nbsp; WebGLQuery&nbsp;\|&nbsp;null) | GLboolean |
| beginQuery(target:&nbsp; GLenum,&nbsp; query:&nbsp; WebGLQuery) | void |
| endQuery(target:&nbsp; GLenum) | void |
| getQuery(target:&nbsp; GLenum,&nbsp; pname:&nbsp; GLenum) | WebGLQuery&nbsp;\|&nbsp;null |
| getQueryParameter(query:&nbsp; WebGLQuery,&nbsp; pname:&nbsp; GLenum) | any |
| createSampler() | WebGLSampler&nbsp;\|&nbsp;null |
| deleteSampler(sampler:&nbsp; WebGLSampler&nbsp;\|&nbsp;null) | void |
| isSampler(sampler:&nbsp; WebGLSampler&nbsp;\|&nbsp;null) | GLboolean |
| bindSampler(unit:&nbsp; GLuint,&nbsp; sampler:&nbsp; WebGLSampler&nbsp;\|&nbsp;null) | void |
| samplerParameteri(sampler:&nbsp; WebGLSampler,&nbsp; pname:&nbsp; GLenum,&nbsp; param:&nbsp; GLint) | void |
| samplerParameterf(sampler:&nbsp; WebGLSampler,&nbsp; pname:&nbsp; GLenum,&nbsp; param:&nbsp; GLfloat) | void |
| getSamplerParameter(sampler:&nbsp; WebGLSampler,&nbsp; pname:&nbsp; GLenum) | any |
| fenceSync(condition:&nbsp; GLenum,&nbsp; flags:&nbsp; GLbitfield) | WebGLSync&nbsp;\|&nbsp;null |
| isSync(sync:&nbsp; WebGLSync&nbsp;\|&nbsp;null) | GLboolean |
| deleteSync(sync:&nbsp; WebGLSync&nbsp;\|&nbsp;null) | void |
| clientWaitSync(sync:&nbsp; WebGLSync,&nbsp; flags:&nbsp; GLbitfield,&nbsp; timeout:&nbsp; GLuint64) | GLenum |
| waitSync(sync:&nbsp; WebGLSync,&nbsp; flags:&nbsp; GLbitfield,&nbsp; timeout:&nbsp; GLint64) | void |
| getSyncParameter(sync:&nbsp; WebGLSync,&nbsp; pname:&nbsp; GLenum) | any |
| createTransformFeedback() | WebGLTransformFeedback&nbsp;\|&nbsp;null |
| deleteTransformFeedback(tf:&nbsp; WebGLTransformFeedback&nbsp;\|&nbsp;null) | void |
| isTransformFeedback(tf:&nbsp; WebGLTransformFeedback&nbsp;\|&nbsp;null) | GLboolean |
| bindTransformFeedback(target:&nbsp; GLenum,&nbsp; tf:&nbsp; WebGLTransformFeedback&nbsp;\|&nbsp;null) | void |
| beginTransformFeedback(primitiveMode:&nbsp; GLenum) | void |
| endTransformFeedback() | void |
| transformFeedbackVaryings(program:&nbsp; WebGLProgram,&nbsp; varyings:&nbsp; string[],&nbsp; bufferMode:&nbsp; GLenum) | void |
| getTransformFeedbackVarying(program:&nbsp; WebGLProgram,&nbsp; index:&nbsp; GLuint) | WebGLActiveInfo&nbsp;\|&nbsp;null |
| pauseTransformFeedback() | void |
| resumeTransformFeedback() | void |
| bindBufferBase(target:&nbsp; GLenum,&nbsp; index:&nbsp; GLuint,&nbsp; buffer:&nbsp; WebGLBuffer&nbsp;\|&nbsp;null) | void |
| bindBufferRange(target:&nbsp; GLenum,&nbsp; index:&nbsp; GLuint,&nbsp; buffer:&nbsp; WebGLBuffer&nbsp;\|&nbsp;null,&nbsp; offset:&nbsp; GLintptr,&nbsp; size:&nbsp; GLsizeiptr) | void |
| getIndexedParameter(target:&nbsp; GLenum,&nbsp; index:&nbsp; GLuint) | any |
| getUniformIndices(program:&nbsp; WebGLProgram,&nbsp; uniformNames:&nbsp; string[]) | GLuint[]&nbsp;\|&nbsp;null |
| getActiveUniforms(program:&nbsp; WebGLProgram,&nbsp; uniformIndices:&nbsp; GLuint[],&nbsp; pname:&nbsp; GLenum) | any |
| getUniformBlockIndex(program:&nbsp; WebGLProgram,&nbsp; uniformBlockName:&nbsp; string) | GLuint |
| getActiveUniformBlockParameter(program:&nbsp; WebGLProgram,&nbsp; uniformBlockIndex:&nbsp; GLuint,&nbsp; pname:&nbsp; GLenum) | any |
| getActiveUniformBlockName(program:&nbsp; WebGLProgram,&nbsp; uniformBlockIndex:&nbsp; GLuint) | string&nbsp;\|&nbsp;null |
| uniformBlockBinding(program:&nbsp; WebGLProgram,&nbsp; uniformBlockIndex:&nbsp; GLuint,&nbsp; uniformBlockBinding:&nbsp; GLuint) | void |
| createVertexArray() | WebGLVertexArrayObject&nbsp;\|&nbsp;null |
| deleteVertexArray(vertexArray:&nbsp; WebGLVertexArrayObject&nbsp;\|&nbsp;null) | void |
| isVertexArray(vertexArray:&nbsp; WebGLVertexArrayObject&nbsp;\|&nbsp;null) | GLboolean |
| bindVertexArray(array:&nbsp; WebGLVertexArrayObject&nbsp;\|&nbsp;null) | void |


## webgl.WebGL2RenderingContextOverloads

WebGL2RenderingContextOverloads

| Method| Return Value Type|
| -------- | ---------- |
| bufferData(target:&nbsp; GLenum,&nbsp; size:&nbsp; GLsizeiptr,&nbsp; usage:&nbsp; GLenum) | void |
| bufferData(target:&nbsp; GLenum,&nbsp; srcData:&nbsp; BufferSource&nbsp;\|&nbsp;null,&nbsp; usage:&nbsp; GLenum) | void |
| bufferSubData(target:&nbsp; GLenum,&nbsp; dstByteOffset:&nbsp; GLintptr,&nbsp; srcData:&nbsp; BufferSource) | void |
| bufferData(target:&nbsp; GLenum,&nbsp; srcData:&nbsp; ArrayBufferView,&nbsp; usage:&nbsp; GLenum,&nbsp; srcOffset:&nbsp; GLuint,&nbsp; length?:&nbsp; GLuint) | void |
| bufferSubData(target:&nbsp; GLenum,&nbsp; dstByteOffset:&nbsp; GLintptr,&nbsp; srcData:&nbsp; ArrayBufferView,&nbsp; srcOffset:&nbsp; GLuint,&nbsp; length?:&nbsp; GLuint) | void |
| texImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; pixels:&nbsp; ArrayBufferView&nbsp;\|&nbsp;null) | void |
| texImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLint,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; source:&nbsp; TexImageSource) | void |
| texSubImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; pixels:&nbsp; ArrayBufferView&nbsp;\|&nbsp;null) | void |
| texSubImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; source:&nbsp; TexImageSource) | void |
| texImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; pboOffset:&nbsp; GLintptr) | void |
| texImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; source:&nbsp; TexImageSource) | void |
| texImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; srcData:&nbsp; ArrayBufferView,&nbsp; srcOffset:&nbsp; GLuint) | void |
| texSubImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; pboOffset:&nbsp; GLintptr) | void |
| texSubImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; source:&nbsp; TexImageSource) | void |
| texSubImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; srcData:&nbsp; ArrayBufferView,&nbsp; srcOffset:&nbsp; GLuint) | void |
| compressedTexImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLenum,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; imageSize:&nbsp; GLsizei,&nbsp; offset:&nbsp; GLintptr) | void |
| compressedTexImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; internalformat:&nbsp; GLenum,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; border:&nbsp; GLint,&nbsp; srcData:&nbsp; ArrayBufferView,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLengthOverride?:&nbsp; GLuint) | void |
| compressedTexSubImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; imageSize:&nbsp; GLsizei,&nbsp; offset:&nbsp; GLintptr) | void |
| compressedTexSubImage2D(target:&nbsp; GLenum,&nbsp; level:&nbsp; GLint,&nbsp; xoffset:&nbsp; GLint,&nbsp; yoffset:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; srcData:&nbsp; ArrayBufferView,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLengthOverride?:&nbsp; GLuint) | void |
| uniform1fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniform2fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniform3fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniform4fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniform1iv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Int32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniform2iv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Int32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniform3iv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Int32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniform4iv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; data:&nbsp; Int32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniformMatrix2fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; transpose:&nbsp; GLboolean,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniformMatrix3fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; transpose:&nbsp; GLboolean,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| uniformMatrix4fv(location:&nbsp; WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp; transpose:&nbsp; GLboolean,&nbsp; data:&nbsp; Float32List,&nbsp; srcOffset?:&nbsp; GLuint,&nbsp; srcLength?:&nbsp; GLuint) | void |
| readPixels(x:&nbsp; GLint,&nbsp; y:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; dstData:&nbsp; ArrayBufferView&nbsp;\|&nbsp;null) | void |
| readPixels(x:&nbsp; GLint,&nbsp; y:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; offset:&nbsp; GLintptr) | void |
| readPixels(x:&nbsp; GLint,&nbsp; y:&nbsp; GLint,&nbsp; width:&nbsp; GLsizei,&nbsp; height:&nbsp; GLsizei,&nbsp; format:&nbsp; GLenum,&nbsp; type:&nbsp; GLenum,&nbsp; dstData:&nbsp; ArrayBufferView,&nbsp; dstOffset:&nbsp; GLuint) | void |


## webgl.WebGLQuery

WebGLQuery


## webgl.WebGLSampler

WebGLSampler


## webgl.WebGLSync

WebGLSync


## webgl.WebGLTransformFeedback

WebGLTransformFeedback


## webgl.WebGLVertexArrayObject

WebGLVertexArrayObject
