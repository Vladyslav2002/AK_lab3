#include <stdio.h>
#include <unistd.h>
#include <map>
#include <getopt.h>
#include <string>


using namespace std;

int main(int argc, char *argv[]) {
    int rezult = 0;
    int indx = -1;
    
    map<string, bool> used;

    static const struct option long_options[] = {
            {"list", 0, NULL, 'l'},
            {"version",  0, NULL, 'v'},
            {"help",  0, NULL, 'h'},
            {"getargument", 1, NULL, 'a'}, 
            {"seeoptions",0,NULL,'s'},
            {NULL,0,NULL,0}
    };

    while ((rezult = getopt_long(argc, argv, "lvha:s", long_options, &indx)) != -1) {
        switch (rezult) {
	    case 'h': {
                if (used["h"] == false) {
                    printf("Arg: Help\n");
                    used["h"] = true;
                    break;
                }
                break;
            }
            case 'l': {
                if (used["l"] == false) {
                    printf("Arg: List\n");
                    used["l"] = true;
                    break;
                }
                break;
            }
            case 's': {
                if (used["s"] == false) {
                    printf("Arg:\n-l --list List\n-h --help Help\n-v --version Version\n-s --seeoptions Options\n");
                    used["s"] = true;
                    break;
                }
                break;    
            }
	    case 'v': {
                if (used["v"] == false) {
                    printf("Arg: Version\n");
                    used["v"] = true;
                    break;
                }
                break;
            }
            case 'a': {
		 if (used["a"] == false) {
                    printf("getargument = %s\n", optarg); 		
                    used["a"] = true;
                    break;
                }
                break;    
            }
            
            case '?': default: {
                printf("error %c not found\n", rezult);
                break;
            }
        }
        indx = -1;
    }
}
