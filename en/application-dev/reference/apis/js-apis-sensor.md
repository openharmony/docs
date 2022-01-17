# Sensors<a name="EN-US_TOPIC_0000001145015663"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The APIs of this module are supported since API version 8.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import sensor from '@ohos.sensor';
```

## Required Permissions<a name="section11257113618419"></a>

To use the pedometer sensor, you must declare the  **ohos.permission.ACTIVITY\_MOTION**  permission.

To use the heart rate sensor, you must declare the  **ohos.permission.READ\_HEALTH\_DATA**  permission.

To use the acceleration sensor, you must declare the  **ohos.permission.ACCELEROMETER**  permission.

To use the gyroscope sensor, you must declare the  **ohos.permission.GYROSCOPE**  permission.

## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\)<a name="section18465193010412"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER, callback: AsyncCallback<AccelerometerResponse\>,options?: Options\): void

Subscribes to acceleration sensor data changes. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table2075112665713"></a>
    <table><thead align="left"><tr id="row141172213109"><th class="cellrowborder" valign="top" width="9.94%" id="mcps1.1.5.1.1"><p id="p127554610576"><a name="p127554610576"></a><a name="p127554610576"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.98%" id="mcps1.1.5.1.2"><p id="p147568665710"><a name="p147568665710"></a><a name="p147568665710"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.819999999999999%" id="mcps1.1.5.1.3"><p id="p2756761571"><a name="p2756761571"></a><a name="p2756761571"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.26%" id="mcps1.1.5.1.4"><p id="p5757196135713"><a name="p5757196135713"></a><a name="p5757196135713"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row81102271018"><td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.1 "><p id="p775710613575"><a name="p775710613575"></a><a name="p775710613575"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.98%" headers="mcps1.1.5.1.2 "><p id="p97582617572"><a name="p97582617572"></a><a name="p97582617572"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819999999999999%" headers="mcps1.1.5.1.3 "><p id="p475812616575"><a name="p475812616575"></a><a name="p475812616575"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.26%" headers="mcps1.1.5.1.4 "><p id="p2759116115718"><a name="p2759116115718"></a><a name="p2759116115718"></a>Type of the sensor to subscribe to, which is <strong id="b138017994415"><a name="b138017994415"></a><a name="b138017994415"></a>SENSOR_TYPE_ID_ACCELEROMETER</strong>.</p>
    </td>
    </tr>
    <tr id="row712152214107"><td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.1 "><p id="p8759763577"><a name="p8759763577"></a><a name="p8759763577"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.98%" headers="mcps1.1.5.1.2 "><p id="p1760268571"><a name="p1760268571"></a><a name="p1760268571"></a>AsyncCallback&lt;<a href="#section965820576618">AccelerometerResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819999999999999%" headers="mcps1.1.5.1.3 "><p id="p19760206145713"><a name="p19760206145713"></a><a name="p19760206145713"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.26%" headers="mcps1.1.5.1.4 "><p id="p19761136155715"><a name="p19761136155715"></a><a name="p19761136155715"></a>Callback used to return the acceleration sensor data. The reported data type in the callback is <strong id="b52925231436"><a name="b52925231436"></a><a name="b52925231436"></a>AccelerometerResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row15724175320317"><td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.1 "><p id="p157625625712"><a name="p157625625712"></a><a name="p157625625712"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.98%" headers="mcps1.1.5.1.2 "><p id="p876286205719"><a name="p876286205719"></a><a name="p876286205719"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.819999999999999%" headers="mcps1.1.5.1.3 "><p id="p276214665714"><a name="p276214665714"></a><a name="p276214665714"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.26%" headers="mcps1.1.5.1.4 "><p id="p1476317685710"><a name="p1476317685710"></a><a name="p1476317685710"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type:SensorType.SENSOR_TYPE_ID_ACCELEROMETER,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);    
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      },
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_LINEAR\_ACCELERATION\)<a name="section136091757133617"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_LINEAR\_ACCELERATION,callback:AsyncCallback<LinearAccelerometerResponse\>, options?: Options\): void

Subscribes to data changes of the linear acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table1762125182215"></a>
    <table><thead align="left"><tr id="row2612657153617"><th class="cellrowborder" valign="top" width="8.85%" id="mcps1.1.5.1.1"><p id="p1567195142214"><a name="p1567195142214"></a><a name="p1567195142214"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="37.81%" id="mcps1.1.5.1.2"><p id="p146745114224"><a name="p146745114224"></a><a name="p146745114224"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.36%" id="mcps1.1.5.1.3"><p id="p16681351112219"><a name="p16681351112219"></a><a name="p16681351112219"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.980000000000004%" id="mcps1.1.5.1.4"><p id="p96895112227"><a name="p96895112227"></a><a name="p96895112227"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9615195714369"><td class="cellrowborder" valign="top" width="8.85%" headers="mcps1.1.5.1.1 "><p id="p66855113223"><a name="p66855113223"></a><a name="p66855113223"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.81%" headers="mcps1.1.5.1.2 "><p id="p56965152215"><a name="p56965152215"></a><a name="p56965152215"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="5.36%" headers="mcps1.1.5.1.3 "><p id="p1369105112226"><a name="p1369105112226"></a><a name="p1369105112226"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p1069951112213"><a name="p1069951112213"></a><a name="p1069951112213"></a>Type of the sensor to subscribe to, which is <strong id="b6964153144920"><a name="b6964153144920"></a><a name="b6964153144920"></a>SENSOR_TYPE_ID_LINEAR_ACCELERATION</strong>.</p>
    </td>
    </tr>
    <tr id="row17616145723613"><td class="cellrowborder" valign="top" width="8.85%" headers="mcps1.1.5.1.1 "><p id="p970145152211"><a name="p970145152211"></a><a name="p970145152211"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.81%" headers="mcps1.1.5.1.2 "><p id="p9706519229"><a name="p9706519229"></a><a name="p9706519229"></a>AsyncCallback&lt;<a href="#section1151477447">LinearAccelerometerResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.36%" headers="mcps1.1.5.1.3 "><p id="p187065117220"><a name="p187065117220"></a><a name="p187065117220"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p47165172216"><a name="p47165172216"></a><a name="p47165172216"></a>Callback used to return the linear acceleration sensor data. The reported data type in the callback is <strong id="b114220431832"><a name="b114220431832"></a><a name="b114220431832"></a>LinearAccelerometerResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row661711574369"><td class="cellrowborder" valign="top" width="8.85%" headers="mcps1.1.5.1.1 "><p id="p2071145192210"><a name="p2071145192210"></a><a name="p2071145192210"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.81%" headers="mcps1.1.5.1.2 "><p id="p47265115222"><a name="p47265115222"></a><a name="p47265115222"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="5.36%" headers="mcps1.1.5.1.3 "><p id="p472351142215"><a name="p472351142215"></a><a name="p472351142215"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.980000000000004%" headers="mcps1.1.5.1.4 "><p id="p1472251162218"><a name="p1472251162218"></a><a name="p1472251162218"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type:SensorType.SENSOR_TYPE_ID_LINEAR_ACCELEROMETER,function(error,data){    
       if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\_UNCALIBRATED\)<a name="section146931430738"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\_UNCALIBRATED,callback:AsyncCallback<AccelerometerUncalibratedResponse\>, options?: Options\): void

Subscribes to data changes of the uncalibrated acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table910218517226"></a>
    <table><thead align="left"><tr id="row1769411301239"><th class="cellrowborder" valign="top" width="10.92%" id="mcps1.1.5.1.1"><p id="p010415118227"><a name="p010415118227"></a><a name="p010415118227"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="37.15%" id="mcps1.1.5.1.2"><p id="p13104175117228"><a name="p13104175117228"></a><a name="p13104175117228"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.090000000000001%" id="mcps1.1.5.1.3"><p id="p71052512225"><a name="p71052512225"></a><a name="p71052512225"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="44.84%" id="mcps1.1.5.1.4"><p id="p7105951112211"><a name="p7105951112211"></a><a name="p7105951112211"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row96957309311"><td class="cellrowborder" valign="top" width="10.92%" headers="mcps1.1.5.1.1 "><p id="p14106135142215"><a name="p14106135142215"></a><a name="p14106135142215"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.15%" headers="mcps1.1.5.1.2 "><p id="p41061951152213"><a name="p41061951152213"></a><a name="p41061951152213"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.090000000000001%" headers="mcps1.1.5.1.3 "><p id="p13107175117221"><a name="p13107175117221"></a><a name="p13107175117221"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.84%" headers="mcps1.1.5.1.4 "><p id="p91071051102216"><a name="p91071051102216"></a><a name="p91071051102216"></a>Type of the sensor to subscribe to, which is <strong id="b437363695119"><a name="b437363695119"></a><a name="b437363695119"></a>SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED</strong>.</p>
    </td>
    </tr>
    <tr id="row186970301937"><td class="cellrowborder" valign="top" width="10.92%" headers="mcps1.1.5.1.1 "><p id="p5108145182212"><a name="p5108145182212"></a><a name="p5108145182212"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.15%" headers="mcps1.1.5.1.2 "><p id="p71081351112218"><a name="p71081351112218"></a><a name="p71081351112218"></a>AsyncCallback&lt;<a href="#section253082316457">AccelerometerUncalibratedResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.090000000000001%" headers="mcps1.1.5.1.3 "><p id="p1410814513221"><a name="p1410814513221"></a><a name="p1410814513221"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.84%" headers="mcps1.1.5.1.4 "><p id="p11109145102213"><a name="p11109145102213"></a><a name="p11109145102213"></a>Callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is <strong id="b2842115410319"><a name="b2842115410319"></a><a name="b2842115410319"></a>AccelerometerUncalibratedResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row76979301934"><td class="cellrowborder" valign="top" width="10.92%" headers="mcps1.1.5.1.1 "><p id="p510914516226"><a name="p510914516226"></a><a name="p510914516226"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.15%" headers="mcps1.1.5.1.2 "><p id="p7109135122219"><a name="p7109135122219"></a><a name="p7109135122219"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.090000000000001%" headers="mcps1.1.5.1.3 "><p id="p111065172218"><a name="p111065172218"></a><a name="p111065172218"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.84%" headers="mcps1.1.5.1.4 "><p id="p011025152211"><a name="p011025152211"></a><a name="p011025152211"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type:SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        // Print the x-, y-, and z-coordinate biases.
        console.info('X-coordinate bias: ' + data.biasX);
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_GRAVITY\)<a name="section61785238140"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_GRAVITY, callback: AsyncCallback<GravityResponse\>,options?: Options\): void

Subscribes to gravity sensor data changes. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table1212835118229"></a>
    <table><thead align="left"><tr id="row1718042310144"><th class="cellrowborder" valign="top" width="12.19%" id="mcps1.1.5.1.1"><p id="p1913019516221"><a name="p1913019516221"></a><a name="p1913019516221"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.97%" id="mcps1.1.5.1.2"><p id="p151302510229"><a name="p151302510229"></a><a name="p151302510229"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.68%" id="mcps1.1.5.1.3"><p id="p0130125132216"><a name="p0130125132216"></a><a name="p0130125132216"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.16%" id="mcps1.1.5.1.4"><p id="p16130175172219"><a name="p16130175172219"></a><a name="p16130175172219"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11823238141"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p2013114514226"><a name="p2013114514226"></a><a name="p2013114514226"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.97%" headers="mcps1.1.5.1.2 "><p id="p913135162215"><a name="p913135162215"></a><a name="p913135162215"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p913112512222"><a name="p913112512222"></a><a name="p913112512222"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p7131135111222"><a name="p7131135111222"></a><a name="p7131135111222"></a>Type of the sensor to subscribe to, which is <strong id="b278018475310"><a name="b278018475310"></a><a name="b278018475310"></a>SENSOR_TYPE_ID_GRAVITY</strong>.</p>
    </td>
    </tr>
    <tr id="row118314235143"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p15132185114224"><a name="p15132185114224"></a><a name="p15132185114224"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.97%" headers="mcps1.1.5.1.2 "><p id="p1013218516223"><a name="p1013218516223"></a><a name="p1013218516223"></a>AsyncCallback&lt;<a href="#section162913399453">GravityResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p1613295192215"><a name="p1613295192215"></a><a name="p1613295192215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p11132135114224"><a name="p11132135114224"></a><a name="p11132135114224"></a>Callback used to return the gravity sensor data. The reported data type in the callback is <strong id="b6784151649"><a name="b6784151649"></a><a name="b6784151649"></a>GravityResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row2018552321412"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p5133135192212"><a name="p5133135192212"></a><a name="p5133135192212"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.97%" headers="mcps1.1.5.1.2 "><p id="p20133115118221"><a name="p20133115118221"></a><a name="p20133115118221"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p10133751142219"><a name="p10133751142219"></a><a name="p10133751142219"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p16133175172211"><a name="p16133175172211"></a><a name="p16133175172211"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type:SensorType.SENSOR_TYPE_ID_GRAVITY,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x); 
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\)<a name="section6189623151413"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE, callback: AsyncCallback<GyroscopeResponse\>, options?: Options\): void

Subscribes to gyroscope sensor data changes. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table17141851172218"></a>
    <table><thead align="left"><tr id="row12190112310148"><th class="cellrowborder" valign="top" width="12.19%" id="mcps1.1.5.1.1"><p id="p17143145132218"><a name="p17143145132218"></a><a name="p17143145132218"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.909999999999997%" id="mcps1.1.5.1.2"><p id="p1314325102216"><a name="p1314325102216"></a><a name="p1314325102216"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.529999999999999%" id="mcps1.1.5.1.3"><p id="p10143105192214"><a name="p10143105192214"></a><a name="p10143105192214"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.370000000000005%" id="mcps1.1.5.1.4"><p id="p12143051162213"><a name="p12143051162213"></a><a name="p12143051162213"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8191323131414"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p314455111224"><a name="p314455111224"></a><a name="p314455111224"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.909999999999997%" headers="mcps1.1.5.1.2 "><p id="p51442513228"><a name="p51442513228"></a><a name="p51442513228"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p6144165117229"><a name="p6144165117229"></a><a name="p6144165117229"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.370000000000005%" headers="mcps1.1.5.1.4 "><p id="p1414412515226"><a name="p1414412515226"></a><a name="p1414412515226"></a>Type of the sensor to subscribe to, which is <strong id="b11696146155312"><a name="b11696146155312"></a><a name="b11696146155312"></a>SENSOR_TYPE_ID_GYROSCOPE</strong>.</p>
    </td>
    </tr>
    <tr id="row9193162301418"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p514414512228"><a name="p514414512228"></a><a name="p514414512228"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.909999999999997%" headers="mcps1.1.5.1.2 "><p id="p151451951142214"><a name="p151451951142214"></a><a name="p151451951142214"></a>AsyncCallback&lt;<a href="#section3669131713463">GyroscopeResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p314565132216"><a name="p314565132216"></a><a name="p314565132216"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.370000000000005%" headers="mcps1.1.5.1.4 "><p id="p114545172215"><a name="p114545172215"></a><a name="p114545172215"></a>Callback used to return the gyroscope sensor data. The reported data type in the callback is <strong id="b158631216412"><a name="b158631216412"></a><a name="b158631216412"></a>GyroscopeResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row21944234143"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p101451251122214"><a name="p101451251122214"></a><a name="p101451251122214"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.909999999999997%" headers="mcps1.1.5.1.2 "><p id="p15145145172212"><a name="p15145145172212"></a><a name="p15145145172212"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p0146195111224"><a name="p0146195111224"></a><a name="p0146195111224"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.370000000000005%" headers="mcps1.1.5.1.4 "><p id="p7146165117229"><a name="p7146165117229"></a><a name="p7146165117229"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type:SensorType.SENSOR_TYPE_ID_GUROSCOPE,function(error,data){    
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x); 
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\_UNCALIBRATED\)<a name="section5203122341410"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\_UNCALIBRATED,callback:AsyncCallback<GyroscopeUncalibratedResponse\>, options?: Options\): void

Subscribes to data changes of the uncalibrated gyroscope sensor. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table6153751182217"></a>
    <table><thead align="left"><tr id="row6204132381416"><th class="cellrowborder" valign="top" width="9.22%" id="mcps1.1.5.1.1"><p id="p51556517222"><a name="p51556517222"></a><a name="p51556517222"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.58%" id="mcps1.1.5.1.2"><p id="p315545112215"><a name="p315545112215"></a><a name="p315545112215"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6%" id="mcps1.1.5.1.3"><p id="p4155351132210"><a name="p4155351132210"></a><a name="p4155351132210"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.2%" id="mcps1.1.5.1.4"><p id="p1015618515222"><a name="p1015618515222"></a><a name="p1015618515222"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18205152318147"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p115655152210"><a name="p115655152210"></a><a name="p115655152210"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.5.1.2 "><p id="p191561451132218"><a name="p191561451132218"></a><a name="p191561451132218"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6%" headers="mcps1.1.5.1.3 "><p id="p4156125113221"><a name="p4156125113221"></a><a name="p4156125113221"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.2%" headers="mcps1.1.5.1.4 "><p id="p4156135114223"><a name="p4156135114223"></a><a name="p4156135114223"></a>Type of the sensor to subscribe to, which is <strong id="b1949332625412"><a name="b1949332625412"></a><a name="b1949332625412"></a>SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED</strong>.</p>
    </td>
    </tr>
    <tr id="row1520612319148"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p7157135116220"><a name="p7157135116220"></a><a name="p7157135116220"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.5.1.2 "><p id="p1615795115228"><a name="p1615795115228"></a><a name="p1615795115228"></a>AsyncCallback&lt;<a href="#section1041541413475">GyroscopeUncalibratedResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6%" headers="mcps1.1.5.1.3 "><p id="p1115715172217"><a name="p1115715172217"></a><a name="p1115715172217"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.2%" headers="mcps1.1.5.1.4 "><p id="p17157251192215"><a name="p17157251192215"></a><a name="p17157251192215"></a>Callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is <strong id="b12207142210410"><a name="b12207142210410"></a><a name="b12207142210410"></a>GyroscopeUncalibratedResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row2020772313145"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p141575517222"><a name="p141575517222"></a><a name="p141575517222"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.5.1.2 "><p id="p61581251162211"><a name="p61581251162211"></a><a name="p61581251162211"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6%" headers="mcps1.1.5.1.3 "><p id="p1715818513229"><a name="p1715818513229"></a><a name="p1715818513229"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.2%" headers="mcps1.1.5.1.4 "><p id="p21581951172213"><a name="p21581951172213"></a><a name="p21581951172213"></a>Interval at which the callback is invoked to return the sensor data.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);  
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        // Print the x-, y-, and z-coordinate biases.
        console.info('X-coordinate bias: ' + data.biasX); 
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_SIGNIFICANT\_MOTION\)<a name="section1824612372145"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_SIGNIFICANT\_MOTION, callback: AsyncCallback<SignificantMotionResponse\>, options?: Options\): void

Subscribes to data changes of the significant motion sensor. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table181681512228"></a>
    <table><thead align="left"><tr id="row224719377142"><th class="cellrowborder" valign="top" width="9.67%" id="mcps1.1.5.1.1"><p id="p1517085114223"><a name="p1517085114223"></a><a name="p1517085114223"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="37.1%" id="mcps1.1.5.1.2"><p id="p517055110222"><a name="p517055110222"></a><a name="p517055110222"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.6000000000000005%" id="mcps1.1.5.1.3"><p id="p181701851152214"><a name="p181701851152214"></a><a name="p181701851152214"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.63%" id="mcps1.1.5.1.4"><p id="p1217085118223"><a name="p1217085118223"></a><a name="p1217085118223"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0248113712146"><td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.5.1.1 "><p id="p917116516228"><a name="p917116516228"></a><a name="p917116516228"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.1%" headers="mcps1.1.5.1.2 "><p id="p9171251162211"><a name="p9171251162211"></a><a name="p9171251162211"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.6000000000000005%" headers="mcps1.1.5.1.3 "><p id="p19171551122213"><a name="p19171551122213"></a><a name="p19171551122213"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.63%" headers="mcps1.1.5.1.4 "><p id="p11171115119223"><a name="p11171115119223"></a><a name="p11171115119223"></a>Type of the sensor to subscribe to, which is <strong id="b20923121112563"><a name="b20923121112563"></a><a name="b20923121112563"></a>SENSOR_TYPE_ID_SIGNIFICANT_MOTION</strong>.</p>
    </td>
    </tr>
    <tr id="row112521375148"><td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.5.1.1 "><p id="p1317155142211"><a name="p1317155142211"></a><a name="p1317155142211"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.1%" headers="mcps1.1.5.1.2 "><p id="p1417225152215"><a name="p1417225152215"></a><a name="p1417225152215"></a>AsyncCallback&lt;<a href="#section1213143164712">SignificantMotionResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.6000000000000005%" headers="mcps1.1.5.1.3 "><p id="p2172205118222"><a name="p2172205118222"></a><a name="p2172205118222"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.63%" headers="mcps1.1.5.1.4 "><p id="p01721851172212"><a name="p01721851172212"></a><a name="p01721851172212"></a>Callback used to return the significant motion sensor data. The reported data type in the callback is <strong id="b26901131645"><a name="b26901131645"></a><a name="b26901131645"></a>SignificantMotionResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row20253183771420"><td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.5.1.1 "><p id="p917210511225"><a name="p917210511225"></a><a name="p917210511225"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="37.1%" headers="mcps1.1.5.1.2 "><p id="p151730511227"><a name="p151730511227"></a><a name="p151730511227"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.6000000000000005%" headers="mcps1.1.5.1.3 "><p id="p1417365172219"><a name="p1417365172219"></a><a name="p1417365172219"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.63%" headers="mcps1.1.5.1.4 "><p id="p5173175132214"><a name="p5173175132214"></a><a name="p5173175132214"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        console.info('Scalar data: ' + data.scalar);
      }
      {interval: 10000000}      
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\_DETECTION\)<a name="section13257937131411"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\_DETECTION, callback: AsyncCallback<PedometerDetectResponse\>, options?: Options\): void

Subscribes to data changes of the pedometer detection sensor. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table6180125113222"></a>
    <table><thead align="left"><tr id="row225873711414"><th class="cellrowborder" valign="top" width="8.86%" id="mcps1.1.5.1.1"><p id="p4181155162210"><a name="p4181155162210"></a><a name="p4181155162210"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.79%" id="mcps1.1.5.1.2"><p id="p121821151142210"><a name="p121821151142210"></a><a name="p121821151142210"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.51%" id="mcps1.1.5.1.3"><p id="p14182185192218"><a name="p14182185192218"></a><a name="p14182185192218"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="43.84%" id="mcps1.1.5.1.4"><p id="p1218205112213"><a name="p1218205112213"></a><a name="p1218205112213"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18259153711145"><td class="cellrowborder" valign="top" width="8.86%" headers="mcps1.1.5.1.1 "><p id="p5182051152210"><a name="p5182051152210"></a><a name="p5182051152210"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.79%" headers="mcps1.1.5.1.2 "><p id="p18182195122214"><a name="p18182195122214"></a><a name="p18182195122214"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.51%" headers="mcps1.1.5.1.3 "><p id="p218335120224"><a name="p218335120224"></a><a name="p218335120224"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.84%" headers="mcps1.1.5.1.4 "><p id="p318385113220"><a name="p318385113220"></a><a name="p318385113220"></a>Type of the sensor to subscribe to, which is <strong id="b1961819598577"><a name="b1961819598577"></a><a name="b1961819598577"></a>SENSOR_TYPE_ID_PEDOMETER_DETECTION</strong>.</p>
    </td>
    </tr>
    <tr id="row20259183761419"><td class="cellrowborder" valign="top" width="8.86%" headers="mcps1.1.5.1.1 "><p id="p12183185120228"><a name="p12183185120228"></a><a name="p12183185120228"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.79%" headers="mcps1.1.5.1.2 "><p id="p1318335152212"><a name="p1318335152212"></a><a name="p1318335152212"></a>AsyncCallback&lt;<a href="#section145653910491">PedometerDetectResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.51%" headers="mcps1.1.5.1.3 "><p id="p131841516228"><a name="p131841516228"></a><a name="p131841516228"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.84%" headers="mcps1.1.5.1.4 "><p id="p918415513221"><a name="p918415513221"></a><a name="p918415513221"></a>Callback used to return the pedometer detection sensor data. The reported data type in the callback is <strong id="b211811362414"><a name="b211811362414"></a><a name="b211811362414"></a>PedometerDetectResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row1126123791420"><td class="cellrowborder" valign="top" width="8.86%" headers="mcps1.1.5.1.1 "><p id="p418485112217"><a name="p418485112217"></a><a name="p418485112217"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.79%" headers="mcps1.1.5.1.2 "><p id="p5184125122217"><a name="p5184125122217"></a><a name="p5184125122217"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.51%" headers="mcps1.1.5.1.3 "><p id="p191841451102216"><a name="p191841451102216"></a><a name="p191841451102216"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.84%" headers="mcps1.1.5.1.4 "><p id="p5185195118226"><a name="p5185195118226"></a><a name="p5185195118226"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION,function(error,data){
        if (error) {
            console.error(""Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        console.info('Scalar data: ' + data.scalar);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\)<a name="section2266113791419"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_PEDOMETER, callback: AsyncCallback<PedometerResponse\>, options?: Options\): void

Subscribes to pedometer sensor data changes. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table151911551182211"></a>
    <table><thead align="left"><tr id="row13267103781414"><th class="cellrowborder" valign="top" width="11.01%" id="mcps1.1.5.1.1"><p id="p4193185162211"><a name="p4193185162211"></a><a name="p4193185162211"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.76%" id="mcps1.1.5.1.2"><p id="p81935517221"><a name="p81935517221"></a><a name="p81935517221"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.870000000000001%" id="mcps1.1.5.1.3"><p id="p51941651182218"><a name="p51941651182218"></a><a name="p51941651182218"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.36%" id="mcps1.1.5.1.4"><p id="p41947518226"><a name="p41947518226"></a><a name="p41947518226"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18267113791416"><td class="cellrowborder" valign="top" width="11.01%" headers="mcps1.1.5.1.1 "><p id="p219495111228"><a name="p219495111228"></a><a name="p219495111228"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.76%" headers="mcps1.1.5.1.2 "><p id="p2194175110229"><a name="p2194175110229"></a><a name="p2194175110229"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.870000000000001%" headers="mcps1.1.5.1.3 "><p id="p3194115118221"><a name="p3194115118221"></a><a name="p3194115118221"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.36%" headers="mcps1.1.5.1.4 "><p id="p41952515220"><a name="p41952515220"></a><a name="p41952515220"></a>Type of the sensor to subscribe to, which is <strong id="b1761632125919"><a name="b1761632125919"></a><a name="b1761632125919"></a>SENSOR_TYPE_ID_PEDOMETER</strong>.</p>
    </td>
    </tr>
    <tr id="row1226803771414"><td class="cellrowborder" valign="top" width="11.01%" headers="mcps1.1.5.1.1 "><p id="p319515116225"><a name="p319515116225"></a><a name="p319515116225"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.76%" headers="mcps1.1.5.1.2 "><p id="p919514515220"><a name="p919514515220"></a><a name="p919514515220"></a>AsyncCallback&lt;<a href="#section1350145915489">PedometerResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.870000000000001%" headers="mcps1.1.5.1.3 "><p id="p9195115172210"><a name="p9195115172210"></a><a name="p9195115172210"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.36%" headers="mcps1.1.5.1.4 "><p id="p1319511516221"><a name="p1319511516221"></a><a name="p1319511516221"></a>Callback used to return the pedometer sensor data. The reported data type in the callback is <strong id="b232211001810"><a name="b232211001810"></a><a name="b232211001810"></a>PedometerResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row10269173731418"><td class="cellrowborder" valign="top" width="11.01%" headers="mcps1.1.5.1.1 "><p id="p10196145142216"><a name="p10196145142216"></a><a name="p10196145142216"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.76%" headers="mcps1.1.5.1.2 "><p id="p61961751132211"><a name="p61961751132211"></a><a name="p61961751132211"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.870000000000001%" headers="mcps1.1.5.1.3 "><p id="p1719614511226"><a name="p1719614511226"></a><a name="p1719614511226"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.36%" headers="mcps1.1.5.1.4 "><p id="p0196105120221"><a name="p0196105120221"></a><a name="p0196105120221"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the number of steps.
        console.info('Steps: ' + data.steps);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_TEMPERATURE\)<a name="section14362204121410"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_TEMPERATURE,callback:AsyncCallback<AmbientTemperatureResponse\>,  options?: Options\): void

Subscribes to data changes of the ambient temperature sensor. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table16204151102210"></a>
    <table><thead align="left"><tr id="row163631841101419"><th class="cellrowborder" valign="top" width="8.76%" id="mcps1.1.5.1.1"><p id="p72069513222"><a name="p72069513222"></a><a name="p72069513222"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.129999999999995%" id="mcps1.1.5.1.2"><p id="p120685115224"><a name="p120685115224"></a><a name="p120685115224"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.01%" id="mcps1.1.5.1.3"><p id="p1720618519224"><a name="p1720618519224"></a><a name="p1720618519224"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.1%" id="mcps1.1.5.1.4"><p id="p3206195172215"><a name="p3206195172215"></a><a name="p3206195172215"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6364104112149"><td class="cellrowborder" valign="top" width="8.76%" headers="mcps1.1.5.1.1 "><p id="p2020713516221"><a name="p2020713516221"></a><a name="p2020713516221"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.129999999999995%" headers="mcps1.1.5.1.2 "><p id="p92079512229"><a name="p92079512229"></a><a name="p92079512229"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.01%" headers="mcps1.1.5.1.3 "><p id="p020718515221"><a name="p020718515221"></a><a name="p020718515221"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.1%" headers="mcps1.1.5.1.4 "><p id="p11207151182219"><a name="p11207151182219"></a><a name="p11207151182219"></a>Type of the sensor to subscribe to, which is <strong id="b1441016481201"><a name="b1441016481201"></a><a name="b1441016481201"></a>SENSOR_TYPE_ID_AMBIENT_TEMPERATURE</strong>.</p>
    </td>
    </tr>
    <tr id="row1236514414147"><td class="cellrowborder" valign="top" width="8.76%" headers="mcps1.1.5.1.1 "><p id="p10207551142214"><a name="p10207551142214"></a><a name="p10207551142214"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.129999999999995%" headers="mcps1.1.5.1.2 "><p id="p220865119221"><a name="p220865119221"></a><a name="p220865119221"></a>AsyncCallback&lt;<a href="#section728281924920">AmbientTemperatureResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.01%" headers="mcps1.1.5.1.3 "><p id="p620895114227"><a name="p620895114227"></a><a name="p620895114227"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.1%" headers="mcps1.1.5.1.4 "><p id="p14208145112227"><a name="p14208145112227"></a><a name="p14208145112227"></a>Callback used to return the ambient temperature sensor data. The reported data type in the callback is <strong id="b20633755184"><a name="b20633755184"></a><a name="b20633755184"></a>AmbientTemperatureResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row93661641181417"><td class="cellrowborder" valign="top" width="8.76%" headers="mcps1.1.5.1.1 "><p id="p16208151192211"><a name="p16208151192211"></a><a name="p16208151192211"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.129999999999995%" headers="mcps1.1.5.1.2 "><p id="p1220945102215"><a name="p1220945102215"></a><a name="p1220945102215"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.01%" headers="mcps1.1.5.1.3 "><p id="p42091951182217"><a name="p42091951182217"></a><a name="p42091951182217"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.1%" headers="mcps1.1.5.1.4 "><p id="p122095516226"><a name="p122095516226"></a><a name="p122095516226"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the temperature.
        console.info('Temperature: ' + data.temperature);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\)<a name="section337584101411"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD, callback: AsyncCallback<MagneticFieldResponse\>,options?: Options\): void

Subscribes to data changes of the magnetic field sensor. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table121675111228"></a>
    <table><thead align="left"><tr id="row837654181415"><th class="cellrowborder" valign="top" width="9.31%" id="mcps1.1.5.1.1"><p id="p921711516222"><a name="p921711516222"></a><a name="p921711516222"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.4%" id="mcps1.1.5.1.2"><p id="p162171751142214"><a name="p162171751142214"></a><a name="p162171751142214"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.36%" id="mcps1.1.5.1.3"><p id="p3218351202219"><a name="p3218351202219"></a><a name="p3218351202219"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.93%" id="mcps1.1.5.1.4"><p id="p8218155110225"><a name="p8218155110225"></a><a name="p8218155110225"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1737710415146"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p1921865132220"><a name="p1921865132220"></a><a name="p1921865132220"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.4%" headers="mcps1.1.5.1.2 "><p id="p13218125172210"><a name="p13218125172210"></a><a name="p13218125172210"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.36%" headers="mcps1.1.5.1.3 "><p id="p421825117228"><a name="p421825117228"></a><a name="p421825117228"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.93%" headers="mcps1.1.5.1.4 "><p id="p421817517228"><a name="p421817517228"></a><a name="p421817517228"></a>Type of the sensor to subscribe to, which is <strong id="b131471410245"><a name="b131471410245"></a><a name="b131471410245"></a>SENSOR_TYPE_ID_MAGNETIC_FIELD</strong>.</p>
    </td>
    </tr>
    <tr id="row737854151420"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p182191251202219"><a name="p182191251202219"></a><a name="p182191251202219"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.4%" headers="mcps1.1.5.1.2 "><p id="p1421935117228"><a name="p1421935117228"></a><a name="p1421935117228"></a>AsyncCallback&lt;<a href="#section20218191813489">MagneticFieldResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.36%" headers="mcps1.1.5.1.3 "><p id="p19219165116224"><a name="p19219165116224"></a><a name="p19219165116224"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.93%" headers="mcps1.1.5.1.4 "><p id="p1219205172210"><a name="p1219205172210"></a><a name="p1219205172210"></a>Callback used to return the magnetic field sensor data. The reported data type in the callback is <strong id="b132081311151813"><a name="b132081311151813"></a><a name="b132081311151813"></a>MagneticFieldResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row15379184113149"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p122015110220"><a name="p122015110220"></a><a name="p122015110220"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.4%" headers="mcps1.1.5.1.2 "><p id="p922017510225"><a name="p922017510225"></a><a name="p922017510225"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.36%" headers="mcps1.1.5.1.3 "><p id="p522010514222"><a name="p522010514222"></a><a name="p522010514222"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.93%" headers="mcps1.1.5.1.4 "><p id="p112201515226"><a name="p112201515226"></a><a name="p112201515226"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD,function(error,data){    
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\_UNCALIBRATED\)<a name="section1738444151414"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\_UNCALIBRATED,callback:AsyncCallback<MagneticFieldUncalibratedResponse\>, options: Options\): void

Subscribes to data changes of the uncalibrated magnetic field sensor. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table16227175132211"></a>
    <table><thead align="left"><tr id="row638744121418"><th class="cellrowborder" valign="top" width="9.22%" id="mcps1.1.5.1.1"><p id="p142281051172216"><a name="p142281051172216"></a><a name="p142281051172216"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.79%" id="mcps1.1.5.1.2"><p id="p822915118223"><a name="p822915118223"></a><a name="p822915118223"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.41%" id="mcps1.1.5.1.3"><p id="p722925122215"><a name="p722925122215"></a><a name="p722925122215"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.580000000000005%" id="mcps1.1.5.1.4"><p id="p5229125182210"><a name="p5229125182210"></a><a name="p5229125182210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row638844112148"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p16229351192211"><a name="p16229351192211"></a><a name="p16229351192211"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.5.1.2 "><p id="p22291651132213"><a name="p22291651132213"></a><a name="p22291651132213"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.41%" headers="mcps1.1.5.1.3 "><p id="p11229145182218"><a name="p11229145182218"></a><a name="p11229145182218"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.580000000000005%" headers="mcps1.1.5.1.4 "><p id="p1123095116228"><a name="p1123095116228"></a><a name="p1123095116228"></a>Type of the sensor to subscribe to, which is <strong id="b399020136587"><a name="b399020136587"></a><a name="b399020136587"></a>SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED</strong>.</p>
    </td>
    </tr>
    <tr id="row17389134117147"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p823025142219"><a name="p823025142219"></a><a name="p823025142219"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.5.1.2 "><p id="p132309510220"><a name="p132309510220"></a><a name="p132309510220"></a>AsyncCallback&lt;<a href="#section13749143113486">MagneticFieldUncalibratedResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.41%" headers="mcps1.1.5.1.3 "><p id="p172301951172214"><a name="p172301951172214"></a><a name="p172301951172214"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.580000000000005%" headers="mcps1.1.5.1.4 "><p id="p1923195110226"><a name="p1923195110226"></a><a name="p1923195110226"></a>Callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is <strong id="b118141521817"><a name="b118141521817"></a><a name="b118141521817"></a>MagneticFieldUncalibratedResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row3390164110146"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p223135122220"><a name="p223135122220"></a><a name="p223135122220"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.79%" headers="mcps1.1.5.1.2 "><p id="p13231175118224"><a name="p13231175118224"></a><a name="p13231175118224"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.41%" headers="mcps1.1.5.1.3 "><p id="p723215112223"><a name="p723215112223"></a><a name="p723215112223"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.580000000000005%" headers="mcps1.1.5.1.4 "><p id="p1623216518229"><a name="p1623216518229"></a><a name="p1623216518229"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    ensor.on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);    
        console.info('Y-coordinate component: ' + data.y);    
        console.info('Z-coordinate component: ' + data.z);    
        // Print the x-, y-, and z-coordinate biases.
        console.info('X-coordinate bias: ' + data.biasX);    
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
      }
      {interval: 10000000} // Set the data reporting frequency.
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_PROXIMITY\)<a name="section12931751101418"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_PROXIMITY, callback: AsyncCallback<ProximityResponse\>,options?: Options\): void

Subscribes to proximity sensor data changes. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table3241851152213"></a>
    <table><thead align="left"><tr id="row1294135117147"><th class="cellrowborder" valign="top" width="9.22%" id="mcps1.1.5.1.1"><p id="p1224218510225"><a name="p1224218510225"></a><a name="p1224218510225"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.14%" id="mcps1.1.5.1.2"><p id="p5243951192211"><a name="p5243951192211"></a><a name="p5243951192211"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.890000000000001%" id="mcps1.1.5.1.3"><p id="p1824319515223"><a name="p1824319515223"></a><a name="p1824319515223"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.74999999999999%" id="mcps1.1.5.1.4"><p id="p172431851122211"><a name="p172431851122211"></a><a name="p172431851122211"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12295351101420"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p18243151152218"><a name="p18243151152218"></a><a name="p18243151152218"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.14%" headers="mcps1.1.5.1.2 "><p id="p18243165132215"><a name="p18243165132215"></a><a name="p18243165132215"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.890000000000001%" headers="mcps1.1.5.1.3 "><p id="p5244451102215"><a name="p5244451102215"></a><a name="p5244451102215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.74999999999999%" headers="mcps1.1.5.1.4 "><p id="p182442515220"><a name="p182442515220"></a><a name="p182442515220"></a>Type of the sensor to subscribe to, which is <strong id="b167111495597"><a name="b167111495597"></a><a name="b167111495597"></a>SENSOR_TYPE_ID_PROXIMITY</strong>.</p>
    </td>
    </tr>
    <tr id="row112961251121415"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p132441251182210"><a name="p132441251182210"></a><a name="p132441251182210"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.14%" headers="mcps1.1.5.1.2 "><p id="p2244165112218"><a name="p2244165112218"></a><a name="p2244165112218"></a>AsyncCallback&lt;<a href="#section5275184313476">ProximityResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.890000000000001%" headers="mcps1.1.5.1.3 "><p id="p2024535102217"><a name="p2024535102217"></a><a name="p2024535102217"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.74999999999999%" headers="mcps1.1.5.1.4 "><p id="p124545112214"><a name="p124545112214"></a><a name="p124545112214"></a>Callback used to return the proximity sensor data. The reported data type in the callback is <strong id="b11503101951815"><a name="b11503101951815"></a><a name="b11503101951815"></a>ProximityResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row1229715112141"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p62458519223"><a name="p62458519223"></a><a name="p62458519223"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.14%" headers="mcps1.1.5.1.2 "><p id="p1524510517224"><a name="p1524510517224"></a><a name="p1524510517224"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.890000000000001%" headers="mcps1.1.5.1.3 "><p id="p324695152215"><a name="p324695152215"></a><a name="p324695152215"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.74999999999999%" headers="mcps1.1.5.1.4 "><p id="p13246351122215"><a name="p13246351122215"></a><a name="p13246351122215"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_PROXIMITY,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the proximity.
        console.info('Distance: ' + data.distance);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_HUMIDITY\)<a name="section0302151141413"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_HUMIDITY, callback: AsyncCallback<HumidityResponse\>,options?: Options\): void

Subscribes to humidity sensor data changes. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table9254051152219"></a>
    <table><thead align="left"><tr id="row6302185131417"><th class="cellrowborder" valign="top" width="10.12%" id="mcps1.1.5.1.1"><p id="p1325555162219"><a name="p1325555162219"></a><a name="p1325555162219"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="31.830000000000002%" id="mcps1.1.5.1.2"><p id="p925595152218"><a name="p925595152218"></a><a name="p925595152218"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.66%" id="mcps1.1.5.1.3"><p id="p12256751182218"><a name="p12256751182218"></a><a name="p12256751182218"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.39%" id="mcps1.1.5.1.4"><p id="p1125685122217"><a name="p1125685122217"></a><a name="p1125685122217"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1330320518149"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p16256051182216"><a name="p16256051182216"></a><a name="p16256051182216"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.830000000000002%" headers="mcps1.1.5.1.2 "><p id="p425665192211"><a name="p425665192211"></a><a name="p425665192211"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.66%" headers="mcps1.1.5.1.3 "><p id="p1225614513228"><a name="p1225614513228"></a><a name="p1225614513228"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.39%" headers="mcps1.1.5.1.4 "><p id="p1525795182213"><a name="p1525795182213"></a><a name="p1525795182213"></a>Type of the sensor to subscribe to, which is <strong id="b1549116715014"><a name="b1549116715014"></a><a name="b1549116715014"></a>SENSOR_TYPE_ID_HUMIDITY</strong>.</p>
    </td>
    </tr>
    <tr id="row143041751141413"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p112577517228"><a name="p112577517228"></a><a name="p112577517228"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.830000000000002%" headers="mcps1.1.5.1.2 "><p id="p1525718513225"><a name="p1525718513225"></a><a name="p1525718513225"></a>AsyncCallback&lt;<a href="#section20444511666">HumidityResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.66%" headers="mcps1.1.5.1.3 "><p id="p132571851172215"><a name="p132571851172215"></a><a name="p132571851172215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.39%" headers="mcps1.1.5.1.4 "><p id="p225711515224"><a name="p225711515224"></a><a name="p225711515224"></a>Callback used to return the humidity sensor data. The reported data type in the callback is <strong id="b16778152213187"><a name="b16778152213187"></a><a name="b16778152213187"></a>HumidityResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row14305145181415"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p3258175117228"><a name="p3258175117228"></a><a name="p3258175117228"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.830000000000002%" headers="mcps1.1.5.1.2 "><p id="p325865142218"><a name="p325865142218"></a><a name="p325865142218"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.66%" headers="mcps1.1.5.1.3 "><p id="p11258151182215"><a name="p11258151182215"></a><a name="p11258151182215"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.39%" headers="mcps1.1.5.1.4 "><p id="p182582512225"><a name="p182582512225"></a><a name="p182582512225"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_HUMIDITY,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the humidity.
        console.info('Humidity: ' + data.humidity);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_BAROMETER\)<a name="section63108518141"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_BAROMETER, callback: AsyncCallback<BarometerResponse\>,options?: Options\): void

Subscribes to barometer sensor data changes. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table1266155112223"></a>
    <table><thead align="left"><tr id="row173111517141"><th class="cellrowborder" valign="top" width="9.76%" id="mcps1.1.5.1.1"><p id="p19267155110221"><a name="p19267155110221"></a><a name="p19267155110221"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="31.94%" id="mcps1.1.5.1.2"><p id="p1826775115223"><a name="p1826775115223"></a><a name="p1826775115223"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.46%" id="mcps1.1.5.1.3"><p id="p6268175192217"><a name="p6268175192217"></a><a name="p6268175192217"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.839999999999996%" id="mcps1.1.5.1.4"><p id="p5268195152216"><a name="p5268195152216"></a><a name="p5268195152216"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1931111510141"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p11268155102218"><a name="p11268155102218"></a><a name="p11268155102218"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.94%" headers="mcps1.1.5.1.2 "><p id="p1526895118225"><a name="p1526895118225"></a><a name="p1526895118225"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.46%" headers="mcps1.1.5.1.3 "><p id="p10268205112225"><a name="p10268205112225"></a><a name="p10268205112225"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p1426916513223"><a name="p1426916513223"></a><a name="p1426916513223"></a>Type of the sensor to subscribe to, which is <strong id="b84961857409"><a name="b84961857409"></a><a name="b84961857409"></a>SENSOR_TYPE_ID_BAROMETER</strong>.</p>
    </td>
    </tr>
    <tr id="row9312351181417"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p102692513229"><a name="p102692513229"></a><a name="p102692513229"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.94%" headers="mcps1.1.5.1.2 "><p id="p192694511225"><a name="p192694511225"></a><a name="p192694511225"></a>AsyncCallback&lt;<a href="#section143457303496">BarometerResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.46%" headers="mcps1.1.5.1.3 "><p id="p5269125152214"><a name="p5269125152214"></a><a name="p5269125152214"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p182694515223"><a name="p182694515223"></a><a name="p182694515223"></a>Callback used to return the barometer sensor data. The reported data type in the callback is <strong id="b13237326131811"><a name="b13237326131811"></a><a name="b13237326131811"></a>BarometerResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row143129513144"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p5270195102218"><a name="p5270195102218"></a><a name="p5270195102218"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.94%" headers="mcps1.1.5.1.2 "><p id="p12270125122213"><a name="p12270125122213"></a><a name="p12270125122213"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.46%" headers="mcps1.1.5.1.3 "><p id="p122701851162220"><a name="p122701851162220"></a><a name="p122701851162220"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p17270851132216"><a name="p17270851132216"></a><a name="p17270851132216"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_BAROMETER,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the atmospheric pressure.
        console.info('Atmospheric pressure: ' + data.pressure);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_HALL\)<a name="section20525181564919"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_HALL, callback: AsyncCallback<HallResponse\>, options?: Options\): void

Subscribes to data changes of the Hall effect sensor. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table1427745118220"></a>
    <table><thead align="left"><tr id="row84955101418"><th class="cellrowborder" valign="top" width="10.47%" id="mcps1.1.5.1.1"><p id="p9278851162214"><a name="p9278851162214"></a><a name="p9278851162214"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.689999999999998%" id="mcps1.1.5.1.2"><p id="p7279145115221"><a name="p7279145115221"></a><a name="p7279145115221"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.68%" id="mcps1.1.5.1.3"><p id="p1327935182212"><a name="p1327935182212"></a><a name="p1327935182212"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.16%" id="mcps1.1.5.1.4"><p id="p1927995111227"><a name="p1927995111227"></a><a name="p1927995111227"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row75855131417"><td class="cellrowborder" valign="top" width="10.47%" headers="mcps1.1.5.1.1 "><p id="p13279135110224"><a name="p13279135110224"></a><a name="p13279135110224"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.689999999999998%" headers="mcps1.1.5.1.2 "><p id="p19280125132220"><a name="p19280125132220"></a><a name="p19280125132220"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p3280165132217"><a name="p3280165132217"></a><a name="p3280165132217"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p18280105114225"><a name="p18280105114225"></a><a name="p18280105114225"></a>Type of the sensor to subscribe to, which is <strong id="b165461422525"><a name="b165461422525"></a><a name="b165461422525"></a>SENSOR_TYPE_ID_HALL</strong>.</p>
    </td>
    </tr>
    <tr id="row175165515149"><td class="cellrowborder" valign="top" width="10.47%" headers="mcps1.1.5.1.1 "><p id="p228015118221"><a name="p228015118221"></a><a name="p228015118221"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.689999999999998%" headers="mcps1.1.5.1.2 "><p id="p172801512226"><a name="p172801512226"></a><a name="p172801512226"></a>AsyncCallback&lt;<a href="#section18608467487">HallResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p12280155132217"><a name="p12280155132217"></a><a name="p12280155132217"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p1428114516221"><a name="p1428114516221"></a><a name="p1428114516221"></a>Callback used to return the Hall effect sensor data. The reported data type in the callback is <strong id="b8847162971820"><a name="b8847162971820"></a><a name="b8847162971820"></a>HallResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row1661555161416"><td class="cellrowborder" valign="top" width="10.47%" headers="mcps1.1.5.1.1 "><p id="p1128119516220"><a name="p1128119516220"></a><a name="p1128119516220"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.689999999999998%" headers="mcps1.1.5.1.2 "><p id="p628175115229"><a name="p628175115229"></a><a name="p628175115229"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p152814517222"><a name="p152814517222"></a><a name="p152814517222"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p42811751162212"><a name="p42811751162212"></a><a name="p42811751162212"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_HALL,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the status.
        console.info('Status: ' + data.status);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_LIGHT\)<a name="section121685551415"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_LIGHT, callback: AsyncCallback<LightResponse\>, options?: Options\): void

Subscribes to data changes of the ambient light sensor. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table102891851162218"></a>
    <table><thead align="left"><tr id="row131715511142"><th class="cellrowborder" valign="top" width="9.22%" id="mcps1.1.5.1.1"><p id="p14290115110223"><a name="p14290115110223"></a><a name="p14290115110223"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.5.1.2"><p id="p202919511227"><a name="p202919511227"></a><a name="p202919511227"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6%" id="mcps1.1.5.1.3"><p id="p13291145117226"><a name="p13291145117226"></a><a name="p13291145117226"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.96%" id="mcps1.1.5.1.4"><p id="p729117513220"><a name="p729117513220"></a><a name="p729117513220"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row51885521415"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p02912051142211"><a name="p02912051142211"></a><a name="p02912051142211"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.5.1.2 "><p id="p1629212511221"><a name="p1629212511221"></a><a name="p1629212511221"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.5.1.3 "><p id="p32921651102212"><a name="p32921651102212"></a><a name="p32921651102212"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="p202928513224"><a name="p202928513224"></a><a name="p202928513224"></a>Type of the sensor to subscribe to, which is <strong id="b1618611161312"><a name="b1618611161312"></a><a name="b1618611161312"></a>SENSOR_TYPE_ID_AMBIENT_LIGHT</strong>.</p>
    </td>
    </tr>
    <tr id="row1919185515144"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p0292851122217"><a name="p0292851122217"></a><a name="p0292851122217"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.5.1.2 "><p id="p0292451202220"><a name="p0292451202220"></a><a name="p0292451202220"></a>AsyncCallback&lt;<a href="#section195685404716">LightResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.5.1.3 "><p id="p11293105110226"><a name="p11293105110226"></a><a name="p11293105110226"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="p429355110225"><a name="p429355110225"></a><a name="p429355110225"></a>Callback used to return the ambient light sensor data. The reported data type in the callback is <strong id="b10102337184"><a name="b10102337184"></a><a name="b10102337184"></a>LightResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row1720115531412"><td class="cellrowborder" valign="top" width="9.22%" headers="mcps1.1.5.1.1 "><p id="p02937513229"><a name="p02937513229"></a><a name="p02937513229"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.5.1.2 "><p id="p1329311517223"><a name="p1329311517223"></a><a name="p1329311517223"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6%" headers="mcps1.1.5.1.3 "><p id="p12931951162214"><a name="p12931951162214"></a><a name="p12931951162214"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="p18294205102217"><a name="p18294205102217"></a><a name="p18294205102217"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT,function(error,data){
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the illumination.
        console.info(''Illumination: ' + data.intensity);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_ORIENTATION\)<a name="section794801295516"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_ORIENTATION, callback: AsyncCallback<OrientationResponse\>, options?: Options\): void

Subscribes to orientation sensor data changes. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table5311551192219"></a>
    <table><thead align="left"><tr id="row1533185512141"><th class="cellrowborder" valign="top" width="11.28%" id="mcps1.1.5.1.1"><p id="p73121551112216"><a name="p73121551112216"></a><a name="p73121551112216"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="31.869999999999997%" id="mcps1.1.5.1.2"><p id="p1731314510221"><a name="p1731314510221"></a><a name="p1731314510221"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.01%" id="mcps1.1.5.1.3"><p id="p8313651172211"><a name="p8313651172211"></a><a name="p8313651172211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.839999999999996%" id="mcps1.1.5.1.4"><p id="p20313135162218"><a name="p20313135162218"></a><a name="p20313135162218"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13341955131416"><td class="cellrowborder" valign="top" width="11.28%" headers="mcps1.1.5.1.1 "><p id="p153131151152211"><a name="p153131151152211"></a><a name="p153131151152211"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.869999999999997%" headers="mcps1.1.5.1.2 "><p id="p9314165112222"><a name="p9314165112222"></a><a name="p9314165112222"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.01%" headers="mcps1.1.5.1.3 "><p id="p6314135102212"><a name="p6314135102212"></a><a name="p6314135102212"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p5314155122214"><a name="p5314155122214"></a><a name="p5314155122214"></a>Type of the sensor to subscribe to, which is <strong id="b58731729510"><a name="b58731729510"></a><a name="b58731729510"></a>SENSOR_TYPE_ID_ORIENTATION</strong>.</p>
    </td>
    </tr>
    <tr id="row9355558146"><td class="cellrowborder" valign="top" width="11.28%" headers="mcps1.1.5.1.1 "><p id="p1331415519223"><a name="p1331415519223"></a><a name="p1331415519223"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.869999999999997%" headers="mcps1.1.5.1.2 "><p id="p23141751122217"><a name="p23141751122217"></a><a name="p23141751122217"></a>AsyncCallback&lt;<a href="#section128271514456">OrientationResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.01%" headers="mcps1.1.5.1.3 "><p id="p1031535118226"><a name="p1031535118226"></a><a name="p1031535118226"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p43158513223"><a name="p43158513223"></a><a name="p43158513223"></a>Callback used to return the orientation sensor data. The reported data type in the callback is <strong id="b42620364184"><a name="b42620364184"></a><a name="b42620364184"></a>OrientationResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row10361655151410"><td class="cellrowborder" valign="top" width="11.28%" headers="mcps1.1.5.1.1 "><p id="p63151051112216"><a name="p63151051112216"></a><a name="p63151051112216"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.869999999999997%" headers="mcps1.1.5.1.2 "><p id="p163151951192215"><a name="p163151951192215"></a><a name="p163151951192215"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.01%" headers="mcps1.1.5.1.3 "><p id="p331565112213"><a name="p331565112213"></a><a name="p331565112213"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p431619514222"><a name="p431619514222"></a><a name="p431619514222"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_ORIENTATION,function(error,data){    
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_ROTATION\_VECTOR\)<a name="section4764201154"></a>

on\(type:SensorType.SENSOR\_TYPE\_ID\_ROTATION\_VECTOR,callback:AsyncCallback<RotationVectorResponse\>,options?: Options\): void

Subscribes to rotation vector data changes. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table732335142215"></a>
    <table><thead align="left"><tr id="row176515012159"><th class="cellrowborder" valign="top" width="10.290000000000001%" id="mcps1.1.5.1.1"><p id="p6325125172213"><a name="p6325125172213"></a><a name="p6325125172213"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.55%" id="mcps1.1.5.1.2"><p id="p8326151142215"><a name="p8326151142215"></a><a name="p8326151142215"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.5600000000000005%" id="mcps1.1.5.1.3"><p id="p1532635112217"><a name="p1532635112217"></a><a name="p1532635112217"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.6%" id="mcps1.1.5.1.4"><p id="p7326125152210"><a name="p7326125152210"></a><a name="p7326125152210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row97671100151"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p73261051152210"><a name="p73261051152210"></a><a name="p73261051152210"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.55%" headers="mcps1.1.5.1.2 "><p id="p43261051142210"><a name="p43261051142210"></a><a name="p43261051142210"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.5.1.3 "><p id="p16327251182216"><a name="p16327251182216"></a><a name="p16327251182216"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.6%" headers="mcps1.1.5.1.4 "><p id="p14327451162218"><a name="p14327451162218"></a><a name="p14327451162218"></a>Type of the sensor to subscribe to, which is <strong id="b404581752"><a name="b404581752"></a><a name="b404581752"></a>SENSOR_TYPE_ID_ROTATION_VECTOR</strong>.</p>
    </td>
    </tr>
    <tr id="row67688016150"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p5327165142219"><a name="p5327165142219"></a><a name="p5327165142219"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.55%" headers="mcps1.1.5.1.2 "><p id="p132725112217"><a name="p132725112217"></a><a name="p132725112217"></a>AsyncCallback&lt;<a href="#section13776194114611">RotationVectorResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.5.1.3 "><p id="p18327851152219"><a name="p18327851152219"></a><a name="p18327851152219"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.6%" headers="mcps1.1.5.1.4 "><p id="p432855119226"><a name="p432855119226"></a><a name="p432855119226"></a>Callback used to return the rotation vector sensor data. The reported data type in the callback is <strong id="b15782439131816"><a name="b15782439131816"></a><a name="b15782439131816"></a>RotationVectorResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row776950131510"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p8328205122210"><a name="p8328205122210"></a><a name="p8328205122210"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.55%" headers="mcps1.1.5.1.2 "><p id="p12328751182215"><a name="p12328751182215"></a><a name="p12328751182215"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.5600000000000005%" headers="mcps1.1.5.1.3 "><p id="p16328351132218"><a name="p16328351132218"></a><a name="p16328351132218"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.6%" headers="mcps1.1.5.1.4 "><p id="p232812516226"><a name="p232812516226"></a><a name="p232812516226"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,function(error,data){    
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
      {interval: 10000000}
    );
    ```


