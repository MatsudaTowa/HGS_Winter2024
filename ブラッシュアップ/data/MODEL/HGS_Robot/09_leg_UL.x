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
 66;
 12.40384;2.95244;-9.62807;,
 12.40384;2.95244;11.70361;,
 11.59889;-22.70854;11.70361;,
 11.59889;-22.70854;-9.62807;,
 12.40384;2.95244;11.70361;,
 -10.36562;-3.08812;7.65910;,
 -6.76693;-22.70854;11.70361;,
 11.59889;-22.70854;11.70361;,
 -10.36562;-3.08812;7.65910;,
 -10.36562;-3.08812;-6.85958;,
 -6.76693;-22.70854;-9.62807;,
 -6.76693;-22.70854;11.70361;,
 9.04872;7.84944;8.34855;,
 -7.01057;1.80892;5.49595;,
 -7.01057;1.80892;-4.85818;,
 9.04872;7.84944;-7.71080;,
 12.40384;2.95244;-9.62807;,
 -10.36562;-3.08812;-6.85958;,
 7.57427;-45.49233;9.27974;,
 7.57427;-45.49233;-7.96895;,
 11.59889;-22.70854;-9.62807;,
 -3.25020;-45.49233;9.27974;,
 -3.25020;-45.49233;-7.96895;,
 -6.76693;-22.70854;-9.62807;,
 9.37563;-2.61088;-15.07943;,
 -7.33745;-8.65134;-15.07943;,
 -10.36562;-3.08812;-6.85958;,
 12.40384;2.95244;-9.62807;,
 9.11837;-22.62278;-16.54290;,
 11.59889;-22.70854;-9.62807;,
 -4.57199;-22.62278;-16.54290;,
 -6.76693;-22.70854;-9.62807;,
 -1.56497;-34.99875;-14.85779;,
 5.88908;-34.99875;-14.85779;,
 -4.57199;-22.62278;-16.54290;,
 9.11837;-22.62278;-16.54290;,
 12.64085;13.79004;7.02883;,
 12.64085;13.79004;-6.39105;,
 14.55619;7.18504;9.83246;,
 14.55619;7.18504;-9.19472;,
 6.43804;-47.99263;-11.68032;,
 6.43804;-57.18704;-6.37186;,
 -3.41236;-57.18704;-6.37186;,
 -3.41236;-47.99263;-11.68032;,
 6.43804;-57.18704;4.24500;,
 -3.41236;-57.18704;4.24500;,
 6.43804;-47.99263;9.55341;,
 -3.41236;-47.99263;9.55341;,
 5.24111;-38.79825;4.24500;,
 0.04900;-38.79825;4.24500;,
 5.24111;-38.79825;-6.37186;,
 0.04900;-38.79825;-6.37186;,
 6.43804;-47.99263;-11.68032;,
 -3.41236;-47.99263;-11.68032;,
 6.43804;-47.99263;-1.06342;,
 6.43804;-47.99263;-1.06342;,
 6.43804;-47.99263;-1.06342;,
 6.43804;-47.99263;-1.06342;,
 6.43804;-47.99263;-1.06342;,
 6.43804;-47.99263;-1.06342;,
 -3.41236;-47.99263;-1.06342;,
 -3.41236;-47.99263;-1.06342;,
 -3.41236;-47.99263;-1.06342;,
 -3.41236;-47.99263;-1.06342;,
 -3.41236;-47.99263;-1.06342;,
 -3.41236;-47.99263;-1.06342;;
 
 42;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,8,1;,
 4;14,15,16,17;,
 4;13,14,17,8;,
 4;13,12,15,14;,
 4;18,19,20,2;,
 4;21,18,2,11;,
 4;22,21,11,23;,
 4;22,19,18,21;,
 4;24,25,26,27;,
 4;28,24,27,29;,
 4;25,30,31,26;,
 4;25,24,28,30;,
 4;32,33,19,22;,
 4;34,32,22,23;,
 4;33,35,20,19;,
 4;33,32,34,35;,
 4;36,37,15,12;,
 4;38,36,12,1;,
 4;37,39,16,15;,
 4;37,36,38,39;,
 4;40,41,42,43;,
 4;41,44,45,42;,
 4;44,46,47,45;,
 4;46,48,49,47;,
 4;48,50,51,49;,
 4;50,52,53,51;,
 3;54,41,40;,
 3;55,44,41;,
 3;56,46,44;,
 3;57,48,46;,
 3;58,50,48;,
 3;59,52,50;,
 3;60,43,42;,
 3;61,42,45;,
 3;62,45,47;,
 3;63,47,49;,
 3;64,49,51;,
 3;65,51,53;,
 4;38,1,0,39;;
 
 MeshMaterialList {
  12;
  42;
  9,
  9,
  9,
  7,
  7,
  7,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  10,
  9,
  9,
  9,
  10,
  9,
  7,
  7,
  7,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  9;;
  Material {
   0.800000;0.800000;0.800000;0.700000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.050196;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.643137;0.514510;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.056471;0.056471;0.056471;1.000000;;
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "child_wear.jpg";
   }
  }
  Material {
   0.614902;0.000000;0.021961;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.065882;0.461176;0.147451;1.000000;;
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
   0.800000;0.000000;0.043922;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.784314;0.800000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.351373;0.351373;0.351373;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  38;
  -0.983592;-0.180406;0.000000;,
  0.999508;-0.031353;-0.000000;,
  -0.088933;0.104627;0.990527;,
  -0.242657;0.356744;-0.902137;,
  -0.293974;0.468556;0.833087;,
  -0.988296;-0.152546;0.000000;,
  0.984754;-0.173951;-0.000000;,
  0.000000;-0.105789;0.994389;,
  -0.271051;0.746538;-0.607629;,
  -0.948844;-0.146897;-0.279494;,
  0.915791;-0.007619;-0.401583;,
  0.000000;-0.548792;-0.835959;,
  -0.219478;0.272774;-0.936709;,
  -0.192650;0.402160;0.895072;,
  -0.855724;0.517433;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.500004;-0.866023;,
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.500001;0.866025;,
  0.000000;0.500002;0.866024;,
  0.000000;1.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.824959;0.565193;0.000000;,
  -0.352057;0.935978;0.000000;,
  -0.013240;0.088732;-0.995968;,
  -0.897739;-0.216795;-0.383489;,
  0.880868;-0.234189;-0.411372;,
  0.000000;-0.134915;-0.990857;,
  0.960433;0.278510;0.000000;,
  0.000000;0.500005;-0.866022;,
  1.000000;0.000000;-0.000000;,
  0.991633;0.129091;0.000000;,
  0.991633;0.129091;0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.935878;0.352324;0.000000;,
  -0.935878;0.352324;0.000000;,
  -0.935878;0.352324;0.000000;,
  0.891370;-0.453276;-0.000000;;
  42;
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;3,3,3,3;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;5,5,5,5;,
  4;17,17,17,17;,
  4;8,8,8,8;,
  4;10,10,10,10;,
  4;9,9,9,9;,
  4;24,24,24,24;,
  4;11,11,11,11;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;27,27,27,27;,
  4;14,14,14,14;,
  4;13,13,13,13;,
  4;12,12,12,12;,
  4;28,28,28,28;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;29,29,29,29;,
  3;15,15,15;,
  3;15,15,15;,
  3;30,30,30;,
  3;31,31,31;,
  3;32,32,32;,
  3;32,32,32;,
  3;21,21,21;,
  3;21,21,21;,
  3;33,33,33;,
  3;34,34,34;,
  3;35,35,35;,
  3;36,36,36;,
  4;37,37,37,37;;
 }
 MeshTextureCoords {
  66;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.166670;0.000000;,
  0.166670;1.000000;,
  0.000000;1.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  0.833330;0.000000;,
  0.833330;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083330;0.000000;,
  0.250000;0.000000;,
  0.416670;0.000000;,
  0.583330;0.000000;,
  0.750000;0.000000;,
  0.916670;0.000000;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;;
 }
}
