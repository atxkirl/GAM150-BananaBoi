/*!
@file Marcus.c
@author TODO
@course TODO
@section TODO
@tutorial TODO
@date TODO
@brief This file contains functions of game init, update, exit
*//*______________________________________________________________________*/

#include <stdio.h>
#include "cprocessing.h"
#include "Helpers.h"
#include "SceneManager.h"
#include "Colors.h"
#include "SystemManager.h"

#define BUTTON_WIDTH 60.f
#define BUTTON_HEIGHT 30.f

void MarcusUI_render();

void Marcus_OnCollision(Collider* left, Collider* right)
{
    //me, other
    if (strcmp(((GameObject*)right->obj)->tag, "Click") == 0)
    {
        if (strcmp(((GameObject*)left->obj)->tag,"editor") == 0)
            SceneManager_ChangeSceneByName("editor");
        else if (strcmp(((GameObject*)left->obj)->tag, "levelone") == 0)
            SceneManager_ChangeSceneByName("levelone");
    }
    return;
}

void Marcus_init(void)
{
    SM_SystemsInit();

    //RM_AddComponent(g);
    GameObject* button = GOM_Create(RECTANGLE);
    Renderer* r = RM_AddComponent(button);
    button->scale = CP_Vector_Set(BUTTON_WIDTH, BUTTON_HEIGHT);
    button->position = CP_Vector_Set(80.0f, 25.0f);
    button->tag = "editor";
    button->type = RECTANGLE;
    //r->color = CP_Color_Create(255, 0, 0, 50);
    r->renderPriority = PRI_UI;
    r->text = "Editor";
    CLM_Set(CLM_AddComponent(button), COL_BOX, Marcus_OnCollision);

    button = GOM_Create(RECTANGLE);
    r = RM_AddComponent(button);
    button->scale = CP_Vector_Set(BUTTON_WIDTH, BUTTON_HEIGHT);
    button->position = CP_Vector_Set(80.0f, 75.0f);
    button->tag = "levelone";
    button->type = RECTANGLE;
    //r->color = CP_Color_Create(255, 0, 0, 50);
    r->renderPriority = PRI_UI;
    r->text = "One";
    CLM_Set(CLM_AddComponent(button), COL_BOX, Marcus_OnCollision);
}

void Marcus_update(void)
{
    SM_SystemsPreUpdate();
    GameObject* clickPoint = NULL;
    if (CP_Input_MouseTriggered(MOUSE_BUTTON_1))
    {
        //Creates a point obj to test collision against button
        clickPoint = GOM_CreateTemp(EMPTY);
        clickPoint->position = CP_Vector_Set(CP_Input_GetMouseX(), CP_Input_GetMouseY());
        clickPoint->isEnabled = 0;
        clickPoint->tag = "Click";
        CLM_Set(CLM_AddComponent(clickPoint), COL_POINT, NULL);
    }

    SM_SystemsUpdate();

    //MarcusUI_render();
    SM_SystemsLateUpdate();
}

void Marcus_exit(void)
{
    SM_SystemsExit();
}

void Marcus_sceneInit(FunctionPtr* init, FunctionPtr* update, FunctionPtr* exit)
{
    *init = Marcus_init;
    *update = Marcus_update;
    *exit = Marcus_exit;
}

void MarcusUI_render()
{
    CP_Settings_Fill(COLOR_WHITE); // r, g, b, a
    CP_Graphics_DrawRect(50.f, 10.f, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Settings_Fill(COLOR_BLACK); // r, g, b, a
    CP_Font_DrawText("Editor", 55, 30);

    CP_Settings_Fill(COLOR_WHITE); // r, g, b, a
    CP_Graphics_DrawRect(50.f, 60.f, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Settings_Fill(COLOR_BLACK); // r, g, b, a
    CP_Font_DrawText("One", 55, 80);
}