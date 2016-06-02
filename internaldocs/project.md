# Project

this documents project save structure.

the current format version is 0.

## File structure

- ProjectName/

  - Graphic/
  
    - Data/
    
      - GraphicResourceName.png
      
    - GraphicResourceName.json
    
  - Audio/
  
    - (not implemented)
    
  - EntityType/
  
    - ETypeName.json
    
  - Scene/
  
    - SceneName.json
    
  - Function/
  
    - FunctionName.json
    
  - ResourceIndex.json
  
  - ProjectName.json
  
## Project file

```json
{
  "projectName": "<project name>",
  "projectID": "<project ID>",
  "lastSaveVersionType": <versionType>,
  "lastSaveVersion": "<version>",
  "formatVersion": <formatVersion>,
  "saveTime": <saveTimeAsUNIXTimestamp>
}
```