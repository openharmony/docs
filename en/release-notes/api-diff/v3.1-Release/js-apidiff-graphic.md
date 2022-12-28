# JS API Changes of the Graphics Subsystem

The table below lists the APIs changes of the graphics subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| webgl2 | WebGL2RenderingContextOverloads | readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, dstData: ArrayBufferView \| null): void;<br>readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, offset: GLintptr): void;<br>readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, dstData: ArrayBufferView, dstOffset: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | uniformMatrix4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | uniformMatrix3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | uniformMatrix2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | uniform4iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | uniform3iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | uniform2iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | uniform1iv(location: WebGLUniformLocation \| null, data: Int32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | uniform4fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | uniform3fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | uniform2fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | uniform1fv(location: WebGLUniformLocation \| null, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | compressedTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, imageSize: GLsizei, offset: GLintptr): void;<br>compressedTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | compressedTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, border: GLint, imageSize: GLsizei, offset: GLintptr): void;<br>compressedTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, border: GLint, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null): void;<br>texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pboOffset: GLintptr): void;<br>texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, srcData: ArrayBufferView, srcOffset: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null): void;<br>texImage2D(target: GLenum, level: GLint, internalformat: GLint, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, pboOffset: GLintptr): void;<br>texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, srcData: ArrayBufferView, srcOffset: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | bufferSubData(target: GLenum, dstByteOffset: GLintptr, srcData: BufferSource): void;<br>bufferSubData(target: GLenum, dstByteOffset: GLintptr, srcData: ArrayBufferView, srcOffset: GLuint, length?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextOverloads | bufferData(target: GLenum, size: GLsizeiptr, usage: GLenum): void;<br>bufferData(target: GLenum, srcData: BufferSource \| null, usage: GLenum): void;<br>bufferData(target: GLenum, srcData: ArrayBufferView, usage: GLenum, srcOffset: GLuint, length?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | bindVertexArray(array: WebGLVertexArrayObject \| null): void; | Added|
| webgl2 | WebGL2RenderingContextBase | isVertexArray(vertexArray: WebGLVertexArrayObject \| null): GLboolean; | Added|
| webgl2 | WebGL2RenderingContextBase | deleteVertexArray(vertexArray: WebGLVertexArrayObject \| null): void; | Added|
| webgl2 | WebGL2RenderingContextBase | createVertexArray(): WebGLVertexArrayObject \| null; | Added|
| webgl2 | WebGL2RenderingContextBase | uniformBlockBinding(program: WebGLProgram, uniformBlockIndex: GLuint, uniformBlockBinding: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | getActiveUniformBlockName(program: WebGLProgram, uniformBlockIndex: GLuint): string \| null; | Added|
| webgl2 | WebGL2RenderingContextBase | getActiveUniformBlockParameter(program: WebGLProgram, uniformBlockIndex: GLuint, pname: GLenum): any; | Added|
| webgl2 | WebGL2RenderingContextBase | getUniformBlockIndex(program: WebGLProgram, uniformBlockName: string): GLuint; | Added|
| webgl2 | WebGL2RenderingContextBase | getActiveUniforms(program: WebGLProgram, uniformIndices: GLuint[], pname: GLenum): any; | Added|
| webgl2 | WebGL2RenderingContextBase | getUniformIndices(program: WebGLProgram, uniformNames: string[]): GLuint[] \| null; | Added|
| webgl2 | WebGL2RenderingContextBase | getIndexedParameter(target: GLenum, index: GLuint): any; | Added|
| webgl2 | WebGL2RenderingContextBase | bindBufferRange(target: GLenum, index: GLuint, buffer: WebGLBuffer \| null, offset: GLintptr, size: GLsizeiptr): void; | Added|
| webgl2 | WebGL2RenderingContextBase | bindBufferBase(target: GLenum, index: GLuint, buffer: WebGLBuffer \| null): void; | Added|
| webgl2 | WebGL2RenderingContextBase | resumeTransformFeedback(): void; | Added|
| webgl2 | WebGL2RenderingContextBase | pauseTransformFeedback(): void; | Added|
| webgl2 | WebGL2RenderingContextBase | getTransformFeedbackVarying(program: WebGLProgram, index: GLuint): WebGLActiveInfo \| null; | Added|
| webgl2 | WebGL2RenderingContextBase | transformFeedbackVaryings(program: WebGLProgram, varyings: string[], bufferMode: GLenum): void; | Added|
| webgl2 | WebGL2RenderingContextBase | endTransformFeedback(): void; | Added|
| webgl2 | WebGL2RenderingContextBase | beginTransformFeedback(primitiveMode: GLenum): void; | Added|
| webgl2 | WebGL2RenderingContextBase | bindTransformFeedback(target: GLenum, tf: WebGLTransformFeedback \| null): void; | Added|
| webgl2 | WebGL2RenderingContextBase | isTransformFeedback(tf: WebGLTransformFeedback \| null): GLboolean; | Added|
| webgl2 | WebGL2RenderingContextBase | deleteTransformFeedback(tf: WebGLTransformFeedback \| null): void; | Added|
| webgl2 | WebGL2RenderingContextBase | createTransformFeedback(): WebGLTransformFeedback \| null; | Added|
| webgl2 | WebGL2RenderingContextBase | getSyncParameter(sync: WebGLSync, pname: GLenum): any; | Added|
| webgl2 | WebGL2RenderingContextBase | waitSync(sync: WebGLSync, flags: GLbitfield, timeout: GLint64): void; | Added|
| webgl2 | WebGL2RenderingContextBase | clientWaitSync(sync: WebGLSync, flags: GLbitfield, timeout: GLuint64): GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | deleteSync(sync: WebGLSync \| null): void; | Added|
| webgl2 | WebGL2RenderingContextBase | isSync(sync: WebGLSync \| null): GLboolean; | Added|
| webgl2 | WebGL2RenderingContextBase | fenceSync(condition: GLenum, flags: GLbitfield): WebGLSync \| null; | Added|
| webgl2 | WebGL2RenderingContextBase | getSamplerParameter(sampler: WebGLSampler, pname: GLenum): any; | Added|
| webgl2 | WebGL2RenderingContextBase | samplerParameterf(sampler: WebGLSampler, pname: GLenum, param: GLfloat): void; | Added|
| webgl2 | WebGL2RenderingContextBase | samplerParameteri(sampler: WebGLSampler, pname: GLenum, param: GLint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | bindSampler(unit: GLuint, sampler: WebGLSampler \| null): void; | Added|
| webgl2 | WebGL2RenderingContextBase | isSampler(sampler: WebGLSampler \| null): GLboolean; | Added|
| webgl2 | WebGL2RenderingContextBase | deleteSampler(sampler: WebGLSampler \| null): void; | Added|
| webgl2 | WebGL2RenderingContextBase | createSampler(): WebGLSampler \| null; | Added|
| webgl2 | WebGL2RenderingContextBase | getQueryParameter(query: WebGLQuery, pname: GLenum): any; | Added|
| webgl2 | WebGL2RenderingContextBase | getQuery(target: GLenum, pname: GLenum): WebGLQuery \| null; | Added|
| webgl2 | WebGL2RenderingContextBase | endQuery(target: GLenum): void; | Added|
| webgl2 | WebGL2RenderingContextBase | beginQuery(target: GLenum, query: WebGLQuery): void; | Added|
| webgl2 | WebGL2RenderingContextBase | isQuery(query: WebGLQuery \| null): GLboolean; | Added|
| webgl2 | WebGL2RenderingContextBase | deleteQuery(query: WebGLQuery \| null): void; | Added|
| webgl2 | WebGL2RenderingContextBase | createQuery(): WebGLQuery \| null; | Added|
| webgl2 | WebGL2RenderingContextBase | clearBufferfi(buffer: GLenum, drawbuffer: GLint, depth: GLfloat, stencil: GLint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | clearBufferuiv(buffer: GLenum, drawbuffer: GLint, values: Uint32List, srcOffset?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | clearBufferiv(buffer: GLenum, drawbuffer: GLint, values: Int32List, srcOffset?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | clearBufferfv(buffer: GLenum, drawbuffer: GLint, values: Float32List, srcOffset?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | drawBuffers(buffers: GLenum[]): void; | Added|
| webgl2 | WebGL2RenderingContextBase | drawRangeElements(mode: GLenum, start: GLuint, end: GLuint, count: GLsizei, type: GLenum, offset: GLintptr): void; | Added|
| webgl2 | WebGL2RenderingContextBase | drawElementsInstanced(mode: GLenum, count: GLsizei, type: GLenum, offset: GLintptr, instanceCount: GLsizei): void; | Added|
| webgl2 | WebGL2RenderingContextBase | drawArraysInstanced(mode: GLenum, first: GLint, count: GLsizei, instanceCount: GLsizei): void; | Added|
| webgl2 | WebGL2RenderingContextBase | vertexAttribDivisor(index: GLuint, divisor: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | vertexAttribIPointer(index: GLuint, size: GLint, type: GLenum, stride: GLsizei, offset: GLintptr): void; | Added|
| webgl2 | WebGL2RenderingContextBase | vertexAttribI4uiv(index: GLuint, values: Uint32List): void; | Added|
| webgl2 | WebGL2RenderingContextBase | vertexAttribI4ui(index: GLuint, x: GLuint, y: GLuint, z: GLuint, w: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | vertexAttribI4iv(index: GLuint, values: Int32List): void; | Added|
| webgl2 | WebGL2RenderingContextBase | vertexAttribI4i(index: GLuint, x: GLint, y: GLint, z: GLint, w: GLint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniformMatrix3x4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniformMatrix2x4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniformMatrix4x3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniformMatrix2x3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniformMatrix4x2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniformMatrix3x2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, data: Float32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniform4uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniform3uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniform2uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniform1uiv(location: WebGLUniformLocation \| null, data: Uint32List, srcOffset?: GLuint, srcLength?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniform4ui(location: WebGLUniformLocation \| null, v0: GLuint, v1: GLuint, v2: GLuint, v3: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniform3ui(location: WebGLUniformLocation \| null, v0: GLuint, v1: GLuint, v2: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniform2ui(location: WebGLUniformLocation \| null, v0: GLuint, v1: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | uniform1ui(location: WebGLUniformLocation \| null, v0: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | getFragDataLocation(program: WebGLProgram, name: string): GLint; | Added|
| webgl2 | WebGL2RenderingContextBase | compressedTexSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, imageSize: GLsizei, offset: GLintptr): void;<br>compressedTexSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | compressedTexImage3D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, imageSize: GLsizei, offset: GLintptr): void;<br>compressedTexImage3D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, srcData: ArrayBufferView, srcOffset?: GLuint, srcLengthOverride?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | copyTexSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, x: GLint, y: GLint, width: GLsizei, height: GLsizei): void; | Added|
| webgl2 | WebGL2RenderingContextBase | texSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, type: GLenum, pboOffset: GLintptr): void;<br>texSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texSubImage3D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, zoffset: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, format: GLenum, type: GLenum, srcData: ArrayBufferView \| null, srcOffset?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, pboOffset: GLintptr): void;<br>texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, source: TexImageSource): void;<br>texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, srcData: ArrayBufferView \| null): void;<br>texImage3D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, depth: GLsizei, border: GLint, format: GLenum, type: GLenum, srcData: ArrayBufferView, srcOffset: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | texStorage3D(target: GLenum, levels: GLsizei, internalformat: GLenum, width: GLsizei, height: GLsizei, depth: GLsizei): void; | Added|
| webgl2 | WebGL2RenderingContextBase | texStorage2D(target: GLenum, levels: GLsizei, internalformat: GLenum, width: GLsizei, height: GLsizei): void; | Added|
| webgl2 | WebGL2RenderingContextBase | renderbufferStorageMultisample(target: GLenum, samples: GLsizei, internalformat: GLenum, width: GLsizei, height: GLsizei): void; | Added|
| webgl2 | WebGL2RenderingContextBase | getInternalformatParameter(target: GLenum, internalformat: GLenum, pname: GLenum): any; | Added|
| webgl2 | WebGL2RenderingContextBase | readBuffer(src: GLenum): void; | Added|
| webgl2 | WebGL2RenderingContextBase | invalidateSubFramebuffer(target: GLenum, attachments: GLenum[], x: GLint, y: GLint, width: GLsizei, height: GLsizei): void; | Added|
| webgl2 | WebGL2RenderingContextBase | invalidateFramebuffer(target: GLenum, attachments: GLenum[]): void; | Added|
| webgl2 | WebGL2RenderingContextBase | framebufferTextureLayer(target: GLenum, attachment: GLenum, texture: WebGLTexture \| null, level: GLint, layer: GLint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | blitFramebuffer(srcX0: GLint, srcY0: GLint, srcX1: GLint, srcY1: GLint, dstX0: GLint, dstY0: GLint, dstX1: GLint, dstY1: GLint, mask: GLbitfield, filter: GLenum): void; | Added|
| webgl2 | WebGL2RenderingContextBase | getBufferSubData(target: GLenum, srcByteOffset: GLintptr, dstBuffer: ArrayBufferView, dstOffset?: GLuint, length?: GLuint): void; | Added|
| webgl2 | WebGL2RenderingContextBase | copyBufferSubData(readTarget: GLenum, writeTarget: GLenum, readOffset: GLintptr, writeOffset: GLintptr, size: GLsizeiptr): void; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_CLIENT_WAIT_TIMEOUT_WEBGL: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TIMEOUT_IGNORED: GLint64; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_IMMUTABLE_LEVELS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_ELEMENT_INDEX: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_IMMUTABLE_FORMAT: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_ACTIVE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_PAUSED: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly INT_2_10_10_10_REV: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB10_A2UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly ANY_SAMPLES_PASSED_CONSERVATIVE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly ANY_SAMPLES_PASSED: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_DIVISOR: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_FLUSH_COMMANDS_BIT: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly WAIT_FAILED: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly CONDITION_SATISFIED: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TIMEOUT_EXPIRED: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly ALREADY_SIGNALED: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SIGNALED: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNALED: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_GPU_COMMANDS_COMPLETE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_FENCE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_FLAGS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_STATUS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SYNC_CONDITION: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly OBJECT_TYPE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_SERVER_WAIT_TIMEOUT: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_FRAGMENT_INPUT_COMPONENTS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_VERTEX_OUTPUT_COMPONENTS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly INVALID_INDEX: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_ACTIVE_UNIFORMS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_DATA_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_IS_ROW_MAJOR: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_MATRIX_STRIDE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_ARRAY_STRIDE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_OFFSET: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BLOCK_INDEX: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_TYPE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly ACTIVE_UNIFORM_BLOCKS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BUFFER_OFFSET_ALIGNMENT: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_UNIFORM_BLOCK_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_UNIFORM_BUFFER_BINDINGS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_COMBINED_UNIFORM_BLOCKS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_FRAGMENT_UNIFORM_BLOCKS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_VERTEX_UNIFORM_BLOCKS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BUFFER_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BUFFER_START: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BUFFER_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNIFORM_BUFFER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COPY_WRITE_BUFFER_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COPY_READ_BUFFER_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COPY_WRITE_BUFFER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COPY_READ_BUFFER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SIGNED_NORMALIZED: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGBA8_SNORM: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB8_SNORM: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG8_SNORM: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly R8_SNORM: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly VERTEX_ARRAY_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG32UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG32I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG16UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG16I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG8UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG8I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly R32UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly R32I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly R16UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly R16I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly R8UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly R8I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG32F: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG16F: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly R32F: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly R16F: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG8: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly R8: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG_INTEGER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RG: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly HALF_FLOAT: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_SAMPLES: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_INCOMPLETE_MULTISAMPLE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT15: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT14: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT13: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT12: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT11: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT10: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT9: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT8: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT7: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT6: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT5: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT4: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT3: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT2: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR_ATTACHMENT1: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_COLOR_ATTACHMENTS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RENDERBUFFER_SAMPLES: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly READ_FRAMEBUFFER_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_FRAMEBUFFER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly READ_FRAMEBUFFER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_FRAMEBUFFER_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_NORMALIZED: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DEPTH24_STENCIL8: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_24_8: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_DEFAULT: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_BLUE_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_GREEN_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_RED_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_32_UNSIGNED_INT_24_8_REV: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DEPTH32F_STENCIL8: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DEPTH_COMPONENT32F: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_SAMPLER_2D_ARRAY: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_SAMPLER_CUBE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_SAMPLER_3D: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_SAMPLER_2D: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly INT_SAMPLER_2D_ARRAY: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly INT_SAMPLER_CUBE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly INT_SAMPLER_3D: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly INT_SAMPLER_2D: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_VEC4: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_VEC3: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_VEC2: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_CUBE_SHADOW: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_2D_ARRAY_SHADOW: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_2D_ARRAY: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGBA_INTEGER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB_INTEGER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RED_INTEGER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB8I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGBA8I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB16I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGBA16I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB32I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGBA32I: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB8UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGBA8UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB16UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGBA16UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB32UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGBA32UI: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BUFFER_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BUFFER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SEPARATE_ATTRIBS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly INTERLEAVED_ATTRIBS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RASTERIZER_DISCARD: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BUFFER_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BUFFER_START: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_VARYINGS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TRANSFORM_FEEDBACK_BUFFER_MODE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_5_9_9_9_REV: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB9_E5: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_10F_11F_11F_REV: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly R11F_G11F_B10F: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_BINDING_2D_ARRAY: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_2D_ARRAY: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_VARYING_COMPONENTS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_PROGRAM_TEXEL_OFFSET: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MIN_PROGRAM_TEXEL_OFFSET: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_ARRAY_TEXTURE_LAYERS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_INTEGER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB16F: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGBA16F: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB32F: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGBA32F: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COMPARE_REF_TO_TEXTURE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SRGB8_ALPHA8: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SRGB8: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SRGB: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT4x3: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT4x2: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT3x4: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT3x2: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT2x4: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FLOAT_MAT2x3: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly PIXEL_UNPACK_BUFFER_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly PIXEL_PACK_BUFFER_BINDING: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly PIXEL_UNPACK_BUFFER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly PIXEL_PACK_BUFFER: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly FRAGMENT_SHADER_DERIVATIVE_HINT: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_2D_SHADOW: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly SAMPLER_3D: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_VERTEX_UNIFORM_COMPONENTS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_FRAGMENT_UNIFORM_COMPONENTS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER15: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER14: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER13: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER12: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER11: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER10: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER9: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER8: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER7: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER6: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER5: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER4: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER3: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER2: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER1: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DRAW_BUFFER0: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_DRAW_BUFFERS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DYNAMIC_COPY: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DYNAMIC_READ: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly STATIC_COPY: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly STATIC_READ: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly STREAM_COPY: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly STREAM_READ: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly QUERY_RESULT_AVAILABLE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly QUERY_RESULT: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly CURRENT_QUERY: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_COMPARE_FUNC: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_COMPARE_MODE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_TEXTURE_LOD_BIAS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DEPTH_COMPONENT24: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MIN: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_MAX_LEVEL: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_BASE_LEVEL: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_MAX_LOD: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_MIN_LOD: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_ELEMENTS_INDICES: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_ELEMENTS_VERTICES: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNSIGNED_INT_2_10_10_10_REV: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly MAX_3D_TEXTURE_SIZE: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_WRAP_R: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_3D: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNPACK_IMAGE_HEIGHT: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNPACK_SKIP_IMAGES: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly TEXTURE_BINDING_3D: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB10_A2: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGBA8: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RGB8: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly RED: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly STENCIL: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly DEPTH: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly COLOR: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly PACK_SKIP_PIXELS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly PACK_SKIP_ROWS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly PACK_ROW_LENGTH: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNPACK_SKIP_PIXELS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNPACK_SKIP_ROWS: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly UNPACK_ROW_LENGTH: GLenum; | Added|
| webgl2 | WebGL2RenderingContextBase | readonly READ_BUFFER: GLenum; | Added|
| webgl | WebGLRenderingContextOverloads | uniformMatrix4fv(location: WebGLUniformLocation \| null, transpose: GLboolean, value: Float32List): void; | Added|
| webgl | WebGLRenderingContextOverloads | uniformMatrix3fv(location: WebGLUniformLocation \| null, transpose: GLboolean, value: Float32List): void; | Added|
| webgl | WebGLRenderingContextOverloads | uniformMatrix2fv(location: WebGLUniformLocation \| null, transpose: GLboolean, value: Float32List): void; | Added|
| webgl | WebGLRenderingContextOverloads | uniform4iv(location: WebGLUniformLocation \| null, v: Int32List): void; | Added|
| webgl | WebGLRenderingContextOverloads | uniform3iv(location: WebGLUniformLocation \| null, v: Int32List): void; | Added|
| webgl | WebGLRenderingContextOverloads | uniform2iv(location: WebGLUniformLocation \| null, v: Int32List): void; | Added|
| webgl | WebGLRenderingContextOverloads | uniform1iv(location: WebGLUniformLocation \| null, v: Int32List): void; | Added|
| webgl | WebGLRenderingContextOverloads | uniform4fv(location: WebGLUniformLocation \| null, v: Float32List): void; | Added|
| webgl | WebGLRenderingContextOverloads | uniform3fv(location: WebGLUniformLocation \| null, v: Float32List): void; | Added|
| webgl | WebGLRenderingContextOverloads | uniform2fv(location: WebGLUniformLocation \| null, v: Float32List): void; | Added|
| webgl | WebGLRenderingContextOverloads | uniform1fv(location: WebGLUniformLocation \| null, v: Float32List): void; | Added|
| webgl | WebGLRenderingContextOverloads | texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null): void;<br>texSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, format: GLenum, type: GLenum, source: TexImageSource): void; | Added|
| webgl | WebGLRenderingContextOverloads | texImage2D(target: GLenum, level: GLint, internalformat: GLint, width: GLsizei, height: GLsizei, border: GLint, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null): void;<br>texImage2D(target: GLenum, level: GLint, internalformat: GLint, format: GLenum, type: GLenum, source: TexImageSource): void; | Added|
| webgl | WebGLRenderingContextOverloads | readPixels(x: GLint, y: GLint, width: GLsizei, height: GLsizei, format: GLenum, type: GLenum, pixels: ArrayBufferView \| null): void; | Added|
| webgl | WebGLRenderingContextOverloads | compressedTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, width: GLsizei, height: GLsizei, format: GLenum, data: ArrayBufferView): void; | Added|
| webgl | WebGLRenderingContextOverloads | compressedTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, width: GLsizei, height: GLsizei, border: GLint, data: ArrayBufferView): void; | Added|
| webgl | WebGLRenderingContextOverloads | bufferSubData(target: GLenum, offset: GLintptr, data: BufferSource): void; | Added|
| webgl | WebGLRenderingContextOverloads | bufferData(target: GLenum, size: GLsizeiptr, usage: GLenum): void;<br>bufferData(target: GLenum, data: BufferSource \| null, usage: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | viewport(x: GLint, y: GLint, width: GLsizei, height: GLsizei): void; | Added|
| webgl | WebGLRenderingContextBase | vertexAttribPointer(index: GLuint, size: GLint, type: GLenum, normalized: GLboolean, stride: GLsizei, offset: GLintptr): void; | Added|
| webgl | WebGLRenderingContextBase | vertexAttrib4fv(index: GLuint, values: Float32List): void; | Added|
| webgl | WebGLRenderingContextBase | vertexAttrib3fv(index: GLuint, values: Float32List): void; | Added|
| webgl | WebGLRenderingContextBase | vertexAttrib2fv(index: GLuint, values: Float32List): void; | Added|
| webgl | WebGLRenderingContextBase | vertexAttrib1fv(index: GLuint, values: Float32List): void; | Added|
| webgl | WebGLRenderingContextBase | vertexAttrib4f(index: GLuint, x: GLfloat, y: GLfloat, z: GLfloat, w: GLfloat): void; | Added|
| webgl | WebGLRenderingContextBase | vertexAttrib3f(index: GLuint, x: GLfloat, y: GLfloat, z: GLfloat): void; | Added|
| webgl | WebGLRenderingContextBase | vertexAttrib2f(index: GLuint, x: GLfloat, y: GLfloat): void; | Added|
| webgl | WebGLRenderingContextBase | vertexAttrib1f(index: GLuint, x: GLfloat): void; | Added|
| webgl | WebGLRenderingContextBase | validateProgram(program: WebGLProgram): void; | Added|
| webgl | WebGLRenderingContextBase | useProgram(program: WebGLProgram \| null): void; | Added|
| webgl | WebGLRenderingContextBase | uniform4i(location: WebGLUniformLocation \| null, x: GLint, y: GLint, z: GLint, w: GLint): void; | Added|
| webgl | WebGLRenderingContextBase | uniform3i(location: WebGLUniformLocation \| null, x: GLint, y: GLint, z: GLint): void; | Added|
| webgl | WebGLRenderingContextBase | uniform2i(location: WebGLUniformLocation \| null, x: GLint, y: GLint): void; | Added|
| webgl | WebGLRenderingContextBase | uniform1i(location: WebGLUniformLocation \| null, x: GLint): void; | Added|
| webgl | WebGLRenderingContextBase | uniform4f(location: WebGLUniformLocation \| null, x: GLfloat, y: GLfloat, z: GLfloat, w: GLfloat): void; | Added|
| webgl | WebGLRenderingContextBase | uniform3f(location: WebGLUniformLocation \| null, x: GLfloat, y: GLfloat, z: GLfloat): void; | Added|
| webgl | WebGLRenderingContextBase | uniform2f(location: WebGLUniformLocation \| null, x: GLfloat, y: GLfloat): void; | Added|
| webgl | WebGLRenderingContextBase | uniform1f(location: WebGLUniformLocation \| null, x: GLfloat): void; | Added|
| webgl | WebGLRenderingContextBase | texParameteri(target: GLenum, pname: GLenum, param: GLint): void; | Added|
| webgl | WebGLRenderingContextBase | texParameterf(target: GLenum, pname: GLenum, param: GLfloat): void; | Added|
| webgl | WebGLRenderingContextBase | stencilOpSeparate(face: GLenum, fail: GLenum, zfail: GLenum, zpass: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | stencilOp(fail: GLenum, zfail: GLenum, zpass: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | stencilMaskSeparate(face: GLenum, mask: GLuint): void; | Added|
| webgl | WebGLRenderingContextBase | stencilMask(mask: GLuint): void; | Added|
| webgl | WebGLRenderingContextBase | stencilFuncSeparate(face: GLenum, func: GLenum, ref: GLint, mask: GLuint): void; | Added|
| webgl | WebGLRenderingContextBase | stencilFunc(func: GLenum, ref: GLint, mask: GLuint): void; | Added|
| webgl | WebGLRenderingContextBase | shaderSource(shader: WebGLShader, source: string): void; | Added|
| webgl | WebGLRenderingContextBase | scissor(x: GLint, y: GLint, width: GLsizei, height: GLsizei): void; | Added|
| webgl | WebGLRenderingContextBase | sampleCoverage(value: GLclampf, invert: GLboolean): void; | Added|
| webgl | WebGLRenderingContextBase | renderbufferStorage(target: GLenum, internalformat: GLenum, width: GLsizei, height: GLsizei): void; | Added|
| webgl | WebGLRenderingContextBase | polygonOffset(factor: GLfloat, units: GLfloat): void; | Added|
| webgl | WebGLRenderingContextBase | pixelStorei(pname: GLenum, param: GLint \| GLboolean): void; | Added|
| webgl | WebGLRenderingContextBase | linkProgram(program: WebGLProgram): void; | Added|
| webgl | WebGLRenderingContextBase | lineWidth(width: GLfloat): void; | Added|
| webgl | WebGLRenderingContextBase | isTexture(texture: WebGLTexture \| null): GLboolean; | Added|
| webgl | WebGLRenderingContextBase | isShader(shader: WebGLShader \| null): GLboolean; | Added|
| webgl | WebGLRenderingContextBase | isRenderbuffer(renderbuffer: WebGLRenderbuffer \| null): GLboolean; | Added|
| webgl | WebGLRenderingContextBase | isProgram(program: WebGLProgram \| null): GLboolean; | Added|
| webgl | WebGLRenderingContextBase | isFramebuffer(framebuffer: WebGLFramebuffer \| null): GLboolean; | Added|
| webgl | WebGLRenderingContextBase | isEnabled(cap: GLenum): GLboolean; | Added|
| webgl | WebGLRenderingContextBase | isBuffer(buffer: WebGLBuffer \| null): GLboolean; | Added|
| webgl | WebGLRenderingContextBase | hint(target: GLenum, mode: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | getVertexAttribOffset(index: GLuint, pname: GLenum): GLintptr; | Added|
| webgl | WebGLRenderingContextBase | getVertexAttrib(index: GLuint, pname: GLenum): any; | Added|
| webgl | WebGLRenderingContextBase | getUniformLocation(program: WebGLProgram, name: string): WebGLUniformLocation \| null; | Added|
| webgl | WebGLRenderingContextBase | getUniform(program: WebGLProgram, location: WebGLUniformLocation): any; | Added|
| webgl | WebGLRenderingContextBase | getTexParameter(target: GLenum, pname: GLenum): any; | Added|
| webgl | WebGLRenderingContextBase | getShaderSource(shader: WebGLShader): string \| null; | Added|
| webgl | WebGLRenderingContextBase | getShaderInfoLog(shader: WebGLShader): string \| null; | Added|
| webgl | WebGLRenderingContextBase | getShaderPrecisionFormat(shadertype: GLenum, precisiontype: GLenum): WebGLShaderPrecisionFormat \| null; | Added|
| webgl | WebGLRenderingContextBase | getShaderParameter(shader: WebGLShader, pname: GLenum): any; | Added|
| webgl | WebGLRenderingContextBase | getRenderbufferParameter(target: GLenum, pname: GLenum): any; | Added|
| webgl | WebGLRenderingContextBase | getProgramInfoLog(program: WebGLProgram): string \| null; | Added|
| webgl | WebGLRenderingContextBase | getProgramParameter(program: WebGLProgram, pname: GLenum): any; | Added|
| webgl | WebGLRenderingContextBase | getFramebufferAttachmentParameter(target: GLenum, attachment: GLenum, pname: GLenum): any; | Added|
| webgl | WebGLRenderingContextBase | getError(): GLenum; | Added|
| webgl | WebGLRenderingContextBase | getParameter(pname: GLenum): any; | Added|
| webgl | WebGLRenderingContextBase | getBufferParameter(target: GLenum, pname: GLenum): any; | Added|
| webgl | WebGLRenderingContextBase | getAttribLocation(program: WebGLProgram, name: string): GLint; | Added|
| webgl | WebGLRenderingContextBase | getAttachedShaders(program: WebGLProgram): WebGLShader[] \| null; | Added|
| webgl | WebGLRenderingContextBase | getActiveUniform(program: WebGLProgram, index: GLuint): WebGLActiveInfo \| null; | Added|
| webgl | WebGLRenderingContextBase | getActiveAttrib(program: WebGLProgram, index: GLuint): WebGLActiveInfo \| null; | Added|
| webgl | WebGLRenderingContextBase | generateMipmap(target: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | frontFace(mode: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | framebufferTexture2D(target: GLenum, attachment: GLenum, textarget: GLenum, texture: WebGLTexture \| null, level: GLint): void; | Added|
| webgl | WebGLRenderingContextBase | framebufferRenderbuffer(target: GLenum, attachment: GLenum, renderbuffertarget: GLenum, renderbuffer: WebGLRenderbuffer \| null): void; | Added|
| webgl | WebGLRenderingContextBase | flush(): void; | Added|
| webgl | WebGLRenderingContextBase | finish(): void; | Added|
| webgl | WebGLRenderingContextBase | enableVertexAttribArray(index: GLuint): void; | Added|
| webgl | WebGLRenderingContextBase | enable(cap: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | drawElements(mode: GLenum, count: GLsizei, type: GLenum, offset: GLintptr): void; | Added|
| webgl | WebGLRenderingContextBase | drawArrays(mode: GLenum, first: GLint, count: GLsizei): void; | Added|
| webgl | WebGLRenderingContextBase | disableVertexAttribArray(index: GLuint): void; | Added|
| webgl | WebGLRenderingContextBase | disable(cap: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | detachShader(program: WebGLProgram, shader: WebGLShader): void; | Added|
| webgl | WebGLRenderingContextBase | depthRange(zNear: GLclampf, zFar: GLclampf): void; | Added|
| webgl | WebGLRenderingContextBase | depthMask(flag: GLboolean): void; | Added|
| webgl | WebGLRenderingContextBase | depthFunc(func: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | deleteTexture(texture: WebGLTexture \| null): void; | Added|
| webgl | WebGLRenderingContextBase | deleteShader(shader: WebGLShader \| null): void; | Added|
| webgl | WebGLRenderingContextBase | deleteRenderbuffer(renderbuffer: WebGLRenderbuffer \| null): void; | Added|
| webgl | WebGLRenderingContextBase | deleteProgram(program: WebGLProgram \| null): void; | Added|
| webgl | WebGLRenderingContextBase | deleteFramebuffer(framebuffer: WebGLFramebuffer \| null): void; | Added|
| webgl | WebGLRenderingContextBase | deleteBuffer(buffer: WebGLBuffer \| null): void; | Added|
| webgl | WebGLRenderingContextBase | cullFace(mode: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | createTexture(): WebGLTexture \| null; | Added|
| webgl | WebGLRenderingContextBase | createShader(type: GLenum): WebGLShader \| null; | Added|
| webgl | WebGLRenderingContextBase | createRenderbuffer(): WebGLRenderbuffer \| null; | Added|
| webgl | WebGLRenderingContextBase | createProgram(): WebGLProgram \| null; | Added|
| webgl | WebGLRenderingContextBase | createFramebuffer(): WebGLFramebuffer \| null; | Added|
| webgl | WebGLRenderingContextBase | createBuffer(): WebGLBuffer \| null; | Added|
| webgl | WebGLRenderingContextBase | copyTexSubImage2D(target: GLenum, level: GLint, xoffset: GLint, yoffset: GLint, x: GLint, y: GLint, width: GLsizei, height: GLsizei): void; | Added|
| webgl | WebGLRenderingContextBase | copyTexImage2D(target: GLenum, level: GLint, internalformat: GLenum, x: GLint, y: GLint, width: GLsizei, height: GLsizei, border: GLint): void; | Added|
| webgl | WebGLRenderingContextBase | compileShader(shader: WebGLShader): void; | Added|
| webgl | WebGLRenderingContextBase | colorMask(red: GLboolean, green: GLboolean, blue: GLboolean, alpha: GLboolean): void; | Added|
| webgl | WebGLRenderingContextBase | clearStencil(s: GLint): void; | Added|
| webgl | WebGLRenderingContextBase | clearDepth(depth: GLclampf): void; | Added|
| webgl | WebGLRenderingContextBase | clearColor(red: GLclampf, green: GLclampf, blue: GLclampf, alpha: GLclampf): void; | Added|
| webgl | WebGLRenderingContextBase | clear(mask: GLbitfield): void; | Added|
| webgl | WebGLRenderingContextBase | checkFramebufferStatus(target: GLenum): GLenum; | Added|
| webgl | WebGLRenderingContextBase | blendFuncSeparate(srcRGB: GLenum, dstRGB: GLenum, srcAlpha: GLenum, dstAlpha: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | blendFunc(sfactor: GLenum, dfactor: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | blendEquationSeparate(modeRGB: GLenum, modeAlpha: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | blendEquation(mode: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | blendColor(red: GLclampf, green: GLclampf, blue: GLclampf, alpha: GLclampf): void; | Added|
| webgl | WebGLRenderingContextBase | bindTexture(target: GLenum, texture: WebGLTexture \| null): void; | Added|
| webgl | WebGLRenderingContextBase | bindRenderbuffer(target: GLenum, renderbuffer: WebGLRenderbuffer \| null): void; | Added|
| webgl | WebGLRenderingContextBase | bindFramebuffer(target: GLenum, framebuffer: WebGLFramebuffer \| null): void; | Added|
| webgl | WebGLRenderingContextBase | bindBuffer(target: GLenum, buffer: WebGLBuffer \| null): void; | Added|
| webgl | WebGLRenderingContextBase | bindAttribLocation(program: WebGLProgram, index: GLuint, name: string): void; | Added|
| webgl | WebGLRenderingContextBase | attachShader(program: WebGLProgram, shader: WebGLShader): void; | Added|
| webgl | WebGLRenderingContextBase | activeTexture(texture: GLenum): void; | Added|
| webgl | WebGLRenderingContextBase | getExtension(name: string): any; | Added|
| webgl | WebGLRenderingContextBase | getSupportedExtensions(): string[] \| null; | Added|
| webgl | WebGLRenderingContextBase | isContextLost(): boolean; | Added|
| webgl | WebGLRenderingContextBase | getContextAttributes(): WebGLContextAttributes \| null; | Added|
| webgl | WebGLRenderingContextBase | readonly drawingBufferHeight: GLsizei; | Added|
| webgl | WebGLRenderingContextBase | readonly drawingBufferWidth: GLsizei; | Added|
| webgl | WebGLRenderingContextBase | readonly canvas: HTMLCanvasElement \| OffscreenCanvas; | Added|
| webgl | WebGLRenderingContextBase | readonly BROWSER_DEFAULT_WEBGL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly UNPACK_COLORSPACE_CONVERSION_WEBGL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly CONTEXT_LOST_WEBGL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly UNPACK_PREMULTIPLY_ALPHA_WEBGL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly UNPACK_FLIP_Y_WEBGL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly INVALID_FRAMEBUFFER_OPERATION: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MAX_RENDERBUFFER_SIZE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_BINDING: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_BINDING: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_UNSUPPORTED: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_INCOMPLETE_DIMENSIONS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_INCOMPLETE_ATTACHMENT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_COMPLETE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly NONE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_STENCIL_ATTACHMENT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_ATTACHMENT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_ATTACHMENT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly COLOR_ATTACHMENT0: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_OBJECT_NAME: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_STENCIL_SIZE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_DEPTH_SIZE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_ALPHA_SIZE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_BLUE_SIZE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_GREEN_SIZE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_RED_SIZE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_INTERNAL_FORMAT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_HEIGHT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER_WIDTH: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_STENCIL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_INDEX8: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_COMPONENT16: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RGB565: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RGB5_A1: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RGBA4: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERBUFFER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAMEBUFFER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly HIGH_INT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MEDIUM_INT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LOW_INT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly HIGH_FLOAT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MEDIUM_FLOAT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LOW_FLOAT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly COMPILE_STATUS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly IMPLEMENTATION_COLOR_READ_FORMAT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly IMPLEMENTATION_COLOR_READ_TYPE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_BUFFER_BINDING: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_POINTER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_NORMALIZED: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_TYPE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_STRIDE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_SIZE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VERTEX_ATTRIB_ARRAY_ENABLED: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SAMPLER_CUBE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SAMPLER_2D: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FLOAT_MAT4: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FLOAT_MAT3: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FLOAT_MAT2: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BOOL_VEC4: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BOOL_VEC3: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BOOL_VEC2: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BOOL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly INT_VEC4: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly INT_VEC3: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly INT_VEC2: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FLOAT_VEC4: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FLOAT_VEC3: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FLOAT_VEC2: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MIRRORED_REPEAT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly CLAMP_TO_EDGE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly REPEAT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ACTIVE_TEXTURE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE31: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE30: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE29: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE28: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE27: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE26: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE25: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE24: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE23: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE22: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE21: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE20: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE19: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE18: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE17: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE16: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE15: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE14: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE13: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE12: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE11: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE10: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE9: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE8: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE7: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE6: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE5: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE4: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE3: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE2: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE1: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE0: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MAX_CUBE_MAP_TEXTURE_SIZE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_NEGATIVE_Z: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_POSITIVE_Z: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_NEGATIVE_Y: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_POSITIVE_Y: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_NEGATIVE_X: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP_POSITIVE_X: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_BINDING_CUBE_MAP: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_CUBE_MAP: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_2D: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_WRAP_T: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_WRAP_S: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_MIN_FILTER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_MAG_FILTER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LINEAR_MIPMAP_LINEAR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly NEAREST_MIPMAP_LINEAR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LINEAR_MIPMAP_NEAREST: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly NEAREST_MIPMAP_NEAREST: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LINEAR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly NEAREST: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VERSION: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RENDERER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VENDOR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DECR_WRAP: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly INCR_WRAP: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly INVERT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DECR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly INCR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly REPLACE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly KEEP: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ALWAYS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly GEQUAL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly NOTEQUAL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly GREATER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LEQUAL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly EQUAL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LESS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly NEVER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly CURRENT_PROGRAM: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SHADING_LANGUAGE_VERSION: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ACTIVE_ATTRIBUTES: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ACTIVE_UNIFORMS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ATTACHED_SHADERS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VALIDATE_STATUS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LINK_STATUS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DELETE_STATUS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SHADER_TYPE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MAX_FRAGMENT_UNIFORM_VECTORS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MAX_TEXTURE_IMAGE_UNITS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MAX_VERTEX_TEXTURE_IMAGE_UNITS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MAX_COMBINED_TEXTURE_IMAGE_UNITS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MAX_VARYING_VECTORS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MAX_VERTEX_UNIFORM_VECTORS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MAX_VERTEX_ATTRIBS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VERTEX_SHADER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRAGMENT_SHADER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_SHORT_5_6_5: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_SHORT_5_5_5_1: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_SHORT_4_4_4_4: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LUMINANCE_ALPHA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LUMINANCE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RGBA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RGB: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ALPHA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_COMPONENT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FLOAT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_INT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly INT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_SHORT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SHORT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly UNSIGNED_BYTE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BYTE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly GENERATE_MIPMAP_HINT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly NICEST: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FASTEST: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DONT_CARE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly COMPRESSED_TEXTURE_FORMATS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SAMPLE_COVERAGE_INVERT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SAMPLE_COVERAGE_VALUE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SAMPLES: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SAMPLE_BUFFERS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TEXTURE_BINDING_2D: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly POLYGON_OFFSET_FACTOR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly POLYGON_OFFSET_UNITS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_BITS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_BITS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ALPHA_BITS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BLUE_BITS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly GREEN_BITS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly RED_BITS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SUBPIXEL_BITS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MAX_VIEWPORT_DIMS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly MAX_TEXTURE_SIZE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly PACK_ALIGNMENT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly UNPACK_ALIGNMENT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly COLOR_WRITEMASK: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly COLOR_CLEAR_VALUE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SCISSOR_BOX: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly VIEWPORT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_WRITEMASK: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_VALUE_MASK: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_REF: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_PASS_DEPTH_PASS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_PASS_DEPTH_FAIL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_FAIL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_BACK_FUNC: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_WRITEMASK: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_VALUE_MASK: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_REF: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_PASS_DEPTH_PASS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_PASS_DEPTH_FAIL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_FAIL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_FUNC: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_CLEAR_VALUE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_FUNC: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_CLEAR_VALUE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_WRITEMASK: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_RANGE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRONT_FACE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly CULL_FACE_MODE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ALIASED_LINE_WIDTH_RANGE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ALIASED_POINT_SIZE_RANGE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LINE_WIDTH: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly CCW: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly CW: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly OUT_OF_MEMORY: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly INVALID_OPERATION: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly INVALID_VALUE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly INVALID_ENUM: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly NO_ERROR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SAMPLE_COVERAGE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SAMPLE_ALPHA_TO_COVERAGE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly POLYGON_OFFSET_FILL: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SCISSOR_TEST: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_TEST: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_TEST: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DITHER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BLEND: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly CULL_FACE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRONT_AND_BACK: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BACK: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FRONT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly CURRENT_VERTEX_ATTRIB: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BUFFER_USAGE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BUFFER_SIZE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DYNAMIC_DRAW: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STATIC_DRAW: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STREAM_DRAW: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ELEMENT_ARRAY_BUFFER_BINDING: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ARRAY_BUFFER_BINDING: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ELEMENT_ARRAY_BUFFER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ARRAY_BUFFER: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BLEND_COLOR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_CONSTANT_ALPHA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly CONSTANT_ALPHA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_CONSTANT_COLOR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly CONSTANT_COLOR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BLEND_SRC_ALPHA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BLEND_DST_ALPHA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BLEND_SRC_RGB: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BLEND_DST_RGB: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FUNC_REVERSE_SUBTRACT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FUNC_SUBTRACT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BLEND_EQUATION_ALPHA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BLEND_EQUATION_RGB: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly BLEND_EQUATION: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly FUNC_ADD: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SRC_ALPHA_SATURATE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_DST_COLOR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DST_COLOR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_DST_ALPHA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DST_ALPHA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_SRC_ALPHA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SRC_ALPHA: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ONE_MINUS_SRC_COLOR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly SRC_COLOR: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ONE: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly ZERO: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TRIANGLE_FAN: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TRIANGLE_STRIP: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly TRIANGLES: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LINE_STRIP: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LINE_LOOP: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly LINES: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly POINTS: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly COLOR_BUFFER_BIT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly STENCIL_BUFFER_BIT: GLenum; | Added|
| webgl | WebGLRenderingContextBase | readonly DEPTH_BUFFER_BIT: GLenum; | Added|
| webgl | WebGLShaderPrecisionFormat | readonly precision: GLint; | Added|
| webgl | WebGLShaderPrecisionFormat | readonly rangeMax: GLint; | Added|
| webgl | WebGLShaderPrecisionFormat | readonly rangeMin: GLint; | Added|
| webgl | WebGLActiveInfo | readonly name: string; | Added|
| webgl | WebGLActiveInfo | readonly type: GLenum; | Added|
| webgl | WebGLActiveInfo | readonly size: GLint; | Added|
| webgl | WebGLContextAttributes | desynchronized?: boolean; | Added|
| webgl | WebGLContextAttributes | failIfMajorPerformanceCaveat?: boolean; | Added|
| webgl | WebGLContextAttributes | powerPreference?: WebGLPowerPreference; | Added|
| webgl | WebGLContextAttributes | preserveDrawingBuffer?: boolean; | Added|
| webgl | WebGLContextAttributes | premultipliedAlpha?: boolean; | Added|
| webgl | WebGLContextAttributes | antialias?: boolean; | Added|
| webgl | WebGLContextAttributes | stencil?: boolean; | Added|
| webgl | WebGLContextAttributes | depth?: boolean; | Added|
| webgl | WebGLContextAttributes | alpha?: boolean; | Added|
