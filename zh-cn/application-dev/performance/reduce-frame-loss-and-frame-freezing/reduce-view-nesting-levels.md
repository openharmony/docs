# 减少视图嵌套层次

视图的嵌套层次会影响应用的性能。在屏幕刷新率为120Hz的设备上，每8.3ms刷新一帧，如果视图的嵌套层次多，可能会导致没法在8.3ms内完成一次屏幕刷新，就会造成丢帧卡顿，影响用户体验。因此推荐开发者移除多余的嵌套层次，缩短组件刷新耗时。

## 移除多余的嵌套层次

反例：使用了Grid来实现一个网格，但是在外层套了3层stack容器，导致组件刷新和渲染耗时长。

```javascript
@Entry
@Component
struct AspectRatioExample {
  @State children: Number[] = Array.from(Array(900), (v, k) => k);

  build() {
    Scroll() {
      Grid() {
        ForEach(this.children, (item) => {
          GridItem() {
            Stack() {
              Stack() {
                Stack() {
                  Text(item.toString())
                }
              }
            }
          }
        }, item => item)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr')
      .columnsGap(0)
      .rowsGap(0)
      .size({ width: "100%", height: "100%" })
    }
  }
}
```

建议：通过减少冗余的Stack容器嵌套，每个GridItem的组件数比上面少了3个，缩短了组件刷新与渲染耗时。

```javascript
// xxx.ets
@Entry
@Component
struct AspectRatioExample {
  @State children: Number[] = Array.from(Array(900), (v, k) => k);

  build() {
    Scroll() {
      Grid() {
        ForEach(this.children, (item) => {
          GridItem() {
            Text(item.toString())
          }
        }, item => item)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr')
      .columnsGap(0)
      .rowsGap(0)
      .size({ width: "100%", height: "100%" })
    }
  }
}
```