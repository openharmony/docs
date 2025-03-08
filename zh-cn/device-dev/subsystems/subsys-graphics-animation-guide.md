# 动画开发指导


## 使用场景

UI动画通过task处理机制每个tick调用一下用户设置的callback函数来实现，具体实现为AnimatorManager、Animator、AnimatorCallback三个类实现。

- AnimatorManager：AnimatorManager为单例，在Init函数执行时将自己注册到系统task回调函数中，系统task机制保证每个tick会调用一下AnimatorManager的callback函数，同时AnimatorManager用来管理Animator实例。

- Animator：Animator中可以设置动画相关的属性，包括动画的起止时间，动画开始和停止，动画状态的设置和获取等。

- AnimatorCallback：具体每一个tick动画所要做的内容在AnimatorCallback类中实现，开发者需要自己实现Callback方法，动画执行时在Callback实现相应功能。


## 接口说明

  **表1** 动画接口说明

| 子模块 | 方法 | 功能 | 
| -------- | -------- | -------- |
| Animator | void&nbsp;&nbsp;Start&nbsp;() | 动画开始 | 
| Animator | void&nbsp;&nbsp;Stop&nbsp;() | 动画停止 | 
| Animator | void&nbsp;&nbsp;Pause&nbsp;() | 动画暂停 | 
| Animator | void&nbsp;&nbsp;Resume&nbsp;() | 动画恢复 | 
| Animator | uint8_t&nbsp;&nbsp;GetState&nbsp;()&nbsp;const | 获取动画当前状态 | 
| Animator | void&nbsp;&nbsp;SetState&nbsp;(uint8_t&nbsp;state) | 设置动画当前状态 | 
| Animator | uint32_t&nbsp;&nbsp;GetTime&nbsp;()&nbsp;const | 获取动画总持续时间 | 
| Animator | void&nbsp;&nbsp;SetTime&nbsp;(uint32_t&nbsp;time) | 设置动画总持续时间 | 
| Animator | uint32_t&nbsp;&nbsp;GetRunTime&nbsp;()&nbsp;const | 获取动画当前已经持续的时间 | 
| Animator | void&nbsp;&nbsp;SetRunTime&nbsp;(uint32_t&nbsp;runTime) | 设置动画当前已经持续的时间 | 
| Animator | bool&nbsp;&nbsp;IsRepeat&nbsp;()&nbsp;const | 获取动画是否循环播放 | 
| AnimatorCallback | virtual&nbsp;void&nbsp;&nbsp;Callback&nbsp;(UIView&nbsp;\*view)=0 | 由用户实现，动画回调函数 | 
| AnimatorCallback | virtual&nbsp;void&nbsp;OnStop(UIView&amp;&nbsp;view)&nbsp;{} | 由用户实现，动画停止后的回调函数 | 
| AnimatorManager | static&nbsp;AnimatorManager\*&nbsp;GetInstance() | 获取AnimatorManager实例 | 
| AnimatorManager | void&nbsp;&nbsp;Add&nbsp;(Animator&nbsp;\*animator) | 添加动画 | 
| AnimatorManager | void&nbsp;Remove(const&nbsp;Animator\*&nbsp;animator) | 删除动画 | 


## 开发步骤

1. 实现AnimatorCallback的回调函数。
     
   ```
   class AnimatorCallbackDemo : public OHOS::AnimatorCallback {
   public:
       AnimatorCallbackDemo(int16_t startPos, int16_t endPos, uint16_t time)
           : start_(startPos), end_(endPos), time_(time), curTime_(0) {}
    
       virtual void Callback(OHOS::UIView* view)
       {
           curTime_++;
           int16_t pos = EasingEquation::CubicEaseIn(start_, end_, curTime_, time_);
           view->Invalidate();
           view->SetPosition(pos, view->GetY());
           view->Invalidate();
       }
   protected:
       int16_t start_;
       int16_t end_;
       uint16_t time_;
       uint16_t curTime_;
   };
   ```

2. 将AnimatorCallback添加到Animator中。
     
   ```
   UIImageView* image = new UIImageView();
   image->SetSrc("..\\config\\images\\A021_001.bin");
   image->SetPosition(0, 50);
   AnimatorCallbackDemo* callback = new AnimatorCallbackDemo(0, 338, 60);
   Animator* animator = new Animator(callback, image, 0, true);
   ```

3. 将Animator添加到AnimatorManager中。
     
   ```
   AnimatorManager::GetInstance()->Add(animator);
   ```

4. 点击下图下方的按钮，检查对应的动画运行效果。
     
     **图1** 动画实现效果图

     ![zh-cn_image_0000001055504010](figures/zh-cn_image_0000001055504010.gif)
