# Lottie<a name="EN-US_TOPIC_0000001193075114"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

Lottie is a third-party open-source library and depends on  **Canvas**  and  **RenderingContext**.

## Required Permissions<a name="section53281531154915"></a>

None

## Modules to Import<a name="section1368314480509"></a>

```
import lottie from 'lottie-web'
```

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>**'lottie-web'**  is subject to the actual released name.

## lottie.loadAnimation<a name="section11378112123018"></a>

loadAnimation\(

path: string, container: object, render: string, loop: boolean, autoplay: boolean, name: string \): AnimationItem

Loads an animation. Before calling this method, declare the  **Animator\('\_\_lottie\_ets'\)**  object and check that the canvas layout is complete. This method can be used together with a lifecycle callback of the  **Canvas**  component, for example,  **onAppear\(\)**  and  **onPageShow\(\)**.

-   Parameters

    <a name="table73781129301"></a>
    <table><thead align="left"><tr id="row037912124303"><th class="cellrowborder" valign="top" width="14.399999999999999%" id="mcps1.1.5.1.1"><p id="p437911214305"><a name="p437911214305"></a><a name="p437911214305"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.32%" id="mcps1.1.5.1.2"><p id="p153791912173019"><a name="p153791912173019"></a><a name="p153791912173019"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p43791812163012"><a name="p43791812163012"></a><a name="p43791812163012"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.22%" id="mcps1.1.5.1.4"><p id="p3379111214309"><a name="p3379111214309"></a><a name="p3379111214309"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row63791612183018"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p id="p53799124302"><a name="p53799124302"></a><a name="p53799124302"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p id="p1237918125301"><a name="p1237918125301"></a><a name="p1237918125301"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p0379111218307"><a name="p0379111218307"></a><a name="p0379111218307"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p id="p337918121301"><a name="p337918121301"></a><a name="p337918121301"></a>Path of the animation resource file in the HAP file. The resource file must be in JSON format. Example: <strong id="b15690184714366"><a name="b15690184714366"></a><a name="b15690184714366"></a>path: "common/lottie/data.json"</strong>.</p>
    </td>
    </tr>
    <tr id="row18379161283015"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p id="p14379191283014"><a name="p14379191283014"></a><a name="p14379191283014"></a>container</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p id="p1337912121301"><a name="p1337912121301"></a><a name="p1337912121301"></a>object</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p93793124301"><a name="p93793124301"></a><a name="p93793124301"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p id="p537981243018"><a name="p537981243018"></a><a name="p537981243018"></a>Canvas drawing context. A <strong id="b156372033163916"><a name="b156372033163916"></a><a name="b156372033163916"></a>CanvasRenderingContext2D</strong> object must be declared in advance.</p>
    </td>
    </tr>
    <tr id="row4379512143018"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p id="p2037941263011"><a name="p2037941263011"></a><a name="p2037941263011"></a>render</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p id="p4379111219302"><a name="p4379111219302"></a><a name="p4379111219302"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p5379912103016"><a name="p5379912103016"></a><a name="p5379912103016"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p id="p10379121217306"><a name="p10379121217306"></a><a name="p10379121217306"></a>Rendering type. Only <strong id="b1629817513394"><a name="b1629817513394"></a><a name="b1629817513394"></a>canvas</strong> is supported.</p>
    </td>
    </tr>
    <tr id="row7379612183019"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p id="p93801212153020"><a name="p93801212153020"></a><a name="p93801212153020"></a>loop</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p id="p10380151210308"><a name="p10380151210308"></a><a name="p10380151210308"></a>boolean | number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p3380171213306"><a name="p3380171213306"></a><a name="p3380171213306"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p id="p8380512133014"><a name="p8380512133014"></a><a name="p8380512133014"></a>If the value is of the Boolean type, this parameter indicates whether to repeat the animation cyclically after the animation ends; the default value is <strong id="b798125919462"><a name="b798125919462"></a><a name="b798125919462"></a>true</strong>. If the value is of the number type and is greater than or equal to 1, this parameter indicates the number of times the animation plays.</p>
    </td>
    </tr>
    <tr id="row1938010121309"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p id="p14380212183012"><a name="p14380212183012"></a><a name="p14380212183012"></a>autoplay</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p id="p153801312153011"><a name="p153801312153011"></a><a name="p153801312153011"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p8380181243017"><a name="p8380181243017"></a><a name="p8380181243017"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p id="p13380111211309"><a name="p13380111211309"></a><a name="p13380111211309"></a>Whether to automatically play the animation. The default value is <strong id="b9800182119497"><a name="b9800182119497"></a><a name="b9800182119497"></a>true</strong>.</p>
    </td>
    </tr>
    <tr id="row73802129303"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p id="p0380161293019"><a name="p0380161293019"></a><a name="p0380161293019"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p id="p338001213018"><a name="p338001213018"></a><a name="p338001213018"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p1138020121306"><a name="p1138020121306"></a><a name="p1138020121306"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p id="p0380312103017"><a name="p0380312103017"></a><a name="p0380312103017"></a>Custom animation name. In later versions, the name can be used to reference and control the animation. The default value is null.</p>
    </td>
    </tr>
    <tr id="row19382711102216"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.5.1.1 "><p id="p638214113222"><a name="p638214113222"></a><a name="p638214113222"></a>initialSegment</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p id="p10382411162219"><a name="p10382411162219"></a><a name="p10382411162219"></a>[number, number]</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p13821211112210"><a name="p13821211112210"></a><a name="p13821211112210"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p id="p1416611137243"><a name="p1416611137243"></a><a name="p1416611137243"></a>Start frame and end frame of the animation, respectively.</p>
    </td>
    </tr>
    </tbody>
    </table>


## lottie.destroy<a name="section0927174125215"></a>

destroy\(name: string\): void

Destroys the animation. This method must be called when a page exits. This method can be used together with a lifecycle callback of the  **Canvas**  component, for example,  **onDisappear\(\)**  and  **onPageHide\(\)**.

