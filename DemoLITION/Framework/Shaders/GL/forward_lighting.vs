/*

        Copyright 2024 Etay Meiri

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


#version 460 core

//
// Non PVP input attributes
//
layout (location = 0) in vec3 Position;
layout (location = 1) in vec2 TexCoord;
layout (location = 2) in vec3 Normal;
layout (location = 3) in vec3 Tangent;
layout (location = 4) in vec3 Bitangent;


// 
// PVP input attributes
//
struct Vertex {
    float Position[3];
    float TexCoord[2];
    float Normal[3];
    float Tangent[3];
    float Bitangent[3];
};

layout(std430, binding = 0) restrict readonly buffer Vertices {
    Vertex in_Vertices[];
};


struct PerObjectData {
    mat4 WorldMatrix;
    mat4 NormalMatrix;
    ivec4 MaterialIndex;
};


layout(std430, binding = 1) restrict readonly buffer PerObjectSSBO {
    PerObjectData o[];
};

out vec2 TexCoord0;
out vec3 Normal0;
out vec3 WorldPos0;
out vec4 LightSpacePos0;
out vec3 Tangent0;
out vec3 Bitangent0;
out flat int MaterialIndex;


uniform mat4 gWVP;
uniform mat4 gVP;
uniform mat4 gLightWVP;
uniform mat4 gLightVP;
uniform mat4 gWorld;
uniform mat3 gNormalMatrix;
uniform bool gIsPVP = false;
uniform bool gIsIndirectRender = false;

vec3 GetPosition(int i)
{
    return vec3(in_Vertices[i].Position[0], 
                in_Vertices[i].Position[1], 
                in_Vertices[i].Position[2]);
}


vec2 GetTexCoord(int i)
{
    return vec2(in_Vertices[i].TexCoord[0], 
                in_Vertices[i].TexCoord[1]);
}


vec3 GetNormal(int i)
{
    return vec3(in_Vertices[i].Normal[0], 
                in_Vertices[i].Normal[1], 
                in_Vertices[i].Normal[2]);
}


vec3 GetTangent(int i)
{
    return vec3(in_Vertices[i].Tangent[0], 
                in_Vertices[i].Tangent[1], 
                in_Vertices[i].Tangent[2]);
}


vec3 GetBitangent(int i)
{
    return vec3(in_Vertices[i].Bitangent[0], 
                in_Vertices[i].Bitangent[1], 
                in_Vertices[i].Bitangent[2]);
}


void main()
{
    vec3 Position_;
    vec2 TexCoord_;
    vec3 Normal_;
    vec3 Tangent_;
    vec3 Bitangent_;

    if (gIsPVP) {
        Position_ = GetPosition(gl_VertexID);        
        TexCoord_ = GetTexCoord(gl_VertexID);
        Normal_ = GetNormal(gl_VertexID);
        Tangent_ = GetTangent(gl_VertexID);
        Bitangent_ = GetBitangent(gl_VertexID);
    } else {
        Position_ = Position;
        TexCoord_ = TexCoord;
        Normal_ = Normal;
        Tangent_ = Tangent;
        Bitangent_ = Bitangent;
    }

    vec4 Pos4 = vec4(Position_, 1.0);

    if (gIsIndirectRender) {
        gl_Position = gVP * o[gl_DrawID].WorldMatrix * Pos4;
        Normal0 = (o[gl_DrawID].NormalMatrix * vec4(Normal_, 0.0)).xyz;
        Tangent0 = (o[gl_DrawID].NormalMatrix * vec4(Tangent_, 0.0)).xyz;
        Bitangent0 = (o[gl_DrawID].NormalMatrix * vec4(Bitangent_, 0.0)).xyz;
        WorldPos0 = (o[gl_DrawID].WorldMatrix * Pos4).xyz;
        LightSpacePos0 = (gLightVP * o[gl_DrawID].WorldMatrix * Pos4);
        MaterialIndex = o[gl_DrawID].MaterialIndex.x;
    } else {
        gl_Position = gWVP * Pos4;
        Normal0 = gNormalMatrix * Normal_;
        Tangent0 = gNormalMatrix * Tangent_;
        Bitangent0 = gNormalMatrix * Bitangent_;
        WorldPos0 = (gWorld * Pos4).xyz;
        LightSpacePos0 = gLightWVP * Pos4;
    }

    TexCoord0 = TexCoord_;
}
