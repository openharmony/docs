# 页面路由<a name="ZH-CN_TOPIC_0000001063442795"></a>

-   [构建页面布局](#section135242911291)
-   [构建页面样式](#section174441114183216)
-   [实现跳转](#section1276711211359)

很多应用由多个页面组成，比如用户可以从音乐列表页面点击歌曲，跳转到该歌曲的播放界面。开发者需要通过页面路由将这些页面串联起来，按需实现跳转。

页面路由router根据页面的uri找到目标页面，从而实现跳转。以最基础的两个页面之间的跳转为例，具体实现步骤如下：

1.  在“Project“窗口，打开“entry \> src \> main  \>  js  \>  default“，右键点击“pages“文件夹，选择“New  \>  JS Page“，创建一个详情页。
2.  调用router.push\(\)路由到详情页。
3.  调用router.back\(\)回到首页。

## 构建页面布局<a name="section135242911291"></a>

index和detail这两个页面均包含一个text组件和button组件：text组件用来指明当前页面，button组件用来实现两个页面之间的相互跳转。hml文件代码示例如下：

```
<!-- index.hml -->
<div class="container">
  <text class="title">This is the index page.</text>
  <button type="capsule" value="Go to the second page" class="button" onclick="launch"></button>
</div>
```

```
<!-- detail.hml -->
<div class="container">
  <text class="title">This is the detail page.</text>
  <button type="capsule" value="Go back" class="button" onclick="launch"></button>
</div>
```

## 构建页面样式<a name="section174441114183216"></a>

构建index和detail页面的页面样式，text组件和button组件居中显示，两个组件之间间距为50px。css代码如下（两个页面样式代码一致）：

```
/* index.css */
/* detail.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
}

.title {
  font-size: 50px;
  margin-bottom: 50px;
}
```

## 实现跳转<a name="section1276711211359"></a>

为了使button组件的launch方法生效，需要在页面的js文件中实现跳转逻辑。调用router.push\(\)接口将uri指定的页面添加到路由栈中，即跳转到uri指定的页面。在调用router方法之前，需要导入router模块。代码示例如下：

```
// index.js
import router from '@system.router';
export default {
  launch() {
    router.push ({
      uri: 'pages/detail/detail',
    });
  },
}
```

```
// detail.js
import router from '@system.router';
export default {
  launch() {
    router.back();
  },
}
```

运行效果如下图所示：

**图 1**  页面路由效果<a name="fig41915914355"></a>  
![](figures/页面路由效果.png "页面路由效果")

