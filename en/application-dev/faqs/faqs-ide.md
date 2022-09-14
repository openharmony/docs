# FAQs About IDE Usage



## What Should Do If the Error Message "npm ERR! code SELF_SIGNED_CERT_IN_CHAIN" Is Displayed?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

1. Run **npm config set strict-ssl=false** on the DevEco Studio terminal.

2. Run the **npm install** on the DevEco Studio terminal.

## After Manual Updating of the DevEco Studio SDK, Error Message "Cannot find module 'xxx\ets\x.x.x.x\build-tools\ets-loader\node_modules\webpack\bin\webpack.js'" Is Displayed During HAP Building. What Should I Do?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

1. Run **npm install** in the **ets\x.x.x.x\build-tools\ets-loader** directory of the SDK.

2. Run **npm install** in the **js\x.x.x.x\build-tools\ace-loader** directory of the SDK. After the preceding steps are complete, perform HAP building again.
