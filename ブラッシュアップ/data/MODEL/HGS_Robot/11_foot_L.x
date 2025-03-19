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
 54;
 -7.56688;-12.65725;-31.15300;,
 7.80942;-12.65725;-31.15300;,
 6.79372;-16.85175;-27.96583;,
 -6.86467;-16.85175;-27.96583;,
 7.65549;-12.65725;18.82899;,
 -7.46053;-12.65725;18.82899;,
 -6.13381;-16.85175;15.03019;,
 5.73658;-16.85175;15.03019;,
 12.34695;-12.65725;2.11954;,
 10.52803;-16.85175;0.16706;,
 -10.70405;-12.65725;2.11954;,
 -9.44642;-16.85175;0.16706;,
 7.63739;3.04602;0.12088;,
 -7.60448;3.04602;0.12088;,
 -7.47169;1.24829;0.73544;,
 7.50459;1.24829;0.73544;,
 6.98053;-2.23633;-15.71386;,
 10.81728;-3.69565;-0.01511;,
 9.17900;-3.56008;1.21406;,
 6.64472;-3.56008;-13.46374;,
 -6.94767;-2.23633;-15.71386;,
 -6.61181;-3.56008;-13.46374;,
 -10.78437;-3.69565;-0.01510;,
 -9.14608;-3.56008;1.21406;,
 -7.68338;2.92570;0.64893;,
 7.68681;2.92457;0.60920;,
 -5.88752;3.40970;9.53382;,
 5.92784;3.40877;9.50328;,
 -6.79221;-1.64345;14.98506;,
 -10.31020;-2.88935;1.94993;,
 -6.48088;-3.56008;12.18796;,
 6.85462;-1.64446;14.94982;,
 6.51379;-3.56008;12.18796;,
 10.31829;-2.89084;1.89667;,
 6.41066;5.78551;-2.94354;,
 -6.37773;5.78551;-2.94354;,
 4.82912;6.23567;-11.02861;,
 -4.79619;6.23567;-11.02861;,
 5.94737;0.18695;-19.90337;,
 9.67250;-1.95330;-3.53309;,
 -5.91444;0.18695;-19.90337;,
 -9.63959;-1.95330;-3.53309;,
 11.63272;-10.60616;1.91539;,
 7.54680;-10.60616;-27.16465;,
 11.63272;-10.60616;1.91539;,
 7.54680;-10.60616;-27.16465;,
 -7.35159;-10.60614;-27.16465;,
 -7.35159;-10.60614;-27.16465;,
 -10.35277;-10.60616;1.91539;,
 -10.35277;-10.60616;1.91539;,
 -7.23963;-10.60614;17.33168;,
 -7.23963;-10.60614;17.33168;,
 7.39809;-10.60614;17.33168;,
 7.39809;-10.60614;17.33168;;
 
 46;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,4,7,9;,
 4;8,9,2,1;,
 4;10,0,3,11;,
 4;10,11,6,5;,
 4;9,7,6,11;,
 4;9,11,3,2;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;17,12,15,18;,
 4;20,16,19,21;,
 4;22,20,21,23;,
 4;13,22,23,14;,
 4;24,25,15,14;,
 4;25,24,26,27;,
 4;28,29,23,30;,
 4;29,24,14,23;,
 4;29,28,26,24;,
 4;31,28,30,32;,
 4;28,31,27,26;,
 4;33,31,32,18;,
 4;25,33,18,15;,
 4;31,33,25,27;,
 4;34,35,13,12;,
 4;34,36,37,35;,
 4;38,39,17,16;,
 4;39,34,12,17;,
 4;39,38,36,34;,
 4;40,38,16,20;,
 4;38,40,37,36;,
 4;41,40,20,22;,
 4;35,41,22,13;,
 4;40,41,35,37;,
 4;42,8,1,43;,
 4;44,45,19,18;,
 4;43,1,0,46;,
 4;45,47,21,19;,
 4;46,0,10,48;,
 4;47,49,23,21;,
 4;48,10,5,50;,
 4;49,51,30,23;,
 4;50,5,4,52;,
 4;51,53,32,30;,
 4;52,4,8,42;,
 4;53,44,18,32;;
 
 MeshMaterialList {
  12;
  46;
  10,
  10,
  10,
  10,
  10,
  10,
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
  9,
  9,
  8,
  9,
  8,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  10,
  8,
  10,
  8,
  10,
  8,
  10,
  8,
  10,
  8,
  10,
  8;;
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
  45;
  0.000000;-0.605004;-0.796222;,
  0.000000;-0.671280;0.741204;,
  -0.966650;-0.239792;-0.089928;,
  0.814094;-0.526103;0.245899;,
  0.000000;0.323475;0.946237;,
  0.000000;-0.861909;-0.507063;,
  0.390791;-0.911191;-0.130432;,
  0.000705;-0.823352;0.567531;,
  -0.650911;-0.733576;0.195401;,
  -0.390782;-0.911196;-0.130429;,
  -0.000064;0.998520;-0.054376;,
  -0.001293;-0.063470;-0.997983;,
  0.654237;-0.730896;0.194330;,
  0.000000;0.998454;0.055592;,
  0.000000;0.745527;0.666476;,
  0.000000;-0.865626;-0.500691;,
  0.969100;0.117464;-0.216902;,
  -0.969099;0.117485;-0.216898;,
  0.000001;0.889292;-0.457339;,
  0.931989;0.338741;-0.129042;,
  0.000000;0.589611;0.807687;,
  -0.958827;0.211166;0.189892;,
  -0.971351;0.217409;-0.095973;,
  0.933797;-0.335013;-0.125655;,
  -0.896735;-0.401055;0.187138;,
  0.000000;-1.000000;-0.000000;,
  0.564490;0.259266;0.783666;,
  -0.564488;0.259265;0.783668;,
  -0.394374;0.000818;-0.918950;,
  -0.894040;0.409788;0.181012;,
  0.001813;0.733230;0.679978;,
  0.368389;-0.010378;-0.929614;,
  0.894867;0.409620;0.177270;,
  0.911389;0.408359;-0.051108;,
  0.905955;0.394001;-0.154949;,
  0.000000;0.826325;-0.563193;,
  -0.911389;0.408361;-0.051110;,
  -0.905954;0.394003;-0.154949;,
  0.929119;0.339902;-0.145617;,
  0.000001;0.889291;-0.457342;,
  -0.966028;0.221204;-0.133639;,
  -0.953376;0.214708;0.212072;,
  0.000000;0.589618;0.807682;,
  0.912240;0.321904;0.253369;,
  0.917125;0.320207;0.237379;;
  46;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;3,3,3,3;,
  4;23,23,23,23;,
  4;2,2,2,2;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;25,25,25,25;,
  4;4,4,4,4;,
  4;6,6,6,6;,
  4;26,26,26,26;,
  4;5,5,5,5;,
  4;9,9,9,9;,
  4;27,27,27,27;,
  4;11,11,11,11;,
  4;10,10,10,10;,
  4;8,8,8,8;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;7,7,7,7;,
  4;30,30,30,30;,
  4;12,12,12,12;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;14,14,14,14;,
  4;13,13,13,13;,
  4;16,16,16,16;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;15,15,15,15;,
  4;35,35,35,35;,
  4;17,17,17,17;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;19,19,19,19;,
  4;38,38,38,38;,
  4;18,18,18,18;,
  4;39,39,39,39;,
  4;22,22,22,22;,
  4;40,40,40,40;,
  4;21,21,21,21;,
  4;41,41,41,41;,
  4;20,20,20,20;,
  4;42,42,42,42;,
  4;43,43,43,43;,
  4;44,44,44,44;;
 }
 MeshTextureCoords {
  54;
  0.920036;2.530063;,
  1.513215;2.530063;,
  1.474033;2.691879;,
  0.947125;2.691879;,
  1.507277;2.530063;,
  0.924139;2.530063;,
  0.975321;2.691879;,
  1.433251;2.691879;,
  1.688262;2.530063;,
  1.618093;2.691879;,
  0.799012;2.530063;,
  0.847528;2.691879;,
  1.000000;0.491370;,
  0.000000;0.491370;,
  0.000000;0.491370;,
  1.000000;0.491370;,
  1.000000;1.000000;,
  1.000000;0.491370;,
  1.000000;0.491370;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.491370;,
  0.000000;0.491370;,
  0.000000;0.491370;,
  1.000000;0.491370;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.491370;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.491370;,
  1.000000;0.491370;,
  0.000000;0.491370;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.491370;,
  0.000000;1.000000;,
  0.000000;0.491370;,
  1.660709;2.450939;,
  1.503085;2.450939;,
  1.000000;0.491370;,
  1.000000;1.000000;,
  0.928342;2.450938;,
  0.000000;1.000000;,
  0.812563;2.450939;,
  0.000000;0.491370;,
  0.932660;2.450938;,
  0.000000;0.000000;,
  1.497348;2.450938;,
  1.000000;0.000000;;
 }
}
