# Debugging Intents
## Overview
The InsightIntent framework provides an intent debugging tool for debugging intents after they access the framework. This tool can be used to query and execute intents.

## Constraints
Intent debugging is supported only on mobile phones, and the corresponding API version must be 20 or later.

## Function Access

1. Enable the intent debugging capability.
     1. Tap **Settings** on your device.
     2. Choose **System** from the menu.
     3. Choose **Developer options**.
     4. Choose **InsightIntent debugging** and turn on the function switch.
2. View intents. On the **InsightIntent debugging** page, tap **View all InsightIntents on device**.
   You can view all registered intents on the current page.
3. Debug intents.
     1. Set intent parameters.
     2. Tap **Execute InsightIntent**.
        If the intent implemented is correct, the execution is successful. The execution results of different types of intents are as follows:

      | Decorator| Execution Mode| Intent Call Result|
      | --------- | --------- | -------- |
      | [@InsightIntentLink](../../application-dev/reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentlink) | UI_ABILITY_FOREGROUND | The page is redirected. A semi-modal window appears in the lower part to display the intent call return result.|
      | [@InsightIntentPage](../../application-dev/reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentpage) | UI_ABILITY_FOREGROUND | The page is redirected. A semi-modal window appears in the lower part to display the intent call return result.|
      | [@InsightIntentEntry](../../application-dev/reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry) | UI_ABILITY_FOREGROUND | The page is redirected. A semi-modal window appears in the lower part to display the intent call return result.|
      | [@InsightIntentEntry](../../application-dev/reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry) | UI_ABILITY_BACKGROUND | A semi-modal window appears in the lower part to display the intent call return result.|
      | [@InsightIntentEntry](../../application-dev/reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry)| UI_EXTENSION_ABILITY | A semi-modal window appears in the lower part to display the embedded [UIExtensionAbility](../../application-dev/reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#uiextensionability) page.|
      | <!--DelRow--> [@InsightIntentEntry](../../application-dev/reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry) | SERVICE_EXTENSION_ABILITY | A semi-modal window appears in the lower part to display the intent call return result.|
      | [@InsightIntentFunctionMethod](../../application-dev/reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentfunctionmethod) | UI_ABILITY_BACKGROUND | A semi-modal window appears in the lower part to display the intent call return result.|
      | [@InsightIntentForm](../../application-dev/reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentform) | - | An embedded widget page. You can tap the widget to go to the application.|
