# WebGL

The **WebGL** module provides the graphics drawing capability, such as processing the graphics position and color.

This module provides WebGL APIs that correspond to the OpenGL ES 2.0 feature set. For more information, see [WebGL™](https://www.khronos.org/registry/webgl/specs/latest/1.0/).

>  **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> WebGL complies with the OpenGL protocol and does not support multi-thread calling.
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


## APIs

**System capability**: SystemCapability.Graphic.Graphic2D.WebGL

**Table 2** APIs

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
| canvas | HTMLCanvasElement \| OffscreenCanvas | Yes| 
| drawingBufferWidth | GLsizei | Yes| 
| drawingBufferHeight | GLsizei | Yes| 


### Methods

  | Method| Return Value Type| 
| -------- | -------- |
| getContextAttributes() | WebGLContextAttributes \| null | 
| isContextLost() | boolean | 
| getSupportedExtensions() | string[] \| null | 
| getExtension(name: string) | any | 
| activeTexture(texture: GLenum) | void | 
| attachShader(program: WebGLProgram, shader: WebGLShader) | void | 
| bindAttribLocation(program: WebGLProgram, index: GLuint, name: string) | void | 
| bindBuffer(target: GLenum, buffer: WebGLBuffer \| null) | void | 
| bindFramebuffer(target: GLenum, framebuffer: WebGLFramebuffer \| null) | void | 
| bindRenderbuffer(target: GLenum, renderbuffer: WebGLRenderbuffer \| null) | void | 
| bindTexture(target: GLenum, texture: WebGLTexture \| null) | void | 
| blendColor(red: GLclampf, green: GLclampf, blue: GLclampf, alpha: GLclampf) | void | 
| blendEquation(mode: GLenum) | void | 
| blendEquationSeparate(modeRGB: GLenum, modeAlpha: GLenum) | void | 
| blendFunc(sfactor: GLenum, dfactor: GLenum) | void | 
| blendFuncSeparate(srcRGB: GLenum, dstRGB: GLenum, srcAlpha: GLenum, dstAlpha: GLenum) | void | 
| checkFramebufferStatus(target: GLenum) | GLenum | 
| clear(mask: GLbitfield) | void | 
| clearColor(red: GLclampf, green: GLclampf, blue: GLclampf, alpha: GLclampf) | void | 
| clearDepth(depth: GLclampf) | void | 
| clearStencil(s: GLint) | void | 
| colorMask(red: GLboolean, green: GLboolean, blue: GLboolean, alpha: GLboolean) | void | 
| compileShader(shader: WebGLShader) | void | 
| copyTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, x: GLint, y: GLint, width: GLsizei, height: GLsizei, border: GLint) | void | 
| copyTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, x: GLint, y: GLint, width: GLsizei, height: GLsizei) | void | 
| createBuffer() | WebGLBuffer \| null | 
| createFramebuffer() | WebGLFramebuffer \| null | 
| createProgram() | WebGLProgram \| null | 
| createRenderbuffer() | WebGLRenderbuffer \| null | 
| createShader(type: GLenum) | WebGLShader \| null | 
| createTexture() | WebGLTexture \| null | 
| cullFace(mode: GLenum) | void | 
| deleteBuffer(buffer: WebGLBuffer \| null) | void | 
| deleteFramebuffer(framebuffer: WebGLFramebuffer \| null) | void | 
| deleteProgram(program: WebGLProgram \| null) | void | 
| deleteRenderbuffer(renderbuffer: WebGLRenderbuffer \| null) | void | 
| deleteShader(shader: WebGLShader \| null) | void | 
| deleteTexture(texture: WebGLTexture \| null) | void | 
| depthFunc(func: GLenum) | void | 
| depthMask(flag: GLboolean) | void | 
| depthRange(zNear: GLclampf, zFar: GLclampf) | void | 
| detachShader(program: WebGLProgram, shader: WebGLShader) | void | 
| disable(cap: GLenum) | void | 
| disableVertexAttribArray(index: GLuint) | void | 
| drawArrays(mode: GLenum, first: GLint, count: GLsizei) | void | 
| drawElements(mode: GLenum, count: GLsizei, type: GLenum, offset: GLintptr) | void | 
| enable(cap: GLenum) | void | 
| enableVertexAttribArray(index: GLuint) | void | 
| finish() | void | 
| flush() | void | 
| framebufferRenderbuffer(target: GLenum, attachment: GLenum, renderbuffertarget: GLenum, renderbuffer: WebGLRenderbuffer \| null) | void | 
| framebufferTexture2D(target: GLenum, attachment: GLenum, textarget: GLenum, texture: WebGLTexture \| null, level: GLint) | void | 
| frontFace(mode: GLenum) | void | 
| generateMipmap(target: GLenum) | void | 
| getActiveAttrib(program: WebGLProgram, index: GLuint) | WebGLActiveInfo \| null | 
| getActiveUniform(program: WebGLProgram, index: GLuint) | WebGLActiveInfo \| null | 
| getAttachedShaders(program: WebGLProgram) | WebGLShader[] \| null | 
| getAttribLocation(program: WebGLProgram, name: string) | GLint | 
| getBufferParameter(target: GLenum, pname: GLenum) | any | 
| getParameter(pname: GLenum) | any | 
| getError() | GLenum | 
| getFramebufferAttachmentParameter(target: GLenum, attachment: GLenum, pname: GLenum) | any | 
| getProgramParameter(program: WebGLProgram, pname: GLenum) | any | 
| getProgramInfoLog(program: WebGLProgram) | string \| null | 
| getRenderbufferParameter(target: GLenum, pname: GLenum) | any | 
| getShaderParameter(shader: WebGLShader, pname: GLenum) | any | 
| getShaderPrecisionFormat(shadertype: GLenum, precisiontype: GLenum) | WebGLShaderPrecisionFormat \| null | 
| getShaderInfoLog(shader: WebGLShader) | string \| null | 
| getShaderSource(shader: WebGLShader) | string \| null | 
| getTexParameter(target: GLenum, pname: GLenum) | any | 
| getUniform(program: WebGLProgram, location: WebGLUniformLocation) | any | 
| getUniformLocation(program: WebGLProgram, name: string) | WebGLUniformLocation \| null | 
| getVertexAttrib(index: GLuint, pname: GLenum) | any | 
| getVertexAttribOffset(index: GLuint, pname: GLenum) | GLintptr | 
| hint(target: GLenum, mode: GLenum) | void | 
| isBuffer(buffer: WebGLBuffer \| null) | GLboolean | 
| isEnabled(cap: GLenum) | GLboolean | 
| isFramebuffer(framebuffer: WebGLFramebuffer \| null) | GLboolean | 
| isProgram(program: WebGLProgram \| null) | GLboolean | 
| isRenderbuffer(renderbuffer: WebGLRenderbuffer \| null) | GLboolean | 
| isShader(shader: WebGLShader \| null) | GLboolean | 
| isTexture(texture: WebGLTexture \| null) | GLboolean | 
| lineWidth(width: GLfloat) | void | 
| linkProgram(program: WebGLProgram) | void | 
| pixelStorei(pname: GLenum, param: GLint \| GLboolean) | void | 
| polygonOffset(factor: GLfloat, units: GLfloat) | void | 
| renderbufferStorage(target: GLenum, internalformat: GLenum, width: GLsizei, height: GLsizei) | void | 
| sampleCoverage(value: GLclampf, invert: GLboolean) | void | 
| scissor(x: GLint, y: GLint, width: GLsizei, height: GLsizei) | void | 
| shaderSource(shader: WebGLShader, source: string) | void | 
| stencilFunc(func: GLenum, ref: GLint, mask: GLuint) | void | 
| stencilFuncSeparate(face: GLenum, func: GLenum, ref: GLint, mask: GLuint) | void | 
| stencilMask(mask: GLuint) | void | 
| stencilMaskSeparate(face: GLenum, mask: GLuint) | void | 
| stencilOp(fail: GLenum, zfail: GLenum, zpass: GLenum) | void | 
| stencilOpSeparate(face: GLenum, fail: GLenum, zfail: GLenum, zpass: GLenum) | void | 
| texParameterf(target: GLenum, pname: GLenum, param: GLfloat) | void | 
| texParameteri(target: GLenum, pname: GLenum, param: GLint) | void | 
| uniform1f(location: WebGLUniformLocation \| null, x: GLfloat) | void | 
| uniform2f(location: WebGLUniformLocation \| null, x: GLfloat, y: GLfloat) | void | 
| uniform3f(location: WebGLUniformLocation \| null, x: GLfloat, y: GLfloat, z: GLfloat) | void | 
| uniform4f(location: WebGLUniformLocation \| null, x: GLfloat, y: GLfloat, z: GLfloat, w: GLfloat) | void | 
| uniform1i(location: WebGLUniformLocation \| null, x: GLint) | void | 
| uniform2i(location: WebGLUniformLocation \| null, x: GLint, y: GLint) | void | 
| uniform3i(location: WebGLUniformLocation \| null, x: GLint, y: GLint, z: GLint) | void | 
| uniform4i(location: WebGLUniformLocation \| null, x: GLint, y: GLint, z: GLint, w: GLint) | void | 
| useProgram(program: WebGLProgram \| null) | void | 
| validateProgram(program: WebGLProgram) | void | 
| vertexAttrib1f(index: GLuint, x: GLfloat) | void | 
| vertexAttrib2f(index: GLuint, x: GLfloat, y: GLfloat) | void | 
| vertexAttrib3f(index: GLuint, x: GLfloat, y: GLfloat, z: GLfloat) | void | 
| vertexAttrib4f(index: GLuint, x: GLfloat, y: GLfloat, z: GLfloat, w: GLfloat) | void | 
| vertexAttrib1fv(index: GLuint, values: Float32List) | void | 
| vertexAttrib2fv(index: GLuint, values: Float32List) | void | 
| vertexAttrib3fv(index: GLuint, values: Float32List) | void | 
| vertexAttrib4fv(index: GLuint, values: Float32List) | void | 
| vertexAttribPointer(index: GLuint, size: GLint, type: GLenum, normalized: GLboolean, stride: GLsizei, offset: GLintptr) | void | 
| viewport(x: GLint, y: GLint, width: GLsizei, height: GLsizei) | void | 


