/*
    PROGRAMMER: JOEL
    LANGUAGE: D PROGRAMMER LANGUAGE
    DATE: 12/05/2019
    TIME: 10:39AM
*/

import std.stdio;
import std.string;

enum inform:int{
    firstL = 1,
    secondL = 2,
    third = 3,
};


void main(string [] args){
    int yam = 10;
    int bean = 10;

    yam is bean && stdout.writeln("hello world and here");

    static if(inform.firstL){
        stdout.writeln("Joel is here");
    }
    char[]input;
    auto stay = r"Joel\a Statement";

    auto name = ['S' , 10L, 'S'];
    stdout.writeln(stay);
    stdout.writeln(typeid("Name"));
    stdout.writeln(input.sizeof);
    stdout.writeln(name[0]);

    typeof(name[0]) pow = name[0];
    stdout.writeln(name[0]);
    stdout.writeln(typeof(name).sizeof);
    auto index = delegate typeof(cast(char)name[0] + 10)(int x){ return x + 10 + inform.firstL;};


}
