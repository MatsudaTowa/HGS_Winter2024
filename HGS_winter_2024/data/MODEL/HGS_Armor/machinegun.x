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
 286;
 -10.86658;43.46240;17.30728;,
 -19.54994;43.42430;14.60302;,
 -25.01831;64.56747;31.86405;,
 -16.33495;64.60556;34.56830;,
 -12.96126;37.94842;24.11097;,
 -21.22542;51.73206;50.45290;,
 -21.64461;37.91033;21.40669;,
 -29.90876;51.69396;47.74863;,
 -18.02031;77.93250;56.14218;,
 -30.15624;77.94525;55.86266;,
 -32.57177;68.83038;55.16726;,
 -23.93724;68.60030;58.01461;,
 -20.45622;77.94306;36.61607;,
 -17.42706;73.69088;38.68413;,
 -27.32914;77.95581;36.33645;,
 -26.06157;73.92097;35.83677;,
 -15.82737;73.43707;38.69777;,
 -28.04954;73.18663;34.80931;,
 -26.06157;73.92097;35.83677;,
 -17.42706;73.69088;38.68413;,
 -26.58770;64.20235;30.79315;,
 -14.36554;64.45280;34.68163;,
 -16.33495;64.60556;34.56830;,
 -25.01831;64.56747;31.86405;,
 -22.70650;62.33242;61.03547;,
 -15.82737;73.43707;38.69777;,
 -17.42706;73.69088;38.68413;,
 -14.36554;64.45280;34.68163;,
 -21.24467;53.34814;57.01940;,
 -16.33495;64.60556;34.56830;,
 -34.92869;62.08192;57.14703;,
 -22.70650;62.33242;61.03547;,
 -23.93724;68.60030;58.01461;,
 -32.57177;68.83038;55.16726;,
 -21.24467;53.34814;57.01940;,
 -33.46686;53.09768;53.13090;,
 -29.90876;51.69396;47.74863;,
 -21.22542;51.73206;50.45290;,
 -28.04954;73.18663;34.80931;,
 -34.92869;62.08192;57.14703;,
 -26.06157;73.92097;35.83677;,
 -33.46686;53.09768;53.13090;,
 -26.58770;64.20235;30.79315;,
 -25.01831;64.56747;31.86405;,
 -13.76026;98.03709;36.54529;,
 -13.76026;98.03709;56.54528;,
 -13.76026;78.03709;56.54528;,
 -13.76026;78.03709;36.54529;,
 -33.76028;98.03709;56.54528;,
 -33.76028;98.03709;36.54529;,
 -33.76028;78.03709;36.54529;,
 -33.76028;78.03709;56.54528;,
 -29.16019;78.03710;36.54529;,
 -33.76028;78.03709;36.54529;,
 -33.76028;98.03709;36.54529;,
 -29.16019;102.05437;36.54529;,
 -24.17320;103.02407;36.54529;,
 -24.17320;78.03710;36.54529;,
 -29.16019;102.05437;56.54529;,
 -33.76028;98.03709;56.54528;,
 -33.76028;78.03709;56.54528;,
 -29.16019;78.03710;56.54529;,
 -24.17320;78.03709;56.54528;,
 -24.17320;103.02407;56.54528;,
 -29.16019;102.05437;36.54529;,
 -33.76028;98.03709;36.54529;,
 -29.16019;102.05437;56.54529;,
 -24.17320;103.02407;56.54528;,
 -24.17320;103.02407;36.54529;,
 -29.16019;78.03710;56.54529;,
 -33.76028;78.03709;36.54529;,
 -29.16019;78.03710;36.54529;,
 -24.17320;78.03710;36.54529;,
 -24.17320;78.03709;56.54528;,
 -17.93945;102.05437;36.54529;,
 -13.76026;98.03709;36.54529;,
 -13.76026;78.03709;36.54529;,
 -17.93945;78.03709;36.54529;,
 -17.93945;78.03709;56.54528;,
 -13.76026;78.03709;56.54528;,
 -13.76026;98.03709;56.54528;,
 -17.93945;102.05437;56.54528;,
 -17.93945;102.05437;56.54528;,
 -13.76026;98.03709;36.54529;,
 -17.93945;102.05437;36.54529;,
 -17.93945;78.03709;36.54529;,
 -13.76026;78.03709;36.54529;,
 -17.93945;78.03709;56.54528;,
 -24.10380;101.62881;60.05852;,
 -15.86488;96.87207;60.05852;,
 -15.86488;96.87207;34.13667;,
 -24.10380;101.62881;34.13667;,
 -15.86488;87.35857;60.05852;,
 -15.86488;87.35857;34.13667;,
 -24.10380;82.60183;60.05852;,
 -24.10380;82.60183;34.13667;,
 -32.34272;87.35857;60.05852;,
 -32.34272;87.35857;34.13667;,
 -32.34272;96.87207;60.05852;,
 -32.34272;96.87207;34.13667;,
 -24.10380;101.62881;60.05852;,
 -24.10380;101.62881;34.13667;,
 -24.10380;92.11532;60.05852;,
 -24.10380;92.11532;60.05852;,
 -24.10380;92.11532;60.05852;,
 -24.10380;92.11532;60.05852;,
 -24.10380;92.11532;60.05852;,
 -24.10380;92.11532;60.05852;,
 -24.10380;92.11532;34.13667;,
 -24.10380;92.11532;34.13667;,
 -24.10380;92.11532;34.13667;,
 -24.10380;92.11532;34.13667;,
 -24.10380;92.11532;34.13667;,
 -24.10380;92.11532;34.13667;,
 -29.56916;93.87819;34.35518;,
 -28.04250;92.99675;34.35518;,
 -28.04250;92.99675;-19.28354;,
 -29.56916;93.87819;-19.28354;,
 -28.04250;91.23392;34.35518;,
 -28.04250;91.23392;-19.28354;,
 -29.56916;90.35250;34.35518;,
 -29.56916;90.35250;-19.28354;,
 -31.09583;91.23392;34.35518;,
 -31.09583;91.23392;-19.28354;,
 -31.09583;92.99675;34.35518;,
 -31.09583;92.99675;-19.28354;,
 -29.56916;93.87819;34.35518;,
 -29.56916;93.87819;-19.28354;,
 -29.56916;92.11532;-19.28354;,
 -29.56916;92.11532;-19.28354;,
 -29.56916;92.11532;-19.28354;,
 -29.56916;92.11532;-19.28354;,
 -29.56916;92.11532;-19.28354;,
 -29.56916;92.11532;-19.28354;,
 -18.74670;93.87819;34.35518;,
 -17.22004;92.99675;34.35518;,
 -17.22004;92.99675;-19.28354;,
 -18.74670;93.87819;-19.28354;,
 -17.22004;91.23392;34.35518;,
 -17.22004;91.23392;-19.28354;,
 -18.74670;90.35250;34.35518;,
 -18.74670;90.35250;-19.28354;,
 -20.27337;91.23392;34.35518;,
 -20.27337;91.23392;-19.28354;,
 -20.27337;92.99675;34.35518;,
 -20.27337;92.99675;-19.28354;,
 -18.74670;93.87819;34.35518;,
 -18.74670;93.87819;-19.28354;,
 -18.74670;92.11532;-19.28354;,
 -18.74670;92.11532;-19.28354;,
 -18.74670;92.11532;-19.28354;,
 -18.74670;92.11532;-19.28354;,
 -18.74670;92.11532;-19.28354;,
 -18.74670;92.11532;-19.28354;,
 -26.91762;89.44097;34.35518;,
 -25.39097;88.55954;34.35518;,
 -25.39097;88.55954;-19.28354;,
 -26.91762;89.44097;-19.28354;,
 -25.39097;86.79671;34.35518;,
 -25.39097;86.79671;-19.28354;,
 -26.91762;85.91528;34.35518;,
 -26.91762;85.91528;-19.28354;,
 -28.44429;86.79671;34.35518;,
 -28.44429;86.79671;-19.28354;,
 -28.44429;88.55954;34.35518;,
 -28.44429;88.55954;-19.28354;,
 -26.91762;89.44097;34.35518;,
 -26.91762;89.44097;-19.28354;,
 -26.91762;87.67810;-19.28354;,
 -26.91762;87.67810;-19.28354;,
 -26.91762;87.67810;-19.28354;,
 -26.91762;87.67810;-19.28354;,
 -26.91762;87.67810;-19.28354;,
 -26.91762;87.67810;-19.28354;,
 -21.50638;89.44097;34.35518;,
 -19.97973;88.55954;34.35518;,
 -19.97973;88.55954;-19.28354;,
 -21.50638;89.44097;-19.28354;,
 -19.97973;86.79671;34.35518;,
 -19.97973;86.79671;-19.28354;,
 -21.50638;85.91528;34.35518;,
 -21.50638;85.91528;-19.28354;,
 -23.03305;86.79671;34.35518;,
 -23.03305;86.79671;-19.28354;,
 -23.03305;88.55954;34.35518;,
 -23.03305;88.55954;-19.28354;,
 -21.50638;89.44097;34.35518;,
 -21.50638;89.44097;-19.28354;,
 -21.50638;87.67810;-19.28354;,
 -21.50638;87.67810;-19.28354;,
 -21.50638;87.67810;-19.28354;,
 -21.50638;87.67810;-19.28354;,
 -21.50638;87.67810;-19.28354;,
 -21.50638;87.67810;-19.28354;,
 -26.91762;98.85651;34.35518;,
 -25.39097;97.97507;34.35518;,
 -25.39097;97.97507;-19.28354;,
 -26.91762;98.85651;-19.28354;,
 -25.39097;96.21225;34.35518;,
 -25.39097;96.21225;-19.28354;,
 -26.91762;95.33082;34.35518;,
 -26.91762;95.33082;-19.28354;,
 -28.44429;96.21225;34.35518;,
 -28.44429;96.21225;-19.28354;,
 -28.44429;97.97507;34.35518;,
 -28.44429;97.97507;-19.28354;,
 -26.91762;98.85651;34.35518;,
 -26.91762;98.85651;-19.28354;,
 -26.91762;97.09364;-19.28354;,
 -26.91762;97.09364;-19.28354;,
 -26.91762;97.09364;-19.28354;,
 -26.91762;97.09364;-19.28354;,
 -26.91762;97.09364;-19.28354;,
 -26.91762;97.09364;-19.28354;,
 -21.45228;98.85651;34.35518;,
 -19.92562;97.97507;34.35518;,
 -19.92562;97.97507;-19.28354;,
 -21.45228;98.85651;-19.28354;,
 -19.92562;96.21225;34.35518;,
 -19.92562;96.21225;-19.28354;,
 -21.45228;95.33082;34.35518;,
 -21.45228;95.33082;-19.28354;,
 -22.97895;96.21225;34.35518;,
 -22.97895;96.21225;-19.28354;,
 -22.97895;97.97507;34.35518;,
 -22.97895;97.97507;-19.28354;,
 -21.45228;98.85651;34.35518;,
 -21.45228;98.85651;-19.28354;,
 -21.45228;97.09364;-19.28354;,
 -21.45228;97.09364;-19.28354;,
 -21.45228;97.09364;-19.28354;,
 -21.45228;97.09364;-19.28354;,
 -21.45228;97.09364;-19.28354;,
 -21.45228;97.09364;-19.28354;,
 -24.10380;101.62881;-12.00347;,
 -15.86488;96.87207;-12.00347;,
 -15.86488;96.87207;-15.25872;,
 -24.10380;101.62881;-15.25872;,
 -15.86488;87.35857;-12.00347;,
 -15.86488;87.35857;-15.25872;,
 -24.10380;82.60183;-12.00347;,
 -24.10380;82.60183;-15.25872;,
 -32.34272;87.35857;-12.00347;,
 -32.34272;87.35857;-15.25872;,
 -32.34272;96.87207;-12.00347;,
 -32.34272;96.87207;-15.25872;,
 -24.10380;101.62881;-12.00347;,
 -24.10380;101.62881;-15.25872;,
 -24.10380;92.11532;-12.00347;,
 -24.10380;92.11532;-12.00347;,
 -24.10380;92.11532;-12.00347;,
 -24.10380;92.11532;-12.00347;,
 -24.10380;92.11532;-12.00347;,
 -24.10380;92.11532;-12.00347;,
 -24.10380;92.11532;-15.25872;,
 -24.10380;92.11532;-15.25872;,
 -24.10380;92.11532;-15.25872;,
 -24.10380;92.11532;-15.25872;,
 -24.10380;92.11532;-15.25872;,
 -24.10380;92.11532;-15.25872;,
 -24.10380;101.62881;16.53649;,
 -15.86488;96.87207;16.53649;,
 -15.86488;96.87207;13.28124;,
 -24.10380;101.62881;13.28124;,
 -15.86488;87.35857;16.53649;,
 -15.86488;87.35857;13.28124;,
 -24.10380;82.60183;16.53649;,
 -24.10380;82.60183;13.28124;,
 -32.34272;87.35857;16.53649;,
 -32.34272;87.35857;13.28124;,
 -32.34272;96.87207;16.53649;,
 -32.34272;96.87207;13.28124;,
 -24.10380;101.62881;16.53649;,
 -24.10380;101.62881;13.28124;,
 -24.10380;92.11532;16.53649;,
 -24.10380;92.11532;16.53649;,
 -24.10380;92.11532;16.53649;,
 -24.10380;92.11532;16.53649;,
 -24.10380;92.11532;16.53649;,
 -24.10380;92.11532;16.53649;,
 -24.10380;92.11532;13.28124;,
 -24.10380;92.11532;13.28124;,
 -24.10380;92.11532;13.28124;,
 -24.10380;92.11532;13.28124;,
 -24.10380;92.11532;13.28124;,
 -24.10380;92.11532;13.28124;;
 
 166;
 4;0,1,2,3;,
 4;4,0,3,5;,
 4;6,4,5,7;,
 4;1,6,7,2;,
 4;1,0,4,6;,
 4;8,9,10,11;,
 4;12,8,11,13;,
 4;14,12,13,15;,
 4;9,14,15,10;,
 4;9,8,12,14;,
 4;16,17,18,19;,
 4;20,21,22,23;,
 4;17,16,21,20;,
 4;24,25,26,11;,
 4;27,28,5,29;,
 4;25,24,28,27;,
 4;30,31,32,33;,
 4;34,35,36,37;,
 4;31,30,35,34;,
 4;38,39,10,40;,
 4;41,42,43,7;,
 4;39,38,42,41;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;52,55,56,57;,
 4;58,59,60,61;,
 4;58,61,62,63;,
 4;64,65,48,66;,
 4;64,66,67,68;,
 4;69,51,70,71;,
 4;69,71,72,73;,
 4;74,75,76,77;,
 4;74,77,57,56;,
 4;78,79,80,81;,
 4;78,81,63,62;,
 4;82,45,83,84;,
 4;82,84,68,67;,
 4;85,86,46,87;,
 4;85,87,73,72;,
 4;88,89,90,91;,
 4;89,92,93,90;,
 4;92,94,95,93;,
 4;94,96,97,95;,
 4;96,98,99,97;,
 4;98,100,101,99;,
 3;102,89,88;,
 3;103,92,89;,
 3;104,94,92;,
 3;105,96,94;,
 3;106,98,96;,
 3;107,100,98;,
 3;108,91,90;,
 3;109,90,93;,
 3;110,93,95;,
 3;111,95,97;,
 3;112,97,99;,
 3;113,99,101;,
 4;114,115,116,117;,
 4;115,118,119,116;,
 4;118,120,121,119;,
 4;120,122,123,121;,
 4;122,124,125,123;,
 4;124,126,127,125;,
 3;128,117,116;,
 3;129,116,119;,
 3;130,119,121;,
 3;131,121,123;,
 3;132,123,125;,
 3;133,125,127;,
 4;134,135,136,137;,
 4;135,138,139,136;,
 4;138,140,141,139;,
 4;140,142,143,141;,
 4;142,144,145,143;,
 4;144,146,147,145;,
 3;148,137,136;,
 3;149,136,139;,
 3;150,139,141;,
 3;151,141,143;,
 3;152,143,145;,
 3;153,145,147;,
 4;154,155,156,157;,
 4;155,158,159,156;,
 4;158,160,161,159;,
 4;160,162,163,161;,
 4;162,164,165,163;,
 4;164,166,167,165;,
 3;168,157,156;,
 3;169,156,159;,
 3;170,159,161;,
 3;171,161,163;,
 3;172,163,165;,
 3;173,165,167;,
 4;174,175,176,177;,
 4;175,178,179,176;,
 4;178,180,181,179;,
 4;180,182,183,181;,
 4;182,184,185,183;,
 4;184,186,187,185;,
 3;188,177,176;,
 3;189,176,179;,
 3;190,179,181;,
 3;191,181,183;,
 3;192,183,185;,
 3;193,185,187;,
 4;194,195,196,197;,
 4;195,198,199,196;,
 4;198,200,201,199;,
 4;200,202,203,201;,
 4;202,204,205,203;,
 4;204,206,207,205;,
 3;208,197,196;,
 3;209,196,199;,
 3;210,199,201;,
 3;211,201,203;,
 3;212,203,205;,
 3;213,205,207;,
 4;214,215,216,217;,
 4;215,218,219,216;,
 4;218,220,221,219;,
 4;220,222,223,221;,
 4;222,224,225,223;,
 4;224,226,227,225;,
 3;228,217,216;,
 3;229,216,219;,
 3;230,219,221;,
 3;231,221,223;,
 3;232,223,225;,
 3;233,225,227;,
 4;234,235,236,237;,
 4;235,238,239,236;,
 4;238,240,241,239;,
 4;240,242,243,241;,
 4;242,244,245,243;,
 4;244,246,247,245;,
 3;248,235,234;,
 3;249,238,235;,
 3;250,240,238;,
 3;251,242,240;,
 3;252,244,242;,
 3;253,246,244;,
 3;254,237,236;,
 3;255,236,239;,
 3;256,239,241;,
 3;257,241,243;,
 3;258,243,245;,
 3;259,245,247;,
 4;260,261,262,263;,
 4;261,264,265,262;,
 4;264,266,267,265;,
 4;266,268,269,267;,
 4;268,270,271,269;,
 4;270,272,273,271;,
 3;274,261,260;,
 3;275,264,261;,
 3;276,266,264;,
 3;277,268,266;,
 3;278,270,268;,
 3;279,272,270;,
 3;280,263,262;,
 3;281,262,265;,
 3;282,265,267;,
 3;283,267,269;,
 3;284,269,271;,
 3;285,271,273;;
 
 MeshMaterialList {
  12;
  166;
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
  8,
  9,
  9,
  8,
  9,
  9,
  8,
  9,
  9,
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
  11;;
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
  72;
  0.217995;0.330748;-0.918196;,
  0.223247;0.650442;-0.726007;,
  0.869510;0.427009;0.248224;,
  -0.230670;0.240885;0.942744;,
  0.954762;0.004189;0.297342;,
  -0.154612;-0.987818;0.017594;,
  -0.129244;-0.894680;0.427602;,
  0.174163;-0.052196;-0.983333;,
  0.999359;0.021306;0.028783;,
  -0.170283;0.112120;0.978996;,
  0.249650;0.551604;-0.795869;,
  -0.125613;-0.890987;0.436307;,
  0.820915;0.414751;0.392531;,
  0.288808;-0.955042;-0.066964;,
  -0.300688;-0.035233;0.953071;,
  -0.180063;-0.776710;0.603571;,
  -0.910434;0.413653;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.920055;0.391788;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.000001;0.000000;1.000000;,
  -0.000000;0.000000;1.000000;,
  -0.000000;0.000000;1.000000;,
  0.000000;0.000000;1.000000;,
  0.499999;0.866026;0.000000;,
  0.499999;-0.866026;-0.000000;,
  -0.500000;-0.866026;0.000000;,
  0.500007;0.866022;0.000000;,
  0.500001;-0.866025;-0.000000;,
  -0.499998;-0.866026;0.000000;,
  0.500005;0.866022;0.000000;,
  0.500000;-0.866025;-0.000000;,
  -0.499999;-0.866026;0.000000;,
  0.500008;0.866021;0.000000;,
  0.500003;-0.866024;-0.000000;,
  0.500010;0.866020;0.000000;,
  0.500004;-0.866023;-0.000000;,
  -0.499999;-0.866026;0.000000;,
  0.500007;0.866021;0.000000;,
  0.500002;-0.866024;-0.000000;,
  -0.499998;-0.866027;0.000000;,
  0.499999;0.866026;0.000000;,
  0.499999;-0.866026;-0.000000;,
  -0.094769;-0.939612;0.328859;,
  -0.954762;-0.004189;-0.297341;,
  0.185244;-0.790572;-0.583679;,
  -0.964953;0.013576;-0.262071;,
  -0.918145;0.365547;-0.152920;,
  0.001431;0.999999;0.000608;,
  0.265843;0.429137;-0.863232;,
  0.576882;-0.739965;-0.345918;,
  0.952753;0.019525;0.303116;,
  -0.265842;-0.429134;0.863234;,
  -0.919648;0.350844;-0.176510;,
  -0.223340;-0.762981;-0.606612;,
  -0.952753;-0.019524;-0.303117;,
  -0.000001;0.000000;1.000000;,
  -0.439426;0.898279;0.000000;,
  -0.018864;0.999822;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000001;-1.000000;-0.000000;,
  -0.000001;-1.000000;-0.000000;,
  -0.000001;0.000000;1.000000;,
  0.443934;0.896060;0.000000;,
  -0.000000;-1.000000;-0.000000;,
  0.000001;-1.000000;-0.000000;,
  -0.500000;0.866026;0.000000;,
  -0.500004;0.866023;0.000000;,
  -0.500004;0.866023;0.000000;,
  -0.500004;0.866023;0.000000;,
  -0.500003;0.866024;0.000000;;
  166;
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;6,6,44,5;,
  4;45,45,45,45;,
  4;46,46,46,46;,
  4;9,9,3,3;,
  4;8,8,2,2;,
  4;7,7,0,0;,
  4;47,47,48,48;,
  4;49,49,49,49;,
  4;10,10,0,0;,
  4;11,11,11,11;,
  4;10,10,50,50;,
  4;12,12,2,2;,
  4;51,13,51,51;,
  4;12,12,52,52;,
  4;14,14,3,3;,
  4;13,15,5,44;,
  4;14,14,15,53;,
  4;54,54,48,48;,
  4;55,55,55,5;,
  4;54,54,56,56;,
  4;18,18,19,19;,
  4;16,16,17,17;,
  4;20,20,20,20;,
  4;20,20,20,20;,
  4;22,57,57,22;,
  4;22,22,21,21;,
  4;58,16,16,58;,
  4;58,58,59,59;,
  4;60,61,61,60;,
  4;60,60,62,62;,
  4;20,20,20,20;,
  4;20,20,20,20;,
  4;23,63,63,23;,
  4;23,23,21,21;,
  4;64,18,18,64;,
  4;64,64,59,59;,
  4;65,66,66,65;,
  4;65,65,62,62;,
  4;25,25,25,25;,
  4;19,19,19,19;,
  4;26,26,26,26;,
  4;27,27,27,27;,
  4;17,17,17,17;,
  4;67,67,67,67;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  4;28,28,28,28;,
  4;19,19,19,19;,
  4;29,29,29,29;,
  4;30,30,30,30;,
  4;17,17,17,17;,
  4;68,68,68,68;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  4;31,31,31,31;,
  4;19,19,19,19;,
  4;32,32,32,32;,
  4;33,33,33,33;,
  4;17,17,17,17;,
  4;69,69,69,69;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  4;34,34,34,34;,
  4;19,19,19,19;,
  4;35,35,35,35;,
  4;30,30,30,30;,
  4;17,17,17,17;,
  4;68,68,68,68;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  4;36,36,36,36;,
  4;19,19,19,19;,
  4;37,37,37,37;,
  4;38,38,38,38;,
  4;17,17,17,17;,
  4;70,70,70,70;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  4;34,34,34,34;,
  4;19,19,19,19;,
  4;35,35,35,35;,
  4;30,30,30,30;,
  4;17,17,17,17;,
  4;68,68,68,68;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  4;39,39,39,39;,
  4;19,19,19,19;,
  4;40,40,40,40;,
  4;41,41,41,41;,
  4;17,17,17,17;,
  4;71,71,71,71;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  4;42,42,42,42;,
  4;19,19,19,19;,
  4;43,43,43,43;,
  4;27,27,27,27;,
  4;17,17,17,17;,
  4;67,67,67,67;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  4;42,42,42,42;,
  4;19,19,19,19;,
  4;43,43,43,43;,
  4;27,27,27,27;,
  4;17,17,17,17;,
  4;67,67,67,67;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;24,24,24;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;,
  3;20,20,20;;
 }
 MeshTextureCoords {
  286;
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
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
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.230004;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.230004;0.000000;,
  0.479354;0.000000;,
  0.479354;1.000000;,
  0.769996;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.769996;1.000000;,
  0.520646;1.000000;,
  0.520646;0.000000;,
  0.230004;1.000000;,
  0.000000;1.000000;,
  0.230004;0.000000;,
  0.479354;0.000000;,
  0.479354;1.000000;,
  0.230004;1.000000;,
  0.000000;0.000000;,
  0.230004;0.000000;,
  0.479354;0.000000;,
  0.479354;1.000000;,
  0.791041;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.791041;1.000000;,
  0.208959;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.208959;0.000000;,
  0.791041;0.000000;,
  1.000000;1.000000;,
  0.791041;1.000000;,
  0.791041;0.000000;,
  1.000000;0.000000;,
  0.791041;1.000000;,
  0.000000;0.000000;,
  0.166667;0.000000;,
  0.166667;1.000000;,
  0.000000;1.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  0.833333;0.000000;,
  0.833333;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083333;0.000000;,
  0.250000;0.000000;,
  0.416667;0.000000;,
  0.583333;0.000000;,
  0.750000;0.000000;,
  0.916667;0.000000;,
  0.083333;1.000000;,
  0.250000;1.000000;,
  0.416667;1.000000;,
  0.583333;1.000000;,
  0.750000;1.000000;,
  0.916667;1.000000;,
  0.000000;0.000000;,
  0.166667;0.000000;,
  0.166667;1.000000;,
  0.000000;1.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  0.833333;0.000000;,
  0.833333;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083333;1.000000;,
  0.250000;1.000000;,
  0.416667;1.000000;,
  0.583333;1.000000;,
  0.750000;1.000000;,
  0.916667;1.000000;,
  0.000000;0.000000;,
  0.166667;0.000000;,
  0.166667;1.000000;,
  0.000000;1.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  0.833333;0.000000;,
  0.833333;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083333;1.000000;,
  0.250000;1.000000;,
  0.416667;1.000000;,
  0.583333;1.000000;,
  0.750000;1.000000;,
  0.916667;1.000000;,
  0.000000;0.000000;,
  0.166667;0.000000;,
  0.166667;1.000000;,
  0.000000;1.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  0.833333;0.000000;,
  0.833333;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083333;1.000000;,
  0.250000;1.000000;,
  0.416667;1.000000;,
  0.583333;1.000000;,
  0.750000;1.000000;,
  0.916667;1.000000;,
  0.000000;0.000000;,
  0.166667;0.000000;,
  0.166667;1.000000;,
  0.000000;1.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  0.833333;0.000000;,
  0.833333;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083333;1.000000;,
  0.250000;1.000000;,
  0.416667;1.000000;,
  0.583333;1.000000;,
  0.750000;1.000000;,
  0.916667;1.000000;,
  0.000000;0.000000;,
  0.166667;0.000000;,
  0.166667;1.000000;,
  0.000000;1.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  0.833333;0.000000;,
  0.833333;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083333;1.000000;,
  0.250000;1.000000;,
  0.416667;1.000000;,
  0.583333;1.000000;,
  0.750000;1.000000;,
  0.916667;1.000000;,
  0.000000;0.000000;,
  0.166667;0.000000;,
  0.166667;1.000000;,
  0.000000;1.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  0.833333;0.000000;,
  0.833333;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083333;1.000000;,
  0.250000;1.000000;,
  0.416667;1.000000;,
  0.583333;1.000000;,
  0.750000;1.000000;,
  0.916667;1.000000;,
  0.000000;0.000000;,
  0.166667;0.000000;,
  0.166667;1.000000;,
  0.000000;1.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  0.833333;0.000000;,
  0.833333;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083333;0.000000;,
  0.250000;0.000000;,
  0.416667;0.000000;,
  0.583333;0.000000;,
  0.750000;0.000000;,
  0.916667;0.000000;,
  0.083333;1.000000;,
  0.250000;1.000000;,
  0.416667;1.000000;,
  0.583333;1.000000;,
  0.750000;1.000000;,
  0.916667;1.000000;,
  0.000000;0.000000;,
  0.166667;0.000000;,
  0.166667;1.000000;,
  0.000000;1.000000;,
  0.333333;0.000000;,
  0.333333;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.666667;0.000000;,
  0.666667;1.000000;,
  0.833333;0.000000;,
  0.833333;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.083333;0.000000;,
  0.250000;0.000000;,
  0.416667;0.000000;,
  0.583333;0.000000;,
  0.750000;0.000000;,
  0.916667;0.000000;,
  0.083333;1.000000;,
  0.250000;1.000000;,
  0.416667;1.000000;,
  0.583333;1.000000;,
  0.750000;1.000000;,
  0.916667;1.000000;;
 }
}