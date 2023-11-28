/*
    Open1560 - An Open Source Re-Implementation of Midtown Madness 1 Beta
    Copyright (C) 2020 Brick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

define_dummy_symbol(mmui_control);

#include "control.h"

#include <iostream>

#include "../data7/memstat.h"
#include "../mmwidget/cwarray.h"
#include <mmcityinfo/state.h>

void ControlSetup::DoneAction()
{}

void ControlSetup::POVCB()
{}

void ControlSetup::ControlSelect()
{
    GameInput()->Init(static_cast<i32>(MMSTATE.InputType));
    this->cwarray->Load();
    this->cwarray->Redraw();
    this->ActivateDeviceOptions();
    this->controlBase->InitSensitivity();
    this->InitCustomControls();
}


// ?CalibrateWatcher@@YGKPAX@Z
ARTS_IMPORT /*static*/ ulong ARTS_STDCALL CalibrateWatcher(void* arg1);
