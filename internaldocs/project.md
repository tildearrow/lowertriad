# Project

this documents project save structure.

the current format version is 0.

## File structure

- ProjectName/

  - Graphic/
  
    - Data/
    
      - GraphicResourceName.png
      
      - GraphicResourceName.bin
      
    - GraphicResourceName.json
    
  - Audio/
  
    - Sound/
    
      - AudioName.wav
  
    - AudioName.json
    
  - EntityType/
  
    - Code/
    
      - ETypeName/
      
	- EventX.cpp
	
	- EventX.cpp
	
    - ETypeName.json
    
  - Scene/
  
    - SceneName.json
    
  - Function/
  
    - FunctionName.json
    
  - ResourceIndex.json
  
  - Project.json
  
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

## Resource index file

```json
{
  "graphicsDirectory": "Graphic",
  "graphics": [
    "graphicFile1.json",
    "graphicFile2.json",
    "graphicFile3.json"
  ],
  "audioDirectory": "Audio",
  "audio": [
    "audioFile1.json",
    "audioFile2.json",
    "audioFile3.json"
  ],
  "entityTypesDirectory": "EntityType",
  "entityTypes": [
    "ETFile1.json",
    "ETFile2.json",
    "ETFile3.json"
  ],
  "scenesDirectory": "Scene",
  "scenes": [
    "sceneFile1.json",
    "sceneFile2.json",
    "sceneFile3.json"
  ],
  "functionsDirectory": "Function",
  "functions": [
    "functionFile1.json",
    "functionFile2.json",
    "functionFile3.json"
  ]
}
```

## Graphic file

```json
{
  "resourceName": "<resource name>",
  "width": width,
  "height": height,
  "frames": frames,
  "isBackground": isback,
  "colMask": {
    "type": "<col mask type>",
    "colMaskCoords": {
      "x": x,
      "y": y,
      "w": w,
      "h": h
    },
    "threshold": threshold,
    "multipleColMask": 0,
    "colMaskFile": "<col mask file>"
  },
  "origin": {
    "x": x,
    "y": y
  },
  "graphicFile": "<graphic file>"
}
```

<col mask type> can be: `box`, `round`, `diamond` or `mask`.

### Mask file structure

```
     0   1   2   3   4   5   6   7   8   9   a   b   c   d   e   f
   +---------------------------------------------------------------+
00 |  mask  width  |  mask height  |  mask frames  | 0 | 0 | 0 | 0 |
   +---------------------------------------------------------------+
10 |             mask data (width*height*frames bytes)             |
   +---------------------------------------------------------------+
```

mask data resembles a monochrome image, where the value of every pixel means maximum threshold for a collision to happen.

## Entity type file

```json
{
  "resourceName": "<resource name>",
  "defaultGraphic": "<graphic resource name>",
  "defaultSubGraphic": index,
  "parent": index,
  "category": index,
  "events": [
    {
      "id": eventid,
      "code": "codefile"
    },
    {
      "id": eventid,
      "code": "codefile"
    }
  ]
}
```

## Scene file

```json
{
  "resourceName": "<resource name>",
  "width": w,
  "height": h,
  "grid": {
    "width": w,
    "height": h,
    "angle": a
  },
  "initCode": "<init code file, or null>",
  "finishCode": "<finish code file, or null>",
  "freeze": freeze,
  "clearColor": color,
  "backgrounds": [
    {
      "graphic": "<resource name>",
      "dimensions": {
	"x": x,
	"y": y,
	"xscale": xs,
	"yscale": ys,
	"rotate": r
      },
      "alpha": a,
      "tileX": 1,
      "tileY": 1,
      "scroll": {
        "x": x,
        "y": y
      }
    },
    {
      "graphic": "<resource name>",
      "dimensions": {
	"x": x,
	"y": y,
	"xscale": xs,
	"yscale": ys,
	"rotate": r
      },
      "alpha": a,
      "tileX": 1,
      "tileY": 1,
      "scroll": {
        "x": x,
        "y": y
      }
    }
  ],
  "viewports": [
    {
      "name": "<name>",
      "view": {
	"x": x,
	"y": y,
	"w": w,
	"h": h,
	"xscale": xscale,
	"yscale": yscale,
	"rotate": r
      },
      "port": {
	"x": x,
	"y": y,
	"w": w,
	"h": h,
	"xscale": xscale,
	"yscale": yscale,
	"rotate": r,
	"alpha": a
      }
    },
    {
      "name": "<name>",
      "view": {
	"x": x,
	"y": y,
	"w": w,
	"h": h,
	"xscale": xscale,
	"yscale": yscale,
	"rotate": r
      },
      "port": {
	"x": x,
	"y": y,
	"w": w,
	"h": h,
	"xscale": xscale,
	"yscale": yscale,
	"rotate": r,
	"alpha": a
      }
    }
  ],
  "layers": [
    {
      "name": "<name>",
      "entities": [
	{
	  "type": "<entity type>",
	  "x": x,
	  "y": y,
	  "xscale": xs,
	  "yscale": ys,
	  "rotate": r,
	  "colorblend": blend,
	  "alpha": a,
	  "initCode": "<init code file, or null>"
	},
	{
	  "type": "<entity type>",
	  "x": x,
	  "y": y,
	  "xscale": xs,
	  "yscale": ys,
	  "rotate": r,
	  "colorblend": blend,
	  "alpha": a,
	  "initCode": "<init code file, or null>"
	}
      ]
    }
  ]
}
```