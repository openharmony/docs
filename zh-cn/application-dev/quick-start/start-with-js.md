# 使用JS语言开发

- [编写第一个页面](#编写第一个页面)
- [创建另一个页面](#创建另一个页面)
- [实现页面跳转](#实现页面跳转)

## 编写第一个页面

1. 第一个页面内有一个文本和一个按钮，通过text和button组件来实现。
   在 “Project“窗口，选择“entry &gt; src &gt; main &gt; js &gt; default &gt; pages &gt; index”，打开”index.hml“文件，添加一个文本和一个按钮，示例代码如下：
   
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
   
2. 打开“index.css”文件，设置文本和按钮的样式，示例代码如下：
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

3. 使用[预览器](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/previewer-0000001054328973#ZH-CN_TOPIC_0000001056725592__section16523172216252)或[模拟器](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/run_simulator-0000001053303709)运行项目，效果如下图所示：
   ![zh-cn_image_0000001212066021](figures/zh-cn_image_0000001212066021.png)


## 创建另一个页面

1. 在 “Project“窗口，打开“entry &gt; src &gt; main &gt; js &gt; default”，右键点击“pages”文件夹，选择“New > JS Page”，命名为“details”，单击回车键。
   创建完成后，可以看到pages文件夹下的文件目录结构如下：

   ![zh-cn_image_0000001166744640](figures/zh-cn_image_0000001166744640.png)

2. 打开“details.hml”文件，添加一个文本，示例代码如下：
   ```
   <!-- details.hml -->
   <div class="container">
     <text class="text">
       Hi there
     </text>
   </div>
   ```

3. 打开“details.css”文件，设置文本的样式，示例代码如下：
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

1. 打开第一个页面的“index.js”文件，导入router模块，页面路由router根据页面的uri来找到目标页面，从而实现跳转。示例代码如下：
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

2. 再次使用[预览器](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/previewer-0000001054328973#ZH-CN_TOPIC_0000001056725592__section16523172216252)或[模拟器](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/run_simulator-0000001053303709)运行项目，效果如下图所示：
   ![zh-cn_image_0000001166904582](figures/zh-cn_image_0000001166904582.png)

恭喜你，至此已成功完成OpenHarmony快速入门-使用JS语言开发。
