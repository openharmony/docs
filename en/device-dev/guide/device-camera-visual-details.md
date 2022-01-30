# Building the Details Page<a name="EN-US_TOPIC_0000001054727679"></a>


The  **detail**  page displays the air quality data of a week in a chart. There are two parts on the page: title bar and chart bar. Considering the display effect of the chart bar, use multiple  **<div\>**  components instead of one  **<chart\>**  component.

Add a root  **<div\>**, set the  **flex-direction**  attribute to  **column**  to arrange the two bars vertically. The sample code is as follows:

```
<div class="container">
    <div class="header" onclick="backMain">
        <image class="back" src="common/ic_back.png"></image>
        <text class="title">
            History
        </text>
    </div>
    <list class="chart-list">
    </list>
</div>
```

In the preceding example,  **onclick="backMain"**  indicates that the application returns to the home page when the click event is triggered. The sample code for  **detail.js**  is as follows:

```
import router from '@system.router'

export default {
    backMain() {
        router.replace({
            // Home page URL
            uri: 'pages/index/index',
            params: {
                // Parameters to pass to the home page
                selectedCityIndex: this.selectedCityIndex
            }
        });
    }
}
```

Add  **<div\>**  components to the  **<list\>**  component to form a chart.

The complete sample code in the three files is as follows.

## detail.hml<a name="section275215487291"></a>

```
<div class="container">
    <div class="header" onclick="backMain">
        <image class="back" src="common/ic_back.png"></image>
        <text class="title">
            History
        </text>
    </div>
    <list class="chart-list">
        <list-item class="list-item-title">
            <text class="location">{{location}}
            </text>
        </list-item>
        <list-item class="list-item-chart">
            <div style="margin-top: 24px;width: 960px;height: 256px;">
                <div class="chart-wrapper" style="margin-left: 128px;">
                    <text class="gas-name">
                        CO
                    </text>
                    <div class="chart">
                        <div class="chart-item" style="height: 78px;background-color: #00ff00;"></div>
                        <div class="chart-item" style="height: 52px;background-color: #00ff00;"></div>
                        <div class="chart-item" style="height: 155px;background-color: #ff0000;"></div>
                        <div class="chart-item" style="height: 134px;background-color: #ff0000;"></div>
                        <div class="chart-item" style="height: 98px;background-color: #FF7500;"></div>
                        <div class="chart-item" style="height: 88px;background-color: #FF7500;"></div>
                        <div class="chart-item" style="height: 144px;background-color: #ff0000;"></div>
                    </div>
                    <div class="white-line"></div>
                    <div class="week">
                        <text class="day">
                            MON
                        </text>
                        <text class="day">
                            TUE
                        </text>
                        <text class="day">
                            WED
                        </text>
                        <text class="day">
                            THU
                        </text>
                        <text class="day">
                            FRI
                        </text>
                        <text class="day">
                            SAT
                        </text>
                        <text class="day">
                            SUN
                        </text>
                    </div>
                </div>
                <div class="chart-wrapper" style="margin-left: 88px;">
                    <text class="gas-name">
                        SO2
                    </text>
                    <div class="chart">
                        <div class="chart-item" style="height: 155px;background-color: #ff0000;"></div>
                        <div class="chart-item" style="height: 134px;background-color: #ff0000;"></div>
                        <div class="chart-item" style="height: 78px;background-color: #00ff00;"></div>
                        <div class="chart-item" style="height: 52px;background-color: #00ff00;"></div>
                        <div class="chart-item" style="height: 98px;background-color: #FF7500;"></div>
                        <div class="chart-item" style="height: 88px;background-color: #FF7500;"></div>
                        <div class="chart-item" style="height: 144px;background-color: #ff0000;"></div>
                    </div>
                    <div class="white-line"></div>
                    <div class="week">
                        <text class="day">
                            MON
                        </text>
                        <text class="day">
                            TUE
                        </text>
                        <text class="day">
                            WED
                        </text>
                        <text class="day">
                            THU
                        </text>
                        <text class="day">
                            FRI
                        </text>
                        <text class="day">
                            SAT
                        </text>
                        <text class="day">
                            SUN
                        </text>
                    </div>
                </div>
            </div>
        </list-item>
        <list-item class="list-item-chart">
            <div style="margin-top: 24px;width: 960px;height: 256px;">
                <div class="chart-wrapper" style="margin-left: 128px;">
                    <text class="gas-name">
                        PM10
                    </text>
                    <div class="chart">
                        <div class="chart-item" style="height: 88px;background-color: #FF7500;"></div>
                        <div class="chart-item" style="height: 144px;background-color: #ff0000;"></div>
                        <div class="chart-item" style="height: 78px;background-color: #00ff00;"></div>
                        <div class="chart-item" style="height: 52px;background-color: #00ff00;"></div>
                        <div class="chart-item" style="height: 155px;background-color: #ff0000;"></div>
                        <div class="chart-item" style="height: 134px;background-color: #ff0000;"></div>
                        <div class="chart-item" style="height: 98px;background-color: #FF7500;"></div>
                    </div>
                    <div class="white-line"></div>
                    <div class="week">
                        <text class="day">
                            MON
                        </text>
                        <text class="day">
                            TUE
                        </text>
                        <text class="day">
                            WED
                        </text>
                        <text class="day">
                            THU
                        </text>
                        <text class="day">
                            FRI
                        </text>
                        <text class="day">
                            SAT
                        </text>
                        <text class="day">
                            SUN
                        </text>
                    </div>
                </div>
                <div class="chart-wrapper" style="margin-left: 88px;">
                    <text class="gas-name">
                        PM2.5
                    </text>
                    <div class="chart">
                        <div class="chart-item" style="height: 98px;background-color: #FF7500;"></div>
                        <div class="chart-item" style="height: 88px;background-color: #FF7500;"></div>
                        <div class="chart-item" style="height: 78px;background-color: #00ff00;"></div>
                        <div class="chart-item" style="height: 52px;background-color: #00ff00;"></div>
                        <div class="chart-item" style="height: 155px;background-color: #ff0000;"></div>
                        <div class="chart-item" style="height: 134px;background-color: #ff0000;"></div>
                        <div class="chart-item" style="height: 144px;background-color: #ff0000;"></div>
                    </div>
                    <div class="white-line"></div>
                    <div class="week">
                        <text class="day">
                            MON
                        </text>
                        <text class="day">
                            TUE
                        </text>
                        <text class="day">
                            WED
                        </text>
                        <text class="day">
                            THU
                        </text>
                        <text class="day">
                            FRI
                        </text>
                        <text class="day">
                            SAT
                        </text>
                        <text class="day">
                            SUN
                        </text>
                    </div>
                </div>
            </div>
        </list-item>
        <list-item class="list-item-chart">
            <div style="margin-top: 24px;width: 960px;height: 256px;">
                <div class="chart-wrapper" style="margin-left: 128px;">
                    <text class="gas-name">
                        NO2
                    </text>
                    <div class="chart">
                        <div class="chart-item" style="height: 155px;background-color: #ff0000;"></div>
                        <div class="chart-item" style="height: 134px;background-color: #ff0000;"></div>
                        <div class="chart-item" style="height: 98px;background-color: #FF7500;"></div>
                        <div class="chart-item" style="height: 78px;background-color: #00ff00;"></div>
                        <div class="chart-item" style="height: 52px;background-color: #00ff00;"></div>
                        <div class="chart-item" style="height: 88px;background-color: #FF7500;"></div>
                        <div class="chart-item" style="height: 144px;background-color: #ff0000;"></div>
                    </div>
                    <div class="white-line"></div>
                    <div class="week">
                        <text class="day">
                            MON
                        </text>
                        <text class="day">
                            TUE
                        </text>
                        <text class="day">
                            WED
                        </text>
                        <text class="day">
                            THU
                        </text>
                        <text class="day">
                            FRI
                        </text>
                        <text class="day">
                            SAT
                        </text>
                        <text class="day">
                            SUN
                        </text>
                    </div>
                </div>
            </div>
        </list-item>
    </list>
</div>
```

