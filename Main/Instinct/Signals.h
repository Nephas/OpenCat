//
// Created by marco-private on 07.06.21.
//

//token list
#define T_ABORT     'a'
#define T_BEEP      'b'
#define T_CALIBRATE 'c'
#define T_REST      'd'
#define T_GYRO      'g'
#define T_HELP      'h'
#define T_INDEXED   'i'
#define T_JOINTS    'j'
#define T_SKILL     'k'
#define T_LISTED    'l'
#define T_MOVE      'm'
#define T_MELODY    'o'
#define T_PAUSE     'p'
#define T_RAMP      'r'
#define T_SAVE      's'
#define T_MEOW      'u'
#define T_UNDEFINED 'w'
#define T_XLEG      'x'

//abbreviation //gait/posture/function names
#define K00 "d"       //rest and shutdown all servos
#define K01 "F"       //forward
#define K02 "g"       //turn off gyro feedback to boost speed

#define K10 "L"       //left
#define K11 "balance" //neutral stand up posture
#define K12 "R"       //right

#define K20 "p"       //pause motion and shut off all servos
#define K21 "B"       //backward
#define K22 "c"       //calibration mode with IMU turned off

#define K30 "vt"      //stepping
#define K31 "cr"      //crawl
#define K32 "wk"      //walk

#define K40 "tr"      //trot
#define K41 "rn"      //run
#define K42 "ck"      //check around

#define K50 "hi"      //greeting
#define K51 "pu"      //push up
#define K52 "pee"     //standng with three legs

#define K60 "str"     //stretch
#define K61 "sit"     //sit
#define K62 "zero"    //zero position

String gait = "wk";
char direct = 'F';
int8_t tStep = 1;

String preprocessSignal(String raw) {
    if (raw == "B") {
        gait = "bk";
        return gait;
    }
    else if (raw == "F" || raw == "L" || raw == "R") {
        direct = raw[0];
        if (direct == 'F' && gait == "bk")
            gait = "wk";
        return gait + direct;
    }
    else if (raw == "cr" || raw == "wk" || raw == "tr" || raw == "rn") {
        gait = raw;
        return gait + direct;
    }
    else {
        return raw;
    }
}