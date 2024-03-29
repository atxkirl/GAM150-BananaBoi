/*
@copyright	All content � 2021 DigiPen Institute of Technology Singapore, all rights reserved.
@file            Objective_Connect.h
@author          Lim Guan Sheng, Marcus (l.guanshengmarcus)
@course          CSD1400 Software Engineering Project 1
@Team            BananaBoi
@brief           This file contains the functions for Objective Connect Wire.
*//*________________________________________________________________________________________*/

#pragma once

/// <summary>
/// Initializes the variables.
/// </summary>
void OB_ConnectInit();

/// <summary>
/// Update.
/// </summary>
void OB_ConnectUpdate();

/// <summary>
/// Toggle the active of the GameObjects.
/// </summary>
void OB_ConnectToggleActive();

/// <summary>
/// Returns whether the objective is complete.
/// </summary>
/// <returns>int</returns>
int OB_ConnectIsComplete();

/// <summary>
/// Return the active of the GameObjects.
/// </summary>
/// <returns>int</returns>
int OB_ConnectGetActive();

/// <summary>
/// Set the active of the GameObjects
/// </summary>
/// <param name="iSetter"></param>
void OB_ConnectSetActive(int iSetter);

/// <summary>
/// Enables the GameObjects
/// </summary>
void OB_ConnectTrigger();

/// <summary>
/// Disables the GameObjects.
/// </summary>
void OB_ConnectUnTrigger();

/// <summary>
/// Creates the connector GameObjects.
/// </summary>
void CreateConnectors();