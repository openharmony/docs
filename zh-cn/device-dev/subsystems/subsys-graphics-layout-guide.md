# 布局容器类组件开发指导


布局类容器组件由视图基础类组成，通过直接设置视图位置，可以达到嵌套和重叠布局的目的；通过设置布局类型和边距达到规格化布局子组件的目的；通过调用相关接口可实现根据父组件及兄弟节点布局视图的目的。


## UISwipeView


### 使用场景

UISwipeView继承UIViewGroup，除提供容器类组件Add、Remove、Insert等方法外还提供按页面滑动功能，滑动结束后当前页面居中对齐显示。该组件分为水平方向和垂直方向，通过Add方法添加的子组件会根据Add的顺序和UISwipeView方向自动水平对齐或者垂直对齐。


### 接口说明

  **表1** SwipeView接口说明

| 方法 | 功能 | 
| -------- | -------- |
| void&nbsp;SetCurrentPage(uint16_t&nbsp;index); | 设置当前页 | 
| uint16_t&nbsp;GetCurrentPage() | 获取当前页 | 
| UIView\*&nbsp;GetCurrentView()&nbsp;const | 获取当前页组件 | 
| void&nbsp;SetOnSwipeListener(OnSwipeListener&amp;&nbsp;onSwipeListener) | 设置滑动回调类 | 
| void&nbsp;SetAnimatorTime(uint16_t&nbsp;time); | 设置动画事件 | 
| void&nbsp;SetLoopState(bool&nbsp;loop) | 设置是否循环 | 
| UIView\*&nbsp;GetViewByIndex(uint16_t&nbsp;index); | 通过index获取view | 


### 开发步骤（水平滑动，不可循环）

1. 创建一个水平滑动的UISwipeView。
     
   ```
   UISwipeView* swipe = new UISwipeView(UISwipeView::HORIZONTAL);
   ```

2. 向UISwipeView中添加子组件。
     
   ```
   UILabelButton* button1 = new UILabelButton();
   button1->SetPosition(0, 0, g_ButtonW, g_ButtonH);
   button1->SetText("button1");
   swipe->Add(button1);
   UILabelButton* button2 = new UILabelButton();
   button2->SetPosition(0, 0, g_ButtonW, g_ButtonH);
   button2->SetText("button2");
   swipe->Add(button2);
   UILabelButton* button3 = new UILabelButton();
   button3->SetPosition(0, 0, g_ButtonW, g_ButtonH);
   button3->SetText("button3");
   swipe->Add(button3);
   ```

3. 检查实现效果，水平滑动，不可循环。
     
     **图1** UISwipeView水平滑动效果图

     ![zh-cn_image_0000001153991438](figures/zh-cn_image_0000001153991438.gif)


### 开发步骤（水平滑动，可循环）

1. 创建一个水平滑动的UISwipeView并添加子组件。
     
   ```
   UISwipeView* swipe = new UISwipeView(UISwipeView::HORIZONTAL);
   UILabelButton* button1 = new UILabelButton();
   button1->SetPosition(0, 0, g_ButtonW, g_ButtonH);
   button1->SetText("button1");
   swipe->Add(button1);
   UILabelButton* button2 = new UILabelButton();
   button2->SetPosition(0, 0, g_ButtonW, g_ButtonH);
   button2->SetText("button2");
   swipe->Add(button2);
   UILabelButton* button3 = new UILabelButton();
   button3->SetPosition(0, 0, g_ButtonW, g_ButtonH);
   button3->SetText("button3");
   swipe->Add(button3);
   ```

2. 设置UISwipeView循环滑动。
     
   ```
   swipe->SetLoopState(true);
   ```

3. 检查实现效果，水平循环滑动。
     
     **图2** UISwipeView水平滑动循环效果图

     ![zh-cn_image_0000001200110781](figures/zh-cn_image_0000001200110781.gif)


## GridLayout


### 使用场景

提供基础布局能力，可设置网格行数和列数，通过Add方法添加的子组件在调用LayoutChildren()方法后自动进行排列布局。


### 接口说明

  **表2** GridLayout接口说明

| 方法 | 功能 | 
| -------- | -------- |
| void&nbsp;SetRows(const&nbsp;uint16_t&amp;&nbsp;rows) | 设置行数 | 
| void&nbsp;SetCols(const&nbsp;uint16_t&amp;&nbsp;cols) | 设置列数 | 
| void&nbsp;LayoutChildren(bool&nbsp;needInvalidate&nbsp;=&nbsp;false) | 布局子组件 | 


### 开发步骤

1. 构造GridLayout并设置位置、大小信息。
     
   ```
   GridLayout* layout_ = new GridLayout();
   layout_->SetPosition(0, g_y, HROIZONTAL_RESOLUTION, 200);
   layout_->SetLayoutDirection(LAYOUT_HOR);
   layout_->SetRows(2);
   layout_->SetCols(2);
   ```

2. 构造子组件button。
     
   ```
   UILabelButton* bt1 = new UILabelButton();
   bt1->SetPosition(0,0,100,50);
   bt1->SetText("bt1");
   UILabelButton* bt2 = new UILabelButton();
   bt2->SetPosition(0, 0, 100, 50);
   bt2->SetText("bt2");
   UILabelButton* bt3 = new UILabelButton();
   bt3->SetPosition(0, 0, 100, 50);
   bt3->SetText("bt3");
   UILabelButton* bt4 = new UILabelButton();
   bt4->SetPosition(0, 0, 100, 50);
   bt4->SetText("bt4");
   ```

3. 添加子组件并调用LayoutChildren()。
     
   ```
   layout_->Add(bt1);
   layout_->Add(bt2);
   layout_->Add(bt3);
   layout_->Add(bt4);
   layout_->LayoutChildren();
   ```

4. 检查button组件布局效果如下图所示。
    
     **图3** 设置2\*2网格并添加4个button组件进行布局

     ![zh-cn_image_0000001197367495](figures/zh-cn_image_0000001197367495.png)
