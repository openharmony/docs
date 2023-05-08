# Tabs


When there is a large amount of page information, to enable the user to focus on the currently displayed content, the page content needs to be classified to improve the page space utilization. The [Tabs](../reference/arkui-ts/ts-container-tabs.md) component can quickly switch between views on a page, improving information search efficiency and reducing the amount of information that users can obtain at a time.


## Basic Layout

  The Tabs component consists of two parts: TabContent and TabBar. TabContent is the content page, and TabBar is the navigation tab bar. The following figure shows the page structure. The layout varies according to the navigation type. TabContent can be classified into bottom navigation, top navigation, and side navigation. The navigation bar is located at the bottom, top, and side, respectively.
  Figure 1 Tabs component layout 

![tabs-layout](figures/tabs-layout.png)


>**NOTE**
>
> - The **\<TabContent>** component does not support setting of the common width attribute. By default, its width is the same as that of the parent **\<Tabs>** component.
>
> - The **\<TabContent>** component does not support setting of the common height attribute. Its height is determined by the height of the parent **\<Tabs>** component and the **\<TabBar>** component.


Tabs use braces to enclose TabContent, as shown in Figure 2. TabContent displays the corresponding content page.


  Figure 2 Using Tabs and TabContent 

![tabs-tabscontent](figures/tabs-tabscontent.png)


The content corresponding to each TabContent must have a tab page, which can be configured through the tabBar attribute of TabContent. You can set the tabBar attribute on the TabContent component to set the content on the corresponding tab page. The tabBar functions as the content tab page.



```ts
 TabContent() {
   Text('Homepage content').fontSize(30)
 }
.tabBar ('Home')
```


When setting multiple contents, place them in sequence in Tabs.



```ts
Tabs() {
  TabContent() {
    Text('Homepage content').fontSize(30)
  }
  .tabBar ('Home')

  TabContent() {
    Text('Recommendation').fontSize(30)
  }
  .tabBar ('Recommend')

  TabContent() {
    Text ('Discovered content').fontSize (30)
  }
  .tabBar ('Discovery')
  
  TabContent() {
    Text ('My Content').fontSize (30)
  }
  .tabBar ("My")
}
```


## Bottom navigation

Bottom navigation is the most common navigation mode in applications. The bottom navigation is located at the bottom of the level-1 page of the application. When the user opens the application, the function classification of the entire application and the content corresponding to the tab can be distinguished. In addition, the bottom navigation is located at the bottom of the application, which facilitates one-hand operations of the user. The bottom navigation generally exists as a main navigation form of an application, and a function of the bottom navigation is to classify content that a user cares about according to a function, cater to a use habit of the user, and facilitate content switching between different modules.


  Figure 3 Navigation bar at the bottom 

![Bottom Navigation](figures/Bottom Navigation.gif)


The barPosition parameter of Tabs is used to set the position of the navigation bar. By default, the navigation bar is on the top, and the default value of the barPosition parameter is Start. To set the bottom navigation, you need to transfer parameters in Tabs. Set barPosition to End.


```ts
Tabs({ barPosition: BarPosition.End }) {
  // TabContent: home page, discovery, recommendation, and my
  ...
}
```


## Top Navigation

When there are many content categories, the probability that users browse different content is similar, and users need to quickly switch between different content categories, the top navigation mode is generally used to further divide the bottom navigation content. Common information applications classify content into attention, video, and digital, alternatively, in a theme application, a theme is further divided into a picture, a video, a font, and the like.

  Figure 4 Navigation bar on the top 

![Top Navigation](figures/Top Navigation.gif)

The default barPosition parameter of the Tabs component is Start, indicating the top navigation mode.


```ts
Tabs({ barPosition: BarPosition.Start }) {
  // TabContent: follow, video, game, digital, technology, sports, and movie
  ...
}
```


## Side Navigation

Side navigation is a navigation mode that is seldom used by applications. It is more applicable to landscape screens and is used to perform navigation operations on applications. Because the visual habit of the user is from left to right, the side navigation bar is the left sidebar by default.


  Figure 5 Side navigation bar 

