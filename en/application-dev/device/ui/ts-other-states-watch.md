# @Watch


@Watch is used to listen for changes of state variables. The syntax structure is as follows:


  
```
@State @Watch("onChanged") count : number = 0
```


As shown above, add an @Watch decorator to the target state variable to register an onChanged callback. When the state variable count is changed, the onChanged callback will be triggered.


@Watch can be used to listen for changes of variables decorated by @State, @Prop, @Link, @ObjectLink, @Provide, @Consume, @StorageProp, or @StorageLink.


  
```
@Entry
@Component
struct CompA {
    @State @Watch("onBasketUpdated") shopBasket : Array<number> = [ 7, 12, 47, 3 ];
    @State totalPurchase : number = 0;

    updateTotal() : number {
        let sum = 0;
        this.shopBasket.forEach((i) => { sum += i; });
        // Calculate the total amount of items in the shopping basket. If the amount exceeds CNY100, the specified discount will be applied.
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