## WebGLRenderingContextOverloads

WebGLRenderingContextOverloads

  | Method| Return Value Type| 
| -------- | -------- |
| bufferData(target: GLenum, size: GLsizeiptr, usage: GLenum) | void | 
| bufferData(target: GLenum, data: BufferSource \| null, usage: GLenum) | void | 
| bufferSubData(target: GLenum, offset: GLintptr, data: BufferSource) | void | 
| compressedTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, border: GLint, data: ArrayBufferView) | void | 
| compressedTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, data: ArrayBufferView) | void | 
| readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null) | void | 
| texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null) | void | 
| texImage2D(target: GLenum, level: GLint, internalformat: GLint, format: GLenum, type: GLenum, source: TexImageSource) | void | 
| texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null) | void | 
| texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, format: GLenum, type: GLenum, source: TexImageSource) | void | 
| uniform1fv(location: WebGLUniformLocation \| null, v: Float32List) | void | 
| uniform2fv(location: WebGLUniformLocation \| null, v: Float32List) | void | 
| uniform3fv(location: WebGLUniformLocation \| null, v: Float32List) | void | 
| uniform4fv(location: WebGLUniformLocation \| null, v: Float32List) | void | 
| uniform1iv(location: WebGLUniformLocation \| null, v: Int32List) | void | 
| uniform2iv(location: WebGLUniformLocation \| null, v: Int32List) | void | 
| uniform3iv(location: WebGLUniformLocation \| null, v: Int32List) | void | 
| uniform4iv(location: WebGLUniformLocation \| null, v: Int32List) | void | 
| uniformMatrix2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, value: Float32List) | void | 
| uniformMatrix3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, value: Float32List) | void | 
| uniformMatrix4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, value: Float32List) | void | 
