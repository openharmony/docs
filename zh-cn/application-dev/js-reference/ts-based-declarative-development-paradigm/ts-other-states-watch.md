# @Watch<a name="ZH-CN_TOPIC_0000001177658253"></a>

应用可以注册回调方法。当一个被@State, @Prop, @Link, @ObjectLink, @Provide, @Consume, @StorageProp, 以及 @StorageLink中任意一个装饰器修饰的变量改变时，均可触发此回调。@Watch中的变量一定要使用（“”）进行包装。

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

