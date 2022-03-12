# 系统应用常见问题<a name="ZH-CN_TOPIC_0000001169690992"></a>

-   [公共基础库常见问题](#section639433461512)
    -   [1.LiteOS-A内核\(Hi3516、Hi3518平台\)KV存储路径设置错误，导致KV存储运行失败](#section16520347131511)

-   [视觉应用常见问题](#section787718474161)
    -   [是否存在一个全局变量，所有的页面都可以访问？](#section187297991718)
    -   [如何获取dom中的元素](#section1833493719175)
    -   [如何在页面间传值？](#section184283812183)
    -   [list如何滚动到某个item？](#section11897734131811)
    -   [text支持多行吗？](#section5872656121814)
    -   [为什么控件不显示？](#section7397125317107)
    -   [如何实现页面滑动？](#section338794422010)
    -   [Left、Top为什么不生效？](#section2597193611217)
    -   [动态绑定为什么不生效？](#section6939050172115)
    -   [如何实现相对定位和绝对定位？](#section5547311192215)
    -   [如何控制控件的显示与隐藏？](#section16107113352213)
    -   [使用Margin时，有什么注意事项？](#section1524910142314)
    -   [使用事件订阅时，有什么注意事项？](#section1537132012231)
    -   [使用动态绑定时，有什么注意事项？](#section96561452236)
    -   [swiper loop属性如何生效？](#section690166112414)
    -   [使用数组时，有什么注意事项？](#section1554552822414)

-   [hdc类问题](#section412357182518)
    -   [hdc\_std连接不到设备](#section1965012223257)
    -   [hdc\_std运行不了](#section1157575212515)


## 公共基础库常见问题<a name="section639433461512"></a>

### 1.LiteOS-A内核\(Hi3516、Hi3518平台\)KV存储路径设置错误，导致KV存储运行失败<a name="section16520347131511"></a>

**现象描述**

LiteOS-A内核\(Hi3516、Hi3518平台\)直接调用KV存储提供的接口，各参数正常的情况下，编译可执行程序运行失败。

**可能原因**

直接运行编译出的可执行文件，没有将程序基于AbilityKit转换成应用，不能由BMS在应用安装时正确设置应用数据存储路径，导致KV存储运行失败。

**解决办法**

显示调用KV存储的UtilsSetEnv接口，设置数据存储路径。

```
UtilsSetEnv("/storage/com.example.kv");
```

## 视觉应用常见问题<a name="section787718474161"></a>

### 是否存在一个全局变量，所有的页面都可以访问？<a name="section187297991718"></a>

当前框架中不存在所有Page都可以访问的全局变量。

### 如何获取dom中的元素<a name="section1833493719175"></a>

如何获取dom中的元素？

通过ref属性获取dom中的元素，详细示例如下图所示；获取的元素只能使用它的方法，不能改变属性。

```
<!--index.hml-->
<div class="container">
   <!--指定组件的ref属性为animator-->
   <image-animator class="image-player" ref="ainmator" images="{{images}}" duration="1s" onclick="handleClick"></image-animator>
</div>

/* index.js */
export default {
    data: {
        images:[
            {src:"common/frame1.png"},
            {src:"common/frame2.png"},
            {src:"common/frame3.png"}
        ]
    },
    handleClick(){
        //通过$refs属性获取对应的组件，在hml中，组件的ref属性要设置为animator
        const animator = this.$refs.animator;
        const state = animator.getState();
        if(state == "paused"){
            animator.resume();
        }else if(state == "stopped"){
            animator.start();
        }else{
            animator.pause();
        }
    }
}
```

### 如何在页面间传值？<a name="section184283812183"></a>

通过router.replace方法中的params参数来传递，参考代码如下：

第一个页面传递数据：

```
router.replace({
    uri:'pages/detail/detail',  //要跳转的页面uri
    params:{transferData:this.data}  //传递的数据，数据个数和名称开发者自己定义，
});
```

第二个界面接受数据：

```
onInit(){
    const data = this.transferData;  //在onInit函数中接受传递的数据
}  
```

### list如何滚动到某个item？<a name="section11897734131811"></a>

通过list的scrollTo方法滚动到指定的item，参数是目标item的index。Index参数可以通过scrollend事件获取或者开发者指定。

### text支持多行吗？<a name="section5872656121814"></a>

text支持多行。通过回车键换行或者是不设置text的高度属性，由控件自动根据内容换行。

### 为什么控件不显示？<a name="section7397125317107"></a>

**现象描述**

开发者在hml文件中添加的控件无法显示

**可能原因**

-   未设置width和height值；
-   样式设置错误。

**处理步骤**

\(1\)检查是否设置width和height值，组件必须显式设置width和height值；

\(2\)检查组件的样式设置是否正确。

### 如何实现页面滑动？<a name="section338794422010"></a>

实现页面滑动目前有三种方式：scroll（根组件大小超过屏幕的大小即自动实现scroll效果）、list、swiper。开发者可以参考开发文档查看三者的区别，并加以使用。

### Left、Top为什么不生效？<a name="section2597193611217"></a>

除根节点外，Left、Top配合Stack组件使用才有效果。

### 动态绑定为什么不生效？<a name="section6939050172115"></a>

在进行绑定时，必须先将要绑定的对象或者对象的属性进行定义，不能先绑定后定义

### 如何实现相对定位和绝对定位？<a name="section5547311192215"></a>

使用div、stack（top left属性）来实现相对和绝对定位。

### 如何控制控件的显示与隐藏？<a name="section16107113352213"></a>

通过display、show和if来控制控件的显示与隐藏。区别在于：if为false时，组件会从VDOM中移除，而show仅是渲染时不可见，组件依然存在于VDOM中。

### 使用Margin时，有什么注意事项？<a name="section1524910142314"></a>

Stack组件不支持其子组件设置margin属性。

### 使用事件订阅时，有什么注意事项？<a name="section1537132012231"></a>

在应用运行期间只存在一个page，所以router.replace跳转是先销毁前一个页面，然后在新创建一个界面。因此，如果涉及到事件订阅的页面，每次页面创建时要进行事件订阅，跳转离开界面前取消事件订阅。

### 使用动态绑定时，有什么注意事项？<a name="section96561452236"></a>

过多的动态绑定会消耗较多的内存，若非业务需要，尽量不要使用太多的动态绑定。

### swiper loop属性如何生效？<a name="section690166112414"></a>

去掉第一个组件或者去掉最后一个组件，剩余的长度大于swiper长度，loop生效。

### 使用数组时，有什么注意事项？<a name="section1554552822414"></a>

数组元素不宜过多，尽量避免对大数组进行频繁操作。

## hdc类问题<a name="section412357182518"></a>

### hdc\_std连接不到设备<a name="section1965012223257"></a>

-   **现象描述**

    执行 "hdc\_std list targets"命令后结果为：\[Empty\]

-   **解决方法**
    1.  设备没有被识别：

        在设备管理器中查看是否有hdc设备，在通用串行总线设备中会有“HDC Device”信息。如果没有，hdc无法连接。此时需要插拔设备，或者烧写最新的镜像。

    2.  hdc\_std工作异常：

        可以执行"hdc kill"或者"hdc start -r"杀掉hdc服务或者重启hdc服务，然后再执行hdc list targets查看是否已经可以获取设备信息。

    3.  hdc\_std与设备不匹配：

        如果设备烧写的是最新镜像，hdc\_std也需要使用最新版本。由于hdc\_std会持续更新，请从开源仓developtools\_hdc\_standard中获取，具体位置在该开源仓的prebuilt目录。



### hdc\_std运行不了<a name="section1157575212515"></a>

-   **现象描述**

    点击hdc\_std.exe文件无法运行。

-   **解决方法**

    hdc\_std.exe不需要安装，直接放到磁盘上就能使用，也可以添加到环境变量中。通过打开cmd执行hdc\_std命令直接使用。