-   Parameters

    <a name="table116784429596"></a>
    <table><thead align="left"><tr id="row167864213591"><th class="cellrowborder" valign="top" width="14.38%" id="mcps1.1.5.1.1"><p id="p8678134225914"><a name="p8678134225914"></a><a name="p8678134225914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.35%" id="mcps1.1.5.1.2"><p id="p567911425597"><a name="p567911425597"></a><a name="p567911425597"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p1099718561418"><a name="p1099718561418"></a><a name="p1099718561418"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p116798423594"><a name="p116798423594"></a><a name="p116798423594"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row46791042125917"><td class="cellrowborder" valign="top" width="14.38%" headers="mcps1.1.5.1.1 "><p id="p181017141103"><a name="p181017141103"></a><a name="p181017141103"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.35%" headers="mcps1.1.5.1.2 "><p id="p1967994235916"><a name="p1967994235916"></a><a name="p1967994235916"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p299815561611"><a name="p299815561611"></a><a name="p299815561611"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p697532875611"><a name="p697532875611"></a><a name="p697532875611"></a>Name of the animation to destroy, which is the same as the <strong id="b174515965919"><a name="b174515965919"></a><a name="b174515965919"></a>name</strong> in the <strong id="b88191218155911"><a name="b88191218155911"></a><a name="b88191218155911"></a>loadAnimation</strong> interface. By default, all animations are destroyed.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    import lottie from 'lottie-web'
    
    @Entry
    @Component
    struct Index {
      private controller: CanvasRenderingContext2D = new CanvasRenderingContext2D()
      private animateName: string = "animate"
      private animatePath: string = "common/lottie/data.json"
      private animateItem: any = null
    
      private onPageHide(): void {
        console.log('onPageHide')
        lottie.destroy()
      }
    
      build() {
        Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
          Canvas(this.controller)
          .width('30%')
          .height('20%')
          .backgroundColor('#0D9FFB')
          .onAppear(() => {
            console.log('canvas onAppear');
            this.animateItem = lottie.loadAnimation({
              container: this.controller,
              renderer: 'canvas',
              loop: true,
              autoplay: true,
              name: this.animateName,
              path: this.animatePath,
            })
          })
    
          Animator('__lottie_ets') // declare Animator('__lottie_ets') when use lottie
          Button('load animation')
            .onClick(() => {
            if (this.animateItem != null) {
              this.animateItem.destroy()
              this.animateItem = null
            }
            this.animateItem = lottie.loadAnimation({
              container: this.controller,
              renderer: 'canvas',
              loop: true,
              autoplay: true,
              name: this.animateName,
              path: this.animatePath,
              initialSegment: [10, 50],
            })
          })
    
          Button('destroy animation')
            .onClick(() => {
              lottie.destroy(this.animateName)
              this.animateItem = null
            })
        }
        .width('100%')
        .height('100%')
      }
    }
    ```

    ![](figures/lottie-ark-2-0-canvas-ui-animate.gif)


## lottie.play<a name="section175031744244"></a>

play\(name: string\): void

Plays a specified animation.

-   Parameters

    <a name="table5503943240"></a>
    <table><thead align="left"><tr id="row13503204142410"><th class="cellrowborder" valign="top" width="15.6%" id="mcps1.1.5.1.1"><p id="p1050316410247"><a name="p1050316410247"></a><a name="p1050316410247"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.13%" id="mcps1.1.5.1.2"><p id="p135036472418"><a name="p135036472418"></a><a name="p135036472418"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p19503164162418"><a name="p19503164162418"></a><a name="p19503164162418"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p15503447247"><a name="p15503447247"></a><a name="p15503447247"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12503341246"><td class="cellrowborder" valign="top" width="15.6%" headers="mcps1.1.5.1.1 "><p id="p850394172420"><a name="p850394172420"></a><a name="p850394172420"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.13%" headers="mcps1.1.5.1.2 "><p id="p250312411244"><a name="p250312411244"></a><a name="p250312411244"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p185038422415"><a name="p185038422415"></a><a name="p185038422415"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p691717593432"><a name="p691717593432"></a><a name="p691717593432"></a>Name of the animation to play, which is the same as the <strong id="b173958442214"><a name="b173958442214"></a><a name="b173958442214"></a>name</strong> in the <strong id="b8396144324"><a name="b8396144324"></a><a name="b8396144324"></a>loadAnimation</strong> interface. By default, all animations are played.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    lottie.play(this.animateName)
    ```


## lottie.pause<a name="section13965204292811"></a>

pause\(name: string\): void

Pauses a specified animation. The next time  **lottie.play\(\)**  is called, the animation starts from the current frame.

-   Parameters

    <a name="table1496584272818"></a>
    <table><thead align="left"><tr id="row49651242132819"><th class="cellrowborder" valign="top" width="15.6%" id="mcps1.1.5.1.1"><p id="p199651742102814"><a name="p199651742102814"></a><a name="p199651742102814"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.13%" id="mcps1.1.5.1.2"><p id="p9965154222811"><a name="p9965154222811"></a><a name="p9965154222811"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p79653429288"><a name="p79653429288"></a><a name="p79653429288"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p1296584216288"><a name="p1296584216288"></a><a name="p1296584216288"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10965154272820"><td class="cellrowborder" valign="top" width="15.6%" headers="mcps1.1.5.1.1 "><p id="p1296554216282"><a name="p1296554216282"></a><a name="p1296554216282"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.13%" headers="mcps1.1.5.1.2 "><p id="p12965194262815"><a name="p12965194262815"></a><a name="p12965194262815"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p496574272810"><a name="p496574272810"></a><a name="p496574272810"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p6965184232815"><a name="p6965184232815"></a><a name="p6965184232815"></a>Name of the animation to pause, which is the same as the <strong id="b119281827419"><a name="b119281827419"></a><a name="b119281827419"></a>name</strong> in the <strong id="b49291120411"><a name="b49291120411"></a><a name="b49291120411"></a>loadAnimation</strong> interface. By default, all animations are paused.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    lottie.pause(this.animateName)
    ```


## lottie.togglePause<a name="section1633164714304"></a>

togglePause\(name: string\): void

Pauses or plays a specified animation. This method is equivalent to the switching between  **lottie.play\(\)**  and  **lottie.pause\(\)**.

-   Parameters

    <a name="table105891271516"></a>
    <table><thead align="left"><tr id="row25886275110"><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p id="p1058810277110"><a name="p1058810277110"></a><a name="p1058810277110"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.1.5.1.2"><p id="p15588727118"><a name="p15588727118"></a><a name="p15588727118"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p1358822718111"><a name="p1358822718111"></a><a name="p1358822718111"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p15588162711112"><a name="p15588162711112"></a><a name="p15588162711112"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8589227316"><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p id="p1658811271919"><a name="p1658811271919"></a><a name="p1658811271919"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.1.5.1.2 "><p id="p0589152713120"><a name="p0589152713120"></a><a name="p0589152713120"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p1258916272119"><a name="p1258916272119"></a><a name="p1258916272119"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p8589172719115"><a name="p8589172719115"></a><a name="p8589172719115"></a>Name of the target animation, which is the same as the <strong id="b1728173317143"><a name="b1728173317143"></a><a name="b1728173317143"></a>name</strong> in the <strong id="b13728153371412"><a name="b13728153371412"></a><a name="b13728153371412"></a>loadAnimation</strong> interface. By default, all animations are paused.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    lottie.togglePause(this.animateName)
    ```


## lottie.stop<a name="section57246132289"></a>

stop\(name: string\): void

Stops the specified animation. The next time  **lottie.play\(\)**  is called, the animation starts from the first frame.