![Side Navigation](figures/Side Navigation.png)


To implement the side navigation bar, you need to set the vertical attribute of Tabs to true. In the bottom navigation and top navigation implementations, the default value is false, indicating that the content page and navigation bar are arranged vertically.



```ts
Tabs({ barPosition: BarPosition.Start }) {
  // TabContent: home page, discovery, recommendation, and my
  ...
}
.vertical(true)
.barWidth(100)
.barHeight(200)
```


>**NOTE**
>
> - When vertical is set to true, the tabbar width fully occupies the screen width by default. You need to set barWidth to a proper value.
>
> - If vertical is set to true, the tabbar height is the actual content height by default. You need to set barHeight to a proper value.


## Restricting the Slide Switch of the Navigation Bar

  By default, the navigation bar supports sliding. On some pages that require multi-level classification of content information, for example, when the bottom navigation and top navigation are supported, the sliding effect of the bottom navigation bar conflicts with that of the top navigation. In this case, the sliding of the bottom navigation bar needs to be restricted, this prevents poor user experience.
  Figure 6 Restricting the sliding of the navigation bar at the bottom 

![Restricted Navigation](figures/Restricted Navigation.gif)


The attribute that controls the sliding switch is scrollable. The default value is true, indicating that the sliding switch is allowed. To restrict the sliding switch, set this parameter to false.



```ts
Tabs({ barPosition: BarPosition.End }) {
  TabContent(){
    Column(){
      Tabs(){
        //Content on the top navigation bar
        ...
      }
    }
    .backgroundColor('#ff08a8f1')
    .width('100%')
  }
  .tabBar ('Home')

  //Other TabContent content: Discover, Recommend, and My
  ...
}
.scrollable(false)
```


## Fixed navigation bar

When the content categories are relatively fixed and not scalable, for example, the bottom navigation content categories are generally fixed, and the number of categories ranges from 3 to 5, the fixed navigation bar is used. The fixed navigation bar cannot be scrolled or dragged. The content is evenly divided into the width of the tab bar.


  Figure 7 Fixed navigation bar

![Fixed Navigation](figures/Fixed Navigation.gif)


The barMode attribute of Tabs specifies whether the navigation bar can be scrolled. The default value is Fixed.



```ts
Tabs({ barPosition: BarPosition.End }) {
  // TabContent: home page, discovery, recommendation, and my
  ...
}
.barMode(BarMode.Fixed)
```


## Scrolling Navigation Bar

The scrolling navigation bar can be used to set the top navigation bar or side navigation bar. If there are many content categories and the screen width cannot accommodate all category tabs, a scrollable navigation bar is required. Users can tap and slide to load hidden tab content.


  Figure 8 Scrollable navigation bar 

![Scrolling Navigation](figures/Scrolling Navigation.gif)


To scroll the navigation bar, you need to set the barMode attribute of the Tabs component. The default value is Fixed, indicating that the navigation bar is fixed. To scroll the navigation bar, set the barMode attribute to Scrollable.



```ts
Tabs({ barPosition: BarPosition.Start }) {
  // TabContent: follow, video, game, digital, technology, sports, movie, humanities, art, nature, and military
  ...
}
.barMode(BarMode.Scrollable)
```


## Customizing the Navigation Bar

The navigation bar at the bottom is generally used as the main page of the application. For better user experience, text and corresponding semantic icons are combined to indicate the tab content. In this case, you need to customize the style of the navigation tab.


  Figure 9 Customizing the navigation bar 

![custom-navigation-bar](figures/custom-navigation-bar.png)


By default, the system uses underscores (_) to mark active tabs. The customized navigation bar needs to implement the corresponding style to distinguish active tabs from inactive tabs.


To customize the navigation bar, you need to use the tabBar parameters and transfer the customized function component style in CustomBuilder mode supported by the tabBar. For example, declare the customized function component of the TabBuilder. The input parameters include the tab text title, corresponding position index, and image resources in the selected and unselected states. The UI display style is determined based on whether the active currentIndex matches the targetIndex corresponding to the tab.



