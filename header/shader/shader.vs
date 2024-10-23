#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 color;

layout (location = 2) in vec2 aTex;
out vec2 texCoord;

//controls scale of vertices
uniform float scale;

uniform mat4 transform;
void main()
{                                               //set y neg to rotate upside down
    //gl_Position = vec4(aPos.x + aPos.x * scale, -(aPos.y + aPos.y * scale), aPos.z + aPos.z * scale, 1.0);
   gl_Position = transform *vec4(aPos.x, aPos.y, aPos.z, 1.0f);
   color = aColor;
   texCoord = vec2(aTex.x,aTex.y);
}