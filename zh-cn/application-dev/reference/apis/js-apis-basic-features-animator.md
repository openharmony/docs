# 动画

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

requestAnimationFrame：无需导入

cancelAnimationFrame：无需导入

createAnimator：

```
import animator from '@ohos.animator';
```

## 权限列表

无


## requestAnimationFrame

requestAnimationFrame(handler[, [ ...args]]): number

请求动画帧，逐帧回调JS函数。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | handler | Function | 是 | 表示要逐帧回调的函数。requestAnimationFrame函数回调handler函数时会在第一个参数位置传入timestamp时间戳。它表示requestAnimationFrame开始去执行回调函数的时刻。 |
  | ...args | Array&lt;any&gt; | 否 | 附加参数，函数回调时，他们会作为参数传递给handler。 |

- 返回值
  | 类型 | 说明 |
  | -------- | -------- |
  | number | requestID请求的ID。 |

- 示例
  ```
  <!-- xxx.hml -->
  <div class="container">
    <button type="capsule" class="btn" onclick="beginAnimation">beginAnimation</button>
  </div>
  ```

  ```
  /* xxx.css */
  .container {
    flex-direction: column;
    justify-content: center;
    align-items: center;
    width: 100%;
    height: 100%;
  }
  .btn{
    width: 300px;
    margin-top: 40px;
  }
  ```

  ```
  /* xxx.js */
  export default {
    data: {
      requestId: 0,
      startTime: 0,
    },
    beginAnimation() {
      cancelAnimationFrame(this.requestId);
      this.requestId = requestAnimationFrame(this.runAnimation);
    },
    runAnimation(timestamp) {
      if (this.startTime == 0) {
        this.startTime = timestamp;
      }
      var elapsed = timestamp - this.startTime;
      if (elapsed < 500) {
        console.log('callback handler timestamp: ' + timestamp);
        this.requestId = requestAnimationFrame(this.runAnimation);
      }
    }
  }
  ```


## cancelAnimationFrame

cancelAnimationFrame(requestId: number): void

取消动画帧，取消逐帧回调请求。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | requestId | number | 是 | 逐帧回调函数的标识id。 |

- 示例
  ```
  <!-- xxx.hml -->
  <div class="container">
    <button type="capsule" class="btn" onclick="beginAnimation">beginAnimation</button>
    <button type="capsule" class="btn" onclick="stopAnimation">stopAnimation</button>
  </div>
  ```

  ```
  /* xxx.css */
  .container {
    flex-direction: column;
    justify-content: center;
    align-items: center;
    width: 100%;
    height: 100%;
  }
  .btn{
    width: 300px;
    margin-top: 40px;
  }
  ```

  ```
  /* xxx.js */
  export default {
    data: {
      requestId: 0,
      startTime: 0,
    },
    beginAnimation() {
      cancelAnimationFrame(this.requestId);
      this.requestId = requestAnimationFrame(this.runAnimation);
    },
    runAnimation(timestamp) {
      if (this.startTime == 0) {
        this.startTime = timestamp;
      }
      var elapsed = timestamp - this.startTime;
      if (elapsed < 500) {
        console.log('callback handler timestamp: ' + timestamp);
        this.requestId = requestAnimationFrame(this.runAnimation);
      }
    },
    stopAnimation() {
      cancelAnimationFrame(this.requestId);
    }
  }
  ```


## createAnimator

createAnimator(options[...]): void

创建动画对象。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | options | Object | 是 | 表示待创建Animator对象的属性，详情见下表options说明。 |

- options说明
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | duration | number | 否 | 动画播放的时长，单位毫秒，默认为0。 |
  | easing | string | 否 | 动画插值曲线，默认为'&nbsp;ease&nbsp;'。 |
  | delay | number | 否 | 动画延时播放时长，单位毫秒，默认为0，即不延时。 |
  | fill | string | 否 | 动画启停模式，默认值none，详情见：[animation-fill-mode](../arkui-js/js-components-common-animation.md) |
  | direction | string | 否 | 动画播放模式，默认值normal，详情见：[animation-direction](../arkui-js/js-components-common-animation.md) |
  | iterations | number | 否 | 动画播放次数，默认值1，设置为0时不播放，设置为-1时无限次播放。 |
  | begin | number | 否 | 动画插值起点，不设置时默认为0。 |
  | end | number | 否 | 动画插值终点，不设置时默认为1。 |

- animator支持的接口
  | 参数名 | 类型 | 说明 |
  | -------- | -------- | -------- |
  | update | options | 过程中可以使用这个接口更新动画参数，入参与createAnimator一致。 |
  | play | - | 开始动画。 |
  | finish | - | 结束动画。 |
  | pause | - | 暂停动画。 |
  | cancel | - | 取消动画。 |
  | reverse | - | 倒播动画。 |

- animator支持的事件：
  | 参数名 | 类型 | 说明 |
  | -------- | -------- | -------- |
  | frame | number | 逐帧插值回调事件，入参为当前帧的插值 |
  | cancel | - | 动画被强制取消 |
  | finish | - | 动画播放完成 |
  | repeat | - | 动画重新播放 |

- 示例
  ```
  <!-- hml -->
  <div class="container">
    <div class="Animation" style="height: {{divHeight}}px; width: {{divWidth}}px; background-color: red;" onclick="Show">
    </div>
  </div>
  ```

  ```
  // js
  export default {
    data : {
      divWidth: 200,
      divHeight: 200,
      animator: null
    },
    onInit() {
      var options = {
        duration: 1500,
        easing: 'friction',
        fill: 'forwards',
        iterations: 2,
        begin: 200.0,
        end: 400.0
      };
      this.animator = animator.createAnimator(options);
    },
    Show() {
      var options1 = {
        duration: 2000,
        easing: 'friction',
        fill: 'forwards',
        iterations: 1,
        begin: 200.0,
        end: 400.0
      };
      this.animator.update(options1);
      var _this = this;
      this.animator.onframe = function(value) {
        _this.divWidth = value;
        _this.divHeight = value;
      };
      this.animator.play();
    }
  }
  ```
