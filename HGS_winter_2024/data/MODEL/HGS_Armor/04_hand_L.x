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
 34;
 -1.96741;7.96901;-2.81122;,
 7.07577;9.71398;-3.55863;,
 7.07577;-8.75204;-3.55863;,
 -1.96741;-7.00708;-2.81122;,
 -1.96741;7.96901;3.60335;,
 -1.96741;7.96901;-2.81122;,
 -1.96741;-7.00708;-2.81122;,
 -1.96741;-7.00708;3.60335;,
 7.07577;9.71398;4.35076;,
 7.07577;9.71398;-3.55863;,
 -1.96741;7.96901;-2.81122;,
 -1.96741;-7.00708;-2.81122;,
 7.07577;-8.75204;-3.55863;,
 7.07577;-8.75204;4.35076;,
 16.66225;6.20105;2.84609;,
 16.66225;6.20105;-2.05396;,
 7.07577;9.71398;-3.55863;,
 16.66225;-5.23912;-2.05396;,
 16.66225;-5.23912;2.84609;,
 7.07577;-8.75204;-3.55863;,
 -3.50186;9.00581;7.02003;,
 6.96618;10.99237;7.86454;,
 7.07577;9.71398;4.35076;,
 -1.96741;7.96901;3.60335;,
 -3.50186;-8.04388;7.02003;,
 -1.96741;-7.00708;3.60335;,
 6.96618;-10.03044;7.86454;,
 7.07577;-8.75204;4.35076;,
 6.96618;10.99237;7.86454;,
 19.02939;6.99305;4.51375;,
 19.02939;-6.03112;4.51375;,
 6.96618;-10.03044;7.86454;,
 20.00603;6.99305;-2.69616;,
 20.00603;-6.03112;-2.69616;;
 
 18;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;4,8,9,10;,
 4;11,12,13,7;,
 4;14,15,16,8;,
 4;17,18,13,19;,
 4;15,17,19,16;,
 4;20,21,22,23;,
 4;24,20,23,25;,
 4;26,24,25,27;,
 4;21,20,24,26;,
 4;28,29,14,8;,
 4;30,31,13,18;,
 4;30,29,28,31;,
 4;29,32,15,14;,
 4;33,30,18,17;,
 4;32,33,17,15;,
 4;32,29,30,33;;
 
 MeshMaterialList {
  11;
  18;
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
  9,
  8,
  8,
  9,
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
 }
 MeshNormals {
  18;
  -0.082368;0.000000;-0.996602;,
  -0.189464;0.981888;0.000000;,
  -0.189464;-0.981888;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.344072;0.938943;0.000000;,
  0.344072;-0.938943;-0.000000;,
  -0.149203;0.926763;-0.344745;,
  -0.149203;-0.926763;-0.344745;,
  -0.912226;0.000000;-0.409687;,
  -0.261366;0.965037;-0.019783;,
  -0.261366;-0.965037;-0.019783;,
  0.201713;0.873099;-0.443857;,
  0.201713;-0.873099;-0.443857;,
  0.155059;0.000000;-0.987905;,
  -0.080414;0.000000;0.996762;,
  0.267636;0.000000;0.963520;,
  -0.188610;0.000000;-0.982052;,
  0.990950;0.000000;0.134233;;
  18;
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;13,13,13,13;,
  4;6,6,6,6;,
  4;8,8,8,8;,
  4;7,7,7,7;,
  4;14,14,14,14;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;15,15,15,15;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;16,16,16,16;,
  4;17,17,17,17;;
 }
 MeshTextureCoords {
  34;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;;
 }
}