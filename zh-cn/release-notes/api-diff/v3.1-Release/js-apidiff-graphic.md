# 图形图像子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，图形图像子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| webgl2 | WebGL2RenderingContextOverloads | readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, dstData: ArrayBufferView \| null): void;<br>readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, offset: GLintptr): void;<br>readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, dstData: ArrayBufferView, dstOffset: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | uniformMatrix4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | uniformMatrix3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | uniformMatrix2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | uniform4iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | uniform3iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | uniform2iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | uniform1iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | uniform4fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | uniform3fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | uniform2fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | uniform1fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | compressedTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, imageSize: GLsizei, offset: GLintptr): void;<br>compressedTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | compressedTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, border: GLint, imageSize: GLsizei, offset: GLintptr): void;<br>compressedTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, border: GLint, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null): void;<br>texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pboOffset: GLintptr): void;<br>texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, srcData: ArrayBufferView, srcOffset: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null): void;<br>texImage2D(target: GLenum, level: GLint, internalformat: GLint, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, pboOffset: GLintptr): void;<br>texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, srcData: ArrayBufferView, srcOffset: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | bufferSubData(target: GLenum, dstByteOffset: GLintptr, srcData: BufferSource): void;<br>bufferSubData(target: GLenum, dstByteOffset: GLintptr, srcData: ArrayBufferView, srcOffset: GLuint, length?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextOverloads | bufferData(target: GLenum, size: GLsizeiptr, usage: GLenum): void;<br>bufferData(target: GLenum, srcData: BufferSource \| null, usage: GLenum): void;<br>bufferData(target: GLenum, srcData: ArrayBufferView, usage: GLenum, srcOffset: GLuint, length?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | bindVertexArray(array: WebGLVertexArrayObject \| null): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | isVertexArray(vertexArray: WebGLVertexArrayObject \| null): GLboolean; | 新增 |
| webgl2 | WebGL2RenderingContextBase | deleteVertexArray(vertexArray: WebGLVertexArrayObject \| null): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | createVertexArray(): WebGLVertexArrayObject \| null; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniformBlockBinding(program: WebGLProgram, uniformBlockIndex: GLuint, uniformBlockBinding: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getActiveUniformBlockName(program: WebGLProgram, uniformBlockIndex: GLuint): string \| null; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getActiveUniformBlockParameter(program: WebGLProgram, uniformBlockIndex: GLuint, pname: GLenum): any; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getUniformBlockIndex(program: WebGLProgram, uniformBlockName: string): GLuint; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getActiveUniforms(program: WebGLProgram, uniformIndices: GLuint[], pname: GLenum): any; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getUniformIndices(program: WebGLProgram, uniformNames: string[]): GLuint[] \| null; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getIndexedParameter(target: GLenum, index: GLuint): any; | 新增 |
| webgl2 | WebGL2RenderingContextBase | bindBufferRange(target: GLenum, index: GLuint, buffer: WebGLBuffer \| null, offset: GLintptr, size: GLsizeiptr): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | bindBufferBase(target: GLenum, index: GLuint, buffer: WebGLBuffer \| null): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | resumeTransformFeedback(): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | pauseTransformFeedback(): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getTransformFeedbackVarying(program: WebGLProgram, index: GLuint): WebGLActiveInfo \| null; | 新增 |
| webgl2 | WebGL2RenderingContextBase | transformFeedbackVaryings(program: WebGLProgram, varyings: string[], bufferMode: GLenum): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | endTransformFeedback(): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | beginTransformFeedback(primitiveMode: GLenum): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | bindTransformFeedback(target: GLenum, tf: WebGLTransformFeedback \| null): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | isTransformFeedback(tf: WebGLTransformFeedback \| null): GLboolean; | 新增 |
| webgl2 | WebGL2RenderingContextBase | deleteTransformFeedback(tf: WebGLTransformFeedback \| null): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | createTransformFeedback(): WebGLTransformFeedback \| null; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getSyncParameter(sync: WebGLSync, pname: GLenum): any; | 新增 |
| webgl2 | WebGL2RenderingContextBase | waitSync(sync: WebGLSync, flags: GLbitfield, timeout: GLint64): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | clientWaitSync(sync: WebGLSync, flags: GLbitfield, timeout: GLuint64): GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | deleteSync(sync: WebGLSync \| null): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | isSync(sync: WebGLSync \| null): GLboolean; | 新增 |
| webgl2 | WebGL2RenderingContextBase | fenceSync(condition: GLenum, flags: GLbitfield): WebGLSync \| null; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getSamplerParameter(sampler: WebGLSampler, pname: GLenum): any; | 新增 |
| webgl2 | WebGL2RenderingContextBase | samplerParameterf(sampler: WebGLSampler, pname: GLenum, param: GLfloat): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | samplerParameteri(sampler: WebGLSampler, pname: GLenum, param: GLint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | bindSampler(unit: GLuint, sampler: WebGLSampler \| null): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | isSampler(sampler: WebGLSampler \| null): GLboolean; | 新增 |
| webgl2 | WebGL2RenderingContextBase | deleteSampler(sampler: WebGLSampler \| null): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | createSampler(): WebGLSampler \| null; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getQueryParameter(query: WebGLQuery, pname: GLenum): any; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getQuery(target: GLenum, pname: GLenum): WebGLQuery \| null; | 新增 |
| webgl2 | WebGL2RenderingContextBase | endQuery(target: GLenum): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | beginQuery(target: GLenum, query: WebGLQuery): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | isQuery(query: WebGLQuery \| null): GLboolean; | 新增 |
| webgl2 | WebGL2RenderingContextBase | deleteQuery(query: WebGLQuery \| null): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | createQuery(): WebGLQuery \| null; | 新增 |
| webgl2 | WebGL2RenderingContextBase | clearBufferfi(buffer: GLenum, drawbuffer: GLint, depth: GLfloat, stencil: GLint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | clearBufferuiv(buffer: GLenum, drawbuffer: GLint, values: Uint32List, srcOffset?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | clearBufferiv(buffer: GLenum, drawbuffer: GLint, values: Int32List, srcOffset?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | clearBufferfv(buffer: GLenum, drawbuffer: GLint, values: Float32List, srcOffset?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | drawBuffers(buffers: GLenum[]): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | drawRangeElements(mode: GLenum, start: GLuint, end: GLuint, count: GLsizei, type: GLenum, offset: GLintptr): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | drawElementsInstanced(mode: GLenum, count: GLsizei, type: GLenum, offset: GLintptr, instanceCount: GLsizei): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | drawArraysInstanced(mode: GLenum, first: GLint, count: GLsizei, instanceCount: GLsizei): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | vertexAttribDivisor(index: GLuint, divisor: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | vertexAttribIPointer(index: GLuint, size: GLint, type: GLenum, stride: GLsizei, offset: GLintptr): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | vertexAttribI4uiv(index: GLuint, values: Uint32List): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | vertexAttribI4ui(index: GLuint, x: GLuint, y: GLuint, z: GLuint, w: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | vertexAttribI4iv(index: GLuint, values: Int32List): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | vertexAttribI4i(index: GLuint, x: GLint, y: GLint, z: GLint, w: GLint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniformMatrix3x4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniformMatrix2x4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniformMatrix4x3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniformMatrix2x3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniformMatrix4x2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniformMatrix3x2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniform4uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniform3uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniform2uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniform1uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniform4ui(location: WebGLUniformLocation \| null, v0: GLuint, v1: GLuint, v2: GLuint, v3: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniform3ui(location: WebGLUniformLocation \| null, v0: GLuint, v1: GLuint, v2: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniform2ui(location: WebGLUniformLocation \| null, v0: GLuint, v1: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | uniform1ui(location: WebGLUniformLocation \| null, v0: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getFragDataLocation(program: WebGLProgram, name: string): GLint; | 新增 |
| webgl2 | WebGL2RenderingContextBase | compressedTexSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, imageSize: GLsizei, offset: GLintptr): void;<br>compressedTexSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | compressedTexImage3D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, imageSize: GLsizei, offset: GLintptr): void;<br>compressedTexImage3D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | copyTexSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, x: GLint, y: GLint, width: GLsizei, height: GLsizei): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | texSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, type: GLenum, pboOffset: GLintptr): void;<br>texSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, type: GLenum, srcData: ArrayBufferView \| null, srcOffset?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, pboOffset: GLintptr): void;<br>texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, srcData: ArrayBufferView \| null): void;<br>texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, srcData: ArrayBufferView, srcOffset: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | texStorage3D(target: GLenum, levels: GLsizei, internalformat: GLenum, width: GLsizei, height: GLsizei, depth: GLsizei): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | texStorage2D(target: GLenum, levels: GLsizei, internalformat: GLenum, width: GLsizei, height: GLsizei): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | renderbufferStorageMultisample(target: GLenum, samples: GLsizei, internalformat: GLenum, width: GLsizei, height: GLsizei): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getInternalformatParameter(target: GLenum, internalformat: GLenum, pname: GLenum): any; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readBuffer(src: GLenum): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | invalidateSubFramebuffer(target: GLenum, attachments: GLenum[], x: GLint, y: GLint, width: GLsizei, height: GLsizei): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | invalidateFramebuffer(target: GLenum, attachments: GLenum[]): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | framebufferTextureLayer(target: GLenum, attachment: GLenum, texture: WebGLTexture \| null, level: GLint, layer: GLint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | blitFramebuffer(srcX0: GLint, srcY0: GLint, srcX1: GLint, srcY1: GLint, dstX0: GLint, dstY0: GLint, dstX1: GLint, dstY1: GLint, mask: GLbitfield, filter: GLenum): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | getBufferSubData(target: GLenum, srcByteOffset: GLintptr, dstBuffer: ArrayBufferView, dstOffset?: GLuint, length?: GLuint): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | copyBufferSubData(readTarget: GLenum, writeTarget: GLenum, readOffset: GLintptr, writeOffset: GLintptr, size: GLsizeiptr): void; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_CLIENT_WAIT_TIMEOUT_WEBGL: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TIMEOUT_IGNORED: GLint64; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_IMMUTABLE_LEVELS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_ELEMENT_INDEX: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_IMMUTABLE_FORMAT: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_ACTIVE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_PAUSED: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly INT_2_10_10_10_REV: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB10_A2UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly ANY_SAMPLES_PASSED_CONSERVATIVE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly ANY_SAMPLES_PASSED: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_DIVISOR: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_FLUSH_COMMANDS_BIT: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly WAIT_FAILED: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly CONDITION_SATISFIED: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TIMEOUT_EXPIRED: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly ALREADY_SIGNALED: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SIGNALED: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNALED: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_GPU_COMMANDS_COMPLETE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_FENCE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_FLAGS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_STATUS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_CONDITION: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly OBJECT_TYPE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_SERVER_WAIT_TIMEOUT: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_FRAGMENT_INPUT_COMPONENTS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_VERTEX_OUTPUT_COMPONENTS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly INVALID_INDEX: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_ACTIVE_UNIFORMS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_DATA_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_IS_ROW_MAJOR: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_MATRIX_STRIDE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_ARRAY_STRIDE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_OFFSET: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_INDEX: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_TYPE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly ACTIVE_UNIFORM_BLOCKS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BUFFER_OFFSET_ALIGNMENT: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_UNIFORM_BLOCK_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_UNIFORM_BUFFER_BINDINGS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_COMBINED_UNIFORM_BLOCKS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_FRAGMENT_UNIFORM_BLOCKS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_VERTEX_UNIFORM_BLOCKS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BUFFER_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BUFFER_START: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BUFFER_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BUFFER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COPY_WRITE_BUFFER_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COPY_READ_BUFFER_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COPY_WRITE_BUFFER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COPY_READ_BUFFER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SIGNED_NORMALIZED: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGBA8_SNORM: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB8_SNORM: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG8_SNORM: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly R8_SNORM: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly VERTEX_ARRAY_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG32UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG32I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG16UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG16I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG8UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG8I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly R32UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly R32I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly R16UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly R16I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly R8UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly R8I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG32F: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG16F: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly R32F: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly R16F: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG8: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly R8: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG_INTEGER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RG: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly HALF_FLOAT: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_SAMPLES: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_INCOMPLETE_MULTISAMPLE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT15: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT14: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT13: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT12: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT11: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT10: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT9: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT8: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT7: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT6: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT5: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT4: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT3: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT2: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT1: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_COLOR_ATTACHMENTS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RENDERBUFFER_SAMPLES: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly READ_FRAMEBUFFER_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_FRAMEBUFFER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly READ_FRAMEBUFFER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_FRAMEBUFFER_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_NORMALIZED: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DEPTH24_STENCIL8: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_24_8: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_DEFAULT: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_BLUE_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_GREEN_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_RED_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_32_UNSIGNED_INT_24_8_REV: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DEPTH32F_STENCIL8: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DEPTH_COMPONENT32F: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_SAMPLER_2D_ARRAY: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_SAMPLER_CUBE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_SAMPLER_3D: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_SAMPLER_2D: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly INT_SAMPLER_2D_ARRAY: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly INT_SAMPLER_CUBE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly INT_SAMPLER_3D: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly INT_SAMPLER_2D: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_VEC4: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_VEC3: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_VEC2: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_CUBE_SHADOW: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_2D_ARRAY_SHADOW: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_2D_ARRAY: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGBA_INTEGER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB_INTEGER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RED_INTEGER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB8I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGBA8I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB16I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGBA16I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB32I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGBA32I: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB8UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGBA8UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB16UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGBA16UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB32UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGBA32UI: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BUFFER_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BUFFER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SEPARATE_ATTRIBS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly INTERLEAVED_ATTRIBS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RASTERIZER_DISCARD: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BUFFER_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BUFFER_START: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_VARYINGS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BUFFER_MODE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_5_9_9_9_REV: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB9_E5: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_10F_11F_11F_REV: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly R11F_G11F_B10F: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_BINDING_2D_ARRAY: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_2D_ARRAY: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_VARYING_COMPONENTS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_PROGRAM_TEXEL_OFFSET: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MIN_PROGRAM_TEXEL_OFFSET: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_ARRAY_TEXTURE_LAYERS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_INTEGER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB16F: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGBA16F: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB32F: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGBA32F: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COMPARE_REF_TO_TEXTURE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SRGB8_ALPHA8: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SRGB8: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SRGB: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT4x3: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT4x2: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT3x4: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT3x2: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT2x4: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT2x3: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly PIXEL_UNPACK_BUFFER_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly PIXEL_PACK_BUFFER_BINDING: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly PIXEL_UNPACK_BUFFER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly PIXEL_PACK_BUFFER: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly FRAGMENT_SHADER_DERIVATIVE_HINT: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_2D_SHADOW: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_3D: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_VERTEX_UNIFORM_COMPONENTS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_FRAGMENT_UNIFORM_COMPONENTS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER15: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER14: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER13: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER12: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER11: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER10: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER9: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER8: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER7: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER6: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER5: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER4: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER3: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER2: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER1: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER0: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_DRAW_BUFFERS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DYNAMIC_COPY: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DYNAMIC_READ: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly STATIC_COPY: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly STATIC_READ: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly STREAM_COPY: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly STREAM_READ: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly QUERY_RESULT_AVAILABLE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly QUERY_RESULT: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly CURRENT_QUERY: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_COMPARE_FUNC: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_COMPARE_MODE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_TEXTURE_LOD_BIAS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DEPTH_COMPONENT24: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MIN: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_MAX_LEVEL: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_BASE_LEVEL: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_MAX_LOD: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_MIN_LOD: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_ELEMENTS_INDICES: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_ELEMENTS_VERTICES: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_2_10_10_10_REV: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly MAX_3D_TEXTURE_SIZE: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_WRAP_R: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_3D: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNPACK_IMAGE_HEIGHT: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNPACK_SKIP_IMAGES: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_BINDING_3D: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB10_A2: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGBA8: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RGB8: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly RED: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly STENCIL: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly DEPTH: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly COLOR: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly PACK_SKIP_PIXELS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly PACK_SKIP_ROWS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly PACK_ROW_LENGTH: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNPACK_SKIP_PIXELS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNPACK_SKIP_ROWS: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly UNPACK_ROW_LENGTH: GLenum; | 新增 |
| webgl2 | WebGL2RenderingContextBase | readonly READ_BUFFER: GLenum; | 新增 |
| webgl | WebGLRenderingContextOverloads | uniformMatrix4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, value: Float32List): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | uniformMatrix3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, value: Float32List): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | uniformMatrix2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, value: Float32List): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | uniform4iv(location: WebGLUniformLocation \| null, v: Int32List): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | uniform3iv(location: WebGLUniformLocation \| null, v: Int32List): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | uniform2iv(location: WebGLUniformLocation \| null, v: Int32List): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | uniform1iv(location: WebGLUniformLocation \| null, v: Int32List): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | uniform4fv(location: WebGLUniformLocation \| null, v: Float32List): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | uniform3fv(location: WebGLUniformLocation \| null, v: Float32List): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | uniform2fv(location: WebGLUniformLocation \| null, v: Float32List): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | uniform1fv(location: WebGLUniformLocation \| null, v: Float32List): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null): void;<br>texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, format: GLenum, type: GLenum, source: TexImageSource): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null): void;<br>texImage2D(target: GLenum, level: GLint, internalformat: GLint, format: GLenum, type: GLenum, source: TexImageSource): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | compressedTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, data: ArrayBufferView): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | compressedTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, border: GLint, data: ArrayBufferView): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | bufferSubData(target: GLenum, offset: GLintptr, data: BufferSource): void; | 新增 |
| webgl | WebGLRenderingContextOverloads | bufferData(target: GLenum, size: GLsizeiptr, usage: GLenum): void;<br>bufferData(target: GLenum, data: BufferSource \| null, usage: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | viewport(x: GLint, y: GLint, width: GLsizei, height: GLsizei): void; | 新增 |
| webgl | WebGLRenderingContextBase | vertexAttribPointer(index: GLuint, size: GLint, type: GLenum, normalized: GLboolean, stride: GLsizei, offset: GLintptr): void; | 新增 |
| webgl | WebGLRenderingContextBase | vertexAttrib4fv(index: GLuint, values: Float32List): void; | 新增 |
| webgl | WebGLRenderingContextBase | vertexAttrib3fv(index: GLuint, values: Float32List): void; | 新增 |
| webgl | WebGLRenderingContextBase | vertexAttrib2fv(index: GLuint, values: Float32List): void; | 新增 |
| webgl | WebGLRenderingContextBase | vertexAttrib1fv(index: GLuint, values: Float32List): void; | 新增 |
| webgl | WebGLRenderingContextBase | vertexAttrib4f(index: GLuint, x: GLfloat, y: GLfloat, z: GLfloat, w: GLfloat): void; | 新增 |
| webgl | WebGLRenderingContextBase | vertexAttrib3f(index: GLuint, x: GLfloat, y: GLfloat, z: GLfloat): void; | 新增 |
| webgl | WebGLRenderingContextBase | vertexAttrib2f(index: GLuint, x: GLfloat, y: GLfloat): void; | 新增 |
| webgl | WebGLRenderingContextBase | vertexAttrib1f(index: GLuint, x: GLfloat): void; | 新增 |
| webgl | WebGLRenderingContextBase | validateProgram(program: WebGLProgram): void; | 新增 |
| webgl | WebGLRenderingContextBase | useProgram(program: WebGLProgram \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | uniform4i(location: WebGLUniformLocation \| null, x: GLint, y: GLint, z: GLint, w: GLint): void; | 新增 |
| webgl | WebGLRenderingContextBase | uniform3i(location: WebGLUniformLocation \| null, x: GLint, y: GLint, z: GLint): void; | 新增 |
| webgl | WebGLRenderingContextBase | uniform2i(location: WebGLUniformLocation \| null, x: GLint, y: GLint): void; | 新增 |
| webgl | WebGLRenderingContextBase | uniform1i(location: WebGLUniformLocation \| null, x: GLint): void; | 新增 |
| webgl | WebGLRenderingContextBase | uniform4f(location: WebGLUniformLocation \| null, x: GLfloat, y: GLfloat, z: GLfloat, w: GLfloat): void; | 新增 |
| webgl | WebGLRenderingContextBase | uniform3f(location: WebGLUniformLocation \| null, x: GLfloat, y: GLfloat, z: GLfloat): void; | 新增 |
| webgl | WebGLRenderingContextBase | uniform2f(location: WebGLUniformLocation \| null, x: GLfloat, y: GLfloat): void; | 新增 |
| webgl | WebGLRenderingContextBase | uniform1f(location: WebGLUniformLocation \| null, x: GLfloat): void; | 新增 |
| webgl | WebGLRenderingContextBase | texParameteri(target: GLenum, pname: GLenum, param: GLint): void; | 新增 |
| webgl | WebGLRenderingContextBase | texParameterf(target: GLenum, pname: GLenum, param: GLfloat): void; | 新增 |
| webgl | WebGLRenderingContextBase | stencilOpSeparate(face: GLenum, fail: GLenum, zfail: GLenum, zpass: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | stencilOp(fail: GLenum, zfail: GLenum, zpass: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | stencilMaskSeparate(face: GLenum, mask: GLuint): void; | 新增 |
| webgl | WebGLRenderingContextBase | stencilMask(mask: GLuint): void; | 新增 |
| webgl | WebGLRenderingContextBase | stencilFuncSeparate(face: GLenum, func: GLenum, ref: GLint, mask: GLuint): void; | 新增 |
| webgl | WebGLRenderingContextBase | stencilFunc(func: GLenum, ref: GLint, mask: GLuint): void; | 新增 |
| webgl | WebGLRenderingContextBase | shaderSource(shader: WebGLShader, source: string): void; | 新增 |
| webgl | WebGLRenderingContextBase | scissor(x: GLint, y: GLint, width: GLsizei, height: GLsizei): void; | 新增 |
| webgl | WebGLRenderingContextBase | sampleCoverage(value: GLclampf, invert: GLboolean): void; | 新增 |
| webgl | WebGLRenderingContextBase | renderbufferStorage(target: GLenum, internalformat: GLenum, width: GLsizei, height: GLsizei): void; | 新增 |
| webgl | WebGLRenderingContextBase | polygonOffset(factor: GLfloat, units: GLfloat): void; | 新增 |
| webgl | WebGLRenderingContextBase | pixelStorei(pname: GLenum, param: GLint \| GLboolean): void; | 新增 |
| webgl | WebGLRenderingContextBase | linkProgram(program: WebGLProgram): void; | 新增 |
| webgl | WebGLRenderingContextBase | lineWidth(width: GLfloat): void; | 新增 |
| webgl | WebGLRenderingContextBase | isTexture(texture: WebGLTexture \| null): GLboolean; | 新增 |
| webgl | WebGLRenderingContextBase | isShader(shader: WebGLShader \| null): GLboolean; | 新增 |
| webgl | WebGLRenderingContextBase | isRenderbuffer(renderbuffer: WebGLRenderbuffer \| null): GLboolean; | 新增 |
| webgl | WebGLRenderingContextBase | isProgram(program: WebGLProgram \| null): GLboolean; | 新增 |
| webgl | WebGLRenderingContextBase | isFramebuffer(framebuffer: WebGLFramebuffer \| null): GLboolean; | 新增 |
| webgl | WebGLRenderingContextBase | isEnabled(cap: GLenum): GLboolean; | 新增 |
| webgl | WebGLRenderingContextBase | isBuffer(buffer: WebGLBuffer \| null): GLboolean; | 新增 |
| webgl | WebGLRenderingContextBase | hint(target: GLenum, mode: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | getVertexAttribOffset(index: GLuint, pname: GLenum): GLintptr; | 新增 |
| webgl | WebGLRenderingContextBase | getVertexAttrib(index: GLuint, pname: GLenum): any; | 新增 |
| webgl | WebGLRenderingContextBase | getUniformLocation(program: WebGLProgram, name: string): WebGLUniformLocation \| null; | 新增 |
| webgl | WebGLRenderingContextBase | getUniform(program: WebGLProgram, location: WebGLUniformLocation): any; | 新增 |
| webgl | WebGLRenderingContextBase | getTexParameter(target: GLenum, pname: GLenum): any; | 新增 |
| webgl | WebGLRenderingContextBase | getShaderSource(shader: WebGLShader): string \| null; | 新增 |
| webgl | WebGLRenderingContextBase | getShaderInfoLog(shader: WebGLShader): string \| null; | 新增 |
| webgl | WebGLRenderingContextBase | getShaderPrecisionFormat(shadertype: GLenum, precisiontype: GLenum): WebGLShaderPrecisionFormat \| null; | 新增 |
| webgl | WebGLRenderingContextBase | getShaderParameter(shader: WebGLShader, pname: GLenum): any; | 新增 |
| webgl | WebGLRenderingContextBase | getRenderbufferParameter(target: GLenum, pname: GLenum): any; | 新增 |
| webgl | WebGLRenderingContextBase | getProgramInfoLog(program: WebGLProgram): string \| null; | 新增 |
| webgl | WebGLRenderingContextBase | getProgramParameter(program: WebGLProgram, pname: GLenum): any; | 新增 |
| webgl | WebGLRenderingContextBase | getFramebufferAttachmentParameter(target: GLenum, attachment: GLenum, pname: GLenum): any; | 新增 |
| webgl | WebGLRenderingContextBase | getError(): GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | getParameter(pname: GLenum): any; | 新增 |
| webgl | WebGLRenderingContextBase | getBufferParameter(target: GLenum, pname: GLenum): any; | 新增 |
| webgl | WebGLRenderingContextBase | getAttribLocation(program: WebGLProgram, name: string): GLint; | 新增 |
| webgl | WebGLRenderingContextBase | getAttachedShaders(program: WebGLProgram): WebGLShader[] \| null; | 新增 |
| webgl | WebGLRenderingContextBase | getActiveUniform(program: WebGLProgram, index: GLuint): WebGLActiveInfo \| null; | 新增 |
| webgl | WebGLRenderingContextBase | getActiveAttrib(program: WebGLProgram, index: GLuint): WebGLActiveInfo \| null; | 新增 |
| webgl | WebGLRenderingContextBase | generateMipmap(target: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | frontFace(mode: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | framebufferTexture2D(target: GLenum, attachment: GLenum, textarget: GLenum, texture: WebGLTexture \| null, level: GLint): void; | 新增 |
| webgl | WebGLRenderingContextBase | framebufferRenderbuffer(target: GLenum, attachment: GLenum, renderbuffertarget: GLenum, renderbuffer: WebGLRenderbuffer \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | flush(): void; | 新增 |
| webgl | WebGLRenderingContextBase | finish(): void; | 新增 |
| webgl | WebGLRenderingContextBase | enableVertexAttribArray(index: GLuint): void; | 新增 |
| webgl | WebGLRenderingContextBase | enable(cap: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | drawElements(mode: GLenum, count: GLsizei, type: GLenum, offset: GLintptr): void; | 新增 |
| webgl | WebGLRenderingContextBase | drawArrays(mode: GLenum, first: GLint, count: GLsizei): void; | 新增 |
| webgl | WebGLRenderingContextBase | disableVertexAttribArray(index: GLuint): void; | 新增 |
| webgl | WebGLRenderingContextBase | disable(cap: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | detachShader(program: WebGLProgram, shader: WebGLShader): void; | 新增 |
| webgl | WebGLRenderingContextBase | depthRange(zNear: GLclampf, zFar: GLclampf): void; | 新增 |
| webgl | WebGLRenderingContextBase | depthMask(flag: GLboolean): void; | 新增 |
| webgl | WebGLRenderingContextBase | depthFunc(func: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | deleteTexture(texture: WebGLTexture \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | deleteShader(shader: WebGLShader \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | deleteRenderbuffer(renderbuffer: WebGLRenderbuffer \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | deleteProgram(program: WebGLProgram \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | deleteFramebuffer(framebuffer: WebGLFramebuffer \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | deleteBuffer(buffer: WebGLBuffer \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | cullFace(mode: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | createTexture(): WebGLTexture \| null; | 新增 |
| webgl | WebGLRenderingContextBase | createShader(type: GLenum): WebGLShader \| null; | 新增 |
| webgl | WebGLRenderingContextBase | createRenderbuffer(): WebGLRenderbuffer \| null; | 新增 |
| webgl | WebGLRenderingContextBase | createProgram(): WebGLProgram \| null; | 新增 |
| webgl | WebGLRenderingContextBase | createFramebuffer(): WebGLFramebuffer \| null; | 新增 |
| webgl | WebGLRenderingContextBase | createBuffer(): WebGLBuffer \| null; | 新增 |
| webgl | WebGLRenderingContextBase | copyTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, x: GLint, y: GLint, width: GLsizei, height: GLsizei): void; | 新增 |
| webgl | WebGLRenderingContextBase | copyTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, x: GLint, y: GLint, width: GLsizei, height: GLsizei, border: GLint): void; | 新增 |
| webgl | WebGLRenderingContextBase | compileShader(shader: WebGLShader): void; | 新增 |
| webgl | WebGLRenderingContextBase | colorMask(red: GLboolean, green: GLboolean, blue: GLboolean, alpha: GLboolean): void; | 新增 |
| webgl | WebGLRenderingContextBase | clearStencil(s: GLint): void; | 新增 |
| webgl | WebGLRenderingContextBase | clearDepth(depth: GLclampf): void; | 新增 |
| webgl | WebGLRenderingContextBase | clearColor(red: GLclampf, green: GLclampf, blue: GLclampf, alpha: GLclampf): void; | 新增 |
| webgl | WebGLRenderingContextBase | clear(mask: GLbitfield): void; | 新增 |
| webgl | WebGLRenderingContextBase | checkFramebufferStatus(target: GLenum): GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | blendFuncSeparate(srcRGB: GLenum, dstRGB: GLenum, srcAlpha: GLenum, dstAlpha: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | blendFunc(sfactor: GLenum, dfactor: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | blendEquationSeparate(modeRGB: GLenum, modeAlpha: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | blendEquation(mode: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | blendColor(red: GLclampf, green: GLclampf, blue: GLclampf, alpha: GLclampf): void; | 新增 |
| webgl | WebGLRenderingContextBase | bindTexture(target: GLenum, texture: WebGLTexture \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | bindRenderbuffer(target: GLenum, renderbuffer: WebGLRenderbuffer \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | bindFramebuffer(target: GLenum, framebuffer: WebGLFramebuffer \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | bindBuffer(target: GLenum, buffer: WebGLBuffer \| null): void; | 新增 |
| webgl | WebGLRenderingContextBase | bindAttribLocation(program: WebGLProgram, index: GLuint, name: string): void; | 新增 |
| webgl | WebGLRenderingContextBase | attachShader(program: WebGLProgram, shader: WebGLShader): void; | 新增 |
| webgl | WebGLRenderingContextBase | activeTexture(texture: GLenum): void; | 新增 |
| webgl | WebGLRenderingContextBase | getExtension(name: string): any; | 新增 |
| webgl | WebGLRenderingContextBase | getSupportedExtensions(): string[] \| null; | 新增 |
| webgl | WebGLRenderingContextBase | isContextLost(): boolean; | 新增 |
| webgl | WebGLRenderingContextBase | getContextAttributes(): WebGLContextAttributes \| null; | 新增 |
| webgl | WebGLRenderingContextBase | readonly drawingBufferHeight: GLsizei; | 新增 |
| webgl | WebGLRenderingContextBase | readonly drawingBufferWidth: GLsizei; | 新增 |
| webgl | WebGLRenderingContextBase | readonly canvas: HTMLCanvasElement \| OffscreenCanvas; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BROWSER_DEFAULT_WEBGL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly UNPACK_COLORSPACE_CONVERSION_WEBGL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly CONTEXT_LOST_WEBGL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly UNPACK_PREMULTIPLY_ALPHA_WEBGL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly UNPACK_FLIP_Y_WEBGL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly INVALID_FRAMEBUFFER_OPERATION: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MAX_RENDERBUFFER_SIZE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_BINDING: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_BINDING: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_UNSUPPORTED: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_INCOMPLETE_DIMENSIONS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_INCOMPLETE_ATTACHMENT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_COMPLETE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly NONE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_STENCIL_ATTACHMENT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_ATTACHMENT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_ATTACHMENT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly COLOR_ATTACHMENT0: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_OBJECT_NAME: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_STENCIL_SIZE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_DEPTH_SIZE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_ALPHA_SIZE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_BLUE_SIZE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_GREEN_SIZE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_RED_SIZE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_INTERNAL_FORMAT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_HEIGHT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_WIDTH: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_STENCIL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_INDEX8: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_COMPONENT16: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RGB565: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RGB5_A1: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RGBA4: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly HIGH_INT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MEDIUM_INT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LOW_INT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly HIGH_FLOAT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MEDIUM_FLOAT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LOW_FLOAT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly COMPILE_STATUS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly IMPLEMENTATION_COLOR_READ_FORMAT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly IMPLEMENTATION_COLOR_READ_TYPE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_BUFFER_BINDING: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_POINTER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_NORMALIZED: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_TYPE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_STRIDE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_SIZE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_ENABLED: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SAMPLER_CUBE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SAMPLER_2D: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FLOAT_MAT4: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FLOAT_MAT3: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FLOAT_MAT2: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BOOL_VEC4: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BOOL_VEC3: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BOOL_VEC2: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BOOL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly INT_VEC4: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly INT_VEC3: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly INT_VEC2: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FLOAT_VEC4: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FLOAT_VEC3: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FLOAT_VEC2: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MIRRORED_REPEAT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly CLAMP_TO_EDGE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly REPEAT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ACTIVE_TEXTURE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE31: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE30: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE29: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE28: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE27: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE26: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE25: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE24: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE23: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE22: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE21: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE20: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE19: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE18: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE17: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE16: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE15: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE14: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE13: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE12: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE11: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE10: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE9: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE8: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE7: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE6: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE5: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE4: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE3: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE2: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE1: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE0: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MAX_CUBE_MAP_TEXTURE_SIZE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_NEGATIVE_Z: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_POSITIVE_Z: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_NEGATIVE_Y: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_POSITIVE_Y: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_NEGATIVE_X: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_POSITIVE_X: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_BINDING_CUBE_MAP: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_2D: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_WRAP_T: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_WRAP_S: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_MIN_FILTER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_MAG_FILTER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LINEAR_MIPMAP_LINEAR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly NEAREST_MIPMAP_LINEAR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LINEAR_MIPMAP_NEAREST: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly NEAREST_MIPMAP_NEAREST: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LINEAR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly NEAREST: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VERSION: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RENDERER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VENDOR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DECR_WRAP: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly INCR_WRAP: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly INVERT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DECR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly INCR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly REPLACE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly KEEP: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ALWAYS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly GEQUAL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly NOTEQUAL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly GREATER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LEQUAL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly EQUAL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LESS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly NEVER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly CURRENT_PROGRAM: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SHADING_LANGUAGE_VERSION: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ACTIVE_ATTRIBUTES: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ACTIVE_UNIFORMS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ATTACHED_SHADERS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VALIDATE_STATUS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LINK_STATUS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DELETE_STATUS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SHADER_TYPE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MAX_FRAGMENT_UNIFORM_VECTORS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MAX_TEXTURE_IMAGE_UNITS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MAX_VERTEX_TEXTURE_IMAGE_UNITS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MAX_COMBINED_TEXTURE_IMAGE_UNITS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MAX_VARYING_VECTORS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MAX_VERTEX_UNIFORM_VECTORS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MAX_VERTEX_ATTRIBS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VERTEX_SHADER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRAGMENT_SHADER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_SHORT_5_6_5: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_SHORT_5_5_5_1: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_SHORT_4_4_4_4: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LUMINANCE_ALPHA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LUMINANCE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RGBA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RGB: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ALPHA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_COMPONENT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FLOAT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_INT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly INT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_SHORT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SHORT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_BYTE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BYTE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly GENERATE_MIPMAP_HINT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly NICEST: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FASTEST: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DONT_CARE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly COMPRESSED_TEXTURE_FORMATS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SAMPLE_COVERAGE_INVERT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SAMPLE_COVERAGE_VALUE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SAMPLES: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SAMPLE_BUFFERS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TEXTURE_BINDING_2D: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly POLYGON_OFFSET_FACTOR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly POLYGON_OFFSET_UNITS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_BITS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_BITS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ALPHA_BITS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BLUE_BITS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly GREEN_BITS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly RED_BITS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SUBPIXEL_BITS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MAX_VIEWPORT_DIMS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly MAX_TEXTURE_SIZE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly PACK_ALIGNMENT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly UNPACK_ALIGNMENT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly COLOR_WRITEMASK: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly COLOR_CLEAR_VALUE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SCISSOR_BOX: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly VIEWPORT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_WRITEMASK: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_VALUE_MASK: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_REF: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_PASS_DEPTH_PASS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_PASS_DEPTH_FAIL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_FAIL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_FUNC: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_WRITEMASK: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_VALUE_MASK: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_REF: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_PASS_DEPTH_PASS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_PASS_DEPTH_FAIL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_FAIL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_FUNC: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_CLEAR_VALUE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_FUNC: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_CLEAR_VALUE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_WRITEMASK: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_RANGE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRONT_FACE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly CULL_FACE_MODE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ALIASED_LINE_WIDTH_RANGE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ALIASED_POINT_SIZE_RANGE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LINE_WIDTH: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly CCW: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly CW: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly OUT_OF_MEMORY: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly INVALID_OPERATION: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly INVALID_VALUE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly INVALID_ENUM: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly NO_ERROR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SAMPLE_COVERAGE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SAMPLE_ALPHA_TO_COVERAGE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly POLYGON_OFFSET_FILL: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SCISSOR_TEST: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_TEST: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_TEST: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DITHER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BLEND: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly CULL_FACE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRONT_AND_BACK: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BACK: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FRONT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly CURRENT_VERTEX_ATTRIB: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BUFFER_USAGE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BUFFER_SIZE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DYNAMIC_DRAW: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STATIC_DRAW: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STREAM_DRAW: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ELEMENT_ARRAY_BUFFER_BINDING: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ARRAY_BUFFER_BINDING: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ELEMENT_ARRAY_BUFFER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ARRAY_BUFFER: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BLEND_COLOR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_CONSTANT_ALPHA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly CONSTANT_ALPHA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_CONSTANT_COLOR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly CONSTANT_COLOR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BLEND_SRC_ALPHA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BLEND_DST_ALPHA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BLEND_SRC_RGB: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BLEND_DST_RGB: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FUNC_REVERSE_SUBTRACT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FUNC_SUBTRACT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BLEND_EQUATION_ALPHA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BLEND_EQUATION_RGB: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly BLEND_EQUATION: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly FUNC_ADD: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SRC_ALPHA_SATURATE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_DST_COLOR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DST_COLOR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_DST_ALPHA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DST_ALPHA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_SRC_ALPHA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SRC_ALPHA: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_SRC_COLOR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly SRC_COLOR: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ONE: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly ZERO: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TRIANGLE_FAN: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TRIANGLE_STRIP: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly TRIANGLES: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LINE_STRIP: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LINE_LOOP: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly LINES: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly POINTS: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly COLOR_BUFFER_BIT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly STENCIL_BUFFER_BIT: GLenum; | 新增 |
| webgl | WebGLRenderingContextBase | readonly DEPTH_BUFFER_BIT: GLenum; | 新增 |
| webgl | WebGLShaderPrecisionFormat | readonly precision: GLint; | 新增 |
| webgl | WebGLShaderPrecisionFormat | readonly rangeMax: GLint; | 新增 |
| webgl | WebGLShaderPrecisionFormat | readonly rangeMin: GLint; | 新增 |
| webgl | WebGLActiveInfo | readonly name: string; | 新增 |
| webgl | WebGLActiveInfo | readonly type: GLenum; | 新增 |
| webgl | WebGLActiveInfo | readonly size: GLint; | 新增 |
| webgl | WebGLContextAttributes | desynchronized?: boolean; | 新增 |
| webgl | WebGLContextAttributes | failIfMajorPerformanceCaveat?: boolean; | 新增 |
| webgl | WebGLContextAttributes | powerPreference?: WebGLPowerPreference; | 新增 |
| webgl | WebGLContextAttributes | preserveDrawingBuffer?: boolean; | 新增 |
| webgl | WebGLContextAttributes | premultipliedAlpha?: boolean; | 新增 |
| webgl | WebGLContextAttributes | antialias?: boolean; | 新增 |
| webgl | WebGLContextAttributes | stencil?: boolean; | 新增 |
| webgl | WebGLContextAttributes | depth?: boolean; | 新增 |
| webgl | WebGLContextAttributes | alpha?: boolean; | 新增 |
