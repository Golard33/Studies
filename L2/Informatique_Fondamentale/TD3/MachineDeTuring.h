

char * q4[1]= {'END'};

char * q0[3][4] = { {'0','0','R','0'} , {'1','1','R','0'} , {'B','B','L','q1'} };

char * q1[2][4] = { {'0','1','L','2'} , {'1','0','L','2'} };

char * q2[3][4] = { {'0','B','L','2'} , {'1','B','L','2'} , {'B','B','R','3'} };

char * q3[3][4] = { {'0','0','S','4'} , {'1','1','S','4'} , {'B','B','R','3'} };


char ** tabQ[5] = {&q0, &q1, &q2, &q3; &q4};