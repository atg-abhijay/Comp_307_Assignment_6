#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *data = getenv("QUERY_STRING");
    char *token, *name;
    const char c[2] = "=";
    const char d[2] = "+";
    /* first we use strtok to
        separate the variable
        name from the value */
    token = strtok(data, c);
    token = strtok(NULL, c);

    printf("%s%c%c\n","Content-Type:text/html;charset=iso-8859-1",13,10);
    printf("<html><title>Hello</title><body>\n");
    printf("<h2 style=\"color: red; text-align: center; padding: 300px 0\">");
    /* we use strtok again to
        remove any '+' from the
        name if user entered
        a multi-word name */
    name = strtok(token, d);
    while (name != NULL) {
        printf("%s ", name);
        name = strtok(NULL, d);
    }
    printf("</h2>");
    printf("</body></html>");
    return 0;
}