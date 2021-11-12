# Custom Component Lifecycle Callbacks<a name="EN-US_TOPIC_0000001110948896"></a>

The lifecycle callbacks of a custom component are used to notify users of the lifecycle of the component. These callbacks are private and are invoked by the development framework at a specified time during running. They cannot be manually invoked from applications.

## Lifecycle Callback Definition<a name="section1597015432486"></a>

<a name="table56583904911"></a>
<table><thead align="left"><tr id="row146581198495"><th class="cellrowborder" valign="top" width="14.84%" id="mcps1.1.3.1.1"><p id="p19658139114912"><a name="p19658139114912"></a><a name="p19658139114912"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="85.16%" id="mcps1.1.3.1.2"><p id="p06581592499"><a name="p06581592499"></a><a name="p06581592499"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row11658109194919"><td class="cellrowborder" valign="top" width="14.84%" headers="mcps1.1.3.1.1 "><p id="p9658109154912"><a name="p9658109154912"></a><a name="p9658109154912"></a>aboutToAppear</p>
</td>
<td class="cellrowborder" valign="top" width="85.16%" headers="mcps1.1.3.1.2 "><p id="p17851645015"><a name="p17851645015"></a><a name="p17851645015"></a>Executed after a new instance of the custom component is created and before its <strong id="b5869734121610"><a name="b5869734121610"></a><a name="b5869734121610"></a>build</strong> function is executed.</p>
<p id="p7658596490"><a name="p7658596490"></a><a name="p7658596490"></a>You can change state variables in the <strong id="b99359017178"><a name="b99359017178"></a><a name="b99359017178"></a>aboutToAppear</strong> function, which will take effect when you execute the <strong id="b157198921719"><a name="b157198921719"></a><a name="b157198921719"></a>build</strong> function later.</p>
</td>
</tr>
<tr id="row1465811913499"><td class="cellrowborder" valign="top" width="14.84%" headers="mcps1.1.3.1.1 "><p id="p1665939124911"><a name="p1665939124911"></a><a name="p1665939124911"></a>aboutToDisappear</p>
</td>
<td class="cellrowborder" valign="top" width="85.16%" headers="mcps1.1.3.1.2 "><p id="p182511622115113"><a name="p182511622115113"></a><a name="p182511622115113"></a>Executed before the destructor of the custom component is consumed.</p>
<p id="p15659199144918"><a name="p15659199144918"></a><a name="p15659199144918"></a>Do not change state variables in the <strong id="b113997361170"><a name="b113997361170"></a><a name="b113997361170"></a>aboutToDisappear</strong> function. Especially, the modification of the <strong id="b1438344751717"><a name="b1438344751717"></a><a name="b1438344751717"></a>@Link</strong> annotated variable may cause unstable application behavior.</p>
</td>
</tr>
<tr id="row1930416179282"><td class="cellrowborder" valign="top" width="14.84%" headers="mcps1.1.3.1.1 "><p id="p1430441792819"><a name="p1430441792819"></a><a name="p1430441792819"></a>onPageShow</p>
</td>
<td class="cellrowborder" valign="top" width="85.16%" headers="mcps1.1.3.1.2 "><p id="p16304131722812"><a name="p16304131722812"></a><a name="p16304131722812"></a>Invoked when the page is displayed. The scenarios include the routing process and scenarios where the application is switched to the foreground or background. Only the custom components decorated by <strong id="b1464282018197"><a name="b1464282018197"></a><a name="b1464282018197"></a>@Entry</strong> take effect.</p>
</td>
</tr>
<tr id="row124040130281"><td class="cellrowborder" valign="top" width="14.84%" headers="mcps1.1.3.1.1 "><p id="p5404191372818"><a name="p5404191372818"></a><a name="p5404191372818"></a>onPageHide</p>
</td>
<td class="cellrowborder" valign="top" width="85.16%" headers="mcps1.1.3.1.2 "><p id="p1740410136287"><a name="p1740410136287"></a><a name="p1740410136287"></a>Invoked when the page is hidden. The scenarios include the routing process and scenarios where the application is switched to the foreground or background. Only the custom components decorated by <strong id="b86916375193"><a name="b86916375193"></a><a name="b86916375193"></a>@Entry</strong> take effect.</p>
</td>
</tr>
<tr id="row914614415143"><td class="cellrowborder" valign="top" width="14.84%" headers="mcps1.1.3.1.1 "><p id="p1420710493489"><a name="p1420710493489"></a><a name="p1420710493489"></a>onBackPress</p>
</td>
<td class="cellrowborder" valign="top" width="85.16%" headers="mcps1.1.3.1.2 "><p id="p1020714916483"><a name="p1020714916483"></a><a name="p1020714916483"></a>Invoked when a user clicks the back button. Only the custom components decorated by <strong id="b117484422012"><a name="b117484422012"></a><a name="b117484422012"></a>@Entry</strong> take effect.</p>
<a name="ul02081949144816"></a><a name="ul02081949144816"></a><ul id="ul02081949144816"><li>The value <strong id="b15338151114203"><a name="b15338151114203"></a><a name="b15338151114203"></a>true</strong> is returned if the page processes the return logic and does not route the page.</li><li><strong id="b186911429200"><a name="b186911429200"></a><a name="b186911429200"></a>false</strong> is returned if the default return logic is used.</li><li>If no value is returned, the default return logic is used.</li></ul>
</td>
</tr>
</tbody>
</table>

## Example<a name="section462551935217"></a>

```
@Component
struct CountDownTimerComponent {
    @State countDownFrom: number = 10
    private timerId: number = -1

    private aboutToAppear(): void  {
        this.timerId = setInterval(() => {
            if (this.countDownFrom <= 1) {
                clearTimeout(this.timerId)
            }
            this.countDownFrom -= 1
        }, 1000) // decr counter by 1 every second
    }

    private aboutToDisappear(): void {
        if (this.timerId > 0) {
            clearTimeout(this.timerId)
            this.timerId = -1
        }
    }

    build() {
        Text(`${this.countDownFrom} sec left`)
    }
}
```

The example above shows that lifecycle functions are critical to allowing  **CountDownTimerComponent**  to manage its timer resources. Similar functions include loading resources asynchronously from the network.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Promise and asynchronous callback functions can be used in lifecycle functions, for example, network resource getters and timer setters.
>-   Do not use  **async await**  in lifecycle functions.

