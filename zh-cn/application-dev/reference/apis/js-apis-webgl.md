# WebGL

WebGL提供图形绘制的能力，包括对当前绘制图形的位置、颜色等进行处理。

WebGL标准图形API，对应OpenGL ES 2.0特性集。更多信息请参考[WebGL™标准](https://www.khronos.org/registry/webgl/specs/latest/1.0/)。

>  **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> WebGL遵循OpenGL协议，不支持多线程调用。
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
const gl = el.getContext('webgl');
// 调用WebGL API
gl.clearColor(0.0, 0.0, 0.0, 1.0);
```


## Type

**系统能力：** 以下各项对应的系统能力均为 SystemCapability.Graphic.Graphic2D.WebGL。

  **表1** Type

| 名称 | 类型 | 
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

**系统能力：** 以下各项对应的系统能力均为 SystemCapability.Graphic.Graphic2D.WebGL。

  **表2** Interface

| 名称 |
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


  | 名称 | 参数类型 | 必填 | 
| -------- | -------- | -------- |
| alpha | boolean | 否 | 
| depth | boolean | 否 | 
| stencil | boolean | 否 | 
| antialias | boolean | 否 | 
| premultipliedAlpha | boolean | 否 | 
| preserveDrawingBuffer | boolean | 否 | 
| powerPreference | WebGLPowerPreference | 否 | 
| failIfMajorPerformanceCaveat | boolean | 否 | 
| desynchronized | boolean | 否 | 


## WebGLActiveInfo

WebGLActiveInfo

  | 名称 | 参数类型 | 必填 | 
| -------- | -------- | -------- |
| size | GLint | 是 | 
| type | GLenum | 是 | 
| name | string | 是 | 


## WebGLShaderPrecisionFormat

WebGLShaderPrecisionFormat

  | 名称 | 参数类型 | 必填 | 
| -------- | -------- | -------- |
| rangeMin | GLint | 是 | 
| rangeMax | GLint | 是 | 
| precision | GLint | 是 | 


## WebGLRenderingContextBase

WebGLRenderingContextBase


### 属性

  | 名称 | 参数类型 | 必填 | 
| -------- | -------- | -------- |
| DEPTH_BUFFER_BIT | GLenum | 是 | 
| STENCIL_BUFFER_BIT | GLenum | 是 | 
| COLOR_BUFFER_BIT | GLenum | 是 | 
| POINTS | GLenum | 是 | 
| LINES | GLenum | 是 | 
| LINE_LOOP | GLenum | 是 | 
| LINE_STRIP | GLenum | 是 | 
| TRIANGLES | GLenum | 是 | 
| TRIANGLE_STRIP | GLenum | 是 | 
| TRIANGLE_FAN | GLenum | 是 | 
| ZERO | GLenum | 是 | 
| ONE | GLenum | 是 | 
| SRC_COLOR | GLenum | 是 | 
| ONE_MINUS_SRC_COLOR | GLenum | 是 | 
| SRC_ALPHA | GLenum | 是 | 
| ONE_MINUS_SRC_ALPHA | GLenum | 是 | 
| DST_ALPHA | GLenum | 是 | 
| ONE_MINUS_DST_ALPHA | GLenum | 是 | 
| DST_COLOR | GLenum | 是 | 
| ONE_MINUS_DST_COLOR | GLenum | 是 | 
| SRC_ALPHA_SATURATE | GLenum | 是 | 
| FUNC_ADD | GLenum | 是 | 
| BLEND_EQUATION | GLenum | 是 | 
| BLEND_EQUATION_RGB | GLenum | 是 | 
| BLEND_EQUATION_ALPHA | GLenum | 是 | 
| FUNC_SUBTRACT | GLenum | 是 | 
| FUNC_REVERSE_SUBTRACT | GLenum | 是 | 
| BLEND_DST_RGB | GLenum | 是 | 
| BLEND_SRC_RGB | GLenum | 是 | 
| BLEND_DST_ALPHA | GLenum | 是 | 
| BLEND_SRC_ALPHA | GLenum | 是 | 
| CONSTANT_COLOR | GLenum | 是 | 
| ONE_MINUS_CONSTANT_COLOR | GLenum | 是 | 
| CONSTANT_ALPHA | GLenum | 是 | 
| ONE_MINUS_CONSTANT_ALPHA | GLenum | 是 | 
| BLEND_COLOR | GLenum | 是 | 
| ARRAY_BUFFER | GLenum | 是 | 
| ELEMENT_ARRAY_BUFFER | GLenum | 是 | 
| ARRAY_BUFFER_BINDING | GLenum | 是 | 
| ELEMENT_ARRAY_BUFFER_BINDING | GLenum | 是 | 
| STREAM_DRAW | GLenum | 是 | 
| STATIC_DRAW | GLenum | 是 | 
| DYNAMIC_DRAW | GLenum | 是 | 
| BUFFER_SIZE | GLenum | 是 | 
| BUFFER_USAGE | GLenum | 是 | 
| CURRENT_VERTEX_ATTRIB | GLenum | 是 | 
| FRONT | GLenum | 是 | 
| BACK | GLenum | 是 | 
| FRONT_AND_BACK | GLenum | 是 | 
| CULL_FACE | GLenum | 是 | 
| BLEND | GLenum | 是 | 
| DITHER | GLenum | 是 | 
| STENCIL_TEST | GLenum | 是 | 
| DEPTH_TEST | GLenum | 是 | 
| SCISSOR_TEST | GLenum | 是 | 
| POLYGON_OFFSET_FILL | GLenum | 是 | 
| SAMPLE_ALPHA_TO_COVERAGE | GLenum | 是 | 
| SAMPLE_COVERAGE | GLenum | 是 | 
| NO_ERROR | GLenum | 是 | 
| INVALID_ENUM | GLenum | 是 | 
| INVALID_VALUE | GLenum | 是 | 
| INVALID_OPERATION | GLenum | 是 | 
| OUT_OF_MEMORY | GLenum | 是 | 
| CW | GLenum | 是 | 
| CCW | GLenum | 是 | 
| LINE_WIDTH | GLenum | 是 | 
| ALIASED_POINT_SIZE_RANGE | GLenum | 是 | 
| ALIASED_LINE_WIDTH_RANGE | GLenum | 是 | 
| CULL_FACE_MODE | GLenum | 是 | 
| FRONT_FACE | GLenum | 是 | 
| DEPTH_RANGE | GLenum | 是 | 
| DEPTH_WRITEMASK | GLenum | 是 | 
| DEPTH_CLEAR_VALUE | GLenum | 是 | 
| DEPTH_FUNC | GLenum | 是 | 
| STENCIL_CLEAR_VALUE | GLenum | 是 | 
| STENCIL_FUNC | GLenum | 是 | 
| STENCIL_FAIL | GLenum | 是 | 
| STENCIL_PASS_DEPTH_FAIL | GLenum | 是 | 
| STENCIL_PASS_DEPTH_PASS | GLenum | 是 | 
| STENCIL_REF | GLenum | 是 | 
| STENCIL_VALUE_MASK | GLenum | 是 | 
| STENCIL_WRITEMASK | GLenum | 是 | 
| STENCIL_BACK_FUNC | GLenum | 是 | 
| STENCIL_BACK_FAIL | GLenum | 是 | 
| STENCIL_BACK_PASS_DEPTH_FAIL | GLenum | 是 | 
| STENCIL_BACK_PASS_DEPTH_PASS | GLenum | 是 | 
| STENCIL_BACK_REF | GLenum | 是 | 
| STENCIL_BACK_VALUE_MASK | GLenum | 是 | 
| STENCIL_BACK_WRITEMASK | GLenum | 是 | 
| VIEWPORT | GLenum | 是 | 
| SCISSOR_BOX | GLenum | 是 | 
| COLOR_CLEAR_VALUE | GLenum | 是 | 
| COLOR_WRITEMASK | GLenum | 是 | 
| UNPACK_ALIGNMENT | GLenum | 是 | 
| PACK_ALIGNMENT | GLenum | 是 | 
| MAX_TEXTURE_SIZE | GLenum | 是 | 
| MAX_VIEWPORT_DIMS | GLenum | 是 | 
| SUBPIXEL_BITS | GLenum | 是 | 
| RED_BITS | GLenum | 是 | 
| GREEN_BITS | GLenum | 是 | 
| BLUE_BITS | GLenum | 是 | 
| ALPHA_BITS | GLenum | 是 | 
| DEPTH_BITS | GLenum | 是 | 
| STENCIL_BITS | GLenum | 是 | 
| POLYGON_OFFSET_UNITS | GLenum | 是 | 
| POLYGON_OFFSET_FACTOR | GLenum | 是 | 
| TEXTURE_BINDING_2D | GLenum | 是 | 
| SAMPLE_BUFFERS | GLenum | 是 | 
| SAMPLES | GLenum | 是 | 
| SAMPLE_COVERAGE_VALUE | GLenum | 是 | 
| SAMPLE_COVERAGE_INVERT | GLenum | 是 | 
| COMPRESSED_TEXTURE_FORMATS | GLenum | 是 | 
| DONT_CARE | GLenum | 是 | 
| FASTEST | GLenum | 是 | 
| NICEST | GLenum | 是 | 
| GENERATE_MIPMAP_HINT | GLenum | 是 | 
| BYTE | GLenum | 是 | 
| UNSIGNED_BYTE | GLenum | 是 | 
| SHORT | GLenum | 是 | 
| UNSIGNED_SHORT | GLenum | 是 | 
| INT | GLenum | 是 | 
| UNSIGNED_INT | GLenum | 是 | 
| FLOAT | GLenum | 是 | 
| DEPTH_COMPONENT | GLenum | 是 | 
| ALPHA | GLenum | 是 | 
| RGB | GLenum | 是 | 
| RGBA | GLenum | 是 | 
| LUMINANCE | GLenum | 是 | 
| LUMINANCE_ALPHA | GLenum | 是 | 
| UNSIGNED_SHORT_4_4_4_4 | GLenum | 是 | 
| UNSIGNED_SHORT_5_5_5_1 | GLenum | 是 | 
| UNSIGNED_SHORT_5_6_5 | GLenum | 是 | 
| FRAGMENT_SHADER | GLenum | 是 | 
| VERTEX_SHADER | GLenum | 是 | 
| MAX_VERTEX_ATTRIBS | GLenum | 是 | 
| MAX_VERTEX_UNIFORM_VECTORS | GLenum | 是 | 
| MAX_VARYING_VECTORS | GLenum | 是 | 
| MAX_COMBINED_TEXTURE_IMAGE_UNITS | GLenum | 是 | 
| MAX_VERTEX_TEXTURE_IMAGE_UNITS | GLenum | 是 | 
| MAX_TEXTURE_IMAGE_UNITS | GLenum | 是 | 
| MAX_FRAGMENT_UNIFORM_VECTORS | GLenum | 是 | 
| SHADER_TYPE | GLenum | 是 | 
| DELETE_STATUS | GLenum | 是 | 
| LINK_STATUS | GLenum | 是 | 
| VALIDATE_STATUS | GLenum | 是 | 
| ATTACHED_SHADERS | GLenum | 是 | 
| ACTIVE_UNIFORMS | GLenum | 是 | 
| ACTIVE_ATTRIBUTES | GLenum | 是 | 
| SHADING_LANGUAGE_VERSION | GLenum | 是 | 
| CURRENT_PROGRAM | GLenum | 是 | 
| NEVER | GLenum | 是 | 
| LESS | GLenum | 是 | 
| EQUAL | GLenum | 是 | 
| LEQUAL | GLenum | 是 | 
| GREATER | GLenum | 是 | 
| NOTEQUAL | GLenum | 是 | 
| GEQUAL | GLenum | 是 | 
| ALWAYS | GLenum | 是 | 
| KEEP | GLenum | 是 | 
| REPLACE | GLenum | 是 | 
| INCR | GLenum | 是 | 
| DECR | GLenum | 是 | 
| INVERT | GLenum | 是 | 
| INCR_WRAP | GLenum | 是 | 
| DECR_WRAP | GLenum | 是 | 
| VENDOR | GLenum | 是 | 
| RENDERER | GLenum | 是 | 
| VERSION | GLenum | 是 | 
| NEAREST | GLenum | 是 | 
| LINEAR | GLenum | 是 | 
| NEAREST_MIPMAP_NEAREST | GLenum | 是 | 
| LINEAR_MIPMAP_NEAREST | GLenum | 是 | 
| NEAREST_MIPMAP_LINEAR | GLenum | 是 | 
| LINEAR_MIPMAP_LINEAR | GLenum | 是 | 
| TEXTURE_MIN_FILTER | GLenum | 是 | 
| TEXTURE_WRAP_S | GLenum | 是 | 
| TEXTURE_WRAP_T | GLenum | 是 | 
| TEXTURE_2D | GLenum | 是 | 
| TEXTURE | GLenum | 是 | 
| TEXTURE_CUBE_MAP | GLenum | 是 | 
| TEXTURE_BINDING_CUBE_MAP | GLenum | 是 | 
| TEXTURE_CUBE_MAP_POSITIVE_X | GLenum | 是 | 
| TEXTURE_CUBE_MAP_NEGATIVE_X | GLenum | 是 | 
| TEXTURE_CUBE_MAP_POSITIVE_Y | GLenum | 是 | 
| TEXTURE_CUBE_MAP_NEGATIVE_Y | GLenum | 是 | 
| TEXTURE_CUBE_MAP_POSITIVE_Z | GLenum | 是 | 
| TEXTURE_CUBE_MAP_NEGATIVE_Z | GLenum | 是 | 
| MAX_CUBE_MAP_TEXTURE_SIZE | GLenum | 是 | 
| TEXTURE0 | GLenum | 是 | 
| TEXTURE1 | GLenum | 是 | 
| TEXTURE2 | GLenum | 是 | 
| TEXTURE3 | GLenum | 是 | 
| TEXTURE4 | GLenum | 是 | 
| TEXTURE5 | GLenum | 是 | 
| TEXTURE6 | GLenum | 是 | 
| TEXTURE7 | GLenum | 是 | 
| TEXTURE8 | GLenum | 是 | 
| TEXTURE9 | GLenum | 是 | 
| TEXTURE10 | GLenum | 是 | 
| TEXTURE11 | GLenum | 是 | 
| TEXTURE12 | GLenum | 是 | 
| TEXTURE13 | GLenum | 是 | 
| TEXTURE14 | GLenum | 是 | 
| TEXTURE15 | GLenum | 是 | 
| TEXTURE16 | GLenum | 是 | 
| TEXTURE17 | GLenum | 是 | 
| TEXTURE18 | GLenum | 是 | 
| TEXTURE19 | GLenum | 是 | 
| TEXTURE20 | GLenum | 是 | 
| TEXTURE21 | GLenum | 是 | 
| TEXTURE22 | GLenum | 是 | 
| TEXTURE23 | GLenum | 是 | 
| TEXTURE24 | GLenum | 是 | 
| TEXTURE25 | GLenum | 是 | 
| TEXTURE26 | GLenum | 是 | 
| TEXTURE27 | GLenum | 是 | 
| TEXTURE28 | GLenum | 是 | 
| TEXTURE29 | GLenum | 是 | 
| TEXTURE30 | GLenum | 是 | 
| TEXTURE31 | GLenum | 是 | 
| ACTIVE_TEXTURE | GLenum | 是 | 
| REPEAT | GLenum | 是 | 
| CLAMP_TO_EDGE | GLenum | 是 | 
| MIRRORED_REPEAT | GLenum | 是 | 
| FLOAT_VEC2 | GLenum | 是 | 
| FLOAT_VEC3 | GLenum | 是 | 
| FLOAT_VEC4 | GLenum | 是 | 
| INT_VEC2 | GLenum | 是 | 
| INT_VEC3 | GLenum | 是 | 
| INT_VEC4 | GLenum | 是 | 
| BOOL | GLenum | 是 | 
| BOOL_VEC2 | GLenum | 是 | 
| BOOL_VEC3 | GLenum | 是 | 
| BOOL_VEC4 | GLenum | 是 | 
| FLOAT_MAT2 | GLenum | 是 | 
| FLOAT_MAT3 | GLenum | 是 | 
| FLOAT_MAT4 | GLenum | 是 | 
| SAMPLER_2D | GLenum | 是 | 
| SAMPLER_CUBE | GLenum | 是 | 
| VERTEX_ATTRIB_ARRAY_ENABLED | GLenum | 是 | 
| VERTEX_ATTRIB_ARRAY_SIZE | GLenum | 是 | 
| VERTEX_ATTRIB_ARRAY_STRIDE | GLenum | 是 | 
| VERTEX_ATTRIB_ARRAY_TYPE | GLenum | 是 | 
| VERTEX_ATTRIB_ARRAY_NORMALIZED | GLenum | 是 | 
| VERTEX_ATTRIB_ARRAY_POINTER | GLenum | 是 | 
| VERTEX_ATTRIB_ARRAY_BUFFER_BINDING | GLenum | 是 | 
| IMPLEMENTATION_COLOR_READ_TYPE | GLenum | 是 | 
| IMPLEMENTATION_COLOR_READ_FORMAT | GLenum | 是 | 
| COMPILE_STATUS | GLenum | 是 | 
| LOW_FLOAT | GLenum | 是 | 
| MEDIUM_FLOAT | GLenum | 是 | 
| HIGH_FLOAT | GLenum | 是 | 
| LOW_INT | GLenum | 是 | 
| MEDIUM_INT | GLenum | 是 | 
| HIGH_INT | GLenum | 是 | 
| FRAMEBUFFER | GLenum | 是 | 
| RENDERBUFFER | GLenum | 是 | 
| RGBA4 | GLenum | 是 | 
| RGB5_A1 | GLenum | 是 | 
| RGB565 | GLenum | 是 | 
| DEPTH_COMPONENT16 | GLenum | 是 | 
| STENCIL_INDEX8 | GLenum | 是 | 
| DEPTH_STENCIL | GLenum | 是 | 
| RENDERBUFFER_WIDTH | GLenum | 是 | 
| RENDERBUFFER_HEIGHT | GLenum | 是 | 
| RENDERBUFFER_INTERNAL_FORMAT | GLenum | 是 | 
| RENDERBUFFER_RED_SIZE | GLenum | 是 | 
| RENDERBUFFER_GREEN_SIZE | GLenum | 是 | 
| RENDERBUFFER_BLUE_SIZE | GLenum | 是 | 
| RENDERBUFFER_ALPHA_SIZE | GLenum | 是 | 
| RENDERBUFFER_DEPTH_SIZE | GLenum | 是 | 
| RENDERBUFFER_STENCIL_SIZE | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL | GLenum | 是 | 
| FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE | GLenum | 是 | 
| COLOR_ATTACHMENT0 | GLenum | 是 | 
| DEPTH_ATTACHMENT | GLenum | 是 | 
| STENCIL_ATTACHMENT | GLenum | 是 | 
| DEPTH_STENCIL_ATTACHMENT | GLenum | 是 | 
| NONE | GLenum | 是 | 
| FRAMEBUFFER_COMPLETE | GLenum | 是 | 
| FRAMEBUFFER_INCOMPLETE_ATTACHMENT | GLenum | 是 | 
| FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT | GLenum | 是 | 
| FRAMEBUFFER_INCOMPLETE_DIMENSIONS | GLenum | 是 | 
| FRAMEBUFFER_UNSUPPORTED | GLenum | 是 | 
| FRAMEBUFFER_BINDING | GLenum | 是 | 
| RENDERBUFFER_BINDING | GLenum | 是 | 
| MAX_RENDERBUFFER_SIZE | GLenum | 是 | 
| INVALID_FRAMEBUFFER_OPERATION | GLenum | 是 | 
| UNPACK_FLIP_Y_WEBGL | GLenum | 是 | 
| UNPACK_PREMULTIPLY_ALPHA_WEBGL | GLenum | 是 | 
| CONTEXT_LOST_WEBGL | GLenum | 是 | 
| UNPACK_COLORSPACE_CONVERSION_WEBGL | GLenum | 是 | 
| BROWSER_DEFAULT_WEBGL | GLenum | 是 | 
| canvas | HTMLCanvasElement \| OffscreenCanvas | 是 | 
| drawingBufferWidth | GLsizei | 是 | 
| drawingBufferHeight | GLsizei | 是 | 


### 方法

  | 方法 | 返回值类型 | 
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

  | 方法 | 返回值类型 | 
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
