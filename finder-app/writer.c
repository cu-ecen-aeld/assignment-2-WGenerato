#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Open syslog
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    
    if(argc==1){
    syslog(LOG_ERR, "Error: No parameter is specified.\n");
        fprintf(stderr, "Error: No parameter is specified\n");
        closelog();
        return 1;
    }
    
    const char *writefile = argv[1];
    const char *writestr = argv[2];
    
    // Check if both arguments are provided
    if (argc != 3) {
     syslog(LOG_ERR, "Error: One of the required parameters is not declared.\n");
        fprintf(stderr, "Error: One of the required parameters is not declared.\n");
        closelog();
        return 1;
    }

    

    // Open the file for writing
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error: Failed to open file %s: %s", writefile, strerror(errno));
        fprintf(stderr, "Error: Failed to open file %s: %s\n", writefile, strerror(errno));
        closelog();
        return 1;
    }

    // Write the string to the file
    if (fprintf(file, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Error: Failed to write to file %s: %s", writefile, strerror(errno));
        fprintf(stderr, "Error: Failed to write to file %s: %s\n", writefile, strerror(errno));
        fclose(file);
        closelog();
        return 1;
    }

    // Close the file
    if (fclose(file) != 0) {
        syslog(LOG_ERR, "Error: Failed to close file %s: %s", writefile, strerror(errno));
        fprintf(stderr, "Error: Failed to close file %s: %s\n", writefile, strerror(errno));
        closelog();
        return 1;
    }

    // Log success message
    syslog(LOG_DEBUG, "Writing \"%s\" to %s", writestr, writefile);
    printf("Content has been written to %s successfully.\n",writefile);

    // Close syslog
    closelog();
    return 0;
}

