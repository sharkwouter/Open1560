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

define_dummy_symbol(mmwidget_menu);

#include "menu.h"

#include "agi/pipeline.h"
#include "arts7/midgets.h"
#include "eventq7/keys.h"
#include "pcwindis/dxinit.h"

#include "manager.h"
#include "widget.h"

#include <algorithm>

#include <SDL3/SDL_keyboard.h>

void UIMenu::PostSetup()
{}

void UIMenu::CheckInput()
{
    // Ignore any events while midgets are open
    if (MIDGETSPTR->IsOpen())
    {
        MenuMgr()->GetEventQ()->Clear();
        return;
    }

    eqEvent event;

    while (MenuMgr()->GetEventQ()->Pop(&event))
    {
        if (event.Type != eqEventType::Keyboard)
        {
            if (event.Type == eqEventType::Mouse)
                MenuMgr()->ToggleWidgetSnapping(false);

            continue;
        }

        eqKeyboardEvent& kev = event.Key;

        switch (kev.Key) // Enable widget snapping when using arrows or joystick
        {
            case EQ_VK_LEFT:
            case EQ_VK_RIGHT:
            case EQ_VK_UP:
            case EQ_VK_DOWN:
            case EQ_VK_GAMEPAD_A:
            case EQ_VK_GAMEPAD_B:
            case EQ_VK_GAMEPAD_DPAD_LEFT:
            case EQ_VK_GAMEPAD_DPAD_RIGHT:
            case EQ_VK_GAMEPAD_DPAD_UP:
            case EQ_VK_GAMEPAD_DPAD_DOWN:
            case EQ_VK_GAMEPAD_VIEW: MenuMgr()->ToggleWidgetSnapping(true); break;
        }

        switch (kev.Key) // Translate gamepad buttons to keyboard buttons
        {
            case EQ_VK_GAMEPAD_A: kev.Key = EQ_VK_RETURN; break;
            case EQ_VK_GAMEPAD_B: kev.Key = EQ_VK_ESCAPE; break;
            case EQ_VK_GAMEPAD_DPAD_LEFT: kev.Key = EQ_VK_LEFT; break;
            case EQ_VK_GAMEPAD_DPAD_RIGHT: kev.Key = EQ_VK_RIGHT; break;
            case EQ_VK_GAMEPAD_DPAD_UP: kev.Key = EQ_VK_UP; break;
            case EQ_VK_GAMEPAD_DPAD_DOWN: kev.Key = EQ_VK_DOWN; break;
        }

        if (ScanInput(&event))
        {
            if (!kev.IsMouseButton())
                KeyboardAction(event);
        }
        else
        {
            if (kev.Key == EQ_VK_ESCAPE)
                ClearAction();
        }
    }
}

i32 UIMenu::IsAnOptionMenu()
{
    return 0;
}

void UIMenu::AddWidget(uiWidget* widget, aconst char* label, f32 x, f32 y, f32 w, f32 h, i32 id, aconst char* icon)
{
    widget->X = x;
    widget->Y = y;
    widget->Width = w;
    widget->Height = h;
    widget->MinX = x;
    widget->MinY = y;
    widget->MaxX = x + w;
    widget->MaxY = y + h;
    widget->field_6C = 0;
    widget->Label = label;
    widget->Icon = icon;
    widget->Menu = this;
    widget->WidgetID = (id != -1) ? id : widget_count_;

    Ptr<uiWidget*[]> widgets = arnewa uiWidget * [widget_count_ + 1] {};
    for (i32 i = 0; i < widget_count_; ++i)
        widgets[i] = widgets_[i];
    widgets[widget_count_] = widget;
    widgets_ = std::move(widgets);
    ++widget_count_;

    // Try and maintain a top-to-bottom order so widgets are navigated in a sane way
    std::sort(&widgets_[0], &widgets_[widget_count_], [](uiWidget* lhs, uiWidget* rhs) {
        if (lhs->MaxY < rhs->MinY)
            return true;
        if (lhs->MinY > rhs->MaxY)
            return false;
        return lhs->X < rhs->X;
    });

    if (label && *label)
        widget->AddToolTip(this, LOC_TEXT(label));
}

void UIMenu::AssignBackground(aconst char* background_name)
{
    background_name_ = background_name;
}

void UIMenu::ClearAction()
{
    state_ = 2;
}

void UIMenu::GetDimensions(f32& x, f32& y, f32& w, f32& h)
{
    x = menu_x_;
    y = menu_y_;
    w = menu_width_;
    h = menu_height_;
}

void UIMenu::ScaleWidget(f32& x, f32& y, f32& w, f32& h)
{
    f32 l = menu_x_ + x * menu_width_;
    f32 b = menu_y_ + y * menu_height_;
    f32 r = l + (w * menu_width_);
    f32 t = b + (h * menu_height_);

    Pipe()->RoundNormalized(l, b);
    Pipe()->RoundNormalized(r, t);

    x = l;
    y = b;
    w = r - x;
    h = t - y;
}

b32 UIMenu::ScanInput(eqEvent* event)
{
    // Returns true if the menu was active, and the event was for a key press

    if (!IsNodeActive() || (event->Type != eqEventType::Keyboard) || !(event->Key.Modifiers & EQ_KMOD_DOWN))
        return false;

    // TODO: return result of ScanGlobalKeys?
    MenuMgr()->ScanGlobalKeys(event->Key.Key);

    return true;
}

uiWidget* UIMenu::FindWidget(i32 id)
{
    for (i32 i = 0; i < widget_count_; ++i)
    {
        uiWidget* widget = widgets_[i];

        if (widget->WidgetID == id)
            return widget;
    }

    return nullptr;
}

void UIMenu::DisableIME()
{
    if (SDL_TextInputActive(g_MainWindow))
    {
        Displayf("Disabled Text Input");
        SDL_StopTextInput(g_MainWindow);
    }
}