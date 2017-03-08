#include <stdio.h>
#include <unistd.h>

#define LED_TRIGGER "/sys/class/leds/led0/trigger"
#define ONBOARD_LED "/sys/class/leds/led0/brightness"


void writeToFile(char* filename, char* value){

  // variable declaration
  FILE *fp;

    // Opens file for writing
    fp = fopen(filename, "w");

    // Check if pointer is valid
    if (fp!=NULL){

	// add value to file and close
	fputs(value, fp);
	fclose(fp);
    }
}




int main(int argc, char **argv){

  // First arg is the program name; second is only valid if 0 or 1
  if (argc == 2 && (argv[1][0] == '0' || argv[1][0] == '1' || argv[1][0] == '2')){

    // Remove possible trigger from led (this is needed only for onboard led0)
    writeToFile(LED_TRIGGER, "none");

    /* Set value:
     1 = led on
     0 = led off
     2 = blink led five times with 500ms delay
     other = error message */
    if (argv[1][0] == '1'){
      writeToFile(ONBOARD_LED, "1");
    }
    else if (argv[1][0] == '0'){
      writeToFile(ONBOARD_LED, "0");
    } 
    else if (argv[1][0] == '2'){
      for (int i = 0; i < 10; i++){
        writeToFile(ONBOARD_LED, (i % 2 == 0) ? "1" : "0");
        usleep(500*1000);
      }	
    }
  }
  else {
    printf("Usage: %s [0|1|2]\n", argv[0]);
  }


  return 0;
}