## sensor.on\(SensorType.SENSOR\_TYPE\_ID\_WEAR\_DETECTION\)<a name="section9776110101518"></a>

on\(type: SensorType.SENSOR\_TYPE\_ID\_WEAR\_DETECTION, callback: AsyncCallback<WearDetectionResponse\>,options?: Options\): void

Subscribes to wear detection data changes. If this API is called multiple times for the same application, the last call takes effect.

-   Parameters

    <a name="table1433525182216"></a>
    <table><thead align="left"><tr id="row17777140171516"><th class="cellrowborder" valign="top" width="10.290000000000001%" id="mcps1.1.5.1.1"><p id="p5336135112212"><a name="p5336135112212"></a><a name="p5336135112212"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.21%" id="mcps1.1.5.1.2"><p id="p93361251152210"><a name="p93361251152210"></a><a name="p93361251152210"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.529999999999999%" id="mcps1.1.5.1.3"><p id="p153375512225"><a name="p153375512225"></a><a name="p153375512225"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.97%" id="mcps1.1.5.1.4"><p id="p103371951102214"><a name="p103371951102214"></a><a name="p103371951102214"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1477716011153"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p1833711513226"><a name="p1833711513226"></a><a name="p1833711513226"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.21%" headers="mcps1.1.5.1.2 "><p id="p12337195117220"><a name="p12337195117220"></a><a name="p12337195117220"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p203371551142219"><a name="p203371551142219"></a><a name="p203371551142219"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.97%" headers="mcps1.1.5.1.4 "><p id="p1533818515220"><a name="p1533818515220"></a><a name="p1533818515220"></a>Type of the sensor to subscribe to, which is <strong id="b185005216121"><a name="b185005216121"></a><a name="b185005216121"></a>SENSOR_TYPE_ID_WEAR_DETECTION</strong>.</p>
    </td>
    </tr>
    <tr id="row1777819011154"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p10338151112216"><a name="p10338151112216"></a><a name="p10338151112216"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.21%" headers="mcps1.1.5.1.2 "><p id="p83382514226"><a name="p83382514226"></a><a name="p83382514226"></a>AsyncCallback&lt;<a href="#section128278501495">WearDetectionResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p10338195192212"><a name="p10338195192212"></a><a name="p10338195192212"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.97%" headers="mcps1.1.5.1.4 "><p id="p133835102218"><a name="p133835102218"></a><a name="p133835102218"></a>Callback used to return the wear detection sensor data. The reported data type in the callback is <strong id="b3315745181815"><a name="b3315745181815"></a><a name="b3315745181815"></a>WearDetectionResponse</strong>.</p>
    </td>
    </tr>
    <tr id="row12779603155"><td class="cellrowborder" valign="top" width="10.290000000000001%" headers="mcps1.1.5.1.1 "><p id="p193391516224"><a name="p193391516224"></a><a name="p193391516224"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.21%" headers="mcps1.1.5.1.2 "><p id="p11339851102220"><a name="p11339851102220"></a><a name="p11339851102220"></a><a href="#section3785619107">Options</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.529999999999999%" headers="mcps1.1.5.1.3 "><p id="p1533995152216"><a name="p1533995152216"></a><a name="p1533995152216"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.97%" headers="mcps1.1.5.1.4 "><p id="p6339851182212"><a name="p6339851182212"></a><a name="p6339851182212"></a>Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.on(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION,function(error,data){    
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the wear status.
        console.info('Wear status: ' + data.value);
      }
      {interval: 10000000}
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\)<a name="section19783707153"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER, callback: AsyncCallback<AccelerometerResponse\>\): void

