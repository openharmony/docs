# Image

Image是图片组件，用来渲染展示图片。具体用法请参考[Image API](../reference/arkui-js/js-components-basic-image.md)。


## 创建Image组件

在pages/index目录下的hml文件中创建一个Image组件。
```
<!-- index.hml -->
<div class="container">
  <image style="height: 30%;" src="common/images/bg-tv.jpg"> </image>
</div>
```

```
/* xxx.css */
.container {
  width: 100%;
  height: 100%; 
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #F1F3F5;
}
```

![zh-cn_image_0000001211227617](figures/zh-cn_image_0000001211227617.png)


## 设置Image样式

通过设置width、height和object-fit属性定义图片的宽、高和缩放样式。


```
<!-- index.hml -->
<div class="container">
  <image src="common/images/bg-tv.jpg"> </image>
</div>
```


```
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background-color:#F1F3F5;
}
image{
  width: 80%;  
  height: 500px;
  border: 5px solid saddlebrown;
  border-radius: 20px;
  object-fit: contain;
  match-text-direction:true;
}
```


![zh-cn_image_0000001163532072](figures/zh-cn_image_0000001163532072.png)


## 显示多张图

定义for循环展示多张图片，同时定义option选择图片的展示方式，选择方式请参考object-fit类型说明。
```
<!-- index.hml -->
<div class="page-container">
  <list>
    <list-item class="item-container" for="{{list}}">
      <div>
        <image class="testimage" src="{{url[$idx]}}" style="object-fit: {{fit}};">  
        </image>
        <div class="text-container">
          <text style="font-size: 32px;color:#7b68ee;">image{{$idx}}</text>
          <text style="font-size: 23px;color: orange;font-style: italic;">content</text>
        </div>
      </div>
    </list-item>
  </list>
  <div style="width: 100%;height:100px;justify-content: center;margin-top: 100px;flex-shrink: 0;">
    <select id="slt2" style="border: 3px solid orange;color: orange;font-size: 40px;width:300px;height:160px;" onchange="setfit">
      <option for="{{fit_list}}" value="{{$item}}" style="font-size: 36px;">{{$item}}</option>
    </select>
  </div>
</div>
```

```
/* xxx.css */
.page-container {
  flex-direction:column;
  background-color:#F1F3F5;
}
.text-container {
  width: 300px;
  flex-direction: column;
  justify-content: center;
}
.item-container {
  flex-direction: row;
  align-items: center;
  justify-content:center;
  margin-top:200px;
}
.testimage {
  width: 175px;
  height: 220px;
  border: 5px solid #add8e6;
  padding: 5px 5px 5px 5px;
  margin: 5px 5px 5px 5px;
}
.testicon {
  width: 50px;
  height: 50px;
  margin-left: 150px;
  border-radius: 25px;
  background-color: orange;
}
```

```
/* index.js */
export default {
  data: {
    url:['common/images/bg-tv.jpg','common/images/img2.jpg'],
    list:[0,1],
    fit:'cover',
    fit_list:['cover','contain','fill','none','scale-down']
  },
  setfit(e) {
    this.fit = e.newValue
  }
}
```


![zh-cn_image_0000001208787005](figures/zh-cn_image_0000001208787005.gif)


## 加载图片

图片成功加载时触发complete事件，返回加载的图源尺寸。加载失败则触发error事件，打印图片加载失败。

```
<!-- index.hml -->
<div class="container" >
  <div>
    <image src="common/images/bg-tv.jpg" oncomplete="imageComplete(1)" onerror="imageError(1)"> </image>
  </div>
  <div>
    <image src="common/images/bg-tv1.jpg" oncomplete="imageComplete(2)" onerror="imageError(2)"> </image>
  </div>
</div>
```

```
/* xxx.css */
.container{
  flex-direction: column;
  justify-content: center;
  align-self: center;
  background-color: #F1F3F5;
}
.container div{
  margin-left: 10%;
  width: 80%;
  height: 300px;
  margin-bottom: 40px;
}
```

```
/* index.js */
import prompt from '@system.prompt';
export default {
  imageComplete(i,e){
    prompt.showToast({
      message: "Image "+i+"'s width"+ e.width+"----Image "+i+"'s height"+e.height,
      duration: 3000,
    })
  },
  imageError(i,e){
    setTimeout(()=>{
      prompt.showToast({
        message: "Failed to load image "+i+".",
        duration: 3000,
      })
    },3000)
  }
}
```

![zh-cn_image_0000001188931396](figures/zh-cn_image_0000001188931396.gif)


## 场景示例

在本场景中，开发者长按图片后将慢慢隐藏图片，当完全隐藏后再重新显示原始图片。定时器setInterval每隔一段时间改变图片透明度,实现慢慢隐藏的效果，当透明度为0时清除定时器，设置透明度为1。
```
<!-- index.hml -->
<div class="page-container">
  <div class="content">
    <div class="image-container">
      <image class="testimage" src="{{testuri}}" style="display:{{displaytype}};opacity:{{imageopacity}};" onclick="changedisplaytype" onlongpress="changeopacity"> </image>
    </div>
    <div class="text-container">
      <text style="font-size: 37px;font-weight:bold;color:orange;text-align: center;width: 100%;">Touch and hold the image</text>
    </div>
  </div>
</div>
```

```
/* xxx.css */
.page-container {
  flex-direction:column;
  align-self: center;
  justify-content: center;
  background-color:#F1F3F5;
  background-color: #F1F3F5;
}
.content{
  flex-direction:column;
}
.image-container {
  width: 100%;
  height: 300px;
  align-items: center;
  justify-content: center;
}
.text-container {
  margin-top:50px;
  width: 100%;
  height: 60px;
  flex-direction: row;
  justify-content: space-between;
}
.testimage {
  width: 100%;  height: 400px;   
  object-fit: scale-down;  
  border-radius: 20px;
}
```

```
/* index.js */
import prompt from '@system.prompt';
export default {
  data: {
    testuri: 'common/images/bg-tv.jpg',
    imageopacity:1,
    timer: null
  },
  changeopacity: function () {
    prompt.showToast({
      message: 'Touch and hold the image.'
    })
    var opval = this.imageopacity * 20
    clearInterval(this.timer);
    this.timer = setInterval(()=>{
      opval--;
      this.imageopacity = opval / 20
      if (opval===0) {
        clearInterval(this.timer)
        this.imageopacity = 1
      }
    },100);
  }
}
```

![zh-cn_image_0000001188771430](figures/zh-cn_image_0000001188771430.gif)
