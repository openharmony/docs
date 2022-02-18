# WebGL

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


This module provides WebGL APIs that correspond to the OpenGL ES 2.0 feature set. For more information, see [WebGL™](https://www.khronos.org/registry/webgl/specs/latest/1.0/).




## Modules to Import

```
import webgl from 'ohos.webglnapi'
```


## System Capabilities

SystemCapability.Graphic.Graphic2D.WebGL


## Invoking Method

```
// Obtain the <canvas\> component instance.
const el = this.$refs.canvas
// Obtain the WebGL context from the <canvas\> component instance.
const gl = el.getContext('webgl');
// Call the WebGL API.
gl.clearColor(0.0, 0.0, 0.0, 1.0);
gl.flush();
```


## GLenum

| Name| Type|
| -------- | -------- |
| GLenum | number |


## GLboolean

| Name| Type|
| -------- | -------- |
| GLboolean | boolean |


## GLbitfield

| Name| Type|
| -------- | -------- |
| GLbitfield | number |


## GLbyte

| Name| Type|
| -------- | -------- |
| GLbyte | number |


## GLshort

| Name| Type|
| -------- | -------- |
| GLshort | number |


## GLint

| Name| Type|
| -------- | -------- |
| GLint | number |


## GLsizei

| Name| Type|
| -------- | -------- |
| GLsizei | number |


## GLintptr

| Name| Type|
| -------- | -------- |
| GLintptr | number |


## GLsizeiptr

| Name| Type|
| -------- | -------- |
| GLsizeiptr | number |


## GLubyte

| Name| Type|
| -------- | -------- |
| GLubyte | number |


## GLushort

| Name| Type|
| -------- | -------- |
| GLushort | number |


## GLuint

| Name| Type|
| -------- | -------- |
| GLuint | number |


## GLfloat

| Name| Type|
| -------- | -------- |
| GLfloat | number |


## GLclampf

| Name| Type|
| -------- | -------- |
| GLclampf | number |


## TexImageSource

| Name| Type|
| -------- | -------- |
| TexImageSource | ImageData |


## Float32List

| Name| Type|
| -------- | -------- |
| Float32List | array |


## Int32List

| Name| Type|
| -------- | -------- |
| Int32List | array |


## WebGLPowerPreference

| Name| Type|
| -------- | -------- |
| WebGLPowerPreference | string |


## webgl.WebGLContextAttributes

WebGLContextAttributes


| Name| Type| Mandatory|
| -------- | -------- | -------- |
| alpha  | boolean | No|
| depth | boolean | No|
| stencil | boolean | No|
| antialias  | boolean | No|
| premultipliedAlpha | boolean | No|
| preserveDrawingBuffer | boolean | No|
| powerPreference  | WebGLPowerPreference | No|
| failIfMajorPerformanceCaveat | boolean | No|
| desynchronized | boolean | No|


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

| Name| Type| Mandatory|
| -------- | -------- | -------- |
| size | [GLint](#glint) | Yes|
| type | [GLenum](#glenum) | Yes|
| name | string | Yes|


## webgl.WebGLShaderPrecisionFormat

WebGLShaderPrecisionFormat

| Name| Type| Mandatory|
| -------- | -------- | -------- |
| rangeMin | [GLint](#glint) | Yes|
| rangeMax | [GLint](#glint) | Yes|
| precision | [GLint](#glint) | Yes|


## webgl.WebGLRenderingContextBase

WebGLRenderingContextBase


### Attributes

| Name| Type| Mandatory|
| -------- | -------- | -------- |
| DEPTH_BUFFER_BIT | [GLenum](#glenum) | Yes|
| STENCIL_BUFFER_BIT | [GLenum](#glenum) | Yes|
| COLOR_BUFFER_BIT | [GLenum](#glenum) | Yes|
| POINTS | [GLenum](#glenum) | Yes|
| LINES | [GLenum](#glenum) | Yes|
| LINE_LOOP | [GLenum](#glenum) | Yes|
| LINE_STRIP | [GLenum](#glenum) | Yes|
| TRIANGLES | [GLenum](#glenum) | Yes|
| TRIANGLE_STRIP | [GLenum](#glenum) | Yes|
| TRIANGLE_FAN | [GLenum](#glenum) | Yes|
| ZERO | [GLenum](#glenum) | Yes|
| ONE | [GLenum](#glenum) | Yes|
| SRC_COLOR | [GLenum](#glenum) | Yes|
| ONE_MINUS_SRC_COLOR | [GLenum](#glenum) | Yes|
| SRC_ALPHA | [GLenum](#glenum) | Yes|
| ONE_MINUS_SRC_ALPHA | [GLenum](#glenum) | Yes|
| DST_ALPHA | [GLenum](#glenum) | Yes|
| ONE_MINUS_DST_ALPHA | [GLenum](#glenum) | Yes|
| DST_COLOR | [GLenum](#glenum) | Yes|
| ONE_MINUS_DST_COLOR | [GLenum](#glenum) | Yes|
| SRC_ALPHA_SATURATE | [GLenum](#glenum) | Yes|
| FUNC_ADD | [GLenum](#glenum) | Yes|
| BLEND_EQUATION | [GLenum](#glenum) | Yes|
| BLEND_EQUATION_RGB | [GLenum](#glenum) | Yes|
| BLEND_EQUATION_ALPHA | [GLenum](#glenum) | Yes|
| FUNC_SUBTRACT | [GLenum](#glenum) | Yes|
| FUNC_REVERSE_SUBTRACT | [GLenum](#glenum) | Yes|
| BLEND_DST_RGB | [GLenum](#glenum) | Yes|
| BLEND_SRC_RGB | [GLenum](#glenum) | Yes|
| BLEND_DST_ALPHA | [GLenum](#glenum) | Yes|
| BLEND_SRC_ALPHA | [GLenum](#glenum) | Yes|
| CONSTANT_COLOR | [GLenum](#glenum) | Yes|
| ONE_MINUS_CONSTANT_COLOR | [GLenum](#glenum) | Yes|
| CONSTANT_ALPHA | [GLenum](#glenum) | Yes|
| ONE_MINUS_CONSTANT_ALPHA | [GLenum](#glenum) | Yes|
| BLEND_COLOR | [GLenum](#glenum) | Yes|
| ARRAY_BUFFER | [GLenum](#glenum) | Yes|
| ELEMENT_ARRAY_BUFFER | [GLenum](#glenum) | Yes|
| ARRAY_BUFFER_BINDING | [GLenum](#glenum) | Yes|
| ELEMENT_ARRAY_BUFFER_BINDING | [GLenum](#glenum) | Yes|
| STREAM_DRAW | [GLenum](#glenum) | Yes|
| STATIC_DRAW | [GLenum](#glenum) | Yes|
| DYNAMIC_DRAW | [GLenum](#glenum) | Yes|
| BUFFER_SIZE | [GLenum](#glenum) | Yes|
| BUFFER_USAGE | [GLenum](#glenum) | Yes|
| CURRENT_VERTEX_ATTRIB | [GLenum](#glenum) | Yes|
| FRONT | [GLenum](#glenum) | Yes|
| BACK | [GLenum](#glenum) | Yes|
| FRONT_AND_BACK | [GLenum](#glenum) | Yes|
| CULL_FACE | [GLenum](#glenum) | Yes|
| BLEND | [GLenum](#glenum) | Yes|
| DITHER | [GLenum](#glenum) | Yes|
| STENCIL_TEST | [GLenum](#glenum) | Yes|
| DEPTH_TEST | [GLenum](#glenum) | Yes|
| SCISSOR_TEST | [GLenum](#glenum) | Yes|
| POLYGON_OFFSET_FILL | [GLenum](#glenum) | Yes|
| SAMPLE_ALPHA_TO_COVERAGE | [GLenum](#glenum) | Yes|
| SAMPLE_COVERAGE | [GLenum](#glenum) | Yes|
| NO_ERROR | [GLenum](#glenum) | Yes|
| INVALID_ENUM | [GLenum](#glenum) | Yes|
| INVALID_VALUE | [GLenum](#glenum) | Yes|
| INVALID_OPERATION | [GLenum](#glenum) | Yes|
| OUT_OF_MEMORY | [GLenum](#glenum) | Yes|
| CW | [GLenum](#glenum) | Yes|
| CCW | [GLenum](#glenum) | Yes|
| ALIASED_POINT_SIZE_RANGE | [GLenum](#glenum) | Yes|
| ALIASED_LINE_WIDTH_RANGE | [GLenum](#glenum) | Yes|
| CULL_FACE_MODE | [GLenum](#glenum) | Yes|
| FRONT_FACE | [GLenum](#glenum) | Yes|
| DEPTH_RANGE | [GLenum](#glenum) | Yes|
| DEPTH_WRITEMASK | [GLenum](#glenum) | Yes|
| DEPTH_CLEAR_VALUE | [GLenum](#glenum) | Yes|
| DEPTH_FUNC | [GLenum](#glenum) | Yes|
| STENCIL_CLEAR_VALUE | [GLenum](#glenum) | Yes|
| STENCIL_FUNC | [GLenum](#glenum) | Yes|
| STENCIL_FAIL | [GLenum](#glenum) | Yes|
| STENCIL_PASS_DEPTH_FAIL | [GLenum](#glenum) | Yes|
| STENCIL_PASS_DEPTH_PASS | [GLenum](#glenum) | Yes|
| STENCIL_REF | [GLenum](#glenum) | Yes|
| STENCIL_VALUE_MASK | [GLenum](#glenum) | Yes|
| STENCIL_WRITEMASK | [GLenum](#glenum) | Yes|
| STENCIL_BACK_FUNC | [GLenum](#glenum) | Yes|
| STENCIL_BACK_FAIL | [GLenum](#glenum) | Yes|
| STENCIL_BACK_PASS_DEPTH_FAIL | [GLenum](#glenum) | Yes|
| STENCIL_BACK_PASS_DEPTH_PASS | [GLenum](#glenum) | Yes|
| STENCIL_BACK_REF | [GLenum](#glenum) | Yes|
| STENCIL_BACK_VALUE_MASK | [GLenum](#glenum) | Yes|
| STENCIL_BACK_WRITEMASK | [GLenum](#glenum) | Yes|
| VIEWPORT | [GLenum](#glenum) | Yes|
| SCISSOR_BOX | [GLenum](#glenum) | Yes|
| COLOR_CLEAR_VALUE | [GLenum](#glenum) | Yes|
| COLOR_WRITEMASK | [GLenum](#glenum) | Yes|
| UNPACK_ALIGNMENT | [GLenum](#glenum) | Yes|
| PACK_ALIGNMENT | [GLenum](#glenum) | Yes|
| MAX_TEXTURE_SIZE | [GLenum](#glenum) | Yes|
| MAX_VIEWPORT_DIMS | [GLenum](#glenum) | Yes|
| SUBPIXEL_BITS | [GLenum](#glenum) | Yes|
| RED_BITS | [GLenum](#glenum) | Yes|
| GREEN_BITS | [GLenum](#glenum) | Yes|
| BLUE_BITS | [GLenum](#glenum) | Yes|
| ALPHA_BITS | [GLenum](#glenum) | Yes|
| DEPTH_BITS | [GLenum](#glenum) | Yes|
| STENCIL_BITS | [GLenum](#glenum) | Yes|
| POLYGON_OFFSET_UNITS | [GLenum](#glenum) | Yes|
| POLYGON_OFFSET_FACTOR | [GLenum](#glenum) | Yes|
| TEXTURE_BINDING_2D | [GLenum](#glenum) | Yes|
| SAMPLE_BUFFERS | [GLenum](#glenum) | Yes|
| SAMPLES | [GLenum](#glenum) | Yes|
| SAMPLE_COVERAGE_VALUE | [GLenum](#glenum) | Yes|
| SAMPLE_COVERAGE_INVERT | [GLenum](#glenum) | Yes|
| COMPRESSED_TEXTURE_FORMATS | [GLenum](#glenum) | Yes|
| DONT_CARE | [GLenum](#glenum) | Yes|
| FASTEST | [GLenum](#glenum) | Yes|
| NICEST | [GLenum](#glenum) | Yes|
| GENERATE_MIPMAP_HINT | [GLenum](#glenum) | Yes|
| BYTE | [GLenum](#glenum) | Yes|
| UNSIGNED_BYTE | [GLenum](#glenum) | Yes|
| SHORT | [GLenum](#glenum) | Yes|
| UNSIGNED_SHORT | [GLenum](#glenum) | Yes|
| INT | [GLenum](#glenum) | Yes|
| UNSIGNED_INT | [GLenum](#glenum) | Yes|
| FLOAT | [GLenum](#glenum) | Yes|
| DEPTH_COMPONENT | [GLenum](#glenum) | Yes|
| ALPHA | [GLenum](#glenum) | Yes|
| RGB | [GLenum](#glenum) | Yes|
| RGBA | [GLenum](#glenum) | Yes|
| LUMINANCE | [GLenum](#glenum) | Yes|
| LUMINANCE_ALPHA | [GLenum](#glenum) | Yes|
| UNSIGNED_SHORT_4_4_4_4 | [GLenum](#glenum) | Yes|
| UNSIGNED_SHORT_5_5_5_1 | [GLenum](#glenum) | Yes|
| UNSIGNED_SHORT_5_6_5 | [GLenum](#glenum) | Yes|
| FRAGMENT_SHADER | [GLenum](#glenum) | Yes|
| VERTEX_SHADER | [GLenum](#glenum) | Yes|
| MAX_VERTEX_ATTRIBS | [GLenum](#glenum) | Yes|
| MAX_VERTEX_UNIFORM_VECTORS | [GLenum](#glenum) | Yes|
| MAX_VARYING_VECTORS | [GLenum](#glenum) | Yes|
| MAX_COMBINED_TEXTURE_IMAGE_UNITS | [GLenum](#glenum) | Yes|
| MAX_VERTEX_TEXTURE_IMAGE_UNITS | [GLenum](#glenum) | Yes|
| MAX_TEXTURE_IMAGE_UNITS | [GLenum](#glenum) | Yes|
| MAX_FRAGMENT_UNIFORM_VECTORS | [GLenum](#glenum) | Yes|
| SHADER_TYPE | [GLenum](#glenum) | Yes|
| DELETE_STATUS | [GLenum](#glenum) | Yes|
| LINK_STATUS | [GLenum](#glenum) | Yes|
| VALIDATE_STATUS | [GLenum](#glenum) | Yes|
| ATTACHED_SHADERS | [GLenum](#glenum) | Yes|
| ACTIVE_UNIFORMS | [GLenum](#glenum) | Yes|
| ACTIVE_ATTRIBUTES | [GLenum](#glenum) | Yes|
| SHADING_LANGUAGE_VERSION | [GLenum](#glenum) | Yes|
| CURRENT_PROGRAM | [GLenum](#glenum) | Yes|
| NEVER | [GLenum](#glenum) | Yes|
| LESS | [GLenum](#glenum) | Yes|
| EQUAL | [GLenum](#glenum) | Yes|
| LEQUAL | [GLenum](#glenum) | Yes|
| GREATER | [GLenum](#glenum) | Yes|
| NOTEQUAL | [GLenum](#glenum) | Yes|
| GEQUAL | [GLenum](#glenum) | Yes|
| ALWAYS | [GLenum](#glenum) | Yes|
| KEEP | [GLenum](#glenum) | Yes|
| REPLACE | [GLenum](#glenum) | Yes|
| INCR | [GLenum](#glenum) | Yes|
| DECR | [GLenum](#glenum) | Yes|
| INVERT | [GLenum](#glenum) | Yes|
| INCR_WRAP | [GLenum](#glenum) | Yes|
| DECR_WRAP | [GLenum](#glenum) | Yes|
| VENDOR | [GLenum](#glenum) | Yes|
| RENDERER | [GLenum](#glenum) | Yes|
| VERSION | [GLenum](#glenum) | Yes|
| NEAREST | [GLenum](#glenum) | Yes|
| LINEAR | [GLenum](#glenum) | Yes|
| NEAREST_MIPMAP_NEAREST | [GLenum](#glenum) | Yes|
| LINEAR_MIPMAP_NEAREST | [GLenum](#glenum) | Yes|
| NEAREST_MIPMAP_LINEAR | [GLenum](#glenum) | Yes|
| LINEAR_MIPMAP_LINEAR | [GLenum](#glenum) | Yes|
| TEXTURE_MAG_FILTER | [GLenum](#glenum) | Yes|
| TEXTURE_MIN_FILTER | [GLenum](#glenum) | Yes|
| TEXTURE_WRAP_S | [GLenum](#glenum) | Yes|
| TEXTURE_WRAP_T | [GLenum](#glenum) | Yes|
| TEXTURE_2D | [GLenum](#glenum) | Yes|
| TEXTURE | [GLenum](#glenum) | Yes|
| TEXTURE_CUBE_MAP | [GLenum](#glenum) | Yes|
| TEXTURE_BINDING_CUBE_MAP | [GLenum](#glenum) | Yes|
| TEXTURE_CUBE_MAP_POSITIVE_X | [GLenum](#glenum) | Yes|
| TEXTURE_CUBE_MAP_NEGATIVE_X | [GLenum](#glenum) | Yes|
| TEXTURE_CUBE_MAP_POSITIVE_Y | [GLenum](#glenum) | Yes|
| TEXTURE_CUBE_MAP_NEGATIVE_Y | [GLenum](#glenum) | Yes|
| TEXTURE_CUBE_MAP_POSITIVE_Z | [GLenum](#glenum) | Yes|
| TEXTURE_CUBE_MAP_NEGATIVE_Z | [GLenum](#glenum) | Yes|
| TEXTURE0 | [GLenum](#glenum) | Yes|
| TEXTURE1 | [GLenum](#glenum) | Yes|
| TEXTURE2 | [GLenum](#glenum) | Yes|
| TEXTURE3 | [GLenum](#glenum) | Yes|
| TEXTURE4 | [GLenum](#glenum) | Yes|
| TEXTURE5 | [GLenum](#glenum) | Yes|
| TEXTURE6 | [GLenum](#glenum) | Yes|
| TEXTURE7 | [GLenum](#glenum) | Yes|
| TEXTURE8 | [GLenum](#glenum) | Yes|
| TEXTURE9 | [GLenum](#glenum) | Yes|
| TEXTURE10 | [GLenum](#glenum) | Yes|
| TEXTURE11 | [GLenum](#glenum) | Yes|
| TEXTURE12 | [GLenum](#glenum) | Yes|
| TEXTURE13 | [GLenum](#glenum) | Yes|
| TEXTURE14 | [GLenum](#glenum) | Yes|
| TEXTURE15 | [GLenum](#glenum) | Yes|
| TEXTURE16 | [GLenum](#glenum) | Yes|
| TEXTURE17 | [GLenum](#glenum) | Yes|
| TEXTURE18 | [GLenum](#glenum) | Yes|
| TEXTURE19 | [GLenum](#glenum) | Yes|
| TEXTURE20 | [GLenum](#glenum) | Yes|
| TEXTURE21 | [GLenum](#glenum) | Yes|
| TEXTURE22 | [GLenum](#glenum) | Yes|
| TEXTURE23 | [GLenum](#glenum) | Yes|
| TEXTURE24 | [GLenum](#glenum) | Yes|
| TEXTURE25 | [GLenum](#glenum) | Yes|
| TEXTURE26 | [GLenum](#glenum) | Yes|
| TEXTURE27 | [GLenum](#glenum) | Yes|
| TEXTURE28 | [GLenum](#glenum) | Yes|
| TEXTURE29 | [GLenum](#glenum) | Yes|
| TEXTURE30 | [GLenum](#glenum) | Yes|
| TEXTURE31 | [GLenum](#glenum) | Yes|
| ACTIVE_TEXTURE | [GLenum](#glenum) | Yes|
| REPEAT | [GLenum](#glenum) | Yes|
| CLAMP_TO_EDGE | [GLenum](#glenum) | Yes|
| MIRRORED_REPEAT | [GLenum](#glenum) | Yes|
| FLOAT_VEC2 | [GLenum](#glenum) | Yes|
| FLOAT_VEC3 | [GLenum](#glenum) | Yes|
| FLOAT_VEC4 | [GLenum](#glenum) | Yes|
| INT_VEC2 | [GLenum](#glenum) | Yes|
| INT_VEC3 | [GLenum](#glenum) | Yes|
| INT_VEC4 | [GLenum](#glenum) | Yes|
| BOOL | [GLenum](#glenum) | Yes|
| BOOL_VEC2 | [GLenum](#glenum) | Yes|
| BOOL_VEC3 | [GLenum](#glenum) | Yes|
| BOOL_VEC4 | [GLenum](#glenum) | Yes|
| FLOAT_MAT2 | [GLenum](#glenum) | Yes|
| FLOAT_MAT3 | [GLenum](#glenum) | Yes|
| FLOAT_MAT4 | [GLenum](#glenum) | Yes|
| SAMPLER_2D | [GLenum](#glenum) | Yes|
| SAMPLER_CUBE | [GLenum](#glenum) | Yes|
| VERTEX_ATTRIB_ARRAY_ENABLED | [GLenum](#glenum) | Yes|
| VERTEX_ATTRIB_ARRAY_SIZE | [GLenum](#glenum) | Yes|
| VERTEX_ATTRIB_ARRAY_STRIDE | [GLenum](#glenum) | Yes|
| VERTEX_ATTRIB_ARRAY_TYPE | [GLenum](#glenum) | Yes|
| VERTEX_ATTRIB_ARRAY_NORMALIZED | [GLenum](#glenum) | Yes|
| VERTEX_ATTRIB_ARRAY_POINTER | [GLenum](#glenum) | Yes|
| VERTEX_ATTRIB_ARRAY_BUFFER_BINDING | [GLenum](#glenum) | Yes|
| IMPLEMENTATION_COLOR_READ_TYPE | [GLenum](#glenum) | Yes|
| IMPLEMENTATION_COLOR_READ_FORMAT | [GLenum](#glenum) | Yes|
| COMPILE_STATUS | [GLenum](#glenum) | Yes|
| LOW_FLOAT | [GLenum](#glenum) | Yes|
| MEDIUM_FLOAT | [GLenum](#glenum) | Yes|
| HIGH_FLOAT | [GLenum](#glenum) | Yes|
| LOW_INT | [GLenum](#glenum) | Yes|
| MEDIUM_INT | [GLenum](#glenum) | Yes|
| HIGH_INT | [GLenum](#glenum) | Yes|
| FRAMEBUFFER | [GLenum](#glenum) | Yes|
| RENDERBUFFER | [GLenum](#glenum) | Yes|
| RGBA4 | [GLenum](#glenum) | Yes|
| RGB5_A1 | [GLenum](#glenum) | Yes|
| RGB565 | [GLenum](#glenum) | Yes|
| DEPTH_COMPONENT16 | [GLenum](#glenum) | Yes|
| STENCIL_INDEX8 | [GLenum](#glenum) | Yes|
| DEPTH_STENCIL | [GLenum](#glenum) | Yes|
| RENDERBUFFER_WIDTH | [GLenum](#glenum) | Yes|
| RENDERBUFFER_HEIGHT | [GLenum](#glenum) | Yes|
| RENDERBUFFER_INTERNAL_FORMAT | [GLenum](#glenum) | Yes|
| RENDERBUFFER_RED_SIZE | [GLenum](#glenum) | Yes|
| RENDERBUFFER_GREEN_SIZE | [GLenum](#glenum) | Yes|
| RENDERBUFFER_BLUE_SIZE | [GLenum](#glenum) | Yes|
| RENDERBUFFER_ALPHA_SIZE | [GLenum](#glenum) | Yes|
| RENDERBUFFER_DEPTH_SIZE | [GLenum](#glenum) | Yes|
| RENDERBUFFER_STENCIL_SIZE | [GLenum](#glenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE | [GLenum](#glenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_OBJECT_NAME | [GLenum](#glenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL | [GLenum](#glenum) | Yes|
| FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE | [GLenum](#glenum) | Yes|
| COLOR_ATTACHMENT0 | [GLenum](#glenum) | Yes|
| DEPTH_ATTACHMENT | [GLenum](#glenum) | Yes|
| STENCIL_ATTACHMENT | [GLenum](#glenum) | Yes|
| DEPTH_STENCIL_ATTACHMENT | [GLenum](#glenum) | Yes|
| NONE | [GLenum](#glenum) | Yes|
| FRAMEBUFFER_COMPLETE | [GLenum](#glenum) | Yes|
| FRAMEBUFFER_INCOMPLETE_ATTACHMENT | [GLenum](#glenum) | Yes|
| FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT | [GLenum](#glenum) | Yes|
| FRAMEBUFFER_INCOMPLETE_DIMENSIONS | [GLenum](#glenum) | Yes|
| FRAMEBUFFER_UNSUPPORTED | [GLenum](#glenum) | Yes|
| FRAMEBUFFER_BINDING | [GLenum](#glenum) | Yes|
| RENDERBUFFER_BINDING | [GLenum](#glenum) | Yes|
| MAX_RENDERBUFFER_SIZE | [GLenum](#glenum) | Yes|
| INVALID_FRAMEBUFFER_OPERATION | [GLenum](#glenum) | Yes|
| UNPACK_FLIP_Y_WEBGL | [GLenum](#glenum) | Yes|
| UNPACK_PREMULTIPLY_ALPHA_WEBGL | [GLenum](#glenum) | Yes|
| CONTEXT_LOST_WEBGL | [GLenum](#glenum) | Yes|
| UNPACK_COLORSPACE_CONVERSION_WEBGL | [GLenum](#glenum) | Yes|
| BROWSER_DEFAULT_WEBGL | [GLenum](#glenum) | Yes|
| canvas | HTMLCanvasElement&nbsp;\|&nbsp;OffscreenCanvas | Yes|
| drawingBufferWidth | [GLsizei](#glsizei) | Yes|
| drawingBufferHeight | [GLsizei](#glsizei) | Yes|


### Methods

| Method| Return Value Type|
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

| Method| Return Value Type|
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