-   Parameters

    <a name="table117241313112817"></a>
    <table><thead align="left"><tr id="row5724131313284"><th class="cellrowborder" valign="top" width="15.72%" id="mcps1.1.5.1.1"><p id="p1172481332811"><a name="p1172481332811"></a><a name="p1172481332811"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.01%" id="mcps1.1.5.1.2"><p id="p17725131311282"><a name="p17725131311282"></a><a name="p17725131311282"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p3725111317288"><a name="p3725111317288"></a><a name="p3725111317288"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p1972501362814"><a name="p1972501362814"></a><a name="p1972501362814"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row37252013172813"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="p3725171372813"><a name="p3725171372813"></a><a name="p3725171372813"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.01%" headers="mcps1.1.5.1.2 "><p id="p18725713102819"><a name="p18725713102819"></a><a name="p18725713102819"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p107251813202819"><a name="p107251813202819"></a><a name="p107251813202819"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p187251313142814"><a name="p187251313142814"></a><a name="p187251313142814"></a>Name of the animation to stop, which is the same as the <strong id="b29356398186"><a name="b29356398186"></a><a name="b29356398186"></a>name</strong> in the <strong id="b14935133918181"><a name="b14935133918181"></a><a name="b14935133918181"></a>loadAnimation</strong> interface. By default, all animations are stopped.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    lottie.stop(this.animateName)
    ```


## lottie.setSpeed<a name="section755319433508"></a>

setSpeed\(speed: number, name: string\): void

Sets the playback speed of the specified animation.

-   Parameters

    <a name="table125531543115012"></a>
    <table><thead align="left"><tr id="row16554134375018"><th class="cellrowborder" valign="top" width="15.72%" id="mcps1.1.5.1.1"><p id="p75541443105013"><a name="p75541443105013"></a><a name="p75541443105013"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.01%" id="mcps1.1.5.1.2"><p id="p35542043115011"><a name="p35542043115011"></a><a name="p35542043115011"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p955424315014"><a name="p955424315014"></a><a name="p955424315014"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p16554154313500"><a name="p16554154313500"></a><a name="p16554154313500"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1829610278529"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="p92962276526"><a name="p92962276526"></a><a name="p92962276526"></a>speed</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.01%" headers="mcps1.1.5.1.2 "><p id="p1296162710521"><a name="p1296162710521"></a><a name="p1296162710521"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p229652717521"><a name="p229652717521"></a><a name="p229652717521"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p11296827185218"><a name="p11296827185218"></a><a name="p11296827185218"></a>Playback speed. The value is a floating-point number. If the value is greater than 0, the animation plays in forward direction. If the value is less than 0, the animation plays in reversed direction. If the value is 0, the animation is paused. If the value is 1.0 or -1.0, the animation plays at the normal speed.</p>
    </td>
    </tr>
    <tr id="row75542436507"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="p17554743175020"><a name="p17554743175020"></a><a name="p17554743175020"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.01%" headers="mcps1.1.5.1.2 "><p id="p15554164315010"><a name="p15554164315010"></a><a name="p15554164315010"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p9554043145014"><a name="p9554043145014"></a><a name="p9554043145014"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p35541343105013"><a name="p35541343105013"></a><a name="p35541343105013"></a>Name of the target animation, which is the same as the <strong id="b8206181023220"><a name="b8206181023220"></a><a name="b8206181023220"></a>name</strong> in the <strong id="b1420691015324"><a name="b1420691015324"></a><a name="b1420691015324"></a>loadAnimation</strong> interface. By default, all animations are stopped.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    lottie.setSpeed(5, this.animateName)
    ```


## lottie.setDirection<a name="section2055464318504"></a>

setDirection\(direction: AnimationDirection, name: string\): void

Sets the dierection in which the specified animation plays.

