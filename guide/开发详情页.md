# 开发详情页<a name="ZH-CN_TOPIC_0000001054727679"></a>

-   [detail.hml](#section275215487291)
-   [detail.css](#section2589154215301)
-   [detail.js](#section163410883117)

详情页以图表的形式展示一周内空气质量指标值。本页面由两部分组成：标题栏和图表栏；在图表栏，考虑显示效果，我们使用多个div替代chart组件来实现图表功能。

首先，添加一个根节点div，并设置flex-direction属性为column，使两栏纵向排列，代码结构如下：

```
<div class="container">
    <div class="header" onclick="backMain">
        <image class="back" src="common/ic_back.png"></image>
        <text class="title">
            历史记录
        </text>
    </div>
    <list class="chart-list">
    </list>
</div>
```

其中onclick="backMain"为返回主页事件，detail.js中的代码实现如下：

```
import router from '@system.router'

export default {
    backMain() {
        router.replace({
            //页面地址
            uri: 'pages/index/index',
            params: {
                //返回主页时带的参数
                selectedCityIndex: this.selectedCityIndex
            }
        });
    }
}
```

其次，在list中添加div组件来实现图表效果。

详情页完整代码如下：

## detail.hml<a name="section275215487291"></a>

```
<div class="container">
    <div class="header" onclick="backMain">
        <image class="back" src="common/ic_back.png"></image>
        <text class="title">
            历史记录
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
            this.location = '东莞';
        } else {
            this.location = '深圳';
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

