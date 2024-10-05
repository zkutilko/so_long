#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test_file.txt", O_RDONLY);
    char *line;

    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    else
        printf("File opened successfully.\n");

    while ((line = get_next_line(fd)) != NULL)
    {
        if (line) {
            printf("Read line: %s\n", line);
        } else {
            printf("NULL line returned.\n");
        }
        free(line);
    }

    printf("End of file or error occurred.\n");
    close(fd);
    return (0);
}