```ts
@Builder TabBuilder(title: string, targetIndex: number, selectedImg: Resource, normalImg: Resource) {
  Column() {
    Image(this.currentIndex === targetIndex ? selectedImg : normalImg)
      .size({ width: 25, height: 25 })
    Text(title)
      .fontColor(this.currentIndex === targetIndex ? '#1698CE' : '#6B6B6B')
  }
  .width('100%')
  .height(50)
  .justifyContent(FlexAlign.Center)
}
```


Transfer the customized function component to the tabBar attribute corresponding to TabContent and transfer the corresponding parameters.



```ts
TabContent() {
  Column(){
    Text('My Content') 
  }
  .width('100%')
  .height('100%')
  .backgroundColor('#007DFF')
}
.tabBar(this.TabBuilder('My', 0, $r('app.media.mine_selected'), $r('app.media.mine_normal')))
```


## Switch to a specified tab page.

If the customized navigation bar is not used, the default tabs implement the switching logic. After the customized navigation bar is used, the logic for switching tab pages needs to be manually implemented. That is, when the user taps a corresponding tab, the screen needs to display a corresponding content page.


  Figure 10 Using the customized navigation bar to switch to a specified tab page 

![Switching to a Specified Tab Page](figures/Switching to a Specified Tab Page.gif)


To switch a specified tab page, you need to use the TabsController. The TabsController is the controller of the Tabs component and is used to control the Tabs component to switch tab pages. The changeIndex method of TabsController is used to jump to the TabContent content corresponding to a specified index value.



```ts
private tabsController : TabsController = new TabsController()
@State currentIndex:number = 0;

@Builder TabBuilder(title: string, targetIndex: number) {
  Column() {
    Text(title)
      .fontColor(this.currentIndex === targetIndex ? '#1698CE' : '#6B6B6B')
  }
  ...
  .onClick(() => {
    this.currentIndex = targetIndex;
    this.tabsController.changeIndex(this.currentIndex);
  })
}
```


When using the customized navigation bar, transfer the corresponding \@Builder in the tabBar attribute and transfer the corresponding parameters.



```ts
Tabs({ barPosition: BarPosition.End, controller: this.tabsController }) {
  TabContent(){
    ...
  }.tabBar (this.TabBuilder ('Home', 0))

  TabContent(){
    ...
  }.tabBar (this.TabBuilder ('Found', 1))

  TabContent(){
    ...
  }.tabBar (this.TabBuilder ('recommend', 2))

  TabContent(){
    ...
  }
  .tabBar (this.TabBuilder (' My',3))
}
```


## Swipe to switch the navigation bar.

If the customized navigation bar is not used, the Tabs implements the switchover association between the TabBar and TabContent by default. However, after the customized navigation bar is used, the TabsController can be used to implement the association between the clicked tab and the page content, but cannot implement the association between the page content and the tab when the page is sliding. That is, when a subscriber swipes on the screen to switch page content, the tab bar needs to be switched to the tab corresponding to the content.


  Figure 11 Tab page content is not associated when you slide to switch between tab pages 

![Final effect 11] (figures / Final effect 11.gif)


In this case, you need to use the onChange event method provided by Tabs to listen to the index change and transfer the active index value to currentIndex to switch the tab content.




```ts
Tabs({ barPosition: BarPosition.End, controller: this.tabsController }) {
  TabContent() {
    ...
  }.tabBar (this.TabBuilder ('Home', 0))

  TabContent() {
    ...
  }.tabBar (this.TabBuilder ('Found', 1))

  TabContent() {
    ...
  }.tabBar (this.TabBuilder ('Recommend', 2))

  TabContent() {
    ...
  }
  .tabBar (this.TabBuilder ('My', 3))
}.onChange((index) => {
  this.currentIndex = index
})
```


  Figure 12 Linkage between content and tabs

![Final Effect] (figures / Final Effect.gif)

## Samples

For details about the implementation of tabs, see the following example:

- [Healthy Life] (https://gitee.com/openharmony/codelabs/tree/master/ETSUI/Healthy_life)

- [Common Components and Layout] (https://gitee.com/openharmony/codelabs/tree/master/ETSUI/ArkTSComponents)