-   Parameters

    <a name="table14554184312503"></a>
    <table><thead align="left"><tr id="row1755494335015"><th class="cellrowborder" valign="top" width="15.939999999999998%" id="mcps1.1.5.1.1"><p id="p0554114315505"><a name="p0554114315505"></a><a name="p0554114315505"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.790000000000001%" id="mcps1.1.5.1.2"><p id="p75542438506"><a name="p75542438506"></a><a name="p75542438506"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p1455534395018"><a name="p1455534395018"></a><a name="p1455534395018"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p1555743205017"><a name="p1555743205017"></a><a name="p1555743205017"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row98709463554"><td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.1.5.1.1 "><p id="p1987154675512"><a name="p1987154675512"></a><a name="p1987154675512"></a>direction</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.790000000000001%" headers="mcps1.1.5.1.2 "><p id="p7871174615559"><a name="p7871174615559"></a><a name="p7871174615559"></a>AnimationDirection</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p0871134619559"><a name="p0871134619559"></a><a name="p0871134619559"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p13871114635517"><a name="p13871114635517"></a><a name="p13871114635517"></a>Direction in which the animation plays. <strong id="b876412283422"><a name="b876412283422"></a><a name="b876412283422"></a>1</strong>: forwards; <strong id="b156013013431"><a name="b156013013431"></a><a name="b156013013431"></a>-1</strong>: backwards. When set to play backwards, the animation plays from the current playback progress to the first frame. When this setting is combined with <strong id="b134809445548"><a name="b134809445548"></a><a name="b134809445548"></a>loop</strong> being set to <strong id="b1956755215411"><a name="b1956755215411"></a><a name="b1956755215411"></a>true</strong>, the animation plays backwards continuously. When the value of <strong id="b82794325582"><a name="b82794325582"></a><a name="b82794325582"></a>speed</strong> is less than 0, the animation also plays backwards.</p>
    <p id="p155301550901"><a name="p155301550901"></a><a name="p155301550901"></a>AnimationDirection: 1 | -1</p>
    </td>
    </tr>
    <tr id="row14555443135013"><td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.1.5.1.1 "><p id="p105551843165012"><a name="p105551843165012"></a><a name="p105551843165012"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.790000000000001%" headers="mcps1.1.5.1.2 "><p id="p12555343125010"><a name="p12555343125010"></a><a name="p12555343125010"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p1655517434505"><a name="p1655517434505"></a><a name="p1655517434505"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p755554375013"><a name="p755554375013"></a><a name="p755554375013"></a>Name of the target animation, which is the same as the <strong id="b174926232597"><a name="b174926232597"></a><a name="b174926232597"></a>name</strong> in the <strong id="b15493182365912"><a name="b15493182365912"></a><a name="b15493182365912"></a>loadAnimation</strong> interface. By default, all animations are set.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    lottie.setDirection(-1, this.controlName)
    ```


## AnimationItem<a name="section038875381812"></a>

Defines an  **AnimationItem**  object, which is returned by the  **loadAnimation**  interface and has attributes and interfaces. The attributes are described as follows:

<a name="table63801556917"></a>
<table><thead align="left"><tr id="row123801259914"><th class="cellrowborder" valign="top" width="33.300000000000004%" id="mcps1.1.4.1.1"><p id="p143801852920"><a name="p143801852920"></a><a name="p143801852920"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="33.36%" id="mcps1.1.4.1.2"><p id="p538011511920"><a name="p538011511920"></a><a name="p538011511920"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.339999999999996%" id="mcps1.1.4.1.3"><p id="p10380751296"><a name="p10380751296"></a><a name="p10380751296"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1638018512912"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p4380255916"><a name="p4380255916"></a><a name="p4380255916"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p63801850913"><a name="p63801850913"></a><a name="p63801850913"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p73801159911"><a name="p73801159911"></a><a name="p73801159911"></a>Animation name.</p>
</td>
</tr>
<tr id="row93801051192"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p11380258918"><a name="p11380258918"></a><a name="p11380258918"></a>isLoaded</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p638019510914"><a name="p638019510914"></a><a name="p638019510914"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p137806258243"><a name="p137806258243"></a><a name="p137806258243"></a>Whether the animation is loaded.</p>
</td>
</tr>
<tr id="row838085692"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p53802051393"><a name="p53802051393"></a><a name="p53802051393"></a>currentFrame</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p2380351918"><a name="p2380351918"></a><a name="p2380351918"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p8381115194"><a name="p8381115194"></a><a name="p8381115194"></a>Frame that is being played. The default precision is a floating-point number greater than or equal to 0.0. After <strong id="b580644753510"><a name="b580644753510"></a><a name="b580644753510"></a>setSubframe(false)</strong> is called, the value is a positive integer without decimal points.</p>
</td>
</tr>
<tr id="row17381158910"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p538125294"><a name="p538125294"></a><a name="p538125294"></a>currentRawFrame</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p17443154532416"><a name="p17443154532416"></a><a name="p17443154532416"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p184427456244"><a name="p184427456244"></a><a name="p184427456244"></a>Number of frames that are being played. The precision is a floating point number greater than or equal to 0.0.</p>
</td>
</tr>
<tr id="row12381851197"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p1938114510911"><a name="p1938114510911"></a><a name="p1938114510911"></a>firstFrame</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p144428453243"><a name="p144428453243"></a><a name="p144428453243"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p844116452248"><a name="p844116452248"></a><a name="p844116452248"></a>First frame of the animation segment that is being played.</p>
</td>
</tr>
<tr id="row1338105290"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p13381251295"><a name="p13381251295"></a><a name="p13381251295"></a>totalFrames</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p144401945182410"><a name="p144401945182410"></a><a name="p144401945182410"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p184406454244"><a name="p184406454244"></a><a name="p184406454244"></a>Total number of frames in the animation segment that is being played.</p>
</td>
</tr>
<tr id="row173811751092"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p138175791"><a name="p138175791"></a><a name="p138175791"></a>frameRate</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p20439645142419"><a name="p20439645142419"></a><a name="p20439645142419"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p1043984518243"><a name="p1043984518243"></a><a name="p1043984518243"></a>Frame rate (frame/s).</p>
</td>
</tr>
<tr id="row14381125798"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p838112515920"><a name="p838112515920"></a><a name="p838112515920"></a>frameMult</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p843864512246"><a name="p843864512246"></a><a name="p843864512246"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p6437194520246"><a name="p6437194520246"></a><a name="p6437194520246"></a>Frame rate (frame/ms).</p>
</td>
</tr>
<tr id="row33821156911"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p11382151194"><a name="p11382151194"></a><a name="p11382151194"></a>playSpeed</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p164378452247"><a name="p164378452247"></a><a name="p164378452247"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p122573611267"><a name="p122573611267"></a><a name="p122573611267"></a>Playback speed. The value is a floating-point number. If the value is greater than 0, the animation plays in forward direction. If the value is less than 0, the animation plays in reversed direction. If the value is 0, the animation is paused. If the value is <strong id="b16484101794015"><a name="b16484101794015"></a><a name="b16484101794015"></a>1.0</strong> or <strong id="b385313191400"><a name="b385313191400"></a><a name="b385313191400"></a>-1.0</strong>, the animation plays at the normal speed.</p>
</td>
</tr>
<tr id="row103821651294"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p63821151916"><a name="p63821151916"></a><a name="p63821151916"></a>playDirection</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p143514502418"><a name="p143514502418"></a><a name="p143514502418"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p1243694514245"><a name="p1243694514245"></a><a name="p1243694514245"></a>Playback direction. The options are <strong id="b1183104424017"><a name="b1183104424017"></a><a name="b1183104424017"></a>1</strong> (forward) and <strong id="b14707104618408"><a name="b14707104618408"></a><a name="b14707104618408"></a>-1</strong> (backward).</p>
</td>
</tr>
<tr id="row0382105693"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p11382854912"><a name="p11382854912"></a><a name="p11382854912"></a>playCount</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p14434145192417"><a name="p14434145192417"></a><a name="p14434145192417"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p1143212452243"><a name="p1143212452243"></a><a name="p1143212452243"></a>Number of times the animation plays.</p>
</td>
</tr>
<tr id="row81351851122618"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p2135125116266"><a name="p2135125116266"></a><a name="p2135125116266"></a>isPaused</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p1913515117269"><a name="p1913515117269"></a><a name="p1913515117269"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p15135135115268"><a name="p15135135115268"></a><a name="p15135135115268"></a>Whether the current animation is paused. The value <strong id="b13323941427"><a name="b13323941427"></a><a name="b13323941427"></a>true</strong> means that the animation is paused.</p>
</td>
</tr>
<tr id="row253805332616"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p8539105316265"><a name="p8539105316265"></a><a name="p8539105316265"></a>autoplay</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p853995392620"><a name="p853995392620"></a><a name="p853995392620"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p8539135342613"><a name="p8539135342613"></a><a name="p8539135342613"></a>Whether to automatically play the animation upon completion of the loading. The value <strong id="b197714111433"><a name="b197714111433"></a><a name="b197714111433"></a>false</strong> means that the <strong id="b77791812164312"><a name="b77791812164312"></a><a name="b77791812164312"></a>play()</strong> interface needs to be called to start playing.</p>
</td>
</tr>
<tr id="row1682234852615"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p582316486262"><a name="p582316486262"></a><a name="p582316486262"></a>loop</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p4823134817265"><a name="p4823134817265"></a><a name="p4823134817265"></a>boolean | number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p128231448112617"><a name="p128231448112617"></a><a name="p128231448112617"></a>If the value is of the Boolean type, this parameter indicates whether to repeat the animation cyclically after the animation ends. If the value is of the number type and is greater than or equal to 1, this parameter indicates the number of times the animation plays.</p>
</td>
</tr>
<tr id="row575133462711"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p47693442716"><a name="p47693442716"></a><a name="p47693442716"></a>renderer</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p276143410278"><a name="p276143410278"></a><a name="p276143410278"></a>any</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p1276163402710"><a name="p1276163402710"></a><a name="p1276163402710"></a>Animation rendering object, which depends on the rendering type.</p>
</td>
</tr>
<tr id="row13154311279"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p93158313272"><a name="p93158313272"></a><a name="p93158313272"></a>animationID</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p13315193119273"><a name="p13315193119273"></a><a name="p13315193119273"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p3315331192712"><a name="p3315331192712"></a><a name="p3315331192712"></a>Animation ID.</p>
</td>
</tr>
<tr id="row12911435162711"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p391116355277"><a name="p391116355277"></a><a name="p391116355277"></a>timeCompleted</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p0911135172715"><a name="p0911135172715"></a><a name="p0911135172715"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p891113353270"><a name="p891113353270"></a><a name="p891113353270"></a>Number of frames that are played for an animation sequence. The value is affected by the setting of <strong id="b1521114516250"><a name="b1521114516250"></a><a name="b1521114516250"></a>AnimationSegment</strong> and is the same as the value of <strong id="b15481448152510"><a name="b15481448152510"></a><a name="b15481448152510"></a>totalFrames</strong>.</p>
</td>
</tr>
<tr id="row1717948162818"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p1017916817281"><a name="p1017916817281"></a><a name="p1017916817281"></a>segmentPos</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p7179183281"><a name="p7179183281"></a><a name="p7179183281"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p1917917872818"><a name="p1917917872818"></a><a name="p1917917872818"></a>ID of the current animation segment. The value is a positive integer greater than or equal to 0.</p>
</td>
</tr>
<tr id="row12961937162820"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p59611037202813"><a name="p59611037202813"></a><a name="p59611037202813"></a>isSubframeEnabled</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p4961437132815"><a name="p4961437132815"></a><a name="p4961437132815"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p996111374284"><a name="p996111374284"></a><a name="p996111374284"></a>Whether the precision of <strong id="b112081635261"><a name="b112081635261"></a><a name="b112081635261"></a>currentFrame</strong> is a floating point number.</p>
</td>
</tr>
<tr id="row84254162915"><td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.1.4.1.1 "><p id="p15438415295"><a name="p15438415295"></a><a name="p15438415295"></a>segments</p>
</td>
<td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.2 "><p id="p134316411298"><a name="p134316411298"></a><a name="p134316411298"></a>AnimationSegment | AnimationSegment[]</p>
</td>
<td class="cellrowborder" valign="top" width="33.339999999999996%" headers="mcps1.1.4.1.3 "><p id="p104312411298"><a name="p104312411298"></a><a name="p104312411298"></a>Current segment of the animation.</p>
</td>
</tr>
</tbody>
</table>

## AnimationItem.play<a name="section035751020599"></a>

play\(name?: string\): void

Plays an animation.

-   Parameters

    <a name="table74746571299"></a>
    <table><thead align="left"><tr id="row1147455715915"><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p id="p18474157992"><a name="p18474157992"></a><a name="p18474157992"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.1.5.1.2"><p id="p1447495716916"><a name="p1447495716916"></a><a name="p1447495716916"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p447414571894"><a name="p447414571894"></a><a name="p447414571894"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p12475175718918"><a name="p12475175718918"></a><a name="p12475175718918"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row64756571192"><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p id="p204751057394"><a name="p204751057394"></a><a name="p204751057394"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.1.5.1.2 "><p id="p14475145713916"><a name="p14475145713916"></a><a name="p14475145713916"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p14475205717920"><a name="p14475205717920"></a><a name="p14475205717920"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p447511571293"><a name="p447511571293"></a><a name="p447511571293"></a>Name of the target animation. By default, the value is null.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    this.anim.play()
    ```


