#include <string.h>
#include "../CProcessing/inc/cprocessing.h"

typedef struct FileObj
{
	int iPosX;
	int iPosY;
	int iType;
	int iDir;
	char* cTag;
} FileObj;

typedef struct StoreMap
{
	FileObj** fObjList;
	int iSize;
} Map;

Map* new_Map();

void ReadLevelFromFile(char* cFileName, Map* mMap);
void ReadObjectivesFromFile(char* cFileName, char** cOutputObjectives);
void ReadControlsFromFile(char* cFileName, char* cText);
void WriteToFile(char* cFileName, char** cToAdd, int iSize); 
void WriteControlsToFile(char* cFileName, char* cToAdd, int iSize);