# Building a Food Data Model


On the created page, we use various items to describe food, such as food names, calories, proteins, fats, carbohydrates, and vitamin C. This form of coding is impractical in actual development. Therefore, you need to create food data models to store and manage data in a unified manner.


![en-us_image_0000001267767897](figures/en-us_image_0000001267767897.png)


1. Create a folder named model and create a file named FoodData.ets therein.
   
![en-us_image_0000001223127760](figures/en-us_image_0000001223127760.png)
   
2. Define a food data storage model, FoodData, and an enum variable, Category. The FoodData class contains the food ID, name, category, image, calories, protein, fat, carbohydrates, and vitamin C attributes.
   The ArkTS programming language is an extension of the TS language and also supports the TS syntax.


   ```
   enum Category  {
     Fruit,
     Vegetable,
     Nut,
     Seafood,
     Dessert
   }

   let NextId = 0;
   class FoodData {
     id: string;
     name: string;
     image: Resource;
     category: Category;
     calories: number;
     protein: number;
     fat: number;
     carbohydrates: number;
     vitaminC: number;

     constructor(name: string, image: Resource, category: Category, calories: number, protein: number, fat: number, carbohydrates: number, vitaminC: number) {
       this.id = `${ NextId++ }`;
       this.name = name;
       this.image = image;
       this.category = category;
       this.calories = calories;
       this.protein = protein;
       this.fat = fat;
       this.carbohydrates = carbohydrates;
       this.vitaminC = vitaminC;
     }
   }
   ```

3. Store food image resources in the resources > base > media directory. Use food names as the image names.

4. Create food resource data. Create FoodDataModels.ets in the model folder and declare a food composition array, FoodComposition on the page.
   In this example, you can customize more data resources when needed. Use LazyForEach to load data if a large amount of food data is involved. 

5. Create the initializeOnStartUp method to initialize the FoodData array. Export the FoodData class from FoodData.ets, and import FoodData and Category in FoodDataModels.ets.

   ```
   // FoodData.ets
   export enum Category {
    ......
   }
   export class FoodData {
     ......
   }
   // FoodDataModels.ets
   import { Category, FoodData } from './FoodData'

   export function initializeOnStartup(): Array<FoodData> {
     let FoodDataArray: Array<FoodData> = []
     FoodComposition.forEach(item => {
       FoodDataArray.push(new FoodData(item.name, item.image, item.category, item.calories, item.protein, item.fat, item.carbohydrates, item.vitaminC ));
     })
     return FoodDataArray;
   }
   ```


The data resources for the diet application are now ready. You can continue to create a food category list by loading the data.