Subscribes to only one acceleration sensor data change.

-   Parameters

    <a name="table1934516513223"></a>
    <table><thead align="left"><tr id="row16783160171512"><th class="cellrowborder" valign="top" width="10.12%" id="mcps1.1.5.1.1"><p id="p193468516224"><a name="p193468516224"></a><a name="p193468516224"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.589999999999996%" id="mcps1.1.5.1.2"><p id="p634655118228"><a name="p634655118228"></a><a name="p634655118228"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.17%" id="mcps1.1.5.1.3"><p id="p14346051152218"><a name="p14346051152218"></a><a name="p14346051152218"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.120000000000005%" id="mcps1.1.5.1.4"><p id="p034715511227"><a name="p034715511227"></a><a name="p034715511227"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row18784160101515"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p1334735115224"><a name="p1334735115224"></a><a name="p1334735115224"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.589999999999996%" headers="mcps1.1.5.1.2 "><p id="p834785102220"><a name="p834785102220"></a><a name="p834785102220"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.17%" headers="mcps1.1.5.1.3 "><p id="p143475515227"><a name="p143475515227"></a><a name="p143475515227"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.120000000000005%" headers="mcps1.1.5.1.4 "><p id="p13471351142215"><a name="p13471351142215"></a><a name="p13471351142215"></a>Type of the sensor to subscribe to, which is <strong id="b1155113326168"><a name="b1155113326168"></a><a name="b1155113326168"></a>SENSOR_TYPE_ID_ACCELEROMETER</strong>.</p>
    </td>
    </tr>
    <tr id="row778512041510"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p10347105132210"><a name="p10347105132210"></a><a name="p10347105132210"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.589999999999996%" headers="mcps1.1.5.1.2 "><p id="p1334825102213"><a name="p1334825102213"></a><a name="p1334825102213"></a>AsyncCallback&lt;<a href="#section965820576618">AccelerometerResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.17%" headers="mcps1.1.5.1.3 "><p id="p83489517228"><a name="p83489517228"></a><a name="p83489517228"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.120000000000005%" headers="mcps1.1.5.1.4 "><p id="p13348195132214"><a name="p13348195132214"></a><a name="p13348195132214"></a>One-shot callback used to return the acceleration sensor data. The reported data type in the callback is <strong id="b721004915185"><a name="b721004915185"></a><a name="b721004915185"></a>AccelerometerResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_ACCELEROMETER, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_LINEAR\_ACCELERATION\)<a name="section18010433133"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_LINEAR\_ACCELERATION,callback:AsyncCallback<LinearAccelerometerResponse\>\): void

