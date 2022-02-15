# WebGL

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


WebGL标准图形API，对应OpenGL ES 2.0特性集。更多信息请参考[WebgGL™标准](https://www.khronos.org/registry/webgl/specs/latest/1.0/)。




## 导入模块

```
import webgl from 'ohos.webglnapi'
```


## 系统能力

SystemCapability.Graphic.Graphic2D.WebGL


## 调用方式

```
// 获取canvas组件实例
const el = this.$refs.canvas
// 从canvas组件实例获取WebGL上下文
const gl = el.getContext('webgl');
// 调用WebGL API
gl.clearColor(0.0, 0.0, 0.0, 1.0);
gl.flush();
```


## GLenum

| 名称 | 类型 |
| -------- | -------- |
| GLenum | number |


## GLboolean

| 名称 | 类型 |
| -------- | -------- |
| GLboolean | boolean |


## GLbitfield

| 名称 | 类型 |
| -------- | -------- |
| GLbitfield | number |


## GLbyte

| 名称 | 类型 |
| -------- | -------- |
| GLbyte | number |


## GLshort

| 名称 | 类型 |
| -------- | -------- |
| GLshort | number |


## GLint

| 名称 | 类型 |
| -------- | -------- |
| GLint | number |


## GLsizei

| 名称 | 类型 |
| -------- | -------- |
| GLsizei | number |


## GLintptr

| 名称 | 类型 |
| -------- | -------- |
| GLintptr | number |


## GLsizeiptr

| 名称 | 类型 |
| -------- | -------- |
| GLsizeiptr | number |


## GLubyte

| 名称 | 类型 |
| -------- | -------- |
| GLubyte | number |


## GLushort

| 名称 | 类型 |
| -------- | -------- |
| GLushort | number |


## GLuint

| 名称 | 类型 |
| -------- | -------- |
| GLuint | number |


## GLfloat

| 名称 | 类型 |
| -------- | -------- |
| GLfloat | number |


## GLclampf

| 名称 | 类型 |
| -------- | -------- |
| GLclampf | number |


## TexImageSource

| 名称 | 类型 |
| -------- | -------- |
| TexImageSource | ImageData |


## Float32List

| 名称 | 类型 |
| -------- | -------- |
| Float32List | array |


## Int32List

| 名称 | 类型 |
| -------- | -------- |
| Int32List | array |


## WebGLPowerPreference

| 名称 | 类型 |
| -------- | -------- |
| WebGLPowerPreference | string |


## webgl.WebGLContextAttributes

WebGLContextAttributes


| 名称 | 参数类型 | 必填 |
| -------- | -------- | -------- |
| alpha  | boolean | 否 |
| depth | boolean | 否 |
| stencil | boolean | 否 |
| antialias  | boolean | 否 |
| premultipliedAlpha | boolean | 否 |
| preserveDrawingBuffer | boolean | 否 |
| powerPreference  | WebGLPowerPreference | 否 |
| failIfMajorPerformanceCaveat | boolean | 否 |
| desynchronized | boolean | 否 |


## webgl.WebGLBuffer

WebGLBuffer


## webgl.WebGLFrameBuffer

WebGLFrameBuffer


## webgl.WebGLProgram

WebGLProgram


## webgl.WebGLRenderbuffer

WebGLRenderbuffer


## webgl.WebGLShader

WebGLShader


## webgl.WebGLTexture

WebGLTexture


## webgl.WebGLUniformLocation

WebGLUniformLocation


## webgl.WebGLActiveInfo

WebGLActiveInfo

| 名称 | 参数类型 | 必填 |
| -------- | -------- | -------- |
| size | [GLint](#glint) | 是 |
| type | [GLenum](#glenum) | 是 |
| name | string | 是 |


## webgl.WebGLShaderPrecisionFormat

WebGLShaderPrecisionFormat

| 名称 | 参数类型 | 必填 |
| -------- | -------- | -------- |
| rangeMin | [GLint](#glint) | 是 |
| rangeMax | [GLint](#glint) | 是 |
| precision | [GLint](#glint) | 是 |


## webgl.WebGLRenderingContextBase

WebGLRenderingContextBase


### 属性

| 名称 | 参数类型 | 必填 |
| -------- | -------- | -------- |
| DEPTH_BUFFER_BIT | [GLenum](#glenum) | 是 |
| STENCIL_BUFFER_BIT | [GLenum](#glenum) | 是 |
| COLOR_BUFFER_BIT | [GLenum](#glenum) | 是 |
| POINTS | [GLenum](#glenum) | 是 |
| LINES | [GLenum](#glenum) | 是 |
| LINE_LOOP | [GLenum](#glenum) | 是 |
| LINE_STRIP | [GLenum](#glenum) | 是 |
| TRIANGLES | [GLenum](#glenum) | 是 |
| TRIANGLE_STRIP | [GLenum](#glenum) | 是 |
| TRIANGLE_FAN | [GLenum](#glenum) | 是 |
| ZERO | [GLenum](#glenum) | 是 |
| ONE | [GLenum](#glenum) | 是 |
| SRC_COLOR | [GLenum](#glenum) | 是 |
| ONE_MINUS_SRC_COLOR | [GLenum](#glenum) | 是 |
| SRC_ALPHA | [GLenum](#glenum) | 是 |
| ONE_MINUS_SRC_ALPHA | [GLenum](#glenum) | 是 |
| DST_ALPHA | [GLenum](#glenum) | 是 |
| ONE_MINUS_DST_ALPHA | [GLenum](#glenum) | 是 |
| DST_COLOR | [GLenum](#glenum) | 是 |
| ONE_MINUS_DST_COLOR | [GLenum](#glenum) | 是 |
| SRC_ALPHA_SATURATE | [GLenum](#glenum) | 是 |
| FUNC_ADD | [GLenum](#glenum) | 是 |
| BLEND_EQUATION | [GLenum](#glenum) | 是 |
| BLEND_EQUATION_RGB | [GLenum](#glenum) | 是 |
| BLEND_EQUATION_ALPHA | [GLenum](#glenum) | 是 |
| FUNC_SUBTRACT | [GLenum](#glenum) | 是 |
| FUNC_REVERSE_SUBTRACT | [GLenum](#glenum) | 是 |
| BLEND_DST_RGB | [GLenum](#glenum) | 是 |
| BLEND_SRC_RGB | [GLenum](#glenum) | 是 |
| BLEND_DST_ALPHA | [GLenum](#glenum) | 是 |
| BLEND_SRC_ALPHA | [GLenum](#glenum) | 是 |
| CONSTANT_COLOR | [GLenum](#glenum) | 是 |
| ONE_MINUS_CONSTANT_COLOR | [GLenum](#glenum) | 是 |
| CONSTANT_ALPHA | [GLenum](#glenum) | 是 |
| ONE_MINUS_CONSTANT_ALPHA | [GLenum](#glenum) | 是 |
| BLEND_COLOR | [GLenum](#glenum) | 是 |
| ARRAY_BUFFER | [GLenum](#glenum) | 是 |
| ELEMENT_ARRAY_BUFFER | [GLenum](#glenum) | 是 |
| ARRAY_BUFFER_BINDING | [GLenum](#glenum) | 是 |
| ELEMENT_ARRAY_BUFFER_BINDING | [GLenum](#glenum) | 是 |
| STREAM_DRAW | [GLenum](#glenum) | 是 |
| STATIC_DRAW | [GLenum](#glenum) | 是 |
| DYNAMIC_DRAW | [GLenum](#glenum) | 是 |
| BUFFER_SIZE | [GLenum](#glenum) | 是 |
| BUFFER_USAGE | [GLenum](#glenum) | 是 |
| CURRENT_VERTEX_ATTRIB | [GLenum](#glenum) | 是 |
| FRONT | [GLenum](#glenum) | 是 |
| BACK | [GLenum](#glenum) | 是 |
| FRONT_AND_BACK | [GLenum](#glenum) | 是 |
| CULL_FACE | [GLenum](#glenum) | 是 |
| BLEND | [GLenum](#glenum) | 是 |
| DITHER | [GLenum](#glenum) | 是 |
| STENCIL_TEST | [GLenum](#glenum) | 是 |
| DEPTH_TEST | [GLenum](#glenum) | 是 |
| SCISSOR_TEST | [GLenum](#glenum) | 是 |
| POLYGON_OFFSET_FILL | [GLenum](#glenum) | 是 |
| SAMPLE_ALPHA_TO_COVERAGE | [GLenum](#glenum) | 是 |
| SAMPLE_COVERAGE | [GLenum](#glenum) | 是 |
| NO_ERROR | [GLenum](#glenum) | 是 |
| INVALID_ENUM | [GLenum](#glenum) | 是 |
| INVALID_VALUE | [GLenum](#glenum) | 是 |
| INVALID_OPERATION | [GLenum](#glenum) | 是 |
| OUT_OF_MEMORY | [GLenum](#glenum) | 是 |
| CW | [GLenum](#glenum) | 是 |
| CCW | [GLenum](#glenum) | 是 |
| ALIASED_POINT_SIZE_RANGE | [GLenum](#glenum) | 是 |
| ALIASED_LINE_WIDTH_RANGE | [GLenum](#glenum) | 是 |
| CULL_FACE_MODE | [GLenum](#glenum) | 是 |
| FRONT_FACE | [GLenum](#glenum) | 是 |
| DEPTH_RANGE | [GLenum](#glenum) | 是 |
| DEPTH_WRITEMASK | [GLenum](#glenum) | 是 |
| DEPTH_CLEAR_VALUE | [GLenum](#glenum) | 是 |
| DEPTH_FUNC | [GLenum](#glenum) | 是 |
| STENCIL_CLEAR_VALUE | [GLenum](#glenum) | 是 |
| STENCIL_FUNC | [GLenum](#glenum) | 是 |
| STENCIL_FAIL | [GLenum](#glenum) | 是 |
| STENCIL_PASS_DEPTH_FAIL | [GLenum](#glenum) | 是 |
| STENCIL_PASS_DEPTH_PASS | [GLenum](#glenum) | 是 |
| STENCIL_REF | [GLenum](#glenum) | 是 |
| STENCIL_VALUE_MASK | [GLenum](#glenum) | 是 |
| STENCIL_WRITEMASK | [GLenum](#glenum) | 是 |
| STENCIL_BACK_FUNC | [GLenum](#glenum) | 是 |
| STENCIL_BACK_FAIL | [GLenum](#glenum) | 是 |
| STENCIL_BACK_PASS_DEPTH_FAIL | [GLenum](#glenum) | 是 |
| STENCIL_BACK_PASS_DEPTH_PASS | [GLenum](#glenum) | 是 |
| STENCIL_BACK_REF | [GLenum](#glenum) | 是 |
| STENCIL_BACK_VALUE_MASK | [GLenum](#glenum) | 是 |
| STENCIL_BACK_WRITEMASK | [GLenum](#glenum) | 是 |
| VIEWPORT | [GLenum](#glenum) | 是 |
| SCISSOR_BOX | [GLenum](#glenum) | 是 |
| COLOR_CLEAR_VALUE | [GLenum](#glenum) | 是 |
| COLOR_WRITEMASK | [GLenum](#glenum) | 是 |
| UNPACK_ALIGNMENT | [GLenum](#glenum) | 是 |
| PACK_ALIGNMENT | [GLenum](#glenum) | 是 |
| MAX_TEXTURE_SIZE | [GLenum](#glenum) | 是 |
| MAX_VIEWPORT_DIMS | [GLenum](#glenum) | 是 |
| SUBPIXEL_BITS | [GLenum](#glenum) | 是 |
| RED_BITS | [GLenum](#glenum) | 是 |
| GREEN_BITS | [GLenum](#glenum) | 是 |
| BLUE_BITS | [GLenum](#glenum) | 是 |
| ALPHA_BITS | [GLenum](#glenum) | 是 |
| DEPTH_BITS | [GLenum](#glenum) | 是 |
| STENCIL_BITS | [GLenum](#glenum) | 是 |
| POLYGON_OFFSET_UNITS | [GLenum](#glenum) | 是 |
| POLYGON_OFFSET_FACTOR | [GLenum](#glenum) | 是 |
| TEXTURE_BINDING_2D | [GLenum](#glenum) | 是 |
| SAMPLE_BUFFERS | [GLenum](#glenum) | 是 |
| SAMPLES | [GLenum](#glenum) | 是 |
| SAMPLE_COVERAGE_VALUE | [GLenum](#glenum) | 是 |
| SAMPLE_COVERAGE_INVERT | [GLenum](#glenum) | 是 |
| COMPRESSED_TEXTURE_FORMATS | [GLenum](#glenum) | 是 |
| DONT_CARE | [GLenum](#glenum) | 是 |
| FASTEST | [GLenum](#glenum) | 是 |
| NICEST | [GLenum](#glenum) | 是 |
| GENERATE_MIPMAP_HINT | [GLenum](#glenum) | 是 |
| BYTE | [GLenum](#glenum) | 是 |
| UNSIGNED_BYTE | [GLenum](#glenum) | 是 |
| SHORT | [GLenum](#glenum) | 是 |
| UNSIGNED_SHORT | [GLenum](#glenum) | 是 |
| INT | [GLenum](#glenum) | 是 |
| UNSIGNED_INT | [GLenum](#glenum) | 是 |
| FLOAT | [GLenum](#glenum) | 是 |
| DEPTH_COMPONENT | [GLenum](#glenum) | 是 |
| ALPHA | [GLenum](#glenum) | 是 |
| RGB | [GLenum](#glenum) | 是 |
| RGBA | [GLenum](#glenum) | 是 |
| LUMINANCE | [GLenum](#glenum) | 是 |
| LUMINANCE_ALPHA | [GLenum](#glenum) | 是 |
| UNSIGNED_SHORT_4_4_4_4 | [GLenum](#glenum) | 是 |
| UNSIGNED_SHORT_5_5_5_1 | [GLenum](#glenum) | 是 |
| UNSIGNED_SHORT_5_6_5 | [GLenum](#glenum) | 是 |
| FRAGMENT_SHADER | [GLenum](#glenum) | 是 |
| VERTEX_SHADER | [GLenum](#glenum) | 是 |
| MAX_VERTEX_ATTRIBS | [GLenum](#glenum) | 是 |
| MAX_VERTEX_UNIFORM_VECTORS | [GLenum](#glenum) | 是 |
| MAX_VARYING_VECTORS | [GLenum](#glenum) | 是 |
| MAX_COMBINED_TEXTURE_IMAGE_UNITS | [GLenum](#glenum) | 是 |
| MAX_VERTEX_TEXTURE_IMAGE_UNITS | [GLenum](#glenum) | 是 |
| MAX_TEXTURE_IMAGE_UNITS | [GLenum](#glenum) | 是 |
| MAX_FRAGMENT_UNIFORM_VECTORS | [GLenum](#glenum) | 是 |
| SHADER_TYPE | [GLenum](#glenum) | 是 |
| DELETE_STATUS | [GLenum](#glenum) | 是 |
| LINK_STATUS | [GLenum](#glenum) | 是 |
| VALIDATE_STATUS | [GLenum](#glenum) | 是 |
| ATTACHED_SHADERS | [GLenum](#glenum) | 是 |
| ACTIVE_UNIFORMS | [GLenum](#glenum) | 是 |
| ACTIVE_ATTRIBUTES | [GLenum](#glenum) | 是 |
| SHADING_LANGUAGE_VERSION | [GLenum](#glenum) | 是 |
| CURRENT_PROGRAM | [GLenum](#glenum) | 是 |
| NEVER | [GLenum](#glenum) | 是 |
| LESS | [GLenum](#glenum) | 是 |
| EQUAL | [GLenum](#glenum) | 是 |
| LEQUAL | [GLenum](#glenum) | 是 |
| GREATER | [GLenum](#glenum) | 是 |
| NOTEQUAL | [GLenum](#glenum) | 是 |
| GEQUAL | [GLenum](#glenum) | 是 |
| ALWAYS | [GLenum](#glenum) | 是 |
| KEEP | [GLenum](#glenum) | 是 |
| REPLACE | [GLenum](#glenum) | 是 |
| INCR | [GLenum](#glenum) | 是 |
| DECR | [GLenum](#glenum) | 是 |
| INVERT | [GLenum](#glenum) | 是 |
| INCR_WRAP | [GLenum](#glenum) | 是 |
| DECR_WRAP | [GLenum](#glenum) | 是 |
| VENDOR | [GLenum](#glenum) | 是 |
| RENDERER | [GLenum](#glenum) | 是 |
| VERSION | [GLenum](#glenum) | 是 |
| NEAREST | [GLenum](#glenum) | 是 |
| LINEAR | [GLenum](#glenum) | 是 |
| NEAREST_MIPMAP_NEAREST | [GLenum](#glenum) | 是 |
| LINEAR_MIPMAP_NEAREST | [GLenum](#glenum) | 是 |
| NEAREST_MIPMAP_LINEAR | [GLenum](#glenum) | 是 |
| LINEAR_MIPMAP_LINEAR | [GLenum](#glenum) | 是 |
| TEXTURE_MAG_FILTER | [GLenum](#glenum) | 是 |
| TEXTURE_MIN_FILTER | [GLenum](#glenum) | 是 |
| TEXTURE_WRAP_S | [GLenum](#glenum) | 是 |
| TEXTURE_WRAP_T | [GLenum](#glenum) | 是 |
| TEXTURE_2D | [GLenum](#glenum) | 是 |
| TEXTURE | [GLenum](#glenum) | 是 |
| TEXTURE_CUBE_MAP | [GLenum](#glenum) | 是 |
| TEXTURE_BINDING_CUBE_MAP | [GLenum](#glenum) | 是 |
| TEXTURE_CUBE_MAP_POSITIVE_X | [GLenum](#glenum) | 是 |
| TEXTURE_CUBE_MAP_NEGATIVE_X | [GLenum](#glenum) | 是 |
| TEXTURE_CUBE_MAP_POSITIVE_Y | [GLenum](#glenum) | 是 |
| TEXTURE_CUBE_MAP_NEGATIVE_Y | [GLenum](#glenum) | 是 |
| TEXTURE_CUBE_MAP_POSITIVE_Z | [GLenum](#glenum) | 是 |
| TEXTURE_CUBE_MAP_NEGATIVE_Z | [GLenum](#glenum) | 是 |
| TEXTURE0 | [GLenum](#glenum) | 是 |
| TEXTURE1 | [GLenum](#glenum) | 是 |
| TEXTURE2 | [GLenum](#glenum) | 是 |
| TEXTURE3 | [GLenum](#glenum) | 是 |
| TEXTURE4 | [GLenum](#glenum) | 是 |
| TEXTURE5 | [GLenum](#glenum) | 是 |
| TEXTURE6 | [GLenum](#glenum) | 是 |
| TEXTURE7 | [GLenum](#glenum) | 是 |
| TEXTURE8 | [GLenum](#glenum) | 是 |
| TEXTURE9 | [GLenum](#glenum) | 是 |
| TEXTURE10 | [GLenum](#glenum) | 是 |
| TEXTURE11 | [GLenum](#glenum) | 是 |
| TEXTURE12 | [GLenum](#glenum) | 是 |
| TEXTURE13 | [GLenum](#glenum) | 是 |
| TEXTURE14 | [GLenum](#glenum) | 是 |
| TEXTURE15 | [GLenum](#glenum) | 是 |
| TEXTURE16 | [GLenum](#glenum) | 是 |
| TEXTURE17 | [GLenum](#glenum) | 是 |
| TEXTURE18 | [GLenum](#glenum) | 是 |
| TEXTURE19 | [GLenum](#glenum) | 是 |
| TEXTURE20 | [GLenum](#glenum) | 是 |
| TEXTURE21 | [GLenum](#glenum) | 是 |
| TEXTURE22 | [GLenum](#glenum) | 是 |
| TEXTURE23 | [GLenum](#glenum) | 是 |
| TEXTURE24 | [GLenum](#glenum) | 是 |
| TEXTURE25 | [GLenum](#glenum) | 是 |
| TEXTURE26 | [GLenum](#glenum) | 是 |
| TEXTURE27 | [GLenum](#glenum) | 是 |
| TEXTURE28 | [GLenum](#glenum) | 是 |
| TEXTURE29 | [GLenum](#glenum) | 是 |
| TEXTURE30 | [GLenum](#glenum) | 是 |
| TEXTURE31 | [GLenum](#glenum) | 是 |
| ACTIVE_TEXTURE | [GLenum](#glenum) | 是 |
| REPEAT | [GLenum](#glenum) | 是 |
| CLAMP_TO_EDGE | [GLenum](#glenum) | 是 |
| MIRRORED_REPEAT | [GLenum](#glenum) | 是 |
| FLOAT_VEC2 | [GLenum](#glenum) | 是 |
| FLOAT_VEC3 | [GLenum](#glenum) | 是 |
| FLOAT_VEC4 | [GLenum](#glenum) | 是 |
| INT_VEC2 | [GLenum](#glenum) | 是 |
| INT_VEC3 | [GLenum](#glenum) | 是 |
| INT_VEC4 | [GLenum](#glenum) | 是 |
| BOOL | [GLenum](#glenum) | 是 |
| BOOL_VEC2 | [GLenum](#glenum) | 是 |
| BOOL_VEC3 | [GLenum](#glenum) | 是 |
| BOOL_VEC4 | [GLenum](#glenum) | 是 |
| FLOAT_MAT2 | [GLenum](#glenum) | 是 |
| FLOAT_MAT3 | [GLenum](#glenum) | 是 |
| FLOAT_MAT4 | [GLenum](#glenum) | 是 |
| SAMPLER_2D | [GLenum](#glenum) | 是 |
| SAMPLER_CUBE | [GLenum](#glenum) | 是 |
| VERTEX_ATTRIB_ARRAY_ENABLED | [GLenum](#glenum) | 是 |
| VERTEX_ATTRIB_ARRAY_SIZE | [GLenum](#glenum) | 是 |
| VERTEX_ATTRIB_ARRAY_STRIDE | [GLenum](#glenum) | 是 |
| VERTEX_ATTRIB_ARRAY_TYPE | [GLenum](#glenum) | 是 |
| VERTEX_ATTRIB_ARRAY_NORMALIZED | [GLenum](#glenum) | 是 |
| VERTEX_ATTRIB_ARRAY_POINTER | [GLenum](#glenum) | 是 |
| VERTEX_ATTRIB_ARRAY_BUFFER_BINDING | [GLenum](#glenum) | 是 |
| IMPLEMENTATION_COLOR_READ_TYPE | [GLenum](#glenum) | 是 |
| IMPLEMENTATION_COLOR_READ_FORMAT | [GLenum](#glenum) | 是 |
| COMPILE_STATUS | [GLenum](#glenum) | 是 |
| LOW_FLOAT | [GLenum](#glenum) | 是 |
| MEDIUM_FLOAT | [GLenum](#glenum) | 是 |
| HIGH_FLOAT | [GLenum](#glenum) | 是 |
| LOW_INT | [GLenum](#glenum) | 是 |
| MEDIUM_INT | [GLenum](#glenum) | 是 |
| HIGH_INT | [GLenum](#glenum) | 是 |
| FRAMEBUFFER | [GLenum](#glenum) | 是 |
| RENDERBUFFER | [GLenum](#glenum) | 是 |
| RGBA4 | [GLenum](#glenum) | 是 |
| RGB5_A1 | [GLenum](#glenum) | 是 |
| RGB565 | [GLenum](#glenum) | 是 |
| DEPTH_COMPONENT16 | [GLenum](#glenum) | 是 |
| STENCIL_INDEX8 | [GLenum](#glenum) | 是 |
| DEPTH_STENCIL | [GLenum](#glenum) | 是 |
| RENDERBUFFER_WIDTH | [GLenum](#glenum) | 是 |
| RENDERBUFFER_HEIGHT | [GLenum](#glenum) | 是 |
| RENDERBUFFER_INTERNAL_FORMAT | [GLenum](#glenum) | 是 |
| RENDERBUFFER_RED_SIZE | [GLenum](#glenum) | 是 |
| RENDERBUFFER_GREEN_SIZE | [GLenum](#glenum) | 是 |
| RENDERBUFFER_BLUE_SIZE | [GLenum](#glenum) | 是 |
| RENDERBUFFER_ALPHA_SIZE | [GLenum](#glenum) | 是 |
| RENDERBUFFER_DEPTH_SIZE | [GLenum](#glenum) | 是 |
| RENDERBUFFER_STENCIL_SIZE | [GLenum](#glenum) | 是 |
| FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE | [GLenum](#glenum) | 是 |
| FRAMEBUFFER_ATTACHMENT_OBJECT_NAME | [GLenum](#glenum) | 是 |
| FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL | [GLenum](#glenum) | 是 |
| FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE | [GLenum](#glenum) | 是 |
| COLOR_ATTACHMENT0 | [GLenum](#glenum) | 是 |
| DEPTH_ATTACHMENT | [GLenum](#glenum) | 是 |
| STENCIL_ATTACHMENT | [GLenum](#glenum) | 是 |
| DEPTH_STENCIL_ATTACHMENT | [GLenum](#glenum) | 是 |
| NONE | [GLenum](#glenum) | 是 |
| FRAMEBUFFER_COMPLETE | [GLenum](#glenum) | 是 |
| FRAMEBUFFER_INCOMPLETE_ATTACHMENT | [GLenum](#glenum) | 是 |
| FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT | [GLenum](#glenum) | 是 |
| FRAMEBUFFER_INCOMPLETE_DIMENSIONS | [GLenum](#glenum) | 是 |
| FRAMEBUFFER_UNSUPPORTED | [GLenum](#glenum) | 是 |
| FRAMEBUFFER_BINDING | [GLenum](#glenum) | 是 |
| RENDERBUFFER_BINDING | [GLenum](#glenum) | 是 |
| MAX_RENDERBUFFER_SIZE | [GLenum](#glenum) | 是 |
| INVALID_FRAMEBUFFER_OPERATION | [GLenum](#glenum) | 是 |
| UNPACK_FLIP_Y_WEBGL | [GLenum](#glenum) | 是 |
| UNPACK_PREMULTIPLY_ALPHA_WEBGL | [GLenum](#glenum) | 是 |
| CONTEXT_LOST_WEBGL | [GLenum](#glenum) | 是 |
| UNPACK_COLORSPACE_CONVERSION_WEBGL | [GLenum](#glenum) | 是 |
| BROWSER_DEFAULT_WEBGL | [GLenum](#glenum) | 是 |
| canvas | HTMLCanvasElement&nbsp;\|&nbsp;OffscreenCanvas | 是 |
| drawingBufferWidth | [GLsizei](#glsizei) | 是 |
| drawingBufferHeight | [GLsizei](#glsizei) | 是 |


### 方法

| 方法 | 返回值类型 |
| -------- | -------- |
| getContextAttributes() | WebGLContextAttributes&nbsp;\|&nbsp;null |
| isContextLost() | boolean |
| getSupportedExtensions() | string[]&nbsp;\|&nbsp;null |
| getExtension(name:&nbsp;string) | any |
| activeTexture(texture:&nbsp;GLenum) | void |
| attachShader(program:&nbsp;WebGLProgram,&nbsp;shader:&nbsp;WebGLShader) | void |
| bindAttribLocation(program:&nbsp;WebGLProgram,&nbsp;index:&nbsp;GLuint,&nbsp;name:&nbsp;string) | void |
| bindBuffer(target:&nbsp;GLenum,&nbsp;buffer:&nbsp;WebGLBuffer&nbsp;\|&nbsp;null) | void |
| bindFramebuffer(target:&nbsp;GLenum,&nbsp;framebuffer:&nbsp;WebGLFramebuffer&nbsp;\|&nbsp;null) | void |
| bindRenderbuffer(target:&nbsp;GLenum,&nbsp;renderbuffer:&nbsp;WebGLRenderbuffer&nbsp;\|&nbsp;null) | void |
| bindTexture(target:&nbsp;GLenum,&nbsp;texture:&nbsp;WebGLTexture&nbsp;\|&nbsp;null) | void |
| blendColor(red:&nbsp;GLclampf,&nbsp;green:&nbsp;GLclampf,&nbsp;blue:&nbsp;GLclampf,&nbsp;alpha:&nbsp;GLclampf) | void |
| blendEquation(mode:&nbsp;GLenum) | void |
| blendEquationSeparate(modeRGB:&nbsp;GLenum,&nbsp;modeAlpha:&nbsp;GLenum) | void |
| blendFunc(sfactor:&nbsp;GLenum,&nbsp;dfactor:&nbsp;GLenum) | void |
| blendFuncSeparate(srcRGB:&nbsp;GLenum,&nbsp;dstRGB:&nbsp;GLenum,&nbsp;srcAlpha:&nbsp;GLenum,&nbsp;dstAlpha:&nbsp;GLenum) | void |
| checkFramebufferStatus(target:&nbsp;GLenum) | GLenum |
| clear(mask:&nbsp;GLbitfield) | void |
| clearColor(red:&nbsp;GLclampf,&nbsp;green:&nbsp;GLclampf,&nbsp;blue:&nbsp;GLclampf,&nbsp;alpha:&nbsp;GLclampf) | void |
| clearDepth(depth:&nbsp;GLclampf) | void |
| clearStencil(s:&nbsp;GLint) | void |
| colorMask(red:&nbsp;GLboolean,&nbsp;green:&nbsp;GLboolean,&nbsp;blue:&nbsp;GLboolean,&nbsp;alpha:&nbsp;GLboolean) | void |
| compileShader(shader:&nbsp;WebGLShader) | void |
| copyTexImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLenum,&nbsp;x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint) | void |
| copyTexSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei) | void |
| createBuffer() | WebGLBuffer&nbsp;\|&nbsp;null |
| createFramebuffer() | WebGLFramebuffer&nbsp;\|&nbsp;null |
| createProgram() | WebGLProgram&nbsp;\|&nbsp;null |
| createRenderbuffer() | WebGLRenderbuffer&nbsp;\|&nbsp;null |
| createShader(type:&nbsp;GLenum) | WebGLShader&nbsp;\|&nbsp;null |
| createTexture() | WebGLTexture&nbsp;\|&nbsp;nullvoid |
| cullFace(mode:&nbsp;GLenum) | void |
| deleteBuffer(buffer:&nbsp;WebGLBuffer&nbsp;\|&nbsp;null) | void |
| deleteFramebuffer(framebuffer:&nbsp;WebGLFramebuffer&nbsp;\|&nbsp;null) | void |
| deleteProgram(program:&nbsp;WebGLProgram&nbsp;\|&nbsp;null) | void |
| deleteRenderbuffer(renderbuffer:&nbsp;WebGLRenderbuffer&nbsp;\|&nbsp;null) | void |
| deleteShader(shader:&nbsp;WebGLShader&nbsp;\|&nbsp;null) | void |
| deleteTexture(texture:&nbsp;WebGLTexture&nbsp;\|&nbsp;null) | void |
| depthFunc(func:&nbsp;GLenum) | void |
| depthMask(flag:&nbsp;GLboolean) | void |
| depthRange(zNear:&nbsp;GLclampf,&nbsp;zFar:&nbsp;GLclampf) | void |
| detachShader(program:&nbsp;WebGLProgram,&nbsp;shader:&nbsp;WebGLShader) | void |
| disable(cap:&nbsp;GLenum) | void |
| disableVertexAttribArray(index:&nbsp;GLuint) | void |
| drawArrays(mode:&nbsp;GLenum,&nbsp;first:&nbsp;GLint,&nbsp;count:&nbsp;GLsizei) | void |
| drawElements(mode:&nbsp;GLenum,&nbsp;count:&nbsp;GLsizei,&nbsp;type:&nbsp;GLenum,&nbsp;offset:&nbsp;GLintptr) | void |
| enable(cap:&nbsp;GLenum) | void |
| enableVertexAttribArray(index:&nbsp;GLuint) | void |
| finish() | void |
| flush() | void |
| framebufferRenderbuffer(target:&nbsp;GLenum,&nbsp;attachment:&nbsp;GLenum,&nbsp;renderbuffertarget:&nbsp;GLenum,&nbsp;renderbuffer:&nbsp;WebGLRenderbuffer&nbsp;\|&nbsp;null) | void |
| framebufferTexture2D(target:&nbsp;GLenum,&nbsp;attachment:&nbsp;GLenum,&nbsp;textarget:&nbsp;GLenum,&nbsp;texture:&nbsp;WebGLTexture&nbsp;\|&nbsp;null,&nbsp;level:&nbsp;GLint) | void |
| frontFace(mode:&nbsp;GLenum) | void |
| generateMipmap(target:&nbsp;GLenum) | void |
| getActiveAttrib(program:&nbsp;WebGLProgram,&nbsp;index:&nbsp;GLuint) | WebGLActiveInfo&nbsp;\|&nbsp;null |
| getActiveUniform(program:&nbsp;WebGLProgram,&nbsp;index:&nbsp;GLuint) | WebGLActiveInfo&nbsp;\|&nbsp;null |
| getAttachedShaders(program:&nbsp;WebGLProgram) | WebGLShader[]&nbsp;\|&nbsp;null |
| getAttribLocation(program:&nbsp;WebGLProgram,&nbsp;name:&nbsp;string) | GLint |
| getBufferParameter(target:&nbsp;GLenum,&nbsp;pname:&nbsp;GLenum) | any |
| getParameter(pname:&nbsp;GLenum) | any |
| getError() | GLenum |
| getFramebufferAttachmentParameter(target:&nbsp;GLenum,&nbsp;attachment:&nbsp;GLenum,&nbsp;pname:&nbsp;GLenum) | any |
| getProgramParameter(program:&nbsp;WebGLProgram,&nbsp;pname:&nbsp;GLenum) | any |
| getProgramInfoLog(program:&nbsp;WebGLProgram) | string&nbsp;\|&nbsp;null |
| getRenderbufferParameter(target:&nbsp;GLenum,&nbsp;pname:&nbsp;GLenum) | any |
| getShaderParameter(shader:&nbsp;WebGLShader,&nbsp;pname:&nbsp;GLenum) | any |
| getShaderPrecisionFormat(shadertype:&nbsp;GLenum,&nbsp;precisiontype:&nbsp;GLenum) | WebGLShaderPrecisionFormat&nbsp;\|&nbsp;null |
| getShaderInfoLog(shader:&nbsp;WebGLShader) | string&nbsp;\|&nbsp;null |
| getShaderSource(shader:&nbsp;WebGLShader) | string&nbsp;\|&nbsp;null |
| getTexParameter(target:&nbsp;GLenum,&nbsp;pname:&nbsp;GLenum) | any |
| getUniform(program:&nbsp;WebGLProgram,&nbsp;location:&nbsp;WebGLUniformLocation) | any |
| getUniformLocation(program:&nbsp;WebGLProgram,&nbsp;name:&nbsp;string) | WebGLUniformLocation&nbsp;\|&nbsp;null |
| getVertexAttrib(index:&nbsp;GLuint,&nbsp;pname:&nbsp;GLenum) | any |
| getVertexAttribOffset(index:&nbsp;GLuint,&nbsp;pname:&nbsp;GLenum) | GLintptr |
| hint(target:&nbsp;GLenum,&nbsp;mode:&nbsp;GLenum) | void |
| isBuffer(buffer:&nbsp;WebGLBuffer&nbsp;\|&nbsp;null) | GLboolean |
| isEnabled(cap:&nbsp;GLenum) | GLboolean |
| isFramebuffer(framebuffer:&nbsp;WebGLFramebuffer&nbsp;\|&nbsp;null) | GLboolean |
| isProgram(program:&nbsp;WebGLProgram&nbsp;\|&nbsp;null) | GLboolean |
| isRenderbuffer(renderbuffer:&nbsp;WebGLRenderbuffer&nbsp;\|&nbsp;null) | GLboolean |
| isShader(shader:&nbsp;WebGLShader&nbsp;\|&nbsp;null) | GLboolean |
| isTexture(texture:&nbsp;WebGLTexture&nbsp;\|&nbsp;null) | GLboolean |
| lineWidth(width:&nbsp;GLfloat) | void |
| linkProgram(program:&nbsp;WebGLProgram) | void |
| pixelStorei(pname:&nbsp;GLenum,&nbsp;param:&nbsp;GLint&nbsp;\|&nbsp;GLboolean) | void |
| polygonOffset(factor:&nbsp;GLfloat,&nbsp;units:&nbsp;GLfloat) | void |
| renderbufferStorage(target:&nbsp;GLenum,&nbsp;internalformat:&nbsp;GLenum,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei) | void |
| sampleCoverage(value:&nbsp;GLclampf,&nbsp;invert:&nbsp;GLboolean) | void |
| scissor(x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei) | void |
| shaderSource(shader:&nbsp;WebGLShader,&nbsp;source:&nbsp;string) | void |
| stencilFunc(func:&nbsp;GLenum,&nbsp;ref:&nbsp;GLint,&nbsp;mask:&nbsp;GLuint) | void |
| stencilFuncSeparate(face:&nbsp;GLenum,&nbsp;func:&nbsp;GLenum,&nbsp;ref:&nbsp;GLint,&nbsp;mask:&nbsp;GLuint) | void |
| stencilMask(mask:&nbsp;GLuint) | void |
| stencilMaskSeparate(face:&nbsp;GLenum,&nbsp;mask:&nbsp;GLuint) | void |
| stencilOp(fail:&nbsp;GLenum,&nbsp;zfail:&nbsp;GLenum,&nbsp;zpass:&nbsp;GLenum) | void |
| stencilOpSeparate(face:&nbsp;GLenum,&nbsp;fail:&nbsp;GLenum,&nbsp;zfail:&nbsp;GLenum,&nbsp;zpass:&nbsp;GLenum) | void |
| texParameterf(target:&nbsp;GLenum,&nbsp;pname:&nbsp;GLenum,&nbsp;param:&nbsp;GLfloat) | void |
| texParameteri(target:&nbsp;GLenum,&nbsp;pname:&nbsp;GLenum,&nbsp;param:&nbsp;GLint) | void |
| uniform1f(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;x:&nbsp;GLfloat) | void |
| uniform2f(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;x:&nbsp;GLfloat,&nbsp;y:&nbsp;GLfloat) | void |
| uniform3f(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;x:&nbsp;GLfloat,&nbsp;y:&nbsp;GLfloat,&nbsp;z:&nbsp;GLfloat) | void |
| uniform4f(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;x:&nbsp;GLfloat,&nbsp;y:&nbsp;GLfloat,&nbsp;z:&nbsp;GLfloat,&nbsp;w:&nbsp;GLfloat) | void |
| uniform1i(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;x:&nbsp;GLint) | void |
| uniform2i(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;x:&nbsp;GLint,&nbsp;y:&nbsp;GLint) | void |
| uniform3i(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;z:&nbsp;GLint) | void |
| uniform4i(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;z:&nbsp;GLint,&nbsp;w:&nbsp;GLint) | void |
| useProgram(program:&nbsp;WebGLProgram&nbsp;\|&nbsp;null) | void |
| validateProgram(program:&nbsp;WebGLProgram) | void |
| vertexAttrib1f(index:&nbsp;GLuint,&nbsp;x:&nbsp;GLfloat) | void |
| vertexAttrib2f(index:&nbsp;GLuint,&nbsp;x:&nbsp;GLfloat,&nbsp;y:&nbsp;GLfloat) | void |
| vertexAttrib3f(index:&nbsp;GLuint,&nbsp;x:&nbsp;GLfloat,&nbsp;y:&nbsp;GLfloat,&nbsp;z:&nbsp;GLfloat) | void |
| vertexAttrib4f(index:&nbsp;GLuint,&nbsp;x:&nbsp;GLfloat,&nbsp;y:&nbsp;GLfloat,&nbsp;z:&nbsp;GLfloat,&nbsp;w:&nbsp;GLfloat) | void |
| vertexAttrib1fv(index:&nbsp;GLuint,&nbsp;values:&nbsp;Float32List) | void |
| vertexAttrib2fv(index:&nbsp;GLuint,&nbsp;values:&nbsp;Float32List) | void |
| vertexAttrib3fv(index:&nbsp;GLuint,&nbsp;values:&nbsp;Float32List) | void |
| vertexAttrib4fv(index:&nbsp;GLuint,&nbsp;values:&nbsp;Float32List) | void |
| vertexAttribPointer(index:&nbsp;GLuint,&nbsp;size:&nbsp;GLint,&nbsp;type:&nbsp;GLenum,&nbsp;normalized:&nbsp;GLboolean,&nbsp;stride:&nbsp;GLsizei,&nbsp;offset:&nbsp;GLintptr) | void |
| viewport(x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei) | void |


## webgl.WebGLRenderingContextOverloads

WebGLRenderingContextOverloads

| 方法 | 返回值类型 |
| -------- | -------- |
| bufferData(target:&nbsp;GLenum,&nbsp;size:&nbsp;GLsizeiptr,&nbsp;usage:&nbsp;GLenum) | void |
| bufferData(target:&nbsp;GLenum,&nbsp;data:&nbsp;BufferSource&nbsp;\|&nbsp;null,&nbsp;usage:&nbsp;GLenum) | void |
| bufferSubData(target:&nbsp;GLenum,&nbsp;offset:&nbsp;GLintptr,&nbsp;data:&nbsp;BufferSource) | void |
| compressedTexImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLenum,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;data:&nbsp;ArrayBufferView) | void |
| compressedTexSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;data:&nbsp;ArrayBufferView) | void |
| readPixels(x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;pixels:&nbsp;ArrayBufferView&nbsp;\|&nbsp;null) | void |
| texImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;pixels:&nbsp;ArrayBufferView&nbsp;\|&nbsp;null) | void |
| texImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;source:&nbsp;TexImageSource) | void |
| texSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;pixels:&nbsp;ArrayBufferView&nbsp;\|&nbsp;null) | void |
| texSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;source:&nbsp;TexImageSource) | void |
| uniform1fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v:&nbsp;Float32List) | void |
| uniform2fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v:&nbsp;Float32List) | void |
| uniform3fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v:&nbsp;Float32List) | void |
| uniform4fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v:&nbsp;Float32List) | void |
| uniform1iv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v:&nbsp;Int32List) | void |
| uniform2iv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v:&nbsp;Int32List) | void |
| uniform3iv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v:&nbsp;Int32List) | void |
| uniform4iv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;v:&nbsp;Int32List) | void |
| uniformMatrix2fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;value:&nbsp;Float32List) | void |
| uniformMatrix3fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;value:&nbsp;Float32List) | void |
| uniformMatrix4fv(location:&nbsp;WebGLUniformLocation&nbsp;\|&nbsp;null,&nbsp;transpose:&nbsp;GLboolean,&nbsp;value:&nbsp;Float32List) | void |
