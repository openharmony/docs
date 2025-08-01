# Developing Intents Using Decorators
## When to Use
Starting from API version 20, you can develop intents using decorators, allowing you to quickly integrate existing features into system entry points. The table below lists some typical scenarios.

| Intent Call Scenario| Common Intent Example| Intent Development Method|
| --- | --- | --- |
| Launching an application| - Play music.<br>- Open a shopping application to a product details page.|  - Create new intent logic using [@InsightIntentEntry](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry), and bind the intent to a UIAbility or UIExtensionAbility.<br>- Convert a URI into an intent using [@InsightIntentLink](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentlink).<br>- Convert a page route to an intent using [@InsightIntentPage](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentpage).|
| Querying or updating information| - Query the weather.<br>- Modify application settings or update an application.| - Convert a function call to a system intent using [@InsightIntentFunctionMethod](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentfunctionmethod).<br>- Create new intent logic using [@InsightIntentEntry](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry), and bind the intent to the background execution mode of a UIAbility or a ServiceExtensionAbility.|
| Adding service widgets| - Add a weather widget.| - Develop an intent using [@InsightIntentForm](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentform).|

## Working Principles

| Function| Intent Development| Intent Execution|
| --- | --- | --- |
| Developing intents using [@InsightIntentEntry](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry)| 1. Add a new intent execution file. If the execution file is not imported by other files, configure its path through the **insightIntentsSrcEntry** field in the **insight_intent.json** file to include it in compilation.<br> 2. Use decorators to define the application component to be bound to the intent and the intent execution mode.| The system entry point matches the intent and triggers the startup of the application component and intent execution according to the intent execution mode.|
| Developing intents using [@InsightIntentLink](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentlink)| Define an intent for link redirection, which can be an existing or a new URI.| The system entry point matches the intent, transfers a URI, and triggers intent execution via [openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#openlink12). For parameter processing during intent execution, see the **paramCategory** description in [LinkIntentParamMapping](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#linkintentparammapping).|
| Developing intents using [@InsightIntentPage](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentpage)| Define a page redirection intent, and configure the corresponding UIAbility, [page route](../ui/arkts-routing.md) path, and [Navigation](../ui/arkts-navigation-navigation.md) path for the intent.| 1. The system entry point uses **startAbility** to start the UIAbility bound to the intent. If the intent is not bound to a UIAbility, it starts the UIAbility corresponding to the [mainElement](../quick-start/module-configuration-file.md#tags-in-the-configuration-file) of the module where the intent is located.<br>2. During intent execution, if the application is not started, it jumps to the page corresponding to the intent after loading the home page of the UIAbility; if the application is already started, it jumps to the page corresponding to the intent from the current page.<br>3. Parameters are passed to the target page during intent execution.<br>4. If the **navigationId** or **navDestinationName** field fails to match, the system falls back to page redirection corresponding to the **pagePath** field.|
| Developing intents using [@InsightIntentFunctionMethod](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentfunctionmethod)| Define an intent for a static method, which can be an existing or a new method.| The system entry point uses [Call](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#background-communication-capability) to start the UIAbility corresponding to the [mainElement](../quick-start/module-configuration-file.md#tags-in-the-configuration-file) of the module where the intent is located.|
| Developing intents using [@InsightIntentForm](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentform)| Define an intent for a widget, which can be an existing or a new widget.| The system entry point creates an intent widget using the FormComponent.|

## How to Develop

This section uses the development of standard intents and custom intents with @InsightIntentEntry as an example. Developing standard and custom intents with other decorators is similar to @InsightIntentEntry. You can refer to the API documentation for developing other types of intents.

### Developing Standard Intents with Intent Decorators

The following uses the standard intent [ViewLogistics](./insight-intent-access-specifications.md#viewing-logistics) as an example to describe how to develop a standard intent with the @InsightIntentEntry decorator.

1. If a new intent execution file is added and not referenced by other entry files, declare the executor path via the **insightIntentsSrcEntry** field in the **insight_intent.json** file to include it in compilation.

    ```json
    {
      "insightIntentsSrcEntry": [
        {
          "srcEntry": "./ets/insightintents/ViewLogisticsImpl.ets"
        }
      ]
    }
    ```

2. Implement the intent executor.

    When developing a standard intent, you do not need to define the large language model description, intent parameters, or intent execution results. Standard intents are matched from the [Appendix: Standard Intent Access Specifications](insight-intent-access-specifications.md) based on the **schema** and **intentVersion** fields. The intent executor must inherit from the **InsightIntentEntryExector\<T>** class and implement the **onExecute()** API.
    ```ts
    import { InsightIntentEntryExecutor, insightIntent, InsightIntentEntry } from '@kit.AbilityKit';

    class ViewLogisticsResultDef {
      msg?: string = '';
    }

    @InsightIntentEntry({
      intentName: 'ViewLogistics',
      domain: 'LocalDomain',
      intentVersion: '1.0.1',
      displayName: 'Query Logistics',
      displayDescription: 'Query logistics with tracking number',
      schema: 'ViewLogistics',
      icon: $r('app.media.viewLogistics'), // $r indicates a local icon, which must be defined in the resource catalog.
      abilityName: 'EntryAbility',
      executeMode: [insightIntent.ExecuteMode.UI_ABILITY_BACKGROUND],
    })
    export default class ViewLogisticsImpl extends InsightIntentEntryExecutor<ViewLogisticsResultDef> {
      trackingNo?: string = '';
      entityId?: string = '';

      onExecute(): Promise<insightIntent.IntentResult<ViewLogisticsResultDef>> {
        // Execute logistics query logic.
        let result: insightIntent.IntentResult<ViewLogisticsResultDef> = {
          code: 0,
          result: {
            msg: 'the logistics is being delivered'
          }
        }
        return Promise.resolve(result);
      }
    }
    ```

The intent execution process is as follows:
1. The system entry point responds to the user request "Query logistics with tracking number 12345", matches the "ViewLogistics" intent of the application, and triggers intent execution through the InsightIntent framework.
2. The intent is bound to an EntryAbility and configured with the execution mode **insightIntent.ExecuteMode.UI_ABILITY_BACKGROUND**. During intent execution, the bound EntryAbility is started via [Call](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#background-communication-capability). The **trackingNo** property of the **ViewLogisticsImpl** class is assigned, and the **onExecute()** API is executed to return the intent execution result to the system entry point through the InsightIntent framework.
3. The system entry point converts the intent execution result into natural language and presents it to the user.

### Developing Custom Intents with Intent Decorators

The following uses the development of a custom intent "Play Music" as an example. You are required to define the large language model description, intent search keywords, intent parameters, and intent execution results for the intent.

1. If a new intent execution file is added and not referenced by other entry files, declare the executor path via the **insightIntentsSrcEntry** field in the **insight_intent.json** file to include it in compilation.

    ```json
    {
      "insightIntentsSrcEntry": [
        {
          "srcEntry": "./ets/insightintents/PlayMusicImpl.ets"
        }
      ]
    }
    ```

2. Implement the intent executor.

    When developing custom intents, you are required to define the large language model description, intent search keywords, intent parameters, and intent execution results. The intent executor must inherit from the **InsightIntentEntryExector\<T>** class and implement the **onExecute()** API.

    ```ts
    // Implementation of the insightIntentsSrcEntry field in the insight_intent.json file.
    import { InsightIntentEntryExecutor, insightIntent, InsightIntentEntity, InsightIntentEntry } from '@kit.AbilityKit';

    // Data format definition of the intent execution result.
    class PlayMusicResultDef {
      msg?: string = '';
    }

    // Intent definition.
    @InsightIntentEntry({
      intentName: 'PlayMusic',
      domain: 'MusicDomain',
      intentVersion: '1.0.1',
      displayName: 'Play Music',
      displayDescription: 'Intent to play music',
      icon: $r('app.media.playMusic'), // $r indicates a local icon, which must be defined in the resource catalog.
      llmDescription: 'Supports passing song names to play music',
      keywords: ['music playback', 'play music', 'PlayMusic'],
      abilityName: 'EntryAbility',
      executeMode: [insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND],
      parameters: {
        "type": "object",
        "description": "A schema for describing songs and their artists",
        "properties": {
          "songName": {
            "type": "string",
            "description": "The name of the song",
            "minLength": 1
          },
          "singer": {
            "type": "string",
            "description": "The name of the singer",
            "minLength": 1
          }
        },
        "required": ["songName"]
      }
    })
    export class PlayMusicImpl extends InsightIntentEntryExecutor<PlayMusicResultDef> {
      songName: string = '';
      singer?: string = '';

      onExecute(): Promise<insightIntent.IntentResult<PlayMusicResultDef>> {
        // Execute the music playback logic.
        let result: insightIntent.IntentResult<PlayMusicResultDef> = {
          code: 123,
          result: {
            msg: 'play music succeed'
          }
        }
        return Promise.resolve(result);
      }
    }
    ```

The intent execution process is as follows:
1. The system entry point responds to the user request "Play song B of singer A", matches the "PlayMusic" intent of the application, and triggers intent execution through the InsightIntent framework.
2. The intent is bound to an EntryAbility and configured with the execution mode **insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND**. During intent execution, the bound EntryAbility is started via **startAbility**. The **songName** and **singer** properties of the **PlayMusicImpl** class are assigned, and the **onExecute()** API is executed to return the intent execution result to the system entry point through the InsightIntent framework.
3. The system entry point converts the intent execution result into natural language and presents it to the user.

### (Optional) Passing Complex Parameters by Developing Intent Entities

By default, data passed from the system entry point to the application is of basic types. For more complex data—such as singer information (including name, nationality, and more) when playing music—you need object types. These are defined using the [@InsightIntentEntity](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententity) decorator and are known as intent entities.

Consider a music playback scenario: A user tells the voice assistant Celia the name and singer information of the desired song, and Celia launches the corresponding music screen to play the song based on the information.

To implement this, you can define singer information as an intent entity and develop the intent entity. The procedure is as follows:

1. Define an intent entity.

    Define singer information (including name, country, city, and more) as a class and use the @InsightIntentEntity decorator to define this class as an intent entity. The **parameters** property of the decorator lists the class's data members, data formats, and the required status of each member.

    ```ts
    import { insightIntent, InsightIntentEntity } from '@kit.AbilityKit';

    @InsightIntentEntity({
      entityCategory: 'artist entity category',
      parameters: {
        '$id': '/schemas/ArtistClassDef',
        'type': 'object',
        'description': 'Information about the artist',
        'properties': {
          'country': {
            'type': 'string',
            'description': 'The artist\'s country of origin',
            'default': 'zh'
          },
          'city': {
            'type': 'string',
            'description': 'The artist\'s city of origin'
          },
          'name': {
            'type': 'string',
            'description': 'The name of the artist',
            'minLength': 1
          }
        },
        // name is a mandatory parameter.
        'required': ['name']
      }
    })
    export class ArtistClassDef implements insightIntent.IntentEntity {
      entityId: string = '0x11';
      country?: string = '';
      city?: string = '';
      name: string = '';
    }
    ```

2. Use the intent entity. Add an intent decorated with [@InsightIntentEntry](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry) that uses the song name and singer information (the **ArtistClassDef** intent entity) as input parameters for music playback.

    ```ts
    import { insightIntent, InsightIntentEntry, InsightIntentEntryExecutor, InsightIntentEntity } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const LOG_TAG: string = 'testTag-EntryIntent';

    @InsightIntentEntity({
      entityCategory: 'artist entity category',
      // The ArtistClassDef intent entity information has been described in parameters of the @InsightIntentEntry decorator. Therefore, parameters can be left unspecified.
    })
    export class ArtistClassDef implements insightIntent.IntentEntity {
      entityId: string = '0x11';
      country?: string = '';
      city?: string = '';
      name: string = '';
    }

    // Use the @InsightIntentEntry decorator to define an intent.
    @InsightIntentEntry({
      intentName: 'PlayMusic',
      domain: 'MusicDomain',
      intentVersion: '1.0.1',
      displayName: 'Play Music',
      displayDescription: 'Intent to play music',
      icon: $r('app.media.app_icon'), // $r indicates a local icon, which must be defined in the resource catalog.
      llmDescription: 'Supports passing song names to play music',
      keywords: ['music playback', 'play music', 'PlayMusic'],
      abilityName: 'EntryAbility',
      executeMode: [insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND],
      parameters: {
        'schema': 'http://json-schema.org/draft-07/schema#',
        'type': 'object',
        'title': 'Song Schema',
        'description': 'A schema for describing songs and their artists',
        'properties': {
          'songName': {
            'type': 'string',
            'description': 'The name of the song',
            'minLength': 1
          },
          'artist': {
            'type': 'object',
            'description': 'Information about the artist',
            'properties': {
              'country': {
                'type': 'string',
                'description': 'The artist\'s country of origin',
                'default': 'zh'
              },
              'city': {
                'type': 'string',
                'description': 'The artist\'s city of origin'
              },
              'name': {
                'type': 'string',
                'description': 'The name of the artist',
                'minLength': 1
              }
            },
            'required': ['name']
          }
        },
        'required': ['songName']
      }
    })
    export default class PlayMusicDemo extends InsightIntentEntryExecutor<string> {
      songName: string = '';
      // Use the intent entity.
      artist?: ArtistClassDef;

      onExecute(): Promise<insightIntent.IntentResult<string>> {
        hilog.info(0x0000, LOG_TAG, 'PlayMusicDemo executeMode %{public}s', JSON.stringify(this.executeMode));
        hilog.info(0x0000, LOG_TAG, 'PlayMusicDemo artist %{public}s', JSON.stringify(this.artist));
        let storage = new LocalStorage();
        storage.setOrCreate('songName', this.songName);
        storage.setOrCreate('artist', this.artist);
        // Open the PlayMusicPage page in different ways based on the executeMode parameter.
        if (this.executeMode == insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND) {
          this.windowStage?.loadContent('pages/PlayMusicPage', storage);
        } else if (this.executeMode == insightIntent.ExecuteMode.UI_EXTENSION_ABILITY) {
          this.uiExtensionSession?.loadContent('pages/PlayMusicPage', storage);
        }
        // Define the intent execution result.
        let result: insightIntent.IntentResult<string> = {
          code: 123,
          result: 'execute success'
        }
        hilog.info(0x0000, LOG_TAG, 'PlayMusicDemo return %{public}s', JSON.stringify(result));
        return Promise.resolve(result);
      }
    }
    ```