Subscribes to only one data change of the linear acceleration sensor.

-   Parameters

    <a name="table17354155112221"></a>
    <table><thead align="left"><tr id="row6294311318"><th class="cellrowborder" valign="top" width="9.04%" id="mcps1.1.5.1.1"><p id="p2035545118229"><a name="p2035545118229"></a><a name="p2035545118229"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.940000000000005%" id="mcps1.1.5.1.2"><p id="p173557513228"><a name="p173557513228"></a><a name="p173557513228"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.36%" id="mcps1.1.5.1.3"><p id="p8355551192215"><a name="p8355551192215"></a><a name="p8355551192215"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.660000000000004%" id="mcps1.1.5.1.4"><p id="p235645118225"><a name="p235645118225"></a><a name="p235645118225"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14534321316"><td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.5.1.1 "><p id="p135620515229"><a name="p135620515229"></a><a name="p135620515229"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.940000000000005%" headers="mcps1.1.5.1.2 "><p id="p16356351152213"><a name="p16356351152213"></a><a name="p16356351152213"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.36%" headers="mcps1.1.5.1.3 "><p id="p6356115118221"><a name="p6356115118221"></a><a name="p6356115118221"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.660000000000004%" headers="mcps1.1.5.1.4 "><p id="p17356175117221"><a name="p17356175117221"></a><a name="p17356175117221"></a>Type of the sensor to subscribe to, which is <strong id="b36092710171"><a name="b36092710171"></a><a name="b36092710171"></a>SENSOR_TYPE_ID_LINEAR_ACCELERATION</strong>.</p>
    </td>
    </tr>
    <tr id="row17104318131"><td class="cellrowborder" valign="top" width="9.04%" headers="mcps1.1.5.1.1 "><p id="p143571951172210"><a name="p143571951172210"></a><a name="p143571951172210"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.940000000000005%" headers="mcps1.1.5.1.2 "><p id="p10357751202216"><a name="p10357751202216"></a><a name="p10357751202216"></a>AsyncCallback&lt;<a href="#section1151477447">LinearAccelerometerResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.36%" headers="mcps1.1.5.1.3 "><p id="p11357105119222"><a name="p11357105119222"></a><a name="p11357105119222"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.660000000000004%" headers="mcps1.1.5.1.4 "><p id="p235735113224"><a name="p235735113224"></a><a name="p235735113224"></a>One-shot callback used to return the linear acceleration sensor data. The reported data type in the callback is <strong id="b759255291811"><a name="b759255291811"></a><a name="b759255291811"></a>LinearAccelerometerResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\_UNCALIBRATED\)<a name="section3897145813147"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_ACCELEROMETER\_UNCALIBRATED,callback:AsyncCallback<AccelerometerUncalibratedResponse\>\): void

Subscribes to only one data change of the uncalibrated acceleration sensor.

-   Parameters

    <a name="table16362451172210"></a>
    <table><thead align="left"><tr id="row889995816147"><th class="cellrowborder" valign="top" width="8.32%" id="mcps1.1.5.1.1"><p id="p936355116224"><a name="p936355116224"></a><a name="p936355116224"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.269999999999996%" id="mcps1.1.5.1.2"><p id="p23641651152216"><a name="p23641651152216"></a><a name="p23641651152216"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.96%" id="mcps1.1.5.1.3"><p id="p163645519225"><a name="p163645519225"></a><a name="p163645519225"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.45%" id="mcps1.1.5.1.4"><p id="p936485115225"><a name="p936485115225"></a><a name="p936485115225"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row209011858141413"><td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.5.1.1 "><p id="p8364135192215"><a name="p8364135192215"></a><a name="p8364135192215"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.269999999999996%" headers="mcps1.1.5.1.2 "><p id="p1436475152219"><a name="p1436475152219"></a><a name="p1436475152219"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="5.96%" headers="mcps1.1.5.1.3 "><p id="p4364185117225"><a name="p4364185117225"></a><a name="p4364185117225"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.45%" headers="mcps1.1.5.1.4 "><p id="p636585110221"><a name="p636585110221"></a><a name="p636585110221"></a>Type of the sensor to subscribe to, which is <strong id="b15761243161714"><a name="b15761243161714"></a><a name="b15761243161714"></a>SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED</strong>.</p>
    </td>
    </tr>
    <tr id="row6902145815141"><td class="cellrowborder" valign="top" width="8.32%" headers="mcps1.1.5.1.1 "><p id="p4365145117229"><a name="p4365145117229"></a><a name="p4365145117229"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.269999999999996%" headers="mcps1.1.5.1.2 "><p id="p836512517227"><a name="p836512517227"></a><a name="p836512517227"></a>AsyncCallback&lt;<a href="#section253082316457">AccelerometerUncalibratedResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.96%" headers="mcps1.1.5.1.3 "><p id="p8365125192215"><a name="p8365125192215"></a><a name="p8365125192215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.45%" headers="mcps1.1.5.1.4 "><p id="p13658518220"><a name="p13658518220"></a><a name="p13658518220"></a>One-shot callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is <strong id="b11987145561817"><a name="b11987145561817"></a><a name="b11987145561817"></a>AccelerometerUncalibratedResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        // Print the x-, y-, and z-coordinate biases.
        console.info('X-coordinate bias: ' + data.biasX);
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_GRAVITY\)<a name="section79121058181416"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_GRAVITY, callback: AsyncCallback<GravityResponse\>\): void

Subscribes to only one gravity sensor data change.

-   Parameters

    <a name="table1337175182211"></a>
    <table><thead align="left"><tr id="row11915105815143"><th class="cellrowborder" valign="top" width="10.38%" id="mcps1.1.5.1.1"><p id="p837335118228"><a name="p837335118228"></a><a name="p837335118228"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="31.619999999999997%" id="mcps1.1.5.1.2"><p id="p1137315112220"><a name="p1137315112220"></a><a name="p1137315112220"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.16%" id="mcps1.1.5.1.3"><p id="p337335192214"><a name="p337335192214"></a><a name="p337335192214"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="50.839999999999996%" id="mcps1.1.5.1.4"><p id="p3373351122210"><a name="p3373351122210"></a><a name="p3373351122210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3917135881411"><td class="cellrowborder" valign="top" width="10.38%" headers="mcps1.1.5.1.1 "><p id="p153731651102213"><a name="p153731651102213"></a><a name="p153731651102213"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.619999999999997%" headers="mcps1.1.5.1.2 "><p id="p10374051112213"><a name="p10374051112213"></a><a name="p10374051112213"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.16%" headers="mcps1.1.5.1.3 "><p id="p5374951172210"><a name="p5374951172210"></a><a name="p5374951172210"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p1537455162216"><a name="p1537455162216"></a><a name="p1537455162216"></a>Type of the sensor to subscribe to, which is <strong id="b7412350187"><a name="b7412350187"></a><a name="b7412350187"></a>SENSOR_TYPE_ID_GRAVITY</strong>.</p>
    </td>
    </tr>
    <tr id="row1291835816148"><td class="cellrowborder" valign="top" width="10.38%" headers="mcps1.1.5.1.1 "><p id="p173749514226"><a name="p173749514226"></a><a name="p173749514226"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="31.619999999999997%" headers="mcps1.1.5.1.2 "><p id="p6374151122213"><a name="p6374151122213"></a><a name="p6374151122213"></a>AsyncCallback&lt;<a href="#section162913399453">GravityResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.16%" headers="mcps1.1.5.1.3 "><p id="p837515182216"><a name="p837515182216"></a><a name="p837515182216"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="50.839999999999996%" headers="mcps1.1.5.1.4 "><p id="p1037585172217"><a name="p1037585172217"></a><a name="p1037585172217"></a>One-shot callback used to return the gravity sensor data. The reported data type in the callback is <strong id="b1842855914187"><a name="b1842855914187"></a><a name="b1842855914187"></a>GravityResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_GRAVITY, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\)<a name="section12419351519"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE, callback: AsyncCallback<GyroscopeResponse\>\): void

Subscribes to only one gyroscope sensor data change.

-   Parameters

    <a name="table338175142219"></a>
    <table><thead align="left"><tr id="row18953161510"><th class="cellrowborder" valign="top" width="10.12%" id="mcps1.1.5.1.1"><p id="p03812517225"><a name="p03812517225"></a><a name="p03812517225"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.95%" id="mcps1.1.5.1.2"><p id="p173821251162213"><a name="p173821251162213"></a><a name="p173821251162213"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.64%" id="mcps1.1.5.1.3"><p id="p2382145162220"><a name="p2382145162220"></a><a name="p2382145162220"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.29%" id="mcps1.1.5.1.4"><p id="p153822051112215"><a name="p153822051112215"></a><a name="p153822051112215"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row111083201510"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p438285122216"><a name="p438285122216"></a><a name="p438285122216"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.95%" headers="mcps1.1.5.1.2 "><p id="p1738215118225"><a name="p1738215118225"></a><a name="p1738215118225"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.64%" headers="mcps1.1.5.1.3 "><p id="p17382951122218"><a name="p17382951122218"></a><a name="p17382951122218"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.29%" headers="mcps1.1.5.1.4 "><p id="p163831451102219"><a name="p163831451102219"></a><a name="p163831451102219"></a>Type of the sensor to subscribe to, which is <strong id="b45907482113"><a name="b45907482113"></a><a name="b45907482113"></a>SENSOR_TYPE_ID_GYROSCOPE</strong>.</p>
    </td>
    </tr>
    <tr id="row6111530152"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p1338313516222"><a name="p1338313516222"></a><a name="p1338313516222"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.95%" headers="mcps1.1.5.1.2 "><p id="p2038335112219"><a name="p2038335112219"></a><a name="p2038335112219"></a>AsyncCallback&lt;<a href="#section3669131713463">GyroscopeResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.64%" headers="mcps1.1.5.1.3 "><p id="p63831651182210"><a name="p63831651182210"></a><a name="p63831651182210"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.29%" headers="mcps1.1.5.1.4 "><p id="p1738315116229"><a name="p1738315116229"></a><a name="p1738315116229"></a>One-shot callback used to return the gyroscope sensor data. The reported data type in the callback is <strong id="b1273612391913"><a name="b1273612391913"></a><a name="b1273612391913"></a>GyroscopeResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_GYROSCOPE, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\_UNCALIBRATED\)<a name="section02033181520"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_GYROSCOPE\_UNCALIBRATED,callback:AsyncCallback<GyroscopeUncalibratedResponse\>\): void

Subscribes to only one data change of the uncalibrated gyroscope sensor.

-   Parameters

    <a name="table4389195162219"></a>
    <table><thead align="left"><tr id="row423173121510"><th class="cellrowborder" valign="top" width="9.76%" id="mcps1.1.5.1.1"><p id="p139065118223"><a name="p139065118223"></a><a name="p139065118223"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.05%" id="mcps1.1.5.1.2"><p id="p17390451182219"><a name="p17390451182219"></a><a name="p17390451182219"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.829999999999999%" id="mcps1.1.5.1.3"><p id="p16390105112215"><a name="p16390105112215"></a><a name="p16390105112215"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.36%" id="mcps1.1.5.1.4"><p id="p639015132217"><a name="p639015132217"></a><a name="p639015132217"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17255320151"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p239117516220"><a name="p239117516220"></a><a name="p239117516220"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.05%" headers="mcps1.1.5.1.2 "><p id="p8391165118223"><a name="p8391165118223"></a><a name="p8391165118223"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.829999999999999%" headers="mcps1.1.5.1.3 "><p id="p83911151102216"><a name="p83911151102216"></a><a name="p83911151102216"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.36%" headers="mcps1.1.5.1.4 "><p id="p1339195112210"><a name="p1339195112210"></a><a name="p1339195112210"></a>Type of the sensor to subscribe to, which is <strong id="b17115162413214"><a name="b17115162413214"></a><a name="b17115162413214"></a>SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED</strong>.</p>
    </td>
    </tr>
    <tr id="row18271934152"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p6391175152215"><a name="p6391175152215"></a><a name="p6391175152215"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.05%" headers="mcps1.1.5.1.2 "><p id="p139217512226"><a name="p139217512226"></a><a name="p139217512226"></a>AsyncCallback&lt;<a href="#section1041541413475">GyroscopeUncalibratedResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.829999999999999%" headers="mcps1.1.5.1.3 "><p id="p239217510223"><a name="p239217510223"></a><a name="p239217510223"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.36%" headers="mcps1.1.5.1.4 "><p id="p16392851172219"><a name="p16392851172219"></a><a name="p16392851172219"></a>One-shot callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is <strong id="b1624011413197"><a name="b1624011413197"></a><a name="b1624011413197"></a>GyroscopeUncalibratedResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        // Print the x-, y-, and z-coordinate biases.
        console.info('X-coordinate bias: ' + data.biasX);
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_SIGNIFICANT\_MOTION\)<a name="section046513810156"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_SIGNIFICANT\_MOTION,callback:AsyncCallback<SignificantMotionResponse\>\): void

Subscribes to only one data change of the significant motion sensor.

-   Parameters

    <a name="table16398175182214"></a>
    <table><thead align="left"><tr id="row1746678151511"><th class="cellrowborder" valign="top" width="9.13%" id="mcps1.1.5.1.1"><p id="p17399351112215"><a name="p17399351112215"></a><a name="p17399351112215"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.72%" id="mcps1.1.5.1.2"><p id="p1440065120221"><a name="p1440065120221"></a><a name="p1440065120221"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5600000000000005%" id="mcps1.1.5.1.3"><p id="p94001651142217"><a name="p94001651142217"></a><a name="p94001651142217"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="44.59%" id="mcps1.1.5.1.4"><p id="p16400175152210"><a name="p16400175152210"></a><a name="p16400175152210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row646858191518"><td class="cellrowborder" valign="top" width="9.13%" headers="mcps1.1.5.1.1 "><p id="p20400105192216"><a name="p20400105192216"></a><a name="p20400105192216"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.72%" headers="mcps1.1.5.1.2 "><p id="p7400351172214"><a name="p7400351172214"></a><a name="p7400351172214"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5600000000000005%" headers="mcps1.1.5.1.3 "><p id="p240125112219"><a name="p240125112219"></a><a name="p240125112219"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.59%" headers="mcps1.1.5.1.4 "><p id="p15401115142210"><a name="p15401115142210"></a><a name="p15401115142210"></a>Type of the sensor to subscribe to, which is <strong id="b9351946172111"><a name="b9351946172111"></a><a name="b9351946172111"></a>SENSOR_TYPE_ID_SIGNIFICANT_MOTION</strong>.</p>
    </td>
    </tr>
    <tr id="row11470168111516"><td class="cellrowborder" valign="top" width="9.13%" headers="mcps1.1.5.1.1 "><p id="p740165119222"><a name="p740165119222"></a><a name="p740165119222"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.72%" headers="mcps1.1.5.1.2 "><p id="p15401185116222"><a name="p15401185116222"></a><a name="p15401185116222"></a>AsyncCallback&lt;<a href="#section1213143164712">SignificantMotionResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5600000000000005%" headers="mcps1.1.5.1.3 "><p id="p7401115172211"><a name="p7401115172211"></a><a name="p7401115172211"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.59%" headers="mcps1.1.5.1.4 "><p id="p19402175111224"><a name="p19402175111224"></a><a name="p19402175111224"></a>One-shot callback used to return the significant motion sensor data. The reported data type in the callback is <strong id="b1314201791919"><a name="b1314201791919"></a><a name="b1314201791919"></a>SignificantMotionResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        console.info('Scalar data: ' + data.scalar);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\_DETECTION\)<a name="section84801280158"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\_DETECTION,callback:AsyncCallback<PedometerDetectResponse\>\): void

Subscribes to only one data change of the pedometer detection sensor.

-   Parameters

    <a name="table5406105118224"></a>
    <table><thead align="left"><tr id="row44828820158"><th class="cellrowborder" valign="top" width="8.95%" id="mcps1.1.5.1.1"><p id="p1540775132211"><a name="p1540775132211"></a><a name="p1540775132211"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.1%" id="mcps1.1.5.1.2"><p id="p1240825119225"><a name="p1240825119225"></a><a name="p1240825119225"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.539999999999999%" id="mcps1.1.5.1.3"><p id="p15408205142212"><a name="p15408205142212"></a><a name="p15408205142212"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="43.41%" id="mcps1.1.5.1.4"><p id="p144081451182217"><a name="p144081451182217"></a><a name="p144081451182217"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1048414881516"><td class="cellrowborder" valign="top" width="8.95%" headers="mcps1.1.5.1.1 "><p id="p164081651142214"><a name="p164081651142214"></a><a name="p164081651142214"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.1%" headers="mcps1.1.5.1.2 "><p id="p1940825122213"><a name="p1940825122213"></a><a name="p1940825122213"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.539999999999999%" headers="mcps1.1.5.1.3 "><p id="p16408155117226"><a name="p16408155117226"></a><a name="p16408155117226"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.41%" headers="mcps1.1.5.1.4 "><p id="p11409105182214"><a name="p11409105182214"></a><a name="p11409105182214"></a>Type of the sensor to subscribe to, which is <strong id="b161121410112210"><a name="b161121410112210"></a><a name="b161121410112210"></a>SENSOR_TYPE_ID_PEDOMETER_DETECTION</strong>.</p>
    </td>
    </tr>
    <tr id="row8485118111514"><td class="cellrowborder" valign="top" width="8.95%" headers="mcps1.1.5.1.1 "><p id="p164099512228"><a name="p164099512228"></a><a name="p164099512228"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.1%" headers="mcps1.1.5.1.2 "><p id="p10409135142210"><a name="p10409135142210"></a><a name="p10409135142210"></a>AsyncCallback&lt;<a href="#section145653910491">PedometerDetectResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.539999999999999%" headers="mcps1.1.5.1.3 "><p id="p10409125116220"><a name="p10409125116220"></a><a name="p10409125116220"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.41%" headers="mcps1.1.5.1.4 "><p id="p1840915516226"><a name="p1840915516226"></a><a name="p1840915516226"></a>One-shot callback used to return the pedometer detection sensor data. The reported data type in the callback is <strong id="b85082015195"><a name="b85082015195"></a><a name="b85082015195"></a>PedometerDetectResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        console.info('Scalar data: ' + data.scalar);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_PEDOMETER\)<a name="section7781212101520"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_PEDOMETER, callback: AsyncCallback<PedometerResponse\>\): void

Subscribes to only one pedometer sensor data change.

