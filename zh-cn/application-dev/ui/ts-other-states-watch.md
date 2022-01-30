# @Watch<a name="ZH-CN_TOPIC_0000001177658253"></a>

@Watch用于监听状态变量的变化，语法结构为：

```
@State @Watch("onChanged") count : number = 0
```

如上给状态变量增加一个@Watch装饰器，通过@Watch注册一个回调方法onChanged， 当状态变量count被改变时， 触发onChanged回调。

装饰器@State, @Prop, @Link, @ObjectLink, @Provide, @Consume, @StorageProp以及 @StorageLink装饰的变量可以监听其变化。

```
@Entry
@Component
struct CompA {
    @State @Watch("onBasketUpdated") shopBasket : Array<number> = [ 7, 12, 47, 3 ];
    @State totalPurchase : number = 0;

    updateTotal() : number {
        let sum = 0;
        this.shopBasket.forEach((i) => { sum += i; });
        // calculate new total shop basket value and apply discount if over 100RMB
        this.totalPurchase = (sum < 100) ? sum : 0.9 * sum;
        return this.totalPurchase;
    }

    // @Watch cb
    onBasketUpdated(propName: string) : void {
      this.updateTotal();
    }

    build() {
        Column() {
            Button("add to basket").onClick(() => { this.shopBasket.push(Math.round(100 * Math.random())) })
            Text(`${this.totalPurchase}`)
                .fontSize(30)
        }
    }
}
```

