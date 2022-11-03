#include <iostream>
#include <getopt.h>
#include <string.h>

int main(int argc, char *argv[]){

    int opt, type, seed, median, partition;
    std::string input, output;

    while((opt = getopt(argc, argv, "v:s:k:m:i:o:")) != -1){
        switch(opt){
            case 'v':
                type = atoi(optarg);
                break;
            case 's':
                seed = atoi(optarg);
                break;
            case 'k':
                median = atoi(optarg);
                break;
            case 'm':
                partition = atoi(optarg);
                break;
            case 'i':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
        }
    }

    return 0;

}