## AnimationItem.destroy<a name="section1335522233318"></a>

destroy\(name?: string\): void

Destroys an animation.

-   Parameters

    <a name="table842718111079"></a>
    <table><thead align="left"><tr id="row15427201113713"><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p id="p1542781118716"><a name="p1542781118716"></a><a name="p1542781118716"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.1.5.1.2"><p id="p1042719117714"><a name="p1042719117714"></a><a name="p1042719117714"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p184282111273"><a name="p184282111273"></a><a name="p184282111273"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p134282117713"><a name="p134282117713"></a><a name="p134282117713"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row84284112714"><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p id="p64281118718"><a name="p64281118718"></a><a name="p64281118718"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.1.5.1.2 "><p id="p194280111879"><a name="p194280111879"></a><a name="p194280111879"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p84286118713"><a name="p84286118713"></a><a name="p84286118713"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p54289111073"><a name="p54289111073"></a><a name="p54289111073"></a>Name of the target animation. By default, the value is null.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    this.anim.destroy()
    ```


## AnimationItem.pause<a name="section1535821016594"></a>

pause\(name?: string\): void

Pauses an animation. When the  **play**  interface is called next time, the animation is played from the current frame.

-   Parameters

    <a name="table1427915931019"></a>
    <table><thead align="left"><tr id="row1827979141011"><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p id="p9279119171011"><a name="p9279119171011"></a><a name="p9279119171011"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.97%" id="mcps1.1.5.1.2"><p id="p172793911014"><a name="p172793911014"></a><a name="p172793911014"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.07%" id="mcps1.1.5.1.3"><p id="p162792919100"><a name="p162792919100"></a><a name="p162792919100"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.22%" id="mcps1.1.5.1.4"><p id="p1727949191018"><a name="p1727949191018"></a><a name="p1727949191018"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row32799911105"><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p id="p728012931018"><a name="p728012931018"></a><a name="p728012931018"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.97%" headers="mcps1.1.5.1.2 "><p id="p12809961018"><a name="p12809961018"></a><a name="p12809961018"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.5.1.3 "><p id="p2028089191019"><a name="p2028089191019"></a><a name="p2028089191019"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p id="p202804921010"><a name="p202804921010"></a><a name="p202804921010"></a>Name of the target animation. By default, the value is null.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    this.anim.pause()
    ```


## AnimationItem.togglePause<a name="section16359210115914"></a>

togglePause\(name?: string\): void

Pauses or plays an animation. This method is equivalent to the switching between  **play**  and  **pause**.

-   Parameters

    <a name="table201948111117"></a>
    <table><thead align="left"><tr id="row019491111117"><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p id="p101955181114"><a name="p101955181114"></a><a name="p101955181114"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.97%" id="mcps1.1.5.1.2"><p id="p1619513117110"><a name="p1619513117110"></a><a name="p1619513117110"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.07%" id="mcps1.1.5.1.3"><p id="p819511118114"><a name="p819511118114"></a><a name="p819511118114"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.22%" id="mcps1.1.5.1.4"><p id="p151952113112"><a name="p151952113112"></a><a name="p151952113112"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1019514111114"><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p id="p1819513151118"><a name="p1819513151118"></a><a name="p1819513151118"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.97%" headers="mcps1.1.5.1.2 "><p id="p8195417110"><a name="p8195417110"></a><a name="p8195417110"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.5.1.3 "><p id="p61951213113"><a name="p61951213113"></a><a name="p61951213113"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p id="p71951113114"><a name="p71951113114"></a><a name="p71951113114"></a>Name of the target animation. By default, the value is null.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    this.anim.togglePause()
    ```


## AnimationItem.stop<a name="section163601107598"></a>

stop\(name?: string\): void

Stops an animation. When the  **play**  interface is called next time, the animation is played from the first frame.

-   Parameters

    <a name="table264771201115"></a>
    <table><thead align="left"><tr id="row7647412121116"><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p id="p16647812141113"><a name="p16647812141113"></a><a name="p16647812141113"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.97%" id="mcps1.1.5.1.2"><p id="p46471712101113"><a name="p46471712101113"></a><a name="p46471712101113"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.07%" id="mcps1.1.5.1.3"><p id="p9647101291117"><a name="p9647101291117"></a><a name="p9647101291117"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.22%" id="mcps1.1.5.1.4"><p id="p20647111219117"><a name="p20647111219117"></a><a name="p20647111219117"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18647171217114"><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p id="p1164781261110"><a name="p1164781261110"></a><a name="p1164781261110"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.97%" headers="mcps1.1.5.1.2 "><p id="p46471112141117"><a name="p46471112141117"></a><a name="p46471112141117"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.07%" headers="mcps1.1.5.1.3 "><p id="p17647012151115"><a name="p17647012151115"></a><a name="p17647012151115"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.22%" headers="mcps1.1.5.1.4 "><p id="p14647712151111"><a name="p14647712151111"></a><a name="p14647712151111"></a>Name of the target animation. By default, the value is null.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    this.anim.stop()
    ```


## AnimationItem.setSpeed<a name="section3824104013716"></a>

setSpeed\(speed: number\): void

Sets the playback speed of an animation.