-   Parameters

    <a name="table34151851122217"></a>
    <table><thead align="left"><tr id="row180412191515"><th class="cellrowborder" valign="top" width="11.1%" id="mcps1.1.5.1.1"><p id="p3417451102210"><a name="p3417451102210"></a><a name="p3417451102210"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.06%" id="mcps1.1.5.1.2"><p id="p5417105122218"><a name="p5417105122218"></a><a name="p5417105122218"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.22%" id="mcps1.1.5.1.3"><p id="p74173511225"><a name="p74173511225"></a><a name="p74173511225"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.620000000000005%" id="mcps1.1.5.1.4"><p id="p8417751102213"><a name="p8417751102213"></a><a name="p8417751102213"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row682111271512"><td class="cellrowborder" valign="top" width="11.1%" headers="mcps1.1.5.1.1 "><p id="p1041855192218"><a name="p1041855192218"></a><a name="p1041855192218"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.06%" headers="mcps1.1.5.1.2 "><p id="p1418165182213"><a name="p1418165182213"></a><a name="p1418165182213"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.1.5.1.3 "><p id="p1341811515227"><a name="p1341811515227"></a><a name="p1341811515227"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.620000000000005%" headers="mcps1.1.5.1.4 "><p id="p15418251162220"><a name="p15418251162220"></a><a name="p15418251162220"></a>Type of the sensor to subscribe to, which is <strong id="b2089311715239"><a name="b2089311715239"></a><a name="b2089311715239"></a>SENSOR_TYPE_ID_PEDOMETER</strong>.</p>
    </td>
    </tr>
    <tr id="row148631212155"><td class="cellrowborder" valign="top" width="11.1%" headers="mcps1.1.5.1.1 "><p id="p641825111225"><a name="p641825111225"></a><a name="p641825111225"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.06%" headers="mcps1.1.5.1.2 "><p id="p5419551162213"><a name="p5419551162213"></a><a name="p5419551162213"></a>AsyncCallback&lt;<a href="#section1350145915489">PedometerResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.1.5.1.3 "><p id="p1141914511225"><a name="p1141914511225"></a><a name="p1141914511225"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.620000000000005%" headers="mcps1.1.5.1.4 "><p id="p1841945118225"><a name="p1841945118225"></a><a name="p1841945118225"></a>One-shot callback used to return the pedometer sensor data. The reported data type in the callback is <strong id="b15810427121917"><a name="b15810427121917"></a><a name="b15810427121917"></a>PedometerResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_PEDOMETER, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the number of steps.
        console.info('Steps: ' + data.steps);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_TEMPERATURE\)<a name="section1595121217155"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_TEMPERATURE,callback:AsyncCallback<AmbientTemperatureResponse\>\): void

Subscribes to only one data change of the ambient temperature sensor.

-   Parameters

    <a name="table164253515228"></a>
    <table><thead align="left"><tr id="row2992122157"><th class="cellrowborder" valign="top" width="9.31%" id="mcps1.1.5.1.1"><p id="p84261151192213"><a name="p84261151192213"></a><a name="p84261151192213"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.75%" id="mcps1.1.5.1.2"><p id="p104261051192213"><a name="p104261051192213"></a><a name="p104261051192213"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.920000000000001%" id="mcps1.1.5.1.3"><p id="p15426135111227"><a name="p15426135111227"></a><a name="p15426135111227"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="44.019999999999996%" id="mcps1.1.5.1.4"><p id="p242615152218"><a name="p242615152218"></a><a name="p242615152218"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row310021291512"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p16427125192210"><a name="p16427125192210"></a><a name="p16427125192210"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.75%" headers="mcps1.1.5.1.2 "><p id="p1542725192216"><a name="p1542725192216"></a><a name="p1542725192216"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.5.1.3 "><p id="p124271851122210"><a name="p124271851122210"></a><a name="p124271851122210"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p742725132217"><a name="p742725132217"></a><a name="p742725132217"></a>Type of the sensor to subscribe to, which is <strong id="b547764211237"><a name="b547764211237"></a><a name="b547764211237"></a>SENSOR_TYPE_ID_AMBIENT_TEMPERATURE</strong>.</p>
    </td>
    </tr>
    <tr id="row18102161212152"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p144279516224"><a name="p144279516224"></a><a name="p144279516224"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.75%" headers="mcps1.1.5.1.2 "><p id="p1442713515227"><a name="p1442713515227"></a><a name="p1442713515227"></a>AsyncCallback&lt;<a href="#section728281924920">AmbientTemperatureResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.5.1.3 "><p id="p9428155110229"><a name="p9428155110229"></a><a name="p9428155110229"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p94286519221"><a name="p94286519221"></a><a name="p94286519221"></a>One-shot callback used to return the ambient temperature sensor data. The reported data type in the callback is <strong id="b111128317194"><a name="b111128317194"></a><a name="b111128317194"></a>AmbientTemperatureResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the temperature data.
        console.info('Temperature: ' + data.temperature);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\)<a name="section20209715181517"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD, callback: AsyncCallback<MagneticFieldResponse\>\): void

Subscribes to only one data change of the magnetic field sensor.

-   Parameters

    <a name="table114330512220"></a>
    <table><thead align="left"><tr id="row202101615151512"><th class="cellrowborder" valign="top" width="9.49%" id="mcps1.1.5.1.1"><p id="p643465113221"><a name="p643465113221"></a><a name="p643465113221"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.300000000000004%" id="mcps1.1.5.1.2"><p id="p2434195115226"><a name="p2434195115226"></a><a name="p2434195115226"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.430000000000001%" id="mcps1.1.5.1.3"><p id="p8434175112224"><a name="p8434175112224"></a><a name="p8434175112224"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.78%" id="mcps1.1.5.1.4"><p id="p194351651122214"><a name="p194351651122214"></a><a name="p194351651122214"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1221221511513"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="p144351251152219"><a name="p144351251152219"></a><a name="p144351251152219"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.1.5.1.2 "><p id="p3435165192214"><a name="p3435165192214"></a><a name="p3435165192214"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.430000000000001%" headers="mcps1.1.5.1.3 "><p id="p114351651122214"><a name="p114351651122214"></a><a name="p114351651122214"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.78%" headers="mcps1.1.5.1.4 "><p id="p194351251132217"><a name="p194351251132217"></a><a name="p194351251132217"></a>Type of the sensor to subscribe to, which is <strong id="b1454513412265"><a name="b1454513412265"></a><a name="b1454513412265"></a>SENSOR_TYPE_ID_MAGNETIC_FIELD</strong>.</p>
    </td>
    </tr>
    <tr id="row162133158154"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="p1943545118220"><a name="p1943545118220"></a><a name="p1943545118220"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.1.5.1.2 "><p id="p11436125116224"><a name="p11436125116224"></a><a name="p11436125116224"></a>AsyncCallback&lt;<a href="#section20218191813489">MagneticFieldResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.430000000000001%" headers="mcps1.1.5.1.3 "><p id="p1643610514224"><a name="p1643610514224"></a><a name="p1643610514224"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.78%" headers="mcps1.1.5.1.4 "><p id="p18436155152213"><a name="p18436155152213"></a><a name="p18436155152213"></a>One-shot callback used to return the magnetic field sensor data. The reported data type in the callback is <strong id="b113760348194"><a name="b113760348194"></a><a name="b113760348194"></a>MagneticFieldResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\_UNCALIBRATED\)<a name="section42211015191510"></a>

once\(type:SensorType.SENSOR\_TYPE\_ID\_MAGNETIC\_FIELD\_UNCALIBRATED,callback:AsyncCallback<MagneticFieldUncalibratedResponse\>\): void

Subscribes to only one data change of the uncalibrated magnetic field sensor.

-   Parameters

    <a name="table244185114226"></a>
    <table><thead align="left"><tr id="row322201561511"><th class="cellrowborder" valign="top" width="9.76%" id="mcps1.1.5.1.1"><p id="p444215122212"><a name="p444215122212"></a><a name="p444215122212"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.01%" id="mcps1.1.5.1.2"><p id="p544235110222"><a name="p544235110222"></a><a name="p544235110222"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.950000000000001%" id="mcps1.1.5.1.3"><p id="p9443115102212"><a name="p9443115102212"></a><a name="p9443115102212"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.28%" id="mcps1.1.5.1.4"><p id="p1344325132214"><a name="p1344325132214"></a><a name="p1344325132214"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13224215121515"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p2044345114226"><a name="p2044345114226"></a><a name="p2044345114226"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.01%" headers="mcps1.1.5.1.2 "><p id="p154433518224"><a name="p154433518224"></a><a name="p154433518224"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.5.1.3 "><p id="p19443451142220"><a name="p19443451142220"></a><a name="p19443451142220"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.28%" headers="mcps1.1.5.1.4 "><p id="p164441451112215"><a name="p164441451112215"></a><a name="p164441451112215"></a>Type of the sensor to subscribe to, which is <strong id="b2095416534262"><a name="b2095416534262"></a><a name="b2095416534262"></a>SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED</strong>.</p>
    </td>
    </tr>
    <tr id="row2226815181517"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p1044425152216"><a name="p1044425152216"></a><a name="p1044425152216"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.01%" headers="mcps1.1.5.1.2 "><p id="p1444495152218"><a name="p1444495152218"></a><a name="p1444495152218"></a>AsyncCallback&lt;<a href="#section13749143113486">MagneticFieldUncalibratedResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.950000000000001%" headers="mcps1.1.5.1.3 "><p id="p9444175114227"><a name="p9444175114227"></a><a name="p9444175114227"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.28%" headers="mcps1.1.5.1.4 "><p id="p744425112219"><a name="p744425112219"></a><a name="p744425112219"></a>One-shot callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is <strong id="b223818371193"><a name="b223818371193"></a><a name="b223818371193"></a>MagneticFieldUncalibratedResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        // Print the x-, y-, and z-coordinate biases.
        console.info('X-coordinate bias: ' + data.biasX);
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_PROXIMITY\)<a name="section569171821513"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_PROXIMITY, callback: AsyncCallback<ProximityResponse\>\): void

Subscribes to only one proximity sensor data change.

-   Parameters

    <a name="table8451155192213"></a>
    <table><thead align="left"><tr id="row4721518121519"><th class="cellrowborder" valign="top" width="10.12%" id="mcps1.1.5.1.1"><p id="p154521451102217"><a name="p154521451102217"></a><a name="p154521451102217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.57%" id="mcps1.1.5.1.2"><p id="p8452145132212"><a name="p8452145132212"></a><a name="p8452145132212"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.2%" id="mcps1.1.5.1.3"><p id="p3452165110223"><a name="p3452165110223"></a><a name="p3452165110223"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.11%" id="mcps1.1.5.1.4"><p id="p1145385142215"><a name="p1145385142215"></a><a name="p1145385142215"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row157321861517"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p104531351142216"><a name="p104531351142216"></a><a name="p104531351142216"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.57%" headers="mcps1.1.5.1.2 "><p id="p8453115111226"><a name="p8453115111226"></a><a name="p8453115111226"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.2%" headers="mcps1.1.5.1.3 "><p id="p545316513221"><a name="p545316513221"></a><a name="p545316513221"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.11%" headers="mcps1.1.5.1.4 "><p id="p5453145122213"><a name="p5453145122213"></a><a name="p5453145122213"></a>Type of the sensor to subscribe to, which is <strong id="b12562112022712"><a name="b12562112022712"></a><a name="b12562112022712"></a>SENSOR_TYPE_ID_PROXIMITY</strong>.</p>
    </td>
    </tr>
    <tr id="row1075201817152"><td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.1 "><p id="p645355116222"><a name="p645355116222"></a><a name="p645355116222"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.57%" headers="mcps1.1.5.1.2 "><p id="p745425114222"><a name="p745425114222"></a><a name="p745425114222"></a>AsyncCallback&lt;<a href="#section5275184313476">ProximityResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.2%" headers="mcps1.1.5.1.3 "><p id="p1345410511225"><a name="p1345410511225"></a><a name="p1345410511225"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.11%" headers="mcps1.1.5.1.4 "><p id="p134549512227"><a name="p134549512227"></a><a name="p134549512227"></a>One-shot callback used to return the proximity sensor data. The reported data type in the callback is <strong id="b15527164012192"><a name="b15527164012192"></a><a name="b15527164012192"></a>ProximityResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_PROXIMITY, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the proximity.
        console.info('Distance: ' + data.distance);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_HUMIDITY\)<a name="section481181811512"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_HUMIDITY, callback: AsyncCallback<HumidityResponse\>\): void

Subscribes to only one humidity sensor data change.

-   Parameters

    <a name="table4459175112213"></a>
    <table><thead align="left"><tr id="row3841318121515"><th class="cellrowborder" valign="top" width="9.030000000000001%" id="mcps1.1.5.1.1"><p id="p546017515228"><a name="p546017515228"></a><a name="p546017515228"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.86%" id="mcps1.1.5.1.2"><p id="p1446025182211"><a name="p1446025182211"></a><a name="p1446025182211"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.79%" id="mcps1.1.5.1.3"><p id="p3460135111221"><a name="p3460135111221"></a><a name="p3460135111221"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.32%" id="mcps1.1.5.1.4"><p id="p144611251122218"><a name="p144611251122218"></a><a name="p144611251122218"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19851618141517"><td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.5.1.1 "><p id="p04611951122218"><a name="p04611951122218"></a><a name="p04611951122218"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.86%" headers="mcps1.1.5.1.2 "><p id="p346155152217"><a name="p346155152217"></a><a name="p346155152217"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.79%" headers="mcps1.1.5.1.3 "><p id="p18461951122218"><a name="p18461951122218"></a><a name="p18461951122218"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.32%" headers="mcps1.1.5.1.4 "><p id="p0461195132215"><a name="p0461195132215"></a><a name="p0461195132215"></a>Type of the sensor to subscribe to, which is <strong id="b18758956182710"><a name="b18758956182710"></a><a name="b18758956182710"></a>SENSOR_TYPE_ID_HUMIDITY</strong>.</p>
    </td>
    </tr>
    <tr id="row887918111515"><td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.5.1.1 "><p id="p24618518224"><a name="p24618518224"></a><a name="p24618518224"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.86%" headers="mcps1.1.5.1.2 "><p id="p13462135152219"><a name="p13462135152219"></a><a name="p13462135152219"></a>AsyncCallback&lt;<a href="#section20444511666">HumidityResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.79%" headers="mcps1.1.5.1.3 "><p id="p11462051172217"><a name="p11462051172217"></a><a name="p11462051172217"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.32%" headers="mcps1.1.5.1.4 "><p id="p146285115227"><a name="p146285115227"></a><a name="p146285115227"></a>One-shot callback used to return the humidity sensor data. The reported data type in the callback is <strong id="b12414134311912"><a name="b12414134311912"></a><a name="b12414134311912"></a>HumidityResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_HUMIDITY, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the humidity.
        console.info('Humidity: ' + data.humidity);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_BAROMETER\)<a name="section178111120201520"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_BAROMETER, callback: AsyncCallback<BarometerResponse\>\): void

Subscribes to only one barometer sensor data change.

-   Parameters

    <a name="table1947114517229"></a>
    <table><thead align="left"><tr id="row6813132091516"><th class="cellrowborder" valign="top" width="9.76%" id="mcps1.1.5.1.1"><p id="p6472051112217"><a name="p6472051112217"></a><a name="p6472051112217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.13%" id="mcps1.1.5.1.2"><p id="p44721151122210"><a name="p44721151122210"></a><a name="p44721151122210"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.07%" id="mcps1.1.5.1.3"><p id="p84721551192214"><a name="p84721551192214"></a><a name="p84721551192214"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.04%" id="mcps1.1.5.1.4"><p id="p1647220517223"><a name="p1647220517223"></a><a name="p1647220517223"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17817172013154"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p24729519226"><a name="p24729519226"></a><a name="p24729519226"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.13%" headers="mcps1.1.5.1.2 "><p id="p17472651122212"><a name="p17472651122212"></a><a name="p17472651122212"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="p94735511228"><a name="p94735511228"></a><a name="p94735511228"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.04%" headers="mcps1.1.5.1.4 "><p id="p1247335113220"><a name="p1247335113220"></a><a name="p1247335113220"></a>Type of the sensor to subscribe to, which is <strong id="b18757153042812"><a name="b18757153042812"></a><a name="b18757153042812"></a>SENSOR_TYPE_ID_BAROMETER</strong>.</p>
    </td>
    </tr>
    <tr id="row281811206158"><td class="cellrowborder" valign="top" width="9.76%" headers="mcps1.1.5.1.1 "><p id="p1747316518226"><a name="p1747316518226"></a><a name="p1747316518226"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.13%" headers="mcps1.1.5.1.2 "><p id="p5473351162210"><a name="p5473351162210"></a><a name="p5473351162210"></a>AsyncCallback&lt;<a href="#section143457303496">BarometerResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.07%" headers="mcps1.1.5.1.3 "><p id="p747395112228"><a name="p747395112228"></a><a name="p747395112228"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.04%" headers="mcps1.1.5.1.4 "><p id="p547435114223"><a name="p547435114223"></a><a name="p547435114223"></a>One-shot callback used to return the barometer sensor data. The reported data type in the callback is <strong id="b127361946171916"><a name="b127361946171916"></a><a name="b127361946171916"></a>BarometerResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_BAROMETER, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the atmospheric pressure.
        console.info('Atmospheric pressure: ' + data.pressure);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_HALL\)<a name="section6826920141517"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_HALL, callback:   AsyncCallback<HallResponse\>\): void

Subscribes to only one data change of the Hall effect sensor.

-   Parameters

    <a name="table947811511222"></a>
    <table><thead align="left"><tr id="row1482812051514"><th class="cellrowborder" valign="top" width="9.49%" id="mcps1.1.5.1.1"><p id="p154791951102210"><a name="p154791951102210"></a><a name="p154791951102210"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.15%" id="mcps1.1.5.1.2"><p id="p12480105117227"><a name="p12480105117227"></a><a name="p12480105117227"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.340000000000001%" id="mcps1.1.5.1.3"><p id="p1148055192215"><a name="p1148055192215"></a><a name="p1148055192215"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.019999999999996%" id="mcps1.1.5.1.4"><p id="p154801751172216"><a name="p154801751172216"></a><a name="p154801751172216"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row382912021511"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="p648010512223"><a name="p648010512223"></a><a name="p648010512223"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.15%" headers="mcps1.1.5.1.2 "><p id="p3480195182215"><a name="p3480195182215"></a><a name="p3480195182215"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.340000000000001%" headers="mcps1.1.5.1.3 "><p id="p5481155192219"><a name="p5481155192219"></a><a name="p5481155192219"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p648117510220"><a name="p648117510220"></a><a name="p648117510220"></a>Type of the sensor to subscribe to, which is <strong id="b20857193010323"><a name="b20857193010323"></a><a name="b20857193010323"></a>SENSOR_TYPE_ID_HALL</strong>.</p>
    </td>
    </tr>
    <tr id="row183172019157"><td class="cellrowborder" valign="top" width="9.49%" headers="mcps1.1.5.1.1 "><p id="p54811351102212"><a name="p54811351102212"></a><a name="p54811351102212"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.15%" headers="mcps1.1.5.1.2 "><p id="p948195182215"><a name="p948195182215"></a><a name="p948195182215"></a>AsyncCallback&lt;<a href="#section18608467487">HallResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.340000000000001%" headers="mcps1.1.5.1.3 "><p id="p9481251102219"><a name="p9481251102219"></a><a name="p9481251102219"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p848214515226"><a name="p848214515226"></a><a name="p848214515226"></a>One-shot callback used to return the Hall effect sensor data. The reported data type in the callback is <strong id="b18289104921912"><a name="b18289104921912"></a><a name="b18289104921912"></a>HallResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_HALL, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the status.
        console.info('Status: ' + data.status);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_LIGHT\)<a name="section449943418257"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_AMBIENT\_LIGHT, callback: AsyncCallback<LightResponse\>\): void

Subscribes to only one data change of the ambient light sensor.

-   Parameters

    <a name="table1348735118229"></a>
    <table><thead align="left"><tr id="row55011034132510"><th class="cellrowborder" valign="top" width="9.39%" id="mcps1.1.5.1.1"><p id="p6487451192212"><a name="p6487451192212"></a><a name="p6487451192212"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.449999999999996%" id="mcps1.1.5.1.2"><p id="p7488175111227"><a name="p7488175111227"></a><a name="p7488175111227"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.64%" id="mcps1.1.5.1.3"><p id="p104881151192216"><a name="p104881151192216"></a><a name="p104881151192216"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="47.52%" id="mcps1.1.5.1.4"><p id="p64883518229"><a name="p64883518229"></a><a name="p64883518229"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15505234122513"><td class="cellrowborder" valign="top" width="9.39%" headers="mcps1.1.5.1.1 "><p id="p164881851192214"><a name="p164881851192214"></a><a name="p164881851192214"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.449999999999996%" headers="mcps1.1.5.1.2 "><p id="p144881151122217"><a name="p144881151122217"></a><a name="p144881151122217"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.64%" headers="mcps1.1.5.1.3 "><p id="p17489155115223"><a name="p17489155115223"></a><a name="p17489155115223"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.52%" headers="mcps1.1.5.1.4 "><p id="p194896519229"><a name="p194896519229"></a><a name="p194896519229"></a>Type of the sensor to subscribe to, which is <strong id="b25044718337"><a name="b25044718337"></a><a name="b25044718337"></a>SENSOR_TYPE_ID_AMBIENT_LIGHT</strong>.</p>
    </td>
    </tr>
    <tr id="row150719349254"><td class="cellrowborder" valign="top" width="9.39%" headers="mcps1.1.5.1.1 "><p id="p16489551122214"><a name="p16489551122214"></a><a name="p16489551122214"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.449999999999996%" headers="mcps1.1.5.1.2 "><p id="p174891151112216"><a name="p174891151112216"></a><a name="p174891151112216"></a>AsyncCallback&lt;<a href="#section195685404716">LightResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.64%" headers="mcps1.1.5.1.3 "><p id="p04908513221"><a name="p04908513221"></a><a name="p04908513221"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="47.52%" headers="mcps1.1.5.1.4 "><p id="p4490205162216"><a name="p4490205162216"></a><a name="p4490205162216"></a>One-shot callback used to return the ambient light sensor data. The reported data type in the callback is <strong id="b1272912516195"><a name="b1272912516195"></a><a name="b1272912516195"></a>LightResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the illumination.
        console.info('Illumination: ' + data.intensity);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_ORIENTATION\)<a name="section438833732512"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_ORIENTATION, callback: AsyncCallback<OrientationResponse\>\): void

