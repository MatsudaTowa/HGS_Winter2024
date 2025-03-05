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
 20;
 0.59784;0.91204;-4.01257;,
 2.78967;0.15018;-5.96554;,
 0.59784;0.15018;-7.91850;,
 2.78967;0.15018;-2.05961;,
 0.59784;0.15018;-0.10665;,
 -1.59399;0.15018;-2.05961;,
 -1.59399;0.15018;-5.96554;,
 3.69756;-1.68911;-6.77448;,
 0.59784;-1.68911;-9.53638;,
 3.69756;-1.68911;-1.25067;,
 0.59784;-1.68911;1.51124;,
 -2.50187;-1.68911;-1.25067;,
 -2.50187;-1.68911;-6.77448;,
 2.78967;-3.52836;-5.96554;,
 0.59784;-3.52836;-7.91850;,
 2.78967;-3.52836;-2.05961;,
 0.59784;-3.52836;-0.10665;,
 -1.59399;-3.52836;-2.05961;,
 -1.59399;-3.52836;-5.96554;,
 0.59784;-4.29023;-4.01257;;
 
 24;
 3;0,1,2;,
 3;0,3,1;,
 3;0,4,3;,
 3;0,5,4;,
 3;0,6,5;,
 3;0,2,6;,
 4;2,1,7,8;,
 4;1,3,9,7;,
 4;3,4,10,9;,
 4;4,5,11,10;,
 4;5,6,12,11;,
 4;6,2,8,12;,
 4;8,7,13,14;,
 4;7,9,15,13;,
 4;9,10,16,15;,
 4;10,11,17,16;,
 4;11,12,18,17;,
 4;12,8,14,18;,
 3;14,13,19;,
 3;13,15,19;,
 3;15,16,19;,
 3;16,17,19;,
 3;17,18,19;,
 3;18,14,19;;
 
 MeshMaterialList {
  3;
  24;
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
   0.800000;0.530196;0.395294;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.175686;0.241569;0.125490;1.000000;;
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
 }
 MeshNormals {
  30;
  -0.000000;1.000000;0.000000;,
  -0.000000;0.881386;-0.472397;,
  0.542893;0.808716;-0.226374;,
  0.542893;0.808716;0.226374;,
  -0.000000;0.881386;0.472397;,
  -0.542894;0.808716;0.226373;,
  -0.542893;0.808716;-0.226374;,
  0.556056;0.548945;-0.624068;,
  0.778407;0.531291;-0.334383;,
  0.778407;0.531292;0.334382;,
  0.556056;0.548945;0.624068;,
  -0.778407;0.531292;0.334382;,
  -0.778407;0.531292;-0.334382;,
  0.203279;-0.908091;-0.366125;,
  0.542892;-0.808718;-0.226373;,
  0.542892;-0.808718;0.226373;,
  0.203279;-0.908092;0.366125;,
  -0.542892;-0.808717;0.226372;,
  -0.542892;-0.808717;-0.226373;,
  -0.000000;-1.000000;0.000000;,
  -0.556057;0.548945;0.624067;,
  -0.556056;0.548945;-0.624068;,
  0.556052;-0.548953;-0.624064;,
  0.778403;-0.531300;-0.334380;,
  0.778403;-0.531300;0.334380;,
  0.556052;-0.548954;0.624064;,
  -0.556053;-0.548954;0.624063;,
  -0.778403;-0.531300;0.334379;,
  -0.778403;-0.531300;-0.334380;,
  -0.556053;-0.548953;-0.624064;;
  24;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,1,6;,
  4;1,2,8,7;,
  4;2,3,9,8;,
  4;3,4,10,9;,
  4;4,5,11,20;,
  4;5,6,12,11;,
  4;6,1,21,12;,
  4;22,23,14,13;,
  4;23,24,15,14;,
  4;24,25,16,15;,
  4;26,27,17,26;,
  4;27,28,18,17;,
  4;28,29,29,18;,
  3;13,14,19;,
  3;14,15,19;,
  3;15,16,19;,
  3;16,17,19;,
  3;17,18,19;,
  3;18,13,19;;
 }
}
