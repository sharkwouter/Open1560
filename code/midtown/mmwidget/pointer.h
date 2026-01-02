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

#pragma once

#include "arts7/node.h"
#include "vector7/vector2.h"

class agiBitmap;
class uiWidget;

class sfPointer final : public asNode
{
public:
    // ??0sfPointer@@QAE@XZ
    ARTS_IMPORT sfPointer();

    // ??1sfPointer@@UAE@XZ
    ARTS_EXPORT ~sfPointer() override;

    // ?Cull@sfPointer@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetClass@sfPointer@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetPointerHeight@sfPointer@@QAEMXZ
    ARTS_IMPORT f32 GetPointerHeight();

    // ?Init@sfPointer@@QAEXXZ
    ARTS_IMPORT void Init();

    // ?ResChange@sfPointer@@UAEXHH@Z
    ARTS_IMPORT void ResChange(i32 arg1, i32 arg2) override;

    // ?Update@sfPointer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?WaitForRelease@sfPointer@@QAEXXZ
    ARTS_IMPORT void WaitForRelease();

    // ?DeclareFields@sfPointer@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    Rc<agiBitmap> CursorTexture;
    Vector2 CurrentPos;
    Vector2 PrevPos;
    i32 MaxX;
    i32 MaxY;
    i32 field_3C;
    i32 field_40;
    i32 State;
    f32 field_48;
    f32 field_4C;
    uiWidget* CurrentWidget;
};

check_size(sfPointer, 0x54);
