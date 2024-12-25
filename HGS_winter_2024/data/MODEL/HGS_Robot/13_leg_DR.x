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
 103;
 3.95876;-60.46610;10.37354;,
 -6.19085;-60.46610;10.37354;,
 -6.19085;-60.46610;-6.34241;,
 3.95876;-60.46610;-6.34241;,
 8.08660;-5.00788;11.76941;,
 8.08660;-5.00788;-14.08613;,
 6.77010;3.60200;-11.91828;,
 6.77010;3.60200;9.60158;,
 -7.47754;3.60200;-11.91828;,
 -7.47754;3.60200;9.60158;,
 3.95876;-60.46610;-6.34241;,
 -6.19085;-60.46610;-6.34241;,
 -4.48739;-56.24795;-13.47862;,
 2.25530;-56.24795;-13.47862;,
 4.37884;1.57043;-19.31912;,
 -5.08627;1.57043;-19.31912;,
 -8.79406;-5.00788;-14.08613;,
 -5.96086;-8.07737;-20.89470;,
 5.25349;-8.07737;-20.89470;,
 -7.47754;-4.58560;18.80491;,
 6.77010;-4.58560;18.80491;,
 6.62939;-13.19549;21.47188;,
 -8.79406;-5.00788;11.76941;,
 -7.33684;-13.19549;21.47188;,
 -5.68807;-23.30810;20.89112;,
 4.98062;-23.30810;20.89112;,
 5.78009;-34.89002;12.24249;,
 -6.48752;-34.89002;12.24249;,
 1.11007;-42.04264;20.96973;,
 -4.46517;-40.66387;22.44426;,
 -2.77722;-29.42295;14.82952;,
 0.81740;-30.31189;13.87885;,
 -6.98888;-36.85086;26.26574;,
 -4.40435;-26.96457;17.29338;,
 -4.98277;-32.83717;30.19545;,
 -3.11094;-24.37673;19.82697;,
 0.37807;-30.97406;31.93138;,
 0.34547;-23.17552;20.94631;,
 5.93193;-32.35380;30.45631;,
 3.91871;-24.06542;19.99500;,
 8.45567;-36.07392;26.58710;,
 5.54582;-26.52390;17.53123;,
 6.44958;-40.18045;22.70519;,
 4.25240;-29.11167;14.99754;,
 0.58139;-26.74374;17.41258;,
 0.74408;-36.50838;26.45056;,
 3.16394;-62.61422;-5.00002;,
 3.16394;-69.22980;-1.47346;,
 -3.06161;-69.22980;-1.47346;,
 -3.06161;-62.61422;-5.00002;,
 3.16394;-69.22980;5.57966;,
 -3.06161;-69.22980;5.57966;,
 3.16394;-62.61422;9.10622;,
 -3.06161;-62.61422;9.10622;,
 3.16394;-55.99868;5.57966;,
 -3.06161;-55.99868;5.57966;,
 3.16394;-55.99868;-1.47346;,
 -3.06161;-55.99868;-1.47346;,
 3.16394;-62.61422;-5.00002;,
 -3.06161;-62.61422;-5.00002;,
 -3.06161;-62.61422;2.05310;,
 -3.06161;-62.61422;2.05310;,
 -3.06161;-62.61422;2.05310;,
 -3.06161;-62.61422;2.05310;,
 -3.06161;-62.61422;2.05310;,
 -3.06161;-62.61422;2.05310;,
 3.16394;-62.61422;2.05310;,
 3.16394;-62.61422;2.05310;,
 3.16394;-62.61422;2.05310;,
 3.16394;-62.61422;2.05310;,
 3.16394;-62.61422;2.05310;,
 3.16394;-62.61422;2.05310;,
 -6.19085;-60.46610;-6.34241;,
 -12.09042;-51.95328;11.42410;,
 -12.09042;-51.95328;-2.54452;,
 -11.43132;0.80677;-8.82617;,
 -11.43132;0.80677;10.77903;,
 -14.15838;-8.01079;12.59062;,
 -14.15838;-8.01079;-10.63775;,
 -6.69214;-40.84023;10.81963;,
 -6.19085;-60.46610;10.37354;,
 3.95876;-60.46610;10.37354;,
 5.30716;-40.84023;10.81963;,
 8.08660;-5.00788;11.76941;,
 -8.79406;-5.00788;11.76941;,
 5.30716;-40.84023;10.81963;,
 3.95876;-60.46610;-6.34241;,
 5.30716;-40.84023;-9.43755;,
 8.08660;-5.00788;-14.08613;,
 -6.69214;-40.84023;-9.43755;,
 -8.79406;-5.00788;-14.08613;,
 -5.96086;-8.07737;-20.89470;,
 -4.77699;-40.84023;-14.68298;,
 5.30716;-40.84023;-9.43755;,
 2.54495;-40.84023;-14.68298;,
 5.25349;-8.07737;-20.89470;,
 8.08660;-5.00788;-14.08613;,
 -6.69214;-40.84023;10.81963;,
 -10.25794;-40.84023;11.64119;,
 -6.69214;-40.84023;-9.43755;,
 -10.25794;-40.84023;-4.05084;,
 -14.15838;-8.01079;-10.63775;,
 -8.79406;-5.00788;-14.08613;;
 
 80;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;6,8,9,7;,
 4;10,11,12,13;,
 4;8,6,14,15;,
 4;16,8,15,17;,
 4;6,5,18,14;,
 4;18,17,15,14;,
 4;7,9,19,20;,
 4;4,7,20,21;,
 4;9,22,23,19;,
 4;23,21,20,19;,
 4;21,23,24,25;,
 4;4,21,25,26;,
 4;22,4,26,27;,
 4;23,22,27,24;,
 4;27,26,25,24;,
 4;28,29,30,31;,
 4;29,32,33,30;,
 4;32,34,35,33;,
 4;34,36,37,35;,
 4;36,38,39,37;,
 4;38,40,41,39;,
 4;40,42,43,41;,
 4;42,28,31,43;,
 3;31,30,44;,
 3;30,33,44;,
 3;33,35,44;,
 3;35,37,44;,
 3;37,39,44;,
 3;39,41,44;,
 3;41,43,44;,
 3;43,31,44;,
 3;29,28,45;,
 3;32,29,45;,
 3;34,32,45;,
 3;36,34,45;,
 3;38,36,45;,
 3;40,38,45;,
 3;42,40,45;,
 3;28,42,45;,
 4;46,47,48,49;,
 4;47,50,51,48;,
 4;50,52,53,51;,
 4;52,54,55,53;,
 4;54,56,57,55;,
 4;56,58,59,57;,
 3;49,48,60;,
 3;48,51,61;,
 3;51,53,62;,
 3;53,55,63;,
 3;55,57,64;,
 3;57,59,65;,
 3;47,46,66;,
 3;50,47,67;,
 3;52,50,68;,
 3;54,52,69;,
 3;56,54,70;,
 3;58,56,71;,
 4;72,1,73,74;,
 4;9,8,75,76;,
 4;22,9,76,77;,
 4;8,16,78,75;,
 4;78,77,76,75;,
 4;79,80,81,82;,
 4;83,84,79,82;,
 4;85,0,86,87;,
 4;88,4,85,87;,
 4;89,90,91,92;,
 4;12,11,89,92;,
 4;93,10,13,94;,
 4;95,96,93,94;,
 4;94,13,12,92;,
 4;91,95,94,92;,
 4;97,22,77,98;,
 4;73,1,97,98;,
 4;99,72,74,100;,
 4;101,102,99,100;,
 4;100,74,73,98;,
 4;77,101,100,98;;
 
 MeshMaterialList {
  12;
  80;
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  10,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
  11,
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
  7,
  7,
  7,
  7,
  7,
  8,
  8,
  9,
  9,
  9,
  9,
  9,
  9,
  10,
  10,
  7,
  7,
  7,
  7,
  7,
  7;;
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
  70;
  0.988511;0.151149;0.000000;,
  0.000000;-1.000000;0.000000;,
  -0.897873;0.190245;-0.397027;,
  -0.977573;0.115673;0.175986;,
  0.000000;1.000000;0.000000;,
  0.897875;0.190246;-0.397022;,
  0.000000;-0.860858;-0.508845;,
  0.000000;0.964327;-0.264713;,
  0.977574;0.115671;0.175983;,
  0.000000;0.747132;0.664675;,
  0.000000;-0.015829;-0.999875;,
  0.987971;-0.117674;0.100327;,
  0.000000;-0.057334;0.998355;,
  -0.014133;0.703128;-0.710922;,
  -0.334397;-0.493623;-0.802817;,
  -0.889046;-0.157662;-0.429814;,
  -0.929512;0.349589;0.117450;,
  -0.426039;0.737112;0.524554;,
  0.335949;0.768590;0.544434;,
  0.889160;0.426499;0.165812;,
  0.919347;-0.084595;-0.384245;,
  0.014140;-0.703125;0.710925;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.470406;-0.882450;,
  0.000000;-0.470407;0.882450;,
  0.000000;0.470409;0.882449;,
  1.000000;0.000000;0.000000;,
  -0.671160;0.306278;-0.675084;,
  -0.821917;-0.569607;0.000000;,
  0.087566;0.205729;0.974684;,
  -0.577280;0.816546;0.000000;,
  0.997648;-0.068543;-0.000000;,
  -0.934283;-0.098930;-0.342533;,
  0.000000;-0.022724;0.999742;,
  0.920999;-0.082574;-0.380712;,
  -0.758117;-0.035619;-0.651145;,
  0.192594;-0.009132;0.981236;,
  0.000000;0.161175;-0.986926;,
  0.000000;0.295886;0.955223;,
  -0.987971;-0.117675;0.100327;,
  0.000000;-0.598325;0.801254;,
  0.416181;-0.462662;-0.782776;,
  -0.014147;0.703137;-0.710914;,
  -0.014145;0.703109;-0.710941;,
  -0.014128;0.703123;-0.710928;,
  -0.014163;0.703121;-0.710929;,
  -0.014144;0.703109;-0.710941;,
  -0.014146;0.703132;-0.710919;,
  -0.014151;0.703128;-0.710923;,
  0.014150;-0.703132;0.710919;,
  0.014149;-0.703124;0.710927;,
  0.014152;-0.703122;0.710928;,
  0.014143;-0.703122;0.710928;,
  0.027653;-0.711510;0.702131;,
  0.026321;-0.693475;0.720000;,
  0.014153;-0.703125;0.710926;,
  0.000000;0.470408;-0.882449;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;-0.000000;,
  -0.955353;0.295468;0.000000;,
  0.000000;-0.026497;0.999649;,
  0.997005;-0.077336;-0.000000;,
  -0.950391;-0.055732;-0.306025;,
  0.906363;-0.138143;-0.399278;,
  0.000000;-0.077928;-0.996959;,
  0.000000;-0.186278;-0.982497;,
  0.186813;-0.037350;0.981685;,
  -0.666297;-0.178006;-0.724128;,
  -0.986676;0.162697;0.000000;,
  -0.993016;-0.117980;0.000000;;
  80;
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;4,4,4,4;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;2,2,2,2;,
  4;5,5,5,5;,
  4;37,37,37,37;,
  4;9,9,9,9;,
  4;8,8,8,8;,
  4;3,3,3,3;,
  4;38,38,38,38;,
  4;12,12,12,12;,
  4;11,11,11,11;,
  4;10,10,10,10;,
  4;39,39,39,39;,
  4;40,40,40,40;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;41,41,41,41;,
  3;13,13,13;,
  3;42,42,42;,
  3;43,43,43;,
  3;44,44,44;,
  3;45,45,45;,
  3;46,46,46;,
  3;47,47,47;,
  3;48,48,48;,
  3;21,21,21;,
  3;49,49,49;,
  3;50,50,50;,
  3;51,51,51;,
  3;52,52,52;,
  3;53,53,53;,
  3;54,54,54;,
  3;55,55,55;,
  4;23,23,23,23;,
  4;1,1,1,1;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;4,4,4,4;,
  4;56,56,56,56;,
  3;22,22,22;,
  3;22,22,22;,
  3;22,22,22;,
  3;22,22,22;,
  3;57,57,57;,
  3;22,22,22;,
  3;26,26,26;,
  3;26,26,26;,
  3;26,26,26;,
  3;26,26,26;,
  3;58,58,58;,
  3;26,26,26;,
  4;28,28,28,28;,
  4;30,30,30,30;,
  4;29,29,29,29;,
  4;27,27,27,27;,
  4;59,59,59,59;,
  4;33,33,33,33;,
  4;60,60,60,60;,
  4;31,31,31,31;,
  4;61,61,61,61;,
  4;32,32,32,32;,
  4;62,62,62,62;,
  4;34,34,34,34;,
  4;63,63,63,63;,
  4;64,64,64,64;,
  4;65,65,65,65;,
  4;36,36,36,36;,
  4;66,66,66,66;,
  4;35,35,35,35;,
  4;67,67,67,67;,
  4;68,68,68,68;,
  4;69,69,69,69;;
 }
 MeshTextureCoords {
  103;
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.979550;3.109840;,
  2.320450;3.099660;,
  2.199610;2.323060;,
  1.979820;2.329620;,
  2.461670;3.074850;,
  2.290660;2.307070;,
  2.320470;3.049950;,
  2.199630;2.291010;,
  1.979580;3.039540;,
  1.979840;2.284300;,
  1.638670;3.049720;,
  1.760040;2.290860;,
  1.497460;3.074520;,
  1.669000;2.306850;,
  1.638660;3.099420;,
  1.760030;2.322910;,
  1.979830;2.306960;,
  1.979560;3.074690;,
  0.000000;1.000000;,
  0.166670;1.000000;,
  0.166670;0.000000;,
  0.000000;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.500000;1.000000;,
  0.500000;0.000000;,
  0.666670;1.000000;,
  0.666670;0.000000;,
  0.833330;1.000000;,
  0.833330;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
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
  0.916670;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.680420;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.680420;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.680420;,
  1.000000;1.000000;,
  1.000000;0.680420;,
  1.000000;0.000000;,
  1.000000;0.680420;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.722050;,
  0.000000;0.680420;,
  0.000000;0.722050;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.680420;,
  1.000000;0.813880;,
  0.000000;0.680420;,
  0.000000;0.813880;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}