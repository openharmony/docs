# 添加容器
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fenglinbailu-->
<!--Designer: @lanshouren-->
<!--Tester: @liuli0427-->
<!--Adviser: @HelloCrease-->

要将页面的基本元素组装在一起，需要使用容器组件。在页面布局中常用到三种容器组件，分别是div、list和tabs。在页面结构相对简单时，可以直接用div作为容器，因为div作为单纯的布局容器，可以支持多种子组件，使用起来更为方便。


## List组件

当页面结构较为复杂时，如果使用div循环渲染，容易出现卡顿，因此推荐使用list组件代替div组件实现长列表布局，从而实现更加流畅的列表滚动体验。需要注意的是，list仅支持list-item作为子组件，具体的使用示例如下：

```html
<!-- xxx.hml -->
<list class="list">
  <list-item type="listItem" for="{{textList}}">
    <text class="desc-text">{{$item.value}}</text>
  </list-item>
</list>
```

```css
/* xxx.css */
.desc-text {
  width: 683.3px;
  font-size: 35.4px;
}
```

```js
// xxx.js
export default {
  data: {
    textList:  [{value: 'JS FA'}],
  },
}
```

为避免示例代码过长，以上示例的list中只包含一个list-item，list-item中只有一个text组件。在实际应用中可以在list中加入多个list-item，同时list-item下可以包含多个其他子组件。


## Tabs组件

当页面经常需要动态加载时，推荐使用tabs组件。tabs组件支持change事件，在页签切换后触发。tabs组件仅支持一个tab-bar和一个tab-content。具体的使用示例如下：

```html
<!-- xxx.hml -->
<tabs>
  <tab-bar>
    <text>Home</text>
    <text>Index</text>
    <text>Detail</text>
  </tab-bar>
  <tab-content>
    <image src="{{homeImage}}"></image>
    <image src="{{indexImage}}"></image>
    <image src="{{detailImage}}"></image>
  </tab-content>
</tabs>
```

```js
// xxx.js
export default {
  data: {
    homeImage: '/common/home.png',
    indexImage: '/common/index.png',
    detailImage: '/common/detail.png',
  },
}
```

tab-content组件用来展示页签的内容区，高度默认充满tabs剩余空间。
