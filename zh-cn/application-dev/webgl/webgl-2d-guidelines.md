#  使用WebGL绘制图形

## 场景介绍

WebGL的全称为Web Graphic Library（网页图形库），主要用于交互式渲染2D图形。目前OpenHarmony中使用的WebGL是基于OpenGL裁剪的OpenGL ES，可以在HTML5的Canvas元素对象中使用，无需使用插件，支持跨平台。WebGL程序是由JavaScript代码组成的，其中使用的API可以利用用户设备提供的GPU硬件完成图形渲染和加速。更多信息请参考[WebGL™标准](https://www.khronos.org/registry/webgl/specs/latest/1.0/)。

> **说明：**
>
> 目前该功能仅支持使用兼容JS的类Web开发范式开发。

## 基本概念

### 着色器程序

将缓冲区中的数据推送到着色器中还需涉及“着色器程序”，一个负责关联着色器和缓冲区的JavaScript对象。一个WebGLProgram对象由两个编译过后的 WebGLShader组成，即顶点着色器和片元着色器（均由GLSL语言所写）。

###  着色器

着色器可以理解为运行在显卡中的指令和数据。在WebGL中，着色器是用OpenGL ES着色语言（GLSL）编写的。

完整的着色器包括顶点着色器和片元着色器。顶点着色器和片元着色器的交互则涉及到图片光栅化。

- 顶点着色器：最基本的任务是接收三维空间中点的坐标，将其处理为二维空间中的坐标并输出。

- 片元着色器：最基本的任务是对需要处理的屏幕上的每个像素输出一个颜色值。

###  图片光栅化

将顶点着色器输出的二维空间中的点坐标，转化为需要处理的像素并传递给片元着色器的过程。

### 帧缓冲对象

帧缓冲区对象为绘图缓冲区提供替代呈现目标。它们是颜色、字母、深度和模板缓冲区的集合，通常用于渲染图像。

###  纹理

纹理是一种图像，可以应用到3D模型的表面上。WebGL中的纹理有许多属性，包括宽度、高度、格式和类型。在使用纹理时，需要将其加载到WebGL中，并将其绑定到一个纹理单元上。


## 变量与接口说明

### 变量类型

| 类型         | 对应Web IDL类型         | 描述                                                         |
| ------------ | -------------------- | ------------------------------------------------------------ |
| GLenum     | unsigned long     | 用于枚举。        |
| GLboolean  | boolean            | 纹理true或者false。 |
| GLbitfield | unsigned long      | 无符号整数，可以包含多个位标志。每个位标志都代表一个特定的选项 |
| GLbyte     | byte               | 纹理八位（一个字节），2的补码表示的有符号整数。                |
| GLshort    | short              | 16位2的补码表示的有符号整数。                             |
| GLint      | long               | 32位2的补码表示的有符号整数。                           |
| GLsizei    | long               | 用来描述尺寸（例如：绘画缓冲drawing buffer 的宽和高）。      |
| GLintptr   | long long          | 用来表示指针的特殊类型，通常用于指定缓冲区对象的偏移量。       |
| GLsizeiptr | long long          | 用来表示指针的特殊类型，通常用于指定缓冲区对象的大小。         |
| GLubyte    | octet              | 八位（一个字节）2的补码表示的无符号整数。                 |
| GLushort   | unsigned short     | 16位2的补码表示的无符号整数。                          |
| GLuint    | unsigned short     | 32位2的补码表示的有符号整数。                        |
| GLfloat   | unrestricted float | 32位的IEEE标准的浮点数。                             |
| GLclampf   | unrestricted float | 限值32位IEEE浮点数。                                      |

### 接口说明

| 接口名                                                       | 描述                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------ |
| canvas.getContext                                            | 获取canvas对象上下文。                                 |
| webgl.createBuffer(): WebGLBuffer \| null                    | 创建与初始化WebGL数据缓冲区。                          |
| webgl.bindBuffer(target: GLenum, buffer: WebGLBuffer \| null): void | 将WebGL数据缓冲区与目标进行绑定。                      |
| webgl.bufferData(target: GLenum, srcData: ArrayBufferView, usage: GLenum, srcOffset: GLuint, length?: GLuint): void | 创建并初始化WebGL的数据存储区。                        |
| webgl.getAttribLocation(program: WebGLProgram, name: string): GLint | 从给定WebGL着色程序中获取着色器中attribute变量的地址。 |
| webgl.vertexAttribPointer(index GLuint, size: GLint, type: GLenum, normalized: GLboolean, stride: GLsizei, offset: GLintptr): void | 将缓冲区对象分配给变量。                               |
| webgl.enableVertexAttribArray(index: GLuint): void           | 连接变量与分配给它的缓冲区对象。                       |
| webgl.clearColor(red: GLclampf, green:GLclampf, blue: GLclampf, alpha: GLclampf): void | 清空&lt;canvas&gt;指定的颜色。                         |
| webgl.clear(mask: GLbitfield): void                          | 清空&lt;canvas&gt;。                                   |
| webgl.drawArrays(mode: GLenum, first:;GLint, count: GLsizei): void | 执行数据绘制。                                         |
| webgl.flush(): void                                          | 刷新数据至GPU，清空缓冲区。                            |
| webgl.createProgram(): WebGLProgram \| null                  | 创建着色器程序对象。                                   |

## 开发步骤

 如下以实现一个彩色正方形为例，来演示使用WebGL绘制2D图形的过程。
 
1. 使用WebGL进行3D渲染前，首先需要一个Canvas元素。以下示例创建了一个Canvas元素并设置一个onclick事件处理程序来初始化WebGL上下文。
 
   ```hml
    <div class="container">
        <canvas ref="canvas1" style="width : 400px; height : 400px; background-color : lightyellow;"></canvas>
        <button class="btn-button" onclick="BtnColorTriangle">BtnColorTriangle</button>
    </div>
   ```

2. 设置WebGL的上下文。

   - JavaScript 代码中的 main() 函数将会在文档加载完成之后被调用。它的任务是设置WebGL上下文并开始渲染内容。

   - 当获取到canvas之后，会调用getContext函数并向它传递 "webgl" 参数，来尝试获取WebGLRenderingContext。如果浏览器不支持WebGL， getContext将会返回null，如果WebGL上下文成功初始化，变量'gl'会用来引用该上下文。

   ```js
   function main() {
     const canvas = document.querySelector("#glcanvas");
     // 初始化WebGL上下文
     const gl = canvas.getContext("webgl");

     // 确认WebGL支持性
     if (!gl) {
       alert("你的浏览器、操作系统或硬件等可能不支持WebGL。");
       return;
     }
     // 使用完全不透明的黑色清除所有图像
     gl.clearColor(0.0, 0.0, 0.0, 1.0);
     // 用上面指定的颜色清除缓冲区
     gl.clear(gl.COLOR_BUFFER_BIT);
   }
   ```
3. 定义顶点着色器。

   顶点着色器需要对顶点坐标进行必要的转换，在每个顶点基础上进行其他调整或计算，然后通过将其保存在由GLSL提供的特殊变量中来返回变换后的顶点。

   在矩阵计算之前需要先引入gl-matrix开源工具库，可以从[gl-matrix官网](https://glmatrix.net/)下载，也可以使用npm命令下载：
   ```
   npm install gl-matrix
   ```
   ```js
   // 引入mat4
   import { mat4 } from 'gl-matrix'
   const vsSource = `
       attribute vec4 aVertexPosition;
       uniform mat4 uModelViewMatrix;
       uniform mat4 uProjectionMatrix;
       void main() {
         gl_Position = uProjectionMatrix * uModelViewMatrix * aVertexPosition;
       }
     `;
   ```

4. 定义片段着色器。

   片段着色器在顶点着色器处理完图形的顶点后，会被要绘制的每个图形的每个像素点调用一次。

   ```js
   const fsSource = `
       void main() {
         gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
       }
    `;
   ```
5. 将着色器传递给WebGL。

   定义顶点着色器与片段着色器之后，需要将它们传递给WebGL，并将其编译连接在一起。

   如下代码通过调用 loadShader()，为着色器传递类型和来源。创建了两个着色器。然后创建一个附加着色器的程序，将它们连接在一起。如果编译或链接失败，代码将弹出alert。

   ```js
   // 初始化着色器程序，让WebGL知道如何绘制数据
   function initShaderProgram(gl, vsSource, fsSource) {
     const vertexShader = loadShader(gl, gl.VERTEX_SHADER, vsSource);
     const fragmentShader = loadShader(gl, gl.FRAGMENT_SHADER, fsSource);
     // 创建着色器程序
     const shaderProgram = gl.createProgram();
     gl.attachShader(shaderProgram, vertexShader);
     gl.attachShader(shaderProgram, fragmentShader);
     gl.linkProgram(shaderProgram);
     // 如果创建失败，将会弹出alert
     if (!gl.getProgramParameter(shaderProgram, gl.LINK_STATUS)) {
       alert(
         "无法初始化着色器程序: " +
        gl.getProgramInfoLog(shaderProgram),
       );
       return null;
     }
     return shaderProgram;
   }
   // 创建指定类型的着色器，上传source源码并编译
   function loadShader(gl, type, source) {
     const shader = gl.createShader(type);
     // 将资源发送到着色器对象
     gl.shaderSource(shader, source);
     // 编译着色器程序
     gl.compileShader(shader);
     // 查看是否编译成功
     if (!gl.getShaderParameter(shader, gl.COMPILE_STATUS)) {
       alert(
      "编译着色器时出错：" + gl.getShaderInfoLog(shader),
       );
       gl.deleteShader(shader);
       return null;
     }
     return shader;
   }
   ```
6. 查找WebGL返回分配的输入位置。

   - 在创建着色器程序之后，需要查找WebGL返回分配的输入位置。上述有一个属性和两个Uniform。

   - 属性从缓冲区接收值。顶点着色器的每次迭代都从分配给该属性的缓冲区接收下一个值。

   - Uniform类似于JavaScript全局变量。它们在着色器的所有迭代中保持相同的值。由于属性的位置是特定于单个着色器程序的，因此将它们存储在一起以易于传递。

   ```js
   const programInfo = {
     program: shaderProgram,
     attribLocations: {
       vertexPosition: gl.getAttribLocation(shaderProgram, "aVertexPosition"),
     },
     uniformLocations: {
       projectionMatrix: gl.getUniformLocation(shaderProgram, "uProjectionMatrix"),
       modelViewMatrix: gl.getUniformLocation(shaderProgram, "uModelViewMatrix"),
     },
   };
   ```

7. 创建缓冲器对象。

   - 在画正方形前，需要创建一个缓冲器来存储它的顶点。

   - 首先调用gl的成员函数createBuffer()得到缓冲对象并存储在顶点缓冲器。然后调用 bindBuffer() 函数绑定上下文。

   - 创建一个Javascript数组去记录每一个正方体的每一个顶点。然后将其转化为WebGL浮点型类型的数组，并将其传到gl对象的bufferData()方法来建立对象的顶点。

   ```js
   function initBuffers(gl) {
     const positionBuffer = initPositionBuffer(gl);
     return {
       position: positionBuffer,
     };
   }
   function initPositionBuffer(gl) {
     // 为正方形的位置创建一个缓冲区。
     const positionBuffer = gl.createBuffer();
     // 选择positionBuffer作为应用缓冲区的位置。
     gl.bindBuffer(gl.ARRAY_BUFFER, positionBuffer);
     // 创建一个正方形的位置数组。
     const positions = [1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0, -1.0];
     //将位置列表传递给WebGL以构建形状。
     gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(positions), gl.STATIC_DRAW);
     return positionBuffer;
   }
   export { initBuffers };
   ```

8. 渲染场景。

   - 用背景色擦除画布，然后建立摄像机透视矩阵。设置45度的视图角度，并且设置一个适合实际图像的宽高比。指定在摄像机距离0.1到100单位长度的范围内的物体可见。

   - 加载特定位置，并把正方形放在距离摄像机6个单位的位置。然后，绑定正方形的顶点缓冲到上下文，并配置好，再通过调用drawArrays()方法来画出对象。

   ```js
   function drawScene(gl, programInfo, buffers) {
     gl.clearColor(0.0, 0.0, 0.0, 1.0); 
     gl.clearDepth(1.0); // 清除所有内容。
     gl.depthFunc(gl.LEQUAL); 
     // 清除画布。
      gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
     //创建透视矩阵用于模拟相机中的透视变形。
     const fieldOfView = (45 * Math.PI) / 180; 
     const aspect = gl.canvas.clientWidth / gl.canvas.clientHeight;
     const zNear = 0.1;
     const zFar = 100.0;
     const projectionMatrix = mat4.create();
     mat4.perspective(projectionMatrix, fieldOfView, aspect, zNear, zFar);
     // 将绘制位置设置为标识点，即场景的中心。
     const modelViewMatrix = mat4.create();
     // 开始绘制正方形。
     mat4.translate(
       modelViewMatrix, // 目标矩阵
       modelViewMatrix, // 要转换的矩阵
       [-0.0, 0.0, -6.0],
     ); 
     {
       const numComponents = 2; 
       const type = gl.FLOAT; 
       const normalize = false; 
       const stride = 0; // 从一组值到下一组值需要多少字节
       const offset = 0; 
       gl.bindBuffer(gl.ARRAY_BUFFER, buffers.position);
       gl.vertexAttribPointer(
         programInfo.attribLocations.vertexPosition,
         numComponents,
         type,
         normalize,
         stride,
         offset,
       );
       gl.enableVertexAttribArray(programInfo.attribLocations.vertexPosition);
     }
     gl.useProgram(programInfo.program);
     gl.uniformMatrix4fv(
       programInfo.uniformLocations.projectionMatrix,
       false,
       projectionMatrix,
     );
     gl.uniformMatrix4fv(
       programInfo.uniformLocations.modelViewMatrix,
       false,
       modelViewMatrix,
     );
     {
       const offset = 0;
       const vertexCount = 4;
       gl.drawArrays(gl.TRIANGLE_STRIP, offset, vertexCount);
     }
   }
   // 告诉WebGL如何从位置中拉出位置缓冲到vertexPosition属性中。
   function setPositionAttribute(gl, buffers, programInfo) {
     const numComponents = 2; 
     const type = gl.FLOAT; 
     const normalize = false;  
     const stride = 0; // 从一组值到下一组值需要多少字节
     const offset = 0;
     gl.bindBuffer(gl.ARRAY_BUFFER, buffers.position);
     gl.vertexAttribPointer(
       programInfo.attribLocations.vertexPosition,
       numComponents,
       type,
       normalize,
       stride,
       offset,
     );
     gl.enableVertexAttribArray(programInfo.attribLocations.vertexPosition);
   }
   export { drawScene };
   ```

最终实现效果示意如下：

![实现效果](figures/square.png)