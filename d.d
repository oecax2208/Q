import std.stdio:stdout;
import std.contracts;


class joel(T){
    private:
        T[] arg;
    public:

};

bool reverse(T)(T[]arg){
    T[]tmp = arg.dup;
    uint counter = arg.length -1;
    foreach(uint y; 0 .. arg.length){
        arg[counter] = tmp[y];
        --counter;
    }

    return true;
}

@property bool empty(int y){
    return true;
}

bool find(T)(T[] arg, T val){
    foreach(uint y; 0 .. arg.length){
        if(arg[y] == val){
            return true;
        }
    }
    return false;
}

private bool reverse_find(alias value, alias index, T)(T[] arg,T val){
    return value(arg) && index(arg,val);
}

pure bool rfind(T)(T[] arg, T val){
    return reverse_find!(reverse,find,T)(arg,val);
}


int main(){
    enforce(false,"Cant");

    auto me = new joel!(int);

    int[]name = [10,2,3,4,5,6,76];
    reverse(name);

    if(rfind(name,1)){
        stdout.writeln("true");
    }else{
        stdout.writeln  ("false");
    }

    foreach(ref int y; 0 ..name.length){
        stdout.writef("%d ",name[y]);
    }



return 0;
}