-   Parameters

    <a name="table38241640173714"></a>
    <table><thead align="left"><tr id="row19825740183720"><th class="cellrowborder" valign="top" width="15.740000000000002%" id="mcps1.1.5.1.1"><p id="p6825134063710"><a name="p6825134063710"></a><a name="p6825134063710"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.989999999999998%" id="mcps1.1.5.1.2"><p id="p1582594012373"><a name="p1582594012373"></a><a name="p1582594012373"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p17825164016371"><a name="p17825164016371"></a><a name="p17825164016371"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p28256407379"><a name="p28256407379"></a><a name="p28256407379"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1882554013376"><td class="cellrowborder" valign="top" width="15.740000000000002%" headers="mcps1.1.5.1.1 "><p id="p482534073719"><a name="p482534073719"></a><a name="p482534073719"></a>speed</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.989999999999998%" headers="mcps1.1.5.1.2 "><p id="p882504017377"><a name="p882504017377"></a><a name="p882504017377"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p1182544013712"><a name="p1182544013712"></a><a name="p1182544013712"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p782514014379"><a name="p782514014379"></a><a name="p782514014379"></a>Playback speed. The value is a floating-point number. If the value is greater than 0, the animation plays in forward direction. If the value is less than 0, the animation plays in reversed direction. If the value is 0, the animation is paused. If the value is <strong id="b146041240163111"><a name="b146041240163111"></a><a name="b146041240163111"></a>1.0</strong> or <strong id="b327517434313"><a name="b327517434313"></a><a name="b327517434313"></a>-1.0</strong>, the animation plays at the normal speed.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    this.anim.setSpeed(5);
    ```


## AnimationItem.setDirection<a name="section1782514083712"></a>

setDirection\(direction: AnimationDirection\): void

Sets the playback direction of an animation.

-   Parameters

    <a name="table282674013711"></a>
    <table><thead align="left"><tr id="row118267404373"><th class="cellrowborder" valign="top" width="15.939999999999998%" id="mcps1.1.5.1.1"><p id="p68263405370"><a name="p68263405370"></a><a name="p68263405370"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.790000000000001%" id="mcps1.1.5.1.2"><p id="p382634013710"><a name="p382634013710"></a><a name="p382634013710"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p2826240183716"><a name="p2826240183716"></a><a name="p2826240183716"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p582694011379"><a name="p582694011379"></a><a name="p582694011379"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9826164043717"><td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.1.5.1.1 "><p id="p8826440143712"><a name="p8826440143712"></a><a name="p8826440143712"></a>direction</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.790000000000001%" headers="mcps1.1.5.1.2 "><p id="p4356532125820"><a name="p4356532125820"></a><a name="p4356532125820"></a>AnimationDirection</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p982644083717"><a name="p982644083717"></a><a name="p982644083717"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p17826124023719"><a name="p17826124023719"></a><a name="p17826124023719"></a>Direction in which the animation plays. <strong id="b0135658324"><a name="b0135658324"></a><a name="b0135658324"></a>1</strong>: forwards; <strong id="b5136165153212"><a name="b5136165153212"></a><a name="b5136165153212"></a>-1</strong>: backwards. When set to play backwards, the animation plays from the current playback progress to the first frame. When this setting is combined with <strong id="b14137175153213"><a name="b14137175153213"></a><a name="b14137175153213"></a>loop</strong> being set to <strong id="b16137351321"><a name="b16137351321"></a><a name="b16137351321"></a>true</strong>, the animation plays backwards continuously. When the value of <strong id="b1213818523213"><a name="b1213818523213"></a><a name="b1213818523213"></a>speed</strong> is less than 0, the animation also plays backwards.</p>
    <p id="p191079467212"><a name="p191079467212"></a><a name="p191079467212"></a>AnimationDirection: 1 | -1.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    this.anim.setDirection(-1)
    ```


## AnimationItem.goToAndStop<a name="section45151420204219"></a>

goToAndStop\(value: number, isFrame: boolean\): void

Sets the animation to stop at the specified frame or time.

-   Parameters

    <a name="table1351517204426"></a>
    <table><thead align="left"><tr id="row18515152044211"><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p id="p1851542012423"><a name="p1851542012423"></a><a name="p1851542012423"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.5.1.2"><p id="p1351542019421"><a name="p1351542019421"></a><a name="p1351542019421"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.08%" id="mcps1.1.5.1.3"><p id="p1051516200429"><a name="p1051516200429"></a><a name="p1051516200429"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p1951518203429"><a name="p1951518203429"></a><a name="p1951518203429"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8515162024214"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p851512016422"><a name="p851512016422"></a><a name="p851512016422"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.5.1.2 "><p id="p1451532016426"><a name="p1451532016426"></a><a name="p1451532016426"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.08%" headers="mcps1.1.5.1.3 "><p id="p1551615209422"><a name="p1551615209422"></a><a name="p1551615209422"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p10516152014423"><a name="p10516152014423"></a><a name="p10516152014423"></a>Frame ID (greater than or equal to 0) or time progress (ms) at which the animation will stop.</p>
    </td>
    </tr>
    <tr id="row1651682024214"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p18516220114218"><a name="p18516220114218"></a><a name="p18516220114218"></a>isFrame</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.5.1.2 "><p id="p051662024216"><a name="p051662024216"></a><a name="p051662024216"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.08%" headers="mcps1.1.5.1.3 "><p id="p1351642034211"><a name="p1351642034211"></a><a name="p1351642034211"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p0516182015426"><a name="p0516182015426"></a><a name="p0516182015426"></a>Whether to set the animation to stop at the specified frame. The value <strong id="b181266378358"><a name="b181266378358"></a><a name="b181266378358"></a>true</strong> means to set the animation to stop at the specified frame, and <strong id="b15947147173611"><a name="b15947147173611"></a><a name="b15947147173611"></a>false</strong> means to set the animation to stop at the specified time progress. The default value is <strong id="b17012483719"><a name="b17012483719"></a><a name="b17012483719"></a>false</strong>.</p>
    </td>
    </tr>
    <tr id="row189417300253"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p18942193082518"><a name="p18942193082518"></a><a name="p18942193082518"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.5.1.2 "><p id="p1194253062510"><a name="p1194253062510"></a><a name="p1194253062510"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.08%" headers="mcps1.1.5.1.3 "><p id="p1294263017254"><a name="p1294263017254"></a><a name="p1294263017254"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p494243012515"><a name="p494243012515"></a><a name="p494243012515"></a>Name of the target animation. By default, the value is null.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    // Set the animation to stop at the specified frame.
    this.anim.goToAndStop(25, true)
    // Set the animation to stop at the specified time progress.
    this.anim.goToAndStop(300, false, this.animateName)
    ```


## AnimationItem.goToAndPlay<a name="section2998182654614"></a>

goToAndPlay\(value: number, isFrame: boolean\): void

Sets the animation to start from the specified frame or time progress.

-   Parameters

    <a name="table9999142654618"></a>
    <table><thead align="left"><tr id="row199994261469"><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p id="p1099952618463"><a name="p1099952618463"></a><a name="p1099952618463"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.19%" id="mcps1.1.5.1.2"><p id="p1799910264461"><a name="p1799910264461"></a><a name="p1799910264461"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p109998262462"><a name="p109998262462"></a><a name="p109998262462"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.21%" id="mcps1.1.5.1.4"><p id="p129990264461"><a name="p129990264461"></a><a name="p129990264461"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3999726104614"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p1899914267467"><a name="p1899914267467"></a><a name="p1899914267467"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.19%" headers="mcps1.1.5.1.2 "><p id="p109991026134615"><a name="p109991026134615"></a><a name="p109991026134615"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p159996266465"><a name="p159996266465"></a><a name="p159996266465"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p3999526194616"><a name="p3999526194616"></a><a name="p3999526194616"></a>Frame ID (greater than or equal to 0) or time progress (ms) at which the animation will start.</p>
    </td>
    </tr>
    <tr id="row199999264465"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p29991226114610"><a name="p29991226114610"></a><a name="p29991226114610"></a>isFrame</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.19%" headers="mcps1.1.5.1.2 "><p id="p15042794615"><a name="p15042794615"></a><a name="p15042794615"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p1701127104617"><a name="p1701127104617"></a><a name="p1701127104617"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p1302272462"><a name="p1302272462"></a><a name="p1302272462"></a>Whether to set the animation to start from the specified frame. The value <strong id="b67738283449"><a name="b67738283449"></a><a name="b67738283449"></a>true</strong> means to set the animation to start from the specified frame, and <strong id="b11773628174413"><a name="b11773628174413"></a><a name="b11773628174413"></a>false</strong> means to set the animation to start from the specified time progress. The default value is <strong id="b187742028164418"><a name="b187742028164418"></a><a name="b187742028164418"></a>false</strong>.</p>
    </td>
    </tr>
    <tr id="row41884816258"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p91891388253"><a name="p91891388253"></a><a name="p91891388253"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.19%" headers="mcps1.1.5.1.2 "><p id="p131897862511"><a name="p131897862511"></a><a name="p131897862511"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p71891989255"><a name="p71891989255"></a><a name="p71891989255"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.21%" headers="mcps1.1.5.1.4 "><p id="p41890812517"><a name="p41890812517"></a><a name="p41890812517"></a>Name of the target animation. By default, the value is null.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    // Set the animation to start from the specified frame.
    this.anim.goToAndPlay(25, true)
    // Set the animation to start from the specified time progress.
    this.anim.goToAndPlay(300, false, this.animateName)
    ```


