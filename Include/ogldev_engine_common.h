/*

        Copyright 2014 Etay Meiri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OGLDEV_ENGINE_COMMON_H
#define OGLDEV_ENGINE_COMMON_H

#define COLOR_TEXTURE_UNIT              GL_TEXTURE0
#define COLOR_TEXTURE_UNIT_INDEX        0
#define SHADOW_TEXTURE_UNIT             GL_TEXTURE1
#define SHADOW_TEXTURE_UNIT_INDEX       1
#define NORMAL_TEXTURE_UNIT             GL_TEXTURE2
#define NORMAL_TEXTURE_UNIT_INDEX       2
#define RANDOM_TEXTURE_UNIT             GL_TEXTURE3
#define RANDOM_TEXTURE_UNIT_INDEX       3
#define DISPLACEMENT_TEXTURE_UNIT       GL_TEXTURE4
#define DISPLACEMENT_TEXTURE_UNIT_INDEX 4
#define ALBEDO_TEXTURE_UNIT             GL_TEXTURE5
#define ALBEDO_TEXTURE_UNIT_INDEX       5          
#define ROUGHNESS_TEXTURE_UNIT          GL_TEXTURE6
#define ROUGHNESS_TEXTURE_UNIT_INDEX    6
#define MOTION_TEXTURE_UNIT             GL_TEXTURE7
#define MOTION_TEXTURE_UNIT_INDEX       7
#define SPECULAR_EXPONENT_UNIT             GL_TEXTURE8
#define SPECULAR_EXPONENT_UNIT_INDEX       8
#define CASCACDE_SHADOW_TEXTURE_UNIT0               SHADOW_TEXTURE_UNIT
#define CASCACDE_SHADOW_TEXTURE_UNIT0_INDEX         SHADOW_TEXTURE_UNIT_INDEX
#define CASCACDE_SHADOW_TEXTURE_UNIT1               GL_TEXTURE9
#define CASCACDE_SHADOW_TEXTURE_UNIT1_INDEX         9
#define CASCACDE_SHADOW_TEXTURE_UNIT2               GL_TEXTURE10
#define CASCACDE_SHADOW_TEXTURE_UNIT2_INDEX         10
#define SHADOW_CUBE_MAP_TEXTURE_UNIT                GL_TEXTURE11
#define SHADOW_CUBE_MAP_TEXTURE_UNIT_INDEX          11
#define SHADOW_MAP_RANDOM_OFFSET_TEXTURE_UNIT       GL_TEXTURE12
#define SHADOW_MAP_RANDOM_OFFSET_TEXTURE_UNIT_INDEX 12
#define METALLIC_TEXTURE_UNIT                       GL_TEXTURE14
#define METALLIC_TEXTURE_UNIT_INDEX                 14
#define HEIGHT_TEXTURE_UNIT                         GL_TEXTURE15
#define HEIGHT_TEXTURE_UNIT_INDEX                   15

#endif  /* OGLDEV_ENGINE_COMMON_H */
