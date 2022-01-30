# @Watch<a name="EN-US_TOPIC_0000001177658253"></a>

The application can register a callback through  **@Watch**. This callback is triggered when a variable decorated by any of the following decorators changes:  **@State**,  **@Prop**,  **@Link**,  **@ObjectLink**,  **@Provide**,  **@Consume**,  **@StorageProp**, and  **@StorageLink**. The variables in  **@Watch**  must be enclosed in  **""**.

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

