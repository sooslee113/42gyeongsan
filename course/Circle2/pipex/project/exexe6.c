/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exexe6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:08:01 by sooslee           #+#    #+#             */
/*   Updated: 2024/06/22 04:00:03 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
안되는 점
1. ./pipex infile "ls" "sleep 3" outfile.
2. infile 읽기 권한 없앴을 때.
3. 
*/
void show_error()
{
    perror("error found");
    exit(-1);
}

char *finding_envp(char **envp)
{
            int i;
    char *path;

    i = 0;
    while (envp[i])
    {
        if (ft_strnstr(envp[i], "PATH=", 5))
        {
            path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
            return (path);
        }
        i++;
    }
    return (NULL);

}
void    free_double(char **collection)
{
    int i;
    i = 0;

    while(collection[i])
    {
        free(collection[i]);
        i++;
    }
    free(collection);
}

char    *finding_path(char **command, char **envp)
{
    char **envp_collec;
    char *path;
    int i;
   
    path = finding_envp(envp); // leak;
    printf("+++++++경로+++++++\n");
    printf("%s\n", path);
    printf("\n\n\n");         
    envp_collec = ft_split(path, ':');
    i = 0;
    while (envp_collec[i])
    {
        printf("++++envp_collec 잘 됐나 확인하기+++++\n");
        printf("%s\n", envp_collec[i]);
        i++;
    }
    char *temp;
    char *temp2;
    temp = ft_strjoin("/", command[0]); //leak
    printf("\n%s\n", temp);

    i = 0;
    while(envp_collec[i])
    {
        printf("\n와일문 잘 들어갔나?\n");
        temp2 = ft_strjoin(envp_collec[i],temp);
        printf("+++ 결합 잘 됐나? : %s \n", temp2);
        if (access(temp2, X_OK) == -1)
        {
           free(temp2);
            printf("fail\n");
        }
        else
        {
            printf("+++경로 찾았습니다 : %s \n", temp2);
            return (temp2);

        }
        i ++;
    }
            free(temp);
            free(path);
            free_double(envp_collec);
            return(command[0]);
}
void    childexecve(int *fd, char *file,char *command, char **envp)
{
    int outfile;
    char **cmd_split;
    char    *path;
    int i;
    i = 0;

    outfile = open(file, O_CREAT| O_WRONLY | O_TRUNC, 0666);
    if (outfile == -1)
    {
        perror("file open fail");
    }
    
    if (command == NULL)
    {
        printf("hello world");
        exit(-1);
    }
    close(fd[ft_write]);
    dup2(fd[0], 0);
    dup2(outfile, 1);
    close(outfile);
    cmd_split = ft_split(command, ' ');
    if (cmd_split[0] == NULL)
    {
        printf("%s : command not found", command);
        exit(-1);
    }

        i ++;
    i = 0;

    while (cmd_split[i])
    {
         printf("++++cmd_collec 잘 됐나 확인하기+++\n");
         printf("%s\n", cmd_split[i]);
         i++;
    }
    path = finding_path(cmd_split, envp);
    printf("+++경로 : %s ++++++\n", path);
    if (execve(path, cmd_split, NULL) == -1)
    {
        free_double(cmd_split);
        perror("error found");
        exit(-1);
    }
}


