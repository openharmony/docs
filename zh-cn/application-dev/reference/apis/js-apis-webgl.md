# WebGL

WebGL提供图形绘制的能力，包括对当前绘制图形的位置、颜色等进行处理。

WebGL标准图形API，对应OpenGL ES 2.0特性集。更多信息请参考[WebGL™标准](https://www.khronos.org/registry/webgl/specs/latest/1.0/)。

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
| canvas | HTMLCanvasElement&nbsp;\|&nbsp;OffscreenCanvas | 是 | 
| drawingBufferWidth | GLsizei | 是 | 
| drawingBufferHeight | GLsizei | 是 | 


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

  | 方法 | 返回值类型 | 
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