Subscribes to only one orientation sensor data change.

-   Parameters

    <a name="table10495551162219"></a>
    <table><thead align="left"><tr id="row639073714252"><th class="cellrowborder" valign="top" width="9.94%" id="mcps1.1.5.1.1"><p id="p149615516226"><a name="p149615516226"></a><a name="p149615516226"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="34.300000000000004%" id="mcps1.1.5.1.2"><p id="p1849611511221"><a name="p1849611511221"></a><a name="p1849611511221"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.959999999999999%" id="mcps1.1.5.1.3"><p id="p1149615512226"><a name="p1149615512226"></a><a name="p1149615512226"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.800000000000004%" id="mcps1.1.5.1.4"><p id="p1549611518224"><a name="p1549611518224"></a><a name="p1549611518224"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row73921337152510"><td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.1 "><p id="p049720510228"><a name="p049720510228"></a><a name="p049720510228"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.1.5.1.2 "><p id="p149720513220"><a name="p149720513220"></a><a name="p149720513220"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.959999999999999%" headers="mcps1.1.5.1.3 "><p id="p13497175122215"><a name="p13497175122215"></a><a name="p13497175122215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.800000000000004%" headers="mcps1.1.5.1.4 "><p id="p249710515225"><a name="p249710515225"></a><a name="p249710515225"></a>Type of the sensor to subscribe to, which is <strong id="b10126339193320"><a name="b10126339193320"></a><a name="b10126339193320"></a>SENSOR_TYPE_ID_ORIENTATION</strong>.</p>
    </td>
    </tr>
    <tr id="row1239583782511"><td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.1 "><p id="p16497851132213"><a name="p16497851132213"></a><a name="p16497851132213"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="34.300000000000004%" headers="mcps1.1.5.1.2 "><p id="p949845182216"><a name="p949845182216"></a><a name="p949845182216"></a>AsyncCallback&lt;<a href="#section128271514456">OrientationResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.959999999999999%" headers="mcps1.1.5.1.3 "><p id="p11498205112226"><a name="p11498205112226"></a><a name="p11498205112226"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.800000000000004%" headers="mcps1.1.5.1.4 "><p id="p849845122216"><a name="p849845122216"></a><a name="p849845122216"></a>One-shot callback used to return the orientation sensor data. The reported data type in the callback is <strong id="b5703554181912"><a name="b5703554181912"></a><a name="b5703554181912"></a>OrientationResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_ORIENTATION, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_ROTATION\_VECTOR\)<a name="section25391940192520"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_ROTATION\_VECTOR, callback: AsyncCallback<RotationVectorResponse\>\): void

Subscribes to only one rotation vector data change.

-   Parameters

    <a name="table8503145112226"></a>
    <table><thead align="left"><tr id="row195415403256"><th class="cellrowborder" valign="top" width="9.85%" id="mcps1.1.5.1.1"><p id="p15048515228"><a name="p15048515228"></a><a name="p15048515228"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.629999999999995%" id="mcps1.1.5.1.2"><p id="p4504195112215"><a name="p4504195112215"></a><a name="p4504195112215"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.85%" id="mcps1.1.5.1.3"><p id="p1504195112213"><a name="p1504195112213"></a><a name="p1504195112213"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="43.669999999999995%" id="mcps1.1.5.1.4"><p id="p450425152211"><a name="p450425152211"></a><a name="p450425152211"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1754310409250"><td class="cellrowborder" valign="top" width="9.85%" headers="mcps1.1.5.1.1 "><p id="p1150545132211"><a name="p1150545132211"></a><a name="p1150545132211"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.629999999999995%" headers="mcps1.1.5.1.2 "><p id="p14505851192212"><a name="p14505851192212"></a><a name="p14505851192212"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.5.1.3 "><p id="p750595182215"><a name="p750595182215"></a><a name="p750595182215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.669999999999995%" headers="mcps1.1.5.1.4 "><p id="p13505751122211"><a name="p13505751122211"></a><a name="p13505751122211"></a>Type of the sensor to subscribe to, which is <strong id="b10285364341"><a name="b10285364341"></a><a name="b10285364341"></a>SENSOR_TYPE_ID_ROTATION_VECTOR</strong>.</p>
    </td>
    </tr>
    <tr id="row9544140192515"><td class="cellrowborder" valign="top" width="9.85%" headers="mcps1.1.5.1.1 "><p id="p450518512222"><a name="p450518512222"></a><a name="p450518512222"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.629999999999995%" headers="mcps1.1.5.1.2 "><p id="p18505351122211"><a name="p18505351122211"></a><a name="p18505351122211"></a>AsyncCallback&lt;<a href="#section13776194114611">RotationVectorResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.5.1.3 "><p id="p1050675142215"><a name="p1050675142215"></a><a name="p1050675142215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="43.669999999999995%" headers="mcps1.1.5.1.4 "><p id="p10506451172218"><a name="p10506451172218"></a><a name="p10506451172218"></a>One-shot callback used to return the rotation vector sensor data. The reported data type in the callback is <strong id="b16171357201917"><a name="b16171357201917"></a><a name="b16171357201917"></a>RotationVectorResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the x-, y-, and z-coordinate components.
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_HEART\_RATE\)<a name="section1345034310258"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_HEART\_RATE, callback: AsyncCallback<HeartRateResponse\>\): void

Subscribes to only one data change of the heart rate sensor.

-   Parameters

    <a name="table45121751192216"></a>
    <table><thead align="left"><tr id="row10452043112519"><th class="cellrowborder" valign="top" width="9.31%" id="mcps1.1.5.1.1"><p id="p16512205152214"><a name="p16512205152214"></a><a name="p16512205152214"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.690000000000005%" id="mcps1.1.5.1.2"><p id="p9513115111221"><a name="p9513115111221"></a><a name="p9513115111221"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.51%" id="mcps1.1.5.1.3"><p id="p165131151152211"><a name="p165131151152211"></a><a name="p165131151152211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.49%" id="mcps1.1.5.1.4"><p id="p1151318510228"><a name="p1151318510228"></a><a name="p1151318510228"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row04566434251"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p3513195115226"><a name="p3513195115226"></a><a name="p3513195115226"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.690000000000005%" headers="mcps1.1.5.1.2 "><p id="p195132514220"><a name="p195132514220"></a><a name="p195132514220"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.51%" headers="mcps1.1.5.1.3 "><p id="p4513115182211"><a name="p4513115182211"></a><a name="p4513115182211"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.1.5.1.4 "><p id="p1851475162217"><a name="p1851475162217"></a><a name="p1851475162217"></a>Type of the sensor to subscribe to, which is <strong id="b79397384343"><a name="b79397384343"></a><a name="b79397384343"></a>SENSOR_TYPE_ID_HEART_RATE</strong>.</p>
    </td>
    </tr>
    <tr id="row144588439259"><td class="cellrowborder" valign="top" width="9.31%" headers="mcps1.1.5.1.1 "><p id="p451485112210"><a name="p451485112210"></a><a name="p451485112210"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.690000000000005%" headers="mcps1.1.5.1.2 "><p id="p14514115132210"><a name="p14514115132210"></a><a name="p14514115132210"></a>AsyncCallback&lt;<a href="#section95011341124915">HeartRateResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.51%" headers="mcps1.1.5.1.3 "><p id="p13514155112211"><a name="p13514155112211"></a><a name="p13514155112211"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.1.5.1.4 "><p id="p1251425182219"><a name="p1251425182219"></a><a name="p1251425182219"></a>One-shot callback used to return the heart rate sensor data. The reported data type in the callback is <strong id="b192431052015"><a name="b192431052015"></a><a name="b192431052015"></a>HeartRateResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_HEART_RATE, function(error, data) {
        if (error) {
            console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        // Print the heart rate.
        console.info("Heart rate: " + data.heartRate);
      }
    );
    ```


## sensor.once\(SensorType.SENSOR\_TYPE\_ID\_WEAR\_DETECTION\)<a name="section2288135016254"></a>

once\(type: SensorType.SENSOR\_TYPE\_ID\_WEAR\_DETECTION, callback: AsyncCallback<WearDetectionResponse\>\): void

Subscribes to only one data change of the wear detection sensor.

-   Parameters

    <a name="table1352017513223"></a>
    <table><thead align="left"><tr id="row1129075062513"><th class="cellrowborder" valign="top" width="9.13%" id="mcps1.1.5.1.1"><p id="p5521145142215"><a name="p5521145142215"></a><a name="p5521145142215"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.22%" id="mcps1.1.5.1.2"><p id="p552114512220"><a name="p552114512220"></a><a name="p552114512220"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.61%" id="mcps1.1.5.1.3"><p id="p1752125112219"><a name="p1752125112219"></a><a name="p1752125112219"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="44.04%" id="mcps1.1.5.1.4"><p id="p145211451162214"><a name="p145211451162214"></a><a name="p145211451162214"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11294125018256"><td class="cellrowborder" valign="top" width="9.13%" headers="mcps1.1.5.1.1 "><p id="p1952245102218"><a name="p1952245102218"></a><a name="p1952245102218"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.22%" headers="mcps1.1.5.1.2 "><p id="p0522851142210"><a name="p0522851142210"></a><a name="p0522851142210"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.5.1.3 "><p id="p19522751162210"><a name="p19522751162210"></a><a name="p19522751162210"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.04%" headers="mcps1.1.5.1.4 "><p id="p8522351182214"><a name="p8522351182214"></a><a name="p8522351182214"></a>Type of the sensor to subscribe to, which is <strong id="b1893183683515"><a name="b1893183683515"></a><a name="b1893183683515"></a>SENSOR_TYPE_ID_WEAR_DETECTION</strong>.</p>
    </td>
    </tr>
    <tr id="row729685092510"><td class="cellrowborder" valign="top" width="9.13%" headers="mcps1.1.5.1.1 "><p id="p752235119224"><a name="p752235119224"></a><a name="p752235119224"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.22%" headers="mcps1.1.5.1.2 "><p id="p2052275116226"><a name="p2052275116226"></a><a name="p2052275116226"></a>AsyncCallback&lt;<a href="#section128278501495">WearDetectionResponse</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.61%" headers="mcps1.1.5.1.3 "><p id="p3523451142214"><a name="p3523451142214"></a><a name="p3523451142214"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="44.04%" headers="mcps1.1.5.1.4 "><p id="p4523165182219"><a name="p4523165182219"></a><a name="p4523165182219"></a>One-shot callback used to return the wear detection sensor data. The reported data type in the callback is <strong id="b71861933200"><a name="b71861933200"></a><a name="b71861933200"></a>WearDetectionResponse</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.once(type:SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, function(error, data) {
        if (error) {
            console.error("Failed to register data, error code is" + error.code + ", message: " + error.message);
            return;
        }
        // Print the wear status.
        console.info("Wear status: "+ data.value);
      }
    );
    ```


## sensor.off<a name="section359005312519"></a>

off\(type: SensorType, callback?: AsyncCallback<void\>\): void

Unsubscribes from sensor data changes.

