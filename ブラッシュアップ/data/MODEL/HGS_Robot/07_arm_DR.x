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
 118;
 -52.71431;-6.84958;-2.94716;,
 -52.71431;-6.84958;11.58752;,
 -52.71431;7.11656;11.58752;,
 -52.71431;7.11656;-2.94716;,
 -2.96801;9.61704;-6.29671;,
 -2.96801;9.61704;14.93702;,
 4.04743;7.72823;12.67667;,
 4.04743;7.72823;-4.03633;,
 -2.96801;-8.12690;-6.29671;,
 -2.96801;9.61704;-6.29671;,
 4.04743;7.72823;-4.03633;,
 4.04743;-6.23794;-4.03633;,
 -2.96801;-8.12690;14.93702;,
 -2.96801;-8.12690;-6.29671;,
 4.04743;-6.23794;-4.03633;,
 4.04743;-6.23794;12.67667;,
 -2.96801;9.61704;14.93702;,
 -2.96801;-8.12690;14.93702;,
 4.04743;-6.23794;12.67667;,
 4.04743;7.72823;12.67667;,
 -9.44036;-7.77029;-3.98775;,
 -9.44036;9.26049;-3.98775;,
 -9.44036;-7.77029;12.83265;,
 -9.44036;9.26061;12.83265;,
 -2.96801;9.61704;-6.29671;,
 -9.44036;9.26049;-3.98775;,
 -9.44036;9.26061;12.83265;,
 -2.96801;-8.12690;-6.29671;,
 -9.44036;-7.77029;12.83265;,
 -9.44036;-7.77029;-3.98775;,
 -28.92350;-7.06406;-3.50820;,
 -28.92350;8.55428;-3.50820;,
 -28.92350;8.55430;12.25875;,
 -28.92350;-7.06406;12.25875;,
 -28.92350;8.55428;-3.50820;,
 -28.92350;8.55430;12.25875;,
 -28.92350;-7.06406;12.25875;,
 -28.92350;-7.06406;-3.50820;,
 -40.41841;-6.64734;-3.22523;,
 -40.41841;8.13767;-3.22523;,
 -40.41841;8.13770;11.92020;,
 -40.41841;-6.64734;11.92020;,
 -40.41841;8.13767;-3.22523;,
 -52.71431;7.11656;-2.94716;,
 -52.71431;7.11656;11.58752;,
 -40.41841;8.13770;11.92020;,
 -40.41841;-6.64734;11.92020;,
 -52.71431;-6.84958;11.58752;,
 -52.71431;-6.84958;-2.94716;,
 -40.41841;-6.64734;-3.22523;,
 -50.50845;9.16894;-4.81626;,
 -50.50845;-8.90200;-4.81623;,
 -13.77721;-9.51065;-5.02188;,
 -13.77721;9.16591;-5.02188;,
 -50.65679;-8.90200;13.52017;,
 -50.65679;9.16894;13.52017;,
 -13.92550;9.16591;13.76622;,
 -13.92550;-9.51065;13.76622;,
 -50.65679;9.16894;13.52017;,
 -50.50845;9.16894;-4.81626;,
 -13.77721;9.16591;-5.02188;,
 -13.92550;9.16591;13.76622;,
 -50.50845;-8.90200;-4.81623;,
 -50.65679;-8.90200;13.52017;,
 -13.92550;-9.51065;13.76622;,
 -13.77721;-9.51065;-5.02188;,
 -23.35895;11.37715;-6.35694;,
 -23.35895;-9.88674;-6.35694;,
 -23.35895;-9.88796;15.08995;,
 -23.35895;11.37827;15.08995;,
 -23.35895;-9.88674;-6.35694;,
 -23.35895;-9.88796;15.08995;,
 -42.45189;-9.77832;-6.28333;,
 -42.45189;11.26861;-6.28334;,
 -42.45189;11.26978;15.00175;,
 -42.45189;-9.77954;15.00175;,
 -42.45189;-9.77954;15.00175;,
 -42.45189;-9.77832;-6.28333;,
 -52.33806;0.05664;-2.59551;,
 -52.33806;-4.94685;0.29321;,
 -59.01379;-4.94685;0.29321;,
 -59.01379;0.05664;-2.59551;,
 -52.33806;-4.94685;6.07067;,
 -59.01379;-4.94685;6.07067;,
 -52.33806;0.05664;8.95938;,
 -59.01379;0.05664;8.95938;,
 -52.33806;5.06009;6.07067;,
 -59.01379;5.06009;6.07067;,
 -52.33806;5.06009;0.29321;,
 -59.01379;5.06009;0.29321;,
 -52.33806;0.05664;-2.59551;,
 -59.01379;0.05664;-2.59551;,
 -59.01379;0.05664;3.18192;,
 -59.01379;0.05664;3.18192;,
 -59.01379;0.05664;3.18192;,
 -59.01379;0.05664;3.18192;,
 -59.01379;0.05664;3.18192;,
 -59.01379;0.05664;3.18192;,
 -23.35895;11.37715;-6.35694;,
 -20.08203;12.91875;-8.85233;,
 -7.01747;10.05244;-7.20123;,
 -7.20034;10.05244;15.96511;,
 -23.35895;11.37827;15.08995;,
 -20.08203;12.92007;17.59240;,
 -42.45189;11.26978;15.00175;,
 -46.18939;12.75537;17.47347;,
 -57.62162;9.99419;15.64136;,
 -57.43859;9.99419;-6.96806;,
 -42.45189;11.26861;-6.28334;,
 -46.18939;12.75406;-8.77177;,
 -22.10619;18.36773;-1.23488;,
 -11.19274;16.31709;-0.53359;,
 -11.33810;16.31709;9.29055;,
 -22.10619;18.36875;9.97953;,
 -43.93507;18.24361;9.92682;,
 -53.56995;16.25640;9.14872;,
 -53.42451;16.25635;-0.43926;,
 -43.93507;18.24278;-1.20299;;
 
 66;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;18,11,10,19;,
 4;9,8,20,21;,
 4;22,17,16,23;,
 4;5,24,25,26;,
 4;27,12,28,29;,
 4;21,20,30,31;,
 4;22,23,32,33;,
 4;26,25,34,35;,
 4;29,28,36,37;,
 4;38,0,3,39;,
 4;40,2,1,41;,
 4;42,43,44,45;,
 4;46,47,48,49;,
 4;38,39,50,51;,
 4;31,30,52,53;,
 4;40,41,54,55;,
 4;33,32,56,57;,
 4;42,45,58,59;,
 4;35,34,60,61;,
 4;46,49,62,63;,
 4;37,36,64,65;,
 4;66,53,52,67;,
 4;68,57,56,69;,
 4;70,65,64,71;,
 4;72,51,50,73;,
 4;66,67,72,73;,
 4;74,55,54,75;,
 4;68,69,74,75;,
 4;76,63,62,77;,
 4;70,71,76,77;,
 4;78,79,80,81;,
 4;79,82,83,80;,
 4;82,84,85,83;,
 4;84,86,87,85;,
 4;86,88,89,87;,
 4;88,90,91,89;,
 3;81,80,92;,
 3;80,83,93;,
 3;83,85,94;,
 3;85,87,95;,
 3;87,89,96;,
 3;89,91,97;,
 4;60,98,99,100;,
 4;61,60,100,101;,
 4;102,61,101,103;,
 4;58,104,105,106;,
 4;59,58,106,107;,
 4;108,59,107,109;,
 4;98,108,109,99;,
 4;104,102,103,105;,
 4;100,99,110,111;,
 4;101,100,111,112;,
 4;103,101,112,113;,
 4;113,112,111,110;,
 4;106,105,114,115;,
 4;107,106,115,116;,
 4;109,107,116,117;,
 4;117,116,115,114;,
 4;99,109,117,110;,
 4;105,103,113,114;,
 4;113,110,117,114;;
 
 MeshMaterialList {
  12;
  66;
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
  8,
  8,
  8,
  8,
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
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  7,
  7,
  7,
  7,
  7,
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
  61;
  0.259979;0.965614;0.000000;,
  0.306675;0.000000;-0.951814;,
  -1.000000;0.000000;0.000000;,
  0.259998;-0.965609;-0.000000;,
  -0.336001;0.000000;-0.941862;,
  -0.309200;0.000000;0.950997;,
  -0.024607;0.000000;-0.999697;,
  -0.029443;0.000000;0.999566;,
  -0.022610;0.000000;-0.999744;,
  -0.027046;0.000000;0.999634;,
  0.099442;0.000000;0.995043;,
  0.100008;0.000000;-0.994987;,
  -0.155757;0.000001;0.987795;,
  -0.154398;0.000000;-0.988009;,
  0.138001;0.000000;-0.990432;,
  0.138961;0.000000;0.990298;,
  -0.179153;-0.000001;-0.983821;,
  -0.177699;0.000000;0.984085;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.499994;-0.866029;,
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.499993;0.866030;,
  0.000000;0.499996;0.866027;,
  0.000000;1.000000;0.000000;,
  -0.095377;-0.785002;-0.612108;,
  0.130362;-0.991466;0.001029;,
  -0.117954;-0.993019;-0.000955;,
  0.091786;-0.786928;0.610180;,
  -0.097625;-0.784388;0.612540;,
  0.094630;-0.786851;-0.609845;,
  0.216595;0.800695;-0.558547;,
  0.831835;0.554943;0.009425;,
  -0.839293;0.543592;-0.009752;,
  -0.245286;0.796614;0.552487;,
  0.218742;0.800523;0.557956;,
  -0.247859;0.797305;-0.550337;,
  0.306671;0.000000;0.951815;,
  1.000000;0.000000;0.000000;,
  -0.054995;0.998487;-0.000004;,
  -0.055015;-0.998486;0.000000;,
  -0.036226;0.999344;-0.000004;,
  -0.036224;-0.999344;0.000000;,
  -0.082762;0.996569;-0.000001;,
  0.016446;-0.999865;-0.000000;,
  -0.101009;-0.994886;-0.000405;,
  0.040563;-0.999177;0.000160;,
  -0.216438;0.976296;-0.000881;,
  0.160293;0.987069;0.000630;,
  0.039619;-0.999215;0.000129;,
  -0.003855;-0.000000;-0.999993;,
  -0.004619;0.000000;0.999989;,
  -0.107168;-0.994241;-0.000458;,
  -0.005679;-0.999984;-0.000057;,
  0.000000;0.499997;-0.866027;,
  0.003318;-0.854265;-0.519828;,
  0.002733;-0.853934;0.520375;,
  0.185829;0.982581;0.001320;,
  -0.203328;0.979109;-0.001569;,
  -0.006212;0.811566;-0.584228;,
  -0.006923;0.811117;0.584842;,
  -0.005728;0.999984;-0.000083;;
  66;
  4;2,2,2,2;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;3,3,3,3;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;38,38,38,38;,
  4;39,39,39,39;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;40,40,40,40;,
  4;41,41,41,41;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;42,42,42,42;,
  4;43,43,43,43;,
  4;12,12,12,12;,
  4;10,10,10,10;,
  4;13,13,13,13;,
  4;11,11,11,11;,
  4;44,44,44,44;,
  4;45,45,45,45;,
  4;46,46,46,46;,
  4;47,47,47,47;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;48,48,48,48;,
  4;16,16,16,16;,
  4;49,49,49,49;,
  4;17,17,17,17;,
  4;50,50,50,50;,
  4;51,51,51,51;,
  4;52,52,52,52;,
  4;19,19,19,19;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;53,53,53,53;,
  3;18,18,18;,
  3;2,2,2;,
  3;2,2,2;,
  3;2,2,2;,
  3;2,2,2;,
  3;2,2,2;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;28,28,28,28;,
  4;27,27,27,27;,
  4;26,26,26,26;,
  4;29,29,29,29;,
  4;54,54,54,54;,
  4;55,55,55,55;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;34,34,34,34;,
  4;56,56,56,56;,
  4;33,33,33,33;,
  4;32,32,32,32;,
  4;35,35,35,35;,
  4;57,57,57,57;,
  4;58,58,58,58;,
  4;59,59,59,59;,
  4;60,60,60,60;;
 }
 MeshTextureCoords {
  118;
  2.109079;-0.940658;,
  2.109079;-0.940658;,
  2.109079;-1.115191;,
  2.109079;-1.115191;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.487405;-0.924696;,
  1.487405;-1.146440;,
  1.399734;-1.122836;,
  1.399734;-0.948302;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.487405;-1.146440;,
  1.487405;-0.924696;,
  1.399734;-0.948302;,
  1.399734;-1.122836;,
  1.568289;-0.929153;,
  1.568289;-1.141985;,
  1.568289;-0.929153;,
  1.568289;-1.141985;,
  0.000000;1.000000;,
  0.188760;1.000000;,
  0.188760;0.000000;,
  0.000000;0.000000;,
  0.188760;1.000000;,
  0.188760;0.000000;,
  1.811768;-0.937978;,
  1.811768;-1.133159;,
  1.811768;-1.133159;,
  1.811768;-0.937978;,
  0.562650;1.000000;,
  0.562650;0.000000;,
  0.562650;1.000000;,
  0.562650;0.000000;,
  1.955418;-0.943186;,
  1.955418;-1.127952;,
  1.955418;-1.127953;,
  1.955418;-0.943186;,
  0.783240;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.783240;0.000000;,
  0.783240;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.783240;0.000000;,
  2.081512;-1.140840;,
  2.081512;-0.915009;,
  1.622486;-0.907404;,
  1.622486;-1.140802;,
  2.083366;-0.915009;,
  2.083366;-1.140840;,
  1.624339;-1.140802;,
  1.624339;-0.907404;,
  0.783240;0.000000;,
  0.783240;1.000000;,
  0.562650;1.000000;,
  0.562650;0.000000;,
  0.783240;0.000000;,
  0.783240;1.000000;,
  0.562650;1.000000;,
  0.562650;0.000000;,
  1.742228;-1.168435;,
  1.742228;-0.902704;,
  1.742228;-0.902688;,
  1.742228;-1.168449;,
  0.629750;0.000000;,
  0.628960;1.000000;,
  1.980830;-0.904058;,
  1.980830;-1.167079;,
  1.980830;-1.167094;,
  1.980830;-0.904043;,
  0.697710;1.000000;,
  0.698500;0.000000;,
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
  0.629750;1.000000;,
  0.629750;1.000000;,
  0.562650;1.000000;,
  0.562650;0.000000;,
  0.628960;0.000000;,
  0.628960;0.000000;,
  0.697710;0.000000;,
  0.697710;0.000000;,
  0.783240;0.000000;,
  0.783240;1.000000;,
  0.698500;1.000000;,
  0.698500;1.000000;,
  0.629750;1.000000;,
  0.562650;1.000000;,
  0.562650;0.000000;,
  0.628960;0.000000;,
  0.697710;0.000000;,
  0.783240;0.000000;,
  0.783240;1.000000;,
  0.698500;1.000000;;
 }
}
