# webgl

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


This module provides WebGL APIs that correspond to the OpenGL ES 2.0 feature set. For more information, see [WebGL™](https://www.khronos.org/registry/webgl/specs/latest/1.0/).


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
const gl = el.getContext('webgl');
// Call the WebGL API.
gl.clearColor(0.0, 0.0, 0.0, 1.0);
```


## Type

**System capability**: SystemCapability.Graphic.Graphic2D.WebGL

  **Table 1** Type

| Name| Type|
| -------- | -------- |
| GLenum | number |
| GLboolean | boolean |
| GLbitfield | number |
| GLbyte | number |
| GLshort | number |
| GLint | number |
| GLsizei | number |
| GLintptr | number |
| GLsizeiptr | number |
| GLubyte | number |
| GLushort | number |
| GLuint | number |
| GLfloat | number |
| GLclampf | number |
| TexImageSource | ImageData |
| Float32List | array |
| Int32List | array |
| WebGLPowerPreference | string |


## Interface

**System capability**: SystemCapability.Graphic.Graphic2D.WebGL

  **Table 2** Interface

| Name|
| -------- |
| [WebGLContextAttributes](#webglcontextattributes) |
| WebGLBuffer |
| WebGLFrameBuffer |
| WebGLProgram |
| WebGLRenderbuffer |
| WebGLShader |
| WebGLTexture |
| WebGLUniformLocation |
| [WebGLActiveInfo](#webglactiveinfo) |
| [WebGLShaderPrecisionFormat](#webglshaderprecisionformat) |
| [WebGLRenderingContextBase](#webglrenderingcontextbase) |
| [WebGLRenderingContextOverloads](#webglrenderingcontextoverloads) |


## WebGLContextAttributes

WebGLContextAttributes


| Name| Type| Mandatory|
| -------- | -------- | -------- |
| alpha | boolean | No|
| depth | boolean | No|
| stencil | boolean | No|
| antialias | boolean | No|
| premultipliedAlpha | boolean | No|
| preserveDrawingBuffer | boolean | No|
| powerPreference | WebGLPowerPreference | No|
| failIfMajorPerformanceCaveat | boolean | No|
| desynchronized | boolean | No|


## WebGLActiveInfo

WebGLActiveInfo

| Name| Type| Mandatory|
| -------- | -------- | -------- |
| size | GLint | Yes|
| type | GLenum | Yes|
| name | string | Yes|


## WebGLShaderPrecisionFormat

WebGLShaderPrecisionFormat

| Name| Type| Mandatory|
| -------- | -------- | -------- |
| rangeMin | GLint | Yes|
| rangeMax | GLint | Yes|
| precision | GLint | Yes|


## WebGLRenderingContextBase

WebGLRenderingContextBase


### Attributes

| Name| Type| Mandatory|
| -------- | -------- | -------- |
| DEPTH_BUFFER_BIT | GLenum | Yes|
| STENCIL_BUFFER_BIT | GLenum | Yes|
| COLOR_BUFFER_BIT | GLenum | Yes|
| POINTS | GLenum | Yes|
| LINES | GLenum | Yes|
| LINE_LOOP | GLenum | Yes|
| LINE_STRIP | GLenum | Yes|
| TRIANGLES | GLenum | Yes|
| TRIANGLE_STRIP | GLenum | Yes|
| TRIANGLE_FAN | GLenum | Yes|
| ZERO | GLenum | Yes|
| ONE | GLenum | Yes|
| SRC_COLOR | GLenum | Yes|
| ONE_MINUS_SRC_COLOR | GLenum | Yes|
| SRC_ALPHA | GLenum | Yes|
| ONE_MINUS_SRC_ALPHA | GLenum | Yes|
| DST_ALPHA | GLenum | Yes|
| ONE_MINUS_DST_ALPHA | GLenum | Yes|
| DST_COLOR | GLenum | Yes|
| ONE_MINUS_DST_COLOR | GLenum | Yes|
| SRC_ALPHA_SATURATE | GLenum | Yes|
| FUNC_ADD | GLenum | Yes|
| BLEND_EQUATION | GLenum | Yes|
| BLEND_EQUATION_RGB | GLenum | Yes|
| BLEND_EQUATION_ALPHA | GLenum | Yes|
| FUNC_SUBTRACT | GLenum | Yes|
| FUNC_REVERSE_SUBTRACT | GLenum | Yes|
| BLEND_DST_RGB | GLenum | Yes|
| BLEND_SRC_RGB | GLenum | Yes|
| BLEND_DST_ALPHA | GLenum | Yes|
| BLEND_SRC_ALPHA | GLenum | Yes|
| CONSTANT_COLOR | GLenum | Yes|
| ONE_MINUS_CONSTANT_COLOR | GLenum | Yes|
| CONSTANT_ALPHA | GLenum | Yes|
| ONE_MINUS_CONSTANT_ALPHA | GLenum | Yes|
| BLEND_COLOR | GLenum | Yes|
| ARRAY_BUFFER | GLenum | Yes|
| ELEMENT_ARRAY_BUFFER | GLenum | Yes|
| ARRAY_BUFFER_BINDING | GLenum | Yes|
| ELEMENT_ARRAY_BUFFER_BINDING | GLenum | Yes|
| STREAM_DRAW | GLenum | Yes|
| STATIC_DRAW | GLenum | Yes|
| DYNAMIC_DRAW | GLenum | Yes|
| BUFFER_SIZE | GLenum | Yes|
| BUFFER_USAGE | GLenum | Yes|
| CURRENT_VERTEX_ATTRIB | GLenum | Yes|
| FRONT | GLenum | Yes|
| BACK | GLenum | Yes|
| FRONT_AND_BACK | GLenum | Yes|
| CULL_FACE | GLenum | Yes|
| BLEND | GLenum | Yes|
| DITHER | GLenum | Yes|
| STENCIL_TEST | GLenum | Yes|
| DEPTH_TEST | GLenum | Yes|
| SCISSOR_TEST | GLenum | Yes|
| POLYGON_OFFSET_FILL | GLenum | Yes|
| SAMPLE_ALPHA_TO_COVERAGE | GLenum | Yes|
| SAMPLE_COVERAGE | GLenum | Yes|
| NO_ERROR | GLenum | Yes|
| INVALID_ENUM | GLenum | Yes|
| INVALID_VALUE | GLenum | Yes|
| INVALID_OPERATION | GLenum | Yes|
| OUT_OF_MEMORY | GLenum | Yes|
| CW | GLenum | Yes|
| CCW | GLenum | Yes|
| LINE_WIDTH | GLenum | Yes|
| ALIASED_POINT_SIZE_RANGE | GLenum | Yes|
| ALIASED_LINE_WIDTH_RANGE | GLenum | Yes|
| CULL_FACE_MODE | GLenum | Yes|
| FRONT_FACE | GLenum | Yes|
| DEPTH_RANGE | GLenum | Yes|
| DEPTH_WRITEMASK | GLenum | Yes|
| DEPTH_CLEAR_VALUE | GLenum | Yes|
| DEPTH_FUNC | GLenum | Yes|
| STENCIL_CLEAR_VALUE | GLenum | Yes|
| STENCIL_FUNC | GLenum | Yes|
| STENCIL_FAIL | GLenum | Yes|
| STENCIL_PASS_DEPTH_FAIL | GLenum | Yes|
| STENCIL_PASS_DEPTH_PASS | GLenum | Yes|
| STENCIL_REF | GLenum | Yes|
| STENCIL_VALUE_MASK | GLenum | Yes|
| STENCIL_WRITEMASK | GLenum | Yes|
| STENCIL_BACK_FUNC | GLenum | Yes|
| STENCIL_BACK_FAIL | GLenum | Yes|
| STENCIL_BACK_PASS_DEPTH_FAIL | GLenum | Yes|
| STENCIL_BACK_PASS_DEPTH_PASS | GLenum | Yes|
| STENCIL_BACK_REF | GLenum | Yes|
| STENCIL_BACK_VALUE_MASK | GLenum | Yes|
| STENCIL_BACK_WRITEMASK | GLenum | Yes|
| VIEWPORT | GLenum | Yes|
| SCISSOR_BOX | GLenum | Yes|
| COLOR_CLEAR_VALUE | GLenum | Yes|
| COLOR_WRITEMASK | GLenum | Yes|
| UNPACK_ALIGNMENT | GLenum | Yes|
| PACK_ALIGNMENT | GLenum | Yes|
| MAX_TEXTURE_SIZE | GLenum | Yes|
| MAX_VIEWPORT_DIMS | GLenum | Yes|
| SUBPIXEL_BITS | GLenum | Yes|
| RED_BITS | GLenum | Yes|
| GREEN_BITS | GLenum | Yes|
| BLUE_BITS | GLenum | Yes|
| ALPHA_BITS | GLenum | Yes|
| DEPTH_BITS | GLenum | Yes|
| STENCIL_BITS | GLenum | Yes|
| POLYGON_OFFSET_UNITS | GLenum | Yes|
| POLYGON_OFFSET_FACTOR | GLenum | Yes|
| TEXTURE_BINDING_2D | GLenum | Yes|
| SAMPLE_BUFFERS | GLenum | Yes|
| SAMPLES | GLenum | Yes|
| SAMPLE_COVERAGE_VALUE | GLenum | Yes|
| SAMPLE_COVERAGE_INVERT | GLenum | Yes|
| COMPRESSED_TEXTURE_FORMATS | GLenum | Yes|
| DONT_CARE | GLenum | Yes|
| FASTEST | GLenum | Yes|
| NICEST | GLenum | Yes|
| GENERATE_MIPMAP_HINT | GLenum | Yes|
| BYTE | GLenum | Yes|
| UNSIGNED_BYTE | GLenum | Yes|
| SHORT | GLenum | Yes|
| UNSIGNED_SHORT | GLenum | Yes|
| INT | GLenum | Yes|
| UNSIGNED_INT | GLenum | Yes|
| FLOAT | GLenum | Yes|
| DEPTH_COMPONENT | GLenum | Yes|
| ALPHA | GLenum | Yes|
| RGB | GLenum | Yes|
| RGBA | GLenum | Yes|
| LUMINANCE | GLenum | Yes|
| LUMINANCE_ALPHA | GLenum | Yes|
| UNSIGNED_SHORT_4_4_4_4 | GLenum | Yes|
| UNSIGNED_SHORT_5_5_5_1 | GLenum | Yes|
| UNSIGNED_SHORT_5_6_5 | GLenum | Yes|
| FRAGMENT_SHADER | GLenum | Yes|
| VERTEX_SHADER | GLenum | Yes|
| MAX_VERTEX_ATTRIBS | GLenum | Yes|
| MAX_VERTEX_UNIFORM_VECTORS | GLenum | Yes|
| MAX_VARYING_VECTORS | GLenum | Yes|
| MAX_COMBINED_TEXTURE_IMAGE_UNITS | GLenum | Yes|
| MAX_VERTEX_TEXTURE_IMAGE_UNITS | GLenum | Yes|
| MAX_TEXTURE_IMAGE_UNITS | GLenum | Yes|
| MAX_FRAGMENT_UNIFORM_VECTORS | GLenum | Yes|
| SHADER_TYPE | GLenum | Yes|
| DELETE_STATUS | GLenum | Yes|
| LINK_STATUS | GLenum | Yes|
| VALIDATE_STATUS | GLenum | Yes|
| ATTACHED_SHADERS | GLenum | Yes|
| ACTIVE_UNIFORMS | GLenum | Yes|
| ACTIVE_ATTRIBUTES | GLenum | Yes|
| SHADING_LANGUAGE_VERSION | GLenum | Yes|
| CURRENT_PROGRAM | GLenum | Yes|
| NEVER | GLenum | Yes|
| LESS | GLenum | Yes|
| EQUAL | GLenum | Yes|
| LEQUAL | GLenum | Yes|
| GREATER | GLenum | Yes|
| NOTEQUAL | GLenum | Yes|
| GEQUAL | GLenum | Yes|
| ALWAYS | GLenum | Yes|
| KEEP | GLenum | Yes|
| REPLACE | GLenum | Yes|
| INCR | GLenum | Yes|
| DECR | GLenum | Yes|
| INVERT | GLenum | Yes|
| INCR_WRAP | GLenum | Yes|
| DECR_WRAP | GLenum | Yes|
| VENDOR | GLenum | Yes|
| RENDERER | GLenum | Yes|
| VERSION | GLenum | Yes|
| NEAREST | GLenum | Yes|
| LINEAR | GLenum | Yes|
| NEAREST_MIPMAP_NEAREST | GLenum | Yes|
| LINEAR_MIPMAP_NEAREST | GLenum | Yes|
| NEAREST_MIPMAP_LINEAR | GLenum | Yes|
| LINEAR_MIPMAP_LINEAR | GLenum | Yes|
| TEXTURE_MIN_FILTER | GLenum | Yes|
| TEXTURE_WRAP_S | GLenum | Yes|
| TEXTURE_WRAP_T | GLenum | Yes|
| TEXTURE_2D | GLenum | Yes|
| TEXTURE | GLenum | Yes|
| TEXTURE_CUBE_MAP | GLenum | Yes|
| TEXTURE_BINDING_CUBE_MAP | GLenum | Yes|
| TEXTURE_CUBE_MAP_POSITIVE_X | GLenum | Yes|
| TEXTURE_CUBE_MAP_NEGATIVE_X | GLenum | Yes|
| TEXTURE_CUBE_MAP_POSITIVE_Y | GLenum | Yes|
| TEXTURE_CUBE_MAP_NEGATIVE_Y | GLenum | Yes|
| TEXTURE_CUBE_MAP_POSITIVE_Z | GLenum | Yes|
| TEXTURE_CUBE_MAP_NEGATIVE_Z | GLenum | Yes|
| MAX_CUBE_MAP_TEXTURE_SIZE | GLenum | Yes|
| TEXTURE0 | GLenum | Yes|
| TEXTURE1 | GLenum | Yes|
| TEXTURE2 | GLenum | Yes|
| TEXTURE3 | GLenum | Yes|
| TEXTURE4 | GLenum | Yes|
| TEXTURE5 | GLenum | Yes|
| TEXTURE6 | GLenum | Yes|
| TEXTURE7 | GLenum | Yes|
| TEXTURE8 | GLenum | Yes|
| TEXTURE9 | GLenum | Yes|
| TEXTURE10 | GLenum | Yes|
| TEXTURE11 | GLenum | Yes|
| TEXTURE12 | GLenum | Yes|
| TEXTURE13 | GLenum | Yes|
| TEXTURE14 | GLenum | Yes|
| TEXTURE15 | GLenum | Yes|
| TEXTURE16 | GLenum | Yes|
| TEXTURE17 | GLenum | Yes|
| TEXTURE18 | GLenum | Yes|
| TEXTURE19 | GLenum | Yes|
| TEXTURE20 | GLenum | Yes|
| TEXTURE21 | GLenum | Yes|
| TEXTURE22 | GLenum | Yes|
| TEXTURE23 | GLenum | Yes|
| TEXTURE24 | GLenum | Yes|
| TEXTURE25 | GLenum | Yes|
| TEXTURE26 | GLenum | Yes|
| TEXTURE27 | GLenum | Yes|
| TEXTURE28 | GLenum | Yes|
| TEXTURE29 | GLenum | Yes|
| TEXTURE30 | GLenum | Yes|
| TEXTURE31 | GLenum | Yes|
| ACTIVE_TEXTURE | GLenum | Yes|
| REPEAT | GLenum | Yes|
| CLAMP_TO_EDGE | GLenum | Yes|
| MIRRORED_REPEAT | GLenum | Yes|
| FLOAT_VEC2 | GLenum | Yes|
| FLOAT_VEC3 | GLenum | Yes|
| FLOAT_VEC4 | GLenum | Yes|
| INT_VEC2 | GLenum | Yes|
| INT_VEC3 | GLenum | Yes|
| INT_VEC4 | GLenum | Yes|
| BOOL | GLenum | Yes|
| BOOL_VEC2 | GLenum | Yes|
| BOOL_VEC3 | GLenum | Yes|
| BOOL_VEC4 | GLenum | Yes|
| FLOAT_MAT2 | GLenum | Yes|
| FLOAT_MAT3 | GLenum | Yes|
| FLOAT_MAT4 | GLenum | Yes|
| SAMPLER_2D | GLenum | Yes|
| SAMPLER_CUBE | GLenum | Yes|
| VERTEX_ATTRIB_ARRAY_ENABLED | GLenum | Yes|
| VERTEX_ATTRIB_ARRAY_SIZE | GLenum | Yes|
| VERTEX_ATTRIB_ARRAY_STRIDE | GLenum | Yes|
| VERTEX_ATTRIB_ARRAY_TYPE | GLenum | Yes|
| VERTEX_ATTRIB_ARRAY_NORMALIZED | GLenum | Yes|
| VERTEX_ATTRIB_ARRAY_POINTER | GLenum | Yes|
| VERTEX_ATTRIB_ARRAY_BUFFER_BINDING | GLenum | Yes|
| IMPLEMENTATION_COLOR_READ_TYPE | GLenum | Yes|
| IMPLEMENTATION_COLOR_READ_FORMAT | GLenum | Yes|
| COMPILE_STATUS | GLenum | Yes|
| LOW_FLOAT | GLenum | Yes|
| MEDIUM_FLOAT | GLenum | Yes|
| HIGH_FLOAT | GLenum | Yes|
| LOW_INT | GLenum | Yes|
| MEDIUM_INT | GLenum | Yes|
| HIGH_INT | GLenum | Yes|
| FRAMEBUFFER | GLenum | Yes|
| RENDERBUFFER | GLenum | Yes|
| RGBA4 | GLenum | Yes|
| RGB5_A1 | GLenum | Yes|
| RGB565 | GLenum | Yes|
| DEPTH_COMPONENT16 | GLenum | Yes|
| STENCIL_INDEX8 | GLenum | Yes|
| DEPTH_STENCIL | GLenum | Yes|
| RENDERBUFFER_WIDTH | GLenum | Yes|
| RENDERBUFFER_HEIGHT | GLenum | Yes|
| RENDERBUFFER_INTERNAL_FORMAT | GLenum | Yes|
| RENDERBUFFER_RED_SIZE | GLenum | Yes|
| RENDERBUFFER_GREEN_SIZE | GLenum | Yes|
| RENDERBUFFER_BLUE_SIZE | GLenum | Yes|
| RENDERBUFFER_ALPHA_SIZE | GLenum | Yes|
| RENDERBUFFER_DEPTH_SIZE | GLenum | Yes|
| RENDERBUFFER_STENCIL_SIZE | GLenum | Yes|
| FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE | GLenum | Yes|
| FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL | GLenum | Yes|
| FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE | GLenum | Yes|
| COLOR_ATTACHMENT0 | GLenum | Yes|
| DEPTH_ATTACHMENT | GLenum | Yes|
| STENCIL_ATTACHMENT | GLenum | Yes|
| DEPTH_STENCIL_ATTACHMENT | GLenum | Yes|
| NONE | GLenum | Yes|
| FRAMEBUFFER_COMPLETE | GLenum | Yes|
| FRAMEBUFFER_INCOMPLETE_ATTACHMENT | GLenum | Yes|
| FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT | GLenum | Yes|
| FRAMEBUFFER_INCOMPLETE_DIMENSIONS | GLenum | Yes|
| FRAMEBUFFER_UNSUPPORTED | GLenum | Yes|
| FRAMEBUFFER_BINDING | GLenum | Yes|
| RENDERBUFFER_BINDING | GLenum | Yes|
| MAX_RENDERBUFFER_SIZE | GLenum | Yes|
| INVALID_FRAMEBUFFER_OPERATION | GLenum | Yes|
| UNPACK_FLIP_Y_WEBGL | GLenum | Yes|
| UNPACK_PREMULTIPLY_ALPHA_WEBGL | GLenum | Yes|
| CONTEXT_LOST_WEBGL | GLenum | Yes|
| UNPACK_COLORSPACE_CONVERSION_WEBGL | GLenum | Yes|
| BROWSER_DEFAULT_WEBGL | GLenum | Yes|
| canvas | HTMLCanvasElement&nbsp;\|&nbsp;OffscreenCanvas | Yes|
| drawingBufferWidth | GLsizei | Yes|
| drawingBufferHeight | GLsizei | Yes|


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
| createTexture() | WebGLTexture&nbsp;\|&nbsp;null |
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


## WebGLRenderingContextOverloads

WebGLRenderingContextOverloads

| Method| Return Value Type|
| -------- | -------- |
| bufferData(target:&nbsp;GLenum,&nbsp;size:&nbsp;GLsizeiptr,&nbsp;usage:&nbsp;GLenum) | void |
| bufferData(target:&nbsp;GLenum,&nbsp;data:&nbsp;BufferSource&nbsp;\|&nbsp;null,&nbsp;usage:&nbsp;GLenum) | void |
| bufferSubData(target:&nbsp;GLenum,&nbsp;offset:&nbsp;GLintptr,&nbsp;data:&nbsp;BufferSource) | void |
| compressedTexImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;internalformat:&nbsp;GLenum,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;border:&nbsp;GLint,&nbsp;data:&nbsp;ArrayBufferView) | void |
| compressedTexSubImage2D(target:&nbsp;GLenum,&nbsp;level:&nbsp;GLint,&nbsp;xoffset:&nbsp;GLint,&nbsp;yoffset:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;data:&nbsp;ArrayBufferView) | void |
| readPixels(x:&nbsp;GLint,&nbsp;y:&nbsp;GLint,&nbsp;width:&nbsp;GLsizei,&nbsp;height:&nbsp;GLsizei,&nbsp;format:&nbsp;GLenum,&nbsp;type:&nbsp;GLenum,&nbsp;pixels:&nbsp;ArrayBufferView&nbsp;\|&nbsp;null) | void; |
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
