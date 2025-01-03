xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 52;
 0.00000;5.77841;0.00000;,
 1.93774;4.88801;-1.93774;,
 0.00000;4.88801;-2.74038;,
 0.00000;5.77841;0.00000;,
 2.74038;4.88801;0.00000;,
 0.00000;5.77841;0.00000;,
 1.93774;4.88801;1.93774;,
 0.00000;5.77841;0.00000;,
 -0.00000;4.88801;2.74038;,
 0.00000;5.77841;0.00000;,
 -1.93774;4.88801;1.93774;,
 0.00000;5.77841;0.00000;,
 -2.74038;4.88801;-0.00000;,
 0.00000;5.77841;0.00000;,
 -1.93774;4.88801;-1.93774;,
 0.00000;5.77841;0.00000;,
 0.00000;4.88801;-2.74038;,
 3.13533;2.55689;-3.13533;,
 0.00000;2.55689;-4.43403;,
 4.43403;2.55689;0.00000;,
 3.13533;2.55689;3.13533;,
 -0.00000;2.55689;4.43403;,
 -3.13533;2.55689;3.13533;,
 -4.43403;2.55689;-0.00000;,
 -3.13533;2.55689;-3.13533;,
 0.00000;2.55689;-4.43403;,
 3.13533;-0.32451;-3.13533;,
 0.00000;-0.32451;-4.43403;,
 4.43403;-0.32451;0.00000;,
 3.13533;-0.32451;3.13533;,
 -0.00000;-0.32451;4.43403;,
 -3.13533;-0.32451;3.13533;,
 -4.43403;-0.32451;-0.00000;,
 -3.13533;-0.32451;-3.13533;,
 0.00000;-0.32451;-4.43403;,
 1.93774;-2.65562;-1.93774;,
 0.00000;-2.65562;-2.74038;,
 2.74038;-2.65562;0.00000;,
 1.93774;-2.65562;1.93774;,
 -0.00000;-2.65562;2.74038;,
 -1.93774;-2.65562;1.93774;,
 -2.74038;-2.65562;-0.00000;,
 -1.93774;-2.65562;-1.93774;,
 0.00000;-2.65562;-2.74038;,
 0.00000;-3.54602;-0.00000;,
 0.00000;-3.54602;-0.00000;,
 0.00000;-3.54602;-0.00000;,
 0.00000;-3.54602;-0.00000;,
 0.00000;-3.54602;-0.00000;,
 0.00000;-3.54602;-0.00000;,
 0.00000;-3.54602;-0.00000;,
 0.00000;-3.54602;-0.00000;;
 
 40;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 4;2,1,17,18;,
 4;1,4,19,17;,
 4;4,6,20,19;,
 4;6,8,21,20;,
 4;8,10,22,21;,
 4;10,12,23,22;,
 4;12,14,24,23;,
 4;14,16,25,24;,
 4;18,17,26,27;,
 4;17,19,28,26;,
 4;19,20,29,28;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;27,26,35,36;,
 4;26,28,37,35;,
 4;28,29,38,37;,
 4;29,30,39,38;,
 4;30,31,40,39;,
 4;31,32,41,40;,
 4;32,33,42,41;,
 4;33,34,43,42;,
 3;36,35,44;,
 3;35,37,45;,
 3;37,38,46;,
 3;38,39,47;,
 3;39,40,48;,
 3;40,41,49;,
 3;41,42,50;,
 3;42,43,51;;
 
 MeshMaterialList {
  6;
  40;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.473726;0.000000;0.536471;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.721569;0.592941;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.517647;0.517647;0.517647;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.338824;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  34;
  0.000000;1.000000;-0.000000;,
  -0.000000;0.813300;-0.581844;,
  0.411426;0.813300;-0.411426;,
  0.581844;0.813300;0.000000;,
  0.411426;0.813300;0.411426;,
  -0.000000;0.813300;0.581844;,
  -0.411426;0.813300;0.411426;,
  -0.581844;0.813300;-0.000000;,
  -0.411426;0.813300;-0.411426;,
  -0.000000;0.313024;-0.949745;,
  0.671571;0.313024;-0.671571;,
  0.949745;0.313024;0.000000;,
  0.671571;0.313024;0.671571;,
  -0.000000;0.313024;0.949745;,
  -0.671571;0.313024;0.671571;,
  -0.949745;0.313024;-0.000000;,
  -0.671571;0.313024;-0.671571;,
  -0.000000;-0.313025;-0.949745;,
  0.671571;-0.313025;-0.671571;,
  0.949745;-0.313025;0.000000;,
  0.671571;-0.313025;0.671571;,
  -0.000000;-0.313025;0.949745;,
  -0.671571;-0.313025;0.671571;,
  -0.949745;-0.313025;0.000000;,
  -0.671571;-0.313025;-0.671571;,
  -0.000000;-0.813300;-0.581845;,
  0.411426;-0.813300;-0.411426;,
  0.581844;-0.813300;0.000000;,
  0.411426;-0.813300;0.411426;,
  -0.000000;-0.813300;0.581845;,
  -0.411426;-0.813300;0.411426;,
  -0.581845;-0.813300;0.000000;,
  -0.411426;-0.813300;-0.411426;,
  -0.000000;-1.000000;-0.000000;;
  40;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,24,32,31;,
  4;24,17,25,32;,
  3;25,26,33;,
  3;26,27,33;,
  3;27,28,33;,
  3;28,29,33;,
  3;29,30,33;,
  3;30,31,33;,
  3;31,32,33;,
  3;32,25,33;;
 }
 MeshTextureCoords {
  52;
  0.062500;0.000000;,
  0.125000;0.200000;,
  0.000000;0.200000;,
  0.187500;0.000000;,
  0.250000;0.200000;,
  0.312500;0.000000;,
  0.375000;0.200000;,
  0.437500;0.000000;,
  0.500000;0.200000;,
  0.562500;0.000000;,
  0.625000;0.200000;,
  0.687500;0.000000;,
  0.750000;0.200000;,
  0.812500;0.000000;,
  0.875000;0.200000;,
  0.937500;0.000000;,
  1.000000;0.200000;,
  0.125000;0.400000;,
  0.000000;0.400000;,
  0.250000;0.400000;,
  0.375000;0.400000;,
  0.500000;0.400000;,
  0.625000;0.400000;,
  0.750000;0.400000;,
  0.875000;0.400000;,
  1.000000;0.400000;,
  0.125000;0.600000;,
  0.000000;0.600000;,
  0.250000;0.600000;,
  0.375000;0.600000;,
  0.500000;0.600000;,
  0.625000;0.600000;,
  0.750000;0.600000;,
  0.875000;0.600000;,
  1.000000;0.600000;,
  0.125000;0.800000;,
  0.000000;0.800000;,
  0.250000;0.800000;,
  0.375000;0.800000;,
  0.500000;0.800000;,
  0.625000;0.800000;,
  0.750000;0.800000;,
  0.875000;0.800000;,
  1.000000;0.800000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}
