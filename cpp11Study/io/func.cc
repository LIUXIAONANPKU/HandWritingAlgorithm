#include <fstream>
#include <iostream>

void ioObjNoCopy(){
    std::ofstream out1, out2;

    //out1 = out2;
    //std::ofstream pr(std::ofstream);
    //out2 = pr(out2);
}

void ioState(){
    std::ifstream ifos;
    ifos.eof();
}

void ioFlash(){
    std::cout << "hi" << std::endl;
    std::cout << "hi1" << std::flush;
    std::cout << "hi2" << std::flush;
    std::cout << "hi3" << std::ends;
    std::cout << "hi4" << std::ends;
}

void ioFile(){
    std::ofstream of1("./sample.txt", std::ofstream::out);
    std::ofstream of2("./sample2.txt", std::ofstream::out);
    for(int i = 0; i < 10; ++i){
        of1 << "Hello file io\n"; 
    }
    of2.tie(&of1);
    of2.open()
    of1.close();
    of2.close();
}