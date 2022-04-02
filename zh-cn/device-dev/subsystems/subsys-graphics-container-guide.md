# 容器类组件开发指导


容器类组件，指能包含其它UI组件的组件，容器类组件继承于UIViewGroup（带Add方法），基于实际组件的使用场景，将需要增加其他子组件的组件，放置到容器类继承结构下。如UIAnalogClock内，通常会Add需要的计步信息，时分秒图标等。


  **图1** 普通容器类组件结构

  ![zh-cn_image_0000001057990780](figures/zh-cn_image_0000001057990780.png)


RootView、UIAbstractScroll、UIPicker组件从UIViewGroup继承，UIList、UIScrollView、UISwipeView组件从UIAbstractScroll继承。


## UIViewGroup


### 使用场景

UIViewGroup是容器类组件基类，实现增加、删除、插入等操作，通过增加方法可以添加子组件。普通容器类组件子组件需要设置位置信息，位置信息为相对父组件的相对坐标。组件树结构如下图：

  **图2** 组件树结构示意图

  ![zh-cn_image_0000001197407385](figures/zh-cn_image_0000001197407385.png)

往根节点rootView里添加ViewGroup1容器组件和View1组件，往ViewGroup1容器组件里再添加View2组件和ViewGroup2容器组件，在View1之后添加View3组件。

- 关于渲染：容器类组件在渲染时会遍历所有子组件OnDraw方法，以达到刷新所有组件的目的。

- 关于坐标：子组件位置信息为相对父组件的相对坐标，系统在渲染时计算绝对坐标并显示。

- 关于树结构遍历：UIViewGroup提供如下方法实现遍历、查找、管理组件树。


### 接口说明

  **表1** ViewGroup接口说明

| 方法 | 功能 | 
| -------- | -------- |
| virtual&nbsp;void&nbsp;Add(UIView\*&nbsp;view) | 添加子组件 | 
| virtual&nbsp;void&nbsp;Insert(UIView\*&nbsp;prevView,&nbsp;UIView\*&nbsp;insertView) | 插入子组件 | 
| virtual&nbsp;void&nbsp;Remove(UIView\*&nbsp;view) | 删除子组件 | 
| virtual&nbsp;void&nbsp;RemoveAll() | 删除所有子组件 | 
| virtual&nbsp;void&nbsp;GetTargetView(const&nbsp;Point&amp;&nbsp;point,&nbsp;UIView\*\*&nbsp;last) | 获取目标视图 | 
| virtual&nbsp;void&nbsp;MoveChildByOffset(int16_t&nbsp;x,&nbsp;int16_t&nbsp;y) | 偏移子组件 | 
| UIView\*&nbsp;GetChildrenHead()&nbsp;const | 获取视图头节点 | 
| UIView\*&nbsp;GetChildrenTail()&nbsp;const | 获取视图最后那个节点 | 
| virtual&nbsp;UIView\*&nbsp;GetChildById(const&nbsp;char\*&nbsp;id)&nbsp;const&nbsp;override | 通过id获取子视图 | 


### 开发步骤

1. 构造button实例并设置坐标信息。
     
   ```
   UILabelButton* btn1 = new UILabelButton();
   btn1->SetPosition(0, 0, 100, 50);
   btn1->SetText("btn1");
   
   UILabelButton* btn2 = new UILabelButton();
   btn2->SetPosition(50, 50, 100, 50);
   btn2->SetText("btn2");
   
   UILabelButton* btn3 = new UILabelButton();
   btn3->SetPosition(100, 100, 100, 50);
   btn3->SetText("btn3");
   ```

2. 构造UIViewGroup实例，并设置坐标信息。
     
   ```
   UIViewGroup* group = new UIViewGroup();
   group->SetPosition(0, 0, 300, 300);
   ```

3. 使用Add方法添加Button实例到UIViewGroup。
     
   ```
   group->Add(btn1);
   group->Add(btn2);
   group->Add(btn3);
   ```

4. 检查ViewGroup效果如下图所示。
     
     **图3** ViewGroup添加view实例效果图

     ![zh-cn_image_0000001197367485](figures/zh-cn_image_0000001197367485.png)


## UIScrollView


### 使用场景

UIScrollView提供可滑动的容器类组件，子组件可在触摸事件驱动下上下、左右滑动，并提供水平和垂直方向的游标显示功能。


### 接口说明

  **表2** ScrollView接口说明

| 方法 | 功能 | 
| -------- | -------- |
| void&nbsp;ScrollBy(int16_t&nbsp;xDistance,&nbsp;int16_t&nbsp;yDistance) | 移动视图 | 
| void&nbsp;SetScrollbarWidth(uint8_t&nbsp;width) | 设置滑动条宽度 | 
| void&nbsp;SetHorizontalScrollState(bool&nbsp;state) | 设置水平滑动状态 | 
| bool&nbsp;GetHorizontalScrollState()&nbsp;const | 获取水平是否可滑动状态 | 
| void&nbsp;SetVerticalScrollState(bool&nbsp;state) | 设置垂直滑动状态 | 
| bool&nbsp;GetVerticalScrollState()&nbsp;const | 获取垂直是否可滑动状态 | 
| void&nbsp;SetXScrollBarVisible(bool&nbsp;state) | 设置X轴滑动条是否可见 | 
| void&nbsp;SetYScrollBarVisible(bool&nbsp;state) | 设置Y轴滑动条是否可见 | 
| void&nbsp;RegisterScrollListener(OnScrollListener\*&nbsp;scrollListener) | 注册滑动事件回调类 | 
| void&nbsp;RefreshScrollBar() | 刷新滑动条 | 
| virtual&nbsp;void&nbsp;OnScrollStart()&nbsp;{} | 滚动开始回调函数 | 
| virtual&nbsp;void&nbsp;OnScrollEnd()&nbsp;{} | 滚动结束回调函数 | 
| uint8_t&nbsp;GetScrollState()&nbsp;const | 获取滚动状态 | 
| void&nbsp;SetScrollState(uint8_t&nbsp;state) | 设置滚动状态 | 


### 开发步骤

添加两个button子组件，并显示水平、垂直方向游标。

  
```
scrollView* scroll = new UIScrollView();
scroll->SetStyle(STYLE_BACKGROUND_COLOR, Color::Red().full);
scroll->SetPosition(0,0, 200, 200);
scroll->SetXScrollBarVisible(true);
scroll->SetYScrollBarVisible(true);
UILabelButton* button1 = new UILabelButton();
button1->SetText("button1");
button1->SetPosition(0, 0, 300, 300);
UILabelButton* button2 = new UILabelButton();
button2->SetText("button2");
button2->SetPosition(0, 300, 300, 300);
scroll->Add(button1);
scroll->Add(button2);
```

  **图4** 水平、垂直方向可滑动效果图
  
  ![zh-cn_image_0000001151367828](figures/zh-cn_image_0000001151367828.gif)
