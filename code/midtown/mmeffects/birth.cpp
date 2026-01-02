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

define_dummy_symbol(mmeffects_birth);

#include "birth.h"

#include "data7/metadefine.h"

META_DEFINE_CHILD("asBirthRule", asBirthRule, Base) // Skip asNode fields
{
    META_FIELD("Position", Position);
    META_FIELD("PositionVar", PositionVar);
    META_FIELD("Velocity", Velocity);
    META_FIELD("VelocityVar", VelocityVar);
    META_FIELD("Life", Life);
    META_FIELD("LifeVar", LifeVar);
    META_FIELD("Mass", Mass);
    META_FIELD("MassVar", MassVar);
    META_FIELD("Radius", Radius);
    META_FIELD("RadiusVar", RadiusVar);
    META_FIELD("DRadius", DRadius);
    META_FIELD("DRadiusVar", DRadiusVar);
    META_FIELD("Drag", Drag);
    META_FIELD("DragVar", DragVar);
    META_FIELD("Damp", Damp);
    META_FIELD("DampVar", DampVar);
    META_FIELD("SpewRate", SpewRate);
    META_FIELD("SpewTimeLimit", SpewTimeLimit);
    META_FIELD("Gravity", Gravity);
    META_FIELD("DAlpha", DAlpha);
    META_FIELD("DAlphaVar", DAlphaVar);
    META_FIELD("DRotation", DRotation);
    META_FIELD("DRotationVar", DRotationVar);
    META_FIELD("TexFrameStart", TexFrameStart);
    META_FIELD("TexFrameEnd", TexFrameEnd);
    META_FIELD("InitialBlast", InitialBlast);
    META_FIELD("BirthFlags", BirthFlags);
}