-   Parameters

    <a name="table9529451172218"></a>
    <table><thead align="left"><tr id="row165911539252"><th class="cellrowborder" valign="top" width="12.19%" id="mcps1.1.5.1.1"><p id="p18530145172211"><a name="p18530145172211"></a><a name="p18530145172211"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.97%" id="mcps1.1.5.1.2"><p id="p11530185115222"><a name="p11530185115222"></a><a name="p11530185115222"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.68%" id="mcps1.1.5.1.3"><p id="p165305519226"><a name="p165305519226"></a><a name="p165305519226"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.16%" id="mcps1.1.5.1.4"><p id="p45301551112214"><a name="p45301551112214"></a><a name="p45301551112214"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4594145313255"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p45301451102214"><a name="p45301451102214"></a><a name="p45301451102214"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.97%" headers="mcps1.1.5.1.2 "><p id="p1653113515228"><a name="p1653113515228"></a><a name="p1653113515228"></a><a href="#section02298004614">SensorType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p15311551122219"><a name="p15311551122219"></a><a name="p15311551122219"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p1153165116220"><a name="p1153165116220"></a><a name="p1153165116220"></a>Type of the sensor to unsubscribe from.</p>
    </td>
    </tr>
    <tr id="row12596155302516"><td class="cellrowborder" valign="top" width="12.19%" headers="mcps1.1.5.1.1 "><p id="p115311451102211"><a name="p115311451102211"></a><a name="p115311451102211"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.97%" headers="mcps1.1.5.1.2 "><p id="p8531135192215"><a name="p8531135192215"></a><a name="p8531135192215"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.68%" headers="mcps1.1.5.1.3 "><p id="p14532115117222"><a name="p14532115117222"></a><a name="p14532115117222"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.16%" headers="mcps1.1.5.1.4 "><p id="p45321151112215"><a name="p45321151112215"></a><a name="p45321151112215"></a>Callback used to return the execution result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    sensor.off(type:SensorType.SENSOR_TYPE_ID_ACCELEROMETER, function(error) {
        if (error) {
            console.error("Failed to unsubscribe from acceleration sensor data. Error code: " + error.code + "; message: " + error.message);
            return;
        }
        console.info("Succeeded in unsubscribing from acceleration sensor data.");
      }
    );
    
    ```


## SensorType<a name="section02298004614"></a>

Enumerates the sensor types.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="44.01%" id="mcps1.1.4.1.1"><p id="a3d0fc780cc904c1cbab7991251622f65"><a name="a3d0fc780cc904c1cbab7991251622f65"></a><a name="a3d0fc780cc904c1cbab7991251622f65"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="9.030000000000001%" id="mcps1.1.4.1.2"><p id="aace9cae4ba0d4939bfa048460f61c3c7"><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="46.96%" id="mcps1.1.4.1.3"><p id="afec895de33f94e3c87ee7acc20190a17"><a name="afec895de33f94e3c87ee7acc20190a17"></a><a name="afec895de33f94e3c87ee7acc20190a17"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row064618971411"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p136471951415"><a name="p136471951415"></a><a name="p136471951415"></a>SENSOR_TYPE_ID_ACCELEROMETER</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p1464711912145"><a name="p1464711912145"></a><a name="p1464711912145"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p5647196143"><a name="p5647196143"></a><a name="p5647196143"></a>Acceleration sensor.</p>
</td>
</tr>
<tr id="row8392113631410"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p133931836181416"><a name="p133931836181416"></a><a name="p133931836181416"></a>SENSOR_TYPE_ID_GYROSCOPE</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p11393123691420"><a name="p11393123691420"></a><a name="p11393123691420"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p15393193681419"><a name="p15393193681419"></a><a name="p15393193681419"></a>Gyroscope sensor.</p>
</td>
</tr>
<tr id="row162951728141419"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p7295202817141"><a name="p7295202817141"></a><a name="p7295202817141"></a>SENSOR_TYPE_ID_AMBIENT_LIGHT</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p132965287145"><a name="p132965287145"></a><a name="p132965287145"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p1929612812149"><a name="p1929612812149"></a><a name="p1929612812149"></a>Ambient light sensor.</p>
</td>
</tr>
<tr id="row106781231111417"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p1567893101419"><a name="p1567893101419"></a><a name="p1567893101419"></a>SENSOR_TYPE_ID_MAGNETIC_FIELD</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p967818319146"><a name="p967818319146"></a><a name="p967818319146"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p867814310146"><a name="p867814310146"></a><a name="p867814310146"></a>Magnetic field sensor.</p>
</td>
</tr>
<tr id="row637811621412"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p3378316101413"><a name="p3378316101413"></a><a name="p3378316101413"></a>SENSOR_TYPE_ID_BAROMETER</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p14378316141412"><a name="p14378316141412"></a><a name="p14378316141412"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p437814165145"><a name="p437814165145"></a><a name="p437814165145"></a>Barometer sensor.</p>
</td>
</tr>
<tr id="row75221141151414"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p16522541171410"><a name="p16522541171410"></a><a name="p16522541171410"></a>SENSOR_TYPE_ID_HALL</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p1252264131415"><a name="p1252264131415"></a><a name="p1252264131415"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p2052210412145"><a name="p2052210412145"></a><a name="p2052210412145"></a>Hall effect sensor.</p>
</td>
</tr>
<tr id="row1971824111418"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p1597213247148"><a name="p1597213247148"></a><a name="p1597213247148"></a>SENSOR_TYPE_ID_PROXIMITY</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p097214243147"><a name="p097214243147"></a><a name="p097214243147"></a>12</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p9972724111413"><a name="p9972724111413"></a><a name="p9972724111413"></a>Proximity sensor.</p>
</td>
</tr>
<tr id="row3110162111416"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p3111132117140"><a name="p3111132117140"></a><a name="p3111132117140"></a>SENSOR_TYPE_ID_HUMIDITY</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p8111162151412"><a name="p8111162151412"></a><a name="p8111162151412"></a>13</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p181111821111415"><a name="p181111821111415"></a><a name="p181111821111415"></a>Humidity sensor.</p>
</td>
</tr>
<tr id="row193052617161"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p2031152615166"><a name="p2031152615166"></a><a name="p2031152615166"></a>SENSOR_TYPE_ID_ORIENTATION</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p031142619162"><a name="p031142619162"></a><a name="p031142619162"></a>256</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p73112651616"><a name="p73112651616"></a><a name="p73112651616"></a>Orientation sensor.</p>
</td>
</tr>
<tr id="row168151840191617"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p118151640201616"><a name="p118151640201616"></a><a name="p118151640201616"></a>SENSOR_TYPE_ID_GRAVITY</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p98161540121614"><a name="p98161540121614"></a><a name="p98161540121614"></a>257</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p12816164021620"><a name="p12816164021620"></a><a name="p12816164021620"></a>Gravity sensor.</p>
</td>
</tr>
<tr id="row2070783741615"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p8707163781612"><a name="p8707163781612"></a><a name="p8707163781612"></a>SENSOR_TYPE_ID_LINEAR_ACCELERATION</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p207071337121611"><a name="p207071337121611"></a><a name="p207071337121611"></a>258</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p570713771613"><a name="p570713771613"></a><a name="p570713771613"></a>Linear acceleration sensor.</p>
</td>
</tr>
<tr id="row090719290166"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p199071629161617"><a name="p199071629161617"></a><a name="p199071629161617"></a>SENSOR_TYPE_ID_ROTATION_VECTOR</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p109071529141617"><a name="p109071529141617"></a><a name="p109071529141617"></a>259</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p8907729111618"><a name="p8907729111618"></a><a name="p8907729111618"></a>Rotation vector sensor.</p>
</td>
</tr>
<tr id="row1288811329164"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p4888143271613"><a name="p4888143271613"></a><a name="p4888143271613"></a>SENSOR_TYPE_ID_AMBIENT_TEMPERATURE</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p1488913231613"><a name="p1488913231613"></a><a name="p1488913231613"></a>260</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p1188953211163"><a name="p1188953211163"></a><a name="p1188953211163"></a>Ambient temperature sensor.</p>
</td>
</tr>
<tr id="row18979121141613"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p897992110164"><a name="p897992110164"></a><a name="p897992110164"></a>SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p997922111160"><a name="p997922111160"></a><a name="p997922111160"></a>261</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p1998082121616"><a name="p1998082121616"></a><a name="p1998082121616"></a>Uncalibrated magnetic field sensor.</p>
</td>
</tr>
<tr id="row1916017051816"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p11603018184"><a name="p11603018184"></a><a name="p11603018184"></a>SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p416012016182"><a name="p416012016182"></a><a name="p416012016182"></a>263</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p1716015091819"><a name="p1716015091819"></a><a name="p1716015091819"></a>Uncalibrated gyroscope sensor.</p>
</td>
</tr>
<tr id="row1498016881817"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p20980118171818"><a name="p20980118171818"></a><a name="p20980118171818"></a>SENSOR_TYPE_ID_SIGNIFICANT_MOTION</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p49801082181"><a name="p49801082181"></a><a name="p49801082181"></a>264</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p698112810187"><a name="p698112810187"></a><a name="p698112810187"></a>Significant motion sensor.</p>
</td>
</tr>
<tr id="row844712141815"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p745812131817"><a name="p745812131817"></a><a name="p745812131817"></a>SENSOR_TYPE_ID_PEDOMETER_DETECTION</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p34571210188"><a name="p34571210188"></a><a name="p34571210188"></a>265</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p64516125181"><a name="p64516125181"></a><a name="p64516125181"></a>Pedometer detection sensor.</p>
</td>
</tr>
<tr id="row34989517184"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p34986510181"><a name="p34986510181"></a><a name="p34986510181"></a>SENSOR_TYPE_ID_PEDOMETER</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p14989512183"><a name="p14989512183"></a><a name="p14989512183"></a>266</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p249875161814"><a name="p249875161814"></a><a name="p249875161814"></a>Pedometer sensor.</p>
</td>
</tr>
<tr id="row21931456151818"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p3193356161813"><a name="p3193356161813"></a><a name="p3193356161813"></a>SENSOR_TYPE_ID_HEART_RATE</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p9193115613181"><a name="p9193115613181"></a><a name="p9193115613181"></a>278</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p101935569185"><a name="p101935569185"></a><a name="p101935569185"></a>Heart rate sensor.</p>
</td>
</tr>
<tr id="row199353526181"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p493517526185"><a name="p493517526185"></a><a name="p493517526185"></a>SENSOR_TYPE_ID_WEAR_DETECTION</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p209351852111814"><a name="p209351852111814"></a><a name="p209351852111814"></a>280</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p593520524181"><a name="p593520524181"></a><a name="p593520524181"></a>Wear detection sensor.</p>
</td>
</tr>
<tr id="row1059723319196"><td class="cellrowborder" valign="top" width="44.01%" headers="mcps1.1.4.1.1 "><p id="p259893318199"><a name="p259893318199"></a><a name="p259893318199"></a>SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED</p>
</td>
<td class="cellrowborder" valign="top" width="9.030000000000001%" headers="mcps1.1.4.1.2 "><p id="p1059853351915"><a name="p1059853351915"></a><a name="p1059853351915"></a>281</p>
</td>
<td class="cellrowborder" valign="top" width="46.96%" headers="mcps1.1.4.1.3 "><p id="p159810334197"><a name="p159810334197"></a><a name="p159810334197"></a>Uncalibrated acceleration sensor.</p>
</td>
</tr>
</tbody>
</table>

## AccelerometerResponse<a name="section965820576618"></a>

Describes the acceleration sensor data.

<a name="table1459620431636"></a>
<table><thead align="left"><tr id="row25971143435"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p1559716434320"><a name="p1559716434320"></a><a name="p1559716434320"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p3597743539"><a name="p3597743539"></a><a name="p3597743539"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p15971343131"><a name="p15971343131"></a><a name="p15971343131"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1459715436311"><a name="p1459715436311"></a><a name="p1459715436311"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p75975439316"><a name="p75975439316"></a><a name="p75975439316"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15385227276"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1738112213273"><a name="p1738112213273"></a><a name="p1738112213273"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p23862218272"><a name="p23862218272"></a><a name="p23862218272"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p53932216277"><a name="p53932216277"></a><a name="p53932216277"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p33922216274"><a name="p33922216274"></a><a name="p33922216274"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1739192217279"><a name="p1739192217279"></a><a name="p1739192217279"></a>X-coordinate component.</p>
</td>
</tr>
<tr id="row118521130192720"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p128521830162718"><a name="p128521830162718"></a><a name="p128521830162718"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1853193014272"><a name="p1853193014272"></a><a name="p1853193014272"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p148537305275"><a name="p148537305275"></a><a name="p148537305275"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p385373092713"><a name="p385373092713"></a><a name="p385373092713"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1785383092711"><a name="p1785383092711"></a><a name="p1785383092711"></a>Y-coordinate component.</p>
</td>
</tr>
<tr id="row18838162692714"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p68391326202713"><a name="p68391326202713"></a><a name="p68391326202713"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p18839182632712"><a name="p18839182632712"></a><a name="p18839182632712"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p9839112622714"><a name="p9839112622714"></a><a name="p9839112622714"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p12839172620273"><a name="p12839172620273"></a><a name="p12839172620273"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p7839826112711"><a name="p7839826112711"></a><a name="p7839826112711"></a>Z-coordinate component.</p>
</td>
</tr>
</tbody>
</table>

## LinearAccelerometerResponse<a name="section1151477447"></a>

Describes the linear acceleration sensor data.

<a name="table99069363387"></a>
<table><thead align="left"><tr id="row1990711362388"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p990873633810"><a name="p990873633810"></a><a name="p990873633810"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p12908836193815"><a name="p12908836193815"></a><a name="p12908836193815"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p49091436193816"><a name="p49091436193816"></a><a name="p49091436193816"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1990911361383"><a name="p1990911361383"></a><a name="p1990911361383"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p179101436193815"><a name="p179101436193815"></a><a name="p179101436193815"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row991083683819"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p59117367383"><a name="p59117367383"></a><a name="p59117367383"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p391143617382"><a name="p391143617382"></a><a name="p391143617382"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p169111936153810"><a name="p169111936153810"></a><a name="p169111936153810"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1691233633818"><a name="p1691233633818"></a><a name="p1691233633818"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p11912103617383"><a name="p11912103617383"></a><a name="p11912103617383"></a>X-coordinate component.</p>
</td>
</tr>
<tr id="row29131936123819"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p291333615386"><a name="p291333615386"></a><a name="p291333615386"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p891318369387"><a name="p891318369387"></a><a name="p891318369387"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p10914113619386"><a name="p10914113619386"></a><a name="p10914113619386"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p69141136143812"><a name="p69141136143812"></a><a name="p69141136143812"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p59141136163810"><a name="p59141136163810"></a><a name="p59141136163810"></a>Y-coordinate component.</p>
</td>
</tr>
<tr id="row18915123683818"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1291543614384"><a name="p1291543614384"></a><a name="p1291543614384"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p11915036143816"><a name="p11915036143816"></a><a name="p11915036143816"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p14917143653811"><a name="p14917143653811"></a><a name="p14917143653811"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1391713366382"><a name="p1391713366382"></a><a name="p1391713366382"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p18918036123816"><a name="p18918036123816"></a><a name="p18918036123816"></a>Z-coordinate component.</p>
</td>
</tr>
</tbody>
</table>

## AccelerometerUncalibratedResponse<a name="section253082316457"></a>

Describes the uncalibrated acceleration sensor data.

<a name="table166899304014"></a>
<table><thead align="left"><tr id="row8696133194017"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p166962334015"><a name="p166962334015"></a><a name="p166962334015"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1669718317405"><a name="p1669718317405"></a><a name="p1669718317405"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p369713314011"><a name="p369713314011"></a><a name="p369713314011"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p36981034405"><a name="p36981034405"></a><a name="p36981034405"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p15698632407"><a name="p15698632407"></a><a name="p15698632407"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1269810316406"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p7699113144011"><a name="p7699113144011"></a><a name="p7699113144011"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1070043114017"><a name="p1070043114017"></a><a name="p1070043114017"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p470123164018"><a name="p470123164018"></a><a name="p470123164018"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p18702133104020"><a name="p18702133104020"></a><a name="p18702133104020"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16702132409"><a name="p16702132409"></a><a name="p16702132409"></a>X-coordinate component.</p>
</td>
</tr>
<tr id="row87038315401"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p870313384011"><a name="p870313384011"></a><a name="p870313384011"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1670316318407"><a name="p1670316318407"></a><a name="p1670316318407"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p67041931400"><a name="p67041931400"></a><a name="p67041931400"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p17704163134013"><a name="p17704163134013"></a><a name="p17704163134013"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1870543144016"><a name="p1870543144016"></a><a name="p1870543144016"></a>Y-coordinate component.</p>
</td>
</tr>
<tr id="row177051433405"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p207054354014"><a name="p207054354014"></a><a name="p207054354014"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p970513354010"><a name="p970513354010"></a><a name="p970513354010"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p3706939401"><a name="p3706939401"></a><a name="p3706939401"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p177062314406"><a name="p177062314406"></a><a name="p177062314406"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16707432406"><a name="p16707432406"></a><a name="p16707432406"></a>Z-coordinate component.</p>
</td>
</tr>
<tr id="row14176111210404"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1117620129404"><a name="p1117620129404"></a><a name="p1117620129404"></a>biasX</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p6176812124016"><a name="p6176812124016"></a><a name="p6176812124016"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p1517761220402"><a name="p1517761220402"></a><a name="p1517761220402"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p16177131214010"><a name="p16177131214010"></a><a name="p16177131214010"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1617721210403"><a name="p1617721210403"></a><a name="p1617721210403"></a>X-coordinate bias.</p>
</td>
</tr>
<tr id="row538415193407"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p83852019194011"><a name="p83852019194011"></a><a name="p83852019194011"></a>biasY</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p133851519154015"><a name="p133851519154015"></a><a name="p133851519154015"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p153851819184014"><a name="p153851819184014"></a><a name="p153851819184014"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p738571916407"><a name="p738571916407"></a><a name="p738571916407"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p163861319124014"><a name="p163861319124014"></a><a name="p163861319124014"></a>Y-coordinate bias.</p>
</td>
</tr>
<tr id="row197261815104013"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p117261515154018"><a name="p117261515154018"></a><a name="p117261515154018"></a>biasZ</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p167271115114018"><a name="p167271115114018"></a><a name="p167271115114018"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p137271215154015"><a name="p137271215154015"></a><a name="p137271215154015"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p10727215124012"><a name="p10727215124012"></a><a name="p10727215124012"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p072721512406"><a name="p072721512406"></a><a name="p072721512406"></a>Z-coordinate bias.</p>
</td>
</tr>
</tbody>
</table>

## GravityResponse<a name="section162913399453"></a>

Describes the gravity sensor data.

<a name="table84391131164311"></a>
<table><thead align="left"><tr id="row16441831154317"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p1244153112439"><a name="p1244153112439"></a><a name="p1244153112439"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p2441331144316"><a name="p2441331144316"></a><a name="p2441331144316"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p144219312435"><a name="p144219312435"></a><a name="p144219312435"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1744243134319"><a name="p1744243134319"></a><a name="p1744243134319"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p15443113111432"><a name="p15443113111432"></a><a name="p15443113111432"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row184431831154312"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p64449312431"><a name="p64449312431"></a><a name="p64449312431"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p204441131174318"><a name="p204441131174318"></a><a name="p204441131174318"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p144515312431"><a name="p144515312431"></a><a name="p144515312431"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p04452315433"><a name="p04452315433"></a><a name="p04452315433"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p11446431114315"><a name="p11446431114315"></a><a name="p11446431114315"></a>X-coordinate component.</p>
</td>
</tr>
<tr id="row844618311437"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p144463319438"><a name="p144463319438"></a><a name="p144463319438"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1344623118439"><a name="p1344623118439"></a><a name="p1344623118439"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p1447173134315"><a name="p1447173134315"></a><a name="p1447173134315"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p54472313438"><a name="p54472313438"></a><a name="p54472313438"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p134481731194311"><a name="p134481731194311"></a><a name="p134481731194311"></a>Y-coordinate component.</p>
</td>
</tr>
<tr id="row54481831114316"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1448163119437"><a name="p1448163119437"></a><a name="p1448163119437"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p94491631134315"><a name="p94491631134315"></a><a name="p94491631134315"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p134496314439"><a name="p134496314439"></a><a name="p134496314439"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p174491231164313"><a name="p174491231164313"></a><a name="p174491231164313"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p2450531104319"><a name="p2450531104319"></a><a name="p2450531104319"></a>Z-coordinate component.</p>
</td>
</tr>
</tbody>
</table>

## OrientationResponse<a name="section128271514456"></a>

Describes the orientation sensor data.

<a name="table1897717534447"></a>
<table><thead align="left"><tr id="row1297895311441"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p1597818531448"><a name="p1597818531448"></a><a name="p1597818531448"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p2979145314410"><a name="p2979145314410"></a><a name="p2979145314410"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p9979253134417"><a name="p9979253134417"></a><a name="p9979253134417"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1297975324410"><a name="p1297975324410"></a><a name="p1297975324410"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p3980653194420"><a name="p3980653194420"></a><a name="p3980653194420"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row698015533445"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1598155314411"><a name="p1598155314411"></a><a name="p1598155314411"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p11981653144411"><a name="p11981653144411"></a><a name="p11981653144411"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p169822053164420"><a name="p169822053164420"></a><a name="p169822053164420"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p198218531448"><a name="p198218531448"></a><a name="p198218531448"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p199831253144413"><a name="p199831253144413"></a><a name="p199831253144413"></a>X-coordinate component.</p>
</td>
</tr>
<tr id="row698365394417"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p898375317447"><a name="p898375317447"></a><a name="p898375317447"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p109841253134412"><a name="p109841253134412"></a><a name="p109841253134412"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p2985175314449"><a name="p2985175314449"></a><a name="p2985175314449"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p20985145324415"><a name="p20985145324415"></a><a name="p20985145324415"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p15985155313447"><a name="p15985155313447"></a><a name="p15985155313447"></a>Y-coordinate component.</p>
</td>
</tr>
<tr id="row9987853194410"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p10987135312440"><a name="p10987135312440"></a><a name="p10987135312440"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p4988105312445"><a name="p4988105312445"></a><a name="p4988105312445"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p1698885354411"><a name="p1698885354411"></a><a name="p1698885354411"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p09883534446"><a name="p09883534446"></a><a name="p09883534446"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p10989753104412"><a name="p10989753104412"></a><a name="p10989753104412"></a>Z-coordinate component.</p>
</td>
</tr>
</tbody>
</table>

## RotationVectorResponse<a name="section13776194114611"></a>

Describes the rotation vector sensor data.

<a name="table936012224464"></a>
<table><thead align="left"><tr id="row1536162218466"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p93621222184610"><a name="p93621222184610"></a><a name="p93621222184610"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p73641422174614"><a name="p73641422174614"></a><a name="p73641422174614"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p936413225462"><a name="p936413225462"></a><a name="p936413225462"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1436515220462"><a name="p1436515220462"></a><a name="p1436515220462"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p163653222464"><a name="p163653222464"></a><a name="p163653222464"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17366722174611"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p43670221462"><a name="p43670221462"></a><a name="p43670221462"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p14367822164613"><a name="p14367822164613"></a><a name="p14367822164613"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p133681722114611"><a name="p133681722114611"></a><a name="p133681722114611"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p17368162211468"><a name="p17368162211468"></a><a name="p17368162211468"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16368172213460"><a name="p16368172213460"></a><a name="p16368172213460"></a>X-coordinate component.</p>
</td>
</tr>
<tr id="row1736952234619"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p2369122214464"><a name="p2369122214464"></a><a name="p2369122214464"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p17369112244616"><a name="p17369112244616"></a><a name="p17369112244616"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p4370202254614"><a name="p4370202254614"></a><a name="p4370202254614"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p2037012216463"><a name="p2037012216463"></a><a name="p2037012216463"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p16371022144615"><a name="p16371022144615"></a><a name="p16371022144615"></a>Y-coordinate component.</p>
</td>
</tr>
<tr id="row10371142284612"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p337262284611"><a name="p337262284611"></a><a name="p337262284611"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p6372322164613"><a name="p6372322164613"></a><a name="p6372322164613"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p53721522154614"><a name="p53721522154614"></a><a name="p53721522154614"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p3373922144618"><a name="p3373922144618"></a><a name="p3373922144618"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p537319223469"><a name="p537319223469"></a><a name="p537319223469"></a>Z-coordinate component.</p>
</td>
</tr>
</tbody>
</table>

## GyroscopeResponse<a name="section3669131713463"></a>

Describes the gyroscope sensor data.

<a name="table102754418482"></a>
<table><thead align="left"><tr id="row132777414481"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p142771946487"><a name="p142771946487"></a><a name="p142771946487"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1827816417489"><a name="p1827816417489"></a><a name="p1827816417489"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p16278945480"><a name="p16278945480"></a><a name="p16278945480"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p112794464817"><a name="p112794464817"></a><a name="p112794464817"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p1927919411483"><a name="p1927919411483"></a><a name="p1927919411483"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row82804419487"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p9280164114818"><a name="p9280164114818"></a><a name="p9280164114818"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p12811748489"><a name="p12811748489"></a><a name="p12811748489"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p1328184124815"><a name="p1328184124815"></a><a name="p1328184124815"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1028214134817"><a name="p1028214134817"></a><a name="p1028214134817"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p82831648484"><a name="p82831648484"></a><a name="p82831648484"></a>X-coordinate component.</p>
</td>
</tr>
<tr id="row1628316411487"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p4283194194814"><a name="p4283194194814"></a><a name="p4283194194814"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p102843418489"><a name="p102843418489"></a><a name="p102843418489"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p20284124134812"><a name="p20284124134812"></a><a name="p20284124134812"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p2285174164816"><a name="p2285174164816"></a><a name="p2285174164816"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p52904454817"><a name="p52904454817"></a><a name="p52904454817"></a>Y-coordinate component.</p>
</td>
</tr>
<tr id="row529014124817"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p17290204144811"><a name="p17290204144811"></a><a name="p17290204144811"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p12913414486"><a name="p12913414486"></a><a name="p12913414486"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p142911147480"><a name="p142911147480"></a><a name="p142911147480"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p13292194104814"><a name="p13292194104814"></a><a name="p13292194104814"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p172923411480"><a name="p172923411480"></a><a name="p172923411480"></a>Z-coordinate component.</p>
</td>
</tr>
</tbody>
</table>

## GyroscopeUncalibratedResponse<a name="section1041541413475"></a>

Describes the uncalibrated gyroscope sensor data.

<a name="table13573121419491"></a>
<table><thead align="left"><tr id="row1257531411492"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p357541412492"><a name="p357541412492"></a><a name="p357541412492"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1157571411492"><a name="p1157571411492"></a><a name="p1157571411492"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p357691434915"><a name="p357691434915"></a><a name="p357691434915"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p65767140498"><a name="p65767140498"></a><a name="p65767140498"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p7576814124913"><a name="p7576814124913"></a><a name="p7576814124913"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row957710147490"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p2577191419497"><a name="p2577191419497"></a><a name="p2577191419497"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p4578101413498"><a name="p4578101413498"></a><a name="p4578101413498"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p257861411497"><a name="p257861411497"></a><a name="p257861411497"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p85781141490"><a name="p85781141490"></a><a name="p85781141490"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1757971418492"><a name="p1757971418492"></a><a name="p1757971418492"></a>X-coordinate component.</p>
</td>
</tr>
<tr id="row4579914134916"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p115791014104911"><a name="p115791014104911"></a><a name="p115791014104911"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p9580714144912"><a name="p9580714144912"></a><a name="p9580714144912"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p14581514134911"><a name="p14581514134911"></a><a name="p14581514134911"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1658281410492"><a name="p1658281410492"></a><a name="p1658281410492"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p05821144494"><a name="p05821144494"></a><a name="p05821144494"></a>Y-coordinate component.</p>
</td>
</tr>
<tr id="row8582214174913"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p458331410497"><a name="p458331410497"></a><a name="p458331410497"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p5583171484918"><a name="p5583171484918"></a><a name="p5583171484918"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p10583131434918"><a name="p10583131434918"></a><a name="p10583131434918"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p258451484917"><a name="p258451484917"></a><a name="p258451484917"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p18584514204911"><a name="p18584514204911"></a><a name="p18584514204911"></a>Z-coordinate component.</p>
</td>
</tr>
<tr id="row8585111414498"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p20585111454910"><a name="p20585111454910"></a><a name="p20585111454910"></a>biasX</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p858541411498"><a name="p858541411498"></a><a name="p858541411498"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p6586914104920"><a name="p6586914104920"></a><a name="p6586914104920"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p958612145494"><a name="p958612145494"></a><a name="p958612145494"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p165871614104919"><a name="p165871614104919"></a><a name="p165871614104919"></a>X-coordinate bias.</p>
</td>
</tr>
<tr id="row1158718145494"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p13587514124919"><a name="p13587514124919"></a><a name="p13587514124919"></a>biasY</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p058811424915"><a name="p058811424915"></a><a name="p058811424915"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p165881414134913"><a name="p165881414134913"></a><a name="p165881414134913"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p458841411491"><a name="p458841411491"></a><a name="p458841411491"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p10589171413495"><a name="p10589171413495"></a><a name="p10589171413495"></a>Y-coordinate bias.</p>
</td>
</tr>
<tr id="row15589514174920"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p558912143499"><a name="p558912143499"></a><a name="p558912143499"></a>biasZ</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1059051415498"><a name="p1059051415498"></a><a name="p1059051415498"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p18590171484915"><a name="p18590171484915"></a><a name="p18590171484915"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p3590191434919"><a name="p3590191434919"></a><a name="p3590191434919"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p114335613132"><a name="p114335613132"></a><a name="p114335613132"></a>Z-coordinate bias.</p>
</td>
</tr>
</tbody>
</table>

## SignificantMotionResponse<a name="section1213143164712"></a>

Describes the significant motion sensor data.

<a name="table4948240175015"></a>
<table><thead align="left"><tr id="row139500400502"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p17950104035012"><a name="p17950104035012"></a><a name="p17950104035012"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1595014402501"><a name="p1595014402501"></a><a name="p1595014402501"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p0951144015010"><a name="p0951144015010"></a><a name="p0951144015010"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p19951184015506"><a name="p19951184015506"></a><a name="p19951184015506"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p1795217408508"><a name="p1795217408508"></a><a name="p1795217408508"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row195264075013"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p49531340145019"><a name="p49531340145019"></a><a name="p49531340145019"></a>scalar</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p59531940145017"><a name="p59531940145017"></a><a name="p59531940145017"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p13953184045010"><a name="p13953184045010"></a><a name="p13953184045010"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p13954174045015"><a name="p13954174045015"></a><a name="p13954174045015"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p783151465110"><a name="p783151465110"></a><a name="p783151465110"></a>Intensity of a motion. This parameter specifies whether a device has a significant motion on three physical axes (X, Y, and Z). The value <strong id="b664442535117"><a name="b664442535117"></a><a name="b664442535117"></a>0</strong> means that the device does not have a significant motion, and <strong id="b156532251516"><a name="b156532251516"></a><a name="b156532251516"></a>1</strong> means the opposite.</p>
</td>
</tr>
</tbody>
</table>

## ProximityResponse<a name="section5275184313476"></a>

Describes the proximity sensor data.

<a name="table202672057205220"></a>
<table><thead align="left"><tr id="row126955713526"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p226985716524"><a name="p226985716524"></a><a name="p226985716524"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p9270195716524"><a name="p9270195716524"></a><a name="p9270195716524"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p112707570523"><a name="p112707570523"></a><a name="p112707570523"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p19271115717528"><a name="p19271115717528"></a><a name="p19271115717528"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p17271957135218"><a name="p17271957135218"></a><a name="p17271957135218"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1827275715524"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1327312575521"><a name="p1327312575521"></a><a name="p1327312575521"></a>distance</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p6274155713523"><a name="p6274155713523"></a><a name="p6274155713523"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p12758576525"><a name="p12758576525"></a><a name="p12758576525"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p2275155735217"><a name="p2275155735217"></a><a name="p2275155735217"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1827511579525"><a name="p1827511579525"></a><a name="p1827511579525"></a>Proximity between the visible object and the device monitor. The value <strong id="b27591729165312"><a name="b27591729165312"></a><a name="b27591729165312"></a>0</strong> means the two are close to each other, and <strong id="b1749514213536"><a name="b1749514213536"></a><a name="b1749514213536"></a>1</strong> means that they are far away from each other.</p>
</td>
</tr>
</tbody>
</table>

## LightResponse<a name="section195685404716"></a>

Describes the ambient light sensor data.

<a name="table9943111745715"></a>
<table><thead align="left"><tr id="row69451176576"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p4946117165719"><a name="p4946117165719"></a><a name="p4946117165719"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p5946131718576"><a name="p5946131718576"></a><a name="p5946131718576"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p1947141775714"><a name="p1947141775714"></a><a name="p1947141775714"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1594791795712"><a name="p1594791795712"></a><a name="p1594791795712"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p19481817105717"><a name="p19481817105717"></a><a name="p19481817105717"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row179481617155718"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p494931755718"><a name="p494931755718"></a><a name="p494931755718"></a>intensity</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p294951712577"><a name="p294951712577"></a><a name="p294951712577"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p6950417135718"><a name="p6950417135718"></a><a name="p6950417135718"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1995011710574"><a name="p1995011710574"></a><a name="p1995011710574"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1395001713579"><a name="p1395001713579"></a><a name="p1395001713579"></a>Illumination, in lux.</p>
</td>
</tr>
</tbody>
</table>

## HallResponse<a name="section18608467487"></a>

Describes the Hall effect sensor data.

<a name="table1911424985916"></a>
<table><thead align="left"><tr id="row111171049205916"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p1511713492592"><a name="p1511713492592"></a><a name="p1511713492592"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p16117144918595"><a name="p16117144918595"></a><a name="p16117144918595"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p16118144915592"><a name="p16118144915592"></a><a name="p16118144915592"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p9118149165915"><a name="p9118149165915"></a><a name="p9118149165915"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p101191149185918"><a name="p101191149185918"></a><a name="p101191149185918"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0119184918596"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1112084919593"><a name="p1112084919593"></a><a name="p1112084919593"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p51211149105919"><a name="p51211149105919"></a><a name="p51211149105919"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p19121164915911"><a name="p19121164915911"></a><a name="p19121164915911"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p312224918597"><a name="p312224918597"></a><a name="p312224918597"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1612224918598"><a name="p1612224918598"></a><a name="p1612224918598"></a>Hall effect sensor status. This parameter specifies whether a magnetic field exists around a device. The value <strong id="b0932552115618"><a name="b0932552115618"></a><a name="b0932552115618"></a>0</strong> means that a magnetic field exists around the device, and <strong id="b424189175714"><a name="b424189175714"></a><a name="b424189175714"></a>1</strong> means the opposite.</p>
</td>
</tr>
</tbody>
</table>

## MagneticFieldResponse<a name="section20218191813489"></a>

Describes the magnetic field sensor data.

<a name="table730517551096"></a>
<table><thead align="left"><tr id="row113071551994"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p1630817551591"><a name="p1630817551591"></a><a name="p1630817551591"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1030885517919"><a name="p1030885517919"></a><a name="p1030885517919"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p1309125516917"><a name="p1309125516917"></a><a name="p1309125516917"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p730935511910"><a name="p730935511910"></a><a name="p730935511910"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p430916559916"><a name="p430916559916"></a><a name="p430916559916"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row531015552910"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p63101155298"><a name="p63101155298"></a><a name="p63101155298"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p13311145518913"><a name="p13311145518913"></a><a name="p13311145518913"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p103119551916"><a name="p103119551916"></a><a name="p103119551916"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p731216558917"><a name="p731216558917"></a><a name="p731216558917"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p931218554920"><a name="p931218554920"></a><a name="p931218554920"></a>X-coordinate component.</p>
</td>
</tr>
<tr id="row153134551696"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p183135551397"><a name="p183135551397"></a><a name="p183135551397"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1231313553915"><a name="p1231313553915"></a><a name="p1231313553915"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p03148551490"><a name="p03148551490"></a><a name="p03148551490"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p193142551292"><a name="p193142551292"></a><a name="p193142551292"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p931516551293"><a name="p931516551293"></a><a name="p931516551293"></a>Y-coordinate component.</p>
</td>
</tr>
<tr id="row93154551999"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p8315105516911"><a name="p8315105516911"></a><a name="p8315105516911"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p531625514919"><a name="p531625514919"></a><a name="p531625514919"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p33162055892"><a name="p33162055892"></a><a name="p33162055892"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p3317455991"><a name="p3317455991"></a><a name="p3317455991"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p13318145517919"><a name="p13318145517919"></a><a name="p13318145517919"></a>Z-coordinate component.</p>
</td>
</tr>
</tbody>
</table>

## MagneticFieldUncalibratedResponse<a name="section13749143113486"></a>

Describes the uncalibrated magnetic field sensor data.

<a name="table131661533141019"></a>
<table><thead align="left"><tr id="row14167103381016"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p171687333103"><a name="p171687333103"></a><a name="p171687333103"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p1168173351011"><a name="p1168173351011"></a><a name="p1168173351011"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p10168433181013"><a name="p10168433181013"></a><a name="p10168433181013"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p191691933171018"><a name="p191691933171018"></a><a name="p191691933171018"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p6169113311107"><a name="p6169113311107"></a><a name="p6169113311107"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row11170633141011"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p131707336105"><a name="p131707336105"></a><a name="p131707336105"></a>x</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p8170203341018"><a name="p8170203341018"></a><a name="p8170203341018"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p8171113311014"><a name="p8171113311014"></a><a name="p8171113311014"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p151717334108"><a name="p151717334108"></a><a name="p151717334108"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1117216339104"><a name="p1117216339104"></a><a name="p1117216339104"></a>X-coordinate component.</p>
</td>
</tr>
<tr id="row617283341012"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p1217210333103"><a name="p1217210333103"></a><a name="p1217210333103"></a>y</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p13173193312104"><a name="p13173193312104"></a><a name="p13173193312104"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p71731433191015"><a name="p71731433191015"></a><a name="p71731433191015"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p2174933151015"><a name="p2174933151015"></a><a name="p2174933151015"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1717413317103"><a name="p1717413317103"></a><a name="p1717413317103"></a>Y-coordinate component.</p>
</td>
</tr>
<tr id="row617443319105"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p13175433181015"><a name="p13175433181015"></a><a name="p13175433181015"></a>z</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p11175173301019"><a name="p11175173301019"></a><a name="p11175173301019"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p171761233101019"><a name="p171761233101019"></a><a name="p171761233101019"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p817623301020"><a name="p817623301020"></a><a name="p817623301020"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p5176113311100"><a name="p5176113311100"></a><a name="p5176113311100"></a>Z-coordinate component.</p>
</td>
</tr>
<tr id="row1117713391016"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p617703319103"><a name="p617703319103"></a><a name="p617703319103"></a>biasX</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1417710332105"><a name="p1417710332105"></a><a name="p1417710332105"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p15178833171015"><a name="p15178833171015"></a><a name="p15178833171015"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p7178203310105"><a name="p7178203310105"></a><a name="p7178203310105"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p14179933111017"><a name="p14179933111017"></a><a name="p14179933111017"></a>X-coordinate bias.</p>
</td>
</tr>
<tr id="row3179103312100"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p16179163351015"><a name="p16179163351015"></a><a name="p16179163351015"></a>biasY</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p51801033191015"><a name="p51801033191015"></a><a name="p51801033191015"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p171811433101014"><a name="p171811433101014"></a><a name="p171811433101014"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p14181833101013"><a name="p14181833101013"></a><a name="p14181833101013"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1318213318105"><a name="p1318213318105"></a><a name="p1318213318105"></a>Y-coordinate bias.</p>
</td>
</tr>
<tr id="row5182113361010"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p61831033201011"><a name="p61831033201011"></a><a name="p61831033201011"></a>biasZ</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1918423311102"><a name="p1918423311102"></a><a name="p1918423311102"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p9184173320105"><a name="p9184173320105"></a><a name="p9184173320105"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1718593371011"><a name="p1718593371011"></a><a name="p1718593371011"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1418563321020"><a name="p1418563321020"></a><a name="p1418563321020"></a>Z-coordinate bias.</p>
</td>
</tr>
</tbody>
</table>

## PedometerResponse<a name="section1350145915489"></a>

Describes the pedometer sensor data.

<a name="table1221161131216"></a>
<table><thead align="left"><tr id="row132312114128"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p923811191215"><a name="p923811191215"></a><a name="p923811191215"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p192415116127"><a name="p192415116127"></a><a name="p192415116127"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p5240115123"><a name="p5240115123"></a><a name="p5240115123"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p32531110121"><a name="p32531110121"></a><a name="p32531110121"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p102551116129"><a name="p102551116129"></a><a name="p102551116129"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row826511151216"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p6276119120"><a name="p6276119120"></a><a name="p6276119120"></a>steps</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1227511161210"><a name="p1227511161210"></a><a name="p1227511161210"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p102716117128"><a name="p102716117128"></a><a name="p102716117128"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p62891114129"><a name="p62891114129"></a><a name="p62891114129"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p930101114120"><a name="p930101114120"></a><a name="p930101114120"></a>Number of steps. The number starts from <strong id="b9436154013580"><a name="b9436154013580"></a><a name="b9436154013580"></a>0</strong> each time the device restarts.</p>
</td>
</tr>
</tbody>
</table>

## HumidityResponse<a name="section20444511666"></a>

Describes the humidity sensor data.

<a name="table1938504321317"></a>
<table><thead align="left"><tr id="row7387134310134"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p838784331318"><a name="p838784331318"></a><a name="p838784331318"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p73888439139"><a name="p73888439139"></a><a name="p73888439139"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p4390843161311"><a name="p4390843161311"></a><a name="p4390843161311"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p53901743131312"><a name="p53901743131312"></a><a name="p53901743131312"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p8391104381315"><a name="p8391104381315"></a><a name="p8391104381315"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row18391154314131"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p17392043191317"><a name="p17392043191317"></a><a name="p17392043191317"></a>humidity</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p183928439135"><a name="p183928439135"></a><a name="p183928439135"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p539354361312"><a name="p539354361312"></a><a name="p539354361312"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p153931943141316"><a name="p153931943141316"></a><a name="p153931943141316"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p2394124391310"><a name="p2394124391310"></a><a name="p2394124391310"></a>Ambient relative humidity, in a percentage (%).</p>
</td>
</tr>
</tbody>
</table>

## PedometerDetectResponse<a name="section145653910491"></a>

Describes the pedometer detection sensor data.

<a name="table1344548131418"></a>
<table><thead align="left"><tr id="row847124841419"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p184784811412"><a name="p184784811412"></a><a name="p184784811412"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p748184871417"><a name="p748184871417"></a><a name="p748184871417"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p0481948101412"><a name="p0481948101412"></a><a name="p0481948101412"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p154915487141"><a name="p154915487141"></a><a name="p154915487141"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p149174819147"><a name="p149174819147"></a><a name="p149174819147"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row124994881417"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p350148161411"><a name="p350148161411"></a><a name="p350148161411"></a>scalar</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p15115487149"><a name="p15115487149"></a><a name="p15115487149"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p155194821414"><a name="p155194821414"></a><a name="p155194821414"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p4521148171413"><a name="p4521148171413"></a><a name="p4521148171413"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p152148131413"><a name="p152148131413"></a><a name="p152148131413"></a>Pedometer detection. This parameter specifies whether a user takes a step. The value <strong id="b1996719148015"><a name="b1996719148015"></a><a name="b1996719148015"></a>0</strong> means that the user does not take a step, and <strong id="b197717141905"><a name="b197717141905"></a><a name="b197717141905"></a>1</strong> means that the user takes a step.</p>
</td>
</tr>
</tbody>
</table>

## AmbientTemperatureResponse<a name="section728281924920"></a>

Describes the ambient temperature sensor data.

<a name="table125671838181519"></a>
<table><thead align="left"><tr id="row1656803818158"><th class="cellrowborder" valign="top" width="17.41%" id="mcps1.1.6.1.1"><p id="p145691638161517"><a name="p145691638161517"></a><a name="p145691638161517"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.200000000000001%" id="mcps1.1.6.1.2"><p id="p1656923871512"><a name="p1656923871512"></a><a name="p1656923871512"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.31%" id="mcps1.1.6.1.3"><p id="p857033813151"><a name="p857033813151"></a><a name="p857033813151"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="10.32%" id="mcps1.1.6.1.4"><p id="p7570103821513"><a name="p7570103821513"></a><a name="p7570103821513"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="48.76%" id="mcps1.1.6.1.5"><p id="p75717386158"><a name="p75717386158"></a><a name="p75717386158"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row55718388151"><td class="cellrowborder" valign="top" width="17.41%" headers="mcps1.1.6.1.1 "><p id="p25713386150"><a name="p25713386150"></a><a name="p25713386150"></a>temperature</p>
</td>
<td class="cellrowborder" valign="top" width="13.200000000000001%" headers="mcps1.1.6.1.2 "><p id="p85729383152"><a name="p85729383152"></a><a name="p85729383152"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.31%" headers="mcps1.1.6.1.3 "><p id="p1757213388153"><a name="p1757213388153"></a><a name="p1757213388153"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="10.32%" headers="mcps1.1.6.1.4 "><p id="p55734383154"><a name="p55734383154"></a><a name="p55734383154"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="48.76%" headers="mcps1.1.6.1.5 "><p id="p1557313811513"><a name="p1557313811513"></a><a name="p1557313811513"></a>Ambient temperature, in degree Celsius.</p>
</td>
</tr>
</tbody>
</table>

## BarometerResponse<a name="section143457303496"></a>

Describes the barometer sensor data.

<a name="table1846831851619"></a>
<table><thead align="left"><tr id="row646931812166"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p124703182168"><a name="p124703182168"></a><a name="p124703182168"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p194702185166"><a name="p194702185166"></a><a name="p194702185166"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p1147117181161"><a name="p1147117181161"></a><a name="p1147117181161"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p16471191811619"><a name="p16471191811619"></a><a name="p16471191811619"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p1447212181164"><a name="p1447212181164"></a><a name="p1447212181164"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row164721418161614"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p64729187163"><a name="p64729187163"></a><a name="p64729187163"></a>pressure</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p047361810165"><a name="p047361810165"></a><a name="p047361810165"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p11474151831612"><a name="p11474151831612"></a><a name="p11474151831612"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p10474131812168"><a name="p10474131812168"></a><a name="p10474131812168"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p947510186168"><a name="p947510186168"></a><a name="p947510186168"></a>Atmospheric pressure, in pascal.</p>
</td>
</tr>
</tbody>
</table>

## HeartRateResponse<a name="section95011341124915"></a>

Describes the heart rate sensor data.

<a name="table47331264174"></a>
<table><thead align="left"><tr id="row473519651714"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p37351611718"><a name="p37351611718"></a><a name="p37351611718"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p273611610170"><a name="p273611610170"></a><a name="p273611610170"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p13736565175"><a name="p13736565175"></a><a name="p13736565175"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p073719691711"><a name="p073719691711"></a><a name="p073719691711"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p127377611172"><a name="p127377611172"></a><a name="p127377611172"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row07380617174"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p147388671710"><a name="p147388671710"></a><a name="p147388671710"></a>heartRate</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p167381063177"><a name="p167381063177"></a><a name="p167381063177"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p177391641717"><a name="p177391641717"></a><a name="p177391641717"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1173911661720"><a name="p1173911661720"></a><a name="p1173911661720"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p11740176131712"><a name="p11740176131712"></a><a name="p11740176131712"></a>Heart rate, in beats per minute.</p>
</td>
</tr>
</tbody>
</table>

## WearDetectionResponse<a name="section128278501495"></a>

Describes the wear detection sensor data.

<a name="table64111853121720"></a>
<table><thead align="left"><tr id="row4413135314174"><th class="cellrowborder" valign="top" width="10.780000000000001%" id="mcps1.1.6.1.1"><p id="p174131653181715"><a name="p174131653181715"></a><a name="p174131653181715"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.149999999999999%" id="mcps1.1.6.1.2"><p id="p5414145312174"><a name="p5414145312174"></a><a name="p5414145312174"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.14%" id="mcps1.1.6.1.3"><p id="p14144533171"><a name="p14144533171"></a><a name="p14144533171"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p134140535176"><a name="p134140535176"></a><a name="p134140535176"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p16415165319173"><a name="p16415165319173"></a><a name="p16415165319173"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row19415155321710"><td class="cellrowborder" valign="top" width="10.780000000000001%" headers="mcps1.1.6.1.1 "><p id="p7416153191713"><a name="p7416153191713"></a><a name="p7416153191713"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="14.149999999999999%" headers="mcps1.1.6.1.2 "><p id="p1341695351714"><a name="p1341695351714"></a><a name="p1341695351714"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="11.14%" headers="mcps1.1.6.1.3 "><p id="p14171153201710"><a name="p14171153201710"></a><a name="p14171153201710"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p041716530173"><a name="p041716530173"></a><a name="p041716530173"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p11418135318172"><a name="p11418135318172"></a><a name="p11418135318172"></a>Whether the device is being worn. The value <strong id="b379118181647"><a name="b379118181647"></a><a name="b379118181647"></a>true</strong> means that the device is being worn, and <strong id="b11753142711414"><a name="b11753142711414"></a><a name="b11753142711414"></a>false</strong> means the opposite.</p>
</td>
</tr>
</tbody>
</table>

## Options<a name="section3785619107"></a>

Describes the sensor data reporting frequency.

<a name="table121139504286"></a>
<table><thead align="left"><tr id="row12114150132817"><th class="cellrowborder" valign="top" width="13.94%" id="mcps1.1.4.1.1"><p id="p15114125010285"><a name="p15114125010285"></a><a name="p15114125010285"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="18.29%" id="mcps1.1.4.1.2"><p id="p131146502289"><a name="p131146502289"></a><a name="p131146502289"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="67.77%" id="mcps1.1.4.1.3"><p id="p19115950192816"><a name="p19115950192816"></a><a name="p19115950192816"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row141161750182819"><td class="cellrowborder" valign="top" width="13.94%" headers="mcps1.1.4.1.1 "><p id="p5121191616307"><a name="p5121191616307"></a><a name="p5121191616307"></a>interval</p>
</td>
<td class="cellrowborder" valign="top" width="18.29%" headers="mcps1.1.4.1.2 "><p id="p7116250102817"><a name="p7116250102817"></a><a name="p7116250102817"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="67.77%" headers="mcps1.1.4.1.3 "><p id="p51446114318"><a name="p51446114318"></a><a name="p51446114318"></a>Frequency at which a sensor reports data. The default value is 200,000,000 ns.</p>
</td>
</tr>
</tbody>
</table>

