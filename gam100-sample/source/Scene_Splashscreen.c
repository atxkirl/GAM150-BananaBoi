/*
@copyright	All content � 2021 DigiPen Institute of Technology Singapore, all rights reserved.
@file	    Scene_Splashscreen.c
@author	    Adrian Tan (t.xingkhiangadrian)
@course	    CSD1400 Software Engineering Project 1
@Team	    BananaBoi
@date	    14/11/2021
@brief	    Scene that displays the DigiPen logo, as well as the team logo when the game is first 
            launched.
*//*________________________________________________________________________________________*/

#include <stdio.h>
#include "cprocessing.h"
#include "SceneManager.h"
#include "SystemManager.h"
#include "Colors.h"
#include "SoundManager.h"

static float logoFadeSpeed = 250.f;
static float logoWaitTimer = 2.f;
static float elapsedTime = 0.f;

static int digipenState;
static int bananaState;

// Digipen Logo
static GameObject* digipenObj;
static Renderer* digipenRenderer;
// Team Logo
static GameObject* bananaObj;
static Renderer* bananaRenderer;

/// <summary>
/// Update loop for the DigiPen logo.
/// </summary>
void update_digipen(void)
{
    if (digipenState == 3)
        return;

    if (digipenState == 1)
    {
        elapsedTime += CP_System_GetDt();
        if (elapsedTime > logoWaitTimer)
        {
            digipenState = 2;
        }
        else
        {
            return;
        }
    }

    if(digipenState != 1)
        digipenRenderer->color.a += (char)(CP_System_GetDt() * logoFadeSpeed); // Slowly increment alpha.

    if (digipenRenderer->color.a > 250 && digipenState == 0)
    {
        logoFadeSpeed *= -1;
        digipenState = 1;
    }
    if (digipenRenderer->color.a < 5 && digipenState == 2)
    {
        digipenRenderer->color.a = 0;
        digipenState = 3;

        elapsedTime = 0.f;
        logoFadeSpeed *= -1;
    }
}
/// <summary>
/// Update loop for the BananaBoi logo.
/// </summary>
void update_bananaboi(void)
{
    if (bananaState == 3)
        return;

    if (bananaState == 1)
    {
        elapsedTime += CP_System_GetDt();
        if (elapsedTime > logoWaitTimer)
        {
            bananaState = 2;
        }
        else
        {
            return;
        }
    }

    if (bananaState != 1)
        bananaRenderer->color.a += (char)(CP_System_GetDt() * logoFadeSpeed); // Slowly increment alpha.

    if (bananaRenderer->color.a > 250 && bananaState == 0)
    {
        logoFadeSpeed *= -1;
        bananaState = 1;
    }
    if (bananaRenderer->color.a < 5 && bananaState == 2)
    {
        bananaRenderer->color.a = 0;
        bananaState = 3;

        elapsedTime = 0.f;
        logoFadeSpeed *= -1;
    }
}

/// <summary>
/// Initializes scene variables.
/// </summary>
void splashscreen_init(void)
{
    SM_SystemsInit();
    float screenWidth, screenHeight;
    RM_GetRenderSize(&screenWidth, &screenHeight, PRI_UI);

    GameObject* bg = GOM_Create2(RECTANGLE, CP_Vector_Set(0.5f * screenWidth, 0.5f * screenHeight), 0.0f, CP_Vector_Set(screenWidth, screenHeight));
    Renderer* bgRenderer = RM_AddComponent(bg);
    bgRenderer->renderPriority = PRI_UI;
    bgRenderer->color = CP_Color_Create(0, 0, 0, 255);
    
    // Create Digipen Logo
    digipenObj = GOM_Create2(RECTANGLE, CP_Vector_Set(0.5f * screenWidth, 0.5f * screenHeight), 0.0f, CP_Vector_Set(screenWidth * 0.5f, screenHeight * 0.5f));
    digipenRenderer = RM_AddComponent(digipenObj);
    digipenRenderer->renderPriority = PRI_UI;
    digipenRenderer->color = CP_Color_Create(0, 0, 0, 0); // Start off as transparent.
    RM_LoadImage(digipenRenderer, "Assets/Logo_Digipen_Temp.png");

    // Create BananaBoi Logo
    bananaObj = GOM_Create2(RECTANGLE, CP_Vector_Set(0.5f * screenWidth, 0.5f * screenHeight), 0.0f, CP_Vector_Set(screenWidth * 0.5f, screenHeight * 0.35f));
    bananaRenderer = RM_AddComponent(bananaObj);
    bananaRenderer->renderPriority = PRI_UI;
    bananaRenderer->color = CP_Color_Create(0, 0, 0, 0); // Start off as transparent.
    RM_LoadImage(bananaRenderer, "Assets/Logo_BananaBoi.png");

    // Initialize variables
    digipenState = 0;
    bananaState = 0;
    elapsedTime = 0.f;
}
/// <summary>
/// Update loop that's called every frame.
/// </summary>
void splashscreen_update(void)
{
    if (CP_Input_KeyTriggered(KEY_ESCAPE))
    {
        SceneManager_ChangeSceneByName("mainmenu");
    }

    if (digipenState == 3 && bananaState == 3)
    {
        SceneManager_ChangeSceneByName("mainmenu");
    }
    else if (digipenState != 3)
    {
        update_digipen();
    }
    else
    {
        update_bananaboi();
    }

    SM_SystemsPreUpdate();
    SM_SystemsUpdate(0);
    SM_SystemsLateUpdate();
}
/// <summary>
/// Exit function that's called before scene change.
/// </summary>
void splashscreen_exit(void)
{
    SM_SystemsExit();

    SDM_Init();
    SDM_PlayBgMusic(1);
}

/// <summary>
/// Called by SceneManager to pass function pointers for this scene's init, update and exit.
/// </summary>
/// <param name="init">Function pointer to scene init.</param>
/// <param name="update">Function pointer to scene update.</param>
/// <param name="exit">Funciton pointer to scene exit.</param>
void splashscreen_sceneInit(FunctionPtr* init, FunctionPtr* update, FunctionPtr* exit)
{
    *init = splashscreen_init;
    *update = splashscreen_update;
    *exit = splashscreen_exit;
}