void    parentexecve(int *fd, char *file, char *command, char **envp)
{
    int infile;
    char **cmd_split;
    char    *path;
    int i;
    
    infile = open(file, O_RDONLY);
    if (infile == -1)
    {
        perror("file open failed");
    }
    if (command == NULL)
    {
        printf("hello world");
        exit(-1);
    }
    close(fd[ft_read]);
    dup2(fd[1], 1);
    dup2(infile, 0); // 파일디스크립터는 파일의 번호라는걸 항상 망각하자. 표준 출력, 표준 출력, 표준 에러도 파일이다.(사실 리눅스에서는 모든 것이 파일이다)
    //포인터 fd를 써서 파이프 라인을 하나 만들어 줬다. fd[0]이라는 파일에 표준입력을 가르키게 해서 부모에서 입력한 데이터 혹은 프로세스를 자식 프로세스에게 연결한다.
    //나는 인파일에 값을 읽어와서 아웃파일에 값을 넣어줘야 한다. 파일을 오픈하면 파일디스크립터가 주어진다. 나는 argv[4]에 인자 값을 줘서 파일을 만들어줬다.
    //argv[4]에 인자 값을 줘서 파일의 파일 디스트립터는 infile이다. 이 infile이 0(표준 입력)을 가르키게 해서 infile안에 값이 들어오도록 한다. 자식 프로세스도 마찬가지
    close(infile);
    cmd_split = ft_split(command, ' ');
    i = 0;
    if (cmd_split[0] == NULL)
    {
        printf("%s : command not found", command);
        exit(-1);
    }
    i ++;
    i = 0;
    while (cmd_split[i])
    {
         printf("++++cmd_collec 잘 됐나 확인하기+++\n");
         printf("%s\n", cmd_split[i]);
         i++;
    }
    path = finding_path(cmd_split, envp);
    printf("+++경로 : %s ++++++\n", path);
    wait(NULL);
    if (execve(path, cmd_split, NULL) == -1)
    {
        free_double(cmd_split);
        perror("error found");
        exit(-1);
    }
}
int main(int argc, char **argv, char **envp)
{
    int fd[2];
    int pid;
    int pid2;
    //int status;

    if (pipe(fd) < 0)
    {
        perror("pipe error");
        exit(-1);
    }
    pid = fork();

    if (pid == -1)
    {
        perror("error found");
    }
    if (argc == 5)
    {
        if(pid > 0) // 부모
        {       
            wait(NULL);
        }
        else if (pid == 0)
        {
            pid2 = fork();
            if (pid2 == -1)
            {
                perror("error found");
            }
            if (pid2 > 0) // 자식
            {
                waitpid(pid2 ,NULL, 0);
                parentexecve(fd, argv[1], argv[2], envp);
            }
            else // 손자    
            {
                childexecve(fd, argv[4], argv[3], envp);
            }         
        }
    }
    return 0;
}
// 1. 부모 프로세스의 역할(의무) : 자식 프로세스가 먼저 종료되고 이에 대한 후속처리는 부모 프로세스가 담당한다.
// 프로세스에서는 자식이 먼저 죽는다. 자식 프로세스가 죽으면 부모 프로세스는 자식 프로세스가 남긴 정보 (PID, 종료 상태)를 남긴다.
// 부모 프로세스는 wait 함수를 호출하여 이 상태를 회수하면 남은 정보가 제거되어 자식 프로세스는 완전히 소멸된다. 
// 2. 좀비프로세스가 생기는 이유 . 
//부모 프로세스가 wait를 호출하지 않아 최소한의 정보가 메모리에 남아 있는 경우를 좀비 프로세스라고 한다. 
// 3. 좀비 프로세스가 쌓이면 어떻게 되는가 
//    좀비 프로세스가 쌓이게 되면 리소스 유출을 야기 할 수 있다. 
// 4. 좀비 프로세스와 고아 프로세스의 차이. 고아 프로세스는 부모 프로세스가 먼저 종료되어서 부모 프로세스가 없는 경우를 말한다.
// 
// 5. mandatory에서 fork를 몇번 해야하는가? > 그에 대한 이유 
// 2번 해야한다. 왜냐하면 execve 함수를 두번 써서 자식과 자식으로 관리 해줘야 한다. 포크를 하면 부모 프로세스 정보를 자식 프로세스가 들고 온다. 
//그리고 execve를 하면 새로운 프로세스로 재 탄생하게된다.  
// 6. wait 함수를 어디서 써야하는지 (부모 or 자식), 왜써야하는지 
// 부모 프로세스에서 써야한다. 앞서 말 했듯 부모 프로세스보다 자식 프로세스가 먼저 죽어야 한다. 그래서 wait 함수를써서 자식 프로세스가 남긴 정보를 가져와야 한다.
// 
// 7. 파이프의 fd를 정확하게 닫지 않으면 어떻게 되는가?
// 8. waitpid의 옵션을 어떻게 했을 때 wait함수와 같아 지는지 
// 9. waitpid 각 인자들이 의미하는것 
//  pid_t waitpid(pid_t pid, int * status, int option)
// 첫번째 인자 : 자식 프로세스의 pid, -1이 들어오면 부모ㅠ프로세스의 여러 자식 프로세스들 중 어느
//한가지라도 종료되기를 기다리게 설정해준다.
// 두번째 인자는 자식 프로세스가 종료될 떄의 상태 정보가 저장된다. 
// 세번째 인수는 옵션이다. 
// 10. fork를 한후 부모, 자식 프로세스의 pid
//