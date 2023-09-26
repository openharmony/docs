# JS语法参考


JS文件用来定义HML页面的业务逻辑，支持ECMA规范的JavaScript语言。基于JavaScript语言的动态化能力，可以使应用更加富有表现力，具备更加灵活的设计。下面讲述JS文件的编译和运行的支持情况。


## 语法

支持ES6语法。轻量级智能穿戴支持的ES6语法有限，仅支持以下ES6 语法：

1. let/const

2. arrow functions

3. class

4. default value

5. destructuring assignment

6. destructuring binding pattern

7. enhanced object initializer

8. for-of

9. rest parameter

10. template strings

- 模块声明
  使用import方法引入功能模块：


  ```
  import router from '@ohos.router';
  ```

- 代码引用
  使用import方法导入js代码：


  ```
  import utils from '../../common/utils.js';
  ```


## 对象

- 页面对象
    | 属性    | 类型              | 描述                                       |
    | ----- | --------------- | ---------------------------------------- |
    | data  | Object/Function | 页面的数据模型，类型是对象或者函数，如果类型是函数，返回值必须是对象。属性名不能以$或_开头，不要使用保留字for,&nbsp;if,&nbsp;show,&nbsp;tid。<br/> |
    | $refs | Object          | 持有注册过ref&nbsp;属性的DOM元素或子组件实例的对象。示例见[获取DOM元素](#获取dom元素)。 |


## 获取DOM元素

1. 通过$refs获取DOM元素

   ```html
   <!-- index.hml -->
   <div class="container">
     <image-animator class="image-player" ref="animator" images="{{images}}" duration="1s" onclick="handleClick"></image-animator>
   </div>
   ```


   ```js
   // index.js
   export default {
     data: {
       images: [
         { src: '/common/frame1.png' },
         { src: '/common/frame2.png' },
         { src: '/common/frame3.png' },
       ],
     },
     handleClick() {
       const animator = this.$refs.animator; // 获取ref属性为animator的DOM元素
       const state = animator.getState();
       if (state === 'paused') {
         animator.resume();
       } else if (state === 'stopped') {
         animator.start();
       } else {
         animator.pause();
       }
     },
   };
   ```


## 生命周期接口

- 页面生命周期
    | 属性        | 类型       | 参数   | 返回值  | 描述     | 触发时机                |
    | --------- | -------- | ---- | ---- | ------ | ------------------- |
    | onInit    | Function | 无    | 无    | 页面初始化  | 页面数据初始化完成时触发，只触发一次。 |
    | onReady   | Function | 无    | 无    | 页面创建完成 | 页面创建完成时触发，只触发一次。    |
    | onShow    | Function | 无    | 无    | 页面显示   | 页面显示时触发。            |
    | onHide    | Function | 无    | 无    | 页面消失   | 页面消失时触发。            |
    | onDestroy | Function | 无    | 无    | 页面销毁   | 页面销毁时触发。            |

    页面A的生命周期接口的调用顺序：
  - 打开页面A：onInit() -&gt; onReady() -&gt; onShow()

  - 在页面A打开页面B：onHide() -&gt; onDestroy()

  - 从页面B返回页面A：onInit() -&gt; onReady() -&gt; onShow()

  - 退出页面A：onHide() -&gt; onDestroy()

  - 页面隐藏到后台运行：onHide()

  - 页面从后台运行恢复到前台：onShow()

- 应用生命周期
    | 属性        | 类型       | 参数   | 返回值  | 描述   | 触发时机      |
    | --------- | -------- | ---- | ---- | ---- | --------- |
    | onCreate  | Function | 无    | 无    | 应用创建 | 当应用创建时调用。 |
    | onDestroy | Function | 无    | 无    | 应用退出 | 当应用退出时触发。 |
