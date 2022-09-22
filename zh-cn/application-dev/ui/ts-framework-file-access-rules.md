# 文件访问规则
应用代码中文件访问方法主要有下面两种：

- **相对路径**：使用相对路径引用代码文件，以"../"访问上一级目录，以"./"访问当前目录，也可以省略不写

- **绝对路径**：使用当前模块根路径引用代码文件，比如：common/utils/utils。




## 示例
```
MainAbility
├─ app.ets
├─ common
│    └─ utils
│           └─ utils.ets
└─ pages
       └─ index.ets
```
>注：公共代码文件推荐新建一个**common**目录存放

如上所示，将utils放在common中,示例中index.ets访问utils.ets文件
```ts
// index.ets
import { FoodData, FoodList } from "../common/utils/utils";

@Entry
@Component
struct FoodCategoryList {  
  private foodItems: FoodData[] = [    
    new FoodData("Tomato"),    
    new FoodData("Strawberry"),    
    new FoodData("Cucumber")  
  ]  
  build() {    
    Column() {      
      FoodList({ foodItems: this.foodItems })    
    }  
  }
}
```

被导入文件utils.ets：

```ts
//common/utils/utils.ets
export class FoodData {  
  name: string;  
  constructor(name: string) {    
    this.name = name;  
  }
}

@Component
export struct FoodList {  
  private foodItems: FoodData[]

  build() {    
    Column() {      
      Flex({justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center}) {        
        Text('Food List')          
          .fontSize(20)      
      }      
      .width(200)      
      .height(56)      
      .backgroundColor('#FFf1f3f5')      
      List() {        
        ForEach(this.foodItems, item => {          
          ListItem() {            
            Text(item.name)              
              .fontSize(14)          
          }        
        }, item => item.toString())      
      }    
    }  
  }
}
```
