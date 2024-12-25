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
 64;
 0.00000;0.04638;-4.24070;,
 2.49262;0.04638;-3.43080;,
 2.24475;-12.55532;-3.08964;,
 0.00000;-12.55532;-3.81900;,
 4.03314;0.04638;-1.31045;,
 3.63209;-12.55532;-1.18014;,
 4.03314;0.04638;1.31045;,
 3.63209;-12.55532;1.18014;,
 2.49262;0.04638;3.43080;,
 2.24475;-12.55532;3.08964;,
 -0.00000;0.04638;4.24070;,
 -0.00000;-7.28326;3.81900;,
 -2.49262;0.04638;3.43080;,
 -2.24475;-7.28326;3.08964;,
 -4.03314;0.04638;1.31045;,
 -3.63209;-12.55532;1.18014;,
 -4.03314;0.04638;-1.31045;,
 -3.63209;-12.55532;-1.18014;,
 -2.49262;0.04638;-3.43080;,
 -2.24475;-12.55532;-3.08964;,
 0.00000;0.04638;-4.24070;,
 0.00000;-12.55532;-3.81900;,
 1.56752;-19.46473;-2.15750;,
 0.00000;-19.46473;-2.66682;,
 2.53630;-19.46473;-0.82409;,
 2.53630;-19.46473;0.82409;,
 1.56752;-19.46473;2.15750;,
 -0.00000;-19.46473;2.66682;,
 -1.56752;-19.46473;2.15750;,
 -2.53630;-19.46473;0.82409;,
 -2.53630;-19.46473;-0.82409;,
 -1.56752;-19.46473;-2.15750;,
 0.00000;-19.46473;-2.66682;,
 2.83775;-23.65714;-2.91015;,
 0.00000;-23.65714;-3.59714;,
 4.59157;-23.65714;-1.11158;,
 4.59157;-23.65714;1.11158;,
 2.83775;-23.65714;2.91015;,
 -0.00000;-23.65714;3.59714;,
 -2.83775;-23.65714;2.91015;,
 -4.59157;-23.65714;1.11158;,
 -4.59157;-23.65714;-1.11158;,
 -2.83774;-23.65714;-2.91015;,
 0.00000;-23.65714;-3.59714;,
 0.00000;0.04638;0.00000;,
 0.00000;0.04638;0.00000;,
 0.00000;0.04638;0.00000;,
 0.00000;0.04638;0.00000;,
 0.00000;0.04638;0.00000;,
 0.00000;0.04638;0.00000;,
 0.00000;0.04638;0.00000;,
 0.00000;0.04638;0.00000;,
 0.00000;0.04638;0.00000;,
 0.00000;0.04638;0.00000;,
 0.00000;-23.65714;-0.00000;,
 0.00000;-23.65714;-0.00000;,
 0.00000;-23.65714;-0.00000;,
 0.00000;-23.65714;-0.00000;,
 0.00000;-23.65714;-0.00000;,
 0.00000;-23.65714;-0.00000;,
 0.00000;-23.65714;-0.00000;,
 0.00000;-23.65714;-0.00000;,
 0.00000;-23.65714;-0.00000;,
 0.00000;-23.65714;-0.00000;;
 
 50;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;16,18,19,17;,
 4;18,20,21,19;,
 4;3,2,22,23;,
 4;2,5,24,22;,
 4;5,7,25,24;,
 4;7,9,26,25;,
 4;9,11,27,26;,
 4;11,13,28,27;,
 4;13,15,29,28;,
 4;15,17,30,29;,
 4;17,19,31,30;,
 4;19,21,32,31;,
 4;23,22,33,34;,
 4;22,24,35,33;,
 4;24,25,36,35;,
 4;25,26,37,36;,
 4;26,27,38,37;,
 4;27,28,39,38;,
 4;28,29,40,39;,
 4;29,30,41,40;,
 4;30,31,42,41;,
 4;31,32,43,42;,
 3;44,1,0;,
 3;45,4,1;,
 3;46,6,4;,
 3;47,8,6;,
 3;48,10,8;,
 3;49,12,10;,
 3;50,14,12;,
 3;51,16,14;,
 3;52,18,16;,
 3;53,20,18;,
 3;54,34,33;,
 3;55,33,35;,
 3;56,35,36;,
 3;57,36,37;,
 3;58,37,38;,
 3;59,38,39;,
 3;60,39,40;,
 3;61,40,41;,
 3;62,41,42;,
 3;63,42,43;;
 
 MeshMaterialList {
  6;
  50;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
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
  42;
  0.000000;1.000000;0.000000;,
  0.000000;-0.033445;-0.999441;,
  0.587456;-0.033445;-0.808565;,
  0.950525;-0.033445;-0.308844;,
  0.950524;-0.033445;0.308844;,
  0.573270;-0.039479;0.818415;,
  -0.017240;-0.050969;0.998551;,
  -0.572986;-0.050969;0.817979;,
  -0.944838;-0.039479;0.325151;,
  -0.950524;-0.033445;-0.308844;,
  -0.587456;-0.033445;-0.808565;,
  0.000000;-0.099220;-0.995065;,
  0.584884;-0.099221;-0.805025;,
  0.946364;-0.099220;-0.307492;,
  0.946363;-0.099220;0.307492;,
  0.556220;-0.095160;0.825569;,
  -0.035395;-0.081445;0.996049;,
  -0.556828;-0.081445;0.826626;,
  -0.935249;-0.095160;0.340961;,
  -0.946363;-0.099220;-0.307492;,
  -0.584884;-0.099221;-0.805025;,
  0.000000;0.035206;-0.999380;,
  0.561744;0.070306;-0.824319;,
  0.936199;0.131727;-0.325852;,
  0.936199;0.131727;0.325852;,
  0.538587;0.079153;0.838844;,
  -0.027102;0.060499;0.997800;,
  -0.538019;0.095308;0.837527;,
  -0.925448;0.141185;0.351587;,
  -0.936199;0.131727;-0.325852;,
  -0.561744;0.070306;-0.824319;,
  0.000000;0.231072;-0.972937;,
  0.512538;0.299866;-0.804602;,
  0.851165;0.417560;-0.318058;,
  0.851165;0.417560;0.318058;,
  0.512538;0.299866;0.804602;,
  -0.000000;0.231072;0.972937;,
  -0.512538;0.299866;0.804602;,
  -0.851165;0.417560;0.318058;,
  -0.851165;0.417560;-0.318059;,
  -0.512538;0.299866;-0.804602;,
  0.000000;-1.000000;-0.000000;;
  50;
  4;1,2,12,11;,
  4;2,3,13,12;,
  4;3,4,14,13;,
  4;4,5,15,14;,
  4;5,6,16,15;,
  4;6,7,17,16;,
  4;7,8,18,17;,
  4;8,9,19,18;,
  4;9,10,20,19;,
  4;10,1,11,20;,
  4;11,12,22,21;,
  4;12,13,23,22;,
  4;13,14,24,23;,
  4;14,15,25,24;,
  4;15,16,26,25;,
  4;16,17,27,26;,
  4;17,18,28,27;,
  4;18,19,29,28;,
  4;19,20,30,29;,
  4;20,11,21,30;,
  4;21,22,32,31;,
  4;22,23,33,32;,
  4;23,24,34,33;,
  4;24,25,35,34;,
  4;25,26,36,35;,
  4;26,27,37,36;,
  4;27,28,38,37;,
  4;28,29,39,38;,
  4;29,30,40,39;,
  4;30,21,31,40;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;,
  3;41,41,41;;
 }
 MeshTextureCoords {
  64;
  0.000000;0.000000;,
  0.100000;0.000000;,
  0.100000;0.333333;,
  0.000000;0.333333;,
  0.200000;0.000000;,
  0.200000;0.333333;,
  0.300000;0.000000;,
  0.300000;0.333333;,
  0.400000;0.000000;,
  0.400000;0.333333;,
  0.500000;0.000000;,
  0.500000;0.333333;,
  0.600000;0.000000;,
  0.600000;0.333333;,
  0.700000;0.000000;,
  0.700000;0.333333;,
  0.800000;0.000000;,
  0.800000;0.333333;,
  0.900000;0.000000;,
  0.900000;0.333333;,
  1.000000;0.000000;,
  1.000000;0.333333;,
  0.100000;0.666667;,
  0.000000;0.666667;,
  0.200000;0.666667;,
  0.300000;0.666667;,
  0.400000;0.666667;,
  0.500000;0.666667;,
  0.600000;0.666667;,
  0.700000;0.666667;,
  0.800000;0.666667;,
  0.900000;0.666667;,
  1.000000;0.666667;,
  0.100000;1.000000;,
  0.000000;1.000000;,
  0.200000;1.000000;,
  0.300000;1.000000;,
  0.400000;1.000000;,
  0.500000;1.000000;,
  0.600000;1.000000;,
  0.700000;1.000000;,
  0.800000;1.000000;,
  0.900000;1.000000;,
  1.000000;1.000000;,
  0.050000;0.000000;,
  0.150000;0.000000;,
  0.250000;0.000000;,
  0.350000;0.000000;,
  0.450000;0.000000;,
  0.550000;0.000000;,
  0.650000;0.000000;,
  0.750000;0.000000;,
  0.850000;0.000000;,
  0.950000;0.000000;,
  0.050000;1.000000;,
  0.150000;1.000000;,
  0.250000;1.000000;,
  0.350000;1.000000;,
  0.450000;1.000000;,
  0.550000;1.000000;,
  0.650000;1.000000;,
  0.750000;1.000000;,
  0.850000;1.000000;,
  0.950000;1.000000;;
 }
}
