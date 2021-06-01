# Adding a Container<a name="EN-US_TOPIC_0000001062990841"></a>

-   [<List\>](#section1875054932714)
-   [<Tabs\>](#section91861363535)

To assemble the basic elements of a page, you need a container component. The  **<div\>**,  **<list\>**, and  **<tabs\>**  components are commonly used for laying out page elements. You can use  **<div\>**  as the container in a page with simple layout.  **<div\>**  supports a variety of child components required to build the page.

## <List\><a name="section1875054932714"></a>

If you use  **<div\>**  repeatedly to render a complex page, frame freezing may occur. In this case, use the  **<list\>**  component instead of  **<div\>**  to lay out list items, which provides a smooth list scrolling. Note that  **<list\>**  supports only  **<list-item\>**  as it child components. The following is an example:

```
<!-- xxx.hml -->
<list class="list">
  <list-item type="listItem" for="{{textList}}">
    <text class="desc-text">{{$item.value}}</text>
  </list-item>
</list>
```

```
/* xxx.css */
.desc-text {
  width: 683.3px;
  font-size: 35.4px;
}
```

```
// xxx.js
export default {
  data: {
    textList:  [{value: 'JS FA'}],
  },
}
```

To shorten the sample code, the list contains only one  **<list-item\>**  component that holds only one  **<text\>**  component. In practice, a  **<list\>**  has multiple  **<list-item\>**  components, and a  **<list-item\>**  has multiple child components.

## <Tabs\><a name="section91861363535"></a>

If your page needs to be dynamically loaded, use the  **<tabs\>**  component. This component supports the change event, which is triggered after tab switching. A  **<tabs\>**  component can hold only one  **<tab-bar\>**  and one  **<tab-content\>**. The following is an example:

```
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

```
// xxx.js
export default {
  data: {
    homeImage: '/common/home.png',
    indexImage: '/common/index.png',
    detailImage: '/common/detail.png',
  },
}
```

The  **<tab-content\>**  component is used to display the tab content, which vertically fills the remaining space of the  **<tabs\>**  component by default. 