## AnimationItem.playSegments<a name="section935124765113"></a>

playSegments\(segments: AnimationSegment | AnimationSegment\[\], forceFlag: boolean\): void

Sets the animation to play only the specified segment.

-   Parameters

    <a name="table11351447155118"></a>
    <table><thead align="left"><tr id="row435847145117"><th class="cellrowborder" valign="top" width="10.6%" id="mcps1.1.5.1.1"><p id="p1351147105112"><a name="p1351147105112"></a><a name="p1351147105112"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.12%" id="mcps1.1.5.1.2"><p id="p1335747135114"><a name="p1335747135114"></a><a name="p1335747135114"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.05%" id="mcps1.1.5.1.3"><p id="p635144755111"><a name="p635144755111"></a><a name="p635144755111"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p id="p33534715114"><a name="p33534715114"></a><a name="p33534715114"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row183594714514"><td class="cellrowborder" valign="top" width="10.6%" headers="mcps1.1.5.1.1 "><p id="p9350478514"><a name="p9350478514"></a><a name="p9350478514"></a>segments</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.12%" headers="mcps1.1.5.1.2 "><p id="p8351474514"><a name="p8351474514"></a><a name="p8351474514"></a>AnimationSegment = [number, number] | AnimationSegment[]</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.5.1.3 "><p id="p135134785111"><a name="p135134785111"></a><a name="p135134785111"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p id="p74901014133519"><a name="p74901014133519"></a><a name="p74901014133519"></a>Segment or segment list.</p>
    <p id="p1836194717510"><a name="p1836194717510"></a><a name="p1836194717510"></a>If all segments in the segment list are played, only the last segment is played in the next cycle.</p>
    </td>
    </tr>
    <tr id="row113634716514"><td class="cellrowborder" valign="top" width="10.6%" headers="mcps1.1.5.1.1 "><p id="p1036184775114"><a name="p1036184775114"></a><a name="p1036184775114"></a>forceFlag</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.12%" headers="mcps1.1.5.1.2 "><p id="p19362476514"><a name="p19362476514"></a><a name="p19362476514"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.5.1.3 "><p id="p123618476516"><a name="p123618476516"></a><a name="p123618476516"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p id="p133644713510"><a name="p133644713510"></a><a name="p133644713510"></a>Whether the settings take effect immediately. The value <strong id="b63296404473"><a name="b63296404473"></a><a name="b63296404473"></a>true</strong> means the settings take effect immediately, and <strong id="b1767818234818"><a name="b1767818234818"></a><a name="b1767818234818"></a>false</strong> means the settings take effect until the current cycle of playback is completed.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    // Set the animation to play the specified segment.
    this.anim.playSegments([10, 20], false)
    // Set the animation to play the specified segment list.
    this.anim.playSegments([[0, 5], [20, 30]], true)
    ```


## AnimationItem.resetSegments<a name="section198278408372"></a>

resetSegments\(forceFlag: boolean\): void

Resets the settings configured by the  **playSegments**  method to play all the frames.

-   Parameters

    <a name="table5827114033715"></a>
    <table><thead align="left"><tr id="row18277404377"><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p id="p782794033719"><a name="p782794033719"></a><a name="p782794033719"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.19%" id="mcps1.1.5.1.2"><p id="p082774015373"><a name="p082774015373"></a><a name="p082774015373"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.040000000000001%" id="mcps1.1.5.1.3"><p id="p12827140153717"><a name="p12827140153717"></a><a name="p12827140153717"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p id="p1482714053713"><a name="p1482714053713"></a><a name="p1482714053713"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15827124015377"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p1082719409377"><a name="p1082719409377"></a><a name="p1082719409377"></a>forceFlag</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.19%" headers="mcps1.1.5.1.2 "><p id="p982734011376"><a name="p982734011376"></a><a name="p982734011376"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.040000000000001%" headers="mcps1.1.5.1.3 "><p id="p1782784014371"><a name="p1782784014371"></a><a name="p1782784014371"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p id="p1082774063718"><a name="p1082774063718"></a><a name="p1082774063718"></a>Whether the settings take effect immediately. The value <strong id="b469377105815"><a name="b469377105815"></a><a name="b469377105815"></a>true</strong> means the settings take effect immediately, and <strong id="b13694373586"><a name="b13694373586"></a><a name="b13694373586"></a>false</strong> means the settings take effect until the current cycle of playback is completed.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    this.anim.resetSegments(true)
    ```


## AnimationItem.resize<a name="section2672102714417"></a>

resize\(\): void

Refreshes the animation layout.

-   Example

    ```
    this.anim.resize()
    ```


## AnimationItem.setSubframe<a name="section151492219586"></a>

setSubframe\(useSubFrame: boolean\): void

Sets the precision of the  **currentFrame**  attribute to display floating-point numbers.

-   Parameters

    <a name="table131492212583"></a>
    <table><thead align="left"><tr id="row1715062155810"><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p id="p315012145815"><a name="p315012145815"></a><a name="p315012145815"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.5.1.2"><p id="p1615014217584"><a name="p1615014217584"></a><a name="p1615014217584"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.059999999999999%" id="mcps1.1.5.1.3"><p id="p171501927581"><a name="p171501927581"></a><a name="p171501927581"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p id="p115072155819"><a name="p115072155819"></a><a name="p115072155819"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row151502255812"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p171501219585"><a name="p171501219585"></a><a name="p171501219585"></a>useSubFrames</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.5.1.2 "><p id="p21509216581"><a name="p21509216581"></a><a name="p21509216581"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.059999999999999%" headers="mcps1.1.5.1.3 "><p id="p121501620588"><a name="p121501620588"></a><a name="p121501620588"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p id="p476416819295"><a name="p476416819295"></a><a name="p476416819295"></a>Whether the <strong id="b75135316112"><a name="b75135316112"></a><a name="b75135316112"></a>currentFrame</strong> attribute displays floating-point numbers. By default, the attribute displays floating-point numbers.</p>
    <p id="p13275161884312"><a name="p13275161884312"></a><a name="p13275161884312"></a><strong id="b1774172511219"><a name="b1774172511219"></a><a name="b1774172511219"></a>true</strong>: The <strong id="b13889730023"><a name="b13889730023"></a><a name="b13889730023"></a>currentFrame</strong> attribute displays floating-point numbers.</p>
    <p id="p2025101315457"><a name="p2025101315457"></a><a name="p2025101315457"></a><strong id="b197507536218"><a name="b197507536218"></a><a name="b197507536218"></a>false</strong>: The <strong id="b375115538210"><a name="b375115538210"></a><a name="b375115538210"></a>currentFrame</strong> attribute displays an integer and does not display floating-point numbers.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    this.anim.setSubframe(false)
    ```


## AnimationItem.getDuration<a name="section1621121414110"></a>

getDuration\(inFrames?: boolean\): void

Obtains the duration \(irrelevant to the playback speed\) or number of frames for playing an animation sequence. The settings are related to the input parameter  **initialSegment**  of the  **Lottie.loadAnimation**  interface.

-   Parameters

    <a name="table176213148111"></a>
    <table><thead align="left"><tr id="row15623171412117"><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p id="p106231141919"><a name="p106231141919"></a><a name="p106231141919"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.19%" id="mcps1.1.5.1.2"><p id="p76231614116"><a name="p76231614116"></a><a name="p76231614116"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.040000000000001%" id="mcps1.1.5.1.3"><p id="p362301416113"><a name="p362301416113"></a><a name="p362301416113"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p id="p196231914511"><a name="p196231914511"></a><a name="p196231914511"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row186237141813"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p96237141410"><a name="p96237141410"></a><a name="p96237141410"></a>inFrames</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.19%" headers="mcps1.1.5.1.2 "><p id="p962311144120"><a name="p962311144120"></a><a name="p962311144120"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.040000000000001%" headers="mcps1.1.5.1.3 "><p id="p1462341416119"><a name="p1462341416119"></a><a name="p1462341416119"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p id="p46232142114"><a name="p46232142114"></a><a name="p46232142114"></a>Whether to obtain the duration or number of frames. <strong id="b10478181318517"><a name="b10478181318517"></a><a name="b10478181318517"></a>true</strong>: number of frames. <strong id="b19151151919515"><a name="b19151151919515"></a><a name="b19151151919515"></a>false</strong>: duration, in ms. The default value is <strong id="b32951629352"><a name="b32951629352"></a><a name="b32951629352"></a>false</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    this.anim.setSubframe(true)
    ```


