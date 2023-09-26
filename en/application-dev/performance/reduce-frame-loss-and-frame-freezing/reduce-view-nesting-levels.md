# Reducing Nesting

The view hierarchy can significantly affect application performance. For example, at the 120 Hz refresh rate, a device screen refreshes frames every 8.3 ms. If there are many levels of nested views, the frames may fail to be refreshed within 8.3 ms. As a result, frame loss and frame freezing occur, detracting from user experience. Therefore, it is recommended that you minimize nesting in your code to shorten the refresh time.

## Removing Redundant Levels of Nesting

In the following negative example, the **\<Grid>** component is used to implement a grid, but it is nested inside three levels of **\<Stack>** containers. As a result, the refresh and rendering process takes a long time to complete.

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

Recommendation: Reduce the redundant nesting of **\<Stack>** containers. In this way, the number of components that each grid item needs to pass is three less, shortening the refresh and rendering time.

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
