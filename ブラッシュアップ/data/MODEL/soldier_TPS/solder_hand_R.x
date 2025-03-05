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
 -3.89279;4.87805;0.00000;,
 -3.89279;3.46400;-3.41381;,
 -6.84926;3.46400;-1.70691;,
 -6.84926;3.46400;1.70691;,
 -3.89279;3.46400;3.41381;,
 -0.93635;3.46400;1.70691;,
 -0.93635;3.46400;-1.70691;,
 -3.89279;0.05020;-4.82786;,
 -8.07383;0.05020;-2.41393;,
 -8.07383;0.05020;2.41393;,
 -3.89279;0.05020;4.82786;,
 0.28826;0.05020;2.41393;,
 0.28826;0.05020;-2.41393;,
 -3.89279;-3.36364;-3.41381;,
 -6.84926;-3.36364;-1.70691;,
 -6.84926;-3.36364;1.70691;,
 -3.89279;-3.36364;3.41381;,
 -0.93635;-3.36364;1.70691;,
 -0.93635;-3.36364;-1.70691;,
 -3.89279;-4.77768;0.00000;;
 
 24;
 3;0,1,2;,
 3;0,2,3;,
 3;0,3,4;,
 3;0,4,5;,
 3;0,5,6;,
 3;0,6,1;,
 4;1,7,8,2;,
 4;2,8,9,3;,
 4;3,9,10,4;,
 4;4,10,11,5;,
 4;5,11,12,6;,
 4;6,12,7,1;,
 4;7,13,14,8;,
 4;8,14,15,9;,
 4;9,15,16,10;,
 4;10,16,17,11;,
 4;11,17,18,12;,
 4;12,18,13,7;,
 3;13,19,14;,
 3;14,19,15;,
 3;15,19,16;,
 3;16,19,17;,
 3;17,19,18;,
 3;18,19,13;;
 
 MeshMaterialList {
  3;
  24;
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
  0,
  0,
  0,
  0;;
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
  20;
  0.000001;1.000000;0.000000;,
  0.000001;0.721780;-0.692123;,
  -0.599396;0.721779;-0.346062;,
  -0.599396;0.721779;0.346062;,
  0.000001;0.721780;0.692123;,
  0.599396;0.721780;0.346061;,
  0.599396;0.721780;-0.346061;,
  0.000001;0.000003;-1.000000;,
  -0.866026;0.000003;-0.500000;,
  -0.866026;0.000003;0.500000;,
  0.000001;0.000003;1.000000;,
  0.866026;0.000003;0.500000;,
  0.866026;0.000003;-0.500000;,
  0.000001;-0.721779;-0.692124;,
  -0.599397;-0.721778;-0.346062;,
  -0.599397;-0.721778;0.346063;,
  0.000001;-0.721779;0.692124;,
  0.599397;-0.721779;0.346061;,
  0.599397;-0.721779;-0.346061;,
  0.000001;-1.000000;-0.000000;;
  24;
  3;0,1,2;,
  3;0,2,3;,
  3;0,3,4;,
  3;0,4,5;,
  3;0,5,6;,
  3;0,6,1;,
  4;1,7,8,2;,
  4;2,8,9,3;,
  4;3,9,10,4;,
  4;4,10,11,5;,
  4;5,11,12,6;,
  4;6,12,7,1;,
  4;7,13,14,8;,
  4;8,14,15,9;,
  4;9,15,16,10;,
  4;10,16,17,11;,
  4;11,17,18,12;,
  4;12,18,13,7;,
  3;13,19,14;,
  3;14,19,15;,
  3;15,19,16;,
  3;16,19,17;,
  3;17,19,18;,
  3;18,19,13;;
 }
}