## AnimationItem.addEventListener<a name="section2025011161294"></a>

addEventListener<T = any\>\(name: AnimationEventName, callback: AnimationEventCallback<T\>\): \(\) =\> void

Adds an event listener. After the event is complete, the specified callback function is triggered. This method returns the function object that can delete the event listener.

-   Parameters

    <a name="table152501816397"></a>
    <table><thead align="left"><tr id="row192511516491"><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p id="p12512163916"><a name="p12512163916"></a><a name="p12512163916"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.03%" id="mcps1.1.5.1.2"><p id="p1525101614914"><a name="p1525101614914"></a><a name="p1525101614914"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.199999999999999%" id="mcps1.1.5.1.3"><p id="p72511116499"><a name="p72511116499"></a><a name="p72511116499"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p id="p192511166920"><a name="p192511166920"></a><a name="p192511166920"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row62511616498"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p02514161193"><a name="p02514161193"></a><a name="p02514161193"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p14251151611913"><a name="p14251151611913"></a><a name="p14251151611913"></a>AnimationEventName</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p id="p82517161296"><a name="p82517161296"></a><a name="p82517161296"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p id="p325112161493"><a name="p325112161493"></a><a name="p325112161493"></a>Animation event type. The available options are as follows:</p>
    <p id="p925113164912"><a name="p925113164912"></a><a name="p925113164912"></a>'enterFrame', 'loopComplete', 'complete', 'segmentStart', 'destroy', 'config_ready', 'data_ready', 'DOMLoaded', 'error', 'data_failed', 'loaded_images'</p>
    </td>
    </tr>
    <tr id="row12251916992"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p182517168919"><a name="p182517168919"></a><a name="p182517168919"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p1525114162912"><a name="p1525114162912"></a><a name="p1525114162912"></a>AnimationEventCallback&lt;T&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p id="p11251111610919"><a name="p11251111610919"></a><a name="p11251111610919"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p id="p625101619911"><a name="p625101619911"></a><a name="p625101619911"></a>Custom callback.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    private callbackItem: any = function() {
        console.log("grunt loopComplete")
    }
    let delFunction = this.animateItem.addEventListener('loopComplete', this.callbackItem)
    
    // Delete the event listener.
    delFunction()
    ```


## AnimationItem.removeEventListener<a name="section10518181695"></a>

removeEventListener<T = any\>\(name: AnimationEventName, callback?: AnimationEventCallback<T\>\): void

Deletes an event listener.

-   Parameters

    <a name="table3614182916"></a>
    <table><thead align="left"><tr id="row13601817910"><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p id="p8611812912"><a name="p8611812912"></a><a name="p8611812912"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.03%" id="mcps1.1.5.1.2"><p id="p166918398"><a name="p166918398"></a><a name="p166918398"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.199999999999999%" id="mcps1.1.5.1.3"><p id="p065184911"><a name="p065184911"></a><a name="p065184911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p id="p968181093"><a name="p968181093"></a><a name="p968181093"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16618188917"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p17618181195"><a name="p17618181195"></a><a name="p17618181195"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p1261518390"><a name="p1261518390"></a><a name="p1261518390"></a>AnimationEventName</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p id="p06618997"><a name="p06618997"></a><a name="p06618997"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p id="p16612181999"><a name="p16612181999"></a><a name="p16612181999"></a>Animation event type. The available options are as follows:</p>
    <p id="p187222374811"><a name="p187222374811"></a><a name="p187222374811"></a>'enterFrame', 'loopComplete', 'complete', 'segmentStart', 'destroy', 'config_ready', 'data_ready', 'DOMLoaded', 'error', 'data_failed', 'loaded_images'</p>
    </td>
    </tr>
    <tr id="row1877186912"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p1471918291"><a name="p1471918291"></a><a name="p1471918291"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p9711189916"><a name="p9711189916"></a><a name="p9711189916"></a>AnimationEventCallback&lt;T&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p id="p9721820914"><a name="p9721820914"></a><a name="p9721820914"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p id="p177918695"><a name="p177918695"></a><a name="p177918695"></a>Custom callback. By default, the value is null, meaning that all callbacks of the event will be removed.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    this.animateItem.removeEventListener('loopComplete', this.callbackItem)
    ```


## AnimationItem.triggerEvent<a name="section15091813747"></a>

triggerEvent<T = any\>\(name: AnimationEventName, args: T\): void

Directly triggers all configured callbacks of a specified event.

-   Parameters

    <a name="table1750916131410"></a>
    <table><thead align="left"><tr id="row45091131344"><th class="cellrowborder" valign="top" width="15.540000000000001%" id="mcps1.1.5.1.1"><p id="p050912131942"><a name="p050912131942"></a><a name="p050912131942"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.03%" id="mcps1.1.5.1.2"><p id="p45091213344"><a name="p45091213344"></a><a name="p45091213344"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.199999999999999%" id="mcps1.1.5.1.3"><p id="p165093131046"><a name="p165093131046"></a><a name="p165093131046"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.23%" id="mcps1.1.5.1.4"><p id="p195096131648"><a name="p195096131648"></a><a name="p195096131648"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row195095131646"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p15093131344"><a name="p15093131344"></a><a name="p15093131344"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p16509213744"><a name="p16509213744"></a><a name="p16509213744"></a>AnimationEventName</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p id="p195097138419"><a name="p195097138419"></a><a name="p195097138419"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p id="p1197421614715"><a name="p1197421614715"></a><a name="p1197421614715"></a>Animation event type.</p>
    <p id="p1851019131541"><a name="p1851019131541"></a><a name="p1851019131541"></a></p>
    </td>
    </tr>
    <tr id="row916615517519"><td class="cellrowborder" valign="top" width="15.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p141663558519"><a name="p141663558519"></a><a name="p141663558519"></a>args</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.03%" headers="mcps1.1.5.1.2 "><p id="p1316620558514"><a name="p1316620558514"></a><a name="p1316620558514"></a>any</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.199999999999999%" headers="mcps1.1.5.1.3 "><p id="p21665551252"><a name="p21665551252"></a><a name="p21665551252"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.23%" headers="mcps1.1.5.1.4 "><p id="p216619557512"><a name="p216619557512"></a><a name="p216619557512"></a>Custom callback parameters.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    private triggerCallBack: any = function(item) {
        console.log("trigger loopComplete, name:" + item.name)
    }
    
    this.animateItem.addEventListener('loopComplete', this.triggerCallBack)
    this.animateItem.triggerEvent('loopComplete', this.animateItem)
    this.animateItem.removeEventListener('loopComplete', this.triggerCallBack)
    ```


