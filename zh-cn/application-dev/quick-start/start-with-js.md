# 使用JS语言开发

为确保运行效果，本文以使用**DevEco Studio 3.0.0.601 Beta1**版本为例，点击[此处](https://developer.harmonyos.com/cn/develop/deveco-studio#download_beta)获取下载链接。

## 编写第一个页面

1. 第一个页面内有一个文本和一个按钮，通过text和button组件来实现。
   在“Project“窗口，选择entry &gt; src &gt; main &gt; js &gt; default &gt; pages &gt; index，打开index.hml文件，添加一个文本和一个按钮，示例代码如下：
   
   ```
   <!-- index.hml -->
   <div class="container">
       <!-- 添加一个文本 -->
       <text class="text">
           Hello World
       </text>
       <!-- 添加一个按钮，按钮样式设置为胶囊型，文本显示为Next，绑定launch事件 -->
       <button class="button" type="capsule" value="Next" onclick="launch"></button>
   </div>
   ```
   
2. 打开index.css文件，设置文本和按钮的样式，示例代码如下：
	```
   /* index.css */
   .container {
       flex-direction: column; /* 设置容器内的项目纵向排列 */
       justify-content: center; /* 设置项目位于容器主轴的中心 */
       align-items: center; /* 项目在交叉轴居中 */
       width:100%;
       height:100%;
   }
   /* 对class="text"的组件设置样式 */
   .text{
       font-size: 42px;
   }
   /* 对class="button"的组件设置样式 */
   .button {
       width: 240px;
       height: 60px;
       background-color: #007dff;
       font-size: 30px;
       text-color: white;
       margin-top: 20px;
   }
	```

3. 使用[预览器](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/previewer-0000001054328973#ZH-CN_TOPIC_0000001056725592__section16523172216252)运行项目，效果如下图所示：

   ![zh-cn_image_0000001217683803](figures/zh-cn_image_0000001217683803.png)


## 创建另一个页面

1. 在“Project“窗口，打开entry &gt; src &gt; main &gt; js &gt; default，右键点击pages文件夹，选择New &gt; JS Page，命名为details，单击回车键。
   创建完成后，可以看到pages文件夹下的文件目录结构如下：

   ![zh-cn_image_0000001217523751](figures/zh-cn_image_0000001217523751.png)

2. 打开details.hml文件，添加一个文本，示例代码如下：
   ```
   <!-- details.hml -->
   <div class="container">
     <text class="text">
       Hi there
     </text>
   </div>
   ```

3. 打开details.css文件，设置文本的样式，示例代码如下：
   ```
   /* details.css */
   .container {
       flex-direction: column;
       justify-content: center;
       align-items: center;
       width:100%;
       height:100%;
   }
   .text {
       font-size: 42px;
       text-align: center;
   }
   ```


## 实现页面跳转

1. 打开第一个页面的index.js文件，导入router模块，页面路由router根据页面的uri来找到目标页面，从而实现跳转。示例代码如下：
   ```
   // index.js
   import router from '@system.router';

   export default {
     launch() {
       router.push ({
         uri:'pages/details/details', // 指定要跳转的页面
       })
     }
   }
   ```

2. 再次使用[预览器](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/previewer-0000001054328973#ZH-CN_TOPIC_0000001056725592__section16523172216252)运行项目，效果如下图所示：
   
![zh-cn_image_0000001217402315](figures/zh-cn_image_0000001217402315.png)

恭喜你，至此已成功完成OpenHarmony快速入门-使用JS语言开发。