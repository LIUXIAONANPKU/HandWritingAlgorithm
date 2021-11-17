#include <unistd.h>

#include "intArray.h"
#include "intSort.h"
#include "maxSubArray.h"

int main(int argc, char **argv){
    IntArray a(30);
 

    maxSubArray sa1, sa2;
    int equalTimes = 0;
    int circleTime = 10000;

    for(int i = 0; i < circleTime; i++){
        a.randomize();
        usleep(3);
        sa1 = divideFindMaxSubArray(a, 0, a.size() - 1);
        sa2 = violentFindMaxSubArray(a, 0, a.size() - 1);
        if(sa1.maxSum == sa2.maxSum){
            equalTimes++;
        }
    }

    std::cout << "use divide method" << std::endl;
    sa1.print();

    std::cout << "use violent method" << std::endl;
    sa2.print();

    std::cout << "total circle = " << circleTime << std::endl;
    std::cout << "equal time = " << equalTimes << std::endl;
    return 0;
}