## detail.css<a name="section2589154215301"></a>

```
.location {
    text-align: center;
    color: #ffffff;
    width: 960px;
    height: 52px;
    font-size: 40px;
}
.container {
    height: 480px;
    width: 960px;
    flex-direction: column;
}

.header {
    width: 960px;
    height: 72px;
}

.back {
    width: 36px;
    height: 36px;
    margin-left: 39px;
    margin-top: 23px;
}

.title {
    width: 296px;
    height: 40px;
    margin-top: 20px;
    margin-left: 21px;
    color: #e6e6e6;
}

.chart-list {
    width: 960px;
    height: 408px;
}

.list-item-title {
    width: 960px;
    height: 52px;
}

.list-item-chart {
    width: 960px;
    height: 280px;
}

.chart-wrapper {
    width: 308px;
    height: 256px;
    flex-direction: column;
}

.gas-name {
    width: 308px;
    height: 35px;
    text-align: left;
}

.chart {
    width: 308px;
    height: 155px;
    margin-top: 10px;
    justify-content: flex-start;
    align-items: flex-end;
}

.chart-item {
    width: 24px;
    margin-left: 18px;
    border-radius: 3px;
}

.white-line {
    width: 308px;
    height: 2px;
    background-color: #ffffff;
    margin-top: 22px;
}

.week {
    width: 308px;
    height: 17px;
    margin-top: 6px;
    border-color: #ffffff;
    border-radius: 2px;
    margin-top: 6px;
}

.day {
    width: 26px;
    height: 17px;
    font-size: 10px;
    margin-left: 16px;
    text-align: center;
}
```

## detail.js<a name="section163410883117"></a>

```
import router from '@system.router'

export default {
    data: {
        location: ''
    },
    onInit() {
        if (this.selectedCityIndex === 0) {
            this.location = 'Dongguan';
        } else {
            this.location = 'Shenzhen';
        }
    },
    backMain() {
        router.replace({
            uri: 'pages/index/index',
            params: {
                selectedCityIndex: this.selectedCityIndex
            }
        });
    }
}
```

