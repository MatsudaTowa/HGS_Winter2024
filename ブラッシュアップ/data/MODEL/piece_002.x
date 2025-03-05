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
 17;
 -59.91869;0.00000;-55.05433;,
 134.43615;0.00000;-55.05433;,
 134.43615;0.00000;55.05433;,
 -37.83909;0.00000;55.05433;,
 134.43616;113.08666;55.05433;,
 134.43615;0.00000;-55.05433;,
 134.43613;122.44224;-55.05433;,
 134.43613;122.44224;-55.05433;,
 134.43615;0.00000;-55.05433;,
 -59.91869;0.00000;-55.05433;,
 5.24598;105.49434;-55.05433;,
 22.98397;98.46575;55.05433;,
 -37.83909;0.00000;55.05433;,
 134.43615;0.00000;55.05433;,
 134.43616;113.08666;55.05433;,
 5.24598;105.49434;-55.05433;,
 22.98397;98.46575;55.05433;;
 
 6;
 4;0,1,2,3;,
 4;4,2,5,6;,
 4;7,8,9,10;,
 4;11,12,13,14;,
 4;15,9,12,16;,
 4;15,16,14,7;;
 
 MeshMaterialList {
  1;
  6;
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\container.jpg";
   }
  }
 }
 MeshNormals {
  7;
  0.000000;-1.000000;-0.000000;,
  1.000000;-0.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  -0.535512;0.832937;0.139438;,
  -0.838658;0.518045;0.168172;,
  -0.129612;0.988005;0.083948;;
  6;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,5,5,4;,
  4;4,4,6,6;;
 }
 MeshTextureCoords {
  17;
  0.277150;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.359270;1.000000;,
  1.000000;0.227100;,
  0.000000;1.000000;,
  0.000000;0.163160;,
  1.000000;0.163160;,
  1.000000;1.000000;,
  0.277150;1.000000;,
  0.519510;0.278990;,
  0.414520;0.327030;,
  0.640730;1.000000;,
  0.000000;1.000000;,
  0.000000;0.227100;,
  0.519510;1.000000;,
  0.677530;0.327030;;
 }
}
