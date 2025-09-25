# Adding a Container
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fenglinbailu-->
<!--Designer: @lanshouren-->
<!--Tester: @liuli0427-->
<!--Adviser: @HelloCrease-->

To assemble the basic elements of a page, you need a container component. The &lt;div&gt;, &lt;list&gt;, and &lt;tabs&gt; components are commonly used for laying out page elements. You can use &lt;div&gt; as the container in a page with simple layout. &lt;div&gt; supports a variety of child components required to build the page.


## &lt;List&gt;

If you use &lt;div&gt; repeatedly to render a complex page, frame freezing may occur. In this case, use the &lt;list&gt; component instead of &lt;div&gt; to lay out list items, which provides a smooth list scrolling. **NOTE** that &lt;list&gt; supports only &lt;list-item&gt; as it child components. The following is an example:

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

To shorten the sample code, the list contains only one &lt;list-item&gt; component that holds only one &lt;text&gt; component. In practice, a &lt;list&gt; has multiple &lt;list-item&gt; components, and a &lt;list-item&gt; has multiple child components.


## &lt;Tabs&gt;

If your page needs to be dynamically loaded, use the &lt;tabs&gt; component. This component supports the change event, which is triggered after tab switching. A &lt;tabs&gt; component can hold only one &lt;tab-bar&gt; and one &lt;tab-content&gt;. The following is an example:

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

The &lt;tab-content&gt; component is used to display the tab content, which vertically fills the remaining space of the &lt;tabs&gt; component by default. 
