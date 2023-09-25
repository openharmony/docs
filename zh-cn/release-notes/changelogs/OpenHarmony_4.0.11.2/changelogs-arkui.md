# arkui子系统ChangeLog

## cl.arkui.1 PanelHeight枚举的WRAP_CONTENT值从0变更为'wrapContent'

**变更影响**

变更前，开发者设置customHeight(0)和customHeight(PanelHeight.WRAP_CONTENT)都会自适应内容高度。</br>
变更后，开发者设置customHeight(0)将内容高度设置为0，customHeight(PanelHeight.WRAP_CONTENT)自适应内容高度。

**关键的接口变更**

PanelHeight枚举的WRAP_CONTENT值从0变为'wrapContent'，接口行为变更对开发者无影响。

## cl.arkui.2 aspectRatio设置非法值和undefined时，默认值从1.0变为null。

**变更影响**

变更前，开发者设置负数和undefined，aspectRatio = 1.0

变更后，开发者设置负数和undefined，aspectRatio为null。例如，Row只设置宽度且没有子组件，aspectRatio不设置值或者设置成负数时，此时Row高度为0。

## cl.arkui.3 defaultFocus设置为true由不生效变更为生效。

**变更影响**
4.0.9.1版本之前，开发者defaultFocus设置为true不生效

4.0.9.1版本及之后，开发者defaultFocus设置为true生效

## cl.arkui.4 焦点tabIndex走焦方式由非循环走焦更改为循环走焦。

**变更影响**
4.0.10.2版本之前，焦点tabIndex走焦方式为非循环走焦

4.0.10.2版本及之后，焦点tabIndex走焦方式为循环走焦

## cl.arkui.5 TextInput设置margin属性时，TextInput的Constraint不再减去Margin的值。

**变更影响**

4.0.11.2版本之前，TextInput设置margin时，TextInput的Constraint会减去所设置margin的值。

4.0.11.2版本及之后，TextInput设置margin时，TextInput的Constraint不会减去所设置margin的值。