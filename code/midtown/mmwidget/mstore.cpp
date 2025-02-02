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

define_dummy_symbol(mmwidget_mstore);

#include "mstore.h"

#include "stream/fsystem.h"
#include "stream/stream.h"
#include "vector7/vector4.h"

void MArray::Flush()
{}

void MArray::Read(char* name)
{
    Ptr<Stream> input = as_ptr OpenFile(name, "tune", ".csv", 0, nullptr, 0, "widget file");

    if (input == nullptr)
    {
        Errorf("Can't open menu data file '%s'", name);

        return;
    }

    char buffer[128];
    input->Gets(buffer, ARTS_SIZE(buffer));

    while (input->Gets(buffer, ARTS_SIZE(buffer)))
    {
        char* split_context = nullptr;

        [[maybe_unused]] char* menu_name = arts_strtok(buffer, ",", &split_context);
        [[maybe_unused]] char* background = arts_strtok(nullptr, ",", &split_context);
        i32 menu_id = std::atoi(arts_strtok(nullptr, ",", &split_context));

        Vector4 pos;
        pos.w = std::atoi(arts_strtok(nullptr, ",", &split_context)) / 640.0f; // x
        pos.x = std::atoi(arts_strtok(nullptr, ",", &split_context)) / 480.0f; // y
        pos.y = std::atoi(arts_strtok(nullptr, ",", &split_context)) / 640.0f; // w
        pos.z = std::atoi(arts_strtok(nullptr, ",", &split_context)) / 480.0f; // h

        AddMenuData(menu_id, pos, nullptr);
    }
}
